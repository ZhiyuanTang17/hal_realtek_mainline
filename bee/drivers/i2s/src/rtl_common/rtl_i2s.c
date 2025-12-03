/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file      rtl_i2s.c
* \brief     This file provides all the I2S interface firmware functions.
* \details
* \author    echo gao
* \date      2023-10-17
* \version   v1.0
*********************************************************************************************************
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
    assert_param(IS_I2S_MCLK_OUTPUT_TYPE(I2S_InitStruct->I2S_MCLKOutput));
    assert_param(IS_I2S_DMA_CMD(I2S_InitStruct->I2S_DMACmd));

    /* set clk to 40M  echo todo*/
    if (I2Sx == I2S0)
    {
        if (I2S_InitStruct->I2S_ClockSource == I2S_CLK_40M)
        {
            /*
               SYSBLKCTRL->u_220.BITS_220.r_PON_FEN_SPORT0 = is_enable;
               SYSBLKCTRL->u_220.BITS_220.r_CLK_EN_SPORT0 = is_enable;
               SYSBLKCTRL->u_220.BITS_220.r_CLK_EN_SPORT_40M = 1;
               SYSBLKCTRL->u_224.BITS_224.r_SPORT0_PLL_CLK_SEL = 4;
            */
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_CLK_EN_SPORT_40M = 0x1;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.sp0_dsp_clk_sel = 0x4;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_sport_pll2_ck_en = 0x0;
        }
        else
        {
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_CLK_EN_SPORT_40M = 0x0;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.sp0_dsp_clk_sel = 0x0;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_sport_pll2_ck_en = 0x1;
        }

    }

    else if (I2Sx == I2S1)
    {
        if (I2S_InitStruct->I2S_ClockSource == I2S_CLK_40M)
        {
            /*
               SYSBLKCTRL->u_220.BITS_220.r_PON_FEN_SPORT0 = is_enable;
               SYSBLKCTRL->u_220.BITS_220.r_CLK_EN_SPORT0 = is_enable;
               SYSBLKCTRL->u_220.BITS_220.r_CLK_EN_SPORT_40M = 1;
               SYSBLKCTRL->u_224.BITS_224.r_SPORT0_PLL_CLK_SEL = 4;
            */
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_CLK_EN_SPORT_40M = 0x1;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.sp1_dsp_clk_sel = 0x4;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_sport_pll2_ck_en = 0x0;
        }
        else
        {
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_CLK_EN_SPORT_40M = 0x0;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.sp1_dsp_clk_sel = 0x0;
            PERIBLKCTRL_AUDIO->u_700.BITS_700.r_sport_pll2_ck_en = 0x1;
        }
    }


    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};
    I2S_FIFO_EN_CLK_CON_TypeDef i2s_reg_0x08 = {.d32 = I2Sx->I2S_FIFO_EN_CLK_CON};
    I2S_TX_FRA_DIV_TypeDef i2s_reg_0x1c = {.d32 = I2Sx->I2S_TX_FRA_DIV};
    I2S_LRCK_FIFO_TH_CON_TypeDef i2s_reg_0x20 = {.d32 = I2Sx->I2S_LRCK_FIFO_TH_CON};
    I2S_FORM_CON_TypeDef i2s_reg_0x28 = {.d32 = I2Sx->I2S_FORM_CON};
    I2S_RX_FRA_DIV_TypeDef i2s_reg_0x2c = {.d32 = I2Sx->I2S_RX_FRA_DIV};

    /* Reset I2S module */
    I2Sx->I2S_CTRL |= BIT0;
    I2Sx->I2S_CTRL &= ~BIT0;


    //trx_parameter_set
    i2s_reg_0x28.b.trx_same_fs = I2S_InitStruct->I2S_Scheme;
    i2s_reg_0x28.b.trx_same_ch = I2S_InitStruct->I2S_TxChannelType == I2S_InitStruct->I2S_RxChannelType;
    i2s_reg_0x28.b.trx_same_length = I2S_InitStruct->I2S_TxDataWidth == I2S_InitStruct->I2S_RxDataWidth;
    i2s_reg_0x28.b.trx_same_ch_len = I2S_InitStruct->I2S_TxChannelWidth ==
                                     I2S_InitStruct->I2S_RxChannelWidth;

    /* I2S  Set data format*/
    i2s_reg_0x28.b.sp_data_format_sel_rx =  I2S_InitStruct->I2S_RxDataFormat;
    i2s_reg_0x04.b.sp_data_format_sel_tx =  I2S_InitStruct->I2S_TxDataFormat;

    /* set rx config only if it's different from the corresponding tx setting */
    i2s_reg_0x28.b.sp_en_i2s_mono_rx =  I2S_InitStruct->I2S_RxChannelType;
    i2s_reg_0x04.b.sp_en_i2s_mono_tx =  I2S_InitStruct->I2S_TxChannelType;

    i2s_reg_0x28.b.sp_data_len_sel_rx = I2S_InitStruct->I2S_RxDataWidth;
    i2s_reg_0x04.b.sp_data_len_sel_tx = I2S_InitStruct->I2S_TxDataWidth;

    i2s_reg_0x28.b.sp_ch_len_sel_tx = I2S_InitStruct->I2S_TxChannelWidth;
    i2s_reg_0x28.b.sp_ch_len_sel_rx = I2S_InitStruct->I2S_RxChannelWidth;

    /* Configure I2S initialization parameters */
    i2s_reg_0x04.b.slave_data_sel = I2S_InitStruct->I2S_DeviceMode;
    i2s_reg_0x04.b.sp_sel_i2s_rx_ch = I2S_InitStruct->I2S_RxChSequence;
    i2s_reg_0x04.b.sp_sel_i2s_tx_ch = I2S_InitStruct->I2S_TxChSequence;
    i2s_reg_0x04.b.rx_lsb_first = I2S_InitStruct->I2S_RxBitSequence;
    i2s_reg_0x04.b.tx_lsb_first = I2S_InitStruct->I2S_TxBitSequence;

    if (I2S_InitStruct->I2S_DeviceMode == I2S_DeviceMode_Slave)
    {
        i2s_reg_0x28.b.trx_same_lrc = 1;
    }
    /* Disable I2S tx rx */
    i2s_reg_0x04.b.sp_tx_disable = 1;
    i2s_reg_0x04.b.sp_rx_disable = 1;

    /* Clear error counter */
    I2Sx->I2S_FIFO_EN_CLK_CON |=  I2S_CLR_RX_ERR_CNT_MSK | I2S_CLR_TX_ERR_CNT_MSK ;
    /* Clear error counter */
    I2Sx->I2S_FIFO_EN_CLK_CON &= I2S_CLR_RX_ERR_CNT_CLR & I2S_CLR_TX_ERR_CNT_CLR;

    /* Set fifo config */
    i2s_reg_0x08.b.tx_fifo_0_reg_0_en = I2S_InitStruct->I2S_TxFifoUsed & I2S_FIFO_USE_0_REG_0;
    i2s_reg_0x08.b.tx_fifo_0_reg_1_en = (I2S_InitStruct->I2S_TxFifoUsed & I2S_FIFO_USE_0_REG_1) >> 1;
    i2s_reg_0x08.b.rx_fifo_0_reg_0_en = I2S_InitStruct->I2S_RxFifoUsed & I2S_FIFO_USE_0_REG_0;
    i2s_reg_0x08.b.rx_fifo_0_reg_1_en = (I2S_InitStruct->I2S_RxFifoUsed & I2S_FIFO_USE_0_REG_1) >> 1;
    /* Configure GDMA burst size */
    i2s_reg_0x20.b.rxdma_burstsize =  I2S_InitStruct->I2S_RxWaterlevel;
    i2s_reg_0x20.b.txdma_burstsize =  I2S_InitStruct->I2S_TxWaterlevel;

    /* Configure I2S LRCLK, LRCLK=BCLK/BCLK_DIV */
    if (I2S_InitStruct->I2S_TxBClockDiv >= 255)
    {
        I2S_InitStruct->I2S_TxBClockDiv = 255;
    }
    if (I2S_InitStruct->I2S_RxBClockDiv >= 255)
    {
        I2S_InitStruct->I2S_RxBClockDiv = 255;
    }
    if (I2S_InitStruct->I2S_BClockFixEn == ENABLE)
    {
        i2s_reg_0x28.b.fixed_bclk = 1;
        i2s_reg_0x08.b.enable_mclk = 1;
    }
    else
    {
        i2s_reg_0x28.b.fixed_bclk = 0;
        i2s_reg_0x08.b.enable_mclk = 0;
    }

    i2s_reg_0x20.b.tx_bclk_div_ratio = I2S_InitStruct->I2S_TxBClockDiv;
    i2s_reg_0x20.b.rx_bclk_div_ratio = I2S_InitStruct->I2S_RxBClockDiv;
    /* Configure I2S BCLK */
    i2s_reg_0x1c.b.tx_mi =  I2S_InitStruct->I2S_TxBClockMi;
    i2s_reg_0x1c.b.tx_ni =  I2S_InitStruct->I2S_TxBClockNi;
    i2s_reg_0x1c.b.tx_mi_ni_update = 1;
    i2s_reg_0x2c.b.rx_mi =  I2S_InitStruct->I2S_RxBClockMi;
    i2s_reg_0x2c.b.rx_ni =  I2S_InitStruct->I2S_RxBClockNi;
    i2s_reg_0x2c.b.rx_mi_ni_update = 1;


    I2Sx->I2S_CTRL =  i2s_reg_0x04.d32;
    I2Sx->I2S_FIFO_EN_CLK_CON = i2s_reg_0x08.d32;
    I2Sx->I2S_TX_FRA_DIV = i2s_reg_0x1c.d32 ;
    I2Sx->I2S_LRCK_FIFO_TH_CON = i2s_reg_0x20.d32;
    I2Sx->I2S_FORM_CON = i2s_reg_0x28.d32;
    I2Sx->I2S_RX_FRA_DIV = i2s_reg_0x2c.d32;

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
        RCC_PeriphClockCmd(APBPeriph_I2S0, APBPeriph_I2S0_CLOCK, DISABLE);
    }
    else  if (I2Sx == I2S1)
    {
        RCC_PeriphClockCmd(APBPeriph_I2S1, APBPeriph_I2S1_CLOCK, DISABLE);
    }

}

/**
  * \brief  Fills each I2S_InitStruct member with its default value.
  * \param  I2S_InitStruct: pointer to an I2S_InitTypeDef structure which will be initialized.
  * \return None
  */
void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct)
{
    I2S_InitStruct->I2S_ClockSource      = I2S_CLK_40M;
    I2S_InitStruct->I2S_Scheme           = I2S_SCHEME_SEPARATE;
    I2S_InitStruct->I2S_TxBClockMi       = 0x271;/* <!BCLK = 16K */
    I2S_InitStruct->I2S_TxBClockNi       = 0x10;
    I2S_InitStruct->I2S_TxBClockDiv      = 0x3F;
    I2S_InitStruct->I2S_RxBClockMi       = 0x271;/* <!BCLK = 16K */
    I2S_InitStruct->I2S_RxBClockNi       = 0x10;
    I2S_InitStruct->I2S_RxBClockDiv      = 0x3F;
    I2S_InitStruct->I2S_DeviceMode       = I2S_DeviceMode_Master;
    I2S_InitStruct->I2S_TxChannelType    = I2S_Channel_Mono;
    I2S_InitStruct->I2S_RxChannelType    = I2S_Channel_Mono;
    I2S_InitStruct->I2S_TxChSequence     = I2S_CH_L_R;
    I2S_InitStruct->I2S_RxChSequence     = I2S_CH_L_R;
    I2S_InitStruct->I2S_TxDataFormat     = I2S_Mode;
    I2S_InitStruct->I2S_RxDataFormat     = I2S_Mode;
    I2S_InitStruct->I2S_TxBitSequence    = I2S_MSB_First;
    I2S_InitStruct->I2S_RxBitSequence    = I2S_MSB_First;
    I2S_InitStruct->I2S_TxDataWidth      = I2S_Width_16Bits;
    I2S_InitStruct->I2S_RxDataWidth      = I2S_Width_16Bits;
    I2S_InitStruct->I2S_TxChannelWidth   = I2S_Width_32Bits;
    I2S_InitStruct->I2S_RxChannelWidth   = I2S_Width_32Bits;
    I2S_InitStruct->I2S_TxFifoUsed       = I2S_FIFO_USE_0_REG_0;
    I2S_InitStruct->I2S_RxFifoUsed       = I2S_FIFO_USE_0_REG_0;
    I2S_InitStruct->I2S_TxWaterlevel     = 16;
    I2S_InitStruct->I2S_RxWaterlevel     = 16;
    I2S_InitStruct->I2S_BClockFixEn      = DISABLE;
}

/**
  * \brief  Fills each I2S_DataSelect member with its default value.
  * \param  I2S_DataSelect: pointer to an I2S_DataSelTypeDef structure which will be initialized.
  * \return None
  */
void I2S_DataSelStructInit(I2S_DataSelTypeDef *I2S_DataSelect)
{

    I2S_DataSelect->tx_channel_map[0] = I2S_TX_FIFO_0_REG_0_L;
    I2S_DataSelect->tx_channel_map[1] = I2S_TX_FIFO_0_REG_0_R;
    I2S_DataSelect->tx_channel_map[2] = I2S_TX_FIFO_0_REG_1_L;
    I2S_DataSelect->tx_channel_map[3] = I2S_TX_FIFO_0_REG_1_R;

    I2S_DataSelect->rx_fifo_map[0] = I2S_RX_CHANNEL_0;
    I2S_DataSelect->rx_fifo_map[1] = I2S_RX_CHANNEL_1;
    I2S_DataSelect->rx_fifo_map[2] = I2S_RX_CHANNEL_2;
    I2S_DataSelect->rx_fifo_map[3] = I2S_RX_CHANNEL_3;
}
/**
  * \brief  Enable or disable the selected I2S mode.
  * \param  I2S: selected I2S peripheral.
  * \param  mode: selected I2S operation mode.
  *         This parameter can be the following values:
  *         \arg I2S_MODE_TX: transmission mode.
  *         \arg I2S_MODE_RX: receiving mode.
  * \param  NewState: new state of the operation mode.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void I2S_Cmd(I2S_TypeDef *I2Sx, uint32_t mode, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    I2S_CTRL_TypeDef i2s_reg_0x04 = {.d32 = I2Sx->I2S_CTRL};

    if (mode == I2S_MODE_TX)
    {
        i2s_reg_0x04.b.sp_start_tx = NewState;
        i2s_reg_0x04.b.sp_tx_disable = !NewState;
    }

    if (mode == I2S_MODE_RX)
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
  *         \arg I2S_INT_TX_VALID: Tx_fifo_data_valid_interrupt.
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

        I2Sx->I2S_INTR_CON |= I2S_INT << 16;
    }
    else
    {
        I2Sx->I2S_INTR_CON &= ~(I2S_INT << 16);
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
  *         \arg I2S_INT_TX_VALID: Tx_fifo_data_valid_interrupt.
  * \return The new state of LCD_FLAG (SET or RESET).
  */
ITStatus I2S_GetINTStatus(I2S_TypeDef *I2Sx, uint32_t I2S_INT)
{
    ITStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_I2S_INT_CONFIG(I2S_INT));

    if ((I2Sx->I2S_FIFO_STA & BIT16) || (I2Sx->I2S_FIFO_STA & (I2S_INT & 0x3F)))
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

    if (I2Sx == I2S0)
    {
        PERIBLKCTRL_AUDIO->u_708.BITS_708.r_SPORT0_EXT_CODEC = NewState;

    }
    if (I2Sx == I2S1)
    {
        PERIBLKCTRL_AUDIO->u_708.BITS_708.r_SPORT1_EXT_CODEC = NewState;
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
        /*Enable mclk mux */
        PERIBLKCTRL_AUDIO->u_708.BITS_708.r_SPORT0_MCLK_OUT = 0x1;
        PERIBLKCTRL_AUDIO->u_70C.BITS_70C.mclk2_pmux_sel = 0x1;
    }
    else
    {
        if (I2Sx == I2S1)
        {
            /*Enable mclk mux */
            PERIBLKCTRL_AUDIO->u_708.BITS_708.r_SPORT1_MCLK_OUT = 0x1;
            PERIBLKCTRL_AUDIO->u_70C.BITS_70C.mclk2_pmux_sel = 0x1;
        }
    }
}

/**
 * \brief   I2S0 communication selection which can be from intrnal codec or external codec.
 * \param[in] NewState: new state of I2S0 communication selection.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 */
void I2S_WithExtCodecCmd(I2S_TypeDef *I2Sx, FunctionalState NewState);


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
    I2S_RX_FRA_DIV_TypeDef i2s_reg_0x2c = {.d32 = I2Sx->I2S_RX_FRA_DIV};
    if (dir == I2S_MODE_TX)
    {
        /* Configure I2S BCLK */
        i2s_reg_0x1c.b.tx_mi =  I2S_BClockMi;
        i2s_reg_0x1c.b.tx_ni =  I2S_BClockNi;
        i2s_reg_0x1c.b.tx_mi_ni_update = 1;
    }
    else if (dir == I2S_MODE_RX)
    {
        i2s_reg_0x2c.b.rx_mi =  I2S_BClockMi;
        i2s_reg_0x2c.b.rx_ni =  I2S_BClockNi;
        i2s_reg_0x2c.b.rx_mi_ni_update = 1;
    }
    I2Sx->I2S_TX_FRA_DIV =  i2s_reg_0x1c.d32;
    I2Sx->I2S_RX_FRA_DIV =  i2s_reg_0x2c.d32;
    return;
}

/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 */
FlagStatus I2S_GetTxBClkStatus(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    if (I2Sx->I2S_TX_FRA_DIV & I2S_MI_NI_UPDATE_MSK)
    {
        return SET;
    }

    return RESET;
}

/**
 * \brief   Get BClk clock status.
 * \param[in] I2Sx: To select I2Sx peripheral, where x can be: 0 or 1.
 * \return  Execution status.
 * \retval  SET: BLCK is updating.
 * \retval  RESET: BLCK update is done.
 */
FlagStatus I2S_GetRxBClkStatus(I2S_TypeDef *I2Sx)
{
    /* Check the parameters */
    assert_param(IS_I2S_ALL_PERIPH(I2Sx));

    if (I2Sx->I2S_RX_FRA_DIV & I2S_MI_NI_UPDATE_MSK)
    {
        return SET;
    }

    return RESET;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

