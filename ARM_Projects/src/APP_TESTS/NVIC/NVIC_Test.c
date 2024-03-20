/*
 * NVIC_Test.c
 *
 *  Created on: Mar 12, 2024
 *      Author: NoteBook
 */
#if 0
#include "../MCAL/LIB/STD_TYPES.h"

#include "RCC/RCC.h"
#include "../MCAL/NVIC/NVIC.h"
#include "LED/LED.h"
int x=0;
int y =0;

EXTI0_IRQHandler(void)
{
	x++;
	}

EXTI1_IRQHandler(void)
{
	y++;
	}
int main (void)
{
	RCC_EnableSystemClock(Clock_HSE);
	RCC_SelectSystemClock(Clock_HSE);
	EnableInterrupt (NVIC_EXT0_INTERRRUPT);
	EnableInterrupt (NVIC_EXT1_INTERRRUPT);
	DisableInterrupt (NVIC_EXT0_INTERRRUPT);

	SetPending (NVIC_EXT0_INTERRRUPT);
	SetPending (NVIC_EXT1_INTERRRUPT);

	while(1)
	{

	}

	return 0;
}

#endif
