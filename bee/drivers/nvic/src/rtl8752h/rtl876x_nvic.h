/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl876x_nvic.h
* \brief    The header file of NVIC  driver.
* \details  This file provides all NVIC firmware functions.
* \author   elliot chen
* \date     2024-01-22
* \version  v1.0
* *********************************************************************************************************
*/

#ifndef _RTL876X_NVIC_H_
#define _RTL876X_NVIC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup  IO          Peripheral Drivers
 * \defgroup    NVIC        NVIC
 * \brief       Manage the NVIC peripheral functions.
 * \ingroup     IO
 */

/*============================================================================*
 *                         Includes
 *============================================================================*/
#include "rtl876x.h"

/*============================================================================*
 *                         Types
 *============================================================================*/
/**
 * \defgroup    NVIC_Exported_Types NVIC Exported Types
 *
 * \ingroup     NVIC
 */

/**
 * \brief       NVIC init structure definition
 *
 * \ingroup     NVIC_Exported_Types
 */

typedef struct
{
    IRQn_Type NVIC_IRQChannel;              /*!< Specifies the IRQ channel to be enabled or disabled.
                                                    This parameter can be a value of \ref IRQn_Type in rtl876x.h. */
    uint32_t NVIC_IRQChannelPriority;       /*!< Specifies the priority for the IRQ channel.
                                                    This parameter can be a value between 0 and x as described in the table.*/
    FunctionalState
    NVIC_IRQChannelCmd;     /*!< Enabled or disabled the IRQ channel defined in NVIC_IRQChannel.*/
} NVIC_InitTypeDef;

/** End of NVIC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * \defgroup    NVIC_Exported_Functions NVIC Exported Functions
 * \{
 * \ingroup     NVIC
 */

/**
 * \brief   Initializes the NVIC peripheral according to the specified
 *          parameters in NVIC_InitStruct.
 * \param[in]   NVIC_InitStruct: Pointer to a NVIC_InitTypeDef structure that contains
 *              the configuration information for the specified NVIC peripheral.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void nvic_config(void)
 * {
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = RTC_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * \endcode
 */
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct);

/**
 * \brief    Clear Pending Interrupt. This api is valid for both primary and secondary interrupt.
 * \param[in]    IRQn  External interrupt number. Value cannot be negative.
 * \return  None.
 *
 * <b>Example usage</b>
 * If you want to clear the pending bit of a secondary interrupt (e.g. Qdecode, KeyScan, WatchDog, ...),
 * use NVIC_ClearPendingIRQ_Generic instead of CMSIS original api NVIC_ClearPendingIRQ.
 *
 * If you want to clear the pending bit of a primary interrupt (e.g. System, UART0, GDMA0_Channel0, ...),
 * use CMSIS original api NVIC_ClearPendingIRQ.
 *
 * Note: A secondary interrupt's IRQ number is no less than Peripheral_First_IRQn.
 * Check rtl876x.h for more details about primary and secondary interrupts.
 *
 * \code{.c}
 *
 * void nvic_clear_pending_demo(void)
 * {
 *     NVIC_ClearPendingIRQ_Generic(WDT_IRQn);//Interrupt WDT_IRQn is a secondary interrupt.
 * }
 * \endcode
 */
void NVIC_ClearPendingIRQ_Generic(IRQn_Type IRQn);

/** End of NVIC_Exported_Functions
  * \}
  */

/** End of NVIC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_NVIC_H_ */


/******************* (C) COPYRIGHT 2024 Realtek Semiconductor Corporation *****END OF FILE****/

