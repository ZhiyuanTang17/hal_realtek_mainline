/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
#define CHIP_I2S_CHANNEL_NUM                (1)

#define I2S_SUPPORT_TRX_INDEPENDENT_CONTROL (0)
#define I2S_SUPPORT_TRX_FIFO                (0)
#define I2S_SUPPORT_INT_TX_VALID            (0)
#define I2S_SUPPORT_PLL_CLK                 (0)
#define I2S_SUPPORT_DATE_WIDTH_32BIT        (0)
#define I2S_SUPPORT_MCLK_OUTPUT             (1)
#define I2S_SUPPORT_AUTO_CLOCK              (1)
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
    __I  uint32_t I2S_RESV[16];                 /*!< 0x28-0X64 */
    __IO uint32_t I2S_QACTIVE_CON;              /*!< 0x68 */

} I2S_TypeDef;

/*============================================================================*
 *                          I2S Declaration
 *============================================================================*/
#define I2S0                ((I2S_TypeDef *) I2S0_BASE)
#define SPORT_EXT_CODEC_REG    (*(volatile uint32_t *)0x40000240)

#define IS_I2S_PERIPH(PERIPH)     (((PERIPH) == I2S0))
/*============================================================================*
 *                         I2S Private Types
 *============================================================================*/
//#define PERIPH_REG_BASE     0x40002000UL

#define I2S_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       0x00
#define I2S_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       0x8000000FUL

/**
 * \defgroup    I2S_Clock_Source I2S Clock Source
 * \{
 * \ingroup     I2S_Exported_Constants
 */
typedef enum
{
    I2S_CLOCK_SRC_40M,
    I2S_CLOCK_SRC_128FS,
    I2S_CLOCK_SRC_256FS,
} I2SClockSrc_TypeDef;

#define IS_I2S_CLOCK_SRC(CLOCK) (((CLOCK) == I2S_CLOCK_SRC_40M) || \
                                 ((CLOCK) == I2S_CLOCK_SRC_128FS) || \
                                 ((CLOCK) == I2S_CLOCK_SRC_256FS))

/** End of I2S_Clock_Source
  * \}
  */


/**
 * \defgroup    I2S_All_Periph   I2S All Periph
 * \{
 * \ingroup     I2S_Exported_Constants
 */
#define IS_I2S_ALL_PERIPH(PERIPH) ((PERIPH) == I2S0)

/** End of I2S_All_Periph
  * \}
  */

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
   6       R/W    sp_loopback                 1'b0
   7       R/W    dsp_ctl_mode                1'b0
   9:8     R/W    sp_data_format_sel_tx       2'b00
   10      R/W    reserved0                   1'b0
   11      R/W    sp_en_i2s_mono_tx           1'b0
   13:12   R/W    sp_data_len_sel_tx          2'b00
   14      R/W    sp_inv_i2s_sclk             1'b0
   15      R/W    sp_i2s_self_lpbk_en         1'b0
   16      R/W    sp_tx_disable               1'b1
   17      R/W    sp_start_tx                 1'b0
   19:18   R/W    reserved1                   2'b00
   21:20   R/W    sp_sel_i2s_tx_ch            2'b00
   22      R/W    tx_lsb_first                1'b0
   23      R/W    rx_lsb_first                1'b0
   24      R/W    sp_rx_disable               1'b1
   25      R/W    sp_start_rx                 1'b0
   27:26   R/W    reserved2                   2'b00
   29:28   R/W    sp_sel_i2s_rx_ch            2'b00
   30      R/W    mclk_sel                    1'b0
   31      R/W    long_frame_sync             1'b1
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
        uint32_t reserved0: 1;
        uint32_t sp_en_i2s_mono_tx: 1;
        uint32_t sp_data_len_sel_tx: 2;
        uint32_t sp_inv_i2s_sclk: 1;
        uint32_t sp_i2s_self_lpbk_en: 1;
        uint32_t sp_tx_disable: 1;
        uint32_t sp_start_tx: 1;
        uint32_t reserved_1: 2;
        uint32_t sp_sel_i2s_tx_ch: 2;
        uint32_t tx_lsb_first: 1;
        uint32_t rx_lsb_first: 1;
        uint32_t sp_rx_disable: 1;
        uint32_t sp_start_rx: 1;
        uint32_t reserved2: 2;
        uint32_t sp_sel_i2s_rx_ch: 2;
        uint32_t mclk_sel: 1;
        uint32_t long_frame_sync: 1;
    } b;
} I2S_CTRL_TypeDef;

/* 0x08
   7:0     R/W    frame_sync_offset           8'h0
   10:8    R/W    debug_bus_sel               3'h0
   11      R/W    reserved0                   1'b0
   12      R/W    clear_tx_err_cnt            1'b0
   13      R/W    clear_rx_err_cnt            1'b0
   15:14   R/W    i2s_clk_sel                 2'h0
   16      R/W    mode_40mhz                  1'b0
   17      R/W    mode_128fs                  1'h0
   19:18   R/W    reserved1                   2'b0
   20      R/W    tx_src_byte_swap            1'b0
   21      R/W    tx_src_lr_swap              1'b0
   22      R/W    rx_snk_byte_swap            1'b0
   23      R/W    rx_snk_lr_swap              1'b0
   29:24   R/W    int_enable                  6'b0
   31:30   R/W    reserved2                   2'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t frame_sync_offset: 8;
        uint32_t debug_bus_sel: 3;
        uint32_t reserved0: 1;
        uint32_t clear_tx_err_cnt: 1;
        uint32_t clear_rx_err_cnt: 1;
        uint32_t i2s_clk_sel: 2;
        uint32_t mode_40mhz: 1;
        uint32_t mode_128fs: 1;
        uint32_t reserved_1: 2;
        uint32_t tx_src_byte_swap: 1;
        uint32_t tx_src_lr_swap: 1;
        uint32_t rx_snk_byte_swap: 1;
        uint32_t rx_snk_lr_swap: 1;
        uint32_t int_enable: 6;
        uint32_t reserved_2: 2;
    } b;
} I2S_FIFO_EN_CLK_CON_TypeDef;

/* 0x0C
   0       R/W    tx_dsp_clear_int_0          1'b0
   1       R/W    rx_dsp_clear_int_0          1'b0
   17:2    R/W    reserved_0                  16'h0
   18      R/W    tx_dma_single_low           1'b0
   19      R/W    tx_dma_single_low           1'b0
   31:20   R/W    reserved_1                  12'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_dsp_clear_int_0: 1;
        uint32_t rx_dsp_clear_int_0: 1;
        uint32_t reserved_0: 16;
        uint32_t tx_dma_single_low: 1;
        uint32_t rx_dma_single_low: 1;
        uint32_t reserved_1: 12;
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
   31:14   R/W    reserved79                  18'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t txdma_burstsize: 6;
        uint32_t reserved_1: 2;
        uint32_t rxdma_burstsize: 6;
        uint32_t reserved_0: 18;
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
   31:7    R      reserved_0                  25'b0
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
        const uint32_t reserved_0: 25;
    } b;
} I2S_FIFO_STA_TypeDef;

/* 0x68
   0       R/W    sclk_qactive_man_data       0x0
   1       R/W    sclk_qactive_man_enable     0x0
   2       R/W    pclk_qactive_man_data       0x0
   3       R/W    pclk_qactive_man_enable     0x0
   30:4    R      reserved_0                  0x0
   31      R/W    sport_func_en               0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sclk_qactive_man_data: 1;
        uint32_t sclk_qactive_man_enable: 1;
        uint32_t pclk_qactive_man_data: 1;
        uint32_t pclk_qactive_man_enable: 1;
        uint32_t reserved_0: 27;
        uint32_t sport_func_en: 1;
    } b;
} I2S_QACTIVE_CON_TypeDef;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_I2S_DEF_H */

