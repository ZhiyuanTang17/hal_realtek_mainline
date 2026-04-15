/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Includes ------------------------------------------------------------------*/
#include "rtl876x_rcc.h"
#include "rtl876x_gpio.h"
#include "app_section.h"

#ifdef _IS_ASIC_
#define GPIO_CLOCK_SOURCE         (40000000)
#define GPIO_CLOCK_SOURCE_KHZ     (40000)
#else
#define GPIO_CLOCK_SOURCE         (20000000)
#define GPIO_CLOCK_SOURCE_KHZ     (20000)
#endif

/**
  * @brief  Deinitializes the GPIO peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void GPIO_DeInit(void)
{
    RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, DISABLE);
}

/**
  * @brief  Initializes the GPIO peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_Init(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
    assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
    assert_param(IS_GPIOIT_LEVEL_TYPE(GPIO_InitStruct->GPIO_ITTrigger));
    assert_param(IS_GPIOIT_POLARITY_TYPE(GPIO_InitStruct->GPIO_ITPolarity));
    assert_param(IS_GPIOIT_DEBOUNCE_TYPE(GPIO_InitStruct->GPIO_ITDebounce));

    /* GPIO configure */
    if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT)
    {
        GPIO->DATADIR |= GPIO_InitStruct->GPIO_Pin;

        if (GPIO_InitStruct->GPIO_ControlMode == GPIO_SOFTWARE_MODE)
        {
            /* Config GPIO control software mode */
            GPIO->DATASRC &= (~GPIO_InitStruct->GPIO_Pin);
        }
        else
        {
            /* Config GPIO hardware control mode */
            GPIO->DATASRC |= (GPIO_InitStruct->GPIO_Pin);
        }

    }
    else
    {
        /*Configure GPIO input mode */
        GPIO->DATADIR = GPIO->DATADIR & (~GPIO_InitStruct->GPIO_Pin);

        if (GPIO_InitStruct->GPIO_ITCmd == ENABLE)
        {

            GPIO->INTMASK = ~GPIO_Pin_All;

            /* configure GPIO interrupt trigger type */
            if (GPIO_InitStruct->GPIO_ITTrigger == GPIO_INT_Trigger_LEVEL)
            {
                GPIO->INTBOTHEDGE &= ~GPIO_InitStruct->GPIO_Pin;
                GPIO->INTTYPE = GPIO->INTTYPE & (~GPIO_InitStruct->GPIO_Pin);

                /* Level-sensitive synchronization enable register */
                GPIO->LSSYNC |= GPIO_InitStruct->GPIO_Pin;
            }
            else if (GPIO_InitStruct->GPIO_ITTrigger == GPIO_INT_Trigger_EDGE)
            {
                GPIO->INTBOTHEDGE &= ~GPIO_InitStruct->GPIO_Pin;
                GPIO->INTTYPE = (GPIO->INTTYPE & (~GPIO_InitStruct->GPIO_Pin))
                                | GPIO_InitStruct->GPIO_Pin;
            }
            else
            {
                GPIO->INTBOTHEDGE |= GPIO_InitStruct->GPIO_Pin;
            }

            /* configure Interrupt polarity register */
            if (GPIO_InitStruct->GPIO_ITPolarity == GPIO_INT_POLARITY_ACTIVE_LOW)
            {
                GPIO->INTPOLARITY = GPIO->INTPOLARITY & (~GPIO_InitStruct->GPIO_Pin);
            }
            else
            {
                GPIO->INTPOLARITY = (GPIO->INTPOLARITY & (~GPIO_InitStruct->GPIO_Pin))
                                    | GPIO_InitStruct->GPIO_Pin;
            }
            /* Configure Debounce enable register */
            if (GPIO_InitStruct->GPIO_ITDebounce == GPIO_INT_DEBOUNCE_DISABLE)
            {
                GPIO->DEBOUNCE = GPIO->DEBOUNCE & (~GPIO_InitStruct->GPIO_Pin);
            }
            else
            {
                GPIO->DEBOUNCE = (GPIO->DEBOUNCE & (~GPIO_InitStruct->GPIO_Pin))
                                 | GPIO_InitStruct->GPIO_Pin;

#ifdef _IS_ASIC_
                /* Config debounce time , default debounce DIV is 14*/
                GPIO_DBCLK_DIV = (((0xd) << 8) | (1 << 12));
                GPIO_DBCLK_DIV |= ((((GPIO_InitStruct->GPIO_DebounceTime) * (GPIO_CLOCK_SOURCE_KHZ) >>
                                     (14)) - 1) & 0xff);
#else
                /* Config debounce time , default debounce DIV is 13*/
                GPIO_DBCLK_DIV = (((0x3) << 10) | (1 << 12));
                GPIO_DBCLK_DIV |= ((((GPIO_InitStruct->GPIO_DebounceTime) * (GPIO_CLOCK_SOURCE_KHZ) >>
                                     (13)) - 1) & 0xff);
#endif
            }

            /* Configure Interrupt enable register */
            //GPIO->INTEN |= GPIO_InitStruct->GPIO_Pin;
        }
    }
}

/**
  * @brief    Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct : pointer to a GPIO_InitTypeDef structure which will
  *    be initialized.
  * @retval None
  */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStruct->GPIO_Pin  = GPIO_Pin_All;
    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct->GPIO_ITCmd = DISABLE;
    GPIO_InitStruct->GPIO_ITTrigger = GPIO_INT_Trigger_LEVEL;
    GPIO_InitStruct->GPIO_ITPolarity = GPIO_INT_POLARITY_ACTIVE_LOW;
    GPIO_InitStruct->GPIO_ITDebounce = GPIO_INT_DEBOUNCE_DISABLE;
    GPIO_InitStruct->GPIO_ControlMode = GPIO_SOFTWARE_MODE;
    GPIO_InitStruct->GPIO_DebounceTime = 20;                 /* ms , can be 1~64 ms */
}

/**
  * @brief enable the specified GPIO interrupt.
  * @param  GPIO_Pin_x: where x can be 0 or 31.
  * @retval None
  */
void GPIO_INTConfig(uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected GPIO pin interrupts */
        GPIO->INTEN |= GPIO_Pin;
    }
    else
    {
        /* Disable the selected GPIO pin interrupts */
        GPIO->INTEN &= ~GPIO_Pin;
    }
}

/**
  * @brief clear the specified GPIO interrupt.
  * @param  GPIO_Pin_x: where x can be 0 or 31.
  * @retval None
  */
void GPIO_ClearINTPendingBit(uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIO->INTCLR = GPIO_Pin;
}

/**
  * @brief  mask the specified GPIO interrupt.
  * @param  GPIO_Pin_x: where x can be 0 or 31.
  * @retval None
  */
void GPIO_MaskINTConfig(uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        GPIO->INTMASK |= GPIO_Pin;
    }
    else
    {
        GPIO->INTMASK &= ~(GPIO_Pin);
    }
}

/**
 * \brief     Get the GPIO_Pin through the given PAD num.
 * \param[in] Pin_num: Pad num which can be from P0_0 to P5_2, please refer to rtl876x.h "Pin_Number" part.
 * \return    GPIO_Pin for GPIO initialization.
 */
uint32_t GPIO_GetPin(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    if (Pin_num <= P3_6)
    {
        return BIT(Pin_num);
    }
    else if (Pin_num == P4_0)
    {
        return BIT(13);
    }
    else if ((Pin_num <= P4_3) && (Pin_num >= P4_1))
    {
        return BIT(Pin_num - 4);
    }
    else if ((Pin_num <= P5_2) && (Pin_num >= H_0))
    {
        return BIT(Pin_num - 26);
    }

    return 0xFF;
}

/**
 * \brief     Get GPIOx(x is 0~31) value through the given pad.
 * \param[in] Pin_num: Pad num which can be from P0_0 to P5_2, please refer to rtl876x.h "Pin_Number" part.
 * \return    GPIOx(x is 0~31) value.
 */
uint8_t GPIO_GetNum(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    if (Pin_num <= P3_6)
    {
        return (Pin_num);
    }
    else if (Pin_num == P4_0)
    {
        return 13;
    }
    else if ((Pin_num <= P4_3) && (Pin_num >= P4_1))
    {
        return (Pin_num - 4);
    }
    else if ((Pin_num <= P5_2) && (Pin_num >= H_0))
    {
        return (Pin_num - 26);
    }

    return 0xFF;
}

/**
 * \brief   Enable GPIO debounce clock.
 * \param[in] NewState: Disable or enable debounce clock.
 * \return  None.
 */
void GPIO_DBClkCmd(FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        GPIO_DBCLK_DIV |= BIT12;
    }
    else
    {
        GPIO_DBCLK_DIV &= ~BIT12;
    }
}

/**
  * \brief  Store GPIO register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Store buffer to store GPIO register data.
  * \return None.
  */
DATA_RAM_FUNCTION
void GPIO_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIOStoreReg_TypeDef *store_buf = (GPIOStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, ENABLE);

    store_buf->gpio_reg[GPIO_DLPS_DR] = GPIOx->DATAOUT;
    store_buf->gpio_reg[GPIO_DLPS_DDR] = GPIOx->DATADIR;
    store_buf->gpio_reg[GPIO_DLPS_DSR] = GPIOx->DATASRC;
    store_buf->gpio_reg[GPIO_DLPS_INTEN] = GPIOx->INTEN;
    store_buf->gpio_reg[GPIO_DLPS_MASK] = GPIOx->INTMASK;
    store_buf->gpio_reg[GPIO_DLPS_LEVEL] = GPIOx->INTTYPE;
    store_buf->gpio_reg[GPIO_DLPS_POLARITY] = GPIOx->INTPOLARITY;
    store_buf->gpio_reg[GPIO_DLPS_DEBEN] = GPIOx->DEBOUNCE;
    store_buf->gpio_reg[GPIO_DLPS_DEBCFG] = *(__IO uint32_t *)(0x40000344UL);
    store_buf->gpio_reg[GPIO_DLPS_BOTHEDGE] = GPIOx->INTBOTHEDGE;

    return;
}

/**
  * \brief  Restore GPIO register values when system exit DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Restore buffer to restore GPIO register data.
  * \return None
  */
DATA_RAM_FUNCTION
void GPIO_DLPSExit(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIOStoreReg_TypeDef *store_buf = (GPIOStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, ENABLE);

    GPIOx->DATADIR       = store_buf->gpio_reg[GPIO_DLPS_DDR];
    GPIOx->DATASRC       = store_buf->gpio_reg[GPIO_DLPS_DSR];
    GPIOx->INTMASK       = store_buf->gpio_reg[GPIO_DLPS_MASK];
    GPIOx->INTTYPE       = store_buf->gpio_reg[GPIO_DLPS_LEVEL];
    GPIOx->INTPOLARITY   = store_buf->gpio_reg[GPIO_DLPS_POLARITY];
    GPIOx->DEBOUNCE      = store_buf->gpio_reg[GPIO_DLPS_DEBEN];
    GPIOx->DATAOUT       = store_buf->gpio_reg[GPIO_DLPS_DR];
    GPIOx->INTCLR        = ~(store_buf->gpio_reg[GPIO_DLPS_DDR]);
    GPIOx->INTEN         = store_buf->gpio_reg[GPIO_DLPS_INTEN];
    *(__IO uint32_t *)(0x40000344UL) = store_buf->gpio_reg[GPIO_DLPS_DEBCFG];
    GPIOx->INTBOTHEDGE  = store_buf->gpio_reg[GPIO_DLPS_BOTHEDGE];

    return;
}



