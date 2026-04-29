/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_GTC_H
#define RTL_GTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "utils.h"

/** \defgroup GTC         GTC
  * \brief
  * \{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup GTC_Exported_Functions GTC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Get the counter value of GTC.
 *
 * \param[in] None.
 *
 * \return    The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gtc_demo(void)
 * {
 *     uint32_t counter = GTC_GetCounter();
 * }
 * \endcode
 */
uint32_t GTC_GetCounter(void);

uint32_t GTC_CounterToUs(uint32_t Counter, RoundType round_type);

uint32_t GTC_UsToCounter(uint32_t TimeUs, RoundType round_type);

/** End of GTC_Exported_Functions
  * \}
  */

/** End of GTC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GTC_H */


