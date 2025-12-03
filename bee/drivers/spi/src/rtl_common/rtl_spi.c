/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_spi.c
* \brief    This file provides all the Spi firmware functions.
* \details
* \author   yuzhuo_liu
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_spi.h"
#include "rtl_rcc.h"

#if SPI0_SUPPORT_MASTER_SLAVE
#define SPI_NOT_SLAVE(SPIx)          (!SPI_IN_SLAVE_MODE(SPIx))
#define SPI_CONFIGURED_MASTER(mode)  (mode == SPI_Mode_Master)
#else
#define SPI_NOT_SLAVE(SPIx)          (SPIx != SPI0_SLAVE)
#define SPI_CONFIGURED_MASTER(mode)  (1)
#endif

#if SPI0_SUPPORT_MASTER_SLAVE
extern void SPI_ConfigMasterSlave(SPIMode_Typedef SPI_Mode);
#endif
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the SPIx peripheral registers to their default reset values.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \return None
  */
void SPI_DeInit(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    switch ((uint32_t)SPIx)
    {
#ifdef SPI0
    case (uint32_t)SPI0:
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, DISABLE);
        break;
#endif
#ifdef SPI0_SLAVE
    case (uint32_t)SPI0_SLAVE:
        RCC_PeriphClockCmd(APBPeriph_SPI0_SLAVE, APBPeriph_SPI0_SLAVE_CLOCK, DISABLE);
        break;
#endif
#ifdef SPI1
    case (uint32_t)SPI1:
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, DISABLE);
        break;
#endif
#ifdef SPI2
    case (uint32_t)SPI2:
        RCC_PeriphClockCmd(APBPeriph_SPI2, APBPeriph_SPI2_CLOCK, DISABLE);
        break;
#endif
#ifdef SPI3
    case (uint32_t)SPI3:
        RCC_PeriphClockCmd(APBPeriph_SPI3, APBPeriph_SPI3_CLOCK, DISABLE);
        break;
#endif

    default:
        break;
    }
}

/**
  * \brief  Initializes the SPIx peripheral according to the specified
  *         parameters in the SPI_InitStruct.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  SPI_InitStruct: Pointer to a SPI_InitTypeDef structure that
  *         contains the configuration information for the specified SPI peripheral.
  * \return None
  */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_DIRECTION_MODE(SPI_InitStruct->SPI_Direction));
    assert_param(IS_SPI_DATASIZE(SPI_InitStruct->SPI_DataSize));
    assert_param(IS_SPI_CPOL(SPI_InitStruct->SPI_CPOL));
    assert_param(IS_SPI_CPHA(SPI_InitStruct->SPI_CPHA));
    assert_param(IS_SPI_FRAME_FORMAT(SPI_InitStruct->SPI_FrameFormat));
    assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_InitStruct->SPI_BaudRatePrescaler));

    /* Disable SPI device before change configuration */
    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = 0;
    SPIx->SPI_SPIENR = spi_0x08.d32;

    /* Configure SPI Master mode if select SPI0, SPI1, SPI2 or SPI3 */
    if (IS_SPIM_PERIPH(SPIx))
    {
#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
        if (SPIx == SPI0)
        {
            SPI_ConfigMasterSlave(SPI_InitStruct->SPI_Mode);
        }
#endif

#if (SPI_SUPPORT_APH_BRIDGE_FOR_HIGH_SPEED == 1)
        extern void SPI_ConfigAPHBridge(SPI_TypeDef * SPIx);
        SPI_ConfigAPHBridge(SPIx);
#endif

#if (SPI0_SUPPORT_HS == 1)
        extern void SPI_SPI0AHBBridgeConfig(FunctionalState NewState);
        if (SPIx == SPI0)
        {
            SPI_SPI0AHBBridgeConfig(DISABLE);
        }
        else if (SPIx == SPI0_HS)
        {
            SPI_SPI0AHBBridgeConfig(ENABLE);
        }
#endif
        /* Configure SPI master mode parameters */
        SPI_M_CTRL0_TypeDef spi_0x00 = {.d32 = SPIx->SPI_M_S_CTRL0};
        spi_0x00.b.frf = SPI_InitStruct->SPI_FrameFormat;
        spi_0x00.b.scph = SPI_InitStruct->SPI_CPHA;
        spi_0x00.b.scpol = SPI_InitStruct->SPI_CPOL;
        spi_0x00.b.tmod = SPI_InitStruct->SPI_Direction;
        spi_0x00.b.SPI_DFS_BIT_FIELD = SPI_InitStruct->SPI_DataSize;
        spi_0x00.b.sste = SPI_InitStruct->SPI_ToggleEn;
        SPIx->SPI_M_S_CTRL0 = spi_0x00.d32;
#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
        if (SPI_InitStruct->SPI_Mode == SPI_Mode_Slave)
        {
            SPI_S_CTRL0_TypeDef spi_0x00 = {.d32 = SPIx->SPI_M_S_CTRL0};
            spi_0x00.b.slv_oe = 0;
            spi_0x00.b.dfs = SPI_InitStruct->SPI_DataSize;
            SPIx->SPI_M_S_CTRL0 = spi_0x00.d32;
        }
#endif

        /* Set master clock divider */
        SPI_M_BAUDR_TypeDef spi_0x14 = {.d32 = SPIx->SPI_M_BAUDR};
        spi_0x14.b.sckdv = SPI_InitStruct->SPI_BaudRatePrescaler % 0xFFFF;
        SPIx->SPI_M_BAUDR = spi_0x14.d32;

        /* Enable slave Select function in master mode */
        if (SPI_CONFIGURED_MASTER(SPI_InitStruct->SPI_Mode))
        {
            SPI_M_SER_TypeDef spi_0x10 = {.d32 = SPIx->SPI_M_SER};
            spi_0x10.b.ser = 1;
            SPIx->SPI_M_SER = spi_0x10.d32;
        }

        /* Set read length in SPI EEPROM & rx only mode */
        if ((SPI_InitStruct->SPI_Direction == SPI_Direction_RxOnly) || \
            (SPI_InitStruct->SPI_Direction == SPI_Direction_EEPROM))
        {
            SPI_M_CTRL1_TypeDef spi_0x04 = {.d32 = SPIx->SPI_M_CTRL1};
            if (SPI_InitStruct->SPI_RXNDF > 0)
            {
                spi_0x04.b.ndf = SPI_InitStruct->SPI_RXNDF - 1;
            }
            SPIx->SPI_M_CTRL1 = spi_0x04.d32;
        }
#if (SPI_SUPPORT_WRAP_MODE == 1)
        else if ((SPI_InitStruct->SPI_Direction == SPI_Direction_TxOnly) || \
                 (SPI_InitStruct->SPI_Direction == SPI_Direction_FullDuplex))
        {
            if (SPI_InitStruct->SPI_WrapModeEn)
            {
                SPIx->SPI_WRAP_CTRL = 0;

                /* Wrapper mode enable */
                SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
                SPI_WRAP_TXFTLR_TypeDef spi_0x204 = {.d32 = SPIx->SPI_WRAP_TXFTLR};
                spi_0x200.b.wrap_ctrl_mode = 1;
                if (SPI_InitStruct->SPI_TXNDF > 0)
                {
                    spi_0x200.b.mst_tx_ndf = SPI_InitStruct->SPI_TXNDF - 1;
                }
                spi_0x204.b.tx_fifo_tl = SPI_InitStruct->SPI_TxThresholdLevel;

                SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
                SPIx->SPI_WRAP_TXFTLR = spi_0x204.d32;

                if (SPI_InitStruct->SPI_WrapModeDmaEn)
                {
                    /* enable tx ndf dma */
                    SPI_WRAP_DMACR_TypeDef spi_0x220 = {.d32 = SPIx->SPI_WRAP_DMACR};
                    SPI_WRAP_DMATDLR_TypeDef spi_0x224 = {.d32 = SPIx->SPI_WRAP_DMATDLR};
                    spi_0x220.b.tx_dma_en = 1;
                    spi_0x224.b.dma_tx_dl = SPI_InitStruct->SPI_TxNdfWaterlevel;
                    SPIx->SPI_WRAP_DMACR = spi_0x220.d32;
                    SPIx->SPI_WRAP_DMATDLR = spi_0x224.d32;
                }
            }
        }

        SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
        spi_0x200.b.cs_inv_en = SPI_InitStruct->SPI_CSHighActiveEn;
        SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
#endif
    }
#if !SPI0_SUPPORT_MASTER_SLAVE
    /* Configure SPI Slave mode if select SPI0_SLAVE */
    else if (SPIx == SPI0_SLAVE)
    {
        /* Configure SPI slave mode parameters */
        SPI_S_CTRL0_TypeDef spi_0x00 = {.d32 = SPIx->SPI_M_S_CTRL0};
        spi_0x00.b.scph = SPI_InitStruct->SPI_CPHA;
        spi_0x00.b.scpol = SPI_InitStruct->SPI_CPOL;
        spi_0x00.b.dfs = SPI_InitStruct->SPI_DataSize;
#if (SPI_SUPPORT_SWAP == 1)
        spi_0x00.b.tx_byte_swap = SPI_InitStruct->SPI_SwapTxByteEn;
        spi_0x00.b.tx_bit_swap = SPI_InitStruct->SPI_SwapTxBitEn;
        spi_0x00.b.rx_byte_swap = SPI_InitStruct->SPI_SwapRxByteEn;
        spi_0x00.b.rx_bit_swap = SPI_InitStruct->SPI_SwapRxBitEn;
#endif

        /* Enable slave output */
        spi_0x00.b.slv_oe = 0;
        SPIx->SPI_M_S_CTRL0 = spi_0x00.d32;
    }
#endif
    /* Set Tx empty level */
    SPI_TXFTLR_TypeDef spi_0x18 = {.d32 = SPIx->SPI_TXFTLR};
    spi_0x18.b.tft = SPI_InitStruct->SPI_TxThresholdLevel;
    SPIx->SPI_TXFTLR = spi_0x18.d32;

    /*set Rx full level*/
    SPI_RXFTLR_TypeDef spi_0x1c = {.d32 = SPIx->SPI_RXFTLR};
    spi_0x1c.b.rft = SPI_InitStruct->SPI_RxThresholdLevel;

    /* Config SPI dma mode */
    SPI_DMACR_TypeDef spi_0x4c = {.d32 = SPIx->SPI_DMACR};
    spi_0x4c.b.rdmae = SPI_InitStruct->SPI_RxDmaEn;
    spi_0x4c.b.tdmae = SPI_InitStruct->SPI_TxDmaEn;
    SPIx->SPI_DMACR = spi_0x4c.d32;

    /* Config SPI waterlevel */
    SPI_DMATDLR_TypeDef spi_0x50 = {.d32 = SPIx->SPI_DMATDLR};
    SPI_DMARDLR_TypeDef spi_0x54 = {.d32 = SPIx->SPI_DMARDLR};
    spi_0x50.b.dmatdl = SPI_InitStruct->SPI_TxWaterlevel;
    spi_0x54.b.dmardl = SPI_InitStruct->SPI_RxWaterlevel;
    SPIx->SPI_DMATDLR = spi_0x50.d32;

    if (SPI_InitStruct->SPI_RxDmaEn)
    {
        /* DMA mode should config DMARDLR later if open AHB */
        SPIx->SPI_RXFTLR = spi_0x1c.d32;
        SPIx->SPI_DMARDLR = spi_0x54.d32;
    }
    else
    {
        /* CPU mode should config RXFTLR later if open AHB */
        SPIx->SPI_DMARDLR = spi_0x54.d32;
        SPIx->SPI_RXFTLR = spi_0x1c.d32;
    }

    /* Mask SPI interrupt in REG_DW_SSI_IMR */
    SPIx->SPI_M_S_IMR = 0;
}

/**
  * \brief  Fills each SPI_InitStruct member with its default value.
  * \param  SPI_InitStruct : Pointer to a SPI_InitTypeDef structure which will be initialized.
  * \return None
  */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct)
{
    /* TX and RX Mode */
    SPI_InitStruct->SPI_Direction         = SPI_Direction_FullDuplex;
    /* Number of data to read in RX/EEPROM Mode */
    SPI_InitStruct->SPI_RXNDF              = 1;
    /* 8-bit serial data transfer */
    SPI_InitStruct->SPI_DataSize          = SPI_DataSize_8b;
    /* Inactive state of clock is high */
    SPI_InitStruct->SPI_CPOL              = SPI_CPOL_High;
    /* Serial clock toggles in first of first data bit */
    SPI_InitStruct->SPI_CPHA              = SPI_CPHA_2Edge;
    /* Motorola format */
    SPI_InitStruct->SPI_FrameFormat       = SPI_Frame_Motorola;
    /* Speed = SPI Clock source/ SPI_ClkDIV*/
    SPI_InitStruct->SPI_BaudRatePrescaler = 128;
#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
    SPI_InitStruct->SPI_Mode = SPI_Mode_Master;
#endif
#if (SPI_SUPPORT_SWAP == 1)
    /* Reverse the rx bit or not */
    SPI_InitStruct->SPI_SwapTxBitEn       = DISABLE;
    SPI_InitStruct->SPI_SwapRxBitEn       = DISABLE;
    SPI_InitStruct->SPI_SwapTxByteEn      = DISABLE;
    SPI_InitStruct->SPI_SwapRxByteEn      = DISABLE;
#endif
    /* Toggle CS line or not */
    SPI_InitStruct->SPI_ToggleEn          = DISABLE;
#if (SPI_SUPPORT_WRAP_MODE == 1)
    /* Number of data to read in TX/FullDuplex Mode */
    SPI_InitStruct->SPI_TXNDF             = 1;
    /* Enable CS high active or not */
    SPI_InitStruct->SPI_CSHighActiveEn    = DISABLE;
    /* Disable tx ndf */
    SPI_InitStruct->SPI_WrapModeEn     = DISABLE;
    /* Disable dma */
    SPI_InitStruct->SPI_WrapModeDmaEn  = DISABLE;
    /* SPI Tx waterlevel, should be less than fifo threshold.
       The best value is SPI FIFO Depth - GDMA Msize */
    SPI_InitStruct->SPI_TxNdfWaterlevel   =  SPI_TX_FIFO_SIZE - 1;
#endif
    /* Tx fifo depth: 32/64 bytes */
    SPI_InitStruct->SPI_TxThresholdLevel  = 1;
    /* Rx fifo depth: 32/64 bytes */
    SPI_InitStruct->SPI_RxThresholdLevel  = 0;
    /* Disable dma */
    SPI_InitStruct->SPI_TxDmaEn           = DISABLE;
    SPI_InitStruct->SPI_RxDmaEn           = DISABLE;
    /* SPI Tx waterlevel, should be less than fifo threshold.
       The best value is SPI FIFO Depth - GDMA Msize */
    SPI_InitStruct->SPI_TxWaterlevel      = SPI_TX_FIFO_SIZE - 1;
    /* SPI Rx waterlevel, should be less than fifo threshold.
       The best value is GDMA Msize */
    SPI_InitStruct->SPI_RxWaterlevel      = 1;
}

/**
  * \brief  Enable or disable the specified SPI peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  NewState: New state of the SPIx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = NewState;
    SPIx->SPI_SPIENR = spi_0x08.d32;
}

/**
  * \brief  Transmits a number of bytes through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  pBuf : Bytes to be transmitted.
  * \param  len : Byte length to be transmitted.
  * \return None
  */
void SPI_SendBuffer(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len)
{
    uint16_t i = 0;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (spi_0x200.b.wrap_ctrl_mode && SPI_NOT_SLAVE(SPIx))
    {
        for (i = 0; i < len; i++)
        {
            /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
            while (!(SPIx->SPI_WRAP_SR & SPI_FLAG_TFNF));
            SPIx->SPI_DR[0] = (*pBuf++);
        }
        return;
    }
#endif
    for (i = 0; i < len; i++)
    {
        /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
        while (SPI_NOT_SLAVE(SPIx) && !(SPIx->SPI_M_S_SR & SPI_FLAG_TFNF));
        SPIx->SPI_DR[0] = (*pBuf++);
    }
}

/**
  * \brief  Transmits a number of halfwords through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  pBuf : Halfwords to be transmitted.
  * \param  len: Halfword length to be transmitted.
  * \return None
  */
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len)
{
    uint16_t i = 0;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (spi_0x200.b.wrap_ctrl_mode && SPI_NOT_SLAVE(SPIx))
    {
        for (i = 0; i < len; i++)
        {
            /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
            while (!(SPIx->SPI_WRAP_SR & SPI_FLAG_TFNF));
            SPIx->SPI_DR[0] = (*pBuf++);
        }
        return;
    }
#endif
    for (i = 0; i < len; i++)
    {
        /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
        while (SPI_NOT_SLAVE(SPIx) && !(SPIx->SPI_M_S_SR & SPI_FLAG_TFNF));
        SPIx->SPI_DR[0] = (*pBuf++);
    }
}

/**
  * \brief  Transmits a number of words through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  pBuf : Words to be transmitted.
  * \param  len: Word length to be transmitted.
  * \return None
  */
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len)
{
    uint16_t i = 0;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (spi_0x200.b.wrap_ctrl_mode && SPI_NOT_SLAVE(SPIx))
    {
        for (i = 0; i < len; i++)
        {
            /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
            while (!(SPIx->SPI_WRAP_SR & SPI_FLAG_TFNF));
            SPIx->SPI_DR[0] = (*pBuf++);
        }
        return;
    }
#endif
    for (i = 0; i < len; i++)
    {
        /* Read TFNF bit status in SPI_SR register: SET is Tx FIFO is not full */
        while (SPI_NOT_SLAVE(SPIx) && !(SPIx->SPI_M_S_SR & SPI_FLAG_TFNF));
        SPIx->SPI_DR[0] = (*pBuf++);
    }
}

/**
  * \brief  Clear the specified SPI interrupt.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  SPI_IT: Specifies the SPI interrupt to clear.
  *         This parameter can be one of the following values:
  *         \arg SPI_INT_TXO: Transmit FIFO Overflow Interrupt .
  *         \arg SPI_INT_RXO: Receive FIFO Overflow Interrupt.
  *         \arg SPI_INT_RXU: Receive FIFO Underflow Interrupt.
  *         \arg SPI_INT_MST: Multi-Master Contention Interrupt.
  *         \arg SPI_INT_FAE: TX Frame Alignment Interrupt.
  *         \arg SPI_INT_TUF: Transmit FIFO Underflow Interrupt.
  *         \arg SPI_INT_RIG: Rising edge detect Interrupt.
  *         \arg SPI_INT_WRAP_TXE: TX NDF mode FIFO Transmit FIFO Empty Interrupt.
  *         \arg SPI_INT_WRAP_TXO: TX NDF mode FIFO Overflow Interrupt.
  *         \arg SPI_INT_WRAP_TXD: TX NDF mode transmit done Interrupt.
  * \return None.
  */
void SPI_ClearINTPendingBit(SPI_TypeDef *SPIx, uint16_t SPI_IT)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

    if (SPI_IT & SPI_INT_TXO)
    {
        (void)SPIx->SPI_TXOICR;
    }

    if (SPI_IT & SPI_INT_RXO)
    {
        (void)SPIx->SPI_RXOICR;
    }

    if (SPI_IT & SPI_INT_RXU)
    {
        (void)SPIx->SPI_RXUICR;
    }

    if (SPI_IT & SPI_INT_FAE)
    {
        (void)SPIx->SPI_M_S_MSTICR_FAEICR;
    }

    if (SPI_IT & SPI_INT_TUF)
    {
        (void)SPIx->SPI_M_S_IDR_TXUICR;
    }

    if (SPI_IT & SPI_INT_RIG)
    {
        (void)SPIx->SPI_M_S_VERSION_ID_SSRICR;
    }

#if (SPI_SUPPORT_WRAP_MODE == 1)
    if (SPI_IT & (SPI_INT_WRAP_TXD | SPI_INT_WRAP_TXO))
    {
        (void)SPIx->SPI_WRAP_ICR;
    }
#endif
}

/**
  * \brief  Transmits a data through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  Data: Data to be transmitted.
  * \return None.
  */
void SPI_SendData(SPI_TypeDef *SPIx, uint32_t Data)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (spi_0x200.b.wrap_ctrl_mode && SPI_NOT_SLAVE(SPIx))
    {
        while (!(SPIx->SPI_WRAP_SR & SPI_FLAG_TFNF));
        SPIx->SPI_DR[0] = Data;
        return;
    }
#endif
    while (SPI_NOT_SLAVE(SPIx) && !(SPIx->SPI_M_S_SR & SPI_FLAG_TFNF));
    SPIx->SPI_DR[0] = Data;
}

/**
  * \brief  Received data by the SPI peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \return The most recent received data.
  */
uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    return (uint32_t)SPIx->SPI_DR[0];
}

/**
  * \brief  Get data length in Tx FIFO through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \return Data length in Tx FIFO.
  */
uint8_t SPI_GetTxFIFOLen(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPI_TXFLR_TypeDef spi_0x20 = {.d32 = SPIx->SPI_TXFLR};
    return spi_0x20.b.txtfl;
}

/**
  * \brief  Get data length in Rx FIFO through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \return Data length in Rx FIFO.
  */
uint8_t SPI_GetRxFIFOLen(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPI_RXFLR_TypeDef spi_0x24 = {.d32 = SPIx->SPI_RXFLR};
    return spi_0x24.b.rxtfl;
}

/**
  * \brief  Change SPI direction mode.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  dir: Value of direction mode.
  * \return None.
  */
void SPI_ChangeDirection(SPI_TypeDef *SPIx, uint16_t dir)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_DIRECTION_MODE(dir));

    /* Disable the selected SPI peripheral */
    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = 0;
    SPIx->SPI_SPIENR = spi_0x08.d32;

    /* Change SPI direction mode */
    SPI_M_CTRL0_TypeDef spi_0x00 = {.d32 = SPIx->SPI_M_S_CTRL0};
    spi_0x00.b.tmod = dir;
    SPIx->SPI_M_S_CTRL0 = spi_0x00.d32;

    /* Enable the selected SPI peripheral */
    spi_0x08.b.spi_en = 1;
    SPIx->SPI_SPIENR = spi_0x08.d32;
}

/**
  * \brief  Set read Data length only in EEPROM mode through the SPIx peripheral,which
            enables you to receive up to 64 KB of data in a continuous transfer.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  len: Length of read data which can be 1 to 65536.
  * \return None.
  */
void SPI_SetReadLen(SPI_TypeDef *SPIx, uint16_t len)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    /* Disable the selected SPI peripheral */
    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = 0;
    SPIx->SPI_SPIENR = spi_0x08.d32;

    /* Set read length in SPI EEPROM or RX only mode */
    SPI_M_CTRL1_TypeDef spi_0x04 = {.d32 = SPIx->SPI_M_CTRL1};
    spi_0x04.b.ndf = len - 1;
    SPIx->SPI_M_CTRL1 = spi_0x04.d32;

    /* Enable the selected SPI peripheral */
    spi_0x08.b.spi_en = 1;
    SPIx->SPI_SPIENR = spi_0x08.d32;
}

/**
  * \brief  Set cs number through the SPIx peripheral.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  number: Number can be 0 to 2.
  * \return None.
 */
void SPI_SetCSNumber(SPI_TypeDef *SPIx, uint8_t number)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    /* set cs number */
    SPIx->SPI_M_SER = BIT(number);
}

/**
  * \brief  Check whether the specified SPI interrupt is set.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  SPI_IT: Specifies the SPI interrupt to check.
  *         This parameter can be one of the following values:
  *         \arg SPI_INT_MST: Multi-Master Contention Interrupt.
  *         \arg SPI_INT_FAE: TX Frame Alignment Interrupt.
  *         \arg SPI_INT_RXF: Receive FIFO Full Interrupt.
  *         \arg SPI_INT_RXO: Receive FIFO Overflow Interrupt.
  *         \arg SPI_INT_RXU: Receive FIFO Underflow Interrupt.
  *         \arg SPI_INT_TXO: Transmit FIFO Overflow Interrupt .
  *         \arg SPI_INT_TXE: Transmit FIFO Empty Interrupt.
  *         \arg SPI_INT_WRAP_TXD: TX NDF mode transmit done Interrupt.
  * \return The new state of SPI_IT (SET or RESET).
  */
ITStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, uint32_t SPI_IT)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

    ITStatus bit_status = RESET;

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (SPI_IT & (SPI_INT_WRAP_TXE | SPI_INT_WRAP_TXO | SPI_INT_WRAP_TXD))
    {
        if (spi_0x200.b.wrap_ctrl_mode)
        {
            if (SPIx->SPI_WRAP_ISR & (SPI_IT >> 8))
            {
                bit_status = SET;
            }
        }
        return  bit_status;
    }
#endif
    /* Check the status of the specified SPI flag */
    if ((SPIx->SPI_M_S_ISR & SPI_IT) != (uint32_t)RESET)
    {
        bit_status = SET;
    }

    /* Return the SPI_IT status */
    return  bit_status;
}

/**
  * \brief  Enable or disable the specified SPI interrupt source.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  SPI_IT: Specifies the SPI interrupt source to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg SPI_INT_TXE: Transmit FIFO empty interrupt.
  *         \arg SPI_INT_TXO: Transmit FIFO overflow interrupt.
  *         \arg SPI_INT_RXU: Receive FIFO underflow interrupt.
  *         \arg SPI_INT_RXO: Receive FIFO overflow interrupt.
  *         \arg SPI_INT_RXF: Receive FIFO full interrupt.
  *         \arg SPI_INT_MST: Multi-Master Contention Interrupt.
  *         \arg SPI_INT_FAE: TX Frame Alignment interrupt.
  *         \arg SPI_INT_TUF: Transmit FIFO underflow interrupt.
  *         \arg SPI_INT_RIG: Rising edge detect interrupt.
  *         \arg SPI_INT_WRAP_TXD: TX NDF mode transmit done Interrupt.
  * \param  NewState: New state of the specified SPI interrupt source.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void SPI_INTConfig(SPI_TypeDef *SPIx, uint16_t SPI_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if (SPI_IT & (SPI_INT_WRAP_TXE | SPI_INT_WRAP_TXO | SPI_INT_WRAP_TXD))
    {
        if (spi_0x200.b.wrap_ctrl_mode)
        {
            if (NewState != DISABLE)
            {
                SPIx->SPI_WRAP_IMR |= (SPI_IT >> 8);
            }
            else
            {
                SPIx->SPI_WRAP_IMR &= ~(SPI_IT >> 8);
            }
        }
    }
#endif
    if (NewState != DISABLE)
    {
        SPIx->SPI_M_S_IMR |= (SPI_IT & 0xff);
    }
    else
    {
        SPIx->SPI_M_S_IMR &= ~(SPI_IT & 0xff);
    }
}


/**
 * \brief  Check whether the specified SPI flag is set.
 *
 * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
 * \param  SPI_FLAG: Specifies the SPI flag to check.
 *         This parameter can be one of the following values:
 *         \arg SPI_FLAG_DCOL: Data Collision Error flag.Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *         \arg SPI_FLAG_TXE: Transmission error flag.Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *         \arg SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *         \arg SPI_FLAG_RFNE: Receive FIFO Not Empty flag.Set if receive FIFO is not empty.
 *         \arg SPI_FLAG_TFE: Transmit FIFO Empty flag.Set if transmit FIFO is empty.
 *         \arg SPI_FLAG_TFNF: Transmit FIFO Not Full flag.Set if transmit FIFO is not full.
 *         \arg SPI_FLAG_BUSY: SPI Busy flag.Set if it is actively transferring data.reset if it is idle or disabled.
 *
 * \return The new state of SPI_FLAG (SET or RESET).
 */
FlagStatus SPI_GetFlagState(SPI_TypeDef *SPIx, uint16_t SPI_FLAG)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_GET_FLAG(SPI_FLAG));

    FlagStatus bitstatus = RESET;

#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    if ((SPI_FLAG & (SPI_FLAG_WRAP_CS_EN | SPI_FLAG_WRAP_TFNF |
                     SPI_FLAG_WRAP_TFE)))
    {
        if ((spi_0x200.b.wrap_ctrl_mode))
        {
            if (SPIx->SPI_WRAP_SR & (SPI_FLAG >> 8))
            {
                bitstatus = SET;
            }
        }
        return  bitstatus;
    }
#endif
    /* Check the status of the specified SPI flag */
    if ((SPIx->SPI_M_S_SR & SPI_FLAG) != (uint8_t)RESET)
    {
        /* SPI_FLAG is set */
        bitstatus = SET;
    }

    /* Return the SPI_FLAG status */
    return  bitstatus;
}

/**
  * \brief  Enable or disable the SPIx GDMA interface.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  SPI_GDMAReq: Specifies the SPI GDMA transfer request to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         \arg SPI_GDMAReq_Tx: Tx buffer DMA transfer request.
  *         \arg SPI_GDMAReq_Rx: Rx buffer DMA transfer request.
  * \param  NewState: New state of the selected SPI GDMA transfer request.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void SPI_GDMACmd(SPI_TypeDef *SPIx, SPIGdmaTransferRequests_TypeDef SPI_GDMAReq,
                 FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_SPI_GDMAREQ(SPI_GDMAReq));

    if (NewState != DISABLE)
    {
        /* Enable the selected SPI GDMA request */
        SPIx->SPI_DMACR |= SPI_GDMAReq;
    }
    else
    {
        /* Disable the selected SPI GDMA request */
        SPIx->SPI_DMACR &= (uint16_t)~(SPI_GDMAReq);
    }
}

/**
  * \brief  Change SPI speed daynamically.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  precalser: Value of prescaler.
  *         This parameter can be one of the following values:
  *         \arg  SPI_BaudRatePrescaler_2
  *         \arg  SPI_BaudRatePrescaler_4
  *         \arg  SPI_BaudRatePrescaler_6
  *         \arg  SPI_BaudRatePrescaler_8
  *         \arg  SPI_BaudRatePrescaler_10
  *         \arg  SPI_BaudRatePrescaler_12
  *         \arg  SPI_BaudRatePrescaler_14
  *         \arg  SPI_BaudRatePrescaler_16
  *         \arg  SPI_BaudRatePrescaler_32
  *         \arg  SPI_BaudRatePrescaler_64
  *         \arg  SPI_BaudRatePrescaler_128
  *         \arg  SPI_BaudRatePrescaler_256
  * \return None.
  */
void SPI_ChangeClock(SPI_TypeDef *SPIx, uint32_t prescaler)
{
    /* Disable the selected SPI peripheral */
    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = 0;
    SPIx->SPI_SPIENR = spi_0x08.d32;

    /* Change SPI speed */
    SPI_M_BAUDR_TypeDef spi_0x14 = {.d32 = SPIx->SPI_M_BAUDR};
    spi_0x14.b.sckdv = prescaler & 0xFFFF;
    SPIx->SPI_M_BAUDR = spi_0x14.d32;

    /* Enable the selected SPI peripheral */
    spi_0x08.b.spi_en = 1;
    SPIx->SPI_SPIENR = spi_0x08.d32;
}

/**
  * \brief  Set SPI Rx sample delay.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  delay: This parameter can be 0 to 255.
  * \return None.
  */
void SPI_SetRxSampleDly(SPI_TypeDef *SPIx, uint32_t delay)
{
    /* Disable the selected SPI peripheral */
    SPI_SPIENR_TypeDef spi_0x08 = {.d32 = SPIx->SPI_SPIENR};
    spi_0x08.b.spi_en = 0;
    SPIx->SPI_SPIENR = spi_0x08.d32;

    /* Set SPI Rx sample delay */
    SPI_M_RSDR_TypeDef spi_0xf0 = {.d32 = SPIx->SPI_M_RSDR};
    spi_0xf0.b.rsd = delay & 0xFF;
    SPIx->SPI_M_RSDR = spi_0xf0.d32;

    /* Enable the selected SPI peripheral */
    spi_0x08.b.spi_en = 1;
    SPIx->SPI_SPIENR = spi_0x08.d32;
}

#if (SPI_SUPPORT_WRAP_MODE == 1)

/**
  * \brief  Enable or disable the specified SPI wrap mode start transfer.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  NewState: new state of the SPIx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void SPI_WrapModeStartTx(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    spi_0x200.b.mst_tx_fifo_en = NewState;
    SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
}

/**
  * \brief  Whether inverse CS active polarity.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  NewState: new state of the SPIx peripheral.
  *         This parameter can be one of the following values:
  *         \arg  ENABLE: Inverse CS active polarity, which means CS is low active.
  *         \arg  DISABLE: Not inverse CS active polarity, which means CS is high active.
  * \return None
  */
void SPI_InverseCSActivePolarity(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    spi_0x200.b.cs_inv_en = NewState;
    SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
}

/**
  * \brief  Whether drive MOSI low in idle state.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  NewState: new state of the SPIx peripheral.
  *         This parameter can be one of the following values:
  *         \arg  ENABLE: Drive MOSI low in idle state.
  *         \arg  DISABLE: Not drive MOSI low in idle state, which means MOSI is Hi-Z in idle state.
  * \return None
  */
void SPI_DriveMOSILow(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    spi_0x200.b.mosi_drv_low_en = NewState;
    SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
}

/**
  * \brief  Whether enable MOSI pull in idle state.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  NewState: new state of the SPIx peripheral.
  *         This parameter can be one of the following values:
  *         \arg  ENABLE: MOSI is pull down in idle state.
  *         \arg  DISABLE: MOSI is pull none in idle state.
  * \return  None
  */
void SPI_PullMOSIEn(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    spi_0x200.b.mosi_pull_en = NewState;
    SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
}

#endif

#if (SPI_SUPPORT_RAP_FUNCTION == 1)
void SPI_RAPModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_CTRL_TypeDef spi_0x200 = {.d32 = SPIx->SPI_WRAP_CTRL};
    spi_0x200.b.rap_ctrl_mode = NewState;
    SPIx->SPI_WRAP_CTRL = spi_0x200.d32;
}

void SPI_SetTaskCmdNum(SPI_TypeDef *SPIx, uint8_t num)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_TCMD_NUM_TypeDef spi_0x230 = {.d32 = SPIx->SPI_WRAP_TCMD_NUM};
    spi_0x230.b.task_cmd_num = num;
    SPIx->SPI_WRAP_TCMD_NUM = spi_0x230.d32;
}

void SPI_SetTaskWaitNum(SPI_TypeDef *SPIx, uint8_t num)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_TWAIT_NUM_TypeDef spi_0x234 = {.d32 = SPIx->SPI_WRAP_TWAIT_NUM};
    spi_0x234.b.task_wait_num = num;
    SPIx->SPI_WRAP_TWAIT_NUM = spi_0x234.d32;
}

void SPI_SetTaskTransferNum(SPI_TypeDef *SPIx, uint8_t num)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI_WRAP_TTRAN_NUM_TypeDef spi_0x238 = {.d32 = SPIx->SPI_WRAP_TTRAN_NUM};
    spi_0x238.b.task_tran_num = num;
    SPIx->SPI_WRAP_TTRAN_NUM = spi_0x238.d32;
}

void SPI_TaskTrigger(SPI_TypeDef *SPIx, uint32_t task)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPIx->SPI_WRAP_FW_ST |= BIT(task);
}

bool SPI_TaskEventStsCheck(SPI_TypeDef *SPIx, uint32_t te)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    return SPIx->SPI_WRAP_TASK_STS & BIT(te);
}

void SPI_TaskEventStsClear(SPI_TypeDef *SPIx, uint32_t te)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPIx->SPI_WRAP_TASK_STS |= BIT(te);
}
#endif

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

