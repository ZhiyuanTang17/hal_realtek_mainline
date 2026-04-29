/*
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _OSIF_H_
#define _OSIF_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cmsis_compiler.h"
#include "mem_types.h"
#include "os_pm.h"
#include "os_sched.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    OS_EXE_SUCCESS = 0,
    OS_EXE_FAIL,
    OS_EXE_ERROR_HANDLE_IS_NULL,
    OS_EXE_ERROR_PTR_HANDLE_IS_NULL,
    OS_EXE_ERROR_PTR_HANDLE_NOT_NULL,
    OS_EXE_ERROR_NOTIFY_IS_NULL,
    OS_EXE_ERROR_AUTORELOAD_IS_NULL,
    OS_EXE_ERROR_TIMER_NUMBER_IS_NULL,
    OS_EXE_ERROR_TIMER_CALLBACK_IS_NULL,
    OS_EXE_ERROR_STATE_IS_NULL,
    OS_EXE_ERROR_PRIORITY_IS_NULL,
    OS_EXE_ERROR_MUTEX_HOLDER_NOT_NULL,
    OS_EXE_ERROR_INPUT_PARA_PTR_IS_NULL,
} OS_EXE_TYPE;

typedef void (*USER_CALL_BACK)();

/* task & isr context check interface */
// static inline bool osif_task_context_check(void);

// void osif_init(void);

// /* OS schedule interfaces */
// void osif_delay(uint32_t ms);
// uint64_t osif_sys_time_get(void);
// uint64_t osif_sys_tick_get(void);
// uint64_t osif_hp_time_get(void);
// bool osif_sched_start(void);
// bool osif_sched_stop(void);
// bool osif_sched_suspend(void);
// bool osif_sched_resume(void);
// bool osif_sched_restore(void);
// bool osif_sched_state_get(long *p_state);
// bool osif_bottom_half(T_OSIF_WORK_FUNC func, void *p_arg);

// /* OS task interfaces */
// bool osif_alloc_secure_ctx(uint32_t stack_size);
// bool osif_task_create(void **pp_handle, const char *p_name, void (*p_routine)(void *),
//                       void *p_param, uint16_t stack_size, uint16_t priority);
// bool osif_task_delete(void *p_handle);
// bool osif_task_suspend(void *p_handle);
// bool osif_task_resume(void *p_handle);
// bool osif_task_yield(void);
// bool osif_task_handle_get(void **pp_handle);
// bool osif_task_priority_get(void *p_handle, uint16_t *p_priority);
// bool osif_task_priority_set(void *p_handle, uint16_t priority);
// bool osif_task_signal_send(void *p_handle, uint32_t signal);
// bool osif_task_signal_recv(uint32_t *p_signal, uint32_t wait_ms);
// bool osif_task_signal_clear(void *p_handle);
// void osif_task_status_dump(void);

// /* OS synchronization interfaces */
// uint32_t osif_lock(void);
// void osif_unlock(uint32_t flags);
// bool osif_sem_create(void **pp_handle,  const char *p_name, uint32_t init_count,
//                      uint32_t max_count);
// bool osif_sem_delete(void *p_handle);
// bool osif_sem_take(void *p_handle, uint32_t wait_ms);
// bool osif_sem_give(void *p_handle);
// bool osif_mutex_create(void **pp_handle);
// bool osif_mutex_delete(void *p_handle);
// bool osif_mutex_take(void *p_handle, uint32_t wait_ms);
// bool osif_mutex_give(void *p_handle);

// /* OS message queue interfaces */
// bool osif_msg_queue_create(void **pp_handle,  const char *p_name, uint32_t msg_num,
//                            uint32_t msg_size);
// bool osif_msg_queue_delete(void *p_handle);
// bool osif_msg_queue_peek(void *p_handle, uint32_t *p_msg_num);
// bool osif_msg_send(void *p_handle, void *p_msg, uint32_t wait_ms);
// bool osif_msg_recv(void *p_handle, void *p_msg, uint32_t wait_ms);
// bool osif_msg_peek(void *p_handle, void *p_msg, uint32_t wait_ms);

// /* OS memory management interfaces */
// void *osif_mem_alloc(RAM_TYPE ram_type, size_t size);
// void *osif_mem_aligned_alloc(RAM_TYPE ram_type, size_t size, uint8_t alignment);
// void *osif_mem_zalloc(RAM_TYPE ram_type, size_t size);
// void *osif_mem_realloc(RAM_TYPE ram_type, void *ptr, size_t size);
// void osif_mem_free(void *p_block);
// void osif_mem_aligned_free(void *p_block);
// size_t osif_mem_peek(RAM_TYPE ram_type);
// size_t osif_mem_peek_max_free_block(RAM_TYPE ram_type);
// void osif_mem_check_heap_usage(void);

// /* OS software timer interfaces */
// bool osif_timer_id_get(void **pp_handle, uint32_t *p_timer_id);
// bool osif_timer_create(void **pp_handle, const char *p_timer_name, uint32_t timer_id,
//                        uint32_t interval_ms, bool reload, void (*p_timer_callback)(void *));
// bool osif_timer_start(void **pp_handle);
// bool osif_timer_restart(void **pp_handle, uint32_t interval_ms);
// bool osif_timer_stop(void **pp_handle);
// bool osif_timer_delete(void **pp_handle);
// bool osif_timer_pend_function_call(void (*p_pend_function)(void *, uint32_t),
//                                    void *pvParameter1, uint32_t ulParameter2);
// bool osif_timer_auto_reload_get(void **pp_handle, long *p_autoreload);
// bool osif_timer_state_get(void **pp_handle, uint32_t *p_timer_state);
// bool osif_timer_handle_get(uint8_t timer_idx, void **pp_handle);
// bool osif_timer_dump(void);
// void osif_timer_init(void);

// /* OS software power manager interfaces */
// void osif_pm_init(void);
// void osif_timer_tick_handler(void);
// uint32_t osif_timer_tick_rate_get(void);
// uint32_t osif_timer_clock_get(void);
// uint64_t osif_timer_tick_increase(uint32_t tick_increment);

// uint32_t osif_pm_next_timeout_value_get(void);

// bool osif_pm_excluded_handle_register(void **handle, PlatformExcludedHandleType type);
// bool osif_pm_excluded_handle_unregister(void **handle, PlatformExcludedHandleType type);

// void osif_pm_tickcount_store(void);
// void osif_pm_tickcount_restore(void);

// void osif_pm_bottom_half(void (*pend_func)(void));
// void osif_pm_return_to_idle_task(void);

// /* OS external interfaces */
// void osif_sched_set_hook(void (*hook)(void *from, void *to));

#ifdef __cplusplus
}
#endif

#endif /* _OSIF_H_ */
