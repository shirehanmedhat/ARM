/*
 * Switch.c
 *
 *  Created on: Feb 24, 2024
 *      Author: NoteBook
 */
#include "SWITCH/SWITCH.h"
#include "GPIO/GPIO.h"
extern const SwitchConfig_t Switches [_Switch_Num];
SWITCH_EnumErrorState Switch_init(void)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_OK;
	GPIO_strPin_t Temp_Switch ;

	for (u8 indx =0 ; indx< _Switch_Num ; indx++)
	{
		Temp_Switch.Mode = Switches[indx].Connection;
		Temp_Switch.Port = Switches[indx].Port;
		Temp_Switch.Pin = Switches[indx].Pin;
		GPIO_initPin (&Temp_Switch);

	}


	return SWITCH_LocalErrorState;

}


SWITCH_EnumErrorState GetSwitchValue(u8 Switch , uint32* ReadedValue)
{
	SWITCH_EnumErrorState  SWITCH_LocalErrorState = SWITCH_NOK;
	if (ReadedValue != NULL)
	{
		uint32 tempRead=0;
		SWITCH_LocalErrorState = SWITCH_OK;
		switch(Switches[Switch].Connection)
		{
		case SW_Input_PullUp:
			GPIO_GetPinValue (SWITCH_TO_SET , Switches[Switch].Port , &tempRead );
			*ReadedValue = !tempRead;
			break;
		case SW_Input_PullDown:
			GPIO_GetPinValue (SWITCH_TO_SET , Switches[Switch].Port , ReadedValue );
			break;
		default:
			break;
		}

	}
	else
	{
		/*Do Nothing*/
	}




	return SWITCH_LocalErrorState;


}



