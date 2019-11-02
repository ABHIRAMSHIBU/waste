################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3addressCodeGen/main.c \
../3addressCodeGen/stringAdv.c 

OBJS += \
./3addressCodeGen/main.o \
./3addressCodeGen/stringAdv.o 

C_DEPS += \
./3addressCodeGen/main.d \
./3addressCodeGen/stringAdv.d 


# Each subdirectory must supply rules for building sources it contributes
3addressCodeGen/%.o: ../3addressCodeGen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


