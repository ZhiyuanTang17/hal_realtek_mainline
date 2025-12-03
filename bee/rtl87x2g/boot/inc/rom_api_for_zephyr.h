/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <patch_header_check.h>
extern const T_ROM_HEADER_FORMAT nonsecure_rom_header;
typedef bool (*BOOL_PATCH_FUNC)();
extern void (*set_active_mode_clk_src)(void);
extern uint32_t (*get_stack_en)(void);
extern bool (*log_buffer_init)(void);
extern void (*log_gdma_init)(void);
extern void (*si_flow_data_init)(void);
extern void (*hal_setup_hardware)(void);
extern void (*hal_setup_cpu)(void);
extern void (*hal_setup_fpu)(void);
extern bool (*mpu_setup)(void);
extern void (*set_up_32k_clk_src)(void);
extern void (*set_lp_module_clk_info)(void);
extern void (*platform_rtc_aon_init)(void);
extern void (*power_manager_master_init)(void);
extern void (*power_manager_slave_init)(void);
extern void (*platform_pm_init)(void);
extern void (*phy_hw_control_init)(bool);
extern void (*flash_task_init)(void);
extern uint32_t (*ftl_init)(uint32_t u32PageStartAddr, uint8_t pagenum);
extern void (*secure_platform_func_ptr_init)(void);
extern void (*secure_os_func_ptr_init)(void);
extern void flash_nor_dump_main_info(void);
extern bool flash_nor_cmd_list_init_nsc(void);
extern void flash_nor_init_bp_lv_nsc(void);
extern void setup_non_secure_nvic(void);
extern void (*ft_paras_apply)(void);
extern void (*pmu_apply_voltage_tune)(void);
extern void (*pmu_power_on_sequence_restart)(void);
extern void (*si_flow_after_exit_low_power_mode)(void);
extern void (*pmu_pm_exit)(void);
extern void (*dvfs_init)(void);
extern void (*phy_hw_control_init)(bool);
extern void (*phy_init)(uint8_t);
extern void (*thermal_tracking_timer_init)(void);
extern void init_osc_sdm_timer(void);
extern void hw_aes_mutex_init(void);
extern void HardFault_Handler_Rom(void);
extern void GDMA0_Channel9_Handler(void);
extern void PF_RTC_Handler(void);
typedef void (*PMFuncToReturn)(void);
void power_manager_slave_register_function_to_return(PMFuncToReturn func);
