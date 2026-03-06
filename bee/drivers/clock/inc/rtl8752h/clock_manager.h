/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CLOCK_MANAGER_H
#define __CLOCK_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CLOCK_40MHZ     40000000
#define CLOCK_30MHZ     30000000
#define CLOCK_20MHZ     20000000
#define CLOCK_10MHZ     10000000
#define CLOCK_8MHZ      8000000
#define CLOCK_5MHZ      5000000
#define CLOCK_4MHZ      4000000
#define CLOCK_3P3MHZ    3333333
#define CLOCK_2P5MHZ    2500000
#define CLOCK_1P25MHZ   1250000
#define CLOCK_625KHZ    625000

extern void (*set_active_mode_clk_src)(void);
extern void (*set_up_32k_clk_src)(void);
extern void (*work_around_32k_power_glitch_after_restart)(void);
extern void (*work_around_32k_power_glitch)(void);
void init_osc_sdm_timer(void);

#endif
