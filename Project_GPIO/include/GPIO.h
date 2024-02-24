/*
 * GPIO.h
 *
 *  Created on: Feb 18, 2024
 *      Author: NoteBook
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef unsigned char u8;
typedef unsigned int uint32;
#define NULL ((void *)0)

/****************************************************#DEFINES*************************************************/


/****************************************************TYPES***************************************************/

typedef enum
{
	GPIO_NOK,
	GPIO_OK
}GPIO_EnumErrorState;

/****************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter : uint32 Port
 *Representation      : The Available Ports
 *
/*****************************************************/
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2


/****************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter :	uint32 Pin
 *Representation      : The Available Pins Wrapping The Masks
 *
/*****************************************************/

#define PIN0  0x00000001
#define PIN1  0x00000002
#define PIN2  0x00000004
#define PIN3  0x00000008
#define PIN4  0x00000010
#define PIN5  0x00000020
#define PIN6  0x00000040
#define PIN7  0x00000080
#define PIN8  0x00000100
#define PIN9  0x00000200
#define PIN10 0x00000400
#define PIN11 0x00000800
#define PIN12 0x00001000
#define PIN13 0x00002000
#define PIN14 0x00004000
#define PIN15 0x00008000
#define PIN16 0x00010000


/****************************************************
 *Input Parameter Options of Function : GPIO_SetPinValue();
 *Input Parameter Options of Function : GPIO_GetPinValue();
 *The Input Parameter :	uint32 OutValue
 *Representation      : The Logical Pin Values.
 *
/*****************************************************/

#define GPIO_LOW	0
#define GPIO_HIGH	1


/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	uint32 Mode  >> GPIO_strPin_t
 *Representation      : The Available Modes Wrapping The Masks
 *
/*****************************************************/
#define Input_Floating  		 			    0b00000000000000000000000000000000
#define Input_PullUp     					    0b00000000000000000000000000000100
#define Input_PullDown  					    0b00000000000000000000000000001000
#define Analog           		 			    0b00000000000000000000000000000011
#define Output_OpenDrain 		 			    0b00000000000000000000000000010001
#define Output_OpenDrain_PullUp  			    0b00000000000000000000000000010101
#define Output_OpenDrain_PullDown			    0b00000000000000000000000000011001

#define Output_PushPull          			    0b00000000000000000000000000000001
#define Output_PushPull_PullUp	 			    0b00000000000000000000000000000101
#define Output_PushPull_PullDown 			    0b00000000000000000000000000001001

#define AlternateFunction_PushPull 			    0b00000000000000000000000000000010
#define AlternateFunction_PushPull_PullUp       0b00000000000000000000000000000110
#define AlternateFunction_PushPull_PullDown     0b00000000000000000000000000001010


#define AlternateFunction_OpenDrain             0b00000000000000000000000000010010
#define AlternateFunction_OpenDrain_PullUp      0b00000000000000000000000000010110
#define AlternateFunction_OpenDrain_PullDown    0b00000000000000000000000000011010



/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	uint32 Speed  >> GPIO_strPin_t
 *Representation      : The Available Speeds Wrapping The Masks
 *
/*****************************************************/


#define Low_Speed	 	0
#define Medium_Speed	1
#define High_Speed		2
#define Very_High_Speed	3


/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	GPIO_Pin_t Pin  >> GPIO_strPin_t
 *Representation      : The Available Pins , an enum type for Algorithm wise
 *
/*****************************************************/

typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16
}GPIO_Pin_t;


/****************************************************
 *Input Parameter Options of Function : GPIO_initPin ( GPIO_strPin_t* Pin);
 *The Input Parameter :	GPIO_strPin_t
 *Representation      : Representing the Pin Number , Port , Mode and Speed.
 *
/*****************************************************/

typedef struct {

	GPIO_Pin_t Pin;
	uint32 Port;
	uint32 Mode;
	uint32 speed;
}GPIO_strPin_t;




/********************************************FUNCTION_PROTOTYPES*********************************************/

/*************************/
/* GPIO Initialization Function */
/*************************/
/*
 * @input parameters: GPIO_strPin_t* Pin (Pointer to a structure containing pin information)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Initializes a GPIO pin based on the provided configuration in the GPIO_strPin_t structure.
 */
GPIO_EnumErrorState GPIO_initPin ( GPIO_strPin_t* Pin);


/*************************/
/* GPIO Set Pin Value Function */
/*************************/
/*
 * @input parameters: uint32 Pin (Pin number), uint32 Port (Port number), uint32 OutValue (Logical pin value)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Sets the logical value (GPIO_LOW or GPIO_HIGH) of a specified pin in a given GPIO port.
 */

GPIO_EnumErrorState GPIO_SetPinValue (uint32 Pin , uint32 Port , uint32 OutValue);

/*************************/
/* GPIO Get Pin Value Function */
/*************************/
/*
 * @input parameters: uint32 Pin (Pin number), uint32 Port (Port number), uint32* ReadedValue (Pointer to store the read value)
 * @output parameters: GPIO_EnumErrorState (Error state indicating success or failure)
 * @description: Reads the logical value of a specified pin in a given GPIO port and stores it in the variable pointed to by ReadedValue.
 */

GPIO_EnumErrorState GPIO_GetPinValue (uint32 Pin , uint32 Port , uint32* ReadedValue );
#endif /* GPIO_H_ */
