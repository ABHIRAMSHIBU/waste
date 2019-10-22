################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RDparser.c \
../enfaeclosure.c \
../enfatonfa.c \
../lexicalAnalyzer.c \
../lexicalAnalyzer_bkp.c \
../nfa2dfa.c \
../test_source.c 

OBJS += \
./RDparser.o \
./enfaeclosure.o \
./enfatonfa.o \
./lexicalAnalyzer.o \
./lexicalAnalyzer_bkp.o \
./nfa2dfa.o \
./test_source.o 

C_DEPS += \
./RDparser.d \
./enfaeclosure.d \
./enfatonfa.d \
./lexicalAnalyzer.d \
./lexicalAnalyzer_bkp.d \
./nfa2dfa.d \
./test_source.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


