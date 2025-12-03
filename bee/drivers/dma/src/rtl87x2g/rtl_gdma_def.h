/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_gdma_def.h
* \brief    GDMA related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_GDMA_DEF_H
#define RTL_GDMA_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         GDMA Defines
 *============================================================================*/
/** \defgroup GDMA        GDMA
  * \brief
  * \{
  */

/** \defgroup GDMA_Exported_Constants GDMA Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup GDMA_Defines GDMA Defines
 * \{
 * \ingroup  GDMA_Exported_Constants
 */
#define CHIP_GDMA_CHANNEL_NUM                        (10)

#define GDMA_SUPPORT_GATHER_SCATTER_FUNCTION         (0)
#define GDMA_SUPPORT_INT_HAIF_BLOCK                  (0)
#define GDMA_SUPPORT_SECURE_MODE                     (1)
#define GDMA_SUPPORT_ADDRESS_DEC                     (1)
#define GDMA_SUPPORT_OSW_OSR_CHANGE                  (1)

/** End of GDMA_Defines
  * \}
  */

/** End of GDMA_Exported_Constants
  * \}
  */

/** End of GDMA
  * \}
  */

/*============================================================================*
 *                         GDMA Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t GDMA_SARx;                    /*!< 0x00 */
    __I  uint32_t GDMA_CURR_SARx;               /*!< 0x04 */
    __IO uint32_t GDMA_DARx;                    /*!< 0x08 */
    __I  uint32_t GDMA_CURR_DARx;               /*!< 0x0C */
    __IO uint32_t GDMA_LLPx_L;                  /*!< 0x10 */
    __IO uint32_t GDMA_RSVD;                    /*!< 0x14 */
    __IO uint32_t GDMA_CTLx_L;                  /*!< 0x18 */
    __IO uint32_t GDMA_CTLx_H;                  /*!< 0x1C */
    __IO uint32_t GDMA_RSVD1[8];                /*!< 0x20 ~ 0x3C */
    __IO uint32_t GDMA_CFGx_L;                  /*!< 0x40 */
    __IO uint32_t GDMA_CFGx_H;                  /*!< 0x44 */
    __IO uint32_t GDMA_RSVD2;                   /*!< 0x48 */
    __IO uint32_t GDMA_RSVD3;                   /*!< 0x4C */
    __IO uint32_t GDMA_RSVD4;                   /*!< 0x50 */
    __IO uint32_t GDMA_RSVD5;                   /*!< 0x54 */
} GDMA_ChannelTypeDef;

typedef struct
{
    __IO uint32_t GDMA_RSVD[10];                /*!< 0x2C0 - 0x2E4 */

    __I  uint32_t GDMA_STATUSTFR_L;             /*!< 0x2E8 */
    __I  uint32_t GDMA_RSVD1;                   /*!< 0x2EC */
    __I  uint32_t GDMA_STATUSBLOCK_L;           /*!< 0x2F0 */
    __I  uint32_t GDMA_RSVD2;                   /*!< 0x2F4 */
    __I  uint32_t GDMA_RSVD3;                   /*!< 0x2F8 */
    __I  uint32_t GDMA_RSVD4;                   /*!< 0x2FC */
    __I  uint32_t GDMA_RSVD5;                   /*!< 0x230 */
    __I  uint32_t GDMA_RSVD6;                   /*!< 0x234 */
    __I  uint32_t GDMA_STATUSERR_L;             /*!< 0x308 */
    __I  uint32_t GDMA_RSVD7;                   /*!< 0x30C */

    __IO uint32_t GDMA_MASKTFR_L;               /*!< 0x310 */
    __IO uint32_t GDMA_RSVD8;                   /*!< 0x314 */
    __IO uint32_t GDMA_MASKBLOCK_L;             /*!< 0x318 */
    __IO uint32_t GDMA_RSVD9;                   /*!< 0x31C */
    __IO uint32_t GDMA_RSVD10;                  /*!< 0x320 */
    __IO uint32_t GDMA_RSVD11;                  /*!< 0x324 */
    __IO uint32_t GDMA_RSVD12;                  /*!< 0x328 */
    __IO uint32_t GDMA_RSVD13;                  /*!< 0x32C */
    __IO uint32_t GDMA_MASKERR_L;               /*!< 0x330 */
    __IO uint32_t GDMA_RSVD14;                  /*!< 0x32C */

    __O  uint32_t GDMA_CLEARTFR_L;              /*!< 0x338 */
    __O  uint32_t GDMA_RSVD15;                  /*!< 0x32C */
    __O  uint32_t GDMA_CLEARBLOCK_L;            /*!< 0x340 */
    __O  uint32_t GDMA_RSVD16;                  /*!< 0x344 */
    __O  uint32_t GDMA_RSVD17;                  /*!< 0x348 */
    __O  uint32_t GDMA_RSVD18;                  /*!< 0x34C */
    __O  uint32_t GDMA_RSVD19;                  /*!< 0x350 */
    __O  uint32_t GDMA_RSVD20;                  /*!< 0x354 */
    __O  uint32_t GDMA_CLEARERR_L;              /*!< 0x358 */
    __O  uint32_t GDMA_RSVD21;                  /*!< 0x354 */

    __IO uint32_t GDMA_RSVD22[14];              /*!< 0x360 ~ 0x394 */

    __IO uint32_t GDMA_DMACFGREG_L;             /*!< 0x398 */
    __IO uint32_t GDMA_RSVD23;                  /*!< 0x39C */
    __IO uint32_t GDMA_CHENREG_L;               /*!< 0x3A0 */
    __IO uint32_t GDMA_RSVD24;                  /*!< 0x3A4 */

    __IO uint32_t GDMA_RSVD25[4];               /*!< 0x3A8 ~ 0x3B4 */

    __IO uint32_t GDMA_DMAOSNUM_L;              /*!< 0x3B8 */
} GDMA_TypeDef;

/*============================================================================*
 *                         GDMA Declaration
 *============================================================================*/
/** \defgroup GDMA        GDMA
  * \brief
  * \{
  */

/** \defgroup GDMA_Exported_Constants GDMA Exported Constants
  * \brief
  * \{
  */

/** \defgroup GDMA_Declaration GDMA Declaration
  * \brief
  * \{
  */

#define GDMA0_CHANNEL_REG_BASE      (RXI350_DMAC0_CFG_REG_BASE)
#define GDMA0_Channel0_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0000)
#define GDMA0_Channel1_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0058)
#define GDMA0_Channel2_BASE         (GDMA0_CHANNEL_REG_BASE + 0x00b0)
#define GDMA0_Channel3_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0108)
#define GDMA0_Channel4_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0160)
#define GDMA0_Channel5_BASE         (GDMA0_CHANNEL_REG_BASE + 0x01b8)
#define GDMA0_Channel6_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0210)
#define GDMA0_Channel7_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0268)
#define GDMA0_Channel8_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0400)
#define GDMA0_Channel9_BASE         (GDMA0_CHANNEL_REG_BASE + 0x0458)
#define GDMA0_REG_BASE              (GDMA0_CHANNEL_REG_BASE + 0x02c0)

#define GDMA0                       ((GDMA_TypeDef        *) GDMA0_REG_BASE)
#define GDMA_Channel0               ((GDMA_ChannelTypeDef *) GDMA0_Channel0_BASE)
#define GDMA_Channel1               ((GDMA_ChannelTypeDef *) GDMA0_Channel1_BASE)
#define GDMA_Channel2               ((GDMA_ChannelTypeDef *) GDMA0_Channel2_BASE)
#define GDMA_Channel3               ((GDMA_ChannelTypeDef *) GDMA0_Channel3_BASE)
#define GDMA_Channel4               ((GDMA_ChannelTypeDef *) GDMA0_Channel4_BASE)
#define GDMA_Channel5               ((GDMA_ChannelTypeDef *) GDMA0_Channel5_BASE)
#define GDMA_Channel6               ((GDMA_ChannelTypeDef *) GDMA0_Channel6_BASE)
#define GDMA_Channel7               ((GDMA_ChannelTypeDef *) GDMA0_Channel7_BASE)
#define GDMA_Channel8               ((GDMA_ChannelTypeDef *) GDMA0_Channel8_BASE)
#define GDMA_Channel9               ((GDMA_ChannelTypeDef *) GDMA0_Channel9_BASE)

#define IS_GDMA_PERIPH(PERIPH)      (((PERIPH) == GDMA_Channel0) || \
                                     ((PERIPH) == GDMA_Channel1) || \
                                     ((PERIPH) == GDMA_Channel2) || \
                                     ((PERIPH) == GDMA_Channel3) || \
                                     ((PERIPH) == GDMA_Channel4) || \
                                     ((PERIPH) == GDMA_Channel5) || \
                                     ((PERIPH) == GDMA_Channel6) || \
                                     ((PERIPH) == GDMA_Channel7) || \
                                     ((PERIPH) == GDMA_Channel8) || \
                                     ((PERIPH) == GDMA_Channel9))

#define IS_GDMA_ALL_PERIPH(PERIPH)  (IS_GDMA_PERIPH(PERIPH))

/** End of GDMA_Declaration
  * \}
  */

/** End of GDMA_Exported_Constants
  * \}
  */

/** End of GDMA
  * \}
  */


/*============================================================================*
 *                         GDMA Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    sar                 undefined
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sar: 32;
    } b;
} GDMA_SARx_TypeDef;


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
    } GDMA_CURR_SARx_TypeDef;


    /* 0x08
       31:0    R/W    dar                 undefined
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t dar: 32;
            } b;
        } GDMA_DARx_TypeDef;


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
        } GDMA_CURR_DARx_TypeDef;


    /* 0x10
       1:0     R/W    reserved13          0x0
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
        } GDMA_LLPx_L_TypeDef;


    /* 0x18
       0       R/W    int_en              0x1
       3:1     R/W    dst_tr_width        0x0
       6:4     R/W    src_tr_width        0x0
       8:7     R/W    dinc                0x0
       10:9    R/W    sinc                0x0
       13:11   R/W    dest_msize          0x1
       16:14   R/W    src_msize           0x1
       17      R/W    reserved22          0x0
       18      R/W    reserved21          0x0
       19      R/W    reserved20          0x0
       22:20   R/W    tt_fc               0x0
       26:23   R      reserved18          0x0
       27      R/W    llp_dst_en          0x0
       28      R/W    llp_src_en          0x0
       31:29   R      reserved15          0x0
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
                uint32_t tt_fc: 3;
                const uint32_t reserved_1: 4;
                uint32_t llp_dst_en: 1;
                uint32_t llp_src_en: 1;
                const uint32_t reserved_0: 3;
            } b;
        } GDMA_CTLx_L_TypeDef;



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
        } GDMA_CTLx_H_R_TypeDef;


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
        } GDMA_CTLx_H_W_TypeDef;


    /* 0x40
       0       R      inactive            0x1
       1       R      reserved47          0x1
       2       R      reserved46          0x1
       3       R      reserved45          0x0
       7:4     R/W    ch_prior            0x0
       8       R/W    ch_susp             0x0
       9       R      fifo_empty          0x1
       10      R/W    hs_sel_dst          0x1
       11      R/W    hs_sel_src          0x1
       17:12   R      reserved39          0x0
       18      R/W    reserved38          0x0
       19      R/W    reserved37          0x0
       29:20   R/W    reserved36          0x0
       30      R/W    reload_src          0x0
       31      R/W    reload_dst          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t inactive: 1;
                const uint32_t reserved_6: 1;
                const uint32_t reserved_5: 1;
                const uint32_t reserved_4: 1;
                uint32_t ch_prior: 4;
                uint32_t ch_susp: 1;
                const uint32_t fifo_empty: 1;
                uint32_t hs_sel_dst: 1;
                uint32_t hs_sel_src: 1;
                const uint32_t reserved_3: 6;
                uint32_t reserved_2: 1;
                uint32_t reserved_1: 1;
                uint32_t reserved_0: 10;
                uint32_t reload_src: 1;
                uint32_t reload_dst: 1;
            } b;
        } GDMA_CFGx_L_TypeDef;


    /* 0x44
       0       R/W    reserved63          0x0
       1       R/W    reserved62          0x0
       2       R      reserved61          0x0
       3       R/W    protctl             0x1
       6:4     R      reserved59          0x0
       10:7    R/W    src_per             0x0
       14:11   R/W    dest_per            0x0
       15      R/W    extended_src_per1   0x0
       16      R/W    extended_dest_per1  0x0
       17      R/W    extended_src_per2   0x0
       18      R/W    extended_dest_per2  0x0
       19      R/W    extended_src_per3   0x0
       20      R/W    extended_dest_per3  0x0
       31:21   R/W    reserved50          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t reserved_4: 1;
                uint32_t reserved_3: 1;
                const uint32_t reserved_2: 1;
                uint32_t protctl: 1;
                const uint32_t reserved_1: 3;
                uint32_t src_per: 4;
                uint32_t dest_per: 4;
                uint32_t extended_src_per1: 1;
                uint32_t extended_dest_per1: 1;
                uint32_t extended_src_per2: 1;
                uint32_t extended_dest_per2: 1;
                uint32_t extended_src_per3: 1;
                uint32_t extended_dest_per3: 1;
                uint32_t reserved_0: 11;
            } b;
        } GDMA_CFGx_H_TypeDef;


    /* 0x2E8
       31:0    R      status              0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t status: 32;
            } b;
        } GDMA_STATUSTFR_L_TypeDef;


    /* 0x2F0
       31:0    R      status              0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t status: 32;
            } b;
        } GDMA_STATUSBLOCK_L_TypeDef;


    /* 0x308
       31:0    R      status              0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                const uint32_t status: 32;
            } b;
        } GDMA_STATUSERR_L_TypeDef;


    /* 0x310
       7:0     R/W    int_mask_l          0x0
       15:8    W      int_mask_we_l       0x0
       17:16   R/W    int_mask_h          0x0
       23:18   R/W    reserved71          0x0
       25:24   W      int_mask_we_h       0x0
       31:26   R      reserved69          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t int_mask_l: 8;
                uint32_t int_mask_we_l: 8;
                uint32_t int_mask_h: 2;
                uint32_t reserved_1: 6;
                uint32_t int_mask_we_h: 2;
                const uint32_t reserved_0: 6;
            } b;
        } GDMA_MASKTFR_L_TypeDef;


    /* 0x318
       7:0     R/W    int_mask_l          0x0
       15:8    W      int_mask_we_l       0x0
       17:16   R/W    int_mask_h          0x0
       23:18   R/W    reserved78          0x0
       25:24   W      int_mask_we_h       0x0
       31:26   R      reserved76          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t int_mask_l: 8;
                uint32_t int_mask_we_l: 8;
                uint32_t int_mask_h: 2;
                uint32_t reserved_1: 6;
                uint32_t int_mask_we_h: 2;
                const uint32_t reserved_0: 6;
            } b;
        } GDMA_MASKBLOCK_L_TypeDef;


    /* 0x330
       7:0     R/W    int_mask_l          0x0
       15:8    W      int_mask_we_l       0x0
       17:16   R/W    int_mask_h          0x0
       23:18   R/W    reserved85          0x0
       25:24   W      int_mask_we_h       0x0
       31:26   R      reserved83          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t int_mask_l: 8;
                uint32_t int_mask_we_l: 8;
                uint32_t int_mask_h: 2;
                uint32_t reserved_1: 6;
                uint32_t int_mask_we_h: 2;
                const uint32_t reserved_0: 6;
            } b;
        } GDMA_MASKERR_L_TypeDef;


    /* 0x338
       31:0    W      clear               0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t clear: 32;
            } b;
        } GDMA_CLEARTFR_L_TypeDef;


    /* 0x340
       31:0    W      clear               0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t clear: 32;
            } b;
        } GDMA_CLEARBLOCK_L_TypeDef;


    /* 0x358
       31:0    W      clear               0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t clear: 32;
            } b;
        } GDMA_CLEARERR_L_TypeDef;


    /* 0x398
       0       R/W    dmac_en             0x0
       31:1    R      reserved96          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t dmac_en: 1;
                const uint32_t reserved_0: 31;
            } b;
        } GDMA_DMACFGREG_L_TypeDef;


    /* 0x3A0
       7:0     R/W    ch_en_l             0x0
       15:8    W      ch_en_we_l          0x0
       17:16   R/W    ch_en_h             0x0
       23:18   R/W    reserved101         0x0
       25:24   W      ch_en_we_h          0x0
       31:26   R/W    reserved99          0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t ch_en_l: 8;
                uint32_t ch_en_we_l: 8;
                uint32_t ch_en_h: 2;
                uint32_t reserved_1: 6;
                uint32_t ch_en_we_h: 2;
                uint32_t reserved_0: 6;
            } b;
        } GDMA_CHENREG_L_TypeDef;



    /* 0x3B8
       7:0     R/W    osr                 0x4
       15:8    R/W    osw                 0x4
       31:16   R      reserved106         0x0
    */
    typedef union
        {
            uint32_t d32;
            struct
            {
                uint32_t osr: 8;
                uint32_t osw: 8;
                const uint32_t reserved_0: 16;
            } b;
        } GDMA_DMAOSNUM_L_TypeDef;


    /*============================================================================*
     *                         GDMA Constants
     *============================================================================*/
    /** \defgroup GDMA        GDMA
      * \brief
      * \{
      */

    /** \defgroup GDMA_Exported_Constants GDMA Exported Constants
      * \brief
      * \{
      */

    /**
     * \defgroup GDMA_Channel_Type GDMA Channel Type
     * \{
     * \ingroup  GDMA_Exported_Constants
     */
#define GDMA_Channel0_IRQn              GDMA0_Channel0_IRQn
#define GDMA_Channel1_IRQn              GDMA0_Channel1_IRQn
#define GDMA_Channel2_IRQn              GDMA0_Channel2_IRQn
#define GDMA_Channel3_IRQn              GDMA0_Channel3_IRQn
#define GDMA_Channel4_IRQn              GDMA0_Channel4_IRQn
#define GDMA_Channel5_IRQn              GDMA0_Channel5_IRQn
#define GDMA_Channel6_IRQn              GDMA0_Channel6_IRQn
#define GDMA_Channel7_IRQn              GDMA0_Channel7_IRQn
#define GDMA_Channel8_IRQn              GDMA0_Channel8_IRQn
#define GDMA_Channel9_IRQn              GDMA0_Channel9_IRQn

#define GDMA_Channel0_Handler           GDMA0_Channel0_Handler
#define GDMA_Channel1_Handler           GDMA0_Channel1_Handler
#define GDMA_Channel2_Handler           GDMA0_Channel2_Handler
#define GDMA_Channel3_Handler           GDMA0_Channel3_Handler
#define GDMA_Channel4_Handler           GDMA0_Channel4_Handler
#define GDMA_Channel5_Handler           GDMA0_Channel5_Handler
#define GDMA_Channel6_Handler           GDMA0_Channel6_Handler
#define GDMA_Channel7_Handler           GDMA0_Channel7_Handler
#define GDMA_Channel8_Handler           GDMA0_Channel8_Handler
#define GDMA_Channel9_Handler           GDMA0_Channel9_Handler

    /** End of GDMA_Channel_Type
      * \}
      */

    /**
     * \defgroup    GDMA_Handshake_Type GDMA Handshake Type
     * \{
     * \ingroup     GDMA_Exported_Constants
     */
#define GDMA_Handshake_UART0_TX             (0)
#define GDMA_Handshake_UART0_RX             (1)
#define GDMA_Handshake_UART1_TX             (2)
#define GDMA_Handshake_UART1_RX             (3)
#define GDMA_Handshake_UART2_TX             (4)
#define GDMA_Handshake_UART2_RX             (5)
#define GDMA_Handshake_UART3_TX             (6)
#define GDMA_Handshake_UART3_RX             (7)
#define GDMA_Handshake_I2C0_TX              (8)
#define GDMA_Handshake_I2C0_RX              (9)
#define GDMA_Handshake_I2C1_TX              (10)
#define GDMA_Handshake_I2C1_RX              (11)
#define GDMA_Handshake_I2C2_TX              (12)
#define GDMA_Handshake_I2C2_RX              (13)
#define GDMA_Handshake_I2C3_TX              (14)
#define GDMA_Handshake_I2C3_RX              (15)
#define GDMA_Handshake_SPI0_TX              (16)
#define GDMA_Handshake_SPI0_RX              (17)
#define GDMA_Handshake_SPI1_TX              (18)
#define GDMA_Handshake_SPI1_RX              (19)
#define GDMA_Handshake_SPI_SLAVE_TX         (20)
#define GDMA_Handshake_SPI_SLAVE_RX         (21)
#define GDMA_Handshake_ENH_TIM0             (22)
#define GDMA_Handshake_ENH_TIM1             (23)
#define GDMA_Handshake_ENH_TIM2             (24)
#define GDMA_Handshake_ENH_TIM3             (25)
#define GDMA_Handshake_ADC_RX               (26)
#define GDMA_Handshake_IDU_RX               (27)
#define GDMA_Handshake_IDU_TX               (28)
#define GDMA_Handshake_TIM5                 (29)
#define GDMA_Handshake_TIM6                 (30)
#define GDMA_Handshake_TIM7                 (31)
#define GDMA_Handshake_CAN_BUS_RX           (32)
#define GDMA_Handshake_SPIC0_TX             (33)
#define GDMA_Handshake_SPIC0_RX             (34)
#define GDMA_Handshake_SPIC1_TX             (35)
#define GDMA_Handshake_SPIC1_RX             (36)
#define GDMA_Handshake_SPIC2_TX             (37)
#define GDMA_Handshake_SPIC2_RX             (38)
#define GDMA_Handshake_IR_TX                (39)
#define GDMA_Handshake_IR_RX                (40)
#define GDMA_Handshake_I2S0_TDM0_TX         (41)
#define GDMA_Handshake_I2S0_TDM0_RX         (42)
#define GDMA_Handshake_I2S1_TDM0_TX         (43)
#define GDMA_Handshake_I2S1_TDM0_RX         (44)
#define GDMA_Handshake_SHA256_TX            (45)

#define GDMA_Handshake_AES_TX               (47)
#define GDMA_Handshake_AES_RX               (48)
#define GDMA_Handshake_PUB_KEY_TX           (49)
#define GDMA_Handshake_PUB_KEY_RX           (50)
#define GDMA_Handshake_24BIT_ADC_RX         (51)
#define GDMA_Handshake_UART4_TX             (52)
#define GDMA_Handshake_UART4_RX             (53)
#define GDMA_Handshake_UART5_TX             (54)
#define GDMA_Handshake_UART5_RX             (55)

#define IS_GDMA_TransferType(Type) (((Type) == GDMA_Handshake_UART0_TX)     || \
                                    ((Type) == GDMA_Handshake_UART0_RX)     || \
                                    ((Type) == GDMA_Handshake_UART1_TX)     || \
                                    ((Type) == GDMA_Handshake_UART1_RX)     || \
                                    ((Type) == GDMA_Handshake_UART2_TX)     || \
                                    ((Type) == GDMA_Handshake_UART2_RX)     || \
                                    ((Type) == GDMA_Handshake_UART3_TX)     || \
                                    ((Type) == GDMA_Handshake_UART3_RX)     || \
                                    ((Type) == GDMA_Handshake_I2C0_TX)      || \
                                    ((Type) == GDMA_Handshake_I2C0_RX)      || \
                                    ((Type) == GDMA_Handshake_I2C1_TX)      || \
                                    ((Type) == GDMA_Handshake_I2C1_RX)      || \
                                    ((Type) == GDMA_Handshake_I2C2_TX)      || \
                                    ((Type) == GDMA_Handshake_I2C2_RX)      || \
                                    ((Type) == GDMA_Handshake_I2C3_TX)      || \
                                    ((Type) == GDMA_Handshake_I2C3_RX)      || \
                                    ((Type) == GDMA_Handshake_SPI0_TX)      || \
                                    ((Type) == GDMA_Handshake_SPI0_RX)      || \
                                    ((Type) == GDMA_Handshake_SPI1_TX)      || \
                                    ((Type) == GDMA_Handshake_SPI1_RX)      || \
                                    ((Type) == GDMA_Handshake_SPI_SLAVE_TX) || \
                                    ((Type) == GDMA_Handshake_SPI_SLAVE_RX) || \
                                    ((Type) == GDMA_Handshake_ENH_TIM0)     || \
                                    ((Type) == GDMA_Handshake_ENH_TIM1)     || \
                                    ((Type) == GDMA_Handshake_ENH_TIM2)     || \
                                    ((Type) == GDMA_Handshake_ENH_TIM3)     || \
                                    ((Type) == GDMA_Handshake_ADC_RX)       || \
                                    ((Type) == GDMA_Handshake_IDMC_RX)      || \
                                    ((Type) == GDMA_Handshake_IDMC_TX)      || \
                                    ((Type) == GDMA_Handshake_TIM5)         || \
                                    ((Type) == GDMA_Handshake_TIM6)         || \
                                    ((Type) == GDMA_Handshake_TIM7)         || \
                                    ((Type) == GDMA_Handshake_CAN_BUS_RX)   || \
                                    ((Type) == GDMA_Handshake_SPIC0_TX)     || \
                                    ((Type) == GDMA_Handshake_SPIC0_RX)     || \
                                    ((Type) == GDMA_Handshake_SPIC1_TX)     || \
                                    ((Type) == GDMA_Handshake_SPIC1_RX)     || \
                                    ((Type) == GDMA_Handshake_SPIC2_TX)     || \
                                    ((Type) == GDMA_Handshake_SPIC2_RX)     || \
                                    ((Type) == GDMA_Handshake_IR_TX)        || \
                                    ((Type) == GDMA_Handshake_IR_RX)        || \
                                    ((Type) == GDMA_Handshake_I2S0_TDM0_TX) || \
                                    ((Type) == GDMA_Handshake_I2S0_TDM0_RX) || \
                                    ((Type) == GDMA_Handshake_I2S1_TDM0_TX) || \
                                    ((Type) == GDMA_Handshake_I2S1_TDM0_RX) || \
                                    ((Type) == GDMA_Handshake_SHA256_TX)    || \
                                    ((Type) == GDMA_Handshake_AES_TX)       || \
                                    ((Type) == GDMA_Handshake_AES_RX)       || \
                                    ((Type) == GDMA_Handshake_PUB_KEY_TX)   || \
                                    ((Type) == GDMA_Handshake_PUB_KEY_RX)   || \
                                    ((Type) == GDMA_Handshake_24BIT_ADC_RX) || \
                                    ((Type) == GDMA_Handshake_UART4_TX)     || \
                                    ((Type) == GDMA_Handshake_UART4_RX)     || \
                                    ((Type) == GDMA_Handshake_UART5_TX)     || \
                                    ((Type) == GDMA_Handshake_UART5_RX))

    /** End of GDMA_Handshake_Type
      * \}
      */

    /** End of GDMA_Exported_Constants
      * \}
      */

    /** End of GDMA
      * \}
      */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_GDMA_DEF_H */
