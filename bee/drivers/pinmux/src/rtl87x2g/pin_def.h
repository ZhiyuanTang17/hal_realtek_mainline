/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     pin_def.h
* \brief    The header file of all the peripheral driver.
* \details  This file provides all firmware functions.
* \author   Bert
* \date     2023-10-17
* \version  v1.0
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef PIN_DEF_H
#define PIN_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup PIN_DEFINE       PIN DEFINE
  * \brief
  * \{
  */

/*============================================================================*
 *                         RTL87x2G Pin Number
 *============================================================================*/
/** \defgroup Pin_Number       Pin Number
  * \brief
  * \{
  */

#define P0_0        0       /*!< GPIOA_0  */
#define P0_1        1       /*!< GPIOA_1  */
#define P0_2        2       /*!< GPIOA_2  */
#define P0_3        3       /*!< GPIOA_3  */
#define P0_4        4       /*!< GPIOA_4  */
#define P0_5        5       /*!< GPIOA_5  */
#define P0_6        6       /*!< GPIOA_6  */
#define P0_7        7       /*!< GPIOA_7  */

#define P1_0        8       /*!< GPIOA_8  */
#define P1_1        9       /*!< GPIOA_9  */
#define P1_2        10      /*!< GPIOA_10 */
#define P1_3        11      /*!< GPIOA_11 */
#define P1_4        12      /*!< GPIOA_12 */
#define P1_5        13      /*!< GPIOA_13 */
#define P1_6        14      /*!< GPIOA_14 */
#define P1_7        15      /*!< GPIOA_15 */

#define P2_0        16      /*!< GPIOA_21 */
#define P2_1        17      /*!< GPIOA_22 */
#define P2_2        18      /*!< GPIOA_23 */
#define P2_3        19      /*!< GPIOA_24 */
#define P2_4        20      /*!< GPIOA_25 */
#define P2_5        21      /*!< GPIOA_26 */
#define P2_6        22      /*!< GPIOA_27 */
#define P2_7        23      /*!< GPIOA_28 */

#define P3_0        24      /*!< GPIOA_29 */
#define P3_1        25      /*!< GPIOA_30 */
#define P3_2        26      /*!< GPIOA_31 */
#define P3_3        27      /*!< GPIOB_0 */
#define P3_4        28      /*!< GPIOB_1 */
#define P3_5        29      /*!< GPIOB_2 */
#define P3_6        30      /*!< GPIOB_3 */
#define P3_7        31      /*!< GPIOB_4 */

#define P4_0        32      /*!< GPIOB_5  */
#define P4_1        33      /*!< GPIOB_6  */
#define P4_2        34      /*!< GPIOB_7  */
#define P4_3        35      /*!< GPIOB_8  */
#define P4_4        36      /*!< GPIOB_9  */
#define P4_5        37      /*!< GPIOB_10  */
#define P4_6        38      /*!< GPIOB_11  */
#define P4_7        39      /*!< GPIOB_12  */

#define P5_0        40      /*!< GPIOB_13  */
#define P5_1        41      /*!< GPIOB_14  */
#define P5_2        42      /*!< GPIOB_15 */
#define P5_3        43      /*!< GPIOB_16 */
#define P5_4        44      /*!< GPIOB_17 */
#define P5_5        45      /*!< GPIOB_18 */
#define P5_6        46      /*!< GPIOB_19 */
#define P5_7        47      /*!< GPIOB_20 */

#define P6_0        48      /*!< GPIOB_19 */
#define P6_1        49      /*!< GPIOB_20 */
#define P6_2        50      /*!< GPIOB_21 */
#define P6_3        51      /*!< GPIOB_22 */
#define P6_4        52      /*!< GPIOB_23 */
#define P6_5        53      /*!< GPIOB_24 */
#define P6_6        54      /*!< GPIOB_25 */
#define P6_7        55      /*!< GPIOB_26 */

#define P7_0        56      /*!< GPIOB_27 */
#define P7_1        57      /*!< GPIOB_28 */
#define P7_2        58      /*!< GPIOB_29 */
#define P7_3        59      /*!< GPIOB_30 */
#define P7_4        60      /*!< GPIOB_31 */

//#define P7_5        61      /*!< RSVD */
//#define P7_6        62      /*!< RSVD */
//#define P7_7        63      /*!< RSVD */

#define MICBIAS     64      /*!< P8_0 GPIOA_16*/
#define XI32K       65      /*!< P8_1 GPIOA_17*/
#define XO32K       66      /*!< P8_2 GPIOA_18*/
#define DACP        67      /*!< P8_3 GPIOA_19*/
#define DACN        68      /*!< P8_4 GPIOA_20*/

//#define P8_5        69      /*!< RSVD */
//#define P8_6        70      /*!< RSVD */
//#define P8_7        71      /*!< RSVD */

#define P9_0        72      /*!< GPIOB_21 */
#define P9_1        73      /*!< GPIOB_22 */
#define P9_2        74      /*!< GPIOB_23 */
#define P9_3        75      /*!< GPIOB_24 */
#define P9_4        76      /*!< GPIOB_25 */
#define P9_5        77      /*!< GPIOB_26 */
#define P9_6        78      /*!< GPIOB_27 */
#define P9_7        79      /*!< GPIOB_28 */

#define P10_0       80      /*!< GPIOB_29 */
#define P10_1       81      /*!< GPIOB_30 */
#define P10_2       82      /*!< GPIOB_31 */

#define ADC_0       P2_0    /*!< GPIO16   */
#define ADC_1       P2_1    /*!< GPIO17   */
#define ADC_2       P2_2    /*!< GPIO18   */
#define ADC_3       P2_3    /*!< GPIO19   */
#define ADC_4       P2_4    /*!< GPIO20   */
#define ADC_5       P2_5    /*!< GPIO21   */
#define ADC_6       P2_6    /*!< GPIO22   */
#define ADC_7       P2_7    /*!< GPIO23   */

#define TOTAL_PIN_NUM         (83)
#define IS_PIN_NUMBER(NUMBER) ((NUMBER) < TOTAL_PIN_NUM)

/** End of Pin_Number
  * \}
  */

/** End of PIN DEFINE
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* PIN_DEF_H */


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

