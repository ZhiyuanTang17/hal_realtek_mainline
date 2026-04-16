/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
 *                          ADC Defines
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
#define ADC_SUPPORT_DMA_EN                             (1)
#define ADC_SUPPORT_INT_FIFO_FULL                      (1)
#define ADC_SUPPORT_VADPIN_MODE                        (0)
#define ADC_SUPPORT_DATAMINUS                          (0)
#define ADC_SUPPORT_POWER_OFF                          (1)
#define ADC_SUPPORT_POWER_ON_DELAY                     (1)
#define ADC_SUPPORT_RAP_FUNCTION                       (1)
#define ADC_SUPPORT_AUTO_CLOCK                         (1)
#define ADC_SUPPORT_18BIT_RAW_DATA                     (1)
#define ADC_SUPPORT_DATA_CLIP                          (1)
#define ADC_SUPPORT_HW_MAPPING                         (1)
#define ADC_SUPPORT_BYPASS_AUTO_REVERT                 (0)
#define ADC_SUPPORT_SAMPLE_RATE_GUARDTIME              (1)
#define ADC_SUPPORT_TIMER_TRIGGER                      (0)
#define ADC_SUPPORT_AUTO_BOOT_PROTECT                  (1)
#define ADC_SUPPORT_GET_VOTAGE_API                     (1)
//#define ADC_POWER_MODE_CTRL_EN                      (0)  //if you need to configure the power mode, you can predefine this macro in the project settings.
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
 *                          ADC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t ADC_FIFO;                         /*!< 0x00 */
    __IO uint32_t ADC_CTRL;                         /*!< 0x04 */
    __IO uint32_t ADC_SCHED_CTRL;                   /*!< 0x08 */
    __IO uint32_t ADC_INT;                          /*!< 0x0C */
    __IO uint16_t ADC_SCHTAB0;                      /*!< 0x10 */
    __IO uint16_t ADC_SCHTAB1;
    __IO uint16_t ADC_SCHTAB2;                      /*!< 0x14 */
    __IO uint16_t ADC_SCHTAB3;
    __IO uint16_t ADC_SCHTAB4;                      /*!< 0x18 */
    __IO uint16_t ADC_SCHTAB5;
    __IO uint16_t ADC_SCHTAB6;                      /*!< 0x1C */
    __IO uint16_t ADC_SCHTAB7;
    __IO uint16_t ADC_SCHTAB8;                      /*!< 0x20 */
    __IO uint16_t ADC_SCHTAB9;
    __IO uint16_t ADC_SCHTAB10;                     /*!< 0x24 */
    __IO uint16_t ADC_SCHTAB11;
    __IO uint16_t ADC_SCHTAB12;                     /*!< 0x28 */
    __IO uint16_t ADC_SCHTAB13;
    __IO uint16_t ADC_SCHTAB14;                     /*!< 0x2C */
    __IO uint16_t ADC_SCHTAB15;
    __I  uint32_t ADC_DATA0;                        /*!< 0x30 */
    __I  uint32_t ADC_DATA1;                        /*!< 0x34 */
    __I  uint32_t ADC_DATA2;                        /*!< 0x38 */
    __I  uint32_t ADC_DATA3;                        /*!< 0x3C */
    __I  uint32_t ADC_DATA4;                        /*!< 0x40 */
    __I  uint32_t ADC_DATA5;                        /*!< 0x44 */
    __I  uint32_t ADC_DATA6;                        /*!< 0x48 */
    __I  uint32_t ADC_DATA7;                        /*!< 0x4C */
    __I  uint32_t ADC_DATA8;                        /*!< 0x50 */
    __I  uint32_t ADC_DATA9;                        /*!< 0x54 */
    __I  uint32_t ADC_DATA10;                       /*!< 0x58 */
    __I  uint32_t ADC_DATA11;                       /*!< 0x5C */
    __I  uint32_t ADC_DATA12;                       /*!< 0x60 */
    __I  uint32_t ADC_DATA13;                       /*!< 0x64 */
    __I  uint32_t ADC_DATA14;                       /*!< 0x68 */
    __I  uint32_t ADC_DATA15;                       /*!< 0x6C */
    __IO uint32_t ADC_POW_DATA_DLY_CTRL;            /*!< 0x70 */
    __IO uint32_t ADC_DATA_CLK_CTRL;                /*!< 0x74 */
    __IO uint32_t ADC_TIME_PERIOD;                  /*!< 0x78 */
    __IO uint32_t ADC_RTL_VERSION;                  /*!< 0x7C */
    __IO uint32_t ADC_TASK_CTRL;                    /*!< 0x80 */
    __IO uint32_t ADC_QACTIVE_CTRL;                 /*!< 0x84 */
    __IO uint32_t REG0X_LDO;                        /*!< 0x88 */
    __IO uint32_t REG0X_AUX;                        /*!< 0x8C */
    __IO uint32_t ADC_SING_DIV_CAL_PAR;             /*!< 0x90 */
    __IO uint32_t ADC_SING_BYP_CAL_PAR;             /*!< 0x94 */
    __IO uint32_t ADC_DIFF_DIV_CAL_PAR;             /*!< 0x98 */
    __IO uint32_t ADC_DIFF_BYP_CAL_PAR;             /*!< 0x9C */
    __IO uint32_t ADC_INT_VBAT_CAL_PAR;             /*!< 0xA0 */
    __IO uint32_t ADC_INT_VDDIO_CAL_PAR;            /*!< 0xA4 */
    __IO uint32_t ADC_INT_VDDCORE_CAL_PAR;          /*!< 0xA8 */
    __IO uint32_t ADC_INT_VCORE1_CAL_PAR;           /*!< 0xAC */
} ADC_TypeDef;

/*============================================================================*
 *                          ADC Declaration
 *============================================================================*/
#define ADC                     ((ADC_TypeDef *) AUX_ADC_BASE)

#define IS_ADC_PERIPH(PERIPH)   ((PERIPH) == ADC)

/** \defgroup ADC_Convert_Time LPC Convert Time
  * \{
  * \ingroup  ADC_Exported_Constants
  */

#define ADC_CONVERT_TIME \
    ADC_CONVERT_TIME_600NS =          0x0, \
                                      ADC_CONVERT_TIME_800NS =          0x1, \
                                                                        ADC_CONVERT_TIME_1000NS =         0x2, \
                                                                                ADC_CONVERT_TIME_1200NS =         0x3

/** End of ADC_Convert_Time
  * \}
  */

/*============================================================================*
 *                          ADC Private Types
 *============================================================================*/

/*============================================================================*
 *                          ADC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R      adc_fifo_data_out               32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t adc_fifo_data_out: 32;
    } b;
} ADC_FIFO_TypeDef;


/* 0x04
   0       R/W    en_adc_continuous_mode          1'h0
   1       R/WAC  en_adc_one_shot_mode            1'h0
   2       R/W    reserved_mask                   1'h0
   7:3     R      reserved_mask                   5'h0
   12:8    R      reserved_mask                   5'h0
   13      R/W    adc_fifo_overwrite              1'h0
   19:14   R/W    adc_burst_size                  6'h0
   25:20   R/W    adc_fifo_thd                    6'h0
   26      R/WAC  adc_fifo_clr                    1'h0
   27      R/W    adc_one_shot_fifo               1'h0
   28      R/W    adc_dma_mode                    1'h0
   29      R      reserved04_29                   1'h0
   31:30   R/W    reserved_mask                   2'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t en_adc_continuous_mode: 1;
        uint32_t en_adc_one_shot_mode: 1;
        uint32_t reserved_4: 1;
        const uint32_t reserved_3: 5;
        const uint32_t reserved_2: 5;
        uint32_t adc_fifo_overwrite: 1;
        uint32_t adc_burst_size: 6;
        uint32_t adc_fifo_thd: 6;
        uint32_t adc_fifo_clr: 1;
        uint32_t adc_one_shot_fifo: 1;
        uint32_t adc_dma_mode: 1;
        const uint32_t reserved_1: 1;
        uint32_t reserved_0: 2;
    } b;
} ADC_CTRL_TypeDef;


/* 0x08
   15:0    R/W    adc_schedule_idx_sel            16'h0
   21:16   R      adc_fifo_data_level             6'h0
   27:22   R      reserved08_27_22                6'h0
   31:28   R      adc_schedule_index              4'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t adc_schedule_idx_sel: 16;
        const uint32_t adc_fifo_data_level: 6;
        const uint32_t reserved_0: 6;
        const uint32_t adc_schedule_index: 4;
    } b;
} ADC_SCHED_CTRL_TypeDef;


/* 0x0C
   0       R/W    en_adc_fifo_rd_req_interrupt    1'h0
   1       R/W    en_adc_fifo_rd_error_interrupt  1'h0
   2       R/W    en_adc_fifo_thd_interrupt       1'h0
   3       R/W    en_adc_fifo_full_interrupt      1'h0
   4       R/W    en_adc_one_shot_done_interrupt  1'h0
   5       R/W    en_adc_fifo_overflow_interrupt  1'h0
   7:6     R      reserved0c_7_6                  2'h0
   8       R/W1C  clr_adc_fifo_rd_req_interrupt   1'h0
   9       R/W1C  clr_adc_fifo_rd_error_interrupt 1'h0
   10      R/W1C  clr_adc_fifo_thd_interrupt      1'h0
   11      R/W1C  clr_adc_fifo_full_interrupt     1'h0
   12      R/W1C  clr_adc_one_shot_done_interrupt 1'h0
   13      R/W1C  clr_adc_fifo_overflow_interrupt 1'h0
   15:14   R      reserved0c_15_14                2'h0
   16      R      st_adc_fifo_rd_req_interrupt    1'h0
   17      R      st_adc_fifo_rd_error_interrupt  1'h0
   18      R      st_adc_fifo_thd_interrupt       1'h0
   19      R      st_adc_fifo_full_interrupt      1'h0
   20      R      st_adc_one_shot_done_interrupt  1'h0
   21      R      st_adc_fifo_overflow_interrupt  1'h0
   31:22   R      reserved0c_31_20                10'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t en_adc_fifo_rd_req_interrupt: 1;
        uint32_t en_adc_fifo_rd_error_interrupt: 1;
        uint32_t en_adc_fifo_thd_interrupt: 1;
        uint32_t en_adc_fifo_full_interrupt: 1;
        uint32_t en_adc_one_shot_done_interrupt: 1;
        uint32_t en_adc_fifo_overflow_interrupt: 1;
        const uint32_t reserved_2: 2;
        uint32_t clr_adc_fifo_rd_req_interrupt: 1;
        uint32_t clr_adc_fifo_rd_error_interrupt: 1;
        uint32_t clr_adc_fifo_thd_interrupt: 1;
        uint32_t clr_adc_fifo_full_interrupt: 1;
        uint32_t clr_adc_one_shot_done_interrupt: 1;
        uint32_t clr_adc_fifo_overflow_interrupt: 1;
        const uint32_t reserved_1: 2;
        const uint32_t st_adc_fifo_rd_req_interrupt: 1;
        const uint32_t st_adc_fifo_rd_error_interrupt: 1;
        const uint32_t st_adc_fifo_thd_interrupt: 1;
        const uint32_t st_adc_fifo_full_interrupt: 1;
        const uint32_t st_adc_one_shot_done_interrupt: 1;
        const uint32_t st_adc_fifo_overflow_interrupt: 1;
        const uint32_t reserved_0: 10;
    } b;
} ADC_INT_TypeDef;


/* 0x10-0x2C
   2:0     R/W    ch_num_idx                      3'h0
   4:3     R/W    adc_mode_idx                    2'h0
   15:5    R      reserved10_15_5                 11'h0
*/
typedef union
{
    uint32_t d16;
    struct
    {
        uint32_t ch_num_idx: 3;
        uint32_t adc_mode_idx: 2;
        const uint32_t reserved_1: 11;
    } b;
} ADC_SCHED_TAB_IDX_TypeDef;


/* 0x30 - 0x6C
   31:0    R      adc_idx_output_data            32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t adc_idx_output_data: 32;
    } b;
} ADC_DATA_TypeDef;


/* 0x70
   1:0     R/W    reserved_mask                   2'h0
   3:2     R/W    reserved_mask                   2'h0
   5:4     R/W    reserved_mask                   2'h0
   8:6     R/W    reserved_mask                   3'h2
   9       R      reserved70_9                    1'h0
   10      R/W    reserved_mask                   1'h0
   14:11   R      reserved70_14_11                4'h0
   15      R/W    adc_poweron_only_en             1'h0
   16      R/W    adc_data_clipping_en            1'h0
   18:17   R      reserved70_18_17                2'h0
   19      R/W    reserved_mask                   1'h0
   20      R      reserved70_23_20                1'h0
   21      R/W    adc_fifo_stop_wr                1'h0
   23:22   R      reserved70_23_22                2'h0
   24      R/W    adc_data_avg_en                 1'h0
   27:25   R/W    adc_data_avg_sel                3'h0
   30:28   R      reserved70_30_28                3'h0
   31      R/W    reserved_mask                   1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reserved_12: 2;
        uint32_t reserved_11: 2;
        uint32_t reserved_10: 2;
        uint32_t reserved_9: 3;
        const uint32_t reserved_8: 1;
        uint32_t reserved_7: 1;
        const uint32_t reserved_6: 4;
        uint32_t adc_poweron_only_en: 1;
        uint32_t adc_data_clipping_en: 1;
        const uint32_t reserved_5: 2;
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


/* 0x74
   6:0     R      reserved74_6_0                  7'h0
   7       R/W    reserved_mask                   1'h0
   8       R/W    reserved_mask                   1'h0
   10:9    R      reserved74_10_9                 2'h0
   12:11   R/W    reserved_mask                   2'h0
   28:13   R      reserved74_28_13                16'h0
   29      R/W    reserved_mask                   1'h0
   30      R/W    adc_data_align_msb              1'h0
   31      R/W    reserved_mask                   1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_7: 7;
        uint32_t reserved_6: 1;
        uint32_t reserved_5: 1;
        const uint32_t reserved_4: 2;
        uint32_t reserved_3: 2;
        const uint32_t reserved_2: 16;
        uint32_t reserved_1: 1;
        uint32_t adc_data_align_msb: 1;
        uint32_t reserved_0: 1;
    } b;
} ADC_DATA_CLK_CTRL_TypeDef;


/* 0x78
   13:0    R/W    adc_sample_time_period          14'h270f
   29:14   R      reserved78_29_14                16'h0
   31:30   R/W    adc_convert_time_period_sel     2'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t adc_sample_time_period: 14;
        const uint32_t reserved_0: 16;
        uint32_t adc_convert_time_period_sel: 2;
    } b;
} ADC_TIME_PERIOD_TypeDef;



/* 0x80
   0       R/W    adc_rap_mode                    1'h0
   1       R/WAC  adc_fw_task_one_shot_sample     1'h0
   31:2    R      reserved80_31_2                 30'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t adc_rap_mode: 1;
        uint32_t adc_fw_task_one_shot_sample: 1;
        const uint32_t reserved_0: 30;
    } b;
} ADC_TASK_CTRL_TypeDef;



/* 0x8C
   0       R/W    reserved_mask                   1'h0
   1       R/W    reserved_mask                   1'h0
   2       R/W    reserved_mask                   1'h0
   3       R/W    reserved_mask                   1'h0
   5:4     R/W    reserved_mask                   2'h1
   6       R/W    reserved_mask                   1'h0
   8:7     R/W    reserved_mask                   2'h0
   9       R/W    reserved_mask                   1'h0
   10      R/W    reserved_mask                   1'h0
   11      R/W    reserved_mask                   1'h1
   13:12   R/W    reserved_mask                   2'h1
   21:14   R/W    bypassen                        8'h0
   22      R/W    reserved_mask                   1'h1
   26:23   R/W    reserved_mask                   4'h0
   31:27   R      reserved8c_31_27                5'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reserved_13: 1;
        uint32_t reserved_12: 1;
        uint32_t reserved_11: 1;
        uint32_t reserved_10: 1;
        uint32_t reserved_9: 2;
        uint32_t reserved_8: 1;
        uint32_t reserved_7: 2;
        uint32_t reserved_6: 1;
        uint32_t reserved_5: 1;
        uint32_t reserved_4: 1;
        uint32_t reserved_3: 2;
        uint32_t bypassen: 8;
        uint32_t reserved_2: 1;
        uint32_t reserved_1: 4;
        const uint32_t reserved_0: 5;
    } b;
} REG0X_AUX_TypeDef;



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
 * \defgroup ADC_Constant_Private ADC Constant Private
 * \{
 * \ingroup  ADC_Exported_Constants
 */
#define ADC_MODE_SINGLE_ENDED_VALUE     0x1
#define ADC_MODE_DIFFERENTIAL_VALUE     0x2
#define ADC_MODE_INTERNAL_VALUE         0x3
#define ADC_MODE_RESERVED_VALUE         0x0

#define ADC_MODE_EXTERNAL_CH_NUM(Index)   (Index)
#define ADC_MODE_INTERNAL_VBAT_CH_NUM   0x0
#define ADC_MODE_INTERNAL_VADPIN_CH_NUM   0x1

#define ADCDataWidth                    uint32_t

#define  ADC_DATA_LATCH_DELAY           0x2


/**
 * \defgroup    ADC_Sample_Mode ADC Sample Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_SAMPLE_DIVIDE_SINGLE_MODE = 1,
    ADC_SAMPLE_BYPASS_SINGLE_MODE = 2,
    ADC_SAMPLE_DIVIDE_DIFFERENTIAL_MODE = 3,
    ADC_SAMPLE_BYPASS_DIFFERENTIAL_MODE = 4,
    ADC_SAMPLE_INT_VBAT_MODE = 5,
} ADCSampleMode_TypeDef;

/** End of ADC_Sample_Mode
  * \}
  */

/**
 * \defgroup    ADC_Status ADC Status
 * \{
 * \ingroup     ADC_Exported_Constants
 */
typedef enum
{
    ADC_SUCCESS = 0,
    ADC_ERROR_PARAMETER = -1,
} ADCStatus_TypeDef;

/** End of ADC_Status
  * \}
  */

/** End of ADC_Constant_Private
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
