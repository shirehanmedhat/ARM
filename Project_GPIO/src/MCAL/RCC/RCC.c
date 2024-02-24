/*
 * RCC.c
 *
 *  Created on: Feb 12, 2024
 *      Author: NoteBook
 */
/***********************1- INCLUDES******************/
#include "RCC/RCC.h"
/***********************2- DEFINES*******************/
#define MASK_PLL			0x01000000
#define MASK_HSEBYP			0x00040000
#define MASK_HSE			0x00010000
#define MASK_HSI			0x00000001
#define HSE_READY_MASK	0x00020000
#define PLL_READY_MASK	0x01000000
#define Clear_PLLP_BITS_MASK 0xfffcffff
#define PLLP_MASK	  0b11
#define PLLN_BITS_LOCATION	6
#define CLEAR_PLLN_BITS		511 /*0b111111111*/
#define CLEAR_PLLM_BITS		0b111111111
#define HSE_READY_MASK		0x00020000

#define PLL_SRC_SELECT_MASK 0x00400000

#define AHB_CLEAR_MASK 0x000000f0
#define AHB_PRE_BIT_LOCATION	4

#define APB1_CLEAR_MASK	0x00001c00
#define APB1_PRE_BIT_LOCATION	10

#define APB2_CLEAR_MASK	0x0000E000
#define APB2_PRE_BIT_LOCATION	13

/********************************************************/
#define HSI_READY_MASK	0x00000002


/***********************3- Types ********************/





/*Peripheral registers*/
typedef struct {
	uint32 RCC_CR;
	uint32 RCC_PLLCFGR;
	uint32 RCC_CFGR;
	uint32 RCC_CIR;
	uint32 RCC_AHB1RSTR;
	uint32 RCC_AHB2RSTR;
	uint32 RCC_APB1RSTR;
	uint32 RCC_APB2RSTR;
	uint32 RCC_AHB1ENR;
	uint32 RCC_AHB2ENR;
	uint32 RCC_APB1ENR;
	uint32 RCC_APB2ENR;
	uint32 RCC_AHB1LPENR;
	uint32 RCC_AHB2LPENR;
	uint32 RCC_APB1LPENR;
	uint32 RCC_APB2LPENR;
	uint32 RCC_BDCR;
	uint32 RCC_CSR;
	uint32 RCC_SSCGR;
	uint32 RCC_PLLI2SCFGR;
	uint32 RCC_DCKCFGR;
}RCC_Peripheral_t;





RCC_ErrorState_t RCC_EnableSystemClock (RCC_Clock_t Clock)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;

	if ( (Clock >= Clock_HSI) &&  (Clock <= Clock_HSEBYP ) )
	{
		LocalErrorState = RCC_OK;
		/*why not global??*/
		volatile RCC_Peripheral_t* const  RCC = (volatile RCC_Peripheral_t*)(0x40023800);
		switch (Clock)
		{
		case Clock_HSI:
			RCC->RCC_CR |= MASK_HSI;
			break;
		case Clock_HSE:
			RCC->RCC_CR |= MASK_HSE;
			break;
		case Clock_PLL:
			RCC->RCC_CR |= MASK_PLL;
			break;
		case Clock_HSEBYP:
			RCC->RCC_CR |= MASK_HSEBYP;
			break;

		}

	}
	else
	{
		/*Do Nothing */
	}

	return LocalErrorState;

}


RCC_ErrorState_t RCC_EnableSystemClock_II (uint32 Clock)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;
	volatile RCC_Peripheral_t* const  RCC = (volatile RCC_Peripheral_t*)(0x40023800);
	if ( (Clock == MASK_HSI) ||  (Clock == MASK_HSE ) || (Clock == MASK_PLL) ||  (Clock == MASK_HSEBYP ))
	{
		RCC->RCC_CR |= Clock;


	}
	else
	{
		/*Do Nothing*/
	}

	return LocalErrorState;

}


RCC_ErrorState_t RCC_DisableSystemClock (RCC_Clock_t Clock)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;

	if ( (Clock >= Clock_HSI) &&  (Clock <= Clock_HSEBYP ) )
	{
		LocalErrorState = RCC_OK;
		volatile RCC_Peripheral_t* const  RCC = (volatile RCC_Peripheral_t*)(0x40023800);
		switch (Clock)
		{
		case Clock_HSI:
			RCC->RCC_CR &= ~MASK_HSI;
			break;
		case Clock_HSE:
			RCC->RCC_CR &= ~MASK_HSE;
			break;
		case Clock_PLL:
			RCC->RCC_CR &= ~MASK_PLL;
			break;
		case Clock_HSEBYP:
			RCC->RCC_CR &= ~MASK_HSEBYP;
			break;

		}

	}
	else
	{
		/*Do Nothing */
	}

	return LocalErrorState;

}


/*Select between SHI , SHE , PLL*/
RCC_ErrorState_t RCC_SelectSystemClock (RCC_Clock_t Clock)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;
	if ((Clock >= Clock_HSI) && (Clock <= Clock_PLL))
	{
		volatile RCC_Peripheral_t* const  RCC = (volatile RCC_Peripheral_t*)(0x40023800);
		switch(Clock)
		{
		case Clock_HSI:
		{
			u8 counter =0;
					/*TimeOut Check*/
					while (!(RCC->RCC_CR & HSI_READY_MASK) && (counter<200) )
					{
						counter++;
					}
					if (RCC->RCC_CR & HSI_READY_MASK)
					{
					 LocalErrorState = RCC_OK;
					 RCC->RCC_CFGR |= Clock;

					}
					else
					{
						 LocalErrorState = RCC_NOK;

					}
		}break;
		case Clock_HSE:
		{
			u8 counter =0;
			while ( !(RCC->RCC_CR & HSE_READY_MASK) && (counter<200) )
			{
				counter++;
			}
			if (RCC->RCC_CR & HSE_READY_MASK)
			{
				 LocalErrorState = RCC_OK;
				 RCC->RCC_CFGR |= Clock;
			}
			else
			{
				LocalErrorState = RCC_NOK;
			}


		}break;
		case Clock_PLL:
				{
					u8 counter =0;
					while ( !(RCC->RCC_CR & PLL_READY_MASK) && (counter<200) )
					{
						counter++;
					}
					if (RCC->RCC_CR & PLL_READY_MASK)
					{
						 LocalErrorState = RCC_OK;
						 RCC->RCC_CFGR |= Clock;
					}
					else
					{
						LocalErrorState = RCC_NOK;
					}


				}break;
		default:
			LocalErrorState = RCC_NOK;
			break;


		}


	}
	else
	{
		/*Do Nothing */
	}


	return LocalErrorState;

}

/* 1- Check if HSI or HSE is ready
 * 2- Configure the P to be 2 = 0b10
 *
 *
 * */

RCC_ErrorState_t RCC_ConfigurePLL(RCC_PLLConfiguration_t* Configuration) {
	RCC_ErrorState_t LocalErrorState = RCC_NOK;
	volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);
	if (Configuration->SelectedClock == Select_HSI) {
		u8 counter = 0;
		/*TimeOut Check*/
		while (!(RCC->RCC_CR & HSI_READY_MASK) && (counter < 200)) {
			counter++;
		}

		/*Implement it by switch case*/
		if (RCC->RCC_CR & HSI_READY_MASK) {
			LocalErrorState = RCC_OK;
			/*Insert the 2 bits of the p parameter  */
			uint32 temp = RCC->RCC_PLLCFGR;

			temp = (temp & Clear_PLLP_BITS_MASK) | ((Configuration->P));
			RCC->RCC_PLLCFGR = temp;
			/*N-Configurations*/
			if (((Configuration->N > 1) && (Configuration->N < 433)) || ((Configuration->N > 434) && (Configuration->N < 510))) {
				temp = RCC->RCC_PLLCFGR;
				temp = temp & (~(CLEAR_PLLN_BITS << PLLN_BITS_LOCATION));
				temp = temp | (Configuration->N << PLLN_BITS_LOCATION);
				RCC->RCC_PLLCFGR = temp;
			} else {
				LocalErrorState = RCC_NOK;
			}
			/*M-Configs*/
			/*if ((Configuration->M > 1) && (Configuration->M < 64)) {
				temp = RCC->RCC_PLLCFGR;
				temp = temp & (~(CLEAR_PLLM_BITS));
				temp = temp | (Configuration->M);
			} else {
				LocalErrorState = RCC_NOK;

			}*/

			temp = RCC->RCC_PLLCFGR;
			temp = temp & (~(CLEAR_PLLM_BITS));
			temp = temp | (Configuration->M);

			/*SELECT*/
			RCC->RCC_PLLCFGR &= ~(PLL_SRC_SELECT_MASK);

		}

	} else if (Configuration->SelectedClock == Select_HSE) {

		u8 counter = 0;
		/*TimeOut Check*/
		while (!(RCC->RCC_CR & HSE_READY_MASK) && (counter < 200)) {
			counter++;
		}

		if (RCC->RCC_CR & HSE_READY_MASK) {
			LocalErrorState = RCC_OK;
			/*Insert the 2 bits of the p parameter  */
			uint32 temp = RCC->RCC_PLLCFGR;

			temp = (temp & Clear_PLLP_BITS_MASK) | ((Configuration->P));
			RCC->RCC_PLLCFGR = temp;
			/*N-Configurations*/
			if (((Configuration->N > 1) && (Configuration->N < 433))
					|| ((Configuration->N > 434) && (Configuration->N < 510))) {
				temp = RCC->RCC_PLLCFGR;
				temp = temp & (~(CLEAR_PLLN_BITS << PLLN_BITS_LOCATION));
				temp = temp | (Configuration->N << PLLN_BITS_LOCATION);
				RCC->RCC_PLLCFGR = temp;
			} else {
				LocalErrorState = RCC_NOK;
			}
			/*M-Configs*/
		/*	if ((Configuration->M > 1) && (Configuration->M < 64)) {
				temp = RCC->RCC_PLLCFGR;
				temp = temp & (~(CLEAR_PLLM_BITS));
				temp = temp | (Configuration->M);
			} else {
				LocalErrorState = RCC_NOK;

			}*/

			temp = RCC->RCC_PLLCFGR;
			temp = temp & (~(CLEAR_PLLM_BITS));
			temp = temp | (Configuration->M);
			RCC->RCC_PLLCFGR = temp;
			/*SELECT*/
			RCC->RCC_PLLCFGR |= (PLL_SRC_SELECT_MASK);

		}

	} else {

		LocalErrorState = RCC_NOK;
	}

	return LocalErrorState;

}




RCC_ErrorState_t RCC_SETAHB (u8 prescaler)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;

	volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);

	switch (prescaler)
	{
	case AHB_PRESCALE_2:
	case AHB_PRESCALE_4:
	case AHB_PRESCALE_8:
	case AHB_PRESCALE_16:
	case AHB_PRESCALE_64:
	case AHB_PRESCALE_128:
	case AHB_PRESCALE_256:
	case AHB_PRESCALE_512:
		LocalErrorState = RCC_OK;
		uint32 temp = RCC->RCC_CFGR;
		temp = temp & (~(AHB_CLEAR_MASK)) ;
		temp = temp | (prescaler <<AHB_PRE_BIT_LOCATION);
		RCC->RCC_CFGR = temp;
		break;
	default:
		LocalErrorState = RCC_NOK;


	}
	return LocalErrorState;

}




RCC_ErrorState_t RCC_SETAPB1 (u8 prescaler)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;

	volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);

	switch (prescaler)
	{
	case APB1_PRESCALE_2:
	case APB1_PRESCALE_4:
	case APB1_PRESCALE_8:
	case APB1_PRESCALE_16:
		LocalErrorState = RCC_OK;
		uint32 temp = RCC->RCC_CFGR;
		temp = temp & (~(APB1_CLEAR_MASK)) ;
		temp = temp | (prescaler <<APB1_PRE_BIT_LOCATION);
		RCC->RCC_CFGR = temp;
		break;
	default:
		LocalErrorState = RCC_NOK;


	}
	return LocalErrorState;

}



RCC_ErrorState_t RCC_SETAPB2 (u8 prescaler)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;

	volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);

	switch (prescaler)
	{
	case APB2_PRESCALE_2:
	case APB2_PRESCALE_4:
	case APB2_PRESCALE_8:
	case APB2_PRESCALE_16:
		LocalErrorState = RCC_OK;
		uint32 temp = RCC->RCC_CFGR;
		temp = temp & (~(APB2_CLEAR_MASK)) ;
		temp = temp | (prescaler <<APB2_PRE_BIT_LOCATION);
		RCC->RCC_CFGR = temp;
		break;
	default:
		LocalErrorState = RCC_NOK;


	}
	return LocalErrorState;

}





RCC_ErrorState_t RCC_EnablePeripheral (RCC_Peripheral_Enable_t Peripheral_ID)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;
	if (Peripheral_ID < 128)
	{
		LocalErrorState = RCC_OK;
		volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);
		if ( Peripheral_ID <  RCC_AHB1ENR_MAX_ENUM_ID )
		{
			RCC->RCC_AHB1ENR |= (1<<Peripheral_ID);
		}
		else if (Peripheral_ID <  RCC_AHB2ENR_MAX_ENUM_ID)
		{
			RCC->RCC_AHB2ENR |= (1<< (Peripheral_ID - RCC_AHB1ENR_MAX_ENUM_ID) );
		}
		else if (Peripheral_ID <  RCC_APB1ENR_MAX_ENUM_ID)
		{
			RCC->RCC_APB1ENR |= (1<<(Peripheral_ID - RCC_AHB2ENR_MAX_ENUM_ID));
		}
		else if (Peripheral_ID <  RCC_APB2ENR_MAX_ENUM_ID)
		{
			RCC->RCC_APB2ENR |= (1<<(Peripheral_ID - RCC_APB1ENR_MAX_ENUM_ID));
		}

	}
	else
	{
		/*DO NOTHING*/
	}
	return LocalErrorState;
}


RCC_ErrorState_t RCC_DisablePeripheral (RCC_Peripheral_Enable_t Peripheral_ID)
{
	RCC_ErrorState_t LocalErrorState = RCC_NOK;
	if (Peripheral_ID < 128)
	{
		LocalErrorState = RCC_OK;
		volatile RCC_Peripheral_t* const RCC = (volatile RCC_Peripheral_t*) (0x40023800);
		if ( Peripheral_ID <  RCC_AHB1ENR_MAX_ENUM_ID )
		{
			RCC->RCC_AHB1ENR &= (~(1<<Peripheral_ID));
		}
		else if (Peripheral_ID <  RCC_AHB2ENR_MAX_ENUM_ID)
		{
			RCC->RCC_AHB2ENR &= (~(1<< (Peripheral_ID-RCC_AHB1ENR_MAX_ENUM_ID) ));
		}
		else if (Peripheral_ID <  RCC_APB1ENR_MAX_ENUM_ID)
		{
			RCC->RCC_APB1ENR &= (~(1<<(Peripheral_ID - RCC_AHB2ENR_MAX_ENUM_ID)));
		}
		else if (Peripheral_ID <  RCC_APB2ENR_MAX_ENUM_ID)
		{
			RCC->RCC_APB2ENR &= (~(1<<(Peripheral_ID-RCC_APB1ENR_MAX_ENUM_ID)));
		}

	}
	else
	{
		/*DO NOTHING*/
	}
	return LocalErrorState;
}



