/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IO_H
#define IO_H

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN                        0
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN                           1
#endif

#define SYSTEM_ENDIAN                        LITTLE_ENDIAN

#define SWAP32(x) ((uint32_t)(                         \
                                                       (((uint32_t)(x) & (uint32_t)0x000000ff) << 24) |            \
                                                       (((uint32_t)(x) & (uint32_t)0x0000ff00) <<  8) |            \
                                                       (((uint32_t)(x) & (uint32_t)0x00ff0000) >>  8) |            \
                                                       (((uint32_t)(x) & (uint32_t)0xff000000) >> 24)))

#define WAP16(x) ((uint16_t)(                         \
                                                      (((uint16_t)(x) & (uint16_t)0x00ff) <<  8) |            \
                                                      (((uint16_t)(x) & (uint16_t)0xff00) >>  8)))

#if SYSTEM_ENDIAN == LITTLE_ENDIAN
#ifndef rtk_le16_to_cpu
#define rtk_cpu_to_le32(x)      ((uint32_t)(x))
#define rtk_le32_to_cpu(x)      ((uint32_t)(x))
#define rtk_cpu_to_le16(x)      ((uint16_t)(x))
#define rtk_le16_to_cpu(x)      ((uint16_t)(x))
#define rtk_cpu_to_be32(x)      SWAP32((x))
#define rtk_be32_to_cpu(x)      SWAP32((x))
#define rtk_cpu_to_be16(x)      WAP16((x))
#define rtk_be16_to_cpu(x)      WAP16((x))
#endif

#elif SYSTEM_ENDIAN == BIG_ENDIAN
#ifndef rtk_le16_to_cpu
#define rtk_cpu_to_le32(x)      SWAP32((x))
#define rtk_le32_to_cpu(x)      SWAP32((x))
#define rtk_cpu_to_le16(x)      WAP16((x))
#define rtk_le16_to_cpu(x)      WAP16((x))
#define rtk_cpu_to_be32(x)      ((uint32_t)(x))
#define rtk_be32_to_cpu(x)      ((uint32_t)(x))
#define rtk_cpu_to_be16(x)      ((uint16_t)(x))
#define rtk_be16_to_cpu(x)      ((uint16_t)(x))
#endif
#endif

#define HAL_READ32(base, addr)            \
    rtk_le32_to_cpu(*((volatile uint32_t *)(base + addr)))

#define HAL_WRITE32(base, addr, value32)  \
    ((*((volatile uint32_t *)(base + addr))) = rtk_cpu_to_le32(value32))

#define HAL_UPDATE32(addr, mask, value32)  \
    HAL_WRITE32(0, addr, (HAL_READ32(0, addr) & ~(mask)) | ((value32) & (mask)))

#define HAL_READ16(base, addr)            \
    rtk_le16_to_cpu(*((volatile uint16_t *)(base + addr)))

#define HAL_WRITE16(base, addr, value)  \
    ((*((volatile uint16_t *)(base + addr))) = rtk_cpu_to_le16(value))

#define HAL_UPDATE16(addr, mask, value16)  \
    HAL_WRITE16(0, addr, (HAL_READ16(0, addr) & ~(mask)) | ((value16) & (mask)))

#define HAL_READ8(base, addr)            \
    (*((volatile uint8_t *)(base + addr)))

#define HAL_WRITE8(base, addr, value)  \
    ((*((volatile uint8_t *)(base + addr))) = value)

#define HAL_UPDATE8(addr, mask, value8)  \
    HAL_WRITE8(0, addr, (HAL_READ8(0, addr) & ~(mask)) | ((value8) & (mask)))


#endif //#define IO_H 
