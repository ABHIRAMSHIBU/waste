################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RD_PARSER/RDparser.c 

OBJS += \
./RD_PARSER/RDparser.o 

C_DEPS += \
./RD_PARSER/RDparser.d 


# Each subdirectory must supply rules for building sources it contributes
RD_PARSER/%.o: ../RD_PARSER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


