################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Sched/Sched.c \
../src/Sched/Sched_Config.c 

OBJS += \
./src/Sched/Sched.o \
./src/Sched/Sched_Config.o 

C_DEPS += \
./src/Sched/Sched.d \
./src/Sched/Sched_Config.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sched/%.o: ../src/Sched/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include" -I"E:\tourkey\LCD\include\HAL" -I"E:\tourkey\LCD\include\LIB" -I"E:\tourkey\LCD\include\MCAL" -I"E:\tourkey\LCD\include\SCHED" -I"../include" -I"E:\tourkey\LCD\include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


