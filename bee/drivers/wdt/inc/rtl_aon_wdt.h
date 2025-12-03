/**
*****************************************************************************************
*     Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * \file    rtl_aon_wdt.h
  * \brief   This file provides api of aon watch dog timer.
  * \author  renee
  * \date    2023-11-16
  * \version v1.0
  * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_AON_WDT_H
#define RTL_AON_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "utils/rtl_utils.h"
#include "wdt/inc/rtl_wdt.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "wdt/src/rtl87x2g/rtl_aon_wdt_def.h"
#endif

/** \defgroup AON_WDT         AON_WDT
  * \brief
  * \{
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup AON_WDT_Exported_Functions AON_WDT Exported Functions
  * \{
  */

/**
  * \brief  Start AON WDT.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \param  TimeMs
  * \param  Mode \ref WDTMode_Typedef
  * \return true or false.
  */
bool AON_WDT_Start(AON_WDT_TypeDef *AON_WDTx, uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
  * \brief  Disable AON WDT.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \return None.
  */
void AON_WDT_Disable(AON_WDT_TypeDef *AON_WDTx);

/**
  * \brief  Kick AON WDT to restart WDT.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \return None.
  */
void AON_WDT_Kick(AON_WDT_TypeDef *AON_WDTx);

/**
  * \brief  Is AON WDT enable.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \return Is AON WDT enable or not
  */
bool AON_WDT_IsEnable(AON_WDT_TypeDef *AON_WDTx);

/**
  * \brief  Get AON WDT timeout.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \return AON WDT timeout
  */
uint32_t AON_WDT_GetTimeoutMs(AON_WDT_TypeDef *AON_WDTx);

/**
  * \brief  Get AON WDT mode.
  * \param  AON_WDTx \ref AON_WDT_Declaration
  * \return AON WDT mode
  */
WDTMode_TypeDef AON_WDT_GetMode(AON_WDT_TypeDef *AON_WDTx);

/** End of AON_WDT_Exported_Functions
  * \}
  */

/** End of AON_WDT
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_AON_WDT_H */
