/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

extern bool (*patch_ram_vector_table_update)(int irqn, IRQ_Fun isr_handler, bool *ret);
extern void default_handler(void);

extern void (*wakeup_init)(void);
extern void (*power_manager_init)(void);
extern void (*platform_pm_init)(void);
extern void (*thermal_meter_init)(void);
extern void phy_hw_control_init(bool);
extern void (*phy_init)(bool);
extern void (*thermal_tracking_init)(void);
extern void (*amu_script_init)(void);
extern void (*amu_init)(void);
