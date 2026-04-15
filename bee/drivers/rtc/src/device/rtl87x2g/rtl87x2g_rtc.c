/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_rtc.h"

/*============================================================================*
 *                        Private Defines
 *============================================================================*/
#define RTC_IN_SEL             *((volatile uint32_t *)0x4000080C)
#define RTC_IN_32K             *((volatile uint32_t *)0x40000814)
#define RTC_GPIO_32K           *((volatile uint32_t *)0x40000C84)
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Select source clock to gpio input of RTC.
  * \param  gpio: the selected gpio.
  * \return None
  */
void RTC_SelectSrcToGpioInput(RTCInSel_TypeDef rtc_in)
{
    /* Set en_gpio_32k if any muxes need USE_32K_GPIO_IN */
    RTC_IN_SEL |= BIT10;

    /* Set XTAL32K_GPIO_SEL if rtc_in choose PAD_32KXI_RTC_IN */
    if (rtc_in == PAD_32KXI_RTC_IN)
    {
        RTC_GPIO_32K |= BIT6;
    }
    else
    {
        RTC_GPIO_32K &= ~BIT6;
    }
    /* Choose rtc_in PAD */
    RTC_IN_SEL &= ~((rtc_in & 0x3) << 8);
    RTC_IN_SEL |= (rtc_in & 0x3) << 8;

    /* Open SEL_32K_GPIO_rtc */
    RTC_IN_32K |= BIT10;
}


