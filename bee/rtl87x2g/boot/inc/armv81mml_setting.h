/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ARMV81_SETTING_H
#define ARMV81_SETTING_H

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */
#define __ARMv8MML_REV            0x0001U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __FPU_DP                  0U        /* single precision FPU */
#define __DSP_PRESENT             1U        /* DSP extension present */
#define __ICACHE_PRESENT          1U
#define __DCACHE_PRESENT          1U

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "vector_table.h"
#include "core_cm55.h"                       /* Processor and core peripherals */

#endif //#define ARMV81_SETTING_H
