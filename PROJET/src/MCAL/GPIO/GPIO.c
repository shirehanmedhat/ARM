/*
 * GPIO.c
 *
 *  Created on: Feb 18, 2024
 *      Author: NoteBook
 */

#include "GPIO/GPIO.h"

#define MODER_INPUT_MASK  0b00
#define MODER_OUTPUT_MASK 0b01
#define MODER_AF_MASK	  0b10
#define MOER_ANALOG_MASK  0b11


#define PUPDR_FLOATING	0b00
#define PUPDR_PullUp	0b01
#define PUPDR_PullDown	0b10
#define RESERVED		0b11

#define OTYPER_PUSH_PULL_MASK	0
#define OTYPER_OPEN_DRAIN_MASK	1
//#define X 0

#define MODER_MASK  0x00000003
#define PUPDR_MASK  0x0000000C
#define OTYPER_MASK 0x00000010
#define OUTPUT		0x00000001
#define TWO_BITS_MASK 0x00000003

typedef struct
{
	uint32 GPIOx_MODER;
	uint32 GPIOx_OTYPER;
	uint32 GPIOx_OSPEEDR;
	uint32 GPIOx_PUPDR;
	uint32 GPIOx_IDR;
	uint32 GPIOx_ODR;
	uint32 GPIOx_BSRR;
	uint32 GPIOx_LCKR;
	uint32 GPIOx_AFRL;
	uint32 GPIOx_AFRH;

}GPIO_Peripheral_t;

#define NUM_OF_PORTS	3

/*volatile GPIO_Peripheral_t* const  GPIO[NUM_OF_PORTS] =
{
		[GPIO_PORTA] = (volatile GPIO_Peripheral_t*)(0x40020000),
		[GPIO_PORTB] = (volatile GPIO_Peripheral_t*)(0x40020400),
		[GPIO_PORTC] = (volatile GPIO_Peripheral_t*)(0x40020800)

};
*/





GPIO_EnumErrorState GPIO_initPin ( GPIO_strPin_t* Pin)
{
	GPIO_EnumErrorState GPIO_LocalErrorState = GPIO_NOK;
	if (Pin != NULL)
	{
		GPIO_LocalErrorState = GPIO_OK;

		/*Get The MODER Register by the MODER Mask */
		uint32 GetBits =  (Pin->Mode & MODER_MASK);
		/*Insert Getted Value in the*/
		uint32 temp =((GPIO_Peripheral_t*)Pin->Port)->GPIOx_MODER;
		temp = temp & (~((MODER_MASK<< (2*(Pin->Pin)))));
		temp = (temp | (GetBits<<(2*(Pin->Pin))));
		((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_MODER = temp;
		switch (GetBits)
		{
			case OUTPUT:
			{
				temp = ((GPIO_Peripheral_t*)Pin->Port)->GPIOx_OSPEEDR;
				temp = temp & (~(TWO_BITS_MASK<< (2*(Pin->Pin))));
				temp = temp | (Pin->speed  << (2*(Pin->Pin)));
				((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_OSPEEDR = temp;
			}break;
			default:
			{
				/*Reset Value For Speed*/
			}

		}

		/*Get The GPIOx_PUPDR Register by the GPIOx_PUPDR Mask */
		GetBits =  ((Pin->Mode & PUPDR_MASK)>>2);
		temp = ((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_PUPDR;
		temp = temp & (~((TWO_BITS_MASK<< (2*(Pin->Pin)))));
		temp = temp | (GetBits<<(2*(Pin->Pin)));
		((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_PUPDR = temp;

		/*Get The GPIOx_OTYPER Register by the GPIOx_OTYPER Mask */
		GetBits =  ((Pin->Mode & OTYPER_MASK)>>4);
		temp = ((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_OTYPER;
		temp = temp & (~((TWO_BITS_MASK<< (Pin->Pin))));
		temp = temp | (GetBits<<(Pin->Pin));
		((GPIO_Peripheral_t*)(Pin->Port))->GPIOx_OTYPER = temp;


	}
	else
	{
		/*Do Nothing*/
	}
	return GPIO_LocalErrorState;

}



GPIO_EnumErrorState GPIO_GetPinValue (uint32 Pin , void* Port , uint32* ReadedValue)
{
	GPIO_EnumErrorState GPIO_LocalErrorState = GPIO_NOK;
	if ( (Pin >= PIN0) && (Pin <= PIN16) )
	{
		GPIO_LocalErrorState = GPIO_OK;
		/*This line returns the bit value at its location but we want to return 1 or 0 only*/
		*ReadedValue = ((GPIO_Peripheral_t*)Port)->GPIOx_IDR & (Pin);

		if (*ReadedValue > GPIO_LOW )
		{
			*ReadedValue = GPIO_HIGH;
		}
		else
		{
			*ReadedValue = GPIO_LOW;
		}


	}
	else
	{
		/*DO Nothing*/
	}
	return GPIO_LocalErrorState;
}


GPIO_EnumErrorState GPIO_SetPinValue (uint32 Pin , void* Port , uint32 OutValue)
{
	GPIO_EnumErrorState GPIO_LocalErrorState = GPIO_NOK;
	if ( (Pin >= PIN0) && (Pin <= PIN16) )
	{
		GPIO_LocalErrorState = GPIO_OK;
		switch (OutValue)
		{
		case GPIO_HIGH:
			((GPIO_Peripheral_t*)Port)->GPIOx_ODR = ((GPIO_Peripheral_t*)Port)->GPIOx_ODR | Pin;
			break;
		case GPIO_LOW:
			((GPIO_Peripheral_t*)Port)->GPIOx_ODR = ((GPIO_Peripheral_t*)Port)->GPIOx_ODR & (~Pin);
			break;
		default:
			GPIO_LocalErrorState = GPIO_NOK;
			break;

		}


	}
	else
	{

		/*Do Nothing*/
	}

	return GPIO_LocalErrorState;
}

