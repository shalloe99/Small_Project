################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LinkedList.cpp \
../src/Node.cpp \
../src/TemperatureData.cpp \
../src/TemperatureDatabase.cpp \
../src/main.cpp 

OBJS += \
./src/LinkedList.o \
./src/Node.o \
./src/TemperatureData.o \
./src/TemperatureDatabase.o \
./src/main.o 

CPP_DEPS += \
./src/LinkedList.d \
./src/Node.d \
./src/TemperatureData.d \
./src/TemperatureDatabase.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


