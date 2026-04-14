/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
   * @file      mem_cfg_int.h
   * @brief     memory config header file for internal project
   * @details
   * @author
   * @date
   * @version
   **************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
  *                   Define to prevent recursive inclusion
  *============================================================================*/
#ifndef _MEM_CFG_INT_H
#define _MEM_CFG_INT_H
#include "mem_config.h"
//#include "address_map.h"

/*============================================================================*
  *                               Memory Address Map
  * refence wiki:
  *============================================================================*/


/*============================================================================*
  *                                   ROM layout
  *============================================================================*/
/* ROM:          Bee5 size: 16K
example:
   1) rom code:    16K
*/
#define ROM_ADDR                     0x0
#define ROM_SIZE                     0x00004000 // 16K


/*============================================================================*
  *                                   Other internal defines
  *============================================================================*/
#define MAIN_STACK_START_ADDR       DATA_RAM_MAIN_STACK_START_ADDR
#define MAIN_STACK_SIZE             DATA_RAM_MAIN_STACK_SIZE

#endif  //_MEM_CFG_INT_H

