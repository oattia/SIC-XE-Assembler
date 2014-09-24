#include "Phase1.h"
#include "IO.h"
#include "Phase2.h"

ifstream ipfile;
ofstream opfile;

bool started;
bool ended;

map<string, OpInfo*>* mainOpTab;

void openInitialStreams(string in, string out) {
	ipfile.open(in.c_str());
	deleteFile(out.c_str());
	opfile.open(out.c_str(), std::ios::app);
}

bool isCSect(parsedLine pl) {
	return (toUpperCase(pl.opcode).compare("CSECT") == 0) ? true : false;
}

parsedLine readAndParse() {
	string before = readLine(&ipfile);
	string x = trim(before);
	return parse(x);
}

void finish() {
	opfile.close();
	ipfile.close();
	deleteOpTab();
}

int main(int argc, char **argv) {

	if (argc != 2) {
		cout << "\aInvalid number of parameters" << endl;
		return 1;
	}

	openInitialStreams(argv[1], "/tmp/pass1_op.txt");

	bool successfullPass1 = true;
	writeHeader(&opfile);
	mainOpTab = getOpTab();
	vector<parsedLine> currCSect;
	vector<cSect> cSects;
	parsedLine pl;

	started = false;
	ended = false;

	while (!ipfile.eof()) {
		pl = readAndParse();

		if (!isCSect(pl)) {
			currCSect.push_back(pl);
			continue;
		}
		if (isCSect(pl)) {
			cSect old = runPhase1(currCSect, &started, &ended,
					&successfullPass1);
			cSects.push_back(old);

			currCSect.clear(); //Already Handled statements
			currCSect.push_back(pl); //Add 'cSect' to the new parsedLines
		}
	}
	cSects.push_back(runPhase1(currCSect, &started, &ended, &successfullPass1));
	currCSect.clear();
	//Write that shit to a file
	for (unsigned int i = 0; i < cSects.size(); i++) {
		for (unsigned int j = 0; j < cSects[i].dataSect.size(); j++) {
			toWrite x = cSects[i].dataSect.at(j);
			if (x.type == -1) {
				writeError(&opfile, x.data);
			} else if (x.type == 0) {
				writeComment(&opfile, x.data);
			} else if (x.type == 1) {
				writeLine(&opfile, x.data);
			} else {
			}
		}
		writeBorder(&opfile);
		writeSymTab(&opfile, &cSects[i].symTab);
	}

	if (!ended) {
		writeError(&opfile, "The program has no END clause");
	}

	if (!successfullPass1) {
		finish();
		return 0;
	}
	runPhase2(&opfile, &cSects);

	finish();
	return 0;
}
