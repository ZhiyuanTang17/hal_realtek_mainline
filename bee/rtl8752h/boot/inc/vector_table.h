#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdbool.h"

typedef void (*IRQ_Fun)(void);       /**< ISR Handler Prototype */

extern uint32_t vector_table_level_two;

typedef enum
{
    InitialSP_VECTORn = 0,
    Reset_VECTORn,
    NMI_VECTORn,
    HardFault_VECTORn,
    RSVD_MemMang_VECTORn,
    RSVD_BusFault_VECTORn,
    RSVD_UsageFault_VECTORn,
    RSVD0_VECTORn,
    RSVD1_VECTORn,
    RSVD2_VECTORn,
    RSVD3_VECTORn,
    SVC_VECTORn,
    DebugMonitor_VECTORn,
    RSVD4_VECTORn,
    PendSV_VECTORn,
    SysTick_VECTORn,
    System_VECTORn = 16,
    TMETER_VECTORn,
    BTMAC_VECTORn,
    Timer3_VECTORn,
    Timer2_VECTORn,
    BTMAC_WRAP_AROUND_VECTORn,
    I2S0_TX_VECTORn,
    I2S0_RX_VECTORn,
    Timer4_5_VECTORn,
    ZIGBEE_VECTORn,
    PF_RTC_VECTORn,
    UART0_VECTORn,
    UART1_VECTORn,
    I8080_VECTORn,
    SPI0_VECTORn,
    SPI1_VECTORn,
    I2C0_VECTORn,
    I2C1_VECTORn,
    ADC_VECTORn,
    Peripheral_VECTORn,
    GDMA0_Channel0_VECTORn,
    GDMA0_Channel1_VECTORn,
    GDMA0_Channel2_VECTORn,
    GDMA0_Channel3_VECTORn,
    Enhanced_Timer0_VECTORn,
    Enhanced_Timer1_VECTORn,
    GPIO_Group3_VECTORn,
    GPIO_Group2_VECTORn,
    IR_VECTORn,
    GPIO_Group1_VECTORn,
    GPIO_Group0_VECTORn,
    UART2_VECTORn,
    Timer4_VECTORn,
    Timer5_VECTORn,
    SPIC0_VECTORn,
    Qdecode_VECTORn,
    Keyscan_VECTORn,
    SPI2W_VECTORn,
    LPCOMP_VECTORn,
    PTA_Mailbox_VECTORn,
    SPIC1_VECTORn,
    SHA256_VECTORn,
    Platform_VECTORn,
    TRNG_VECTORn,
    FLASH_SEC_VECTORn,
    RTC_VECTORn,
    WDT_VECTORn,
} VECTORn_Type;

/**
 * @brief  Initialize RAM vector table to a given RAM address.
 * @param  ram_vector_addr: RAM Vector Address.
 * @retval TRUE Success
 * @retval FALSE Fail
 * @note   When using vector table relocation, the base address of the new vector
 *         table must be aligned to the size of the vector table extended to the
 *         next larger power of 2. In RTL8762C, the base address is aligned at 0x100.
 */
extern bool RamVectorTableInit(uint32_t ram_vector_addr);

/**
 * @brief  Update ISR Handler in RAM Vector Table.
 * @param  v_num: Vector number(index)
 * @param  isr_handler: User defined ISR Handler.
 * @retval TRUE Success
 * @retval FALSE Fail
 */
extern bool RamVectorTableUpdate(VECTORn_Type v_num, IRQ_Fun isr_handler);

extern void ROM_Default_Handler(void);

extern void Reset_Handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void System_Handler(void);
extern void TMETER_Handler(void);
extern void BTMAC_Handler(void);
extern void Timer3_Handler(void);
extern void Timer2_Handler(void);
extern void BTMAC_WRAP_AROUND_Handler(void);
extern void I2S0_TX_Handler(void);
extern void I2S0_RX_Handler(void);
extern void Timer4_5_Handler(void);
extern void ZIGBEE_Handler(void);
extern void PF_RTC_Handler(void);
extern void UART0_Handler(void);
extern void UART1_Handler(void);
extern void I8080_Handler(void);
extern void SPI0_Handler(void);
extern void SPI1_Handler(void);
extern void I2C0_Handler(void);
extern void I2C1_Handler(void);
extern void ADC_Handler(void);
extern void Peripheral_Handler(void);
extern void GDMA0_Channel0_Handler(void);
extern void GDMA0_Channel1_Handler(void);
extern void GDMA0_Channel2_Handler(void);
extern void GDMA0_Channel3_Handler(void);
extern void Enhanced_Timer0_Handler(void);
extern void Enhanced_Timer1_Handler(void);
extern void GPIO_Group3_Handler(void);
extern void GPIO_Group2_Handler(void);
extern void IR_Handler(void);
extern void GPIO_Group1_Handler(void);
extern void GPIO_Group0_Handler(void);
extern void UART2_Handler(void);
extern void Timer4_Handler(void);
extern void Timer5_Handler(void);
extern void SPIC0_Handler(void);
extern void Qdecode_Handler(void);
extern void Keyscan_Handler(void);
extern void SPI2W_Handler(void);
extern void LPCOMP_Handler(void);
extern void PTA_Mailbox_Handler(void);
extern void SPIC1_Handler(void);
extern void SHA256_Handler(void);
extern void Platform_Handler(void);
extern void TRNG_Handler(void);
extern void FLASH_SEC_Handler(void);
extern void RTC_Handler(void);
extern void WDT_Handler(void);

extern void GPIO0_Handler(void);
extern void GPIO1_Handler(void);
extern void GPIO2_Handler(void);
extern void GPIO3_Handler(void);
extern void GPIO4_Handler(void);
extern void GPIO5_Handler(void);
extern void GPIO6_Handler(void);
extern void GPIO7_Handler(void);
extern void GPIO8_Handler(void);
extern void GPIO9_Handler(void);
extern void GPIO10_Handler(void);
extern void GPIO11_Handler(void);
extern void GPIO12_Handler(void);
extern void GPIO13_Handler(void);
extern void GPIO14_Handler(void);
extern void GPIO15_Handler(void);
extern void GPIO16_Handler(void);
extern void GPIO17_Handler(void);
extern void GPIO18_Handler(void);
extern void GPIO19_Handler(void);
extern void GPIO20_Handler(void);
extern void GPIO21_Handler(void);
extern void GPIO22_Handler(void);
extern void GPIO23_Handler(void);
extern void GPIO24_Handler(void);
extern void GPIO25_Handler(void);
extern void GPIO26_Handler(void);
extern void GPIO27_Handler(void);
extern void GPIO28_Handler(void);
extern void GPIO29_Handler(void);
extern void GPIO30_Handler(void);
extern void GPIO31_Handler(void);

#ifdef __cplusplus
}
#endif

#endif // VECTOR_TABLE_H
