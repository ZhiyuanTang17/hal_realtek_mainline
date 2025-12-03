/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_enh_tim.c
* \brief    This file provides all the ENHTIM firmware internal functions.
* \details
* \author   Bert
* \date     2024-08-01
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_enh_tim.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define PWM_EMG_STOP        BIT8

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
uint32_t ENHTIM_GetTimerID(ENHTIM_TypeDef *ENHTIMx)
{
    uint32_t enhtim_id = ((uint32_t)ENHTIMx - (uint32_t)ENH_TIM0) / 0x24;

    return enhtim_id;
}

ENHPWM_TypeDef *ENHTIM_GetPwmID(uint32_t enhtim_id)
{
    switch (enhtim_id)
    {
    case 0:
        return ENH_TIM0_PWM;
    case 1:
        return ENH_TIM1_PWM;
    case 2:
        return ENH_TIM2_PWM;
    case 3:
        return ENH_TIM3_PWM;
    default:
        return 0;
    }
}

bool ENHTIM_ClkGet(ENHTIM_TypeDef *ENHTIMx, ENHTIMClkSrc_TypdDef *ClockSrc,
                   ENHTIMClkDiv_TypeDef *ClockDiv)
{
    uint32_t enhtim_id = ((uint32_t)ENHTIMx - (uint32_t)ENH_TIM0) / 0x24;
    uint32_t enhtim_id_odd = enhtim_id % 2;
    uint32_t enhtim_id_temp = enhtim_id / 2;

    uint32_t temp_addr_value = *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp);
    *ClockSrc = (temp_addr_value >> 4) & 0x7;

    *ClockDiv = (((temp_addr_value >> (3 + 16 * enhtim_id_odd)) & BIT0) == 0) ? ENHTIM_CLOCK_DIVIDER_1 :
                ((temp_addr_value >> (16 * enhtim_id_odd)) & 0x7);

    return true;
}

void ENHTIM_ClkConfig(ENHTIM_TypeDef *ENHTIMx, ENHTIMClkSrc_TypdDef ClockSrc,
                      ENHTIMClkDiv_TypeDef ClockDiv)
{
    uint32_t enhtim_id = ((uint32_t)ENHTIMx - (uint32_t)ENH_TIM0) / 0x24;
    uint32_t enhtim_id_odd = enhtim_id % 2;
    uint32_t enhtim_id_temp = enhtim_id / 2;
    uint8_t ENHTIM_ClockDiv_En = ClockDiv == 0 ? DISABLE : ENABLE;

    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(0x7 << 4);
    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= (ClockSrc << 4);

    /*Clear ENHTIM Clock DIV */
    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(0xF << 16 * enhtim_id_odd);
    if ((ENHTIM_ClockDiv_En != DISABLE))
    {
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= BIT3 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= (ClockDiv << 16 * enhtim_id_odd);
    }
}

void ENHTIM_PWMDeadZoneEMStop(ENHTIM_TypeDef *ENHTIMx)
{
    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);
    ENHPWM_TypeDef *ENH_TIMx_PWM = ENHTIM_GetPwmID(enhtim_id);

    ENH_TIMx_PWM->ENHTIMER_PWM_CFG |= PWM_EMG_STOP;
}

void ENHTIM_ConfigLatchTrigger(uint32_t enhtim_id, const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    uint8_t ENHTIM_LatchTriggerPad =  ENHTIM_InitStruct->ENHTIM_LatchTriggerPad;
    uint32_t temp = 0xFF;

    /* Config Latch Count0 trigger GPIO pin. */

    if ((ENHTIM_LatchTriggerPad >= P0_0) && (ENHTIM_LatchTriggerPad <= P7_4))
    {
        temp = ENHTIM_LatchTriggerPad + 1;
    }
    else if ((ENHTIM_LatchTriggerPad >= MICBIAS) && (ENHTIM_LatchTriggerPad <= DACN))
    {
        temp = ENHTIM_LatchTriggerPad - 2;
    }
    else if ((ENHTIM_LatchTriggerPad >= P9_0) && (ENHTIM_LatchTriggerPad <= P10_2))
    {
        temp = ENHTIM_LatchTriggerPad - 5;
    }

    *((uint32_t *)(&(REG_ENHTIMER_0_LATCH_TRIG_CFG)) + enhtim_id) |= temp;

    /* Config gpio trigger target enhtimer channel selection. */
    *((uint32_t *)(&(REG_BT_GPIO_TRIG_ENHTIMER_CTRL))) &= ~0x7;
    *((uint32_t *)(&(REG_BT_GPIO_TRIG_ENHTIMER_CTRL))) |= enhtim_id + 1;
}

void ENHTIM_ConfigLatchTriggerBtTxOn(uint32_t enhtim_id,
                                     const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    /* Config bt tx on trigger target enhtimer channel selection. */
    *((uint32_t *)(&(REG_BT_TX_ON_TRIG_ENHTIMER_CTRL))) &= ~0x7;
    *((uint32_t *)(&(REG_BT_TX_ON_TRIG_ENHTIMER_CTRL))) |= enhtim_id + 1;
}

void ENHTIM_ConfigLatchTriggerBtAccHit(uint32_t enhtim_id,
                                       const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    /* Config bt acc hit trigger target enhtimer channel selection. */
    *((uint32_t *)(&(REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL))) &= ~0x7;
    *((uint32_t *)(&(REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL))) |= enhtim_id + 1;
}

void ENHTIM_PWMDeadzoneConfig(uint32_t enhtim_id, \
                              const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    ENHPWM_TypeDef *ENH_TIMx_PWM = ENHTIM_GetPwmID(enhtim_id);

    uint32_t enhtim_id_odd = enhtim_id % 2;
    uint32_t enhtim_id_temp = enhtim_id / 2;
    uint8_t ENHTIM_PWMDeadZoneClockSource = ENHTIM_InitStruct->ENHTIM_PWMDeadZoneClockSource;
    uint8_t  ENHTIM_PWMDeadZone_ClockDiv = ENHTIM_InitStruct->ENHTIM_PWMDeadZone_ClockDiv;
    uint8_t ENHTIM_PWMDeadZoneEn = ENHTIM_InitStruct->ENHTIM_PWMDeadZoneEn;
    uint32_t ENHTIM_DeadZoneSize = ENHTIM_InitStruct->ENHTIM_DeadZoneSize;
    uint8_t ENHTIM_PWMStopStateP = ENHTIM_InitStruct->ENHTIM_PWMStopStateP;
    uint8_t ENHTIM_PWMStopStateN = ENHTIM_InitStruct->ENHTIM_PWMStopStateN;
    uint8_t ENHTIM_PWMDeadZone_ClockDivEn = ENHTIM_PWMDeadZone_ClockDiv == 0 ? DISABLE : ENABLE;

    /* Set pwm1 deadzone mode, pwm1_pn based on enhance timer0 */

    ENHTIMER_PWM_CFG_TypeDef enhpwm_cfg = {.d32 = ENH_TIMx_PWM->ENHTIMER_PWM_CFG};
    if (ENHTIM_PWMDeadZoneEn == ENABLE)
    {
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= BIT12 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= BIT13 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= ((ENHTIM_PWMDeadZoneClockSource)
                                                                         << (11 + 16 * enhtim_id_odd));

        if ((ENHTIM_PWMDeadZone_ClockDivEn != DISABLE))
        {
            *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= BIT10 << 16 * enhtim_id_odd;
            *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(0x7 << (7 + 16 * enhtim_id_odd));
            *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= ((ENHTIM_PWMDeadZone_ClockDiv) <<
                                                                             (7 + 16 * enhtim_id_odd));
        }
        else
        {
            *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(BIT10 << 16 * enhtim_id_odd);
        }

        /* Enable pwm1 deadzone mode. */

        ENH_TIMx_PWM->ENHTIMER_PWM_CFG &= ~0xFFFF;
        enhpwm_cfg.b.enhtimer_pwm_dz_en = ENABLE;
        enhpwm_cfg.b.enhtimer_pwm_dz_stop_state_p = ENHTIM_PWMStopStateP;
        enhpwm_cfg.b.enhtimer_pwm_dz_stop_state_n = ENHTIM_PWMStopStateN;
        enhpwm_cfg.b.enhtimer_pwm_dz_size = ENHTIM_DeadZoneSize;
        ENH_TIMx_PWM->ENHTIMER_PWM_CFG = enhpwm_cfg.d32;
    }
    else
    {
        *((uint32_t *)(&REG_ENHTIMER_CLOCK_CTRL) + enhtim_id_temp) &= ~(BIT12 << 16 * enhtim_id_odd);
        *((uint32_t *)(&REG_ENHTIMER_CLOCK_CTRL) + enhtim_id_temp) &= ~(BIT13 << 16 * enhtim_id_odd);

        /* Disable pwm1 deadzone mode. */

        enhpwm_cfg.b.enhtimer_pwm_dz_en = DISABLE;
        ENH_TIMx_PWM->ENHTIMER_PWM_CFG = enhpwm_cfg.d32;
    }
}

#if ENHTIM_SUPPORT_PWM_SRC_SELECT
void ENHTIM_PWMSrcSelect(ENHTIM_TypeDef *ENHTIMx, ENHTIMPWMDZRef_TypeDef PWMSrcSel)
{
    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);
    ENHPWM_TypeDef *ENH_TIMx_PWM = ENHTIM_GetPwmID(enhtim_id);

    ENHTIMER_PWM_CFG_TypeDef enhtim_0x300 = {.d32 = ENH_TIMx_PWM->ENHTIMER_PWM_CFG};
    enhtim_0x300.b.enhtimer_pwm_dz_ref_sel = PWMSrcSel;
    ENH_TIMx_PWM->ENHTIMER_PWM_CFG = enhtim_0x300.d32;
}
#endif


RAM_FUNCTION
void ENHTIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    ENHTIMStoreReg_Typedef *store_buf = (ENHTIMStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);

    store_buf->enhtim_reg[29] = PERIBLKCTRL_PERI_CLK->u_344.REG_ENHTIMER_1_0_CLOCK_CTRL;
    store_buf->enhtim_reg[30] = PERIBLKCTRL_PERI_CLK->u_348.REG_ENHTIMER_3_2_CLOCK_CTRL;

    store_buf->enhtim_reg[0] = ENH_TIM0->ENHTIM_CONFIGURE;
    store_buf->enhtim_reg[1] = ENH_TIM0->ENHTIM_MAX_CNT;
    store_buf->enhtim_reg[2] = ENH_TIM0->ENHTIM_CCR;
    store_buf->enhtim_reg[3] = ENH_TIM0->ENHTIM_CCR_FIFO_ENTRY;

    store_buf->enhtim_reg[4] = ENH_TIM1->ENHTIM_CONFIGURE;
    store_buf->enhtim_reg[5] = ENH_TIM1->ENHTIM_MAX_CNT;
    store_buf->enhtim_reg[6] = ENH_TIM1->ENHTIM_CCR;
    store_buf->enhtim_reg[7] = ENH_TIM1->ENHTIM_CCR_FIFO_ENTRY;

    store_buf->enhtim_reg[8]  = ENH_TIM2->ENHTIM_CONFIGURE;
    store_buf->enhtim_reg[9]  = ENH_TIM2->ENHTIM_MAX_CNT;
    store_buf->enhtim_reg[10] = ENH_TIM2->ENHTIM_CCR;
    store_buf->enhtim_reg[11] = ENH_TIM2->ENHTIM_CCR_FIFO_ENTRY;

    store_buf->enhtim_reg[12] = ENH_TIM3->ENHTIM_CONFIGURE;
    store_buf->enhtim_reg[13] = ENH_TIM3->ENHTIM_MAX_CNT;
    store_buf->enhtim_reg[14] = ENH_TIM3->ENHTIM_CCR;
    store_buf->enhtim_reg[15] = ENH_TIM3->ENHTIM_CCR_FIFO_ENTRY;

    store_buf->enhtim_reg[16] = ENH_TIM_SHARE->ENHTIM_FIFO_CLR;
    store_buf->enhtim_reg[17] = ENH_TIM_SHARE->ENHTIM_CONTROL;
    store_buf->enhtim_reg[18] = ENH_TIM_SHARE->ENHTIM_INT_CONTROL;
    store_buf->enhtim_reg[19] = ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_0;
    store_buf->enhtim_reg[20] = ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_2;

    store_buf->enhtim_reg[21] = REG_ENHTIMER_0_LATCH_TRIG_CFG;
    store_buf->enhtim_reg[22] = REG_ENHTIMER_1_LATCH_TRIG_CFG;
    store_buf->enhtim_reg[23] = REG_ENHTIMER_2_LATCH_TRIG_CFG;
    store_buf->enhtim_reg[24] = REG_ENHTIMER_3_LATCH_TRIG_CFG;
    store_buf->enhtim_reg[25] = REG_BT_GPIO_TRIG_ENHTIMER_CTRL;
    store_buf->enhtim_reg[26] = REG_BT_TX_ON_TRIG_ENHTIMER_CTRL;
    store_buf->enhtim_reg[27] = REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL;
    store_buf->enhtim_reg[28] = REG_ENHTIMER_ONESHOT;

    store_buf->enhpwm_reg[0] = ENH_TIM0_PWM->ENHTIMER_PWM_CFG;
    store_buf->enhpwm_reg[1] = ENH_TIM1_PWM->ENHTIMER_PWM_CFG;
    store_buf->enhpwm_reg[2] = ENH_TIM2_PWM->ENHTIMER_PWM_CFG;
    store_buf->enhpwm_reg[3] = ENH_TIM3_PWM->ENHTIMER_PWM_CFG;
}

RAM_FUNCTION
void ENHTIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    ENHTIMStoreReg_Typedef *store_buf = (ENHTIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);
    PERIBLKCTRL_PERI_CLK->u_344.REG_ENHTIMER_1_0_CLOCK_CTRL = store_buf->enhtim_reg[29];
    PERIBLKCTRL_PERI_CLK->u_348.REG_ENHTIMER_3_2_CLOCK_CTRL = store_buf->enhtim_reg[30];

    ENH_TIM0->ENHTIM_CONFIGURE      = store_buf->enhtim_reg[0];
    ENH_TIM0->ENHTIM_MAX_CNT        = store_buf->enhtim_reg[1];
    ENH_TIM0->ENHTIM_CCR            = store_buf->enhtim_reg[2];
    ENH_TIM0->ENHTIM_CCR_FIFO_ENTRY = store_buf->enhtim_reg[3];

    ENH_TIM1->ENHTIM_CONFIGURE      = store_buf->enhtim_reg[4];
    ENH_TIM1->ENHTIM_MAX_CNT        = store_buf->enhtim_reg[5];
    ENH_TIM1->ENHTIM_CCR            = store_buf->enhtim_reg[6];
    ENH_TIM1->ENHTIM_CCR_FIFO_ENTRY = store_buf->enhtim_reg[7];

    ENH_TIM2->ENHTIM_CONFIGURE      = store_buf->enhtim_reg[8];
    ENH_TIM2->ENHTIM_MAX_CNT        = store_buf->enhtim_reg[9];
    ENH_TIM2->ENHTIM_CCR            = store_buf->enhtim_reg[10];
    ENH_TIM2->ENHTIM_CCR_FIFO_ENTRY = store_buf->enhtim_reg[11];

    ENH_TIM3->ENHTIM_CONFIGURE      = store_buf->enhtim_reg[12];
    ENH_TIM3->ENHTIM_MAX_CNT        = store_buf->enhtim_reg[13];
    ENH_TIM3->ENHTIM_CCR            = store_buf->enhtim_reg[14];
    ENH_TIM3->ENHTIM_CCR_FIFO_ENTRY = store_buf->enhtim_reg[15];

    ENH_TIM_SHARE->ENHTIM_FIFO_CLR            = store_buf->enhtim_reg[16];
    ENH_TIM_SHARE->ENHTIM_CONTROL             = store_buf->enhtim_reg[17] ;
    ENH_TIM_SHARE->ENHTIM_INT_CONTROL         = store_buf->enhtim_reg[18];
    ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_0 = store_buf->enhtim_reg[19];
    ENH_TIM_SHARE->ENHTIM_LATCH_INT_CONTROL_2 = store_buf->enhtim_reg[20];

    REG_ENHTIMER_0_LATCH_TRIG_CFG     =  store_buf->enhtim_reg[21];
    REG_ENHTIMER_1_LATCH_TRIG_CFG     =  store_buf->enhtim_reg[22];
    REG_ENHTIMER_2_LATCH_TRIG_CFG     =  store_buf->enhtim_reg[23];
    REG_ENHTIMER_3_LATCH_TRIG_CFG     =  store_buf->enhtim_reg[24];
    REG_BT_GPIO_TRIG_ENHTIMER_CTRL    =  store_buf->enhtim_reg[25];
    REG_BT_TX_ON_TRIG_ENHTIMER_CTRL   =  store_buf->enhtim_reg[26];
    REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL =  store_buf->enhtim_reg[27];
    REG_ENHTIMER_ONESHOT              =  store_buf->enhtim_reg[28];

    ENH_TIM0_PWM->ENHTIMER_PWM_CFG = store_buf->enhpwm_reg[0];
    ENH_TIM1_PWM->ENHTIMER_PWM_CFG = store_buf->enhpwm_reg[1];
    ENH_TIM2_PWM->ENHTIMER_PWM_CFG = store_buf->enhpwm_reg[2];
    ENH_TIM3_PWM->ENHTIMER_PWM_CFG = store_buf->enhpwm_reg[3];
}

/******************* (C) COPYRIGHT 2024 Realtek Semiconductor Corporation *****END OF FILE****/

