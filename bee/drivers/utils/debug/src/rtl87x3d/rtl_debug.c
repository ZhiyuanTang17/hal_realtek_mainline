/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdint.h>

#include "rtl_pinmux.h"
#include "rtl8763_syson_reg.h"
#include "rtl_debug.h"
#include "trace.h"
#include "rtl_gpio.h"

extern const uint16_t PINADDR_TABLE[];
extern const uint16_t PIN_ADDR_SW_TABLE[TOTAL_PIN_NUM];

void pad_set_all_shut_down(void)
{
    for (uint8_t pin_index = 0; pin_index <= TOTAL_PIN_NUM / sizeof(uint16_t); pin_index++)
    {
        uint16_t reg_temp = PINADDR_TABLE[pin_index];
        if (reg_temp)
        {
            Pad_Config(pin_index, PAD_SW_MODE, PAD_SHUTDOWN, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
        }
    }
}
static const char *const key_name[] =
{
    "KEY0",   "KEY1",   "KEY2",   "KEY3",   "KEY4",   "KEY5",   "KEY6",   "KEY7"
};

static char *wakeup_config_to_str(PAD_WAKEUP_POL_VAL wakeup_config)
{
    switch (wakeup_config)
    {
    case PAD_WAKEUP_POL_HIGH:
        return "PAD_WAKEUP_POL_HIGH";
    case PAD_WAKEUP_POL_LOW:
        return "PAD_WAKEUP_POL_LOW";
    case PAD_WAKEUP_NONE:
        return "PAD_WAKEUP_NONE";
    default:
        return "NULL";
    }
}

static char *pullup_config_to_str(PAD_Pull_Mode pullup_config)
{
    switch (pullup_config)
    {
    case PAD_PULL_NONE:
        return "NONE";
    case PAD_PULL_UP:
        return "PULLUP";
    case PAD_PULL_DOWN:
        return "PULLDOWN";
    default:
        return "";
    }
}

static char *output_config_to_str(PAD_OUTPUT_ENABLE_Mode output_en, PAD_OUTPUT_VAL output_val)
{
    if (output_en == PAD_OUT_DISABLE)
    {
        return "OUTPUT_DISABLE";
    }
    else if (output_en == PAD_OUT_ENABLE)
    {
        if (output_val == PAD_OUT_LOW)
        {
            return "OUTPUT_LOW";
        }
        else
        {
            return "OUTPUT_HIGH";
        }
    }
    else
    {
        return "UNKNOWN";
    }
}

static char *pad_mode_to_str(PAD_Mode mode)
{
    if (mode == PAD_SW_MODE)
    {
        return "PAD_SW_MODE";
    }
    else
    {
        return "PAD_PINMUX_MODE";
    }
}

static char *pad_power_to_str(PAD_PWR_Mode pwr_mode)
{
    if (pwr_mode == PAD_IS_PWRON)
    {
        return "IS_POWER_ON";
    }
    else
    {
        return "PAD_SHUT_DOWN";
    }
}


const char *pad_get_wake_up_func_string(uint8_t pin_num)
{
    PAD_WAKEUP_POL_VAL wakeup_config = PAD_WAKEUP_NONE;

    //to be implemented

    return wakeup_config_to_str(wakeup_config);
}

int32_t pad_print_setting(uint8_t pin_num)
{
    if (pin_num >= TOTAL_PIN_NUM)
    {
        APP_PRINT_ERROR1("pad_print_setting pin =%d is invaild", pin_num);
        return -1;
    }

    uint16_t reg_temp = PINADDR_TABLE[pin_num];
    uint8_t tmp_offset = 0;
    uint16_t mode_reg_temp;
    uint16_t bit_temp;
    uint16_t tmp_val;

    PAD_Pull_Mode pullup_config = PAD_PULL_DOWN;
    PAD_OUTPUT_ENABLE_Mode output_en = PAD_OUT_DISABLE;
    PAD_OUTPUT_VAL output_val = PAD_OUT_LOW;
    PAD_Mode mode = PAD_SW_MODE;
    PAD_PWR_Mode pwr_mode = PAD_IS_PWRON;

    if (reg_temp == 0x00)
    {
        return (-1);
    }

    /* Pad control mode */
    mode_reg_temp = (PIN_ADDR_SW_TABLE[pin_num] & (0xfff));
    bit_temp = BIT(((PIN_ADDR_SW_TABLE[pin_num] & (0xf000)) >> 12));
    if (pin_num == P7_7)
    {
        mode_reg_temp = 0x23C;
        bit_temp = 7;
    }

    tmp_val = btaon_fast_read_safe(mode_reg_temp);
    if (tmp_val & bit_temp)
    {
        mode = PAD_PINMUX_MODE;
    }

    if (reg_temp & 0x01)
    {
        reg_temp--;
        tmp_offset = 8;
    }

    tmp_val = btaon_fast_read_safe(reg_temp);

    tmp_val = tmp_val >> tmp_offset;

    if (tmp_val & Pull_En)
    {
        if (tmp_val & Pull_Direction)
        {
            pullup_config = PAD_PULL_UP;
        }
        else
        {
            pullup_config = PAD_PULL_DOWN;
        }
    }
    else
    {
        pullup_config = PAD_PULL_NONE;
    }

    if (tmp_val & Output_En)
    {
        output_en = PAD_OUT_ENABLE;
        if (tmp_val & Output_Val)
        {
            output_val = PAD_OUT_HIGH;
        }
        else
        {
            output_val = PAD_OUT_LOW;
        }
    }
    else
    {
        output_en = PAD_OUT_DISABLE;
    }

    if (tmp_val & SHDN)
    {
        pwr_mode = PAD_IS_PWRON;
    }
    else
    {
        pwr_mode = PAD_SHUTDOWN;
    }

    DBG_DIRECT("%d\t%s\t%s\t%s\t%s\t%s\t%s", pin_num, Pad_GetPinName(pin_num), pad_mode_to_str(mode),
               pad_power_to_str(pwr_mode),
               output_config_to_str(output_en, output_val), pullup_config_to_str(pullup_config));
    return 0;
}

void pad_print_all_pin_setting(void)
{
    for (uint8_t pin_index = 0; pin_index <= P7_1; pin_index++)
    {
        pad_print_setting(pin_index);
    }
}

const char *key_get_name(uint8_t key_mask)
{
    return key_name[(31 - __clz(key_mask))];
}

const char *key_get_stat_str(uint32_t active, uint8_t key_status)
{
    if (active) // high active
    {
        if (key_status) //Button pressed
        {
            return "KEY_PRESS";
        }
        else
        {
            return "KEY_RELEASE";
        }
    }
    else
    {
        if (!key_status) //Button
        {
            return "KEY_PRESS";
        }
        else
        {
            return "KEY_RELEASE";
        }
    }
}


static char *gpio_mode_to_str(GPIOMode_TypeDef mode)
{
    if (mode == GPIO_Mode_IN)
    {
        return "INPUT_MODE";
    }
    else
    {
        return "OUTPUT_MODE";
    }
}

static char *gpio_input_str(bool value)
{
    if (value == 0)
    {
        return "INPUT_LOW";
    }
    else
    {
        return "INPUT_HIGH";
    }
}

static char *gpio_output_str(bool value)
{
    if (value == 0)
    {
        return "OUTPUT_LOW";
    }
    else
    {
        return "OUTPUT_HIGH";
    }
}

static char *gpio_int_polarty_str(bool value)
{
    if (value == 0)
    {
        return "int_polary_low";
    }
    else
    {
        return "int_polary_high";
    }
}

static char *gpio_int_en_str(bool value)
{
    if (value == 0)
    {
        return "int_en_disable";
    }
    else
    {
        return "int_en_enable";
    }
}

static char *gpio_int_en_mask_str(bool value)
{
    if (value == 0)
    {
        return "int_en_mask_disable";
    }
    else
    {
        return "int_en_mask_enable";
    }
}

static char *gpio_int_type_str(bool value)
{
    if (value == 0)
    {
        return "int_type_level";
    }
    else
    {
        return "int_type_edge";
    }
}

static char *gpio_int_type_edeg_both_str(bool value)
{
    if (value == 0)
    {
        return "int_type_edge_one";
    }
    else
    {
        return "int_type_edge_both";
    }
}
static char *gpio_debounce_str(bool value)
{
    if (value == 0)
    {
        return "debounce_disable";
    }
    else
    {
        return "debounce_enable";
    }
}

static char *gpio_int_status_str(bool value)
{
    if (value == 0)
    {
        return "int_not_triggle";
    }
    else
    {
        return "int_triggle";
    }
}

void gpio_print_pin_setting(uint8_t pin_num)
{
    T_GPIO_SETTING gpio_setting;
    GPIO_TypeDef *GPIOx;
    uint8_t gpio_num ;
    if (pin_num >= TOTAL_PIN_NUM)
    {
        APP_PRINT_ERROR1("gpio_print_pin_setting pin =%d is invaild", pin_num);
        return ;
    }
    gpio_num = GPIO_GetNum(pin_num);
    GPIOx = gpio_num <= GPIO31 ? GPIOA : GPIOB;
    gpio_setting.mode = (bool)((GPIOx->DATADIR & GPIO_GetPin(pin_num)));

    gpio_setting.in_value = (bool)(GPIOx_ReadInputDataBit(GPIOx, GPIO_GetPin(pin_num)));
    gpio_setting.out_value = (bool)(GPIOx_ReadOutputDataBit(GPIOx, GPIO_GetPin(pin_num)));
    gpio_setting.int_polarty = (bool)((GPIOx->INTPOLARITY & GPIO_GetPin(pin_num)));
    gpio_setting.int_en = (bool)((GPIOx->INTEN & GPIO_GetPin(pin_num)));
    gpio_setting.int_type = (bool)((GPIOx->INTTYPE & GPIO_GetPin(pin_num)));
    gpio_setting.int_type_edg_both = (bool)((GPIOx->INTBOTHEDGE & GPIO_GetPin(pin_num)));
    gpio_setting.int_en_mask = (bool)((GPIOx->INTMASK & GPIO_GetPin(pin_num)));
    gpio_setting.int_status = (bool)((GPIOx->INTSTATUS & GPIO_GetPin(pin_num)));
    gpio_setting.debounce = (bool)((GPIOx->DEBOUNCE & GPIO_GetPin(pin_num)));

    APP_PRINT_INFO8("%d \t%s \t%s \t%s \t%s \t%s \t%s \t%s", pin_num,
                    TRACE_STRING(Pad_GetPinName(pin_num)),
                    TRACE_STRING(gpio_mode_to_str((GPIOMode_TypeDef)gpio_setting.mode)),
                    TRACE_STRING(gpio_input_str(gpio_setting.in_value)),
                    TRACE_STRING(gpio_output_str(gpio_setting.out_value)),
                    TRACE_STRING(gpio_int_en_str(gpio_setting.int_en)),
                    TRACE_STRING(gpio_int_en_mask_str(gpio_setting.int_en_mask)),
                    TRACE_STRING(gpio_int_polarty_str(gpio_setting.int_polarty))
                   );
    APP_PRINT_INFO4("\t%s \t%s \t%s \t%s",
                    TRACE_STRING(gpio_int_type_str(gpio_setting.int_type)),
                    TRACE_STRING(gpio_int_type_edeg_both_str(gpio_setting.int_type_edg_both)),
                    TRACE_STRING(gpio_debounce_str(gpio_setting.debounce)),
                    TRACE_STRING(gpio_int_status_str(gpio_setting.int_status))
                   );
}
