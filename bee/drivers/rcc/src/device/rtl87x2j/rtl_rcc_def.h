/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_RCC_DEF_H
#define RTL_RCC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "pcc_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          RCC Defines
 *============================================================================*/
/** \defgroup RCC         RCC
  * \brief
  * \{
  */

/** \defgroup RCC_Exported_Constants RCC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup RCC_Defines RCC Defines
 * \{
 * \ingroup  RCC_Exported_Constants
 */
#define RCC_SUPPORT_CLOCKGATECMD_API                   (0)
#define RCC_SUPPORT_AUTO_CLOCK                         (1)

/** End of RCC_Defines
  * \}
  */

/** End of RCC_Exported_Constants
  * \}
  */

/** End of RCC
  * \}
  */
/*============================================================================*
 *                         RCC Private Defines
 *============================================================================*/


/*============================================================================*
 *                         RCC Constants
 *============================================================================*/
/** \defgroup RCC         RCC
  * \brief
  * \{
  */

/** \defgroup RCC_Exported_Constants RCC Exported Constants
  * \brief
  * \{
  */


/**
 * \defgroup    RCC_PERIPH_CLOCK RCC PERIPH CLOCK
 * \{
 * \ingroup     RCC_Exported_Constants
 */

/* 32bit Encoding:    VUTSRQPO NMLKJIHG FEDCBA98 76543210
 * Positions of FEN:  FFFFFFFF ffffffff ffffffff ffffffff
 * Note:
 *   F ~ FEN ADDRESS  8 BIT   24 ~ 31
 *   f ~ FEN BIT     24 BIT    0 ~ 23
 */
#define WDT_CLOCK                   ((uint32_t)((0x00 << 24) | (30)))
#define MODEMRFCPI_CLOCK            ((uint32_t)((0x00 << 24) | (27)))
#define DMA_CLOCK                   ((uint32_t)((0x00 << 24) | (26)))
#define SPI0_CLOCK                  ((uint32_t)((0x00 << 24) | (24)))
#define SPI1_CLOCK                  ((uint32_t)((0x00 << 24) | (23)))
#define SPI2_CLOCK                  ((uint32_t)((0x00 << 24) | (22)))
#define I2S_CLOCK                   ((uint32_t)((0x00 << 24) | (21)))
#define TIMER0_CLOCK                ((uint32_t)((0x00 << 24) | (20)))
#define TIMER1_CLOCK                ((uint32_t)((0x00 << 24) | (19)))
#define TIMER2_CLOCK                ((uint32_t)((0x00 << 24) | (18)))
#define USB_CLOCK                   ((uint32_t)((0x00 << 24) | (16)))
#define ADC_CLOCK                   ((uint32_t)((0x00 << 24) | (15)))
#define I2C0_CLOCK                  ((uint32_t)((0x00 << 24) | (14)))
#define I2C1_CLOCK                  ((uint32_t)((0x00 << 24) | (13)))
#define KEYSCAN_CLOCK               ((uint32_t)((0x00 << 24) | (12)))
#define SPI3W_CLOCK                 ((uint32_t)((0x00 << 24) | (11)))
#define CAN_CLOCK                   ((uint32_t)((0x00 << 24) | ( 9)))
#define UART0_CLOCK                 ((uint32_t)((0x00 << 24) | ( 7)))
#define UART1_CLOCK                 ((uint32_t)((0x00 << 24) | ( 6)))
#define UART2_CLOCK                 ((uint32_t)((0x00 << 24) | ( 5)))
#define CODEC_CLOCK                 ((uint32_t)((0x00 << 24) | ( 4)))
#define TMETER_CLOCK                ((uint32_t)((0x00 << 24) | ( 2)))

#define UART3_CLOCK                 ((uint32_t)((0x01 << 24) | (31)))
#define GPIOA_CLOCK                 ((uint32_t)((0x01 << 24) | (30)))
#define GPIOB_CLOCK                 ((uint32_t)((0x01 << 24) | (30)))
#define IR_CLOCK                    ((uint32_t)((0x01 << 24) | (28)))

#define LPPWM_CLOCK                 ((uint32_t)((0x03 << 24) | (31)))
#define LPQDEC_CLOCK                ((uint32_t)((0x04 << 24) | (31)))
#define GRTC_CLOCK                  ((uint32_t)((0x05 << 24) | (31)))
#define BLUEWIZ_CLOCK               ((uint32_t)((0x06 << 24) | (31)))
#define RTC_CLOCK                   ((uint32_t)((0x07 << 24) | (31)))
//#define RAP_CLOCK                   ((uint32_t)((0x08 << 24) | (31)))
#define LPWDT_CLOCK                 ((uint32_t)((0x0B << 24) | (31)))
#define LPC_CLOCK                   ((uint32_t)((0x0E << 24) | (31)))

#define IS_PERIPH_CLOCK(CLOCK)      (((CLOCK) == WDT_CLOCK) || \
                                     ((CLOCK) == MODEMRFCPI_CLOCK) || \
                                     ((CLOCK) == DMA_CLOCK) || \
                                     ((CLOCK) == SPI0_CLOCK) || \
                                     ((CLOCK) == SPI1_CLOCK) || \
                                     ((CLOCK) == SPI2_CLOCK) || \
                                     ((CLOCK) == I2S_CLOCK) || \
                                     ((CLOCK) == TIMER0_CLOCK) || \
                                     ((CLOCK) == TIMER1_CLOCK) || \
                                     ((CLOCK) == TIMER2_CLOCK) || \
                                     ((CLOCK) == USB_CLOCK) || \
                                     ((CLOCK) == ADC_CLOCK) || \
                                     ((CLOCK) == I2C0_CLOCK) || \
                                     ((CLOCK) == I2C1_CLOCK) || \
                                     ((CLOCK) == KEYSCAN_CLOCK) || \
                                     ((CLOCK) == SPI3W_CLOCK) || \
                                     ((CLOCK) == CAN_CLOCK) || \
                                     ((CLOCK) == UART0_CLOCK) || \
                                     ((CLOCK) == UART1_CLOCK) || \
                                     ((CLOCK) == UART2_CLOCK) || \
                                     ((CLOCK) == CODEC_CLOCK) || \
                                     ((CLOCK) == TMETER_CLOCK) || \
                                     ((CLOCK) == UART3_CLOCK) || \
                                     ((CLOCK) == GPIOA_CLOCK) || \
                                     ((CLOCK) == GPIOB_CLOCK) || \
                                     ((CLOCK) == IR_CLOCK) || \
                                     ((CLOCK) == LPPWM_CLOCK) || \
                                     ((CLOCK) == LPQDEC_CLOCK) || \
                                     ((CLOCK) == GRTC_CLOCK) || \
                                     ((CLOCK) == RTC_CLOCK) || \
                                     ((CLOCK) == LPWDT_CLOCK) || \
                                     ((CLOCK) == LPC_CLOCK))

/** End of RCC_PERIPH_CLOCK
  * \}
  */

/** End of RCC_Exported_Constants
  * \}
  */

/** End of RCC
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_RCC_DEF_H */
