/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_NVIC_DEF_H
#define RTL_NVIC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "platform_reg.h"
#include "vector_table.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         NVIC Defines
 *============================================================================*/

/*============================================================================*
 *                         NVIC Private Defines
 *============================================================================*/
#define Peripheral_First_IRQn    PERIPHERAL_ISR_IRQn //TODO BERT
#define Peripheral_Last_IRQn     PERIPHERAL_ISR_IRQn //TODO BERT

#define PeriphGPIO_First_IRQn    SUB_IRQ_DEF(GPIOA0_7_IRQn, 0)
#define PeriphGPIO_Last_IRQn     SUB_IRQ_DEF(GPIOA48_55_IRQn, 55)

#define PeriphTIMER_First_IRQn   SUB_IRQ_DEF(TIMER0_CH0_CH1_IRQn, 0)
#define PeriphTIMER_Last_IRQn    SUB_IRQ_DEF(TIMER0_CH0_CH1_IRQn, 1)

/*============================================================================*
 *                         NVIC Constants
 *============================================================================*/

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_NVIC_DEF_H */
