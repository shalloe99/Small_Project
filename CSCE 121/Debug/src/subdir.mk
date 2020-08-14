################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CSCE\ 121.cpp 

OBJS += \
./src/CSCE\ 121.o 

CPP_DEPS += \
./src/CSCE\ 121.d 


# Each subdirectory must supply rules for building sources it contributes
src/CSCE\ 121.o: ../src/CSCE\ 121.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/CSCE 121.d" -MT"src/CSCE\ 121.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


