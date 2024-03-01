################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/LED/LED.c \
../src/HAL/LED/LED_Config.c 

OBJS += \
./src/HAL/LED/LED.o \
./src/HAL/LED/LED_Config.o 

C_DEPS += \
./src/HAL/LED/LED.d \
./src/HAL/LED/LED_Config.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/LED/%.o: ../src/HAL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"E:\tourkey\Project_GPIO_Mod2\include\HAL" -I"E:\tourkey\Project_GPIO_Mod2\include\HAL" -I"E:\tourkey\Project_GPIO_Mod2\include\MCAL" -I"E:\tourkey\Project_GPIO_Mod2\include" -I"E:\tourkey\Project_GPIO_Mod2\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


