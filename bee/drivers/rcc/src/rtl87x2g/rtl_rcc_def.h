/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_rcc_def.h
* \brief    RCC related definitions for RTL8762G
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
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
#define RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS  (1)
#define RCC_SUPPORT_CLOCKGATECMD_API                   (0)

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
 * \defgroup    APB_Peripheral_Clock APB Peripheral Clock
 * \{
 * \ingroup     RCC_Exported_Constants
 */
#define APBPeriph_SPIC0_CLOCK               ((uint32_t)(1 << 30))

#define APBPeriph_SPIC1_CLOCK               ((uint32_t)(1 << 30))

#define APBPeriph_SPIC2_CLOCK               ((uint32_t)(1 << 30))

#define APBPeriph_GDMA_CLOCK                ((uint32_t)(1 << 1))

#define APBPeriph_SPI0_SLAVE_CLOCK          ((uint32_t)(1 << 17))
#define APBPeriph_SPI1_CLOCK                ((uint32_t)(1 << 9))
#define APBPeriph_SPI0_CLOCK                ((uint32_t)(1 << 1))

#define APBPeriph_I2C3_CLOCK                ((uint32_t)(1 << 25))
#define APBPeriph_I2C2_CLOCK                ((uint32_t)(1 << 17))
#define APBPeriph_I2C1_CLOCK                ((uint32_t)(1 << 9))
#define APBPeriph_I2C0_CLOCK                ((uint32_t)(1 << 1))

#define APBPeriph_UART3_CLOCK               ((uint32_t)(1 << 26))
#define APBPeriph_UART2_CLOCK               ((uint32_t)(1 << 18))
#define APBPeriph_UART1_CLOCK               ((uint32_t)(1 << 10))
#define APBPeriph_UART0_CLOCK               ((uint32_t)(1 << 2))

#define APBPeriph_ACCXTAL_CLOCK             ((uint32_t)(1 << 31))
#define APBPeriph_PDCK_CLOCK                ((uint32_t)(1 << 29))
#define APBPeriph_ZBMAC_CLOCK               ((uint32_t)(1 << 25))
#define APBPeriph_BTPHY_CLOCK               ((uint32_t)(1 << 23))
#define APBPeriph_BTMAC_CLOCK               ((uint32_t)(1 << 21))
#define APBPeriph_SEGCOM_CLOCK              ((uint32_t)(1 << 19))
#define APBPeriph_SPI3W_CLOCK               ((uint32_t)(1 << 15))
#define APBPeriph_ETH_CLOCK                 ((uint32_t)(1 << 13))
#define APBPeriph_PPE_CLOCK                 ((uint32_t)(1 << 11))
#define APBPeriph_KEYSCAN_CLOCK             ((uint32_t)(1 << 7))
#define APBPeriph_HRADC_CLOCK               ((uint32_t)(1 << 3))
#define APBPeriph_ADC_CLOCK                 ((uint32_t)(1 << 1))

#define APBPeriph_CAN_CLOCK                 ((uint32_t)(1 << 24))
#define APBPeriph_IR_CLOCK                  ((uint32_t)(1 << 19))
#define APBPeriph_ISO7816_CLOCK             ((uint32_t)(1 << 9))
#define APBPeriph_GPIOB_CLOCK               ((uint32_t)(1 << 5))
#define APBPeriph_GPIOA_CLOCK               ((uint32_t)(1 << 1))

#define APBPeriph_DISP_CLOCK                ((uint32_t)(1 << 23))
#define APBPeriph_IDU_CLOCK                 ((uint32_t)(1 << 7))

#define APBPeriph_TIMER_CLOCK               ((uint32_t)(1 << 31))

#define APBPeriph_ENHTIMER_CLOCK            ((uint32_t)(1 << 31))
#define APBPeriph_ENHTIMER_PWM1_CLOCK       ((uint32_t)(1 << 29))
#define APBPeriph_ENHTIMER_PWM0_CLOCK       ((uint32_t)(1 << 13))

#define APBPeriph_ENHTIMER_PWM3_CLOCK       ((uint32_t)(1 << 29))
#define APBPeriph_ENHTIMER_PWM2_CLOCK       ((uint32_t)(1 << 13))

#define APBPeriph_SDHC_CLOCK                ((uint32_t)(1 << 0))

#define APBPeriph_UART5_CLOCK               ((uint32_t)(1 << 10))  // new 20220731
#define APBPeriph_UART4_CLOCK               ((uint32_t)(1 << 2)) // new 20220731

#define APBPeriph_CODEC_CLOCK               ((uint32_t)(1 << 9))//new vcore3 221223
#define APBPeriph_I2S1_CLOCK                ((uint32_t)(1 << 3))
#define APBPeriph_I2S0_CLOCK                ((uint32_t)(1 << 1))

#define IS_APB_PERIPH_CLOCK(CLOCK) (((CLOCK) == APBPeriph_GDMA_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI1_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI0_SLAVE_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2C2_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2C1_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2C0_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI0_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ADC_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART5_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART4_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART3_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART2_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART1_CLOCK) \
                                    || ((CLOCK) == APBPeriph_UART0_CLOCK) \
                                    || ((CLOCK) == APBPeriph_TIMERB_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ENHTIMER_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ENHTIMER_PWM1_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ENHTIMER_PWM0_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ENHTIMER_PWM3_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ENHTIMER_PWM2_CLOCK) \
                                    || ((CLOCK) == APBPeriph_GPIOB_CLOCK) \
                                    || ((CLOCK) == APBPeriph_GPIOA_CLOCK) \
                                    || ((CLOCK) == APBPeriph_KEYSCAN_CLOCK) \
                                    || ((CLOCK) == APBPeriph_QDEC_CLOCK) \
                                    || ((CLOCK) == APBPeriph_IR_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2C3_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ISO7816_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI2_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI3_CLOCK) \
                                    || ((CLOCK) == APBPeriph_TIMER_CLOCK) \
                                    || ((CLOCK) == APBPeriph_CODEC_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2S0_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2S1_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2S2_CLOCK) \
                                    || ((CLOCK) == APBPeriph_I2S3_CLOCK) \
                                    || ((CLOCK) == APBPeriph_ACCXTAL_CLOCK)\
                                    || ((CLOCK) == APBPeriph_ZBMAC_CLOCK) \
                                    || ((CLOCK) == APBPeriph_BTPHY_CLOCK) \
                                    || ((CLOCK) == APBPeriph_BTMAC_CLOCK))

/** End of APB_Peripheral_Clock
  * \}
  */

/**
 * \defgroup    APB_Peripheral_Func APB Peripheral Func
 * \{
 * \ingroup     RCC_Exported_Constants
 */
#define APBPeriph_SPIC0                 ((uint32_t)(0x800))
#define APBPeriph_SPIC1                 ((uint32_t)(0x801))
#define APBPeriph_SPIC2                 ((uint32_t)(0x802))


#define APBPeriph_GDMA                  ((uint32_t)(0x3))

#define APBPeriph_SPI0_SLAVE            ((uint32_t)(0x4))
#define APBPeriph_SPI1                  ((uint32_t)(0x4))
#define APBPeriph_SPI0                  ((uint32_t)(0x4))

#define APBPeriph_I2C3                  ((uint32_t)(0x5))
#define APBPeriph_I2C2                  ((uint32_t)(0x5))
#define APBPeriph_I2C1                  ((uint32_t)(0x5))
#define APBPeriph_I2C0                  ((uint32_t)(0x5))


#define APBPeriph_UART3                 ((uint32_t)(0x6))
#define APBPeriph_UART2                 ((uint32_t)(0x6))
#define APBPeriph_UART1                 ((uint32_t)(0x6))
#define APBPeriph_UART0                 ((uint32_t)(0x6))


#define APBPeriph_ACCXTAL               ((uint32_t)(0x7))
#define APBPeriph_PDCK                  ((uint32_t)(0x7))
#define APBPeriph_ZBMAC                 ((uint32_t)(0x7))
#define APBPeriph_BTPHY                 ((uint32_t)(0x7))
#define APBPeriph_BTMAC                 ((uint32_t)(0x7))
#define APBPeriph_SEGCOM                ((uint32_t)(0x7))
#define APBPeriph_SPI3W                 ((uint32_t)(0x7))
#define APBPeriph_ETH                   ((uint32_t)(0x7))
#define APBPeriph_PPE                   ((uint32_t)(0x7))
#define APBPeriph_KEYSCAN               ((uint32_t)(0x7))
#define APBPeriph_HRADC                 ((uint32_t)(0x7))
#define APBPeriph_ADC                   ((uint32_t)(0x7))

#define APBPeriph_CAN                   ((uint32_t)(0x808))
#define APBPeriph_IR                    ((uint32_t)(0x808))
#define APBPeriph_ISO7816               ((uint32_t)(0x808))
#define APBPeriph_GPIOB                 ((uint32_t)(0x8))
#define APBPeriph_GPIOA                 ((uint32_t)(0x8))

#define APBPeriph_DISP                  ((uint32_t)(0x809))
#define APBPeriph_IDU                  ((uint32_t)(0x809))

#define APBPeriph_TIMER                 ((uint32_t)(0xA))

#define APBPeriph_ENHTIMER              ((uint32_t)(0x11))
#define APBPeriph_ENHTIMER_PWM1         ((uint32_t)(0x11))
#define APBPeriph_ENHTIMER_PWM0         ((uint32_t)(0x11))
#define APBPeriph_ENHTIMER_PWM3         ((uint32_t)(0x12))
#define APBPeriph_ENHTIMER_PWM2         ((uint32_t)(0x12))

#define APBPeriph_SDHC                  ((uint32_t)(0x81D))

#define APBPeriph_UART5                 ((uint32_t)(0x23))// 0x8C new 20220731
#define APBPeriph_UART4                 ((uint32_t)(0x23))// 0x8C new 20220731 

#define APBPeriph_CODEC                 ((uint32_t)(0x100))
#define APBPeriph_I2S1                  ((uint32_t)(0x100))
#define APBPeriph_I2S0                  ((uint32_t)(0x100))

#define IS_APB_PERIPH(PERIPH) (((PERIPH) == APBPeriph_GDMA) \
                               || ((PERIPH) == APBPeriph_SPI1) \
                               || ((PERIPH) == APBPeriph_SPI0_SLAVE) \
                               || ((PERIPH) == APBPeriph_I2C2) \
                               || ((PERIPH) == APBPeriph_I2C1) \
                               || ((PERIPH) == APBPeriph_I2C0) \
                               || ((PERIPH) == APBPeriph_SPI0) \
                               || ((PERIPH) == APBPeriph_ADC) \
                               || ((PERIPH) == APBPeriph_UART5) \
                               || ((PERIPH) == APBPeriph_UART4) \
                               || ((PERIPH) == APBPeriph_UART3) \
                               || ((PERIPH) == APBPeriph_UART2) \
                               || ((PERIPH) == APBPeriph_UART1) \
                               || ((PERIPH) == APBPeriph_UART0) \
                               || ((PERIPH) == APBPeriph_TIMER) \
                               || ((PERIPH) == APBPeriph_ENHTIMER) \
                               || ((PERIPH) == APBPeriph_ENHTIMER_PWM1) \
                               || ((PERIPH) == APBPeriph_ENHTIMER_PWM0) \
                               || ((PERIPH) == APBPeriph_ENHTIMER_PWM3) \
                               || ((PERIPH) == APBPeriph_ENHTIMER_PWM2) \
                               || ((PERIPH) == APBPeriph_GPIOB) \
                               || ((PERIPH) == APBPeriph_GPIOA) \
                               || ((PERIPH) == APBPeriph_SDHC) \
                               || ((PERIPH) == APBPeriph_KEYSCAN) \
                               || ((PERIPH) == APBPeriph_QDEC) \
                               || ((PERIPH) == APBPeriph_IR) \
                               || ((PERIPH) == APBPeriph_I2C3) \
                               || ((PERIPH) == APBPeriph_ISO7816) \
                               || ((PERIPH) == APBPeriph_SPI2) \
                               || ((PERIPH) == APBPeriph_SPI3) \
                               || ((PERIPH) == APBPeriph_CODEC) \
                               || ((PERIPH) == APBPeriph_I2S0) \
                               || ((PERIPH) == APBPeriph_I2S1) \
                               || ((PERIPH) == APBPeriph_ACCXTAL)\
                               || ((PERIPH) == APBPeriph_PDCK)\
                               || ((PERIPH) == APBPeriph_ZBMAC)\
                               || ((PERIPH) == APBPeriph_BTPHY)\
                               || ((PERIPH) == APBPeriph_BTMAC))

/** End of APB_Peripheral_Func
  * \}
  */

/*============================================================================*
 *                          RCC TYPE/API Wrappers
 *============================================================================*/
/** \defgroup RCC        RCC
  * \brief
  * \{
  */

/** \defgroup RCC_Exported_Constants RCC Exported Constants
  * \brief
  * \{
  */

/**
 * \brief       To be compatible with the previous driver.
 * \defgroup    RCC_Constant_Wrapper RCC Constant Wrapper
 * \{
 * \ingroup     RCC_Exported_Constants
 */
#define APBPeriph_CAN0                APBPeriph_CAN
#define APBPeriph_CAN0_CLOCK          APBPeriph_CAN_CLOCK

/** End of RCC_Constant_Wrapper
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
