/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _MEM_TYPES_H_
#define _MEM_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup MEM_CONFIG Memory Configure
  * @{
  */

/*============================================================================*
 *                               Types
*============================================================================*/
/** @defgroup MEM_CONFIG_Exported_Types Memory Configure Exported Types
  * @{
  */

typedef enum
{
    RAM_TYPE_DATA_ON,        //DTCM Heap
    RAM_TYPE_DATA_OFF = RAM_TYPE_DATA_ON,
    RAM_TYPE_BUFFER_ON,
    RAM_TYPE_BUFFER_OFF = RAM_TYPE_BUFFER_ON,
    RAM_TYPE_EXT_DATA_SRAM,  //Ext DATA SRAM heap
    RAM_TYPE_NUM
} RAM_TYPE;

/** End of MEM_TYPES_Exported_Types
  * @}
  */

/** End of MEM_CONFIG
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* _MEM_TYPES_H_ */
