################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Keil tools exit code 1 is warnings only, so don't treat as an error in make
RC := test $$? -lt 2

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: GE_EFM8LB12F64E-B-QFN32_YJ.omf

# Tool invocations
GE_EFM8LB12F64E-B-QFN32_YJ.omf: echo_path $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Keil 8051 Linker'
	LX51 "@GE_EFM8LB12F64E-B-QFN32_YJ.lnp" || $(RC)
	@echo 'Finished building target: $@'

# Change from all upper case to the expected case
	@-mv "GE_EFM8LB12F64E-B-QFN32_YJ.OMF.CRBUILD" "$@"

# Generate hex file: GE_EFM8LB12F64E-B-QFN32_YJ.hex
	@Ohx51 "GE_EFM8LB12F64E-B-QFN32_YJ.omf" "HEXFILE (GE_EFM8LB12F64E-B-QFN32_YJ.hex)" "H386" 2>&1 >/dev/null

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS) GE_EFM8LB12F64E-B-QFN32_YJ.omf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
# echo the path
echo_path:
	@echo PATH=$$PATH
	@echo ' '

