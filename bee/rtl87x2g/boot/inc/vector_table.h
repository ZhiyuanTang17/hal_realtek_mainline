/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdbool.h"
#include "vector_table_auto_gen.h"

/** @defgroup VECTOR_TABLE  Vector table
  * @brief
  * @{
  */

/** @defgroup VECTOR_TABLE_Exported_Types Vector table Exported Types
  * @brief
  * @{
  */

typedef void (*IRQ_Fun)(void);       /**< ISR Handler Prototype */

/* ================================================================================ */
/* ================                      IRQ                       ================ */
/* ================================================================================ */

typedef enum IRQn
{
    IRQn_AUTO_GEN
} IRQn_Type;

/* ================================================================================ */
/* ================                     VECTOR                     ================ */
/* ================================================================================ */

typedef enum
{
    VECTORn_AUTO_GEN
} VECTORn_Type;

extern void *RamVectorTable[];

extern void Default_Handler_rom(void);
extern void BTMAC_Handler(void);

/** End of VECTOR_TABLE_Exported_Types
  * @}
  */

/*============================================================================*
*                              Functions
*============================================================================*/
/** @defgroup VECTOR_TABLE_Exported_Functions Vector table Exported Functions
  * @brief
  * @{
  */
/**
 * @brief  Initialize RAM vector table to a given RAM address.
 * @param  ram_vector_addr: RAM Vector Address.
 * @retval true: Success
 *         false: Fail
 * @note   When using vector table relocation, the base address of the new vector
 *         table must be aligned to the size of the vector table extended to the
 *         next larger power of 2. In RTL8763, the base address is aligned at 0x100.
 */
bool RamVectorTableInit(uint32_t ram_vector_addr);

/**
 * @brief  Update ISR Handler in RAM Vector Table.
 * @param  v_num: Vector number(index)
 * @param  isr_handler: User defined ISR Handler.
 * @retval true: Success
 *         false: Fail
 */
bool RamVectorTableUpdate(VECTORn_Type v_num, IRQ_Fun isr_handler);

/** End of VECTOR_TABLE_Exported_Functions
  * @}
  */

/** End of VECTOR_TABLE
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif // VECTOR_TABLE_H
