/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
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
 * \defgroup OS_MEM Memory Management
 *
 * \brief   Allocate, free, and peek memory functions.
 * \details The Memory Management function group allows to allocate, free, and peek heap
 *          memory in the system.\n
 *
 */


extern void *(*os_mem_alloc_intern)(RAM_TYPE ram_type, size_t size,
                                    const char *p_func, uint32_t file_line);

extern void *(*os_mem_zalloc_intern)(RAM_TYPE ram_type, size_t size,
                                     const char *p_func, uint32_t file_line);
extern void *(*os_mem_aligned_alloc_intern)(RAM_TYPE ram_type,
                                            size_t size, uint8_t alignment,
                                            const char *p_func, uint32_t file_line);

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup OS_MEM_Exported_Functions OS Memory Exported Functions
  * \ingroup  OS_MEM
  * @{
  */

/**
 * os_mem.h
 *
 * \brief    Allocate a memory block with required size.
 *
 * \param   ram_type            RAM type for allocation.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \param   size     Required memory size.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
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
 * \endcode
 *
 */
#define os_mem_alloc(ram_type, size)    \
    os_mem_alloc_intern(ram_type, size, __func__, __LINE__)

/**
 * os_mem.h
 *
 * \brief    Allocate a memory block with required size in DATA RAM type.
 *
 * \param   size     Required memory size.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_alloc2(mem_size);
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
 * \endcode
 *
 */
#define os_mem_alloc2(size)    \
    os_mem_alloc_intern(RAM_TYPE_DATA_ON, size, __func__, __LINE__)

/**
 * os_mem.h
 *
 * \brief    Allocate and clear a memory block with required size.
 *
 * \param   ram_type            RAM type for allocation.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \param   size     Required memory size.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
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
 * \endcode
 *
 */
#define os_mem_zalloc(ram_type, size)   \
    os_mem_zalloc_intern(ram_type, size, __func__, __LINE__)

/**
 * os_mem.h
 *
 * \brief    Allocate and clear a memory block with required size in DATA RAM type.
 *
 * \param   size     Required memory size.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_zalloc2(mem_size);
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
 * \endcode
 *
 */
#define os_mem_zalloc2(size)   \
    os_mem_zalloc_intern(RAM_TYPE_DATA_ON, size, __func__, __LINE__)

/**
 * os_mem.h
 *
 * \brief    Allocate an aligned memory block with required size.
 *
 * \param   ram_type            RAM type for allocation.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \param   size        Required memory size.
 *
 * \param   alignment   memory alignment in 2^N bytes. If alignment is 0, use
 *                          system default memory alignment. The aligned memory block
 *                          must use os_mem_aligned_free() API function to free.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     uint8_t mem_alignment = 16;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_aligned_alloc(RAM_TYPE_DATA_ON, mem_size, mem_alignment);
 *     if (p_mem != NULL)
 *     {
 *         // Aligned memory allocation successed, and free it.
 *         os_mem_aligned_free(p_mem);
 *     }
 *     else
 *     {
 *         // Aligned memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_mem_aligned_alloc(ram_type, size, alignment) \
    os_mem_aligned_alloc_intern(ram_type, size, alignment, __func__, __LINE__)

/**
 * os_mem.h
 *
 * \brief    Free a memory block that had been allocated.
 *
 * \param   p_block     The address of memory block being freed.
 *
 * \return     None.
 *
 * <b>Example usage</b>
 * \code{.c}
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
 * \endcode
 *
 */
extern void (*os_mem_free)(void *p_block);

/**
 * os_mem.h
 *
 * \brief    Free a memory block that had been aligned allocated.
 *
 * \param    p_block  The address of memory block being freed.
 *
 * \return     The address of the allocated memory block. If the address is NULL, the
 *             memory allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     size_t mem_size = 0x1000;
 *     uint8_t mem_alignment = 16;
 *     void *p_mem = NULL;
 *
 *     p_mem = os_mem_aligned_alloc(RAM_TYPE_DATA_ON, mem_size, mem_alignment);
 *     if (p_mem != NULL)
 *     {
 *         // Aligned memory allocation successed, and free it.
 *         os_mem_aligned_free(p_mem);
 *     }
 *     else
 *     {
 *         // Aligned memory allocation failed.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * \endcode
 *
 */
extern void (*os_mem_aligned_free)(void *p_block);

/**
 * os_mem.h
 *
 * \brief    Peek the unused memory size of the specified RAM type.
 *
 * \param   ram_type            RAM type for allocation.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \return     The unused memory size in btyes.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     size_t unused_data_on;
 *     size_t unused_data_off;
 *
 *     // Peek unused DATA ON memory size.
 *     unused_size = os_mem_peek(RAM_TYPE_DATA_ON);
 *
 *     // Peek unused DATA OFF memory size.
 *     unused_size = os_mem_peek(RAM_TYPE_DATA_OFF);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
extern size_t (*os_mem_peek)(RAM_TYPE ram_type);

#define mem_peek()  os_mem_peek(RAM_TYPE_DATA_ON)

/**
 * os_mem.h
 *
 * \brief    Peek the unused max block memory size of the specified RAM type.
 *
 * \param   ram_type            RAM type for allocation.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \return     The unused memory size in btyes.
 *
 * <b>Example usage</b>
 * \code{.c}
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
 * \endcode
 *
 */
extern size_t (*os_mem_peek_max_free_block)(RAM_TYPE ram_type);


extern void (*os_mem_peek_printf)(void);
/**
 * os_mem.h
 *
 * \brief    Peek and print the unused memory size of all RAM type.
 *
 * \param   void.
 *
 * \return     void.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     // Peek and print all unused memory size.
 *     os_mem_dump();
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_mem_dump()   os_mem_peek_printf()

/** End of group OS_MEM_Exported_Functions
  * @}
  */

/** End of OS_MEM
  * @}
  */

extern void (*os_mem_check_heap_usage)(void);

#ifdef __cplusplus
}
#endif

#endif /* _OS_MEM_H_ */
