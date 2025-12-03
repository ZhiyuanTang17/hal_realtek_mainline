/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VECTOR_TABLE_AUTO_GEN_H
#define VECTOR_TABLE_AUTO_GEN_H

// *INDENT-OFF*
/* ================================================================================ */
/* ================                      IRQ                       ================ */
/* ======== Reference: rtl87x2g_AddrMap_IRQs_DmaPorts_20220913v0.xlsx   =========== */
/* ================================================================================ */

#define IRQn_AUTO_GEN \
        NMI_IRQn =                              -14, \
        HardFault_IRQn =                        -13, \
        MemoryManagement_IRQn =                   -12, \
        BusFault_IRQn =                         -11, \
        UsageFault_IRQn =                       -10, \
        SecureFault_IRQn =                      -9, \
        RSVD0_IRQn =                            -8, \
        RSVD1_IRQn =                            -7, \
        RSVD2_IRQn =                            -6, \
        SVCall_IRQn =                              -5, \
        DebugMonitor_IRQn =                     -4, \
        RSVD3_IRQn =                            -3, \
        PendSV_IRQn =                           -2, \
        SysTick_IRQn =                          -1, \
        System_IRQn =                           0, \
        WDT_IRQn =                              1, \
        RXI300_IRQn =                           2, \
        RXI300_SEC_IRQn =                       3, \
        Zigbee_IRQn =                           4, \
        BTMAC_IRQn =                            5, \
        Peripheral_IRQn =                       6, \
        RSVD4_IRQn =                            7, \
        RTC_IRQn =                              8, \
        GPIO_A0_IRQn =                          9, \
        GPIO_A1_IRQn =                          10, \
        GPIO_A_2_7_IRQn =                       11, \
        GPIO_A_8_15_IRQn =                      12, \
        GPIO_A_16_23_IRQn =                     13, \
        GPIO_A_24_31_IRQn =                     14, \
        GPIO_B_0_7_IRQn =                       15, \
        GPIO_B_8_15_IRQn =                      16, \
        GPIO_B_16_23_IRQn =                     17, \
        GPIO_B_24_31_IRQn =                     18, \
        GDMA0_Channel0_IRQn =                   19, \
        GDMA0_Channel1_IRQn =                   20, \
        GDMA0_Channel2_IRQn =                   21, \
        GDMA0_Channel3_IRQn =                   22, \
        GDMA0_Channel4_IRQn =                   23, \
        GDMA0_Channel5_IRQn =                   24, \
        GDMA0_Channel6_IRQn =                   25, \
        GDMA0_Channel7_IRQn =                   26, \
        GDMA0_Channel8_IRQn =                   27, \
        GDMA0_Channel9_IRQn =                   28, \
        PPE_IRQn =                              29, \
        I2C0_IRQn =                             30, \
        I2C1_IRQn =                             31, \
        I2C2_IRQn =                             32, \
        I2C3_IRQn =                             33, \
        UART0_IRQn =                            34, \
        UART1_IRQn =                            35, \
        UART2_IRQn =                            36, \
        UART3_IRQn =                            37, \
        UART4_IRQn =                            38, \
        UART5_IRQn =                            39, \
        SPI3W_IRQn =                            40, \
        SPI0_IRQn =                             41, \
        SPI1_IRQn =                             42, \
        SPI_Slave_IRQn =                        43, \
        Timer0_IRQn =                           44, \
        Timer1_IRQn =                           45, \
        Timer2_IRQn =                           46, \
        Timer3_IRQn =                           47, \
        Timer4_IRQn =                           48, \
        Timer5_IRQn =                           49, \
        Timer6_IRQn =                           50, \
        Timer7_IRQn =                           51, \
        Enhanced_Timer0_IRQn =                  52, \
        Enhanced_Timer1_IRQn =                  53, \
        Enhanced_Timer2_IRQn =                  54, \
        Enhanced_Timer3_IRQn =                  55, \
        HRADC_IRQn =                            56, \
        SAR_ADC_IRQn =                          57, \
        KEYSCAN_IRQn =                          58, \
        AON_QDEC_IRQn =                         59, \
        IR_IRQn =                               60, \
        SDHC_IRQn =                             61, \
        ISO7816_IRQn =                          62, \
        Display_IRQn =                          63, \
        SPORT0_RX_IRQn =                        64, \
        SPORT0_TX_IRQn =                        65, \
        SPORT1_RX_IRQn =                        66, \
        SPORT1_TX_IRQn =                        67, \
        SHA256_IRQn =                           68, \
        Public_Key_Engine_IRQn =                69, \
        Flash_SEC_IRQn =                        70, \
        SegCom_CTL_IRQn =                       71, \
        A2C_IRQn =                              72, \
        ETH_IRQn =                              73, \
        IMDC_IRQn =                             74, \
        Slave_Port_Monitor_IRQn =               75, \
        PTA_Mailbox_IRQn =                      76, \
        USB_IRQn =                              77, \
        USB_SUSPEND_N_IRQn =                    78, \
        USB_Endp_Multi_Proc_IRQn =              79, \
        USB_IN_EP_0_IRQn =                      80, \
        USB_IN_EP_1_IRQn =                      81, \
        USB_IN_EP_2_IRQn =                      82, \
        USB_IN_EP_3_IRQn =                      83, \
        USB_IN_EP_4_IRQn =                      84, \
        USB_IN_EP_5_IRQn =                      85, \
        USB_OUT_EP_0_IRQn =                     86, \
        USB_OUT_EP_1_IRQn =                     87, \
        USB_OUT_EP_2_IRQn =                     88, \
        USB_OUT_EP_3_IRQn =                     89, \
        USB_OUT_EP_4_IRQn =                     90, \
        USB_OUT_EP_5_IRQn =                     91, \
        USB_Sof_IRQn =                          92, \
        TMETER_IRQn =                           93, \
        PF_RTC_IRQn =                           94, \
        BTMAC_WRAP_AROUND_IRQn =                95, \
        \
/* second level interrupt (BTMAC_ISR Status Register) */ \
        Timer_A0_A1_IRQn =                      96, \
        BT_Bluewiz_IRQn =                       97, \
        RSVD6_IRQn =                            98, \
        BT_BZ_DMA_IRQn =                        99, \
        Proprietary_protocol_IRQn =             100, \
        RSVD7_IRQn =                            101, \
        \
/* second level interrupt (Peripheral_ISR Status Register) */ \
        SPIC0_IRQn =                            102, \
        SPIC1_IRQn =                            103, \
        SPIC2_IRQn =                            104, \
        TRNG_IRQn=                              105, \
        LPCOMP_IRQn =                           106, \
        SPI_PHY1_IRQn =                         107, \
        RSVD8_IRQn =                            108, \


#define FIRST_LEVEL_First_IRQn   System_IRQn
#define FIRST_LEVEL_Last_IRQn    PF_RTC_IRQn

#define Peripheral_First_IRQn    SPIC0_IRQn
#define Peripheral_Last_IRQn     RSVD7_IRQn

#define BTMAC_First_IRQn         Timer_A0_A1_IRQn
#define BTMAC_Last_IRQn          RSVD6_IRQn

#define GPIOA0_IRQn              GPIO_A0_IRQn
#define GPIOA1_IRQn              GPIO_A1_IRQn
#define GPIOA2_IRQn              GPIO_A_2_7_IRQn
#define GPIOA3_IRQn              GPIO_A_2_7_IRQn
#define GPIOA4_IRQn              GPIO_A_2_7_IRQn
#define GPIOA5_IRQn              GPIO_A_2_7_IRQn
#define GPIOA6_IRQn              GPIO_A_2_7_IRQn
#define GPIOA7_IRQn              GPIO_A_2_7_IRQn
#define GPIOA8_IRQn              GPIO_A_8_15_IRQn
#define GPIOA9_IRQn              GPIO_A_8_15_IRQn
#define GPIOA10_IRQn             GPIO_A_8_15_IRQn
#define GPIOA11_IRQn             GPIO_A_8_15_IRQn
#define GPIOA12_IRQn             GPIO_A_8_15_IRQn
#define GPIOA13_IRQn             GPIO_A_8_15_IRQn
#define GPIOA14_IRQn             GPIO_A_8_15_IRQn
#define GPIOA15_IRQn             GPIO_A_8_15_IRQn
#define GPIOA16_IRQn             GPIO_A_16_23_IRQn
#define GPIOA17_IRQn             GPIO_A_16_23_IRQn
#define GPIOA18_IRQn             GPIO_A_16_23_IRQn
#define GPIOA19_IRQn             GPIO_A_16_23_IRQn
#define GPIOA20_IRQn             GPIO_A_16_23_IRQn
#define GPIOA21_IRQn             GPIO_A_16_23_IRQn
#define GPIOA22_IRQn             GPIO_A_16_23_IRQn
#define GPIOA23_IRQn             GPIO_A_16_23_IRQn
#define GPIOA24_IRQn             GPIO_A_24_31_IRQn
#define GPIOA25_IRQn             GPIO_A_24_31_IRQn
#define GPIOA26_IRQn             GPIO_A_24_31_IRQn
#define GPIOA27_IRQn             GPIO_A_24_31_IRQn
#define GPIOA28_IRQn             GPIO_A_24_31_IRQn
#define GPIOA29_IRQn             GPIO_A_24_31_IRQn
#define GPIOA30_IRQn             GPIO_A_24_31_IRQn
#define GPIOA31_IRQn             GPIO_A_24_31_IRQn

#define GPIOB0_IRQn              GPIO_B_0_7_IRQn
#define GPIOB1_IRQn              GPIO_B_0_7_IRQn
#define GPIOB2_IRQn              GPIO_B_0_7_IRQn
#define GPIOB3_IRQn              GPIO_B_0_7_IRQn
#define GPIOB4_IRQn              GPIO_B_0_7_IRQn
#define GPIOB5_IRQn              GPIO_B_0_7_IRQn
#define GPIOB6_IRQn              GPIO_B_0_7_IRQn
#define GPIOB7_IRQn              GPIO_B_0_7_IRQn
#define GPIOB8_IRQn              GPIO_B_8_15_IRQn
#define GPIOB9_IRQn              GPIO_B_8_15_IRQn
#define GPIOB10_IRQn             GPIO_B_8_15_IRQn
#define GPIOB11_IRQn             GPIO_B_8_15_IRQn
#define GPIOB12_IRQn             GPIO_B_8_15_IRQn
#define GPIOB13_IRQn             GPIO_B_8_15_IRQn
#define GPIOB14_IRQn             GPIO_B_8_15_IRQn
#define GPIOB15_IRQn             GPIO_B_8_15_IRQn
#define GPIOB16_IRQn             GPIO_B_16_23_IRQn
#define GPIOB17_IRQn             GPIO_B_16_23_IRQn
#define GPIOB18_IRQn             GPIO_B_16_23_IRQn
#define GPIOB19_IRQn             GPIO_B_16_23_IRQn
#define GPIOB20_IRQn             GPIO_B_16_23_IRQn
#define GPIOB21_IRQn             GPIO_B_16_23_IRQn
#define GPIOB22_IRQn             GPIO_B_16_23_IRQn
#define GPIOB23_IRQn             GPIO_B_16_23_IRQn
#define GPIOB24_IRQn             GPIO_B_24_31_IRQn
#define GPIOB25_IRQn             GPIO_B_24_31_IRQn
#define GPIOB26_IRQn             GPIO_B_24_31_IRQn
#define GPIOB27_IRQn             GPIO_B_24_31_IRQn
#define GPIOB28_IRQn             GPIO_B_24_31_IRQn
#define GPIOB29_IRQn             GPIO_B_24_31_IRQn
#define GPIOB30_IRQn             GPIO_B_24_31_IRQn
#define GPIOB31_IRQn             GPIO_B_24_31_IRQn


/* ================================================================================ */
/* ================                     VECTOR                     ================ */
/* ======== Reference: rtl87x2g_AddrMap_IRQs_DmaPorts_20220913v0.xlsx   =========== */
/* ================================================================================ */

#define VECTORn_AUTO_GEN \
        InitialSPvalue_VECTORn =                   0, \
        Reset_VECTORn =                            1, \
        NMI_VECTORn =                              2, \
        HardFault_VECTORn =                        3, \
        MemManageFault_VECTORn =                   4, \
        BusFault_VECTORn =                         5, \
        UsageFault_VECTORn =                       6, \
        RSVD0_VECTORn =                            7, \
        RSVD1_VECTORn =                            8, \
        RSVD2_VECTORn =                            9, \
        RSVD3_VECTORn =                            10, \
        SVC_VECTORn =                              11, \
        DebugMonitor_VECTORn =                     12, \
        RSVD4_VECTORn =                            13, \
        PendSV_VECTORn =                           14, \
        SysTick_VECTORn =                          15, \
        System_VECTORn =                           16, \
        WDT_VECTORn =                              17, \
        RXI300_VECTORn =                           18, \
        RXI300_SEC_VECTORn =                       19, \
        Zigbee_VECTORn =                           20, \
        BTMAC_VECTORn =                            21, \
        Peripheral_VECTORn =                       22, \
        RSVD5_VECTORn =                            23, \
        RTC_VECTORn =                              24, \
        GPIO_A0_VECTORn =                          25, \
        GPIO_A1_VECTORn =                          26, \
        GPIO_A_2_7_VECTORn =                       27, \
        GPIO_A_8_15_VECTORn =                      28, \
        GPIO_A_16_23_VECTORn =                     29, \
        GPIO_A_24_31_VECTORn =                     30, \
        GPIO_B_0_7_VECTORn =                       31, \
        GPIO_B_8_15_VECTORn =                      32, \
        GPIO_B_16_23_VECTORn =                     33, \
        GPIO_B_24_31_VECTORn =                     34, \
        GDMA0_Channel0_VECTORn =                   35, \
        GDMA0_Channel1_VECTORn =                   36, \
        GDMA0_Channel2_VECTORn =                   37, \
        GDMA0_Channel3_VECTORn =                   38, \
        GDMA0_Channel4_VECTORn =                   39, \
        GDMA0_Channel5_VECTORn =                   40, \
        GDMA0_Channel6_VECTORn =                   41, \
        GDMA0_Channel7_VECTORn =                   42, \
        GDMA0_Channel8_VECTORn =                   43, \
        GDMA0_Channel9_VECTORn =                   44, \
        PPE_VECTORn =                              45, \
        I2C0_VECTORn =                             46, \
        I2C1_VECTORn =                             47, \
        I2C2_VECTORn =                             48, \
        I2C3_VECTORn =                             49, \
        UART0_VECTORn =                            50, \
        UART1_VECTORn =                            51, \
        UART2_VECTORn =                            52, \
        UART3_VECTORn =                            53, \
        UART4_VECTORn =                            54, \
        UART5_VECTORn =                            55, \
        SPI_3Wire_VECTORn =                        56, \
        SPI0_VECTORn =                             57, \
        SPI1_VECTORn =                             58, \
        SPI_Slave_VECTORn =                        59, \
        Timer0_VECTORn =                           60, \
        Timer1_VECTORn =                           61, \
        Timer2_VECTORn =                           62, \
        Timer3_VECTORn =                           63, \
        Timer4_VECTORn =                           64, \
        Timer5_VECTORn =                           65, \
        Timer6_VECTORn =                           66, \
        Timer7_VECTORn =                           67, \
        Enhanced_Timer0_VECTORn =                  68, \
        Enhanced_Timer1_VECTORn =                  69, \
        Enhanced_Timer2_VECTORn =                  70, \
        Enhanced_Timer3_VECTORn =                  71, \
        ADC_24bit_VECTORn =                        72, \
        SAR_ADC_VECTORn =                          73, \
        KEYSCAN_VECTORn =                          74, \
        AON_QDEC_VECTORn =                         75, \
        IR_VECTORn =                               76, \
        SDIO_VECTORn =                             77, \
        ISO7816_VECTORn =                          78, \
        Display_VECTORn =                          79, \
        SPORT0_RX_VECTORn =                        80, \
        SPORT0_TX_VECTORn =                        81, \
        SPORT1_RX_VECTORn =                        82, \
        SPORT1_TX_VECTORn =                        83, \
        SHA256_VECTORn =                           84, \
        Public_Key_Engine_VECTORn =                85, \
        Flash_SEC_VECTORn =                        86, \
        SegCom_CTL_VECTORn =                       87, \
        A2C_VECTORn =                              88, \
        ETH_VECTORn =                              89, \
        IMDC_VECTORn =                             90, \
        Slave_Port_Monitor_VECTORn =               91, \
        PTA_Mailbox_VECTORn =                      92, \
        USB_VECTORn =                              93, \
        USB_SUSPEND_N_VECTORn =                    94, \
        USB_Endp_Muti_Proc_VECTORn =               95, \
        USB_IN_EP_0_VECTORn =                      96, \
        USB_IN_EP_1_VECTORn =                      97, \
        USB_IN_EP_2_VECTORn =                      98, \
        USB_IN_EP_3_VECTORn =                      99, \
        USB_IN_EP_4_VECTORn =                      100, \
        USB_IN_EP_5_VECTORn =                      101, \
        USB_OUT_EP_0_VECTORn =                     102, \
        USB_OUT_EP_1_VECTORn =                     103, \
        USB_OUT_EP_2_VECTORn =                     104, \
        USB_OUT_EP_3_VECTORn =                     105, \
        USB_OUT_EP_4_VECTORn =                     106, \
        USB_OUT_EP_5_VECTORn =                     107, \
        USB_Sof_VECTORn =                          108, \
        TMETER_VECTORn =                           109, \
        PF_RTC_VECTORn =                           110, \
        BTMAC_WRAP_AROUND_VECTORn =                111, \
        \
/* second level interrupt (BTMAC_ISR Status Register) */ \
        Timer_A0_A1_VECTORn =                      112, \
        BT_Bluewiz_VECTORn =                       113, \
        RSVD6_VECTORn =                            114, \
        BT_BZ_DMA_VECTORn =                        115, \
        Proprietary_protocol_VECTORn =             116, \
        RSVD7_VECTORn =                            117, \
        \
/* second level interrupt (Peripheral_ISR Status Register) */ \
        SPIC0_VECTORn =                            118, \
        SPIC1_VECTORn =                            119, \
        SPIC2_VECTORn =                            120, \
        TRNG_VECTORn =                             121, \
        LPCOMP_VECTORn =                           122, \
        SPI_PHY1_VECTORn =                         123, \
        RSVD8_VECTORn =                            124, \
        \
/* second level interrupt (GPIO_ISR Status Register) */ \
        GPIOA2_VECTORn =                           125, \
        GPIOA3_VECTORn =                           126, \
        GPIOA4_VECTORn =                           127, \
        GPIOA5_VECTORn =                           128, \
        GPIOA6_VECTORn =                           129, \
        GPIOA7_VECTORn =                           130, \
        GPIOA8_VECTORn =                           131, \
        GPIOA9_VECTORn =                           132, \
        GPIOA10_VECTORn =                          133, \
        GPIOA11_VECTORn =                          134, \
        GPIOA12_VECTORn =                          135, \
        GPIOA13_VECTORn =                          136, \
        GPIOA14_VECTORn =                          137, \
        GPIOA15_VECTORn =                          138, \
        GPIOA16_VECTORn =                          139, \
        GPIOA17_VECTORn =                          140, \
        GPIOA18_VECTORn =                          141, \
        GPIOA19_VECTORn =                          142, \
        GPIOA20_VECTORn =                          143, \
        GPIOA21_VECTORn =                          144, \
        GPIOA22_VECTORn =                          145, \
        GPIOA23_VECTORn =                          146, \
        GPIOA24_VECTORn =                          147, \
        GPIOA25_VECTORn =                          148, \
        GPIOA26_VECTORn =                          149, \
        GPIOA27_VECTORn =                          150, \
        GPIOA28_VECTORn =                          151, \
        GPIOA29_VECTORn =                          152, \
        GPIOA30_VECTORn =                          153, \
        GPIOA31_VECTORn =                          154, \
        GPIOB0_VECTORn =                           155, \
        GPIOB1_VECTORn =                           156, \
        GPIOB2_VECTORn =                           157, \
        GPIOB3_VECTORn =                           158, \
        GPIOB4_VECTORn =                           159, \
        GPIOB5_VECTORn =                           160, \
        GPIOB6_VECTORn =                           161, \
        GPIOB7_VECTORn =                           162, \
        GPIOB8_VECTORn =                           163, \
        GPIOB9_VECTORn =                           164, \
        GPIOB10_VECTORn =                          165, \
        GPIOB11_VECTORn =                          166, \
        GPIOB12_VECTORn =                          167, \
        GPIOB13_VECTORn =                          168, \
        GPIOB14_VECTORn =                          169, \
        GPIOB15_VECTORn =                          170, \
        GPIOB16_VECTORn =                          171, \
        GPIOB17_VECTORn =                          172, \
        GPIOB18_VECTORn =                          173, \
        GPIOB19_VECTORn =                          174, \
        GPIOB20_VECTORn =                          175, \
        GPIOB21_VECTORn =                          176, \
        GPIOB22_VECTORn =                          177, \
        GPIOB23_VECTORn =                          178, \
        GPIOB24_VECTORn =                          179, \
        GPIOB25_VECTORn =                          180, \
        GPIOB26_VECTORn =                          181, \
        GPIOB27_VECTORn =                          182, \
        GPIOB28_VECTORn =                          183, \
        GPIOB29_VECTORn =                          184, \
        GPIOB30_VECTORn =                          185, \
        GPIOB31_VECTORn =                          186, \
        MAX_VECTORn =                              187, \


#define Peripheral_First_VECTORn    SPIC0_VECTORn
#define Peripheral_Last_VECTORn     RSVD7_VECTORn

#define BTMAC_First_VECTORn         Timer_A0_A1_IRQn
#define BTMAC_Last_VECTORn          RSVD6_VECTORn

#define GPIOA_First_VECTORn         GPIOA2_VECTORn
#define GPIOA_Last_VECTORn          GPIOA31_VECTORn
#define GPIOB_First_VECTORn         GPIOB0_VECTORn
#define GPIOB_Last_VECTORn          GPIOB31_VECTORn

// *INDENT-ON* 
#endif //#define VECTOR_TABLE_AUTO_GEN_H
