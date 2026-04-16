/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_uart.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define UART_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x7E)//Force off 0x54
#define UART_MIN_OVSR                               10
#define UART_MAX_OVSR                               20
#define UART_OVSR_OFFSET                            5

uint32_t uart_clock_src_hz = 40000000;

static const uint32_t uart_baudrate_table[] =
{
    1200, 4800, 7200, 9600, 14400, 19200, 28800, 38400, 57600, 76800, 115200,  128000,  153600,
    230400, 460800, 500000, 921600, 1000000, 1382400, 1444400, 1500000, 1843200, 2000000, 3000000, 4000000
};

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * @brief  TX data to tx FIFO.
  * @param  UARTx: selected UART peripheral.
  * @param  data: buffer to be written to Tx FIFO.
  * @param  len: len of data to be written.
  * @return None
  */
void UART_TxData(UART_TypeDef *UARTx, const uint8_t *InBuf, uint16_t Count)
{
    uint32_t blkcount  = Count / UART_TX_FIFO_SIZE;
    uint32_t remainder = Count % UART_TX_FIFO_SIZE;
    uint32_t i = 0;

    for (i = 0; i < blkcount; ++i)
    {
        UART_SendData(UARTx, InBuf + UART_TX_FIFO_SIZE * i, UART_TX_FIFO_SIZE);
        /* wait tx fifo empty */
        while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_EMPTY) != SET);
    }

    /* send left bytes */
    if (remainder)
    {
        UART_SendData(UARTx, InBuf + UART_TX_FIFO_SIZE * i, remainder);
        /* wait tx fifo empty */
        while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_EMPTY) != SET);
    }
}

/**
 * \brief   UART one wire config.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param   NewState: UART one wire config is set or not.
 *          This parameter can be one of the following values:
 *          \arg true: UART one wire config is set.
 *          \arg false: UART one wire config is unset.
 * \return  None.
 */
void UART_OneWireConfig(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    uint32_t uart_id = (((uint32_t)UARTx - UART0_BASE) / 0x400);

    uint32_t uartx_one_wire_mask = PCC_REG_READ_BITFIELD(PCC_r_PMUX_TEST_MODE, R_PMUX_1_WIRE_UART_EN);

    uartx_one_wire_mask = NewState ?
                          (uartx_one_wire_mask | BIT(uart_id)) :
                          (uartx_one_wire_mask & ~BIT(uart_id));

    PCC_REG_WRITE_BITFIELD(PCC_r_PMUX_TEST_MODE, R_PMUX_1_WIRE_UART_EN, uartx_one_wire_mask);
}

/**
  * \brief  UART clock divider config.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock. \ref Clock_Divider
  * \return None
  */
void UART_SetClock(UART_TypeDef *UARTx, uint16_t ClockSrc, uint16_t ClockDiv)
{
    assert_param(IS_UART_DIV(ClockDiv));

    if (UARTx == UART0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_UART0, R_UART0_CLK_DIV_SEL, ClockDiv);
    }
    else if (UARTx == UART1)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_UART1, R_UART1_CLK_DIV_SEL, ClockDiv);
    }
    else if (UARTx == UART2)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_UART2, R_UART2_CLK_DIV_SEL, ClockDiv);
    }
    else if (UARTx == UART3)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_UART3, R_UART3_CLK_DIV_SEL, ClockDiv);
    }

    uint8_t divider = 1;
    if (ClockDiv < UART_CLOCK_DIV_40)
    {
        divider = BIT(ClockDiv);
    }
    else if (ClockDiv == UART_CLOCK_DIV_40)
    {
        divider = 40;
    }
    else if (ClockDiv == UART_CLOCK_DIV_64)
    {
        divider = 64;
    }
    if (ClockSrc == UART_CLOCK_SRC_40M)
    {
        uart_clock_src_hz = 40000000 / divider;
    }

    return;
}

void UART_ClockAutoModeCmd(UART_TypeDef *UARTx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    uint32_t uart_id = (((uint32_t)UARTx - UART0_BASE) / 0x400);
    volatile uint32_t *manual_force = (volatile uint32_t *)(PCC_REG_BASE + PCC_REG_PERION_CLK_REG4X);
    volatile uint32_t *clken_o = (volatile uint32_t *)(PCC_REG_BASE + PCC_REG_PERION_CLK_REG0X);

    if (Newstate == DISABLE)
    {
        *manual_force |= BIT(12 + uart_id);
        while (!(*clken_o & BIT(12 + uart_id)));
    }
    else
    {
        *manual_force &= ~BIT(12 + uart_id);
    }

    return;
}


static uint32_t UART_CalcAdjMask(uint32_t adj_num, uint32_t frame_len)
{
    /* Initialize accumulator to frame_len / 2 for center-aligned distribution */
    uint32_t mask = 0, acc = frame_len / 2;

    for (uint32_t i = 0; i < frame_len; i++)
    {
        acc += adj_num;

        /* Check if accumulator overflows the threshold (frame_len) */
        uint32_t bit = (acc >= frame_len);
        mask |= (bit << i);
        acc -= (bit * frame_len);
    }
    return mask;
}

static uint32_t UART_CalcBaudSettings(uint32_t baudrate, uint8_t frame_len,
                                      uint16_t *div, uint16_t *ovsr, uint16_t *adj)
{
    /* Default initialization */
    *div = 1;
    *ovsr = 10;
    *adj = 0;

    /*
     * Calculate target clock cycles per bit.
     * Note: it will overflow when Clock > 67MHz.
     */
    uint32_t target_bit_x64 = ((uart_clock_src_hz << 6) + (baudrate / 2)) / baudrate;
    uint32_t target_frame_x64 = target_bit_x64 * frame_len;
    uint32_t min_err = 0xFFFFFFFF;
    uint32_t last_div_try = 0;

    /* Iterate through valid Oversampling Ratios to find the best Div */
    for (uint32_t ovsr_try = UART_MAX_OVSR; ovsr_try >= UART_MIN_OVSR; ovsr_try--)
    {
        /* Calculate trial Divider based on current OVSR guess */
        uint32_t div_try = target_bit_x64 / (ovsr_try << 6);

        if (div_try == 0 || div_try == last_div_try) { continue; }
        last_div_try = div_try;

        /* Reverse calculation: Given this Div, what is the precise OVSR needed? */
        uint32_t ideal_ovsr_x64 = target_bit_x64 / div_try;

        /* Split precise OVSR into Integer and Fractional parts */
        uint32_t ovsr_int = ideal_ovsr_x64 >> 6;
        uint32_t ovsr_frac = ideal_ovsr_x64 & 0x3F;

        /* Filter invalid OVSR integer parts */
        if (ovsr_int < UART_MIN_OVSR || ovsr_int > UART_MAX_OVSR) { continue; }

        /*
         * Convert OVSR fraction to Adjustment bits (distributed over frame_len).
         * Formula: (Fraction/64) * FrameLen. Rounding (+32) included.
         */
        uint32_t adj_cnt = (ovsr_frac * frame_len + 32) >> 6;

        /* Handle carry-over case (e.g., fraction rounds up to a full bit) */
        if (adj_cnt >= frame_len)
        {
            adj_cnt = 0;
            ovsr_int++;
            if (ovsr_int > UART_MAX_OVSR) { continue; }
        }

        /* Generate the mask temporarily to verify constraints */
        uint32_t temp_adj = UART_CalcAdjMask(adj_cnt, frame_len);

#if (UART_SUPPORT_CONSTRAINT_START_AND_STOP_ADJ == 1)
        /*
         * Constraint Check:
         * Prevent that Start Bit (Bit 0) is 0,
         * meanwhile Last Stop Bit (Bit frame_len-1) is 1.
         */
        uint32_t start_bit_val = temp_adj & 0x01;
        uint32_t stop_bit_val  = (temp_adj >> (frame_len - 1)) & 0x01;

        if (start_bit_val == 0 && stop_bit_val == 1)
        {
            /* Constraint failed, skip this OVSR candidate */
            continue;
        }
#endif

        /* Calculate actual cycles generated by these parameters (x64 format) */
        uint32_t real_cycles_x64 = div_try * ((ovsr_int * frame_len + adj_cnt) << 6);

        /* Calculate absolute error */
        uint32_t diff = (real_cycles_x64 > target_frame_x64) ?
                        (real_cycles_x64 - target_frame_x64) :
                        (target_frame_x64 - real_cycles_x64);

        /* Update best result if error is smaller, or same error with larger Div (lower power?) */
        if (diff < min_err)
        {
            min_err = diff;
            *div = div_try;
            *ovsr = ovsr_int - UART_OVSR_OFFSET;
            *adj = temp_adj;

            if (diff == 0) { break; }
        }
    }

    uint32_t err_x10000 = 10000;
    if (min_err != 0xFFFFFFFF && target_frame_x64 > 0)
    {
        err_x10000 = (min_err * 10000 + (target_frame_x64 / 2)) / target_frame_x64;
    }
    return err_x10000;
}

uint32_t UART_GetBaudSettings(uint32_t baudrate,
                              uint8_t data_width, uint8_t parity, uint8_t stop_bits,
                              uint16_t *div, uint16_t *ovsr, uint16_t *adj)
{
    uint32_t target_baudrate = 115200;

    if ((uint32_t)baudrate < UART_BAUD_RATE_MAXIMUM)
    {
        target_baudrate = uart_baudrate_table[baudrate];
    }
    else
    {
        target_baudrate = baudrate;
    }

    uint8_t frame_len = 1 +
                        (uint8_t)(data_width == UART_WORD_LENGTH_7BIT ? 7 : 8) +
                        (uint8_t)(parity == UART_PARITY_NO_PARTY ? 0 : 1) +
                        (uint8_t)(stop_bits == UART_STOP_BITS_1 ? 1 : 2);

    return UART_CalcBaudSettings(target_baudrate, frame_len, div, ovsr, adj);
}



