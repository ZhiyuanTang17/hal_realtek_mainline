/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_timer.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define TIMER_TRIG_CTRL *((volatile uint32_t *)(SOC_VENDOR_REG_BASE + 0x0028))

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
uint32_t TIMER_GetTimerID(TIMER_TypeDef *TIMERx)
{
    uint32_t timerid = 0xFF;
    uint32_t timerbase = (uint32_t)TIMERx;

    if ((TIMERx == TIMER0_CH0) || (TIMERx == TIMER0_CH1))
    {
        timerid = (timerbase - TIMER0_BASE) / 0x50;
    }
    else if (TIMERx == TIMER2_CH0)
    {
        timerid = (timerbase - ENHANCED_TIMER_BASE) / 0x50;
    }
    else
    {
        timerid = (timerbase - TIMER1_BASE) / 0x50;
    }
    return timerid;
}

TIMERCASE_TypeDef TIMER_GetTimerCase(TIMER_TypeDef *TIMERx)
{
    if ((TIMERx == TIMER0_CH0) || (TIMERx == TIMER0_CH1))
    {
        return TIMER_CASE1;
    }
    else if ((TIMERx >= TIMER1_CH0) && (TIMERx <= TIMER1_CH5))
    {
        return TIMER_CASE7;
    }
    else if ((TIMERx >= TIMER1_CH6) && (TIMERx <= TIMER1_CH8))
    {
        return TIMER_CASE3;
    }
    else
    {
        return TIMER_CASE5;
    }
}

TIMER_ShareTypeDef *TIMER_GetTimerShareBase(TIMER_TypeDef *TIMERx)
{
    if ((TIMERx == TIMER0_CH0) || (TIMERx == TIMER0_CH1))
    {
        return TIMER0_SHARE;
    }
    else if (TIMERx == TIMER2_CH0)
    {
        return TIMER2_SHARE;
    }
    else
    {
        return TIMER1_SHARE;
    }
}

/**
  * \brief  TIMER clock config.
  * \param  TIMERx: Select the TIMER peripheral. \ref TIMER_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void TIMER_SetClock(TIMER_TypeDef *TIMERx, uint32_t ClockSrc, uint16_t ClockDiv)
{
    uint32_t timerid = TIMER_GetTimerID(TIMERx);

    if (TIMERx == TIMER0_CH0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_TIMER0, R_TIMER_1_CLK_DIV, ClockDiv);
    }
    else if (TIMERx == TIMER0_CH1)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_TIMER0, R_TIMER_2_CLK_DIV, ClockDiv);
    }
    else if (TIMERx == TIMER2_CH0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_TIMER2, R_ETIMER_CLK_DIV_SEL, ClockDiv);
    }
    else
    {
        uint32_t clkdivpos = 0;
        if (timerid <= 2) /* TIMER1_CH0 TIMER1_CH1 TIMER1_CH2 */
        {
            clkdivpos = 20 + timerid * 3; /* BIT20~22 BIT23~25 BIT26~28 */

            PCC_REG_UPDATE(PCC_REG_TIMER1_A, 7 << clkdivpos, ClockDiv << clkdivpos);
        }
        else if (timerid <= 5) /* TIMER1_CH3 TIMER1_CH4 TIMER1_CH5 */
        {
            clkdivpos = 20 + (timerid - 3) * 3; /* BIT20~22 BIT23~25 BIT26~28 */

            PCC_REG_UPDATE(PCC_REG_TIMER1_B, 7 << clkdivpos, ClockDiv << clkdivpos);
        }
        else /* TIMER1_CH6 TIMER1_CH7 TIMER1_CH8 */
        {
            clkdivpos = 20 + (timerid - 6) * 3; /* BIT20~22 BIT23~25 BIT26~28 */

            PCC_REG_UPDATE(PCC_REG_TIMER1_C, 7 << clkdivpos, ClockDiv << clkdivpos);
        }
    }
}

/**
 * \brief  Change the PWM dead zone clock source.
 * \param  PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param  PWM_Deazone_ClockSrc: New state of the PWMx peripheral.
 *         \arg PWM_CK_5M_TIMER: Use 5M clock source.
 *         \arg PWM_TIM_CLOCK_SRC_32K: Use 32k clock source.
 * \return None.
 * \note   To use this function, need to configure the corresponding timer.
 *         PWM2 ->> TIMER2, PWM3 ->> TIMER3.
 */
void TIMER_SetPWMDZClock(TIMER_TypeDef *TIMERx, uint16_t ClockSrc, uint16_t ClockDiv)
{
    uint32_t timerid = TIMER_GetTimerID(TIMERx);

    if (TIMERx == TIMER2_CH0)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_TIMER2_PWM, R_ETIMER_PWM_CLK_SRC_SEL, ClockSrc);
        PCC_REG_WRITE_BITFIELD(PCC_REG_TIMER2_PWM, R_ETIMER_PWM_CLK_DIV_SEL, ClockDiv);
    }
    else if (TIMERx == TIMER1_CH6 || TIMERx == TIMER1_CH7 || TIMERx == TIMER1_CH8)
    {
        /* TIMER1_CH6 TIMER1_CH7 TIMER1_CH8 */
        uint32_t clksrcpos = 16 + (timerid - 6); /* BIT16 BIT17 BIT18 */
        uint32_t clkdivpos = 19 + (timerid - 6) * 3; /* BIT19~21 BIT22~24 BIT25~28 */

        PCC_REG_UPDATE(PCC_REG_TIMER1_D, 1 << clksrcpos, ClockSrc << clksrcpos);
        PCC_REG_UPDATE(PCC_REG_TIMER1_D, 7 << clkdivpos, ClockDiv << clkdivpos);
    }
}

void TIMER_ClockAutoModeCmd(TIMER_TypeDef *TIMERx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));
    uint32_t timerid = TIMER_GetTimerID(TIMERx);

    if (Newstate == ENABLE)
    {
        if (TIMERx == TIMER2_CH0)
        {
            PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_ETIMER, 0);
        }
        else if ((TIMERx == TIMER0_CH0) || (TIMERx == TIMER0_CH1))
        {
            uint8_t timerxpos = 18 + timerid;
            PCC_REG_UPDATE(PCC_REG_PERION_CLK_REG4X, 1 << timerxpos, 0 << timerxpos);
        }
        else
        {
            uint8_t timerxpos = 20 + timerid;
            PCC_REG_UPDATE(PCC_REG_PERION_CLK_REG4X, 1 << timerxpos, 0 << timerxpos);
        }
    }
    else
    {
        if (TIMERx == TIMER2_CH0)
        {
            PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_ETIMER, 1);
            while (!PCC_REG_READ_BITFIELD(PCC_REG_PERION_CLK_REG0X, CLKEN_O_ETIMER));
        }
        else if ((TIMERx == TIMER0_CH0) || (TIMERx == TIMER0_CH1))
        {
            uint8_t timerxpos = 18 + timerid;
            PCC_REG_UPDATE(PCC_REG_PERION_CLK_REG4X, 1 << timerxpos, 1 << timerxpos);
            while (!((PCC_REG_READ(PCC_REG_PERION_CLK_REG0X) & BIT(timerxpos)) >> timerxpos));
        }
        else
        {
            uint8_t timerxpos = 20 + timerid;
            PCC_REG_UPDATE(PCC_REG_PERION_CLK_REG4X, 1 << timerxpos, 1 << timerxpos);
            while (!((PCC_REG_READ(PCC_REG_PERION_CLK_REG0X) & BIT(timerxpos)) >> timerxpos));
        }
    }


    return;
}

void TIMER_DynamicConfigCmd(TIMER_TypeDef *TIMERx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_TIMER_ALL_PERIPH(TIMERx));

    uint32_t timerid = TIMER_GetTimerID(TIMERx);
    TIMER_ShareTypeDef *sharebase = TIMER_GetTimerShareBase(TIMERx);

    if (Newstate == ENABLE)
    {
        sharebase->TIMER_Q_CH_FW_CTRL0 &= ~BIT(timerid);
    }
    else
    {
        sharebase->TIMER_Q_CH_FW_CTRL0 |= BIT(timerid);
    }

    return;
}

/*============================================================================*
 *                        LATCH Functions
 *============================================================================*/
const uint8_t latch_mapping_table[TOTAL_PIN_NUM] =
{
    0,  1,  2,  3,      /*!< P0_0 P0_1 P0_2 P0_3 */
    4,  5,  6,  7,      /*!< P0_4 P0_5 P0_6 P0_7 */
    8,  9,  12, 13,     /*!< P1_0 P1_1 P1_6 P1_7 */
    14, 15, 16, 17,     /*!< P2_0 P2_1 P2_2 P2_3 */
    18, 19, 20, 21,     /*!< P2_4 P2_5 P2_6 P2_7 */
    22, 23, 24, 25,     /*!< P3_0 P3_1 P3_2 P3_3 */
    26, 27, 28, 29,     /*!< P3_4 P3_5 P3_6 P4_0 */
    30, 31, 32, 49,     /*!< P4_1 P4_2 P4_3 MICBIAS */
    33, 34, 35, 36,     /*!< P5_1 P5_2 P6_0 P6_1 */
    37, 38, 39, 40,     /*!< P6_2 P6_3 P6_4 P6_5 */
    41, 42, 43, 44,     /*!< P6_6 P6_7 P7_0 P7_1 */
    45, 46, 47, 48,     /*!< SPIC_CSN SPIC_SCK SPIC_SI SPIC_SO */
    11, 10,             /*!< SPIC_WEN SPIC_HOLDEN */
};

void TIMER_SetLatchTriggerPad(TIMER_TypeDef *TIMERx, uint8_t Pin_num)
{
    uint8_t latch_number = latch_mapping_table[Pin_num];

    PLATFORM_REG_WRITE_BITFIELD(PLATFORM_REG_ENHTIMER_TRIG_CTRL, enhtimer_gpio_trig_sel, latch_number);
}

void TIMER_LatchDebCmd(TIMER_TypeDef *TIMERx, FunctionalState Newstate)
{
    PLATFORM_REG_WRITE_BITFIELD(PLATFORM_REG_ENHTIMER_TRIG_CTRL, enhtimer_gpio_trig_deb_en, Newstate);;
}

void TIMER_SetLatchDebClock(TIMER_TypeDef *TIMERx, uint16_t ClockSrc, uint16_t ClockDiv,
                            uint16_t CountLimit)
{
    /* Clock Source Fix 32K */
    PCC_REG_WRITE_BITFIELD(PCC_REG_GPIO_DEBOUNCE_2P4G, DBNC_DIV_SEL, ClockDiv);
    PLATFORM_REG_WRITE_BITFIELD(PLATFORM_REG_ENHTIMER_TRIG_CTRL, enhtimer_gpio_trig_deb_cnt_limit,
                                CountLimit);
}

/*============================================================================*
 *                        EXTI Functions
 *============================================================================*/
static struct
{
    IRQ_Fun timer_callback[2];
} timer_isr;

static void TIMER_ISRUpdate(uint32_t irqn, IRQ_Fun isr_handler)
{
    timer_isr.timer_callback[irqn & 0xFF] = isr_handler;
}

void TIMER0_CH0_CH1_ISR(void)
{
    uint32_t real_interrupt_status = TIMER0_SHARE->TIMER_INTR;
    while (real_interrupt_status)
    {
        uint8_t idx = 31 - __builtin_clz(real_interrupt_status);
        if (timer_isr.timer_callback[idx])
        {
            timer_isr.timer_callback[idx]();
        }
        real_interrupt_status &= ~BIT(idx);
    }
}

void TIMER_IRQInit(void)
{
    ram_vector_table_register(TIMER0_CH0_CH1_IRQn, TIMER_ISRUpdate);
    ram_vector_table_update(TIMER0_CH0_CH1_IRQn, TIMER0_CH0_CH1_ISR);
}


