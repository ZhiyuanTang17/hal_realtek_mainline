/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_uart.c
* \brief    This file provides all the UART firmware functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_uart.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the UART peripheral registers to their default reset values(turn off UART clock).
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \return None
  */
void UART_DeInit(UART_TypeDef *UARTx)
{
    assert_param(IS_UART_PERIPH(UARTx));

    switch ((uint32_t)UARTx)
    {
#ifdef UART0
    case (uint32_t)UART0:
        RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, DISABLE);
        break;
#endif
#ifdef UART1
    case (uint32_t)UART1:
        RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, DISABLE);
        break;
#endif
#ifdef UART2
    case (uint32_t)UART2:
        RCC_PeriphClockCmd(APBPeriph_UART2, APBPeriph_UART2_CLOCK, DISABLE);
        break;
#endif
#ifdef UART3
    case (uint32_t)UART3:
        RCC_PeriphClockCmd(APBPeriph_UART3, APBPeriph_UART3_CLOCK, DISABLE);
        break;
#endif
#ifdef UART4
    case (uint32_t)UART4:
        RCC_PeriphClockCmd(APBPeriph_UART4, APBPeriph_UART4_CLOCK, DISABLE);
        break;
#endif
#ifdef UART5
    case (uint32_t)UART5:
        RCC_PeriphClockCmd(APBPeriph_UART5, APBPeriph_UART5_CLOCK, DISABLE);
        break;
#endif
#ifdef UART6
    case (uint32_t)UART6:
        RCC_PeriphClockCmd(APBPeriph_UART6, APBPeriph_UART6_CLOCK, DISABLE);
        break;
#endif

    default:
        break;
    }
}

/**
  * \brief  Initializes the UART peripheral according to the specified
  *         parameters in the UART_InitStruct
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  UART_InitStruct: pointer to a UART_InitTypeDef structure that
  *         contains the configuration information for the specified UART peripheral
  * \return None
  */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLen));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_RX_FIFO_TRIGGER_LEVEL(UART_InitStruct->UART_RxThdLevel));
    assert_param(IS_UART_IDLE_TIME(UART_InitStruct->UART_IdleTime));
    assert_param(IS_UART_DMA_CFG(UART_InitStruct->UART_DmaEn));
    assert_param(IS_UART_AUTO_FLOW_CTRL(UART_InitStruct->UART_HardwareFlowControl));

    /* Clear DLAB bit*/
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Disable all interrupt */
    UARTx->UART_DLM_IER = 0x0;

    /* Read to clear Line Status Reg */
    (void) UARTx->UART_LSR;

    /* Clear FIFO */
    UART_FCR_TypeDef uart_0x08 = {.d32 = 0x0};
    uart_0x08.b.clear_rxfifo = 0x1;
#if UART_SUPPORT_CLEAR_TX_FIFO
    uart_0x08.b.clear_txfifo = 0x1;
#endif
    UARTx->UART_IIR_FCR = uart_0x08.d32;

    /* Set baudrate, firstly set DLAB bit */
    uart_0x0c.b.dlab = 0x1;
    UARTx->UART_LCR = uart_0x0c.d32;
    /* Set calibration parameters(OVSR) */
    UART_STSR_TypeDef uart_0x20 = {.d32 = UARTx->UART_STSR};
    uart_0x20.b.xfactor = UART_InitStruct->UART_Ovsr;
    UARTx->UART_STSR = uart_0x20.d32;
    /* Set calibration parameters(OVSR_adj) */
    UART_SCR_TypeDef uart_0x1c = {.d32 = UARTx->UART_SCR};
    uart_0x1c.b.xfactor_adj = UART_InitStruct->UART_OvsrAdj;
    UARTx->UART_SCR = uart_0x1c.d32;
    /* Set DLL and DLH */
    UARTx->UART_DLL = (UART_InitStruct->UART_Div & 0x00FF);
    UARTx->UART_DLM_IER = ((UART_InitStruct->UART_Div & 0xFF00) >> 8);
    /* After set baudrate, clear DLAB bit */
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set LCR reg */
    uart_0x0c.b.wls0 = UART_InitStruct->UART_WordLen;
    uart_0x0c.b.stb = UART_InitStruct->UART_StopBits;
    uart_0x0c.b.parity_sel = UART_InitStruct->UART_Parity;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set FCR reg, FIFO must enable */
    uart_0x08.d32 = 0x0;
    uart_0x08.b.rxfifo_error_en = ENABLE;
    uart_0x08.b.dma_mode = UART_InitStruct->UART_DmaEn;
    uart_0x08.b.rxfifo_trigger_level = UART_InitStruct->UART_RxThdLevel;
    uart_0x08.b.tx_fifo_th = UART_InitStruct->UART_TxThdLevel;
    UARTx->UART_IIR_FCR = uart_0x08.d32;

    /* Harware flow control */ //Bert check register
    UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
    uart_0x10.b.rts = UART_InitStruct->UART_HardwareFlowControl;
    uart_0x10.b.autoflow_en = UART_InitStruct->UART_HardwareFlowControl;
    UARTx->UART_CTRL0 = uart_0x10.d32;

    /* Set rx idle time */
    UARTx->UART_RX_TIMEOUT = (UART_InitStruct->UART_IdleTime);

    if (UART_InitStruct->UART_DmaEn == UART_DMA_ENABLE)
    {
        /* Config UART Tx dma parameter */
        UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
        if (UART_InitStruct->UART_TxDmaEn != DISABLE)
        {
            /* Mask uart TX threshold value */
            uart_0x28.b.txdma_en = ENABLE;
            uart_0x28.b.txdma_burstsize = UART_InitStruct->UART_TxWaterLevel;
        }
        /* Config UART Rx dma parameter */
        if (UART_InitStruct->UART_RxDmaEn != DISABLE)
        {
            /* Mask uart RX threshold value */
            uart_0x28.b.rxdma_en = ENABLE;
            uart_0x28.b.rxdma_burstsize = UART_InitStruct->UART_RxWaterLevel;
        }
        UARTx->UART_MISCR = uart_0x28.d32;
    }

    return;
}

/**
  * \brief  Fills each UART_InitStruct member with its default value.
  * \param  UART_InitStruct: pointer to an UART_InitTypeDef structure which will be initialized.
  * \return None
  */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct)
{
    //115200 default
    UART_InitStruct->UART_Div                 = 20;
    UART_InitStruct->UART_Ovsr                = 12;
    UART_InitStruct->UART_OvsrAdj             = 0x252;

    UART_InitStruct->UART_WordLen             = UART_WORD_LENGTH_8BIT;
    UART_InitStruct->UART_StopBits            = UART_STOP_BITS_1;
    UART_InitStruct->UART_Parity              = UART_PARITY_NO_PARTY;
    UART_InitStruct->UART_TxThdLevel          = 16; //1~29
    UART_InitStruct->UART_RxThdLevel          = 16; //1~29
    UART_InitStruct->UART_IdleTime            = UART_RX_IDLE_2BYTE; //idle interrupt wait time
    UART_InitStruct->UART_HardwareFlowControl = UART_HW_FLOW_CTRL_DISABLE;
    UART_InitStruct->UART_DmaEn               = UART_DMA_DISABLE;
    UART_InitStruct->UART_TxDmaEn             = DISABLE;
    UART_InitStruct->UART_RxDmaEn             = DISABLE;
    UART_InitStruct->UART_TxWaterLevel        = 15; //Better to equal TX_FIFO_SIZE(16)- GDMA_MSize
    UART_InitStruct->UART_RxWaterLevel        = 1; //Better to equal GDMA_MSize
    return;
}

/**
  * \brief  Mask or unmask the specified UART interrupts.
  * \param  UART_INT: specifies the IR interrupts sources to be mask or unmask.
  *         This parameter can be the following values:
  *         \arg UART_INT_MASK_RD_AVA: mask INTCR(erbi).
  *         \arg UART_INT_MASK_TX_FIFO_EMPTY: mask INTCR(etbei).
  *         \arg UART_INT_MASK_RX_LINE_STS: mask INTCR(elsi).
  *         \arg UART_INT_MASK_MODEM_STS: mask INTCR(edssi).
  *         \arg UART_INT_MASK_RX_BREAK: mask rx break interrupt.
  *         \arg UART_INT_MASK_RX_IDLE: mask rx idle interrupt.
  *         \arg UART_INT_MASK_TX_DONE: mask the interrupt tx done interrupt.
  *         \arg UART_INT_MASK_TX_THD: mask tx fifo threshold interrupt.
  * \param  NewState: new state of the specified UART interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void UART_MaskINTConfig(UART_TypeDef *UARTx, uint32_t UART_INT_MASK, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_INT_MASK(UART_INT_MASK));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        UARTx->UART_INT_MASK |= UART_INT_MASK;
    }
    else
    {
        UARTx->UART_INT_MASK &= ~(UART_INT_MASK);
    }
}

/**
  * \brief  Enable or disable the specified UART interrupts.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  UART_INT: specifies the UART interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg UART_INT_RD_AVA: Rx data avaliable interrupt source.
  *         \arg UART_INT_TX_FIFO_EMPTY: Tx FIFO empty interrupt source.
  *         \arg UART_INT_RX_LINE_STS: Rx line status interrupt source.
  *         \arg UART_INT_MODEM_STS: modem status interrupt source.
  *         \arg UART_INT_TX_DONE: Tx data done interrupt source.
  *         \arg UART_INT_TX_THD: Tx FIFO data <= thredhold interrupt source.
  *         \arg UART_INT_RX_BREAK: Rx break signal interrupt source.
  *         \arg UART_INT_RX_IDLE: Rx idle interrupt source.
  * \param  NewState: new state of the specified UART interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void UART_INTConfig(UART_TypeDef *UARTx, uint32_t UART_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_INT(UART_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (UART_INT & UART_INT_RX_IDLE)
    {
        if (NewState == ENABLE)
        {
            UARTx->UART_RX_TIMEOUT_EN |= BIT0;
            UARTx->UART_RX_TIMEOUT |= BIT31;
        }
        else
        {
            UARTx->UART_RX_TIMEOUT &= (~BIT31);
            UARTx->UART_RX_TIMEOUT_STS |= BIT0;
            UARTx->UART_RX_TIMEOUT_EN &= (~BIT0);
        }
    }

    if (UART_INT & 0x3F)
    {

        if (NewState == ENABLE)
        {
            /* Enable the selected UARTx interrupts */
            UARTx->UART_DLM_IER |= UART_INT;
        }
        else
        {
            /* Disable the selected UARTx interrupts */
            UARTx->UART_DLM_IER &= (uint32_t)~UART_INT;
        }
    }
    return;
}

/**
  * \brief  Send data to tx FIFO.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  inBuf: buffer to be written to Tx FIFO.
  * \param  num: number of data to be written.
  * \return None
  */
void UART_SendData(UART_TypeDef *UARTx, const uint8_t *inBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        UARTx->UART_RBR_THR = *inBuf++;
    }

    return;
}

#if UART_SUPPORT_HALF_WORD
/**
  * \brief  Send half word data to tx FIFO.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  inBuf: buffer to be written to Tx FIFO.
  * \param  num: number of data to be written.
  * \return None
  */
void UART_SendHalfWordData(UART_TypeDef *UARTx, const uint16_t *inBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        UARTx->UART_RBR_THR = *inBuf++;
    }

    return;
}
#endif

/**
  * \brief  Receive data from rx FIFO.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param[out] outBuf: buffer to save data read from UART FIFO.
  * \param  count: number of data to be read.
  * \return None
  */
void UART_ReceiveData(UART_TypeDef *UARTx, uint8_t *OutBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        *OutBuf++ = (uint8_t)UARTx->UART_RBR_THR;
    }

    return;
}

#if UART_SUPPORT_HALF_WORD
/**
  * \brief  Receive data from rx FIFO.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param[out] outBuf: buffer to save data read from UART FIFO.
  * \param  count: number of data to be read.
  * \return None
  */
void UART_ReceiveHalfWordData(UART_TypeDef *UARTx, uint16_t *OutBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        *OutBuf++ = (uint16_t)UARTx->UART_RBR_THR;
    }

    return;
}
#endif

/**
  * \brief  Change UART baudrate.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  div: parameter of the selected UART baudrate.
  * \param  ovsr: parameter of the selected UART baudrate.
  * \param  ovsr_adj: parameter of the selected UART baudrate.
  * \return None.
  */
void UART_SetBaudRate(UART_TypeDef *UARTx, uint16_t div, uint16_t ovsr, uint16_t ovsr_adj)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* Set baudrate, firstly set DLAB bit */
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.dlab = 0x1;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set calibration parameters(OVSR) */
    UART_STSR_TypeDef uart_0x20 = {.d32 = UARTx->UART_STSR};
    uart_0x20.b.xfactor = ovsr;
    UARTx->UART_STSR = uart_0x20.d32;

    /* Set calibration parameters(OVSR_adj) */
    UART_SCR_TypeDef uart_0x1c = {.d32 = UARTx->UART_SCR};
    uart_0x1c.b.xfactor_adj = ovsr_adj;
    UARTx->UART_SCR = uart_0x1c.d32;

    /* Set DLL and DLH */
    UARTx->UART_DLL = (div & 0x00FF);
    UARTx->UART_DLM_IER = ((div & 0xFF00) >> 8);

    /* After set baudrate, clear DLAB bit */
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;
}

/**
  * \brief  Set UART parameters.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  wordLen: data width of selected UART peripheral.
  * \param  parity: parity of selected UART peripheral.
  * \param  stopBits: stop bit of selected UART peripheral.
  * \return None
  */
void UART_SetParams(UART_TypeDef *UARTx, uint16_t wordLen, uint16_t parity, uint16_t stopBits)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* set LCR reg */
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.wls0 = wordLen;
    uart_0x0c.b.stb = stopBits;
    uart_0x0c.b.parity_sel = parity;
    UARTx->UART_LCR = uart_0x0c.d32;
}

/**
  * \brief  UART loop back mode config.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  NewState: new state, this parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void UART_LoopBackCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
    uart_0x10.b.loopback_en = NewState;
    UARTx->UART_CTRL0 = uart_0x10.d32;
}

/**
  * \brief  Checks whether the specified UART flag is set or not.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  UART_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *         \arg UART_FLAG_RX_DATA_RDY: rx data is avaliable.
  *         \arg UART_FLAG_RX_OVERRUN: rx overrun.
  *         \arg UART_FLAG_PARTY_ERR: parity error.
  *         \arg UART_FLAG_FRAME_ERR: UARTx frame error.
  *         \arg UART_FLAG_BREAK_ERR: UARTx break error.
  *         \arg UART_FLAG_THR_EMPTY: tx FIFO is empty.
  *         \arg UART_FLAG_THR_TSR_EMPTY: tx FIFO and tx shift reg are both empty.
  *         \arg UART_FLAG_RX_FIFO_ERR: rx FIFO error.
  *         \arg UART_FLAG_RX_IDLE.
  * \return The new state of UART_FLAG (SET or RESET).
  */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint32_t UART_FLAG)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_GET_FLAG(UART_FLAG));

    FlagStatus bitstatus = RESET;

    if (UART_FLAG == UART_FLAG_RX_IDLE)
    {
        if (UARTx->UART_RX_TIMEOUT_STS & BIT(0))
        {
            bitstatus = SET;
        }
    }
#if UART_SUPPORT_TX_DONE
    else if (UART_FLAG == UART_FLAG_TX_THD)
    {
        if (UARTx->UART_TX_THD_INT & BIT(0))
        {
            bitstatus = SET;
        }
    }
#endif
#if UART_SUPPORT_TX_THD
    else if (UART_FLAG == UART_FLAG_TX_DONE)
    {
        if (UARTx->UART_TXDONE_INT & BIT(0))
        {
            bitstatus = SET;
        }
    }
#endif
    else
    {
        if (UART_GetLineStatus(UARTx) & UART_FLAG)
        {
            bitstatus = SET;
        }
    }

    return bitstatus;
}

/**
  * \brief  Get line status.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \return Line status.
  */
uint8_t UART_GetLineStatus(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_LSR & (0x000000FF));
}

/**
 * \brief   Send one byte of data.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param   data: Byte data to send.
 * \return  None.
 */
void UART_SendByte(UART_TypeDef *UARTx, uint8_t data)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_RBR_THR = data;

    return;
}

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Send half word of data.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param   data: Byte data to send.
 * \return  None.
 */
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t data)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_RBR_THR = data;

    return;
}
#endif

/**
 * \brief   Read a byte of data from UART RX FIFO.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  Which byte data has been read.
 */
uint8_t UART_ReceiveByte(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_RBR_THR);
}

#if UART_SUPPORT_HALF_WORD
/**
 * \brief   Read a byte of data from UART RX FIFO.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  Which byte data has been read.
 */
uint8_t UART_ReceiveHalfWord(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint16_t)(UARTx->UART_RBR_THR);
}
#endif

/**
 * \brief   Get interrupt identifier of the selected UART peripheral.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  The interrupt identifier value.
 *          This return value can be one or a combination of the following:
 *          \retval UART_INT_ID_LINE_STATUS: Rx line status interrupt ID.
 *          \retval UART_INT_ID_RX_LEVEL_REACH: Rx data available or trigger level reached interrupt ID.
 *          \retval UART_INT_ID_RX_TMEOUT: Rx FIFO data timeout interrupt ID.
 *          \retval UART_INT_ID_TX_FIFO_EMPTY: Tx FIFO empty interrupt ID.
 *          \retval UART_INT_ID_MODEM_STATUS: Modem status interrupt ID.
 */
uint16_t UART_GetIID(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint16_t)(UARTx->UART_IIR_FCR & (0x0000000E));
}

#if UART_SUPPORT_CLEAR_TX_FIFO
/**
 * \brief   Clear Tx FIFO of the selected UART peripheral.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  None.
 */
void UART_ClearTxFIFO(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_IIR_FCR = (((UARTx->UART_STSR & BIT24) >> 21) | \
                           ((UARTx->UART_STSR & 0x7C000000) >> 18) | \
                           ((UARTx->UART_STSR & BIT25) >> 25) | \
                           FCR_CLEAR_TX_FIFO_Set);

    return;
}
#endif

/**
 * \brief   Clear Rx FIFO of the selected UART peripheral.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  None.
 */
void UART_ClearRxFIFO(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_IIR_FCR = (((UARTx->UART_STSR & BIT24) >> 21) | \
                           ((UARTx->UART_STSR & 0x7C000000) >> 18) | \
                           ((UARTx->UART_STSR & BIT25) >> 25) | \
                           FCR_CLEAR_RX_FIFO_Set);

    return;
}

/**
 * \brief   Get the data length in Tx FIFO of the selected UART peripheral.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  Data length in UART TX FIFO.
 */
uint8_t UART_GetTxFIFODataLen(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_RXTX_FIFO_WL & 0x1F);
}

/**
 * \brief   Get the data length in Rx FIFO of the selected UART peripheral.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \return  Data length in UART RX FIFO.
 */
uint8_t UART_GetRxFIFODataLen(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)((UARTx->UART_RXTX_FIFO_WL >> 8) & 0x3F);
}

/**
 * \brief    Enable/Disable DMA mode on UART side.
 * \param    UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param    NewState: Enable or disable UART DMA mode.
 *           This parameter can be one of the following values:
 *           \arg true: Enable UART DMA mode.
 *           \arg false: Disable UART DMA mode.
 * \return   None.
 */
void UART_TxDmaCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
    uart_0x28.b.txdma_en = NewState;
    UARTx->UART_MISCR = uart_0x28.d32;
}

/**
 * \brief    Enable/Disable DMA mode on UART side.
 * \param    UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param    NewState: Enable or disable UART DMA mode.
 *           This parameter can be one of the following values:
 *           \arg true: Enable UART DMA mode.
 *           \arg false: Disable UART DMA mode.
 * \return   None.
 */
void UART_RxDmaCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
    uart_0x28.b.rxdma_en = NewState;
    UARTx->UART_MISCR = uart_0x28.d32;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/
