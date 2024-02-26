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
	Temp_Switch.Mode = SW_Input_PullUp ;

	for (u8 indx =0 ; indx< _Switch_Num ; indx++)
	{
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
		SWITCH_LocalErrorState = SWITCH_OK;
		GPIO_GetPinValue (Switches[Switch].Pin , Switches[Switch].Port , ReadedValue );

	}
	else
	{
		/*Do Nothing*/
	}




	return SWITCH_LocalErrorState;


}



