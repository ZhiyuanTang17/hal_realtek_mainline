/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    mem_config.h
  * @brief   Memory Configuration
  * @date    2024.4.28
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __MEM_CONFIG__
#define __MEM_CONFIG__

#ifdef __cplusplus
extern "C" {
#endif

//#include "address_map.h"


/** @defgroup MEM_CONFIG Memory Configure
  * @brief Memory configuration for user application
  * @{
  */
/** @defgroup MEM_CONFIG_Exported_Constant Mem Config Exported Constants
  * @{
  */

// Build Bank Configure
#define BUILD_BANK              0   //Bank0 as default

//Enable RAM Code
#define FEATURE_RAM_CODE        0

/** @brief encrypt app or not */
#define FEATURE_ENCRYPTION      0

//Use Cache RAM to run RAM Code
#define FEATURE_CACHE_RAM_CODE  0

/*============================================================================*
  *                            Memory layout
  *============================================================================*/
#define EFLASH_ADDR            0x02000000
#define EFLASH_SIZE            (720*1024)

#define EFLASH_NVR_ADDR        0x02200000
#define EFLASH_NVR_SIZE        (34*1024)

#define EFLASH_NVR_CFG_AREA_ADDR    0x04B00000
#define EFLASH_NVR_CFG_AREA_SIZE    (2*1024)

#define CODE_RAM_ADDR         0x00200000
#define CODE_RAM_SIZE         (0*1024)

#define DATA_RAM_ADDR         0x20000000
#define DATA_RAM_SIZE         (104*1024)

#define BUFFER_RAM_ADDR       0x20100000
#define BUFFER_RAM_SIZE       (24*1024)

/*============================================================================*
  *                            Eflash NVR layout
  *============================================================================*/
/* Fflash NVR:                  Bee5 size: 34K
example:
       1) OTP:                   1K
       3) OEM Header:            3K
       4) FTL                    16K
       5) User Data              14K
*/

#define OTP_TABLE_SIZE           (1*1024)
#define OEM_HEADER_SIZE          (3*1024)
#define FTL_SIZE                 (16*1024)

#define OTP_TABLE_ADDR           (EFLASH_NVR_ADDR)
#define OEM_HEADER_ADDR          OTP_TABLE_ADDR + OTP_TABLE_SIZE
#define FTL_ADDR                 OEM_HEADER_ADDR + OEM_HEADER_SIZE
#define USER_DATA_ADDR           FTL_ADDR + FTL_SIZE
#define USER_DATA_SIZE           EFLASH_NVR_ADDR + EFLASH_NVR_SIZE - USER_DATA_ADDR


/*============================================================================*
  *                                Data RAM layout
  *============================================================================*/
/* Data RAM:                  Bee5 size: 104K
example:
       1) boot patch:            5K
       2) sys patch:             4K
       3) bt controller:        12K
       4) bt host:               3K
       5) APP global:           24K
       6) heap:                 48K
       7) non_retention:       5.5K
       8) rom:                   1K + 64
       9) main stack:          1.5K - 64

*/
#define DATA_RAM_ROM_GLOBAL_SIZE          (1*1024 + 64)
#define DATA_RAM_MAIN_STACK_SIZE          (1*1024+512-64)
#define DATA_RAM_BOOT_PATCH_SIZE          (5*1024)
#define DATA_RAM_SYS_PATCH_SIZE           (4*1024)
#define DATA_RAM_BT_CONTROLLER_SIZE       (12*1024)
#define DATA_RAM_BT_HOST_SIZE             (3*1024)
#define DATA_RAM_APP_SIZE                 (24*1024)
#define DATA_NON_RETENTION_SIZE           (5*1024+512)
//#define DATA_HEAP_SIZE                    (48*1024)

/** @brief shared cache ram size (adjustable, config SHARE_CACHE_RAM_SIZE: 0/4KB/8KB) */
#define SHARE_CACHE_RAM_SIZE           (0 * 1024)


/* -----------------The following macros should not be modified!------------------------- */
#define DATA_RAM_BOOT_PATCH_ADDR           (DATA_RAM_ADDR)
#define DATA_RAM_SYS_PATCH_ADDR            (DATA_RAM_BOOT_PATCH_ADDR + DATA_RAM_BOOT_PATCH_SIZE)
#define DATA_RAM_BT_CONTROLLER_ADDR        (DATA_RAM_SYS_PATCH_ADDR + DATA_RAM_SYS_PATCH_SIZE)
#define DATA_RAM_BT_HOST_ADDR              (DATA_RAM_BT_CONTROLLER_ADDR + DATA_RAM_BT_CONTROLLER_SIZE)
#define DATA_RAM_APP_ADDR                  (DATA_RAM_BT_HOST_ADDR + DATA_RAM_BT_HOST_SIZE)
#define DATA_HEAP_ADDR                     (DATA_RAM_APP_ADDR + DATA_RAM_APP_SIZE)
#define DATA_HEAP_SIZE                     (DATA_NON_RETENTION_ADDR - DATA_HEAP_ADDR)
#define DATA_NON_RETENTION_ADDR            (DATA_RAM_ADDR + DATA_RAM_SIZE - DATA_NON_RETENTION_SIZE - DATA_RAM_MAIN_STACK_SIZE - DATA_RAM_ROM_GLOBAL_SIZE)
#define DATA_RAM_ROM_GLOBAL_ADDR           (DATA_NON_RETENTION_ADDR + DATA_NON_RETENTION_SIZE)
#define DATA_RAM_MAIN_STACK_START_ADDR     (DATA_RAM_ROM_GLOBAL_ADDR + DATA_RAM_ROM_GLOBAL_SIZE)

//alias
#define MAIN_STACK_START_ADDR              DATA_RAM_MAIN_STACK_START_ADDR
#define MAIN_STACK_SIZE                    DATA_RAM_MAIN_STACK_SIZE

/*============================================================================*
  *                                 Buffer RAM layout
  *============================================================================*/
/* Buffer RAM:                 Bee5 size: 24K
example:
   1) global:        2K
   1) heap:          22K
*/
#define BUFFER_RAM_GLOBAL_SIZE             (2*1024)
/* -----------------The following macros should not be modified!------------------------- */
#define BUFFER_RAM_GLOBAL_ADDR             (BUFFER_RAM_ADDR)
#define BUFFER_HEAP_ADDR                   (BUFFER_RAM_GLOBAL_ADDR + BUFFER_RAM_GLOBAL_SIZE)
#define BUFFER_HEAP_SIZE                   (BUFFER_RAM_SIZE - BUFFER_RAM_GLOBAL_SIZE)

/** @} */ /* End of group MEM_CONFIG_Exported_Constents */



#ifdef __cplusplus
}
#endif


/** @} */ /* End of group MEM_CONFIG */

#endif

