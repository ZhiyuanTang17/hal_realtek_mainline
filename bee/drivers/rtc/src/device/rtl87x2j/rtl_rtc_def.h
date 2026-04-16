/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_RTC_DEF_H
#define RTL_RTC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"
#include "utils.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/*============================================================================*
 *                          RTC Defines
 *============================================================================*/
/** \defgroup RTC         RTC
  * \brief
  * \{
  */

/** \defgroup RTC_Exported_Constants RTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup RTC_Defines RTC Defines
 * \{
 * \ingroup  RTC_Exported_Constants
 */
#define RTC_SUPPORT_CLOCK_IN_FROM_OUTSIDE_PAD          (1)
#define RTC_SUPPORT_CLOCK_OUT_TO_OUTSIDE_PAD           (0)
#define RTC_SUPPORT_WAKEUP_MORE_SOURCE                 (1) /*Support TICK OVERFLOW PRECOMP PRECOMP_COMP3*/
#define RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME           (0)
#define RTC_SUPPORT_COMPARE_AUTO_RELOAD                (1)
#define RTC_SUPPORT_RAP_FUNCTION                       (1)
#define RTC_SUPPORT_RESET_REGISTER_TO_DEFAULT          (1)

/** End of RTC_Defines
  * \}
  */

/** End of RTC_Exported_Constants
  * \}
  */

/** End of RTC
  * \}
  */

/*============================================================================*
 *                          RTC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t RTC_CR0;                  /*!< 0x00 */
    __IO uint32_t RTC_INT_CLEAR;            /*!< 0x04 */
    __IO uint32_t RTC_INT_SR;               /*!< 0x08 */
    __IO uint32_t RTC_PRESCALER0;           /*!< 0x0C */
    __IO uint32_t RTC_COMP_0;               /*!< 0x10 */
    __IO uint32_t RTC_COMP_1;               /*!< 0x14 */
    __IO uint32_t RTC_COMP_2;               /*!< 0x18 */
    __IO uint32_t RTC_COMP_3;               /*!< 0x1C */
    __I  uint32_t RTC_CNT0;                 /*!< 0x20 */
    __IO uint32_t RTC_PRESCALE_CNT0;        /*!< 0x24 */
    __IO uint32_t RTC_PRESCALE_CMP0;        /*!< 0x28 */
    __IO uint32_t RTC_BACKUP;               /*!< 0x2C */
    __I  uint32_t RTC_RTL_VERSION0;         /*!< 0x30 */
    __IO uint32_t RTC_RELOAD_CTRL;          /*!< 0x34 */
    __IO uint32_t RTC_COMP_0_RELOAD;        /*!< 0x38 */
    __IO uint32_t RTC_COMP_1_RELOAD;        /*!< 0x3C */
    __IO uint32_t RTC_COMP_2_RELOAD;        /*!< 0x40 */
    __IO uint32_t RTC_COMP_3_RELOAD;        /*!< 0x44 */
    __IO uint32_t RTC_TASK_CTRL;            /*!< 0x48 */
    __IO uint32_t RTC_SHOT_CTRL;            /*!< 0x4C */
    __IO uint32_t RTC_QACTIVE_CTRL;         /*!< 0x50 */
} RTC_TypeDef;

/*============================================================================*
 *                          RTC Declaration
 *============================================================================*/
#define RTC_REG_BASE       (SYSON_BASE + AON_REG_RTC_CR0)
#define RTC                ((RTC_TypeDef *) RTC_REG_BASE)

/*============================================================================*
 *                          RTC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   0       R/W    rtc_cnt_start                   1'b0
   1       R/W    rtc_cnt_rst                     1'b0
   2       R/W    rtc_pre_cnt_rst                 1'b0
   7:3     R      rtc_cr0_reserved7_3             5'b0
   8       R/W    rtc_tick_ie                     1'b0
   9       R/W    rtc_cnt_ov_ie                   1'b0
   10      R/W    rtc_precmp_ie                   1'b0
   11      R/W    rtc_precmp_cmp3_ie              1'b0
   15:12   R      rtc_cr0_reserved15_12           4'h0
   16      R/W    rtc_cmp0_nv_ie                  1'b0
   17      R/W    rtc_cmp1_nv_ie                  1'b0
   18      R/W    rtc_cmp2_nv_ie                  1'b0
   19      R/W    rtc_cmp3_nv_ie                  1'b0
   20      R/W    rtc_cmp0_wk_ie                  1'b0
   21      R/W    rtc_cmp1_wk_ie                  1'b0
   22      R/W    rtc_cmp2_wk_ie                  1'b0
   23      R/W    rtc_cmp3_wk_ie                  1'b0
   28:24   R      rtc_cr0_reserved28_24           5'b0
   29      R/W    rtc_wk_ie                       1'b0
   30      R/W    rtc_nv_ie                       1'b0
   31      R/W    rtc_rst                         1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cnt_start: 1;
        uint32_t rtc_cnt_rst: 1;
        uint32_t rtc_pre_cnt_rst: 1;
        const uint32_t rtc_cr0_reserved7_3: 5;
        uint32_t rtc_tick_ie: 1;
        uint32_t rtc_cnt_ov_ie: 1;
        uint32_t rtc_precmp_ie: 1;
        uint32_t rtc_precmp_cmp3_ie: 1;
        const uint32_t rtc_cr0_reserved15_12: 4;
        uint32_t rtc_cmp0_nv_ie: 1;
        uint32_t rtc_cmp1_nv_ie: 1;
        uint32_t rtc_cmp2_nv_ie: 1;
        uint32_t rtc_cmp3_nv_ie: 1;
        uint32_t rtc_cmp0_wk_ie: 1;
        uint32_t rtc_cmp1_wk_ie: 1;
        uint32_t rtc_cmp2_wk_ie: 1;
        uint32_t rtc_cmp3_wk_ie: 1;
        const uint32_t rtc_cr0_reserved28_24: 5;
        uint32_t rtc_wk_ie: 1;
        uint32_t rtc_nv_ie: 1;
        uint32_t rtc_rst: 1;
    } b;
} RTC_CR0_TypeDef;


/* 0x04
   0       R/WAC  rtc_tick_clr                    1'b0
   1       R/WAC  rtc_cnt_ov_clr                  1'b0
   2       R/WAC  rtc_precmp_clr                  1'b0
   3       R/WAC  rtc_precmp_cmp3_clr             1'b0
   7:4     R      rtc_int_clear_reserved7_4       4'h0
   8       R/WAC  rtc_cmp0_nv_clr                 1'b0
   9       R/WAC  rtc_cmp1_nv_clr                 1'b0
   10      R/WAC  rtc_cmp2_nv_clr                 1'b0
   11      R/WAC  rtc_cmp3_nv_clr                 1'b0
   12      R/WAC  rtc_cmp0_wk_clr                 1'b0
   13      R/WAC  rtc_cmp1_wk_clr                 1'b0
   14      R/WAC  rtc_cmp2_wk_clr                 1'b0
   15      R/WAC  rtc_cmp3_wk_clr                 1'b0
   31:16   R      rtc_int_clear_reserved31_16     16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_tick_clr: 1;
        uint32_t rtc_cnt_ov_clr: 1;
        uint32_t rtc_precmp_clr: 1;
        uint32_t rtc_precmp_cmp3_clr: 1;
        const uint32_t rtc_int_clear_reserved7_4: 4;
        uint32_t rtc_cmp0_nv_clr: 1;
        uint32_t rtc_cmp1_nv_clr: 1;
        uint32_t rtc_cmp2_nv_clr: 1;
        uint32_t rtc_cmp3_nv_clr: 1;
        uint32_t rtc_cmp0_wk_clr: 1;
        uint32_t rtc_cmp1_wk_clr: 1;
        uint32_t rtc_cmp2_wk_clr: 1;
        uint32_t rtc_cmp3_wk_clr: 1;
        const uint32_t rtc_int_clear_reserved31_16: 16;
    } b;
} RTC_INT_CLEAR_TypeDef;


/* 0x08
   0       R      rtc_tick_sr                     1'b0
   1       R      rtc_cnt_ov_sr                   1'b0
   2       R      rtc_precmp_sr                   1'b0
   3       R      rtc_precmp_cmp3_sr              1'b0
   7:4     R      rtc_int_sr_reserved7_4          4'h0
   8       R      rtc_cmp0_nv_sr                  1'b0
   9       R      rtc_cmp1_nv_sr                  1'b0
   10      R      rtc_cmp2_nv_sr                  1'b0
   11      R      rtc_cmp3_nv_sr                  1'b0
   12      R      rtc_cmp0_wk_sr                  1'b0
   13      R      rtc_cmp1_wk_sr                  1'b0
   14      R      rtc_cmp2_wk_sr                  1'b0
   15      R      rtc_cmp3_wk_sr                  1'b0
   31:16   R      rtc_int_sr_reserved31_16        16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rtc_tick_sr: 1;
        const uint32_t rtc_cnt_ov_sr: 1;
        const uint32_t rtc_precmp_sr: 1;
        const uint32_t rtc_precmp_cmp3_sr: 1;
        const uint32_t rtc_int_sr_reserved7_4: 4;
        const uint32_t rtc_cmp0_nv_sr: 1;
        const uint32_t rtc_cmp1_nv_sr: 1;
        const uint32_t rtc_cmp2_nv_sr: 1;
        const uint32_t rtc_cmp3_nv_sr: 1;
        const uint32_t rtc_cmp0_wk_sr: 1;
        const uint32_t rtc_cmp1_wk_sr: 1;
        const uint32_t rtc_cmp2_wk_sr: 1;
        const uint32_t rtc_cmp3_wk_sr: 1;
        const uint32_t rtc_int_sr_reserved31_16: 16;
    } b;
} RTC_INT_SR_TypeDef;


/* 0x0C
   11:0    R/W    rtc_prescaler                   12'b0
   31:12   R      rtc_prescaler_reserved31_12     20'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_prescaler: 12;
        const uint32_t rtc_prescaler_reserved31_12: 20;
    } b;
} RTC_PRESCALER0_TypeDef;


/* 0x10
   31:0    R/W    rtc_cmp0                        32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp0: 32;
    } b;
} RTC_COMP_0_TypeDef;


/* 0x14
   31:0    R/W    rtc_cmp1                        32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp1: 32;
    } b;
} RTC_COMP_1_TypeDef;


/* 0x18
   31:0    R/W    rtc_cmp2                        32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp2: 32;
    } b;
} RTC_COMP_2_TypeDef;


/* 0x1C
   31:0    R/W    rtc_cmp3                        32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp3: 32;
    } b;
} RTC_COMP_3_TypeDef;


/* 0x20
   31:0    R      rtc_cnt                         32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rtc_cnt: 32;
    } b;
} RTC_CNT0_TypeDef;


/* 0x24
   11:0    R      rtc_prescale_cnt                12'b0
   31:12   R      rtc_prescaler_cnt0_reserved31_12 20'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rtc_prescale_cnt: 12;
        const uint32_t rtc_prescaler_cnt0_reserved31_12: 20;
    } b;
} RTC_PRESCALE_CNT0_TypeDef;


/* 0x28
   11:0    R/W    rtc_prescale_cmp                12'b0
   31:12   R      rtc_prescaler_cmp0_reserved31_12 20'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_prescale_cmp: 12;
        const uint32_t rtc_prescaler_cmp0_reserved31_12: 20;
    } b;
} RTC_PRESCALE_CMP0_TypeDef;


/* 0x2C
   31:0    R/W    rtc_backup                      32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_backup: 32;
    } b;
} RTC_BACKUP_TypeDef;


/* 0x30
   31:0    R      rtc_rtl_version                 32'h20240402
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rtc_rtl_version: 32;
    } b;
} RTC_RTL_VERSION0_TypeDef;


/* 0x34
   0       R/W    rtc_cmp0_reload_en              1'h0
   1       R/W    rtc_cmp1_reload_en              1'h0
   2       R/W    rtc_cmp2_reload_en              1'h0
   3       R/W    rtc_cmp3_reload_en              1'h0
   31:4    R      rtc_qactive_ctrl_reserved31_4   28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp0_reload_en: 1;
        uint32_t rtc_cmp1_reload_en: 1;
        uint32_t rtc_cmp2_reload_en: 1;
        uint32_t rtc_cmp3_reload_en: 1;
        const uint32_t rtc_qactive_ctrl_reserved31_4: 28;
    } b;
} RTC_RELOAD_CTRL_TypeDef;


/* 0x38
   31:0    R/W    rtc_cmp0_reload                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp0_reload: 32;
    } b;
} RTC_COMP_0_RELOAD_TypeDef;


/* 0x3C
   31:0    R/W    rtc_cmp1_reload                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp1_reload: 32;
    } b;
} RTC_COMP_1_RELOAD_TypeDef;


/* 0x40
   31:0    R/W    rtc_cmp2_reload                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp2_reload: 32;
    } b;
} RTC_COMP_2_RELOAD_TypeDef;


/* 0x44
   31:0    R/W    rtc_cmp3_reload                 32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_cmp3_reload: 32;
    } b;
} RTC_COMP_3_RELOAD_TypeDef;


/* 0x48
   0       R/W    rtc_rap_mode                    1'h0
   1       R/WAC  rtc_fw_task_start               1'h0
   2       R/WAC  rtc_fw_task_stop                1'h0
   3       R/WAC  rtc_fw_task_clear               1'h0
   4       R/WAC  rtc_fw_task_reload_cmp0         1'h0
   5       R/WAC  rtc_fw_task_reload_cmp1         1'h0
   6       R/WAC  rtc_fw_task_reload_cmp2         1'h0
   7       R/WAC  rtc_fw_task_reload_cmp3         1'h0
   31:8    R      rtc_task_ctrl_reserved31_8      24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_rap_mode: 1;
        uint32_t rtc_fw_task_start: 1;
        uint32_t rtc_fw_task_stop: 1;
        uint32_t rtc_fw_task_clear: 1;
        uint32_t rtc_fw_task_reload_cmp0: 1;
        uint32_t rtc_fw_task_reload_cmp1: 1;
        uint32_t rtc_fw_task_reload_cmp2: 1;
        uint32_t rtc_fw_task_reload_cmp3: 1;
        const uint32_t rtc_task_ctrl_reserved31_8: 24;
    } b;
} RTC_TASK_CTRL_TypeDef;


/* 0x4C
   0       R/W    rtc_task_stop_sub_en            1'h0
   1       R/W    rtc_task_clear_sub_en           1'h0
   2       R/W    rtc_task_reload_cmp0_sub_en     1'h0
   3       R/W    rtc_task_reload_cmp1_sub_en     1'h0
   4       R/W    rtc_task_reload_cmp2_sub_en     1'h0
   5       R/W    rtc_task_reload_cmp3_sub_en     1'h0
   15:6    R      rtc_shot_ctrl_reserved15_6      10'h0
   16      R/W    rtc_event_cmp0_pub_en           1'h0
   17      R/W    rtc_event_cmp1_pub_en           1'h0
   18      R/W    rtc_event_cmp2_pub_en           1'h0
   19      R/W    rtc_event_cmp3_pub_en           1'h0
   31:20   R      rtc_shot_ctrl_reserved31_20     12'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_task_stop_sub_en: 1;
        uint32_t rtc_task_clear_sub_en: 1;
        uint32_t rtc_task_reload_cmp0_sub_en: 1;
        uint32_t rtc_task_reload_cmp1_sub_en: 1;
        uint32_t rtc_task_reload_cmp2_sub_en: 1;
        uint32_t rtc_task_reload_cmp3_sub_en: 1;
        const uint32_t rtc_shot_ctrl_reserved15_6: 10;
        uint32_t rtc_event_cmp0_pub_en: 1;
        uint32_t rtc_event_cmp1_pub_en: 1;
        uint32_t rtc_event_cmp2_pub_en: 1;
        uint32_t rtc_event_cmp3_pub_en: 1;
        const uint32_t rtc_shot_ctrl_reserved31_20: 12;
    } b;
} RTC_SHOT_CTRL_TypeDef;


/* 0x50
   0       R/W    rtc_qact_sclk_man_data          1'h0
   1       R/W    rtc_qact_sclk_man_en            1'h0
   2       R/W    rtc_qact_pclk_man_data          1'h0
   3       R/W    rtc_qact_pclk_man_en            1'h0
   31:4    R      rtc_qactive_ctrl_reserved31_4   28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rtc_qact_sclk_man_data: 1;
        uint32_t rtc_qact_sclk_man_en: 1;
        uint32_t rtc_qact_pclk_man_data: 1;
        uint32_t rtc_qact_pclk_man_en: 1;
        const uint32_t rtc_qactive_ctrl_reserved31_4: 28;
    } b;
} RTC_QACTIVE_CTRL_TypeDef;


/*============================================================================*
 *                          RTC Constants
 *============================================================================*/
/** \defgroup RTC        RTC
  * \brief
  * \{
  */

/** \defgroup RTC_Exported_Constants RTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    RTC_CLOCK_IN RTC CLOCK IN
 * \{
 * \ingroup     RTC_Exported_Constants
 */

typedef enum
{
    RTC_CLOCK_IN_DISABLE,
    RTC_CLOCK_IN_P5_1,
    RTC_CLOCK_IN_P2_1,
    RTC_CLOCK_IN_MAX = RTC_CLOCK_IN_DISABLE,
} RTCClockIn_TypeDef;

#define RTC_CLOCK_IN         (RTC_CLOCK_OUT_DISABLE | \
                              RTC_CLOCK_OUT_P5_1 | \
                              RTC_CLOCK_OUT_P2_1)

/** End of RTC_CLOCK_IN
  * \}
  */

/**
 * \defgroup    RTC_CLOCK_OUT RTC CLOCK OUT
 * \{
 * \ingroup     RTC_Exported_Constants
 */

typedef enum
{
    RTC_CLOCK_OUT_P0_1_OSC,
    RTC_CLOCK_OUT_P0_1_XTAL,
    RTC_CLOCK_OUT_P0_3_OSC,
    RTC_CLOCK_OUT_P0_3_XTAL,
} RTCClockOut_TypeDef;

#define RTC_CLOCK_OUT         (RTC_CLOCK_OUT_P0_1_OSC | \
                               RTC_CLOCK_OUT_P0_1_XTAL | \
                               RTC_CLOCK_OUT_P0_3_OSC \
                               RTC_CLOCK_OUT_P0_3_XTAL)

/** End of RTC_CLOCK_OUT
  * \}
  */

/** End of RTC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         RTC Wrappers
 *============================================================================*/

/**
 * \brief    RTC Macro Wrapper
 *
 * \ingroup  RTC_Exported_Constants
 */
#define RTC_WRITE(reg, value)         \
    do {                              \
        RTC->reg = (value);           \
    } while (0)

#define RTC_WRITE_DELAY(reg, value)   \
    do {                              \
        RTC->reg = (value);           \
        platform_delay_us(63);        \
    } while (0)

/** End of RTC
  * \}
  */


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_RTC_DEF_H */
