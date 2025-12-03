/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_nvic.c
* \brief    This file provides all the NVIC firmware functions.
* \details
* \author   Yuan Feng
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_nvic.h"
#include "app_section.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Initializes the NVIC peripheral according to the specified
  *         parameters in the NVIC_InitStruct.
  * \param  NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure that contains
  *         the configuration information for the specified NVIC peripheral.
  * \return None
  */
RAM_FUNCTION
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NVIC_InitStruct->NVIC_IRQChannelCmd));

    if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
    {
        if (NVIC_InitStruct->NVIC_IRQChannel >= Peripheral_First_IRQn &&
            NVIC_InitStruct->NVIC_IRQChannel <= Peripheral_Last_IRQn)
        {
            SoC_VENDOR->u_00C.REG_LOW_PRI_INT_EN |= BIT(NVIC_InitStruct->NVIC_IRQChannel -
                                                        Peripheral_First_IRQn);
            NVIC_InitStruct->NVIC_IRQChannel = Peripheral_IRQn;
        }

        NVIC_ClearPendingIRQ(NVIC_InitStruct->NVIC_IRQChannel);
        NVIC_SetPriority(NVIC_InitStruct->NVIC_IRQChannel,
                         NVIC_InitStruct->NVIC_IRQChannelPriority);
        NVIC_EnableIRQ(NVIC_InitStruct->NVIC_IRQChannel);
    }
    else
    {
        if (NVIC_InitStruct->NVIC_IRQChannel >= Peripheral_First_IRQn &&
            NVIC_InitStruct->NVIC_IRQChannel <= Peripheral_Last_IRQn)
        {
            SoC_VENDOR->u_00C.REG_LOW_PRI_INT_EN &= ~BIT(NVIC_InitStruct->NVIC_IRQChannel -
                                                         Peripheral_First_IRQn);

            if (SoC_VENDOR->u_00C.REG_LOW_PRI_INT_EN == 0)
            {
                /* Disable Peripheral IRQ Channel */
                NVIC_DisableIRQ(Peripheral_IRQn);
            }
        }
        else
        {
            /* Disable the Selected IRQ Channels */
            NVIC_DisableIRQ(NVIC_InitStruct->NVIC_IRQChannel);
        }
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
