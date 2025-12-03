/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __MEM_CONFIG__
#define __MEM_CONFIG__

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup MEM_CONFIG Memory Configure
  * @brief Memory configuration for user application
  * @{
  */
// Build Bank Configure
#define BUILD_BANK                  0   //Bank0 as default

//Enable RAM Code
#define FEATURE_RAM_CODE            0

/** @brief encrypt app or not */
#define FEATURE_ENCRYPTION          0

//Use Cache RAM to run RAM Code
#define FEATURE_CACHE_RAM_CODE      0

//default disable trustzone
#define FEATURE_TRUSTZONE_ENABLE    0

/*============================================================================*
  *                            Memory layout
  *============================================================================*/
#define SPIC0_ADDR            0x04000000
#define SPIC0_SIZE            (64*1024*1024)
#define SPIC1_ADDR            0x08000000
#define SPIC1_SIZE            (64*1024*1024)
#define SPIC2_ADDR            0x10000000
#define SPIC2_SIZE            (256*1024*1024)

#define ITCM1_ADDR            0x00100000
#define ITCM1_SIZE            (192*1024)

#define DTCM0_ADDR            0x00130000
#define DTCM0_SIZE            (64*1024)

#define DTCM1_ADDR            0x00140000
#define DTCM1_SIZE            (64*1024)

#define DATA_SRAM_ADDR        0x00200000
#define DATA_SRAM_SIZE        (16*1024)

#define BUFFER_RAM_ADDR       0x00280000
#define BUFFER_RAM_SIZE       (48*1024)

#define VECTOR_TABLE_ITEMS    (187)

/*============================================================================*
  *                    Non Secure Buffer RAM layout
  *============================================================================*/
/* --------------------The following macros should not be modified!------------------------- */
#define BUFFER_ON_GLOBAL_SIZE           (1024 + 512)
#define BUFFER_ON_HEAP_ADDR             (BUFFER_RAM_ADDR + BUFFER_ON_GLOBAL_SIZE)
#define BUFFER_ON_HEAP_SIZE             (BUFFER_RAM_SIZE - BUFFER_ON_GLOBAL_SIZE)

/*============================================================================*
  *                       Non Secure Ext Data SRAM layout
  *============================================================================*/
#define EXT_DATA_SRAM_GLOBAL_SIZE       (0*1024)

/* --------------------The following macros should not be modified!------------------------- */
#define EXT_DATA_SRAM_GLOBAL_ADDR       DATA_SRAM_ADDR
#define EXT_DATA_SRAM_HEAP_ADDR         (EXT_DATA_SRAM_GLOBAL_ADDR + EXT_DATA_SRAM_GLOBAL_SIZE)
#define EXT_DATA_SRAM_HEAP_SIZE         (DATA_SRAM_SIZE - EXT_DATA_SRAM_GLOBAL_SIZE)


/*=======================================================================================*
  *                                 ITCM1 + DTCM0 + DTCM1 layout
  *=====================================================================================*/
/* RAM(ITCM1):          rtl87x2g size: 192K
 * RAM(DTCM0):          rtl87x2g size:  64K
 * RAM(DTCM1):          rtl87x2g size:  64K
 * Total RAM(TCM):      rtl87x2g size: 320K
example:
   a) non-secure total size:                          243K
      1) non-secure upperstack ram         3K (adjustable, depend on used upperstack version, config NS_RAM_UPPERSTACK_SIZE)
      2) non-secure APP ram                40K (adjustable, config NS_RAM_APP_SIZE)
      3) non-secure tcm heap               200K (adjustable, config NS_HEAP_SIZE)
   b) non-secure system reserved size:                57K
      1) non-secure rom global             7K - 64B (fixed)
      2) non-secure lowstack rom global    11K + 64B (fixed)
      3) non-secure stack patch ram        25K (fixed)
      4) non-secure patch global and code  14K (fixed)
   c) secure system reserved size:                    20K
      1) secure boot patch ram             12K (fixed)
      2) secure main stack                 3K (fixed)
      3) secure rom global                 5K (fixed)
*/
/** @brief tcm ram size for upperstack global variables and code, could be changed */
#define NS_RAM_UPPERSTACK_SIZE          (3*1024)
/** @brief tcm ram size for app global variables and code, could be changed */
#define NS_RAM_APP_SIZE                 (40*1024)

/* --------------------The following macros should not be modified!------------------------- */
#define TCM_START_ADDR                  ITCM1_ADDR
#define TCM_TOTAL_SIZE                  (ITCM1_SIZE + DTCM0_SIZE + DTCM1_SIZE)

/** @brief secure rom system reserved size, can't be modified */
#define S_RAM_SYSTEM_RESERVED_SIZE      (20*1024)
/** @brief non-secure rom system reserved size, can't be modified */
#define NS_RAM_SYSTEM_RESERVED_SIZE     (57*1024)
#define NS_RAM_APP_RESERVED_SIZE        (TCM_TOTAL_SIZE - S_RAM_SYSTEM_RESERVED_SIZE - NS_RAM_SYSTEM_RESERVED_SIZE)

#if (S_RAM_SYSTEM_RESERVED_SIZE + NS_RAM_SYSTEM_RESERVED_SIZE + S_RAM_APP_RESERVED_SIZE > TCM_TOTAL_SIZE)
#error "TCM Config size error"
#endif

/* --------------------The following macros should not be modified!------------------------- */
#define NS_RAM_UPPERSTACK_ADDR          (TCM_START_ADDR)
#define NS_RAM_APP_ADDR                 (NS_RAM_UPPERSTACK_ADDR + NS_RAM_UPPERSTACK_SIZE)
#define NS_HEAP_ADDR                    (NS_RAM_APP_ADDR + NS_RAM_APP_SIZE)
#define NS_HEAP_SIZE                    (NS_RAM_APP_RESERVED_SIZE - NS_RAM_APP_SIZE - NS_RAM_UPPERSTACK_SIZE)

#if (NS_RAM_UPPERSTACK_SIZE + NS_RAM_APP_SIZE > NS_RAM_APP_RESERVED_SIZE)
#error "non-secure app ram size config error"
#endif

/* --------------------The following macros should not be modified!------------------------- */
#define S_RAM_ROM_GLOBAL_SIZE           (5*1024)
#define S_RAM_MAIN_STACK_SIZE           (3*1024)

#define S_RAM_ROM_GLOBAL_ADDR           (TCM_START_ADDR + TCM_TOTAL_SIZE - S_RAM_ROM_GLOBAL_SIZE)
#define S_RAM_MAIN_STACK_START_ADDR     (S_RAM_ROM_GLOBAL_ADDR - S_RAM_MAIN_STACK_SIZE)

#define S_RAM_VECTOR_ADDR               (S_RAM_ROM_GLOBAL_ADDR)
#define S_RAM_VECTOR_SIZE               (VECTOR_TABLE_ITEMS*4)

/* ------------------------------------------------------------------------------------------------------- */

/** @} */ /* End of group MEM_CONFIG_Exported_Constents */



#ifdef __cplusplus
}
#endif


/** @} */ /* End of group MEM_CONFIG */

#endif

