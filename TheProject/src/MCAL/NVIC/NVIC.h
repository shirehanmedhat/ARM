/*
 * NVIC.h
 *
 *  Created on: Mar 4, 2024
 *      Author: NoteBook
 */

#ifndef MCAL_NVIC_NVIC_H_
#define MCAL_NVIC_NVIC_H_


/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/




/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
#define INTERRUPT_NOT_ACTIVE	0
#define INTERRUPT_ACTIVE	    1


/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

/***************************************************/
/**********************Enums************************/
/***************************************************/


/**
 * @brief Enumeration Returned Error State For NVIC.
 *
 */
typedef enum
{
	NVIC_NOK,
	NVIC_OK
}NVIC_ErrorState_t;



/**
 * @brief Enumeration defining NVIC Interrupts.
 *
 */

typedef enum
{
  NVIC_WINDOW_WATCHDOG_TIMER    ,
  NIVC_EXTERNAL_LINE16		    ,
  NIVC_EXTERNAL_LINE21		    ,
  NIVC_EXTERNAL_LINE22		    ,
  NIVC_FLASH_INTERRUPT		    ,
  NVIC_RCC_INTERRUPT		    ,
  NVIC_EXT0_INTERRRUPT		    ,
  NVIC_EXT1_INTERRRUPT		    ,
  NVIC_EXT2_INTERRRUPT		    ,
  NVIC_EXT3_INTERRRUPT		    ,
  NVIC_EXT4_INTERRRUPT		    ,
  NVIC_DMA1_STREAM0			    ,
  NVIC_DMA1_STREAM1			    ,
  NVIC_DMA1_STREAM2			    ,
  NVIC_DMA1_STREAM3			    ,
  NVIC_DMA1_STREAM4			    ,
  NVIC_DMA1_STREAM5			    ,
  NVIC_DMA1_STREAM6             ,
  NVIC_ADC_INTERRUPT            ,
  NVIC_EXT9_INTERRUPT = 23      ,
  NVIC_TIM1_BRK_INTERRUPT       ,
  NVIC_TIM1_UP_INTERRUPT        ,
  NVIC_TIMI1_TRG_INTERRUPT      ,
  NVIC_TIMI1_CC_INTERRUPT       ,
  NVIC_TIMI2_INTERRUPT          ,
  NVIC_TIMI3_INTERRUPT          ,
  NVIC_TIMI4_INTERRUPT          ,
  NVIC_I2C1_EV_INTERRUPT        ,
  NVIC_I2C1_ER_INTERRUPT        ,
  NVIC_I2C2_EV_INTERRUPT        ,
  NVIC_I2C2_ER_INTERRUPT        ,
  NVIC_SPI1_INTERRUPT           ,
  NVIC_SPI2_INTERRUPT           ,
  NVIC_USART1_INTERRUPT         ,
  NVIC_USART2_INTERRUPT         ,
  NVIC_EXTI15_INTERRUPT  =  40      ,
  NVIC_EXTI17_INTERRUPT             ,
  NVIC_EXTI18_INTERRUPT             ,
  NVIC_DMA1_INTERRUPT  = 47         ,
  NVIC_SDIO_INTERRUPT   = 49        ,
  NVIC_TIM5_INTERRUPT               ,
  NVIC_SPI3_INTERRUPT               ,
  NVIC_DMA2_STREAM0_INTERRUPT = 56  ,
  NVIC_DMA2_STREAM1_INTERRUPT       ,
  NVIC_DMA2_STREAM2_INTERRUPT       ,
  NVIC_DMA2_STREAM3_INTERRUPT       ,
  NVIC_DMA2_STREAM4_INTERRUPT  	    ,
  NVIC_OTG_FS_INTERRUPT      = 67   ,
  NVIC_DMA2_STREAM5_INTERRUPT   ,
  NVIC_DMA2_STREAM6_INTERRUPT   ,
  NVIC_DMA2_STREAM7_INTERRUPT   ,
  NVIC_USART6_INTERRUPT         ,
  NVIC_I2C3_EV_INTERRUPT        ,
  NVIC_I2C3_ER_INTERRUPT        ,
  NVIC_FPU_INTERRUPT       = 81 ,
  NVIC_SPI4_INTERRUPT     = 84
}Interrupt_ID_t;



/**
 * @brief Enable a specific interrupt.
 *
 * This function enables the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to be enabled.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t EnableInterrupt (Interrupt_ID_t ID);


/**
 * @brief Disable a specific interrupt.
 *
 * This function disables the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to be disabled.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t DisableInterrupt (Interrupt_ID_t ID);

/**
 * @brief Mark a specific interrupt as pending.
 *
 * This function sets the pending status for the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to be marked as pending.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t SetPending (Interrupt_ID_t ID);

/**
 * @brief Clear the pending status of a specific interrupt.
 *
 * This function clears the pending status for the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to clear as pending.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t ClearPending (Interrupt_ID_t ID);

/**
 * @brief Get the active state of a specific interrupt.
 *
 * This function retrieves the active state of the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to query.
 * @param[out] ActiveState Pointer to a variable to store the active state.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t GetActiveState (Interrupt_ID_t ID , uint8_t* ActiveState);

/**
 * @brief Generate a software interrupt for a specific interrupt.
 *
 * This function generates a software interrupt for the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to be generated.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t GenerateSoftwareInterrupt (Interrupt_ID_t ID);


/**
 * @brief Set the priority level for a specific interrupt.
 *
 * This function sets the priority level for the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt to set the priority.
 * @param[in] PriorityLevel Priority level for the interrupt.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t SetPriority (Interrupt_ID_t ID , uint8_t PriorityLevel);



/**
 * @brief Set the priority grouping for interrupts with split priority.
 *
 * This function sets the priority grouping for interrupts with split priority.
 * To determine the number of bits for Preemption group and the SubGroup
 *
 * @param[in] BinaryPoint Binary point position for priority grouping.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t SetPriorityGroupingSplit(uint32_t BinaryPoint);


/**
 * @brief Encode priority information for a specific interrupt.
 *
 * This function encodes priority information for the specified interrupt identified by the provided Interrupt_ID_t.
 *
 * @param[in] ID Identifier for the interrupt.
 * @param[in] BinaryPoint Binary point position for the priority.
 * @param[in] PreemptPriority Preemptive priority for the interrupt.
 * @param[in] Subpriority Subpriority for the interrupt.
 * @return NVIC_ErrorState_t: Error state indicating success or failure.
 */
NVIC_ErrorState_t NVIC_EncodePriority(Interrupt_ID_t ID , uint32_t BinaryPoint ,uint32_t PreemptPriority, uint32_t Subpriority);

//NVIC_ErrorState_t SetPriority (Interrupt_ID_t Preeemption , Interrupt_ID_t SubGroup ,ID);
//NVIC_ErrorState_t SetSubGroupNumber (Interrupt_ID_t ID);





#endif /* MCAL_NVIC_NVIC_H_ */
