/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ADDRESS_MAP_H
#define ADDRESS_MAP_H

/* ================================================================================ */
/* ================                  Address Map                   ================ */
/* ======== Reference: rtl87x2g_AddrMap_IRQs_DmaPorts_20220913v0.xlsx   ============ */
/* ================================================================================ */

#define SYSTEM_REG_BASE                    0x40000000UL
#define RTC_REG_BASE                       0x40001800UL
#define LPC_REG_BASE                       0x40001850UL
#define LPC0_REG_BASE                      0x40001850UL
#define PAD_REG_BASE                       0x40001900UL
#define PAD_STS_REG_BASE                   0x40001AA0UL
#define AON_WDT_REG_BASE                   0x40001B60UL
#define AUXADC_REG_BASE                    0x40001B90UL
#define QUAD_DECODER_REG_BASE              0x40001BD0UL
#define PERI_ON_REG_BASE                   0x40002000UL
#define PERI_ON_RCC_REG_BASE               0x40002300UL
#define GPIOA_DEB_REG_BASE                 0x4000234CUL
#define GPIOB_DEB_REG_BASE                 0x40002360UL
#define TIMER_PWM_REG_BASE                 0x4000233CUL
#define PINMUX_REG_BASE                    0x40002500UL
#define QDEC_REG_BASE                      0x40009000UL
#define SPI0_REG_BASE                      0x40013000UL
#define SPI1_REG_BASE                      0x40013400UL
#define SPI_SLAVE_REG_BASE                 0x40013800UL
#define ENHANCED_TIMER_REG_BASE            0x40017000UL
#define MODEMRFCPI_REG_BASE                0x40018000UL
#define I2S0_REG_BASE                      0x40020000UL
#define I2S1_REG_BASE                      0x40021000UL
#define SPI_CODEC_REG_BASE                 0x40022000UL
#define DISPLAY_CTRL_REG_BASE              0x40023000UL
#define RXI350_DMAC0_CFG_REG_BASE          0x40024000UL
#define PPE_CFG_REG_BASE                   0x40025000UL
#define ISO7816_REG_BASE                   0x40026000UL
#define SEGCOM_CTL_REG_BASE                0x40027000UL
#define A2C_REG_BASE                       0x40028000UL
#define SPIC_PHY_REG_BASE                  0x40029000UL

#define PUBLIC_KEY_ENGINE_REG_BASE         0x40080000UL
#define FLASH_SEC_REG_BASE                 0x400C0000UL
#define AES_REG_BASE                       0x400C1000UL
#define SHA256_REG_BASE                    0x400C2000UL
#define TRNG_REG_BASE                      0x400C2400UL
#define EFUSE_CONTROLLER_REG_BASE          0x400C2800UL
#define USB_OTG_CFG_REG_BASE               0x40100000UL
#define SPIC0_REG_BASE                     0x40140000UL
#define SDHC_REG_BASE                      0x40150000UL
#define SPIC1_REG_BASE                     0x40160000UL
#define SPIC2_REG_BASE                     0x40170000UL
#define GPIOA_REG_BASE                     0x40030000UL
#define GPIOB_REG_BASE                     0x40030800UL
#define TIMER_REG_BASE                     0x40031000UL
#define SAR_ADC_REG_BASE                   0x40032000UL
#define HRADC_REG_BASE                     0x40033000UL
#define UART0_REG_BASE                     0x40034000UL
#define UART1_REG_BASE                     0x40034400UL
#define UART2_REG_BASE                     0x40034800UL
#define UART3_REG_BASE                     0x40034C00UL
#define UART4_REG_BASE                     0x40035000UL
#define UART5_REG_BASE                     0x40035400UL
#define I2C0_REG_BASE                      0x40035800UL
#define I2C1_REG_BASE                      0x40035C00UL
#define I2C2_REG_BASE                      0x40036000UL
#define I2C3_REG_BASE                      0x40036400UL
#define SPI3W_REG_BASE                     0x40036800UL
#define KEYSCAN_REG_BASE                   0x40037000UL
#define IR_RC_REG_BASE                     0x40038000UL
#define ETH_CTRL_REG_BASE                  0x40040000UL
#define BLUEWIZ_REG_BASE                   0x40050000UL
#define BT_DMA_UART_BASE                   0x40051000UL
#define BT_DMA_BASE                        0x40055000UL
#define BT_VENDOR_REG_BASE                 0x40058000UL
#define ZIGBEE_REG_BASE                    0x4005C000UL
#define SPI0_HS_REG_BASE                   0x40060000UL
#define IMDC_REG_BASE                      0x40070000UL


#endif //#define ADDRESS_MAP_H 
