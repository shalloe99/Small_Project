################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Customer.cpp \
../src/Product.cpp \
../src/Store.cpp \
../src/driver.cpp 

OBJS += \
./src/Customer.o \
./src/Product.o \
./src/Store.o \
./src/driver.o 

CPP_DEPS += \
./src/Customer.d \
./src/Product.d \
./src/Store.d \
./src/driver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


