/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_nvic.h"
#include "section.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define PLATFORM_REG_LPIE *((volatile uint32_t *)(SOC_VENDOR_REG_BASE + PLATFORM_REG_LOW_PRI_INT_MODE))

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
RAM_TEXT_SECTION
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NVIC_InitStruct->NVIC_IRQChannelCmd));

    if (NVIC_InitStruct->NVIC_IRQChannel >= PeriphGPIO_First_IRQn &&
        NVIC_InitStruct->NVIC_IRQChannel <= PeriphGPIO_Last_IRQn ||
        NVIC_InitStruct->NVIC_IRQChannel >= PeriphTIMER_First_IRQn &&
        NVIC_InitStruct->NVIC_IRQChannel <= PeriphTIMER_Last_IRQn)
    {
        NVIC_InitStruct->NVIC_IRQChannel = GET_FIRST_IRQn(NVIC_InitStruct->NVIC_IRQChannel);
    }

    if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
    {
        if (NVIC_InitStruct->NVIC_IRQChannel >= Peripheral_First_IRQn &&
            NVIC_InitStruct->NVIC_IRQChannel <= Peripheral_Last_IRQn)
        {
            PLATFORM_REG_LPIE |= BIT(NVIC_InitStruct->NVIC_IRQChannel - Peripheral_First_IRQn);
            NVIC_InitStruct->NVIC_IRQChannel = PERIPHERAL_ISR_IRQn;
        }

        NVIC_ClearPendingIRQ(NVIC_InitStruct->NVIC_IRQChannel);
        NVIC_SetPriority(NVIC_InitStruct->NVIC_IRQChannel, NVIC_InitStruct->NVIC_IRQChannelPriority);
        NVIC_EnableIRQ(NVIC_InitStruct->NVIC_IRQChannel);
    }
    else
    {
        if (NVIC_InitStruct->NVIC_IRQChannel >= Peripheral_First_IRQn &&
            NVIC_InitStruct->NVIC_IRQChannel <= Peripheral_Last_IRQn)
        {
            PLATFORM_REG_LPIE &= ~BIT(NVIC_InitStruct->NVIC_IRQChannel - Peripheral_First_IRQn);
            if (PLATFORM_REG_LPIE == 0)
            {
                /* Disable Peripheral IRQ Channel */
                NVIC_DisableIRQ(PERIPHERAL_ISR_IRQn);
            }
        }
        else
        {
            /* Disable the Selected IRQ Channels */
            NVIC_DisableIRQ(NVIC_InitStruct->NVIC_IRQChannel);
        }
    }
}


