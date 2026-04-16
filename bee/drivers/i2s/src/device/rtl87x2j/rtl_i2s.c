/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_i2s.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief Initializes the I2S peripheral according to the specified
  *   parameters in the I2S_InitStruct
  * \param  I2S: selected I2S peripheral.
  * \param  I2S_InitStruct: pointer to a I2S_InitTypeDef structure that
  *   contains the configuration information for the specified I2S peripheral
  * \return None
  */
void I2S_Init(I2S_TypeDef *I2Sx, I2S_InitTypeDef *I2S_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    assert_param(IS_I2S_DEVICE_MODE(I2S_InitStruct->I2S_DeviceMode));
    assert_param(IS_I2S_CHANNEL_TYPE(I2S_InitStruct->I2S_ChannelType));
    assert_param(IS_I2S_DATA_FORMAT(I2S_InitStruct->I2S_DataFormat));
    assert_param(IS_I2S_DATA_WIDTH(I2S_InitStruct->I2S_DataWidth));
    assert_param(IS_I2S_MCLK_OUTPUT_TYPE(I2S_InitStruct->I2S_MClockOutput));
    assert_param(IS_I2S_DMA_CMD(I2S_InitStruct->I2S_DMACmd));

    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};
    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    I2S_TX_FRA_DIV_TypeDef i2s_reg_0x1c = {.d32 = I2Sx->I2S_TX_FRA_DIV};
    I2S_LRCK_FIFO_TH_CON_TypeDef i2s_reg_0x20 = {.d32 = I2Sx->I2S_LRCK_FIFO_TH_CON};
    I2S_QACTIVE_CON_TypeDef i2s_reg_0x68 = {.d32 = I2Sx->I2S_QACTIVE_CON};

    /* Reset I2S module */
    I2Sx->I2S_CTRL |= BIT0;
    I2Sx->I2S_CTRL &= ~BIT0;

    /* Open I2S qactive function */
    i2s_reg_0x68.b.sport_func_en = ENABLE;
    I2Sx->I2S_QACTIVE_CON = i2s_reg_0x68.d32;

    /* I2S Set data format*/
    i2s_reg_0x04.b.sp_data_format_sel_tx =  I2S_InitStruct->I2S_DataFormat;
    i2s_reg_0x04.b.sp_en_i2s_mono_tx =  I2S_InitStruct->I2S_ChannelType;
    i2s_reg_0x04.b.sp_data_len_sel_tx = I2S_InitStruct->I2S_DataWidth;

    /* Configure I2S initialization parameters */
    i2s_reg_0x04.b.mclk_sel = I2S_InitStruct->I2S_MClockOutput;
    i2s_reg_0x04.b.slave_data_sel = I2S_InitStruct->I2S_DeviceMode;
    i2s_reg_0x04.b.sp_sel_i2s_rx_ch = I2S_InitStruct->I2S_RxChannelSequence;
    i2s_reg_0x04.b.sp_sel_i2s_tx_ch = I2S_InitStruct->I2S_TxChannelSequence;
    i2s_reg_0x04.b.rx_lsb_first = I2S_InitStruct->I2S_RxBitSequence;
    i2s_reg_0x04.b.tx_lsb_first = I2S_InitStruct->I2S_TxBitSequence;
    i2s_reg_0x04.b.dsp_ctl_mode = 0x1; // DSP and SPORT1 handshaking is enabled.
    /* Disable I2S tx rx */
    i2s_reg_0x04.b.sp_tx_disable = 1;
    i2s_reg_0x04.b.sp_rx_disable = 1;

    /* Configure I2S Clock Source parameters */
    if (I2S_InitStruct->I2S_ClockSource == I2S_CLOCK_SRC_40M)
    {
        i2s_reg_0x08.b.mode_40mhz = 0x1;
        i2s_reg_0x08.b.mode_128fs = 0x0;
    }
    else if (I2S_InitStruct->I2S_ClockSource == I2S_CLOCK_SRC_128FS)
    {
        i2s_reg_0x08.b.mode_128fs = 0x1;
        i2s_reg_0x08.b.mode_40mhz = 0x0;
    }
    else if (I2S_InitStruct->I2S_ClockSource == I2S_CLOCK_SRC_256FS)
    {
        i2s_reg_0x08.b.mode_128fs = 0x0;
        i2s_reg_0x08.b.mode_40mhz = 0x0;
    }

    i2s_reg_0x08.b.frame_sync_offset = I2S_FRAME_SYNC_OFFSET_DEFAULT;

    /* Configure DMA burst size */
    i2s_reg_0x20.b.rxdma_burstsize =  I2S_InitStruct->I2S_RxWaterlevel;
    i2s_reg_0x20.b.txdma_burstsize =  I2S_InitStruct->I2S_TxWaterlevel;

    /* Configure I2S BCLK */
    i2s_reg_0x1c.b.tx_mi =  I2S_InitStruct->I2S_BClockMi;
    i2s_reg_0x1c.b.tx_ni =  I2S_InitStruct->I2S_BClockNi;
    i2s_reg_0x1c.b.tx_mi_ni_update = 1;

    I2Sx->I2S_CTRL =  i2s_reg_0x04.d32;
    I2Sx->I2S_FIFO_EN_CLK_CON = i2s_reg_0x08.d32;

    /* Clear error counter */
    I2Sx->I2S_FIFO_EN_CLK_CON |=  I2S_CLR_RX_ERR_CNT_MSK | I2S_CLR_TX_ERR_CNT_MSK ;
    I2Sx->I2S_FIFO_EN_CLK_CON &= I2S_CLR_RX_ERR_CNT_CLR & I2S_CLR_TX_ERR_CNT_CLR;

    I2Sx->I2S_TX_FRA_DIV = i2s_reg_0x1c.d32 ;
    I2Sx->I2S_LRCK_FIFO_TH_CON = i2s_reg_0x20.d32;

}

/**
  * \brief  Deinitializes the I2S peripheral registers to their default values.
  * \param  I2S: selected I2S peripheral.
  * \return None
  */
void I2S_DeInit(I2S_TypeDef *I2Sx)
{
    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};
    i2s_reg_0x04.b.sp_reset = 1;
    I2Sx->I2S_CTRL =    i2s_reg_0x04.d32;

    if (I2Sx == I2S0)
    {
        RCC_ClockCmd(I2S_CLOCK, DISABLE);
    }
}

/**
  * \brief  Fills each I2S_InitStruct member with its default value.
  * \param  I2S_InitStruct: pointer to an I2S_InitTypeDef structure which will be initialized.
  * \return None
  */
void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct)
{
    I2S_InitStruct->I2S_ClockSource      = I2S_CLOCK_SRC_40M;
    I2S_InitStruct->I2S_BClockMi         = 0x271;/* <!BCLK = 16K */
    I2S_InitStruct->I2S_BClockNi         = 0x10;
    I2S_InitStruct->I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
    I2S_InitStruct->I2S_ChannelType      = I2S_CHANNEL_MONO;
    I2S_InitStruct->I2S_TxChannelSequence     = I2S_CH_SEQ_L_R;
    I2S_InitStruct->I2S_RxChannelSequence     = I2S_CH_SEQ_L_R;
    I2S_InitStruct->I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
    I2S_InitStruct->I2S_TxBitSequence    = I2S_MSB_FIRST;
    I2S_InitStruct->I2S_RxBitSequence    = I2S_MSB_FIRST;
    I2S_InitStruct->I2S_DataWidth        = I2S_WIDTH_16BITS ;
    I2S_InitStruct->I2S_TxWaterlevel     = 16;
    I2S_InitStruct->I2S_RxWaterlevel     = 16;
    I2S_InitStruct->I2S_MClockOutput       = I2S_MCLK_128FS;
}

/**
  * \brief  Enable or disable the selected I2S mode.
  * \param  I2S: selected I2S peripheral.
  * \param  I2S_Mode: selected I2S operation mode.
  *         This parameter can be the following values:
  *         \arg I2S_MODE_TX: transmission mode.
  *         \arg I2S_MODE_RX: receiving mode.
  * \param  NewState: new state of the operation mode.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void I2S_Cmd(I2S_TypeDef *I2Sx, I2SMode_TypeDef I2S_Mode, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};

    if (I2S_Mode == I2S_MODE_TX)
    {
        i2s_reg_0x04.b.sp_start_tx = NewState;
        i2s_reg_0x04.b.sp_tx_disable = !NewState;
    }

    if (I2S_Mode == I2S_MODE_RX)
    {
        i2s_reg_0x04.b.sp_start_rx = NewState;
        i2s_reg_0x04.b.sp_rx_disable = !NewState;
    }

    I2Sx->I2S_CTRL = i2s_reg_0x04.d32;
}


/**
  * \brief  Enable or disable the specified I2S interrupts.
  * \param  I2S: selected I2S peripheral.
  * \param  I2S_INT: specifies the I2S interrupts sources to be enable or disable.
  *         This parameter can be the following values:
  *         \arg I2S_INT_TX_IDLE: Transmit idle interrupt.
  *         \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt.
  *         \arg I2S_NT_TF_EMPTY: Transmit FIFO empty interrupt.
  *         \arg I2S_INT_RF_FULL: Receive FIFO full interrupt.
  *         \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt.
  *         \arg I2S_INT_RX_READY: Ready to receive interrupt.
  *         \arg I2S_INT_TX_READY: Ready to transmit interrupt.
  * \param  NewState: new state of the specified I2S interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void I2S_INTConfig(I2S_TypeDef *I2Sx, uint32_t I2S_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_MCU_INT_CONFIG(I2S_MCU_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Enable Interrupt */
    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};
    i2s_reg_0x04.b.dsp_ctl_mode = 1;
    I2Sx->I2S_CTRL = i2s_reg_0x04.d32;

    if (NewState == ENABLE)
    {

        I2Sx->I2S_FIFO_EN_CLK_CON |= I2S_INT << 24;
    }
    else
    {
        I2Sx->I2S_FIFO_EN_CLK_CON &= ~(I2S_INT << 24);
    }
}


/**
  * \brief  Get the specified I2S flag status.
  * \param  I2S: selected I2S peripheral.
  * \param  I2S_INT: the specified I2S interrupt.
  *         This parameter can be one of the following values:
  *         \arg I2S_INT_TX_IDLE: Transmit idle interrupt.
  *         \arg I2S_INT_RF_EMPTY: Receive FIFO empty interrupt.
  *         \arg I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt.
  *         \arg I2S_INT_RF_FULL: Receive FIFO full interrupt.
  *         \arg I2S_INT_TF_FULL: Transmit FIFO full interrupt.
  *         \arg I2S_INT_RX_READY: Ready to receive interrupt.
  *         \arg I2S_INT_TX_READY: Ready to transmit interrupt.
  * \return The new state of LCD_FLAG (SET or RESET).
  */
ITStatus I2S_GetINTStatus(I2S_TypeDef *I2Sx, uint32_t I2S_INT)
{
    ITStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_I2S_INT_CONFIG(I2S_INT));

    if ((I2Sx->I2S_FIFO_STA & (I2S_INT & 0x7F)))
    {
        bit_status = SET;
    }

    /* Return the I2S_INT status */
    return  bit_status;
}


/**
  * \brief  Clears the I2S interrupt pending bits.
  * \param  I2S: selected I2S peripheral.
  * \param  I2S_CLEAR_INT: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *         \arg I2S_CLEAR_INT_RX_READY: Clear ready to receive interrupt.
  *         \arg I2S_CLEAR_INT_TX_READY: Clear ready to transmit interrupt.
  * \return None
  */
void I2S_ClearINTPendingBit(I2S_TypeDef *I2Sx, uint32_t I2S_CLEAR_INT)
{
    /* Check the parameters */
    assert_param(IS_I2S_INT_CONFIG(I2S_CLEAR_INT));
    I2Sx->I2S_INTR_CON |= I2S_CLEAR_INT;
    I2Sx->I2S_INTR_CON &= I2S_CLEAR_INT;
}

/**
 * \brief   I2S communication selection which can be from intrnal codec or external codec.
 * \param   NewState: new state of I2S0 communication selection.
 *          This parameter can be: ENABLE or DISABLE.
 * \return  None.
 */
void I2S_WithExtCodecCmd(I2S_TypeDef *I2Sx, FunctionalState NewState)
{
    if (NewState == 0x1)
    {
        SPORT_EXT_CODEC_REG |= BIT27;
    }
    else
    {
        SPORT_EXT_CODEC_REG &= ~BIT27;
    }
}

/**
 * \brief   Transmits a data through the SPIx/I2Sx peripheral.
 * \param[in] I2Sx: To select the I2Sx peripheral, x can be 0 or 1.
 * \param[in] Data: Data to be transmitted.
 * \return None.
 */
void I2S_SendData(I2S_TypeDef *I2Sx, uint32_t Data)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    I2Sx->I2S_TX_FIFO_WR_ADDR = Data;
}


/**
 * \brief  Received data by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return Return the most recent received data.
 */
uint32_t I2S_ReceiveFIFOData(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    return  I2Sx->I2S_RX_FIFO_RD_ADDR;

}

/**
 * \brief   Get transmit FIFO free length by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \retval  Return the transmit FIFO free length.
 */
uint8_t I2S_GetTxFIFOFreeLen(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    return I2Sx->I2S_FIFO_CNT_STA & 0x3F ;
}

/**
 * \brief   Get receive FIFO data length by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  The data length of the receive FIFO.
 */
uint8_t I2S_GetRxFIFOLen(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    return ((I2Sx->I2S_FIFO_CNT_STA & 0x3F00) >> I2S_RX_FIFO_DEPTH_CNT_0_POS);
}

/**
 * \brief   Get the send error counter value by the I2Sx peripheral.
 * \param[in]  I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  The send error counter value .
 */
uint8_t I2S_GetTxErrCnt(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    return I2Sx->I2S_TX_RX_ERR_STA & 0xFF;
}

/**
 * \brief  Get the reception error counter value by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \retval  The reception error counter value .
 */
uint8_t I2S_GetRxErrCnt(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    return ((I2Sx->I2S_TX_RX_ERR_STA & 0xFFFF) >> I2S_RX_ERR_CNT_POS);
}

/**
 * \brief   Swap audio data bytes sequence which sent by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the bytes sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 */
void I2S_SwapBytesForSend(I2S_TypeDef *I2Sx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    i2s_reg_0x08.b.tx_src_byte_swap = NewState;
    I2Sx->I2S_FIFO_EN_CLK_CON =  i2s_reg_0x08.d32;
}

/**
 * \brief   Swap audio data bytes sequence which read by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the bytes sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 */
void I2S_SwapBytesForRead(I2S_TypeDef *I2Sx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    i2s_reg_0x08.b.rx_snk_byte_swap = NewState;
    I2Sx->I2S_FIFO_EN_CLK_CON =  i2s_reg_0x08.d32;
}

/**
 * \brief  Swap audio channel data which sent by the I2Sx peripheral..
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the left and right channel data sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 */
void I2S_SwapLRChDataForSend(I2S_TypeDef *I2Sx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    i2s_reg_0x08.b.tx_src_lr_swap = NewState;
    I2Sx->I2S_FIFO_EN_CLK_CON =  i2s_reg_0x08.d32;
}

/**
 * \brief   Swap audio channel data which read by the I2Sx peripheral.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of the left and right channel data sequence.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 */
void I2S_SwapLRChDataForRead(I2S_TypeDef *I2Sx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    i2s_reg_0x08.b.rx_snk_lr_swap = NewState;
    I2Sx->I2S_FIFO_EN_CLK_CON =  i2s_reg_0x08.d32;
}

/**
 * \brief   MCLK output selection which can be from I2S0 or I2S1.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] NewState: New state of MCLK output.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 */
void I2S_MCLKOutputSelectCmd(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    if (I2Sx == I2S0)
    {
//        /*Enable mclk mux */
//        PERIBLKCTRL_AUDIO->u_708.BITS_708.r_SPORT0_MCLK_OUT = 0x1;
//        PERIBLKCTRL_AUDIO->u_70C.BITS_70C.mclk2_pmux_sel = 0x1;
    }
}


/**
 * \brief   Config BClk clock.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \param[in] I2S_BClockMi: Mi parameter.
 * \param[in] I2S_BClockNi: Ni parameter.
 * \return  Execution status.
 * \retval  SET: Success.
 * \retval  RESET: Failure.
 */
void I2S_UpdateBClk(I2S_TypeDef *I2Sx, uint32_t dir, uint16_t I2S_BClockMi,
                    uint16_t I2S_BClockNi)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    I2S_TX_FRA_DIV_TypeDef i2s_reg_0x1c = {.d32 = I2Sx->I2S_TX_FRA_DIV};

    /* Configure I2S BCLK */
    i2s_reg_0x1c.b.tx_mi =  I2S_BClockMi;
    i2s_reg_0x1c.b.tx_ni =  I2S_BClockNi;
    i2s_reg_0x1c.b.tx_mi_ni_update = 1;

    I2Sx->I2S_TX_FRA_DIV =  i2s_reg_0x1c.d32;
    return;
}

/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 */
FlagStatus I2S_GetBClkStatus(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    if (I2Sx->I2S_TX_FRA_DIV & I2S_MI_NI_UPDATE_MSK)
    {
        return SET;
    }

    return RESET;
}

#if (I2S_SUPPORT_AUTO_CLOCK == 1)
void I2S_ClockAutoModeCmd(I2S_TypeDef *I2Sx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    if (Newstate == ENABLE)
    {
        I2Sx->I2S_QACTIVE_CON = I2S_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        I2Sx->I2S_QACTIVE_CON = I2S_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}
#endif



