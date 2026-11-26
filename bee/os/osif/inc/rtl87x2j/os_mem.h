/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OS_MEM_H_
#define _OS_MEM_H_

#include <stdint.h>
#include <stddef.h>
#include "mem_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup Memory  Memory Management
 *
 * @brief Allocate, free, and peek memory functions.
 * @details The Memory Management function group allows to allocate, free, and peek heap
 *          memory in the system.
 *
 * @ingroup OS
 * @{
 */


/**
 * os_mem.h
 *
 * @brief Allocate a memory block with required size.
 *
 * @param[in]   ram_type            RAM type for allocation.
 *                                  - RAM_TYPE_DATA_ON: Data ON RAM type.
 *                                  - RAM_TYPE_BUFFER_ON: BUFFER ON RAM type.
 *
 * @param[in]   size     Required memory size.
 *
 * @return The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_alloc(RAM_TYPE_DATA_ON, mem_size);
 *     if (p_mem != NULL)
 *     {
 *         // Memory allocation successed, and free it.
 *         os_mem_free(p_mem);
 *     }
 *     else
 *     {
 *         // Memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup Memory
 */

void *os_mem_alloc(RAM_TYPE ram_type, size_t size);

/**
 * os_mem.h
 *
 * @brief Allocate and clear a memory block with required size.
 *
 * @param[in]   ram_type            RAM type for allocation.
 *                                  - RAM_TYPE_DATA_ON: Data ON RAM type.
 *                                  - RAM_TYPE_BUFFER_ON: BUFFER ON RAM type.
 *
 * @param[in]   size     Required memory size.
 *
 * @return The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_zalloc(RAM_TYPE_DATA_ON, mem_size);
 *     if (p_mem != NULL)
 *     {
 *         // Memory allocation successed, and free it.
 *         os_mem_free(p_mem);
 *     }
 *     else
 *     {
 *         // Memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup Memory
 */
void *os_mem_zalloc(RAM_TYPE ram_type, size_t size);

/**
 * os_mem.h
 *
 * @brief    Allocate a memory block with required size and address alignment.
 *
 * @note     The memory block allocated by this function shall be freed by
 *           os_mem_aligned_free(), not by os_mem_free().
 *
 * @param[in]   ram_type            RAM type for allocation.
 * \arg @c      RAM_TYPE_DATA_ON    Data ON RAM type.
 * \arg @c      RAM_TYPE_BUFFER_ON  BUFFER ON RAM type.
 *
 * @param[in]   size        Required memory size.
 *
 * @param[in]   alignment   Required address alignment in bytes. It shall be a power of 2.
 *                          If it is zero, the default heap alignment is used.
 *
 * @return     The aligned address of the allocated memory block. If the address is NULL,
 *             the memory allocation failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_aligned_alloc(RAM_TYPE_DATA_ON, mem_size, 32);
 *     if (p_mem != NULL)
 *     {
 *         // Memory allocation successed, and free it.
 *         os_mem_aligned_free(p_mem);
 *     }
 *     else
 *     {
 *         // Memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup  Memory
 */
void *os_mem_aligned_alloc(RAM_TYPE ram_type, size_t size, uint8_t alignment);


/**
 * os_mem.h
 *
 * @brief Resize a previously allocated memory block.
 *
 * @param[in]   ram_type  RAM type for allocation.
 *                        - RAM_TYPE_DATA_ON: Data ON RAM type.
 *                        - RAM_TYPE_BUFFER_ON: BUFFER ON RAM type.
 *
 * @param[in]   ptr       The address of the memory block to resize. If the address is NULL,
 *                        a new memory block is allocated.
 *
 * @param[in]   size      New memory size. If size is zero, the memory block is freed.
 *
 * @return The address of the resized memory block. If the address is NULL, the
 *             memory reallocation failed or the requested size was zero.
 *
 * @ingroup Memory
 */
void *os_mem_realloc(RAM_TYPE ram_type, void *ptr, size_t size);

/**
 * os_mem.h
 *
 * @brief Free a memory block that had been allocated.
 *
 * @param[in]   p_block     The address of memory block being freed.
 *
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_alloc(RAM_TYPE_DATA_ON, mem_size);
 *     if (p_mem != NULL)
 *     {
 *         // Memory allocation successed, and free it.
 *         os_mem_free(p_mem);
 *     }
 *     else
 *     {
 *         // Memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup Memory
 */
void os_mem_free(void *p_block);

/**
 * os_mem.h
 *
 * @brief    Free an aligned memory block that had been allocated by
 *           os_mem_aligned_alloc().
 *
 * @param[in]   p_block The address of the aligned memory block being freed.
 *
 *
 * @ingroup Memory
 */
void os_mem_aligned_free(void *p_block);

/**
 * os_mem.h
 *
 * @brief Peek the unused memory size of the specified RAM type.
 *
 * @param[in]   ram_type            RAM type for allocation.
 *                                  - RAM_TYPE_DATA_ON: Data ON RAM type.
 *                                  - RAM_TYPE_BUFFER_ON: BUFFER ON RAM type.
 *
 * @return The unused memory size in btyes.
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t unused_size;
 *
 *     // Peek unused DATA ON memory size.
 *     unused_size = os_mem_peek(RAM_TYPE_DATA_ON);
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup Memory
 */
extern size_t os_mem_peek(RAM_TYPE ram_type);

/**
 * os_mem.h
 *
 * @brief Peek the unused max block memory size of the specified RAM type.
 *
 * @param[in]   ram_type            RAM type for allocation.
 *                                  - RAM_TYPE_DATA_ON: Data ON RAM type.
 *                                  - RAM_TYPE_BUFFER_ON: BUFFER ON RAM type.
 *
 * @return The unused memory size in btyes.
 *
 * <b>Example usage</b>
 * @code{.c}
 * int test(void)
 * {
 *     size_t unused_data_on;
 *     size_t unused_data_off;
 *
 *     // Peek unused DATA ON memory size.
 *     unused_size = os_mem_peek_max_block(RAM_TYPE_DATA_ON);
 *
 *     // Peek unused DATA OFF memory size.
 *     unused_size = os_mem_peek_max_block(RAM_TYPE_DATA_OFF);
 *
 *     return 0;
 * }
 * @endcode
 *
 * @ingroup Memory
 */
size_t os_mem_peek_max_free_block(RAM_TYPE ram_type);

/**
 * os_mem.h
 *
 * @brief Check and report heap usage for debugging.
 *
 *
 *
 * @ingroup Memory
 */
void os_mem_check_heap_usage(void);


#ifdef __cplusplus
}
#endif

/** @} */ /* End of group Memory */
#endif /* _OS_MEM_H_ */
