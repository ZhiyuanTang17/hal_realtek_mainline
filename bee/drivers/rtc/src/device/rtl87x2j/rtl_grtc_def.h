/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GRTC_DEF_H
#define RTL_GRTC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"
#include "utils.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          GRTC Defines
 *============================================================================*/
#define GRTC_COMP_NUM                         (8)

#define GRTC_SUPPORT_RAP_FUNCTION             (1)
#define GRTC_SUPPORT_FORCE_QACTIVE            (1)
#define GRTC_SUPPORT_ERROR_INTERRUPT          (1)

/*============================================================================*
 *                          GRTC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t GRTC_CTRL;                                /*!< 0x00 */
    __IO uint32_t GRTC_INTR_CTRL;                           /*!< 0x04 */
    __I  uint32_t GRTC_COMP_INTR_SR;                        /*!< 0x08 */
    __IO uint32_t GRTC_COMP_INT_CLR;                        /*!< 0x0C */
    __IO uint32_t GRTC_COMP_0;                              /*!< 0x10 */
    __IO uint32_t GRTC_COMP_1;                              /*!< 0x14 */
    __IO uint32_t GRTC_COMP_2;                              /*!< 0x18 */
    __IO uint32_t GRTC_COMP_3;                              /*!< 0x1C */
    __IO uint32_t GRTC_COMP_4;                              /*!< 0x20 */
    __IO uint32_t GRTC_COMP_5;                              /*!< 0x24 */
    __IO uint32_t GRTC_COMP_6;                              /*!< 0x28 */
    __IO uint32_t GRTC_COMP_7;                              /*!< 0x2C */
    __IO uint32_t GRTC_RELOAD_CTRL;                         /*!< 0x30 */
    __IO uint32_t GRTC_COMP_0_RELOAD;                       /*!< 0x34 */
    __IO uint32_t GRTC_COMP_1_RELOAD;                       /*!< 0x38 */
    __IO uint32_t GRTC_COMP_2_RELOAD;                       /*!< 0x3C */
    __IO uint32_t GRTC_COMP_3_RELOAD;                       /*!< 0x40 */
    __IO uint32_t GRTC_COMP_4_RELOAD;                       /*!< 0x44 */
    __IO uint32_t GRTC_COMP_5_RELOAD;                       /*!< 0x48 */
    __IO uint32_t GRTC_COMP_6_RELOAD;                       /*!< 0x4C */
    __IO uint32_t GRTC_COMP_7_RELOAD;                       /*!< 0x50 */
    __IO uint32_t GRTC_SLEEP_CTRL;                          /*!< 0x54 */
    __I  uint32_t GRTC_COMP_0_SLEEP_PENDING_CNT;            /*!< 0x58 */
    __I  uint32_t GRTC_COMP_1_SLEEP_PENDING_CNT;            /*!< 0x5C */
    __I  uint32_t GRTC_COMP_2_SLEEP_PENDING_CNT;            /*!< 0x60 */
    __I  uint32_t GRTC_COMP_3_SLEEP_PENDING_CNT;            /*!< 0x64 */
    __I  uint32_t GRTC_COMP_4_SLEEP_PENDING_CNT;            /*!< 0x68 */
    __I  uint32_t GRTC_COMP_5_SLEEP_PENDING_CNT;            /*!< 0x6C */
    __I  uint32_t GRTC_COMP_6_SLEEP_PENDING_CNT;            /*!< 0x70 */
    __I  uint32_t GRTC_COMP_7_SLEEP_PENDING_CNT;            /*!< 0x74 */
    __IO uint32_t GRTC_TASK_CTRL;                           /*!< 0x78 */
    __IO uint32_t GRTC_QACTIVE_CTRL;                        /*!< 0x7C */
    __I  uint32_t GRTC_RTL_VERSION;                         /*!< 0x80 */
    __IO uint32_t GRTC_COMP_TIMEOUT_OV_ERR_SR;              /*!< 0x84 */
    __IO uint32_t GRTC_COMP_TIMEOUT_OV_ERR_CLR;             /*!< 0x88 */
} GRTC_TypeDef;

/*============================================================================*
 *                          GRTC Declaration
 *============================================================================*/
#define GRTC_REG_BASE       (SYSON_BASE + AON_REG_GRTC_CTRL)
#define GRTC                ((GRTC_TypeDef *) GRTC_REG_BASE)

/*============================================================================*
 *                          GRTC Private Types
 *============================================================================*/

/*============================================================================*
 *                          GRTC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   30:0    R      grtc_ctrl_reserved30_0                      31'b0
   31      R/W    grtc_rst                                    1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_ctrl_reserved30_0: 31;
        uint32_t grtc_rst: 1;
    } b;
} GRTC_CTRL_TypeDef;


/* 0x04
   0       R/W    grtc_cmp0_nv_ie                             1'b0
   1       R/W    grtc_cmp1_nv_ie                             1'b0
   2       R/W    grtc_cmp2_nv_ie                             1'b0
   3       R/W    grtc_cmp3_nv_ie                             1'b0
   4       R/W    grtc_cmp4_nv_ie                             1'b0
   5       R/W    grtc_cmp5_nv_ie                             1'b0
   6       R/W    grtc_cmp6_nv_ie                             1'b0
   7       R/W    grtc_cmp7_nv_ie                             1'b0
   31:8    R      grtc_intr_ctrl_reserved31_8                 24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_nv_ie: 1;
        uint32_t grtc_cmp1_nv_ie: 1;
        uint32_t grtc_cmp2_nv_ie: 1;
        uint32_t grtc_cmp3_nv_ie: 1;
        uint32_t grtc_cmp4_nv_ie: 1;
        uint32_t grtc_cmp5_nv_ie: 1;
        uint32_t grtc_cmp6_nv_ie: 1;
        uint32_t grtc_cmp7_nv_ie: 1;
        const uint32_t grtc_intr_ctrl_reserved31_8: 24;
    } b;
} GRTC_INTR_CTRL_TypeDef;


/* 0x08
   0       R      grtc_cmp0_nv_sr                             1'b0
   1       R      grtc_cmp1_nv_sr                             1'b0
   2       R      grtc_cmp2_nv_sr                             1'b0
   3       R      grtc_cmp3_nv_sr                             1'b0
   4       R      grtc_cmp4_nv_sr                             1'b0
   5       R      grtc_cmp5_nv_sr                             1'b0
   6       R      grtc_cmp6_nv_sr                             1'b0
   7       R      grtc_cmp7_nv_sr                             1'b0
   31:8    R      grtc_comp_intr_sr_reserved31_8              24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp0_nv_sr: 1;
        const uint32_t grtc_cmp1_nv_sr: 1;
        const uint32_t grtc_cmp2_nv_sr: 1;
        const uint32_t grtc_cmp3_nv_sr: 1;
        const uint32_t grtc_cmp4_nv_sr: 1;
        const uint32_t grtc_cmp5_nv_sr: 1;
        const uint32_t grtc_cmp6_nv_sr: 1;
        const uint32_t grtc_cmp7_nv_sr: 1;
        const uint32_t grtc_comp_intr_sr_reserved31_8: 24;
    } b;
} GRTC_COMP_INTR_SR_TypeDef;


/* 0x0C
   0       R/WAC  grtc_cmp0_nv_clr                            1'b0
   1       R/WAC  grtc_cmp1_nv_clr                            1'b0
   2       R/WAC  grtc_cmp2_nv_clr                            1'b0
   3       R/WAC  grtc_cmp3_nv_clr                            1'b0
   4       R/WAC  grtc_cmp4_nv_clr                            1'b0
   5       R/WAC  grtc_cmp5_nv_clr                            1'b0
   6       R/WAC  grtc_cmp6_nv_clr                            1'b0
   7       R/WAC  grtc_cmp7_nv_clr                            1'b0
   31:8    R      grtc_comp_intr_clr_reserved31_8             24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_nv_clr: 1;
        uint32_t grtc_cmp1_nv_clr: 1;
        uint32_t grtc_cmp2_nv_clr: 1;
        uint32_t grtc_cmp3_nv_clr: 1;
        uint32_t grtc_cmp4_nv_clr: 1;
        uint32_t grtc_cmp5_nv_clr: 1;
        uint32_t grtc_cmp6_nv_clr: 1;
        uint32_t grtc_cmp7_nv_clr: 1;
        const uint32_t grtc_comp_intr_clr_reserved31_8: 24;
    } b;
} GRTC_COMP_INT_CLR_TypeDef;


/* 0x10
   31:0    R/W    grtc_cmp0                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0: 32;
    } b;
} GRTC_COMP_0_TypeDef;


/* 0x14
   31:0    R/W    grtc_cmp1                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp1: 32;
    } b;
} GRTC_COMP_1_TypeDef;


/* 0x18
   31:0    R/W    grtc_cmp2                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp2: 32;
    } b;
} GRTC_COMP_2_TypeDef;


/* 0x1C
   31:0    R/W    grtc_cmp3                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp3: 32;
    } b;
} GRTC_COMP_3_TypeDef;


/* 0x20
   31:0    R/W    grtc_cmp4                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp4: 32;
    } b;
} GRTC_COMP_4_TypeDef;


/* 0x24
   31:0    R/W    grtc_cmp5                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp5: 32;
    } b;
} GRTC_COMP_5_TypeDef;


/* 0x28
   31:0    R/W    grtc_cmp6                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp6: 32;
    } b;
} GRTC_COMP_6_TypeDef;


/* 0x2C
   31:0    R/W    grtc_cmp7                                   32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp7: 32;
    } b;
} GRTC_COMP_7_TypeDef;


/* 0x30
   0       R/W    grtc_cmp0_reload_en                         1'h0
   1       R/W    grtc_cmp1_reload_en                         1'b0
   2       R/W    grtc_cmp2_reload_en                         1'b0
   3       R/W    grtc_cmp3_reload_en                         1'b0
   4       R/W    grtc_cmp4_reload_en                         1'b0
   5       R/W    grtc_cmp5_reload_en                         1'b0
   6       R/W    grtc_cmp6_reload_en                         1'b0
   7       R/W    grtc_cmp7_reload_en                         1'b0
   31:8    R      grtc_comp_reload_ctrl_reserved31_8          24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_reload_en: 1;
        uint32_t grtc_cmp1_reload_en: 1;
        uint32_t grtc_cmp2_reload_en: 1;
        uint32_t grtc_cmp3_reload_en: 1;
        uint32_t grtc_cmp4_reload_en: 1;
        uint32_t grtc_cmp5_reload_en: 1;
        uint32_t grtc_cmp6_reload_en: 1;
        uint32_t grtc_cmp7_reload_en: 1;
        const uint32_t grtc_comp_reload_ctrl_reserved31_8: 24;
    } b;
} GRTC_RELOAD_CTRL_TypeDef;


/* 0x34
   31:0    R/W    grtc_cmp0_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_reload: 32;
    } b;
} GRTC_COMP_0_RELOAD_TypeDef;


/* 0x38
   31:0    R/W    grtc_cmp1_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp1_reload: 32;
    } b;
} GRTC_COMP_1_RELOAD_TypeDef;


/* 0x3C
   31:0    R/W    grtc_cmp2_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp2_reload: 32;
    } b;
} GRTC_COMP_2_RELOAD_TypeDef;


/* 0x40
   31:0    R/W    grtc_cmp3_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp3_reload: 32;
    } b;
} GRTC_COMP_3_RELOAD_TypeDef;


/* 0x44
   31:0    R/W    grtc_cmp4_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp4_reload: 32;
    } b;
} GRTC_COMP_4_RELOAD_TypeDef;


/* 0x48
   31:0    R/W    grtc_cmp5_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp5_reload: 32;
    } b;
} GRTC_COMP_5_RELOAD_TypeDef;


/* 0x4C
   31:0    R/W    grtc_cmp6_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp6_reload: 32;
    } b;
} GRTC_COMP_6_RELOAD_TypeDef;


/* 0x50
   31:0    R/W    grtc_cmp7_reload                            32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp7_reload: 32;
    } b;
} GRTC_COMP_7_RELOAD_TypeDef;


/* 0x54
   0       R/W    grtc_cmp0_sleep_ctrl                        1'h0
   1       R/W    grtc_cmp1_sleep_ctrl                        1'b0
   2       R/W    grtc_cmp2_sleep_ctrl                        1'b0
   3       R/W    grtc_cmp3_sleep_ctrl                        1'b0
   4       R/W    grtc_cmp4_sleep_ctrl                        1'b0
   5       R/W    grtc_cmp5_sleep_ctrl                        1'b0
   6       R/W    grtc_cmp6_sleep_ctrl                        1'b0
   7       R/W    grtc_cmp7_sleep_ctrl                        1'b0
   31:8    R      grtc_sleep_ctrl_reserved31_8                24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_sleep_ctrl: 1;
        uint32_t grtc_cmp1_sleep_ctrl: 1;
        uint32_t grtc_cmp2_sleep_ctrl: 1;
        uint32_t grtc_cmp3_sleep_ctrl: 1;
        uint32_t grtc_cmp4_sleep_ctrl: 1;
        uint32_t grtc_cmp5_sleep_ctrl: 1;
        uint32_t grtc_cmp6_sleep_ctrl: 1;
        uint32_t grtc_cmp7_sleep_ctrl: 1;
        const uint32_t grtc_sleep_ctrl_reserved31_8: 24;
    } b;
} GRTC_SLEEP_CTRL_TypeDef;


/* 0x58
   31:0    R      grtc_cmp0_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp0_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_0_SLEEP_PENDING_CNT_TypeDef;


/* 0x5C
   31:0    R      grtc_cmp1_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp1_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_1_SLEEP_PENDING_CNT_TypeDef;


/* 0x60
   31:0    R      grtc_cmp2_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp2_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_2_SLEEP_PENDING_CNT_TypeDef;


/* 0x64
   31:0    R      grtc_cmp3_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp3_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_3_SLEEP_PENDING_CNT_TypeDef;


/* 0x68
   31:0    R      grtc_cmp4_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp4_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_4_SLEEP_PENDING_CNT_TypeDef;


/* 0x6C
   31:0    R      grtc_cmp5_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp5_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_5_SLEEP_PENDING_CNT_TypeDef;


/* 0x70
   31:0    R      grtc_cmp6_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp6_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_6_SLEEP_PENDING_CNT_TypeDef;


/* 0x74
   31:0    R      grtc_cmp7_sleep_pending_cnt                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp7_sleep_pending_cnt: 32;
    } b;
} GRTC_COMP_7_SLEEP_PENDING_CNT_TypeDef;


/* 0x78
   0       R/W    grtc_cmp0_rap_mode                          1'h0
   1       R/W    grtc_cmp1_rap_mode                          1'h0
   2       R/W    grtc_cmp2_rap_mode                          1'h0
   3       R/W    grtc_cmp3_rap_mode                          1'h0
   4       R/W    grtc_cmp4_rap_mode                          1'h0
   5       R/W    grtc_cmp5_rap_mode                          1'h0
   6       R/W    grtc_cmp6_rap_mode                          1'h0
   7       R/W    grtc_cmp7_rap_mode                          1'h0
   8       R/WAC  grtc_fw_task_reload_cmp0                    1'h0
   9       R/WAC  grtc_fw_task_reload_cmp1                    1'b0
   10      R/WAC  grtc_fw_task_reload_cmp2                    1'b0
   11      R/WAC  grtc_fw_task_reload_cmp3                    1'b0
   12      R/WAC  grtc_fw_task_reload_cmp4                    1'b0
   13      R/WAC  grtc_fw_task_reload_cmp5                    1'b0
   14      R/WAC  grtc_fw_task_reload_cmp6                    1'b0
   15      R/WAC  grtc_fw_task_reload_cmp7                    1'b0
   31:16   R      grtc_task_ctrl_reserved31_16                16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_rap_mode: 1;
        uint32_t grtc_cmp1_rap_mode: 1;
        uint32_t grtc_cmp2_rap_mode: 1;
        uint32_t grtc_cmp3_rap_mode: 1;
        uint32_t grtc_cmp4_rap_mode: 1;
        uint32_t grtc_cmp5_rap_mode: 1;
        uint32_t grtc_cmp6_rap_mode: 1;
        uint32_t grtc_cmp7_rap_mode: 1;
        uint32_t grtc_fw_task_reload_cmp0: 1;
        uint32_t grtc_fw_task_reload_cmp1: 1;
        uint32_t grtc_fw_task_reload_cmp2: 1;
        uint32_t grtc_fw_task_reload_cmp3: 1;
        uint32_t grtc_fw_task_reload_cmp4: 1;
        uint32_t grtc_fw_task_reload_cmp5: 1;
        uint32_t grtc_fw_task_reload_cmp6: 1;
        uint32_t grtc_fw_task_reload_cmp7: 1;
        const uint32_t grtc_task_ctrl_reserved31_16: 16;
    } b;
} GRTC_TASK_CTRL_TypeDef;


/* 0x7C
   0       R/W    grtc_qact_sclk_man_data                     1'h0
   1       R/W    grtc_qact_sclk_man_en                       1'h0
   2       R/W    grtc_qact_pclk_man_data                     1'h0
   3       R/W    grtc_qact_pclk_man_en                       1'h0
   7:4     R      grtc_intr_clr_reserved7_4                   4'b0
   8       R/W    grtc_cmp0_force_qact_en                     1'h0
   9       R/W    grtc_cmp1_force_qact_en                     1'h0
   10      R/W    grtc_cmp2_force_qact_en                     1'h0
   11      R/W    grtc_cmp3_force_qact_en                     1'h0
   12      R/W    grtc_cmp4_force_qact_en                     1'h0
   13      R/W    grtc_cmp5_force_qact_en                     1'h0
   14      R/W    grtc_cmp6_force_qact_en                     1'h0
   15      R/W    grtc_cmp7_force_qact_en                     1'h0
   31:16   R      grtc_intr_clr_reserved31_16                 16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_qact_sclk_man_data: 1;
        uint32_t grtc_qact_sclk_man_en: 1;
        uint32_t grtc_qact_pclk_man_data: 1;
        uint32_t grtc_qact_pclk_man_en: 1;
        const uint32_t grtc_intr_clr_reserved7_4: 4;
        uint32_t grtc_cmp0_force_qact_en: 1;
        uint32_t grtc_cmp1_force_qact_en: 1;
        uint32_t grtc_cmp2_force_qact_en: 1;
        uint32_t grtc_cmp3_force_qact_en: 1;
        uint32_t grtc_cmp4_force_qact_en: 1;
        uint32_t grtc_cmp5_force_qact_en: 1;
        uint32_t grtc_cmp6_force_qact_en: 1;
        uint32_t grtc_cmp7_force_qact_en: 1;
        const uint32_t grtc_intr_clr_reserved31_16: 16;
    } b;
} GRTC_QACTIVE_CTRL_TypeDef;


/* 0x80
   31:0    R      grtc_rtl_version                            32'h20240930
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_rtl_version: 32;
    } b;
} GRTC_RTL_VERSION_TypeDef;


/* 0x84
   0       R      grtc_cmp0_timeout_ov_err_sr                 1'b0
   1       R      grtc_cmp1_timeout_ov_err_sr                 1'b0
   2       R      grtc_cmp2_timeout_ov_err_sr                 1'b0
   3       R      grtc_cmp3_timeout_ov_err_sr                 1'b0
   4       R      grtc_cmp4_timeout_ov_err_sr                 1'b0
   5       R      grtc_cmp5_timeout_ov_err_sr                 1'b0
   6       R      grtc_cmp6_timeout_ov_err_sr                 1'b0
   7       R      grtc_cmp7_timeout_ov_err_sr                 1'b0
   31:8    R      grtc_comp_timeout_ov_err_sr_reserved31_8    24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t grtc_cmp0_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp1_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp2_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp3_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp4_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp5_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp6_timeout_ov_err_sr: 1;
        const uint32_t grtc_cmp7_timeout_ov_err_sr: 1;
        const uint32_t grtc_comp_timeout_ov_err_sr_reserved31_8: 24;
    } b;
} GRTC_COMP_TIMEOUT_OV_ERR_SR_TypeDef;


/* 0x88
   0       R/WAC  grtc_cmp0_timeout_ov_err_clr                1'b0
   1       R/WAC  grtc_cmp1_timeout_ov_err_clr                1'b0
   2       R/WAC  grtc_cmp2_timeout_ov_err_clr                1'b0
   3       R/WAC  grtc_cmp3_timeout_ov_err_clr                1'b0
   4       R/WAC  grtc_cmp4_timeout_ov_err_clr                1'b0
   5       R/WAC  grtc_cmp5_timeout_ov_err_clr                1'b0
   6       R/WAC  grtc_cmp6_timeout_ov_err_clr                1'b0
   7       R/WAC  grtc_cmp7_timeout_ov_err_clr                1'b0
   31:8    R      grtc_comp_timeout_ov_err_clr_reserved31_8   24'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t grtc_cmp0_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp1_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp2_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp3_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp4_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp5_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp6_timeout_ov_err_clr: 1;
        uint32_t grtc_cmp7_timeout_ov_err_clr: 1;
        const uint32_t grtc_comp_timeout_ov_err_clr_reserved31_8: 24;
    } b;
} GRTC_COMP_TIMEOUT_OV_ERR_CLR_TypeDef;



/*============================================================================*
 *                         GRTC Wrappers
 *============================================================================*/


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_GRTC_DEF_H */
