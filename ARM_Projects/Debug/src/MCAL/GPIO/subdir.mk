################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/GPIO/GPIO.c 

OBJS += \
./src/MCAL/GPIO/GPIO.o 

C_DEPS += \
./src/MCAL/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/GPIO/%.o: ../src/MCAL/GPIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include\HAL" -I"E:\tourkey\LCD\include\LIB" -I"E:\tourkey\LCD\include\MCAL" -I"E:\tourkey\LCD\include\SCHED" -I"../include" -I"E:\tourkey\LCD\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


