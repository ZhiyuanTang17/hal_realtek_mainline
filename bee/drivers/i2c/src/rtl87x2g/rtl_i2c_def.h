/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_i2c_def.h
* \brief    I2C related definitions for RTL87x2G
* \details
* \author
* \date     2023-11-16
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_I2C_DEF_H
#define RTL_I2C_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          I2C Defines
 *============================================================================*/
/** \defgroup I2C         I2C
  * \brief
  * \{
  */

/** \defgroup I2C_Exported_Constants I2C Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup I2C_Defines I2C Defines
 * \{
 * \ingroup  I2C_Exported_Constants
 */
#define I2C_TX_FIFO_SIZE                               (24)
#define I2C_RX_FIFO_SIZE                               (24)
#define I2C_CLOCK_MAX_SPEED                            (1000000)
/** End of I2C_Defines
  * \}
  */

/** End of I2C_Exported_Constants
  * \}
  */

/** End of I2C
  * \}
  */

/*============================================================================*
 *                         I2C Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t  IC_CON;                      /*!< 0x00 */
    __IO uint32_t  IC_TAR;                      /*!< 0x04 */
    __IO uint32_t  IC_SAR;                      /*!< 0x08 */
    __IO uint32_t  RSVD_0C;                     /*!< 0x0C */
    __IO uint32_t  IC_DATA_CMD;                 /*!< 0x10 */
    __IO uint32_t  IC_SS_SCL_HCNT;              /*!< 0x14 */
    __IO uint32_t  IC_SS_SCL_LCNT;              /*!< 0x18 */
    __IO uint32_t  IC_FS_SCL_HCNT;              /*!< 0x1C */
    __IO uint32_t  IC_FS_SCL_LCNT;              /*!< 0x20 */
    __IO uint32_t  RSVD_24[2];                  /*!< 0x24 - 0x28 */
    __I  uint32_t  IC_INTR_STAT;                /*!< 0x2C */
    __IO uint32_t  IC_INTR_MASK;                /*!< 0x30 */
    __I  uint32_t  IC_RAW_INTR_STAT;            /*!< 0x34 */
    __IO uint32_t  IC_RX_TL;                    /*!< 0x38 */
    __IO uint32_t  IC_TX_TL;                    /*!< 0x3C */
    __I  uint32_t  IC_CLR_INTR;                 /*!< 0x40 */
    __I  uint32_t  IC_CLR_RX_UNDER;             /*!< 0x44 */
    __I  uint32_t  IC_CLR_RX_OVER;              /*!< 0x48 */
    __I  uint32_t  IC_CLR_TX_OVER;              /*!< 0x4C */
    __I  uint32_t  IC_CLR_RD_REQ;               /*!< 0x50 */
    __I  uint32_t  IC_CLR_TX_ABRT;              /*!< 0x54 */
    __I  uint32_t  IC_CLR_RX_DONE;              /*!< 0x58 */
    __I  uint32_t  IC_CLR_ACTIVITY;             /*!< 0x5C */
    __I  uint32_t  IC_CLR_STOP_DET;             /*!< 0x60 */
    __I  uint32_t  IC_CLR_START_DET;            /*!< 0x64 */
    __I  uint32_t  IC_CLR_GEN_CALL;             /*!< 0x68 */
    __IO uint32_t  IC_ENABLE;                   /*!< 0x6C */
    __I  uint32_t  IC_STATUS;                   /*!< 0x70 */
    __I  uint32_t  IC_TXFLR;                    /*!< 0x74 */
    __I  uint32_t  IC_RXFLR;                    /*!< 0x78 */
    __IO uint32_t  IC_SDA_HOLD;                 /*!< 0x7C */
    __I  uint32_t  IC_TX_ABRT_SOURCE;           /*!< 0x80 */
    __IO uint32_t  IC_SLV_DATA_NACK_ONLY;       /*!< 0x84 */
    __IO uint32_t  IC_DMA_CR;                   /*!< 0x88 */
    __IO uint32_t  IC_DMA_TDLR;                 /*!< 0x8C */
    __IO uint32_t  IC_DMA_RDLR;                 /*!< 0x90 */
    __IO uint32_t  IC_SDA_SETUP;                /*!< 0x94 */
    __IO uint32_t  IC_ACK_GENERAL_CALL;         /*!< 0x98 */
    __I  uint32_t  IC_ENABLE_STATUS;            /*!< 0x9C */
    __IO uint32_t  IC_FS_SPKLEN;                /*!< 0xA0 */
} I2C_TypeDef;

/*============================================================================*
 *                         I2C Declaration
 *============================================================================*/
/** \defgroup I2C         I2C
  * \brief
  * \{
  */

/** \defgroup I2C_Exported_Constants I2C Exported Constants
  * \brief
  * \{
  */

/** \defgroup I2C_Declaration I2C Declaration
  * \{
  * \ingroup  I2C_Exported_Constants
  */

#define I2C0               ((I2C_TypeDef *) I2C0_REG_BASE)
#define I2C1               ((I2C_TypeDef *) I2C1_REG_BASE)
#define I2C2               ((I2C_TypeDef *) I2C2_REG_BASE)
#define I2C3               ((I2C_TypeDef *) I2C3_REG_BASE)

#define IS_I2C_ALL_PERIPH(PERIPH) (((PERIPH) == I2C0) || \
                                   ((PERIPH) == I2C1) || \
                                   ((PERIPH) == I2C2) || \
                                   ((PERIPH) == I2C3))

/** End of I2C_Declaration
  * \}
  */

/** End of I2C_Exported_Constants
  * \}
  */

/** End of I2C
  * \}
  */

/*============================================================================*
 *                         I2C Private Types
 *============================================================================*/
typedef struct
{
    uint32_t i2c_reg[18];
} I2CStoreReg_Typedef;

/*============================================================================*
 *                         I2C Registers and Field Descriptions
 *============================================================================*/
/* 0x00
    0       R/W    master_mode             1'h1
    2:1     R/W    speed                   2'b11
    3       R/W    ic_10bitaddr_slave      1'h1
    4       R      ic_10bitaddr_master     1'h1
    5       R/W    ic_restart_en           1'h1
    6       R/W    ic_slave_disable        1'h1
    7       R      reserved_dummy00_7      1'h0
    8       R/W    tx_empty_ctrl           1'h0
    9       R/W    reserved_dummy00_9      1'h0
    31:10   R      reserved_dummy00_31_10  22'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t master_mode: 1;
        uint32_t speed: 2;
        uint32_t ic_10bitaddr_slave: 1;
        const uint32_t ic_10bitaddr_master: 1;
            uint32_t ic_restart_en: 1;
            uint32_t ic_slave_disable: 1;
            const uint32_t reserved_2: 1;
            uint32_t tx_empty_ctrl: 1;
            const uint32_t reserved_1: 1;
            const uint32_t reserved_0: 22;
        } b;
    } IC_CON_TypeDef;



    /* 0x04
        9:0     R/W    ic_tar                  10'h055
        10      R/W    gc_or_start             1'h0
        11      R/W    special                 1'h0
        12      R/W    ic_10bitaddr_master     1'h1
        31:13   R      reserved_dummy04_31_13  19'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_tar: 10;
                uint32_t gc_or_start: 1;
                uint32_t special: 1;
                uint32_t ic_10bitaddr_master: 1;
                const uint32_t reserved_0: 19;
            } b;
        } IC_TAR_TypeDef;



    /* 0x08
        9:0     R/W    ic_sar                  10'h055
        31:10   R      reserved_dummy08_31_10  22'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_sar: 10;
                const uint32_t reserved_0: 22;
            } b;
        } IC_SAR_TypeDef;



    /* 0x10
        7:0     R/W    dat                     8'h0
        8       W      cmd                     1'h0
        9       W      stop                    1'h0
        10      W      restart                 1'h0
        31:11   R      reserved_dummy10_31_11  21'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dat: 8;
                uint32_t cmd: 1;
                uint32_t stop: 1;
                uint32_t restart: 1;
                const uint32_t reserved_0: 21;
            } b;
        } IC_DATA_CMD_TypeDef;



    /* 0x14
        15:0    R/W    ic_ss_scl_hcnt          16'h0190
        31:16   R      reserved_dummy14_31_16  16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_ss_scl_hcnt: 16;
                const uint32_t reserved_0: 16;
            } b;
        } IC_SS_SCL_HCNT_TypeDef;



    /* 0x18
        15:0    R/W    ic_ss_scl_lcnt          16'h01d6
        31:16   R      reserved_dummy18_31_16  16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_ss_scl_lcnt: 16;
                const uint32_t reserved_0: 16;
            } b;
        } IC_SS_SCL_LCNT_TypeDef;



    /* 0x1C
        15:0    R/W    ic_fs_scl_hcnt          16'h003c
        31:16   R      reserved_dummy1c_31_16  16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_fs_scl_hcnt: 16;
                const uint32_t reserved_0: 16;
            } b;
        } IC_FS_SCL_HCNT_TypeDef;



    /* 0x20
        15:0    R/W    ic_fs_scl_lcnt          16'h0082
        31:16   R      reserved_dummy20_31_16  16'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_fs_scl_lcnt: 16;
                const uint32_t reserved_0: 16;
            } b;
        } IC_FS_SCL_LCNT_TypeDef;




    /* 0x2C
        0       R      r_rx_under              1'h0
        1       R      r_rx_over               1'h0
        2       R      r_rx_full               1'h0
        3       R      r_tx_over               1'h0
        4       R      r_tx_empty              1'h0
        5       R      r_rd_req                1'h0
        6       R      r_tx_abrt               1'h0
        7       R      r_rx_done               1'h0
        8       R      r_activity              1'h0
        9       R      r_stop_det              1'h0
        10      R      r_start_det             1'h0
        11      R      r_gen_call              1'h0
        12      R      reserved_dummy2c_12     1'h0
        13      R      r_mst_on_hold           1'h0
        31:14   R      reserved_dummy2c_31_14  18'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t r_rx_under: 1;
                const uint32_t r_rx_over: 1;
                const uint32_t r_rx_full: 1;
                const uint32_t r_tx_over: 1;
                const uint32_t r_tx_empty: 1;
                const uint32_t r_rd_req: 1;
                const uint32_t r_tx_abrt: 1;
                const uint32_t r_rx_done: 1;
                const uint32_t r_activity: 1;
                const uint32_t r_stop_det: 1;
                const uint32_t r_start_det: 1;
                const uint32_t r_gen_call: 1;
                const uint32_t reserved_1: 1;
                const uint32_t r_mst_on_hold: 1;
                const uint32_t reserved_0: 18;
            } b;
        } IC_INTR_STAT_TypeDef;



    /* 0x30
        0       R/W    m_rx_under              1'h1
        1       R/W    m_rx_over               1'h1
        2       R/W    m_rx_full               1'h1
        3       R/W    m_tx_over               1'h1
        4       R/W    m_tx_empty              1'h1
        5       R/W    m_rd_req                1'h1
        6       R/W    m_tx_abrt               1'h1
        7       R/W    m_rx_done               1'h1
        8       R/W    m_activity              1'h0
        9       R/W    m_stop_det              1'h0
        10      R/W    m_start_det             1'h0
        11      R/W    m_gen_call              1'h1
        12      R      reserved_dummy30_12     1'h0
        13      R/W    m_mst_on_hold           1'h0
        31:14   R      reserved_dummy30_31_14  18'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t m_rx_under: 1;
                uint32_t m_rx_over: 1;
                uint32_t m_rx_full: 1;
                uint32_t m_tx_over: 1;
                uint32_t m_tx_empty: 1;
                uint32_t m_rd_req: 1;
                uint32_t m_tx_abrt: 1;
                uint32_t m_rx_done: 1;
                uint32_t m_activity: 1;
                uint32_t m_stop_det: 1;
                uint32_t m_start_det: 1;
                uint32_t m_gen_call: 1;
                const uint32_t reserved_1: 1;
                uint32_t m_mst_on_hold: 1;
                const uint32_t reserved_0: 18;
            } b;
        } IC_INTR_MASK_TypeDef;



    /* 0x34
        0       R      rx_under                1'h0
        1       R      rx_over                 1'h0
        2       R      rx_full                 1'h0
        3       R      tx_over                 1'h0
        4       R      tx_empty                1'h0
        5       R      rd_req                  1'h0
        6       R      tx_abrt                 1'h0
        7       R      rx_done                 1'h0
        8       R      activity                1'h0
        9       R      stop_det                1'h0
        10      R      start_det               1'h0
        11      R      gen_call                1'h0
        12      R      reserved_dummy34_12     1'h0
        13      R      mst_on_hold             1'h0
        31:14   R      reserved_dummy34_31_14  18'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rx_under: 1;
                const uint32_t rx_over: 1;
                const uint32_t rx_full: 1;
                const uint32_t tx_over: 1;
                const uint32_t tx_empty: 1;
                const uint32_t rd_req: 1;
                const uint32_t tx_abrt: 1;
                const uint32_t rx_done: 1;
                const uint32_t activity: 1;
                const uint32_t stop_det: 1;
                const uint32_t start_det: 1;
                const uint32_t gen_call: 1;
                const uint32_t reserved_1: 1;
                const uint32_t mst_on_hold: 1;
                const uint32_t reserved_0: 18;
            } b;
        } IC_RAW_INTR_STAT_TypeDef;



    /* 0x38
        7:0     R/W    rx_tl                   8'h14
        31:8    R      reserved_dummy38_31_8   24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rx_tl: 8;
                const uint32_t reserved_0: 24;
            } b;
        } IC_RX_TL_TypeDef;



    /* 0x3C
        7:0     R/W    tx_tl                   8'h03
        31:8    R      reserved_dummy3c_31_8   24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t tx_tl: 8;
                const uint32_t reserved_0: 24;
            } b;
        } IC_TX_TL_TypeDef;



    /* 0x40
        0       W1C    clr_intr                1'h0
        31:1    R      reserved_dummy40_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t clr_intr: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_INTR_TypeDef;



    /* 0x44
        0       R      clr_rx_under            1'h0
        31:1    R      reserved_dummy44_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_rx_under: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_RX_UNDER_TypeDef;



    /* 0x48
        0       R      clr_rx_over             1'h0
        31:1    R      reserved_dummy48_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_rx_over: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_RX_OVER_TypeDef;



    /* 0x4C
        0       R      clr_tx_over             1'h0
        31:1    R      reserved_dummy4c_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_tx_over: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_TX_OVER_TypeDef;



    /* 0x50
        0       R      clr_rd_req              1'h0
        31:1    R      reserved_dummy50_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_rd_req: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_RD_REQ_TypeDef;



    /* 0x54
        0       R      clr_tx_abrt             1'h0
        31:1    R      reserved_dummy54_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_tx_abrt: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_TX_ABRT_TypeDef;



    /* 0x58
        0       R      clr_rx_done             1'h0
        31:1    R      reserved_dummy58_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_rx_done: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_RX_DONE_TypeDef;



    /* 0x5C
        0       R      clr_activity            1'h0
        31:1    R      reserved_dummy5c_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_activity: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_ACTIVITY_TypeDef;



    /* 0x60
        0       R      clr_stop_det            1'h0
        31:1    R      reserved_dummy60_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_stop_det: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_STOP_DET_TypeDef;



    /* 0x64
        0       R      clr_start_det           1'h0
        31:1    R      reserved_dummy64_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_start_det: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_START_DET_TypeDef;



    /* 0x68
        0       R      clr_gen_call            1'h0
        31:1    R      reserved_dummy68_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t clr_gen_call: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_CLR_GEN_CALL_TypeDef;



    /* 0x6C
        0       R/W    ic_enable               1'h0
        31:1    R      reserved_dummy6c_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_enable: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_ENABLE_TypeDef;



    /* 0x70
        0       R      activity                1'h0
        1       R      tfnf                    1'h1
        2       R      tfe                     1'h1
        3       R      rfne                    1'h0
        4       R      rff                     1'h0
        5       R      mst_activity            1'h0
        6       R      slv_activity            1'h0
        7       R      Reserved                1'h0
        8       R      Reserved                1'h0
        9       R      Reserved                1'h0
        10      R      Reserved                1'h0
        31:11   R      reserved_dummy70_31_11  21'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t activity: 1;
                const uint32_t tfnf: 1;
                const uint32_t tfe: 1;
                const uint32_t rfne: 1;
                const uint32_t rff: 1;
                const uint32_t mst_activity: 1;
                const uint32_t slv_activity: 1;
                const uint32_t reserved_4: 1;
                const uint32_t reserved_3: 1;
                const uint32_t reserved_2: 1;
                const uint32_t reserved_1: 1;
                const uint32_t reserved_0: 21;
            } b;
        } IC_STATUS_TypeDef;



    /* 0x74
        6:0     R      txflr                   7'h0
        31:7    R      reserved_dummy74_31_7   25'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t txflr: 7;
                const uint32_t reserved_0: 25;
            } b;
        } IC_TXFLR_TypeDef;



    /* 0x78
        6:0     R      rxflr                   7'h0
        31:7    R      reserved_dummy78_31_7   25'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rxflr: 7;
                const uint32_t reserved_0: 25;
            } b;
        } IC_RXFLR_TypeDef;



    /* 0x7C
        15:0    R/W    ic_sda_tx_hold          16'h1
        23:16   R/W    ic_sda_rx_hold          8'h0
        31:24   R      reserved_dummy7c_31_24  8'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_sda_tx_hold: 16;
                uint32_t ic_sda_rx_hold: 8;
                const uint32_t reserved_0: 8;
            } b;
        } IC_SDA_HOLD_TypeDef;



    /* 0x80
        0       R      abrt_7b_addr_noack      1'h0
        1       R      abrt_10addr1_noack      1'h0
        2       R      abrt_10addr2_noack      1'h0
        3       R      abrt_txdata_noack       1'h0
        4       R      abrt_gcall_noack        1'h0
        5       R      abrt_gcall_read         1'h0
        6       R      reserved_dummy80_6      1'h0
        7       R      abrt_sbyte_ackdet       1'h0
        8       R      reserved_dummy80_8      1'h0
        9       R      abrt_sbyte_norstrt      1'h0
        10      R      abrt_10b_rd_norstrt     1'h0
        11      R      abrt_master_dis         1'h0
        12      R      arb_lost                1'h0
        13      R      abrt_slvflush_txfifo    1'h0
        14      R      abrt_slv_arblost        1'h0
        15      R      abrt_slvrd_intx         1'h0
        22:16   R      reserved_dummy80_22_16  7'h0
        31:23   R      tx_flush_cnt            9'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t abrt_7b_addr_noack: 1;
                const uint32_t abrt_10addr1_noack: 1;
                const uint32_t abrt_10addr2_noack: 1;
                const uint32_t abrt_txdata_noack: 1;
                const uint32_t abrt_gcall_noack: 1;
                const uint32_t abrt_gcall_read: 1;
                const uint32_t reserved_2: 1;
                const uint32_t abrt_sbyte_ackdet: 1;
                const uint32_t reserved_1: 1;
                const uint32_t abrt_sbyte_norstrt: 1;
                const uint32_t abrt_10b_rd_norstrt: 1;
                const uint32_t abrt_master_dis: 1;
                const uint32_t arb_lost: 1;
                const uint32_t abrt_slvflush_txfifo: 1;
                const uint32_t abrt_slv_arblost: 1;
                const uint32_t abrt_slvrd_intx: 1;
                const uint32_t reserved_0: 7;
                const uint32_t tx_flush_cnt: 9;
            } b;
        } IC_TX_ABRT_SOURCE_TypeDef;



    /* 0x84
        0       R/W    nack                    1'h0
        31:1    R      reserved_dummy84_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t nack: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_SLV_DATA_NACK_ONLY_TypeDef;



    /* 0x88
        0       R/W    rdmae                   1'h0
        1       R/W    tdmae                   1'h0
        31:2    R      reserved_dummy88_31_2   30'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rdmae: 1;
                uint32_t tdmae: 1;
                const uint32_t reserved_0: 30;
            } b;
        } IC_DMA_CR_TypeDef;



    /* 0x8C
        5:0     R/W    dmatdl                  6'h0
        31:6    R      reserved_dummy8c_31_6   26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dmatdl: 6;
                const uint32_t reserved_0: 26;
            } b;
        } IC_DMA_TDLR_TypeDef;



    /* 0x90
        5:0     R/W    dmardl                  6'h0
        31:6    R      reserved_dummy90_31_6   26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t dmardl: 6;
                const uint32_t reserved_0: 26;
            } b;
        } IC_DMA_RDLR_TypeDef;



    /* 0x94
        7:0     R/W    sda_setup               8'h64
        31:8    R      reserved_dummy94_31_8   24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t sda_setup: 8;
                const uint32_t reserved_0: 24;
            } b;
        } IC_SDA_SETUP_TypeDef;



    /* 0x98
        0       R/W    ack_gen_call            1'h1
        31:1    R      reserved_dummy98_31_1   31'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ack_gen_call: 1;
                const uint32_t reserved_0: 31;
            } b;
        } IC_ACK_GENERAL_CALL_TypeDef;



    /* 0x9C
        0       R      ic_en                   1'h0
        1       R      slv_disabled_while_busy 1'h0
        2       R      slv_rx_data_lost        1'h0
        31:3    R      reserved_dummy9c_31_3   29'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t ic_en: 1;
                const uint32_t slv_disabled_while_busy: 1;
                const uint32_t slv_rx_data_lost: 1;
                const uint32_t reserved_0: 29;
            } b;
        } IC_ENABLE_STATUS_TypeDef;



    /* 0xA0
        7:0     R/W    ic_fs_spklen            8'h5
        31:8    R      reserved_dummya0_31_8   24'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t ic_fs_spklen: 8;
                const uint32_t reserved_0: 24;
            } b;
        } IC_FS_SPKLEN_TypeDef;

    /* ================================================================================ */
    /* ================                   I2C  Constants               ================ */
    /* ================================================================================ */
    /** \defgroup I2C         I2C
      * \brief
      * \{
      */

    /** \defgroup I2C_Exported_Constants I2C Exported Constants
      * \brief
      * \{
      */

    /**
     * \defgroup    I2C_Clock_Source I2C Clock Source
     * \{
     * \ingroup     I2C_Exported_Constants
     */
    typedef enum
{
    I2C_CLOCK_SRC_40M,
} I2CClockSrc_TypeDef;

#define IS_I2C_CLK_SOURCE(PERIPH)     ((PERIPH) == I2C_CLOCK_SRC_40M)

/** End of I2C_Clock_Source
  * \}
  */

/**
 * \defgroup    I2C_Clock_Divider I2C Clock Divider
 * \{
 * \ingroup     I2C_Exported_Constants
 */
typedef enum
{
    I2C_CLOCK_DIVIDER_1 = 0x0,
    I2C_CLOCK_DIVIDER_2 = 0x1,
    I2C_CLOCK_DIVIDER_4 = 0x2,
    I2C_CLOCK_DIVIDER_8 = 0x3,
    I2C_CLOCK_DIVIDER_16 = 0x4,
    I2C_CLOCK_DIVIDER_32 = 0x5,
    I2C_CLOCK_DIVIDER_40 = 0x6,
    I2C_CLOCK_DIVIDER_64 = 0x7,
} I2CClockDiv_TypeDef;

#define IS_I2C_CLK_DIV(DIV) (((DIV) == I2C_CLOCK_DIVIDER_1) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_2) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_4) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_8) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_16) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_32) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_40) || \
                             ((DIV) == I2C_CLOCK_DIVIDER_64))

/** End of I2C_Clock_Divider
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_I2C_DEF_H */
