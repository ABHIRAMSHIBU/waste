################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FirstAndFollow/firstandfollow.c \
../FirstAndFollow/stringAdv.c 

OBJS += \
./FirstAndFollow/firstandfollow.o \
./FirstAndFollow/stringAdv.o 

C_DEPS += \
./FirstAndFollow/firstandfollow.d \
./FirstAndFollow/stringAdv.d 


# Each subdirectory must supply rules for building sources it contributes
FirstAndFollow/%.o: ../FirstAndFollow/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


