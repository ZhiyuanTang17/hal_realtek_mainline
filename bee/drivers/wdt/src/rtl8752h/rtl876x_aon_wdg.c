/**
***************************************************************************************************
*        Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
***************************************************************************************************
* @file     rtl876x_aon_wdg.c
* @brief    This file provides all the AON Watch Dog firmware functions.
* @details
* @author   Serval Li
* @date     2017-06-27
* @version  v0.1
***************************************************************************************************
*/

#include "rtl876x.h"
#include "rtl876x_aon_wdg.h"
#include "patch_iodriver.h"

#define REG_FAST_WRITE_BASE_ADDR        (0x40000100UL)
#define REG_RTC_FAST_WDATA              (0x400001F0UL)
#define REG_RTC_FAST_ADDR               (0x400001F4UL)
#define REG_RTC_WR_STROBE               (0x400001F8UL)

/**
  * @brief  Fast write RTC register.
  * @param  offset: the register address.
  * @param  data: data which write to register.
  * @retval None
  */
void RTC_WriteReg(uint32_t regAddress, uint32_t data)
{
    if (patch_RTC_Register_Write)
    {
        if (patch_RTC_Register_Write(regAddress, data))
        {
            return;
        }
    }

    static bool is_called = false;

    if (is_called == false)
    {
        *((volatile uint32_t *)0x40000014) |= BIT(9);//no need run this every time
        is_called = true;
    }

    /* Write data */
    *((volatile uint32_t *)REG_RTC_FAST_WDATA) = data;
    /* Write RTC register address. Only offset */
    *((volatile uint32_t *)REG_RTC_FAST_ADDR) = regAddress - REG_FAST_WRITE_BASE_ADDR;
    *((volatile uint32_t *)REG_RTC_WR_STROBE) = 1;
}

/* Enable Write to CRT register */
#define AON_WDG_EnableWriteCRT() RTC_WriteReg((uint32_t)&AON_WDG->WP - SYSTEM_REG_BASE, AON_WDG->WP | BIT0)

/* Disable Write to CRT register */
#define AON_WDG_DisableWriteCRT() RTC_WriteReg((uint32_t)&AON_WDG->WP - SYSTEM_REG_BASE, AON_WDG->WP & ~BIT0);


void AON_WDG_Config(uint8_t reset_level, uint32_t comp, uint8_t cnt_ctl, uint8_t cnt_reload)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;

    aon_wdg.u.CRT_BITS.RST_LVL = reset_level;
    aon_wdg.u.CRT_BITS.COMP = comp;
    aon_wdg.u.CRT_BITS.CNT_CTL = cnt_ctl;
    aon_wdg.u.CRT_BITS.CNT_RELOAD = cnt_reload;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_ConfigResetLevel(uint8_t reset_level)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.RST_LVL = reset_level;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_ConfigComp(uint32_t comp)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.COMP = comp;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_ConfigCntCtl(uint8_t cnt_ctl)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.CNT_CTL = cnt_ctl;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_ConfigCntReload(uint8_t cnt_reload)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.CNT_RELOAD = cnt_reload;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_Enable(void)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.EN = 1;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_Disable(void)
{
    AON_WDG_TypeDef aon_wdg;

    aon_wdg.u.CRT = AON_WDG->u.CRT;
    aon_wdg.u.CRT_BITS.EN = 2;

    AON_WDG_EnableWriteCRT();
    RTC_WriteReg((uint32_t)&AON_WDG->u.CRT - SYSTEM_REG_BASE, aon_wdg.u.CRT);
    AON_WDG_DisableWriteCRT();
}

void AON_WDG_Restart(void)
{
    RTC_WriteReg((uint32_t)&AON_WDG->CNT_CLR, 1);
    RTC_WriteReg((uint32_t)&AON_WDG->CNT_CLR, 0);
}

void AON_WDG_SystemReset(void)
{
    AON_WDG_Config(1, 1, 1, 0);
    AON_WDG_Enable();

    while (1); /* wait until reset */
}
