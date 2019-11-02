################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LeadAndTrail/LeadingAndTrailing.c 

OBJS += \
./LeadAndTrail/LeadingAndTrailing.o 

C_DEPS += \
./LeadAndTrail/LeadingAndTrailing.d 


# Each subdirectory must supply rules for building sources it contributes
LeadAndTrail/%.o: ../LeadAndTrail/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


