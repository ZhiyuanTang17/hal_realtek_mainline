/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_adc_def.h
* \brief    ADC related definitions for RTL87x2G
* \details
* \author
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_ADC_DEF_H
#define RTL_ADC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         ADC Defines
 *============================================================================*/
/** \defgroup ADC         ADC
  * \brief
  * \{
  */

/** \defgroup ADC_Exported_Constants ADC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup ADC_Defines ADC Defines
 * \{
 * \ingroup  ADC_Exported_Constants
 */
#define CHIP_ADC_CHANNEL_NUM                           (8)
#define CHIP_ADC_SCHEDULE_NUM                          (16)
#define CHIP_ADC_MODE_OFFSET                           (3)
#define ADC_SUPPORT_DMA_EN                             (0)
#define ADC_SUPPORT_INT_FIFO_FULL                      (0)
#define ADC_SUPPORT_VADPIN_MODE                        (0)
#define ADC_SUPPORT_POWER_OFF                          (1)
#define ADC_SUPPORT_POWER_ON_DELAY                     (1)

/** End of ADC_Defines
  * \}
  */

/** End of ADC_Exported_Constants
  * \}
  */

/** End of ADC
  * \}
  */
/*============================================================================*
 *                         ADC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __I  uint32_t ADC_FIFO_READ;              /*!< 0x00 */
    __IO uint32_t ADC_DIG_CTRL;               /*!< 0x04 */
    __IO uint32_t ADC_SCHED_CTRL;             /*!< 0x08 */
    __IO uint32_t ADC_CTRL_INT;               /*!< 0x0C */
    __IO uint16_t ADC_SCHTAB0;                /*!< 0x10 */
    __IO uint16_t ADC_SCHTAB1;
    __IO uint16_t ADC_SCHTAB2;                /*!< 0x14 */
    __IO uint16_t ADC_SCHTAB3;
    __IO uint16_t ADC_SCHTAB4;                /*!< 0x18 */
    __IO uint16_t ADC_SCHTAB5;
    __IO uint16_t ADC_SCHTAB6;                /*!< 0x1C */
    __IO uint16_t ADC_SCHTAB7;
    __IO uint16_t ADC_SCHTAB8;                /*!< 0x20 */
    __IO uint16_t ADC_SCHTAB9;
    __IO uint16_t ADC_SCHTAB10;               /*!< 0x24 */
    __IO uint16_t ADC_SCHTAB11;
    __IO uint16_t ADC_SCHTAB12;               /*!< 0x28 */
    __IO uint16_t ADC_SCHTAB13;
    __IO uint16_t ADC_SCHTAB14;               /*!< 0x2C */
    __IO uint16_t ADC_SCHTAB15;
    __I  uint16_t ADC_SCHD0;                  /*!< 0x30 */
    __I  uint16_t ADC_SCHD1;
    __I  uint16_t ADC_SCHD2;                  /*!< 0x34 */
    __I  uint16_t ADC_SCHD3;
    __I  uint16_t ADC_SCHD4;                  /*!< 0x38 */
    __I  uint16_t ADC_SCHD5;
    __I  uint16_t ADC_SCHD6;                  /*!< 0x3C */
    __I  uint16_t ADC_SCHD7;
    __I  uint16_t ADC_SCHD8;                  /*!< 0x40 */
    __I  uint16_t ADC_SCHD9;
    __I  uint16_t ADC_SCHD10;                 /*!< 0x44 */
    __I  uint16_t ADC_SCHD11;
    __I  uint16_t ADC_SCHD12;                 /*!< 0x48 */
    __I  uint16_t ADC_SCHD13;
    __I  uint16_t ADC_SCHD14;                 /*!< 0x4C */
    __I  uint16_t ADC_SCHD15;
    __IO uint32_t ADC_POW_DATA_DLY_CTRL;      /*!< 0x50 */
    __IO uint32_t ADC_DATA_CLK_CTRL;          /*!< 0x54 */
    __IO uint32_t RSVD1;                      /*!< 0x58 */
    __IO uint32_t ADC_TIME_PERIOD;            /*!< 0x5C */
    __IO uint32_t RSVD2;                      /*!< 0x60 */
} ADC_TypeDef;

/*============================================================================*
 *                         ADC Declaration
 *============================================================================*/
#define ADC                     ((ADC_TypeDef *) SAR_ADC_REG_BASE)
#define IS_ADC_PERIPH(PERIPH)   ((PERIPH) == ADC)
/*============================================================================*
 *                         ADC Private Types
 *============================================================================*/
typedef struct
{
    uint32_t adc_reg[6];
    uint32_t adc_schtab_reg[16];
} ADCStoreReg_TypeDef;

/*============================================================================*
 *                         ADC Registers and Field Descriptions
 *============================================================================*/
/**
* @brief Analog to digital converter. (ADC)
*/
/* 0x00
    11:0    R      adc_fifo_data_out               12'h0
    15:12   R      reserved_dummy00_15_12          4'h0
    27:16   R      reserved_dummy00_27_16          12'h0
    31:28   R      adc_schedule_index              4'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t adc_fifo_data_out: 12;
            const uint32_t reserved_1: 4;
            const uint32_t reserved_0: 12;
            const uint32_t adc_schedule_index: 4;
        } b;
    } ADC_FIFO_READ_TypeDef;



    /* 0x04
        0       R/W    en_adc_continous_mode           1'h0
        1       W1C    en_adc_one_shot_mode            1'h0
        2       R/W    reserved_dummy04_02             1'h0
        7:3     R      adc_fifo_wpt                    5'h0
        12:8    R      adc_fifo_rpt                    5'h0
        13      R/W    adc_fifo_overwrite              1'h0
        19:14   R/W    adc_burst_size                  6'h0
        25:20   R/W    adc_fifo_thd                    6'h0
        26      W1C    adc_fifo_clr                    1'h0
        27      R/W    adc_one_shot_fifo               1'h0
        29:28   R      reserved_dummy04_29_28          2'h0
        31:30   R/W    adc_dbg_sel                     2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t en_adc_continous_mode: 1;
                uint32_t en_adc_one_shot_mode: 1;
                const uint32_t reserved_1: 1;
                const uint32_t adc_fifo_wpt: 5;
                const uint32_t adc_fifo_rpt: 5;
                uint32_t adc_fifo_overwrite: 1;
                uint32_t adc_burst_size: 6;
                uint32_t adc_fifo_thd: 6;
                uint32_t adc_fifo_clr: 1;
                uint32_t adc_one_shot_fifo: 1;
                const uint32_t reserved_0: 2;
                uint32_t adc_dbg_sel: 2;
            } b;
        } ADC_DIG_CTRL_TypeDef;



    /* 0x08
        16:0    R/W    adc_schedule_idx_sel            16'h0
        16:20   R      adc_fifo_data_level             6'h0
        31:22   R      reserved_dummy08_31_22          19'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_schedule_idx_sel: 16;
                const uint32_t adc_fifo_data_level: 6;
                const uint32_t reserved_0: 10;
            } b;
        } ADC_SCHED_CTRL_TypeDef;



    /* 0x0C
        0       R/W    en_adc_fifio_rd_req_interrupt   1'h0
        1       R/W    en_adc_fifo_rd_error_interrupt  1'h0
        2       R/W    en_adc_fifo_thd_interrupt       1'h0
        3       R/W    en_adc_fifo_overflow_interrupt  1'h0
        4       R/W    en_adc_one_shot_done_interrupt  1'h0
        7:5     R      reserved_dummy0c_7_5            3'h0
        8       W1C    clr_adc_fifio_rd_req_interrupt  1'h0
        9       W1C    clr_adc_fifo_rd_error_interrupt 1'h0
        10      W1C    clr_adc_fifo_thd_interrupt      1'h0
        11      W1C    clr_adc_fifo_overflow_interrupt 1'h0
        12      W1C    clr_adc_one_shot_done_interrupt 1'h0
        15:13   R      reserved_dummy0c_15_13          3'h0
        16      R      st_adc_fifio_rd_req_interrupt   1'h0
        17      R      st_adc_fifo_rd_error_interrupt  1'h0
        18      R      st_adc_fifo_thd_interrupt       1'h0
        19      R      st_adc_fifo_overflow_interrupt  1'h0
        20      R      st_adc_one_shot_done_interrupt  1'h0
        31:21   R      reserved_dummy0c_31_21          11'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t en_adc_fifio_rd_req_interrupt: 1;
                uint32_t en_adc_fifo_rd_error_interrupt: 1;
                uint32_t en_adc_fifo_thd_interrupt: 1;
                uint32_t en_adc_fifo_overflow_interrupt: 1;
                uint32_t en_adc_one_shot_done_interrupt: 1;
                const uint32_t reserved_2: 3;
                uint32_t clr_adc_fifio_rd_req_interrupt: 1;
                uint32_t clr_adc_fifo_rd_error_interrupt: 1;
                uint32_t clr_adc_fifo_thd_interrupt: 1;
                uint32_t clr_adc_fifo_overflow_interrupt: 1;
                uint32_t clr_adc_one_shot_done_interrupt: 1;
                const uint32_t reserved_1: 3;
                const uint32_t st_adc_fifio_rd_req_interrupt: 1;
                const uint32_t st_adc_fifo_rd_error_interrupt: 1;
                const uint32_t st_adc_fifo_thd_interrupt: 1;
                const uint32_t st_adc_fifo_overflow_interrupt: 1;
                const uint32_t st_adc_one_shot_done_interrupt: 1;
                const uint32_t reserved_0: 11;
            } b;
        } ADC_CTRL_INT_TypeDef;



    /* 0x10-0x2C
        3:0     R/W    ch_num_idx0                     4'h0
        5:4     R/W    adc_mode_idx0                   2'h0
        15:6    R      reserved_dummy10_15_5           10'h0
    */
    typedef union
        {
            uint32_t d16;
            uint8_t d8[2];
            struct
            {
                uint32_t ch_num_idx: 4;
                uint32_t adc_mode_idx: 2;
                const uint32_t reserved: 10;
            } b;
        } ADC_SCHED_TAB_IDX_TypeDef;


    /* 0x30-0x4c
        11:0    R      adc_idx_output_data            12'h0
        15:12   R      reserved_dummy30_15_12          4'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t adc_idx_output_data: 12;
                const uint32_t reserved_1: 4;
            } b;
        } ADC_IDX_OUTPUT_DATA_TypeDef;


    /* 0x50
        1:0     R/W    adc_reg0x_aux_v09_1_delay_sel   2'h0
        3:2     R/W    adc_reg0x_ldo_2_delay_sel       2'h0
        5:4     R/W    adc_reg0x_ldo_1_delay_sel       2'h0
        8:6     R/W    adc_data_delay                  3'h1
        9       R      reserved_dummy50_9              1'h0
        14:10   R/W    adc_poweron_select              5'h0
        15      R/W    adc_poweron_only_en             1'h0
        18:16   R      reserved_dummy50_18_16          3'h0
        19      R/W    adc_manual_poweron              1'h0
        20      R      reserved_dummy50_20             1'h0
        21      R/W    adc_fifo_stop_wr                1'h0
        23:22   R      reserved_dummy50_23_22          2'h0
        24      R/W    adc_data_avg_en                 1'h0
        27:25   R/W    adc_data_avg_sel                3'h0
        30:28   R      reserved_dummy50_30_28          3'h0
        31      R/W    reserved_dummy50_31             1'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_reg0x_aux_v09_1_delay_sel: 2;
                uint32_t adc_reg0x_ldo_2_delay_sel: 2;
                uint32_t adc_reg0x_ldo_1_delay_sel: 2;
                uint32_t adc_data_delay: 3;
                const uint32_t reserved_5: 1;
                uint32_t adc_poweron_select: 5;
                uint32_t adc_poweron_only_en: 1;
                const uint32_t reserved_4: 3;
                uint32_t adc_manual_poweron: 1;
                const uint32_t reserved_3: 1;
                uint32_t adc_fifo_stop_wr: 1;
                const uint32_t reserved_2: 2;
                uint32_t adc_data_avg_en: 1;
                uint32_t adc_data_avg_sel: 3;
                const uint32_t reserved_1: 3;
                uint32_t reserved_0: 1;
            } b;
        } ADC_POW_DATA_DLY_CTRL_TypeDef;



    /* 0x54
        7:0     R      reserved_dummy54_7_0            8'h0
        8       R/W    adc_keep_ck_ad_high             1'h0
        10:9    R      reserved_dummy54_10_9           2'h0
        12:11   R/W    adc_delay_tune_sel              2'h0
        15:13   R      reserved_dummy54_15_13          3'h0
        27:16   R/W    adc_data_offset                 12'h0
        28      R      reserved_dummy54_28             1'h0
        29      R/W    adc_timer_trigger_en            1'h0
        30      R/W    adc_data_align_msb              1'h0
        31      R/W    adc_data_offset_en              1'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t reserved_3: 8;
                uint32_t adc_keep_ck_ad_high: 1;
                const uint32_t reserved_2: 2;
                uint32_t adc_delay_tune_sel: 2;
                const uint32_t reserved_1: 3;
                uint32_t adc_data_offset: 12;
                const uint32_t reserved_0: 1;
                uint32_t adc_timer_trigger_en: 1;
                uint32_t adc_data_align_msb: 1;
                uint32_t adc_data_offset_en: 1;
            } b;
        } ADC_DATA_CLK_CTRL_TypeDef;

    /* 0x5C
        13:0    R/W    adc_sample_time_period          14'h3E7
        29:14   R      reserved_dummy5c_29_14          16'h0
        31:30   R/W    adc_convert_time_period_sel     2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_sample_time_period: 14;
                const uint32_t reserved_0: 16;
                uint32_t adc_convert_time_period_sel: 2;
            } b;
        } ADC_TIME_PERIOD_TypeDef;


    /*============================================================================*
     *                          ADC MODE Wrappers
     *============================================================================*/
    /** \defgroup ADC        ADC
      * \brief
      * \{
      */

    /** \defgroup ADC_Exported_Constants ADC Exported Constants
      * \brief
      * \{
      */

    /**
     * \defgroup ADC_Constant_Wrapper ADC Constant Wrapper
     * \{
     * \ingroup  ADC_Exported_Constants
     */
#define ADC_MODE_SINGLE_ENDED_VALUE     0x0
#define ADC_MODE_DIFFERENTIAL_VALUE     0x1
#define ADC_MODE_INTERNAL_VALUE         0x2
#define ADC_MODE_RESERVED_VALUE         0x3

    /** End of ADC_Constant_Wrapper
      * \}
      */

    /**
     * \defgroup ADC_Function_Wrapper ADC Function Wrapper
     * \{
     * \ingroup  ADC_Exported_Constants
     */
#define ADC_SchTableConfig(ADCx, Index, AdcMode) ADC_SchIndexConfig(ADCx, AdcMode, Index)

    /** End of ADC_Function_Wrapper
      * \}
      */

    /** End of ADC_Exported_Constants
      * \}
      */

    /** End of ADC
      * \}
      */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_ADC_DEF_H */
