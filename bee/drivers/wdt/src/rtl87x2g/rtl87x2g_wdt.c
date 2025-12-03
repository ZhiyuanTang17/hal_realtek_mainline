/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_wdt.c
* \brief    This file provides all the WDT firmware internal functions.
* \details
* \author   Bert
* \date     2023-07-05
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                         Header Files
*============================================================================*/
#include "rtl_wdt.h"
#include "nsc_veneer.h"

/*============================================================================*
 *                         Private Functions
 *============================================================================*/
extern bool WDG_Start(uint32_t TimeMs, WDTMode_TypeDef Mode);
extern bool WDG_Disable();
extern bool WDG_Kick();
extern bool is_WDG_Enable();

/*============================================================================*
 *                         Functions
 *============================================================================*/
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    return WDG_Start(TimeMs, Mode);
}

void WDT_Disable(void)
{
    WDG_Disable();
}

void WDT_Kick(void)
{
    WDG_Kick();
}

bool WDT_IsEnable(void)
{
    return is_WDG_Enable();
}

uint32_t WDT_GetTimeoutMs(void)
{
    uint32_t timeout;

    secure_function_call(WDT_GET_TIMEOUT_MS, &timeout);

    return timeout;
}

WDTMode_TypeDef WDT_GetMode(void)
{
    uint8_t wdt_mode;

    secure_function_call(WDT_GET_MODE, &wdt_mode);

    return (WDTMode_TypeDef)wdt_mode;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

