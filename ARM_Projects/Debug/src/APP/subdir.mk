################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP/GPIO_test.c \
../src/APP/NVIC_Test.c \
../src/APP/SysTick.c \
../src/APP/main.c \
../src/APP/main_led.c \
../src/APP/switch_led_test.c 

OBJS += \
./src/APP/GPIO_test.o \
./src/APP/NVIC_Test.o \
./src/APP/SysTick.o \
./src/APP/main.o \
./src/APP/main_led.o \
./src/APP/switch_led_test.o 

C_DEPS += \
./src/APP/GPIO_test.d \
./src/APP/NVIC_Test.d \
./src/APP/SysTick.d \
./src/APP/main.d \
./src/APP/main_led.d \
./src/APP/switch_led_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/APP/%.o: ../src/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"E:\tourkey\TrafficLightApp\include" -I"E:\tourkey\TrafficLightApp\include\LIB" -I"E:\tourkey\TrafficLightApp\include\HAL" -I"E:\tourkey\TrafficLightApp\include\HAL" -I"E:\tourkey\TrafficLightApp\include\MCAL" -I"E:\tourkey\TrafficLightApp\include" -I"E:\tourkey\TrafficLightApp\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


