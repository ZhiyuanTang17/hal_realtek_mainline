/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPPWM_DEF_H
#define RTL_LPPWM_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          LPPWM Defines
 *============================================================================*/

/*============================================================================*
 *                          LPPWM Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t LPPWM_CH0_CTL;                    /*!< 0x00 */
    __IO uint32_t LPPWM_CH0_P0_H;                   /*!< 0x04 */
    __IO uint32_t LPPWM_CH0_P0_L;                   /*!< 0x08 */
    __I  uint32_t LPPWM_CH0_CURRENT;                /*!< 0x0C */
    __I  uint32_t LPPWM_VERSION;                    /*!< 0x10 */
    __IO uint32_t LPPWM_QACTIVE_MANUAL_CTRL;        /*!< 0x14 */
} LPPWM_TypeDef;

/*============================================================================*
 *                          LPPWM Declaration
 *============================================================================*/
#define LPPWM_REG_BASE           (SYSON_BASE + AON_REG_LPPWM_CH0_CTL)
#define LPPWM                    ((LPPWM_TypeDef *) LPPWM_REG_BASE)

#define IS_LPPWM_PERIPH(PERIPH)  ((PERIPH) == LPPWM)

/*============================================================================*
 *                          LPPWM Private Types
 *============================================================================*/

/*============================================================================*
 *                          LPPWM Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   0       R/W    lppwm_ch0_reg_rst_n         1'h0
   1       R/W    lppwm_ch0_en                1'h0
   2       R/W    lppwm_ch0_polarity          1'h0
   31:3    R      rsvd                        29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lppwm_ch0_reg_rst_n: 1;
        uint32_t lppwm_ch0_en: 1;
        uint32_t lppwm_ch0_polarity: 1;
        const uint32_t reserved_0: 29;
    } b;
} LPPWM_CH0_CTL_TypeDef;


/* 0x04
   15:0    R/W    lppwm_ch0_p0_h              16'h0
   31:16   R      rsvd                        16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lppwm_ch0_p0_h: 16;
        const uint32_t reserved_0: 16;
    } b;
} LPPWM_CH0_P0_H_TypeDef;


/* 0x08
   15:0    R/W    lppwm_ch0_p0_l              16'h0
   31:16   R      rsvd                        16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lppwm_ch0_p0_l: 16;
        const uint32_t reserved_0: 16;
    } b;
} LPPWM_CH0_P0_L_TypeDef;


/* 0x0C
   15:0    R      lppwm_ch0_current           16'h0
   31:16   R      rsvd                        16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lppwm_ch0_current: 16;
        const uint32_t reserved_0: 16;
    } b;
} LPPWM_CH0_CURRENT_TypeDef;


/* 0x10
   31:0    R      lppwm_version               32'h2305230A
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lppwm_version: 32;
    } b;
} LPPWM_VERSION_TypeDef;


/* 0x14
   0       R/W    lppwm_clk_qactive_man_data  1'h0
   1       R/W    lppwm_clk_qactive_man_enable 1'h0
   31:2    R      rsvd                        30'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lppwm_clk_qactive_man_data: 1;
        uint32_t lppwm_clk_qactive_man_enable: 1;
        const uint32_t reserved_0: 30;
    } b;
} LPPWM_QACTIVE_MANUAL_CTRL_TypeDef;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_LPPWM_DEF_H */
