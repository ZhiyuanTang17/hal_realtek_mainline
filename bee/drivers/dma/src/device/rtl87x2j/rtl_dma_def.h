/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_DMA_DEF_H
#define RTL_DMA_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "vector_table.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         DMA Defines
 *============================================================================*/
/** \defgroup DMA        DMA
  * \brief
  * \{
  */

/** \defgroup DMA_Exported_Constants DMA Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup DMA_Defines DMA Defines
 * \{
 * \ingroup  DMA_Exported_Constants
 */
#define CHIP_DMA_CHANNEL_NUM                        (6)

#define DMA_SUPPORT_GATHER_SCATTER_FUNCTION         (0)
#define DMA_SUPPORT_INT_HAIF_BLOCK                  (0)
#define DMA_SUPPORT_SECURE_MODE                     (0)
#define DMA_SUPPORT_ADDRESS_DECREASE                (1)
#define DMA_SUPPORT_OSW_OSR_CHANGE                  (0)
#define DMA_SUPPORT_RAP_FUNCTION                    (1)
#define DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS        (1)
#define DMA_SUPPORT_BLOCK_COUNTER                   (1)
#define DMA_SUPPORT_AUTO_CLOCK                      (1)
#define DMA_SUPPORT_DATA_SIZE_DOUBLE_WORD           (0)
#define DMA_SUPPORT_MSIZE_64                        (1)
#define DMA_SUPPORT_MSIZE_128                       (1)
#define DMA_SUPPORT_MSIZE_256                       (1)
#define DMA_SUPPORT_MSIZE_BIGGER_THAN_FIFO_DEPTH    (0)
#define DMA_MEMORY_BARRIER_BEFORE_ENABLE            (0)
#define DMA_READ_REG_AFTER_CLEAR                    (0)
#define DMA_SUPPORT_PERIPHERAL_FLOW_CONTROL         (0)
#define DMA_SUPPORT_AUTO_SLOW_CONFIG                (0)

/** End of DMA_Defines
  * \}
  */

/** End of DMA_Exported_Constants
  * \}
  */

/** End of DMA
  * \}
  */

/*============================================================================*
 *                         DMA Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t DMA_SARx;                    /*!< 0x00 */
    __I  uint32_t DMA_CURR_SARx;               /*!< 0x04 */
    __IO uint32_t DMA_DARx;                    /*!< 0x08 */
    __I  uint32_t DMA_CURR_DARx;               /*!< 0x0C */
    __IO uint32_t DMA_LLPx_L;                  /*!< 0x10 */
    __IO uint32_t DMA_RSVD;                    /*!< 0x14 */
    __IO uint32_t DMA_CTLx_L;                  /*!< 0x18 */
    __IO uint32_t DMA_CTLx_H;                  /*!< 0x1C */
    __IO uint32_t DMA_BLK_COUNTER_REGx;        /*!< 0x20 */
    __IO uint32_t DMA_RSVD1[7];                /*!< 0x24 ~ 0x3C */
    __IO uint32_t DMA_CFGx_L;                  /*!< 0x40 */
    __IO uint32_t DMA_CFGx_H;                  /*!< 0x44 */
    __IO uint32_t DMA_RSVD2;                   /*!< 0x48 */
    __IO uint32_t DMA_RSVD3;                   /*!< 0x4C */
    __IO uint32_t DMA_RSVD4;                   /*!< 0x50 */
    __IO uint32_t DMA_RSVD5;                   /*!< 0x54 */
} DMA_ChannelTypeDef;

typedef struct
{
    __IO uint32_t DMA_RSVD[10];                /*!< 0x2C0 - 0x2E4 */

    __I  uint32_t DMA_STATUSTFR_L;             /*!< 0x2E8 */
    __I  uint32_t DMA_STATUSTFR_H;             /*!< 0x2EC */
    __I  uint32_t DMA_STATUSBLOCK_L;           /*!< 0x2F0 */
    __I  uint32_t DMA_RSVD2;                   /*!< 0x2F4 */
    __I  uint32_t DMA_RSVD3;                   /*!< 0x2F8 */
    __I  uint32_t DMA_RSVD4;                   /*!< 0x2FC */
    __I  uint32_t DMA_RSVD5;                   /*!< 0x230 */
    __I  uint32_t DMA_RSVD6;                   /*!< 0x234 */
    __I  uint32_t DMA_STATUSERR_L;             /*!< 0x308 */
    __I  uint32_t DMA_RSVD7;                   /*!< 0x30C */

    __IO uint32_t DMA_MASKTFR_L;               /*!< 0x310 */
    __IO uint32_t DMA_MASKTFR_H;               /*!< 0x314 */
    __IO uint32_t DMA_MASKBLOCK_L;             /*!< 0x318 */
    __IO uint32_t DMA_RSVD8;                   /*!< 0x31C */
    __IO uint32_t DMA_RSVD9;                   /*!< 0x320 */
    __IO uint32_t DMA_RSVD10;                  /*!< 0x324 */
    __IO uint32_t DMA_RSVD11;                  /*!< 0x328 */
    __IO uint32_t DMA_RSVD12;                  /*!< 0x32C */
    __IO uint32_t DMA_MASKERR_L;               /*!< 0x330 */
    __IO uint32_t DMA_RSVD13;                  /*!< 0x334 */

    __O  uint32_t DMA_CLEARTFR_L;              /*!< 0x338 */
    __O  uint32_t DMA_CLEARTFR_H;              /*!< 0x33C */
    __O  uint32_t DMA_CLEARBLOCK_L;            /*!< 0x340 */
    __O  uint32_t DMA_RSVD14;                  /*!< 0x344 */
    __O  uint32_t DMA_RSVD15;                  /*!< 0x348 */
    __O  uint32_t DMA_RSVD16;                  /*!< 0x34C */
    __O  uint32_t DMA_RSVD17;                  /*!< 0x350 */
    __O  uint32_t DMA_RSVD18;                  /*!< 0x354 */
    __O  uint32_t DMA_CLEARERR_L;              /*!< 0x358 */
    __O  uint32_t DMA_RSVD19;                  /*!< 0x35C */

    __IO uint32_t DMA_RSVD20[14];              /*!< 0x360 ~ 0x394 */

    __IO uint32_t DMA_DMACFGREG_L;              /*!< 0x398 */
    __IO uint32_t DMA_RSVD21;                   /*!< 0x39C */
    __IO uint32_t DMA_CHENREG_L;                /*!< 0x3A0 */
    __IO uint32_t DMA_RSVD22;                   /*!< 0x3A4 */

    __IO uint32_t DMA_RSVD23[6];                /*!< 0x3A8 ~ 0x3BC */
} DMA_TypeDef;

/*============================================================================*
 *                         DMA Declaration
 *============================================================================*/
/** \defgroup DMA        DMA
  * \brief
  * \{
  */

/** \defgroup DMA_Exported_Constants DMA Exported Constants
  * \brief
  * \{
  */

/** \defgroup DMA_Declaration DMA Declaration
  * \brief
  * \{
  */

#define DMA_CH_REG_BASE             (RXI350_CFG_BASE)
#define DMA_REG_BASE                (DMA_CH_REG_BASE + 0x02C0)
#define DMA_CH0_BASE                (DMA_CH_REG_BASE + 0x0000)
#define DMA_CH1_BASE                (DMA_CH_REG_BASE + 0x0058)
#define DMA_CH2_BASE                (DMA_CH_REG_BASE + 0x00B0)
#define DMA_CH3_BASE                (DMA_CH_REG_BASE + 0x0108)
#define DMA_CH4_BASE                (DMA_CH_REG_BASE + 0x0160)
#define DMA_CH5_BASE                (DMA_CH_REG_BASE + 0x01B8)

#define DMA                         ((DMA_TypeDef        *) DMA_REG_BASE)
#define DMA_CH0                     ((DMA_ChannelTypeDef *) DMA_CH0_BASE)
#define DMA_CH1                     ((DMA_ChannelTypeDef *) DMA_CH1_BASE)
#define DMA_CH2                     ((DMA_ChannelTypeDef *) DMA_CH2_BASE)
#define DMA_CH3                     ((DMA_ChannelTypeDef *) DMA_CH3_BASE)
#define DMA_CH4                     ((DMA_ChannelTypeDef *) DMA_CH4_BASE)
#define DMA_CH5                     ((DMA_ChannelTypeDef *) DMA_CH5_BASE)

#define IS_DMA_PERIPH(PERIPH)       (((PERIPH) == DMA_CH0) || \
                                     ((PERIPH) == DMA_CH1) || \
                                     ((PERIPH) == DMA_CH2) || \
                                     ((PERIPH) == DMA_CH3) || \
                                     ((PERIPH) == DMA_CH4) || \
                                     ((PERIPH) == DMA_CH5))
#define IS_DMA_ALL_PERIPH(PERIPH)   (IS_DMA1_PERIPH(PERIPH))

/** End of DMA_Declaration
  * \}
  */

/** End of DMA_Exported_Constants
  * \}
  */

/** End of DMA
  * \}
  */


/*============================================================================*
 *                         DMA Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    sar                 0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sar: 32;
    } b;
} DMA_SARx_TypeDef;


/* 0x04
   31:0    R      curr_sar            0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t curr_sar: 32;
    } b;
} DMA_CURR_SARx_TypeDef;


/* 0x08
   31:0    R/W    dar                 0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dar: 32;
    } b;
} DMA_DARx_TypeDef;


/* 0x0C
   31:0    R      curr_dar            0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t curr_dar: 32;
    } b;
} DMA_CURR_DARx_TypeDef;


/* 0x10
   1:0     R/W    reserved14          0x0
   31:2    R/W    loc                 0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reserved_0: 2;
        uint32_t loc: 30;
    } b;
} DMA_LLPx_L_TypeDef;


/* 0x18
   0       R/W    int_en              0x1
   3:1     R/W    dst_tr_width        0x0
   6:4     R/W    src_tr_width        0x0
   8:7     R/W    dinc                0x0
   10:9    R/W    sinc                0x0
   13:11   R/W    dest_msize          0x1
   16:14   R/W    src_msize           0x1
   17      R/W    reserved25          0x0
   18      R/W    reserved24          0x0
   19      R/W    reserved23          0x0
   23:20   R/W    tt_fc               0x0
   26:24   R      reserved21          0x0
   27      R/W    llp_dst_en          0x0
   28      R/W    llp_src_en          0x0
   31:29   R      reserved18          0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t int_en: 1;
        uint32_t dst_tr_width: 3;
        uint32_t src_tr_width: 3;
        uint32_t dinc: 2;
        uint32_t sinc: 2;
        uint32_t dest_msize: 3;
        uint32_t src_msize: 3;
        uint32_t reserved_4: 1;
        uint32_t reserved_3: 1;
        uint32_t reserved_2: 1;
        uint32_t tt_fc: 4;
        const uint32_t reserved_1: 3;
        uint32_t llp_dst_en: 1;
        uint32_t llp_src_en: 1;
        const uint32_t reserved_0: 3;
    } b;
} DMA_CTLx_L_TypeDef;


/* 0x1C
   31:0    R      trans_data_cnt          0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t trans_data_cnt: 32;
    } b;
} DMA_CTLx_H_R_TypeDef;


/* 0x1C
   15:0    W      block_ts                0x2
   31:16   W      reserved31              0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t block_ts: 16;
        uint32_t reserved31: 16;
    } b;
} DMA_CTLx_H_W_TypeDef;


/* 0x20
   15:0    R/W    blk_counter_reg     0x0
   31:16   R      reserved37          0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t blk_counter_reg: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_BLK_COUNTER_REGx_TypeDef;


/* 0x40
   0       R      inactive            0x1
   1       R      src_pctl_over       0x1
   2       R      dst_pctl_over       0x1
   3       R      reserved53          0x0
   7:4     R/W    ch_prior            0x0
   8       R/W    ch_susp             0x0
   9       R      fifo_empty          0x1
   10      R/W    hs_sel_dst          0x1
   11      R/W    hs_sel_src          0x1
   17:12   R      reserved47          0x0
   18      R      dst_hs_pol          0x0
   19      R      src_hs_pol          0x0
   29:20   R      reserved44          0x0
   30      R/W    reload_src          0x0
   31      R/W    reload_dst          0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t inactive: 1;
        const uint32_t src_pctl_over: 1;
        const uint32_t dst_pctl_over: 1;
        const uint32_t reserved_2: 1;
        uint32_t ch_prior: 4;
        uint32_t ch_susp: 1;
        const uint32_t fifo_empty: 1;
        uint32_t hs_sel_dst: 1;
        uint32_t hs_sel_src: 1;
        const uint32_t reserved_1: 6;
        const uint32_t dst_hs_pol: 1;
        const uint32_t src_hs_pol: 1;
        const uint32_t reserved_0: 10;
        uint32_t reload_src: 1;
        uint32_t reload_dst: 1;
    } b;
} DMA_CFGx_L_TypeDef;


/* 0x44
   0       R/W    fcmode              0x0
   1       R/W    reserved72          0x0
   2       R      reserved71          0x0
   3       R/W    reserved70          0x1
   4       R/W    direct_ctl_en       0x0
   5       R/W    cont_sar            0x0
   6       R/W    cont_dar            0x0
   10:7    R/W    src_per             0x0
   14:11   R/W    dest_per            0x0
   15      R/W    extended_src_per1   0x0
   16      R/W    extended_dest_per1  0x0
   17      R/W    extended_src_per2   0x0
   18      R/W    extended_dest_per2  0x0
   19      R/W    extended_src_per3   0x0
   20      R/W    extended_dest_per3  0x0
   31:21   R      reserved58          0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t fcmode: 1;
        uint32_t reserved_5: 1;
        const uint32_t reserved_4: 1;
        uint32_t reserved_3: 1;
        uint32_t direct_ctl_en: 1;
        uint32_t cont_sar: 1;
        uint32_t cont_dar: 1;
        uint32_t src_per: 4;
        uint32_t dest_per: 4;
        uint32_t extended_src_per1: 1;
        uint32_t extended_dest_per1: 1;
        uint32_t extended_src_per2: 1;
        uint32_t extended_dest_per2: 1;
        uint32_t extended_src_per3: 1;
        uint32_t extended_dest_per3: 1;
        const uint32_t reserved_0: 11;
    } b;
} DMA_CFGx_H_TypeDef;


/* 0x2E8
   15:0    R      status_tfr          0x0
   31:16   R      reserved108         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t status_tfr: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_STATUSTFR_L_TypeDef;


/* 0x2EC
   15:0    R      status_tfr_h        0x0
   31:16   R      reserved111         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t status_tfr_h: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_STATUSTFR_H_TypeDef;


/* 0x2F0
   15:0    R      status_block        0x0
   31:16   R      reserved114         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t status_block: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_STATUSBLOCK_L_TypeDef;


/* 0x308
   15:0    R      status_err          0x0
   31:16   R      reserved120         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t status_err: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_STATUSERR_L_TypeDef;


/* 0x310
   7:0     R/W    int_mask            0x0
   15:8    W      int_mask_we         0x0
   23:16   R/W    int_mask            0x0
   31:24   W      int_mask_we         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t int_mask_2: 8;
        uint32_t int_mask_we_2: 8;
        uint32_t int_mask: 8;
        uint32_t int_mask_we: 8;
    } b;
} DMA_MASKTFR_L_TypeDef;


/* 0x314
   7:0     R/W    int_mask            0x0
   15:8    W      int_mask_we         0x0
   23:16   R/W    int_mask            0x0
   31:24   W      int_mask_we         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t int_mask_2: 8;
        uint32_t int_mask_we_2: 8;
        uint32_t int_mask: 8;
        uint32_t int_mask_we: 8;
    } b;
} DMA_MASKTFR_H_TypeDef;


/* 0x318
   7:0     R/W    int_mask            0x0
   15:8    W      int_mask_we         0x0
   23:16   R/W    int_mask            0x0
   31:24   W      int_mask_we         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t int_mask_2: 8;
        uint32_t int_mask_we_2: 8;
        uint32_t int_mask: 8;
        uint32_t int_mask_we: 8;
    } b;
} DMA_MASKBLOCK_L_TypeDef;


/* 0x330
   7:0     R/W    int_mask            0x0
   15:8    W      int_mask_we         0x0
   23:16   R/W    int_mask            0x0
   31:24   W      int_mask_we         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t int_mask_2: 8;
        uint32_t int_mask_we_2: 8;
        uint32_t int_mask: 8;
        uint32_t int_mask_we: 8;
    } b;
} DMA_MASKERR_L_TypeDef;


/* 0x338
   15:0    W1C    clear_tfr           0x0
   31:16   R      reserved156         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t clear_tfr: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_CLEARTFR_L_TypeDef;


/* 0x33C
   15:0    W1C    clear_tfr_h         0x0
   31:16   R      reserved159         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t clear_tfr_h: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_CLEARTFR_H_TypeDef;


/* 0x340
   15:0    W1C    clear_block         0x0
   31:16   R      reserved162         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t clear_block: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_CLEARBLOCK_L_TypeDef;


/* 0x358
   15:0    W1C    clear_protocolerror 0x0
   31:16   R      reserved168         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t clear_protocolerror: 16;
        const uint32_t reserved_0: 16;
    } b;
} DMA_CLEARERR_L_TypeDef;


/* 0x398
   0       R/W    dma_en              0x1
   31:1    R      reserved184         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dma_en: 1;
        const uint32_t reserved_0: 31;
    } b;
} DMA_DMACFGREG_L_TypeDef;


/* 0x3A0
   5:0     R/W    ch_en               0x0
   7:6     R      reserved191         0x0
   13:8    W      ch_en_we            0x0
   31:14   R      reserved189         0x0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t ch_en: 6;
        const uint32_t reserved_1: 2;
        uint32_t ch_en_we: 6;
        const uint32_t reserved_0: 18;
    } b;
} DMA_CHENREG_L_TypeDef;


/*============================================================================*
 *                         DMA Constants
 *============================================================================*/
/** \defgroup DMA        DMA
  * \brief
  * \{
  */

/** \defgroup DMA_Exported_Constants DMA Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    DMA_HANDSHAKE DMA HANDSHAKE
 * \{
 * \ingroup     DMA_Exported_Constants
 */
#define DMA_HANDSHAKE_UART0_TX                                    (0)
#define DMA_HANDSHAKE_UART0_RX                                    (1)
#define DMA_HANDSHAKE_UART1_TX                                    (2)
#define DMA_HANDSHAKE_UART1_RX                                    (3)
#define DMA_HANDSHAKE_SPI0_TX                                     (4)
#define DMA_HANDSHAKE_SPI0_RX                                     (5)
#define DMA_HANDSHAKE_SPI1_TX                                     (6)
#define DMA_HANDSHAKE_SPI1_RX                                     (7)
#define DMA_HANDSHAKE_I2C0_TX                                     (8)
#define DMA_HANDSHAKE_I2C0_RX                                     (9)
#define DMA_HANDSHAKE_I2C1_TX                                     (10)
#define DMA_HANDSHAKE_I2C1_RX                                     (11)
#define DMA_HANDSHAKE_ADC_RX                                      (12)
#define DMA_HANDSHAKE_AES_TX                                      (13)
#define DMA_HANDSHAKE_AES_RX                                      (14)
#define DMA_HANDSHAKE_SPIC0_TX                                    (15)
#define DMA_HANDSHAKE_I2S0_TX                                     (16)
#define DMA_HANDSHAKE_I2S0_RX                                     (17)
#define DMA_HANDSHAKE_UART2_TX                                    (18)
#define DMA_HANDSHAKE_UART2_RX                                    (19)
#define DMA_HANDSHAKE_UART3_TX                                    (20)
#define DMA_HANDSHAKE_UART3_RX                                    (21)
#define DMA_HANDSHAKE_SPIC0_RX                                    (22)
#define DMA_HANDSHAKE_TIMER2_TRX                                  (23)
#define DMA_HANDSHAKE_SPI2_TX                                     (24)
#define DMA_HANDSHAKE_SPI2_RX                                     (25)
#define DMA_HANDSHAKE_IR_TX                                       (27)
#define DMA_HANDSHAKE_IR_RX                                       (28)
#define DMA_HANDSHAKE_CANBUS_RX                                   (29)
#define DMA_HANDSHAKE_SHA256_TX                                   (30)
#define DMA_HANDSHAKE_TIMER1_6_TRX                                (31)
#define DMA_HANDSHAKE_TIMER1_7_TRX                                (32)
#define DMA_HANDSHAKE_TIMER1_8_TRX                                (33)


#define IS_DMA_TransferType(Type) (((Type) == DMA_HANDSHAKE_UART0_TX) || \
                                   ((Type) == DMA_HANDSHAKE_UART0_RX) || \
                                   ((Type) == DMA_HANDSHAKE_UART1_TX) || \
                                   ((Type) == DMA_HANDSHAKE_UART1_RX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI0_TX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI0_RX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI1_TX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI1_RX) || \
                                   ((Type) == DMA_HANDSHAKE_I2C0_TX) || \
                                   ((Type) == DMA_HANDSHAKE_I2C0_RX) || \
                                   ((Type) == DMA_HANDSHAKE_I2C1_TX) || \
                                   ((Type) == DMA_HANDSHAKE_I2C1_RX) || \
                                   ((Type) == DMA_HANDSHAKE_ADC_RX) || \
                                   ((Type) == DMA_HANDSHAKE_AES_TX) || \
                                   ((Type) == DMA_HANDSHAKE_AES_RX) || \
                                   ((Type) == DMA_HANDSHAKE_SPIC0_TX) || \
                                   ((Type) == DMA_HANDSHAKE_I2S0_TX) || \
                                   ((Type) == DMA_HANDSHAKE_I2S0_RX) || \
                                   ((Type) == DMA_HANDSHAKE_UART2_TX) || \
                                   ((Type) == DMA_HANDSHAKE_UART2_RX) || \
                                   ((Type) == DMA_HANDSHAKE_UART3_TX) || \
                                   ((Type) == DMA_HANDSHAKE_UART3_RX) || \
                                   ((Type) == DMA_HANDSHAKE_SPIC0_RX) || \
                                   ((Type) == DMA_HANDSHAKE_TIMER2_TRX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI2_TX) || \
                                   ((Type) == DMA_HANDSHAKE_SPI2_RX) || \
                                   ((Type) == DMA_HANDSHAKE_IR_TX) || \
                                   ((Type) == DMA_HANDSHAKE_IR_RX) || \
                                   ((Type) == DMA_HANDSHAKE_CAN_RX) || \
                                   ((Type) == DMA_HANDSHAKE_SHA256_TX) || \
                                   ((Type) == DMA_HANDSHAKE_TIMER1_6_TRX) || \
                                   ((Type) == DMA_HANDSHAKE_TIMER1_7_TRX) || \
                                   ((Type) == DMA_HANDSHAKE_TIMER1_8_TRX))


/** End of DMA_HANDSHAKE
  * \}
  */

/** End of DMA_Exported_Constants
  * \}
  */

/** End of DMA
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_DMA_DEF_H */

