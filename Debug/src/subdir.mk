################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ExpressionEvaluator.cpp \
../src/IO.cpp \
../src/Main.cpp \
../src/OpCodeGenerator.cpp \
../src/OpTab.cpp \
../src/OperandHandler.cpp \
../src/Parser.cpp \
../src/Phase1.cpp \
../src/Phase2.cpp \
../src/StringUtilities.cpp \
../src/Validate.cpp 

OBJS += \
./src/ExpressionEvaluator.o \
./src/IO.o \
./src/Main.o \
./src/OpCodeGenerator.o \
./src/OpTab.o \
./src/OperandHandler.o \
./src/Parser.o \
./src/Phase1.o \
./src/Phase2.o \
./src/StringUtilities.o \
./src/Validate.o 

CPP_DEPS += \
./src/ExpressionEvaluator.d \
./src/IO.d \
./src/Main.d \
./src/OpCodeGenerator.d \
./src/OpTab.d \
./src/OperandHandler.d \
./src/Parser.d \
./src/Phase1.d \
./src/Phase2.d \
./src/StringUtilities.d \
./src/Validate.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


