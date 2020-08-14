################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/free_list.cpp \
../src/memtest.cpp \
../src/my_allocator.cpp 

OBJS += \
./src/free_list.o \
./src/memtest.o \
./src/my_allocator.o 

CPP_DEPS += \
./src/free_list.d \
./src/memtest.d \
./src/my_allocator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


