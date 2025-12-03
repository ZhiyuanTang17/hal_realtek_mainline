#ifndef __CM0PLUS_SETTING_H__
#define __CM0PLUS_SETTING_H__

/* ----------------Configuration of the cm0+ Processor and Core Peripherals---------------- */
#define __VTOR_PRESENT CONFIG_CPU_CORTEX_M_HAS_VTOR /* VTOR present or not */
#define __MPU_PRESENT                  1            /*!< MPU present or not                                                    */
#define __FPU_PRESENT                  0            /* FPU present                                                             */
#define __NVIC_PRIO_BITS               3            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0           /*!< Set to 1 if different SysTick Config is used                          */


#endif /* __CM0PLUS_SETTING_H__ */


