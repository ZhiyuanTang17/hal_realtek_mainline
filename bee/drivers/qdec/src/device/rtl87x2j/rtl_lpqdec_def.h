/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPQDEC_DEF_H
#define RTL_LPQDEC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          LPQDEC Defines
 *============================================================================*/
#define LPQDEC_SUPPORT_LED_FUNCTION                         (1)
#define LPQDEC_SUPPORT_CLK_SRC_DIV                          (1)

/*============================================================================*
 *                          LPQDEC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t LPQDEC_DIV;                   /*!< 0x00 */
    __IO uint32_t LPQDEC_CONFIG;                /*!< 0x04 */
    __I  uint32_t LPQDEC_SR_1_X;                /*!< 0x08 */
    __I  uint32_t LPQDEC_SR_2_X;                /*!< 0x0C */
    __IO uint32_t LPQDEC_INT_CLR;               /*!< 0x10 */
    __I  uint32_t LPQDEC_VERSION;               /*!< 0x14 */
    __IO uint32_t LPQDEC_LED_CTRL;              /*!< 0x18 */
    __IO uint32_t LPQDEC_QACTIVE_CTRL;          /*!< 0x1C */
} LPQDEC_TypeDef;

/*============================================================================*
 *                          LPQDEC Declaration
 *============================================================================*/
#define LPQDEC_REG_BASE           (SYSON_BASE + AON_REG_LPQDEC_X_DIV)
#define LPQDEC                    ((LPQDEC_TypeDef *) LPQDEC_REG_BASE)

#define IS_LPQDEC_PERIPH(PERIPH)  ((PERIPH) == LPQDEC)

/*============================================================================*
 *                          LPQDEC Private Types
 *============================================================================*/

/*============================================================================*
 *                          LPQDEC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   3:0     R/W    scan_div                        4'h0
   31:4    R      reg_div_reserved31_4            28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t scan_div: 4;
        const uint32_t reg_div_reserved31_4: 28;
    } b;
} LPQDEC_DIV_TypeDef;


/* 0x04
   1:0     R/W    x_initial_phase                 2'h0
   2       R/W    x_set_inital_phase              1'h0
   3       R/W    x_cnt_pause                     1'h0
   4       R/W    x_cnt_scale                     1'h0
   5       R/W    x_illegal_int_en                1'h0
   6       R/W    x_cnt_int_en                    1'h0
   7       R/W    illegal_int_mask                1'h1
   8       R/W    cnt_int_mask                    1'h1
   21:9    R/W    x_debounce_cnt                  13'h0
   22      R/W    x_debounce_en                   1'h0
   23      R/W    x_wake_aon_mask                 1'b1
   24      R/W    x_int_mask                      1'b1
   28:25   R      reg_config_reserved28_25        4'b0
   29      R/W    x_rst                           1'b0
   30      R/WAC  x_fsm_en                        1'h0
   31      R/W    x_axis_en                       1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t x_initial_phase: 2;
        uint32_t x_set_inital_phase: 1;
        uint32_t x_cnt_pause: 1;
        uint32_t x_cnt_scale: 1;
        uint32_t x_illegal_int_en: 1;
        uint32_t x_cnt_int_en: 1;
        uint32_t illegal_int_mask: 1;
        uint32_t cnt_int_mask: 1;
        uint32_t x_debounce_cnt: 13;
        uint32_t x_debounce_en: 1;
        uint32_t x_wake_aon_mask: 1;
        uint32_t x_int_mask: 1;
        const uint32_t reg_config_reserved28_25: 4;
        uint32_t x_rst: 1;
        uint32_t x_fsm_en: 1;
        uint32_t x_axis_en: 1;
    } b;
} LPQDEC_CONFIG_TypeDef;


/* 0x08
   15:0    R      reg_sr_1_x_reserved15_0         16'h0
   16      R      cnt_of_flg                      1'h0
   17      R      cnt_uf_flg                      1'h0
   18      R      cnt_int_sta                     1'h0
   19      R      illegal_int_sta                 1'h0
   20      R      cnt_dir                         1'h0
   21      R      pha_sta                         1'h0
   22      R      phb_sta                         1'h0
   31:23   R      reg_sr_1_x_reserved31_23        9'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reg_sr_1_x_reserved15_0: 16;
        const uint32_t cnt_of_flg: 1;
        const uint32_t cnt_uf_flg: 1;
        const uint32_t cnt_int_sta: 1;
        const uint32_t illegal_int_sta: 1;
        const uint32_t cnt_dir: 1;
        const uint32_t pha_sta: 1;
        const uint32_t phb_sta: 1;
        const uint32_t reg_sr_1_x_reserved31_23: 9;
    } b;
} LPQDEC_SR_1_X_TypeDef;


/* 0x0C
   15:0    R      acc_cnt                         16'h0
   21:16   R      reg_sr_2_x_reserved21           6'h0
   23:22   R      debug_state_x                   2'h0
   31:24   R      debug_illegal_counter_x         8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t acc_cnt: 16;
        const uint32_t reg_sr_2_x_reserved21: 6;
        const uint32_t debug_state_x: 2;
        const uint32_t debug_illegal_counter_x: 8;
    } b;
} LPQDEC_SR_2_X_TypeDef;


/* 0x10
   0       R/WAC  acc_cnt_clr                     1'h0
   1       R/WAC  cnt_int_clr                     1'h0
   2       R/WAC  of_flg_clr                      1'h0
   3       R/WAC  uf_flg_clr                      1'h0
   4       R/WAC  illegal_int_clr                 1'h0
   5       R/WAC  illegal_cnt_clr                 1'h0
   31:6    R      reg_int_clr_reserved31_6        26'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t acc_cnt_clr: 1;
        uint32_t cnt_int_clr: 1;
        uint32_t of_flg_clr: 1;
        uint32_t uf_flg_clr: 1;
        uint32_t illegal_int_clr: 1;
        uint32_t illegal_cnt_clr: 1;
        const uint32_t reg_int_clr_reserved31_6: 26;
    } b;
} LPQDEC_INT_CLR_TypeDef;


/* 0x14
   31:0    R      qdec_version                    32'h20240329
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t qdec_version: 32;
    } b;
} LPQDEC_VERSION_TypeDef;


/* 0x18
   0       R/W    led_en                          1'h0
   1       R/W    ledpol                          1'h0
   4:2     R/W    ledpre                          3'h0
   31:5    R      reg_led_ctrl_reserved31_5       27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t led_en: 1;
        uint32_t ledpol: 1;
        uint32_t ledpre: 3;
        const uint32_t reg_led_ctrl_reserved31_5: 27;
    } b;
} LPQDEC_LED_CTRL_TypeDef;


/* 0x1C
   0       R/W    lpqdec_qact_sclk_man_data       1'h0
   1       R/W    lpqdec_qact_sclk_man_en         1'h0
   2       R/W    lpqdec_qact_pclk_man_data       1'h0
   3       R/W    lpqdec_qact_pclk_man_en         1'h0
   31:4    R      reg_qactive_ctrl_reserved31_4   28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpqdec_qact_sclk_man_data: 1;
        uint32_t lpqdec_qact_sclk_man_en: 1;
        uint32_t lpqdec_qact_pclk_man_data: 1;
        uint32_t lpqdec_qact_pclk_man_en: 1;
        const uint32_t reg_qactive_ctrl_reserved31_4: 28;
    } b;
} LPQDEC_QACTIVE_CTRL_TypeDef;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_LPQDEC_DEF_H */
