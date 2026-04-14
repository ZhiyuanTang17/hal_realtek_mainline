/**
  ******************************************************************************
  * @file    image_check.h
  * @author
  * @version V1.0
  * @date    2024-03
  * @brief
  ******************************************************************************
  * Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _IMAGE_CHECK_H_
#define _IMAGE_CHECK_H_
#include <stdbool.h>
#include <stdint.h>
#include "image_info.h"


/*============================================================================*
  *                                   Constants
  *============================================================================*/


/*============================================================================*
  *                                   Types
  *============================================================================*/
typedef enum
{
    IMG_CHECK_PASS,
    IMG_CHECK_ERR_HEADER_ADDR,
    IMG_CHECK_ERR_NOT_READY,
    IMG_CHECK_ERR_ROM_UUID,
    IMG_CHECK_ERR_MAGIC_PATTERN,
    IMG_CHECK_ERR_SIZE,
    IMG_CHECK_ERR_ID,
    IMG_CHECK_ERR_ENTRY_RETURN,
    IMG_CHECK_ERR_VERIFY,
    IMG_CHECK_ERR_EXE_BASE,
    IMG_CHECK_ERR_ID_MISMATCH,
    IMG_CHECK_ERR_MAX,
} IMG_CHECK_ERR_TYPE;

typedef struct _ROM_HEADER_FORMAT
{
    uint8_t uuid[UUID_SIZE];
    void *init_ptr;
    void *entry_ptr;
} T_ROM_HEADER_FORMAT;

/*************************************************************************************************
*                          functions
*************************************************************************************************/
/**
 * @brief check specified signature image start address
 * @param header image header info of the given image.
 * @param signature signature to specify which image
 * @return image address
*/

extern bool (*image_integrity_check)(uint32_t img_addr, IMG_ID img_id);

uint32_t check_image_header(T_IMG_HEADER_FORMAT *header, uint16_t image_id);

IMG_CHECK_ERR_TYPE check_header_valid(uint32_t header_addr, IMG_ID image_id);

bool check_image_crc16(T_IMG_HEADER_FORMAT *p_header);

bool check_image_sha256(T_IMG_HEADER_FORMAT *p_header);

IMG_CHECK_ERR_TYPE image_entry(uint16_t image_id, uint32_t image_addr);

IMG_CHECK_ERR_TYPE image_entry_check(T_ROM_HEADER_FORMAT *rom_header,
                                     T_ROM_HEADER_FORMAT *patch_header);

IMG_CHECK_ERR_TYPE stack_patch_check_entry(void);


#endif // _IMAGE_CHECK_H_
