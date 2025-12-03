/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl876x_rcc.h
* \brief    The header file of the clock control and reset driver.
* \details  This file provides all peripheral clock control firmware functions.
* \author   tifnan_ge
* \date     2024-01-18
* \version  v0.1
* *********************************************************************************************************
*/


#ifndef _RTL876X_RCC_H_
#define _RTL876X_RCC_H_

#ifdef __cplusplus
extern "C" {
#endif


/**
 * \addtogroup  IO          Peripheral Drivers
 * \defgroup    RCC         RCC
 *
 * \brief       Manage the RCC peripheral functions.
 *
 * \ingroup     IO
 */


/*============================================================================*
 *                         Includes
 *============================================================================*/
#include "rtl876x.h"


/*============================================================================*
 *                         Constants
 *============================================================================*/
/**
 * \defgroup    RCC_Exported_Constants RCC Exported Constants
 *
 * \ingroup     RCC
 */

/**
 * \defgroup    RCC_Peripheral_Clock RCC Peripheral Clock
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define APBPeriph_I2S0_CLOCK                ((uint32_t)(((uint32_t)0x01 << 5) | ((uint32_t)0x01 << 8) | ((uint32_t)0x00 << 29)))
#define APBPeriph_I2S1_CLOCK                ((uint32_t)(((uint32_t)0x01 << 6) | ((uint32_t)0x01 << 8) | ((uint32_t)0x00 << 29)))
#define APBPeriph_CODEC_CLOCK               ((uint32_t)(((uint32_t)0x01 << 4) | ((uint32_t)0x00 << 29)))
#define APBPeriph_GPIO_CLOCK                ((uint32_t)(((uint32_t)0x01 << 24) | ((uint32_t)0x01 << 29)))
#define APBPeriph_GDMA_CLOCK                ((uint32_t)(((uint32_t)0x01 << 16) | ((uint32_t)0x01 << 29)))
#define APBPeriph_TIMER_CLOCK               ((uint32_t)(((uint32_t)0x01 << 14) | ((uint32_t)0x01 << 29)))
#define APBPeriph_ENHTIMER_CLOCK            ((uint32_t)(((uint32_t)0x01 << 14) | ((uint32_t)0x01 << 29)))
#define APBPeriph_UART2_CLOCK               ((uint32_t)(((uint32_t)0x01 << 10) | ((uint32_t)0x01 << 29)))
#define APBPeriph_UART0_CLOCK               ((uint32_t)(((uint32_t)0x01 << 12) | ((uint32_t)0x01 << 29)))
#define APBPeriph_FLASH_CLOCK               ((uint32_t)(((uint32_t)0x01 << 8)  | ((uint32_t)0x01 << 29)))
#define APBPeriph_PKE_CLOCK                 ((uint32_t)(((uint32_t)0x01 << 31) | ((uint32_t)0x02 << 29)))
#define APBPeriph_SHA256_CLOCK              ((uint32_t)(((uint32_t)0x01 << 28) | ((uint32_t)0x02 << 29)))
#define APBPeriph_FLASH1_CLOCK              ((uint32_t)(((uint32_t)0x01 << 24) | ((uint32_t)0x02 << 29)))
#define APBPeriph_FLH_SEC_CLOCK             ((uint32_t)(((uint32_t)0x01 << 22) | ((uint32_t)0x02 << 29)))
#define APBPeriph_IR_CLOCK                  ((uint32_t)(((uint32_t)0x01 << 20) | ((uint32_t)0x02 << 29)))
#define APBPeriph_SPI1_CLOCK                ((uint32_t)(((uint32_t)0x01 << 18) | ((uint32_t)0x02 << 29)))
#define APBPeriph_SPI0_CLOCK                ((uint32_t)(((uint32_t)0x01 << 16) | ((uint32_t)0x02 << 29)))
#define APBPeriph_UART1_CLOCK               ((uint32_t)(((uint32_t)0x01 << 0)  | ((uint32_t)0x02 << 29)))
#define APBPeriph_IF8080_CLOCK              ((uint32_t)(((uint32_t)0x01 << 28) | ((uint32_t)0x03 << 29)))
#define APBPeriph_ADC_CLOCK                 ((uint32_t)(((uint32_t)0x01 << 24) | ((uint32_t)0x03 << 29)))
#define APBPeriph_SPI2W_CLOCK               ((uint32_t)(((uint32_t)0x01 << 16) | ((uint32_t)0x03 << 29)))
#define APBPeriph_MODEMRFCPI_CLOCK          ((uint32_t)(((uint32_t)0x01 << 14) | ((uint32_t)0x03 << 29)))
#define APBPeriph_BLUEWIZ_CLOCK             ((uint32_t)(((uint32_t)0x01 << 12) | ((uint32_t)0x03 << 29)))
#define APBPeriph_ZIGBEE_CLOCK              ((uint32_t)(((uint32_t)0x01 << 10) | ((uint32_t)0x03 << 29)))
#define APBPeriph_KEYSCAN_CLOCK             ((uint32_t)(((uint32_t)0x01 << 6) | ((uint32_t)0x03 << 29)))
#define APBPeriph_QDEC_CLOCK                ((uint32_t)(((uint32_t)0x01 << 4) | ((uint32_t)0x03 << 29)))
#define APBPeriph_I2C1_CLOCK                ((uint32_t)(((uint32_t)0x01 << 2) | ((uint32_t)0x03 << 29)))
#define APBPeriph_I2C0_CLOCK                ((uint32_t)(((uint32_t)0x01 << 0) | ((uint32_t)0x03 << 29)))
/** \} */

#define IS_APB_PERIPH_CLOCK(CLOCK) (((CLOCK) == APBPeriph_GPIO_CLOCK) || ((CLOCK) == APBPeriph_GDMA_CLOCK)\
                                    || ((CLOCK) == APBPeriph_TIMER_CLOCK) || ((CLOCK) == APBPeriph_IR_CLOCK)\
                                    || ((CLOCK) == APBPeriph_ENHTIMER_CLOCK) || ((CLOCK) == APBPeriph_FLASH_CLOCK)\
                                    || ((CLOCK) == APBPeriph_PKE_CLOCK) || ((CLOCK) == APBPeriph_SHA256_CLOCK)\
                                    || ((CLOCK) == APBPeriph_FLASH1_CLOCK) || ((CLOCK) == APBPeriph_FLH_SEC_CLOCK)\
                                    || ((CLOCK) == APBPeriph_MODEM_CLOCK) || ((CLOCK) == APBPeriph_BLUEWIZ_CLOCK)\
                                    || ((CLOCK) == APBPeriph_ZIGBEE_CLOCK) \
                                    || ((CLOCK) == APBPeriph_SPI1_CLOCK) || ((CLOCK) == APBPeriph_SPI0_CLOCK)\
                                    || ((CLOCK) == APBPeriph_UART0_CLOCK) || ((CLOCK) == APBPeriph_ADC_CLOCK)\
                                    || ((CLOCK) == APBPeriph_SPI2W_CLOCK) || ((CLOCK) == APBPeriph_KEYSCAN_CLOCK)\
                                    || ((CLOCK) == APBPeriph_QDEC_CLOCK) || ((CLOCK) == APBPeriph_I2C1_CLOCK)\
                                    || ((CLOCK) == APBPeriph_I2C0_CLOCK) || ((CLOCK) == APBPeriph_CODEC_CLOCK)\
                                    || ((CLOCK) == APBPeriph_UART1_CLOCK) || ((CLOCK) == APBPeriph_UART2_CLOCK)\
                                    || ((CLOCK) == APBPeriph_I2S0_CLOCK) || ((CLOCK) == APBPeriph_I2S1_CLOCK)\
                                    || ((CLOCK) == APBPeriph_IF8080_CLOCK) || ((CLOCK) == APBPeriph_ENHTIMER_CLOCK))

/**
 * \defgroup    APB_Peripheral_Define APB Peripheral Define
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define APBPeriph_TIMER                     ((uint32_t)(((uint32_t)1 << 16) | ((uint32_t)0x00 << 26)))
#define APBPeriph_ENHTIMER                  ((uint32_t)(((uint32_t)1 << 16) | ((uint32_t)0x00 << 26)))
#define APBPeriph_GDMA                      ((uint32_t)(((uint32_t)1 << 13) | ((uint32_t)0x00 << 26)))
#define APBPeriph_UART0                     ((uint32_t)(((uint32_t)1 << 12) | ((uint32_t)0x00 << 26)))
#define APBPeriph_ZIGBEE                    ((uint32_t)(((uint32_t)1 << 11) | ((uint32_t)0x00 << 26)))
#define APBPeriph_BLUEWIZ                   ((uint32_t)(((uint32_t)1 << 10) | ((uint32_t)0x00 << 26)))
#define APBPeriph_MODEMRFCPI                ((uint32_t)(((uint32_t)1 << 9) | ((uint32_t)0x00 << 26)))
#define APBPeriph_FLH_SEC                   ((uint32_t)(((uint32_t)1 << 8) | ((uint32_t)0x00 << 26)))
#define APBPeriph_SHA256                    ((uint32_t)(((uint32_t)1 << 7) | ((uint32_t)0x00 << 26)))
#define APBPeriph_PKE                       ((uint32_t)(((uint32_t)1 << 6) | ((uint32_t)0x00 << 26)))
#define APBPeriph_FLASH                     ((uint32_t)(((uint32_t)1 << 4)  | ((uint32_t)0x00 << 26)))
#define APBPeriph_FLASH1                    ((uint32_t)(((uint32_t)1 << 3)  | ((uint32_t)0x00 << 26)))
#define APBPeriph_IF8080                    ((uint32_t)(((uint32_t)1 << 25) | ((uint32_t)0x02 << 26)))
#define APBPeriph_SPI2W                     ((uint32_t)(((uint32_t)1 << 24) | ((uint32_t)0x02 << 26)))
#define APBPeriph_KEYSCAN                   ((uint32_t)(((uint32_t)1 << 19) | ((uint32_t)0x02 << 26)))
#define APBPeriph_QDEC                      ((uint32_t)(((uint32_t)1 << 18) | ((uint32_t)0x02 << 26)))
#define APBPeriph_I2C1                      ((uint32_t)(((uint32_t)1 << 17) | ((uint32_t)0x02 << 26)))
#define APBPeriph_I2C0                      ((uint32_t)(((uint32_t)1 << 16) | ((uint32_t)0x02 << 26)))
#define APBPeriph_IR                        ((uint32_t)(((uint32_t)1 << 10) | ((uint32_t)0x02 << 26)))
#define APBPeriph_SPI1                      ((uint32_t)(((uint32_t)1 << 9) | ((uint32_t)0x02 << 26)))
#define APBPeriph_SPI0                      ((uint32_t)(((uint32_t)1 << 8) | ((uint32_t)0x02 << 26)))
#define APBPeriph_UART1                     ((uint32_t)(((uint32_t)1 << 0) | ((uint32_t)0x02 << 26)))
#define APBPeriph_UART2                     ((uint32_t)(((uint32_t)1 << 1) | ((uint32_t)0x02 << 26)))
#define APBPeriph_GPIO                      ((uint32_t)(((uint32_t)1 << 8) | ((uint32_t)0x03 << 26)))
#define APBPeriph_ADC                       ((uint32_t)(((uint32_t)1 << 0) | ((uint32_t)0x03 << 26)))
#define APBPeriph_I2S1                      ((uint32_t)(((uint32_t)1 << 2) | ((uint32_t)0x00 << 26)))
#define APBPeriph_I2S0                      ((uint32_t)(((uint32_t)1 << 1) | ((uint32_t)0x00 << 26)))
#define APBPeriph_CODEC                     ((uint32_t)(((uint32_t)1 << 0) | ((uint32_t)0x00 << 26)))
/** \} */

#define IS_APB_PERIPH(PERIPH) (((PERIPH) == APBPeriph_TIMER) || ((PERIPH) == APBPeriph_GDMA)\
                               || ((PERIPH) == APBPeriph_SPI2W) || ((PERIPH) == APBPeriph_KEYSCAN)\
                               || ((PERIPH) == APBPeriph_QDEC) || ((PERIPH) == APBPeriph_I2C1)\
                               || ((PERIPH) == APBPeriph_I2C0) || ((PERIPH) == APBPeriph_IR)\
                               || ((PERIPH) == APBPeriph_ENHTIMER) || ((PERIPH) == APBPeriph_FLASH)\
                               || ((PERIPH) == APBPeriph_PKE) || ((PERIPH) == APBPeriph_SHA256)\
                               || ((PERIPH) == APBPeriph_FLASH1) || ((PERIPH) == APBPeriph_FLH_SEC)\
                               || ((PERIPH) == APBPeriph_MODEM) || ((PERIPH) == APBPeriph_BLUEWIZ)\
                               || ((PERIPH) == APBPeriph_ZIGBEE) \
                               || ((PERIPH) == APBPeriph_SPI1) || ((PERIPH) == APBPeriph_SPI0)\
                               || ((PERIPH) == APBPeriph_UART0) || ((PERIPH) == APBPeriph_GPIO)\
                               || ((PERIPH) == APBPeriph_ADC) || ((PERIPH) == APBPeriph_CODEC)\
                               || (PERIPH == APBPeriph_UART1) || (PERIPH == APBPeriph_UART2)\
                               || ((PERIPH) == APBPeriph_I2S0) || ((PERIPH) == APBPeriph_I2S1)\
                               || ((PERIPH) == APBPeriph_IF8080) || ((PERIPH) == APBPeriph_ENHTIMER))

/**
 * \defgroup    RCC_Peripheral_Clock RCC Peripheral Clock
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define CLOCK_GATE_5M                       ((uint32_t)(0x01 << 29))/* 5M clock source for adc and keyscan */
#define CLOCK_GATE_20M                      ((uint32_t)(0x01 << 27))/* 20M clock source for 2wssi and qdec */
#define CLOCK_GATE_10M                      ((uint32_t)(0x01 << 28))/* 10M clock source for bluewiz */
/** \} */
#define IS_CLOCK_GATE(CLOCK) (((CLOCK) == CLOCK_GATE_5M) || ((CLOCK) == CLOCK_GATE_20M)\
                              || ((CLOCK) == CLOCK_GATE_10M))

/**
 * \defgroup    I2C_Clock_Divider I2C Clock Divider
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define I2C_CLOCK_DIV_1                     ((uint16_t)0x0)
#define I2C_CLOCK_DIV_2                     ((uint16_t)0x1)
#define I2C_CLOCK_DIV_4                     ((uint16_t)0x2)
#define I2C_CLOCK_DIV_8                     ((uint16_t)0x3)
/** \} */
#define IS_I2C_DIV(DIV)              (((DIV) == I2C_CLOCK_DIV_1) || \
                                      ((DIV) == I2C_CLOCK_DIV_2) || \
                                      ((DIV) == I2C_CLOCK_DIV_4) || \
                                      ((DIV) == I2C_CLOCK_DIV_8))
/**
 * \defgroup    SPI_Clock_Divider SPI Clock Divider
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define SPI_CLOCK_DIV_1                     ((uint16_t)0x0)
#define SPI_CLOCK_DIV_2                     ((uint16_t)0x1)
#define SPI_CLOCK_DIV_4                     ((uint16_t)0x2)
#define SPI_CLOCK_DIV_8                     ((uint16_t)0x3)
/** \} */
#define IS_SPI_DIV(DIV)              (((DIV) == SPI_CLOCK_DIV_1) || \
                                      ((DIV) == SPI_CLOCK_DIV_2) || \
                                      ((DIV) == SPI_CLOCK_DIV_4) || \
                                      ((DIV) == SPI_CLOCK_DIV_8))

/**
 * \defgroup    UART_Clock_Divider UART Clock Divider
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define UART_CLOCK_DIV_1                    ((uint16_t)0x0)
#define UART_CLOCK_DIV_2                    ((uint16_t)0x1)
#define UART_CLOCK_DIV_4                    ((uint16_t)0x2)
#define UART_CLOCK_DIV_16                   ((uint16_t)0x3)
/** \} */
#define IS_UART_DIV(DIV)              (((DIV) == UART_CLOCK_DIV_1) || \
                                       ((DIV) == UART_CLOCK_DIV_2) || \
                                       ((DIV) == UART_CLOCK_DIV_4) || \
                                       ((DIV) == UART_CLOCK_DIV_16))
/**
 * \defgroup    TIM_Clock_Divider TIM Clock Divider
 * \{
 * \ingroup     RCC_Exported_Constants
 */

#define TIM_CLOCK_DIV_1                     0x00
#define TIM_CLOCK_DIV_125                   0x03
#define TIM_CLOCK_DIV_2                     0x04
#define TIM_CLOCK_DIV_4                     0x05
#define TIM_CLOCK_DIV_8                     0x06
#define TIM_CLOCK_DIV_40                    0x07
/** \} */
#define IS_TIM_DIV(DIV) (((DIV) == TIM_CLOCK_DIV_1) || \
                         ((DIV) == TIM_CLOCK_DIV_125) || \
                         ((DIV) == TIM_CLOCK_DIV_2) || \
                         ((DIV) == TIM_CLOCK_DIV_4) || \
                         ((DIV) == TIM_CLOCK_DIV_8) || \
                         ((DIV) == TIM_CLOCK_DIV_40))

/**
 * \defgroup    TIM_Clock_Divider TIM Clock Divider
 * \{
 * \ingroup     RCC_Exported_Constants
 */

typedef enum
{
    TIM_CLK_2   = 2,
    TIM_CLK_3,
    TIM_CLK_4,
    TIM_CLK_5,
    TIMENH_CLK_0,
    TIMENH_CLK_1,
} E_TIM_NUM;

#define TIM0_CLK                        0x00
#define TIM_CLOCK_DIV_125                   0x03
#define TIM_CLOCK_DIV_2                     0x04
#define TIM_CLOCK_DIV_4                     0x05
#define TIM_CLOCK_DIV_8                     0x06
#define TIM_CLOCK_DIV_40                    0x07
/** \} */
#define IS_TIM_DIV(DIV) (((DIV) == TIM_CLOCK_DIV_1) || \
                         ((DIV) == TIM_CLOCK_DIV_125) || \
                         ((DIV) == TIM_CLOCK_DIV_2) || \
                         ((DIV) == TIM_CLOCK_DIV_4) || \
                         ((DIV) == TIM_CLOCK_DIV_8) || \
                         ((DIV) == TIM_CLOCK_DIV_40))

/** End of RCC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * \defgroup    RCC_Exported_Functions RCC Exported Functions
 * \{
 * \ingroup     RCC
 */

/**
 * \brief  Enables or disables the APB peripheral clock.
 * \param  APBPeriph: Specifies the APB peripheral to gates its clock.
 *     This parameter can be one of the following values:
  *     @arg APBPeriph_TIMER
  *     @arg APBPeriph_ENHTIMER
  *     @arg APBPeriph_FLASH
  *     @arg APBPeriph_GDMA
  *     @arg APBPeriph_PKE
  *     @arg APBPeriph_SHA256
  *     @arg APBPeriph_FLASH1
  *     @arg APBPeriph_FLH_SEC
  *     @arg APBPeriph_MODEM
  *     @arg APBPeriph_BLUEWIZ
  *     @arg APBPeriph_ZIGBEE
  *     @arg APBPeriph_IF8080
  *     @arg APBPeriph_SPI2W
  *     @arg APBPeriph_KEYSCAN
  *     @arg APBPeriph_QDEC
  *     @arg APBPeriph_I2C1
  *     @arg APBPeriph_I2C0
  *     @arg APBPeriph_IR
  *     @arg APBPeriph_SPI1
  *     @arg APBPeriph_SPI0
  *     @arg APBPeriph_UART0
  *     @arg APBPeriph_UART1
  *     @arg APBPeriph_UART2
  *     @arg APBPeriph_GPIO
  *     @arg APBPeriph_ADC
  *     @arg APBPeriph_I2S0
  *     @arg APBPeriph_I2S1
  *     @arg APBPeriph_CODEC
  * @param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *   This parameter can be one of the following values(must be the same with APBPeriph):
  *     @arg APBPeriph_TIMER_CLOCK
  *     @arg APBPeriph_ENHTIMER_CLOCK
  *     @arg APBPeriph_FLASH_CLOCK
  *     @arg APBPeriph_GDMA_CLOCK
  *     @arg APBPeriph_PKE_CLOCK
  *     @arg APBPeriph_SHA256_CLOCK
  *     @arg APBPeriph_FLASH1_CLOCK
  *     @arg APBPeriph_FLH_SEC_CLOCK
  *     @arg APBPeriph_MODEM_CLOCK
  *     @arg APBPeriph_BLUEWIZ_CLOCK
  *     @arg APBPeriph_ZIGBEE_CLOCK
  *     @arg APBPeriph_IF8080_CLOCK
  *     @arg APBPeriph_SPI2W_CLOCK
  *     @arg APBPeriph_KEYSCAN_CLOCK
  *     @arg APBPeriph_QDEC_CLOCK
  *     @arg APBPeriph_I2C1_CLOCK
  *     @arg APBPeriph_I2C0_CLOCK
  *     @arg APBPeriph_IR_CLOCK
  *     @arg APBPeriph_SPI1_CLOCK
  *     @arg APBPeriph_SPI0_CLOCK
  *     @arg APBPeriph_UART0_CLOCK
  *     @arg APBPeriph_UART1_CLOCK
  *     @arg APBPeriph_UART2_CLOCK
  *     @arg APBPeriph_GPIO_CLOCK
  *     @arg APBPeriph_ADC_CLOCK
  *     @arg APBPeriph_I2S0_CLOCK
  *     @arg APBPeriph_I2S1_CLOCK
  *     @arg APBPeriph_CODEC_CLOCK
 * \param  NewState: New state of the specified peripheral clock.
 *     This parameter can be: ENABLE or DISABLE.
 * \retval None.
 */
void RCC_PeriphClockCmd(uint32_t APBPeriph, uint32_t APBPeriph_Clock,
                        FunctionalState NewState);
/**
 * \brief  I2C clock divider config.
 * \param  I2Cx: Where x can be 0 or 1 to select the I2C peripheral.
 * \param  ClockDiv: Specifies the APB peripheral to gates its clock.
 *     This parameter can be one of the following values:
 *     \arg I2C_CLOCK_DIV_1
 *     \arg I2C_CLOCK_DIV_2
 *     \arg I2C_CLOCK_DIV_4
 *     \arg I2C_CLOCK_DIV_8
 * \retval None.
 */
void RCC_I2CClkDivConfig(I2C_TypeDef *I2Cx, uint16_t ClockDiv);

/**
 * \brief  SPI clock divider config.
 * \param  SPIx: Where x can be 0 or 1 to select the SPI peripheral.
 * \param  ClockDiv: Specifies the APB peripheral to gates its clock.
 *     This parameter can be one of the following values:
 *     \arg SPI_CLOCK_DIV_1
 *     \arg SPI_CLOCK_DIV_2
 *     \arg SPI_CLOCK_DIV_4
 *     \arg SPI_CLOCK_DIV_8
 * \retval None.
 */
void RCC_SPIClkDivConfig(SPI_TypeDef *SPIx, uint16_t ClockDiv);

/**
  * @brief  TIMER & ENH-TIMER clock divider config.
  * @param  TIMx: selected TIM number.
  * @param  ClockDiv: specifies the APB peripheral to gates its clock.
  *         This parameter can be one of the following values:
  *         @arg TIM_CLOCK_DIV_1
  *         @arg TIM_CLOCK_DIV_125
  *         @arg TIM_CLOCK_DIV_2
  *         @arg TIM_CLOCK_DIV_4
  *         @arg TIM_CLOCK_DIV_8
  *         @arg TIM_CLOCK_DIV_40
  * @retval None
  */
void RCC_TIMClkDivConfig(E_TIM_NUM TIMx, uint16_t ClockDiv);

/**
 * \brief  UART clock divider config.
 * \param  UARTx: Selected UART peripheral.
 * \param  ClockDiv: Specifies the APB peripheral to gates its clock.
 *     This parameter can be one of the following values:
 *     \arg UART_CLOCK_DIV_1
 *     \arg UART_CLOCK_DIV_2
 *     \arg UART_CLOCK_DIV_4
 *     \arg UART_CLOCK_DIV_16
 * \retval None.
 */
void RCC_UARTClkDivConfig(UART_TypeDef *UARTx, uint16_t ClockDiv);

/**
 * \brief   Enables or disables the APB peripheral function.
 * \param   APBPeriph: Specifies the APB peripheral .
 *          This parameter can be one of the following values:
  *     @arg APBPeriph_TIMER
  *     @arg APBPeriph_ENHTIMER
  *     @arg APBPeriph_FLASH
  *     @arg APBPeriph_GDMA
  *     @arg APBPeriph_PKE
  *     @arg APBPeriph_SHA256
  *     @arg APBPeriph_FLASH1
  *     @arg APBPeriph_FLH_SEC
  *     @arg APBPeriph_MODEM
  *     @arg APBPeriph_BLUEWIZ
  *     @arg APBPeriph_ZIGBEE
  *     @arg APBPeriph_IF8080
  *     @arg APBPeriph_SPI2W
  *     @arg APBPeriph_KEYSCAN
  *     @arg APBPeriph_QDEC
  *     @arg APBPeriph_I2C1
  *     @arg APBPeriph_I2C0
  *     @arg APBPeriph_IR
  *     @arg APBPeriph_SPI1
  *     @arg APBPeriph_SPI0
  *     @arg APBPeriph_UART0
  *     @arg APBPeriph_UART1
  *     @arg APBPeriph_UART2
  *     @arg APBPeriph_GPIO
  *     @arg APBPeriph_ADC
  *     @arg APBPeriph_I2S0
  *     @arg APBPeriph_I2S1
  *     @arg APBPeriph_CODEC
 * \param  NewState: New state of the specified peripheral clock.
 *     This parameter can be: ENABLE or DISABLE.
 * \retval None.
 */
void RCC_PeriFunctionConfig(uint32_t APBPeriph, FunctionalState NewState);

/**
 * \brief  Enables or disables the APB peripheral clock.
 * \param  APBPeriph_Clock: Specifies the APB peripheral clock config.
 *     This parameter can be one of the following values(must be the same with APBPeriph):
  *     @arg APBPeriph_TIMER_CLOCK
  *     @arg APBPeriph_ENHTIMER_CLOCK
  *     @arg APBPeriph_FLASH_CLOCK
  *     @arg APBPeriph_GDMA_CLOCK
  *     @arg APBPeriph_PKE_CLOCK
  *     @arg APBPeriph_SHA256_CLOCK
  *     @arg APBPeriph_FLASH1_CLOCK
  *     @arg APBPeriph_FLH_SEC_CLOCK
  *     @arg APBPeriph_MODEM_CLOCK
  *     @arg APBPeriph_BLUEWIZ_CLOCK
  *     @arg APBPeriph_ZIGBEE_CLOCK
  *     @arg APBPeriph_IF8080_CLOCK
  *     @arg APBPeriph_SPI2W_CLOCK
  *     @arg APBPeriph_KEYSCAN_CLOCK
  *     @arg APBPeriph_QDEC_CLOCK
  *     @arg APBPeriph_I2C1_CLOCK
  *     @arg APBPeriph_I2C0_CLOCK
  *     @arg APBPeriph_IR_CLOCK
  *     @arg APBPeriph_SPI1_CLOCK
  *     @arg APBPeriph_SPI0_CLOCK
  *     @arg APBPeriph_UART0_CLOCK
  *     @arg APBPeriph_UART1_CLOCK
  *     @arg APBPeriph_UART2_CLOCK
  *     @arg APBPeriph_GPIO_CLOCK
  *     @arg APBPeriph_ADC_CLOCK
  *     @arg APBPeriph_I2S0_CLOCK
  *     @arg APBPeriph_I2S1_CLOCK
  *     @arg APBPeriph_CODEC_CLOCK
 * \param  NewState: New state of the specified peripheral clock.
 *     This parameter can be: ENABLE or DISABLE.
 * \retval None.
 */
void RCC_PeriClockConfig(uint32_t APBPeriph_Clock, FunctionalState NewState);

/**
 * \brief   Enable clock 5M source.
 * \param   None.
 * \return  None.
 */
__STATIC_INLINE void RCC_ClockSrc5MCmd(void)
{
    /*Open 5M clock source*/
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT26;
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT29;
}

/**
 * \brief   Enable clock 10M source.
 * \param   None.
 * \return  None.
 */
__STATIC_INLINE void RCC_ClockSrc10MCmd(void)
{
    /*Open 10M clock source*/
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT26;
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT28;
}

/**
 * \brief   Enable clock 20M source.
 * \param   None.
 * \return  None.
 */
__STATIC_INLINE void RCC_ClockSrc20MCmd(void)
{
    /*Open 20M clock source*/
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT26;
    SYSBLKCTRL->u_20C.PERION_REG_SYS_CLK_SEL_2 |= BIT27;
}

/** End of RCC_Exported_Functions
  * \}
  */

/** End of RCC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_RCC_H_ */


/******************* (C) COPYRIGHT 2015 Realtek Semiconductor *****END OF FILE****/



