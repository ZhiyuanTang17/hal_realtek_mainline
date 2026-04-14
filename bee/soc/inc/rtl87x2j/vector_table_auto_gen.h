#ifndef VECTOR_TABLE_AUTO_GEN_H
#define VECTOR_TABLE_AUTO_GEN_H

// *INDENT-OFF*
#include "stdint.h"
#include "stdbool.h"
#include "cmsis_compiler.h"

typedef void (*IRQ_Fun)(void);       // < ISR Handler Prototype

/* ================================================================================ */
/* ================                  IRQ_NUMBER                    ================ */
/* ======== Reference: Bee5_Vector_Table_20250822v0.xlsx   =========== */
/* ================================================================================ */

typedef enum IRQn
{
    NMI_IRQn =                             -14,
    HardFault_IRQn =                       -13,
    MemoryManagement_IRQn =                -12,
    BusFault_IRQn =                        -11,
    UsageFault_IRQn =                      -10,
    SecureFault_IRQn =                     -9,
    RSVD0_IRQn =                           -8,
    RSVD1_IRQn =                           -7,
    RSVD2_IRQn =                           -6,
    SVCall_IRQn =                          -5,
    Debug_Monitor_IRQn =                   -4,
    RSVD3_IRQn =                           -3,
    PendSV_IRQn =                          -2,
    SysTick_IRQn =                         -1,
    AON_IRQn =                             0,
    WDT_IRQn =                             1,
    RXI300_IRQn =                          2,
    BTMAC_0_IRQn =                         3,
    BTMAC_0_WRAP_AROUND_IRQn =             4,
    TIMER0_CH0_CH1_IRQn =                  5,
    BT_BZ_DMA_0_IRQn =                     6,
    PROPIETARY_2P4G_IRQn =                 7,
    RTC_IRQn =                             8,
    SCH_PLN_IRQn =                         9,
    I2S_0_RX_IRQn =                        10,
    I2S_0_TX_IRQn =                        11,
    TIMER1_CH0_IRQn =                      12,
    TIMER1_CH1_IRQn =                      13,
    TIMER1_CH2_IRQn =                      14,
    TIMER1_CH3_IRQn =                      15,
    TIMER1_CH4_IRQn =                      16,
    TIMER1_CH5_IRQn =                      17,
    TIMER1_CH6_IRQn =                      18,
    TIMER1_CH7_IRQn =                      19,
    TIMER1_CH8_IRQn =                      20,
    TIMER2_CH0_IRQn =                      21,
    RSVD4_IRQn =                           22,
    PERIPHERAL_ISR_IRQn =                  23,
    UART0_IRQn =                           24,
    UART1_IRQn =                           25,
    UART2_IRQn =                           26,
    UART3_IRQn =                           27,
    SPI_0_IRQn =                           28,
    SPI_1_IRQn =                           29,
    I2C_0_IRQn =                           30,
    I2C_1_IRQn =                           31,
    DMA0_CH0_IRQn =                        32,
    DMA0_CH1_IRQn =                        33,
    DMA0_CH2_IRQn =                        34,
    DMA0_CH3_IRQn =                        35,
    DMA0_CH4_IRQn =                        36,
    DMA0_CH5_IRQn =                        37,
    GPIOA0_7_IRQn =                        38,
    GPIOA8_15_IRQn =                       39,
    GPIOA16_23_IRQn =                      40,
    GPIOA24_31_IRQn =                      41,
    IR_IRQn =                              42,
    KEYSCAN_IRQn =                         43,
    LPQDEC_IRQn =                          44,
    ADC0_IRQn =                            45,
    SPI3W_IRQn =                           46,
    LPC_IRQn =                             47,
    MAILBOX_IRQn =                         48,
    TM_IRQn =                              49,
    A2C_IRQn =                             50,
    SHA256_IRQn =                          51,
    TRNG_IRQn =                            52,
    RAP_IRQn =                             53,
    MAE_IRQn =                             54,
    PPU0_IRQn =                            55,
    PPU1_IRQn =                            56,
    USB_IRQn =                             57,
    USB_ENDP_MULTI_PROC_INT_IRQn =         58,
    USB_SUSPEND_N_INT_IRQn =               59,
    USB_IN_EP_INT_0_IRQn =                 60,
    USB_IN_EP_INT_1_IRQn =                 61,
    USB_IN_EP_INT_2_IRQn =                 62,
    USB_IN_EP_INT_3_IRQn =                 63,
    USB_IN_EP_INT_4_IRQn =                 64,
    USB_IN_EP_INT_5_IRQn =                 65,
    USB_IN_EP_INT_6_IRQn =                 66,
    USB_OUT_EP_INT_0_IRQn =                67,
    USB_OUT_EP_INT_1_IRQn =                68,
    USB_OUT_EP_INT_2_IRQn =                69,
    USB_OUT_EP_INT_3_IRQn =                70,
    USB_OUT_EP_INT_4_IRQn =                71,
    USB_OUT_EP_INT_5_IRQn =                72,
    USB_OUT_EP_INT_6_IRQn =                73,
    USB_SOF_INT_IRQn =                     74,
    GPIOA32_39_IRQn =                      75,
    GPIOA40_47_IRQn =                      76,
    GPIOA48_55_IRQn =                      77,
    PAD_IRQn =                             78,
    SPI_2_IRQn =                           79,
    AUDIO_IRQn =                           80,
    TMETER_FW_IRQn =                       81,
    RXI300_EXT_IRQn =                      82,
    GRTC_CH0_IRQn =                        83,
    GRTC_CH1_IRQn =                        84,
    GRTC_CH2_IRQn =                        85,
    GRTC_CH3_IRQn =                        86,
    GRTC_CH4_IRQn =                        87,
    GRTC_CH5_IRQn =                        88,
    GRTC_CH6_IRQn =                        89,
    GRTC_CH7_IRQn =                        90,
    IRQn_MAX,
} IRQn_Type;

#define IRQn_TO_VECTORn(irqn)   ((irqn) + 16)

extern void *RomVectorTable[] ;
extern void *RamVectorTable[IRQn_TO_VECTORn(IRQn_MAX)];

void VTORInit(void);
void vector_table_ram_init(void);

// *INDENT-ON*
#endif //#define VECTOR_TABLE_AUTO_GEN_H
