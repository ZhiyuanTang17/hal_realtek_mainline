/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_codec_def.h
* \brief    CODEC related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_CODEC_DEF_H
#define RTL_CODEC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         CODEC Registers Memory Map
 *============================================================================*/
typedef struct                  /*!< CODEC_ANA Structure */
{
    __IO uint32_t  CODEC_ANA_00_BUS;     /*!< 0x00 */
    __IO uint32_t  CODEC_ANA_01_BUS;     /*!< 0x04 */
    __IO uint32_t  CODEC_ANA_02_BUS;     /*!< 0x08 */
    __IO uint32_t  CODEC_ANA_03_BUS;     /*!< 0x0C */
    __IO uint32_t  CODEC_ANA_04_BUS;     /*!< 0x10 */
    __IO uint32_t  PN_SWAP_CTRL;         /*!< 0x14 */
} CODEC_ANA_TypeDef;

typedef struct                  /*!< CODEC Structure */
{
    __IO uint32_t  AUDIO_CONTROL_0;      /*!< 0x100 */
    __IO uint32_t  AUDIO_CONTROL_1;      /*!< 0x104 */
    __IO uint32_t  CLOCK_CONTROL_1;      /*!< 0x108 */
    __IO uint32_t  RSVD0;                /*!< 0x10C */
    __IO uint32_t  CLOCK_CONTROL_3;      /*!< 0x110 */
    __IO uint32_t  CLOCK_CONTROL_4;      /*!< 0x114 */
    __IO uint32_t  CLOCK_CONTROL_7;      /*!< 0x118 */
    __IO uint32_t  CLOCK_CONTROL_5;      /*!< 0x11C */
    __IO uint32_t  ASRC_CONTROL_0;       /*!< 0x120 */
    __IO uint32_t  RSVD1;                /*!< 0x124 */
    __IO uint32_t  ASRC_CONTROL_RX0;     /*!< 0x128 */
    __IO  uint32_t RSVD2[5];
    __IO uint32_t  FS_CONTROL_1;         /*!< 0x140 */
    __IO uint32_t  FS_CONTROL_3;         /*!< 0x144 */
    __IO uint32_t  I2S_0_CONTROL;        /*!< 0x148 */
    __IO  uint32_t RSVD3[6];
    __IO uint32_t  ADC_0_CONTROL_0;      /*!< 0x164 */
    __IO uint32_t  ADC_0_CONTROL_1;      /*!< 0x168 */
    __IO uint32_t  ADC_1_CONTROL_0;      /*!< 0x16C */
    __IO uint32_t  ADC_1_CONTROL_1;      /*!< 0x170 */
    __IO  uint32_t RSVD4[8];
    __IO uint32_t  DAC_L_CONTROL_0;      /*!< 0x194 */
    __IO uint32_t  DAC_L_CONTROL_1;      /*!< 0x198 */
    __IO uint32_t  DAC_L_CONTROL_2;      /*!< 0x19C */
} CODEC_TypeDef;


typedef struct
{
    __IO uint32_t EQ_H0;                 /*!< 0x40 */
    __IO uint32_t EQ_B1;                 /*!< 0x44 */
    __IO uint32_t EQ_B2;                 /*!< 0x48 */
    __IO uint32_t EQ_A1;                 /*!< 0x4C */
    __IO uint32_t EQ_A2;                 /*!< 0x50 */
} CODEC_EQTypeDef;

/*============================================================================*
 *                          CODEC Declaration
 *============================================================================*/
#define CODEC       ((CODEC_TypeDef     *)0x40022100UL)
#define CODEC_ANA   ((CODEC_ANA_TypeDef *)(SPI_CODEC_REG_BASE ))

/*============================================================================*
 *                          CODEC Private Types
 *============================================================================*/
#define CODEC_DAC_L_CR_REG_BASE          0x40022300UL
#define CODEC_DAC_L_EQ0_REG_BASE         0x40022304UL
#define CODEC_DAC_L_EQ1_REG_BASE         0x40022318UL
#define CODEC_DAC_L_EQ2_REG_BASE         0x4002232CUL
#define CODEC_DAC_L_EQ3_REG_BASE         0x40022340UL
#define CODEC_DAC_L_EQ4_REG_BASE         0x40022354UL
#define CODEC_DAC_L_EQ5_REG_BASE         0x40022368UL
#define CODEC_DAC_L_EQ6_REG_BASE         0x4002237CUL
#define CODEC_DAC_L_EQ7_REG_BASE         0x40022390UL
#define CODEC_DAC_L_EQ8_REG_BASE         0x400223A4UL
#define CODEC_DAC_L_EQ9_REG_BASE         0x400223B8UL

#define CODEC_ADC_CH0_CR_REG_BASE        0x40022500UL
#define CODEC_ADC_CH0_EQ0_REG_BASE       0x40022504UL
#define CODEC_ADC_CH0_EQ1_REG_BASE       0x40022518UL
#define CODEC_ADC_CH0_EQ2_REG_BASE       0x4002252CUL
#define CODEC_ADC_CH0_EQ3_REG_BASE       0x40022540UL
#define CODEC_ADC_CH0_EQ4_REG_BASE       0x40022554UL

#define CODEC_ADC_CH1_CR_REG_BASE        0x40022568UL
#define CODEC_ADC_CH1_EQ0_REG_BASE       0x4002256CUL
#define CODEC_ADC_CH1_EQ1_REG_BASE       0x40022580UL
#define CODEC_ADC_CH1_EQ2_REG_BASE       0x40022594UL
#define CODEC_ADC_CH1_EQ3_REG_BASE       0x400225A8UL
#define CODEC_ADC_CH1_EQ4_REG_BASE       0x400225BCUL

#define CODEC_DAC_L_CR                   (*((volatile uint32_t *)CODEC_DAC_L_CR_REG_BASE))
#define CODEC_DAC_L_EQ0                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ0_REG_BASE)
#define CODEC_DAC_L_EQ1                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ1_REG_BASE)
#define CODEC_DAC_L_EQ2                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ2_REG_BASE)
#define CODEC_DAC_L_EQ3                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ3_REG_BASE)
#define CODEC_DAC_L_EQ4                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ4_REG_BASE)
#define CODEC_DAC_L_EQ5                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ5_REG_BASE)
#define CODEC_DAC_L_EQ6                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ6_REG_BASE)
#define CODEC_DAC_L_EQ7                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ7_REG_BASE)
#define CODEC_DAC_L_EQ8                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ8_REG_BASE)
#define CODEC_DAC_L_EQ9                  ((CODEC_EQTypeDef*) CODEC_DAC_L_EQ9_REG_BASE)

#define CODEC_ADC_CH0_CR                 (*((volatile uint32_t *)CODEC_ADC_CH0_CR_REG_BASE))
#define CODEC_ADC_CH0_EQ0                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ0_REG_BASE)
#define CODEC_ADC_CH0_EQ1                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ1_REG_BASE)
#define CODEC_ADC_CH0_EQ2                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ2_REG_BASE)
#define CODEC_ADC_CH0_EQ3                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ3_REG_BASE)
#define CODEC_ADC_CH0_EQ4                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ4_REG_BASE)

#define CODEC_ADC_CH1_CR                 (*((volatile uint32_t *)CODEC_ADC_CH1_CR_REG_BASE))
#define CODEC_ADC_CH1_EQ0                ((CODEC_EQTypeDef*) CODEC_ADC_CH1_EQ0_REG_BASE)
#define CODEC_ADC_CH1_EQ1                ((CODEC_EQTypeDef*) CODEC_ADC_CH1_EQ1_REG_BASE)
#define CODEC_ADC_CH1_EQ2                ((CODEC_EQTypeDef*) CODEC_ADC_CH1_EQ2_REG_BASE)
#define CODEC_ADC_CH1_EQ3                ((CODEC_EQTypeDef*) CODEC_ADC_CH1_EQ3_REG_BASE)
#define CODEC_ADC_CH1_EQ4                ((CODEC_EQTypeDef*) CODEC_ADC_CH1_EQ4_REG_BASE)


/*============================================================================*
 *                          CODEC Registers and Field Descriptions
 *============================================================================*/
//=== start of page0 0x00 ===
/* 0x00
    0       R/W    DAC_ADDACK_POW          1'h0
    7:1     R/W    codec_ana_dummy         7'h0
    8       R      RSVD                    1'h0
    9       R/W    DTSDM_CKXEN             1'h1
    10      R/W    DTSDM_POW_L             1'h0
    31:11   R      RSVD                    21'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t DAC_ADDACK_POW: 1;
        uint32_t codec_ana_dummy: 7;
        const uint32_t reserved_1: 1;
            uint32_t DTSDM_CKXEN: 1;
            uint32_t DTSDM_POW_L: 1;
            const uint32_t reserved_0: 21;
        } b;
    } CODEC_ANA_00_BUS_t;



    /* 0x04
        8:0     R/W    codec_ana_01_bus_rsvd   9'h0
        9       R/W    MICBIAS_ENCHX           1'h1
        10      R/W    MICBIAS_POW             1'h0
        13:11   R/W    MICBIAS_VSET            3'h3
        14      R/W    MICBST_ENDFL            1'h0
        15      R/W    VREF_POW                1'h0
        17:16   R/W    MICBST_GSELL            2'h0
        19:18   R      RSVD                    2'h0
        21:20   R/W    MICBST_MUTE_L           2'h2
        24:22   R      RSVD                    3'h0
        25      R/W    MICBST_POW              1'h0
        27:26   R/W    VREF_VREFSEL            2'h2
        31:28   R      RSVD                    4'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t codec_ana_01_bus_rsvd: 9;
                uint32_t MICBIAS_ENCHX: 1;
                uint32_t MICBIAS_POW: 1;
                uint32_t MICBIAS_VSET: 3;
                uint32_t MICBST_ENDFL: 1;
                uint32_t VREF_POW: 1;
                uint32_t MICBST_GSELL: 2;
                const uint32_t reserved_2: 2;
                uint32_t MICBST_MUTE_L: 2;
                const uint32_t reserved_1: 3;
                uint32_t MICBST_POW: 1;
                uint32_t VREF_VREFSEL: 2;
                const uint32_t reserved_0: 4;
            } b;
        } CODEC_ANA_01_BUS_t;



    /* 0x08
        7:0     R/W    codec_ana_02_bus_rsvd   8'h0
        11:8    R/W    MICBIAS_COUNT           4'h1
        13:12   R/W    MICBIAS_OCSEL           2'h1
        14      R/W    MICBIAS_POWSHDT         1'h0
        15      R/W    MICBIAS_ILIMIT          1'h0
        31:16   R      RSVD                    16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t codec_ana_02_bus_rsvd: 8;
                uint32_t MICBIAS_COUNT: 4;
                uint32_t MICBIAS_OCSEL: 2;
                uint32_t MICBIAS_POWSHDT: 1;
                uint32_t MICBIAS_ILIMIT: 1;
                const uint32_t reserved_0: 16;
            } b;
        } CODEC_ANA_02_BUS_t;



    /* 0x0C
        0       R/W    CODEC_DAC_POW           1'h0
        1       R/W    CODEC_DAC_CK_POW        1'h0
        2       R/W    CODEC_DAC_CKXEN         1'h4
        3       R/W    CODEC_DAC_CKXSEL        1'h4
        4       R/W    CODEC_DAC_OFFSETP_EN    1'h0
        5       R/W    CODEC_DAC_OFFSETN_EN    1'h0
        31:6    R      RSVD                    26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t CODEC_DAC_POW: 1;
                uint32_t CODEC_DAC_CK_POW: 1;
                uint32_t CODEC_DAC_CKXEN: 1;
                uint32_t CODEC_DAC_CKXSEL: 1;
                uint32_t CODEC_DAC_OFFSETP_EN: 1;
                uint32_t CODEC_DAC_OFFSETN_EN: 1;
                const uint32_t reserved_0: 26;
            } b;
        } CODEC_ANA_03_BUS_t;



    /* 0x10
        31:0    R/W    codec_RSVD              32'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t codec_RSVD: 32;
            } b;
        } CODEC_ANA_04_BUS_t;



    /* 0x14
        0       R/W    dac_l_sdm_inv           1'h0
        3:1     R      RSVD                    3'h0
        4       R/W    adc_1_3b_inv            1'h0
        5       R/W    adc_2_3b_inv            1'h0
        6       R/W    adc_3_3b_inv            1'h0
        7       R/W    adc_4_3b_inv            1'h0
        31:8    R      RSVD                    24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dac_l_sdm_inv: 1;
                const uint32_t reserved_1: 3;
                uint32_t adc_1_3b_inv: 1;
                uint32_t adc_2_3b_inv: 1;
                uint32_t adc_3_3b_inv: 1;
                uint32_t adc_4_3b_inv: 1;
                const uint32_t reserved_0: 24;
            } b;
        } PN_SWAP_CTRL_t;
//--- end of page 0x00 ---

//=== start of page 0x01 ===
    /* 0x100
        0       R/W    audio_ip_en                 1'h0
        1       R/W    daad_lpbk_en                1'h0
        2       R/W    adda_lpbk_en                1'h0
        3       R/W    ext_adda_en                 1'h0
        18:4    R      RSVD                        15'h0
        23:19   R/W    audio_dbg_sel               5'h0
        31:24   R      RSVD                        8'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t audio_ip_en: 1;
                uint32_t daad_lpbk_en: 1;
                uint32_t adda_lpbk_en: 1;
                uint32_t ext_adda_en: 1;
                const uint32_t reserved_1: 15;
                uint32_t audio_dbg_sel: 5;
                const uint32_t reserved_0: 8;
            } b;
        } AUDIO_CONTROL_0_t;



    /* 0x104
        1:0     R/W    sel_bb_ck_depop             2'h1
        2       R/W    bb_ck_depop_en              1'h0
        3       R/W    ckx_micbias_en              1'h0
        4       R      RSVD                        1'h0
        5       R/W    pdm_clk_double              1'h0
        7:6     R/W    pdm_clk_sel                 2'h0
        9:8     R/W    pdm_ch_swap                 2'h2
        10      R/W    pdm_data_phase_sel          1'h1
        11      R/W    pdm_gain_shift_en           1'h1
        12      R/W    pdm_clk_inv_sel             1'h1
        13      R/W    i2s_data_rnd_en             1'h1
        31:14   R      RSVD                        18'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t sel_bb_ck_depop: 2;
                uint32_t bb_ck_depop_en: 1;
                uint32_t ckx_micbias_en: 1;
                const uint32_t reserved_1: 1;
                uint32_t pdm_clk_double: 1;
                uint32_t pdm_clk_sel: 2;
                uint32_t pdm_ch_swap: 2;
                uint32_t pdm_data_phase_sel: 1;
                uint32_t pdm_gain_shift_en: 1;
                uint32_t pdm_clk_inv_sel: 1;
                uint32_t i2s_data_rnd_en: 1;
                const uint32_t reserved_0: 18;
            } b;
        } AUDIO_CONTROL_1_t;



    /* 0x108
        0       R/W    da_l_en                     1'h0
        1       R      RSVD                        1'h0
        2       R/W    mod_l_en                    1'h0
        3       R      RSVD                        1'h0
        4       R/W    da_ana_clk_en               1'h0
        5       R/W    da_fifo_en                  1'h0
        6       R/W    ad_0_en                     1'h0
        7       R/W    ad_1_en                     1'h0
        9:8     R      RSVD                        2'h0
        10      R/W    ad_fifo_en                  1'h0
        11      R/W    ad_ana_clk_en               1'h0
        12      R/W    ad_ana_0_en                 1'h0
        13      R/W    ad_ana_1_en                 1'h0
        15:14   R      RSVD                        2'h0
        16      R/W    ad_0_eq_en                  1'h0
        17      R/W    ad_1_eq_en                  1'h0
        19:18   R      RSVD                        2'h0
        20      R/W    da_l_eq_en                  1'h0
        31:21   R      RSVD                        11'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t da_l_en: 1;
                const uint32_t reserved_5: 1;
                uint32_t mod_l_en: 1;
                const uint32_t reserved_4: 1;
                uint32_t da_ana_clk_en: 1;
                uint32_t da_fifo_en: 1;
                uint32_t ad_0_en: 1;
                uint32_t ad_1_en: 1;
                const uint32_t reserved_3: 2;
                uint32_t ad_fifo_en: 1;
                uint32_t ad_ana_clk_en: 1;
                uint32_t ad_ana_0_en: 1;
                uint32_t ad_ana_1_en: 1;
                const uint32_t reserved_2: 2;
                uint32_t ad_0_eq_en: 1;
                uint32_t ad_1_eq_en: 1;
                const uint32_t reserved_1: 2;
                uint32_t da_l_eq_en: 1;
                const uint32_t reserved_0: 11;
            } b;
        } CLOCK_CONTROL_1_t;

// uint32_t RSVD_0X10C[1];



    /* 0x110
        2:0     R/W    dmic1_clk_sel               3'h1
        3       R/W    dmic1_clk_en                1'h0
        4       R/W    dmic1_src_clk_sel           1'h0
        31:5    R      RSVD                        27'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dmic1_clk_sel: 3;
                uint32_t dmic1_clk_en: 1;
                uint32_t dmic1_src_clk_sel: 1;
                const uint32_t reserved_0: 27;
            } b;
        } CLOCK_CONTROL_3_t;



    /* 0x114
        3:0     R/W    sample_rate_0               4'h0
        7:4     R/W    sample_rate_1               4'h0
        31:8    R      RSVD                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t sample_rate_0: 4;
                uint32_t sample_rate_1: 4;
                const uint32_t reserved_0: 24;
            } b;
        } CLOCK_CONTROL_4_t;



    /* 0x118
        0       R/W    dac_fs_src_sel              1'h0
        3:1     R      RSVD                        3'h0
        4       R/W    adc_fs_src_sel              1'h0
        31:5    R      RSVD                        27'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dac_fs_src_sel: 1;
                const uint32_t reserved_1: 3;
                uint32_t adc_fs_src_sel: 1;
                const uint32_t reserved_0: 27;
            } b;
        } CLOCK_CONTROL_7_t;



    /* 0x11C
        0       R/W    ad_asrc_en                  1'h0
        5:1     R      RSVD                        5'h0
        6       R/W    da_asrc_en                  1'h0
        8:7     R      RSVD                        2'h0
        9       R/W    da_ana_clk_sel              1'h0
        10      R/W    ad_ana_clk_sel              1'h0
        11      R/W    adc_latch_phase             1'h0
        15:12   R      RSVD                        4'h0
        16      R/W    ana_clk_rate_sel            1'h0
        17      R      RSVD                        1'h0
        19:18   R/W    ad_lpf_clk_sel              2'h0
        31:20   R      RSVD                        12'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ad_asrc_en: 1;
                const uint32_t reserved_4: 5;
                uint32_t da_asrc_en: 1;
                const uint32_t reserved_3: 2;
                uint32_t da_ana_clk_sel: 1;
                uint32_t ad_ana_clk_sel: 1;
                uint32_t adc_latch_phase: 1;
                const uint32_t reserved_2: 4;
                uint32_t ana_clk_rate_sel: 1;
                const uint32_t reserved_1: 1;
                uint32_t ad_lpf_clk_sel: 2;
                const uint32_t reserved_0: 12;
            } b;
        } CLOCK_CONTROL_5_t;



    /* 0x120
        0       R/W    asrc_rate_sel_tx            1'h0
        1       R      RSVD                        1'h0
        3:2     R/W    asrc_gain_sel_tx            2'h3
        4       R/W    asrc_auto_adjust_tx         1'h1
        7:5     R      RSVD                        3'h0
        31:8    R/W    asrc_sdm_inti_tx            24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t asrc_rate_sel_tx: 1;
                const uint32_t reserved_1: 1;
                uint32_t asrc_gain_sel_tx: 2;
                uint32_t asrc_auto_adjust_tx: 1;
                const uint32_t reserved_0: 3;
                uint32_t asrc_sdm_inti_tx: 24;
            } b;
        } ASRC_CONTROL_0_t;


    /* 0x128
        0       R/W    asrc_rate_sel_rx            1'h0
        1       R      RSVD                        1'h0
        3:2     R/W    asrc_gain_sel_rx            2'h3
        4       R/W    asrc_auto_adjust_rx         1'h1
        7:5     R      RSVD                        3'h0
        31:8    R/W    asrc_sdm_inti_rx            24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t asrc_rate_sel_rx: 1;
                const uint32_t reserved_1: 1;
                uint32_t asrc_gain_sel_rx: 2;
                uint32_t asrc_auto_adjust_rx: 1;
                const uint32_t reserved_0: 3;
                uint32_t asrc_sdm_inti_rx: 24;
            } b;
        } ASRC_CONTROL_RX0_t;

// uint32_t RSVD_0X12C[5];



    /* 0x140
        14:0    R/W    fs_frac_n_part              15'h13f
        15      R      RSVD                        1'h0
        31:16   R/W    fs_frac_m_part              16'h271
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t fs_frac_n_part: 15;
                const uint32_t reserved_0: 1;
                uint32_t fs_frac_m_part: 16;
            } b;
        } FS_CONTROL_1_t;



    /* 0x144
        23:0    R/W    fs_integ_part               24'h1d4951
        24      R/W    fs_update                   1'h0
        25      R/W    fs_i2s_sync_mode            1'h0
        27:26   R      RSVD                        2'h0
        28      R/W    dual_rate_mode              1'h0
        29      R/W    qual_rate_mode              1'h0
        31:30   R      RSVD                        2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t fs_integ_part: 24;
                uint32_t fs_update: 1;
                uint32_t fs_i2s_sync_mode: 1;
                const uint32_t reserved_1: 2;
                uint32_t dual_rate_mode: 1;
                uint32_t qual_rate_mode: 1;
                const uint32_t reserved_0: 2;
            } b;
        } FS_CONTROL_3_t;



    /* 0x148
        0       R/W    i2s_0_rst_n                 1'h0
        1       R/W    i2s_0_inv_sclk              1'h0
        2       R/W    i2s_0_self_lpbk_en          1'h0
        3       R/W    i2s_0_same_lrc_en           1'h0
        5:4     R      RSVD                        2'h0
        7:6     R/W    i2s_0_data_format_sel_tx    2'h0
        9:8     R/W    i2s_0_data_format_sel_rx    2'h0
        11:10   R/W    i2s_0_data_len_sel_tx       2'h0
        13:12   R/W    i2s_0_data_len_sel_rx       2'h0
        15:14   R/W    i2s_0_ch_len_sel_tx         2'h1
        17:16   R/W    i2s_0_ch_len_sel_rx         2'h1
        19:18   R/W    i2s_0_data_ch_sel_tx        2'h0
        21:20   R/W    i2s_0_data_ch_sel_rx        2'h0
        31:22   R      RSVD                        10'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t i2s_0_rst_n: 1;
                uint32_t i2s_0_inv_sclk: 1;
                uint32_t i2s_0_self_lpbk_en: 1;
                uint32_t i2s_0_same_lrc_en: 1;
                const uint32_t reserved_1: 2;
                uint32_t i2s_0_data_format_sel_tx: 2;
                uint32_t i2s_0_data_format_sel_rx: 2;
                uint32_t i2s_0_data_len_sel_tx: 2;
                uint32_t i2s_0_data_len_sel_rx: 2;
                uint32_t i2s_0_ch_len_sel_tx: 2;
                uint32_t i2s_0_ch_len_sel_rx: 2;
                uint32_t i2s_0_data_ch_sel_tx: 2;
                uint32_t i2s_0_data_ch_sel_rx: 2;
                const uint32_t reserved_0: 10;
            } b;
        } I2S_0_CONTROL_t;

// uint32_t RSVD_0X14C[6];



    /* 0x164
        1:0     R/W    adc_0_dmic_src_sel          2'h0
        7:2     R      RSVD                        6'h0
        9:8     R/W    adc_0_ad_src_sel            2'h0
        10      R      RSVD                        1'h0
        11      R/W    adc_0_ad_lpf2nd_en          1'h1
        12      R/W    adc_0_ad_lpf1st_en          1'h1
        14:13   R/W    adc_0_ad_lpf1st_fc_sel      2'h0
        15      R/W    adc_0_admic_sel             1'h1
        17:16   R/W    adc_0_ad_zdet_func          2'h2
        19:18   R/W    adc_0_ad_zdet_tout          2'h0
        20      R/W    adc_0_ad_mute               1'h0
        23:21   R      RSVD                        3'h0
        24      R/W    adc_0_dchpf_en              1'h0
        27:25   R/W    adc_0_dchpf_fc_sel          3'h4
        29:28   R/W    adc_0_dmic_lpf2nd_fc_sel    2'h1
        31:30   R/W    adc_0_ad_lpf2nd_fc_sel      2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_0_dmic_src_sel: 2;
                const uint32_t reserved_2: 6;
                uint32_t adc_0_ad_src_sel: 2;
                const uint32_t reserved_1: 1;
                uint32_t adc_0_ad_lpf2nd_en: 1;
                uint32_t adc_0_ad_lpf1st_en: 1;
                uint32_t adc_0_ad_lpf1st_fc_sel: 2;
                uint32_t adc_0_admic_sel: 1;
                uint32_t adc_0_ad_zdet_func: 2;
                uint32_t adc_0_ad_zdet_tout: 2;
                uint32_t adc_0_ad_mute: 1;
                const uint32_t reserved_0: 3;
                uint32_t adc_0_dchpf_en: 1;
                uint32_t adc_0_dchpf_fc_sel: 3;
                uint32_t adc_0_dmic_lpf2nd_fc_sel: 2;
                uint32_t adc_0_ad_lpf2nd_fc_sel: 2;
            } b;
        } ADC_0_CONTROL_0_t;



    /* 0x168
        8:0     R/W    adc_0_ad_gain               9'h2f
        11:9    R/W    adc_0_rsvd                  3'h0
        16:12   R      RSVD                        5'h0
        17      R/W    adc_0_depop_en              1'h0
        19:18   R/W    adc_0_depop_time_sel        2'h0
        31:20   R      RSVD                        12'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_0_ad_gain: 9;
                uint32_t adc_0_rsvd: 3;
                const uint32_t reserved_1: 5;
                uint32_t adc_0_depop_en: 1;
                uint32_t adc_0_depop_time_sel: 2;
                const uint32_t reserved_0: 12;
            } b;
        } ADC_0_CONTROL_1_t;



    /* 0x16C
        1:0     R/W    adc_1_dmic_src_sel          2'h0
        7:2     R      RSVD                        6'h0
        9:8     R/W    adc_1_ad_src_sel            2'h0
        10      R      RSVD                        1'h0
        11      R/W    adc_1_ad_lpf2nd_en          1'h1
        12      R/W    adc_1_ad_lpf1st_en          1'h1
        14:13   R/W    adc_1_ad_lpf1st_fc_sel      2'h0
        15      R/W    adc_1_admic_sel             1'h1
        17:16   R/W    adc_1_ad_zdet_func          2'h2
        19:18   R/W    adc_1_ad_zdet_tout          2'h0
        20      R/W    adc_1_ad_mute               1'h0
        23:21   R      RSVD                        3'h0
        24      R/W    adc_1_dchpf_en              1'h0
        27:25   R/W    adc_1_dchpf_fc_sel          3'h4
        29:28   R/W    adc_1_dmic_lpf2nd_fc_sel    2'h1
        31:30   R/W    adc_1_ad_lpf2nd_fc_sel      2'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_1_dmic_src_sel: 2;
                const uint32_t reserved_2: 6;
                uint32_t adc_1_ad_src_sel: 2;
                const uint32_t reserved_1: 1;
                uint32_t adc_1_ad_lpf2nd_en: 1;
                uint32_t adc_1_ad_lpf1st_en: 1;
                uint32_t adc_1_ad_lpf1st_fc_sel: 2;
                uint32_t adc_1_admic_sel: 1;
                uint32_t adc_1_ad_zdet_func: 2;
                uint32_t adc_1_ad_zdet_tout: 2;
                uint32_t adc_1_ad_mute: 1;
                const uint32_t reserved_0: 3;
                uint32_t adc_1_dchpf_en: 1;
                uint32_t adc_1_dchpf_fc_sel: 3;
                uint32_t adc_1_dmic_lpf2nd_fc_sel: 2;
                uint32_t adc_1_ad_lpf2nd_fc_sel: 2;
            } b;
        } ADC_1_CONTROL_0_t;



    /* 0x170
        8:0     R/W    adc_1_ad_gain               9'h2f
        11:9    R/W    adc_1_rsvd                  3'h0
        16:12   R      RSVD                        5'h0
        17      R/W    adc_1_depop_en              1'h0
        19:18   R/W    adc_1_depop_time_sel        2'h0
        31:20   R      RSVD                        12'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t adc_1_ad_gain: 9;
                uint32_t adc_1_rsvd: 3;
                const uint32_t reserved_1: 5;
                uint32_t adc_1_depop_en: 1;
                uint32_t adc_1_depop_time_sel: 2;
                const uint32_t reserved_0: 12;
            } b;
        } ADC_1_CONTROL_1_t;

// uint32_t RSVD_0X174[8];



    /* 0x194
        7:0     R/W    dac_l_da_gain               8'haf
        31:8    R      RSVD                        24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dac_l_da_gain: 8;
                const uint32_t reserved_0: 24;
            } b;
        } DAC_L_CONTROL_0_t;



    /* 0x198
        1:0     R/W    dac_l_da_zdet_func          2'h2
        3:2     R/W    dac_l_da_zdet_tout          2'h0
        4       R/W    dac_l_da_mute               1'h0
        5       R/W    dac_l_dahpf_en              1'h0
        7:6     R/W    dac_l_da_dither_sel         2'h0
        8       R/W    dac_l_dmix_mute_da          1'h0
        9       R      RSVD                        1'h0
        10      R/W    dac_l_dmix_mute_dc          1'h1
        12:11   R      RSVD                        2'h0
        13      R/W    dac_l_pdm_en                1'h0
        15:14   R      RSVD                        2'h0
        17:16   R/W    dac_l_sdm_dither_sel        2'h0
        21:18   R      RSVD                        4'h0
        23:22   R/W    dac_l_hpf_fc_sel            2'h1
        31:24   R      RSVD                        8'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dac_l_da_zdet_func: 2;
                uint32_t dac_l_da_zdet_tout: 2;
                uint32_t dac_l_da_mute: 1;
                uint32_t dac_l_dahpf_en: 1;
                uint32_t dac_l_da_dither_sel: 2;
                uint32_t dac_l_dmix_mute_da: 1;
                const uint32_t reserved_4: 1;
                uint32_t dac_l_dmix_mute_dc: 1;
                const uint32_t reserved_3: 2;
                uint32_t dac_l_pdm_en: 1;
                const uint32_t reserved_2: 2;
                uint32_t dac_l_sdm_dither_sel: 2;
                const uint32_t reserved_1: 4;
                uint32_t dac_l_hpf_fc_sel: 2;
                const uint32_t reserved_0: 8;
            } b;
        } DAC_L_CONTROL_1_t;



    /* 0x19C
        15:0    R/W    dac_l_dc_offset             16'h0
        31:16   R      RSVD                        16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dac_l_dc_offset: 16;
                const uint32_t reserved_0: 16;
            } b;
        } DAC_L_CONTROL_2_t;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_CODEC_DEF_H */

