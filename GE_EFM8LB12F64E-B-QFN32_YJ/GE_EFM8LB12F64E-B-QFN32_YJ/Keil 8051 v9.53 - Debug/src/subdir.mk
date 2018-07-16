################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/EFM8LB1_FlashPrimitives.c \
../src/GE_EFM8LB12F64E-B-QFN32_YJ_main.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/uart_1.c 

OBJS += \
./src/EFM8LB1_FlashPrimitives.OBJ \
./src/GE_EFM8LB12F64E-B-QFN32_YJ_main.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/uart_1.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/GE_EFM8LB12F64E-B-QFN32_YJ_main.OBJ: D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/bsp.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/uart_1.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/EFM8LB1_SMBus_MasterMultibyte.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/EFM8LB1_I2C_Slave.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/bsp_config.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/efm8_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/EFM8LB1_SMBus_MasterMultibyte.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/EFM8LB1_I2C_Slave.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/uart_1.OBJ: D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/uart_1.h D:/WorkSpace/MyCode/GE_EFM8LB12F64E-B-QFN32_YJ/GE_EFM8LB12F64E-B-QFN32_YJ/inc/efm8_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/EFM8LB1/inc/SI_EFM8LB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.1.1/Device/shared/si8051Base/stdbool.h


