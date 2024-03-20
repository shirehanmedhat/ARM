/*
 * SYSTICK.h
 *
 *  Created on: Mar 12, 2024
 *      Author: NoteBook
 */

#ifndef MCAL_SYSTICK_SYSTICK_H_
#define MCAL_SYSTICK_SYSTICK_H_
/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/
#include"STD_TYPES.h"


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/

/**
 * @brief Clock Source Selection Options for the SysTick timer.
 *
 * These macros define options for selecting the clock source for the SysTick timer.
 */
#define AHB_8	0
#define AHB		1

/**< Default clock frequency for the SysTick timer. */
#define STK_CLOCK	2000000

/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/


/**
 * @brief Pointer to a callback function TYPE for the SysTick timer.
 *
 * This typedef defines a pointer to a function that can serve as a callback for the SysTick timer.
 */
typedef void (*SysTick_CB_t) (void);


/**
 * @brief Error states for SysTick functions.
 *
 * This enumeration defines error states that indicate the success or failure of SysTick functions.
 */
typedef enum
{
	STK_NOK,
	STK_OK
}STK_ErrorState_t;



/********************************************************************************************************/
/************************************************APIs****************************************************/
/********************************************************************************************************/



/**
 * @brief Initialize the SysTick timer.
 *
 * This function initializes the SysTick timer with the specified clock source.
 *
 * @param[in] ClkSource Clock source for the SysTick timer.
 * @return STK_ErrorState_t: Error state indicating success or failure.
 */
STK_ErrorState_t STK_Init(uint32_t ClkSource);



/**
 * @brief Set the time value for the SysTick timer in milliseconds.
 *
 * This function sets the time value for the SysTick timer in milliseconds.
 *
 * @param[in] TimeValue Time value in milliseconds.
 * @return STK_ErrorState_t: Error state indicating success or failure.
 */
STK_ErrorState_t STK_SetTime_ms(uint32_t TimeValue);



/**
 * @brief Enable the SysTick timer interrupt.
 *
 * This function enables the interrupt for the SysTick timer.
 */
void STK_EnableInterrupt(void);


/**
 * @brief Disable the SysTick timer interrupt.
 *
 * This function disables the interrupt for the SysTick timer.
 */
void STK_DisableInterrupt(void);


/**
 * @brief Start the SysTick timer.
 *
 * This function starts the SysTick timer.
 */
void STK_Start(void);


/**
 * @brief Stop the SysTick timer.
 *
 * This function stops the SysTick timer.
 */
void STK_Stop(void);


/**
 * @brief Set a callback function for the SysTick timer.
 *
 * This function sets a callback function to be called when the SysTick timer triggers.
 *
 * @param[in] cbf Pointer to the callback function.
 * @return STK_ErrorState_t: Error state indicating success or failure.
 */
STK_ErrorState_t STK_SetCallBack (SysTick_CB_t CBF);

#endif /* MCAL_SYSTICK_SYSTICK_H_ */
