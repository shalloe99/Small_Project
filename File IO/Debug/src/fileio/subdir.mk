################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/fileio/file_io.cpp 

OBJS += \
./src/fileio/file_io.o 

CPP_DEPS += \
./src/fileio/file_io.d 


# Each subdirectory must supply rules for building sources it contributes
src/fileio/%.o: ../src/fileio/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


