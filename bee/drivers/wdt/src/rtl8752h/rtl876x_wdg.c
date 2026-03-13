/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "rtl876x_wdg.h"
#include "platform_cfg.h"

void WDG_ClockEnable(void)
{
    HAL_WRITE32(PERIPH_REG_BASE, 0x230, HAL_READ32(PERIPH_REG_BASE, 0x230) | BIT6);
    HAL_WRITE32(PERIPH_REG_BASE, 0x360, HAL_READ32(PERIPH_REG_BASE, 0x360) | BIT8);
    HAL_WRITE32(PERIPH_REG_BASE, 0x210, HAL_READ32(PERIPH_REG_BASE, 0x210) | BIT16);
}

#define CLK_FREQ_HZ 32000
#define WDT_MAX_TIMEOUT_MS 8192000

/**
 * @brief  Calculate best div_factor and cnt_limit for target timeout (ms).
 */
static void get_wdt_config_params(uint32_t target_ms, uint16_t *out_div_factor, uint8_t *out_cnt_limit)
{
    uint8_t best_cnt_limit = 11;
    uint16_t best_div_factor = 0xFFFF;
    uint64_t best_diff = 0xFFFFFFFFFFFFFFFFULL;

    /* Iterate through all possible cnt_limit values (0 to 11) */
    for (uint8_t limit = 0; limit <= 11; limit++) {
        uint32_t max_cnt = (1UL << (limit + 1)) - 1; /* 0x1, 0x3, 0x7 ... 0xFFF */

        /*
         * Reverse calculate required div_factor:
         * Hardware counts from 0 to max_cnt, which is (max_cnt + 1) clock cycles.
         * Formula: ((max_cnt + 1) * (1 + div_factor) * 1000) / CLK_FREQ_HZ = target_ms
         * 1 + div_factor = (target_ms * CLK_FREQ_HZ) / ((max_cnt + 1) * 1000)
         */
        uint64_t numerator = (uint64_t)target_ms * CLK_FREQ_HZ;
        uint64_t denominator = (uint64_t)(max_cnt + 1) * 1000ULL;

        /* Round up to ensure timeout >= target_ms */
        uint64_t required_div_plus_1 = (numerator + denominator - 1) / denominator;

        if (required_div_plus_1 == 0) {
            required_div_plus_1 = 1;
        }

        /* Check hardware limits (div_factor max is 0xFFFF) */
        if (required_div_plus_1 > 65536) {
            continue;
        }

        uint16_t div_factor = (uint16_t)(required_div_plus_1 - 1);

        /* WDG_Config has a limitation that div_factor cannot be 0, so clamp to 1 */
        if (div_factor == 0) {
            div_factor = 1;
        }

        /* Calculate actual timeout - counter counts (max_cnt + 1) times */
        uint64_t actual_ms = ((max_cnt + 1) * (1ULL + div_factor) * 1000ULL) / CLK_FREQ_HZ;
        uint64_t diff = actual_ms >= target_ms ? (actual_ms - target_ms) : (target_ms - actual_ms);

        /* Find the combination with the smallest difference */
        if (diff < best_diff) {
            best_diff = diff;
            best_cnt_limit = limit;
            best_div_factor = div_factor;
        }
    }

    *out_cnt_limit = best_cnt_limit;
    *out_div_factor = best_div_factor;
}

/**
divfactor: 16Bit: 32000/(1+divfactor)
cnt_limit: 2^(cnt_limit+1) - 1 ; max 11~15 = 0xFFF
            0: 0x001
            1: 0x003
            2: 0x007
            3: 0x00F
            4: 0x01F
            5: 0x03F
            6: 0x07F
            7: 0x0FF
            8: 0x1FF
            9: 0x3FF
            10: 0x7FF
            11~15: 0xFFF
Wdg_mode: 0: interrupt cpu
          1: reset all except AON
          2: reset core domain
          3: reset all
*/
void WDG_Config(
    uint16_t div_factor,
    uint8_t  cnt_limit,
    T_WDG_MODE  wdg_mode
)
{
    T_WATCH_DOG_TIMER_REG wdg_ctrl_value;
    if (patch_WDG_Config)
    {
        if (patch_WDG_Config(div_factor, cnt_limit, wdg_mode))
        {
            return;
        }
    }
    if (div_factor == 0)
    {
        div_factor = 1;
    }

    wdg_ctrl_value.d32 = WDG->WDG_CTL;

    wdg_ctrl_value.b.div_factor = div_factor;
    wdg_ctrl_value.b.cnt_limit = cnt_limit;
    wdg_ctrl_value.b.wdg_mode = wdg_mode;

    WDG->WDG_CTL = wdg_ctrl_value.d32;
}


void WDG_Enable(void)
{
    T_WATCH_DOG_TIMER_REG wdg_ctrl_value;

    wdg_ctrl_value.d32 = WDG->WDG_CTL;

    wdg_ctrl_value.b.en_byte = 0xA5;
    wdg_ctrl_value.b.clear = 1;
    wdg_ctrl_value.b.timeout = 1; // W1C;

    WDG->WDG_CTL = wdg_ctrl_value.d32;
}


void WDG_Disable(void)
{
    T_WATCH_DOG_TIMER_REG wdg_ctrl_value;

    wdg_ctrl_value.d32 = WDG->WDG_CTL;

    wdg_ctrl_value.b.en_byte = 0;
    wdg_ctrl_value.b.clear = 1;
    wdg_ctrl_value.b.timeout = 1; // W1C;

    WDG->WDG_CTL = wdg_ctrl_value.d32;
}

void WDG_Restart(void)
{
    T_WATCH_DOG_TIMER_REG wdg_ctrl_value;

    wdg_ctrl_value.d32 = WDG->WDG_CTL;
    wdg_ctrl_value.b.clear = 1;
    WDG->WDG_CTL = wdg_ctrl_value.d32;
}

bool WDT_Start(uint32_t time_ms, T_WDG_MODE wdt_mode)
{
    /* Check for invalid input (zero or exceeding maximum hardware capability) */
    if (time_ms == 0 || time_ms > WDT_MAX_TIMEOUT_MS) {
        return false;
    }

    uint16_t div_factor;
    uint8_t cnt_limit;

    /* Get the optimal configuration based on required milliseconds */
    get_wdt_config_params(time_ms, &div_factor, &cnt_limit);

    /* Configure and Enable Watchdog */
    WDG_Config(div_factor, cnt_limit, wdt_mode);
    WDG_Enable();

    return true;
}
