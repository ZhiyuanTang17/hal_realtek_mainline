/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_gpio.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Macros
 *============================================================================*/

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern void GPIO_ExtPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the GPIO peripheral registers to their default reset values.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \return None.
  */
void GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
#ifdef GPIOA
    if (GPIOx == GPIOA)
    {
        RCC_ClockCmd(GPIOA_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOB
    if (GPIOx == GPIOB)
    {
        RCC_ClockCmd(GPIOB_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOC
    if (GPIOx == GPIOC)
    {
        RCC_ClockCmd(GPIOC_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOD
    if (GPIOx == GPIOD)
    {
        RCC_ClockCmd(GPIOD_CLOCK, DISABLE);
        return;
    }
#endif
}

/**
  * \brief  Initializes the GPIO peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * \return None
  */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
    assert_param(IS_GPIO_DIR(GPIO_InitStruct->GPIO_Dir));
#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    assert_param(IS_GPIO_OUTPUT_MODE(GPIO_InitStruct->GPIO_OutPutMode));
#endif
    assert_param(IS_GPIOIT_TRIGGER_TYPE(GPIO_InitStruct->GPIO_Trigger));
    assert_param(IS_GPIOIT_POLARITY_TYPE(GPIO_InitStruct->GPIO_Polarity));
    assert_param(IS_GPIOIT_DEBOUNCE_TYPE(GPIO_InitStruct->GPIO_DebounceEn));

    /* GPIO configure */
    if (GPIO_InitStruct->GPIO_Dir == GPIO_DIR_OUT)
    {
        GPIOx->GPIO_DDR |= GPIO_InitStruct->GPIO_Pin;

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
        if (GPIO_InitStruct->GPIO_OutPutMode == GPIO_OUTPUT_OPENDRAIN)
        {
            GPIOx->GPIO_OUT_MODE |= GPIO_InitStruct->GPIO_Pin;
        }
        else
        {
            GPIOx->GPIO_OUT_MODE &= ~(GPIO_InitStruct->GPIO_Pin);
        }
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
        if (GPIO_InitStruct->GPIO_ControlMode == GPIO_SOFTWARE_MODE)
        {
            /* Config GPIOx control software mode */
            GPIOx->GPIO_SRC &= (~GPIO_InitStruct->GPIO_Pin);
        }
        else
        {
            /* Config GPIOx hardware control mode */
            GPIOx->GPIO_SRC |= (GPIO_InitStruct->GPIO_Pin);
        }
#endif
    }
    else
    {
        /*Configure GPIO input mode */
        GPIOx->GPIO_DDR = GPIOx->GPIO_DDR & (~GPIO_InitStruct->GPIO_Pin);

        if (GPIO_InitStruct->GPIO_INTEventEn == ENABLE)
        {
            GPIOx->GPIO_INT_MASK = ~GPIO_Pin_All;

            /* configure GPIO interrupt trigger type */
#if GPIO_SUPPORT_BOTHEDGE
            if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_BOTH_EDGE)
            {
                GPIOx->GPIO_INT_BOTHEDGE |= GPIO_InitStruct->GPIO_Pin;
            }
            else
            {
                GPIOx->GPIO_INT_BOTHEDGE &= ~GPIO_InitStruct->GPIO_Pin;
            }
#endif

            if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_LEVEL)
            {
                GPIOx->GPIO_INT_LV &= ~GPIO_InitStruct->GPIO_Pin;

#if (GPIO_SUPPORT_LS_SYNC == 1)
                /* Level-sensitive synchronization enable register */
                GPIOx->GPIO_LS_SYNC = 0x1;
#endif
            }
            else if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_EDGE)
            {
                GPIOx->GPIO_INT_LV |= GPIO_InitStruct->GPIO_Pin;
            }

            /* configure Interrupt polarity register */
            GPIO_ExtPolarity(GPIOx, GPIO_InitStruct->GPIO_Pin, GPIO_InitStruct->GPIO_Polarity);

            /* configure Debounce enable register */
            if (GPIO_InitStruct->GPIO_DebounceEn == ENABLE)
            {
                GPIO_ExtDebUpdate(GPIOx, GPIO_InitStruct->GPIO_Pin,
                                  GPIO_InitStruct->GPIO_DebClockSrc,
                                  GPIO_InitStruct->GPIO_DebClockDiv,
                                  GPIO_InitStruct->GPIO_DebCountLimit);
            }
            GPIO_ExtDebCmd(GPIOx, GPIO_InitStruct->GPIO_Pin,
                           (FunctionalState) GPIO_InitStruct->GPIO_DebounceEn);
        }
    }
}

/**
  * \brief  Fills each GPIO_InitStruct member with its default value.
  * \param  GPIO_InitStruct : pointer to a GPIO_InitTypeDef structure which will be initialized.
  * \return None
  */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStruct->GPIO_Pin         = GPIO_Pin_All;
    GPIO_InitStruct->GPIO_Dir         = GPIO_DIR_IN;
#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    GPIO_InitStruct->GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
#endif
#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIO_InitStruct->GPIO_ControlMode = GPIO_SOFTWARE_MODE;
#endif
    GPIO_InitStruct->GPIO_INTEventEn  = DISABLE;
    GPIO_InitStruct->GPIO_Trigger     = GPIO_TRIGGER_LEVEL;
    GPIO_InitStruct->GPIO_Polarity    = GPIO_POLARITY_ACTIVE_LOW;

    /* Set GPIO doubonce parameters: set doubonce time is 1ms,
     * debounce time = (CntLimit + 1) * DEB_CLK = 32 / 32000 = 1ms */
    GPIO_InitStruct->GPIO_DebounceEn  = DISABLE;
    GPIO_InitStruct->GPIO_DebClockSrc = GPIO_DEFAULT_DEB_CLOCK_SRC;
    GPIO_InitStruct->GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
    GPIO_InitStruct->GPIO_DebCountLimit = 32;
}

/**
  * \brief  Enable the specified GPIO interrupt.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  Enable or disable interrupt
  * \return None
  */
void GPIO_INTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected GPIO pin interrupts */
        GPIOx->GPIO_INT_EN |= GPIO_Pin;
    }
    else
    {
        /* Disable the selected GPIO pin interrupts */
        GPIOx->GPIO_INT_EN &= ~GPIO_Pin;
    }
}

/**
  * \brief  Clear the specified GPIO interrupt.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \return None
  */
void GPIO_ClearINTPendingBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_INT_CLR = GPIO_Pin;
}

/**
  * \brief  Mask the specified GPIO interrupt.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  NewState: Mask or unmask gpio debounce clock.
  * \return None
  */
void GPIO_MaskINTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        GPIOx->GPIO_INT_MASK |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_INT_MASK &= ~(GPIO_Pin);
    }
}

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
/**
  * \brief  Set GPIO Output mode.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  GPIO_OutputMode: Specifies the output mode to be set.
  * \return None.
  */
void GPIO_SetOutputMode(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                        GPIOOutputMode_TypeDef GPIO_OutputMode)
{
    /* Check the parameters */
    assert_param(IS_GPIO_OUTPUT_MODE(GPIO_OutputMode));

    /* configure Interrupt polarity register */
    if (GPIO_OutputMode == GPIO_OUTPUT_OPENDRAIN)
    {
        GPIOx->GPIO_OUT_MODE = (GPIOx->GPIO_OUT_MODE & (~GPIO_Pin)) | GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_OUT_MODE &= (~GPIO_Pin);
    }
}
#endif

/**
  * \brief  Read the specified input port pin.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bit to read.
  * \return The input port pin value.
  */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if (GPIOx->GPIO_PAD_STATE & GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
  * \brief  Read value of all GPIO input data port.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \return GPIO input data port value.
  */
uint32_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx)
{
    return ((uint32_t)GPIOx->GPIO_PAD_STATE);
}

/**
  * \brief  Read the specified output port pin.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bit to read.
  * \return The output port pin value.
  */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if (GPIOx->GPIO_DR & GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
  * \brief  Read value of all GPIO output data port.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \return GPIO output data port value.
  */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx)
{
    return ((uint32_t)GPIOx->GPIO_DR);
}

/**
  * \brief  Sets the selected data port bit.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bit to be written.
  * \return None.
  */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_DR |= GPIO_Pin;
}

/**
  * \brief  Reset the selected data port bit.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bits to be written.
  * \return None.
  */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_DR &= ~(GPIO_Pin);
}

/**
  * \brief  Set or clear the selected data port bit.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bit to be written.
  * \param  BitVal: specifies the value to be written to the selected bit.
  * \return None.
  */
void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, BitAction BitVal)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_GPIO_BIT_ACTION(BitVal));

    if (BitVal != Bit_RESET)
    {
        GPIOx->GPIO_DR |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_DR &= ~(GPIO_Pin);
    }
}

/**
  * \brief  Set or clear data port.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  PortVal: Specifies the value to be written to the selected bit.
  * \return None.
  */
void GPIO_Write(GPIO_TypeDef *GPIOx, uint32_t PortVal)
{
    GPIOx->GPIO_DR = PortVal;
}


/**
  * \brief  Get GPIO interrupt status.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: Specifies the port bit to be written.
  * \return The new state of GPIO_INT (SET or RESET).
  */
ITStatus GPIO_GetINTStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->GPIO_INT_STS & GPIO_Pin) == GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
  * \brief  Specifies the direction for the selected pins.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_PinBit: Specifies the GPIO pins to be configured, please refer to "GPIO_pins_define" part.
  * \param  GPIO_Dir: Set the GPIO direction.
  * \return None.
  */
void GPIO_SetDirection(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinBit,
                       GPIODir_TypeDef GPIO_Dir)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_PinBit));

    if (GPIO_Dir == GPIO_DIR_OUT)
    {
        GPIOx->GPIO_DDR |= GPIO_PinBit;
    }
    else
    {
        GPIOx->GPIO_DDR &= ~GPIO_PinBit;
    }
}

/**
  * \brief  Get GPIO pad status.
  * \param  GPIO_Pin: Specifies the port bit to be written.
  * \return The new state of GPIO_Pad (SET or RESET).
  */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->GPIO_PAD_STATE & GPIO_Pin) == GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
  * \brief  Set GPIO Int Polarity.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  int_type: Specifies the polarity type to be set.
  * \return None.
  */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity)
{
    /* Check the parameters */
    assert_param(IS_GPIO_POLARITY_TYPE(Polarity));

    GPIO_ExtPolarity(GPIOx, GPIO_Pin, Polarity);
}

/*============================================================================*
 *                        RAP Functions
 *============================================================================*/
#if (GPIO_SUPPORT_RAP_FUNCTION == 1)

void GPIO_RAPModeCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (NewState != DISABLE)
    {
        GPIOx->GPIO_RAP_CTL |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_RAP_CTL &= ~GPIO_Pin;
    }
    return;
}

void GPIO_ActionTrigger(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (Action == GPIO_ACTION_DRSET)
    {
        GPIOx->GPIO_RAP_TASK_DRSET |= GPIO_Pin;
    }
    else if (Action == GPIO_ACTION_DRCLR)
    {
        GPIOx->GPIO_RAP_TASK_DRCLR |= GPIO_Pin;
    }
    else if (Action == GPIO_ACTION_DRTOGGLE)
    {
        GPIOx->GPIO_RAP_TASK_DRTOGGLE |= GPIO_Pin;
    }
    return;
}
#endif



