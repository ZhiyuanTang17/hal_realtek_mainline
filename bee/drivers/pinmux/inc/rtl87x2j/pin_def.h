/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
 *                         Pin Number
 *============================================================================*/
/** \defgroup Pin_Number       Pin Number
  * \brief
  * \{
  */

/******************* Reference: Bee5_pin_mux_20250117A-bitfile0305.xlsx *******************/
#define P0_0                         0         /*!< GPIO_0 */
#define P0_1                         1         /*!< GPIO_1 */
#define P0_2                         2         /*!< GPIO_2 */
#define P0_3                         3         /*!< GPIO_3 */
#define P0_4                         4         /*!< GPIO_4 */
#define P0_5                         5         /*!< GPIO_5 */
#define P0_6                         6         /*!< GPIO_6 */
#define P0_7                         7         /*!< GPIO_7 */
#define P1_0                         8         /*!< GPIO_8 */
#define P1_1                         9         /*!< GPIO_9 */
#define P1_6                         10        /*!< GPIO_10 */
#define P1_7                         11        /*!< GPIO_11 */
#define P2_0                         12        /*!< GPIO_12 */
#define P2_1                         13        /*!< GPIO_13 */
#define P2_2                         14        /*!< GPIO_14 */
#define P2_3                         15        /*!< GPIO_15 */
#define P2_4                         16        /*!< GPIO_16 */
#define P2_5                         17        /*!< GPIO_17 */
#define P2_6                         18        /*!< GPIO_18 */
#define P2_7                         19        /*!< GPIO_19 */
#define P3_0                         20        /*!< GPIO_20 */
#define P3_1                         21        /*!< GPIO_21 */
#define P3_2                         22        /*!< GPIO_22 */
#define P3_3                         23        /*!< GPIO_23 */
#define P3_4                         24        /*!< GPIO_24 */
#define P3_5                         25        /*!< GPIO_25 */
#define P3_6                         26        /*!< GPIO_26 */
#define P4_0                         27        /*!< GPIO_27 */
#define P4_1                         28        /*!< GPIO_28 */
#define P4_2                         29        /*!< GPIO_29 */
#define P4_3                         30        /*!< GPIO_30 */
#define MICBIAS                      31        /*!< GPIO_31 */
#define P5_1                         32        /*!< GPIO_32 */
#define P5_2                         33        /*!< GPIO_33 */
#define P6_0                         34        /*!< GPIO_34 */
#define P6_1                         35        /*!< GPIO_35 */
#define P6_2                         36        /*!< GPIO_36 */
#define P6_3                         37        /*!< GPIO_37 */
#define P6_4                         38        /*!< GPIO_38 */
#define P6_5                         39        /*!< GPIO_39 */
#define P6_6                         40        /*!< GPIO_40 */
#define P6_7                         41        /*!< GPIO_41 */
#define P7_0                         42        /*!< GPIO_42 */
#define P7_1                         43        /*!< GPIO_43 */
#define SPIC_CSN                     44        /*!< GPIO_44 */
#define SPIC_SCK                     45        /*!< GPIO_45 */
#define SPIC_SI                      46        /*!< GPIO_46 */
#define SPIC_SO                      47        /*!< GPIO_47 */
#define SPIC_WEN                     48        /*!< GPIO_48 P1_4 */
#define SPIC_HOLDEN                  49        /*!< GPIO_49 P1_3 */

#define ADC_0                        P2_0
#define ADC_1                        P2_1
#define ADC_2                        P2_2
#define ADC_3                        P2_3
#define ADC_4                        P2_4
#define ADC_5                        P2_5
#define ADC_6                        P2_6
#define ADC_7                        P2_7

#define TOTAL_PIN_NUM                (50)
#define IS_PIN_NUMBER(NUMBER)        (NUMBER < TOTAL_PIN_NUM)

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


