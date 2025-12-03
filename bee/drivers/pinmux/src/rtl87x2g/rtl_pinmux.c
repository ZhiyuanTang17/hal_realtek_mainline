/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_pinmux.c
* \brief    This file provides all the PINMUX firmware functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_pinmux.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
static void Pad_WakeupConfig(uint8_t Pin_Num, PADWakeupCmd_TypeDef Status);
static void Pad_SetWakeupPolarity(uint8_t Pin_Num, PADWakeupPolarity_TypeDef Wakeup_Polarity);
static void Pad_WakeupDebounceCmd(uint8_t Pin_Num, PADWakeupDebCmd_TypeDef Status);
static uint8_t Pad_GetWakeupINTStatus(uint8_t Pin_Num);

static uint32_t pad_aon_read(uint32_t reg_addr)
{
    uint32_t reg_value = *((volatile uint32_t *)(reg_addr));
    return reg_value;
}

static void pad_aon_write(uint32_t reg_addr, uint32_t reg_value)
{
    *((volatile uint32_t *)(reg_addr)) = reg_value;
}
/*============================================================================*
 *                            Private Macros
 *============================================================================*/
#define Output_Val                  (BIT0)
#define Output_En                   (BIT1)
#define Pull_En                     (BIT2)
#define Pull_Direction              (BIT3)
#define Pull_Resistance             (BIT4)
#define WKEN                        (BIT5)
#define WKPOL                       (BIT6)
#define Driving_Current             (BIT7)
#define SHDN                        (BIT8)
#define AON_SEL                     (BIT9)
#define DEB                         (BIT10)

/* BIT11~BIT15 has diffs in different PAD */
#define DEDICATE                    (BIT11)
#define Out_Gate_En                 (BIT15)

/* IO_SYS_NS Configs */
#define DEBIO_WAKEUP                (BIT14)
#define DEBIO_WAKEUP_STS            (BIT15)

#define MAX_PIN_ADDR_NUM            ((TOTAL_PIN_NUM / 2) + ((TOTAL_PIN_NUM % 2) != 0)) /* pad Register number: 42 */
#define MAX_PIN_REG_NUM             ((TOTAL_PIN_NUM / 4) + ((TOTAL_PIN_NUM % 4) != 0)) /* pinmux Register number: 21 */

#define PAD_DEBOUNCE_WKUP_STS       0x40001AACUL
#define PAD_HS_MUX_SEL              (*((volatile uint32_t *)0x40002560UL))

#define GPIO_32KXTAL_SEL_GPIO_FUNC  (SYSTEM_REG_BASE + 0xC84)

const uint16_t PINADDR_TABLE[MAX_PIN_ADDR_NUM] =
{
    0x00, 0x04, 0x08, 0x0C, //P0
    0x10, 0x14, 0x18, 0x1C, //P1
    0x20, 0x24, 0x28, 0x2C, //P2
    0x30, 0x34, 0x38, 0x3C, //P3
    0x40, 0x44, 0x5C, 0x60, //P4
    0x64, 0x68, 0x6C, 0x70, //P5
    0x74, 0x78, 0x7C, 0x80, //P6
    0x84, 0x88, 0x8C, 0xff, //P7
    0x4C,                   //MICBIAS
    0x48,                   //32K_XI_XO
    0x58, 0xff,             //DAC
    0xB0, 0xB4, 0xB8, 0xBC, //P9
    0xC0, 0xC4,             //P10
};

const uint16_t WKSTATUS_TABLE[4] =
{
    0x00, 0x04, 0x08, 0x10
};

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Reset all pin to default value.
  * \param  None.
  * \note   two SWD pins will also be reset. Please use this function carefully.
  * \return None
  */
void Pinmux_Reset(void)
{
    for (uint8_t i = 0; i < MAX_PIN_REG_NUM; i++)
    {
        PINMUX->CFG[i] = 0x00;
    }

    return;
}

/**
  * \brief  Configure the specified pin to idle mode.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \return None
  */
void Pinmux_Deinit(uint8_t Pin_Num)
{
    uint8_t pinmux_reg_num;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    pinmux_reg_num = Pin_Num >> 2;
    PINMUX->CFG[pinmux_reg_num] &= ~(0xff << ((Pin_Num % 4) << 3));

    return;
}

/**
  * \brief  Configure the specified pin to its corresponding pin function.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param  Pin_Func: Pin function. \ref PIN_Function.
  * \return None
  */
void Pinmux_Config(uint8_t Pin_Num, uint8_t Pin_Func)
{
    uint8_t pinmux_reg_num;
    uint8_t reg_offset;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    pinmux_reg_num = Pin_Num >> 2;
    reg_offset = (Pin_Num & 0x03) << 3;

    PINMUX->CFG[pinmux_reg_num] = (PINMUX->CFG[pinmux_reg_num] & ~(0xFF << reg_offset))
                                  | Pin_Func << reg_offset;

    /* Select GPIO Func when XI32K and XO32K should config as GPIO */
    if (((Pin_Num >= XI32K) && (Pin_Num <= XO32K)) && Pin_Func == DWGPIO)
    {
        *((uint32_t *) GPIO_32KXTAL_SEL_GPIO_FUNC) |= BIT6;
    }

    return;
}

/**
  * \brief  Configure the specified pin to its corresponding pin AON function.
  * \param  Pin_Func: Pin AON function. \ref PINMUX_AON_Function.
  * \return None
  */
void Pinmux_AON_Config(uint16_t Pin_Func)
{
    uint32_t reg_value = AON_REG_READ(AON_REG3X_SYS);
    uint8_t offset = (Pin_Func & 0xFF00) >> 8;
    uint8_t value = Pin_Func & 0xFF;

    reg_value |= value << offset;

    AON_REG_WRITE(AON_REG3X_SYS, reg_value);
    return;
}

/**
  * \brief  Configure the specified pin to its corresponding pin high speed function.
  * \param  Pin_Func: High Speed function. \ref PINMUX_HS_Function.
  * \return None
  */
void Pinmux_HS_Config(uint32_t Pin_Func)
{
    if (Pin_Func < (uint32_t)SDHC_HS_MUX)
    {
        PAD_HS_MUX_SEL &= ~0xF;
        PAD_HS_MUX_SEL |= Pin_Func;
    }
    else
    {
        PAD_HS_MUX_SEL &= ~0xFFF0;
        PAD_HS_MUX_SEL |= (Pin_Func & 0xFFF0);
    }

    return;
}

/**
  * \brief  config the corresponding pad.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param  AON_PAD_MODE: use software mode or pinmux mode.
  *         This parameter can be one of the following values:
  *         \arg PAD_SW_MODE: use software mode.
  *         \arg PAD_PINMUX_MODE: use pinmux mode.
  * \param  AON_PAD_PwrOn: config power of pad.
  *         This parameter can be one of the following values:
  *         \arg PAD_NOT_PWRON: shutdown power of pad.
  *         \arg PAD_IS_PWRON: enable power of pad.
  * \param  AON_PAD_Pull: config pad pull mode.
  *         This parameter can be one of the following values:
  *         \arg PAD_PULL_NONE: no pull.
  *         \arg PAD_PULL_UP: pull this pin up.
  *         \arg PAD_PULL_DOWN: pull thi pin down.
  * \param  AON_PAD_E: config pad out put function.
  *         This parameter can be one of the following values:
  *         \arg PAD_OUT_DISABLE: disable pin output.
  *         \arg PAD_OUT_ENABLE: enable pad output.
  * \param  AON_PAD_O: config pin output level.
  *         This parameter can be one of the following values:
  *         \arg PAD_OUT_LOW: pad output low.
  *         \arg PAD_OUT_HIGH: pad output high.
  * \return None
  */
void Pad_Config(uint8_t                 Pin_Num,
                PADMode_TypeDef         AON_PAD_Mode,
                PADPowerMode_TypeDef    AON_PAD_PwrOn,
                PADPullMode_TypeDef     AON_PAD_Pull,
                PADOutputMode_TypeDef   AON_PAD_E,
                PADOutputValue_TypeDef  AON_PAD_O)
{
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];
    uint32_t reg_value;
    bool P40_gate_offset = 0;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }
    if (Pin_Num == P4_0)
    {
        P40_gate_offset = 1;
    }

    reg_value = pad_aon_read(reg_addr);

    if (reg_value_high_low)
    {
        /* GATE  RSVD  CLKP  CLKP  1111
           AMUX  DEB   ASEL  SHDN  1100
           DCUR  WKP   WKE   PULR  1111
           PULD  PULE  OUTE  OUTV  0000
         Clear reg value first. */
        reg_value &= 0xFCF0FFFF;

        /* Power on first */
        reg_value |= SHDN << 16;
        pad_aon_write(reg_addr, reg_value);

        if (AON_PAD_Mode)
        {
            reg_value |= AON_SEL << 16;
        }
        else
        {
            reg_value &= ~(AON_SEL << 16);
        }

        /* Pull config */
        if (AON_PAD_Pull == PAD_PULL_UP)
        {
            reg_value |= Pull_En << 16;
            reg_value &= ~(Pull_Direction << 16);
        }
        else if (AON_PAD_Pull == PAD_PULL_DOWN)
        {
            reg_value |= Pull_En << 16;
            reg_value |= Pull_Direction << 16;
        }
        else if (AON_PAD_Pull == PAD_PULL_NONE)
        {
            reg_value &= ~(Pull_En << 16);
        }

        /* Output Config */
        if (AON_PAD_E == PAD_OUT_ENABLE)
        {
            reg_value |= (Output_En | AON_PAD_O) << 16;
        }

        /* Enable pad output gate. */
        reg_value |= (Out_Gate_En >> P40_gate_offset) << 16;

        pad_aon_write(reg_addr, reg_value);
    }
    else
    {
        /* RSVD  GATE  CLKP  CLKP  1111
           AMUX  DEB   ASEL  SHDN  1100
           DCUR  WKP   WKE   PULR  1111
           PULD  PULE  OUTE  OUTV  0000
         Clear reg value first. */
        reg_value &= 0xFFFFFCF0;

        /* Power on first */
        reg_value |= SHDN;
        pad_aon_write(reg_addr, reg_value);

        if (AON_PAD_Mode)
        {
            reg_value |= AON_SEL;
        }
        else
        {
            reg_value &= ~AON_SEL;
        }

        /* Pull config */
        if (AON_PAD_Pull == PAD_PULL_UP)
        {
            reg_value |= Pull_En;
            reg_value &= ~Pull_Direction;
        }
        else if (AON_PAD_Pull == PAD_PULL_DOWN)
        {
            reg_value |= Pull_En;
            reg_value |= Pull_Direction;
        }
        else if (AON_PAD_Pull == PAD_PULL_NONE)
        {
            reg_value &= ~(Pull_En);
        }

        /* Output Config */
        if (AON_PAD_E == PAD_OUT_ENABLE)
        {
            reg_value |= (Output_En | AON_PAD_O);
        }

        /* Enable pad output gate. */
        reg_value |= Out_Gate_En >> P40_gate_offset;

        pad_aon_write(reg_addr, reg_value);
    }

    /* Pad control mode */
    if (AON_PAD_PwrOn == PAD_NOT_PWRON)
    {
        if (reg_value_high_low)
        {
            reg_value &= ~(SHDN << 16);
            pad_aon_write(reg_addr, reg_value);
        }
        else
        {
            reg_value &= ~SHDN ;
            pad_aon_write(reg_addr, reg_value);
        }
    }
}

/**
 * \brief  Config the corresponding pad dedicated function.
 * \param  Pin_Num: Pin number to be configured.
 *         This parameter is specific to certain PINs that support dedicated IO.
 * \param  Status: Select from AON_MUX_SEL or dedicated IO.
 * \return None
 */
void Pad_Dedicated_Config(uint8_t Pin_Num, FunctionalState Status)
{
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];
    uint32_t reg_value = 0;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Status == ENABLE)
    {
        if (reg_value_high_low)
        {
            reg_value |= DEDICATE << 16;
        }
        else
        {
            reg_value |= DEDICATE;
        }
    }
    else
    {
        if (reg_value_high_low)
        {
            reg_value &= ~(DEDICATE << 16);
        }
        else
        {
            reg_value &= ~DEDICATE;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
  * \brief  Enable the function of the wake-up system of the specified pin.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param  Polarity: use high or low level wakeu to wakeup system.
            This parameter is can be PAD_WAKEUP_POL_HIGH and PAD_WAKEUP_POL_LOW.
  * \param  DebounceEn: Enable or disable debounce function.
            This parameter is can be PAD_WK_DEBOUNCE_ENABLE and PAD_WK_DEBOUNCE_DISABLE.
  * \return None
  */
void System_WakeUpPinEnable(uint8_t Pin_Num, uint8_t Polarity, uint8_t DebounceEn)
{
    uint32_t reg_value = 0;
    uint32_t reg_addr = PAD_DEBOUNCE_WKUP_STS;

    reg_value = pad_aon_read(reg_addr);

    if (reg_value & DEBIO_WAKEUP_STS)
    {
        //Write 1 to clear debounceWakeupStatus
        pad_aon_write(reg_addr, reg_value | DEBIO_WAKEUP_STS);
    }

    Pad_SetWakeupPolarity(Pin_Num, Polarity);
    Pad_WakeupDebounceCmd(Pin_Num, DebounceEn);
    if (PAD_WAKEUP_DEB_ENABLE == DebounceEn)
    {
        System_WakeUpDebounceCmd(Pin_Num, PAD_WAKEUP_ENABLE);
    }
    Pad_WakeupConfig(Pin_Num, PAD_WAKEUP_ENABLE);
}

/**
  * \brief  Disable the function of the wake-up system of the specified pin.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \return None
  */
void System_WakeUpPinDisable(uint8_t Pin_Num)
{
    Pad_WakeupConfig(Pin_Num, PAD_WAKEUP_DISABLE);
}

/**
  * \brief  Check wake up pin interrupt status.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \return Pin interrupt status
  */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num)
{
    return Pad_GetWakeupINTStatus(Pin_Num);
}

/**
 * \brief  Enable or disable wake-up debounce function.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 *         \note: Pin_Num is invalid parameter for rtl87x2g series
 *                so that any pin can be filled in.
 * \param  PADWakeupCmd_TypeDef: wake-up system enable or disable.
 *         \arg PAD_WAKEUP_DISABLE: Disable wakeup.
 *         \arg PAD_WAKEUP_DISABLE: Enable wakeup.
 * \return None.
 */
void System_WakeUpDebounceCmd(uint8_t Pin_Num, PADWakeupCmd_TypeDef Status)
{
    uint32_t reg_value = 0;
    uint32_t reg_addr = PAD_DEBOUNCE_WKUP_STS;
    reg_value = pad_aon_read(reg_addr);

    if (Status == PAD_WAKEUP_ENABLE)
    {
        reg_value |= DEBIO_WAKEUP;
    }
    else if (Status == PAD_WAKEUP_DISABLE)
    {
        reg_value &= ~DEBIO_WAKEUP;
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Config wak-up system debounce time.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 *         \note: Pin_Num is invalid parameter for rtl87x2g series
 *                so that any pin can be filled in.
 * \param  time: Debounce time, 1 ~ 64ms.
 * \return None.
 */
void System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t time_ms)
{
    uint8_t cnt = time_ms;
    uint32_t reg_value = 0;
    uint32_t reg_addr = PAD_DEBOUNCE_WKUP_STS;
    reg_value = pad_aon_read(reg_addr);

    if (cnt > 0x3F)
    {
        cnt = 0x3F;
    }

    reg_value &= 0x00003F00;
    reg_value |= (cnt << 8) | DEBIO_WAKEUP;

    pad_aon_write(reg_addr, reg_value);
}

/**
  * \brief  Check debounce wake up status.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  *         \note: Pin_Num is invalid parameter for rtl87x2g series
  *                so that any pin can be filled in.
  * \return Debounce wakeup status.
  */
uint8_t System_WakeupDebounceStatus(uint8_t Pin_Num)
{
    uint8_t int_status = RESET;

    uint32_t reg_value = 0;
    uint32_t reg_addr = PAD_DEBOUNCE_WKUP_STS;

    reg_value = pad_aon_read(reg_addr);

    if (reg_value & DEBIO_WAKEUP_STS)
    {
        int_status = SET;
    }

    return int_status;
}

/**
  * \brief  Clear debounce wake up status.
  * \note:  Call this API will clear the debunce wakeup status bit.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  *         \note: Pin_Num is invalid parameter for rtl87x2g series
  *                so that any pin can be filled in.
  * \return None.
  */
void System_WakeupDebounceClear(uint8_t Pin_Num)
{
    uint32_t reg_value = 0;
    uint32_t reg_addr = PAD_DEBOUNCE_WKUP_STS;

    /* Write 1 to clear debounceWakeupStatus */
    reg_value = pad_aon_read(reg_addr);
    pad_aon_write(reg_addr, reg_value | DEBIO_WAKEUP_STS);
}

/**
 * \brief  Set pin drivering current.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets the pin drivering current.
 *         This parameter can be the following:
 *         \arg PAD_DRIVING_CURRENT_4mA.
 *         \arg PAD_DRIVING_CURRENT_8mA.
 * \return None.
 */
void Pad_SetDrivingCurrent(uint8_t Pin_Num, PADDrivingCurrent_TypeDef PAD_Driving_Current)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    uint8_t driver_current_e2 = 0;
    uint8_t driver_current_e3 = 0;
    if (PAD_Driving_Current == PAD_DRIVING_CURRENT_4mA)
    {
        driver_current_e2 = 0;
        driver_current_e3 = 0;
    }
    else if (PAD_Driving_Current == PAD_DRIVING_CURRENT_8mA)
    {
        driver_current_e2 = 1;
        driver_current_e3 = 0;
    }
    else if (PAD_Driving_Current == PAD_DRIVING_CURRENT_12mA)
    {
        driver_current_e2 = 0;
        driver_current_e3 = 1;
    }
    else if (PAD_Driving_Current == PAD_DRIVING_CURRENT_16mA)
    {
        driver_current_e2 = 1;
        driver_current_e3 = 1;
    }

    /* Set driving current E2 */
    reg_value = pad_aon_read(reg_addr);
    reg_value = driver_current_e2 ?
                (reg_value | (Driving_Current << (16 * reg_value_high_low))) :
                (reg_value & ~(Driving_Current << (16 * reg_value_high_low)));
    pad_aon_write(reg_addr, reg_value);

    /* Set driving current E3 */
    pad_aon_write(PAD_REG_BASE + 0xC8, driver_current_e3);
}

/**
 * \brief  Set pin control mode.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets the pin mode.
 *         This parameter can be the following:
 *         \arg PAD_SW_MODE: Software mode.
 *         \arg PAD_PINMUX_MODE: Default pinmux mode.
 * \return None.
 */
void Pad_SetControlMode(uint8_t Pin_Num, PADMode_TypeDef PAD_Mode)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (reg_value_high_low) //1
    {
        reg_value &= ~(AON_SEL << 16);
        reg_value |= PAD_Mode << 25;
    }
    else
    {
        reg_value &= ~AON_SEL;
        reg_value |= PAD_Mode << 9;
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Enable or disable pad output mode.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets whether the pin outputs the level in software mode.
 *         This parameter can be enumerated PAD_OUTPUT_ENABLE_Mod of the values:
 *         \arg PAD_OUT_DISABLE: Disable output.
 *         \arg PAD_OUT_ENABLE: Enable output.
 * \return None.
 */
void Pad_OutputCmd(uint8_t Pin_Num, PADOutputMode_TypeDef Status)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Status == PAD_OUT_ENABLE)
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Output_En << 16);
            reg_value |= Output_En << 16;
        }
        else
        {
            reg_value &= ~Output_En;
            reg_value |= Output_En;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Output_En << 16);
        }
        else
        {
            reg_value &= ~Output_En;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Configure pad output level.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: Config pin output level.
 *         This parameter can be one of the following values:
 *         \arg PAD_OUT_LOW: Pad output low.
 *         \arg PAD_OUT_HIGH: Pad output high.
 * \return None.
 */
void Pad_SetOutputLevel(uint8_t Pin_Num, uint8_t value)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (value)
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Output_Val << 16);
            reg_value |= Output_Val << 16;
        }
        else
        {
            reg_value &= ~Output_Val;
            reg_value |= Output_Val;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Output_Val << 16);
        }
        else
        {
            reg_value &= ~Output_Val;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Enable or disable pad pull-up / pull-down resistance function.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter enable or disable the the pad pin pull-up/pull-down function.
 *         This parameter can be the following:
 *         \arg DISABLE: Disable pad pull-up / pull-down function.
 *         \arg ENABLE: Enable  pad pull-up / pull-down function.
 * \return None.
 */
void Pad_PullCmd(uint8_t Pin_Num, FunctionalState Status)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Status == ENABLE)
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Pull_En << 16);
            reg_value |= Pull_En << 16;
        }
        else
        {
            reg_value &= ~Pull_En;
            reg_value |= Pull_En;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Pull_En << 16);
        }
        else
        {
            reg_value &= ~Pull_En;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Pad pull-up/pull-down resistance function selection.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets whether the pin pull-up or pull-down.
 *         This parameter can be the following:
 *         \arg 0: Config pad pull-up function.
 *         \arg 1: Config  pad pull-down function.
 * \return None.
 */
void Pad_SetPullMode(uint8_t Pin_Num, PADPullMode_TypeDef PAD_Pull_Mode)
{
    uint32_t tmp_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];
    uint32_t reg_value = 0;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    if (PAD_Pull_Mode == PAD_PULL_UP)
    {
        tmp_value |= Pull_En;
        tmp_value &= ~Pull_Direction;
    }
    else if (PAD_Pull_Mode == PAD_PULL_DOWN)
    {
        tmp_value |= Pull_En;
        tmp_value |= Pull_Direction;
    }
    else if (PAD_Pull_Mode == PAD_PULL_NONE)
    {
        tmp_value &= ~Pull_En;
    }

    reg_value = pad_aon_read(reg_addr);

    if (reg_value_high_low) //1
    {
        reg_value &= ~((Pull_Direction | Pull_En) << 16);
        reg_value |= tmp_value << 16;
    }
    else
    {
        reg_value &= ~(Pull_Direction | Pull_En);
        reg_value |= tmp_value;
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Configure the strength of pull-up/pull-down resistance.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets the strength of pull-up/pull-down resistance.
 *         This parameter can be the following:
 *         \arg PAD_WEAK_PULL: Resistance weak pull.
 *         \arg PAD_STRONG_PULL: Resistance strong pull.
 * \return None.
 */
void Pad_SetPullStrength(uint8_t Pin_Num, PADPullStrengthMode_TypeDef PAD_Pull_Strength_Mode)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (PAD_Pull_Strength_Mode == PAD_PULL_STRONG)
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Pull_Resistance << 16);
            reg_value |= Pull_Resistance << 16;
        }
        else
        {
            reg_value &= ~Pull_Resistance;
            reg_value |= Pull_Resistance;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(Pull_Resistance << 16);
        }
        else
        {
            reg_value &= ~Pull_Resistance;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Set pin power mode.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: This parameter sets the power supply mode of the pin,
 *                and the value is enumeration PADPowerMode_TypeDef One of the values.
 *         \arg PAD_NOT_PWRON: Power off.
 *         \arg PAD_IS_PWRON: Power on.
 * \return None.
 */
void Pad_PowerCmd(uint8_t Pin_Num, PADPowerMode_TypeDef PWR_Mode)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (PWR_Mode == PAD_IS_PWRON)
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(SHDN << 16);
            reg_value |= SHDN << 16;
        }
        else
        {
            reg_value &= ~SHDN;
            reg_value |= SHDN;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(SHDN << 16);
        }
        else
        {
            reg_value &= ~SHDN;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Enable the function of the wake-up system of the specified pin.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: Enable wake-up system function.
 *         \arg 0:Disable wake-up system function.
 *         \arg 1:Enable wake-up system function.
 * \return None.
 */
static void Pad_WakeupConfig(uint8_t Pin_Num, PADWakeupCmd_TypeDef Status)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Status == PAD_WAKEUP_ENABLE)
    {
        if (reg_value_high_low) //1
        {
            reg_value |= WKEN << 16;
        }
        else
        {
            reg_value |= WKEN;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(WKEN << 16);
        }
        else
        {
            reg_value &= ~WKEN;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Set polarity of wake-up system.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  Polarity: Polarity of wake-up system.
 *         This parameter can be the following:
 *         \arg PAD_WAKEUP_POL_LOW:Use low level wakeup.
 *         \arg PAD_WAKEUP_POL_HIGH: Use high level wakeup.
 * \return None.
 */
static void Pad_SetWakeupPolarity(uint8_t Pin_Num, PADWakeupPolarity_TypeDef Wakeup_Polarity)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Wakeup_Polarity == PAD_WAKEUP_POL_LOW)
    {
        if (reg_value_high_low) //1
        {
            reg_value |= WKPOL << 16;
        }
        else
        {
            reg_value |= WKPOL;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(WKPOL << 16);
        }
        else
        {
            reg_value &= ~WKPOL;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Config pin delay function.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \param  value: Enable delay function.
 *         \arg 0:Disable delay function.
 *         \arg 1:Enable delay function.
 * \return None.
 */
static void Pad_WakeupDebounceCmd(uint8_t Pin_Num, PADWakeupDebCmd_TypeDef Status)
{
    uint32_t reg_value = 0;
    uint32_t reg_value_high_low = Pin_Num % 2;
    uint32_t reg_addr = PAD_REG_BASE + PINADDR_TABLE[Pin_Num / 2];

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
        reg_value_high_low = (Pin_Num + 1) % 2;
    }
    if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        reg_addr = PAD_REG_BASE + PINADDR_TABLE[(Pin_Num + 1) / 2];
    }

    reg_value = pad_aon_read(reg_addr);

    if (Status == PAD_WAKEUP_DEB_ENABLE)
    {
        if (reg_value_high_low) //1
        {
            reg_value |= DEB << 16;
        }
        else
        {
            reg_value |= DEB;
        }
    }
    else
    {
        if (reg_value_high_low) //1
        {
            reg_value &= ~(DEB << 16);
        }
        else
        {
            reg_value &= ~DEB;
        }
    }

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief  Get pin interrupt status, function is the same as \ref system_WakeUpInterruptValue.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \return Interrupt status.
 *         \retval 0: The pin does not wake up the system.
 *         \retval 1: Pin wake up system.
 */
static uint8_t Pad_GetWakeupINTStatus(uint8_t Pin_Num)
{
    uint8_t  int_status = RESET;
    uint32_t bit_temp = 0;
    uint32_t num_temp = 0;
    uint32_t order_temp = 0;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return 0xFF;
    }

    //P0_0-P7_4
    if ((Pin_Num >= P0_0) && (Pin_Num <= P7_4))
    {
        num_temp = Pin_Num;
    }
    //MICBIAS
    else if (Pin_Num == MICBIAS)
    {
        num_temp = Pin_Num + 2;
    }
    //XI32K-XO32K
    else if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        num_temp = Pin_Num - 1;
    }
    //DACP-DACN
    else if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        order_temp = Pin_Num  % 2;
        if (order_temp)
        {
            num_temp = Pin_Num + 1;
        }
        else
        {
            num_temp = Pin_Num - 1;
        }

    }
    //P9_0-P10_2
    else if ((Pin_Num >= P9_0) && (Pin_Num <= P10_2))
    {
        num_temp = Pin_Num + 24;
    }

    bit_temp = num_temp % 32;

    uint32_t reg_addr = PAD_STS_REG_BASE + WKSTATUS_TABLE[num_temp / 32];
    uint32_t reg_value = pad_aon_read(reg_addr);

    if (reg_value & BIT(bit_temp))
    {
        int_status = SET;
    }

    return int_status;
}

/**
 * \brief  Clear the interrupt pending bit of the specified pin
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 * \return None.
 */
void Pad_ClearWakeupINTPendingBit(uint8_t Pin_Num)
{
    uint32_t bit_temp = 0;
    uint32_t num_temp = 0;
    uint32_t order_temp = 0;

    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    //P0_0-P7_4
    if ((Pin_Num >= P0_0) && (Pin_Num <= P7_4))
    {
        num_temp = Pin_Num;
    }
    //MICBIAS
    else if (Pin_Num == MICBIAS)
    {
        num_temp = Pin_Num + 2;
    }
    //XI32K-XO32K
    else if ((Pin_Num >= XI32K) && (Pin_Num <= XO32K))
    {
        num_temp = Pin_Num - 1;
    }
    //DACP-DACN
    else if ((Pin_Num >= DACP) && (Pin_Num <= DACN))
    {
        order_temp = Pin_Num  % 2;
        if (order_temp)
        {
            num_temp = Pin_Num + 1;
        }
        else
        {
            num_temp = Pin_Num - 1;
        }
    }
    //P9_0-P10_2
    else if ((Pin_Num >= P9_0) && (Pin_Num <= P10_2))
    {
        num_temp = Pin_Num + 24;
    }

    bit_temp = num_temp % 32;

    uint32_t reg_addr = PAD_STS_REG_BASE + WKSTATUS_TABLE[num_temp / 32];
    uint32_t reg_value = 0;

    reg_value = 1 << bit_temp;

    pad_aon_write(reg_addr, reg_value);
}

/**
 * \brief Clear all wake up pin interrupt pending bit.
 * \param  None.
 * \return None.
 */
void Pad_ClearAllWakeupINT(void)
{
    uint32_t reg_value = 0xFFFFFFFF;

    for (uint8_t i = 0; i < 4; i++)
    {
        pad_aon_write(PAD_STS_REG_BASE + WKSTATUS_TABLE[i], reg_value);
    }
}

/**
  * \brief  Store PINMUX register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the PINMUX peripheral.
  * \param  StoreBuf: Store buffer to store PINMUX register data.
  * \return None.
  */
void Pinmux_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    PINMUXStoreReg_Typedef *store_buf = (PINMUXStoreReg_Typedef *)StoreBuf;

    uint8_t i = 0;

    for (i = 0; i < MAX_PIN_REG_NUM; i++)
    {
        store_buf->pinmux_reg[i] = PINMUX->CFG[i];
    }

    return;
}

/**
  * \brief  Restore PINMUX register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the PINMUX peripheral.
  * \param  StoreBuf: Restore buffer to restore PINMUX register data.
  * \return None.
  */
void Pinmux_DLPSExit(void *PeriReg, void *StoreBuf)
{
    PINMUXStoreReg_Typedef *store_buf = (PINMUXStoreReg_Typedef *)StoreBuf;

    uint8_t i;

    for (i = 0; i < MAX_PIN_REG_NUM; i++)
    {
        PINMUX->CFG[i] = store_buf->pinmux_reg[i];
    }

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor *****END OF FILE****/
