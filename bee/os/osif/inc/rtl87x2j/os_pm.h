/*
 * Copyright (c) 2017, Realtek Semiconductor Corporation. All rights reserved.
 */

#ifndef _OS_POWER_MANAGER_H_
#define _OS_POWER_MANAGER_H_
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

#define portNVIC_INT_CTRL_REG     ( *( ( volatile uint32_t * ) 0xe000ed04 ) )

#define UPDATE_TICK_COUNT()\
    if (portNVIC_INT_CTRL_REG & SCB_ICSR_PENDSTSET_Msk)\
    {\
        os_timer_tick_handler();\
        portNVIC_INT_CTRL_REG = SCB_ICSR_PENDSTCLR_Msk;\
    }

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
        uint8_t os_pm_wake_event:       1;
        uint8_t rsvd:                   6;
    };
} OSPMFeatureConfig;

extern OSPMFeatureConfig os_pm_feature_cfg;

bool os_sched_restore(void);
void os_timer_tick_handler(void);
uint32_t os_timer_tick_rate_get(void);
uint32_t os_timer_clock_get(void);
uint64_t os_timer_tick_increase(uint32_t tick_increment);
uint32_t os_pm_next_timeout_value_get(void);
bool os_pm_excluded_handle_register(void **pp_handle, PlatformExcludedHandleType type);
bool os_pm_excluded_handle_unregister(void **pp_handle, PlatformExcludedHandleType type);
void os_pm_tickcount_store(void);
void os_pm_tickcount_restore(void);
void os_pm_init(void);

#ifdef __cplusplus
}
#endif

#endif /* _OS_POWER_MANAGER_H_ */
