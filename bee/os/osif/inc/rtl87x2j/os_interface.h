#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

#include <stdint.h>
#include <stddef.h>
#include "section.h"
#include "os_mem.h"
#include "osif.h"
#include "os_sched.h"

typedef struct _OS_INTERFACE_INFO
{
    void *(*os_mem_alloc_intern)(RAM_TYPE ram_type, size_t size);
    void *(*os_mem_zalloc_intern)(RAM_TYPE ram_type, size_t size);
    void *(*os_mem_aligned_alloc_intern)(RAM_TYPE ram_type, size_t size, uint8_t alignment);
    void *(*os_mem_realloc_intern)(RAM_TYPE ram_type, void *ptr, size_t size);
    void (* os_mem_free)(void *p_block);
    void (* os_mem_aligned_free)(void *p_block);
    size_t (* os_mem_peek)(RAM_TYPE ram_type);
    size_t (* os_mem_peek_max_free_block)(RAM_TYPE ram_type);
    void (* os_mem_check_heap_usage)(void);

    bool (* os_msg_queue_create)(void **pp_handle,  const char *p_name, uint32_t msg_num,
                                 uint32_t msg_size);
    bool (* os_msg_queue_delete_intern)(void *p_handle);
    bool (* os_msg_queue_peek_intern)(void *p_handle, uint32_t *p_msg_num);
    bool (* os_msg_send_intern)(void *p_handle, void *p_msg, uint32_t wait_ms);
    bool (* os_msg_recv_intern)(void *p_handle, void *p_msg, uint32_t wait_ms);
    bool (* os_msg_peek_intern)(void *p_handle, void *p_msg, uint32_t wait_ms);

    bool (* os_alloc_secure_ctx)(uint32_t stack_size);
    bool (* os_task_create)(void **pp_handle, const char *p_name, void (*p_routine)(void *),
                            void *p_param, uint16_t stack_size, uint16_t priority);
    bool (* os_task_delete)(void *p_handle);
    bool (* os_task_suspend)(void *p_handle);
    bool (* os_task_resume)(void *p_handle);
    bool (* os_task_yield)(void);
    bool (* os_task_handle_get)(void **pp_handle);
    bool (* os_task_priority_get)(void *p_handle, uint16_t *p_priority);
    bool (* os_task_priority_set)(void *p_handle, uint16_t priority);
    bool (* os_task_signal_send)(void *p_handle, uint32_t signal);
    bool (* os_task_signal_recv)(uint32_t *p_signal, uint32_t wait_ms);
    bool (* os_task_signal_clear)(void *p_handle);
    void (* os_task_status_dump)(void);

    bool (* os_timer_id_get)(void **pp_handle, uint32_t *p_timer_id);
    bool (* os_timer_create)(void **pp_handle, const char *p_timer_name, uint32_t timer_id,
                             uint32_t interval_ms, bool reload, void (*p_timer_callback)(void *));
    bool (* os_timer_start)(void **pp_handle);
    bool (* os_timer_restart)(void **pp_handle, uint32_t interval_ms);
    bool (* os_timer_stop)(void **pp_handle);
    bool (* os_timer_delete)(void **pp_handle);
    bool (* os_timer_pend_function_call)(void (*p_pend_function)(void *, uint32_t),
                                         void *pvParameter1, uint32_t ulParameter2);
    bool (* os_timer_state_get)(void **pp_handle, uint32_t *p_timer_state);
    bool (* os_timer_auto_reload_get)(void **pp_handle, long *p_autoreload);
    bool (* os_timer_handle_get)(uint8_t timer_idx, void **pp_handle);
    bool (* os_timer_dump)(void);
    void (* os_timer_init)(void);

    uint32_t (* os_lock)(void);
    void (* os_unlock)(uint32_t s);
    bool (* os_sem_create)(void **pp_handle, const char *p_name, uint32_t init_count,
                           uint32_t max_count);
    bool (* os_sem_delete)(void *p_handle);
    bool (* os_sem_take)(void *p_handle, uint32_t wait_ms);
    bool (* os_sem_give)(void *p_handle);
    bool (* os_mutex_create)(void **pp_handle);
    bool (* os_mutex_delete)(void *p_handle);
    bool (* os_mutex_take)(void *p_handle, uint32_t wait_ms);
    bool (* os_mutex_give)(void *p_handle);

    void (* os_init)(void);
    void (* os_delay)(uint32_t ms);
    uint64_t (* os_sys_time_get)(void);
    uint64_t (* os_sys_tick_get)(void);
    uint64_t (* os_hp_time_get)(void);
    bool (* os_sched_start)(void);
    bool (* os_sched_stop)(void);
    bool (* os_sched_suspend)(void);
    bool (* os_sched_resume)(void);
    bool (* os_sched_state_get)(long *p_state);
    bool (* os_bottom_half)(T_OSIF_WORK_FUNC func, void *p_arg);

    bool (* os_sched_restore)(void);
    void (* os_timer_tick_handler)(void);
    uint32_t (* os_timer_tick_rate_get)(void);
    uint32_t (* os_timer_clock_get)(void);
    uint64_t (* os_timer_tick_increase)(uint32_t tick_increment);
    uint32_t (* os_pm_next_timeout_value_get)(void);
    bool (* os_pm_excluded_handle_register)(void **handle, PlatformExcludedHandleType type);
    bool (* os_pm_excluded_handle_unregister)(void **handle, PlatformExcludedHandleType type);
    void (* os_pm_tickcount_store)(void);
    void (* os_pm_tickcount_restore)(void);
    void (* os_pm_init)(void);

} T_OS_INTERFACE_INFO;

extern T_OS_INTERFACE_INFO os_interface;

#endif /* OS_INTERFACE_H */