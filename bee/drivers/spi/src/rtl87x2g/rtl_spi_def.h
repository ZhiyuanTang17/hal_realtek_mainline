/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_spi_def.h
* \brief    Pinmux related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_SPI_DEF_H
#define RTL_SPI_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

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
#define SPI_TX_FIFO_SIZE                               (32)
#define SPI_RX_FIFO_SIZE                               (32)
#define SPI0_SLAVE_TX_FIFO_SIZE                        (64)
#define SPI0_SLAVE_RX_FIFO_SIZE                        (64)
#define SPI_SUPPORT_WRAP_MODE                          (0)
#define SPI0_SUPPORT_MASTER_SLAVE                      (0)
#define SPI0_SUPPORT_HS                                (1)
#define SPI_SUPPORT_APH_BRIDGE_FOR_HIGH_SPEED          (1)
#define SPI_SUPPORT_CLOCK_SOURCE_SWITCH                (0)
#define SPI_SUPPORT_CLOCK_SOURCE_CONFIG                (1)
#define SPI_DFS_BIT_FIELD                              dfs_32
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
    __IO  uint32_t SPI_M_S_CTRL0;               /*!< 0x00 */
    __IO  uint32_t SPI_M_CTRL1;                 /*!< 0x04 */
    __IO  uint32_t SPI_SPIENR;                  /*!< 0x08 */
    __IO  uint32_t RSVD_0C;                     /*!< 0x0C */
    __IO  uint32_t SPI_M_SER;                   /*!< 0x10 */
    __IO  uint32_t SPI_M_BAUDR;                 /*!< 0x14 */
    __IO  uint32_t SPI_TXFTLR;                  /*!< 0x18 */
    __IO  uint32_t SPI_RXFTLR;                  /*!< 0x1C */
    __I   uint32_t SPI_TXFLR;                   /*!< 0x20 */
    __I   uint32_t SPI_RXFLR;                   /*!< 0x24 */
    __I   uint32_t SPI_M_S_SR;                  /*!< 0x28 */
    __IO  uint32_t SPI_M_S_IMR;                 /*!< 0x2C */
    __I   uint32_t SPI_M_S_ISR;                 /*!< 0x30 */
    __I   uint32_t SPI_M_S_RISR;                /*!< 0x34 */
    __I   uint32_t SPI_TXOICR;                  /*!< 0x38 */
    __I   uint32_t SPI_RXOICR;                  /*!< 0x3C */
    __I   uint32_t SPI_RXUICR;                  /*!< 0x40 */
    __I   uint32_t SPI_M_S_MSTICR_FAEICR;       /*!< 0x44 */
    __I   uint32_t SPI_ICR;                     /*!< 0x48 */
    __IO  uint32_t SPI_DMACR;                   /*!< 0x4C */
    __IO  uint32_t SPI_DMATDLR;                 /*!< 0x50 */
    __IO  uint32_t SPI_DMARDLR;                 /*!< 0x54 */
    __I   uint32_t SPI_M_S_IDR_TXUICR;          /*!< 0x58 */
    __I   uint32_t SPI_M_S_VERSION_ID_SSRICR;   /*!< 0x5C */
    __IO  uint32_t SPI_DR[36];                  /*!< 0x60 - 0xEC */
    __IO  uint32_t SPI_M_RSDR;                  /*!< 0xF0 */
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

#define SPI0                      ((SPI_TypeDef *) SPI0_REG_BASE)
#define SPI1                      ((SPI_TypeDef *) SPI1_REG_BASE)
#define SPI0_SLAVE                ((SPI_TypeDef *) SPI_SLAVE_REG_BASE)
#define SPI0_HS                   ((SPI_TypeDef *) SPI0_HS_REG_BASE)

#define IS_SPIM_PERIPH(PERIPH)    (((PERIPH) == SPI0) || \
                                   ((PERIPH) == SPI1) || \
                                   ((PERIPH) == SPI0_HS))
#define IS_SPIS_PERIPH(PERIPH)    (((PERIPH) == SPI0_SLAVE))
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
    3:0     R      dfs             4'h0
    5:4     R/W    frf             2'b0
    6       R/W    scph            1'b0
    7       R/W    scpol           1'b0
    9:8     R/W    tmod            2'b0
    10      R/W    slv_oe          1'b0
    11      R/W    srl             1'b0
    15:12   R/W    cfs             4'b0
    20:16   R/W    dfs_32          5'h7
    22:21   R      spi_frf         2'b0
    23      R      reserved23      1'b0
    24      R/W    sste            1'b1
    31:25   R      reserved31_25   7'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t dfs: 4;
            uint32_t frf: 2;
            uint32_t scph: 1;
            uint32_t scpol: 1;
            uint32_t tmod: 2;
            uint32_t slv_oe: 1;
            uint32_t srl: 1;
            uint32_t cfs: 4;
            uint32_t dfs_32: 5;
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
            struct
            {
                uint32_t sckdv: 16;
                const uint32_t reserved_0: 16;
            } b;
        } SPI_M_BAUDR_TypeDef;



    /* 0x18
        5:0     R/W    tft             6'b0
        31:6    R      reserved0       26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t tft: 6;
                const uint32_t reserved_0: 26;
            } b;
        } SPI_TXFTLR_TypeDef;



    /* 0x1C
        5:0     R/W    rft             6'b0
        31:6    R      reserved0       26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t rft: 6;
                const uint32_t reserved_0: 26;
            } b;
        } SPI_RXFTLR_TypeDef;



    /* 0x20
        6:0     R      txtfl           7'b0
        31:7    R      reserved0       25'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t txtfl: 7;
                const uint32_t reserved_0: 25;
            } b;
        } SPI_TXFLR_TypeDef;



    /* 0x24
        6:0     R      rxtfl           7'b0
        31:7    R      reserved0       25'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t rxtfl: 7;
                const uint32_t reserved_0: 25;
            } b;
        } SPI_RXFLR_TypeDef;



    /* 0x28
        0       R      busy            1'b0
        1       R      tfnf            1'b1
        2       R      tfe             1'b1
        3       R      rfne            1'b0
        4       R      rff             1'b0
        5       R      txe             1'b0
        6       R      dcol            1'b0
        31:7    R      reserved31_7    25'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t busy: 1;
                const uint32_t tfnf: 1;
                const uint32_t tfe: 1;
                const uint32_t rfne: 1;
                const uint32_t rff: 1;
                const uint32_t txe: 1;
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
            uint8_t d8[4];
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
        5       R/W    mstim           1'b1
        31:6    R      reserved31_6    26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                uint32_t txeim: 1;
                uint32_t txoim: 1;
                uint32_t rxuim: 1;
                uint32_t rxoim: 1;
                uint32_t rxfim: 1;
                uint32_t mstim: 1;
                const uint32_t reserved_0: 26;
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
            uint8_t d8[4];
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
        5       R      mstis           1'b0
        31:6    R      reserved31_6    26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t txeis: 1;
                const uint32_t txois: 1;
                const uint32_t rxuis: 1;
                const uint32_t rxois: 1;
                const uint32_t rxfis: 1;
                const uint32_t mstis: 1;
                const uint32_t reserved_0: 26;
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
            uint8_t d8[4];
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
        5       R      mstir           1'b0
        31:6    R      reserved31_6    26'h0
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
            struct
            {
                const uint32_t txeir: 1;
                const uint32_t txoir: 1;
                const uint32_t rxuir: 1;
                const uint32_t rxoir: 1;
                const uint32_t rxfir: 1;
                const uint32_t mstir: 1;
                const uint32_t reserved_0: 26;
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
            struct
            {
                uint32_t rdmae: 1;
                uint32_t tdmae: 1;
                const uint32_t reserved_0: 30;
            } b;
        } SPI_DMACR_TypeDef;



    /* 0x50
        5:0     R/W    dmatdl          6'b0
        31:6    R      reserved0       26'h0
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
        } SPI_DMATDLR_TypeDef;



    /* 0x54
        5:0     R/W    dmardl          6'b0
        31:6    R      reserved0       26'h0
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
        } SPI_DMARDLR_TypeDef;



    /* 0x58
        31:0    R      idcode       32'hffffffff
    */
    typedef union
        {
            uint32_t d32;
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
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
            uint8_t d8[4];
            struct
            {
                uint32_t rsd: 8;
                const uint32_t reserved_0: 24;
            } b;
        } SPI_M_RSDR_TypeDef;

    /* ================================================================================ */
    /* ================                   SPI  Constants               ================ */
    /* ================================================================================ */
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
    SPI_CLOCK_SRC_PLL1 = 0x0,
    SPI_CLOCK_SRC_PLL2 = 0x1,
    SPI_CLOCK_SRC_40M = 0x2,
} SPIClockSrc_TypeDef;

#define IS_SPI_CLK_SOURCE(PERIPH)     (((PERIPH) == SPI_CLOCK_SRC_40M) || \
                                       ((PERIPH) == SPI_CLOCK_SRC_PLL1) || \
                                       ((PERIPH) == SPI_CLOCK_SRC_PLL2))

/** End of SPI_Clock_Source
  * \}
  */

/**
 * \defgroup    SPI_Clock_Divider SPI Clock Divider
 * \{
 * \ingroup     SPI_Exported_Constants
 */
typedef enum
{
    SPI_CLOCK_DIVIDER_1 = 0x0,
    SPI_CLOCK_DIVIDER_2 = 0x1,
    SPI_CLOCK_DIVIDER_4 = 0x2,
    SPI_CLOCK_DIVIDER_8 = 0x3,
    SPI_CLOCK_DIVIDER_16 = 0x4,
    SPI_CLOCK_DIVIDER_32 = 0x5,
    SPI_CLOCK_DIVIDER_40 = 0x6,
    SPI_CLOCK_DIVIDER_64 = 0x7,
} SPIClockDiv_TypeDef;

#define IS_SPI_CLK_DIV(DIV) (((DIV) == SPI_CLOCK_DIVIDER_1) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_2) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_4) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_8) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_16) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_32) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_40) || \
                             ((DIV) == SPI_CLOCK_DIVIDER_64))

/** End of SPI_Clock_Divider
  * \}
  */

/*============================================================================*
 *                          SPI TYPE/API Wrappers
 *============================================================================*/
/**
 * \defgroup SPI_API_Wrapper SPI API Wrapper
 * \{
 * \ingroup  SPI_Exported_Constants
 */
#define SPI_Change_CLK                  SPI_ChangeClock
#define SPI_NDF                         SPI_RXNDF

#define CK_40M_SPI                      SPI_CLOCK_SRC_40M
#define CK_PLL1_SPI                     SPI_CLOCK_SRC_PLL1
#define CK_PLL2_SPI                     SPI_CLOCK_SRC_PLL2

/** End of SPI_API_Wrapper
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
