#ifndef ADDRESS_MAP_H
#define ADDRESS_MAP_H

/* ================================================================================ */
/* ================                  Address Map                   ================ */
/* ======== Reference: Bee5_AddressMap_20241022v0.xlsx   ============ */
/* ================================================================================ */

#define CM33_ROM_BASE            0x0
#define CM33_RAM_BASE            0x200000
#define BUFFER_RAM_BASE          0x20100000
#define ICACHE_MEM_BASE          0x3000000
#define EFLASH_MEM_BASE          0x4000000
#define SPIC0_MEM_BASE           0x5000000
#define DATA_RAM_BASE            0x20000000
#define EFLASH_CTRL_BASE         0x40082000
#define SPIC0_BASE               0x40080000
#define SYSON_BASE               0x40000000
#define RXI350_CFG_BASE          0x40001000
#define PPU0_BASE                0x40002000
#define RXI300_BASE              0x40003000
#define SPI3W_BASE               0x40004000
#define KEY_SCAN_BASE            0x40004800
#define RXI300_EXT_BASE          0x40005000
#define SOC_VENDOR_REG_BASE      0x40006000
#define RAP_BASE                 0x40007000
#define MODEMRFCPI_BASE          0x40008000
#define AMU_BASE                 0x40200000
#define AUX_ADC_BASE             0x40010000
#define UART0_BASE               0x40011000
#define UART1_BASE               0x40011400
#define UART2_BASE               0x40011800
#define UART3_BASE               0x40011c00
#define SPI0_BASE                0x40012000
#define SPI1_BASE                0x40012400
#define SPI2_BASE                0x40012800
#define RSVD0_BASE               0x40012c00
#define RSVD1_BASE               0x40013000
#define ICACHE_CTRL_BASE         0x40013800
#define I2C0_BASE                0x40015000
#define I2C1_BASE                0x40015400
#define IR_RC_BASE               0x40015800
#define CAN_BASE                 0x40016000
#define ENHANCED_TIMER_BASE      0x40018000
#define GPIO0_BASE               0x4001a000
#define PPU1_BASE                0x4001b000
#define AES_BASE                 0x40020000
#define TIMER0_BASE              0x40022000
#define TIMER1_BASE              0x40024000
#define SPI_CODEC_BASE           0x40026000
#define I2S0_BASE                0x40029000
#define SHA256_BASE              0x4002a000
#define BLUEWIZ_BASE             0x40050000
#define RSVD2_BASE               0x40054000
#define PROPRIETARY_2P4G_BASE    0x40056000
#define BT_VENDOR_REG_BASE       0x40058000
#define SPI0_HS_BASE             0x40040000
#define SPI1_HS_BASE             0x40040400
#define SPI2_HS_BASE             0x40040800
#define USBOTG_CFG_BASE          0x40100000


#endif //#define ADDRESS_MAP_H 
