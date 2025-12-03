/**
*****************************************************************************************
*     Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
* \file    rtl_keyscan_def.h
* \brief   KEYSCAN related definitions for RTL87x2G.
* \author
* \date    2023-11-16
* \version v1.0
* *************************************************************************************
*/

#ifndef RTL_KEYSCAN_DEF_H
#define RTL_KEYSCAN_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */
/*============================================================================*
 *                         KEYSCAN Defines
 *============================================================================*/
/** \defgroup KEYSCAN         KEYSCAN
  * \brief
  * \{
  */

/** \defgroup KEYSCAN_Exported_Constants KEYSCAN Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup KEYSCAN_Defines KEYSCAN Defines
 * \{
 * \ingroup  KEYSCAN_Exported_Constants
 */
#define KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE (0)
#define KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE    (1)
#define KEYSCAN_SUPPORT_RAP_FUNCTION           (0)

/** End of KEYSCAN_Defines
  * \}
  */

/** End of KEYSCAN_Exported_Constants
  * \}
  */

/** End of KEYSCAN
  * \}
  */

/*============================================================================*
 *                         KEYSCAN Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t  KEYSCAN_CLK_DIV;         /*!< 0x00 */
    __IO uint32_t  KEYSCAN_CONFIG1;         /*!< 0x04 */
    __IO uint32_t  KEYSCAN_CONFIG2;         /*!< 0x08 */
    __IO uint32_t  KEYSCAN_COLUMN_CONFIG;   /*!< 0x0C */
    __IO uint32_t  KEYSCAN_ROW_CONFIG;      /*!< 0x10 */
    __I  uint32_t  KEYSCAN_FIFO_ENTRY;      /*!< 0x14 */
    __IO uint32_t  KEYSCAN_INT_MASK;        /*!< 0x18 */
    __IO uint32_t  KEYSCAN_INT_CLR;         /*!< 0x1C */
    __I  uint32_t  KEYSCAN_INT_STS;         /*!< 0x20 */
    __I  uint32_t  RSVD0[3];                /*!< 0x24 - 0x2C */
    __I  uint32_t  KEYSCAN_DBG1;            /*!< 0x30 */
    __IO uint32_t  KEYSCAN_DBG2;            /*!< 0x34 */
} KEYSCAN_TypeDef;

/*============================================================================*
 *                         KEYSCAN Declaration
 *============================================================================*/
#define KEYSCAN                     ((KEYSCAN_TypeDef *) KEYSCAN_REG_BASE)

#define IS_KeyScan_PERIPH(PERIPH)   ((PERIPH) == KEYSCAN)

/*============================================================================*
 *                         KEYSCAN Private Types
 *============================================================================*/
typedef struct
{
    uint32_t keyscan_reg[7];
} KEYSCANStoreReg_Typedef;

/*============================================================================*
 *                         KEYSCAN Registers and Field Descriptions
 *============================================================================*/
/* 0x00
    5:0     R/W    keyscan_delay_div                   6'h1
    7:6     R/W    reserved_dummy00_7_6                2'h0
    18:8    R/W    keyscan_clk_div                     11'h26
    23:19   R      reserved_dummy00_23_19              5'h0
    25:24   R/W    keyscan_clk_sel                     2'h0
    28:26   R/W    keyscan_gt_pre_sel                  3'h3
    31:29   R/W    keyscan_gt_post_sel                 3'h3
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t keyscan_delay_div: 6;
        uint32_t reserved_1: 2;
        uint32_t keyscan_clk_div: 11;
        const uint32_t reserved_0: 5;
            uint32_t keyscan_clk_sel: 2;
            uint32_t keyscan_gt_pre_sel: 3;
            uint32_t keyscan_gt_post_sel: 3;
        } b;
    } KEYSCAN_CLK_DIV_TypeDef;



    /* 0x04
        8:0     R/W    keyscan_release_timer_cnt           9'h10
        17:9    R/W    keyscan_interval_timer_cnt          9'h10
        26:18   R/W    keyscan_deb_timer_cnt               9'h10
        27      R      reserved_dummy04_27                 1'h0
        28      R/W    keyscan_row_pull_high_en            1'h1
        29      R/W    keyscan_release_timer_en            1'h0
        30      R/W    keyscan_interval_timer_en           1'h1
        31      R/W    keyscan_deb_timer_en                1'h1
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_release_timer_cnt: 9;
                uint32_t keyscan_interval_timer_cnt: 9;
                uint32_t keyscan_deb_timer_cnt: 9;
                const uint32_t reserved_0: 1;
                uint32_t keyscan_row_pull_high_en: 1;
                uint32_t keyscan_release_timer_en: 1;
                uint32_t keyscan_interval_timer_en: 1;
                uint32_t keyscan_deb_timer_en: 1;
            } b;
        } KEYSCAN_CONFIG1_TypeDef;



    /* 0x08
        0       R/W    keyscan_all_release_int_en          1'h0
        1       R/W    keyscan_fifo_notempty_int_en        1'h0
        2       R/W    keyscan_scan_finish_int_en          1'h0
        3       R/W    keyscan_fifo_or_int_en              1'h0
        4       R/W    keyscan_fifo_th_int_en              1'h0
        9:5     R/W    keyscan_fifo_th_level               5'h1a
        10      R      reserved_dummy08_10                 1'h0
        11      R/W    keyscan_manual_sel                  1'h0
        20:12   R/W    keyscan_fifo_filter_data            9'h0
        21      R/W    keyscan_fifo_data_filter_en         1'h0
        22      R/W    keyscan_manual_trigger              1'h0
        27:23   R/W    keyscan_fifo_limit                  5'h0
        28      R/W    keyscan_fifo_ov_ctrl                1'h1
        29      R/W    keyscan_trig_sel                    1'h1
        30      R/W    keyscan_work_mode                   1'h1
        31      R/W    keyscan_run_enable                  1'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_all_release_int_en: 1;
                uint32_t keyscan_fifo_notempty_int_en: 1;
                uint32_t keyscan_scan_finish_int_en: 1;
                uint32_t keyscan_fifo_or_int_en: 1;
                uint32_t keyscan_fifo_th_int_en: 1;
                uint32_t keyscan_fifo_th_level: 5;
                const uint32_t reserved_0: 1;
                uint32_t keyscan_manual_sel: 1;
                uint32_t keyscan_fifo_filter_data: 9;
                uint32_t keyscan_fifo_data_filter_en: 1;
                uint32_t keyscan_manual_trigger: 1;
                uint32_t keyscan_fifo_limit: 5;
                uint32_t keyscan_fifo_ov_ctrl: 1;
                uint32_t keyscan_trig_sel: 1;
                uint32_t keyscan_work_mode: 1;
                uint32_t keyscan_run_enable: 1;
            } b;
        } KEYSCAN_CONFIG2_TypeDef;



    /* 0x0C
        4:0     R/W    keyscan_col_num                     5'h0
        7:5     R      reserved_dummy0c_7_5                3'h0
        27:8    R/W    keyscan_col_sel                     20'h0
        31:28   R      reserved_dummy0c_31_28              4'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_col_num: 5;
                const uint32_t reserved_1: 3;
                uint32_t keyscan_col_sel: 20;
                const uint32_t reserved_0: 4;
            } b;
        } KEYSCAN_COLUMN_CONFIG_TypeDef;



    /* 0x10
        11:0    R/W    keyscan_row_sel                     12'h0
        15:12   R      reserved_dummy10_15_12              4'h0
        19:16   R/W    keyscan_row_num                     4'h0
        31:20   R      reserved_dummy10_31_20              12'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_row_sel: 12;
                const uint32_t reserved_1: 4;
                uint32_t keyscan_row_num: 4;
                const uint32_t reserved_0: 12;
            } b;
        } KEYSCAN_ROW_CONFIG_TypeDef;



    /* 0x14
        8:0     R      keyscan_fifo_entry                  9'h0
        31:9    R      reserved_dummy14_31_9               23'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t keyscan_fifo_entry: 9;
                const uint32_t reserved_0: 23;
            } b;
        } KEYSCAN_FIFO_ENTRY_TypeDef;



    /* 0x18
        0       R/W    keyscan_all_release_int_mask        1'h0
        1       R/W    keyscan_fifo_notempty_int_mask      1'h0
        2       R/W    keyscan_scan_finish_int_mask        1'h0
        3       R/W    keyscan_fifo_or_int_mask            1'h0
        4       R/W    keyscan_fifo_th_int_mask            1'h0
        31:5    R      reserved_dummy18_31_5               27'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_all_release_int_mask: 1;
                uint32_t keyscan_fifo_notempty_int_mask: 1;
                uint32_t keyscan_scan_finish_int_mask: 1;
                uint32_t keyscan_fifo_or_int_mask: 1;
                uint32_t keyscan_fifo_th_int_mask: 1;
                const uint32_t reserved_0: 27;
            } b;
        } KEYSCAN_INT_MASK_TypeDef;



    /* 0x1C
        0       W1C    keyscan_all_release_int_clr         1'h0
        1       W1C    keyscan_fifo_notempty_int_clr       1'h0
        2       W1C    keyscan_scan_finish_int_clr         1'h0
        3       W1C    keyscan_fifo_or_int_clr             1'h0
        4       W1C    keyscan_fifo_th_int_clr             1'h0
        5       W1C    keyscan_fifo_ov_st_clr              1'h0
        6       W1C    keyscan_fifo_clr                    1'h0
        7       W1C    keyscan_fifo_datafilter_st_clr      1'h0
        8       W1C    keyscan_fifo_limit_st_clr           1'h0
        31:9    R      reserved_dummy1c_31_9               23'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t keyscan_all_release_int_clr: 1;
                uint32_t keyscan_fifo_notempty_int_clr: 1;
                uint32_t keyscan_scan_finish_int_clr: 1;
                uint32_t keyscan_fifo_or_int_clr: 1;
                uint32_t keyscan_fifo_th_int_clr: 1;
                uint32_t keyscan_fifo_ov_st_clr: 1;
                uint32_t keyscan_fifo_clr: 1;
                uint32_t keyscan_fifo_datafilter_st_clr: 1;
                uint32_t keyscan_fifo_limit_st_clr: 1;
                const uint32_t reserved_0: 23;
            } b;
        } KEYSCAN_INT_CLR_TypeDef;



    /* 0x20
        0       R      keyscan_fifo_empty                  1'h0
        1       R      keyscan_fifo_full                   1'h0
        2       R      keyscan_fifo_ov_status              1'h0
        3       R      keyscan_fifo_datafilter_status      1'h0
        9:4     R      keyscan_fifo_data_level             6'h0
        14:10   R      reserved_dummy20_14_10              5'h0
        15      R      keyscan_all_release_int_status      1'h0
        16      R      keyscan_fifo_notempty_int_status    1'h0
        17      R      keyscan_scan_finish_int_status      1'h0
        18      R      keyscan_fifo_or_int_status          1'h0
        19      R      keyscan_fifo_th_int_status          1'h0
        20      R      keyscan_fifo_limit_status           1'h0
        31:21   R      reserved_dummy20_31_21              11'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t keyscan_fifo_empty: 1;
                const uint32_t keyscan_fifo_full: 1;
                const uint32_t keyscan_fifo_ov_status: 1;
                const uint32_t keyscan_fifo_datafilter_status: 1;
                const uint32_t keyscan_fifo_data_level: 6;
                const uint32_t reserved_1: 5;
                const uint32_t keyscan_all_release_int_status: 1;
                const uint32_t keyscan_fifo_notempty_int_status: 1;
                const uint32_t keyscan_scan_finish_int_status: 1;
                const uint32_t keyscan_fifo_or_int_status: 1;
                const uint32_t keyscan_fifo_th_int_status: 1;
                const uint32_t keyscan_fifo_limit_status: 1;
                const uint32_t reserved_0: 11;
            } b;
        } KEYSCAN_INT_STS_TypeDef;



    /* 0x30
        31:0    R      rtl_version                         32'h20221011
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rtl_version: 32;
            } b;
        } KEYSCAN_DBG1_TypeDef;



    /* 0x34
        2:0     R/W    dbg_sel                             3'h0
        3       R/W    reg_speedup_mode                    1'h0
        6:4     R      current_state                       3'h0
        30:7    R      reserved_dummy34_30_7               24'h0
        31      R/W    force_512k                          1'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dbg_sel: 3;
                uint32_t reg_speedup_mode: 1;
                const uint32_t current_state: 3;
                const uint32_t reserved_0: 24;
                uint32_t force_512k: 1;
            } b;
        } KEYSCAN_DBG2_TypeDef;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_KEYSCAN_DEF_H */
