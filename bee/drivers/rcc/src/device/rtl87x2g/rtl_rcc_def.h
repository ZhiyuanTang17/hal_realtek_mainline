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
#define RCC_SUPPORT_PERIPHCLOCKCONFIG_API_MORE_PARAMS  (1) //!< The chip supports peripheral clock config.
#define RCC_SUPPORT_CLOCKGATECMD_API                   (0) //!< The function is not supported.

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
#define APBPeriph_SPIC0_CLOCK               ((uint32_t)(1 << 30))  //!< SPIC0 clock

#define APBPeriph_SPIC1_CLOCK               ((uint32_t)(1 << 30))  //!< SPIC1 clock

#define APBPeriph_SPIC2_CLOCK               ((uint32_t)(1 << 30))  //!< SPIC2 clock

#define APBPeriph_GDMA_CLOCK                ((uint32_t)(1 << 1))   //!< GDMA clock

#define APBPeriph_SPI0_SLAVE_CLOCK          ((uint32_t)(1 << 17))  //!< SPI0 slave clock
#define APBPeriph_SPI1_CLOCK                ((uint32_t)(1 << 9))   //!< SPI1 clock
#define APBPeriph_SPI0_CLOCK                ((uint32_t)(1 << 1))   //!< SPI0 clock

#define APBPeriph_I2C3_CLOCK                ((uint32_t)(1 << 25))  //!< I2C3 clock
#define APBPeriph_I2C2_CLOCK                ((uint32_t)(1 << 17))  //!< I2C2 clock
#define APBPeriph_I2C1_CLOCK                ((uint32_t)(1 << 9))   //!< I2C1 clock
#define APBPeriph_I2C0_CLOCK                ((uint32_t)(1 << 1))   //!< I2C0 clock

#define APBPeriph_UART3_CLOCK               ((uint32_t)(1 << 26))  //!< UART3 clock
#define APBPeriph_UART2_CLOCK               ((uint32_t)(1 << 18))  //!< UART2 clock
#define APBPeriph_UART1_CLOCK               ((uint32_t)(1 << 10))  //!< UART1 clock
#define APBPeriph_UART0_CLOCK               ((uint32_t)(1 << 2))   //!< UART0 clock

#define APBPeriph_ACCXTAL_CLOCK             ((uint32_t)(1 << 31))  //!< ACCXTAL clock
#define APBPeriph_PDCK_CLOCK                ((uint32_t)(1 << 29))  //!< PDCK clock
#define APBPeriph_ZBMAC_CLOCK               ((uint32_t)(1 << 25))  //!< ZBMAC clock
#define APBPeriph_BTPHY_CLOCK               ((uint32_t)(1 << 23))  //!< BTPHY clock
#define APBPeriph_BTMAC_CLOCK               ((uint32_t)(1 << 21))  //!< BTMAC clock
#define APBPeriph_SEGCOM_CLOCK              ((uint32_t)(1 << 19))  //!< SEGCOM clock
#define APBPeriph_SPI3W_CLOCK               ((uint32_t)(1 << 15))  //!< SPI3W clock
#define APBPeriph_ETH_CLOCK                 ((uint32_t)(1 << 13))  //!< ETH clock
#define APBPeriph_PPE_CLOCK                 ((uint32_t)(1 << 11))  //!< PPE clock
#define APBPeriph_KEYSCAN_CLOCK             ((uint32_t)(1 << 7))   //!< KEYSCAN clock
#define APBPeriph_HRADC_CLOCK               ((uint32_t)(1 << 3))   //!< HRADC clock
#define APBPeriph_ADC_CLOCK                 ((uint32_t)(1 << 1))   //!< ADC clock

#define APBPeriph_CAN_CLOCK                 ((uint32_t)(1 << 24))  //!< CAN clock
#define APBPeriph_IR_CLOCK                  ((uint32_t)(1 << 19))  //!< IR clock
#define APBPeriph_ISO7816_CLOCK             ((uint32_t)(1 << 9))   //!< ISO7816 clock
#define APBPeriph_GPIOB_CLOCK               ((uint32_t)(1 << 5))   //!< GPIOB clock
#define APBPeriph_GPIOA_CLOCK               ((uint32_t)(1 << 1))   //!< GPIOA clock

#define APBPeriph_DISP_CLOCK                ((uint32_t)(1 << 23))  //!< DISP clock
#define APBPeriph_IDU_CLOCK                 ((uint32_t)(1 << 7))   //!< IDU clock

#define APBPeriph_TIMER_CLOCK               ((uint32_t)(1 << 31))  //!< TIMER clock

#define APBPeriph_ENHTIMER_CLOCK            ((uint32_t)(1 << 31))  //!< ENHTIMER clock
#define APBPeriph_ENHTIMER_PWM1_CLOCK       ((uint32_t)(1 << 29))  //!< ENHTIMER_PWM1 clock
#define APBPeriph_ENHTIMER_PWM0_CLOCK       ((uint32_t)(1 << 13))  //!< ENHTIMER_PWM0 clock

#define APBPeriph_ENHTIMER_PWM3_CLOCK       ((uint32_t)(1 << 29))  //!< ENHTIMER_PWM3 clock
#define APBPeriph_ENHTIMER_PWM2_CLOCK       ((uint32_t)(1 << 13))  //!< ENHTIMER_PWM2 clock

#define APBPeriph_SDHC_CLOCK                ((uint32_t)(1 << 0))   //!< SDHC clock

#define APBPeriph_UART5_CLOCK               ((uint32_t)(1 << 10))  //!< UART5 clock
#define APBPeriph_UART4_CLOCK               ((uint32_t)(1 << 2))   //!< UART4 clock

#define APBPeriph_CODEC_CLOCK               ((uint32_t)(1 << 9))   //!< CODEC clock
#define APBPeriph_I2S1_CLOCK                ((uint32_t)(1 << 3))   //!< I2S1 clock
#define APBPeriph_I2S0_CLOCK                ((uint32_t)(1 << 1))   //!< I2S0 clock

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
                                    || ((CLOCK) == APBPeriph_BTMAC_CLOCK)) //!< Check if the input parameter is valid.

/** End of APB_Peripheral_Clock
  * \}
  */

/**
 * \defgroup    APB_Peripheral_Func APB Peripheral Func
 * \{
 * \ingroup     RCC_Exported_Constants
 */
#define APBPeriph_SPIC0                 ((uint32_t)(0x800))   //!< SPIC0 function
#define APBPeriph_SPIC1                 ((uint32_t)(0x801))   //!< SPIC1 function
#define APBPeriph_SPIC2                 ((uint32_t)(0x802))   //!< SPIC2 function


#define APBPeriph_GDMA                  ((uint32_t)(0x3))     //!< GDMA function

#define APBPeriph_SPI0_SLAVE            ((uint32_t)(0x4))     //!< SPI0 slave function
#define APBPeriph_SPI1                  ((uint32_t)(0x4))     //!< SPI1 function
#define APBPeriph_SPI0                  ((uint32_t)(0x4))     //!< SPI0 function

#define APBPeriph_I2C3                  ((uint32_t)(0x5))     //!< I2C3 function
#define APBPeriph_I2C2                  ((uint32_t)(0x5))     //!< I2C2 function
#define APBPeriph_I2C1                  ((uint32_t)(0x5))     //!< I2C1 function
#define APBPeriph_I2C0                  ((uint32_t)(0x5))     //!< I2C0 function


#define APBPeriph_UART3                 ((uint32_t)(0x6))     //!< UART3 function
#define APBPeriph_UART2                 ((uint32_t)(0x6))     //!< UART2 function
#define APBPeriph_UART1                 ((uint32_t)(0x6))     //!< UART1 function
#define APBPeriph_UART0                 ((uint32_t)(0x6))     //!< UART0 function


#define APBPeriph_ACCXTAL               ((uint32_t)(0x7))     //!< ACCXTAL function
#define APBPeriph_PDCK                  ((uint32_t)(0x7))     //!< PDCK function
#define APBPeriph_ZBMAC                 ((uint32_t)(0x7))     //!< ZBMAC function
#define APBPeriph_BTPHY                 ((uint32_t)(0x7))     //!< BTPHY function
#define APBPeriph_BTMAC                 ((uint32_t)(0x7))     //!< BTMAC function
#define APBPeriph_SEGCOM                ((uint32_t)(0x7))     //!< SEGCOM function
#define APBPeriph_SPI3W                 ((uint32_t)(0x7))     //!< SPI3W function
#define APBPeriph_ETH                   ((uint32_t)(0x7))     //!< ETH function
#define APBPeriph_PPE                   ((uint32_t)(0x7))     //!< PPE function
#define APBPeriph_KEYSCAN               ((uint32_t)(0x7))     //!< KEYSCAN function
#define APBPeriph_HRADC                 ((uint32_t)(0x7))     //!< HRADC function
#define APBPeriph_ADC                   ((uint32_t)(0x7))     //!< ADC function

#define APBPeriph_CAN                   ((uint32_t)(0x808))   //!< CAN function
#define APBPeriph_IR                    ((uint32_t)(0x808))   //!< IR function
#define APBPeriph_ISO7816               ((uint32_t)(0x808))   //!< ISO7816 function
#define APBPeriph_GPIOB                 ((uint32_t)(0x8))     //!< GPIOB function
#define APBPeriph_GPIOA                 ((uint32_t)(0x8))     //!< GPIOA function

#define APBPeriph_DISP                  ((uint32_t)(0x809))   //!< DISP function
#define APBPeriph_IDU                  ((uint32_t)(0x809))    //!< IDU function

#define APBPeriph_TIMER                 ((uint32_t)(0xA))     //!< TIMER function

#define APBPeriph_ENHTIMER              ((uint32_t)(0x11))    //!< ENHTIMER function
#define APBPeriph_ENHTIMER_PWM1         ((uint32_t)(0x11))    //!< ENHTIMER_PWM1 function
#define APBPeriph_ENHTIMER_PWM0         ((uint32_t)(0x11))    //!< ENHTIMER_PWM0 function
#define APBPeriph_ENHTIMER_PWM3         ((uint32_t)(0x12))    //!< ENHTIMER_PWM3 function
#define APBPeriph_ENHTIMER_PWM2         ((uint32_t)(0x12))    //!< ENHTIMER_PWM2 function

#define APBPeriph_SDHC                  ((uint32_t)(0x81D))   //!< SDHC function

#define APBPeriph_UART5                 ((uint32_t)(0x23))    //!< UART5 function
#define APBPeriph_UART4                 ((uint32_t)(0x23))    //!< UART4 function

#define APBPeriph_CODEC                 ((uint32_t)(0x100))   //!< CODEC function
#define APBPeriph_I2S1                  ((uint32_t)(0x100))   //!< I2S1 function
#define APBPeriph_I2S0                  ((uint32_t)(0x100))   //!< I2S0 function

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
                               || ((PERIPH) == APBPeriph_BTMAC)) //!< Check if the input parameter is valid.

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
#define APBPeriph_CAN0                APBPeriph_CAN         //!< The macro is a wrapper for APBPeriph_CAN.
#define APBPeriph_CAN0_CLOCK          APBPeriph_CAN_CLOCK   //!< The macro is a wrapper for APBPeriph_CAN_CLOCK.

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
