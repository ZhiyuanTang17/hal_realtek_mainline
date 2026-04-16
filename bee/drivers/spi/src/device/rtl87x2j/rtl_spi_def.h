/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_SPI_DEF_H
#define RTL_SPI_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "pcc_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/*============================================================================*
 *                          SPI Defines
 *============================================================================*/
/** \defgroup SPI         SPI
  * \brief
  * \{
  */

/** \defgroup SPI_Exported_Constants SPI Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup SPI_Defines SPI Defines
 * \{
 * \ingroup  SPI_Exported_Constants
 */
#define SPI_TX_FIFO_SIZE                               (16)
#define SPI_RX_FIFO_SIZE                               (16)
#define SPI0_SLAVE_TX_FIFO_SIZE                        (32)
#define SPI0_SLAVE_RX_FIFO_SIZE                        (32)
#define SPI_WRAPPER_TX_FIFO_SIZE                       (32)
#define SPI_SUPPORT_WRAP_MODE                          (1)
#define SPI0_SUPPORT_MASTER_SLAVE                      (1)
#define SPI0_SUPPORT_HS                                (1)
#define SPI1_SUPPORT_HS                                (1)
#define SPI2_SUPPORT_HS                                (0)
#define SPI_SUPPORT_APH_BRIDGE_FOR_HIGH_SPEED          (1)
#define SPI_SUPPORT_DFS_4BIT_TO_16BIT                  (1)
#define SPI_SUPPORT_SWAP                               (0)
#define SPI_SUPPORT_RAP_FUNCTION                       (1)
#define SPI_SUPPORT_CLOCK_SOURCE_CONFIG                (1)
#define SPI_SUPPORT_AUTO_CLOCK                         (1)

#define SPI_DFS_BIT_FIELD                              dfs
#define SPI_IN_SLAVE_MODE(SPIx)                       ((SPIx == SPI0) && (PCC_REG_READ_BITFIELD(PCC_REG_SPI0, PON_SPI0_MST) == 0))
/** End of SPI_Defines
  * \}
  */

/** End of SPI_Exported_Constants
  * \}
  */

/** End of SPI
  * \}
  */

/*============================================================================*
 *                         SPI Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t SPI_M_S_CTRL0;                /*!< 0x00 */
    __IO uint32_t SPI_M_CTRL1;                  /*!< 0x04 */
    __IO uint32_t SPI_SPIENR;                   /*!< 0x08 */
    __IO uint32_t RSVD_0C;                      /*!< 0x0C */
    __IO uint32_t SPI_M_SER;                    /*!< 0x10 */
    __IO uint32_t SPI_M_BAUDR;                  /*!< 0x14 */
    __IO uint32_t SPI_TXFTLR;                   /*!< 0x18 */
    __IO uint32_t SPI_RXFTLR;                   /*!< 0x1C */
    __I  uint32_t SPI_TXFLR;                    /*!< 0x20 */
    __I  uint32_t SPI_RXFLR;                    /*!< 0x24 */
    __I  uint32_t SPI_M_S_SR;                   /*!< 0x28 */
    __IO uint32_t SPI_M_S_IMR;                  /*!< 0x2C */
    __I  uint32_t SPI_M_S_ISR;                  /*!< 0x30 */
    __I  uint32_t SPI_M_S_RISR;                 /*!< 0x34 */
    __I  uint32_t SPI_TXOICR;                   /*!< 0x38 */
    __I  uint32_t SPI_RXOICR;                   /*!< 0x3C */
    __I  uint32_t SPI_RXUICR;                   /*!< 0x40 */
    __I  uint32_t SPI_M_S_MSTICR_FAEICR;        /*!< 0x44 */
    __I  uint32_t SPI_ICR;                      /*!< 0x48 */
    __IO uint32_t SPI_DMACR;                    /*!< 0x4C */
    __IO uint32_t SPI_DMATDLR;                  /*!< 0x50 */
    __IO uint32_t SPI_DMARDLR;                  /*!< 0x54 */
    __I  uint32_t SPI_M_S_IDR_TXUICR;           /*!< 0x58 */
    __I  uint32_t SPI_M_S_VERSION_ID_SSRICR;    /*!< 0x5C */
    __IO uint32_t SPI_DR[36];                   /*!< 0x60 - 0xEC */
    __IO uint32_t SPI_M_RSDR;                   /*!< 0xF0 */
    __IO uint32_t RSVD_F4[67];                  /*!< 0xF4 - 0x1FC */
    __IO uint32_t SPI_WRAP_CTRL;                /*!< 0x200 */
    __IO uint32_t SPI_WRAP_TXFTLR;              /*!< 0x204 */
    __I  uint32_t SPI_MST_TXFLR;                /*!< 0x208 */
    __I  uint32_t SPI_WRAP_SR;                  /*!< 0x20C */
    __IO uint32_t SPI_WRAP_IMR;                 /*!< 0x210 */
    __I  uint32_t SPI_WRAP_ISR;                 /*!< 0x214 */
    __I  uint32_t SPI_WRAP_RISR;                /*!< 0x218 */
    __I  uint32_t SPI_WRAP_ICR;                 /*!< 0x21C */
    __IO uint32_t SPI_WRAP_DMACR;               /*!< 0x220 */
    __IO uint32_t SPI_WRAP_DMATDLR;             /*!< 0x224 */
    __I  uint32_t SPI_WRAP_TXNDF_CNT;           /*!< 0x228 */
    __IO uint32_t SPI_WRAP_CS_DLY;              /*!< 0x22C */
    __IO uint32_t SPI_WRAP_TCMD_NUM;            /*!< 0x230 */
    __IO uint32_t SPI_WRAP_TWAIT_NUM;           /*!< 0x234 */
    __IO uint32_t SPI_WRAP_TTRAN_NUM;           /*!< 0x238 */
    __IO uint32_t SPI_WRAP_FW_ST;               /*!< 0x23C */
    __IO uint32_t SPI_WRAP_TASK_STS;            /*!< 0x240 */
    __IO uint32_t SPI_WRAP_QACTIVE_MAN;         /*!< 0x244 */
} SPI_TypeDef;

/*============================================================================*
 *                         SPI Declaration
 *============================================================================*/
/** \defgroup SPI         SPI
  * \brief
  * \{
  */

/** \defgroup SPI_Exported_Constants SPI Exported Constants
  * \brief
  * \{
  */

/** \defgroup SPI_Declaration SPI Declaration
  * \brief
  * \{
  */

#define SPI0                      ((SPI_TypeDef *) SPI0_BASE)
#define SPI1                      ((SPI_TypeDef *) SPI1_BASE)
#define SPI2                      ((SPI_TypeDef *) SPI2_BASE)
#define SPI0_HS                   ((SPI_TypeDef *) SPI0_HS_BASE)
#define SPI1_HS                   ((SPI_TypeDef *) SPI1_HS_BASE)

#define IS_SPIM_PERIPH(PERIPH)    (((PERIPH) == SPI0) || \
                                   ((PERIPH) == SPI1) || \
                                   ((PERIPH) == SPI2) || \
                                   ((PERIPH) == SPI0_HS) || \
                                   ((PERIPH) == SPI1_HS))

#define IS_SPI_ALL_PERIPH(PERIPH) (IS_SPIM_PERIPH(PERIPH) || \
                                   IS_SPIS_PERIPH(PERIPH))

/** End of SPI_Declaration
  * \}
  */

/** End of SPI_Exported_Constants
  * \}
  */

/** End of SPI
  * \}
  */

/*============================================================================*
 *                         SPI Private Types
 *============================================================================*/
typedef struct
{
    uint32_t spi_reg[12];
} SPIStoreReg_Typedef;

/*============================================================================*
 *                         SPI Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   3:0     R/W    dfs                 4'h0
   5:4     R/W    frf                 2'b0
   6       R/W    scph                1'b0
   7       R/W    scpol               1'b0
   9:8     R/W    tmod                2'b0
   11:10   R      reserved0_11_10     2'b0
   15:12   R      reserved0_15_12     4'b0
   20:16   R      dfs_31              5'h0
   22:21   R      spi_frf             2'b0
   23      R      reserved0_23        1'b0
   24      R/W    sste                1'b1
   31:25   R      reserved0_31_25     7'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dfs: 4;
        uint32_t frf: 2;
        uint32_t scph: 1;
        uint32_t scpol: 1;
        uint32_t tmod: 2;
        const uint32_t reserved_3: 2;
        const uint32_t reserved_2: 4;
        const uint32_t dfs_31: 5;
        const uint32_t spi_frf: 2;
        const uint32_t reserved_1: 1;
        uint32_t sste: 1;
        const uint32_t reserved_0: 7;
    } b;
} SPI_M_CTRL0_TypeDef;


/* 0x00
    3:0     R/W    dfs             4'h7
    5:4     R      reserved5_4     2'b0
    6       R/W    scph            1'b0
    7       R/W    scpol           1'b0
    9:8     R      reserved9_8     2'b0
    10      R/W    slv_oe          1'b0
    20:11   R      reserved20_11   10'b0
    21      R/W    tx_byte_swap    1'b0
    22      R/W    tx_bit_swap     1'b0
    23      R/W    rx_byte_swap    1'b0
    24      R/W    rx_bit_swap     1'b0
    31:25   R      reserved31_25   7'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dfs: 4;
        const uint32_t reserved_3: 2;
        uint32_t scph: 1;
        uint32_t scpol: 1;
        const uint32_t reserved_2: 2;
        uint32_t slv_oe: 1;
        const uint32_t reserved_1: 10;
        uint32_t tx_byte_swap: 1;
        uint32_t tx_bit_swap: 1;
        uint32_t rx_byte_swap: 1;
        uint32_t rx_bit_swap: 1;
        const uint32_t reserved_0: 7;
    } b;
} SPI_S_CTRL0_TypeDef;



/* 0x04
    15:0    R/W    ndf             16'h0
    31:16   R      reserved0       16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t ndf: 16;
        const uint32_t reserved_0: 16;
    } b;
} SPI_M_CTRL1_TypeDef;



/* 0x08
    0       R/W    spi_en          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi_en: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_SPIENR_TypeDef;



/* 0x10
    0       R/W    ser             1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t ser: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_M_SER_TypeDef;



/* 0x14
    15:0    R/W    sckdv           16'b0
    31:16   R      reserved0       16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t sckdv: 16;
        const uint32_t reserved_0: 16;
    } b;
} SPI_M_BAUDR_TypeDef;



/* 0x18
   4:0     R/W    tft                 5'b0
   31:5    R      reserved18_31_5     27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tft: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_TXFTLR_TypeDef;



/* 0x1C
   4:0     R/W    rft                 5'b0
   31:5    R      reserved1c_31_5     27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rft: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_RXFTLR_TypeDef;



/* 0x20
   4:0     R      txtfl               5'b0
   31:5    R      reserved20_31_5     27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txtfl: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_TXFLR_TypeDef;




/* 0x24
   4:0     R      rxtfl               5'b0
   31:5    R      reserved24_31_5     27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rxtfl: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_RXFLR_TypeDef;



/* 0x28
    0       R      busy            1'b0
    1       R      tfnf            1'b1
    2       R      tfe             1'b1
    3       R      rfne            1'b0
    4       R      rff             1'b0
    5       R      reserved5       1'b0
    6       R      dcol            1'b0
    31:7    R      reserved31_7    25'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t busy: 1;
        const uint32_t tfnf: 1;
        const uint32_t tfe: 1;
        const uint32_t rfne: 1;
        const uint32_t rff: 1;
        const uint32_t reserved_1: 1;
        const uint32_t dcol: 1;
        const uint32_t reserved_0: 25;
    } b;
} SPI_M_SR_TypeDef;



/* 0x28
    0       R      busy            1'b0
    1       R      tfnf            1'b1
    2       R      tfe             1'b1
    3       R      rfne            1'b0
    4       R      rff             1'b0
    5       R      txe             1'b0
    6       R      reserved6       1'b0
    31:7    R      reserved31_7    25'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t busy: 1;
        const uint32_t tfnf: 1;
        const uint32_t tfe: 1;
        const uint32_t rfne: 1;
        const uint32_t rff: 1;
        const uint32_t txe: 1;
        const uint32_t reserved_1: 1;
        const uint32_t reserved_0: 25;
    } b;
} SPI_S_SR_TypeDef;



/* 0x2C
    0       R/W    txeim           1'b1
    1       R/W    txoim           1'b1
    2       R/W    rxuim           1'b1
    3       R/W    rxoim           1'b1
    4       R/W    rxfim           1'b1
    31:5    R      reserved31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t txeim: 1;
        uint32_t txoim: 1;
        uint32_t rxuim: 1;
        uint32_t rxoim: 1;
        uint32_t rxfim: 1;
        const uint32_t reserved_0: 27;
    } b;
} SPI_M_IMR_TypeDef;



/* 0x2C
    0       R/W    txeim           1'b1
    1       R/W    txoim           1'b1
    2       R/W    rxuim           1'b1
    3       R/W    rxoim           1'b1
    4       R/W    rxfim           1'b1
    5       R/W    faeim           1'b1
    6       R/W    txuim           1'b1
    7       R/W    ssrim           1'b1
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t txeim: 1;
        uint32_t txoim: 1;
        uint32_t rxuim: 1;
        uint32_t rxoim: 1;
        uint32_t rxfim: 1;
        uint32_t faeim: 1;
        uint32_t txuim: 1;
        uint32_t ssrim: 1;
        const uint32_t reserved_0: 24;
    } b;
} SPI_S_IMR_TypeDef;



/* 0x30
    0       R      txeis           1'b0
    1       R      txois           1'b0
    2       R      rxuis           1'b0
    3       R      rxois           1'b0
    4       R      rxfis           1'b0
    31:5    R      reserved31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txeis: 1;
        const uint32_t txois: 1;
        const uint32_t rxuis: 1;
        const uint32_t rxois: 1;
        const uint32_t rxfis: 1;
        const uint32_t reserved_0: 27;
    } b;
} SPI_M_ISR_TypeDef;



/* 0x30
    0       R      txeis           1'b0
    1       R      txois           1'b0
    2       R      rxuis           1'b0
    3       R      rxois           1'b0
    4       R      rxfis           1'b0
    5       R      faeis           1'b0
    6       R      txuis           1'b0
    7       R      ssris           1'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txeis: 1;
        const uint32_t txois: 1;
        const uint32_t rxuis: 1;
        const uint32_t rxois: 1;
        const uint32_t rxfis: 1;
        const uint32_t faeis: 1;
        const uint32_t txuis: 1;
        const uint32_t ssris: 1;
        const uint32_t reserved_0: 24;
    } b;
} SPI_S_ISR_TypeDef;



/* 0x34
    0       R      txeir           1'b0
    1       R      txoir           1'b0
    2       R      rxuir           1'b0
    3       R      rxoir           1'b0
    4       R      rxfir           1'b0
    31:5    R      reserved31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txeir: 1;
        const uint32_t txoir: 1;
        const uint32_t rxuir: 1;
        const uint32_t rxoir: 1;
        const uint32_t rxfir: 1;
        const uint32_t reserved_0: 27;
    } b;
} SPI_M_RISR_TypeDef;



/* 0x34
    0       R      txeir           1'b0
    1       R      txoir           1'b0
    2       R      rxuir           1'b0
    3       R      rxoir           1'b0
    4       R      rxfir           1'b0
    5       R      faeir           1'b0
    6       R      txuir           1'b0
    7       R      ssrir           1'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txeir: 1;
        const uint32_t txoir: 1;
        const uint32_t rxuir: 1;
        const uint32_t rxoir: 1;
        const uint32_t rxfir: 1;
        const uint32_t faeir: 1;
        const uint32_t txuir: 1;
        const uint32_t ssrir: 1;
        const uint32_t reserved_0: 24;
    } b;
} SPI_S_RISR_TypeDef;



/* 0x38
    0       R      txoicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txoicr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_TXOICR_TypeDef;



/* 0x3C
    0       R      rxoicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rxoicr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_RXOICR_TypeDef;



/* 0x40
    0       R      rxuicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t rxuicr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_RXUICR_TypeDef;



/* 0x44
    0       R      msticr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t msticr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_M_MSTICR_TypeDef;



/* 0x44
    0       R      faeicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t faeicr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_S_FAEICR_TypeDef;



/* 0x48
    0       R      icr             1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t icr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_ICR_TypeDef;



/* 0x4C
    0       R/W    rdmae           1'b0
    1       R/W    tdmae           1'b0
    31:2    R      reserved0       30'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rdmae: 1;
        uint32_t tdmae: 1;
        const uint32_t reserved_0: 30;
    } b;
} SPI_DMACR_TypeDef;



/* 0x50
   3:0     R/W    dmatdl              4'b0
   31:4    R      reserved50_31_4     28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dmatdl: 4;
        const uint32_t reserved_0: 28;
    } b;
} SPI_DMATDLR_TypeDef;



/* 0x54
   3:0     R/W    dmardl              4'b0
   31:4    R      reserved54_31_4     28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dmardl: 4;
        const uint32_t reserved_0: 28;
    } b;
} SPI_DMARDLR_TypeDef;



/* 0x58
    31:0    R      idcode       32'hffffffff
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t idcode: 32;
    } b;
} SPI_M_IDR_TypeDef;



/* 0x58
    0       R      txuicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t txuicr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_S_TXUICR_TypeDef;



/* 0x5C
    31:0    R      ssi_comp_version       32'h3430322a
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t ssi_comp_version: 32;
    } b;
} SPI_M_VERSION_ID_TypeDef;



/* 0x5C
    0       R      ssricr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t ssricr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_S_SSRICR_TypeDef;



/* 0x60
    31:0    R/W    dr              32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dr: 32;
    } b;
} SPI_DR_TypeDef;



/* 0xF0
    7:0     R/W    rsd             8'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rsd: 8;
        const uint32_t reserved_0: 24;
    } b;
} SPI_M_RSDR_TypeDef;


/* 0x200
   0       R/W    wrap_ctrl_mode      1'b0
   1       R/WAC  mst_tx_fifo_en      1'b0
   2       R/W    tx_fifo_rst         1'b0
   3       R/W    mosi_pull_en        1'b0
   4       R/W    mosi_drv_low_en     1'b0
   5       R/W    cs_inv_en           1'b0
   6       R/W    rap_ctrl_mode       1'b0
   15:7    R      reserved200_15_7    9'b0
   31:16   R/W    mst_tx_ndf          16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t wrap_ctrl_mode: 1;
        uint32_t mst_tx_fifo_en: 1;
        uint32_t tx_fifo_rst: 1;
        uint32_t mosi_pull_en: 1;
        uint32_t mosi_drv_low_en: 1;
        uint32_t cs_inv_en: 1;
        uint32_t rap_ctrl_mode: 1;
        const uint32_t reserved_0: 9;
        uint32_t mst_tx_ndf: 16;
    } b;
} SPI_WRAP_CTRL_TypeDef;


/* 0x204
   4:0     R/W    tx_fifo_tl          5'b0
   31:5    R      reserved204_31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_fifo_tl: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_WRAP_TXFTLR_TypeDef;


/* 0x208
   4:0     R      tx_fifo_lv          5'b0
   31:5    R      reserved208_31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_fifo_lv: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_MST_TXFLR_TypeDef;


/* 0x20C
   0       R      cs_en               1'b0
   1       R      tx_fifo_not_full    1'b1
   2       R      tx_fifo_empty       1'b1
   31:3    R      reserved20c_31_3    29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t cs_en: 1;
        const uint32_t tx_fifo_not_full: 1;
        const uint32_t tx_fifo_empty: 1;
        const uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_SR_TypeDef;


/* 0x210
   0       R/W    tx_fifo_empty_int_m 1'b0
   1       R/W    tx_fifo_ov_int_m    1'b0
   2       R/W    tx_ndf_done_int_m   1'b0
   31:3    R      reserved210_31_3    29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_fifo_empty_int_m: 1;
        uint32_t tx_fifo_ov_int_m: 1;
        uint32_t tx_ndf_done_int_m: 1;
        const uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_IMR_TypeDef;


/* 0x214
   0       R      tx_fifo_empty_int_st1'b0
   1       R      tx_fifo_ov_int_st   1'b0
   2       R      tx_ndf_done_int_st  1'b0
   31:3    R      reserved214_31_3    29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_fifo_empty_int_st: 1;
        const uint32_t tx_fifo_ov_int_st: 1;
        const uint32_t tx_ndf_done_int_st: 1;
        const uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_ISR_TypeDef;


/* 0x218
   0       R      tx_fifo_empty_r_st  1'b0
   1       R      tx_fifo_ov_r_st     1'b0
   2       R      tx_ndf_done_r_st    1'b0
   31:3    R      reserved218_31_3    29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_fifo_empty_r_st: 1;
        const uint32_t tx_fifo_ov_r_st: 1;
        const uint32_t tx_ndf_done_r_st: 1;
        const uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_RISR_TypeDef;


/* 0x21C
   0       R      int_clr             1'b0
   31:1    R      reserved21c_31_1    31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t int_clr: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_WRAP_ICR_TypeDef;


/* 0x220
   0       R/W    tx_dma_en           1'b0
   31:1    R      reserved220_31_1    31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t tx_dma_en: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_WRAP_DMACR_TypeDef;


/* 0x224
   4:0     R/W    dma_tx_dl           5'b0
   31:5    R      reserved224_31_5    27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t dma_tx_dl: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI_WRAP_DMATDLR_TypeDef;


/* 0x228
   16:0    R      tx_ndf_cnt          17'b0
   31:17   R      reserved228_31_17   15'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t tx_ndf_cnt: 17;
        const uint32_t reserved_0: 15;
    } b;
} SPI_WRAP_TXNDF_CNT_TypeDef;


/* 0x22C
   3:0     R/W    cs_setup_dly        4'b0
   7:4     R      reserved22c_7_4     4'b0
   11:8    R/W    cs_hold_dly         4'b0
   15:12   R      reserved22c_15_12   4'b0
   23:16   R/W    cs_clk_div_sel      8'b0
   31:24   R      reserved22c_31_24   8'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t cs_setup_dly: 4;
        const uint32_t reserved_2: 4;
        uint32_t cs_hold_dly: 4;
        const uint32_t reserved_1: 4;
        uint32_t cs_clk_div_sel: 8;
        const uint32_t reserved_0: 8;
    } b;
} SPI_WRAP_CS_DLY_TypeDef;


/* 0x230
   3:0     R/W    task_cmd_num        4'b0
   31:4    R      reserved230_31_4    28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t task_cmd_num: 4;
        const uint32_t reserved_0: 28;
    } b;
} SPI_WRAP_TCMD_NUM_TypeDef;


/* 0x234
   15:0    R/W    task_wait_num       16'b0
   31:16   R      reserved234_31_16   16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t task_wait_num: 16;
        const uint32_t reserved_0: 16;
    } b;
} SPI_WRAP_TWAIT_NUM_TypeDef;


/* 0x238
   15:0    R/W    task_tran_num       16'b0
   31:16   R      reserved238_31_16   16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t task_tran_num: 16;
        const uint32_t reserved_0: 16;
    } b;
} SPI_WRAP_TTRAN_NUM_TypeDef;


/* 0x23C
   0       R/WAC  fw_start_task       1'b0
   31:1    R      reserved23c_31_1    31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t fw_start_task: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI_WRAP_FW_ST_TypeDef;


/* 0x240
   0       R/W1C  start_task_sts      1'b0
   1       R/W1C  start_event_sts     1'b0
   2       R/W1C  end_event_sts       1'b0
   31:3    R      reserved240_31_3    29'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t start_task_sts: 1;
        uint32_t start_event_sts: 1;
        uint32_t end_event_sts: 1;
        const uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_TASK_STS_TypeDef;


/* 0x244
   0       R/W    clk1_qactive_man_data   1'b0
   1       R/W    clk1_qactive_man_en     1'b0
   2       R/W    clk2_qactive_man_data   1'b0
   3       R/W    clk2_qactive_man_en     1'b0
   4       R/W    clk3_qactive_man_data   1'b0
   5       R/W    clk3_qactive_man_en     1'b0
   15:6    R      reserved244_15_6        10'b0
   16      R/W    pwr_qactive_man_data    1'b0
   17      R/W    pwr_qactive_man_en      1'b0
   31:18   R      reserved240_31_18       14'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t clk1_qactive_man_data: 1;
        uint32_t clk1_qactive_man_en: 1;
        uint32_t clk2_qactive_man_data: 1;
        uint32_t clk2_qactive_man_en: 1;
        uint32_t clk3_qactive_man_data: 1;
        uint32_t clk3_qactive_man_en: 1;
        const uint32_t reserved_1: 10;
        uint32_t pwr_qactive_man_data: 1;
        uint32_t pwr_qactive_man_en: 1;
        const uint32_t reserved_0: 14;
    } b;
} SPI_WRAP_QACTIVE_MAN_TypeDef;

/*============================================================================*
 *                         SPI Constant
 *============================================================================*/
/** \defgroup SPI         SPI
  * \brief
  * \{
  */

/** \defgroup SPI_Exported_Constants SPI Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    SPI_Clock_Source SPI Clock Source
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_CLOCK_SRC_40M = 0x0,
    SPI_CLOCK_SRC_80M = 0x1,
} SPIClockSrc_TypeDef;

#define IS_SPI_CLOCK_SRC(CLOCK)     (((CLOCK) == SPI_CLOCK_SRC_40M) || \
                                     ((CLOCK) == SPI_CLOCK_SRC_80M))

/** End of SPI_Clock_Source
  * \}
  */

/**
 * \defgroup    SPI_Clock_Divider SPI Clock Divider
 * \{
 * \ingroup     SPI_Exported_Constants
 *
 * \note        SPI2 Clock divider only support:
 *              SPI_CLOCK_DIV_1
 *              SPI_CLOCK_DIV_2
 *              SPI_CLOCK_DIV_4
 *              SPI_CLOCK_DIV_8
 */
typedef enum
{
    SPI_CLOCK_DIV_1 = 0x0,
    SPI_CLOCK_DIV_2 = 0x1,
    SPI_CLOCK_DIV_4 = 0x2,
    SPI_CLOCK_DIV_8 = 0x3,
    SPI_CLOCK_DIV_16 = 0x4,
    SPI_CLOCK_DIV_32 = 0x5,
    SPI_CLOCK_DIV_40 = 0x6,
    SPI_CLOCK_DIV_64 = 0x7,
} SPIClockDiv_TypeDef;

#define IS_SPI_CLOCK_DIV(DIV) (((DIV) == SPI_CLOCK_DIV_1) || \
                               ((DIV) == SPI_CLOCK_DIV_2) || \
                               ((DIV) == SPI_CLOCK_DIV_4) || \
                               ((DIV) == SPI_CLOCK_DIV_8) || \
                               ((DIV) == SPI_CLOCK_DIV_16) || \
                               ((DIV) == SPI_CLOCK_DIV_32) || \
                               ((DIV) == SPI_CLOCK_DIV_40) || \
                               ((DIV) == SPI_CLOCK_DIV_64))

/** End of SPI_Clock_Divider
  * \}
  */

/**
 * \defgroup SPI_Constant_Private SPI Constant Private
 * \{
 * \ingroup  SPI_Exported_Constants
 */
#define SPI_NDF                         SPI_RXNDF

/** End of SPI_Constant_Private
  * \}
  */

/** End of SPI_Exported_Constants
  * \}
  */

/** End of SPI
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_SPI_DEF_H */
