/*
 * NVIC.c
 *
 *  Created on: Mar 4, 2024
 *      Author: NoteBook
 */



/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "NVIC.h"


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
#define NVIC_STIR_MASK	0x0000000F

#define _0bXXXX_	  0x00000000
#define _0bXXXY_	  0x00000400
#define _0bXXYY_	  0x00000500
#define _0bXYYY_	  0x00000600
#define _0bYYYY_	  0x00000700
#define INTERRUPT_PRIORITY_GROUPING_FIELD_MASK 		0x00000700


/************************************/
/***************Registers************/
/************************************/
#define SCB_AIRCR_REG			(*((uint32_t*)0xE000ED0C))


//Pointer To The Start Address Of the Peripheral
//Will Be Casted During the Implementation to be from NVIC_t
#define NVIC_Peripheral        (void*)(0xE000E100)



/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

/***********************************************************/
/******************Peripheral Register NVIC******************/
/***********************************************************/


/**
 * @brief Structure representing the NVIC peripheral registers.
 *
 * This structure encapsulates the various registers associated with NVIC Peripheral.
 */
typedef struct
{
	uint32_t NVIC_ISER0;
	uint32_t NVIC_ISER1;
	uint32_t NVIC_ISER2;
	uint32_t RESERVED_1[29];
	uint32_t NVIC_ICER0;
	uint32_t NVIC_ICER1;
	uint32_t NVIC_ICER2;
	uint32_t RESERVED_2[29];
	uint32_t NVIC_ISPR0;
	uint32_t NVIC_ISPR1;
	uint32_t NVIC_ISPR2;
	uint32_t RESERVED_3[29];
	uint32_t NVIC_ICPR0;
	uint32_t NVIC_ICPR1;
	uint32_t NVIC_ICPR2;
	uint32_t RESERVED_4[29];
	uint32_t NVIC_IABR0;
	uint32_t NVIC_IABR1;
	uint32_t NVIC_IABR2;
	uint32_t RESERVED_5[61];
	uint32_t NVIC_IPR[24];
	/*uint32_t NVIC_IPR1;
	uint32_t NVIC_IPR2;
	uint32_t NVIC_IPR3;
	uint32_t NVIC_IPR4;
	uint32_t NVIC_IPR5;
	uint32_t NVIC_IPR6;
	uint32_t NVIC_IPR7;
	uint32_t NVIC_IPR8;
	uint32_t NVIC_IPR9;
	uint32_t NVIC_IPR10;
	uint32_t NVIC_IPR11;
	uint32_t NVIC_IPR12;
	uint32_t NVIC_IPR13;
	uint32_t NVIC_IPR14;
	uint32_t NVIC_IPR15;
	uint32_t NVIC_IPR16;
	uint32_t NVIC_IPR17;
	uint32_t NVIC_IPR18;
	uint32_t NVIC_IPR19;
	uint32_t NVIC_IPR20;
	uint32_t NVIC_IPR21;
	uint32_t NVIC_IPR22;
	uint32_t NVIC_IPR23;*/
	uint32_t RESERVED_6[558];
	uint32_t NVIC_STIR;

}NVIC_t;




/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/


NVIC_ErrorState_t EnableInterrupt (Interrupt_ID_t ID)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) )
	{
		 NVIC_LocalErrorState = NVIC_OK;

		 if (ID<= NVIC_I2C1_EV_INTERRUPT)
		 {
			 ((NVIC_t*)NVIC_Peripheral)->NVIC_ISER0 |= (1<<ID);

		 }
		 else if ((ID > NVIC_I2C1_EV_INTERRUPT) && (ID<= NVIC_DMA2_STREAM4_INTERRUPT))
		 {
			 ((NVIC_t*)NVIC_Peripheral)->NVIC_ISER1 |= (1<<(ID-32));



		 }
		 else if ((ID > NVIC_DMA2_STREAM4_INTERRUPT) && (ID<= NVIC_SPI4_INTERRUPT))
		 {
		 	((NVIC_t*)NVIC_Peripheral)->NVIC_ISER2 |= (1<<(ID-64));



		 }

	}
	return NVIC_LocalErrorState;

}

NVIC_ErrorState_t DisableInterrupt (Interrupt_ID_t ID)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) )
	{
		 NVIC_LocalErrorState = NVIC_OK;

		 if (ID<= NVIC_I2C1_EV_INTERRUPT)
		 {
			 ((NVIC_t*)NVIC_Peripheral)->NVIC_ICER0 |= (1<<ID);

		 }
		 else if ((ID > NVIC_I2C1_EV_INTERRUPT) && (ID<= NVIC_DMA2_STREAM4_INTERRUPT))
		 {
			 ((NVIC_t*)NVIC_Peripheral)->NVIC_ICER1 |= (1<<(ID-32));



		 }
		 else if ((ID > NVIC_DMA2_STREAM4_INTERRUPT) && (ID<= NVIC_SPI4_INTERRUPT))
		 {
		 		 	((NVIC_t*)NVIC_Peripheral)->NVIC_ICER2 |= (1<<(ID-64));



		 }


	}
	return NVIC_LocalErrorState;

}


NVIC_ErrorState_t SetPending (Interrupt_ID_t ID)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
		if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) )
		{
			 NVIC_LocalErrorState = NVIC_OK;

			 if (ID<= NVIC_I2C1_EV_INTERRUPT)
			 {
				 ((NVIC_t*)NVIC_Peripheral)->NVIC_ISPR0 |= (1<<ID);

			 }
			 else if ((ID > NVIC_I2C1_EV_INTERRUPT) && (ID<= NVIC_DMA2_STREAM4_INTERRUPT))
			 {
				 ((NVIC_t*)NVIC_Peripheral)->NVIC_ISPR1 |= (1<<(ID-32));



			 }
			 else if ((ID > NVIC_DMA2_STREAM4_INTERRUPT) && (ID<= NVIC_SPI4_INTERRUPT))
			 {
			 	((NVIC_t*)NVIC_Peripheral)->NVIC_ISPR2 |= (1<<(ID-64));
			 }

		}
		return NVIC_LocalErrorState;


}


NVIC_ErrorState_t ClearPending (Interrupt_ID_t ID)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
			if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) )
			{
				 NVIC_LocalErrorState = NVIC_OK;

				 if (ID<= NVIC_I2C1_EV_INTERRUPT)
				 {
					 ((NVIC_t*)NVIC_Peripheral)->NVIC_ICPR0 |= (1<<ID);

				 }
				 else if ((ID > NVIC_I2C1_EV_INTERRUPT) && (ID<= NVIC_DMA2_STREAM4_INTERRUPT))
				 {
					 ((NVIC_t*)NVIC_Peripheral)->NVIC_ICPR1  |= (1<<(ID-32));



				 }
				 else if ((ID > NVIC_DMA2_STREAM4_INTERRUPT) && (ID<= NVIC_SPI4_INTERRUPT))
				 {
				 ((NVIC_t*)NVIC_Peripheral)->NVIC_ICPR2 |= (1<<(ID-64));
				 }

			}
			return NVIC_LocalErrorState;



}



NVIC_ErrorState_t GetActiveState (Interrupt_ID_t ID , uint8_t* ActiveState)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ((ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) && (ActiveState != NULL))
	{
		 NVIC_LocalErrorState = NVIC_OK;
		 if (ID<= NVIC_I2C1_EV_INTERRUPT)
		 {
			 *ActiveState = ( (((NVIC_t*)NVIC_Peripheral)->NVIC_IABR0 & (1<<ID))>>(ID));

		 }
		 else if ((ID > NVIC_I2C1_EV_INTERRUPT) && (ID<= NVIC_DMA2_STREAM4_INTERRUPT))
		 {
		 	((NVIC_t*)NVIC_Peripheral)->NVIC_ICPR0  |= (1<<(ID-32));

		 	*ActiveState = ( (((NVIC_t*)NVIC_Peripheral)->NVIC_IABR1 & (1<<(ID-32)))>>((ID-32)));



		 }

	}

	return NVIC_LocalErrorState;
}

NVIC_ErrorState_t GenerateSoftwareInterrupt (Interrupt_ID_t ID)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) )
	{
		NVIC_LocalErrorState = NVIC_OK;
		uint32_t temp;
		temp = ((NVIC_t*)NVIC_Peripheral)->NVIC_STIR;
		temp = temp & (~NVIC_STIR_MASK);
		/*To make sure that the rest of bits of the ID variable is cleared*/
		ID = ID & NVIC_STIR_MASK;
		temp = temp | ID;
		((NVIC_t*)NVIC_Peripheral)->NVIC_STIR = temp;

	}

	return NVIC_LocalErrorState;
}

/*0:3bits in the IPR register ignore writes*/
NVIC_ErrorState_t SetPriority (Interrupt_ID_t ID , uint8_t PriorityLevel)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ( (ID >= NVIC_WINDOW_WATCHDOG_TIMER) && ( ID <= NVIC_SPI4_INTERRUPT) && (PriorityLevel<128))
	{
		NVIC_LocalErrorState = NVIC_OK;
		*(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4) )= PriorityLevel;


	}

	return NVIC_LocalErrorState;
}


NVIC_ErrorState_t SetPriorityGroupingSplit(uint32_t BinaryPoint)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	if ((BinaryPoint ==_0bXXXX_) || (BinaryPoint ==_0bXXXY_) || (BinaryPoint ==_0bXXYY_) || (BinaryPoint ==_0bXYYY_) || (BinaryPoint ==_0bYYYY_) )
	{
		NVIC_LocalErrorState = NVIC_OK;
		uint32_t temp=0;
		temp = SCB_AIRCR_REG;
		temp = temp & (~INTERRUPT_PRIORITY_GROUPING_FIELD_MASK);
		temp = temp | BinaryPoint;
		SCB_AIRCR_REG = temp;


	}
	else
	{
		/*Do Nothing */
	}

	return NVIC_LocalErrorState;

}

NVIC_ErrorState_t NVIC_EncodePriority(Interrupt_ID_t ID , uint32_t BinaryPoint ,uint32_t PreemptPriority, uint32_t Subpriority)
{
	NVIC_ErrorState_t NVIC_LocalErrorState = NVIC_NOK;
	uint8_t temp=0;
	if ((BinaryPoint ==_0bXXXX_) || (BinaryPoint ==_0bXXXY_) || (BinaryPoint ==_0bXXYY_) || (BinaryPoint ==_0bXYYY_) || (BinaryPoint ==_0bYYYY_) )
{
		NVIC_LocalErrorState = NVIC_OK;
	switch (BinaryPoint)
   {
	case _0bXXXX_:
	{
		temp = *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4));
		temp = temp & (~0b11110000);
		temp = temp | (PreemptPriority<<4);
		*(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4)) = temp;
	}break;

	case _0bXXXY_:
	{
	    temp = *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4));
	    temp = temp & (~0b11100000);
	    temp = temp | (PreemptPriority<<5);
	    temp = temp & (~0b00010000);
	    temp = temp | (Subpriority<<4);
	    *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4)) = temp;
	}break;

	case _0bXXYY_:
	{
		temp = *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4));
		temp = temp & (~0b11000000);
		temp = temp | (PreemptPriority<<6);
		temp = temp & (~0b00110000);
		temp = temp | (Subpriority<<4);
		*(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4)) = temp;
	}break;

	case _0bXYYY_:
	{
	    temp = *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4));
	    temp = temp & (~0b10000000);
	    temp = temp | (PreemptPriority<<6);
	    temp = temp & (~0b01110000);
	    temp = temp | (Subpriority<<4);
		*(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4)) = temp;
	}break;
	case _0bYYYY_:
	{
	    temp = *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4));
	    temp = temp & (~0b11110000);
	    temp = temp | (Subpriority<<4);
	    *(((uint8_t*)((NVIC_t*)NVIC_Peripheral)->NVIC_IPR[ID/4])+((ID%4)*4)) = temp;
	}break;

   }
}


	return NVIC_LocalErrorState;


}
