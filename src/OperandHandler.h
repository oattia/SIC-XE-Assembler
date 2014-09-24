/*
 * OperandHandler.h
 *
 *  Created on: May 31, 2014
 *      Author: michael
 */

#ifndef OPERANDHANDLER_H_
#define OPERANDHANDLER_H_


#include <string>
#include <math.h>
#include "ExpressionEvaluator.h"
#include "StringUtilities.h"
#include <stdexcept>


using namespace std;
int valueOfLiteralOperand(string op);
int evaluateOperand(string operand, cSect* csect = NULL);
bool isValidOpNm(string operand) ;
int findExpressionType(string op);
int addressOfLiteralOperand(string op);

#endif /* OPERANDHANDLER_H_ */
