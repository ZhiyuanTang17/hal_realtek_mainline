/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __POWER_MANAGER_UNIT_PLATFORM_H
#define __POWER_MANAGER_UNIT_PLATFORM_H

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "os_queue.h"
#include "power_manager_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup PLATFORM_PM_Exported_Types Platform_PM Exported Types
  * @{
  */

typedef enum
{
    //PLATFORM_POWEROFF       = 0,   /**< Power off  */     // rtl87x2g not support
    PLATFORM_POWERDOWN      = 1,   /**< Power down */
    PLATFORM_DLPS_PFM       = 2,   /**< DLPS (PFM) */
    PLATFORM_DLPS_RET       = 3,   /**< DLPS (RET) */
    //PLATFORM_LPS_PFM        = 4,   /**< LPS        */     // rtl87x2g not support
    PLATFORM_ACTIVE         = 5,   /**< Active     */
    PLATFORM_POWER_MODE_MAX = 6
} PlatformPowerMode;

typedef enum
{
    PLATFORM_PM_CHECK                       = 0,
    PLATFORM_PM_STORE                       = 1,
    PLATFORM_PM_ENTER                       = 2,
    PLATFORM_PM_EXIT                        = 3,
    PLATFORM_PM_RESTORE                     = 4,
    PLATFORM_PM_PEND                        = 5,
    PLATFORM_PM_STAGE_MAX                   = 6,
} PlatformPMStage;

typedef enum
{
    PLATFORM_PM_WAKEUP_UNKNOWN              = 0x00000000,
    PLATFORM_PM_WAKEUP_PRE_SYSTEM_LEVEL     = 0x00000001,
    PLATFORM_PM_WAKEUP_PF_RTC               = 0x00000100,
    PLATFORM_PM_WAKEUP_RTC                  = 0x00000200,
    PLATFORM_PM_WAKEUP_MAC                  = 0x00000400,
    PLATFORM_PM_WAKEUP_GPIO                 = 0x00000800,
    PLATFORM_WAKEUP_REASON_USB              = 0x00001000,
    PLATFORM_WAKEUP_REASON_LPCOMP           = 0x00002000,
    PLATFORM_WAKEUP_REASON_AON_QUAD_DEC     = 0x00004000,
    PLATFORM_PM_WAKEUP_DEF_MAX              = 0xFFFFFFFF,
} PlatformWakeupReason;

typedef enum
{
    PLATFORM_PM_ERROR_UNKNOWN               = 0x0,
    PLATFORM_PM_ERROR_POWER_MODE            = 0x1,
    PLATFORM_PM_ERROR_DISABLE_DLPS_TIME     = 0x2,
    PLATFORM_PM_ERROR_32K_CHECK_LOCK        = 0x3,
    PLATFORM_PM_ERROR_LOG_DMA_NOT_IDLE      = 0x4,
    PLATFORM_PM_ERROR_LOG_BUFFER_NOT_EMPTY  = 0x5,
    PLATFORM_PM_ERROR_CALLBACK_CHECK        = 0x6,
    PLATFORM_PM_ERROR_INTERRUPT_OCCURRED    = 0x7,
    PLATFORM_PM_ERROR_WAKEUP_TIME           = 0x8,
    PLATFORM_PM_ERROR_OCCUPIED_TIME         = 0x9,
} PlatformPowerModeErrorCode;

typedef PMCheckResult(*PlatformPMCheckCbFunc)(uint32_t *);
typedef void (*PlatformPMStoreCbFunc)(void);
typedef void (*PlatformPMRestoreCbFunc)(void);
typedef void (*PlatformPMEnterCbFunc)(void);
typedef void (*PlatformPMExitCbFunc)(void);
typedef void (*PlatformPMPendCbFunc)(void);

typedef void (*PlatformPMScheduleBottomHalfFunc)(void (*)(void));

typedef struct _PlatformPMCbFuncQueueElem
{
    struct _PlatformPMCbFuncQueueElem *pNext;
    void *cb_func;
    int8_t priority;
} PlatformPMCbFuncQueueElem;

typedef struct _PlatformPMSystem
{
    PlatformPowerMode power_mode;

    PlatformWakeupReason wakeup_reason;
    PlatformPowerModeErrorCode error_code;
    uint32_t *refuse_reason;

    uint32_t wakeup_count;
    uint32_t allow_sleep_count;
    uint32_t last_wakeup_clk;
    uint32_t last_sleep_clk;
    uint32_t total_wakeup_time;
    uint32_t total_sleep_time;

    uint32_t stage_time[PLATFORM_PM_STAGE_MAX];
    uint32_t minimum_sleep_time;
    uint32_t learning_guard_time;

    T_OS_QUEUE callback_func_queue[PLATFORM_PM_STAGE_MAX];

    PlatformPMScheduleBottomHalfFunc schedule_bottom_half_callback;
} PlatformPMSystem;

typedef union _PlatformPMFeatureConfig
{
    uint8_t value[1];
    struct
    {
        uint8_t platform_check_dbg:                 1;
        uint8_t platform_enter_dbg:                 1;
        uint8_t platform_exit_dbg:                  1;
        uint8_t platform_stage_time:                1;
        uint8_t platform_statistics:                1;
        uint8_t rsvd1:                              3;
    };
} PlatformPMFeatureConfig;

/** @} */ /* End of group PLATFORM_PM_Exported_Types */

/*============================================================================*
 *                              Variables
 *============================================================================*/
/** @defgroup PLATFORM_PM_Exported_Variables Platform_PM Exported Variables
  * @{
  */

extern PlatformPMFeatureConfig platform_pm_feature_cfg;
extern PlatformPMSystem platform_pm_system;

extern void (*platform_pm_hw_enter_flow)(void);
extern void (*platform_pm_hw_exit_flow)(void);
extern void (*platform_pm_cpu_enter_flow)(void);
extern void (*platform_pm_cpu_exit_flow)(void);

extern PMCheckResult(*platform_pm_wakeup_time)(const uint32_t, const uint32_t, uint32_t *);
extern PMCheckResult(*platform_pm_check)(const uint32_t, const uint32_t, uint32_t *);
extern void (*platform_pm_store)(void);
extern void (*platform_pm_restore)(void);
extern void (*platform_pm_enter)(void);
extern void (*platform_pm_exit)(void);
extern void (*platform_pm_pend)(void);
extern void (*platform_pm_init)(void);
extern void (*platform_pm_statistics)(void);

extern uint32_t (*platform_pm_get_extra_wait_cnt)(void);
extern void (*platfom_pm_callback_queue_in)(T_OS_QUEUE *, PlatformPMCbFuncQueueElem *, bool);
extern void (*platform_pm_register_callback_func_with_priority)(void *, PlatformPMStage, int8_t);
extern void (*platform_pm_register_callback_func)(void *, PlatformPMStage);
/** @} */ /* End of group PLATFORM_PM_Exported_Variables */

/*============================================================================*
 *                              Functions
 *============================================================================*/

/** @defgroup PLATFORM_PM_Exported_Functions Platform_PM Exported Functions
  * @{
  */

void platform_pm_set_power_mode(PlatformPowerMode pf_power_mode_user);
PlatformPowerMode platform_pm_get_power_mode(void);
PlatformPowerModeErrorCode platform_pm_get_error_code(void);
uint32_t *platform_pm_get_refuse_reason(void);
void platform_pm_get_statistics(uint32_t *wakeup_count, uint32_t *last_wakeup_clk,
                                uint32_t *last_sleep_clk);
PlatformWakeupReason platform_pm_get_wakeup_reason(void);
void platform_pm_register_schedule_bottom_half_callback_func(PlatformPMScheduleBottomHalfFunc
                                                             cb_func);

/** @} */ /* End of group PLATFORM_PM_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif  /* __POWER_MANAGER_UNIT_PLATFORM_H */

