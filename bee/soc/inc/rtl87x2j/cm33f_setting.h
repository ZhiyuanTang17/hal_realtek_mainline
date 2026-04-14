#ifndef CM33F_SETTING_H
#define CM33F_SETTING_H

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */
#define __CHECK_DEVICE_DEFINES
#define __CM33_REV                     0x0000U    //!< Core revision
#define __MPU_PRESENT                  1          //!< MPU present or not
#define __SAUREGION_PRESENT            0          //!< SAU present or not
#define __VTOR_PRESENT                 1          //!< VTOR present or not
#define __FPU_PRESENT                  1          //!< FPU present or not
#define __DSP_PRESENT                  1          //!< DSP extension present or not
#define __NVIC_PRIO_BITS               3          //!< Number of Bits used for Priority Levels
#define __Vendor_SysTickConfig         0          //!< Set to 1 if different SysTick Config is used

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "vector_table.h"
#include "core_cm33.h"                       /* Processor and core peripherals */

#endif //#define CM33F_SETTING_H
