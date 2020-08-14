################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Stack\ ADT.cpp 

OBJS += \
./src/Stack\ ADT.o 

CPP_DEPS += \
./src/Stack\ ADT.d 


# Each subdirectory must supply rules for building sources it contributes
src/Stack\ ADT.o: ../src/Stack\ ADT.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Stack ADT.d" -MT"src/Stack\ ADT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


