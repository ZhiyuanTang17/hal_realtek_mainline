/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_wdt.c
* \brief    This file provides all the AON WDT firmware internal functions.
* \details
* \author   Bert
* \date     2023-07-05
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                         Header Files
*============================================================================*/
#include "rtl_aon_wdt.h"
#include "nsc_veneer.h"

/*============================================================================*
 *                         Private Functions
 *============================================================================*/
extern bool aon_wdg_start(uint32_t TimeMs, WDTMode_TypeDef Mode);
extern void aon_wdg_disable();
extern void aon_wdg_kick();

/*============================================================================*
 *                         Functions
 *============================================================================*/
bool AON_WDT_Start(AON_WDT_TypeDef *AON_WDTx, uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    if (Mode == INTERRUPT_CPU)
    {
        return false;
    }

    aon_wdg_start(TimeMs, Mode);
    aon_wdg_kick();

    return true;
}

void AON_WDT_Disable(AON_WDT_TypeDef *AON_WDTx)
{
    aon_wdg_disable();
}

void AON_WDT_Kick(AON_WDT_TypeDef *AON_WDTx)
{
    aon_wdg_kick();
}

bool AON_WDT_IsEnable(AON_WDT_TypeDef *AON_WDTx)
{
    bool is_enable;

    secure_function_call(AON_WDT_IS_ENABLE, &is_enable);

    return is_enable;
}

uint32_t AON_WDT_GetTimeoutMs(AON_WDT_TypeDef *AON_WDTx)
{
    uint32_t timeout;

    secure_function_call(AON_WDT_GET_TIMEOUT_MS, &timeout);

    return timeout;
}

WDTMode_TypeDef AON_WDT_GetMode(AON_WDT_TypeDef *AON_WDTx)
{
    uint8_t wdt_mode;

    secure_function_call(AON_WDT_GET_MODE, &wdt_mode);

    return (WDTMode_TypeDef)wdt_mode;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

