/*
 * Switch_Config.c
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */

#include "SWITCH/Switch.h"
#include "GPIO/GPIO.h"


const SwitchConfig_t Switches [_Switch_Num] =
{
		[Switch_One] =
		{
				.Pin = PIN2,
				.Port = GPIOA,
				.Connection = SW_Input_PullUp

		}

};
