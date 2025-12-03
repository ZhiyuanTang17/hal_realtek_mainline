/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_i2s_def.h
* \brief    I2S related definitions for RTL8762G
* \details
* \author   echo
* \date     2024-04-01
* \version  v1.2
* *********************************************************************************************************
*/

#ifndef RTL_I2S_DEF_H
#define RTL_I2S_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/*============================================================================*
 *                          I2S Defines
 *============================================================================*/
/** \defgroup I2S         I2S
  * \brief
  * \{
  */

/** \defgroup I2S_Exported_Constants I2S Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup I2S_Defines I2S Defines
 * \{
 * \ingroup  I2S_Exported_Constants
 */

#define I2S_SUPPORT_TRX_INDEPENDENT_CONTROL (1)
#define I2S_SUPPORT_TRX_FIFO                (1)
#define I2S_SUPPORT_INT_TX_VALID            (1)
#define I2S_SUPPORT_PLL_CLK                 (1)
#define I2S_SUPPORT_DATE_WIDTH_32BIT        (1)
#define I2S_SUPPORT_MCLK_OUTPUT_SEL         (0)

/** End of I2S_Defines
  * \}
  */

/** End of I2S_Exported_Constants
  * \}
  */

/** End of I2S
  * \}
  */
/*============================================================================*
 *                          APB_I2S Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t I2S_TX_FIFO_WR_ADDR;          /*!< 0x00 */
    __IO uint32_t I2S_CTRL;                     /*!< 0x04 */
    __IO uint32_t I2S_FIFO_EN_CLK_CON;          /*!< 0x08 */
    __IO uint32_t I2S_INTR_CON;                 /*!< 0x0C */
    __IO uint32_t I2S_RX_FIFO_RD_ADDR;          /*!< 0x10 */
    __IO uint32_t I2S_FIFO_CNT_STA;             /*!< 0x14 */
    __IO uint32_t I2S_TX_RX_ERR_STA;            /*!< 0x18 */
    __IO uint32_t I2S_TX_FRA_DIV;               /*!< 0x1C */
    __IO uint32_t I2S_LRCK_FIFO_TH_CON;         /*!< 0x20 */
    __IO uint32_t I2S_FIFO_STA;                 /*!< 0x24 */
    __IO uint32_t I2S_FORM_CON;                 /*!< 0x28 */
    __IO uint32_t I2S_RX_FRA_DIV;               /*!< 0x2C */
    __IO uint32_t I2S_TX_CNT_CTRL;              /*!< 0x30 */
    __IO uint32_t I2S_TX_CNT_VAL;               /*!< 0x34 */
    __IO uint32_t I2S_TX_CH_DATA_MIX;           /*!< 0x38 */
    __IO uint32_t I2S_TX_CH_DATA_SEL;           /*!< 0x3C */
    __IO uint32_t RSVD_0;                       /**< 0x40 */
    __IO uint32_t RSVD_1;                       /**< 0x44 */
    __IO uint32_t RSVD_2;                       /**< 0x48 */
    __IO uint32_t RSVD_3;                       /**< 0x4C */
    __IO uint32_t RSVD_4;                       /**< 0x50 */
    __IO uint32_t I2S_I2S_RX_FIFO_REG0;         /*!< 0x54 */
    __IO uint32_t RSVD_5;                       /**< 0x58 */
    __IO uint32_t I2S_RX_CNT_CTRL;              /*!< 0x5C */
    __IO uint32_t I2S_RX_CNT_VAL;               /*!< 0x60 */
    __IO uint32_t I2S_TX_VAL_CNT;               /*!< 0x64 */
    __IO uint32_t I2S_FIFO_CNT_LATCH;           /*!< 0x68 */
} I2S_TypeDef;

/*============================================================================*
 *                          I2S Declaration
 *============================================================================*/
#define I2S0                ((I2S_TypeDef *) I2S0_REG_BASE)
#define I2S1                ((I2S_TypeDef *) I2S1_REG_BASE)

#define IS_I2S_PERIPH(PERIPH)     (((PERIPH) == I2S0) || \
                                   ((PERIPH) == I2S1))
///*============================================================================*
// *                         I2S Private Types
// *============================================================================*/
//#define PERIPH_REG_BASE     0x40002000UL

/*============================================================================*
 *                         I2S Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    W      TX_FIFO_WR_ADDR             32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t TX_FIFO_WR_ADDR: 32;
    } b;
} I2S_TX_FIFO_WR_ADDR_TypeDef;

/* 0x04
   0       R/W    sp_reset                    1'b0
   1       R/W    tx_inv_i2s_sclk             1'b0
   2       R/W    rx_inv_i2s_sclk             1'b0
   3       R/W    slave_clk_sel               1'b0
   4       R/W    slave_data_sel              1'b0
   5       R/W    sp_wclk_tx_inverse          1'h0
   6       R/W   sp_loopback                 1'b0
   7       R/W    dsp_ctl_mode                1'b0
   9:8     R/W    sp_data_format_sel_tx       2'b00
   10      R/W    sp_inv_i2s_sclk             1'b0
   11      R/W    sp_en_i2s_mono_tx           1'b0
   14:12   R/W    sp_data_len_sel_tx          3'b00
   15      R/W    sp_i2s_self_lpbk_en         1'b0
   16      R/W    sp_tx_disable               1'b1
   17      R/W    sp_start_tx                 1'b0
   19:18   R/W    reserved15                  2'b00
   21:20   R/W    reserved14                  2'b00
   22      R/W    tx_lsb_first                1'b0
   23      R/W    rx_lsb_first                1'b0
   24      R/W    sp_rx_disable               1'b1
   25      R/W    sp_start_rx                 1'b0
   27:26   R/W    sp_sel_i2s_tx_ch            2'b00
   29:28   R/W    sp_sel_i2s_rx_ch            2'b00
   30      R/W    mclk_sel                    1'b0
   31      R/W    reserved6                   1'b1
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sp_reset: 1;
        uint32_t tx_inv_i2s_sclk: 1;
        uint32_t rx_inv_i2s_sclk: 1;
        uint32_t slave_clk_sel: 1;
        uint32_t slave_data_sel: 1;
        uint32_t sp_wclk_tx_inverse: 1;
        uint32_t sp_loopback: 1;
        uint32_t dsp_ctl_mode: 1;
        uint32_t sp_data_format_sel_tx: 2;
        uint32_t sp_inv_i2s_sclk: 1;
        uint32_t sp_en_i2s_mono_tx: 1;
        uint32_t sp_data_len_sel_tx: 3;
        uint32_t sp_i2s_self_lpbk_en: 1;
        uint32_t sp_tx_disable: 1;
        uint32_t sp_start_tx: 1;
        uint32_t reserved_2: 2;
        uint32_t reserved_1: 2;
        uint32_t tx_lsb_first: 1;
        uint32_t rx_lsb_first: 1;
        uint32_t sp_rx_disable: 1;
        uint32_t sp_start_rx: 1;
        uint32_t sp_sel_i2s_tx_ch: 2;
        uint32_t sp_sel_i2s_rx_ch: 2;
        uint32_t mclk_sel: 1;
        uint32_t reserved_0: 1;
    } b;
} I2S_CTRL_TypeDef;

/* 0x08
   4:0     R/W    reserved51                  5'h0
   5       R/W    bclk_reset                  1'b0
   7:6     R/W    reserved49                  2'b0
   10:8    R/W    debug_bus_sel               3'h0
   11      R/W    enable_mclk                 1'b0
   12      R/W    clear_tx_err_cnt            1'b0
   13      R/W    clear_rx_err_cnt            1'b0
   15:14   R/W    i2s_clk_sel                 2'h0
   16      R/W    err_cnt_sat_set             1'b0
   19:17   R/W    reserved42                  3'h0
   20      R/W    tx_src_byte_swap            1'b0
   21      R/W    tx_src_lr_swap              1'b0
   22      R/W    rx_snk_byte_swap            1'b0
   23      R/W    rx_snk_lr_swap              1'b0
   24      R/W    tx_fifo_0_reg_0_en          1'b1
   25      R/W    tx_fifo_0_reg_1_en          1'b0
   27:26   R/W    reserved35                  2'h0
   28      R/W    rx_fifo_0_reg_0_en          1'b1
   29      R/W    rx_fifo_0_reg_1_en          1'b0
   31:30   R/W    reserved32                  2'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reserved_4: 5;
        uint32_t bclk_reset: 1;
        uint32_t reserved_3: 2;
        uint32_t debug_bus_sel: 3;
        uint32_t enable_mclk: 1;
        uint32_t clear_tx_err_cnt: 1;
        uint32_t clear_rx_err_cnt: 1;
        uint32_t i2s_clk_sel: 2;
        uint32_t err_cnt_sat_set: 1;
        uint32_t reserved_2: 3;
        uint32_t tx_src_byte_swap: 1;
        uint32_t tx_src_lr_swap: 1;
        uint32_t rx_snk_byte_swap: 1;
        uint32_t rx_snk_lr_swap: 1;
        uint32_t tx_fifo_0_reg_0_en: 1;
        uint32_t tx_fifo_0_reg_1_en: 1;
        uint32_t reserved_1: 2;
        uint32_t rx_fifo_0_reg_0_en: 1;
        uint32_t rx_fifo_0_reg_1_en: 1;
        uint32_t reserved_0: 2;
    } b;
} I2S_FIFO_EN_CLK_CON_TypeDef;

/* 0x0C
   0       R/W    tx_dsp_clear_int_0          1'b0
   1       R/W    rx_dsp_clear_int_0          1'b0
   6:2     R/W    intr_clr_0                  5'h0
   13:7    R/W    reserved57                  7'h0
   14      R/W    tx_fifo_data_valid_intr_clr 1'b0
   15      R/W    reserved55                  1'b0
   23:16   R/W    int_enable_dsp_0            8'h0
   31:24   R/W    reserved53                  8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_dsp_clear_int_0: 1;
        uint32_t rx_dsp_clear_int_0: 1;
        uint32_t intr_clr_0: 5;
        uint32_t reserved_2: 7;
        uint32_t tx_fifo_data_valid_intr_clr: 1;
        uint32_t reserved_1: 1;
        uint32_t int_enable_dsp_0: 8;
        uint32_t reserved_0: 8;
    } b;
} I2S_INTR_CON_TypeDef;

/* 0x10
   31:0    R      RX_FIFO_RD_ADDR             32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t RX_FIFO_RD_ADDR: 32;
        } b;
    } I2S_RX_FIFO_RD_ADDR_TypeDef;

    /* 0x14
       5:0     R      tx_depth_cnt_0              6'h20
       7:6     R      dummy67                     2'b00
       13:8    R      rx_depth_cnt_0              6'h0
       30:14   R      dummy65                     17'h0
       31      R      dummy64                     1'b0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t tx_depth_cnt_0: 6;
                const uint32_t dummy67: 2;
                const uint32_t rx_depth_cnt_0: 6;
                const uint32_t dummy65: 17;
                const uint32_t dummy64: 1;
            } b;
        } I2S_FIFO_CNT_STA_TypeDef;

    /* 0x18
       15:0    R      tx_err_cnt                  16'h0
       31:16   R      rx_err_cnt                  16'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t tx_err_cnt: 16;
                const uint32_t rx_err_cnt: 16;
            } b;
        } I2S_TX_RX_ERR_STA_TypeDef;

    /* 0x1C
       15:0    R/W    tx_mi                       16'h625
       30:16   R/W    tx_ni                       15'h48
       31      R/W    tx_mi_ni_update             1'b0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t tx_mi: 16;
                uint32_t tx_ni: 15;
                uint32_t tx_mi_ni_update: 1;
            } b;
        } I2S_TX_FRA_DIV_TypeDef;

    /* 0x20
       5:0     R/W    txdma_burstsize             6'h10
       7:6     R/W    reserved81                  2'h0
       13:8    R/W    rxdma_burstsize             6'h10
       15:14   R/W    reserved79                  2'h0
       23:16   R/W    tx_bclk_div_ratio           8'h40
       31:24   R/W    rx_bclk_div_ratio           8'h40
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t txdma_burstsize: 6;
                uint32_t reserved_1: 2;
                uint32_t rxdma_burstsize: 6;
                uint32_t reserved_0: 2;
                uint32_t tx_bclk_div_ratio: 8;
                uint32_t rx_bclk_div_ratio: 8;
            } b;
        } I2S_LRCK_FIFO_TH_CON_TypeDef;

    /* 0x24
       0       R      sp_ready_to_tx              1'b0
       1       R      sp_ready_to_rx              1'b0
       2       R      tx_fifo_full_intr           1'b0
       3       R      rx_fifo_full_intr           1'b0
       4       R      tx_fifo_empty_intr          1'b0
       5       R      rx_fifo_empty_intr          1'b0
       6       R      tx_i2s_idle                 1'b0
       15:7    R      dummy90                     9'b0
       16      R      tx_fifo_data_valid_intr     1'b0
       27:17   R      dummy88                     11'b0
       28      R      tx_fifo_full_0              1'b0
       29      R      rx_fifo_full_0              1'b0
       30      R      tx_fifo_empty_0             1'b1
       31      R      rx_fifo_empty_0             1'b1
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t sp_ready_to_tx: 1;
                const uint32_t sp_ready_to_rx: 1;
                const uint32_t tx_fifo_full_intr: 1;
                const uint32_t rx_fifo_full_intr: 1;
                const uint32_t tx_fifo_empty_intr: 1;
                const uint32_t rx_fifo_empty_intr: 1;
                const uint32_t tx_i2s_idle: 1;
                const uint32_t dummy90: 9;
                const uint32_t tx_fifo_data_valid_intr: 1;
                const uint32_t dummy88: 11;
                const uint32_t tx_fifo_full_0: 1;
                const uint32_t rx_fifo_full_0: 1;
                const uint32_t tx_fifo_empty_0: 1;
                const uint32_t rx_fifo_empty_0: 1;
            } b;
        } I2S_FIFO_STA_TypeDef;

    /* 0x28
       0       R/W    trx_same_fs                 1'h1
       1       R/W    trx_same_ch                 1'h1
       2       R/W    trx_same_length             1'h1
       3       R/W    sck_out_inverse             1'h0
       4       R/W    reserved111                 1'h0
       5       R/W    sp_wclk_rx_inverse          1'h0
       6       R/W    fixed_bclk_sel              1'h0
       7       R/W    fixed_bclk                  1'h0
       9:8     R/W    sp_data_format_sel_rx       2'h0
       10      R/W    trx_same_lrc                1'h0
       11      R/W    sp_en_i2s_mono_rx           1'h0
       14:12   R/W    sp_data_len_sel_rx          3'h0
       23:15   R/W    reserved103                 9'h0
       26:24   R/W    sp_ch_len_sel_tx            3'b100
       27      R/W    reserved101                 1'h0
       30:28   R/W    sp_ch_len_sel_rx            3'b100
       31      R/W    trx_same_ch_len             1'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t trx_same_fs: 1;
                uint32_t trx_same_ch: 1;
                uint32_t trx_same_length: 1;
                uint32_t sck_out_inverse: 1;
                uint32_t reserved_2: 1;
                uint32_t sp_wclk_rx_inverse: 1;
                uint32_t fixed_bclk_sel: 1;
                uint32_t fixed_bclk: 1;
                uint32_t sp_data_format_sel_rx: 2;
                uint32_t trx_same_lrc: 1;
                uint32_t sp_en_i2s_mono_rx: 1;
                uint32_t sp_data_len_sel_rx: 3;
                uint32_t reserved_1: 9;
                uint32_t sp_ch_len_sel_tx: 3;
                uint32_t reserved_0: 1;
                uint32_t sp_ch_len_sel_rx: 3;
                uint32_t trx_same_ch_len: 1;
            } b;
        } I2S_FORM_CON_TypeDef;

    /* 0x2C
       15:0    R/W    rx_mi                       16'h625
       30:16   R/W    rx_ni                       15'h48
       31      R/W    rx_mi_ni_update             1'b0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t rx_mi: 16;
                uint32_t rx_ni: 15;
                uint32_t rx_mi_ni_update: 1;
            } b;
        } I2S_RX_FRA_DIV_TypeDef;

    /* 0x30
       26:0    R/W    tx_i2s_compare_val          27'h64
       28:27   R/W    reserved124                 2'h0
       29      W1C    en_fs_phase_latch           1'h0
       30      R/W    en_tx_i2s_interrupt         1'h0
       31      W1C    clr_tx_i2s_rdy              1'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t tx_i2s_compare_val: 27;
                uint32_t reserved_0: 2;
                uint32_t en_fs_phase_latch: 1;
                uint32_t en_tx_i2s_interrupt: 1;
                uint32_t clr_tx_i2s_rdy: 1;
            } b;
        } I2S_TX_CNT_CTRL_TypeDef;

    /* 0x34
       4:0     R      tx_fs_phase_rpt             5'h0
       31:5    R      tx_i2s_counter              27'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t tx_fs_phase_rpt: 5;
                const uint32_t tx_i2s_counter: 27;
            } b;
        } I2S_TX_CNT_VAL_TypeDef;


    /* 0x38
       14:0    R/W    reserved136                 15'h0
       15      R/W    tx_ch0_mix_sat_set          1'b0
       18:16   R/W    reserved134                 3'b0
       19      R/W    tx_ch1_mix_sat_set          1'b0
       20      R/W    tx_ch0_mix_en               1'b0
       21      R/W    tx_ch1_mix_en               1'b0
       31:22   R/W    reserved130                 10'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t reserved_2: 15;
                uint32_t tx_ch0_mix_sat_set: 1;
                uint32_t reserved_1: 3;
                uint32_t tx_ch1_mix_sat_set: 1;
                uint32_t tx_ch0_mix_en: 1;
                uint32_t tx_ch1_mix_en: 1;
                uint32_t reserved_0: 10;
            } b;
        } I2S_TX_CH_DATA_MIX_TypeDef;

    /* 0x3C
       1:0     R/W    tx_ch0_data_sel             2'h0
       3:2     R/W    reserved144                 2'h0
       5:4     R/W    tx_ch1_data_sel             2'h1
       7:6     R/W    reserved142                 2'h0
       9:8     R/W    tx_ch2_data_sel             2'h2
       11:10   R/W    reserved140                 2'h0
       13:12   R/W    tx_ch3_data_sel             2'h3
       31:14   R/W    reserved138                 18'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t tx_ch0_data_sel: 2;
                uint32_t reserved_3: 2;
                uint32_t tx_ch1_data_sel: 2;
                uint32_t reserved_2: 2;
                uint32_t tx_ch2_data_sel: 2;
                uint32_t reserved_1: 2;
                uint32_t tx_ch3_data_sel: 2;
                uint32_t reserved_0: 18;
            } b;
        } I2S_TX_CH_DATA_SEL_TypeDef;

    /* 0x54
       1:0     R/W    rx_fifo_0_reg_0_l_sel       2'h0
       7:2     R/W    reserved153                 6'h0
       9:8     R/W    rx_fifo_0_reg_0_r_sel       2'h1
       15:10   R/W    reserved151                 6'h0
       17:16   R/W    rx_fifo_0_reg_1_l_sel       2'h2
       23:18   R/W    reserved149                 6'h0
       25:24   R/W    rx_fifo_0_reg_1_r_sel       2'h3
       31:26   R/W    reserved147                 6'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t rx_fifo_0_reg_0_l_sel: 2;
                uint32_t reserved_3: 6;
                uint32_t rx_fifo_0_reg_0_r_sel: 2;
                uint32_t reserved_2: 6;
                uint32_t rx_fifo_0_reg_1_l_sel: 2;
                uint32_t reserved_1: 6;
                uint32_t rx_fifo_0_reg_1_r_sel: 2;
                uint32_t reserved_0: 6;
            } b;
        } I2S_RX_FIFO_REG0_TypeDef;

    /* 0x5C
       26:0    R/W    rx_i2s_compare_val          27'h64
       29:27   R/W    reserved158                 3'h0
       30      R/W    en_rx_i2s_interrupt         1'h0
       31      W1C    clr_rx_i2s_rdy              1'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t rx_i2s_compare_val: 27;
                uint32_t reserved_0: 3;
                uint32_t en_rx_i2s_interrupt: 1;
                uint32_t clr_rx_i2s_rdy: 1;
            } b;
        } I2S_RX_CNT_CTRL_TypeDef;

    /* 0x60
       4:0     R      rx_fs_phase_rpt             5'h0
       31:5    R      rx_i2s_counter              27'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t rx_fs_phase_rpt: 5;
                const uint32_t rx_i2s_counter: 27;
            } b;
        } I2S_RX_CNT_VAL_TypeDef;

    /* 0x64
       4:0     R      reserved165                 5'h0
       31:5    R      tx_data_valid_fs_counter_rpt27'h0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t reserved_0: 5;
                const uint32_t tx_data_valid_fs_counter_rpt: 27;
            } b;
        } I2S_TX_VAL_CNT_TypeDef;

    /* 0x68
       5:0     R      tx_depth_cnt_latch          6'h0
       7:6     R      dummy169                    2'b0
       13:8    R      rx_depth_cnt_latch          6'h0
       31:14   R      dummy167                    18'b0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t tx_depth_cnt_latch: 6;
                const uint32_t dummy169: 2;
                const uint32_t rx_depth_cnt_latch: 6;
                const uint32_t dummy167: 18;
            } b;
        } I2S_FIFO_CNT_LATCH_TypeDef;

    typedef union t_soc_0x220_type
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t r_PON_FEN_AUDIO: 1;            // [0]
                uint32_t r_PON_FEN_SPORT0: 1;           // [1]
                uint32_t r_PON_FEN_SPORT1: 1;           // [2]
                uint32_t rsvd0: 1;                      // [3]
                uint32_t r_CLK_EN_AUDIO: 1;             // [4]
                uint32_t r_CLK_EN_SPORT0: 1;            // [5]
                uint32_t r_CLK_EN_SPORT1: 1;            // [6]
                uint32_t rsvd1: 1;                      // [7]
                uint32_t r_CLK_EN_SPORT_40M: 1;         // [8]
                uint32_t r_CLK_EN_AUDIO_REG: 1;         // [9]
                uint32_t r_PON_FEN_SPORT2: 1;           // [10]
                uint32_t rsvd2: 1;                      // [11]
                uint32_t r_CLK_EN_SPORT2: 1;            // [12]
                uint32_t rsvd3: 19;                     // [31:13]
            };
        } T_SOC_0x220_TYPE;

    typedef union t_soc_0x224_type
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t r_SPORT0_PLL_CLK_SEL: 3;       // [2:0]
                uint32_t r_SPORT0_EXT_CODEC: 1;         // [3]
                uint32_t r_SPORT1_PLL_CLK_SEL: 3;       // [6:4]
                uint32_t r_CODEC_STANDALONE: 1;         // [7]
                uint32_t r_PLL_DIV0_SETTING: 8;         // [15:8]
                uint32_t r_PLL_DIV1_SETTING: 8;         // [23:16]
                uint32_t r_PLL_DIV2_SETTING: 8;         // [31:24]
            };
        } T_SOC_0x224_TYPE;

    typedef union t_soc_0x228_type
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rsvd0: 3;                      // [2:0]
                uint32_t r_SPORT0_MCLK_OUT: 1;          // [3]
                uint32_t r_SPORT1_MCLK_OUT: 1;          // [4]
                uint32_t r_SPORT2_MCLK_OUT: 1;          // [5]
                uint32_t rsvd1: 1;                      // [6]
                uint32_t r_AUDIO_CLK_FROM_PLL: 1;       // [7]
                uint32_t r_SPORT1_EXT_CODEC: 1;         // [8]
                uint32_t rsvd2: 4;                      // [12:9]
                uint32_t r_SPORT2_PLL_CLK_SEL: 3;       // [15:13]
                uint32_t rsvd3: 3;                      // [18:16]
                uint32_t r_SPORT2_EXT_CODEC: 1;         // [19]
                uint32_t rsvd4: 12;                     // [31:20]
            };
        } T_SOC_0x228_TYPE;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_I2S_DEF_H */

