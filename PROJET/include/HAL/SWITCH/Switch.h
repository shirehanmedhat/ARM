/*
 * Switch.h
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */

#ifndef HAL_SWITCH_SWITCH_H_
#define HAL_SWITCH_SWITCH_H_
#include "SWITCH/Switch_Config.h"
typedef unsigned char u8;
typedef unsigned int uint32;
#define NULL ((void *)0)
#define SWITCH_TO_SET	PIN1
/*********Connection Options ****************/
#define SW_Input_Floating  		 			    0b00000000000000000000000000000000
#define SW_Input_PullUp     					0b00000000000000000000000000000100
#define SW_Input_PullDown  					    0b00000000000000000000000000001000
/********************************************/


#define SWITCH_PRESSED	1
#define SWITCH_RELEASED	0
typedef enum
{
	SWITCH_NOK,
	SWITCH_OK
}SWITCH_EnumErrorState;

typedef struct
{
	void* Port;
	uint32 Pin;
	uint32 Connection;

}SwitchConfig_t;



SWITCH_EnumErrorState Switch_init(void);
SWITCH_EnumErrorState GetSwitchValue(u8 Switch , uint32* ReadedValue);

#endif /* HAL_SWITCH_SWITCH_H_ */
