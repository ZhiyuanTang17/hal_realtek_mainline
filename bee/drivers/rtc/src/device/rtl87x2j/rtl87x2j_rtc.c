/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_rtc.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

void RTC_ClockInCmd(RTCClockIn_TypeDef ClockIn, FunctionalState NewState)
{
    if (NewState)
    {
        /* Select which externel pad as rtc clock in */
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_VPON_REG1X, RTC_IN_SEL, ClockIn);
    }

    /* Select rtc clock in from external pad */
    PCC_REG_WRITE_BITFIELD(PCC_REG_USER_RTC, R_RTC_GPIO_CLK_SRC_SEL, NewState);
}

void RTC_ClockOutCmd(RTCClockOut_TypeDef ClockOut, FunctionalState NewState)
{
    if (NewState)
    {
        if (ClockOut / 2)
        {
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_VPON_REG1X, PIN_CLK_OUT_SEL_1, ClockOut % 2);
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_3_RTC_CLK_OUT_EN, ENABLE);
        }
        else
        {
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_VPON_REG1X, PIN_CLK_OUT_SEL_0, ClockOut % 2);
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_1_RTC_CLK_OUT_EN, ENABLE);
        }
    }
    else
    {
        if (ClockOut / 2)
        {
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_3_RTC_CLK_OUT_EN, DISABLE);
        }
        else
        {
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_1_RTC_CLK_OUT_EN, DISABLE);
        }
    }
}

/**
  * \brief  Enable/Disable the RTC function of auto reload.
  * \param  index: The comparator number,can be 0 ~ 3.
  * \param  NewState: new state of RTC peripheral.
  *         This parameter can be the following values:
  *         \arg ENABLE: start RTC.
  *         \arg DISABLE: stop RTC.
  * \return None
  */
void RTC_CompAutoReloadCmd(RTCCompIndex_TypeDef index, FunctionalState NewState)
{
    RTC_RELOAD_CTRL_TypeDef rtc_0x34 = {.d32 = RTC->RTC_RELOAD_CTRL};

    if (NewState == ENABLE)
    {
        rtc_0x34.d32 |= BIT(index);
    }
    else
    {
        rtc_0x34.d32 &= (~BIT(index));
    }

    RTC_WRITE(RTC_RELOAD_CTRL, rtc_0x34.d32);
}



