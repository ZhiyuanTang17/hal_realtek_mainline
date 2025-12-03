/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLASH_NOR_DEVICE_H
#define _FLASH_NOR_DEVICE_H

#include "fmc_platform.h"
#include <stdint.h>
#include <stdbool.h>

/** @defgroup NOR_FLASH  Nor Flash
  * @brief
  * @{
  */

/****************************************************************************************
 * Nor Flash Enumeration
 ****************************************************************************************/
/** @defgroup Nor_Flash_Exported_Types  Nor Flash Exported Types
  * @ingroup  FLASH
  * @brief
  * @{
  */

/** @defgroup FLASH_NOR_IOCTL_TYPE  FLASH NOR IOCTL TYPE
  * @ingroup  Nor_Flash_Exported_Types
  * @brief
  * @{
  */
typedef enum _FLASH_NOR_IOCTL_TYPE
{
    FLASH_NOR_GET_BASE                          = 0x0000,
    FLASH_NOR_GET_ADDR_BASE,
    FLASH_NOR_GET_RDID,
    FLASH_NOR_GET_SIZE,
    FLASH_NOR_GET_BP,
    FLASH_NOR_GET_BP_TOP_BOTTOM,
    FLASH_NOR_GET_WAIT_BUSY_CTR,
    FLASH_NOR_GET_BIT_MODE,

    FLASH_NOR_SET_BASE                          = 0x1000,
    FLASH_NOR_SET_BP,
    FLASH_NOR_SET_BP_TOP_BOTTOM,
    FLASH_NOR_SET_BP_UNLOCK_BY_ADDR,
    FLASH_NOR_SET_WAIT_BUSY_CTR,
    FLASH_NOR_SET_SPIC_BAUD,
    FLASH_NOR_SET_LOG_BITMAP,

    FLASH_NOR_EXEC_BASE                         = 0x2000,
    FLASH_NOR_EXEC_FLASH_INIT,
    FLASH_NOR_EXEC_DP,
    FLASH_NOR_EXEC_FLASH_SW_RESET,
    FLASH_NOR_EXEC_QUERY_INFO_LOADING,
    FLASH_NOR_EXEC_HIGH_SPEED_MODE,
    FLASH_NOR_EXEC_FLASH_CAL,
    FLASH_NOR_EXEC_FLASH_READ,
    FLASH_NOR_EXEC_FLASH_WRITE,
    FLASH_NOR_EXEC_FLASH_ERASE,

    FLASH_NOR_BASE_MASK                         = 0xF000,
} FLASH_NOR_IOCTL_TYPE;
/** End of FLASH_NOR_IOCTL_TYPE
  * @}
  */

/** @defgroup FLASH_LAYOUT_NAME  FLASH LAYOUT NAME
  * @ingroup  Nor_Flash_Exported_Types
  * @brief
  * @{
  */
typedef enum
{
    FLASH_OCCD,
    FLASH_BOOT_PATCH0,
    FLASH_BOOT_PATCH1,
    FLASH_OTA_BANK_0,
    FLASH_OTA_BANK_1,
    FLASH_SECURE_APP0,
    FLASH_SECURE_APP1,
    FLASH_SECURE_APP_DATA0,
    FLASH_SECURE_APP_DATA1,
    FLASH_RO_DATA1,
    FLASH_RO_DATA2,
    FLASH_RO_DATA3,
    FLASH_RO_DATA4,
    FLASH_RO_DATA5,
    FLASH_RO_DATA6,
    FLASH_BKP_DATA1,
    FLASH_BKP_DATA2,
    FLASH_OTA_TMP,
    FLASH_FTL,

#ifndef _IS_ASIC_
    FLASH_FAKE_DSP_ROM,
#endif

    FLASH_TOTAL,
} FLASH_LAYOUT_NAME;

/** End of FLASH_LAYOUT_NAME
  * @}
  */

/** End of Nor_Flash_Exported_Types
  * @}
  */

/****************************************************************************************
 * Nor Flash Function Prototype
 ****************************************************************************************/
/** @defgroup Nor_Flash_Exported_Functions  Nor Flash Exported Functions
  * @brief
  * @{
  */

extern uint8_t *flash_nor_ioctl_buf;
extern uint32_t flash_nor_ioctl_buf_len;

/**
 * @brief           dump spic & nor flash info
 * @return          none
 */
void flash_nor_dump_main_info(void);

/**
 * @brief           get nor flash layout member start address
 * @param name      specify address of nor flash layout member
 * @return          specific address of nor flash layout member
 */
uint32_t flash_nor_get_bank_addr(FLASH_LAYOUT_NAME name);

/**
 * @brief           get nor flash layout member size
 * @param name      specify size of nor flash layout member
 * @return          specific size of nor flash layout member
 */
uint32_t flash_nor_get_bank_size(FLASH_LAYOUT_NAME name);

/**
 * @brief           set specific nor flash commands and query info
 * @param idx       specific nor flash
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_set_all_info(FLASH_NOR_IDX_TYPE idx);

/**
 * @brief           task-safe of @ref flash_nor_read
 * @param addr      the ram address mapping of nor flash going to be read
 * @param data      data buffer to be read into
 * @param len       read data length
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_read_locked(uint32_t addr, uint8_t *data, uint32_t len);

/**
 * @brief           task-safe of @ref flash_nor_write
 * @param addr      the ram address mapping of nor flash going to be written
 * @param data      data buffer to be write into
 * @param len       write data length
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_write_locked(uint32_t addr, uint8_t *data, uint32_t len);

/**
 * @brief           task-safe of @ref flash_nor_erase
 * @param addr      the ram address mapping of nor flash going to be erased
 * @param mode      erase mode defined as @ref FLASH_NOR_ERASE_MODE
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_erase_locked(uint32_t addr, FLASH_NOR_ERASE_MODE mode);

/**
 * @brief           task-safe nor flash auto dma read
 * @param src       the ram address mapping of nor flash going to be read from
 * @param dst       the ram address going to be written to
 * @param len       dma data length
 * @param cb        call back function which is to be executed when dma finishing
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_auto_dma_read_locked(uint32_t src, uint32_t dst, uint32_t len,
                                                         FLASH_NOR_ASYNC_CB cb);

/**
 * @brief           task-safe nor flash auto dma read with sequential transaction enabled
 * @param src       the ram address mapping of nor flash going to be read from
 * @param dst       the ram address going to be written to
 * @param len       dma data length
 * @param cb        call back function which is to be executed when dma finishing
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_auto_seq_trans_dma_read_locked(uint32_t src, uint32_t dst,
                                                                   uint32_t len, FLASH_NOR_ASYNC_CB cb);

/**
 * @brief           nor flash try high speed mode with bit mode configuration
 * @param idx       specific nor flash
 * @param bit_mode  nor flash bit mode
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_try_high_speed_mode(FLASH_NOR_IDX_TYPE idx,
                                                        FLASH_NOR_BIT_MODE bit_mode);

/**
 * @brief           nor flash check busy status
 * @param idx       specific nor flash
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_wait_busy(FLASH_NOR_IDX_TYPE idx);

/**
 * @brief           nor flash IO control entry
 * @param cmd       @ref FLASH_NOR_IOCTL_TYPE cmd
 * @param idx       specific nor flash
 * @param p1        parameter 1 based on different @ref FLASH_NOR_IOCTL_TYPE cmd
 * @param p2        parameter 2 based on different @ref FLASH_NOR_IOCTL_TYPE cmd
 * @param p3        parameter 3 based on different @ref FLASH_NOR_IOCTL_TYPE cmd
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
extern FLASH_NOR_RET_TYPE flash_nor_ioctl(uint16_t cmd, uint16_t idx, uint32_t p1, uint32_t p2,
                                          uint32_t p3);

/**
 * @brief           get flash exist level
 * @param idx       specific nor flash
 * @return          @ref FLASH_NOR_EXIST_LV result
 */
FLASH_NOR_EXIST_LV flash_nor_get_exist_nsc(FLASH_NOR_IDX_TYPE idx);

/**
 * @brief              set top/bottom of block protect with lock
 * @param idx          specific nor flash
 * @param from_bottom  true if from bottom
 * @return             @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_set_tb_bit_locked(FLASH_NOR_IDX_TYPE idx, bool from_bottom);

/**
 * @brief           set block protect level with lock
 * @param idx       specific nor flash
 * @param bp_lv     nor flash BP level
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_set_bp_lv_locked(FLASH_NOR_IDX_TYPE idx, uint8_t bp_lv);

/**
 * @brief           get block protect level with lock
 * @param idx       specific nor flash
 * @param bp_lv     nor flash BP level
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_get_bp_lv_locked(FLASH_NOR_IDX_TYPE idx, uint8_t *bp_lv);

/**
 * @brief           set sequential transfer function
 * @param idx       specific nor flash
 * @param enable    true if enable
 * @return          @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_set_seq_trans_enable(FLASH_NOR_IDX_TYPE idx, bool enable);

/**
 * @brief                 set flash address mode for flash >= 32M byte
 * @param idx             specific nor flash
 * @param is_4_byte_mode  true if set to 4 byte address mode
 * @return                @ref FLASH_NOR_RET_TYPE result
 */
FLASH_NOR_RET_TYPE flash_nor_set_addr_mode(FLASH_NOR_IDX_TYPE idx, bool is_4_byte_mode);

/**
 * @brief           get flash ID
 * @param idx       specific nor flash
 * @return          return flash ID
 */
uint32_t flash_nor_get_id(FLASH_NOR_IDX_TYPE idx);
/** End of Nor_Flash_Exported_Functions
  * @}
  */

/** End of NOR_FLASH
  * @}
  */
#endif
