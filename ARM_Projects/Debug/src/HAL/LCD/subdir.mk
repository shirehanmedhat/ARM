################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/LCD/LCD.c \
../src/HAL/LCD/LCD_Config.c 

OBJS += \
./src/HAL/LCD/LCD.o \
./src/HAL/LCD/LCD_Config.o 

C_DEPS += \
./src/HAL/LCD/LCD.d \
./src/HAL/LCD/LCD_Config.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/LCD/%.o: ../src/HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include\HAL" -I"E:\tourkey\LCD\include\LIB" -I"E:\tourkey\LCD\include\MCAL" -I"E:\tourkey\LCD\include\SCHED" -I"../include" -I"E:\tourkey\LCD\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


