/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_grtc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F) // Force off 0x0A

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
void GRTC_ClockAutoModeCmd(FunctionalState Newstate)
{
    if (Newstate == ENABLE)
    {
        GRTC->GRTC_QACTIVE_CTRL &= ~GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }
    else
    {
        GRTC->GRTC_QACTIVE_CTRL |= GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
bool GRTC_IsSupportRAPComp(GRTCCompIndex_TypeDef Index)
{
    return true;
}
#endif


