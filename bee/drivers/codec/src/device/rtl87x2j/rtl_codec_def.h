/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
 *                          CODEC Defines
 *============================================================================*/
/** \defgroup CODEC         CODEC
  * \brief
  * \{
  */

/** \defgroup CODEC_Exported_Constants I2S Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup CODEC_Defines I2S Defines
 * \{
 * \ingroup  CODEC_Exported_Constants
 */
#define CODEC_SUPPORT_INT                (1)
/** End of CODEC_Defines
  * \}
  */

/** End of CODEC_Exported_Constants
  * \}
  */

/** End of CODEC
  * \}
  */

/*============================================================================*
 *                         CODEC Registers Memory Map
 *============================================================================*/
typedef struct                  /*!< CODEC_ANA Structure */
{
    __IO uint32_t REG0X_CODEC_ANA;              /*!< 0x00 */
    __IO uint32_t REG2X_CODEC_ANA;              /*!< 0x04 */
    __IO uint32_t REG4X_CODEC_ANA;              /*!< 0x08 */
    __IO uint32_t REG6X_CODEC_ANA;              /*!< 0x0C */
    __IO uint32_t REG8X_CODEC_ANA;              /*!< 0x10 */
    __IO uint32_t RESERVED_0;                   /*!< 0x14 */
    __IO uint32_t RESERVED_1;                   /*!< 0x18 */
    __IO uint32_t RESERVED_2;                   /*!< 0x1C */
    __IO uint32_t AUDIO_PON_POF;                /*!< 0x20 */
    __IO uint32_t AUDIO_INT_CONTROL;            /*!< 0x24 */
} CODEC_ANA_TypeDef;

typedef struct                  /*!< CODEC Structure */
{
    __IO uint32_t AUDIO_CONTROL_1;              /*!< 0x100 */
    __IO uint32_t AUDIO_ANA_CONTROL_1;          /*!< 0x104 */
    __IO uint32_t AUDIO_CLOCK_CONTROL_1;        /*!< 0x108 */
    __IO uint32_t AUDIO_CLOCK_CONTROL_2;        /*!< 0x10C */
    __IO uint32_t AUDIO_CLOCK_CONTROL_3;        /*!< 0x110 */
    __IO uint32_t RESERVED_0;                   /*!< 0x114 */
    __IO uint32_t RESERVED_1;                   /*!< 0x118 */
    __IO uint32_t I2S_0_CONTROL_0;              /*!< 0x11C */
    __IO uint32_t ADC_0_CONTROL_0;              /*!< 0x120 */
    __IO uint32_t ADC_0_CONTROL_1;              /*!< 0x124 */
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
#define CODEC       ((CODEC_TypeDef     *)(SPI_CODEC_BASE +0x100) )
#define CODEC_ANA   ((CODEC_ANA_TypeDef *)(SPI_CODEC_BASE ))

/*============================================================================*
 *                          CODEC Private Types
 *============================================================================*/

#define CODEC_ADC_CH0_CR_REG_BASE        0x40026200UL
#define CODEC_ADC_CH0_EQ0_REG_BASE       0x40026204UL
#define CODEC_ADC_CH0_EQ1_REG_BASE       0x40026218UL
#define CODEC_ADC_CH0_EQ2_REG_BASE       0x4002622CUL
#define CODEC_ADC_CH0_EQ3_REG_BASE       0x40026240UL
#define CODEC_ADC_CH0_EQ4_REG_BASE       0x40026254UL


#define CODEC_ADC_CH0_CR                 (*((volatile uint32_t *)CODEC_ADC_CH0_CR_REG_BASE))
#define CODEC_ADC_CH0_EQ0                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ0_REG_BASE)
#define CODEC_ADC_CH0_EQ1                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ1_REG_BASE)
#define CODEC_ADC_CH0_EQ2                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ2_REG_BASE)
#define CODEC_ADC_CH0_EQ3                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ3_REG_BASE)
#define CODEC_ADC_CH0_EQ4                ((CODEC_EQTypeDef*) CODEC_ADC_CH0_EQ4_REG_BASE)


/*============================================================================*
 *                          CODEC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   0       R/W    dtsdm_pow               1'b0
   1       R/W    dtsdm_ckxen             1'b1
   7:2     R/W    codec_dummy_vcore       6'h0
   31:8    R      reserved8               24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dtsdm_pow: 1;
        uint32_t dtsdm_ckxen: 1;
        uint32_t codec_dummy_vcore: 6;
        const uint32_t reserved_0: 24;
    } b;
} REG0X_CODEC_ANA_TypeDef;


/* 0x04
   0       R/W    micbst_pow              1'b0
   1       R      reserved1               1'b0
   2       R/W    micbst_endf             1'b1
   3       R      reserved3               1'b0
   4       R/W    micbst_mute             1'b1
   7:5     R      reserved5               3'h0
   10:8    R/W    micbst_gsel             3'b000
   31:11   R      reserved11              21'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t micbst_pow: 1;
        const uint32_t reserved_3: 1;
        uint32_t micbst_endf: 1;
        const uint32_t reserved_2: 1;
        uint32_t micbst_mute: 1;
        const uint32_t reserved_1: 3;
        uint32_t micbst_gsel: 3;
        const uint32_t reserved_0: 21;
    } b;
} REG2X_CODEC_ANA_TypeDef;


/* 0x08
   0       R/W    micbias_pow             1'b0
   1       R/W    micbias_enchx           1'b1
   2       R/W    micbias_extcap          1'b1
   4:3     R      reserved3               2'h0
   7:5     R/W    micbias_vset            3'b011
   9:8     R/W    micbias_count           2'b01
   11:10   R      reserved10              2'h0
   13:12   R/W    micbias_ocsel           2'b01
   14      R/W    micbias_powshdt         1'b0
   15      R/W    micbias_ilimit          1'b0
   31:16   R      reserved16              16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t micbias_pow: 1;
        uint32_t micbias_enchx: 1;
        uint32_t micbias_extcap: 1;
        const uint32_t reserved_2: 2;
        uint32_t micbias_vset: 3;
        uint32_t micbias_count: 2;
        const uint32_t reserved_1: 2;
        uint32_t micbias_ocsel: 2;
        uint32_t micbias_powshdt: 1;
        uint32_t micbias_ilimit: 1;
        const uint32_t reserved_0: 16;
    } b;
} REG4X_CODEC_ANA_TypeDef;


/* 0x0C
   1:0     R/W    isel_micbst             2'b11
   3:2     R/W    isel_dtsdm              2'b11
   7:4     R      reserved4               4'h0
   9:8     R/W    isel_micbias            2'b11
   31:10   R      reserved10              22'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t isel_micbst: 2;
        uint32_t isel_dtsdm: 2;
        const uint32_t reserved_1: 4;
        uint32_t isel_micbias: 2;
        const uint32_t reserved_0: 22;
    } b;
} REG6X_CODEC_ANA_TypeDef;


/* 0x10
   0       R/W    mbias_pow               1'b0
   1       R/W    ldo318_aud_pow          1'b0
   2       R/W    ldo318_aud_ilimit       1'b0
   7:3     R/W    ldo318_aud_tune         5'b01111
   9:8     R/W    ldo318_aud_bw_sel       2'b11
   11:10   R/W    codec_dummy_ldo         2'b00
   12      R/W    vref_bypass             1'b0
   13      R/W    vref_extcap_en          1'b0
   15:14   R/W    vref_sel                2'b10
   31:16   R      reserved16              16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t mbias_pow: 1;
        uint32_t ldo318_aud_pow: 1;
        uint32_t ldo318_aud_ilimit: 1;
        uint32_t ldo318_aud_tune: 5;
        uint32_t ldo318_aud_bw_sel: 2;
        uint32_t codec_dummy_ldo: 2;
        uint32_t vref_bypass: 1;
        uint32_t vref_extcap_en: 1;
        uint32_t vref_sel: 2;
        const uint32_t reserved_0: 16;
    } b;
} REG8X_CODEC_ANA_TypeDef;




/* 0x20
   0       R/W    audio_pon_en            1'b0
   1       R/W    audio_pof_en            1'b0
   3:2     R      reserved2               2'h0
   6:4     R/W    pon_st1_delay_sel       3'h1
   7       R      reserved7               1'h0
   10:8    R/W    pon_st2_delay_sel       3'h1
   11      R      reserved7               1'h0
   14:12   R/W    pon_st3_delay_sel       3'h1
   15      R      reserved7               1'h0
   18:16   R/W    pon_st4_delay_sel       3'h0
   19      R      reserved7               1'h0
   22:20   R/W    pon_st5_delay_sel       3'h1
   23      R      reserved7               1'h0
   26:24   R/W    pof_st1_delay_sel       3'h1
   27      R      reserved7               1'h0
   30:28   R/W    pof_st2_delay_sel       3'h1
   31      R      reserved7               1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t audio_pon_en: 1;
        uint32_t audio_pof_en: 1;
        const uint32_t reserved_7: 2;
        uint32_t pon_st1_delay_sel: 3;
        const uint32_t reserved_6: 1;
        uint32_t pon_st2_delay_sel: 3;
        const uint32_t reserved_5: 1;
        uint32_t pon_st3_delay_sel: 3;
        const uint32_t reserved_4: 1;
        uint32_t pon_st4_delay_sel: 3;
        const uint32_t reserved_3: 1;
        uint32_t pon_st5_delay_sel: 3;
        const uint32_t reserved_2: 1;
        uint32_t pof_st1_delay_sel: 3;
        const uint32_t reserved_1: 1;
        uint32_t pof_st2_delay_sel: 3;
        const uint32_t reserved_0: 1;
    } b;
} AUDIO_PON_POF_TypeDef;

/* 0x24
   0       R/W    audio_pon_ready_int            1'b0
   1       R/W    audio_pof_ready_int            1'b0
   7:2     R      reserved2                      6'h0
   8       R/W    audio_pon_ready_int_en         1'h1
   9       R/W    audio_pof_ready_int_en         1'h1
   15:10   R      reserved10                     6'h0
   16      R/W    audio_pon_ready_int_mask       1'h0
   17      R/W    audio_pof_ready_int_mask       1'h0
   31:18   R/W    reserved18                     14'h0

*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t audio_pon_ready_int: 1;
        uint32_t audio_pof_ready_int: 1;
        const uint32_t reserved_2: 6;
        uint32_t audio_pon_ready_int_en: 1;
        uint32_t audio_pof_ready_int_en: 1;
        const uint32_t reserved_10: 6;
        uint32_t audio_pon_ready_int_mask: 1;
        uint32_t audio_pof_ready_int_mask: 1;
        const uint32_t reserved_18: 14;
    } b;
} AUDIO_INT_CONTROL_TypeDef;


/* 0x100
   0       R/W    audio_ip_en             1'h0
   2:1     R/W    audio_control_dummy1    2'h0
   7:3     R/W    audio_dbg_sel           5'h0
   31:8    R      reserved8               24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t audio_ip_en: 1;
        uint32_t audio_control_dummy1: 2;
        uint32_t audio_dbg_sel: 5;
        const uint32_t reserved_0: 24;
    } b;
} AUDIO_CONTROL_1_TypeDef;


/* 0x104
   2:0     R/W    audio_ana_dummy1        3'h0
   3       R/W    ckx_micbias_en          1'h0
   31:4    R      reserved4               28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t audio_ana_dummy1: 3;
        uint32_t ckx_micbias_en: 1;
        const uint32_t reserved_0: 28;
    } b;
} AUDIO_ANA_CONTROL_1_TypeDef;


/* 0x108
   5:0     R      reserved0               6'h0
   6       R/W    ad_0_en                 1'h0
   9:7     R      reserved7               3'h0
   10      R/W    ad_fifo_en              1'h0
   11      R/W    ad_ana_clk_en           1'h0
   12      R/W    ad_ana_0_en             1'h0
   31:13   R/W    reserved13              19'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_2: 6;
        uint32_t ad_0_en: 1;
        const uint32_t reserved_1: 3;
        uint32_t ad_fifo_en: 1;
        uint32_t ad_ana_clk_en: 1;
        uint32_t ad_ana_0_en: 1;
        uint32_t reserved_0: 19;
    } b;
} AUDIO_CLOCK_CONTROL_1_TypeDef;


/* 0x10C
   2:0     R/W    dmic1_clk_sel           3'h1
   3       R/W    dmic1_clk_en            1'h0
   4       R/W    dmic1_src_clk_sel       1'h0
   31:5    R      reserved5               27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dmic1_clk_sel: 3;
        uint32_t dmic1_clk_en: 1;
        uint32_t dmic1_src_clk_sel: 1;
        const uint32_t reserved_0: 27;
    } b;
} AUDIO_CLOCK_CONTROL_2_TypeDef;


/* 0x110
   3:0     R/W    sample_rate_0           4'h5
   6:4     R      reserved4               3'h0
   8:7     R/W    ana_clk_rate_sel        2'h2
   9       R/W    ad_ana_clk_sel          1'h0
   10      R/W    adc_latch_phase         1'h0
   11      R      reserved11              1'h0
   13:12   R/W    ad_lpf_clk_rate_sel     2'h0
   31:14   R      reserved14              18'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sample_rate_0: 4;
        const uint32_t reserved_2: 3;
        uint32_t ana_clk_rate_sel: 2;
        uint32_t ad_ana_clk_sel: 1;
        uint32_t adc_latch_phase: 1;
        const uint32_t reserved_1: 1;
        uint32_t ad_lpf_clk_rate_sel: 2;
        const uint32_t reserved_0: 18;
    } b;
} AUDIO_CLOCK_CONTROL_3_TypeDef;



/* 0x11C
   0       R/W    i2s_0_rst_n_reg         1'h0
   1       R/W    i2s_0_inv_sclk          1'h0
   2       R/W    i2s_0_self_lpbk_en      1'h0
   7:3     R      reserved3               5'h0
   9:8     R      reserved8               2'h0
   11:10   R/W    i2s_0_data_format_sel_rx2'h0
   13:12   R      reserved12              2'h0
   15:14   R/W    i2s_0_data_len_sel_rx   2'h0
   17:16   R      reserved17              2'h0
   19:18   R/W    i2s_0_data_ch_sel_rx    2'h0
   31:20   R      reserved20              12'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t i2s_0_rst_n_reg: 1;
        uint32_t i2s_0_inv_sclk: 1;
        uint32_t i2s_0_self_lpbk_en: 1;
        const uint32_t reserved_4: 5;
        const uint32_t reserved_3: 2;
        uint32_t i2s_0_data_format_sel_rx: 2;
        const uint32_t reserved_2: 2;
        uint32_t i2s_0_data_len_sel_rx: 2;
        const uint32_t reserved_1: 2;
        uint32_t i2s_0_data_ch_sel_rx: 2;
        const uint32_t reserved_0: 12;
    } b;
} I2S_0_CONTROL_0_TypeDef;


/* 0x120
   1:0     R/W    adc_0_dmic_src_sel      2'h0
   3:2     R/W    adc_0_control_dummy     2'h0
   4       R/W    adc_0_ad_lpf2nd_en      1'h1
   5       R/W    adc_0_ad_lpf1st_en      1'h1
   7:6     R/W    adc_0_ad_lpf1st_fc_sel  2'h0
   9:8     R/W    adc_0_ad_zdet_func      2'h2
   11:10   R/W    adc_0_ad_zdet_tout      2'h1
   12      R/W    adc_0_ad_mute           1'h0
   14:13   R/W    adc_0_boost_gain        2'h0
   15      R/W    adc_0_admic_sel         1'h1
   16      R/W    adc_0_dchpf_en          1'h0
   19:17   R/W    adc_0_dchpf_fc_sel      3'h2
   29:20   R      reserved20              10'h0
   31:30   R/W    adc_0_ad_lpf2nd_fc_sel  2'h1
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t adc_0_dmic_src_sel: 2;
        uint32_t adc_0_control_dummy: 2;
        uint32_t adc_0_ad_lpf2nd_en: 1;
        uint32_t adc_0_ad_lpf1st_en: 1;
        uint32_t adc_0_ad_lpf1st_fc_sel: 2;
        uint32_t adc_0_ad_zdet_func: 2;
        uint32_t adc_0_ad_zdet_tout: 2;
        uint32_t adc_0_ad_mute: 1;
        uint32_t adc_0_boost_gain: 2;
        uint32_t adc_0_admic_sel: 1;
        uint32_t adc_0_dchpf_en: 1;
        uint32_t adc_0_dchpf_fc_sel: 3;
        const uint32_t reserved_0: 10;
        uint32_t adc_0_ad_lpf2nd_fc_sel: 2;
    } b;
} ADC_0_CONTROL_0_TypeDef;


/* 0x124
   6:0     R/W    adc_0_ad_gain           7'h2f
   16:7    R      reserved7               10'h0
   17      R/W    adc_0_depop_en          1'h1
   19:18   R/W    adc_0_depop_time_sel    2'h0
   31:20   R      reserved                12'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t adc_0_ad_gain: 7;
        const uint32_t reserved_1: 10;
        uint32_t adc_0_depop_en: 1;
        uint32_t adc_0_depop_time_sel: 2;
        const uint32_t reserved_0: 12;
    } b;
} ADC_0_CONTROL_1_TypeDef;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_CODEC_DEF_H */

