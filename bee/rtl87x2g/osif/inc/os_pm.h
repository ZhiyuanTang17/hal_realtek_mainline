/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OS_POWER_MANAGER_H_
#define _OS_POWER_MANAGER_H_
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "rtl876x.h"
#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define portNVIC_INT_CTRL_REG     ( *( ( volatile uint32_t * ) 0xe000ed04 ) )

#define UPDATE_TICK_COUNT()\
    if (portNVIC_INT_CTRL_REG & SCB_ICSR_PENDSTSET_Msk)\
    {\
        os_systick_handler();\
        portNVIC_INT_CTRL_REG = SCB_ICSR_PENDSTCLR_Msk;\
    }

#define US_TO_TICK_COUNT(us, residual)\
    cal_quotient_remainder(1000000 * (uint64_t)(os_sys_tick_clk_get() / os_sys_tick_rate_get()), os_sys_tick_clk_get(), us, &residual)

#define US_TO_SYSTICK(us, residual)\
    cal_quotient_remainder(1000000, os_sys_tick_clk_get(), us, &residual)

#define TICK_COUNT_TO_US(tick_count)\
    cal_quotient_remainder(os_sys_tick_clk_get(), 1000000 * (uint64_t)(os_sys_tick_clk_get() / os_sys_tick_rate_get()), tick_count, NULL)

#define SYSTICK_TO_US(systick)\
    cal_quotient_remainder(os_sys_tick_clk_get(), 1000000, systick, NULL)

#define SYSTICK_RELOAD_VALUE    (os_sys_tick_clk_get() / os_sys_tick_rate_get() - 1)

typedef enum
{
    PLATFORM_PM_EXCLUDED_TIMER,
    PLATFORM_PM_EXCLUDED_TASK,
    PLATFORM_PM_EXCLUDED_TYPE_MAX,
} PlatformExcludedHandleType;

typedef struct
{
    struct PlatformPMExcludedHandleQueueElem *pNext;
    void **handle;
} PlatformPMExcludedHandleQueueElem;

typedef union
{
    uint8_t value[1];
    struct
    {
        uint8_t os_pm_statistic:        1;
        uint8_t rsvd:                   7;
    };
} OSPMFeatureConfig;

typedef struct
{
    uint32_t last_sleep_clk;
    uint32_t last_sleep_systick;
    uint32_t tickcount_restore_remain_us;
} OSPMSystem;

extern void (*os_pm_init)(void);
extern bool (*os_sched_restore)(void);
extern void (*os_systick_handler)(void);
extern uint32_t (*os_sys_tick_rate_get)(void);
extern uint32_t (*os_sys_tick_clk_get)(void);
extern uint64_t (*os_sys_tick_increase)(uint32_t tick_increment);


extern uint32_t (*os_pm_next_timeout_value_get)(void);

extern bool (*os_register_pm_excluded_handle)(void **pp_handle, PlatformExcludedHandleType type);
extern bool (*os_unregister_pm_excluded_handle)(void **pp_handle, PlatformExcludedHandleType type);

#ifdef __cplusplus
}
#endif

#endif /* _OS_POWER_MANAGER_H_ */
