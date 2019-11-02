################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ShiftReduceParsing/Debug/subdir.mk
-include ShiftReduceParsing/subdir.mk
-include RD_PARSER/subdir.mk
-include OperatorPrecedenceParser/Debug/subdir.mk
-include OperatorPrecedenceParser/subdir.mk
-include LeadAndTrail/Debug/subdir.mk
-include LeadAndTrail/subdir.mk
-include FirstAndFollow/Debug/subdir.mk
-include FirstAndFollow/subdir.mk
-include 3addressCodeGen/Debug/subdir.mk
-include 3addressCodeGen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: abhiram

# Tool invocations
abhiram: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "abhiram" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) abhiram
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
