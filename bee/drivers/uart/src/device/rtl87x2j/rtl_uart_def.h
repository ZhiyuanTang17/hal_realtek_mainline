/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_UART_DEF_H
#define RTL_UART_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/*============================================================================*
 *                          UART Defines
 *============================================================================*/
/** \defgroup UART        UART
  * \brief
  * \{
  */

/** \defgroup UART_Exported_Constants UART Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup UART_Defines UART Defines
 * \{
 * \ingroup  UART_Exported_Constants
 */
#define CHIP_UART_NUM                       (4)
#define UART_SUPPORT_TX_DONE                (1)
#define UART_SUPPORT_TX_THRESHOLD           (1)
#define UART_SUPPORT_TXDATA_API             (1)
#define UART_SUPPORT_HALF_WORD              (0)
#define UART_SUPPORT_CLEAR_TX_FIFO          (1)
#define UART_SUPPORT_AUTO_CLOCK             (1)

/** End of UART_Defines
  * \}
  */

/** End of UART_Exported_Constants
  * \}
  */

/** End of UART
  * \}
  */

/*============================================================================*
 *                          UART Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t UART_DLL;                  /*!< 0x00 */
    __IO uint32_t UART_DLM_IER;              /*!< 0x04 */
    __IO uint32_t UART_IIR_FCR;              /*!< 0x08 */
    __IO uint32_t UART_LCR;                  /*!< 0x0C */
    __IO uint32_t UART_CTRL0;                /*!< 0x10 */
    __I  uint32_t UART_LSR;                  /*!< 0x14 */
    __IO uint32_t UART_CTRL1;                /*!< 0x18 */
    __IO uint32_t UART_SCR;                  /*!< 0x1C */
    __IO uint32_t UART_STSR;                 /*!< 0x20 */
    __IO uint32_t UART_RBR_THR;              /*!< 0x24 */
    __IO uint32_t UART_MISCR;                /*!< 0x28 */
    __IO uint32_t UART_DUMMY;                /*!< 0x2C */
    __IO uint32_t UART_RSVD1[4];             /*!< 0x30 - 0x3C */
    __IO uint32_t UART_RX_TIMEOUT;           /*!< 0x40 */
    __IO uint32_t UART_RX_TIMEOUT_STS;       /*!< 0x44 */
    __IO uint32_t UART_RX_TIMEOUT_EN;        /*!< 0x48 */
    __I  uint32_t UART_RXTX_FIFO_WL;         /*!< 0x4C */
    __IO uint32_t UART_INT_MASK;             /*!< 0x50 */
    __I  uint32_t UART_TXDONE_INT;           /*!< 0x54 */
    __I  uint32_t UART_TX_THD_INT;           /*!< 0x58 */
    __IO uint32_t UART_CTRL2;                /*!< 0x5C */
    __IO uint32_t UART_VERSION;              /*!< 0x60 */
    __IO uint32_t UART_QACTIVE_CTRL;         /*!< 0x64 */
} UART_TypeDef;

/*============================================================================*
 *                          UART Declaration
 *============================================================================*/
/** \defgroup UART        UART
  * \brief
  * \{
  */

/** \defgroup UART_Exported_Constants UART Exported Constants
  * \brief
  * \{
  */

/** \defgroup UART_Declaration UART Declaration
  * \{
  * \ingroup  UART_Exported_Constants
  */

#define UART0                   ((UART_TypeDef *) UART0_BASE)
#define UART1                   ((UART_TypeDef *) UART1_BASE)
#define UART2                   ((UART_TypeDef *) UART2_BASE)
#define UART3                   ((UART_TypeDef *) UART3_BASE)

#define IS_UART_PERIPH(PERIPH)  (((PERIPH) == UART0) || \
                                 ((PERIPH) == UART1) || \
                                 ((PERIPH) == UART2) || \
                                 ((PERIPH) == UART3))

/** End of UART_Declaration
  * \}
  */

/** End of UART_Exported_Constants
  * \}
  */

/** End of UART
  * \}
  */

/*============================================================================*
 *                          UART Private Types
 *============================================================================*/
typedef struct
{
    uint32_t uart_reg[13];
} UARTStoreReg_Typedef;

/*============================================================================*
 *                          UART Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   7:0     R/W    dll                             8'h0
   31:8    R      reserved1                       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dll: 8;
        const uint32_t reserved_0: 24;
    } b;
} UART_DLL_TypeDef;


/* 0x04
   7:0     R/W    dlm                                 8'h0
   31:8    R      reserved2                           24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dlm: 8;
        const uint32_t reserved_0: 24;
    } b;
} UART_DLM_TypeDef;


/* 0x04
   0       R/W    erbi                            1'h0
   1       R/W    etbei                           1'h0
   2       R/W    elsi                            1'h0
   3       R/W    uart_dummy_000                  1'h0
   4       R/W    tx_empty_stop_int_en            1'h0
   5       R/W    tx_fifo_th_int_en               1'h0
   31:6    R      reserved3                       26'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t erbi: 1;
        uint32_t etbei: 1;
        uint32_t elsi: 1;
        uint32_t uart_dummy_000: 1;
        uint32_t tx_empty_stop_int_en: 1;
        uint32_t tx_fifo_th_int_en: 1;
        const uint32_t reserved_0: 26;
    } b;
} UART_IER_TypeDef;


/* 0x08
   0       R      int_pend                        1'h1
   3:1     R      int_id                          3'h0
   31:4    R      reserved4                       28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t int_pend: 1;
        const uint32_t int_id: 3;
        const uint32_t reserved_0: 28;
    } b;
} UART_IIR_TypeDef;


/* 0x08
   0       W      rxfifo_error_en                 1'h1
   1       R/WAC  clear_rxfifo                    1'h0
   2       R/WAC  clear_txfifo                    1'h0
   3       W      dma_mode                        1'h0
   7:4     R      reserved7                       4'h0
   12:8    W      rxfifo_trigger_level            5'he
   15:13   R      reserved6                       3'h0
   20:16   W      tx_fifo_th                      5'h0
   31:21   R      reserved5                       11'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rxfifo_error_en: 1;
        uint32_t clear_rxfifo: 1;
        uint32_t clear_txfifo: 1;
        uint32_t dma_mode: 1;
        const uint32_t reserved_2: 4;
        uint32_t rxfifo_trigger_level: 5;
        const uint32_t reserved_1: 3;
        uint32_t tx_fifo_th: 5;
        const uint32_t reserved_0: 11;
    } b;
} UART_FCR_TypeDef;


/* 0x0C
   0       R/W    wls0                            1'h1
   1       R      reserved9                       1'h1
   2       R/W    stb                             1'h0
   3       R/W    parity_en                       1'h0
   4       R/W    even_parity_sel                 1'h0
   5       R/W    stick_parity                    1'h0
   6       R/W    break_ctrl                      1'h0
   7       R/W    dlab                            1'h0
   31:8    R      reserved8                       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t wls0: 1;
        const uint32_t reserved_1: 1;
        uint32_t stb: 1;
        uint32_t parity_sel: 3;
        uint32_t break_ctrl: 1;
        uint32_t dlab: 1;
        const uint32_t reserved_0: 24;
    } b;
} UART_LCR_TypeDef;


/* 0x10
   0       R/W    uart_dummy_002                  1'h0
   1       R/W    rts                             1'h0
   3:2     R/W    uart_dummy_001                  2'h0
   4       R/W    loopback_en                     1'h0
   5       R/W    autoflow_en                     1'h0
   31:6    R      reserved10                      26'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t uart_dummy_002: 1;
        uint32_t rts: 1;
        uint32_t uart_dummy_001: 2;
        uint32_t loopback_en: 1;
        uint32_t autoflow_en: 1;
        const uint32_t reserved_0: 26;
    } b;
} UART_CTRL0_TypeDef;


/* 0x14
   0       R      rxfifo_datardy                  1'h0
   1       R      overrun_err                     1'h0
   2       R      parity_err                      1'h0
   3       R      framing_err                     1'h0
   4       R      break_err_int                   1'h0
   5       R      tx_fifo_empty                   1'h1
   6       R      tx_empty                        1'h1
   7       R      rxfifo_err                      1'h0
   31:8    R      reserved11                      24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rxfifo_datardy: 1;
        const uint32_t overrun_err: 1;
        const uint32_t parity_err: 1;
        const uint32_t framing_err: 1;
        const uint32_t break_err_int: 1;
        const uint32_t tx_fifo_empty: 1;
        const uint32_t tx_empty: 1;
        const uint32_t rxfifo_err: 1;
        const uint32_t reserved_0: 24;
    } b;
} UART_LSR_TypeDef;


/* 0x18
   0       R      cts_tog                         1'h0
   3:1     R      reserved13                      3'h0
   4       R      cts_inv                         1'h1
   31:5    R      reserved12                      27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t cts_tog: 1;
        const uint32_t reserved_1: 3;
        const uint32_t cts_inv: 1;
        const uint32_t reserved_0: 27;
    } b;
} UART_CTRL1_TypeDef;


/* 0x1C
   2:0     R      reserved16                      3'h0
   3       R/W    pin_lb_test                     1'h0
   5:4     R/W    uart_dummy_003                  2'h3
   6       R/W    rxbreaksignalinterruptenable    1'h0
   7       R/W1C  rxbreaksignalinterruptstatus    1'h0
   11:8    R/W    dbg_sel                         4'h0
   15:12   R      reserved15                      4'h0
   27:16   R/W    xfactor_adj                     12'h0
   31:28   R      reserved14                      4'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_2: 3;
        uint32_t pin_lb_test: 1;
        uint32_t uart_dummy_003: 2;
        uint32_t rxbreaksignalinterruptenable: 1;
        uint32_t rxbreaksignalinterruptstatus: 1;
        uint32_t dbg_sel: 4;
        const uint32_t reserved_1: 4;
        uint32_t xfactor_adj: 12;
        const uint32_t reserved_0: 4;
    } b;
} UART_SCR_TypeDef;


/* 0x20
   2:0     R      reserved19                      3'h0
   3       R/W    reset_rcv                       1'h0
   7:4     R/W    xfactor                         4'hb
   18:8    R      reserved18                      11'h0
   23:19   R      tx_fifo_th                      5'h0
   24      R      dma_mode                        1'h0
   25      R      rxfifo_error_en                 1'h1
   30:26   R      rxfifo_trigger_level            5'he
   31      R      reserved17                      1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_2: 3;
        uint32_t reset_rcv: 1;
        uint32_t xfactor: 4;
        const uint32_t reserved_1: 11;
        const uint32_t tx_fifo_th: 5;
        const uint32_t dma_mode: 1;
        const uint32_t rxfifo_error_en: 1;
        const uint32_t rxfifo_trigger_level: 5;
        const uint32_t reserved_0: 1;
    } b;
} UART_STSR_TypeDef;


/* 0x24
   7:0     R      rx_data                         8'h0
   31:8    R      reserved20                      24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rx_data: 8;
        const uint32_t reserved_0: 24;
    } b;
} UART_RBR_TypeDef;



/* 0x24
   7:0     W      tx_data                             8'h0
   31:8    R      reserved21                          24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_data: 8;
        const uint32_t reserved_0: 24;
    } b;
} UART_THR_TypeDef;



/* 0x28
   0       R/W    uart_dummy_005                  1'h0
   1       R/W    txdma_en                        1'h0
   2       R/W    rxdma_en                        1'h0
   7:3     R/W    txdma_burstsize                 5'h0
   13:8    R/W    rxdma_burstsize                 6'h0
   15:14   R/W    uart_dummy_004                  2'h0
   31:16   R      reserved22                      16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t uart_dummy_005: 1;
        uint32_t txdma_en: 1;
        uint32_t rxdma_en: 1;
        uint32_t txdma_burstsize: 5;
        uint32_t rxdma_burstsize: 6;
        uint32_t uart_dummy_004: 2;
        const uint32_t reserved_0: 16;
    } b;
} UART_MISCR_TypeDef;


/* 0x2C
   31:0    R/W    uart_dummy_006                  32'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t uart_dummy_006: 32;
    } b;
} UART_DUMMY_TypeDef;



/* 0x40
   3:0     R/W    rxidle_timeout_value            4'h0
   29:4    R      reserved23                      26'h0
   30      R/W    rxidle_timeout_en_clr_opt       1'h0
   31      R/W    rxidle_timeout_en               1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rxidle_timeout_value: 4;
        const uint32_t reserved_0: 26;
        uint32_t rxidle_timeout_en_clr_opt: 1;
        uint32_t rxidle_timeout_en: 1;
    } b;
} UART_RX_TIMEOUT_TypeDef;


/* 0x44
   0       R/W1C  rxidle_timeout_int_sts          1'h0
   31:1    R      reserved24                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rxidle_timeout_int_sts: 1;
        const uint32_t reserved_0: 31;
    } b;
} UART_RX_TIMEOUT_STS_TypeDef;


/* 0x48
   0       R/W    rxidle_timeout_int_en           1'h0
   31:1    R      reserved25                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rxidle_timeout_int_en: 1;
        const uint32_t reserved_0: 31;
    } b;
} UART_RX_TIMEOUT_EN_TypeDef;


/* 0x4C
   4:0     R      tx_fifo_level                   5'h0
   7:5     R      reserved27                      3'h0
   13:8    R      rx_fifo_level                   6'h0
   31:14   R      reserved26                      18'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_fifo_level: 5;
        const uint32_t reserved_1: 3;
        const uint32_t rx_fifo_level: 6;
        const uint32_t reserved_0: 18;
    } b;
} UART_RXTX_FIFO_WL_TypeDef;


/* 0x50
   0       R/W    rd_ava_int_mask                     1'h0
   1       R/W    txfifo_empty_int_mask               1'h0
   2       R/W    rx_line_sts_int_mask                1'h0
   3       R/W    modem_sts_int_mask                  1'h0
   4       R/W    rx_break_int_mask                   1'h0
   5       R/W    rxidle_timeout_int_mask             1'h0
   6       R/W    txdone_int_mask                     1'h0
   7       R/W    tx_thd_int_mask                     1'h0
   31:8    R      reserved28                          24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rd_ava_int_mask: 1;
        uint32_t txfifo_empty_int_mask: 1;
        uint32_t rx_line_sts_int_mask: 1;
        uint32_t modem_sts_int_mask: 1;
        uint32_t rx_break_int_mask: 1;
        uint32_t rxidle_timeout_int_mask: 1;
        uint32_t txdone_int_mask: 1;
        uint32_t tx_thd_int_mask: 1;
        const uint32_t reserved_0: 24;
    } b;
} UART_INT_MASK_TypeDef;


/* 0x54
   0       R      tx_empty_stop_rdy               1'h0
   31:1    R      reserved29                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_empty_stop_rdy: 1;
        const uint32_t reserved_0: 31;
    } b;
} UART_TXDONE_INT_TypeDef;


/* 0x58
   0       R      int_tx_fifo                     1'h0
   31:1    R      reserved30                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t int_tx_fifo: 1;
        const uint32_t reserved_0: 31;
    } b;
} UART_TX_THD_INT_TypeDef;


/* 0x5C
   0       R/W    rx_data_sw                      1'h0
   31:1    R      reserved31                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rx_data_sw: 1;
        const uint32_t reserved_0: 31;
    } b;
} UART_CTRL2_TypeDef;


/* 0x60
   31:0    R      rtlversion                      32'h20240227
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rtlversion: 32;
    } b;
} UART_VERSION_TypeDef;


/* 0x64
   0       R/W    qact_pclk_icg_en                1'h0
   1       R/W    qact_sclk_man_data              1'h0
   2       R/W    qact_sclk_man_en                1'h0
   3       R/W    qact_pclk_man_data              1'h0
   4       R/W    qact_pclk_man_en                1'h0
   5       R/W    qact_pwr_man_data               1'h0
   6       R/W    qact_pwr_man_en                 1'h0
   15:7    R      reserved33                      9'h0
   16      R/W    rx_qact_auto_en                 1'h1
   17      R/W1O  rx_qact_auto_sts                1'h1
   29:18   R/W    rx_qact_auto_timeout_val_sel    12'h0
   31:30   R      reserved32                      2'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t qact_pclk_icg_en: 1;
        uint32_t qact_sclk_man_data: 1;
        uint32_t qact_sclk_man_en: 1;
        uint32_t qact_pclk_man_data: 1;
        uint32_t qact_pclk_man_en: 1;
        uint32_t qact_pwr_man_data: 1;
        uint32_t qact_pwr_man_en: 1;
        const uint32_t reserved_1: 9;
        uint32_t rx_qact_auto_en: 1;
        uint32_t rx_qact_auto_sts: 1;
        uint32_t rx_qact_auto_timeout_val_sel: 12;
        const uint32_t reserved_0: 2;
    } b;
} UART_QACTIVE_CTRL_TypeDef;


/*============================================================================*
 *                          UART TYPE/API Wrappers
 *============================================================================*/
/** \defgroup UART        UART
  * \brief
  * \{
  */


/** \defgroup UART_Exported_Constants UART Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    UART_Clock_Source UART Clock Source
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_CLOCK_SRC_40M = 0x0,
} UARTClockSrc_TypeDef;

#define IS_UART_CLOCK_SRC(CLOCK)     (((CLOCK) == UART_CLOCK_SRC_40M))

/** End of UART_Clock_Source
  * \}
  */

/**
 * \defgroup    UART_Clock_Divider UART Clock Divider
 * \{
 * \ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_CLOCK_DIV_1 = 0x0,
    UART_CLOCK_DIV_2 = 0x1,
    UART_CLOCK_DIV_4 = 0x2,
    UART_CLOCK_DIV_8 = 0x3,
    UART_CLOCK_DIV_16 = 0x4,
    UART_CLOCK_DIV_32 = 0x5,
    UART_CLOCK_DIV_40 = 0x6,
    UART_CLOCK_DIV_64 = 0x7,
} UARTClockDiv_TypeDef;

#define IS_UART_CLOCK_DIV(DIV) (((DIV) == UART_CLOCK_DIV_1) || \
                                ((DIV) == UART_CLOCK_DIV_2) || \
                                ((DIV) == UART_CLOCK_DIV_4) || \
                                ((DIV) == UART_CLOCK_DIV_8) || \
                                ((DIV) == UART_CLOCK_DIV_16) || \
                                ((DIV) == UART_CLOCK_DIV_32) || \
                                ((DIV) == UART_CLOCK_DIV_40) || \
                                ((DIV) == UART_CLOCK_DIV_64))

/** End of UART_Clock_Divider
  * \}
  */

/** End of UART_Exported_Constants
  * \}
  */

/** End of UART
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_UART_DEF_H */
