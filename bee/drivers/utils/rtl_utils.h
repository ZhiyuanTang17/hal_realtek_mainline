/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __RTL_UTILS_H
#define __RTL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                         Header Files
 *============================================================================*/
#include "stdint.h"
#include "stdbool.h"
#include "bitops.h"

/*============================================================================*
 *                         Types
*============================================================================*/
/** @addtogroup IO_UTILS IO_UTILS
  * @{
  */

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
//typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;


/* Uncomment the line below to expanse the "assert_param" macro in the
   Standard Peripheral Library drivers code */
//#define USE_FULL_ASSERT

#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports
  *         the name of the source file and the source line number of the call
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0 : io_assert_failed((uint8_t *)__FILE__, __LINE__))
void io_assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
#define   __I     volatile             /*!< Defines 'read only' permissions */
#else
#define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */


#ifdef __cplusplus
}
#endif

#endif /*__RTL_UTILS_H*/


/** @} */ /* End of group __RTL_UTILS_H */
