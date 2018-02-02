################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../List.cpp \
../briefing.cpp \
../main.cpp \
../parent.cpp \
../teacher.cpp 

OBJS += \
./List.o \
./briefing.o \
./main.o \
./parent.o \
./teacher.o 

CPP_DEPS += \
./List.d \
./briefing.d \
./main.d \
./parent.d \
./teacher.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


