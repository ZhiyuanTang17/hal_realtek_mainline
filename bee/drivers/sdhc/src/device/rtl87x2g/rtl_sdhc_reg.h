/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_SDHC_REG_H
#define RTL_SDHC_REG_H

#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         SDHC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t CTRL;                   /*!< 0x00 */
    __IO uint32_t PWREN;                  /*!< 0x04 */
    __IO uint32_t CLKDIV;                 /*!< 0x08 */
    __IO uint32_t CLKSRC;                 /*!< 0x0C */
    __IO uint32_t CLKENA;                 /*!< 0x10 */
    __IO uint32_t TMOUT;                  /*!< 0x14 */
    __IO uint32_t CTYPE;                  /*!< 0x18 */
    __IO uint32_t BLKSIZ;                 /*!< 0x1C */
    __IO uint32_t BYTCNT;                 /*!< 0x20 */
    __IO uint32_t INTMASK;                /*!< 0x24 */
    __IO uint32_t CMDARG;                 /*!< 0x28 */
    __IO uint32_t CMD;                    /*!< 0x2C */
    __I  uint32_t RESP0;                  /*!< 0x30 */
    __I  uint32_t RESP1;                  /*!< 0x34 */
    __I  uint32_t RESP2;                  /*!< 0x38 */
    __I  uint32_t RESP3;                  /*!< 0x3C */
    __I  uint32_t MINTSTS;                /*!< 0x40 */
    __IO uint32_t RINTSTS;                /*!< 0x44 */
    __I  uint32_t STATUS;                 /*!< 0x48 */
    __IO uint32_t FIFOTH;                 /*!< 0x4C */
    __I  uint32_t CDETECT;                /*!< 0x50 */
    __I  uint32_t WRTPRT;                 /*!< 0x54 */
    __IO uint32_t GPIO;                   /*!< 0x58 */
    __I  uint32_t TCBCNT;                 /*!< 0x5C */
    __I  uint32_t TBBCNT;                 /*!< 0x60 */
    __IO uint32_t DEBNCE;                 /*!< 0x64 */
    __IO uint32_t USRID;                  /*!< 0x68 */
    __I  uint32_t VERID;                  /*!< 0x6C */
    __I  uint32_t HCON;                   /*!< 0x70 */
    __IO uint32_t UHS_REG;                /*!< 0x74 */
    __IO uint32_t RST_N;                  /*!< 0x78 */
    __I  uint32_t Reserved0;              /*!< 0x7C */
    __IO uint32_t BMOD;                   /*!< 0x80 */
    __O  uint32_t PLDMND;                 /*!< 0x84 */
    __IO uint32_t DBADDR;                 /*!< 0x88 */
    __IO uint32_t IDSTS;                  /*!< 0x8C */
    __IO uint32_t IDINTEN;                /*!< 0x90 */
    __I  uint32_t DSCADDR;                /*!< 0x94 */
    __I  uint32_t BUFADDR;                /*!< 0x98 */
    __I  uint8_t Reserved1[0x100 - 0x9C]; /*!< 0x9C */
    __IO uint32_t CARDTHRCTL;             /*!< 0x100 */
    __IO uint32_t BACK_END_POWER;         /*!< 0x104 */
    __IO uint32_t UHS_REG_EXT;            /*!< 0x108 */
    __IO uint32_t EMMC_DDR_REG;           /*!< 0x10C */
    __IO uint32_t ENABLE_SHIFT;           /*!< 0x110 */
    __IO uint8_t Reserved2[0x100 - 0x14]; /*!< 0x114 */
    __IO uint32_t DATA;                   /*!< >=0x200 */
} SDHC_TypeDef;

/*============================================================================*
 *                         SDHC Declaration
 *============================================================================*/
#define SDHC0                           ((SDHC_TypeDef *) SDHC_REG_BASE)
#define SDHC1                           ((SDHC_TypeDef *) SDHC_REG_BASE)

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_SDHC_REG_H */

