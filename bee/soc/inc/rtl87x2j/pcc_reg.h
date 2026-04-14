#ifndef PCC_REG_H
#define PCC_REG_H
#include <stdint.h>

/* ================================================================================ */
/* ================                PCC Register               ================ */
/* ===========     Reference: RL7019_SYSON_auto_gen_table_20251107A.xlsx     =========== */
/* ================================================================================ */
#define PCC_REG_PERION_CLK_REG0X        0x200
#define PCC_REG_PERION_CLK_REG1X        0x204
#define PCC_REG_PERION_CLK_REG2X        0x208
#define PCC_REG_PERION_CLK_REG3X        0x20C
#define PCC_REG_PERION_CLK_REG4X        0x210
#define PCC_REG_PERION_CLK_REG5X        0x214
#define PCC_REG_TRNG                    0x218
#define PCC_REG_CORE_WDT                0x21C
#define PCC_REG_AES                     0x220
#define PCC_REG_SHA256                  0x224
#define PCC_REG_MODEMRFCPI              0x228
#define PCC_REG_DMA                     0x22C
#define PCC_REG_SPIC                    0x230
#define PCC_REG_SPI0                    0x234
#define PCC_REG_SPI1                    0x238
#define PCC_REG_SPI2                    0x23C
#define PCC_REG_I2S0                    0x240
#define PCC_REG_TIMER0                  0x244
#define PCC_REG_TIMER1_A                0x248
#define PCC_REG_TIMER1_B                0x24C
#define PCC_REG_TIMER1_C                0x250
#define PCC_REG_TIMER2                  0x254
#define PCC_REG_TIMER2_PWM              0x258
#define PCC_REG_USB                     0x25C
#define PCC_REG_ADC_CONTROLLER          0x260
#define PCC_REG_I2C0                    0x264
#define PCC_REG_I2C1                    0x268
#define PCC_REG_Keyscan                 0x26C
#define PCC_REG_SPI3W                   0x270
#define PCC_REG_EFLASH                  0x274
#define PCC_REG_CAN                     0x278
#define PCC_REG_GPIO_DEBOUNCE_2P4G      0x27C
#define PCC_REG_UART0                   0x280
#define PCC_REG_UART1                   0x284
#define PCC_REG_UART2                   0x288
#define PCC_REG_UART3                   0x28C
#define PCC_REG_GPIOA                   0x290
#define PCC_REG_MODEM                   0x294
#define PCC_REG_PROPRIETARY             0x298
#define PCC_REG_IR                      0x29C
#define PCC_REG_BT_VDREG                0x2A0
#define PCC_REG_AUDIO                   0x2A4
#define PCC_REG_LXBUS                   0x2A8
#define PCC_REG_CAL32K                  0x2AC
#define PCC_REG_PLATFORM                0x2B0
#define PCC_REG_PCC                     0x2B4
#define PCC_REG_TMETER                  0x2B8
#define PCC_REG_TIMER1_D                0x2BC
#define PCC_REG_CAL80M                  0x8F0
#define PCC_REG_CAL10M                  0x8F4
#define PCC_REG_VDREG                   0x8F8
#define PCC_REG_CPU                     0x8FC
#define PCC_REG_SYSON                   0x900
#define PCC_REG_HCI                     0x904
#define PCC_REG_BT_OTHER0               0x908
#define PCC_REG_TIMER0_PCLK             0x90C
#define PCC_REG_TIMER1_PCLK             0x910
#define PCC_REG_ETIMER_PCLK             0x914
#define PCC_REG_OSC128K_CAL             0x918
#define PCC_REG_RXI300                  0x91C
#define PCC_REG_AON_DEB_TOP             0x920
#define PCC_REG_OTHERS                  0x924
#define PCC_REG_PERION_CLK_VPON_REG0X   0x3C4
#define PCC_REG_PERION_CLK_VPON_REG1X   0x3C8
#define PCC_REG_PERION_CLK_VPON_REG2X   0x3CC
#define PCC_REG_LPPWM                   0x3D0
#define PCC_REG_LPQDEC                  0x3D4
#define PCC_REG_GRTC                    0x3D8
#define PCC_REG_BLUEWIZ                 0x3DC
#define PCC_REG_USER_RTC                0x3E0
#define PCC_REG_RAP                     0x3E4
#define PCC_REG_GTC                     0x3E8
#define PCC_REG_SDM_VPON                0x3EC
#define PCC_REG_LPWDT_VPON              0x3F0
#define PCC_REG_PERION_CLK_AON_REG0X    0x3F4
#define PCC_REG_PCK600                  0x3F8
#define PCC_REG_LPC                     0x3FC
#define PCC_r_PMUX_GPIO_P0_0to3         0x2C0
#define PCC_r_PMUX_GPIO_P0_4to7         0x2C4
#define PCC_r_PMUX_GPIO_P1_0to7         0x2C8
#define PCC_r_PMUX_GPIO_P2_0to3         0x2CC
#define PCC_r_PMUX_GPIO_P2_4to7         0x2D0
#define PCC_r_PMUX_GPIO_P3_0to3         0x2D4
#define PCC_r_PMUX_GPIO_P3_4to6         0x2D8
#define PCC_r_PMUX_GPIO_P4_0to3         0x2DC
#define PCC_r_PMUX_GPIO_H_0to2          0x2E0
#define PCC_REG_PMUX_GPIO_6_0to3        0x2E4
#define PCC_REG_PMUX_GPIO_6_4to7        0x2E8
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1 0x2EC
#define PCC_REG_PMUX_GPIO_SPIC_2        0x2F0
#define PCC_r_PMUX_TEST_MODE            0x2F4
#define PCC_REG_BC12_CTRL1              0x2F8
#define PCC_REG_BC12_CTRL2              0x2FC
#define PCC_REG_BC12_CTRL3              0x300
#define PCC_REG_BC12_CTRL4              0x304
#define PCC_REG_BC12_CTRL5              0x308
#define PCC_REG_BC12_CTRL6              0x30C
#define PCC_REG_DBG_MUX_CTRL            0x310
#define PCC_REG_RSVD_2D8                0x314
#define PCC_REG_SWITCH_PAR              0x318
#define PCC_REG_PINMUX_DBG_REG          0x31C
#define PCC_LDO_PA_SWR_AUTO_SW          0x320
#define PCC_CORE_SWR_PAR_TAB_0_0        0x324
#define PCC_CORE_SWR_PAR_TAB_4_0        0x328
#define PCC_CORE_SWR_PAR_TAB_5_0        0x32C
#define PCC_CORE_SWR_PAR_TAB_6_0        0x330
#define PCC_CORE_SWR_PAR_TAB_7_0        0x334
#define PCC_REG_CORE_PAR                0x338
#define PCC_PON_PERI_DLYSEL_CTRL        0x33C
#define PCC_REG_DSS_CTRL0               0x340
#define PCC_REG_DSS_CTRL1               0x344
#define PCC_REG_DSS_CTRL2               0x348
#define PCC_REG_OSC40_CTRL              0x34C
#define PCC_REG_AAC_0                   0x350
#define PCC_REG_AAC_1                   0x354
#define PCC_REG_XTAL_PLL                0x358
#define PCC_REG_XTALPDCK                0x35C
#define PCC_REG_PADMUX_AS_CFG0          0x360
#define PCC_REG_PADMUX_AS_CFG1          0x364
#define PCC_REG_PADMUX_AS_CFG2          0x368
#define PCC_REG_PADMUX_AS_CFG3          0x36C
#define PCC_REG_PADMUX_AS_CFG4          0x370
#define PCC_REG_PADMUX_AS_CFG5          0x374
#define PCC_REG_PADMUX_AS_CFG6          0x378
#define PCC_REG_PADMUX_AS_CFG7          0x37C
#define PCC_REG_PADMUX_AS_CFG8          0x380
#define PCC_REG_PADMUX_AS_CFG9          0x384
#define PCC_REG_PADMUX_AS_CFG10         0x388
#define PCC_REG_QCH_BUSY_FLAG1_PROC1    0x38C
#define PCC_REG_QCH_BUSY_FLAG1_PROC2    0x390
#define PCC_REG_QCH_BUSY_FLAG0_PROC0    0x394
#define PCC_REG_QCH_BUSY_FLAG0_PROC1    0x398
#define PCC_REG_QCH_BUSY_FLAG0_PROC2    0x39C
#define PCC_REG_QCH_BUSY_FLAG1          0x3A0
#define PCC_REG_QCH_BUSY_FLAG0          0x3A4
#define PCC_REG_USB_POW                 0x3A8
#define PCC_REG_DUMMY_3AC               0x3AC
#define PCC_REG_DUMMY_3B0               0x3B0
#define PCC_REG_DUMMY_3B4               0x3B4
#define PCC_REG_DBG_MUX_PCK             0x3B8
#define PCC_REG_DBG_MUX_GRP_CFG0        0x3BC
#define PCC_REG_DBG_MUX_GRP_CFG1        0x3C0

/* 0x200    0x4000_0200
    0       R/W     RESERVED                                        1'b0
    1       W1O     REG_ZONE1_WRP_EN                                1'b0
    2       W1O     REG_ZONE2_WRP_EN                                1'b0
    3       W1O     REG_WRP_LOCK                                    1'b0
    9:4     R/W     R_BT_AHB_WAIT_CNT                               6'h0C
    10      R/W     R_AON_RD_OPT                                    1'b1
    11      R/W     R_BTAON_ACC_NO_BLOCK                            1'b0
    12      R       CLKEN_O_UART0                                   1'h0
    13      R       CLKEN_O_UART1                                   1'h0
    14      R       CLKEN_O_UART2                                   1'h0
    15      R       CLKEN_O_UART3                                   1'h0
    16      R       CLKEN_O_IRRC                                    1'h0
    17      R       CLKEN_O_AUDIO                                   1'h0
    18      R       CLKEN_O_TIMER1                                  1'h0
    19      R       CLKEN_O_TIMER2                                  1'h0
    20      R       CLKEN_O_TIMER3                                  1'h0
    21      R       CLKEN_O_TIMER4                                  1'h0
    22      R       CLKEN_O_TIMER5                                  1'h0
    23      R       CLKEN_O_TIMER6                                  1'h0
    24      R       CLKEN_O_TIMER7                                  1'h0
    25      R       CLKEN_O_TIMER8                                  1'h0
    26      R       CLKEN_O_TIMER9                                  1'h0
    27      R       CLKEN_O_TIMER10                                 1'h0
    28      R       CLKEN_O_TIMER11                                 1'h0
    29      R       CLKEN_O_ETIMER                                  1'h0
    30      R       CLKEN_O_RFC                                     1'h0
    31      R       CLKEN_O_MODEM                                   1'h0
 */
typedef union _PCC_REG_PERION_CLK_REG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED: 1;
        uint32_t REG_ZONE1_WRP_EN: 1;
        uint32_t REG_ZONE2_WRP_EN: 1;
        uint32_t REG_WRP_LOCK: 1;
        uint32_t R_BT_AHB_WAIT_CNT: 6;
        uint32_t R_AON_RD_OPT: 1;
        uint32_t R_BTAON_ACC_NO_BLOCK: 1;
        uint32_t CLKEN_O_UART0: 1;
        uint32_t CLKEN_O_UART1: 1;
        uint32_t CLKEN_O_UART2: 1;
        uint32_t CLKEN_O_UART3: 1;
        uint32_t CLKEN_O_IRRC: 1;
        uint32_t CLKEN_O_AUDIO: 1;
        uint32_t CLKEN_O_TIMER1: 1;
        uint32_t CLKEN_O_TIMER2: 1;
        uint32_t CLKEN_O_TIMER3: 1;
        uint32_t CLKEN_O_TIMER4: 1;
        uint32_t CLKEN_O_TIMER5: 1;
        uint32_t CLKEN_O_TIMER6: 1;
        uint32_t CLKEN_O_TIMER7: 1;
        uint32_t CLKEN_O_TIMER8: 1;
        uint32_t CLKEN_O_TIMER9: 1;
        uint32_t CLKEN_O_TIMER10: 1;
        uint32_t CLKEN_O_TIMER11: 1;
        uint32_t CLKEN_O_ETIMER: 1;
        uint32_t CLKEN_O_RFC: 1;
        uint32_t CLKEN_O_MODEM: 1;
    };
} PCC_REG_PERION_CLK_REG0X_TYPE;

/*0x4000_0200 PCC_REG_PERION_CLK_REG0X*/
#define PCC_REG_PERION_CLK_REG0X_RESERVED_Pos                                                    0U
#define PCC_REG_PERION_CLK_REG0X_RESERVED_Msk                                                    (0x1UL << PCC_REG_PERION_CLK_REG0X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG0X_REG_ZONE1_WRP_EN_Pos                                            1U
#define PCC_REG_PERION_CLK_REG0X_REG_ZONE1_WRP_EN_Msk                                            (0x1UL << PCC_REG_PERION_CLK_REG0X_REG_ZONE1_WRP_EN_Pos)

#define PCC_REG_PERION_CLK_REG0X_REG_ZONE2_WRP_EN_Pos                                            2U
#define PCC_REG_PERION_CLK_REG0X_REG_ZONE2_WRP_EN_Msk                                            (0x1UL << PCC_REG_PERION_CLK_REG0X_REG_ZONE2_WRP_EN_Pos)

#define PCC_REG_PERION_CLK_REG0X_REG_WRP_LOCK_Pos                                                3U
#define PCC_REG_PERION_CLK_REG0X_REG_WRP_LOCK_Msk                                                (0x1UL << PCC_REG_PERION_CLK_REG0X_REG_WRP_LOCK_Pos)

#define PCC_REG_PERION_CLK_REG0X_R_BT_AHB_WAIT_CNT_Pos                                           4U
#define PCC_REG_PERION_CLK_REG0X_R_BT_AHB_WAIT_CNT_Msk                                           (0x3FUL << PCC_REG_PERION_CLK_REG0X_R_BT_AHB_WAIT_CNT_Pos)

#define PCC_REG_PERION_CLK_REG0X_R_AON_RD_OPT_Pos                                                10U
#define PCC_REG_PERION_CLK_REG0X_R_AON_RD_OPT_Msk                                                (0x1UL << PCC_REG_PERION_CLK_REG0X_R_AON_RD_OPT_Pos)

#define PCC_REG_PERION_CLK_REG0X_R_BTAON_ACC_NO_BLOCK_Pos                                        11U
#define PCC_REG_PERION_CLK_REG0X_R_BTAON_ACC_NO_BLOCK_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG0X_R_BTAON_ACC_NO_BLOCK_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART0_Pos                                               12U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART0_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART0_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART1_Pos                                               13U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART1_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART1_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART2_Pos                                               14U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART2_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART2_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART3_Pos                                               15U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART3_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_UART3_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_IRRC_Pos                                                16U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_IRRC_Msk                                                (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_IRRC_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_AUDIO_Pos                                               17U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_AUDIO_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_AUDIO_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER1_Pos                                              18U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER1_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER1_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER2_Pos                                              19U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER2_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER2_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER3_Pos                                              20U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER3_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER3_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER4_Pos                                              21U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER4_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER4_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER5_Pos                                              22U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER5_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER5_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER6_Pos                                              23U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER6_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER6_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER7_Pos                                              24U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER7_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER7_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER8_Pos                                              25U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER8_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER8_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER9_Pos                                              26U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER9_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER9_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER10_Pos                                             27U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER10_Msk                                             (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER10_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER11_Pos                                             28U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER11_Msk                                             (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_TIMER11_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_ETIMER_Pos                                              29U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_ETIMER_Msk                                              (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_ETIMER_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_RFC_Pos                                                 30U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_RFC_Msk                                                 (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_RFC_Pos)

#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_MODEM_Pos                                               31U
#define PCC_REG_PERION_CLK_REG0X_CLKEN_O_MODEM_Msk                                               (0x1UL << PCC_REG_PERION_CLK_REG0X_CLKEN_O_MODEM_Pos)

/* 0x204    0x4000_0204
    3:0     R       RF_RL_ID                                        4'd0
    7:4     R       RF_RTL_ID                                       4'd0
    27:8    R       RESERVED                                        20'h0
    30:28   R/W     DUMMY2                                          3'b0
    31      R/W     VCORE_STATUS_CHECK                              1'b0
 */
typedef union _PCC_REG_PERION_CLK_REG1X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RF_RL_ID: 4;
        uint32_t RF_RTL_ID: 4;
        uint32_t RESERVED: 20;
        uint32_t DUMMY2: 3;
        uint32_t VCORE_STATUS_CHECK: 1;
    };
} PCC_REG_PERION_CLK_REG1X_TYPE;

/*0x4000_0204 PCC_REG_PERION_CLK_REG1X*/
#define PCC_REG_PERION_CLK_REG1X_RF_RL_ID_Pos                                                    0U
#define PCC_REG_PERION_CLK_REG1X_RF_RL_ID_Msk                                                    (0xFUL << PCC_REG_PERION_CLK_REG1X_RF_RL_ID_Pos)

#define PCC_REG_PERION_CLK_REG1X_RF_RTL_ID_Pos                                                   4U
#define PCC_REG_PERION_CLK_REG1X_RF_RTL_ID_Msk                                                   (0xFUL << PCC_REG_PERION_CLK_REG1X_RF_RTL_ID_Pos)

#define PCC_REG_PERION_CLK_REG1X_RESERVED_Pos                                                    8U
#define PCC_REG_PERION_CLK_REG1X_RESERVED_Msk                                                    (0xFFFFFUL << PCC_REG_PERION_CLK_REG1X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG1X_DUMMY2_Pos                                                      28U
#define PCC_REG_PERION_CLK_REG1X_DUMMY2_Msk                                                      (0x7UL << PCC_REG_PERION_CLK_REG1X_DUMMY2_Pos)

#define PCC_REG_PERION_CLK_REG1X_VCORE_STATUS_CHECK_Pos                                          31U
#define PCC_REG_PERION_CLK_REG1X_VCORE_STATUS_CHECK_Msk                                          (0x1UL << PCC_REG_PERION_CLK_REG1X_VCORE_STATUS_CHECK_Pos)

/* 0x208    0x4000_0208
    0       R/W     HCLK_AUTO_SLOW_EN                               1'b0
    8:1     R/W     HCLK_AUTO_SLOW_OP1_EVNT                         8'b0
    11:9    R/W     HCLK_DIV_SEL                                    3'h0
    12      R       MODEM_CLK_SWITCH_DONE                           1'h1
    13      R/W     MODEM_CK_40M_GATE_EN                            1'h0
    14      R/W     MODEM_CK_FORCE_LOW                              1'h0
    16:15   R/W     R_PLATFORM_DIV_SEL                              2'b00
    19:17   R/W     RESERVED_2                                      3'b000
    20      R/W     RESERVED_1                                      1'b0
    21      R/W     RESERVED                                        1'b0
    22      R/W     R_CLK_SYSTICK_EN                                1'b1
    23      R/W     R_10M_SYSTICK_CLK_SRC_SEL                       1'b1
    24      R/W     R_40M_AUDIO_CLK_SRC_SEL                         1'b1
    25      R/W     R_TIMER_CLK_F40M_SRC_SEL                        1'b1
    26      R/W     R_UART_CLK_SRC_SEL                              1'b1
    31:27   R/W     DUMMY3                                          5'b0
 */
typedef union _PCC_REG_PERION_CLK_REG2X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t HCLK_AUTO_SLOW_EN: 1;
        uint32_t HCLK_AUTO_SLOW_OP1_EVNT: 8;
        uint32_t HCLK_DIV_SEL: 3;
        uint32_t MODEM_CLK_SWITCH_DONE: 1;
        uint32_t MODEM_CK_40M_GATE_EN: 1;
        uint32_t MODEM_CK_FORCE_LOW: 1;
        uint32_t R_PLATFORM_DIV_SEL: 2;
        uint32_t RESERVED_2: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t R_CLK_SYSTICK_EN: 1;
        uint32_t R_10M_SYSTICK_CLK_SRC_SEL: 1;
        uint32_t R_40M_AUDIO_CLK_SRC_SEL: 1;
        uint32_t R_TIMER_CLK_F40M_SRC_SEL: 1;
        uint32_t R_UART_CLK_SRC_SEL: 1;
        uint32_t DUMMY3: 5;
    };
} PCC_REG_PERION_CLK_REG2X_TYPE;

/*0x4000_0208 PCC_REG_PERION_CLK_REG2X*/
#define PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_EN_Pos                                           0U
#define PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_EN_Msk                                           (0x1UL << PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_EN_Pos)

#define PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_OP1_EVNT_Pos                                     1U
#define PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_OP1_EVNT_Msk                                     (0xFFUL << PCC_REG_PERION_CLK_REG2X_HCLK_AUTO_SLOW_OP1_EVNT_Pos)

#define PCC_REG_PERION_CLK_REG2X_HCLK_DIV_SEL_Pos                                                9U
#define PCC_REG_PERION_CLK_REG2X_HCLK_DIV_SEL_Msk                                                (0x7UL << PCC_REG_PERION_CLK_REG2X_HCLK_DIV_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_MODEM_CLK_SWITCH_DONE_Pos                                       12U
#define PCC_REG_PERION_CLK_REG2X_MODEM_CLK_SWITCH_DONE_Msk                                       (0x1UL << PCC_REG_PERION_CLK_REG2X_MODEM_CLK_SWITCH_DONE_Pos)

#define PCC_REG_PERION_CLK_REG2X_MODEM_CK_40M_GATE_EN_Pos                                        13U
#define PCC_REG_PERION_CLK_REG2X_MODEM_CK_40M_GATE_EN_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG2X_MODEM_CK_40M_GATE_EN_Pos)

#define PCC_REG_PERION_CLK_REG2X_MODEM_CK_FORCE_LOW_Pos                                          14U
#define PCC_REG_PERION_CLK_REG2X_MODEM_CK_FORCE_LOW_Msk                                          (0x1UL << PCC_REG_PERION_CLK_REG2X_MODEM_CK_FORCE_LOW_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_PLATFORM_DIV_SEL_Pos                                          15U
#define PCC_REG_PERION_CLK_REG2X_R_PLATFORM_DIV_SEL_Msk                                          (0x3UL << PCC_REG_PERION_CLK_REG2X_R_PLATFORM_DIV_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_RESERVED_2_Pos                                                  17U
#define PCC_REG_PERION_CLK_REG2X_RESERVED_2_Msk                                                  (0x7UL << PCC_REG_PERION_CLK_REG2X_RESERVED_2_Pos)

#define PCC_REG_PERION_CLK_REG2X_RESERVED_1_Pos                                                  20U
#define PCC_REG_PERION_CLK_REG2X_RESERVED_1_Msk                                                  (0x1UL << PCC_REG_PERION_CLK_REG2X_RESERVED_1_Pos)

#define PCC_REG_PERION_CLK_REG2X_RESERVED_Pos                                                    21U
#define PCC_REG_PERION_CLK_REG2X_RESERVED_Msk                                                    (0x1UL << PCC_REG_PERION_CLK_REG2X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_CLK_SYSTICK_EN_Pos                                            22U
#define PCC_REG_PERION_CLK_REG2X_R_CLK_SYSTICK_EN_Msk                                            (0x1UL << PCC_REG_PERION_CLK_REG2X_R_CLK_SYSTICK_EN_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_10M_SYSTICK_CLK_SRC_SEL_Pos                                   23U
#define PCC_REG_PERION_CLK_REG2X_R_10M_SYSTICK_CLK_SRC_SEL_Msk                                   (0x1UL << PCC_REG_PERION_CLK_REG2X_R_10M_SYSTICK_CLK_SRC_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_40M_AUDIO_CLK_SRC_SEL_Pos                                     24U
#define PCC_REG_PERION_CLK_REG2X_R_40M_AUDIO_CLK_SRC_SEL_Msk                                     (0x1UL << PCC_REG_PERION_CLK_REG2X_R_40M_AUDIO_CLK_SRC_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_TIMER_CLK_F40M_SRC_SEL_Pos                                    25U
#define PCC_REG_PERION_CLK_REG2X_R_TIMER_CLK_F40M_SRC_SEL_Msk                                    (0x1UL << PCC_REG_PERION_CLK_REG2X_R_TIMER_CLK_F40M_SRC_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_R_UART_CLK_SRC_SEL_Pos                                          26U
#define PCC_REG_PERION_CLK_REG2X_R_UART_CLK_SRC_SEL_Msk                                          (0x1UL << PCC_REG_PERION_CLK_REG2X_R_UART_CLK_SRC_SEL_Pos)

#define PCC_REG_PERION_CLK_REG2X_DUMMY3_Pos                                                      27U
#define PCC_REG_PERION_CLK_REG2X_DUMMY3_Msk                                                      (0x1FUL << PCC_REG_PERION_CLK_REG2X_DUMMY3_Pos)

/* 0x20C    0x4000_020c
    23:0    R/W     RESERVED                                        24'h0
    31:24   R/W     DUMMY4                                          8'h0
 */
typedef union _PCC_REG_PERION_CLK_REG3X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED: 24;
        uint32_t DUMMY4: 8;
    };
} PCC_REG_PERION_CLK_REG3X_TYPE;

/*0x4000_020c PCC_REG_PERION_CLK_REG3X*/
#define PCC_REG_PERION_CLK_REG3X_RESERVED_Pos                                                    0U
#define PCC_REG_PERION_CLK_REG3X_RESERVED_Msk                                                    (0xFFFFFFUL << PCC_REG_PERION_CLK_REG3X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG3X_DUMMY4_Pos                                                      24U
#define PCC_REG_PERION_CLK_REG3X_DUMMY4_Msk                                                      (0xFFUL << PCC_REG_PERION_CLK_REG3X_DUMMY4_Pos)

/* 0x210    0x4000_0210
    0       R/W     R_LS_MCU_ROM                                    1'b0
    1       R/W     R_CODEC_STANDALONE                              1'b0
    11:2    R/W     RESERVED                                        10'h0
    12      R/W     FORCE_QACTIVE_UART0                             1'h0
    13      R/W     FORCE_QACTIVE_UART1                             1'h0
    14      R/W     FORCE_QACTIVE_UART2                             1'h0
    15      R/W     FORCE_QACTIVE_UART3                             1'h0
    16      R/W     FORCE_QACTIVE_IRRC                              1'h0
    17      R/W     FORCE_QACTIVE_AUDIO                             1'h0
    18      R/W     FORCE_QACTIVE_TIMER1                            1'h0
    19      R/W     FORCE_QACTIVE_TIMER2                            1'h0
    20      R/W     FORCE_QACTIVE_TIMER3                            1'h0
    21      R/W     FORCE_QACTIVE_TIMER4                            1'h0
    22      R/W     FORCE_QACTIVE_TIMER5                            1'h0
    23      R/W     FORCE_QACTIVE_TIMER6                            1'h0
    24      R/W     FORCE_QACTIVE_TIMER7                            1'h0
    25      R/W     FORCE_QACTIVE_TIMER8                            1'h0
    26      R/W     FORCE_QACTIVE_TIMER9                            1'h0
    27      R/W     FORCE_QACTIVE_TIMER10                           1'h0
    28      R/W     FORCE_QACTIVE_TIMER11                           1'h0
    29      R/W     FORCE_QACTIVE_ETIMER                            1'h0
    30      R/W     FORCE_QACTIVE_RFC                               1'h0
    31      R/W     FORCE_QACTIVE_MODEM                             1'h0
 */
typedef union _PCC_REG_PERION_CLK_REG4X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_LS_MCU_ROM: 1;
        uint32_t R_CODEC_STANDALONE: 1;
        uint32_t RESERVED: 10;
        uint32_t FORCE_QACTIVE_UART0: 1;
        uint32_t FORCE_QACTIVE_UART1: 1;
        uint32_t FORCE_QACTIVE_UART2: 1;
        uint32_t FORCE_QACTIVE_UART3: 1;
        uint32_t FORCE_QACTIVE_IRRC: 1;
        uint32_t FORCE_QACTIVE_AUDIO: 1;
        uint32_t FORCE_QACTIVE_TIMER1: 1;
        uint32_t FORCE_QACTIVE_TIMER2: 1;
        uint32_t FORCE_QACTIVE_TIMER3: 1;
        uint32_t FORCE_QACTIVE_TIMER4: 1;
        uint32_t FORCE_QACTIVE_TIMER5: 1;
        uint32_t FORCE_QACTIVE_TIMER6: 1;
        uint32_t FORCE_QACTIVE_TIMER7: 1;
        uint32_t FORCE_QACTIVE_TIMER8: 1;
        uint32_t FORCE_QACTIVE_TIMER9: 1;
        uint32_t FORCE_QACTIVE_TIMER10: 1;
        uint32_t FORCE_QACTIVE_TIMER11: 1;
        uint32_t FORCE_QACTIVE_ETIMER: 1;
        uint32_t FORCE_QACTIVE_RFC: 1;
        uint32_t FORCE_QACTIVE_MODEM: 1;
    };
} PCC_REG_PERION_CLK_REG4X_TYPE;

/*0x4000_0210 PCC_REG_PERION_CLK_REG4X*/
#define PCC_REG_PERION_CLK_REG4X_R_LS_MCU_ROM_Pos                                                0U
#define PCC_REG_PERION_CLK_REG4X_R_LS_MCU_ROM_Msk                                                (0x1UL << PCC_REG_PERION_CLK_REG4X_R_LS_MCU_ROM_Pos)

#define PCC_REG_PERION_CLK_REG4X_R_CODEC_STANDALONE_Pos                                          1U
#define PCC_REG_PERION_CLK_REG4X_R_CODEC_STANDALONE_Msk                                          (0x1UL << PCC_REG_PERION_CLK_REG4X_R_CODEC_STANDALONE_Pos)

#define PCC_REG_PERION_CLK_REG4X_RESERVED_Pos                                                    2U
#define PCC_REG_PERION_CLK_REG4X_RESERVED_Msk                                                    (0x3FFUL << PCC_REG_PERION_CLK_REG4X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART0_Pos                                         12U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART0_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART0_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART1_Pos                                         13U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART1_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART1_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART2_Pos                                         14U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART2_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART2_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART3_Pos                                         15U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART3_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_UART3_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_IRRC_Pos                                          16U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_IRRC_Msk                                          (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_IRRC_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_AUDIO_Pos                                         17U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_AUDIO_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_AUDIO_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER1_Pos                                        18U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER1_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER1_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER2_Pos                                        19U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER2_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER2_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER3_Pos                                        20U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER3_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER3_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER4_Pos                                        21U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER4_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER4_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER5_Pos                                        22U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER5_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER5_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER6_Pos                                        23U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER6_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER6_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER7_Pos                                        24U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER7_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER7_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER8_Pos                                        25U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER8_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER8_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER9_Pos                                        26U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER9_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER9_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER10_Pos                                       27U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER10_Msk                                       (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER10_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER11_Pos                                       28U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER11_Msk                                       (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_TIMER11_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_ETIMER_Pos                                        29U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_ETIMER_Msk                                        (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_ETIMER_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_RFC_Pos                                           30U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_RFC_Msk                                           (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_RFC_Pos)

#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_MODEM_Pos                                         31U
#define PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_MODEM_Msk                                         (0x1UL << PCC_REG_PERION_CLK_REG4X_FORCE_QACTIVE_MODEM_Pos)

/* 0x214    0x4000_0214
    6:0     R/W     R_PRO_AHB_WAIT_CNT                              7'h3
    26:7    R/W     RESERVED                                        20'b0
    31:27   R/W     DUMMY6                                          5'b0
 */
typedef union _PCC_REG_PERION_CLK_REG5X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PRO_AHB_WAIT_CNT: 7;
        uint32_t RESERVED: 20;
        uint32_t DUMMY6: 5;
    };
} PCC_REG_PERION_CLK_REG5X_TYPE;

/*0x4000_0214 PCC_REG_PERION_CLK_REG5X*/
#define PCC_REG_PERION_CLK_REG5X_R_PRO_AHB_WAIT_CNT_Pos                                          0U
#define PCC_REG_PERION_CLK_REG5X_R_PRO_AHB_WAIT_CNT_Msk                                          (0x7FUL << PCC_REG_PERION_CLK_REG5X_R_PRO_AHB_WAIT_CNT_Pos)

#define PCC_REG_PERION_CLK_REG5X_RESERVED_Pos                                                    7U
#define PCC_REG_PERION_CLK_REG5X_RESERVED_Msk                                                    (0xFFFFFUL << PCC_REG_PERION_CLK_REG5X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_REG5X_DUMMY6_Pos                                                      27U
#define PCC_REG_PERION_CLK_REG5X_DUMMY6_Msk                                                      (0x1FUL << PCC_REG_PERION_CLK_REG5X_DUMMY6_Pos)

/* 0x218    0x4000_0218
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_RNG                       8'b0
    8       R/W     RESERVED_12                                     1'b0
    9       R/W     RESERVED_11                                     1'b1
    10      R/W     RESERVED_10                                     1'b0
    11      R/W     RESERVED_9                                      1'b1
    12      R/W     RESERVED_8                                      1'b1
    13      R/W     RESERVED_7                                      1'b0
    14      R/W     RESERVED_6                                      1'b1
    15      R/W     RESERVED_5                                      1'b0
    16      R/W     R_CKE_RNG                                       1'b0
    17      R/W     RNG_CLK_FORCE                                   1'b0
    20:18   R/W     RSVD_1                                          3'b000
    21      R/W     RESERVED_4                                      1'b0
    22      R/W     RESERVED_3                                      1'b0
    23      R/W     RESERVED_2                                      1'b0
    24      R/W     RESERVED_1                                      1'b0
    27:25   R/W     R_RNG_SFOSC_DIV_SEL                             3'h0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_TRNG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_RNG: 8;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t R_CKE_RNG: 1;
        uint32_t RNG_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t R_RNG_SFOSC_DIV_SEL: 3;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_TRNG_TYPE;

/*0x4000_0218 PCC_REG_TRNG*/
#define PCC_REG_TRNG_ENTRY_DELAY_CORE1_DEV_RNG_Pos                                               0U
#define PCC_REG_TRNG_ENTRY_DELAY_CORE1_DEV_RNG_Msk                                               (0xFFUL << PCC_REG_TRNG_ENTRY_DELAY_CORE1_DEV_RNG_Pos)

#define PCC_REG_TRNG_RESERVED_12_Pos                                                             8U
#define PCC_REG_TRNG_RESERVED_12_Msk                                                             (0x1UL << PCC_REG_TRNG_RESERVED_12_Pos)

#define PCC_REG_TRNG_RESERVED_11_Pos                                                             9U
#define PCC_REG_TRNG_RESERVED_11_Msk                                                             (0x1UL << PCC_REG_TRNG_RESERVED_11_Pos)

#define PCC_REG_TRNG_RESERVED_10_Pos                                                             10U
#define PCC_REG_TRNG_RESERVED_10_Msk                                                             (0x1UL << PCC_REG_TRNG_RESERVED_10_Pos)

#define PCC_REG_TRNG_RESERVED_9_Pos                                                              11U
#define PCC_REG_TRNG_RESERVED_9_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_9_Pos)

#define PCC_REG_TRNG_RESERVED_8_Pos                                                              12U
#define PCC_REG_TRNG_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_8_Pos)

#define PCC_REG_TRNG_RESERVED_7_Pos                                                              13U
#define PCC_REG_TRNG_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_7_Pos)

#define PCC_REG_TRNG_RESERVED_6_Pos                                                              14U
#define PCC_REG_TRNG_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_6_Pos)

#define PCC_REG_TRNG_RESERVED_5_Pos                                                              15U
#define PCC_REG_TRNG_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_5_Pos)

#define PCC_REG_TRNG_R_CKE_RNG_Pos                                                               16U
#define PCC_REG_TRNG_R_CKE_RNG_Msk                                                               (0x1UL << PCC_REG_TRNG_R_CKE_RNG_Pos)

#define PCC_REG_TRNG_RNG_CLK_FORCE_Pos                                                           17U
#define PCC_REG_TRNG_RNG_CLK_FORCE_Msk                                                           (0x1UL << PCC_REG_TRNG_RNG_CLK_FORCE_Pos)

#define PCC_REG_TRNG_RSVD_1_Pos                                                                  18U
#define PCC_REG_TRNG_RSVD_1_Msk                                                                  (0x7UL << PCC_REG_TRNG_RSVD_1_Pos)

#define PCC_REG_TRNG_RESERVED_4_Pos                                                              21U
#define PCC_REG_TRNG_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_4_Pos)

#define PCC_REG_TRNG_RESERVED_3_Pos                                                              22U
#define PCC_REG_TRNG_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_3_Pos)

#define PCC_REG_TRNG_RESERVED_2_Pos                                                              23U
#define PCC_REG_TRNG_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_2_Pos)

#define PCC_REG_TRNG_RESERVED_1_Pos                                                              24U
#define PCC_REG_TRNG_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_TRNG_RESERVED_1_Pos)

#define PCC_REG_TRNG_R_RNG_SFOSC_DIV_SEL_Pos                                                     25U
#define PCC_REG_TRNG_R_RNG_SFOSC_DIV_SEL_Msk                                                     (0x7UL << PCC_REG_TRNG_R_RNG_SFOSC_DIV_SEL_Pos)

#define PCC_REG_TRNG_RSVD_Pos                                                                    28U
#define PCC_REG_TRNG_RSVD_Msk                                                                    (0x7UL << PCC_REG_TRNG_RSVD_Pos)

#define PCC_REG_TRNG_RESERVED_Pos                                                                31U
#define PCC_REG_TRNG_RESERVED_Msk                                                                (0x1UL << PCC_REG_TRNG_RESERVED_Pos)

/* 0x21C    0x4000_021c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_WDT                       8'b0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    12      R/W     RESERVED_12                                     1'b1
    13      R/W     RESERVED_11                                     1'b0
    14      R/W     RESERVED_10                                     1'b1
    15      R/W     RESERVED_9                                      1'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     WDT_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_CORE_WDT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_WDT: 8;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t WDT_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_CORE_WDT_TYPE;

/*0x4000_021c PCC_REG_CORE_WDT*/
#define PCC_REG_CORE_WDT_ENTRY_DELAY_CORE1_DEV_WDT_Pos                                           0U
#define PCC_REG_CORE_WDT_ENTRY_DELAY_CORE1_DEV_WDT_Msk                                           (0xFFUL << PCC_REG_CORE_WDT_ENTRY_DELAY_CORE1_DEV_WDT_Pos)

#define PCC_REG_CORE_WDT_RESERVED_16_Pos                                                         8U
#define PCC_REG_CORE_WDT_RESERVED_16_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_16_Pos)

#define PCC_REG_CORE_WDT_RESERVED_15_Pos                                                         9U
#define PCC_REG_CORE_WDT_RESERVED_15_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_15_Pos)

#define PCC_REG_CORE_WDT_RESERVED_14_Pos                                                         10U
#define PCC_REG_CORE_WDT_RESERVED_14_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_14_Pos)

#define PCC_REG_CORE_WDT_RESERVED_13_Pos                                                         11U
#define PCC_REG_CORE_WDT_RESERVED_13_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_13_Pos)

#define PCC_REG_CORE_WDT_RESERVED_12_Pos                                                         12U
#define PCC_REG_CORE_WDT_RESERVED_12_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_12_Pos)

#define PCC_REG_CORE_WDT_RESERVED_11_Pos                                                         13U
#define PCC_REG_CORE_WDT_RESERVED_11_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_11_Pos)

#define PCC_REG_CORE_WDT_RESERVED_10_Pos                                                         14U
#define PCC_REG_CORE_WDT_RESERVED_10_Msk                                                         (0x1UL << PCC_REG_CORE_WDT_RESERVED_10_Pos)

#define PCC_REG_CORE_WDT_RESERVED_9_Pos                                                          15U
#define PCC_REG_CORE_WDT_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_9_Pos)

#define PCC_REG_CORE_WDT_RESERVED_8_Pos                                                          16U
#define PCC_REG_CORE_WDT_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_8_Pos)

#define PCC_REG_CORE_WDT_RESERVED_7_Pos                                                          17U
#define PCC_REG_CORE_WDT_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_7_Pos)

#define PCC_REG_CORE_WDT_WDT_CLK_FORCE_Pos                                                       18U
#define PCC_REG_CORE_WDT_WDT_CLK_FORCE_Msk                                                       (0x1UL << PCC_REG_CORE_WDT_WDT_CLK_FORCE_Pos)

#define PCC_REG_CORE_WDT_RSVD_1_Pos                                                              19U
#define PCC_REG_CORE_WDT_RSVD_1_Msk                                                              (0x7UL << PCC_REG_CORE_WDT_RSVD_1_Pos)

#define PCC_REG_CORE_WDT_RESERVED_6_Pos                                                          22U
#define PCC_REG_CORE_WDT_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_6_Pos)

#define PCC_REG_CORE_WDT_RESERVED_5_Pos                                                          23U
#define PCC_REG_CORE_WDT_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_5_Pos)

#define PCC_REG_CORE_WDT_RESERVED_4_Pos                                                          24U
#define PCC_REG_CORE_WDT_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_4_Pos)

#define PCC_REG_CORE_WDT_RESERVED_3_Pos                                                          25U
#define PCC_REG_CORE_WDT_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_3_Pos)

#define PCC_REG_CORE_WDT_RESERVED_2_Pos                                                          26U
#define PCC_REG_CORE_WDT_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_2_Pos)

#define PCC_REG_CORE_WDT_RESERVED_1_Pos                                                          27U
#define PCC_REG_CORE_WDT_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_CORE_WDT_RESERVED_1_Pos)

#define PCC_REG_CORE_WDT_RSVD_Pos                                                                28U
#define PCC_REG_CORE_WDT_RSVD_Msk                                                                (0x7UL << PCC_REG_CORE_WDT_RSVD_Pos)

#define PCC_REG_CORE_WDT_RESERVED_Pos                                                            31U
#define PCC_REG_CORE_WDT_RESERVED_Msk                                                            (0x1UL << PCC_REG_CORE_WDT_RESERVED_Pos)

/* 0x220    0x4000_0220
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_AES                       8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b0
    10      R/W     RESERVED_11                                     1'b0
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     AES_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_AES_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_AES: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t AES_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_AES_TYPE;

/*0x4000_0220 PCC_REG_AES*/
#define PCC_REG_AES_ENTRY_DELAY_CORE1_DEV_AES_Pos                                                0U
#define PCC_REG_AES_ENTRY_DELAY_CORE1_DEV_AES_Msk                                                (0xFFUL << PCC_REG_AES_ENTRY_DELAY_CORE1_DEV_AES_Pos)

#define PCC_REG_AES_RESERVED_13_Pos                                                              8U
#define PCC_REG_AES_RESERVED_13_Msk                                                              (0x1UL << PCC_REG_AES_RESERVED_13_Pos)

#define PCC_REG_AES_RESERVED_12_Pos                                                              9U
#define PCC_REG_AES_RESERVED_12_Msk                                                              (0x1UL << PCC_REG_AES_RESERVED_12_Pos)

#define PCC_REG_AES_RESERVED_11_Pos                                                              10U
#define PCC_REG_AES_RESERVED_11_Msk                                                              (0x1UL << PCC_REG_AES_RESERVED_11_Pos)

#define PCC_REG_AES_RESERVED_10_Pos                                                              11U
#define PCC_REG_AES_RESERVED_10_Msk                                                              (0x1UL << PCC_REG_AES_RESERVED_10_Pos)

#define PCC_REG_AES_RESERVED_9_Pos                                                               12U
#define PCC_REG_AES_RESERVED_9_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_9_Pos)

#define PCC_REG_AES_RSVD_2_Pos                                                                   13U
#define PCC_REG_AES_RSVD_2_Msk                                                                   (0x7UL << PCC_REG_AES_RSVD_2_Pos)

#define PCC_REG_AES_RESERVED_8_Pos                                                               16U
#define PCC_REG_AES_RESERVED_8_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_8_Pos)

#define PCC_REG_AES_RESERVED_7_Pos                                                               17U
#define PCC_REG_AES_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_7_Pos)

#define PCC_REG_AES_AES_CLK_FORCE_Pos                                                            18U
#define PCC_REG_AES_AES_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_AES_AES_CLK_FORCE_Pos)

#define PCC_REG_AES_RSVD_1_Pos                                                                   19U
#define PCC_REG_AES_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_AES_RSVD_1_Pos)

#define PCC_REG_AES_RESERVED_6_Pos                                                               22U
#define PCC_REG_AES_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_6_Pos)

#define PCC_REG_AES_RESERVED_5_Pos                                                               23U
#define PCC_REG_AES_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_5_Pos)

#define PCC_REG_AES_RESERVED_4_Pos                                                               24U
#define PCC_REG_AES_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_4_Pos)

#define PCC_REG_AES_RESERVED_3_Pos                                                               25U
#define PCC_REG_AES_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_3_Pos)

#define PCC_REG_AES_RESERVED_2_Pos                                                               26U
#define PCC_REG_AES_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_2_Pos)

#define PCC_REG_AES_RESERVED_1_Pos                                                               27U
#define PCC_REG_AES_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_AES_RESERVED_1_Pos)

#define PCC_REG_AES_RSVD_Pos                                                                     28U
#define PCC_REG_AES_RSVD_Msk                                                                     (0x7UL << PCC_REG_AES_RSVD_Pos)

#define PCC_REG_AES_RESERVED_Pos                                                                 31U
#define PCC_REG_AES_RESERVED_Msk                                                                 (0x1UL << PCC_REG_AES_RESERVED_Pos)

/* 0x224    0x4000_0224
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SHA256                    8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b0
    10      R/W     RESERVED_11                                     1'b0
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     SHA256_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SHA256_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SHA256: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t SHA256_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SHA256_TYPE;

/*0x4000_0224 PCC_REG_SHA256*/
#define PCC_REG_SHA256_ENTRY_DELAY_CORE1_DEV_SHA256_Pos                                          0U
#define PCC_REG_SHA256_ENTRY_DELAY_CORE1_DEV_SHA256_Msk                                          (0xFFUL << PCC_REG_SHA256_ENTRY_DELAY_CORE1_DEV_SHA256_Pos)

#define PCC_REG_SHA256_RESERVED_13_Pos                                                           8U
#define PCC_REG_SHA256_RESERVED_13_Msk                                                           (0x1UL << PCC_REG_SHA256_RESERVED_13_Pos)

#define PCC_REG_SHA256_RESERVED_12_Pos                                                           9U
#define PCC_REG_SHA256_RESERVED_12_Msk                                                           (0x1UL << PCC_REG_SHA256_RESERVED_12_Pos)

#define PCC_REG_SHA256_RESERVED_11_Pos                                                           10U
#define PCC_REG_SHA256_RESERVED_11_Msk                                                           (0x1UL << PCC_REG_SHA256_RESERVED_11_Pos)

#define PCC_REG_SHA256_RESERVED_10_Pos                                                           11U
#define PCC_REG_SHA256_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_SHA256_RESERVED_10_Pos)

#define PCC_REG_SHA256_RESERVED_9_Pos                                                            12U
#define PCC_REG_SHA256_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_9_Pos)

#define PCC_REG_SHA256_RSVD_2_Pos                                                                13U
#define PCC_REG_SHA256_RSVD_2_Msk                                                                (0x7UL << PCC_REG_SHA256_RSVD_2_Pos)

#define PCC_REG_SHA256_RESERVED_8_Pos                                                            16U
#define PCC_REG_SHA256_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_8_Pos)

#define PCC_REG_SHA256_RESERVED_7_Pos                                                            17U
#define PCC_REG_SHA256_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_7_Pos)

#define PCC_REG_SHA256_SHA256_CLK_FORCE_Pos                                                      18U
#define PCC_REG_SHA256_SHA256_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_SHA256_SHA256_CLK_FORCE_Pos)

#define PCC_REG_SHA256_RSVD_1_Pos                                                                19U
#define PCC_REG_SHA256_RSVD_1_Msk                                                                (0x7UL << PCC_REG_SHA256_RSVD_1_Pos)

#define PCC_REG_SHA256_RESERVED_6_Pos                                                            22U
#define PCC_REG_SHA256_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_6_Pos)

#define PCC_REG_SHA256_RESERVED_5_Pos                                                            23U
#define PCC_REG_SHA256_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_5_Pos)

#define PCC_REG_SHA256_RESERVED_4_Pos                                                            24U
#define PCC_REG_SHA256_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_4_Pos)

#define PCC_REG_SHA256_RESERVED_3_Pos                                                            25U
#define PCC_REG_SHA256_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_3_Pos)

#define PCC_REG_SHA256_RESERVED_2_Pos                                                            26U
#define PCC_REG_SHA256_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_2_Pos)

#define PCC_REG_SHA256_RESERVED_1_Pos                                                            27U
#define PCC_REG_SHA256_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_SHA256_RESERVED_1_Pos)

#define PCC_REG_SHA256_RSVD_Pos                                                                  28U
#define PCC_REG_SHA256_RSVD_Msk                                                                  (0x7UL << PCC_REG_SHA256_RSVD_Pos)

#define PCC_REG_SHA256_RESERVED_Pos                                                              31U
#define PCC_REG_SHA256_RESERVED_Msk                                                              (0x1UL << PCC_REG_SHA256_RESERVED_Pos)

/* 0x228    0x4000_0228
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_MODEMRFCPI_APB_WRAPPER    8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b0
    10      R/W     RESERVED_11                                     1'b0
    11      R/W     RESERVED_10                                     1'b0
    12      R/W     RESERVED_9                                      1'b0
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     MODEMRFCPI_CLK_FORCE                            1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_MODEMRFCPI_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_MODEMRFCPI_APB_WRAPPER: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t MODEMRFCPI_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_MODEMRFCPI_TYPE;

/*0x4000_0228 PCC_REG_MODEMRFCPI*/
#define PCC_REG_MODEMRFCPI_ENTRY_DELAY_CORE1_DEV_MODEMRFCPI_APB_WRAPPER_Pos                      0U
#define PCC_REG_MODEMRFCPI_ENTRY_DELAY_CORE1_DEV_MODEMRFCPI_APB_WRAPPER_Msk                      (0xFFUL << PCC_REG_MODEMRFCPI_ENTRY_DELAY_CORE1_DEV_MODEMRFCPI_APB_WRAPPER_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_13_Pos                                                       8U
#define PCC_REG_MODEMRFCPI_RESERVED_13_Msk                                                       (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_13_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_12_Pos                                                       9U
#define PCC_REG_MODEMRFCPI_RESERVED_12_Msk                                                       (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_12_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_11_Pos                                                       10U
#define PCC_REG_MODEMRFCPI_RESERVED_11_Msk                                                       (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_11_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_10_Pos                                                       11U
#define PCC_REG_MODEMRFCPI_RESERVED_10_Msk                                                       (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_10_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_9_Pos                                                        12U
#define PCC_REG_MODEMRFCPI_RESERVED_9_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_9_Pos)

#define PCC_REG_MODEMRFCPI_RSVD_2_Pos                                                            13U
#define PCC_REG_MODEMRFCPI_RSVD_2_Msk                                                            (0x7UL << PCC_REG_MODEMRFCPI_RSVD_2_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_8_Pos                                                        16U
#define PCC_REG_MODEMRFCPI_RESERVED_8_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_8_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_7_Pos                                                        17U
#define PCC_REG_MODEMRFCPI_RESERVED_7_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_7_Pos)

#define PCC_REG_MODEMRFCPI_MODEMRFCPI_CLK_FORCE_Pos                                              18U
#define PCC_REG_MODEMRFCPI_MODEMRFCPI_CLK_FORCE_Msk                                              (0x1UL << PCC_REG_MODEMRFCPI_MODEMRFCPI_CLK_FORCE_Pos)

#define PCC_REG_MODEMRFCPI_RSVD_1_Pos                                                            19U
#define PCC_REG_MODEMRFCPI_RSVD_1_Msk                                                            (0x7UL << PCC_REG_MODEMRFCPI_RSVD_1_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_6_Pos                                                        22U
#define PCC_REG_MODEMRFCPI_RESERVED_6_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_6_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_5_Pos                                                        23U
#define PCC_REG_MODEMRFCPI_RESERVED_5_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_5_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_4_Pos                                                        24U
#define PCC_REG_MODEMRFCPI_RESERVED_4_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_4_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_3_Pos                                                        25U
#define PCC_REG_MODEMRFCPI_RESERVED_3_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_3_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_2_Pos                                                        26U
#define PCC_REG_MODEMRFCPI_RESERVED_2_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_2_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_1_Pos                                                        27U
#define PCC_REG_MODEMRFCPI_RESERVED_1_Msk                                                        (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_1_Pos)

#define PCC_REG_MODEMRFCPI_RSVD_Pos                                                              28U
#define PCC_REG_MODEMRFCPI_RSVD_Msk                                                              (0x7UL << PCC_REG_MODEMRFCPI_RSVD_Pos)

#define PCC_REG_MODEMRFCPI_RESERVED_Pos                                                          31U
#define PCC_REG_MODEMRFCPI_RESERVED_Msk                                                          (0x1UL << PCC_REG_MODEMRFCPI_RESERVED_Pos)

/* 0x22C    0x4000_022c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_DMA0                      8'b0
    8       R/W     RESERVED_8                                      1'b0
    9       R/W     RESERVED_7                                      1'b0
    10      R/W     RESERVED_6                                      1'b0
    11      R/W     RESERVED_5                                      1'b1
    14:12   R/W     RSVD_2                                          3'h0
    15      R/W     RESERVED_4                                      1'b0
    16      R/W     RESERVED_3                                      1'b0
    17      R/W     GDMA0_CLK_FORCE                                 1'b0
    20:18   R/W     RSVD_1                                          3'b000
    21      R/W     RESERVED_2                                      1'b0
    22      R/W     RESERVED_1                                      1'b0
    23      R/W     GDMA0_MANU_SEL                                  1'b0
    24      R/W     GDMA0_MANU_DAT                                  1'b0
    26:25   R/W     DMA_CG_CTRL                                     2'b10
    27      R/W     BZDMA_AUTOSLOW_ECO_DISABLE                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_DMA_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_DMA0: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t GDMA0_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t GDMA0_MANU_SEL: 1;
        uint32_t GDMA0_MANU_DAT: 1;
        uint32_t DMA_CG_CTRL: 2;
        uint32_t BZDMA_AUTOSLOW_ECO_DISABLE: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_DMA_TYPE;

/*0x4000_022c PCC_REG_DMA*/
#define PCC_REG_DMA_ENTRY_DELAY_CORE1_DEV_DMA0_Pos                                               0U
#define PCC_REG_DMA_ENTRY_DELAY_CORE1_DEV_DMA0_Msk                                               (0xFFUL << PCC_REG_DMA_ENTRY_DELAY_CORE1_DEV_DMA0_Pos)

#define PCC_REG_DMA_RESERVED_8_Pos                                                               8U
#define PCC_REG_DMA_RESERVED_8_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_8_Pos)

#define PCC_REG_DMA_RESERVED_7_Pos                                                               9U
#define PCC_REG_DMA_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_7_Pos)

#define PCC_REG_DMA_RESERVED_6_Pos                                                               10U
#define PCC_REG_DMA_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_6_Pos)

#define PCC_REG_DMA_RESERVED_5_Pos                                                               11U
#define PCC_REG_DMA_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_5_Pos)

#define PCC_REG_DMA_RSVD_2_Pos                                                                   12U
#define PCC_REG_DMA_RSVD_2_Msk                                                                   (0x7UL << PCC_REG_DMA_RSVD_2_Pos)

#define PCC_REG_DMA_RESERVED_4_Pos                                                               15U
#define PCC_REG_DMA_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_4_Pos)

#define PCC_REG_DMA_RESERVED_3_Pos                                                               16U
#define PCC_REG_DMA_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_3_Pos)

#define PCC_REG_DMA_GDMA0_CLK_FORCE_Pos                                                          17U
#define PCC_REG_DMA_GDMA0_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_DMA_GDMA0_CLK_FORCE_Pos)

#define PCC_REG_DMA_RSVD_1_Pos                                                                   18U
#define PCC_REG_DMA_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_DMA_RSVD_1_Pos)

#define PCC_REG_DMA_RESERVED_2_Pos                                                               21U
#define PCC_REG_DMA_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_2_Pos)

#define PCC_REG_DMA_RESERVED_1_Pos                                                               22U
#define PCC_REG_DMA_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_DMA_RESERVED_1_Pos)

#define PCC_REG_DMA_GDMA0_MANU_SEL_Pos                                                           23U
#define PCC_REG_DMA_GDMA0_MANU_SEL_Msk                                                           (0x1UL << PCC_REG_DMA_GDMA0_MANU_SEL_Pos)

#define PCC_REG_DMA_GDMA0_MANU_DAT_Pos                                                           24U
#define PCC_REG_DMA_GDMA0_MANU_DAT_Msk                                                           (0x1UL << PCC_REG_DMA_GDMA0_MANU_DAT_Pos)

#define PCC_REG_DMA_DMA_CG_CTRL_Pos                                                              25U
#define PCC_REG_DMA_DMA_CG_CTRL_Msk                                                              (0x3UL << PCC_REG_DMA_DMA_CG_CTRL_Pos)

#define PCC_REG_DMA_BZDMA_AUTOSLOW_ECO_DISABLE_Pos                                               27U
#define PCC_REG_DMA_BZDMA_AUTOSLOW_ECO_DISABLE_Msk                                               (0x1UL << PCC_REG_DMA_BZDMA_AUTOSLOW_ECO_DISABLE_Pos)

#define PCC_REG_DMA_RSVD_Pos                                                                     28U
#define PCC_REG_DMA_RSVD_Msk                                                                     (0x7UL << PCC_REG_DMA_RSVD_Pos)

#define PCC_REG_DMA_RESERVED_Pos                                                                 31U
#define PCC_REG_DMA_RESERVED_Msk                                                                 (0x1UL << PCC_REG_DMA_RESERVED_Pos)

/* 0x230    0x4000_0230
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SPIC0                     8'b0
    8       R/W     RESERVED_9                                      1'b1
    9       R/W     RESERVED_8                                      1'b1
    10      R/W     RESERVED_7                                      1'b1
    11      R/W     RESERVED_6                                      1'b1
    12      R/W     RESERVED_5                                      1'b1
    13      R/W     RESERVED_4                                      1'b1
    15:14   R/W     RESERVED_3                                      2'b0
    18:16   R/W     SPIC0_DIV_SEL                                   3'h0
    19      R/W     SPIC0_CLK_SRC_SEL                               1'b0
    20      R/W     FMC0_CLK_FORCE                                  1'b0
    21      R/W     RESERVED_2                                      1'b0
    22      R/W     RESERVED_1                                      1'b0
    28:23   R/W     R_PON_DLYSEL_FMC0                               6'h0
    29      R/W     SPIC0_MANU_SEL                                  1'b0
    30      R/W     SPIC0_MANU_DAT                                  1'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SPIC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SPIC0: 8;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 2;
        uint32_t SPIC0_DIV_SEL: 3;
        uint32_t SPIC0_CLK_SRC_SEL: 1;
        uint32_t FMC0_CLK_FORCE: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t R_PON_DLYSEL_FMC0: 6;
        uint32_t SPIC0_MANU_SEL: 1;
        uint32_t SPIC0_MANU_DAT: 1;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SPIC_TYPE;

/*0x4000_0230 PCC_REG_SPIC*/
#define PCC_REG_SPIC_ENTRY_DELAY_CORE1_DEV_SPIC0_Pos                                             0U
#define PCC_REG_SPIC_ENTRY_DELAY_CORE1_DEV_SPIC0_Msk                                             (0xFFUL << PCC_REG_SPIC_ENTRY_DELAY_CORE1_DEV_SPIC0_Pos)

#define PCC_REG_SPIC_RESERVED_9_Pos                                                              8U
#define PCC_REG_SPIC_RESERVED_9_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_9_Pos)

#define PCC_REG_SPIC_RESERVED_8_Pos                                                              9U
#define PCC_REG_SPIC_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_8_Pos)

#define PCC_REG_SPIC_RESERVED_7_Pos                                                              10U
#define PCC_REG_SPIC_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_7_Pos)

#define PCC_REG_SPIC_RESERVED_6_Pos                                                              11U
#define PCC_REG_SPIC_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_6_Pos)

#define PCC_REG_SPIC_RESERVED_5_Pos                                                              12U
#define PCC_REG_SPIC_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_5_Pos)

#define PCC_REG_SPIC_RESERVED_4_Pos                                                              13U
#define PCC_REG_SPIC_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_4_Pos)

#define PCC_REG_SPIC_RESERVED_3_Pos                                                              14U
#define PCC_REG_SPIC_RESERVED_3_Msk                                                              (0x3UL << PCC_REG_SPIC_RESERVED_3_Pos)

#define PCC_REG_SPIC_SPIC0_DIV_SEL_Pos                                                           16U
#define PCC_REG_SPIC_SPIC0_DIV_SEL_Msk                                                           (0x7UL << PCC_REG_SPIC_SPIC0_DIV_SEL_Pos)

#define PCC_REG_SPIC_SPIC0_CLK_SRC_SEL_Pos                                                       19U
#define PCC_REG_SPIC_SPIC0_CLK_SRC_SEL_Msk                                                       (0x1UL << PCC_REG_SPIC_SPIC0_CLK_SRC_SEL_Pos)

#define PCC_REG_SPIC_FMC0_CLK_FORCE_Pos                                                          20U
#define PCC_REG_SPIC_FMC0_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_SPIC_FMC0_CLK_FORCE_Pos)

#define PCC_REG_SPIC_RESERVED_2_Pos                                                              21U
#define PCC_REG_SPIC_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_2_Pos)

#define PCC_REG_SPIC_RESERVED_1_Pos                                                              22U
#define PCC_REG_SPIC_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_SPIC_RESERVED_1_Pos)

#define PCC_REG_SPIC_R_PON_DLYSEL_FMC0_Pos                                                       23U
#define PCC_REG_SPIC_R_PON_DLYSEL_FMC0_Msk                                                       (0x3FUL << PCC_REG_SPIC_R_PON_DLYSEL_FMC0_Pos)

#define PCC_REG_SPIC_SPIC0_MANU_SEL_Pos                                                          29U
#define PCC_REG_SPIC_SPIC0_MANU_SEL_Msk                                                          (0x1UL << PCC_REG_SPIC_SPIC0_MANU_SEL_Pos)

#define PCC_REG_SPIC_SPIC0_MANU_DAT_Pos                                                          30U
#define PCC_REG_SPIC_SPIC0_MANU_DAT_Msk                                                          (0x1UL << PCC_REG_SPIC_SPIC0_MANU_DAT_Pos)

#define PCC_REG_SPIC_RESERVED_Pos                                                                31U
#define PCC_REG_SPIC_RESERVED_Msk                                                                (0x1UL << PCC_REG_SPIC_RESERVED_Pos)

/* 0x234    0x4000_0234
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SPI0                      8'b0
    8       R/W     RESERVED_9                                      1'b1
    9       R/W     RESERVED_8                                      1'b1
    10      R/W     RESERVED_7                                      1'b1
    11      R/W     RESERVED_6                                      1'b1
    12      R/W     RESERVED_5                                      1'b1
    13      R/W     RESERVED_4                                      1'b1
    14      R/W     RESERVED_3                                      1'b1
    15      R/W     RESERVED_2                                      1'b0
    18:16   R/W     R_SPI0_CLK_DIV_SEL                              3'h0
    19      R/W     R_SPI0_CLK_SRC_SEL                              1'b0
    20      R/W     RESERVED_1                                      1'b0
    21      R/W     SPI0_CLK_FORCE                                  1'b0
    22      R/W     PON_SPI0_MST                                    1'b0
    23      R/W     PON_SPI0_H2S_BRG_EN                             1'b0
    24      R/W     PON_SPI0_BRG_EN                                 1'b0
    25      R/W     R_CPU_SLOW_OPT_SPI0                             1'b0
    26      W1O     R_SPI0_DIV_SEL_OPT                              1'b0
    27      W1O     R_SPI0_DIV_SEL_OPT1                             1'b0
    30:28   R/W     RSVD                                            3'b00
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SPI0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SPI0: 8;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t R_SPI0_CLK_DIV_SEL: 3;
        uint32_t R_SPI0_CLK_SRC_SEL: 1;
        uint32_t RESERVED_1: 1;
        uint32_t SPI0_CLK_FORCE: 1;
        uint32_t PON_SPI0_MST: 1;
        uint32_t PON_SPI0_H2S_BRG_EN: 1;
        uint32_t PON_SPI0_BRG_EN: 1;
        uint32_t R_CPU_SLOW_OPT_SPI0: 1;
        uint32_t R_SPI0_DIV_SEL_OPT: 1;
        uint32_t R_SPI0_DIV_SEL_OPT1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SPI0_TYPE;

/*0x4000_0234 PCC_REG_SPI0*/
#define PCC_REG_SPI0_ENTRY_DELAY_CORE1_DEV_SPI0_Pos                                              0U
#define PCC_REG_SPI0_ENTRY_DELAY_CORE1_DEV_SPI0_Msk                                              (0xFFUL << PCC_REG_SPI0_ENTRY_DELAY_CORE1_DEV_SPI0_Pos)

#define PCC_REG_SPI0_RESERVED_9_Pos                                                              8U
#define PCC_REG_SPI0_RESERVED_9_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_9_Pos)

#define PCC_REG_SPI0_RESERVED_8_Pos                                                              9U
#define PCC_REG_SPI0_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_8_Pos)

#define PCC_REG_SPI0_RESERVED_7_Pos                                                              10U
#define PCC_REG_SPI0_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_7_Pos)

#define PCC_REG_SPI0_RESERVED_6_Pos                                                              11U
#define PCC_REG_SPI0_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_6_Pos)

#define PCC_REG_SPI0_RESERVED_5_Pos                                                              12U
#define PCC_REG_SPI0_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_5_Pos)

#define PCC_REG_SPI0_RESERVED_4_Pos                                                              13U
#define PCC_REG_SPI0_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_4_Pos)

#define PCC_REG_SPI0_RESERVED_3_Pos                                                              14U
#define PCC_REG_SPI0_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_3_Pos)

#define PCC_REG_SPI0_RESERVED_2_Pos                                                              15U
#define PCC_REG_SPI0_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_2_Pos)

#define PCC_REG_SPI0_R_SPI0_CLK_DIV_SEL_Pos                                                      16U
#define PCC_REG_SPI0_R_SPI0_CLK_DIV_SEL_Msk                                                      (0x7UL << PCC_REG_SPI0_R_SPI0_CLK_DIV_SEL_Pos)

#define PCC_REG_SPI0_R_SPI0_CLK_SRC_SEL_Pos                                                      19U
#define PCC_REG_SPI0_R_SPI0_CLK_SRC_SEL_Msk                                                      (0x1UL << PCC_REG_SPI0_R_SPI0_CLK_SRC_SEL_Pos)

#define PCC_REG_SPI0_RESERVED_1_Pos                                                              20U
#define PCC_REG_SPI0_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_SPI0_RESERVED_1_Pos)

#define PCC_REG_SPI0_SPI0_CLK_FORCE_Pos                                                          21U
#define PCC_REG_SPI0_SPI0_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_SPI0_SPI0_CLK_FORCE_Pos)

#define PCC_REG_SPI0_PON_SPI0_MST_Pos                                                            22U
#define PCC_REG_SPI0_PON_SPI0_MST_Msk                                                            (0x1UL << PCC_REG_SPI0_PON_SPI0_MST_Pos)

#define PCC_REG_SPI0_PON_SPI0_H2S_BRG_EN_Pos                                                     23U
#define PCC_REG_SPI0_PON_SPI0_H2S_BRG_EN_Msk                                                     (0x1UL << PCC_REG_SPI0_PON_SPI0_H2S_BRG_EN_Pos)

#define PCC_REG_SPI0_PON_SPI0_BRG_EN_Pos                                                         24U
#define PCC_REG_SPI0_PON_SPI0_BRG_EN_Msk                                                         (0x1UL << PCC_REG_SPI0_PON_SPI0_BRG_EN_Pos)

#define PCC_REG_SPI0_R_CPU_SLOW_OPT_SPI0_Pos                                                     25U
#define PCC_REG_SPI0_R_CPU_SLOW_OPT_SPI0_Msk                                                     (0x1UL << PCC_REG_SPI0_R_CPU_SLOW_OPT_SPI0_Pos)

#define PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT_Pos                                                      26U
#define PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT_Msk                                                      (0x1UL << PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT_Pos)

#define PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT1_Pos                                                     27U
#define PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT1_Msk                                                     (0x1UL << PCC_REG_SPI0_R_SPI0_DIV_SEL_OPT1_Pos)

#define PCC_REG_SPI0_RSVD_Pos                                                                    28U
#define PCC_REG_SPI0_RSVD_Msk                                                                    (0x7UL << PCC_REG_SPI0_RSVD_Pos)

#define PCC_REG_SPI0_RESERVED_Pos                                                                31U
#define PCC_REG_SPI0_RESERVED_Msk                                                                (0x1UL << PCC_REG_SPI0_RESERVED_Pos)

/* 0x238    0x4000_0238
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SPI1                      8'b0
    8       R/W     RESERVED_8                                      1'b1
    9       R/W     RESERVED_7                                      1'b1
    10      R/W     RESERVED_6                                      1'b1
    11      R/W     RESERVED_5                                      1'b1
    12      R/W     RESERVED_4                                      1'b1
    13      R/W     RESERVED_3                                      1'b1
    14      R/W     RESERVED_2                                      1'b1
    17:15   R/W     R_SPI1_CLK_DIV_SEL                              3'h0
    18      R/W     R_SPI1_CLK_SRC_SEL                              1'b0
    19      R/W     SPI1_CLK_FORCE                                  1'b0
    23:20   R/W     RESERVED_1                                      4'b0
    24      R/W     PON_SPI1_H2S_BRG_EN                             1'b0
    25      R/W     PON_SPI1_BRG_EN                                 1'b0
    26      W1O     R_SPI1_DIV_SEL_OPT                              1'b0
    27      W1O     R_SPI1_DIV_SEL_OPT1                             1'b0
    30:28   R/W     RSVD                                            3'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SPI1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SPI1: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t R_SPI1_CLK_DIV_SEL: 3;
        uint32_t R_SPI1_CLK_SRC_SEL: 1;
        uint32_t SPI1_CLK_FORCE: 1;
        uint32_t RESERVED_1: 4;
        uint32_t PON_SPI1_H2S_BRG_EN: 1;
        uint32_t PON_SPI1_BRG_EN: 1;
        uint32_t R_SPI1_DIV_SEL_OPT: 1;
        uint32_t R_SPI1_DIV_SEL_OPT1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SPI1_TYPE;

/*0x4000_0238 PCC_REG_SPI1*/
#define PCC_REG_SPI1_ENTRY_DELAY_CORE1_DEV_SPI1_Pos                                              0U
#define PCC_REG_SPI1_ENTRY_DELAY_CORE1_DEV_SPI1_Msk                                              (0xFFUL << PCC_REG_SPI1_ENTRY_DELAY_CORE1_DEV_SPI1_Pos)

#define PCC_REG_SPI1_RESERVED_8_Pos                                                              8U
#define PCC_REG_SPI1_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_8_Pos)

#define PCC_REG_SPI1_RESERVED_7_Pos                                                              9U
#define PCC_REG_SPI1_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_7_Pos)

#define PCC_REG_SPI1_RESERVED_6_Pos                                                              10U
#define PCC_REG_SPI1_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_6_Pos)

#define PCC_REG_SPI1_RESERVED_5_Pos                                                              11U
#define PCC_REG_SPI1_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_5_Pos)

#define PCC_REG_SPI1_RESERVED_4_Pos                                                              12U
#define PCC_REG_SPI1_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_4_Pos)

#define PCC_REG_SPI1_RESERVED_3_Pos                                                              13U
#define PCC_REG_SPI1_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_3_Pos)

#define PCC_REG_SPI1_RESERVED_2_Pos                                                              14U
#define PCC_REG_SPI1_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_SPI1_RESERVED_2_Pos)

#define PCC_REG_SPI1_R_SPI1_CLK_DIV_SEL_Pos                                                      15U
#define PCC_REG_SPI1_R_SPI1_CLK_DIV_SEL_Msk                                                      (0x7UL << PCC_REG_SPI1_R_SPI1_CLK_DIV_SEL_Pos)

#define PCC_REG_SPI1_R_SPI1_CLK_SRC_SEL_Pos                                                      18U
#define PCC_REG_SPI1_R_SPI1_CLK_SRC_SEL_Msk                                                      (0x1UL << PCC_REG_SPI1_R_SPI1_CLK_SRC_SEL_Pos)

#define PCC_REG_SPI1_SPI1_CLK_FORCE_Pos                                                          19U
#define PCC_REG_SPI1_SPI1_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_SPI1_SPI1_CLK_FORCE_Pos)

#define PCC_REG_SPI1_RESERVED_1_Pos                                                              20U
#define PCC_REG_SPI1_RESERVED_1_Msk                                                              (0xFUL << PCC_REG_SPI1_RESERVED_1_Pos)

#define PCC_REG_SPI1_PON_SPI1_H2S_BRG_EN_Pos                                                     24U
#define PCC_REG_SPI1_PON_SPI1_H2S_BRG_EN_Msk                                                     (0x1UL << PCC_REG_SPI1_PON_SPI1_H2S_BRG_EN_Pos)

#define PCC_REG_SPI1_PON_SPI1_BRG_EN_Pos                                                         25U
#define PCC_REG_SPI1_PON_SPI1_BRG_EN_Msk                                                         (0x1UL << PCC_REG_SPI1_PON_SPI1_BRG_EN_Pos)

#define PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT_Pos                                                      26U
#define PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT_Msk                                                      (0x1UL << PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT_Pos)

#define PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT1_Pos                                                     27U
#define PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT1_Msk                                                     (0x1UL << PCC_REG_SPI1_R_SPI1_DIV_SEL_OPT1_Pos)

#define PCC_REG_SPI1_RSVD_Pos                                                                    28U
#define PCC_REG_SPI1_RSVD_Msk                                                                    (0x7UL << PCC_REG_SPI1_RSVD_Pos)

#define PCC_REG_SPI1_RESERVED_Pos                                                                31U
#define PCC_REG_SPI1_RESERVED_Msk                                                                (0x1UL << PCC_REG_SPI1_RESERVED_Pos)

/* 0x23C    0x4000_023c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SPI2                      8'b0
    8       R/W     RESERVED_8                                      1'b0
    9       R/W     RESERVED_7                                      1'b1
    10      R/W     RESERVED_6                                      1'b1
    11      R/W     RESERVED_5                                      1'b1
    12      R/W     RESERVED_4                                      1'b1
    13      R/W     RESERVED_3                                      1'b1
    15:14   R/W     RESERVED_2                                      2'b0
    18:16   R/W     R_SPI2_CLK_DIV_SEL                              3'h0
    19      R/W     R_SPI2_CLK_SRC_SEL                              1'b0
    20      R/W     SPI2_CLK_FORCE                                  1'b0
    23:21   R/W     RESERVED_1                                      3'b0
    24      R/W     PON_SPI2_H2S_BRG_EN                             1'b0
    25      R/W     PON_SPI2_BRG_EN                                 1'b0
    26      W1O     R_SPI2_DIV_SEL_OPT                              1'b0
    27      W1O     R_SPI2_DIV_SEL_OPT1                             1'b0
    30:28   R/W     RSVD                                            3'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SPI2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SPI2: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 2;
        uint32_t R_SPI2_CLK_DIV_SEL: 3;
        uint32_t R_SPI2_CLK_SRC_SEL: 1;
        uint32_t SPI2_CLK_FORCE: 1;
        uint32_t RESERVED_1: 3;
        uint32_t PON_SPI2_H2S_BRG_EN: 1;
        uint32_t PON_SPI2_BRG_EN: 1;
        uint32_t R_SPI2_DIV_SEL_OPT: 1;
        uint32_t R_SPI2_DIV_SEL_OPT1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SPI2_TYPE;

/*0x4000_023c PCC_REG_SPI2*/
#define PCC_REG_SPI2_ENTRY_DELAY_CORE1_DEV_SPI2_Pos                                              0U
#define PCC_REG_SPI2_ENTRY_DELAY_CORE1_DEV_SPI2_Msk                                              (0xFFUL << PCC_REG_SPI2_ENTRY_DELAY_CORE1_DEV_SPI2_Pos)

#define PCC_REG_SPI2_RESERVED_8_Pos                                                              8U
#define PCC_REG_SPI2_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_8_Pos)

#define PCC_REG_SPI2_RESERVED_7_Pos                                                              9U
#define PCC_REG_SPI2_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_7_Pos)

#define PCC_REG_SPI2_RESERVED_6_Pos                                                              10U
#define PCC_REG_SPI2_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_6_Pos)

#define PCC_REG_SPI2_RESERVED_5_Pos                                                              11U
#define PCC_REG_SPI2_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_5_Pos)

#define PCC_REG_SPI2_RESERVED_4_Pos                                                              12U
#define PCC_REG_SPI2_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_4_Pos)

#define PCC_REG_SPI2_RESERVED_3_Pos                                                              13U
#define PCC_REG_SPI2_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_SPI2_RESERVED_3_Pos)

#define PCC_REG_SPI2_RESERVED_2_Pos                                                              14U
#define PCC_REG_SPI2_RESERVED_2_Msk                                                              (0x3UL << PCC_REG_SPI2_RESERVED_2_Pos)

#define PCC_REG_SPI2_R_SPI2_CLK_DIV_SEL_Pos                                                      16U
#define PCC_REG_SPI2_R_SPI2_CLK_DIV_SEL_Msk                                                      (0x7UL << PCC_REG_SPI2_R_SPI2_CLK_DIV_SEL_Pos)

#define PCC_REG_SPI2_R_SPI2_CLK_SRC_SEL_Pos                                                      19U
#define PCC_REG_SPI2_R_SPI2_CLK_SRC_SEL_Msk                                                      (0x1UL << PCC_REG_SPI2_R_SPI2_CLK_SRC_SEL_Pos)

#define PCC_REG_SPI2_SPI2_CLK_FORCE_Pos                                                          20U
#define PCC_REG_SPI2_SPI2_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_SPI2_SPI2_CLK_FORCE_Pos)

#define PCC_REG_SPI2_RESERVED_1_Pos                                                              21U
#define PCC_REG_SPI2_RESERVED_1_Msk                                                              (0x7UL << PCC_REG_SPI2_RESERVED_1_Pos)

#define PCC_REG_SPI2_PON_SPI2_H2S_BRG_EN_Pos                                                     24U
#define PCC_REG_SPI2_PON_SPI2_H2S_BRG_EN_Msk                                                     (0x1UL << PCC_REG_SPI2_PON_SPI2_H2S_BRG_EN_Pos)

#define PCC_REG_SPI2_PON_SPI2_BRG_EN_Pos                                                         25U
#define PCC_REG_SPI2_PON_SPI2_BRG_EN_Msk                                                         (0x1UL << PCC_REG_SPI2_PON_SPI2_BRG_EN_Pos)

#define PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT_Pos                                                      26U
#define PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT_Msk                                                      (0x1UL << PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT_Pos)

#define PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT1_Pos                                                     27U
#define PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT1_Msk                                                     (0x1UL << PCC_REG_SPI2_R_SPI2_DIV_SEL_OPT1_Pos)

#define PCC_REG_SPI2_RSVD_Pos                                                                    28U
#define PCC_REG_SPI2_RSVD_Msk                                                                    (0x7UL << PCC_REG_SPI2_RSVD_Pos)

#define PCC_REG_SPI2_RESERVED_Pos                                                                31U
#define PCC_REG_SPI2_RESERVED_Msk                                                                (0x1UL << PCC_REG_SPI2_RESERVED_Pos)

/* 0x240    0x4000_0240
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_I2S0                      8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    17:16   R/W     MCLK_SEL                                        2'b00
    20:18   R/W     R_I2S_PLL_CLK_SEL                               3'h4
    21      R/W     RESERVED_1                                      1'b0
    22      R/W     I2S_CLK_FORCE                                   1'b0
    26:23   R/W     RSVD                                            4'b00
    27      R/W     R_SPORT0_EXT_CODEC                              1'b0
    31:28   R/W     RESERVED                                        4'b0
 */
typedef union _PCC_REG_I2S0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_I2S0: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t MCLK_SEL: 2;
        uint32_t R_I2S_PLL_CLK_SEL: 3;
        uint32_t RESERVED_1: 1;
        uint32_t I2S_CLK_FORCE: 1;
        uint32_t RSVD: 4;
        uint32_t R_SPORT0_EXT_CODEC: 1;
        uint32_t RESERVED: 4;
    };
} PCC_REG_I2S0_TYPE;

/*0x4000_0240 PCC_REG_I2S0*/
#define PCC_REG_I2S0_ENTRY_DELAY_CORE1_DEV_I2S0_Pos                                              0U
#define PCC_REG_I2S0_ENTRY_DELAY_CORE1_DEV_I2S0_Msk                                              (0xFFUL << PCC_REG_I2S0_ENTRY_DELAY_CORE1_DEV_I2S0_Pos)

#define PCC_REG_I2S0_RESERVED_7_Pos                                                              8U
#define PCC_REG_I2S0_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_7_Pos)

#define PCC_REG_I2S0_RESERVED_6_Pos                                                              9U
#define PCC_REG_I2S0_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_6_Pos)

#define PCC_REG_I2S0_RESERVED_5_Pos                                                              10U
#define PCC_REG_I2S0_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_5_Pos)

#define PCC_REG_I2S0_RESERVED_4_Pos                                                              11U
#define PCC_REG_I2S0_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_4_Pos)

#define PCC_REG_I2S0_RESERVED_3_Pos                                                              12U
#define PCC_REG_I2S0_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_3_Pos)

#define PCC_REG_I2S0_RESERVED_2_Pos                                                              13U
#define PCC_REG_I2S0_RESERVED_2_Msk                                                              (0x7UL << PCC_REG_I2S0_RESERVED_2_Pos)

#define PCC_REG_I2S0_MCLK_SEL_Pos                                                                16U
#define PCC_REG_I2S0_MCLK_SEL_Msk                                                                (0x3UL << PCC_REG_I2S0_MCLK_SEL_Pos)

#define PCC_REG_I2S0_R_I2S_PLL_CLK_SEL_Pos                                                       18U
#define PCC_REG_I2S0_R_I2S_PLL_CLK_SEL_Msk                                                       (0x7UL << PCC_REG_I2S0_R_I2S_PLL_CLK_SEL_Pos)

#define PCC_REG_I2S0_RESERVED_1_Pos                                                              21U
#define PCC_REG_I2S0_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_I2S0_RESERVED_1_Pos)

#define PCC_REG_I2S0_I2S_CLK_FORCE_Pos                                                           22U
#define PCC_REG_I2S0_I2S_CLK_FORCE_Msk                                                           (0x1UL << PCC_REG_I2S0_I2S_CLK_FORCE_Pos)

#define PCC_REG_I2S0_RSVD_Pos                                                                    23U
#define PCC_REG_I2S0_RSVD_Msk                                                                    (0xFUL << PCC_REG_I2S0_RSVD_Pos)

#define PCC_REG_I2S0_R_SPORT0_EXT_CODEC_Pos                                                      27U
#define PCC_REG_I2S0_R_SPORT0_EXT_CODEC_Msk                                                      (0x1UL << PCC_REG_I2S0_R_SPORT0_EXT_CODEC_Pos)

#define PCC_REG_I2S0_RESERVED_Pos                                                                28U
#define PCC_REG_I2S0_RESERVED_Msk                                                                (0xFUL << PCC_REG_I2S0_RESERVED_Pos)

/* 0x244    0x4000_0244
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TIMER0                    8'b0
    8       R/W     RESERVED_8                                      1'b1
    9       R/W     RESERVED_7                                      1'b1
    10      R/W     RESERVED_6                                      1'b1
    11      R/W     RESERVED_5                                      1'b1
    12      R/W     RESERVED_4                                      1'b1
    13      R/W     RESERVED_3                                      1'b1
    14      R/W     RESERVED_2                                      1'b1
    15      R/W     RESERVED_1                                      1'b1
    21:16   R/W     RESERVED                                        6'b0
    22      R/W     RSVD_1                                          1'b0
    23      R/W     RSVD                                            1'b0
    26:24   R/W     R_TIMER_1_CLK_DIV                               3'h0
    29:27   R/W     R_TIMER_2_CLK_DIV                               3'h0
    30      R/W     TIMER0_CH1_CLK_FORCE                            1'b0
    31      R/W     TIMER0_CH2_CLK_FORCE                            1'b0
 */
typedef union _PCC_REG_TIMER0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TIMER0: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 6;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
        uint32_t R_TIMER_1_CLK_DIV: 3;
        uint32_t R_TIMER_2_CLK_DIV: 3;
        uint32_t TIMER0_CH1_CLK_FORCE: 1;
        uint32_t TIMER0_CH2_CLK_FORCE: 1;
    };
} PCC_REG_TIMER0_TYPE;

/*0x4000_0244 PCC_REG_TIMER0*/
#define PCC_REG_TIMER0_ENTRY_DELAY_CORE1_DEV_TIMER0_Pos                                          0U
#define PCC_REG_TIMER0_ENTRY_DELAY_CORE1_DEV_TIMER0_Msk                                          (0xFFUL << PCC_REG_TIMER0_ENTRY_DELAY_CORE1_DEV_TIMER0_Pos)

#define PCC_REG_TIMER0_RESERVED_8_Pos                                                            8U
#define PCC_REG_TIMER0_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_8_Pos)

#define PCC_REG_TIMER0_RESERVED_7_Pos                                                            9U
#define PCC_REG_TIMER0_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_7_Pos)

#define PCC_REG_TIMER0_RESERVED_6_Pos                                                            10U
#define PCC_REG_TIMER0_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_6_Pos)

#define PCC_REG_TIMER0_RESERVED_5_Pos                                                            11U
#define PCC_REG_TIMER0_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_5_Pos)

#define PCC_REG_TIMER0_RESERVED_4_Pos                                                            12U
#define PCC_REG_TIMER0_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_4_Pos)

#define PCC_REG_TIMER0_RESERVED_3_Pos                                                            13U
#define PCC_REG_TIMER0_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_3_Pos)

#define PCC_REG_TIMER0_RESERVED_2_Pos                                                            14U
#define PCC_REG_TIMER0_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_2_Pos)

#define PCC_REG_TIMER0_RESERVED_1_Pos                                                            15U
#define PCC_REG_TIMER0_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_TIMER0_RESERVED_1_Pos)

#define PCC_REG_TIMER0_RESERVED_Pos                                                              16U
#define PCC_REG_TIMER0_RESERVED_Msk                                                              (0x3FUL << PCC_REG_TIMER0_RESERVED_Pos)

#define PCC_REG_TIMER0_RSVD_1_Pos                                                                22U
#define PCC_REG_TIMER0_RSVD_1_Msk                                                                (0x1UL << PCC_REG_TIMER0_RSVD_1_Pos)

#define PCC_REG_TIMER0_RSVD_Pos                                                                  23U
#define PCC_REG_TIMER0_RSVD_Msk                                                                  (0x1UL << PCC_REG_TIMER0_RSVD_Pos)

#define PCC_REG_TIMER0_R_TIMER_1_CLK_DIV_Pos                                                     24U
#define PCC_REG_TIMER0_R_TIMER_1_CLK_DIV_Msk                                                     (0x7UL << PCC_REG_TIMER0_R_TIMER_1_CLK_DIV_Pos)

#define PCC_REG_TIMER0_R_TIMER_2_CLK_DIV_Pos                                                     27U
#define PCC_REG_TIMER0_R_TIMER_2_CLK_DIV_Msk                                                     (0x7UL << PCC_REG_TIMER0_R_TIMER_2_CLK_DIV_Pos)

#define PCC_REG_TIMER0_TIMER0_CH1_CLK_FORCE_Pos                                                  30U
#define PCC_REG_TIMER0_TIMER0_CH1_CLK_FORCE_Msk                                                  (0x1UL << PCC_REG_TIMER0_TIMER0_CH1_CLK_FORCE_Pos)

#define PCC_REG_TIMER0_TIMER0_CH2_CLK_FORCE_Pos                                                  31U
#define PCC_REG_TIMER0_TIMER0_CH2_CLK_FORCE_Msk                                                  (0x1UL << PCC_REG_TIMER0_TIMER0_CH2_CLK_FORCE_Pos)

/* 0x248    0x4000_0248
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TIMER1                    8'b0
    8       R/W     RESERVED_9                                      1'b1
    9       R/W     RESERVED_8                                      1'b1
    10      R/W     RESERVED_7                                      1'b1
    11      R/W     RESERVED_6                                      1'b1
    12      R/W     RESERVED_5                                      1'b1
    13      R/W     RESERVED_4                                      1'b1
    14      R/W     RESERVED_3                                      1'b1
    15      R/W     RESERVED_2                                      1'b1
    16      R/W     RESERVED_1                                      1'b1
    17      R/W     RESERVED                                        1'b1
    19:18   R/W     RSVD                                            2'b0
    22:20   R/W     R_TIMER_3_CLK_DIV                               3'h0
    25:23   R/W     R_TIMER_4_CLK_DIV                               3'h0
    28:26   R/W     R_TIMER_5_CLK_DIV                               3'h0
    29      R/W     TIMER1_CH3_CLK_FORCE                            1'b0
    30      R/W     TIMER1_CH4_CLK_FORCE                            1'b0
    31      R/W     TIMER1_CH5_CLK_FORCE                            1'b0
 */
typedef union _PCC_REG_TIMER1_A_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TIMER1: 8;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 2;
        uint32_t R_TIMER_3_CLK_DIV: 3;
        uint32_t R_TIMER_4_CLK_DIV: 3;
        uint32_t R_TIMER_5_CLK_DIV: 3;
        uint32_t TIMER1_CH3_CLK_FORCE: 1;
        uint32_t TIMER1_CH4_CLK_FORCE: 1;
        uint32_t TIMER1_CH5_CLK_FORCE: 1;
    };
} PCC_REG_TIMER1_A_TYPE;

/*0x4000_0248 PCC_REG_TIMER1_A*/
#define PCC_REG_TIMER1_A_ENTRY_DELAY_CORE1_DEV_TIMER1_Pos                                        0U
#define PCC_REG_TIMER1_A_ENTRY_DELAY_CORE1_DEV_TIMER1_Msk                                        (0xFFUL << PCC_REG_TIMER1_A_ENTRY_DELAY_CORE1_DEV_TIMER1_Pos)

#define PCC_REG_TIMER1_A_RESERVED_9_Pos                                                          8U
#define PCC_REG_TIMER1_A_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_9_Pos)

#define PCC_REG_TIMER1_A_RESERVED_8_Pos                                                          9U
#define PCC_REG_TIMER1_A_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_8_Pos)

#define PCC_REG_TIMER1_A_RESERVED_7_Pos                                                          10U
#define PCC_REG_TIMER1_A_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_7_Pos)

#define PCC_REG_TIMER1_A_RESERVED_6_Pos                                                          11U
#define PCC_REG_TIMER1_A_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_6_Pos)

#define PCC_REG_TIMER1_A_RESERVED_5_Pos                                                          12U
#define PCC_REG_TIMER1_A_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_5_Pos)

#define PCC_REG_TIMER1_A_RESERVED_4_Pos                                                          13U
#define PCC_REG_TIMER1_A_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_4_Pos)

#define PCC_REG_TIMER1_A_RESERVED_3_Pos                                                          14U
#define PCC_REG_TIMER1_A_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_3_Pos)

#define PCC_REG_TIMER1_A_RESERVED_2_Pos                                                          15U
#define PCC_REG_TIMER1_A_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_2_Pos)

#define PCC_REG_TIMER1_A_RESERVED_1_Pos                                                          16U
#define PCC_REG_TIMER1_A_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_TIMER1_A_RESERVED_1_Pos)

#define PCC_REG_TIMER1_A_RESERVED_Pos                                                            17U
#define PCC_REG_TIMER1_A_RESERVED_Msk                                                            (0x1UL << PCC_REG_TIMER1_A_RESERVED_Pos)

#define PCC_REG_TIMER1_A_RSVD_Pos                                                                18U
#define PCC_REG_TIMER1_A_RSVD_Msk                                                                (0x3UL << PCC_REG_TIMER1_A_RSVD_Pos)

#define PCC_REG_TIMER1_A_R_TIMER_3_CLK_DIV_Pos                                                   20U
#define PCC_REG_TIMER1_A_R_TIMER_3_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_A_R_TIMER_3_CLK_DIV_Pos)

#define PCC_REG_TIMER1_A_R_TIMER_4_CLK_DIV_Pos                                                   23U
#define PCC_REG_TIMER1_A_R_TIMER_4_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_A_R_TIMER_4_CLK_DIV_Pos)

#define PCC_REG_TIMER1_A_R_TIMER_5_CLK_DIV_Pos                                                   26U
#define PCC_REG_TIMER1_A_R_TIMER_5_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_A_R_TIMER_5_CLK_DIV_Pos)

#define PCC_REG_TIMER1_A_TIMER1_CH3_CLK_FORCE_Pos                                                29U
#define PCC_REG_TIMER1_A_TIMER1_CH3_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_A_TIMER1_CH3_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_A_TIMER1_CH4_CLK_FORCE_Pos                                                30U
#define PCC_REG_TIMER1_A_TIMER1_CH4_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_A_TIMER1_CH4_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_A_TIMER1_CH5_CLK_FORCE_Pos                                                31U
#define PCC_REG_TIMER1_A_TIMER1_CH5_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_A_TIMER1_CH5_CLK_FORCE_Pos)

/* 0x24C    0x4000_024c
    7:0     R/W     RESERVED_11                                     8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b1
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    13      R/W     RESERVED_5                                      1'b1
    14      R/W     RESERVED_4                                      1'b1
    15      R/W     RESERVED_3                                      1'b1
    16      R/W     RESERVED_2                                      1'b1
    17      R/W     RESERVED_1                                      1'b1
    19:18   R/W     RESERVED                                        2'b0
    22:20   R/W     R_TIMER_6_CLK_DIV                               3'h0
    25:23   R/W     R_TIMER_7_CLK_DIV                               3'h0
    28:26   R/W     R_TIMER_8_CLK_DIV                               3'h0
    29      R/W     TIMER1_CH6_CLK_FORCE                            1'b0
    30      R/W     TIMER1_CH7_CLK_FORCE                            1'b0
    31      R/W     TIMER1_CH8_CLK_FORCE                            1'b0
 */
typedef union _PCC_REG_TIMER1_B_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_11: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 2;
        uint32_t R_TIMER_6_CLK_DIV: 3;
        uint32_t R_TIMER_7_CLK_DIV: 3;
        uint32_t R_TIMER_8_CLK_DIV: 3;
        uint32_t TIMER1_CH6_CLK_FORCE: 1;
        uint32_t TIMER1_CH7_CLK_FORCE: 1;
        uint32_t TIMER1_CH8_CLK_FORCE: 1;
    };
} PCC_REG_TIMER1_B_TYPE;

/*0x4000_024c PCC_REG_TIMER1_B*/
#define PCC_REG_TIMER1_B_RESERVED_11_Pos                                                         0U
#define PCC_REG_TIMER1_B_RESERVED_11_Msk                                                         (0xFFUL << PCC_REG_TIMER1_B_RESERVED_11_Pos)

#define PCC_REG_TIMER1_B_RESERVED_10_Pos                                                         8U
#define PCC_REG_TIMER1_B_RESERVED_10_Msk                                                         (0x1UL << PCC_REG_TIMER1_B_RESERVED_10_Pos)

#define PCC_REG_TIMER1_B_RESERVED_9_Pos                                                          9U
#define PCC_REG_TIMER1_B_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_9_Pos)

#define PCC_REG_TIMER1_B_RESERVED_8_Pos                                                          10U
#define PCC_REG_TIMER1_B_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_8_Pos)

#define PCC_REG_TIMER1_B_RESERVED_7_Pos                                                          11U
#define PCC_REG_TIMER1_B_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_7_Pos)

#define PCC_REG_TIMER1_B_RESERVED_6_Pos                                                          12U
#define PCC_REG_TIMER1_B_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_6_Pos)

#define PCC_REG_TIMER1_B_RESERVED_5_Pos                                                          13U
#define PCC_REG_TIMER1_B_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_5_Pos)

#define PCC_REG_TIMER1_B_RESERVED_4_Pos                                                          14U
#define PCC_REG_TIMER1_B_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_4_Pos)

#define PCC_REG_TIMER1_B_RESERVED_3_Pos                                                          15U
#define PCC_REG_TIMER1_B_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_3_Pos)

#define PCC_REG_TIMER1_B_RESERVED_2_Pos                                                          16U
#define PCC_REG_TIMER1_B_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_2_Pos)

#define PCC_REG_TIMER1_B_RESERVED_1_Pos                                                          17U
#define PCC_REG_TIMER1_B_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_TIMER1_B_RESERVED_1_Pos)

#define PCC_REG_TIMER1_B_RESERVED_Pos                                                            18U
#define PCC_REG_TIMER1_B_RESERVED_Msk                                                            (0x3UL << PCC_REG_TIMER1_B_RESERVED_Pos)

#define PCC_REG_TIMER1_B_R_TIMER_6_CLK_DIV_Pos                                                   20U
#define PCC_REG_TIMER1_B_R_TIMER_6_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_B_R_TIMER_6_CLK_DIV_Pos)

#define PCC_REG_TIMER1_B_R_TIMER_7_CLK_DIV_Pos                                                   23U
#define PCC_REG_TIMER1_B_R_TIMER_7_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_B_R_TIMER_7_CLK_DIV_Pos)

#define PCC_REG_TIMER1_B_R_TIMER_8_CLK_DIV_Pos                                                   26U
#define PCC_REG_TIMER1_B_R_TIMER_8_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_B_R_TIMER_8_CLK_DIV_Pos)

#define PCC_REG_TIMER1_B_TIMER1_CH6_CLK_FORCE_Pos                                                29U
#define PCC_REG_TIMER1_B_TIMER1_CH6_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_B_TIMER1_CH6_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_B_TIMER1_CH7_CLK_FORCE_Pos                                                30U
#define PCC_REG_TIMER1_B_TIMER1_CH7_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_B_TIMER1_CH7_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_B_TIMER1_CH8_CLK_FORCE_Pos                                                31U
#define PCC_REG_TIMER1_B_TIMER1_CH8_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_B_TIMER1_CH8_CLK_FORCE_Pos)

/* 0x250    0x4000_0250
    7:0     R/W     RESERVED_11                                     8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b1
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    13      R/W     RESERVED_5                                      1'b1
    14      R/W     RESERVED_4                                      1'b1
    15      R/W     RESERVED_3                                      1'b1
    16      R/W     RESERVED_2                                      1'b1
    17      R/W     RESERVED_1                                      1'b1
    19:18   R/W     RESERVED                                        2'b0
    22:20   R/W     R_TIMER_9_CLK_DIV                               3'h0
    25:23   R/W     R_TIMER_10_CLK_DIV                              3'h0
    28:26   R/W     R_TIMER_11_CLK_DIV                              3'h0
    29      R/W     TIMER1_CH9_CLK_FORCE                            1'b0
    30      R/W     TIMER1_CH10_CLK_FORCE                           1'b0
    31      R/W     TIMER1_CH11_CLK_FORCE                           1'b0
 */
typedef union _PCC_REG_TIMER1_C_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_11: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 2;
        uint32_t R_TIMER_9_CLK_DIV: 3;
        uint32_t R_TIMER_10_CLK_DIV: 3;
        uint32_t R_TIMER_11_CLK_DIV: 3;
        uint32_t TIMER1_CH9_CLK_FORCE: 1;
        uint32_t TIMER1_CH10_CLK_FORCE: 1;
        uint32_t TIMER1_CH11_CLK_FORCE: 1;
    };
} PCC_REG_TIMER1_C_TYPE;

/*0x4000_0250 PCC_REG_TIMER1_C*/
#define PCC_REG_TIMER1_C_RESERVED_11_Pos                                                         0U
#define PCC_REG_TIMER1_C_RESERVED_11_Msk                                                         (0xFFUL << PCC_REG_TIMER1_C_RESERVED_11_Pos)

#define PCC_REG_TIMER1_C_RESERVED_10_Pos                                                         8U
#define PCC_REG_TIMER1_C_RESERVED_10_Msk                                                         (0x1UL << PCC_REG_TIMER1_C_RESERVED_10_Pos)

#define PCC_REG_TIMER1_C_RESERVED_9_Pos                                                          9U
#define PCC_REG_TIMER1_C_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_9_Pos)

#define PCC_REG_TIMER1_C_RESERVED_8_Pos                                                          10U
#define PCC_REG_TIMER1_C_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_8_Pos)

#define PCC_REG_TIMER1_C_RESERVED_7_Pos                                                          11U
#define PCC_REG_TIMER1_C_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_7_Pos)

#define PCC_REG_TIMER1_C_RESERVED_6_Pos                                                          12U
#define PCC_REG_TIMER1_C_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_6_Pos)

#define PCC_REG_TIMER1_C_RESERVED_5_Pos                                                          13U
#define PCC_REG_TIMER1_C_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_5_Pos)

#define PCC_REG_TIMER1_C_RESERVED_4_Pos                                                          14U
#define PCC_REG_TIMER1_C_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_4_Pos)

#define PCC_REG_TIMER1_C_RESERVED_3_Pos                                                          15U
#define PCC_REG_TIMER1_C_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_3_Pos)

#define PCC_REG_TIMER1_C_RESERVED_2_Pos                                                          16U
#define PCC_REG_TIMER1_C_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_2_Pos)

#define PCC_REG_TIMER1_C_RESERVED_1_Pos                                                          17U
#define PCC_REG_TIMER1_C_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_TIMER1_C_RESERVED_1_Pos)

#define PCC_REG_TIMER1_C_RESERVED_Pos                                                            18U
#define PCC_REG_TIMER1_C_RESERVED_Msk                                                            (0x3UL << PCC_REG_TIMER1_C_RESERVED_Pos)

#define PCC_REG_TIMER1_C_R_TIMER_9_CLK_DIV_Pos                                                   20U
#define PCC_REG_TIMER1_C_R_TIMER_9_CLK_DIV_Msk                                                   (0x7UL << PCC_REG_TIMER1_C_R_TIMER_9_CLK_DIV_Pos)

#define PCC_REG_TIMER1_C_R_TIMER_10_CLK_DIV_Pos                                                  23U
#define PCC_REG_TIMER1_C_R_TIMER_10_CLK_DIV_Msk                                                  (0x7UL << PCC_REG_TIMER1_C_R_TIMER_10_CLK_DIV_Pos)

#define PCC_REG_TIMER1_C_R_TIMER_11_CLK_DIV_Pos                                                  26U
#define PCC_REG_TIMER1_C_R_TIMER_11_CLK_DIV_Msk                                                  (0x7UL << PCC_REG_TIMER1_C_R_TIMER_11_CLK_DIV_Pos)

#define PCC_REG_TIMER1_C_TIMER1_CH9_CLK_FORCE_Pos                                                29U
#define PCC_REG_TIMER1_C_TIMER1_CH9_CLK_FORCE_Msk                                                (0x1UL << PCC_REG_TIMER1_C_TIMER1_CH9_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_C_TIMER1_CH10_CLK_FORCE_Pos                                               30U
#define PCC_REG_TIMER1_C_TIMER1_CH10_CLK_FORCE_Msk                                               (0x1UL << PCC_REG_TIMER1_C_TIMER1_CH10_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_C_TIMER1_CH11_CLK_FORCE_Pos                                               31U
#define PCC_REG_TIMER1_C_TIMER1_CH11_CLK_FORCE_Msk                                               (0x1UL << PCC_REG_TIMER1_C_TIMER1_CH11_CLK_FORCE_Pos)

/* 0x254    0x4000_0254
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER            8'b0
    8       R/W     RESERVED_12                                     1'b0
    9       R/W     RESERVED_11                                     1'b1
    10      R/W     RESERVED_10                                     1'b1
    11      R/W     RESERVED_9                                      1'b1
    12      R/W     RESERVED_8                                      1'b1
    13      R/W     RESERVED_7                                      1'b0
    14      R/W     RESERVED_6                                      1'b1
    15      R/W     RESERVED_5                                      1'b0
    16      R/W     RESERVED_4                                      1'b0
    19:17   R/W     R_ETIMER_CLK_DIV_SEL                            3'h0
    20      R/W     RSVD_2                                          1'h0
    21      R/W     RESERVED_3                                      1'b0
    22      R/W     RESERVED_2                                      1'b0
    23      R/W     ENHANCED_TIMER_CLK_FORCE                        1'b0
    26:24   R/W     RSVD_1                                          3'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_TIMER2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER: 8;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t R_ETIMER_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t ENHANCED_TIMER_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_TIMER2_TYPE;

/*0x4000_0254 PCC_REG_TIMER2*/
#define PCC_REG_TIMER2_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_Pos                                  0U
#define PCC_REG_TIMER2_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_Msk                                  (0xFFUL << PCC_REG_TIMER2_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_Pos)

#define PCC_REG_TIMER2_RESERVED_12_Pos                                                           8U
#define PCC_REG_TIMER2_RESERVED_12_Msk                                                           (0x1UL << PCC_REG_TIMER2_RESERVED_12_Pos)

#define PCC_REG_TIMER2_RESERVED_11_Pos                                                           9U
#define PCC_REG_TIMER2_RESERVED_11_Msk                                                           (0x1UL << PCC_REG_TIMER2_RESERVED_11_Pos)

#define PCC_REG_TIMER2_RESERVED_10_Pos                                                           10U
#define PCC_REG_TIMER2_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_TIMER2_RESERVED_10_Pos)

#define PCC_REG_TIMER2_RESERVED_9_Pos                                                            11U
#define PCC_REG_TIMER2_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_9_Pos)

#define PCC_REG_TIMER2_RESERVED_8_Pos                                                            12U
#define PCC_REG_TIMER2_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_8_Pos)

#define PCC_REG_TIMER2_RESERVED_7_Pos                                                            13U
#define PCC_REG_TIMER2_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_7_Pos)

#define PCC_REG_TIMER2_RESERVED_6_Pos                                                            14U
#define PCC_REG_TIMER2_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_6_Pos)

#define PCC_REG_TIMER2_RESERVED_5_Pos                                                            15U
#define PCC_REG_TIMER2_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_5_Pos)

#define PCC_REG_TIMER2_RESERVED_4_Pos                                                            16U
#define PCC_REG_TIMER2_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_4_Pos)

#define PCC_REG_TIMER2_R_ETIMER_CLK_DIV_SEL_Pos                                                  17U
#define PCC_REG_TIMER2_R_ETIMER_CLK_DIV_SEL_Msk                                                  (0x7UL << PCC_REG_TIMER2_R_ETIMER_CLK_DIV_SEL_Pos)

#define PCC_REG_TIMER2_RSVD_2_Pos                                                                20U
#define PCC_REG_TIMER2_RSVD_2_Msk                                                                (0x1UL << PCC_REG_TIMER2_RSVD_2_Pos)

#define PCC_REG_TIMER2_RESERVED_3_Pos                                                            21U
#define PCC_REG_TIMER2_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_3_Pos)

#define PCC_REG_TIMER2_RESERVED_2_Pos                                                            22U
#define PCC_REG_TIMER2_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_2_Pos)

#define PCC_REG_TIMER2_ENHANCED_TIMER_CLK_FORCE_Pos                                              23U
#define PCC_REG_TIMER2_ENHANCED_TIMER_CLK_FORCE_Msk                                              (0x1UL << PCC_REG_TIMER2_ENHANCED_TIMER_CLK_FORCE_Pos)

#define PCC_REG_TIMER2_RSVD_1_Pos                                                                24U
#define PCC_REG_TIMER2_RSVD_1_Msk                                                                (0x7UL << PCC_REG_TIMER2_RSVD_1_Pos)

#define PCC_REG_TIMER2_RESERVED_1_Pos                                                            27U
#define PCC_REG_TIMER2_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_TIMER2_RESERVED_1_Pos)

#define PCC_REG_TIMER2_RSVD_Pos                                                                  28U
#define PCC_REG_TIMER2_RSVD_Msk                                                                  (0x7UL << PCC_REG_TIMER2_RSVD_Pos)

#define PCC_REG_TIMER2_RESERVED_Pos                                                              31U
#define PCC_REG_TIMER2_RESERVED_Msk                                                              (0x1UL << PCC_REG_TIMER2_RESERVED_Pos)

/* 0x258    0x4000_0258
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_PWM        8'b0
    8       R/W     RESERVED_11                                     1'b0
    9       R/W     RESERVED_10                                     1'b1
    10      R/W     RESERVED_9                                      1'b1
    11      R/W     RESERVED_8                                      1'b0
    12      R/W     RESERVED_7                                      1'b1
    13      R/W     RESERVED_6                                      1'b0
    14      R/W     RESERVED_5                                      1'b1
    15      R/W     RESERVED_4                                      1'b0
    16      R/W     R_ETIMER_PWM_CLK_SRC_SEL                        1'b0
    19:17   R/W     R_ETIMER_PWM_CLK_DIV_SEL                        3'h0
    20      R/W     RSVD_2                                          1'h0
    21      R/W     RESERVED_3                                      1'b0
    22      R/W     RESERVED_2                                      1'b0
    23      R/W     ENHANCED_TIMER_PWM_CLK_FORCE                    1'b0
    26:24   R/W     RSVD_1                                          3'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_TIMER2_PWM_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_PWM: 8;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t R_ETIMER_PWM_CLK_SRC_SEL: 1;
        uint32_t R_ETIMER_PWM_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t ENHANCED_TIMER_PWM_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_TIMER2_PWM_TYPE;

/*0x4000_0258 PCC_REG_TIMER2_PWM*/
#define PCC_REG_TIMER2_PWM_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_PWM_Pos                          0U
#define PCC_REG_TIMER2_PWM_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_PWM_Msk                          (0xFFUL << PCC_REG_TIMER2_PWM_ENTRY_DELAY_CORE1_DEV_ENHANCED_TIMER_PWM_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_11_Pos                                                       8U
#define PCC_REG_TIMER2_PWM_RESERVED_11_Msk                                                       (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_11_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_10_Pos                                                       9U
#define PCC_REG_TIMER2_PWM_RESERVED_10_Msk                                                       (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_10_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_9_Pos                                                        10U
#define PCC_REG_TIMER2_PWM_RESERVED_9_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_9_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_8_Pos                                                        11U
#define PCC_REG_TIMER2_PWM_RESERVED_8_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_8_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_7_Pos                                                        12U
#define PCC_REG_TIMER2_PWM_RESERVED_7_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_7_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_6_Pos                                                        13U
#define PCC_REG_TIMER2_PWM_RESERVED_6_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_6_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_5_Pos                                                        14U
#define PCC_REG_TIMER2_PWM_RESERVED_5_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_5_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_4_Pos                                                        15U
#define PCC_REG_TIMER2_PWM_RESERVED_4_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_4_Pos)

#define PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_SRC_SEL_Pos                                          16U
#define PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_SRC_SEL_Msk                                          (0x1UL << PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_SRC_SEL_Pos)

#define PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_DIV_SEL_Pos                                          17U
#define PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_DIV_SEL_Msk                                          (0x7UL << PCC_REG_TIMER2_PWM_R_ETIMER_PWM_CLK_DIV_SEL_Pos)

#define PCC_REG_TIMER2_PWM_RSVD_2_Pos                                                            20U
#define PCC_REG_TIMER2_PWM_RSVD_2_Msk                                                            (0x1UL << PCC_REG_TIMER2_PWM_RSVD_2_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_3_Pos                                                        21U
#define PCC_REG_TIMER2_PWM_RESERVED_3_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_3_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_2_Pos                                                        22U
#define PCC_REG_TIMER2_PWM_RESERVED_2_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_2_Pos)

#define PCC_REG_TIMER2_PWM_ENHANCED_TIMER_PWM_CLK_FORCE_Pos                                      23U
#define PCC_REG_TIMER2_PWM_ENHANCED_TIMER_PWM_CLK_FORCE_Msk                                      (0x1UL << PCC_REG_TIMER2_PWM_ENHANCED_TIMER_PWM_CLK_FORCE_Pos)

#define PCC_REG_TIMER2_PWM_RSVD_1_Pos                                                            24U
#define PCC_REG_TIMER2_PWM_RSVD_1_Msk                                                            (0x7UL << PCC_REG_TIMER2_PWM_RSVD_1_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_1_Pos                                                        27U
#define PCC_REG_TIMER2_PWM_RESERVED_1_Msk                                                        (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_1_Pos)

#define PCC_REG_TIMER2_PWM_RSVD_Pos                                                              28U
#define PCC_REG_TIMER2_PWM_RSVD_Msk                                                              (0x7UL << PCC_REG_TIMER2_PWM_RSVD_Pos)

#define PCC_REG_TIMER2_PWM_RESERVED_Pos                                                          31U
#define PCC_REG_TIMER2_PWM_RESERVED_Msk                                                          (0x1UL << PCC_REG_TIMER2_PWM_RESERVED_Pos)

/* 0x25C    0x4000_025c
    7:0     R/W     ENTRY_DELAY_USB                                 8'b0
    8       R/W     RESERVED_9                                      1'b1
    9       R/W     RESERVED_8                                      1'b1
    10      R/W     RESERVED_7                                      1'b1
    11      R/W     RESERVED_6                                      1'b0
    12      R/W     RESERVED_5                                      1'b1
    13      R/W     RESERVED_4                                      1'b1
    15:14   R/W     RESERVED_3                                      2'b0
    16      R/W     R_USB_CLK_SRC_SEL                               1'b0
    20:17   R/W     R_USB_CLK_DIV_SEL                               4'h0
    21      R/W     RSVD_2                                          1'h0
    22      R/W     RESERVED_2                                      1'b0
    23      R/W     USB_CLK_FORCE                                   1'b0
    26:24   R/W     RSVD_1                                          3'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_USB_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_USB: 8;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 2;
        uint32_t R_USB_CLK_SRC_SEL: 1;
        uint32_t R_USB_CLK_DIV_SEL: 4;
        uint32_t RSVD_2: 1;
        uint32_t RESERVED_2: 1;
        uint32_t USB_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_USB_TYPE;

/*0x4000_025c PCC_REG_USB*/
#define PCC_REG_USB_ENTRY_DELAY_USB_Pos                                                          0U
#define PCC_REG_USB_ENTRY_DELAY_USB_Msk                                                          (0xFFUL << PCC_REG_USB_ENTRY_DELAY_USB_Pos)

#define PCC_REG_USB_RESERVED_9_Pos                                                               8U
#define PCC_REG_USB_RESERVED_9_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_9_Pos)

#define PCC_REG_USB_RESERVED_8_Pos                                                               9U
#define PCC_REG_USB_RESERVED_8_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_8_Pos)

#define PCC_REG_USB_RESERVED_7_Pos                                                               10U
#define PCC_REG_USB_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_7_Pos)

#define PCC_REG_USB_RESERVED_6_Pos                                                               11U
#define PCC_REG_USB_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_6_Pos)

#define PCC_REG_USB_RESERVED_5_Pos                                                               12U
#define PCC_REG_USB_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_5_Pos)

#define PCC_REG_USB_RESERVED_4_Pos                                                               13U
#define PCC_REG_USB_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_4_Pos)

#define PCC_REG_USB_RESERVED_3_Pos                                                               14U
#define PCC_REG_USB_RESERVED_3_Msk                                                               (0x3UL << PCC_REG_USB_RESERVED_3_Pos)

#define PCC_REG_USB_R_USB_CLK_SRC_SEL_Pos                                                        16U
#define PCC_REG_USB_R_USB_CLK_SRC_SEL_Msk                                                        (0x1UL << PCC_REG_USB_R_USB_CLK_SRC_SEL_Pos)

#define PCC_REG_USB_R_USB_CLK_DIV_SEL_Pos                                                        17U
#define PCC_REG_USB_R_USB_CLK_DIV_SEL_Msk                                                        (0xFUL << PCC_REG_USB_R_USB_CLK_DIV_SEL_Pos)

#define PCC_REG_USB_RSVD_2_Pos                                                                   21U
#define PCC_REG_USB_RSVD_2_Msk                                                                   (0x1UL << PCC_REG_USB_RSVD_2_Pos)

#define PCC_REG_USB_RESERVED_2_Pos                                                               22U
#define PCC_REG_USB_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_2_Pos)

#define PCC_REG_USB_USB_CLK_FORCE_Pos                                                            23U
#define PCC_REG_USB_USB_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_USB_USB_CLK_FORCE_Pos)

#define PCC_REG_USB_RSVD_1_Pos                                                                   24U
#define PCC_REG_USB_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_USB_RSVD_1_Pos)

#define PCC_REG_USB_RESERVED_1_Pos                                                               27U
#define PCC_REG_USB_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_USB_RESERVED_1_Pos)

#define PCC_REG_USB_RSVD_Pos                                                                     28U
#define PCC_REG_USB_RSVD_Msk                                                                     (0x7UL << PCC_REG_USB_RSVD_Pos)

#define PCC_REG_USB_RESERVED_Pos                                                                 31U
#define PCC_REG_USB_RESERVED_Msk                                                                 (0x1UL << PCC_REG_USB_RESERVED_Pos)

/* 0x260    0x4000_0260
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_AUXADC                    8'b0
    8       R/W     RESERVED_8                                      1'b0
    9       R/W     RESERVED_7                                      1'b1
    10      R/W     RESERVED_6                                      1'b1
    11      R/W     RESERVED_5                                      1'b1
    12      R/W     RESERVED_4                                      1'b1
    16:13   R/W     RESERVED_3                                      4'b0
    17      R/W     RESERVED_2                                      1'b0
    18      R/W     ADC_CLK_FORCE                                   1'b0
    26:19   R/W     RSVD_1                                          8'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_ADC_CONTROLLER_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_AUXADC: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 4;
        uint32_t RESERVED_2: 1;
        uint32_t ADC_CLK_FORCE: 1;
        uint32_t RSVD_1: 8;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_ADC_CONTROLLER_TYPE;

/*0x4000_0260 PCC_REG_ADC_CONTROLLER*/
#define PCC_REG_ADC_CONTROLLER_ENTRY_DELAY_CORE1_DEV_AUXADC_Pos                                  0U
#define PCC_REG_ADC_CONTROLLER_ENTRY_DELAY_CORE1_DEV_AUXADC_Msk                                  (0xFFUL << PCC_REG_ADC_CONTROLLER_ENTRY_DELAY_CORE1_DEV_AUXADC_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_8_Pos                                                    8U
#define PCC_REG_ADC_CONTROLLER_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_8_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_7_Pos                                                    9U
#define PCC_REG_ADC_CONTROLLER_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_7_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_6_Pos                                                    10U
#define PCC_REG_ADC_CONTROLLER_RESERVED_6_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_6_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_5_Pos                                                    11U
#define PCC_REG_ADC_CONTROLLER_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_5_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_4_Pos                                                    12U
#define PCC_REG_ADC_CONTROLLER_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_4_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_3_Pos                                                    13U
#define PCC_REG_ADC_CONTROLLER_RESERVED_3_Msk                                                    (0xFUL << PCC_REG_ADC_CONTROLLER_RESERVED_3_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_2_Pos                                                    17U
#define PCC_REG_ADC_CONTROLLER_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_2_Pos)

#define PCC_REG_ADC_CONTROLLER_ADC_CLK_FORCE_Pos                                                 18U
#define PCC_REG_ADC_CONTROLLER_ADC_CLK_FORCE_Msk                                                 (0x1UL << PCC_REG_ADC_CONTROLLER_ADC_CLK_FORCE_Pos)

#define PCC_REG_ADC_CONTROLLER_RSVD_1_Pos                                                        19U
#define PCC_REG_ADC_CONTROLLER_RSVD_1_Msk                                                        (0xFFUL << PCC_REG_ADC_CONTROLLER_RSVD_1_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_1_Pos                                                    27U
#define PCC_REG_ADC_CONTROLLER_RESERVED_1_Msk                                                    (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_1_Pos)

#define PCC_REG_ADC_CONTROLLER_RSVD_Pos                                                          28U
#define PCC_REG_ADC_CONTROLLER_RSVD_Msk                                                          (0x7UL << PCC_REG_ADC_CONTROLLER_RSVD_Pos)

#define PCC_REG_ADC_CONTROLLER_RESERVED_Pos                                                      31U
#define PCC_REG_ADC_CONTROLLER_RESERVED_Msk                                                      (0x1UL << PCC_REG_ADC_CONTROLLER_RESERVED_Pos)

/* 0x264    0x4000_0264
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_I2C0                      8'b0
    8       R/W     RESERVED_9                                      1'b0
    9       R/W     RESERVED_8                                      1'b1
    10      R/W     RESERVED_7                                      1'b1
    11      R/W     RESERVED_6                                      1'b1
    12      R/W     RESERVED_5                                      1'b1
    15:13   R/W     RESERVED_4                                      3'b0
    18:16   R/W     R_I2C0_CLK_DIV_SEL                              3'b000
    20:19   R/W     RSVD_2                                          2'h0
    21      R/W     RESERVED_3                                      1'b0
    22      R/W     RESERVED_2                                      1'b0
    23      R/W     I2C0_CLK_FORCE                                  1'b0
    26:24   R/W     RSVD_1                                          3'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_I2C0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_I2C0: 8;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 3;
        uint32_t R_I2C0_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 2;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t I2C0_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_I2C0_TYPE;

/*0x4000_0264 PCC_REG_I2C0*/
#define PCC_REG_I2C0_ENTRY_DELAY_CORE1_DEV_I2C0_Pos                                              0U
#define PCC_REG_I2C0_ENTRY_DELAY_CORE1_DEV_I2C0_Msk                                              (0xFFUL << PCC_REG_I2C0_ENTRY_DELAY_CORE1_DEV_I2C0_Pos)

#define PCC_REG_I2C0_RESERVED_9_Pos                                                              8U
#define PCC_REG_I2C0_RESERVED_9_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_9_Pos)

#define PCC_REG_I2C0_RESERVED_8_Pos                                                              9U
#define PCC_REG_I2C0_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_8_Pos)

#define PCC_REG_I2C0_RESERVED_7_Pos                                                              10U
#define PCC_REG_I2C0_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_7_Pos)

#define PCC_REG_I2C0_RESERVED_6_Pos                                                              11U
#define PCC_REG_I2C0_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_6_Pos)

#define PCC_REG_I2C0_RESERVED_5_Pos                                                              12U
#define PCC_REG_I2C0_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_5_Pos)

#define PCC_REG_I2C0_RESERVED_4_Pos                                                              13U
#define PCC_REG_I2C0_RESERVED_4_Msk                                                              (0x7UL << PCC_REG_I2C0_RESERVED_4_Pos)

#define PCC_REG_I2C0_R_I2C0_CLK_DIV_SEL_Pos                                                      16U
#define PCC_REG_I2C0_R_I2C0_CLK_DIV_SEL_Msk                                                      (0x7UL << PCC_REG_I2C0_R_I2C0_CLK_DIV_SEL_Pos)

#define PCC_REG_I2C0_RSVD_2_Pos                                                                  19U
#define PCC_REG_I2C0_RSVD_2_Msk                                                                  (0x3UL << PCC_REG_I2C0_RSVD_2_Pos)

#define PCC_REG_I2C0_RESERVED_3_Pos                                                              21U
#define PCC_REG_I2C0_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_3_Pos)

#define PCC_REG_I2C0_RESERVED_2_Pos                                                              22U
#define PCC_REG_I2C0_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_2_Pos)

#define PCC_REG_I2C0_I2C0_CLK_FORCE_Pos                                                          23U
#define PCC_REG_I2C0_I2C0_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_I2C0_I2C0_CLK_FORCE_Pos)

#define PCC_REG_I2C0_RSVD_1_Pos                                                                  24U
#define PCC_REG_I2C0_RSVD_1_Msk                                                                  (0x7UL << PCC_REG_I2C0_RSVD_1_Pos)

#define PCC_REG_I2C0_RESERVED_1_Pos                                                              27U
#define PCC_REG_I2C0_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_I2C0_RESERVED_1_Pos)

#define PCC_REG_I2C0_RSVD_Pos                                                                    28U
#define PCC_REG_I2C0_RSVD_Msk                                                                    (0x7UL << PCC_REG_I2C0_RSVD_Pos)

#define PCC_REG_I2C0_RESERVED_Pos                                                                31U
#define PCC_REG_I2C0_RESERVED_Msk                                                                (0x1UL << PCC_REG_I2C0_RESERVED_Pos)

/* 0x268    0x4000_0268
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_I2C1                      8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b1
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RESERVED_5                                      3'b0
    18:16   R/W     R_I2C1_CLK_DIV_SEL                              3'b000
    19      R/W     RSVD_2                                          1'h0
    20      R/W     RESERVED_4                                      1'b0
    21      R/W     RESERVED_3                                      1'b0
    22      R/W     I2C1_CLK_FORCE                                  1'b0
    25:23   R/W     RSVD_1                                          3'b000
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_I2C1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_I2C1: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 3;
        uint32_t R_I2C1_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t I2C1_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_I2C1_TYPE;

/*0x4000_0268 PCC_REG_I2C1*/
#define PCC_REG_I2C1_ENTRY_DELAY_CORE1_DEV_I2C1_Pos                                              0U
#define PCC_REG_I2C1_ENTRY_DELAY_CORE1_DEV_I2C1_Msk                                              (0xFFUL << PCC_REG_I2C1_ENTRY_DELAY_CORE1_DEV_I2C1_Pos)

#define PCC_REG_I2C1_RESERVED_10_Pos                                                             8U
#define PCC_REG_I2C1_RESERVED_10_Msk                                                             (0x1UL << PCC_REG_I2C1_RESERVED_10_Pos)

#define PCC_REG_I2C1_RESERVED_9_Pos                                                              9U
#define PCC_REG_I2C1_RESERVED_9_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_9_Pos)

#define PCC_REG_I2C1_RESERVED_8_Pos                                                              10U
#define PCC_REG_I2C1_RESERVED_8_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_8_Pos)

#define PCC_REG_I2C1_RESERVED_7_Pos                                                              11U
#define PCC_REG_I2C1_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_7_Pos)

#define PCC_REG_I2C1_RESERVED_6_Pos                                                              12U
#define PCC_REG_I2C1_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_6_Pos)

#define PCC_REG_I2C1_RESERVED_5_Pos                                                              13U
#define PCC_REG_I2C1_RESERVED_5_Msk                                                              (0x7UL << PCC_REG_I2C1_RESERVED_5_Pos)

#define PCC_REG_I2C1_R_I2C1_CLK_DIV_SEL_Pos                                                      16U
#define PCC_REG_I2C1_R_I2C1_CLK_DIV_SEL_Msk                                                      (0x7UL << PCC_REG_I2C1_R_I2C1_CLK_DIV_SEL_Pos)

#define PCC_REG_I2C1_RSVD_2_Pos                                                                  19U
#define PCC_REG_I2C1_RSVD_2_Msk                                                                  (0x1UL << PCC_REG_I2C1_RSVD_2_Pos)

#define PCC_REG_I2C1_RESERVED_4_Pos                                                              20U
#define PCC_REG_I2C1_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_4_Pos)

#define PCC_REG_I2C1_RESERVED_3_Pos                                                              21U
#define PCC_REG_I2C1_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_3_Pos)

#define PCC_REG_I2C1_I2C1_CLK_FORCE_Pos                                                          22U
#define PCC_REG_I2C1_I2C1_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_I2C1_I2C1_CLK_FORCE_Pos)

#define PCC_REG_I2C1_RSVD_1_Pos                                                                  23U
#define PCC_REG_I2C1_RSVD_1_Msk                                                                  (0x7UL << PCC_REG_I2C1_RSVD_1_Pos)

#define PCC_REG_I2C1_RESERVED_2_Pos                                                              26U
#define PCC_REG_I2C1_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_2_Pos)

#define PCC_REG_I2C1_RESERVED_1_Pos                                                              27U
#define PCC_REG_I2C1_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_I2C1_RESERVED_1_Pos)

#define PCC_REG_I2C1_RSVD_Pos                                                                    28U
#define PCC_REG_I2C1_RSVD_Msk                                                                    (0x7UL << PCC_REG_I2C1_RSVD_Pos)

#define PCC_REG_I2C1_RESERVED_Pos                                                                31U
#define PCC_REG_I2C1_RESERVED_Msk                                                                (0x1UL << PCC_REG_I2C1_RESERVED_Pos)

/* 0x26C    0x4000_026c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_KEYSCAN                   8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b1
    10      R/W     RESERVED_11                                     1'b1
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     KEYSCAN_CLK_FORCE                               1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_Keyscan_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_KEYSCAN: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t KEYSCAN_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_Keyscan_TYPE;

/*0x4000_026c PCC_REG_Keyscan*/
#define PCC_REG_Keyscan_ENTRY_DELAY_CORE1_DEV_KEYSCAN_Pos                                        0U
#define PCC_REG_Keyscan_ENTRY_DELAY_CORE1_DEV_KEYSCAN_Msk                                        (0xFFUL << PCC_REG_Keyscan_ENTRY_DELAY_CORE1_DEV_KEYSCAN_Pos)

#define PCC_REG_Keyscan_RESERVED_13_Pos                                                          8U
#define PCC_REG_Keyscan_RESERVED_13_Msk                                                          (0x1UL << PCC_REG_Keyscan_RESERVED_13_Pos)

#define PCC_REG_Keyscan_RESERVED_12_Pos                                                          9U
#define PCC_REG_Keyscan_RESERVED_12_Msk                                                          (0x1UL << PCC_REG_Keyscan_RESERVED_12_Pos)

#define PCC_REG_Keyscan_RESERVED_11_Pos                                                          10U
#define PCC_REG_Keyscan_RESERVED_11_Msk                                                          (0x1UL << PCC_REG_Keyscan_RESERVED_11_Pos)

#define PCC_REG_Keyscan_RESERVED_10_Pos                                                          11U
#define PCC_REG_Keyscan_RESERVED_10_Msk                                                          (0x1UL << PCC_REG_Keyscan_RESERVED_10_Pos)

#define PCC_REG_Keyscan_RESERVED_9_Pos                                                           12U
#define PCC_REG_Keyscan_RESERVED_9_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_9_Pos)

#define PCC_REG_Keyscan_RSVD_2_Pos                                                               13U
#define PCC_REG_Keyscan_RSVD_2_Msk                                                               (0x7UL << PCC_REG_Keyscan_RSVD_2_Pos)

#define PCC_REG_Keyscan_RESERVED_8_Pos                                                           16U
#define PCC_REG_Keyscan_RESERVED_8_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_8_Pos)

#define PCC_REG_Keyscan_RESERVED_7_Pos                                                           17U
#define PCC_REG_Keyscan_RESERVED_7_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_7_Pos)

#define PCC_REG_Keyscan_KEYSCAN_CLK_FORCE_Pos                                                    18U
#define PCC_REG_Keyscan_KEYSCAN_CLK_FORCE_Msk                                                    (0x1UL << PCC_REG_Keyscan_KEYSCAN_CLK_FORCE_Pos)

#define PCC_REG_Keyscan_RSVD_1_Pos                                                               19U
#define PCC_REG_Keyscan_RSVD_1_Msk                                                               (0x7UL << PCC_REG_Keyscan_RSVD_1_Pos)

#define PCC_REG_Keyscan_RESERVED_6_Pos                                                           22U
#define PCC_REG_Keyscan_RESERVED_6_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_6_Pos)

#define PCC_REG_Keyscan_RESERVED_5_Pos                                                           23U
#define PCC_REG_Keyscan_RESERVED_5_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_5_Pos)

#define PCC_REG_Keyscan_RESERVED_4_Pos                                                           24U
#define PCC_REG_Keyscan_RESERVED_4_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_4_Pos)

#define PCC_REG_Keyscan_RESERVED_3_Pos                                                           25U
#define PCC_REG_Keyscan_RESERVED_3_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_3_Pos)

#define PCC_REG_Keyscan_RESERVED_2_Pos                                                           26U
#define PCC_REG_Keyscan_RESERVED_2_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_2_Pos)

#define PCC_REG_Keyscan_RESERVED_1_Pos                                                           27U
#define PCC_REG_Keyscan_RESERVED_1_Msk                                                           (0x1UL << PCC_REG_Keyscan_RESERVED_1_Pos)

#define PCC_REG_Keyscan_RSVD_Pos                                                                 28U
#define PCC_REG_Keyscan_RSVD_Msk                                                                 (0x7UL << PCC_REG_Keyscan_RSVD_Pos)

#define PCC_REG_Keyscan_RESERVED_Pos                                                             31U
#define PCC_REG_Keyscan_RESERVED_Msk                                                             (0x1UL << PCC_REG_Keyscan_RESERVED_Pos)

/* 0x270    0x4000_0270
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SPI3W                     8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b1
    10      R/W     RESERVED_11                                     1'b1
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     SPI3W_CLK_FORCE                                 1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_SPI3W_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SPI3W: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t SPI3W_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_SPI3W_TYPE;

/*0x4000_0270 PCC_REG_SPI3W*/
#define PCC_REG_SPI3W_ENTRY_DELAY_CORE1_DEV_SPI3W_Pos                                            0U
#define PCC_REG_SPI3W_ENTRY_DELAY_CORE1_DEV_SPI3W_Msk                                            (0xFFUL << PCC_REG_SPI3W_ENTRY_DELAY_CORE1_DEV_SPI3W_Pos)

#define PCC_REG_SPI3W_RESERVED_13_Pos                                                            8U
#define PCC_REG_SPI3W_RESERVED_13_Msk                                                            (0x1UL << PCC_REG_SPI3W_RESERVED_13_Pos)

#define PCC_REG_SPI3W_RESERVED_12_Pos                                                            9U
#define PCC_REG_SPI3W_RESERVED_12_Msk                                                            (0x1UL << PCC_REG_SPI3W_RESERVED_12_Pos)

#define PCC_REG_SPI3W_RESERVED_11_Pos                                                            10U
#define PCC_REG_SPI3W_RESERVED_11_Msk                                                            (0x1UL << PCC_REG_SPI3W_RESERVED_11_Pos)

#define PCC_REG_SPI3W_RESERVED_10_Pos                                                            11U
#define PCC_REG_SPI3W_RESERVED_10_Msk                                                            (0x1UL << PCC_REG_SPI3W_RESERVED_10_Pos)

#define PCC_REG_SPI3W_RESERVED_9_Pos                                                             12U
#define PCC_REG_SPI3W_RESERVED_9_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_9_Pos)

#define PCC_REG_SPI3W_RSVD_2_Pos                                                                 13U
#define PCC_REG_SPI3W_RSVD_2_Msk                                                                 (0x7UL << PCC_REG_SPI3W_RSVD_2_Pos)

#define PCC_REG_SPI3W_RESERVED_8_Pos                                                             16U
#define PCC_REG_SPI3W_RESERVED_8_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_8_Pos)

#define PCC_REG_SPI3W_RESERVED_7_Pos                                                             17U
#define PCC_REG_SPI3W_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_7_Pos)

#define PCC_REG_SPI3W_SPI3W_CLK_FORCE_Pos                                                        18U
#define PCC_REG_SPI3W_SPI3W_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_SPI3W_SPI3W_CLK_FORCE_Pos)

#define PCC_REG_SPI3W_RSVD_1_Pos                                                                 19U
#define PCC_REG_SPI3W_RSVD_1_Msk                                                                 (0x7UL << PCC_REG_SPI3W_RSVD_1_Pos)

#define PCC_REG_SPI3W_RESERVED_6_Pos                                                             22U
#define PCC_REG_SPI3W_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_6_Pos)

#define PCC_REG_SPI3W_RESERVED_5_Pos                                                             23U
#define PCC_REG_SPI3W_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_5_Pos)

#define PCC_REG_SPI3W_RESERVED_4_Pos                                                             24U
#define PCC_REG_SPI3W_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_4_Pos)

#define PCC_REG_SPI3W_RESERVED_3_Pos                                                             25U
#define PCC_REG_SPI3W_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_3_Pos)

#define PCC_REG_SPI3W_RESERVED_2_Pos                                                             26U
#define PCC_REG_SPI3W_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_2_Pos)

#define PCC_REG_SPI3W_RESERVED_1_Pos                                                             27U
#define PCC_REG_SPI3W_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_SPI3W_RESERVED_1_Pos)

#define PCC_REG_SPI3W_RSVD_Pos                                                                   28U
#define PCC_REG_SPI3W_RSVD_Msk                                                                   (0x7UL << PCC_REG_SPI3W_RSVD_Pos)

#define PCC_REG_SPI3W_RESERVED_Pos                                                               31U
#define PCC_REG_SPI3W_RESERVED_Msk                                                               (0x1UL << PCC_REG_SPI3W_RESERVED_Pos)

/* 0x274    0x4000_0274
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_EFLASH_CTRL               8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b1
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b0
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_5                                      1'b0
    17      R/W     RESERVED_4                                      1'b0
    18      R/W     EFLASH_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_3                                      1'b0
    23      R/W     EFLASH_MANU_SEL                                 1'b0
    24      R/W     EFLASH_MANU_DAT                                 1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     LVCTL                                           1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_EFLASH_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_EFLASH_CTRL: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t EFLASH_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_3: 1;
        uint32_t EFLASH_MANU_SEL: 1;
        uint32_t EFLASH_MANU_DAT: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t LVCTL: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_EFLASH_TYPE;

/*0x4000_0274 PCC_REG_EFLASH*/
#define PCC_REG_EFLASH_ENTRY_DELAY_CORE1_DEV_EFLASH_CTRL_Pos                                     0U
#define PCC_REG_EFLASH_ENTRY_DELAY_CORE1_DEV_EFLASH_CTRL_Msk                                     (0xFFUL << PCC_REG_EFLASH_ENTRY_DELAY_CORE1_DEV_EFLASH_CTRL_Pos)

#define PCC_REG_EFLASH_RESERVED_10_Pos                                                           8U
#define PCC_REG_EFLASH_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_EFLASH_RESERVED_10_Pos)

#define PCC_REG_EFLASH_RESERVED_9_Pos                                                            9U
#define PCC_REG_EFLASH_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_9_Pos)

#define PCC_REG_EFLASH_RESERVED_8_Pos                                                            10U
#define PCC_REG_EFLASH_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_8_Pos)

#define PCC_REG_EFLASH_RESERVED_7_Pos                                                            11U
#define PCC_REG_EFLASH_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_7_Pos)

#define PCC_REG_EFLASH_RESERVED_6_Pos                                                            12U
#define PCC_REG_EFLASH_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_6_Pos)

#define PCC_REG_EFLASH_RSVD_2_Pos                                                                13U
#define PCC_REG_EFLASH_RSVD_2_Msk                                                                (0x7UL << PCC_REG_EFLASH_RSVD_2_Pos)

#define PCC_REG_EFLASH_RESERVED_5_Pos                                                            16U
#define PCC_REG_EFLASH_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_5_Pos)

#define PCC_REG_EFLASH_RESERVED_4_Pos                                                            17U
#define PCC_REG_EFLASH_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_4_Pos)

#define PCC_REG_EFLASH_EFLASH_CLK_FORCE_Pos                                                      18U
#define PCC_REG_EFLASH_EFLASH_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_EFLASH_EFLASH_CLK_FORCE_Pos)

#define PCC_REG_EFLASH_RSVD_1_Pos                                                                19U
#define PCC_REG_EFLASH_RSVD_1_Msk                                                                (0x7UL << PCC_REG_EFLASH_RSVD_1_Pos)

#define PCC_REG_EFLASH_RESERVED_3_Pos                                                            22U
#define PCC_REG_EFLASH_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_3_Pos)

#define PCC_REG_EFLASH_EFLASH_MANU_SEL_Pos                                                       23U
#define PCC_REG_EFLASH_EFLASH_MANU_SEL_Msk                                                       (0x1UL << PCC_REG_EFLASH_EFLASH_MANU_SEL_Pos)

#define PCC_REG_EFLASH_EFLASH_MANU_DAT_Pos                                                       24U
#define PCC_REG_EFLASH_EFLASH_MANU_DAT_Msk                                                       (0x1UL << PCC_REG_EFLASH_EFLASH_MANU_DAT_Pos)

#define PCC_REG_EFLASH_RESERVED_2_Pos                                                            25U
#define PCC_REG_EFLASH_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_2_Pos)

#define PCC_REG_EFLASH_RESERVED_1_Pos                                                            26U
#define PCC_REG_EFLASH_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_EFLASH_RESERVED_1_Pos)

#define PCC_REG_EFLASH_LVCTL_Pos                                                                 27U
#define PCC_REG_EFLASH_LVCTL_Msk                                                                 (0x1UL << PCC_REG_EFLASH_LVCTL_Pos)

#define PCC_REG_EFLASH_RSVD_Pos                                                                  28U
#define PCC_REG_EFLASH_RSVD_Msk                                                                  (0x7UL << PCC_REG_EFLASH_RSVD_Pos)

#define PCC_REG_EFLASH_RESERVED_Pos                                                              31U
#define PCC_REG_EFLASH_RESERVED_Msk                                                              (0x1UL << PCC_REG_EFLASH_RESERVED_Pos)

/* 0x278    0x4000_0278
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_CAN                       8'b0
    8       R/W     RESERVED_5                                      1'b0
    9       R/W     RESERVED_4                                      1'b1
    10      R/W     RESERVED_3                                      1'b1
    11      R/W     RESERVED_2                                      1'b1
    12      R/W     RESERVED_1                                      1'b1
    14:13   R/W     R_CAN_CLK_DIV                                   2'h0
    15      R/W     CAN_CLK_FORCE                                   1'b0
    23:16   R/W     ENTRY_DELAY_CORE1_DEV_CAN_LP                    8'b0
    24      R/W     CAN_LP_CLK_FORCE                                1'b0
    26:25   R/W     R_CAN_LP_CLK_DIV                                2'h0
    31:27   R/W     RESERVED                                        5'b0
 */
typedef union _PCC_REG_CAN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_CAN: 8;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t R_CAN_CLK_DIV: 2;
        uint32_t CAN_CLK_FORCE: 1;
        uint32_t ENTRY_DELAY_CORE1_DEV_CAN_LP: 8;
        uint32_t CAN_LP_CLK_FORCE: 1;
        uint32_t R_CAN_LP_CLK_DIV: 2;
        uint32_t RESERVED: 5;
    };
} PCC_REG_CAN_TYPE;

/*0x4000_0278 PCC_REG_CAN*/
#define PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_Pos                                                0U
#define PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_Msk                                                (0xFFUL << PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_Pos)

#define PCC_REG_CAN_RESERVED_5_Pos                                                               8U
#define PCC_REG_CAN_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_CAN_RESERVED_5_Pos)

#define PCC_REG_CAN_RESERVED_4_Pos                                                               9U
#define PCC_REG_CAN_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_CAN_RESERVED_4_Pos)

#define PCC_REG_CAN_RESERVED_3_Pos                                                               10U
#define PCC_REG_CAN_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_CAN_RESERVED_3_Pos)

#define PCC_REG_CAN_RESERVED_2_Pos                                                               11U
#define PCC_REG_CAN_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_CAN_RESERVED_2_Pos)

#define PCC_REG_CAN_RESERVED_1_Pos                                                               12U
#define PCC_REG_CAN_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_CAN_RESERVED_1_Pos)

#define PCC_REG_CAN_R_CAN_CLK_DIV_Pos                                                            13U
#define PCC_REG_CAN_R_CAN_CLK_DIV_Msk                                                            (0x3UL << PCC_REG_CAN_R_CAN_CLK_DIV_Pos)

#define PCC_REG_CAN_CAN_CLK_FORCE_Pos                                                            15U
#define PCC_REG_CAN_CAN_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_CAN_CAN_CLK_FORCE_Pos)

#define PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_LP_Pos                                             16U
#define PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_LP_Msk                                             (0xFFUL << PCC_REG_CAN_ENTRY_DELAY_CORE1_DEV_CAN_LP_Pos)

#define PCC_REG_CAN_CAN_LP_CLK_FORCE_Pos                                                         24U
#define PCC_REG_CAN_CAN_LP_CLK_FORCE_Msk                                                         (0x1UL << PCC_REG_CAN_CAN_LP_CLK_FORCE_Pos)

#define PCC_REG_CAN_R_CAN_LP_CLK_DIV_Pos                                                         25U
#define PCC_REG_CAN_R_CAN_LP_CLK_DIV_Msk                                                         (0x3UL << PCC_REG_CAN_R_CAN_LP_CLK_DIV_Pos)

#define PCC_REG_CAN_RESERVED_Pos                                                                 27U
#define PCC_REG_CAN_RESERVED_Msk                                                                 (0x1FUL << PCC_REG_CAN_RESERVED_Pos)

/* 0x27C    0x4000_027c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_GPIO_DBNC                 8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b0
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    18:16   R/W     DBNC_DIV_SEL                                    3'h001
    19      R/W     RSVD_1                                          1'h0
    20      R/W     GPIO_DBNC_2P4G_CLK_FORCE                        1'b0
    29:21   R/W     RSVD                                            9'b0
    30      R/W     RESERVED_1                                      1'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_GPIO_DEBOUNCE_2P4G_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_GPIO_DBNC: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t DBNC_DIV_SEL: 3;
        uint32_t RSVD_1: 1;
        uint32_t GPIO_DBNC_2P4G_CLK_FORCE: 1;
        uint32_t RSVD: 9;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
    };
} PCC_REG_GPIO_DEBOUNCE_2P4G_TYPE;

/*0x4000_027c PCC_REG_GPIO_DEBOUNCE_2P4G*/
#define PCC_REG_GPIO_DEBOUNCE_2P4G_ENTRY_DELAY_CORE1_DEV_GPIO_DBNC_Pos                           0U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_ENTRY_DELAY_CORE1_DEV_GPIO_DBNC_Msk                           (0xFFUL << PCC_REG_GPIO_DEBOUNCE_2P4G_ENTRY_DELAY_CORE1_DEV_GPIO_DBNC_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_7_Pos                                                8U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_7_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_7_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_6_Pos                                                9U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_6_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_6_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_5_Pos                                                10U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_5_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_5_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_4_Pos                                                11U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_4_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_4_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_3_Pos                                                12U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_3_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_3_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_2_Pos                                                13U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_2_Msk                                                (0x7UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_2_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_DBNC_DIV_SEL_Pos                                              16U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_DBNC_DIV_SEL_Msk                                              (0x7UL << PCC_REG_GPIO_DEBOUNCE_2P4G_DBNC_DIV_SEL_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_1_Pos                                                    19U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_1_Msk                                                    (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_1_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_GPIO_DBNC_2P4G_CLK_FORCE_Pos                                  20U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_GPIO_DBNC_2P4G_CLK_FORCE_Msk                                  (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_GPIO_DBNC_2P4G_CLK_FORCE_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_Pos                                                      21U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_Msk                                                      (0x1FFUL << PCC_REG_GPIO_DEBOUNCE_2P4G_RSVD_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_1_Pos                                                30U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_1_Msk                                                (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_1_Pos)

#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_Pos                                                  31U
#define PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_Msk                                                  (0x1UL << PCC_REG_GPIO_DEBOUNCE_2P4G_RESERVED_Pos)

/* 0x280    0x4000_0280
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_UART0                     8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    18:16   R/W     R_UART0_CLK_DIV_SEL                             3'h0
    19      R/W     RSVD_2                                          1'h0
    20      R/W     UART0_CLK_FORCE                                 1'b0
    25:21   R/W     RSVD_1                                          5'b000
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     UART0_PCLK_NO_LATENCY_EN                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_UART0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_UART0: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t R_UART0_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t UART0_CLK_FORCE: 1;
        uint32_t RSVD_1: 5;
        uint32_t RESERVED_1: 1;
        uint32_t UART0_PCLK_NO_LATENCY_EN: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_UART0_TYPE;

/*0x4000_0280 PCC_REG_UART0*/
#define PCC_REG_UART0_ENTRY_DELAY_CORE1_DEV_UART0_Pos                                            0U
#define PCC_REG_UART0_ENTRY_DELAY_CORE1_DEV_UART0_Msk                                            (0xFFUL << PCC_REG_UART0_ENTRY_DELAY_CORE1_DEV_UART0_Pos)

#define PCC_REG_UART0_RESERVED_7_Pos                                                             8U
#define PCC_REG_UART0_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_7_Pos)

#define PCC_REG_UART0_RESERVED_6_Pos                                                             9U
#define PCC_REG_UART0_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_6_Pos)

#define PCC_REG_UART0_RESERVED_5_Pos                                                             10U
#define PCC_REG_UART0_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_5_Pos)

#define PCC_REG_UART0_RESERVED_4_Pos                                                             11U
#define PCC_REG_UART0_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_4_Pos)

#define PCC_REG_UART0_RESERVED_3_Pos                                                             12U
#define PCC_REG_UART0_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_3_Pos)

#define PCC_REG_UART0_RESERVED_2_Pos                                                             13U
#define PCC_REG_UART0_RESERVED_2_Msk                                                             (0x7UL << PCC_REG_UART0_RESERVED_2_Pos)

#define PCC_REG_UART0_R_UART0_CLK_DIV_SEL_Pos                                                    16U
#define PCC_REG_UART0_R_UART0_CLK_DIV_SEL_Msk                                                    (0x7UL << PCC_REG_UART0_R_UART0_CLK_DIV_SEL_Pos)

#define PCC_REG_UART0_RSVD_2_Pos                                                                 19U
#define PCC_REG_UART0_RSVD_2_Msk                                                                 (0x1UL << PCC_REG_UART0_RSVD_2_Pos)

#define PCC_REG_UART0_UART0_CLK_FORCE_Pos                                                        20U
#define PCC_REG_UART0_UART0_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_UART0_UART0_CLK_FORCE_Pos)

#define PCC_REG_UART0_RSVD_1_Pos                                                                 21U
#define PCC_REG_UART0_RSVD_1_Msk                                                                 (0x1FUL << PCC_REG_UART0_RSVD_1_Pos)

#define PCC_REG_UART0_RESERVED_1_Pos                                                             26U
#define PCC_REG_UART0_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_UART0_RESERVED_1_Pos)

#define PCC_REG_UART0_UART0_PCLK_NO_LATENCY_EN_Pos                                               27U
#define PCC_REG_UART0_UART0_PCLK_NO_LATENCY_EN_Msk                                               (0x1UL << PCC_REG_UART0_UART0_PCLK_NO_LATENCY_EN_Pos)

#define PCC_REG_UART0_RSVD_Pos                                                                   28U
#define PCC_REG_UART0_RSVD_Msk                                                                   (0x7UL << PCC_REG_UART0_RSVD_Pos)

#define PCC_REG_UART0_RESERVED_Pos                                                               31U
#define PCC_REG_UART0_RESERVED_Msk                                                               (0x1UL << PCC_REG_UART0_RESERVED_Pos)

/* 0x284    0x4000_0284
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_UART1                     8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    18:16   R/W     R_UART1_CLK_DIV_SEL                             3'h0
    19      R/W     RSVD_2                                          1'h0
    20      R/W     UART1_CLK_FORCE                                 1'b0
    25:21   R/W     RSVD_1                                          5'b000
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     UART1_PCLK_NO_LATENCY_EN                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_UART1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_UART1: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t R_UART1_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t UART1_CLK_FORCE: 1;
        uint32_t RSVD_1: 5;
        uint32_t RESERVED_1: 1;
        uint32_t UART1_PCLK_NO_LATENCY_EN: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_UART1_TYPE;

/*0x4000_0284 PCC_REG_UART1*/
#define PCC_REG_UART1_ENTRY_DELAY_CORE1_DEV_UART1_Pos                                            0U
#define PCC_REG_UART1_ENTRY_DELAY_CORE1_DEV_UART1_Msk                                            (0xFFUL << PCC_REG_UART1_ENTRY_DELAY_CORE1_DEV_UART1_Pos)

#define PCC_REG_UART1_RESERVED_7_Pos                                                             8U
#define PCC_REG_UART1_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_7_Pos)

#define PCC_REG_UART1_RESERVED_6_Pos                                                             9U
#define PCC_REG_UART1_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_6_Pos)

#define PCC_REG_UART1_RESERVED_5_Pos                                                             10U
#define PCC_REG_UART1_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_5_Pos)

#define PCC_REG_UART1_RESERVED_4_Pos                                                             11U
#define PCC_REG_UART1_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_4_Pos)

#define PCC_REG_UART1_RESERVED_3_Pos                                                             12U
#define PCC_REG_UART1_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_3_Pos)

#define PCC_REG_UART1_RESERVED_2_Pos                                                             13U
#define PCC_REG_UART1_RESERVED_2_Msk                                                             (0x7UL << PCC_REG_UART1_RESERVED_2_Pos)

#define PCC_REG_UART1_R_UART1_CLK_DIV_SEL_Pos                                                    16U
#define PCC_REG_UART1_R_UART1_CLK_DIV_SEL_Msk                                                    (0x7UL << PCC_REG_UART1_R_UART1_CLK_DIV_SEL_Pos)

#define PCC_REG_UART1_RSVD_2_Pos                                                                 19U
#define PCC_REG_UART1_RSVD_2_Msk                                                                 (0x1UL << PCC_REG_UART1_RSVD_2_Pos)

#define PCC_REG_UART1_UART1_CLK_FORCE_Pos                                                        20U
#define PCC_REG_UART1_UART1_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_UART1_UART1_CLK_FORCE_Pos)

#define PCC_REG_UART1_RSVD_1_Pos                                                                 21U
#define PCC_REG_UART1_RSVD_1_Msk                                                                 (0x1FUL << PCC_REG_UART1_RSVD_1_Pos)

#define PCC_REG_UART1_RESERVED_1_Pos                                                             26U
#define PCC_REG_UART1_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_UART1_RESERVED_1_Pos)

#define PCC_REG_UART1_UART1_PCLK_NO_LATENCY_EN_Pos                                               27U
#define PCC_REG_UART1_UART1_PCLK_NO_LATENCY_EN_Msk                                               (0x1UL << PCC_REG_UART1_UART1_PCLK_NO_LATENCY_EN_Pos)

#define PCC_REG_UART1_RSVD_Pos                                                                   28U
#define PCC_REG_UART1_RSVD_Msk                                                                   (0x7UL << PCC_REG_UART1_RSVD_Pos)

#define PCC_REG_UART1_RESERVED_Pos                                                               31U
#define PCC_REG_UART1_RESERVED_Msk                                                               (0x1UL << PCC_REG_UART1_RESERVED_Pos)

/* 0x288    0x4000_0288
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_UART2                     8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    18:16   R/W     R_UART2_CLK_DIV_SEL                             3'h0
    19      R/W     RSVD_2                                          1'h0
    20      R/W     UART2_CLK_FORCE                                 1'b0
    25:21   R/W     RSVD_1                                          5'b000
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     UART2_PCLK_NO_LATENCY_EN                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_UART2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_UART2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t R_UART2_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t UART2_CLK_FORCE: 1;
        uint32_t RSVD_1: 5;
        uint32_t RESERVED_1: 1;
        uint32_t UART2_PCLK_NO_LATENCY_EN: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_UART2_TYPE;

/*0x4000_0288 PCC_REG_UART2*/
#define PCC_REG_UART2_ENTRY_DELAY_CORE1_DEV_UART2_Pos                                            0U
#define PCC_REG_UART2_ENTRY_DELAY_CORE1_DEV_UART2_Msk                                            (0xFFUL << PCC_REG_UART2_ENTRY_DELAY_CORE1_DEV_UART2_Pos)

#define PCC_REG_UART2_RESERVED_7_Pos                                                             8U
#define PCC_REG_UART2_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_7_Pos)

#define PCC_REG_UART2_RESERVED_6_Pos                                                             9U
#define PCC_REG_UART2_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_6_Pos)

#define PCC_REG_UART2_RESERVED_5_Pos                                                             10U
#define PCC_REG_UART2_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_5_Pos)

#define PCC_REG_UART2_RESERVED_4_Pos                                                             11U
#define PCC_REG_UART2_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_4_Pos)

#define PCC_REG_UART2_RESERVED_3_Pos                                                             12U
#define PCC_REG_UART2_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_3_Pos)

#define PCC_REG_UART2_RESERVED_2_Pos                                                             13U
#define PCC_REG_UART2_RESERVED_2_Msk                                                             (0x7UL << PCC_REG_UART2_RESERVED_2_Pos)

#define PCC_REG_UART2_R_UART2_CLK_DIV_SEL_Pos                                                    16U
#define PCC_REG_UART2_R_UART2_CLK_DIV_SEL_Msk                                                    (0x7UL << PCC_REG_UART2_R_UART2_CLK_DIV_SEL_Pos)

#define PCC_REG_UART2_RSVD_2_Pos                                                                 19U
#define PCC_REG_UART2_RSVD_2_Msk                                                                 (0x1UL << PCC_REG_UART2_RSVD_2_Pos)

#define PCC_REG_UART2_UART2_CLK_FORCE_Pos                                                        20U
#define PCC_REG_UART2_UART2_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_UART2_UART2_CLK_FORCE_Pos)

#define PCC_REG_UART2_RSVD_1_Pos                                                                 21U
#define PCC_REG_UART2_RSVD_1_Msk                                                                 (0x1FUL << PCC_REG_UART2_RSVD_1_Pos)

#define PCC_REG_UART2_RESERVED_1_Pos                                                             26U
#define PCC_REG_UART2_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_UART2_RESERVED_1_Pos)

#define PCC_REG_UART2_UART2_PCLK_NO_LATENCY_EN_Pos                                               27U
#define PCC_REG_UART2_UART2_PCLK_NO_LATENCY_EN_Msk                                               (0x1UL << PCC_REG_UART2_UART2_PCLK_NO_LATENCY_EN_Pos)

#define PCC_REG_UART2_RSVD_Pos                                                                   28U
#define PCC_REG_UART2_RSVD_Msk                                                                   (0x7UL << PCC_REG_UART2_RSVD_Pos)

#define PCC_REG_UART2_RESERVED_Pos                                                               31U
#define PCC_REG_UART2_RESERVED_Msk                                                               (0x1UL << PCC_REG_UART2_RESERVED_Pos)

/* 0x28C    0x4000_028c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_UART3                     8'b0
    8       R/W     RESERVED_7                                      1'b0
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    18:16   R/W     R_UART3_CLK_DIV_SEL                             3'h0
    19      R/W     RSVD_2                                          1'h0
    20      R/W     UART3_CLK_FORCE                                 1'b0
    25:21   R/W     RSVD_1                                          5'b000
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     UART3_PCLK_NO_LATENCY_EN                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_UART3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_UART3: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t R_UART3_CLK_DIV_SEL: 3;
        uint32_t RSVD_2: 1;
        uint32_t UART3_CLK_FORCE: 1;
        uint32_t RSVD_1: 5;
        uint32_t RESERVED_1: 1;
        uint32_t UART3_PCLK_NO_LATENCY_EN: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_UART3_TYPE;

/*0x4000_028c PCC_REG_UART3*/
#define PCC_REG_UART3_ENTRY_DELAY_CORE1_DEV_UART3_Pos                                            0U
#define PCC_REG_UART3_ENTRY_DELAY_CORE1_DEV_UART3_Msk                                            (0xFFUL << PCC_REG_UART3_ENTRY_DELAY_CORE1_DEV_UART3_Pos)

#define PCC_REG_UART3_RESERVED_7_Pos                                                             8U
#define PCC_REG_UART3_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_7_Pos)

#define PCC_REG_UART3_RESERVED_6_Pos                                                             9U
#define PCC_REG_UART3_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_6_Pos)

#define PCC_REG_UART3_RESERVED_5_Pos                                                             10U
#define PCC_REG_UART3_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_5_Pos)

#define PCC_REG_UART3_RESERVED_4_Pos                                                             11U
#define PCC_REG_UART3_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_4_Pos)

#define PCC_REG_UART3_RESERVED_3_Pos                                                             12U
#define PCC_REG_UART3_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_3_Pos)

#define PCC_REG_UART3_RESERVED_2_Pos                                                             13U
#define PCC_REG_UART3_RESERVED_2_Msk                                                             (0x7UL << PCC_REG_UART3_RESERVED_2_Pos)

#define PCC_REG_UART3_R_UART3_CLK_DIV_SEL_Pos                                                    16U
#define PCC_REG_UART3_R_UART3_CLK_DIV_SEL_Msk                                                    (0x7UL << PCC_REG_UART3_R_UART3_CLK_DIV_SEL_Pos)

#define PCC_REG_UART3_RSVD_2_Pos                                                                 19U
#define PCC_REG_UART3_RSVD_2_Msk                                                                 (0x1UL << PCC_REG_UART3_RSVD_2_Pos)

#define PCC_REG_UART3_UART3_CLK_FORCE_Pos                                                        20U
#define PCC_REG_UART3_UART3_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_UART3_UART3_CLK_FORCE_Pos)

#define PCC_REG_UART3_RSVD_1_Pos                                                                 21U
#define PCC_REG_UART3_RSVD_1_Msk                                                                 (0x1FUL << PCC_REG_UART3_RSVD_1_Pos)

#define PCC_REG_UART3_RESERVED_1_Pos                                                             26U
#define PCC_REG_UART3_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_UART3_RESERVED_1_Pos)

#define PCC_REG_UART3_UART3_PCLK_NO_LATENCY_EN_Pos                                               27U
#define PCC_REG_UART3_UART3_PCLK_NO_LATENCY_EN_Msk                                               (0x1UL << PCC_REG_UART3_UART3_PCLK_NO_LATENCY_EN_Pos)

#define PCC_REG_UART3_RSVD_Pos                                                                   28U
#define PCC_REG_UART3_RSVD_Msk                                                                   (0x7UL << PCC_REG_UART3_RSVD_Pos)

#define PCC_REG_UART3_RESERVED_Pos                                                               31U
#define PCC_REG_UART3_RESERVED_Msk                                                               (0x1UL << PCC_REG_UART3_RESERVED_Pos)

/* 0x290    0x4000_0290
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_RTKGPIO                   8'b0
    8       R/W     RESERVED_11                                     1'b0
    9       R/W     RESERVED_10                                     1'b1
    10      R/W     RESERVED_9                                      1'b0
    11      R/W     RESERVED_8                                      1'b1
    12      R/W     RESERVED_7                                      1'b1
    13      R/W     RESERVED_6                                      1'b1
    14      R/W     RESERVED_5                                      1'b1
    15      R/W     RESERVED_4                                      1'b0
    16      R/W     RESERVED_3                                      1'b0
    17      R/W     RESERVED_2                                      1'b0
    18      R/W     GPIOA_CLK_FORCE                                 1'b0
    29:19   R/W     RSVD                                            11'b0
    30      R/W     RESERVED_1                                      1'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_GPIOA_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_RTKGPIO: 8;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t GPIOA_CLK_FORCE: 1;
        uint32_t RSVD: 11;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
    };
} PCC_REG_GPIOA_TYPE;

/*0x4000_0290 PCC_REG_GPIOA*/
#define PCC_REG_GPIOA_ENTRY_DELAY_CORE1_DEV_RTKGPIO_Pos                                          0U
#define PCC_REG_GPIOA_ENTRY_DELAY_CORE1_DEV_RTKGPIO_Msk                                          (0xFFUL << PCC_REG_GPIOA_ENTRY_DELAY_CORE1_DEV_RTKGPIO_Pos)

#define PCC_REG_GPIOA_RESERVED_11_Pos                                                            8U
#define PCC_REG_GPIOA_RESERVED_11_Msk                                                            (0x1UL << PCC_REG_GPIOA_RESERVED_11_Pos)

#define PCC_REG_GPIOA_RESERVED_10_Pos                                                            9U
#define PCC_REG_GPIOA_RESERVED_10_Msk                                                            (0x1UL << PCC_REG_GPIOA_RESERVED_10_Pos)

#define PCC_REG_GPIOA_RESERVED_9_Pos                                                             10U
#define PCC_REG_GPIOA_RESERVED_9_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_9_Pos)

#define PCC_REG_GPIOA_RESERVED_8_Pos                                                             11U
#define PCC_REG_GPIOA_RESERVED_8_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_8_Pos)

#define PCC_REG_GPIOA_RESERVED_7_Pos                                                             12U
#define PCC_REG_GPIOA_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_7_Pos)

#define PCC_REG_GPIOA_RESERVED_6_Pos                                                             13U
#define PCC_REG_GPIOA_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_6_Pos)

#define PCC_REG_GPIOA_RESERVED_5_Pos                                                             14U
#define PCC_REG_GPIOA_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_5_Pos)

#define PCC_REG_GPIOA_RESERVED_4_Pos                                                             15U
#define PCC_REG_GPIOA_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_4_Pos)

#define PCC_REG_GPIOA_RESERVED_3_Pos                                                             16U
#define PCC_REG_GPIOA_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_3_Pos)

#define PCC_REG_GPIOA_RESERVED_2_Pos                                                             17U
#define PCC_REG_GPIOA_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_2_Pos)

#define PCC_REG_GPIOA_GPIOA_CLK_FORCE_Pos                                                        18U
#define PCC_REG_GPIOA_GPIOA_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_GPIOA_GPIOA_CLK_FORCE_Pos)

#define PCC_REG_GPIOA_RSVD_Pos                                                                   19U
#define PCC_REG_GPIOA_RSVD_Msk                                                                   (0x7FFUL << PCC_REG_GPIOA_RSVD_Pos)

#define PCC_REG_GPIOA_RESERVED_1_Pos                                                             30U
#define PCC_REG_GPIOA_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_GPIOA_RESERVED_1_Pos)

#define PCC_REG_GPIOA_RESERVED_Pos                                                               31U
#define PCC_REG_GPIOA_RESERVED_Msk                                                               (0x1UL << PCC_REG_GPIOA_RESERVED_Pos)

/* 0x294    0x4000_0294
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_MODEM                     8'b0
    8       R/W     RESERVED_7                                      1'b1
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    14:13   R/W     RESERVED_2                                      2'b0
    15      R/W     R_MODEM_CLK_SEL_CK1_FORCE                       1'b0
    16      R/W     R_MODEM_CLK_SRC_SEL                             1'b1
    17      R/W     RSVD_4                                          1'h0
    18      R/W     MODEM_CLK_FORCE                                 1'b0
    21:19   R/W     RSVD_3                                          3'b000
    22      R/W     RESERVED_1                                      1'b0
    23      R/W     RSVD_2                                          1'b0
    24      R/W     RSVD_1                                          1'b0
    30:25   R/W     RSVD                                            6'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_MODEM_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_MODEM: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 2;
        uint32_t R_MODEM_CLK_SEL_CK1_FORCE: 1;
        uint32_t R_MODEM_CLK_SRC_SEL: 1;
        uint32_t RSVD_4: 1;
        uint32_t MODEM_CLK_FORCE: 1;
        uint32_t RSVD_3: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 6;
        uint32_t RESERVED: 1;
    };
} PCC_REG_MODEM_TYPE;

/*0x4000_0294 PCC_REG_MODEM*/
#define PCC_REG_MODEM_ENTRY_DELAY_CORE1_DEV_MODEM_Pos                                            0U
#define PCC_REG_MODEM_ENTRY_DELAY_CORE1_DEV_MODEM_Msk                                            (0xFFUL << PCC_REG_MODEM_ENTRY_DELAY_CORE1_DEV_MODEM_Pos)

#define PCC_REG_MODEM_RESERVED_7_Pos                                                             8U
#define PCC_REG_MODEM_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_7_Pos)

#define PCC_REG_MODEM_RESERVED_6_Pos                                                             9U
#define PCC_REG_MODEM_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_6_Pos)

#define PCC_REG_MODEM_RESERVED_5_Pos                                                             10U
#define PCC_REG_MODEM_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_5_Pos)

#define PCC_REG_MODEM_RESERVED_4_Pos                                                             11U
#define PCC_REG_MODEM_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_4_Pos)

#define PCC_REG_MODEM_RESERVED_3_Pos                                                             12U
#define PCC_REG_MODEM_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_3_Pos)

#define PCC_REG_MODEM_RESERVED_2_Pos                                                             13U
#define PCC_REG_MODEM_RESERVED_2_Msk                                                             (0x3UL << PCC_REG_MODEM_RESERVED_2_Pos)

#define PCC_REG_MODEM_R_MODEM_CLK_SEL_CK1_FORCE_Pos                                              15U
#define PCC_REG_MODEM_R_MODEM_CLK_SEL_CK1_FORCE_Msk                                              (0x1UL << PCC_REG_MODEM_R_MODEM_CLK_SEL_CK1_FORCE_Pos)

#define PCC_REG_MODEM_R_MODEM_CLK_SRC_SEL_Pos                                                    16U
#define PCC_REG_MODEM_R_MODEM_CLK_SRC_SEL_Msk                                                    (0x1UL << PCC_REG_MODEM_R_MODEM_CLK_SRC_SEL_Pos)

#define PCC_REG_MODEM_RSVD_4_Pos                                                                 17U
#define PCC_REG_MODEM_RSVD_4_Msk                                                                 (0x1UL << PCC_REG_MODEM_RSVD_4_Pos)

#define PCC_REG_MODEM_MODEM_CLK_FORCE_Pos                                                        18U
#define PCC_REG_MODEM_MODEM_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_MODEM_MODEM_CLK_FORCE_Pos)

#define PCC_REG_MODEM_RSVD_3_Pos                                                                 19U
#define PCC_REG_MODEM_RSVD_3_Msk                                                                 (0x7UL << PCC_REG_MODEM_RSVD_3_Pos)

#define PCC_REG_MODEM_RESERVED_1_Pos                                                             22U
#define PCC_REG_MODEM_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_MODEM_RESERVED_1_Pos)

#define PCC_REG_MODEM_RSVD_2_Pos                                                                 23U
#define PCC_REG_MODEM_RSVD_2_Msk                                                                 (0x1UL << PCC_REG_MODEM_RSVD_2_Pos)

#define PCC_REG_MODEM_RSVD_1_Pos                                                                 24U
#define PCC_REG_MODEM_RSVD_1_Msk                                                                 (0x1UL << PCC_REG_MODEM_RSVD_1_Pos)

#define PCC_REG_MODEM_RSVD_Pos                                                                   25U
#define PCC_REG_MODEM_RSVD_Msk                                                                   (0x3FUL << PCC_REG_MODEM_RSVD_Pos)

#define PCC_REG_MODEM_RESERVED_Pos                                                               31U
#define PCC_REG_MODEM_RESERVED_Msk                                                               (0x1UL << PCC_REG_MODEM_RESERVED_Pos)

/* 0x298    0x4000_0298
    7:0     R/W     RESERVED_16                                     8'b0
    8       R/W     RESERVED_15                                     1'b0
    9       R/W     RESERVED_14                                     1'b1
    10      R/W     RESERVED_13                                     1'b1
    11      R/W     RESERVED_12                                     1'b1
    12      R/W     RESERVED_11                                     1'b1
    13      R/W     RESERVED_10                                     1'b0
    14      R/W     RESERVED_9                                      1'b0
    15      R/W     RSVD_2                                          1'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     PRO24G_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PROPRIETARY_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_16: 8;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t PRO24G_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PROPRIETARY_TYPE;

/*0x4000_0298 PCC_REG_PROPRIETARY*/
#define PCC_REG_PROPRIETARY_RESERVED_16_Pos                                                      0U
#define PCC_REG_PROPRIETARY_RESERVED_16_Msk                                                      (0xFFUL << PCC_REG_PROPRIETARY_RESERVED_16_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_15_Pos                                                      8U
#define PCC_REG_PROPRIETARY_RESERVED_15_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_15_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_14_Pos                                                      9U
#define PCC_REG_PROPRIETARY_RESERVED_14_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_14_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_13_Pos                                                      10U
#define PCC_REG_PROPRIETARY_RESERVED_13_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_13_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_12_Pos                                                      11U
#define PCC_REG_PROPRIETARY_RESERVED_12_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_12_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_11_Pos                                                      12U
#define PCC_REG_PROPRIETARY_RESERVED_11_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_11_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_10_Pos                                                      13U
#define PCC_REG_PROPRIETARY_RESERVED_10_Msk                                                      (0x1UL << PCC_REG_PROPRIETARY_RESERVED_10_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_9_Pos                                                       14U
#define PCC_REG_PROPRIETARY_RESERVED_9_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_9_Pos)

#define PCC_REG_PROPRIETARY_RSVD_2_Pos                                                           15U
#define PCC_REG_PROPRIETARY_RSVD_2_Msk                                                           (0x1UL << PCC_REG_PROPRIETARY_RSVD_2_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_8_Pos                                                       16U
#define PCC_REG_PROPRIETARY_RESERVED_8_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_8_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_7_Pos                                                       17U
#define PCC_REG_PROPRIETARY_RESERVED_7_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_7_Pos)

#define PCC_REG_PROPRIETARY_PRO24G_CLK_FORCE_Pos                                                 18U
#define PCC_REG_PROPRIETARY_PRO24G_CLK_FORCE_Msk                                                 (0x1UL << PCC_REG_PROPRIETARY_PRO24G_CLK_FORCE_Pos)

#define PCC_REG_PROPRIETARY_RSVD_1_Pos                                                           19U
#define PCC_REG_PROPRIETARY_RSVD_1_Msk                                                           (0x7UL << PCC_REG_PROPRIETARY_RSVD_1_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_6_Pos                                                       22U
#define PCC_REG_PROPRIETARY_RESERVED_6_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_6_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_5_Pos                                                       23U
#define PCC_REG_PROPRIETARY_RESERVED_5_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_5_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_4_Pos                                                       24U
#define PCC_REG_PROPRIETARY_RESERVED_4_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_4_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_3_Pos                                                       25U
#define PCC_REG_PROPRIETARY_RESERVED_3_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_3_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_2_Pos                                                       26U
#define PCC_REG_PROPRIETARY_RESERVED_2_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_2_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_1_Pos                                                       27U
#define PCC_REG_PROPRIETARY_RESERVED_1_Msk                                                       (0x1UL << PCC_REG_PROPRIETARY_RESERVED_1_Pos)

#define PCC_REG_PROPRIETARY_RSVD_Pos                                                             28U
#define PCC_REG_PROPRIETARY_RSVD_Msk                                                             (0x7UL << PCC_REG_PROPRIETARY_RSVD_Pos)

#define PCC_REG_PROPRIETARY_RESERVED_Pos                                                         31U
#define PCC_REG_PROPRIETARY_RESERVED_Msk                                                         (0x1UL << PCC_REG_PROPRIETARY_RESERVED_Pos)

/* 0x29C    0x4000_029c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_IR_RC                     8'b0
    8       R/W     RESERVED_7                                      1'b1
    9       R/W     RESERVED_6                                      1'b1
    10      R/W     RESERVED_5                                      1'b1
    11      R/W     RESERVED_4                                      1'b1
    12      R/W     RESERVED_3                                      1'b1
    15:13   R/W     RESERVED_2                                      3'b0
    16      R/W     R_SCLK_IRRC_SRC_SEL_0                           1'b1
    17      R/W     R_SCLK_IRRC_SRC_SEL_1                           1'b0
    18      R/W     IRRC_CLK_FORCE                                  1'b0
    26:19   R/W     RSVD_1                                          8'b000
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_IR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_IR_RC: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t R_SCLK_IRRC_SRC_SEL_0: 1;
        uint32_t R_SCLK_IRRC_SRC_SEL_1: 1;
        uint32_t IRRC_CLK_FORCE: 1;
        uint32_t RSVD_1: 8;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_IR_TYPE;

/*0x4000_029c PCC_REG_IR*/
#define PCC_REG_IR_ENTRY_DELAY_CORE1_DEV_IR_RC_Pos                                               0U
#define PCC_REG_IR_ENTRY_DELAY_CORE1_DEV_IR_RC_Msk                                               (0xFFUL << PCC_REG_IR_ENTRY_DELAY_CORE1_DEV_IR_RC_Pos)

#define PCC_REG_IR_RESERVED_7_Pos                                                                8U
#define PCC_REG_IR_RESERVED_7_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_7_Pos)

#define PCC_REG_IR_RESERVED_6_Pos                                                                9U
#define PCC_REG_IR_RESERVED_6_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_6_Pos)

#define PCC_REG_IR_RESERVED_5_Pos                                                                10U
#define PCC_REG_IR_RESERVED_5_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_5_Pos)

#define PCC_REG_IR_RESERVED_4_Pos                                                                11U
#define PCC_REG_IR_RESERVED_4_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_4_Pos)

#define PCC_REG_IR_RESERVED_3_Pos                                                                12U
#define PCC_REG_IR_RESERVED_3_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_3_Pos)

#define PCC_REG_IR_RESERVED_2_Pos                                                                13U
#define PCC_REG_IR_RESERVED_2_Msk                                                                (0x7UL << PCC_REG_IR_RESERVED_2_Pos)

#define PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos                                                     16U
#define PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Msk                                                     (0x1UL << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos)

#define PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_1_Pos                                                     17U
#define PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_1_Msk                                                     (0x1UL << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_1_Pos)

#define PCC_REG_IR_IRRC_CLK_FORCE_Pos                                                            18U
#define PCC_REG_IR_IRRC_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_IR_IRRC_CLK_FORCE_Pos)

#define PCC_REG_IR_RSVD_1_Pos                                                                    19U
#define PCC_REG_IR_RSVD_1_Msk                                                                    (0xFFUL << PCC_REG_IR_RSVD_1_Pos)

#define PCC_REG_IR_RESERVED_1_Pos                                                                27U
#define PCC_REG_IR_RESERVED_1_Msk                                                                (0x1UL << PCC_REG_IR_RESERVED_1_Pos)

#define PCC_REG_IR_RSVD_Pos                                                                      28U
#define PCC_REG_IR_RSVD_Msk                                                                      (0x7UL << PCC_REG_IR_RSVD_Pos)

#define PCC_REG_IR_RESERVED_Pos                                                                  31U
#define PCC_REG_IR_RESERVED_Msk                                                                  (0x1UL << PCC_REG_IR_RESERVED_Pos)

/* 0x2A0    0x4000_02a0
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_BT_VENDOR_REG             8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b0
    10      R/W     RESERVED_11                                     1'b0
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b0
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     BT_VDREG_CLK_FORCE                              1'b0
    18      R/W     RESERVED_7                                      1'b1
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_BT_VDREG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_BT_VENDOR_REG: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t BT_VDREG_CLK_FORCE: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_BT_VDREG_TYPE;

/*0x4000_02a0 PCC_REG_BT_VDREG*/
#define PCC_REG_BT_VDREG_ENTRY_DELAY_CORE1_DEV_BT_VENDOR_REG_Pos                                 0U
#define PCC_REG_BT_VDREG_ENTRY_DELAY_CORE1_DEV_BT_VENDOR_REG_Msk                                 (0xFFUL << PCC_REG_BT_VDREG_ENTRY_DELAY_CORE1_DEV_BT_VENDOR_REG_Pos)

#define PCC_REG_BT_VDREG_RESERVED_13_Pos                                                         8U
#define PCC_REG_BT_VDREG_RESERVED_13_Msk                                                         (0x1UL << PCC_REG_BT_VDREG_RESERVED_13_Pos)

#define PCC_REG_BT_VDREG_RESERVED_12_Pos                                                         9U
#define PCC_REG_BT_VDREG_RESERVED_12_Msk                                                         (0x1UL << PCC_REG_BT_VDREG_RESERVED_12_Pos)

#define PCC_REG_BT_VDREG_RESERVED_11_Pos                                                         10U
#define PCC_REG_BT_VDREG_RESERVED_11_Msk                                                         (0x1UL << PCC_REG_BT_VDREG_RESERVED_11_Pos)

#define PCC_REG_BT_VDREG_RESERVED_10_Pos                                                         11U
#define PCC_REG_BT_VDREG_RESERVED_10_Msk                                                         (0x1UL << PCC_REG_BT_VDREG_RESERVED_10_Pos)

#define PCC_REG_BT_VDREG_RESERVED_9_Pos                                                          12U
#define PCC_REG_BT_VDREG_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_9_Pos)

#define PCC_REG_BT_VDREG_RSVD_2_Pos                                                              13U
#define PCC_REG_BT_VDREG_RSVD_2_Msk                                                              (0x7UL << PCC_REG_BT_VDREG_RSVD_2_Pos)

#define PCC_REG_BT_VDREG_RESERVED_8_Pos                                                          16U
#define PCC_REG_BT_VDREG_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_8_Pos)

#define PCC_REG_BT_VDREG_BT_VDREG_CLK_FORCE_Pos                                                  17U
#define PCC_REG_BT_VDREG_BT_VDREG_CLK_FORCE_Msk                                                  (0x1UL << PCC_REG_BT_VDREG_BT_VDREG_CLK_FORCE_Pos)

#define PCC_REG_BT_VDREG_RESERVED_7_Pos                                                          18U
#define PCC_REG_BT_VDREG_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_7_Pos)

#define PCC_REG_BT_VDREG_RSVD_1_Pos                                                              19U
#define PCC_REG_BT_VDREG_RSVD_1_Msk                                                              (0x7UL << PCC_REG_BT_VDREG_RSVD_1_Pos)

#define PCC_REG_BT_VDREG_RESERVED_6_Pos                                                          22U
#define PCC_REG_BT_VDREG_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_6_Pos)

#define PCC_REG_BT_VDREG_RESERVED_5_Pos                                                          23U
#define PCC_REG_BT_VDREG_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_5_Pos)

#define PCC_REG_BT_VDREG_RESERVED_4_Pos                                                          24U
#define PCC_REG_BT_VDREG_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_4_Pos)

#define PCC_REG_BT_VDREG_RESERVED_3_Pos                                                          25U
#define PCC_REG_BT_VDREG_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_3_Pos)

#define PCC_REG_BT_VDREG_RESERVED_2_Pos                                                          26U
#define PCC_REG_BT_VDREG_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_2_Pos)

#define PCC_REG_BT_VDREG_RESERVED_1_Pos                                                          27U
#define PCC_REG_BT_VDREG_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_BT_VDREG_RESERVED_1_Pos)

#define PCC_REG_BT_VDREG_RSVD_Pos                                                                28U
#define PCC_REG_BT_VDREG_RSVD_Msk                                                                (0x7UL << PCC_REG_BT_VDREG_RSVD_Pos)

#define PCC_REG_BT_VDREG_RESERVED_Pos                                                            31U
#define PCC_REG_BT_VDREG_RESERVED_Msk                                                            (0x1UL << PCC_REG_BT_VDREG_RESERVED_Pos)

/* 0x2A4    0x4000_02a4
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_CODEC                     8'b0
    8       R/W     RESERVED_14                                     1'b0
    9       R/W     RESERVED_13                                     1'b1
    10      R/W     RESERVED_12                                     1'b1
    11      R/W     RESERVED_11                                     1'b1
    12      R/W     RESERVED_10                                     1'b1
    13      R/W     RESERVED_9                                      1'b0
    15:14   R/W     RSVD_2                                          2'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     CODEC_CLK_FORCE                                 1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_AUDIO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_CODEC: 8;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 2;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t CODEC_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_AUDIO_TYPE;

/*0x4000_02a4 PCC_REG_AUDIO*/
#define PCC_REG_AUDIO_ENTRY_DELAY_CORE1_DEV_CODEC_Pos                                            0U
#define PCC_REG_AUDIO_ENTRY_DELAY_CORE1_DEV_CODEC_Msk                                            (0xFFUL << PCC_REG_AUDIO_ENTRY_DELAY_CORE1_DEV_CODEC_Pos)

#define PCC_REG_AUDIO_RESERVED_14_Pos                                                            8U
#define PCC_REG_AUDIO_RESERVED_14_Msk                                                            (0x1UL << PCC_REG_AUDIO_RESERVED_14_Pos)

#define PCC_REG_AUDIO_RESERVED_13_Pos                                                            9U
#define PCC_REG_AUDIO_RESERVED_13_Msk                                                            (0x1UL << PCC_REG_AUDIO_RESERVED_13_Pos)

#define PCC_REG_AUDIO_RESERVED_12_Pos                                                            10U
#define PCC_REG_AUDIO_RESERVED_12_Msk                                                            (0x1UL << PCC_REG_AUDIO_RESERVED_12_Pos)

#define PCC_REG_AUDIO_RESERVED_11_Pos                                                            11U
#define PCC_REG_AUDIO_RESERVED_11_Msk                                                            (0x1UL << PCC_REG_AUDIO_RESERVED_11_Pos)

#define PCC_REG_AUDIO_RESERVED_10_Pos                                                            12U
#define PCC_REG_AUDIO_RESERVED_10_Msk                                                            (0x1UL << PCC_REG_AUDIO_RESERVED_10_Pos)

#define PCC_REG_AUDIO_RESERVED_9_Pos                                                             13U
#define PCC_REG_AUDIO_RESERVED_9_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_9_Pos)

#define PCC_REG_AUDIO_RSVD_2_Pos                                                                 14U
#define PCC_REG_AUDIO_RSVD_2_Msk                                                                 (0x3UL << PCC_REG_AUDIO_RSVD_2_Pos)

#define PCC_REG_AUDIO_RESERVED_8_Pos                                                             16U
#define PCC_REG_AUDIO_RESERVED_8_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_8_Pos)

#define PCC_REG_AUDIO_RESERVED_7_Pos                                                             17U
#define PCC_REG_AUDIO_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_7_Pos)

#define PCC_REG_AUDIO_CODEC_CLK_FORCE_Pos                                                        18U
#define PCC_REG_AUDIO_CODEC_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_AUDIO_CODEC_CLK_FORCE_Pos)

#define PCC_REG_AUDIO_RSVD_1_Pos                                                                 19U
#define PCC_REG_AUDIO_RSVD_1_Msk                                                                 (0x7UL << PCC_REG_AUDIO_RSVD_1_Pos)

#define PCC_REG_AUDIO_RESERVED_6_Pos                                                             22U
#define PCC_REG_AUDIO_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_6_Pos)

#define PCC_REG_AUDIO_RESERVED_5_Pos                                                             23U
#define PCC_REG_AUDIO_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_5_Pos)

#define PCC_REG_AUDIO_RESERVED_4_Pos                                                             24U
#define PCC_REG_AUDIO_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_4_Pos)

#define PCC_REG_AUDIO_RESERVED_3_Pos                                                             25U
#define PCC_REG_AUDIO_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_3_Pos)

#define PCC_REG_AUDIO_RESERVED_2_Pos                                                             26U
#define PCC_REG_AUDIO_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_2_Pos)

#define PCC_REG_AUDIO_RESERVED_1_Pos                                                             27U
#define PCC_REG_AUDIO_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_AUDIO_RESERVED_1_Pos)

#define PCC_REG_AUDIO_RSVD_Pos                                                                   28U
#define PCC_REG_AUDIO_RSVD_Msk                                                                   (0x7UL << PCC_REG_AUDIO_RSVD_Pos)

#define PCC_REG_AUDIO_RESERVED_Pos                                                               31U
#define PCC_REG_AUDIO_RESERVED_Msk                                                               (0x1UL << PCC_REG_AUDIO_RESERVED_Pos)

/* 0x2A8    0x4000_02a8
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_LXBUS                     8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b0
    10      R/W     RESERVED_11                                     1'b0
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     LXBUS_CLK_FORCE                                 1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_LXBUS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_LXBUS: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t LXBUS_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_LXBUS_TYPE;

/*0x4000_02a8 PCC_REG_LXBUS*/
#define PCC_REG_LXBUS_ENTRY_DELAY_CORE1_DEV_LXBUS_Pos                                            0U
#define PCC_REG_LXBUS_ENTRY_DELAY_CORE1_DEV_LXBUS_Msk                                            (0xFFUL << PCC_REG_LXBUS_ENTRY_DELAY_CORE1_DEV_LXBUS_Pos)

#define PCC_REG_LXBUS_RESERVED_13_Pos                                                            8U
#define PCC_REG_LXBUS_RESERVED_13_Msk                                                            (0x1UL << PCC_REG_LXBUS_RESERVED_13_Pos)

#define PCC_REG_LXBUS_RESERVED_12_Pos                                                            9U
#define PCC_REG_LXBUS_RESERVED_12_Msk                                                            (0x1UL << PCC_REG_LXBUS_RESERVED_12_Pos)

#define PCC_REG_LXBUS_RESERVED_11_Pos                                                            10U
#define PCC_REG_LXBUS_RESERVED_11_Msk                                                            (0x1UL << PCC_REG_LXBUS_RESERVED_11_Pos)

#define PCC_REG_LXBUS_RESERVED_10_Pos                                                            11U
#define PCC_REG_LXBUS_RESERVED_10_Msk                                                            (0x1UL << PCC_REG_LXBUS_RESERVED_10_Pos)

#define PCC_REG_LXBUS_RESERVED_9_Pos                                                             12U
#define PCC_REG_LXBUS_RESERVED_9_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_9_Pos)

#define PCC_REG_LXBUS_RSVD_2_Pos                                                                 13U
#define PCC_REG_LXBUS_RSVD_2_Msk                                                                 (0x7UL << PCC_REG_LXBUS_RSVD_2_Pos)

#define PCC_REG_LXBUS_RESERVED_8_Pos                                                             16U
#define PCC_REG_LXBUS_RESERVED_8_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_8_Pos)

#define PCC_REG_LXBUS_RESERVED_7_Pos                                                             17U
#define PCC_REG_LXBUS_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_7_Pos)

#define PCC_REG_LXBUS_LXBUS_CLK_FORCE_Pos                                                        18U
#define PCC_REG_LXBUS_LXBUS_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_LXBUS_LXBUS_CLK_FORCE_Pos)

#define PCC_REG_LXBUS_RSVD_1_Pos                                                                 19U
#define PCC_REG_LXBUS_RSVD_1_Msk                                                                 (0x7UL << PCC_REG_LXBUS_RSVD_1_Pos)

#define PCC_REG_LXBUS_RESERVED_6_Pos                                                             22U
#define PCC_REG_LXBUS_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_6_Pos)

#define PCC_REG_LXBUS_RESERVED_5_Pos                                                             23U
#define PCC_REG_LXBUS_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_5_Pos)

#define PCC_REG_LXBUS_RESERVED_4_Pos                                                             24U
#define PCC_REG_LXBUS_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_4_Pos)

#define PCC_REG_LXBUS_RESERVED_3_Pos                                                             25U
#define PCC_REG_LXBUS_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_3_Pos)

#define PCC_REG_LXBUS_RESERVED_2_Pos                                                             26U
#define PCC_REG_LXBUS_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_2_Pos)

#define PCC_REG_LXBUS_RESERVED_1_Pos                                                             27U
#define PCC_REG_LXBUS_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_LXBUS_RESERVED_1_Pos)

#define PCC_REG_LXBUS_RSVD_Pos                                                                   28U
#define PCC_REG_LXBUS_RSVD_Msk                                                                   (0x7UL << PCC_REG_LXBUS_RSVD_Pos)

#define PCC_REG_LXBUS_RESERVED_Pos                                                               31U
#define PCC_REG_LXBUS_RESERVED_Msk                                                               (0x1UL << PCC_REG_LXBUS_RESERVED_Pos)

/* 0x2AC    0x4000_02ac
    7:0     R/W     RESERVED_11                                     8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b0
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RSVD_2                                          3'b0
    16      R/W     ACC_CLK_FORCE                                   1'b0
    18:17   R/W     RSVD_1                                          2'b0
    19      R/W     CAL32K_CLK_FORCE                                1'b0
    24:20   R/W     RSVD                                            5'b0
    25      R/W     RESERVED_5                                      1'b0
    27:26   R/W     RESERVED_4                                      2'b0
    28      R/W     RESERVED_3                                      1'b0
    29      R/W     RESERVED_2                                      1'b0
    30      R/W     RESERVED_1                                      1'b0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_CAL32K_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_11: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RSVD_2: 3;
        uint32_t ACC_CLK_FORCE: 1;
        uint32_t RSVD_1: 2;
        uint32_t CAL32K_CLK_FORCE: 1;
        uint32_t RSVD: 5;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 2;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
    };
} PCC_REG_CAL32K_TYPE;

/*0x4000_02ac PCC_REG_CAL32K*/
#define PCC_REG_CAL32K_RESERVED_11_Pos                                                           0U
#define PCC_REG_CAL32K_RESERVED_11_Msk                                                           (0xFFUL << PCC_REG_CAL32K_RESERVED_11_Pos)

#define PCC_REG_CAL32K_RESERVED_10_Pos                                                           8U
#define PCC_REG_CAL32K_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_CAL32K_RESERVED_10_Pos)

#define PCC_REG_CAL32K_RESERVED_9_Pos                                                            9U
#define PCC_REG_CAL32K_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_9_Pos)

#define PCC_REG_CAL32K_RESERVED_8_Pos                                                            10U
#define PCC_REG_CAL32K_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_8_Pos)

#define PCC_REG_CAL32K_RESERVED_7_Pos                                                            11U
#define PCC_REG_CAL32K_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_7_Pos)

#define PCC_REG_CAL32K_RESERVED_6_Pos                                                            12U
#define PCC_REG_CAL32K_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_6_Pos)

#define PCC_REG_CAL32K_RSVD_2_Pos                                                                13U
#define PCC_REG_CAL32K_RSVD_2_Msk                                                                (0x7UL << PCC_REG_CAL32K_RSVD_2_Pos)

#define PCC_REG_CAL32K_ACC_CLK_FORCE_Pos                                                         16U
#define PCC_REG_CAL32K_ACC_CLK_FORCE_Msk                                                         (0x1UL << PCC_REG_CAL32K_ACC_CLK_FORCE_Pos)

#define PCC_REG_CAL32K_RSVD_1_Pos                                                                17U
#define PCC_REG_CAL32K_RSVD_1_Msk                                                                (0x3UL << PCC_REG_CAL32K_RSVD_1_Pos)

#define PCC_REG_CAL32K_CAL32K_CLK_FORCE_Pos                                                      19U
#define PCC_REG_CAL32K_CAL32K_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_CAL32K_CAL32K_CLK_FORCE_Pos)

#define PCC_REG_CAL32K_RSVD_Pos                                                                  20U
#define PCC_REG_CAL32K_RSVD_Msk                                                                  (0x1FUL << PCC_REG_CAL32K_RSVD_Pos)

#define PCC_REG_CAL32K_RESERVED_5_Pos                                                            25U
#define PCC_REG_CAL32K_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_5_Pos)

#define PCC_REG_CAL32K_RESERVED_4_Pos                                                            26U
#define PCC_REG_CAL32K_RESERVED_4_Msk                                                            (0x3UL << PCC_REG_CAL32K_RESERVED_4_Pos)

#define PCC_REG_CAL32K_RESERVED_3_Pos                                                            28U
#define PCC_REG_CAL32K_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_3_Pos)

#define PCC_REG_CAL32K_RESERVED_2_Pos                                                            29U
#define PCC_REG_CAL32K_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_2_Pos)

#define PCC_REG_CAL32K_RESERVED_1_Pos                                                            30U
#define PCC_REG_CAL32K_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_CAL32K_RESERVED_1_Pos)

#define PCC_REG_CAL32K_RESERVED_Pos                                                              31U
#define PCC_REG_CAL32K_RESERVED_Msk                                                              (0x1UL << PCC_REG_CAL32K_RESERVED_Pos)

/* 0x2B0    0x4000_02b0
    7:0     R/W     RESERVED_9                                      8'b0
    8       R/W     RESERVED_8                                      1'b1
    9       R/W     RESERVED_7                                      1'b1
    10      R/W     RESERVED_6                                      1'b1
    11      R/W     RESERVED_5                                      1'b0
    12      R/W     RESERVED_4                                      1'b1
    13      R/W     RESERVED_3                                      1'b1
    14      R/W     RESERVED_2                                      1'b1
    15      R/W     RESERVED_1                                      1'b0
    16      R/W     PLATFORM_CLK_FORCE                              1'b0
    17      R/W     PLATFORM_MANU_SEL                               1'b0
    18      R/W     PLATFORM_MANU_DAT                               1'b0
    31:19   R/W     RESERVED                                        13'b0
 */
typedef union _PCC_REG_PLATFORM_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_9: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t PLATFORM_CLK_FORCE: 1;
        uint32_t PLATFORM_MANU_SEL: 1;
        uint32_t PLATFORM_MANU_DAT: 1;
        uint32_t RESERVED: 13;
    };
} PCC_REG_PLATFORM_TYPE;

/*0x4000_02b0 PCC_REG_PLATFORM*/
#define PCC_REG_PLATFORM_RESERVED_9_Pos                                                          0U
#define PCC_REG_PLATFORM_RESERVED_9_Msk                                                          (0xFFUL << PCC_REG_PLATFORM_RESERVED_9_Pos)

#define PCC_REG_PLATFORM_RESERVED_8_Pos                                                          8U
#define PCC_REG_PLATFORM_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_8_Pos)

#define PCC_REG_PLATFORM_RESERVED_7_Pos                                                          9U
#define PCC_REG_PLATFORM_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_7_Pos)

#define PCC_REG_PLATFORM_RESERVED_6_Pos                                                          10U
#define PCC_REG_PLATFORM_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_6_Pos)

#define PCC_REG_PLATFORM_RESERVED_5_Pos                                                          11U
#define PCC_REG_PLATFORM_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_5_Pos)

#define PCC_REG_PLATFORM_RESERVED_4_Pos                                                          12U
#define PCC_REG_PLATFORM_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_4_Pos)

#define PCC_REG_PLATFORM_RESERVED_3_Pos                                                          13U
#define PCC_REG_PLATFORM_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_3_Pos)

#define PCC_REG_PLATFORM_RESERVED_2_Pos                                                          14U
#define PCC_REG_PLATFORM_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_2_Pos)

#define PCC_REG_PLATFORM_RESERVED_1_Pos                                                          15U
#define PCC_REG_PLATFORM_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_PLATFORM_RESERVED_1_Pos)

#define PCC_REG_PLATFORM_PLATFORM_CLK_FORCE_Pos                                                  16U
#define PCC_REG_PLATFORM_PLATFORM_CLK_FORCE_Msk                                                  (0x1UL << PCC_REG_PLATFORM_PLATFORM_CLK_FORCE_Pos)

#define PCC_REG_PLATFORM_PLATFORM_MANU_SEL_Pos                                                   17U
#define PCC_REG_PLATFORM_PLATFORM_MANU_SEL_Msk                                                   (0x1UL << PCC_REG_PLATFORM_PLATFORM_MANU_SEL_Pos)

#define PCC_REG_PLATFORM_PLATFORM_MANU_DAT_Pos                                                   18U
#define PCC_REG_PLATFORM_PLATFORM_MANU_DAT_Msk                                                   (0x1UL << PCC_REG_PLATFORM_PLATFORM_MANU_DAT_Pos)

#define PCC_REG_PLATFORM_RESERVED_Pos                                                            19U
#define PCC_REG_PLATFORM_RESERVED_Msk                                                            (0x1FFFUL << PCC_REG_PLATFORM_RESERVED_Pos)

/* 0x2B4    0x4000_02b4
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_PCC                       8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b0
    10      R/W     RESERVED_8                                      1'b0
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RESERVED_5                                      3'b0
    16      R/W     RESERVED_4                                      1'b1
    17      R/W     RESERVED_3                                      1'b0
    18      R/W     RESERVED_2                                      1'b0
    19      R/W     RESERVED_1                                      1'b0
    31:20   R/W     RESERVED                                        12'b0
 */
typedef union _PCC_REG_PCC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_PCC: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 12;
    };
} PCC_REG_PCC_TYPE;

/*0x4000_02b4 PCC_REG_PCC*/
#define PCC_REG_PCC_ENTRY_DELAY_CORE1_DEV_PCC_Pos                                                0U
#define PCC_REG_PCC_ENTRY_DELAY_CORE1_DEV_PCC_Msk                                                (0xFFUL << PCC_REG_PCC_ENTRY_DELAY_CORE1_DEV_PCC_Pos)

#define PCC_REG_PCC_RESERVED_10_Pos                                                              8U
#define PCC_REG_PCC_RESERVED_10_Msk                                                              (0x1UL << PCC_REG_PCC_RESERVED_10_Pos)

#define PCC_REG_PCC_RESERVED_9_Pos                                                               9U
#define PCC_REG_PCC_RESERVED_9_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_9_Pos)

#define PCC_REG_PCC_RESERVED_8_Pos                                                               10U
#define PCC_REG_PCC_RESERVED_8_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_8_Pos)

#define PCC_REG_PCC_RESERVED_7_Pos                                                               11U
#define PCC_REG_PCC_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_7_Pos)

#define PCC_REG_PCC_RESERVED_6_Pos                                                               12U
#define PCC_REG_PCC_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_6_Pos)

#define PCC_REG_PCC_RESERVED_5_Pos                                                               13U
#define PCC_REG_PCC_RESERVED_5_Msk                                                               (0x7UL << PCC_REG_PCC_RESERVED_5_Pos)

#define PCC_REG_PCC_RESERVED_4_Pos                                                               16U
#define PCC_REG_PCC_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_4_Pos)

#define PCC_REG_PCC_RESERVED_3_Pos                                                               17U
#define PCC_REG_PCC_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_3_Pos)

#define PCC_REG_PCC_RESERVED_2_Pos                                                               18U
#define PCC_REG_PCC_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_2_Pos)

#define PCC_REG_PCC_RESERVED_1_Pos                                                               19U
#define PCC_REG_PCC_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_PCC_RESERVED_1_Pos)

#define PCC_REG_PCC_RESERVED_Pos                                                                 20U
#define PCC_REG_PCC_RESERVED_Msk                                                                 (0xFFFUL << PCC_REG_PCC_RESERVED_Pos)

/* 0x2B8    0x4000_02b8
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TMETER                    8'b0
    8       R/W     RESERVED_13                                     1'b0
    9       R/W     RESERVED_12                                     1'b1
    10      R/W     RESERVED_11                                     1'b1
    11      R/W     RESERVED_10                                     1'b1
    12      R/W     RESERVED_9                                      1'b1
    15:13   R/W     RSVD_2                                          3'h0
    16      R/W     RESERVED_8                                      1'b0
    17      R/W     RESERVED_7                                      1'b0
    18      R/W     TMETER_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_TMETER_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TMETER: 8;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RSVD_2: 3;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t TMETER_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_TMETER_TYPE;

/*0x4000_02b8 PCC_REG_TMETER*/
#define PCC_REG_TMETER_ENTRY_DELAY_CORE1_DEV_TMETER_Pos                                          0U
#define PCC_REG_TMETER_ENTRY_DELAY_CORE1_DEV_TMETER_Msk                                          (0xFFUL << PCC_REG_TMETER_ENTRY_DELAY_CORE1_DEV_TMETER_Pos)

#define PCC_REG_TMETER_RESERVED_13_Pos                                                           8U
#define PCC_REG_TMETER_RESERVED_13_Msk                                                           (0x1UL << PCC_REG_TMETER_RESERVED_13_Pos)

#define PCC_REG_TMETER_RESERVED_12_Pos                                                           9U
#define PCC_REG_TMETER_RESERVED_12_Msk                                                           (0x1UL << PCC_REG_TMETER_RESERVED_12_Pos)

#define PCC_REG_TMETER_RESERVED_11_Pos                                                           10U
#define PCC_REG_TMETER_RESERVED_11_Msk                                                           (0x1UL << PCC_REG_TMETER_RESERVED_11_Pos)

#define PCC_REG_TMETER_RESERVED_10_Pos                                                           11U
#define PCC_REG_TMETER_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_TMETER_RESERVED_10_Pos)

#define PCC_REG_TMETER_RESERVED_9_Pos                                                            12U
#define PCC_REG_TMETER_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_9_Pos)

#define PCC_REG_TMETER_RSVD_2_Pos                                                                13U
#define PCC_REG_TMETER_RSVD_2_Msk                                                                (0x7UL << PCC_REG_TMETER_RSVD_2_Pos)

#define PCC_REG_TMETER_RESERVED_8_Pos                                                            16U
#define PCC_REG_TMETER_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_8_Pos)

#define PCC_REG_TMETER_RESERVED_7_Pos                                                            17U
#define PCC_REG_TMETER_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_7_Pos)

#define PCC_REG_TMETER_TMETER_CLK_FORCE_Pos                                                      18U
#define PCC_REG_TMETER_TMETER_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_TMETER_TMETER_CLK_FORCE_Pos)

#define PCC_REG_TMETER_RSVD_1_Pos                                                                19U
#define PCC_REG_TMETER_RSVD_1_Msk                                                                (0x7UL << PCC_REG_TMETER_RSVD_1_Pos)

#define PCC_REG_TMETER_RESERVED_6_Pos                                                            22U
#define PCC_REG_TMETER_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_6_Pos)

#define PCC_REG_TMETER_RESERVED_5_Pos                                                            23U
#define PCC_REG_TMETER_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_5_Pos)

#define PCC_REG_TMETER_RESERVED_4_Pos                                                            24U
#define PCC_REG_TMETER_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_4_Pos)

#define PCC_REG_TMETER_RESERVED_3_Pos                                                            25U
#define PCC_REG_TMETER_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_3_Pos)

#define PCC_REG_TMETER_RESERVED_2_Pos                                                            26U
#define PCC_REG_TMETER_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_2_Pos)

#define PCC_REG_TMETER_RESERVED_1_Pos                                                            27U
#define PCC_REG_TMETER_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_TMETER_RESERVED_1_Pos)

#define PCC_REG_TMETER_RSVD_Pos                                                                  28U
#define PCC_REG_TMETER_RSVD_Msk                                                                  (0x7UL << PCC_REG_TMETER_RSVD_Pos)

#define PCC_REG_TMETER_RESERVED_Pos                                                              31U
#define PCC_REG_TMETER_RESERVED_Msk                                                              (0x1UL << PCC_REG_TMETER_RESERVED_Pos)

/* 0x2BC    0x4000_02bc
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TIMER1_PWM                8'b0
    8       R/W     RESERVED_5                                      1'b1
    9       R/W     RESERVED_4                                      1'b1
    10      R/W     RESERVED_3                                      1'b1
    11      R/W     RESERVED_2                                      1'b1
    12      R/W     RESERVED_1                                      1'b1
    13      R/W     RESERVED                                        1'b1
    15:14   R/W     RSVD_1                                          2'b0
    16      R/W     R_TIMER_PWM_9_CLK_SRC_SEL                       1'b0
    17      R/W     R_TIMER_PWM_10_CLK_SRC_SEL                      1'b0
    18      R/W     R_TIMER_PWM_11_CLK_SRC_SEL                      1'b0
    21:19   R/W     R_TIMER_PWM_9_CLK_DIV                           3'h0
    24:22   R/W     R_TIMER_PWM_10_CLK_DIV                          3'h0
    27:25   R/W     R_TIMER_PWM_11_CLK_DIV                          3'h0
    28      R/W     TIMER1_PWM_CH9_CLK_FORCE                        1'b0
    29      R/W     TIMER1_PWM_CH10_CLK_FORCE                       1'b0
    30      R/W     TIMER1_PWM_CH11_CLK_FORCE                       1'b0
    31      R/W     RSVD                                            1'b0
 */
typedef union _PCC_REG_TIMER1_D_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TIMER1_PWM: 8;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD_1: 2;
        uint32_t R_TIMER_PWM_9_CLK_SRC_SEL: 1;
        uint32_t R_TIMER_PWM_10_CLK_SRC_SEL: 1;
        uint32_t R_TIMER_PWM_11_CLK_SRC_SEL: 1;
        uint32_t R_TIMER_PWM_9_CLK_DIV: 3;
        uint32_t R_TIMER_PWM_10_CLK_DIV: 3;
        uint32_t R_TIMER_PWM_11_CLK_DIV: 3;
        uint32_t TIMER1_PWM_CH9_CLK_FORCE: 1;
        uint32_t TIMER1_PWM_CH10_CLK_FORCE: 1;
        uint32_t TIMER1_PWM_CH11_CLK_FORCE: 1;
        uint32_t RSVD: 1;
    };
} PCC_REG_TIMER1_D_TYPE;

/*0x4000_02bc PCC_REG_TIMER1_D*/
#define PCC_REG_TIMER1_D_ENTRY_DELAY_CORE1_DEV_TIMER1_PWM_Pos                                    0U
#define PCC_REG_TIMER1_D_ENTRY_DELAY_CORE1_DEV_TIMER1_PWM_Msk                                    (0xFFUL << PCC_REG_TIMER1_D_ENTRY_DELAY_CORE1_DEV_TIMER1_PWM_Pos)

#define PCC_REG_TIMER1_D_RESERVED_5_Pos                                                          8U
#define PCC_REG_TIMER1_D_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_TIMER1_D_RESERVED_5_Pos)

#define PCC_REG_TIMER1_D_RESERVED_4_Pos                                                          9U
#define PCC_REG_TIMER1_D_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_TIMER1_D_RESERVED_4_Pos)

#define PCC_REG_TIMER1_D_RESERVED_3_Pos                                                          10U
#define PCC_REG_TIMER1_D_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_TIMER1_D_RESERVED_3_Pos)

#define PCC_REG_TIMER1_D_RESERVED_2_Pos                                                          11U
#define PCC_REG_TIMER1_D_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_TIMER1_D_RESERVED_2_Pos)

#define PCC_REG_TIMER1_D_RESERVED_1_Pos                                                          12U
#define PCC_REG_TIMER1_D_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_TIMER1_D_RESERVED_1_Pos)

#define PCC_REG_TIMER1_D_RESERVED_Pos                                                            13U
#define PCC_REG_TIMER1_D_RESERVED_Msk                                                            (0x1UL << PCC_REG_TIMER1_D_RESERVED_Pos)

#define PCC_REG_TIMER1_D_RSVD_1_Pos                                                              14U
#define PCC_REG_TIMER1_D_RSVD_1_Msk                                                              (0x3UL << PCC_REG_TIMER1_D_RSVD_1_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_SRC_SEL_Pos                                           16U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_SRC_SEL_Msk                                           (0x1UL << PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_SRC_SEL_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_SRC_SEL_Pos                                          17U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_SRC_SEL_Msk                                          (0x1UL << PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_SRC_SEL_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_SRC_SEL_Pos                                          18U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_SRC_SEL_Msk                                          (0x1UL << PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_SRC_SEL_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_DIV_Pos                                               19U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_DIV_Msk                                               (0x7UL << PCC_REG_TIMER1_D_R_TIMER_PWM_9_CLK_DIV_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_DIV_Pos                                              22U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_DIV_Msk                                              (0x7UL << PCC_REG_TIMER1_D_R_TIMER_PWM_10_CLK_DIV_Pos)

#define PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_DIV_Pos                                              25U
#define PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_DIV_Msk                                              (0x7UL << PCC_REG_TIMER1_D_R_TIMER_PWM_11_CLK_DIV_Pos)

#define PCC_REG_TIMER1_D_TIMER1_PWM_CH9_CLK_FORCE_Pos                                            28U
#define PCC_REG_TIMER1_D_TIMER1_PWM_CH9_CLK_FORCE_Msk                                            (0x1UL << PCC_REG_TIMER1_D_TIMER1_PWM_CH9_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_D_TIMER1_PWM_CH10_CLK_FORCE_Pos                                           29U
#define PCC_REG_TIMER1_D_TIMER1_PWM_CH10_CLK_FORCE_Msk                                           (0x1UL << PCC_REG_TIMER1_D_TIMER1_PWM_CH10_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_D_TIMER1_PWM_CH11_CLK_FORCE_Pos                                           30U
#define PCC_REG_TIMER1_D_TIMER1_PWM_CH11_CLK_FORCE_Msk                                           (0x1UL << PCC_REG_TIMER1_D_TIMER1_PWM_CH11_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_D_RSVD_Pos                                                                31U
#define PCC_REG_TIMER1_D_RSVD_Msk                                                                (0x1UL << PCC_REG_TIMER1_D_RSVD_Pos)

/* 0x8F0    0x4000_08f0
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_OSC80M_CAL                8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b1
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RESERVED_5                                      3'b0
    16      R/W     CAL80M_CLK_FORCE                                1'b0
    19:17   R/W     RSVD                                            3'b0
    20      R/W     RESERVED_4                                      1'b0
    21      R/W     RESERVED_3                                      1'b0
    23:22   R/W     RESERVED_2                                      2'b0
    24      R/W     RESERVED_1                                      1'b0
    31:25   R/W     RESERVED                                        7'b0
 */
typedef union _PCC_REG_CAL80M_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_OSC80M_CAL: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 3;
        uint32_t CAL80M_CLK_FORCE: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 2;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 7;
    };
} PCC_REG_CAL80M_TYPE;

/*0x4000_08f0 PCC_REG_CAL80M*/
#define PCC_REG_CAL80M_ENTRY_DELAY_CORE1_DEV_OSC80M_CAL_Pos                                      0U
#define PCC_REG_CAL80M_ENTRY_DELAY_CORE1_DEV_OSC80M_CAL_Msk                                      (0xFFUL << PCC_REG_CAL80M_ENTRY_DELAY_CORE1_DEV_OSC80M_CAL_Pos)

#define PCC_REG_CAL80M_RESERVED_10_Pos                                                           8U
#define PCC_REG_CAL80M_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_CAL80M_RESERVED_10_Pos)

#define PCC_REG_CAL80M_RESERVED_9_Pos                                                            9U
#define PCC_REG_CAL80M_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_9_Pos)

#define PCC_REG_CAL80M_RESERVED_8_Pos                                                            10U
#define PCC_REG_CAL80M_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_8_Pos)

#define PCC_REG_CAL80M_RESERVED_7_Pos                                                            11U
#define PCC_REG_CAL80M_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_7_Pos)

#define PCC_REG_CAL80M_RESERVED_6_Pos                                                            12U
#define PCC_REG_CAL80M_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_6_Pos)

#define PCC_REG_CAL80M_RESERVED_5_Pos                                                            13U
#define PCC_REG_CAL80M_RESERVED_5_Msk                                                            (0x7UL << PCC_REG_CAL80M_RESERVED_5_Pos)

#define PCC_REG_CAL80M_CAL80M_CLK_FORCE_Pos                                                      16U
#define PCC_REG_CAL80M_CAL80M_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_CAL80M_CAL80M_CLK_FORCE_Pos)

#define PCC_REG_CAL80M_RSVD_Pos                                                                  17U
#define PCC_REG_CAL80M_RSVD_Msk                                                                  (0x7UL << PCC_REG_CAL80M_RSVD_Pos)

#define PCC_REG_CAL80M_RESERVED_4_Pos                                                            20U
#define PCC_REG_CAL80M_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_4_Pos)

#define PCC_REG_CAL80M_RESERVED_3_Pos                                                            21U
#define PCC_REG_CAL80M_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_3_Pos)

#define PCC_REG_CAL80M_RESERVED_2_Pos                                                            22U
#define PCC_REG_CAL80M_RESERVED_2_Msk                                                            (0x3UL << PCC_REG_CAL80M_RESERVED_2_Pos)

#define PCC_REG_CAL80M_RESERVED_1_Pos                                                            24U
#define PCC_REG_CAL80M_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_CAL80M_RESERVED_1_Pos)

#define PCC_REG_CAL80M_RESERVED_Pos                                                              25U
#define PCC_REG_CAL80M_RESERVED_Msk                                                              (0x7FUL << PCC_REG_CAL80M_RESERVED_Pos)

/* 0x8F4    0x4000_08f4
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_OSC10M_CAL                8'b0
    8       R/W     RESERVED_10                                     1'b0
    9       R/W     RESERVED_9                                      1'b0
    10      R/W     RESERVED_8                                      1'b1
    11      R/W     RESERVED_7                                      1'b1
    12      R/W     RESERVED_6                                      1'b1
    15:13   R/W     RESERVED_5                                      3'b0
    16      R/W     CAL10M_CLK_FORCE                                1'b0
    19:17   R/W     RSVD                                            3'h0
    20      R/W     RESERVED_4                                      1'b0
    21      R/W     RESERVED_3                                      1'b0
    23:22   R/W     RESERVED_2                                      2'b0
    24      R/W     RESERVED_1                                      1'b0
    31:25   R/W     RESERVED                                        7'b0
 */
typedef union _PCC_REG_CAL10M_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_OSC10M_CAL: 8;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 3;
        uint32_t CAL10M_CLK_FORCE: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 2;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 7;
    };
} PCC_REG_CAL10M_TYPE;

/*0x4000_08f4 PCC_REG_CAL10M*/
#define PCC_REG_CAL10M_ENTRY_DELAY_CORE1_DEV_OSC10M_CAL_Pos                                      0U
#define PCC_REG_CAL10M_ENTRY_DELAY_CORE1_DEV_OSC10M_CAL_Msk                                      (0xFFUL << PCC_REG_CAL10M_ENTRY_DELAY_CORE1_DEV_OSC10M_CAL_Pos)

#define PCC_REG_CAL10M_RESERVED_10_Pos                                                           8U
#define PCC_REG_CAL10M_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_CAL10M_RESERVED_10_Pos)

#define PCC_REG_CAL10M_RESERVED_9_Pos                                                            9U
#define PCC_REG_CAL10M_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_9_Pos)

#define PCC_REG_CAL10M_RESERVED_8_Pos                                                            10U
#define PCC_REG_CAL10M_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_8_Pos)

#define PCC_REG_CAL10M_RESERVED_7_Pos                                                            11U
#define PCC_REG_CAL10M_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_7_Pos)

#define PCC_REG_CAL10M_RESERVED_6_Pos                                                            12U
#define PCC_REG_CAL10M_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_6_Pos)

#define PCC_REG_CAL10M_RESERVED_5_Pos                                                            13U
#define PCC_REG_CAL10M_RESERVED_5_Msk                                                            (0x7UL << PCC_REG_CAL10M_RESERVED_5_Pos)

#define PCC_REG_CAL10M_CAL10M_CLK_FORCE_Pos                                                      16U
#define PCC_REG_CAL10M_CAL10M_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_CAL10M_CAL10M_CLK_FORCE_Pos)

#define PCC_REG_CAL10M_RSVD_Pos                                                                  17U
#define PCC_REG_CAL10M_RSVD_Msk                                                                  (0x7UL << PCC_REG_CAL10M_RSVD_Pos)

#define PCC_REG_CAL10M_RESERVED_4_Pos                                                            20U
#define PCC_REG_CAL10M_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_4_Pos)

#define PCC_REG_CAL10M_RESERVED_3_Pos                                                            21U
#define PCC_REG_CAL10M_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_3_Pos)

#define PCC_REG_CAL10M_RESERVED_2_Pos                                                            22U
#define PCC_REG_CAL10M_RESERVED_2_Msk                                                            (0x3UL << PCC_REG_CAL10M_RESERVED_2_Pos)

#define PCC_REG_CAL10M_RESERVED_1_Pos                                                            24U
#define PCC_REG_CAL10M_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_CAL10M_RESERVED_1_Pos)

#define PCC_REG_CAL10M_RESERVED_Pos                                                              25U
#define PCC_REG_CAL10M_RESERVED_Msk                                                              (0x7FUL << PCC_REG_CAL10M_RESERVED_Pos)

/* 0x8F8    0x4000_08f8
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_VDREG                     8'b0
    8       R/W     RESERVED_8                                      1'b0
    9       R/W     RESERVED_7                                      1'b0
    10      R/W     RESERVED_6                                      1'b0
    11      R/W     RESERVED_5                                      1'b1
    12      R/W     RESERVED_4                                      1'b1
    15:13   R/W     RESERVED_3                                      3'b0
    16      R/W     VDREG_CLK_FORCE                                 1'b0
    17      R/W     RESERVED_2                                      1'b0
    18      R/W     RESERVED_1                                      1'b0
    31:19   R/W     RESERVED                                        13'b0
 */
typedef union _PCC_REG_VDREG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_VDREG: 8;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 3;
        uint32_t VDREG_CLK_FORCE: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 13;
    };
} PCC_REG_VDREG_TYPE;

/*0x4000_08f8 PCC_REG_VDREG*/
#define PCC_REG_VDREG_ENTRY_DELAY_CORE1_DEV_VDREG_Pos                                            0U
#define PCC_REG_VDREG_ENTRY_DELAY_CORE1_DEV_VDREG_Msk                                            (0xFFUL << PCC_REG_VDREG_ENTRY_DELAY_CORE1_DEV_VDREG_Pos)

#define PCC_REG_VDREG_RESERVED_8_Pos                                                             8U
#define PCC_REG_VDREG_RESERVED_8_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_8_Pos)

#define PCC_REG_VDREG_RESERVED_7_Pos                                                             9U
#define PCC_REG_VDREG_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_7_Pos)

#define PCC_REG_VDREG_RESERVED_6_Pos                                                             10U
#define PCC_REG_VDREG_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_6_Pos)

#define PCC_REG_VDREG_RESERVED_5_Pos                                                             11U
#define PCC_REG_VDREG_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_5_Pos)

#define PCC_REG_VDREG_RESERVED_4_Pos                                                             12U
#define PCC_REG_VDREG_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_4_Pos)

#define PCC_REG_VDREG_RESERVED_3_Pos                                                             13U
#define PCC_REG_VDREG_RESERVED_3_Msk                                                             (0x7UL << PCC_REG_VDREG_RESERVED_3_Pos)

#define PCC_REG_VDREG_VDREG_CLK_FORCE_Pos                                                        16U
#define PCC_REG_VDREG_VDREG_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_VDREG_VDREG_CLK_FORCE_Pos)

#define PCC_REG_VDREG_RESERVED_2_Pos                                                             17U
#define PCC_REG_VDREG_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_2_Pos)

#define PCC_REG_VDREG_RESERVED_1_Pos                                                             18U
#define PCC_REG_VDREG_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_VDREG_RESERVED_1_Pos)

#define PCC_REG_VDREG_RESERVED_Pos                                                               19U
#define PCC_REG_VDREG_RESERVED_Msk                                                               (0x1FFFUL << PCC_REG_VDREG_RESERVED_Pos)

/* 0x8FC    0x4000_08fc
    7:0     R/W     ENTRY_DELAY_CM33                                8'b0
    8       R/W     RESERVED_6                                      1'b0
    9       R/W     RESERVED_5                                      1'b0
    10      R/W     RESERVED_4                                      1'b0
    11      R/W     RESERVED_3                                      1'b1
    12      R/W     RESERVED_2                                      1'b1
    15:13   R/W     RESERVED_1                                      3'b0
    16      R/W     CM33_CLK_FORCE                                  1'b0
    31:17   R/W     RESERVED                                        15'b0
 */
typedef union _PCC_REG_CPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CM33: 8;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t CM33_CLK_FORCE: 1;
        uint32_t RESERVED: 15;
    };
} PCC_REG_CPU_TYPE;

/*0x4000_08fc PCC_REG_CPU*/
#define PCC_REG_CPU_ENTRY_DELAY_CM33_Pos                                                         0U
#define PCC_REG_CPU_ENTRY_DELAY_CM33_Msk                                                         (0xFFUL << PCC_REG_CPU_ENTRY_DELAY_CM33_Pos)

#define PCC_REG_CPU_RESERVED_6_Pos                                                               8U
#define PCC_REG_CPU_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_CPU_RESERVED_6_Pos)

#define PCC_REG_CPU_RESERVED_5_Pos                                                               9U
#define PCC_REG_CPU_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_CPU_RESERVED_5_Pos)

#define PCC_REG_CPU_RESERVED_4_Pos                                                               10U
#define PCC_REG_CPU_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_CPU_RESERVED_4_Pos)

#define PCC_REG_CPU_RESERVED_3_Pos                                                               11U
#define PCC_REG_CPU_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_CPU_RESERVED_3_Pos)

#define PCC_REG_CPU_RESERVED_2_Pos                                                               12U
#define PCC_REG_CPU_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_CPU_RESERVED_2_Pos)

#define PCC_REG_CPU_RESERVED_1_Pos                                                               13U
#define PCC_REG_CPU_RESERVED_1_Msk                                                               (0x7UL << PCC_REG_CPU_RESERVED_1_Pos)

#define PCC_REG_CPU_CM33_CLK_FORCE_Pos                                                           16U
#define PCC_REG_CPU_CM33_CLK_FORCE_Msk                                                           (0x1UL << PCC_REG_CPU_CM33_CLK_FORCE_Pos)

#define PCC_REG_CPU_RESERVED_Pos                                                                 17U
#define PCC_REG_CPU_RESERVED_Msk                                                                 (0x7FFFUL << PCC_REG_CPU_RESERVED_Pos)

/* 0x900    0x4000_0900
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_SYSON                     8'b0
    15:8    R/W     RESERVED_1                                      8'b0
    16      R/W     SYSON_CLK_FORCE                                 1'b0
    17      R/W     RFC_MANU_SEL                                    1'b0
    18      R/W     RFC_MANU_DAT                                    1'b0
    31:19   R/W     RESERVED                                        13'b0
 */
typedef union _PCC_REG_SYSON_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_SYSON: 8;
        uint32_t RESERVED_1: 8;
        uint32_t SYSON_CLK_FORCE: 1;
        uint32_t RFC_MANU_SEL: 1;
        uint32_t RFC_MANU_DAT: 1;
        uint32_t RESERVED: 13;
    };
} PCC_REG_SYSON_TYPE;

/*0x4000_0900 PCC_REG_SYSON*/
#define PCC_REG_SYSON_ENTRY_DELAY_CORE1_DEV_SYSON_Pos                                            0U
#define PCC_REG_SYSON_ENTRY_DELAY_CORE1_DEV_SYSON_Msk                                            (0xFFUL << PCC_REG_SYSON_ENTRY_DELAY_CORE1_DEV_SYSON_Pos)

#define PCC_REG_SYSON_RESERVED_1_Pos                                                             8U
#define PCC_REG_SYSON_RESERVED_1_Msk                                                             (0xFFUL << PCC_REG_SYSON_RESERVED_1_Pos)

#define PCC_REG_SYSON_SYSON_CLK_FORCE_Pos                                                        16U
#define PCC_REG_SYSON_SYSON_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_SYSON_SYSON_CLK_FORCE_Pos)

#define PCC_REG_SYSON_RFC_MANU_SEL_Pos                                                           17U
#define PCC_REG_SYSON_RFC_MANU_SEL_Msk                                                           (0x1UL << PCC_REG_SYSON_RFC_MANU_SEL_Pos)

#define PCC_REG_SYSON_RFC_MANU_DAT_Pos                                                           18U
#define PCC_REG_SYSON_RFC_MANU_DAT_Msk                                                           (0x1UL << PCC_REG_SYSON_RFC_MANU_DAT_Pos)

#define PCC_REG_SYSON_RESERVED_Pos                                                               19U
#define PCC_REG_SYSON_RESERVED_Msk                                                               (0x1FFFUL << PCC_REG_SYSON_RESERVED_Pos)

/* 0x904    0x4000_0904
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_HCI                       8'b0
    8       R/W     RESERVED_5                                      1'b0
    9       R/W     RESERVED_4                                      1'b1
    10      R/W     RESERVED_3                                      1'b1
    11      R/W     RESERVED_2                                      1'b1
    12      R/W     RESERVED_1                                      1'b1
    15:13   R/W     RSVD                                            3'h0
    16      R/W     HCI_CLK_FORCE                                   1'b0
    31:17   R/W     RESERVED                                        15'b0
 */
typedef union _PCC_REG_HCI_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_HCI: 8;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t HCI_CLK_FORCE: 1;
        uint32_t RESERVED: 15;
    };
} PCC_REG_HCI_TYPE;

/*0x4000_0904 PCC_REG_HCI*/
#define PCC_REG_HCI_ENTRY_DELAY_CORE1_DEV_HCI_Pos                                                0U
#define PCC_REG_HCI_ENTRY_DELAY_CORE1_DEV_HCI_Msk                                                (0xFFUL << PCC_REG_HCI_ENTRY_DELAY_CORE1_DEV_HCI_Pos)

#define PCC_REG_HCI_RESERVED_5_Pos                                                               8U
#define PCC_REG_HCI_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_HCI_RESERVED_5_Pos)

#define PCC_REG_HCI_RESERVED_4_Pos                                                               9U
#define PCC_REG_HCI_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_HCI_RESERVED_4_Pos)

#define PCC_REG_HCI_RESERVED_3_Pos                                                               10U
#define PCC_REG_HCI_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_HCI_RESERVED_3_Pos)

#define PCC_REG_HCI_RESERVED_2_Pos                                                               11U
#define PCC_REG_HCI_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_HCI_RESERVED_2_Pos)

#define PCC_REG_HCI_RESERVED_1_Pos                                                               12U
#define PCC_REG_HCI_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_HCI_RESERVED_1_Pos)

#define PCC_REG_HCI_RSVD_Pos                                                                     13U
#define PCC_REG_HCI_RSVD_Msk                                                                     (0x7UL << PCC_REG_HCI_RSVD_Pos)

#define PCC_REG_HCI_HCI_CLK_FORCE_Pos                                                            16U
#define PCC_REG_HCI_HCI_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_HCI_HCI_CLK_FORCE_Pos)

#define PCC_REG_HCI_RESERVED_Pos                                                                 17U
#define PCC_REG_HCI_RESERVED_Msk                                                                 (0x7FFFUL << PCC_REG_HCI_RESERVED_Pos)

/* 0x908    0x4000_0908
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_RFC                       8'b0
    15:8    R/W     ENTRY_DELAY_CORE1_DEV_BLUEWIZ_BRIDGE            8'b0
    23:16   R/W     ENTRY_DELAY_CORE1_DEV_2P4G_MAC                  8'b0
    31:24   R/W     ENTRY_DELAY_CORE1_DEV_BTMAC                     8'b0
 */
typedef union _PCC_REG_BT_OTHER0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_RFC: 8;
        uint32_t ENTRY_DELAY_CORE1_DEV_BLUEWIZ_BRIDGE: 8;
        uint32_t ENTRY_DELAY_CORE1_DEV_2P4G_MAC: 8;
        uint32_t ENTRY_DELAY_CORE1_DEV_BTMAC: 8;
    };
} PCC_REG_BT_OTHER0_TYPE;

/*0x4000_0908 PCC_REG_BT_OTHER0*/
#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_RFC_Pos                                          0U
#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_RFC_Msk                                          (0xFFUL << PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_RFC_Pos)

#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BLUEWIZ_BRIDGE_Pos                               8U
#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BLUEWIZ_BRIDGE_Msk                               (0xFFUL << PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BLUEWIZ_BRIDGE_Pos)

#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_2P4G_MAC_Pos                                     16U
#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_2P4G_MAC_Msk                                     (0xFFUL << PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_2P4G_MAC_Pos)

#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BTMAC_Pos                                        24U
#define PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BTMAC_Msk                                        (0xFFUL << PCC_REG_BT_OTHER0_ENTRY_DELAY_CORE1_DEV_BTMAC_Pos)

/* 0x90C    0x4000_090c
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TIMER0_PCLK               8'b0
    8       R/W     RESERVED_4                                      1'b0
    9       R/W     RESERVED_3                                      1'b1
    10      R/W     RESERVED_2                                      1'b1
    21:11   R/W     RESERVED_1                                      11'b0
    22      R/W     TIMER0_PCLK_CLK_FORCE                           1'b0
    31:23   R/W     RESERVED                                        9'b0
 */
typedef union _PCC_REG_TIMER0_PCLK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TIMER0_PCLK: 8;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 11;
        uint32_t TIMER0_PCLK_CLK_FORCE: 1;
        uint32_t RESERVED: 9;
    };
} PCC_REG_TIMER0_PCLK_TYPE;

/*0x4000_090c PCC_REG_TIMER0_PCLK*/
#define PCC_REG_TIMER0_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER0_PCLK_Pos                                0U
#define PCC_REG_TIMER0_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER0_PCLK_Msk                                (0xFFUL << PCC_REG_TIMER0_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER0_PCLK_Pos)

#define PCC_REG_TIMER0_PCLK_RESERVED_4_Pos                                                       8U
#define PCC_REG_TIMER0_PCLK_RESERVED_4_Msk                                                       (0x1UL << PCC_REG_TIMER0_PCLK_RESERVED_4_Pos)

#define PCC_REG_TIMER0_PCLK_RESERVED_3_Pos                                                       9U
#define PCC_REG_TIMER0_PCLK_RESERVED_3_Msk                                                       (0x1UL << PCC_REG_TIMER0_PCLK_RESERVED_3_Pos)

#define PCC_REG_TIMER0_PCLK_RESERVED_2_Pos                                                       10U
#define PCC_REG_TIMER0_PCLK_RESERVED_2_Msk                                                       (0x1UL << PCC_REG_TIMER0_PCLK_RESERVED_2_Pos)

#define PCC_REG_TIMER0_PCLK_RESERVED_1_Pos                                                       11U
#define PCC_REG_TIMER0_PCLK_RESERVED_1_Msk                                                       (0x7FFUL << PCC_REG_TIMER0_PCLK_RESERVED_1_Pos)

#define PCC_REG_TIMER0_PCLK_TIMER0_PCLK_CLK_FORCE_Pos                                            22U
#define PCC_REG_TIMER0_PCLK_TIMER0_PCLK_CLK_FORCE_Msk                                            (0x1UL << PCC_REG_TIMER0_PCLK_TIMER0_PCLK_CLK_FORCE_Pos)

#define PCC_REG_TIMER0_PCLK_RESERVED_Pos                                                         23U
#define PCC_REG_TIMER0_PCLK_RESERVED_Msk                                                         (0x1FFUL << PCC_REG_TIMER0_PCLK_RESERVED_Pos)

/* 0x910    0x4000_0910
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_TIMER1_PCLK               8'b0
    8       R/W     RESERVED_4                                      1'b0
    9       R/W     RESERVED_3                                      1'b1
    10      R/W     RESERVED_2                                      1'b1
    21:11   R/W     RESERVED_1                                      11'b0
    22      R/W     TIMER1_PCLK_CLK_FORCE                           1'b0
    31:23   R/W     RESERVED                                        9'b0
 */
typedef union _PCC_REG_TIMER1_PCLK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_TIMER1_PCLK: 8;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 11;
        uint32_t TIMER1_PCLK_CLK_FORCE: 1;
        uint32_t RESERVED: 9;
    };
} PCC_REG_TIMER1_PCLK_TYPE;

/*0x4000_0910 PCC_REG_TIMER1_PCLK*/
#define PCC_REG_TIMER1_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER1_PCLK_Pos                                0U
#define PCC_REG_TIMER1_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER1_PCLK_Msk                                (0xFFUL << PCC_REG_TIMER1_PCLK_ENTRY_DELAY_CORE1_DEV_TIMER1_PCLK_Pos)

#define PCC_REG_TIMER1_PCLK_RESERVED_4_Pos                                                       8U
#define PCC_REG_TIMER1_PCLK_RESERVED_4_Msk                                                       (0x1UL << PCC_REG_TIMER1_PCLK_RESERVED_4_Pos)

#define PCC_REG_TIMER1_PCLK_RESERVED_3_Pos                                                       9U
#define PCC_REG_TIMER1_PCLK_RESERVED_3_Msk                                                       (0x1UL << PCC_REG_TIMER1_PCLK_RESERVED_3_Pos)

#define PCC_REG_TIMER1_PCLK_RESERVED_2_Pos                                                       10U
#define PCC_REG_TIMER1_PCLK_RESERVED_2_Msk                                                       (0x1UL << PCC_REG_TIMER1_PCLK_RESERVED_2_Pos)

#define PCC_REG_TIMER1_PCLK_RESERVED_1_Pos                                                       11U
#define PCC_REG_TIMER1_PCLK_RESERVED_1_Msk                                                       (0x7FFUL << PCC_REG_TIMER1_PCLK_RESERVED_1_Pos)

#define PCC_REG_TIMER1_PCLK_TIMER1_PCLK_CLK_FORCE_Pos                                            22U
#define PCC_REG_TIMER1_PCLK_TIMER1_PCLK_CLK_FORCE_Msk                                            (0x1UL << PCC_REG_TIMER1_PCLK_TIMER1_PCLK_CLK_FORCE_Pos)

#define PCC_REG_TIMER1_PCLK_RESERVED_Pos                                                         23U
#define PCC_REG_TIMER1_PCLK_RESERVED_Msk                                                         (0x1FFUL << PCC_REG_TIMER1_PCLK_RESERVED_Pos)

/* 0x914    0x4000_0914
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_ETIMER_PCLK               8'b0
    8       R/W     RESERVED_4                                      1'b0
    9       R/W     RESERVED_3                                      1'b1
    10      R/W     RESERVED_2                                      1'b1
    21:11   R/W     RESERVED_1                                      11'b0
    22      R/W     ETIMER_PCLK_CLK_FORCE                           1'b0
    31:23   R/W     RESERVED                                        9'b0
 */
typedef union _PCC_REG_ETIMER_PCLK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_ETIMER_PCLK: 8;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 11;
        uint32_t ETIMER_PCLK_CLK_FORCE: 1;
        uint32_t RESERVED: 9;
    };
} PCC_REG_ETIMER_PCLK_TYPE;

/*0x4000_0914 PCC_REG_ETIMER_PCLK*/
#define PCC_REG_ETIMER_PCLK_ENTRY_DELAY_CORE1_DEV_ETIMER_PCLK_Pos                                0U
#define PCC_REG_ETIMER_PCLK_ENTRY_DELAY_CORE1_DEV_ETIMER_PCLK_Msk                                (0xFFUL << PCC_REG_ETIMER_PCLK_ENTRY_DELAY_CORE1_DEV_ETIMER_PCLK_Pos)

#define PCC_REG_ETIMER_PCLK_RESERVED_4_Pos                                                       8U
#define PCC_REG_ETIMER_PCLK_RESERVED_4_Msk                                                       (0x1UL << PCC_REG_ETIMER_PCLK_RESERVED_4_Pos)

#define PCC_REG_ETIMER_PCLK_RESERVED_3_Pos                                                       9U
#define PCC_REG_ETIMER_PCLK_RESERVED_3_Msk                                                       (0x1UL << PCC_REG_ETIMER_PCLK_RESERVED_3_Pos)

#define PCC_REG_ETIMER_PCLK_RESERVED_2_Pos                                                       10U
#define PCC_REG_ETIMER_PCLK_RESERVED_2_Msk                                                       (0x1UL << PCC_REG_ETIMER_PCLK_RESERVED_2_Pos)

#define PCC_REG_ETIMER_PCLK_RESERVED_1_Pos                                                       11U
#define PCC_REG_ETIMER_PCLK_RESERVED_1_Msk                                                       (0x7FFUL << PCC_REG_ETIMER_PCLK_RESERVED_1_Pos)

#define PCC_REG_ETIMER_PCLK_ETIMER_PCLK_CLK_FORCE_Pos                                            22U
#define PCC_REG_ETIMER_PCLK_ETIMER_PCLK_CLK_FORCE_Msk                                            (0x1UL << PCC_REG_ETIMER_PCLK_ETIMER_PCLK_CLK_FORCE_Pos)

#define PCC_REG_ETIMER_PCLK_RESERVED_Pos                                                         23U
#define PCC_REG_ETIMER_PCLK_RESERVED_Msk                                                         (0x1FFUL << PCC_REG_ETIMER_PCLK_RESERVED_Pos)

/* 0x918    0x4000_0918
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_OSC128K_CAL               8'b0
    31:8    R/W     RESERVED                                        24'b0
 */
typedef union _PCC_REG_OSC128K_CAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_OSC128K_CAL: 8;
        uint32_t RESERVED: 24;
    };
} PCC_REG_OSC128K_CAL_TYPE;

/*0x4000_0918 PCC_REG_OSC128K_CAL*/
#define PCC_REG_OSC128K_CAL_ENTRY_DELAY_CORE1_DEV_OSC128K_CAL_Pos                                0U
#define PCC_REG_OSC128K_CAL_ENTRY_DELAY_CORE1_DEV_OSC128K_CAL_Msk                                (0xFFUL << PCC_REG_OSC128K_CAL_ENTRY_DELAY_CORE1_DEV_OSC128K_CAL_Pos)

#define PCC_REG_OSC128K_CAL_RESERVED_Pos                                                         8U
#define PCC_REG_OSC128K_CAL_RESERVED_Msk                                                         (0xFFFFFFUL << PCC_REG_OSC128K_CAL_RESERVED_Pos)

/* 0x91C    0x4000_091c
    7:0     R/W     ENTRY_DELAY_RXI300                              8'b0
    31:8    R/W     RESERVED                                        24'b0
 */
typedef union _PCC_REG_RXI300_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_RXI300: 8;
        uint32_t RESERVED: 24;
    };
} PCC_REG_RXI300_TYPE;

/*0x4000_091c PCC_REG_RXI300*/
#define PCC_REG_RXI300_ENTRY_DELAY_RXI300_Pos                                                    0U
#define PCC_REG_RXI300_ENTRY_DELAY_RXI300_Msk                                                    (0xFFUL << PCC_REG_RXI300_ENTRY_DELAY_RXI300_Pos)

#define PCC_REG_RXI300_RESERVED_Pos                                                              8U
#define PCC_REG_RXI300_RESERVED_Msk                                                              (0xFFFFFFUL << PCC_REG_RXI300_RESERVED_Pos)

/* 0x920    0x4000_0920
    7:0     R/W     ENTRY_DELAY_AON_DEB_TOP                         8'b0
    31:8    R/W     RESERVED                                        24'b0
 */
typedef union _PCC_REG_AON_DEB_TOP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_AON_DEB_TOP: 8;
        uint32_t RESERVED: 24;
    };
} PCC_REG_AON_DEB_TOP_TYPE;

/*0x4000_0920 PCC_REG_AON_DEB_TOP*/
#define PCC_REG_AON_DEB_TOP_ENTRY_DELAY_AON_DEB_TOP_Pos                                          0U
#define PCC_REG_AON_DEB_TOP_ENTRY_DELAY_AON_DEB_TOP_Msk                                          (0xFFUL << PCC_REG_AON_DEB_TOP_ENTRY_DELAY_AON_DEB_TOP_Pos)

#define PCC_REG_AON_DEB_TOP_RESERVED_Pos                                                         8U
#define PCC_REG_AON_DEB_TOP_RESERVED_Msk                                                         (0xFFFFFFUL << PCC_REG_AON_DEB_TOP_RESERVED_Pos)

/* 0x924    0x4000_0924
    7:0     R/W     ENTRY_DELAY_CORE1_DEV_OSC128K                   8'b0
    15:8    R/W     ENTRY_DELAY_CORE1_DEV_OSC10M                    8'b0
    31:16   R/W     RESERVED                                        16'b0
 */
typedef union _PCC_REG_OTHERS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CORE1_DEV_OSC128K: 8;
        uint32_t ENTRY_DELAY_CORE1_DEV_OSC10M: 8;
        uint32_t RESERVED: 16;
    };
} PCC_REG_OTHERS_TYPE;

/*0x4000_0924 PCC_REG_OTHERS*/
#define PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC128K_Pos                                         0U
#define PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC128K_Msk                                         (0xFFUL << PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC128K_Pos)

#define PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC10M_Pos                                          8U
#define PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC10M_Msk                                          (0xFFUL << PCC_REG_OTHERS_ENTRY_DELAY_CORE1_DEV_OSC10M_Pos)

#define PCC_REG_OTHERS_RESERVED_Pos                                                              16U
#define PCC_REG_OTHERS_RESERVED_Msk                                                              (0xFFFFUL << PCC_REG_OTHERS_RESERVED_Pos)

/* 0x3C4    0x4000_03c4
    0       R/W     R_PON_FEN_VDREG                                 1'b0
    1       R/W     R_PON_FEN_SYSON                                 1'b1
    2       R/W     R_PON_FEN_TMETER                                1'b1
    3       R/W     R_PON_FEN_DSS                                   1'b0
    4       R/W     R_PON_FEN_CODEC                                 1'b0
    5       R/W     R_PON_FEN_UART2                                 1'b0
    6       R/W     R_PON_FEN_UART1                                 1'b0
    7       R/W     R_PON_FEN_UART0                                 1'b0
    8       R/W     R_PON_FEN_GPIO_DBNC_2P4G                        1'b0
    9       R/W     R_PON_FEN_CAN                                   1'b0
    10      R/W     R_PON_FEN_EFLASH                                1'b1
    11      R/W     R_PON_FEN_SPI3W                                 1'b0
    12      R/W     R_PON_FEN_KEYSCAN                               1'b0
    13      R/W     R_PON_FEN_I2C1                                  1'b0
    14      R/W     R_PON_FEN_I2C0                                  1'b0
    15      R/W     R_PON_FEN_ADC                                   1'b0
    16      R/W     R_PON_FEN_USB                                   1'b0
    17      R/W     R_PON_FEN_TIMER_2_PWM                           1'b0
    18      R/W     R_PON_FEN_TIMER_2                               1'b0
    19      R/W     R_PON_FEN_TIMER_1                               1'b0
    20      R/W     R_PON_FEN_TIMER_0                               1'b0
    21      R/W     R_PON_FEN_I2S                                   1'b0
    22      R/W     R_PON_FEN_SPI2                                  1'b0
    23      R/W     R_PON_FEN_SPI1                                  1'b0
    24      R/W     R_PON_FEN_SPI0                                  1'b0
    25      R/W     R_PON_FEN_FMC0                                  1'b0
    26      R/W     R_PON_FEN_DMA0                                  1'b0
    27      R/W     R_PON_FEN_MODEMRFCPI                            1'b0
    28      R/W     R_PON_FEN_SHA256                                1'b0
    29      R/W     R_PON_FEN_AES                                   1'b0
    30      R/W     R_PON_FEN_CORE_WDT                              1'b0
    31      R/W     R_PON_FEN_RNG                                   1'b0
 */
typedef union _PCC_REG_PERION_CLK_VPON_REG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PON_FEN_VDREG: 1;
        uint32_t R_PON_FEN_SYSON: 1;
        uint32_t R_PON_FEN_TMETER: 1;
        uint32_t R_PON_FEN_DSS: 1;
        uint32_t R_PON_FEN_CODEC: 1;
        uint32_t R_PON_FEN_UART2: 1;
        uint32_t R_PON_FEN_UART1: 1;
        uint32_t R_PON_FEN_UART0: 1;
        uint32_t R_PON_FEN_GPIO_DBNC_2P4G: 1;
        uint32_t R_PON_FEN_CAN: 1;
        uint32_t R_PON_FEN_EFLASH: 1;
        uint32_t R_PON_FEN_SPI3W: 1;
        uint32_t R_PON_FEN_KEYSCAN: 1;
        uint32_t R_PON_FEN_I2C1: 1;
        uint32_t R_PON_FEN_I2C0: 1;
        uint32_t R_PON_FEN_ADC: 1;
        uint32_t R_PON_FEN_USB: 1;
        uint32_t R_PON_FEN_TIMER_2_PWM: 1;
        uint32_t R_PON_FEN_TIMER_2: 1;
        uint32_t R_PON_FEN_TIMER_1: 1;
        uint32_t R_PON_FEN_TIMER_0: 1;
        uint32_t R_PON_FEN_I2S: 1;
        uint32_t R_PON_FEN_SPI2: 1;
        uint32_t R_PON_FEN_SPI1: 1;
        uint32_t R_PON_FEN_SPI0: 1;
        uint32_t R_PON_FEN_FMC0: 1;
        uint32_t R_PON_FEN_DMA0: 1;
        uint32_t R_PON_FEN_MODEMRFCPI: 1;
        uint32_t R_PON_FEN_SHA256: 1;
        uint32_t R_PON_FEN_AES: 1;
        uint32_t R_PON_FEN_CORE_WDT: 1;
        uint32_t R_PON_FEN_RNG: 1;
    };
} PCC_REG_PERION_CLK_VPON_REG0X_TYPE;

/*0x4000_03c4 PCC_REG_PERION_CLK_VPON_REG0X*/
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_VDREG_Pos                                        0U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_VDREG_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_VDREG_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SYSON_Pos                                        1U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SYSON_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SYSON_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TMETER_Pos                                       2U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TMETER_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TMETER_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DSS_Pos                                          3U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DSS_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DSS_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CODEC_Pos                                        4U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CODEC_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CODEC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART2_Pos                                        5U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART2_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART2_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART1_Pos                                        6U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART1_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART0_Pos                                        7U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART0_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_UART0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_GPIO_DBNC_2P4G_Pos                               8U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_GPIO_DBNC_2P4G_Msk                               (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_GPIO_DBNC_2P4G_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CAN_Pos                                          9U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CAN_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CAN_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_EFLASH_Pos                                       10U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_EFLASH_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_EFLASH_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI3W_Pos                                        11U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI3W_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI3W_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_KEYSCAN_Pos                                      12U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_KEYSCAN_Msk                                      (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_KEYSCAN_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C1_Pos                                         13U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C1_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C0_Pos                                         14U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C0_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2C0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_ADC_Pos                                          15U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_ADC_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_ADC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_USB_Pos                                          16U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_USB_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_USB_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_PWM_Pos                                  17U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_PWM_Msk                                  (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_PWM_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_Pos                                      18U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_Msk                                      (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_2_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_1_Pos                                      19U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_1_Msk                                      (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_0_Pos                                      20U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_0_Msk                                      (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_TIMER_0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2S_Pos                                          21U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2S_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_I2S_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI2_Pos                                         22U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI2_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI2_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI1_Pos                                         23U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI1_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI0_Pos                                         24U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI0_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SPI0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_FMC0_Pos                                         25U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_FMC0_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_FMC0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DMA0_Pos                                         26U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DMA0_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_DMA0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_MODEMRFCPI_Pos                                   27U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_MODEMRFCPI_Msk                                   (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_MODEMRFCPI_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SHA256_Pos                                       28U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SHA256_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_SHA256_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_AES_Pos                                          29U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_AES_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_AES_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CORE_WDT_Pos                                     30U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CORE_WDT_Msk                                     (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_CORE_WDT_Pos)

#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_RNG_Pos                                          31U
#define PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_RNG_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG0X_R_PON_FEN_RNG_Pos)

/* 0x3C8    0x4000_03c8
    11:0    R/W     RESERVED                                        12'h0
    12      W1O     SWD_ENABLE_WR_ENABLE                            1'b0
    13      R/W     SWD_ENABLE                                      1'b1
    14      R/W     R_PON_FEN_RFC                                   1'b0
    15      R/W     R_PON_FEN_PLATFORM                              1'b1
    16      R/W     R_PON_FEN_CPU                                   1'b1
    17      R/W     R_PON_FEN_SDM32K                                1'b1
    18      R/W     R_PON_FEN_AAC                                   1'b0
    19      R/W     R_PON_FEN_CAL80M                                1'b0
    20      R/W     R_PON_FEN_CAL10M                                1'b0
    21      R/W     R_PON_FEN_CAL32K                                1'b1
    22      R/W     R_PON_FEN_TIMER1_PWM_CH8                        1'b0
    23      R/W     R_PON_FEN_TIMER1_PWM_CH7                        1'b0
    24      R/W     R_PON_FEN_TIMER1_PWM_CH6                        1'b0
    25      R/W     R_PON_FEN_HCI                                   1'b0
    26      R/W     R_PON_FEN_LXBUS                                 1'b1
    27      R/W     R_PON_FEN_BT_VEN                                1'b1
    28      R/W     R_PON_FEN_IRRC                                  1'b0
    29      R/W     R_PON_FEN_PRO24G                                1'b0
    30      R/W     R_PON_FEN_GPIO0                                 1'b0
    31      R/W     R_PON_FEN_UART3                                 1'b0
 */
typedef union _PCC_REG_PERION_CLK_VPON_REG1X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED: 12;
        uint32_t SWD_ENABLE_WR_ENABLE: 1;
        uint32_t SWD_ENABLE: 1;
        uint32_t R_PON_FEN_RFC: 1;
        uint32_t R_PON_FEN_PLATFORM: 1;
        uint32_t R_PON_FEN_CPU: 1;
        uint32_t R_PON_FEN_SDM32K: 1;
        uint32_t R_PON_FEN_AAC: 1;
        uint32_t R_PON_FEN_CAL80M: 1;
        uint32_t R_PON_FEN_CAL10M: 1;
        uint32_t R_PON_FEN_CAL32K: 1;
        uint32_t R_PON_FEN_TIMER1_PWM_CH8: 1;
        uint32_t R_PON_FEN_TIMER1_PWM_CH7: 1;
        uint32_t R_PON_FEN_TIMER1_PWM_CH6: 1;
        uint32_t R_PON_FEN_HCI: 1;
        uint32_t R_PON_FEN_LXBUS: 1;
        uint32_t R_PON_FEN_BT_VEN: 1;
        uint32_t R_PON_FEN_IRRC: 1;
        uint32_t R_PON_FEN_PRO24G: 1;
        uint32_t R_PON_FEN_GPIO0: 1;
        uint32_t R_PON_FEN_UART3: 1;
    };
} PCC_REG_PERION_CLK_VPON_REG1X_TYPE;

/*0x4000_03c8 PCC_REG_PERION_CLK_VPON_REG1X*/
#define PCC_REG_PERION_CLK_VPON_REG1X_RESERVED_Pos                                               0U
#define PCC_REG_PERION_CLK_VPON_REG1X_RESERVED_Msk                                               (0xFFFUL << PCC_REG_PERION_CLK_VPON_REG1X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_WR_ENABLE_Pos                                   12U
#define PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_WR_ENABLE_Msk                                   (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_WR_ENABLE_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_Pos                                             13U
#define PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_Msk                                             (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_SWD_ENABLE_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_RFC_Pos                                          14U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_RFC_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_RFC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PLATFORM_Pos                                     15U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PLATFORM_Msk                                     (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PLATFORM_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CPU_Pos                                          16U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CPU_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CPU_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_SDM32K_Pos                                       17U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_SDM32K_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_SDM32K_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_AAC_Pos                                          18U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_AAC_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_AAC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL80M_Pos                                       19U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL80M_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL80M_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL10M_Pos                                       20U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL10M_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL10M_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL32K_Pos                                       21U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL32K_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_CAL32K_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH8_Pos                               22U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH8_Msk                               (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH8_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH7_Pos                               23U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH7_Msk                               (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH7_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH6_Pos                               24U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH6_Msk                               (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_TIMER1_PWM_CH6_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_HCI_Pos                                          25U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_HCI_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_HCI_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_LXBUS_Pos                                        26U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_LXBUS_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_LXBUS_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_BT_VEN_Pos                                       27U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_BT_VEN_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_BT_VEN_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_IRRC_Pos                                         28U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_IRRC_Msk                                         (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_IRRC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PRO24G_Pos                                       29U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PRO24G_Msk                                       (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_PRO24G_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_GPIO0_Pos                                        30U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_GPIO0_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_GPIO0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_UART3_Pos                                        31U
#define PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_UART3_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG1X_R_PON_FEN_UART3_Pos)

/* 0x3CC    0x4000_03cc
    0       R/W     S9_INTF_MASK_EN                                 1'b0
    1       R/W     M4_INTF_MASK_EN                                 1'b0
    6:2     R/W     RESERVED_3                                      5'h0
    7       R       CLKEN_O_BTMAC                                   1'b0
    20:8    R/W     RESERVED_2                                      13'h0
    21      R/W     R_CPU_CLK_SRC_SEL_1                             1'b0
    22      R/W     R_CPU_CLK_SRC_SEL_2                             1'b1
    23      R/W     R_40M_MAC_CLK_SRC_SEL                           1'b1
    26:24   R/W     RESERVED_1                                      3'h0
    27      R/W     R_40M_CLK_SRC_SEL_0                             1'b1
    30:28   R/W     RESERVED                                        3'h0
    31      R/W     R_32K_CLK_SRC_SEL                               1'b1
 */
typedef union _PCC_REG_PERION_CLK_VPON_REG2X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t S9_INTF_MASK_EN: 1;
        uint32_t M4_INTF_MASK_EN: 1;
        uint32_t RESERVED_3: 5;
        uint32_t CLKEN_O_BTMAC: 1;
        uint32_t RESERVED_2: 13;
        uint32_t R_CPU_CLK_SRC_SEL_1: 1;
        uint32_t R_CPU_CLK_SRC_SEL_2: 1;
        uint32_t R_40M_MAC_CLK_SRC_SEL: 1;
        uint32_t RESERVED_1: 3;
        uint32_t R_40M_CLK_SRC_SEL_0: 1;
        uint32_t RESERVED: 3;
        uint32_t R_32K_CLK_SRC_SEL: 1;
    };
} PCC_REG_PERION_CLK_VPON_REG2X_TYPE;

/*0x4000_03cc PCC_REG_PERION_CLK_VPON_REG2X*/
#define PCC_REG_PERION_CLK_VPON_REG2X_S9_INTF_MASK_EN_Pos                                        0U
#define PCC_REG_PERION_CLK_VPON_REG2X_S9_INTF_MASK_EN_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_S9_INTF_MASK_EN_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_M4_INTF_MASK_EN_Pos                                        1U
#define PCC_REG_PERION_CLK_VPON_REG2X_M4_INTF_MASK_EN_Msk                                        (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_M4_INTF_MASK_EN_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_3_Pos                                             2U
#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_3_Msk                                             (0x1FUL << PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_3_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_CLKEN_O_BTMAC_Pos                                          7U
#define PCC_REG_PERION_CLK_VPON_REG2X_CLKEN_O_BTMAC_Msk                                          (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_CLKEN_O_BTMAC_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_2_Pos                                             8U
#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_2_Msk                                             (0x1FFFUL << PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_2_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_1_Pos                                    21U
#define PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_1_Msk                                    (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_2_Pos                                    22U
#define PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_2_Msk                                    (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_R_CPU_CLK_SRC_SEL_2_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_R_40M_MAC_CLK_SRC_SEL_Pos                                  23U
#define PCC_REG_PERION_CLK_VPON_REG2X_R_40M_MAC_CLK_SRC_SEL_Msk                                  (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_R_40M_MAC_CLK_SRC_SEL_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_1_Pos                                             24U
#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_1_Msk                                             (0x7UL << PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_1_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_R_40M_CLK_SRC_SEL_0_Pos                                    27U
#define PCC_REG_PERION_CLK_VPON_REG2X_R_40M_CLK_SRC_SEL_0_Msk                                    (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_R_40M_CLK_SRC_SEL_0_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_Pos                                               28U
#define PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_Msk                                               (0x7UL << PCC_REG_PERION_CLK_VPON_REG2X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_VPON_REG2X_R_32K_CLK_SRC_SEL_Pos                                      31U
#define PCC_REG_PERION_CLK_VPON_REG2X_R_32K_CLK_SRC_SEL_Msk                                      (0x1UL << PCC_REG_PERION_CLK_VPON_REG2X_R_32K_CLK_SRC_SEL_Pos)

/* 0x3D0    0x4000_03d0
    7:0     R/W     ENTRY_DELAY_LPPWM                               8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     LPPWM_CLK_FORCE                                 1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_LPPWM                                 1'b0
 */
typedef union _PCC_REG_LPPWM_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_LPPWM: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t LPPWM_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_LPPWM: 1;
    };
} PCC_REG_LPPWM_TYPE;

/*0x4000_03d0 PCC_REG_LPPWM*/
#define PCC_REG_LPPWM_ENTRY_DELAY_LPPWM_Pos                                                      0U
#define PCC_REG_LPPWM_ENTRY_DELAY_LPPWM_Msk                                                      (0xFFUL << PCC_REG_LPPWM_ENTRY_DELAY_LPPWM_Pos)

#define PCC_REG_LPPWM_RSVD_2_Pos                                                                 8U
#define PCC_REG_LPPWM_RSVD_2_Msk                                                                 (0xFFUL << PCC_REG_LPPWM_RSVD_2_Pos)

#define PCC_REG_LPPWM_RESERVED_7_Pos                                                             16U
#define PCC_REG_LPPWM_RESERVED_7_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_7_Pos)

#define PCC_REG_LPPWM_RESERVED_6_Pos                                                             17U
#define PCC_REG_LPPWM_RESERVED_6_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_6_Pos)

#define PCC_REG_LPPWM_LPPWM_CLK_FORCE_Pos                                                        18U
#define PCC_REG_LPPWM_LPPWM_CLK_FORCE_Msk                                                        (0x1UL << PCC_REG_LPPWM_LPPWM_CLK_FORCE_Pos)

#define PCC_REG_LPPWM_RSVD_1_Pos                                                                 19U
#define PCC_REG_LPPWM_RSVD_1_Msk                                                                 (0x7UL << PCC_REG_LPPWM_RSVD_1_Pos)

#define PCC_REG_LPPWM_RESERVED_5_Pos                                                             22U
#define PCC_REG_LPPWM_RESERVED_5_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_5_Pos)

#define PCC_REG_LPPWM_RESERVED_4_Pos                                                             23U
#define PCC_REG_LPPWM_RESERVED_4_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_4_Pos)

#define PCC_REG_LPPWM_RESERVED_3_Pos                                                             24U
#define PCC_REG_LPPWM_RESERVED_3_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_3_Pos)

#define PCC_REG_LPPWM_RESERVED_2_Pos                                                             25U
#define PCC_REG_LPPWM_RESERVED_2_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_2_Pos)

#define PCC_REG_LPPWM_RESERVED_1_Pos                                                             26U
#define PCC_REG_LPPWM_RESERVED_1_Msk                                                             (0x1UL << PCC_REG_LPPWM_RESERVED_1_Pos)

#define PCC_REG_LPPWM_RESERVED_Pos                                                               27U
#define PCC_REG_LPPWM_RESERVED_Msk                                                               (0x1UL << PCC_REG_LPPWM_RESERVED_Pos)

#define PCC_REG_LPPWM_RSVD_Pos                                                                   28U
#define PCC_REG_LPPWM_RSVD_Msk                                                                   (0x7UL << PCC_REG_LPPWM_RSVD_Pos)

#define PCC_REG_LPPWM_R_PON_FEN_LPPWM_Pos                                                        31U
#define PCC_REG_LPPWM_R_PON_FEN_LPPWM_Msk                                                        (0x1UL << PCC_REG_LPPWM_R_PON_FEN_LPPWM_Pos)

/* 0x3D4    0x4000_03d4
    7:0     R/W     ENTRY_DELAY_LPQDEC                              8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     LPQDEC_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_LPQDEC                                1'b0
 */
typedef union _PCC_REG_LPQDEC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_LPQDEC: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t LPQDEC_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_LPQDEC: 1;
    };
} PCC_REG_LPQDEC_TYPE;

/*0x4000_03d4 PCC_REG_LPQDEC*/
#define PCC_REG_LPQDEC_ENTRY_DELAY_LPQDEC_Pos                                                    0U
#define PCC_REG_LPQDEC_ENTRY_DELAY_LPQDEC_Msk                                                    (0xFFUL << PCC_REG_LPQDEC_ENTRY_DELAY_LPQDEC_Pos)

#define PCC_REG_LPQDEC_RSVD_2_Pos                                                                8U
#define PCC_REG_LPQDEC_RSVD_2_Msk                                                                (0xFFUL << PCC_REG_LPQDEC_RSVD_2_Pos)

#define PCC_REG_LPQDEC_RESERVED_7_Pos                                                            16U
#define PCC_REG_LPQDEC_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_7_Pos)

#define PCC_REG_LPQDEC_RESERVED_6_Pos                                                            17U
#define PCC_REG_LPQDEC_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_6_Pos)

#define PCC_REG_LPQDEC_LPQDEC_CLK_FORCE_Pos                                                      18U
#define PCC_REG_LPQDEC_LPQDEC_CLK_FORCE_Msk                                                      (0x1UL << PCC_REG_LPQDEC_LPQDEC_CLK_FORCE_Pos)

#define PCC_REG_LPQDEC_RSVD_1_Pos                                                                19U
#define PCC_REG_LPQDEC_RSVD_1_Msk                                                                (0x7UL << PCC_REG_LPQDEC_RSVD_1_Pos)

#define PCC_REG_LPQDEC_RESERVED_5_Pos                                                            22U
#define PCC_REG_LPQDEC_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_5_Pos)

#define PCC_REG_LPQDEC_RESERVED_4_Pos                                                            23U
#define PCC_REG_LPQDEC_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_4_Pos)

#define PCC_REG_LPQDEC_RESERVED_3_Pos                                                            24U
#define PCC_REG_LPQDEC_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_3_Pos)

#define PCC_REG_LPQDEC_RESERVED_2_Pos                                                            25U
#define PCC_REG_LPQDEC_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_2_Pos)

#define PCC_REG_LPQDEC_RESERVED_1_Pos                                                            26U
#define PCC_REG_LPQDEC_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_LPQDEC_RESERVED_1_Pos)

#define PCC_REG_LPQDEC_RESERVED_Pos                                                              27U
#define PCC_REG_LPQDEC_RESERVED_Msk                                                              (0x1UL << PCC_REG_LPQDEC_RESERVED_Pos)

#define PCC_REG_LPQDEC_RSVD_Pos                                                                  28U
#define PCC_REG_LPQDEC_RSVD_Msk                                                                  (0x7UL << PCC_REG_LPQDEC_RSVD_Pos)

#define PCC_REG_LPQDEC_R_PON_FEN_LPQDEC_Pos                                                      31U
#define PCC_REG_LPQDEC_R_PON_FEN_LPQDEC_Msk                                                      (0x1UL << PCC_REG_LPQDEC_R_PON_FEN_LPQDEC_Pos)

/* 0x3D8    0x4000_03d8
    7:0     R/W     ENTRY_DELAY_GRTC                                8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     GRTC_CLK_FORCE                                  1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_GRTC                                  1'b0
 */
typedef union _PCC_REG_GRTC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_GRTC: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t GRTC_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_GRTC: 1;
    };
} PCC_REG_GRTC_TYPE;

/*0x4000_03d8 PCC_REG_GRTC*/
#define PCC_REG_GRTC_ENTRY_DELAY_GRTC_Pos                                                        0U
#define PCC_REG_GRTC_ENTRY_DELAY_GRTC_Msk                                                        (0xFFUL << PCC_REG_GRTC_ENTRY_DELAY_GRTC_Pos)

#define PCC_REG_GRTC_RSVD_2_Pos                                                                  8U
#define PCC_REG_GRTC_RSVD_2_Msk                                                                  (0xFFUL << PCC_REG_GRTC_RSVD_2_Pos)

#define PCC_REG_GRTC_RESERVED_7_Pos                                                              16U
#define PCC_REG_GRTC_RESERVED_7_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_7_Pos)

#define PCC_REG_GRTC_RESERVED_6_Pos                                                              17U
#define PCC_REG_GRTC_RESERVED_6_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_6_Pos)

#define PCC_REG_GRTC_GRTC_CLK_FORCE_Pos                                                          18U
#define PCC_REG_GRTC_GRTC_CLK_FORCE_Msk                                                          (0x1UL << PCC_REG_GRTC_GRTC_CLK_FORCE_Pos)

#define PCC_REG_GRTC_RSVD_1_Pos                                                                  19U
#define PCC_REG_GRTC_RSVD_1_Msk                                                                  (0x7UL << PCC_REG_GRTC_RSVD_1_Pos)

#define PCC_REG_GRTC_RESERVED_5_Pos                                                              22U
#define PCC_REG_GRTC_RESERVED_5_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_5_Pos)

#define PCC_REG_GRTC_RESERVED_4_Pos                                                              23U
#define PCC_REG_GRTC_RESERVED_4_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_4_Pos)

#define PCC_REG_GRTC_RESERVED_3_Pos                                                              24U
#define PCC_REG_GRTC_RESERVED_3_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_3_Pos)

#define PCC_REG_GRTC_RESERVED_2_Pos                                                              25U
#define PCC_REG_GRTC_RESERVED_2_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_2_Pos)

#define PCC_REG_GRTC_RESERVED_1_Pos                                                              26U
#define PCC_REG_GRTC_RESERVED_1_Msk                                                              (0x1UL << PCC_REG_GRTC_RESERVED_1_Pos)

#define PCC_REG_GRTC_RESERVED_Pos                                                                27U
#define PCC_REG_GRTC_RESERVED_Msk                                                                (0x1UL << PCC_REG_GRTC_RESERVED_Pos)

#define PCC_REG_GRTC_RSVD_Pos                                                                    28U
#define PCC_REG_GRTC_RSVD_Msk                                                                    (0x7UL << PCC_REG_GRTC_RSVD_Pos)

#define PCC_REG_GRTC_R_PON_FEN_GRTC_Pos                                                          31U
#define PCC_REG_GRTC_R_PON_FEN_GRTC_Msk                                                          (0x1UL << PCC_REG_GRTC_R_PON_FEN_GRTC_Pos)

/* 0x3DC    0x4000_03dc
    0       R/W     RESERVED_13                                     1'b0
    1       R/W     RESERVED_12                                     1'b0
    2       R/W     RESERVED_11                                     1'b0
    3       R/W     RESERVED_10                                     1'b0
    4       R/W     RESERVED_9                                      1'b0
    5       R/W     RESERVED_8                                      1'b0
    15:6    R/W     RSVD_2                                          10'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     BLUEWIZ_CLK_FORCE                               1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_BLUEWIZ                               1'b0
 */
typedef union _PCC_REG_BLUEWIZ_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RSVD_2: 10;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t BLUEWIZ_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_BLUEWIZ: 1;
    };
} PCC_REG_BLUEWIZ_TYPE;

/*0x4000_03dc PCC_REG_BLUEWIZ*/
#define PCC_REG_BLUEWIZ_RESERVED_13_Pos                                                          0U
#define PCC_REG_BLUEWIZ_RESERVED_13_Msk                                                          (0x1UL << PCC_REG_BLUEWIZ_RESERVED_13_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_12_Pos                                                          1U
#define PCC_REG_BLUEWIZ_RESERVED_12_Msk                                                          (0x1UL << PCC_REG_BLUEWIZ_RESERVED_12_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_11_Pos                                                          2U
#define PCC_REG_BLUEWIZ_RESERVED_11_Msk                                                          (0x1UL << PCC_REG_BLUEWIZ_RESERVED_11_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_10_Pos                                                          3U
#define PCC_REG_BLUEWIZ_RESERVED_10_Msk                                                          (0x1UL << PCC_REG_BLUEWIZ_RESERVED_10_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_9_Pos                                                           4U
#define PCC_REG_BLUEWIZ_RESERVED_9_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_9_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_8_Pos                                                           5U
#define PCC_REG_BLUEWIZ_RESERVED_8_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_8_Pos)

#define PCC_REG_BLUEWIZ_RSVD_2_Pos                                                               6U
#define PCC_REG_BLUEWIZ_RSVD_2_Msk                                                               (0x3FFUL << PCC_REG_BLUEWIZ_RSVD_2_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_7_Pos                                                           16U
#define PCC_REG_BLUEWIZ_RESERVED_7_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_7_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_6_Pos                                                           17U
#define PCC_REG_BLUEWIZ_RESERVED_6_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_6_Pos)

#define PCC_REG_BLUEWIZ_BLUEWIZ_CLK_FORCE_Pos                                                    18U
#define PCC_REG_BLUEWIZ_BLUEWIZ_CLK_FORCE_Msk                                                    (0x1UL << PCC_REG_BLUEWIZ_BLUEWIZ_CLK_FORCE_Pos)

#define PCC_REG_BLUEWIZ_RSVD_1_Pos                                                               19U
#define PCC_REG_BLUEWIZ_RSVD_1_Msk                                                               (0x7UL << PCC_REG_BLUEWIZ_RSVD_1_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_5_Pos                                                           22U
#define PCC_REG_BLUEWIZ_RESERVED_5_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_5_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_4_Pos                                                           23U
#define PCC_REG_BLUEWIZ_RESERVED_4_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_4_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_3_Pos                                                           24U
#define PCC_REG_BLUEWIZ_RESERVED_3_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_3_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_2_Pos                                                           25U
#define PCC_REG_BLUEWIZ_RESERVED_2_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_2_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_1_Pos                                                           26U
#define PCC_REG_BLUEWIZ_RESERVED_1_Msk                                                           (0x1UL << PCC_REG_BLUEWIZ_RESERVED_1_Pos)

#define PCC_REG_BLUEWIZ_RESERVED_Pos                                                             27U
#define PCC_REG_BLUEWIZ_RESERVED_Msk                                                             (0x1UL << PCC_REG_BLUEWIZ_RESERVED_Pos)

#define PCC_REG_BLUEWIZ_RSVD_Pos                                                                 28U
#define PCC_REG_BLUEWIZ_RSVD_Msk                                                                 (0x7UL << PCC_REG_BLUEWIZ_RSVD_Pos)

#define PCC_REG_BLUEWIZ_R_PON_FEN_BLUEWIZ_Pos                                                    31U
#define PCC_REG_BLUEWIZ_R_PON_FEN_BLUEWIZ_Msk                                                    (0x1UL << PCC_REG_BLUEWIZ_R_PON_FEN_BLUEWIZ_Pos)

/* 0x3E0    0x4000_03e0
    7:0     R/W     ENTRY_DELAY_USER_RTC                            8'b0
    15:8    R/W     RSVD_3                                          8'h0
    16      R/W     RESERVED_3                                      1'b0
    17      R/W     RESERVED_2                                      1'b0
    18      R/W     USER_RTC_CLK_FORCE                              1'b0
    21:19   R/W     RSVD_2                                          3'b000
    22      R/W     MULTI_DATA_CMP_OUT                              1'b0
    24:23   R/W     RSVD_1                                          2'b00
    25      R/W     R_RTC_GPIO_CLK_SRC_SEL                          1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_USER_RTC                              1'b0
 */
typedef union _PCC_REG_USER_RTC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_USER_RTC: 8;
        uint32_t RSVD_3: 8;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t USER_RTC_CLK_FORCE: 1;
        uint32_t RSVD_2: 3;
        uint32_t MULTI_DATA_CMP_OUT: 1;
        uint32_t RSVD_1: 2;
        uint32_t R_RTC_GPIO_CLK_SRC_SEL: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_USER_RTC: 1;
    };
} PCC_REG_USER_RTC_TYPE;

/*0x4000_03e0 PCC_REG_USER_RTC*/
#define PCC_REG_USER_RTC_ENTRY_DELAY_USER_RTC_Pos                                                0U
#define PCC_REG_USER_RTC_ENTRY_DELAY_USER_RTC_Msk                                                (0xFFUL << PCC_REG_USER_RTC_ENTRY_DELAY_USER_RTC_Pos)

#define PCC_REG_USER_RTC_RSVD_3_Pos                                                              8U
#define PCC_REG_USER_RTC_RSVD_3_Msk                                                              (0xFFUL << PCC_REG_USER_RTC_RSVD_3_Pos)

#define PCC_REG_USER_RTC_RESERVED_3_Pos                                                          16U
#define PCC_REG_USER_RTC_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_USER_RTC_RESERVED_3_Pos)

#define PCC_REG_USER_RTC_RESERVED_2_Pos                                                          17U
#define PCC_REG_USER_RTC_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_USER_RTC_RESERVED_2_Pos)

#define PCC_REG_USER_RTC_USER_RTC_CLK_FORCE_Pos                                                  18U
#define PCC_REG_USER_RTC_USER_RTC_CLK_FORCE_Msk                                                  (0x1UL << PCC_REG_USER_RTC_USER_RTC_CLK_FORCE_Pos)

#define PCC_REG_USER_RTC_RSVD_2_Pos                                                              19U
#define PCC_REG_USER_RTC_RSVD_2_Msk                                                              (0x7UL << PCC_REG_USER_RTC_RSVD_2_Pos)

#define PCC_REG_USER_RTC_MULTI_DATA_CMP_OUT_Pos                                                  22U
#define PCC_REG_USER_RTC_MULTI_DATA_CMP_OUT_Msk                                                  (0x1UL << PCC_REG_USER_RTC_MULTI_DATA_CMP_OUT_Pos)

#define PCC_REG_USER_RTC_RSVD_1_Pos                                                              23U
#define PCC_REG_USER_RTC_RSVD_1_Msk                                                              (0x3UL << PCC_REG_USER_RTC_RSVD_1_Pos)

#define PCC_REG_USER_RTC_R_RTC_GPIO_CLK_SRC_SEL_Pos                                              25U
#define PCC_REG_USER_RTC_R_RTC_GPIO_CLK_SRC_SEL_Msk                                              (0x1UL << PCC_REG_USER_RTC_R_RTC_GPIO_CLK_SRC_SEL_Pos)

#define PCC_REG_USER_RTC_RESERVED_1_Pos                                                          26U
#define PCC_REG_USER_RTC_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_USER_RTC_RESERVED_1_Pos)

#define PCC_REG_USER_RTC_RESERVED_Pos                                                            27U
#define PCC_REG_USER_RTC_RESERVED_Msk                                                            (0x1UL << PCC_REG_USER_RTC_RESERVED_Pos)

#define PCC_REG_USER_RTC_RSVD_Pos                                                                28U
#define PCC_REG_USER_RTC_RSVD_Msk                                                                (0x7UL << PCC_REG_USER_RTC_RSVD_Pos)

#define PCC_REG_USER_RTC_R_PON_FEN_USER_RTC_Pos                                                  31U
#define PCC_REG_USER_RTC_R_PON_FEN_USER_RTC_Msk                                                  (0x1UL << PCC_REG_USER_RTC_R_PON_FEN_USER_RTC_Pos)

/* 0x3E4    0x4000_03e4
    7:0     R/W     ENTRY_DELAY_RAP                                 8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     RAP_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_RAP                                   1'b0
 */
typedef union _PCC_REG_RAP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_RAP: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RAP_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_RAP: 1;
    };
} PCC_REG_RAP_TYPE;

/*0x4000_03e4 PCC_REG_RAP*/
#define PCC_REG_RAP_ENTRY_DELAY_RAP_Pos                                                          0U
#define PCC_REG_RAP_ENTRY_DELAY_RAP_Msk                                                          (0xFFUL << PCC_REG_RAP_ENTRY_DELAY_RAP_Pos)

#define PCC_REG_RAP_RSVD_2_Pos                                                                   8U
#define PCC_REG_RAP_RSVD_2_Msk                                                                   (0xFFUL << PCC_REG_RAP_RSVD_2_Pos)

#define PCC_REG_RAP_RESERVED_7_Pos                                                               16U
#define PCC_REG_RAP_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_7_Pos)

#define PCC_REG_RAP_RESERVED_6_Pos                                                               17U
#define PCC_REG_RAP_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_6_Pos)

#define PCC_REG_RAP_RAP_CLK_FORCE_Pos                                                            18U
#define PCC_REG_RAP_RAP_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_RAP_RAP_CLK_FORCE_Pos)

#define PCC_REG_RAP_RSVD_1_Pos                                                                   19U
#define PCC_REG_RAP_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_RAP_RSVD_1_Pos)

#define PCC_REG_RAP_RESERVED_5_Pos                                                               22U
#define PCC_REG_RAP_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_5_Pos)

#define PCC_REG_RAP_RESERVED_4_Pos                                                               23U
#define PCC_REG_RAP_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_4_Pos)

#define PCC_REG_RAP_RESERVED_3_Pos                                                               24U
#define PCC_REG_RAP_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_3_Pos)

#define PCC_REG_RAP_RESERVED_2_Pos                                                               25U
#define PCC_REG_RAP_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_2_Pos)

#define PCC_REG_RAP_RESERVED_1_Pos                                                               26U
#define PCC_REG_RAP_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_RAP_RESERVED_1_Pos)

#define PCC_REG_RAP_RESERVED_Pos                                                                 27U
#define PCC_REG_RAP_RESERVED_Msk                                                                 (0x1UL << PCC_REG_RAP_RESERVED_Pos)

#define PCC_REG_RAP_RSVD_Pos                                                                     28U
#define PCC_REG_RAP_RSVD_Msk                                                                     (0x7UL << PCC_REG_RAP_RSVD_Pos)

#define PCC_REG_RAP_R_PON_FEN_RAP_Pos                                                            31U
#define PCC_REG_RAP_R_PON_FEN_RAP_Msk                                                            (0x1UL << PCC_REG_RAP_R_PON_FEN_RAP_Pos)

/* 0x3E8    0x4000_03e8
    7:0     R/W     ENTRY_DELAY_SCHPLN                              8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_6                                      1'b1
    17      R/W     RESERVED_5                                      1'b1
    18      R/W     SCHPLN_CLK_FORCE                                1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_4                                      1'b0
    23      R/W     RESERVED_3                                      1'b0
    24      R/W     RESERVED_2                                      1'b0
    25      R/W     RESERVED_1                                      1'b0
    26      R/W     RESERVED                                        1'b0
    27      R/W     R_PON_FEN_SCHPLN                                1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_GTC                                   1'b1
 */
typedef union _PCC_REG_GTC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_SCHPLN: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t SCHPLN_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t R_PON_FEN_SCHPLN: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_GTC: 1;
    };
} PCC_REG_GTC_TYPE;

/*0x4000_03e8 PCC_REG_GTC*/
#define PCC_REG_GTC_ENTRY_DELAY_SCHPLN_Pos                                                       0U
#define PCC_REG_GTC_ENTRY_DELAY_SCHPLN_Msk                                                       (0xFFUL << PCC_REG_GTC_ENTRY_DELAY_SCHPLN_Pos)

#define PCC_REG_GTC_RSVD_2_Pos                                                                   8U
#define PCC_REG_GTC_RSVD_2_Msk                                                                   (0xFFUL << PCC_REG_GTC_RSVD_2_Pos)

#define PCC_REG_GTC_RESERVED_6_Pos                                                               16U
#define PCC_REG_GTC_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_6_Pos)

#define PCC_REG_GTC_RESERVED_5_Pos                                                               17U
#define PCC_REG_GTC_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_5_Pos)

#define PCC_REG_GTC_SCHPLN_CLK_FORCE_Pos                                                         18U
#define PCC_REG_GTC_SCHPLN_CLK_FORCE_Msk                                                         (0x1UL << PCC_REG_GTC_SCHPLN_CLK_FORCE_Pos)

#define PCC_REG_GTC_RSVD_1_Pos                                                                   19U
#define PCC_REG_GTC_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_GTC_RSVD_1_Pos)

#define PCC_REG_GTC_RESERVED_4_Pos                                                               22U
#define PCC_REG_GTC_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_4_Pos)

#define PCC_REG_GTC_RESERVED_3_Pos                                                               23U
#define PCC_REG_GTC_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_3_Pos)

#define PCC_REG_GTC_RESERVED_2_Pos                                                               24U
#define PCC_REG_GTC_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_2_Pos)

#define PCC_REG_GTC_RESERVED_1_Pos                                                               25U
#define PCC_REG_GTC_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_GTC_RESERVED_1_Pos)

#define PCC_REG_GTC_RESERVED_Pos                                                                 26U
#define PCC_REG_GTC_RESERVED_Msk                                                                 (0x1UL << PCC_REG_GTC_RESERVED_Pos)

#define PCC_REG_GTC_R_PON_FEN_SCHPLN_Pos                                                         27U
#define PCC_REG_GTC_R_PON_FEN_SCHPLN_Msk                                                         (0x1UL << PCC_REG_GTC_R_PON_FEN_SCHPLN_Pos)

#define PCC_REG_GTC_RSVD_Pos                                                                     28U
#define PCC_REG_GTC_RSVD_Msk                                                                     (0x7UL << PCC_REG_GTC_RSVD_Pos)

#define PCC_REG_GTC_R_PON_FEN_GTC_Pos                                                            31U
#define PCC_REG_GTC_R_PON_FEN_GTC_Msk                                                            (0x1UL << PCC_REG_GTC_R_PON_FEN_GTC_Pos)

/* 0x3EC    0x4000_03ec
    7:0     R/W     ENTRY_DELAY_CAL32K                              8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     SDM_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_CAL32K_VPON                           1'b0
 */
typedef union _PCC_REG_SDM_VPON_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_CAL32K: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t SDM_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_CAL32K_VPON: 1;
    };
} PCC_REG_SDM_VPON_TYPE;

/*0x4000_03ec PCC_REG_SDM_VPON*/
#define PCC_REG_SDM_VPON_ENTRY_DELAY_CAL32K_Pos                                                  0U
#define PCC_REG_SDM_VPON_ENTRY_DELAY_CAL32K_Msk                                                  (0xFFUL << PCC_REG_SDM_VPON_ENTRY_DELAY_CAL32K_Pos)

#define PCC_REG_SDM_VPON_RSVD_2_Pos                                                              8U
#define PCC_REG_SDM_VPON_RSVD_2_Msk                                                              (0xFFUL << PCC_REG_SDM_VPON_RSVD_2_Pos)

#define PCC_REG_SDM_VPON_RESERVED_7_Pos                                                          16U
#define PCC_REG_SDM_VPON_RESERVED_7_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_7_Pos)

#define PCC_REG_SDM_VPON_RESERVED_6_Pos                                                          17U
#define PCC_REG_SDM_VPON_RESERVED_6_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_6_Pos)

#define PCC_REG_SDM_VPON_SDM_CLK_FORCE_Pos                                                       18U
#define PCC_REG_SDM_VPON_SDM_CLK_FORCE_Msk                                                       (0x1UL << PCC_REG_SDM_VPON_SDM_CLK_FORCE_Pos)

#define PCC_REG_SDM_VPON_RSVD_1_Pos                                                              19U
#define PCC_REG_SDM_VPON_RSVD_1_Msk                                                              (0x7UL << PCC_REG_SDM_VPON_RSVD_1_Pos)

#define PCC_REG_SDM_VPON_RESERVED_5_Pos                                                          22U
#define PCC_REG_SDM_VPON_RESERVED_5_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_5_Pos)

#define PCC_REG_SDM_VPON_RESERVED_4_Pos                                                          23U
#define PCC_REG_SDM_VPON_RESERVED_4_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_4_Pos)

#define PCC_REG_SDM_VPON_RESERVED_3_Pos                                                          24U
#define PCC_REG_SDM_VPON_RESERVED_3_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_3_Pos)

#define PCC_REG_SDM_VPON_RESERVED_2_Pos                                                          25U
#define PCC_REG_SDM_VPON_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_2_Pos)

#define PCC_REG_SDM_VPON_RESERVED_1_Pos                                                          26U
#define PCC_REG_SDM_VPON_RESERVED_1_Msk                                                          (0x1UL << PCC_REG_SDM_VPON_RESERVED_1_Pos)

#define PCC_REG_SDM_VPON_RESERVED_Pos                                                            27U
#define PCC_REG_SDM_VPON_RESERVED_Msk                                                            (0x1UL << PCC_REG_SDM_VPON_RESERVED_Pos)

#define PCC_REG_SDM_VPON_RSVD_Pos                                                                28U
#define PCC_REG_SDM_VPON_RSVD_Msk                                                                (0x7UL << PCC_REG_SDM_VPON_RSVD_Pos)

#define PCC_REG_SDM_VPON_R_PON_FEN_CAL32K_VPON_Pos                                               31U
#define PCC_REG_SDM_VPON_R_PON_FEN_CAL32K_VPON_Msk                                               (0x1UL << PCC_REG_SDM_VPON_R_PON_FEN_CAL32K_VPON_Pos)

/* 0x3F0    0x4000_03f0
    7:0     R/W     ENTRY_DELAY_WDT                                 8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b1
    18      R/W     WDT_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_WDT                                   1'b0
 */
typedef union _PCC_REG_LPWDT_VPON_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_WDT: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t WDT_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_WDT: 1;
    };
} PCC_REG_LPWDT_VPON_TYPE;

/*0x4000_03f0 PCC_REG_LPWDT_VPON*/
#define PCC_REG_LPWDT_VPON_ENTRY_DELAY_WDT_Pos                                                   0U
#define PCC_REG_LPWDT_VPON_ENTRY_DELAY_WDT_Msk                                                   (0xFFUL << PCC_REG_LPWDT_VPON_ENTRY_DELAY_WDT_Pos)

#define PCC_REG_LPWDT_VPON_RSVD_2_Pos                                                            8U
#define PCC_REG_LPWDT_VPON_RSVD_2_Msk                                                            (0xFFUL << PCC_REG_LPWDT_VPON_RSVD_2_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_7_Pos                                                        16U
#define PCC_REG_LPWDT_VPON_RESERVED_7_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_7_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_6_Pos                                                        17U
#define PCC_REG_LPWDT_VPON_RESERVED_6_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_6_Pos)

#define PCC_REG_LPWDT_VPON_WDT_CLK_FORCE_Pos                                                     18U
#define PCC_REG_LPWDT_VPON_WDT_CLK_FORCE_Msk                                                     (0x1UL << PCC_REG_LPWDT_VPON_WDT_CLK_FORCE_Pos)

#define PCC_REG_LPWDT_VPON_RSVD_1_Pos                                                            19U
#define PCC_REG_LPWDT_VPON_RSVD_1_Msk                                                            (0x7UL << PCC_REG_LPWDT_VPON_RSVD_1_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_5_Pos                                                        22U
#define PCC_REG_LPWDT_VPON_RESERVED_5_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_5_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_4_Pos                                                        23U
#define PCC_REG_LPWDT_VPON_RESERVED_4_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_4_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_3_Pos                                                        24U
#define PCC_REG_LPWDT_VPON_RESERVED_3_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_3_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_2_Pos                                                        25U
#define PCC_REG_LPWDT_VPON_RESERVED_2_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_2_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_1_Pos                                                        26U
#define PCC_REG_LPWDT_VPON_RESERVED_1_Msk                                                        (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_1_Pos)

#define PCC_REG_LPWDT_VPON_RESERVED_Pos                                                          27U
#define PCC_REG_LPWDT_VPON_RESERVED_Msk                                                          (0x1UL << PCC_REG_LPWDT_VPON_RESERVED_Pos)

#define PCC_REG_LPWDT_VPON_RSVD_Pos                                                              28U
#define PCC_REG_LPWDT_VPON_RSVD_Msk                                                              (0x7UL << PCC_REG_LPWDT_VPON_RSVD_Pos)

#define PCC_REG_LPWDT_VPON_R_PON_FEN_WDT_Pos                                                     31U
#define PCC_REG_LPWDT_VPON_R_PON_FEN_WDT_Msk                                                     (0x1UL << PCC_REG_LPWDT_VPON_R_PON_FEN_WDT_Pos)

/* 0x3F4    0x4000_03f4
    28:0    R/W     RESERVED                                        29'h0
    31:29   R/W     AON_HF_DIV_SEL                                  3'b000
 */
typedef union _PCC_REG_PERION_CLK_AON_REG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED: 29;
        uint32_t AON_HF_DIV_SEL: 3;
    };
} PCC_REG_PERION_CLK_AON_REG0X_TYPE;

/*0x4000_03f4 PCC_REG_PERION_CLK_AON_REG0X*/
#define PCC_REG_PERION_CLK_AON_REG0X_RESERVED_Pos                                                0U
#define PCC_REG_PERION_CLK_AON_REG0X_RESERVED_Msk                                                (0x1FFFFFFFUL << PCC_REG_PERION_CLK_AON_REG0X_RESERVED_Pos)

#define PCC_REG_PERION_CLK_AON_REG0X_AON_HF_DIV_SEL_Pos                                          29U
#define PCC_REG_PERION_CLK_AON_REG0X_AON_HF_DIV_SEL_Msk                                          (0x7UL << PCC_REG_PERION_CLK_AON_REG0X_AON_HF_DIV_SEL_Pos)

/* 0x3F8    0x4000_03f8
    0       R/W     RESERVED_15                                     1'b0
    1       R/W     RESERVED_14                                     1'b0
    2       R/W     RESERVED_13                                     1'b0
    3       R/W     RESERVED_12                                     1'b0
    4       R/W     RESERVED_11                                     1'b0
    5       R/W     RESERVED_10                                     1'b0
    15:6    R/W     RSVD_2                                          10'h0
    16      R/W     RESERVED_9                                      1'b0
    17      R/W     RESERVED_8                                      1'b0
    18      R/W     RESERVED_7                                      1'b1
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_6                                      1'b0
    23      R/W     RESERVED_5                                      1'b0
    24      R/W     RESERVED_4                                      1'b0
    25      R/W     RESERVED_3                                      1'b0
    26      R/W     RESERVED_2                                      1'b0
    27      R/W     RESERVED_1                                      1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PCK600_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 1;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RSVD_2: 10;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RSVD: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PCK600_TYPE;

/*0x4000_03f8 PCC_REG_PCK600*/
#define PCC_REG_PCK600_RESERVED_15_Pos                                                           0U
#define PCC_REG_PCK600_RESERVED_15_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_15_Pos)

#define PCC_REG_PCK600_RESERVED_14_Pos                                                           1U
#define PCC_REG_PCK600_RESERVED_14_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_14_Pos)

#define PCC_REG_PCK600_RESERVED_13_Pos                                                           2U
#define PCC_REG_PCK600_RESERVED_13_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_13_Pos)

#define PCC_REG_PCK600_RESERVED_12_Pos                                                           3U
#define PCC_REG_PCK600_RESERVED_12_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_12_Pos)

#define PCC_REG_PCK600_RESERVED_11_Pos                                                           4U
#define PCC_REG_PCK600_RESERVED_11_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_11_Pos)

#define PCC_REG_PCK600_RESERVED_10_Pos                                                           5U
#define PCC_REG_PCK600_RESERVED_10_Msk                                                           (0x1UL << PCC_REG_PCK600_RESERVED_10_Pos)

#define PCC_REG_PCK600_RSVD_2_Pos                                                                6U
#define PCC_REG_PCK600_RSVD_2_Msk                                                                (0x3FFUL << PCC_REG_PCK600_RSVD_2_Pos)

#define PCC_REG_PCK600_RESERVED_9_Pos                                                            16U
#define PCC_REG_PCK600_RESERVED_9_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_9_Pos)

#define PCC_REG_PCK600_RESERVED_8_Pos                                                            17U
#define PCC_REG_PCK600_RESERVED_8_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_8_Pos)

#define PCC_REG_PCK600_RESERVED_7_Pos                                                            18U
#define PCC_REG_PCK600_RESERVED_7_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_7_Pos)

#define PCC_REG_PCK600_RSVD_1_Pos                                                                19U
#define PCC_REG_PCK600_RSVD_1_Msk                                                                (0x7UL << PCC_REG_PCK600_RSVD_1_Pos)

#define PCC_REG_PCK600_RESERVED_6_Pos                                                            22U
#define PCC_REG_PCK600_RESERVED_6_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_6_Pos)

#define PCC_REG_PCK600_RESERVED_5_Pos                                                            23U
#define PCC_REG_PCK600_RESERVED_5_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_5_Pos)

#define PCC_REG_PCK600_RESERVED_4_Pos                                                            24U
#define PCC_REG_PCK600_RESERVED_4_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_4_Pos)

#define PCC_REG_PCK600_RESERVED_3_Pos                                                            25U
#define PCC_REG_PCK600_RESERVED_3_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_3_Pos)

#define PCC_REG_PCK600_RESERVED_2_Pos                                                            26U
#define PCC_REG_PCK600_RESERVED_2_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_2_Pos)

#define PCC_REG_PCK600_RESERVED_1_Pos                                                            27U
#define PCC_REG_PCK600_RESERVED_1_Msk                                                            (0x1UL << PCC_REG_PCK600_RESERVED_1_Pos)

#define PCC_REG_PCK600_RSVD_Pos                                                                  28U
#define PCC_REG_PCK600_RSVD_Msk                                                                  (0x7UL << PCC_REG_PCK600_RSVD_Pos)

#define PCC_REG_PCK600_RESERVED_Pos                                                              31U
#define PCC_REG_PCK600_RESERVED_Msk                                                              (0x1UL << PCC_REG_PCK600_RESERVED_Pos)

/* 0x3FC    0x4000_03fc
    7:0     R/W     ENTRY_DELAY_DEV_LPC                             8'b0
    15:8    R/W     RSVD_2                                          8'h0
    16      R/W     RESERVED_7                                      1'b0
    17      R/W     RESERVED_6                                      1'b0
    18      R/W     LPC_CLK_FORCE                                   1'b0
    21:19   R/W     RSVD_1                                          3'b000
    22      R/W     RESERVED_5                                      1'b0
    23      R/W     RESERVED_4                                      1'b0
    24      R/W     RESERVED_3                                      1'b0
    25      R/W     RESERVED_2                                      1'b0
    26      R/W     RESERVED_1                                      1'b0
    27      R/W     RESERVED                                        1'b0
    30:28   R/W     RSVD                                            3'b000
    31      R/W     R_PON_FEN_LPC                                   1'b0
 */
typedef union _PCC_REG_LPC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENTRY_DELAY_DEV_LPC: 8;
        uint32_t RSVD_2: 8;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t LPC_CLK_FORCE: 1;
        uint32_t RSVD_1: 3;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 1;
        uint32_t RSVD: 3;
        uint32_t R_PON_FEN_LPC: 1;
    };
} PCC_REG_LPC_TYPE;

/*0x4000_03fc PCC_REG_LPC*/
#define PCC_REG_LPC_ENTRY_DELAY_DEV_LPC_Pos                                                      0U
#define PCC_REG_LPC_ENTRY_DELAY_DEV_LPC_Msk                                                      (0xFFUL << PCC_REG_LPC_ENTRY_DELAY_DEV_LPC_Pos)

#define PCC_REG_LPC_RSVD_2_Pos                                                                   8U
#define PCC_REG_LPC_RSVD_2_Msk                                                                   (0xFFUL << PCC_REG_LPC_RSVD_2_Pos)

#define PCC_REG_LPC_RESERVED_7_Pos                                                               16U
#define PCC_REG_LPC_RESERVED_7_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_7_Pos)

#define PCC_REG_LPC_RESERVED_6_Pos                                                               17U
#define PCC_REG_LPC_RESERVED_6_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_6_Pos)

#define PCC_REG_LPC_LPC_CLK_FORCE_Pos                                                            18U
#define PCC_REG_LPC_LPC_CLK_FORCE_Msk                                                            (0x1UL << PCC_REG_LPC_LPC_CLK_FORCE_Pos)

#define PCC_REG_LPC_RSVD_1_Pos                                                                   19U
#define PCC_REG_LPC_RSVD_1_Msk                                                                   (0x7UL << PCC_REG_LPC_RSVD_1_Pos)

#define PCC_REG_LPC_RESERVED_5_Pos                                                               22U
#define PCC_REG_LPC_RESERVED_5_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_5_Pos)

#define PCC_REG_LPC_RESERVED_4_Pos                                                               23U
#define PCC_REG_LPC_RESERVED_4_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_4_Pos)

#define PCC_REG_LPC_RESERVED_3_Pos                                                               24U
#define PCC_REG_LPC_RESERVED_3_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_3_Pos)

#define PCC_REG_LPC_RESERVED_2_Pos                                                               25U
#define PCC_REG_LPC_RESERVED_2_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_2_Pos)

#define PCC_REG_LPC_RESERVED_1_Pos                                                               26U
#define PCC_REG_LPC_RESERVED_1_Msk                                                               (0x1UL << PCC_REG_LPC_RESERVED_1_Pos)

#define PCC_REG_LPC_RESERVED_Pos                                                                 27U
#define PCC_REG_LPC_RESERVED_Msk                                                                 (0x1UL << PCC_REG_LPC_RESERVED_Pos)

#define PCC_REG_LPC_RSVD_Pos                                                                     28U
#define PCC_REG_LPC_RSVD_Msk                                                                     (0x7UL << PCC_REG_LPC_RSVD_Pos)

#define PCC_REG_LPC_R_PON_FEN_LPC_Pos                                                            31U
#define PCC_REG_LPC_R_PON_FEN_LPC_Msk                                                            (0x1UL << PCC_REG_LPC_R_PON_FEN_LPC_Pos)

/* 0x2C0    0x4000_02c0
    7:0     R/W     R_PMUX_GPIO_P0_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P0_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P0_2                                8'h00
    31:24   R/W     R_PMUX_GPIO_P0_3                                8'h1D
 */
typedef union _PCC_r_PMUX_GPIO_P0_0to3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P0_0: 8;
        uint32_t R_PMUX_GPIO_P0_1: 8;
        uint32_t R_PMUX_GPIO_P0_2: 8;
        uint32_t R_PMUX_GPIO_P0_3: 8;
    };
} PCC_r_PMUX_GPIO_P0_0to3_TYPE;

/*0x4000_02c0 PCC_r_PMUX_GPIO_P0_0to3*/
#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_0_Pos                                             0U
#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_0_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_0_Pos)

#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_1_Pos                                             8U
#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_1_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_1_Pos)

#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_2_Pos                                             16U
#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_2_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_2_Pos)

#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_3_Pos                                             24U
#define PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_3_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_0to3_R_PMUX_GPIO_P0_3_Pos)

/* 0x2C4    0x4000_02c4
    7:0     R/W     R_PMUX_GPIO_P0_4                                8'h00
    15:8    R/W     R_PMUX_GPIO_P0_5                                8'h00
    23:16   R/W     R_PMUX_GPIO_P0_6                                8'h00
    31:24   R/W     R_PMUX_GPIO_P0_7                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P0_4to7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P0_4: 8;
        uint32_t R_PMUX_GPIO_P0_5: 8;
        uint32_t R_PMUX_GPIO_P0_6: 8;
        uint32_t R_PMUX_GPIO_P0_7: 8;
    };
} PCC_r_PMUX_GPIO_P0_4to7_TYPE;

/*0x4000_02c4 PCC_r_PMUX_GPIO_P0_4to7*/
#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_4_Pos                                             0U
#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_4_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_4_Pos)

#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_5_Pos                                             8U
#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_5_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_5_Pos)

#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_6_Pos                                             16U
#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_6_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_6_Pos)

#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_7_Pos                                             24U
#define PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_7_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P0_4to7_R_PMUX_GPIO_P0_7_Pos)

/* 0x2C8    0x4000_02c8
    7:0     R/W     R_PMUX_GPIO_P1_0                                8'h3C
    15:8    R/W     R_PMUX_GPIO_P1_1                                8'h3B
    23:16   R/W     R_PMUX_GPIO_P1_6                                8'h00
    31:24   R/W     R_PMUX_GPIO_P1_7                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P1_0to7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P1_0: 8;
        uint32_t R_PMUX_GPIO_P1_1: 8;
        uint32_t R_PMUX_GPIO_P1_6: 8;
        uint32_t R_PMUX_GPIO_P1_7: 8;
    };
} PCC_r_PMUX_GPIO_P1_0to7_TYPE;

/*0x4000_02c8 PCC_r_PMUX_GPIO_P1_0to7*/
#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_0_Pos                                             0U
#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_0_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_0_Pos)

#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_1_Pos                                             8U
#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_1_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_1_Pos)

#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_6_Pos                                             16U
#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_6_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_6_Pos)

#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_7_Pos                                             24U
#define PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_7_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P1_0to7_R_PMUX_GPIO_P1_7_Pos)

/* 0x2CC    0x4000_02cc
    7:0     R/W     R_PMUX_GPIO_P2_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P2_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P2_2                                8'h00
    31:24   R/W     R_PMUX_GPIO_P2_3                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P2_0to3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P2_0: 8;
        uint32_t R_PMUX_GPIO_P2_1: 8;
        uint32_t R_PMUX_GPIO_P2_2: 8;
        uint32_t R_PMUX_GPIO_P2_3: 8;
    };
} PCC_r_PMUX_GPIO_P2_0to3_TYPE;

/*0x4000_02cc PCC_r_PMUX_GPIO_P2_0to3*/
#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_0_Pos                                             0U
#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_0_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_0_Pos)

#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_1_Pos                                             8U
#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_1_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_1_Pos)

#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_2_Pos                                             16U
#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_2_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_2_Pos)

#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_3_Pos                                             24U
#define PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_3_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_0to3_R_PMUX_GPIO_P2_3_Pos)

/* 0x2D0    0x4000_02d0
    7:0     R/W     R_PMUX_GPIO_P2_4                                8'h00
    15:8    R/W     R_PMUX_GPIO_P2_5                                8'h00
    23:16   R/W     R_PMUX_GPIO_P2_6                                8'h00
    31:24   R/W     R_PMUX_GPIO_P2_7                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P2_4to7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P2_4: 8;
        uint32_t R_PMUX_GPIO_P2_5: 8;
        uint32_t R_PMUX_GPIO_P2_6: 8;
        uint32_t R_PMUX_GPIO_P2_7: 8;
    };
} PCC_r_PMUX_GPIO_P2_4to7_TYPE;

/*0x4000_02d0 PCC_r_PMUX_GPIO_P2_4to7*/
#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_4_Pos                                             0U
#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_4_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_4_Pos)

#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_5_Pos                                             8U
#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_5_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_5_Pos)

#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_6_Pos                                             16U
#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_6_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_6_Pos)

#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_7_Pos                                             24U
#define PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_7_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P2_4to7_R_PMUX_GPIO_P2_7_Pos)

/* 0x2D4    0x4000_02d4
    7:0     R/W     R_PMUX_GPIO_P3_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P3_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P3_2                                8'h00
    31:24   R/W     R_PMUX_GPIO_P3_3                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P3_0to3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P3_0: 8;
        uint32_t R_PMUX_GPIO_P3_1: 8;
        uint32_t R_PMUX_GPIO_P3_2: 8;
        uint32_t R_PMUX_GPIO_P3_3: 8;
    };
} PCC_r_PMUX_GPIO_P3_0to3_TYPE;

/*0x4000_02d4 PCC_r_PMUX_GPIO_P3_0to3*/
#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_0_Pos                                             0U
#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_0_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_0_Pos)

#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_1_Pos                                             8U
#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_1_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_1_Pos)

#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_2_Pos                                             16U
#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_2_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_2_Pos)

#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_3_Pos                                             24U
#define PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_3_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_0to3_R_PMUX_GPIO_P3_3_Pos)

/* 0x2D8    0x4000_02d8
    7:0     R/W     R_PMUX_GPIO_P3_4                                8'h23
    15:8    R/W     R_PMUX_GPIO_P3_5                                8'h24
    23:16   R/W     R_PMUX_GPIO_P3_6                                8'h00
    31:24   R/W     DUMMY                                           8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P3_4to6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P3_4: 8;
        uint32_t R_PMUX_GPIO_P3_5: 8;
        uint32_t R_PMUX_GPIO_P3_6: 8;
        uint32_t DUMMY: 8;
    };
} PCC_r_PMUX_GPIO_P3_4to6_TYPE;

/*0x4000_02d8 PCC_r_PMUX_GPIO_P3_4to6*/
#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_4_Pos                                             0U
#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_4_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_4_Pos)

#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_5_Pos                                             8U
#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_5_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_5_Pos)

#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_6_Pos                                             16U
#define PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_6_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P3_4to6_R_PMUX_GPIO_P3_6_Pos)

#define PCC_r_PMUX_GPIO_P3_4to6_DUMMY_Pos                                                        24U
#define PCC_r_PMUX_GPIO_P3_4to6_DUMMY_Msk                                                        (0xFFUL << PCC_r_PMUX_GPIO_P3_4to6_DUMMY_Pos)

/* 0x2DC    0x4000_02dc
    7:0     R/W     R_PMUX_GPIO_P4_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P4_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P4_2                                8'h00
    31:24   R/W     R_PMUX_GPIO_P4_3                                8'h00
 */
typedef union _PCC_r_PMUX_GPIO_P4_0to3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P4_0: 8;
        uint32_t R_PMUX_GPIO_P4_1: 8;
        uint32_t R_PMUX_GPIO_P4_2: 8;
        uint32_t R_PMUX_GPIO_P4_3: 8;
    };
} PCC_r_PMUX_GPIO_P4_0to3_TYPE;

/*0x4000_02dc PCC_r_PMUX_GPIO_P4_0to3*/
#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_0_Pos                                             0U
#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_0_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_0_Pos)

#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_1_Pos                                             8U
#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_1_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_1_Pos)

#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_2_Pos                                             16U
#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_2_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_2_Pos)

#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_3_Pos                                             24U
#define PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_3_Msk                                             (0xFFUL << PCC_r_PMUX_GPIO_P4_0to3_R_PMUX_GPIO_P4_3_Pos)

/* 0x2E0    0x4000_02e0
    7:0     R/W     R_PMUX_GPIO_MICBIAS_0                           8'h00
    15:8    R/W     R_PMUX_GPIO_P5_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P5_2                                8'h00
    31:24   R/W     DUMMY37                                         8'h00
 */
typedef union _PCC_r_PMUX_GPIO_H_0to2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_MICBIAS_0: 8;
        uint32_t R_PMUX_GPIO_P5_1: 8;
        uint32_t R_PMUX_GPIO_P5_2: 8;
        uint32_t DUMMY37: 8;
    };
} PCC_r_PMUX_GPIO_H_0to2_TYPE;

/*0x4000_02e0 PCC_r_PMUX_GPIO_H_0to2*/
#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_MICBIAS_0_Pos                                         0U
#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_MICBIAS_0_Msk                                         (0xFFUL << PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_MICBIAS_0_Pos)

#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_1_Pos                                              8U
#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_1_Msk                                              (0xFFUL << PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_1_Pos)

#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_2_Pos                                              16U
#define PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_2_Msk                                              (0xFFUL << PCC_r_PMUX_GPIO_H_0to2_R_PMUX_GPIO_P5_2_Pos)

#define PCC_r_PMUX_GPIO_H_0to2_DUMMY37_Pos                                                       24U
#define PCC_r_PMUX_GPIO_H_0to2_DUMMY37_Msk                                                       (0xFFUL << PCC_r_PMUX_GPIO_H_0to2_DUMMY37_Pos)

/* 0x2E4    0x4000_02e4
    7:0     R/W     R_PMUX_GPIO_P6_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P6_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_P6_2                                8'h00
    31:24   R/W     R_PMUX_GPIO_P6_3                                8'h00
 */
typedef union _PCC_REG_PMUX_GPIO_6_0to3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P6_0: 8;
        uint32_t R_PMUX_GPIO_P6_1: 8;
        uint32_t R_PMUX_GPIO_P6_2: 8;
        uint32_t R_PMUX_GPIO_P6_3: 8;
    };
} PCC_REG_PMUX_GPIO_6_0to3_TYPE;

/*0x4000_02e4 PCC_REG_PMUX_GPIO_6_0to3*/
#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_0_Pos                                            0U
#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_0_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_0_Pos)

#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_1_Pos                                            8U
#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_1_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_1_Pos)

#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_2_Pos                                            16U
#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_2_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_2_Pos)

#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_3_Pos                                            24U
#define PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_3_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_0to3_R_PMUX_GPIO_P6_3_Pos)

/* 0x2E8    0x4000_02e8
    7:0     R/W     R_PMUX_GPIO_P6_4                                8'h00
    15:8    R/W     R_PMUX_GPIO_P6_5                                8'h00
    23:16   R/W     R_PMUX_GPIO_P6_6                                8'h00
    31:24   R/W     R_PMUX_GPIO_P6_7                                8'h00
 */
typedef union _PCC_REG_PMUX_GPIO_6_4to7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P6_4: 8;
        uint32_t R_PMUX_GPIO_P6_5: 8;
        uint32_t R_PMUX_GPIO_P6_6: 8;
        uint32_t R_PMUX_GPIO_P6_7: 8;
    };
} PCC_REG_PMUX_GPIO_6_4to7_TYPE;

/*0x4000_02e8 PCC_REG_PMUX_GPIO_6_4to7*/
#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_4_Pos                                            0U
#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_4_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_4_Pos)

#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_5_Pos                                            8U
#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_5_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_5_Pos)

#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_6_Pos                                            16U
#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_6_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_6_Pos)

#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_7_Pos                                            24U
#define PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_7_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_6_4to7_R_PMUX_GPIO_P6_7_Pos)

/* 0x2EC    0x4000_02ec
    7:0     R/W     R_PMUX_GPIO_P7_0                                8'h00
    15:8    R/W     R_PMUX_GPIO_P7_1                                8'h00
    23:16   R/W     R_PMUX_GPIO_SPIC_CSN                            8'h00
    31:24   R/W     R_PMUX_GPIO_SPIC_SCK                            8'h00
 */
typedef union _PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_P7_0: 8;
        uint32_t R_PMUX_GPIO_P7_1: 8;
        uint32_t R_PMUX_GPIO_SPIC_CSN: 8;
        uint32_t R_PMUX_GPIO_SPIC_SCK: 8;
    };
} PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_TYPE;

/*0x4000_02ec PCC_REG_PMUX_GPIO_7_0to1_SPIC_1*/
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_0_Pos                                     0U
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_0_Msk                                     (0xFFUL << PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_0_Pos)

#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_1_Pos                                     8U
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_1_Msk                                     (0xFFUL << PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_P7_1_Pos)

#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_CSN_Pos                                 16U
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_CSN_Msk                                 (0xFFUL << PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_CSN_Pos)

#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_SCK_Pos                                 24U
#define PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_SCK_Msk                                 (0xFFUL << PCC_REG_PMUX_GPIO_7_0to1_SPIC_1_R_PMUX_GPIO_SPIC_SCK_Pos)

/* 0x2F0    0x4000_02f0
    7:0     R/W     R_PMUX_GPIO_SPIC_SI                             8'h00
    15:8    R/W     R_PMUX_GPIO_SPIC_SO                             8'h00
    23:16   R/W     R_PMUX_GPIO_P1_4                                8'h00
    31:24   R/W     R_PMUX_GPIO_P1_3                                8'h00
 */
typedef union _PCC_REG_PMUX_GPIO_SPIC_2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_GPIO_SPIC_SI: 8;
        uint32_t R_PMUX_GPIO_SPIC_SO: 8;
        uint32_t R_PMUX_GPIO_P1_4: 8;
        uint32_t R_PMUX_GPIO_P1_3: 8;
    };
} PCC_REG_PMUX_GPIO_SPIC_2_TYPE;

/*0x4000_02f0 PCC_REG_PMUX_GPIO_SPIC_2*/
#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SI_Pos                                         0U
#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SI_Msk                                         (0xFFUL << PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SI_Pos)

#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SO_Pos                                         8U
#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SO_Msk                                         (0xFFUL << PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_SPIC_SO_Pos)

#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_4_Pos                                            16U
#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_4_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_4_Pos)

#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_3_Pos                                            24U
#define PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_3_Msk                                            (0xFFUL << PCC_REG_PMUX_GPIO_SPIC_2_R_PMUX_GPIO_P1_3_Pos)

/* 0x2F4    0x4000_02f4
    3:0     R/W     R_PMUX_TEST_MODE                                4'h1
    6:4     R/W     R_DW_SPIM_EN                                    3'h0
    7       R/W     R_PMUX_TEST_MODE_EN                             0
    8       R/W     R_SAR_TM_DAT_SEL                                0
    9       R/W     DUMMY62                                         0
    13:10   R/W     R_PMUX_1_WIRE_UART_EN                           4'h0
    14      R/W     R_SAR_TM_CLK_SEL                                1'b0
    15      R/W     R_SAR_TM_CH_SEL                                 1'b0
    17:16   R/W     R_OSC80M_TEST_MODE_CLK_DIV                      2'h0
    19:18   R/W     R_PLL_TEST_MODE_CLK_DIV                         2'h0
    20      R/W     R_PMUX_DBG_SPIC0                                0
    21      R/W     DUMMY60                                         0
    22      R/W     DUMMY59                                         0
    23      R/W     R_PMUX_DIG_SMUX_EN                              0
    24      R/W     R_PON_PMUX_SPIM0_EN                             0
    25      R/W     R_PMUX_SPIM_EN_OPT                              0
    26      R/W     R_PMUX_FLASH_EXTC_EN                            0
    27      R/W     R_PMUX_FLASH_EN                                 0
    29:28   R/W     DUMMY58                                         2'h0
    30      R/W     DUMMY57                                         0
    31      R/W     DUMMY56                                         0
 */
typedef union _PCC_r_PMUX_TEST_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_TEST_MODE: 4;
        uint32_t R_DW_SPIM_EN: 3;
        uint32_t R_PMUX_TEST_MODE_EN: 1;
        uint32_t R_SAR_TM_DAT_SEL: 1;
        uint32_t DUMMY62: 1;
        uint32_t R_PMUX_1_WIRE_UART_EN: 4;
        uint32_t R_SAR_TM_CLK_SEL: 1;
        uint32_t R_SAR_TM_CH_SEL: 1;
        uint32_t R_OSC80M_TEST_MODE_CLK_DIV: 2;
        uint32_t R_PLL_TEST_MODE_CLK_DIV: 2;
        uint32_t R_PMUX_DBG_SPIC0: 1;
        uint32_t DUMMY60: 1;
        uint32_t DUMMY59: 1;
        uint32_t R_PMUX_DIG_SMUX_EN: 1;
        uint32_t R_PON_PMUX_SPIM0_EN: 1;
        uint32_t R_PMUX_SPIM_EN_OPT: 1;
        uint32_t R_PMUX_FLASH_EXTC_EN: 1;
        uint32_t R_PMUX_FLASH_EN: 1;
        uint32_t DUMMY58: 2;
        uint32_t DUMMY57: 1;
        uint32_t DUMMY56: 1;
    };
} PCC_r_PMUX_TEST_MODE_TYPE;

/*0x4000_02f4 PCC_r_PMUX_TEST_MODE*/
#define PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_Pos                                                0U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_Msk                                                (0xFUL << PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_Pos)

#define PCC_r_PMUX_TEST_MODE_R_DW_SPIM_EN_Pos                                                    4U
#define PCC_r_PMUX_TEST_MODE_R_DW_SPIM_EN_Msk                                                    (0x7UL << PCC_r_PMUX_TEST_MODE_R_DW_SPIM_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_EN_Pos                                             7U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_EN_Msk                                             (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_TEST_MODE_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_DAT_SEL_Pos                                                8U
#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_DAT_SEL_Msk                                                (0x1UL << PCC_r_PMUX_TEST_MODE_R_SAR_TM_DAT_SEL_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY62_Pos                                                         9U
#define PCC_r_PMUX_TEST_MODE_DUMMY62_Msk                                                         (0x1UL << PCC_r_PMUX_TEST_MODE_DUMMY62_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_1_WIRE_UART_EN_Pos                                           10U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_1_WIRE_UART_EN_Msk                                           (0xFUL << PCC_r_PMUX_TEST_MODE_R_PMUX_1_WIRE_UART_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_CLK_SEL_Pos                                                14U
#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_CLK_SEL_Msk                                                (0x1UL << PCC_r_PMUX_TEST_MODE_R_SAR_TM_CLK_SEL_Pos)

#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_CH_SEL_Pos                                                 15U
#define PCC_r_PMUX_TEST_MODE_R_SAR_TM_CH_SEL_Msk                                                 (0x1UL << PCC_r_PMUX_TEST_MODE_R_SAR_TM_CH_SEL_Pos)

#define PCC_r_PMUX_TEST_MODE_R_OSC80M_TEST_MODE_CLK_DIV_Pos                                      16U
#define PCC_r_PMUX_TEST_MODE_R_OSC80M_TEST_MODE_CLK_DIV_Msk                                      (0x3UL << PCC_r_PMUX_TEST_MODE_R_OSC80M_TEST_MODE_CLK_DIV_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PLL_TEST_MODE_CLK_DIV_Pos                                         18U
#define PCC_r_PMUX_TEST_MODE_R_PLL_TEST_MODE_CLK_DIV_Msk                                         (0x3UL << PCC_r_PMUX_TEST_MODE_R_PLL_TEST_MODE_CLK_DIV_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_DBG_SPIC0_Pos                                                20U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_DBG_SPIC0_Msk                                                (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_DBG_SPIC0_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY60_Pos                                                         21U
#define PCC_r_PMUX_TEST_MODE_DUMMY60_Msk                                                         (0x1UL << PCC_r_PMUX_TEST_MODE_DUMMY60_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY59_Pos                                                         22U
#define PCC_r_PMUX_TEST_MODE_DUMMY59_Msk                                                         (0x1UL << PCC_r_PMUX_TEST_MODE_DUMMY59_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_DIG_SMUX_EN_Pos                                              23U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_DIG_SMUX_EN_Msk                                              (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_DIG_SMUX_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PON_PMUX_SPIM0_EN_Pos                                             24U
#define PCC_r_PMUX_TEST_MODE_R_PON_PMUX_SPIM0_EN_Msk                                             (0x1UL << PCC_r_PMUX_TEST_MODE_R_PON_PMUX_SPIM0_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_SPIM_EN_OPT_Pos                                              25U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_SPIM_EN_OPT_Msk                                              (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_SPIM_EN_OPT_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EXTC_EN_Pos                                            26U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EXTC_EN_Msk                                            (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EXTC_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EN_Pos                                                 27U
#define PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EN_Msk                                                 (0x1UL << PCC_r_PMUX_TEST_MODE_R_PMUX_FLASH_EN_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY58_Pos                                                         28U
#define PCC_r_PMUX_TEST_MODE_DUMMY58_Msk                                                         (0x3UL << PCC_r_PMUX_TEST_MODE_DUMMY58_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY57_Pos                                                         30U
#define PCC_r_PMUX_TEST_MODE_DUMMY57_Msk                                                         (0x1UL << PCC_r_PMUX_TEST_MODE_DUMMY57_Pos)

#define PCC_r_PMUX_TEST_MODE_DUMMY56_Pos                                                         31U
#define PCC_r_PMUX_TEST_MODE_DUMMY56_Msk                                                         (0x1UL << PCC_r_PMUX_TEST_MODE_DUMMY56_Pos)

/* 0x2F8    0x4000_02f8
    0       R/W     DET_ENABLE                                      1'b0
    1       R/W     VBUS_DET                                        1'b0
    2       R/W     SKIP_SEC_DET                                    1'b0
    3       R/W     DUMMY68                                         1'b0
    7:4     R/W     DUMMY67                                         4'h0
    8       R       SDP_0P5A                                        1'h0
    9       R       DCP_CDP_1P5A                                    1'h0
    10      R       CDP_DET                                         1'h0
    11      R       DCP_DET                                         1'h0
    12      R       OTHERS_0P5A                                     1'h0
    13      R       RSVD_4                                          1'h0
    14      R       RSVD_3                                          1'h0
    15      R       RSVD_2                                          1'h0
    16      R       DET_IS_DONE                                     1'h0
    17      R       RSVD_1                                          1'h0
    18      R       RSVD                                            1'h0
    28:19   R/W     DUMMY66                                         10'h0
    29      R/W     DCP_OPTION                                      1'h1
    30      R/W     DUMMY65                                         1'h1
    31      R/W     BYPASS_DCD_DBNC                                 1'h0
 */
typedef union _PCC_REG_BC12_CTRL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DET_ENABLE: 1;
        uint32_t VBUS_DET: 1;
        uint32_t SKIP_SEC_DET: 1;
        uint32_t DUMMY68: 1;
        uint32_t DUMMY67: 4;
        uint32_t SDP_0P5A: 1;
        uint32_t DCP_CDP_1P5A: 1;
        uint32_t CDP_DET: 1;
        uint32_t DCP_DET: 1;
        uint32_t OTHERS_0P5A: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t DET_IS_DONE: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
        uint32_t DUMMY66: 10;
        uint32_t DCP_OPTION: 1;
        uint32_t DUMMY65: 1;
        uint32_t BYPASS_DCD_DBNC: 1;
    };
} PCC_REG_BC12_CTRL1_TYPE;

/*0x4000_02f8 PCC_REG_BC12_CTRL1*/
#define PCC_REG_BC12_CTRL1_DET_ENABLE_Pos                                                        0U
#define PCC_REG_BC12_CTRL1_DET_ENABLE_Msk                                                        (0x1UL << PCC_REG_BC12_CTRL1_DET_ENABLE_Pos)

#define PCC_REG_BC12_CTRL1_VBUS_DET_Pos                                                          1U
#define PCC_REG_BC12_CTRL1_VBUS_DET_Msk                                                          (0x1UL << PCC_REG_BC12_CTRL1_VBUS_DET_Pos)

#define PCC_REG_BC12_CTRL1_SKIP_SEC_DET_Pos                                                      2U
#define PCC_REG_BC12_CTRL1_SKIP_SEC_DET_Msk                                                      (0x1UL << PCC_REG_BC12_CTRL1_SKIP_SEC_DET_Pos)

#define PCC_REG_BC12_CTRL1_DUMMY68_Pos                                                           3U
#define PCC_REG_BC12_CTRL1_DUMMY68_Msk                                                           (0x1UL << PCC_REG_BC12_CTRL1_DUMMY68_Pos)

#define PCC_REG_BC12_CTRL1_DUMMY67_Pos                                                           4U
#define PCC_REG_BC12_CTRL1_DUMMY67_Msk                                                           (0xFUL << PCC_REG_BC12_CTRL1_DUMMY67_Pos)

#define PCC_REG_BC12_CTRL1_SDP_0P5A_Pos                                                          8U
#define PCC_REG_BC12_CTRL1_SDP_0P5A_Msk                                                          (0x1UL << PCC_REG_BC12_CTRL1_SDP_0P5A_Pos)

#define PCC_REG_BC12_CTRL1_DCP_CDP_1P5A_Pos                                                      9U
#define PCC_REG_BC12_CTRL1_DCP_CDP_1P5A_Msk                                                      (0x1UL << PCC_REG_BC12_CTRL1_DCP_CDP_1P5A_Pos)

#define PCC_REG_BC12_CTRL1_CDP_DET_Pos                                                           10U
#define PCC_REG_BC12_CTRL1_CDP_DET_Msk                                                           (0x1UL << PCC_REG_BC12_CTRL1_CDP_DET_Pos)

#define PCC_REG_BC12_CTRL1_DCP_DET_Pos                                                           11U
#define PCC_REG_BC12_CTRL1_DCP_DET_Msk                                                           (0x1UL << PCC_REG_BC12_CTRL1_DCP_DET_Pos)

#define PCC_REG_BC12_CTRL1_OTHERS_0P5A_Pos                                                       12U
#define PCC_REG_BC12_CTRL1_OTHERS_0P5A_Msk                                                       (0x1UL << PCC_REG_BC12_CTRL1_OTHERS_0P5A_Pos)

#define PCC_REG_BC12_CTRL1_RSVD_4_Pos                                                            13U
#define PCC_REG_BC12_CTRL1_RSVD_4_Msk                                                            (0x1UL << PCC_REG_BC12_CTRL1_RSVD_4_Pos)

#define PCC_REG_BC12_CTRL1_RSVD_3_Pos                                                            14U
#define PCC_REG_BC12_CTRL1_RSVD_3_Msk                                                            (0x1UL << PCC_REG_BC12_CTRL1_RSVD_3_Pos)

#define PCC_REG_BC12_CTRL1_RSVD_2_Pos                                                            15U
#define PCC_REG_BC12_CTRL1_RSVD_2_Msk                                                            (0x1UL << PCC_REG_BC12_CTRL1_RSVD_2_Pos)

#define PCC_REG_BC12_CTRL1_DET_IS_DONE_Pos                                                       16U
#define PCC_REG_BC12_CTRL1_DET_IS_DONE_Msk                                                       (0x1UL << PCC_REG_BC12_CTRL1_DET_IS_DONE_Pos)

#define PCC_REG_BC12_CTRL1_RSVD_1_Pos                                                            17U
#define PCC_REG_BC12_CTRL1_RSVD_1_Msk                                                            (0x1UL << PCC_REG_BC12_CTRL1_RSVD_1_Pos)

#define PCC_REG_BC12_CTRL1_RSVD_Pos                                                              18U
#define PCC_REG_BC12_CTRL1_RSVD_Msk                                                              (0x1UL << PCC_REG_BC12_CTRL1_RSVD_Pos)

#define PCC_REG_BC12_CTRL1_DUMMY66_Pos                                                           19U
#define PCC_REG_BC12_CTRL1_DUMMY66_Msk                                                           (0x3FFUL << PCC_REG_BC12_CTRL1_DUMMY66_Pos)

#define PCC_REG_BC12_CTRL1_DCP_OPTION_Pos                                                        29U
#define PCC_REG_BC12_CTRL1_DCP_OPTION_Msk                                                        (0x1UL << PCC_REG_BC12_CTRL1_DCP_OPTION_Pos)

#define PCC_REG_BC12_CTRL1_DUMMY65_Pos                                                           30U
#define PCC_REG_BC12_CTRL1_DUMMY65_Msk                                                           (0x1UL << PCC_REG_BC12_CTRL1_DUMMY65_Pos)

#define PCC_REG_BC12_CTRL1_BYPASS_DCD_DBNC_Pos                                                   31U
#define PCC_REG_BC12_CTRL1_BYPASS_DCD_DBNC_Msk                                                   (0x1UL << PCC_REG_BC12_CTRL1_BYPASS_DCD_DBNC_Pos)

/* 0x2FC    0x4000_02fc
    7:0     R/W     FW_WRITE_BUS                                    8'h0
    8       R/W     FW_CTRL_MODE                                    1'h0
    15:9    R/W     DUMMY70                                         7'h0
    19:16   R       VDP_COMP_L                                      4'h0
    20      R       VDP_LT_VLOW_L                                   1'h0
    24:21   R       VDM_COMP_L                                      4'h0
    25      R       VDM_LT_VLOW_L                                   1'h0
    31:26   R/W     DUMMY69                                         6'h0
 */
typedef union _PCC_REG_BC12_CTRL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_WRITE_BUS: 8;
        uint32_t FW_CTRL_MODE: 1;
        uint32_t DUMMY70: 7;
        uint32_t VDP_COMP_L: 4;
        uint32_t VDP_LT_VLOW_L: 1;
        uint32_t VDM_COMP_L: 4;
        uint32_t VDM_LT_VLOW_L: 1;
        uint32_t DUMMY69: 6;
    };
} PCC_REG_BC12_CTRL2_TYPE;

/*0x4000_02fc PCC_REG_BC12_CTRL2*/
#define PCC_REG_BC12_CTRL2_FW_WRITE_BUS_Pos                                                      0U
#define PCC_REG_BC12_CTRL2_FW_WRITE_BUS_Msk                                                      (0xFFUL << PCC_REG_BC12_CTRL2_FW_WRITE_BUS_Pos)

#define PCC_REG_BC12_CTRL2_FW_CTRL_MODE_Pos                                                      8U
#define PCC_REG_BC12_CTRL2_FW_CTRL_MODE_Msk                                                      (0x1UL << PCC_REG_BC12_CTRL2_FW_CTRL_MODE_Pos)

#define PCC_REG_BC12_CTRL2_DUMMY70_Pos                                                           9U
#define PCC_REG_BC12_CTRL2_DUMMY70_Msk                                                           (0x7FUL << PCC_REG_BC12_CTRL2_DUMMY70_Pos)

#define PCC_REG_BC12_CTRL2_VDP_COMP_L_Pos                                                        16U
#define PCC_REG_BC12_CTRL2_VDP_COMP_L_Msk                                                        (0xFUL << PCC_REG_BC12_CTRL2_VDP_COMP_L_Pos)

#define PCC_REG_BC12_CTRL2_VDP_LT_VLOW_L_Pos                                                     20U
#define PCC_REG_BC12_CTRL2_VDP_LT_VLOW_L_Msk                                                     (0x1UL << PCC_REG_BC12_CTRL2_VDP_LT_VLOW_L_Pos)

#define PCC_REG_BC12_CTRL2_VDM_COMP_L_Pos                                                        21U
#define PCC_REG_BC12_CTRL2_VDM_COMP_L_Msk                                                        (0xFUL << PCC_REG_BC12_CTRL2_VDM_COMP_L_Pos)

#define PCC_REG_BC12_CTRL2_VDM_LT_VLOW_L_Pos                                                     25U
#define PCC_REG_BC12_CTRL2_VDM_LT_VLOW_L_Msk                                                     (0x1UL << PCC_REG_BC12_CTRL2_VDM_LT_VLOW_L_Pos)

#define PCC_REG_BC12_CTRL2_DUMMY69_Pos                                                           26U
#define PCC_REG_BC12_CTRL2_DUMMY69_Msk                                                           (0x3FUL << PCC_REG_BC12_CTRL2_DUMMY69_Pos)

/* 0x300    0x4000_0300
    15:0    R/W     DCD_A_MIN_TIME                                  16'h200
    31:16   R/W     DCD_B_MIN_TIME                                  16'h3E80
 */
typedef union _PCC_REG_BC12_CTRL3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DCD_A_MIN_TIME: 16;
        uint32_t DCD_B_MIN_TIME: 16;
    };
} PCC_REG_BC12_CTRL3_TYPE;

/*0x4000_0300 PCC_REG_BC12_CTRL3*/
#define PCC_REG_BC12_CTRL3_DCD_A_MIN_TIME_Pos                                                    0U
#define PCC_REG_BC12_CTRL3_DCD_A_MIN_TIME_Msk                                                    (0xFFFFUL << PCC_REG_BC12_CTRL3_DCD_A_MIN_TIME_Pos)

#define PCC_REG_BC12_CTRL3_DCD_B_MIN_TIME_Pos                                                    16U
#define PCC_REG_BC12_CTRL3_DCD_B_MIN_TIME_Msk                                                    (0xFFFFUL << PCC_REG_BC12_CTRL3_DCD_B_MIN_TIME_Pos)

/* 0x304    0x4000_0304
    15:0    R/W     PRI_DET_MIN_TIME                                16'h500
    31:16   R/W     NOTE_DET_MIN_TIME                               16'h140
 */
typedef union _PCC_REG_BC12_CTRL4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PRI_DET_MIN_TIME: 16;
        uint32_t NOTE_DET_MIN_TIME: 16;
    };
} PCC_REG_BC12_CTRL4_TYPE;

/*0x4000_0304 PCC_REG_BC12_CTRL4*/
#define PCC_REG_BC12_CTRL4_PRI_DET_MIN_TIME_Pos                                                  0U
#define PCC_REG_BC12_CTRL4_PRI_DET_MIN_TIME_Msk                                                  (0xFFFFUL << PCC_REG_BC12_CTRL4_PRI_DET_MIN_TIME_Pos)

#define PCC_REG_BC12_CTRL4_NOTE_DET_MIN_TIME_Pos                                                 16U
#define PCC_REG_BC12_CTRL4_NOTE_DET_MIN_TIME_Msk                                                 (0xFFFFUL << PCC_REG_BC12_CTRL4_NOTE_DET_MIN_TIME_Pos)

/* 0x308    0x4000_0308
    15:0    R/W     WAIT_A_MIN_TIME                                 16'h280
    31:16   R/W     SECOND_DET_MIN_TIME                             16'h540
 */
typedef union _PCC_REG_BC12_CTRL5_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WAIT_A_MIN_TIME: 16;
        uint32_t SECOND_DET_MIN_TIME: 16;
    };
} PCC_REG_BC12_CTRL5_TYPE;

/*0x4000_0308 PCC_REG_BC12_CTRL5*/
#define PCC_REG_BC12_CTRL5_WAIT_A_MIN_TIME_Pos                                                   0U
#define PCC_REG_BC12_CTRL5_WAIT_A_MIN_TIME_Msk                                                   (0xFFFFUL << PCC_REG_BC12_CTRL5_WAIT_A_MIN_TIME_Pos)

#define PCC_REG_BC12_CTRL5_SECOND_DET_MIN_TIME_Pos                                               16U
#define PCC_REG_BC12_CTRL5_SECOND_DET_MIN_TIME_Msk                                               (0xFFFFUL << PCC_REG_BC12_CTRL5_SECOND_DET_MIN_TIME_Pos)

/* 0x30C    0x4000_030c
    15:0    R/W     SA_DET_MIN_TIME                                 16'h140
    31:16   R/W     DUMMY71                                         16'h0
 */
typedef union _PCC_REG_BC12_CTRL6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t SA_DET_MIN_TIME: 16;
        uint32_t DUMMY71: 16;
    };
} PCC_REG_BC12_CTRL6_TYPE;

/*0x4000_030c PCC_REG_BC12_CTRL6*/
#define PCC_REG_BC12_CTRL6_SA_DET_MIN_TIME_Pos                                                   0U
#define PCC_REG_BC12_CTRL6_SA_DET_MIN_TIME_Msk                                                   (0xFFFFUL << PCC_REG_BC12_CTRL6_SA_DET_MIN_TIME_Pos)

#define PCC_REG_BC12_CTRL6_DUMMY71_Pos                                                           16U
#define PCC_REG_BC12_CTRL6_DUMMY71_Msk                                                           (0xFFFFUL << PCC_REG_BC12_CTRL6_DUMMY71_Pos)

/* 0x310    0x4000_0310
    3:0     R/W     R_PMUX_DBG_MODE_SEL_G0                          4'h0
    7:4     R/W     R_PMUX_DBG_MODE_SEL_G1                          4'h0
    11:8    R/W     R_PMUX_DBG_MODE_SEL_G2                          4'h0
    15:12   R/W     R_PMUX_DBG_MODE_SEL_G3                          4'h0
    17:16   R/W     R_DBG_MUX_SEC_SEL_G0                            2'h0
    19:18   R/W     R_DBG_MUX_SEC_SEL_G1                            2'h0
    21:20   R/W     R_DBG_MUX_SEC_SEL_G2                            2'h0
    23:22   R/W     R_DBG_MUX_SEC_SEL_G3                            2'h0
    31:24   R       RSVD                                            8'h00
 */
typedef union _PCC_REG_DBG_MUX_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_DBG_MODE_SEL_G0: 4;
        uint32_t R_PMUX_DBG_MODE_SEL_G1: 4;
        uint32_t R_PMUX_DBG_MODE_SEL_G2: 4;
        uint32_t R_PMUX_DBG_MODE_SEL_G3: 4;
        uint32_t R_DBG_MUX_SEC_SEL_G0: 2;
        uint32_t R_DBG_MUX_SEC_SEL_G1: 2;
        uint32_t R_DBG_MUX_SEC_SEL_G2: 2;
        uint32_t R_DBG_MUX_SEC_SEL_G3: 2;
        uint32_t RSVD: 8;
    };
} PCC_REG_DBG_MUX_CTRL_TYPE;

/*0x4000_0310 PCC_REG_DBG_MUX_CTRL*/
#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G0_Pos                                          0U
#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G0_Msk                                          (0xFUL << PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G0_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G1_Pos                                          4U
#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G1_Msk                                          (0xFUL << PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G1_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G2_Pos                                          8U
#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G2_Msk                                          (0xFUL << PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G2_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G3_Pos                                          12U
#define PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G3_Msk                                          (0xFUL << PCC_REG_DBG_MUX_CTRL_R_PMUX_DBG_MODE_SEL_G3_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G0_Pos                                            16U
#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G0_Msk                                            (0x3UL << PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G0_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G1_Pos                                            18U
#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G1_Msk                                            (0x3UL << PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G1_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G2_Pos                                            20U
#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G2_Msk                                            (0x3UL << PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G2_Pos)

#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G3_Pos                                            22U
#define PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G3_Msk                                            (0x3UL << PCC_REG_DBG_MUX_CTRL_R_DBG_MUX_SEC_SEL_G3_Pos)

#define PCC_REG_DBG_MUX_CTRL_RSVD_Pos                                                            24U
#define PCC_REG_DBG_MUX_CTRL_RSVD_Msk                                                            (0xFFUL << PCC_REG_DBG_MUX_CTRL_RSVD_Pos)

/* 0x314    0x4000_0314
    31:0    R       RSVD                                            32'hEAEAEAEA
 */
typedef union _PCC_REG_RSVD_2D8_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PCC_REG_RSVD_2D8_TYPE;

/*0x4000_0314 PCC_REG_RSVD_2D8*/
#define PCC_REG_RSVD_2D8_RSVD_Pos                                                                0U
#define PCC_REG_RSVD_2D8_RSVD_Msk                                                                (0xFFFFFFFFUL << PCC_REG_RSVD_2D8_RSVD_Pos)

/* 0x318    0x4000_0318
    2:0     R/W     RF_0_REMAP_TABLE                                3'b000
    3       R       RSVD_4                                          1'b0
    6:4     R/W     RF_4_REMAP_TABLE                                3'b000
    7       R       RSVD_3                                          1'b0
    10:8    R/W     RF_5_REMAP_TABLE                                3'b001
    11      R       RSVD_2                                          1'b0
    14:12   R/W     RF_6_REMAP_TABLE                                3'b000
    15      R       RSVD_1                                          1'b0
    18:16   R/W     RF_7_REMAP_TABLE                                3'b010
    30:19   R       RSVD                                            12'b000001100000
    31      R/W     AUTO_SWITCH_UPDATE                              1'b0
 */
typedef union _PCC_REG_SWITCH_PAR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RF_0_REMAP_TABLE: 3;
        uint32_t RSVD_4: 1;
        uint32_t RF_4_REMAP_TABLE: 3;
        uint32_t RSVD_3: 1;
        uint32_t RF_5_REMAP_TABLE: 3;
        uint32_t RSVD_2: 1;
        uint32_t RF_6_REMAP_TABLE: 3;
        uint32_t RSVD_1: 1;
        uint32_t RF_7_REMAP_TABLE: 3;
        uint32_t RSVD: 12;
        uint32_t AUTO_SWITCH_UPDATE: 1;
    };
} PCC_REG_SWITCH_PAR_TYPE;

/*0x4000_0318 PCC_REG_SWITCH_PAR*/
#define PCC_REG_SWITCH_PAR_RF_0_REMAP_TABLE_Pos                                                  0U
#define PCC_REG_SWITCH_PAR_RF_0_REMAP_TABLE_Msk                                                  (0x7UL << PCC_REG_SWITCH_PAR_RF_0_REMAP_TABLE_Pos)

#define PCC_REG_SWITCH_PAR_RSVD_4_Pos                                                            3U
#define PCC_REG_SWITCH_PAR_RSVD_4_Msk                                                            (0x1UL << PCC_REG_SWITCH_PAR_RSVD_4_Pos)

#define PCC_REG_SWITCH_PAR_RF_4_REMAP_TABLE_Pos                                                  4U
#define PCC_REG_SWITCH_PAR_RF_4_REMAP_TABLE_Msk                                                  (0x7UL << PCC_REG_SWITCH_PAR_RF_4_REMAP_TABLE_Pos)

#define PCC_REG_SWITCH_PAR_RSVD_3_Pos                                                            7U
#define PCC_REG_SWITCH_PAR_RSVD_3_Msk                                                            (0x1UL << PCC_REG_SWITCH_PAR_RSVD_3_Pos)

#define PCC_REG_SWITCH_PAR_RF_5_REMAP_TABLE_Pos                                                  8U
#define PCC_REG_SWITCH_PAR_RF_5_REMAP_TABLE_Msk                                                  (0x7UL << PCC_REG_SWITCH_PAR_RF_5_REMAP_TABLE_Pos)

#define PCC_REG_SWITCH_PAR_RSVD_2_Pos                                                            11U
#define PCC_REG_SWITCH_PAR_RSVD_2_Msk                                                            (0x1UL << PCC_REG_SWITCH_PAR_RSVD_2_Pos)

#define PCC_REG_SWITCH_PAR_RF_6_REMAP_TABLE_Pos                                                  12U
#define PCC_REG_SWITCH_PAR_RF_6_REMAP_TABLE_Msk                                                  (0x7UL << PCC_REG_SWITCH_PAR_RF_6_REMAP_TABLE_Pos)

#define PCC_REG_SWITCH_PAR_RSVD_1_Pos                                                            15U
#define PCC_REG_SWITCH_PAR_RSVD_1_Msk                                                            (0x1UL << PCC_REG_SWITCH_PAR_RSVD_1_Pos)

#define PCC_REG_SWITCH_PAR_RF_7_REMAP_TABLE_Pos                                                  16U
#define PCC_REG_SWITCH_PAR_RF_7_REMAP_TABLE_Msk                                                  (0x7UL << PCC_REG_SWITCH_PAR_RF_7_REMAP_TABLE_Pos)

#define PCC_REG_SWITCH_PAR_RSVD_Pos                                                              19U
#define PCC_REG_SWITCH_PAR_RSVD_Msk                                                              (0xFFFUL << PCC_REG_SWITCH_PAR_RSVD_Pos)

#define PCC_REG_SWITCH_PAR_AUTO_SWITCH_UPDATE_Pos                                                31U
#define PCC_REG_SWITCH_PAR_AUTO_SWITCH_UPDATE_Msk                                                (0x1UL << PCC_REG_SWITCH_PAR_AUTO_SWITCH_UPDATE_Pos)

/* 0x31C    0x4000_031c
    31:0    R/W     R_PMUX_DIGI_DBG_REG                             32'h0
 */
typedef union _PCC_REG_PINMUX_DBG_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PMUX_DIGI_DBG_REG;
    };
} PCC_REG_PINMUX_DBG_REG_TYPE;

/*0x4000_031c PCC_REG_PINMUX_DBG_REG*/
#define PCC_REG_PINMUX_DBG_REG_R_PMUX_DIGI_DBG_REG_Pos                                           0U
#define PCC_REG_PINMUX_DBG_REG_R_PMUX_DIGI_DBG_REG_Msk                                           (0xFFFFFFFFUL << PCC_REG_PINMUX_DBG_REG_R_PMUX_DIGI_DBG_REG_Pos)

/* 0x320    0x4000_0320
    15:0    R/W     DUMMY73                                         15'h0
    24:16   R       RSVD_1                                          10'h0
    25      R/W     RSVD                                            1'b0
    31:26   R/W     LDOPA_VOUT_SW_VOUT_TUNE                         6'b000101
 */
typedef union _PCC_LDO_PA_SWR_AUTO_SW_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY73: 16;
        uint32_t RSVD_1: 9;
        uint32_t RSVD: 1;
        uint32_t LDOPA_VOUT_SW_VOUT_TUNE: 6;
    };
} PCC_LDO_PA_SWR_AUTO_SW_TYPE;

/*0x4000_0320 PCC_LDO_PA_SWR_AUTO_SW*/
#define PCC_LDO_PA_SWR_AUTO_SW_DUMMY73_Pos                                                       0U
#define PCC_LDO_PA_SWR_AUTO_SW_DUMMY73_Msk                                                       (0xFFFFUL << PCC_LDO_PA_SWR_AUTO_SW_DUMMY73_Pos)

#define PCC_LDO_PA_SWR_AUTO_SW_RSVD_1_Pos                                                        16U
#define PCC_LDO_PA_SWR_AUTO_SW_RSVD_1_Msk                                                        (0x1FFUL << PCC_LDO_PA_SWR_AUTO_SW_RSVD_1_Pos)

#define PCC_LDO_PA_SWR_AUTO_SW_RSVD_Pos                                                          25U
#define PCC_LDO_PA_SWR_AUTO_SW_RSVD_Msk                                                          (0x1UL << PCC_LDO_PA_SWR_AUTO_SW_RSVD_Pos)

#define PCC_LDO_PA_SWR_AUTO_SW_LDOPA_VOUT_SW_VOUT_TUNE_Pos                                       26U
#define PCC_LDO_PA_SWR_AUTO_SW_LDOPA_VOUT_SW_VOUT_TUNE_Msk                                       (0x3FUL << PCC_LDO_PA_SWR_AUTO_SW_LDOPA_VOUT_SW_VOUT_TUNE_Pos)

/* 0x324    0x4000_0324
    7:0     R/W     TUNE_VDDCORE_0                                  8'b01100010
    12:8    R/W     TON2_TUNE_0                                     5'b01000
    17:13   R/W     TON1_TUNE_0                                     5'b01000
    18      R/W     RESERVED                                        1'b1
    23:19   R/W     LDO_TUNE_LDOANA_0                               5'b00101
    31:24   R/W     TUNE_VDDPA_0                                    8'b00100010
 */
typedef union _PCC_CORE_SWR_PAR_TAB_0_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TUNE_VDDCORE_0: 8;
        uint32_t TON2_TUNE_0: 5;
        uint32_t TON1_TUNE_0: 5;
        uint32_t RESERVED: 1;
        uint32_t LDO_TUNE_LDOANA_0: 5;
        uint32_t TUNE_VDDPA_0: 8;
    };
} PCC_CORE_SWR_PAR_TAB_0_0_TYPE;

/*0x4000_0324 PCC_CORE_SWR_PAR_TAB_0_0*/
#define PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDCORE_0_Pos                                              0U
#define PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDCORE_0_Msk                                              (0xFFUL << PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDCORE_0_Pos)

#define PCC_CORE_SWR_PAR_TAB_0_0_TON2_TUNE_0_Pos                                                 8U
#define PCC_CORE_SWR_PAR_TAB_0_0_TON2_TUNE_0_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_0_0_TON2_TUNE_0_Pos)

#define PCC_CORE_SWR_PAR_TAB_0_0_TON1_TUNE_0_Pos                                                 13U
#define PCC_CORE_SWR_PAR_TAB_0_0_TON1_TUNE_0_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_0_0_TON1_TUNE_0_Pos)

#define PCC_CORE_SWR_PAR_TAB_0_0_RESERVED_Pos                                                    18U
#define PCC_CORE_SWR_PAR_TAB_0_0_RESERVED_Msk                                                    (0x1UL << PCC_CORE_SWR_PAR_TAB_0_0_RESERVED_Pos)

#define PCC_CORE_SWR_PAR_TAB_0_0_LDO_TUNE_LDOANA_0_Pos                                           19U
#define PCC_CORE_SWR_PAR_TAB_0_0_LDO_TUNE_LDOANA_0_Msk                                           (0x1FUL << PCC_CORE_SWR_PAR_TAB_0_0_LDO_TUNE_LDOANA_0_Pos)

#define PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDPA_0_Pos                                                24U
#define PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDPA_0_Msk                                                (0xFFUL << PCC_CORE_SWR_PAR_TAB_0_0_TUNE_VDDPA_0_Pos)

/* 0x328    0x4000_0328
    7:0     R/W     TUNE_VDDCORE_4                                  8'b01100010
    12:8    R/W     TON2_TUNE_4                                     5'b01000
    17:13   R/W     TON1_TUNE_4                                     5'b01000
    18      R/W     RESERVED                                        1'b1
    23:19   R/W     LDO_TUNE_LDOANA_4                               5'b00101
    31:24   R/W     TUNE_VDDPA_4                                    8'b01111010
 */
typedef union _PCC_CORE_SWR_PAR_TAB_4_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TUNE_VDDCORE_4: 8;
        uint32_t TON2_TUNE_4: 5;
        uint32_t TON1_TUNE_4: 5;
        uint32_t RESERVED: 1;
        uint32_t LDO_TUNE_LDOANA_4: 5;
        uint32_t TUNE_VDDPA_4: 8;
    };
} PCC_CORE_SWR_PAR_TAB_4_0_TYPE;

/*0x4000_0328 PCC_CORE_SWR_PAR_TAB_4_0*/
#define PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDCORE_4_Pos                                              0U
#define PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDCORE_4_Msk                                              (0xFFUL << PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDCORE_4_Pos)

#define PCC_CORE_SWR_PAR_TAB_4_0_TON2_TUNE_4_Pos                                                 8U
#define PCC_CORE_SWR_PAR_TAB_4_0_TON2_TUNE_4_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_4_0_TON2_TUNE_4_Pos)

#define PCC_CORE_SWR_PAR_TAB_4_0_TON1_TUNE_4_Pos                                                 13U
#define PCC_CORE_SWR_PAR_TAB_4_0_TON1_TUNE_4_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_4_0_TON1_TUNE_4_Pos)

#define PCC_CORE_SWR_PAR_TAB_4_0_RESERVED_Pos                                                    18U
#define PCC_CORE_SWR_PAR_TAB_4_0_RESERVED_Msk                                                    (0x1UL << PCC_CORE_SWR_PAR_TAB_4_0_RESERVED_Pos)

#define PCC_CORE_SWR_PAR_TAB_4_0_LDO_TUNE_LDOANA_4_Pos                                           19U
#define PCC_CORE_SWR_PAR_TAB_4_0_LDO_TUNE_LDOANA_4_Msk                                           (0x1FUL << PCC_CORE_SWR_PAR_TAB_4_0_LDO_TUNE_LDOANA_4_Pos)

#define PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDPA_4_Pos                                                24U
#define PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDPA_4_Msk                                                (0xFFUL << PCC_CORE_SWR_PAR_TAB_4_0_TUNE_VDDPA_4_Pos)

/* 0x32C    0x4000_032c
    7:0     R/W     TUNE_VDDCORE_5                                  8'b01100010
    12:8    R/W     TON2_TUNE_5                                     5'b01000
    17:13   R/W     TON1_TUNE_5                                     5'b01000
    18      R/W     RESERVED                                        1'b1
    23:19   R/W     LDO_TUNE_LDOANA_5                               5'b00101
    31:24   R/W     TUNE_VDDPA_5                                    8'b01111010
 */
typedef union _PCC_CORE_SWR_PAR_TAB_5_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TUNE_VDDCORE_5: 8;
        uint32_t TON2_TUNE_5: 5;
        uint32_t TON1_TUNE_5: 5;
        uint32_t RESERVED: 1;
        uint32_t LDO_TUNE_LDOANA_5: 5;
        uint32_t TUNE_VDDPA_5: 8;
    };
} PCC_CORE_SWR_PAR_TAB_5_0_TYPE;

/*0x4000_032c PCC_CORE_SWR_PAR_TAB_5_0*/
#define PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDCORE_5_Pos                                              0U
#define PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDCORE_5_Msk                                              (0xFFUL << PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDCORE_5_Pos)

#define PCC_CORE_SWR_PAR_TAB_5_0_TON2_TUNE_5_Pos                                                 8U
#define PCC_CORE_SWR_PAR_TAB_5_0_TON2_TUNE_5_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_5_0_TON2_TUNE_5_Pos)

#define PCC_CORE_SWR_PAR_TAB_5_0_TON1_TUNE_5_Pos                                                 13U
#define PCC_CORE_SWR_PAR_TAB_5_0_TON1_TUNE_5_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_5_0_TON1_TUNE_5_Pos)

#define PCC_CORE_SWR_PAR_TAB_5_0_RESERVED_Pos                                                    18U
#define PCC_CORE_SWR_PAR_TAB_5_0_RESERVED_Msk                                                    (0x1UL << PCC_CORE_SWR_PAR_TAB_5_0_RESERVED_Pos)

#define PCC_CORE_SWR_PAR_TAB_5_0_LDO_TUNE_LDOANA_5_Pos                                           19U
#define PCC_CORE_SWR_PAR_TAB_5_0_LDO_TUNE_LDOANA_5_Msk                                           (0x1FUL << PCC_CORE_SWR_PAR_TAB_5_0_LDO_TUNE_LDOANA_5_Pos)

#define PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDPA_5_Pos                                                24U
#define PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDPA_5_Msk                                                (0xFFUL << PCC_CORE_SWR_PAR_TAB_5_0_TUNE_VDDPA_5_Pos)

/* 0x330    0x4000_0330
    7:0     R/W     TUNE_VDDCORE_6                                  8'b01100010
    12:8    R/W     TON2_TUNE_6                                     5'b01000
    17:13   R/W     TON1_TUNE_6                                     5'b01000
    18      R/W     RESERVED                                        1'b1
    23:19   R/W     LDO_TUNE_LDOANA_6                               5'b00101
    31:24   R/W     TUNE_VDDPA_6                                    8'b01111010
 */
typedef union _PCC_CORE_SWR_PAR_TAB_6_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TUNE_VDDCORE_6: 8;
        uint32_t TON2_TUNE_6: 5;
        uint32_t TON1_TUNE_6: 5;
        uint32_t RESERVED: 1;
        uint32_t LDO_TUNE_LDOANA_6: 5;
        uint32_t TUNE_VDDPA_6: 8;
    };
} PCC_CORE_SWR_PAR_TAB_6_0_TYPE;

/*0x4000_0330 PCC_CORE_SWR_PAR_TAB_6_0*/
#define PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDCORE_6_Pos                                              0U
#define PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDCORE_6_Msk                                              (0xFFUL << PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDCORE_6_Pos)

#define PCC_CORE_SWR_PAR_TAB_6_0_TON2_TUNE_6_Pos                                                 8U
#define PCC_CORE_SWR_PAR_TAB_6_0_TON2_TUNE_6_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_6_0_TON2_TUNE_6_Pos)

#define PCC_CORE_SWR_PAR_TAB_6_0_TON1_TUNE_6_Pos                                                 13U
#define PCC_CORE_SWR_PAR_TAB_6_0_TON1_TUNE_6_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_6_0_TON1_TUNE_6_Pos)

#define PCC_CORE_SWR_PAR_TAB_6_0_RESERVED_Pos                                                    18U
#define PCC_CORE_SWR_PAR_TAB_6_0_RESERVED_Msk                                                    (0x1UL << PCC_CORE_SWR_PAR_TAB_6_0_RESERVED_Pos)

#define PCC_CORE_SWR_PAR_TAB_6_0_LDO_TUNE_LDOANA_6_Pos                                           19U
#define PCC_CORE_SWR_PAR_TAB_6_0_LDO_TUNE_LDOANA_6_Msk                                           (0x1FUL << PCC_CORE_SWR_PAR_TAB_6_0_LDO_TUNE_LDOANA_6_Pos)

#define PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDPA_6_Pos                                                24U
#define PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDPA_6_Msk                                                (0xFFUL << PCC_CORE_SWR_PAR_TAB_6_0_TUNE_VDDPA_6_Pos)

/* 0x334    0x4000_0334
    7:0     R/W     TUNE_VDDCORE_7                                  8'b01100010
    12:8    R/W     TON2_TUNE_7                                     5'b01000
    17:13   R/W     TON1_TUNE_7                                     5'b01000
    18      R/W     RESERVED                                        1'b1
    23:19   R/W     LDO_TUNE_LDOANA_7                               5'b00101
    31:24   R/W     TUNE_VDDPA_7                                    8'b01111010
 */
typedef union _PCC_CORE_SWR_PAR_TAB_7_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TUNE_VDDCORE_7: 8;
        uint32_t TON2_TUNE_7: 5;
        uint32_t TON1_TUNE_7: 5;
        uint32_t RESERVED: 1;
        uint32_t LDO_TUNE_LDOANA_7: 5;
        uint32_t TUNE_VDDPA_7: 8;
    };
} PCC_CORE_SWR_PAR_TAB_7_0_TYPE;

/*0x4000_0334 PCC_CORE_SWR_PAR_TAB_7_0*/
#define PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDCORE_7_Pos                                              0U
#define PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDCORE_7_Msk                                              (0xFFUL << PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDCORE_7_Pos)

#define PCC_CORE_SWR_PAR_TAB_7_0_TON2_TUNE_7_Pos                                                 8U
#define PCC_CORE_SWR_PAR_TAB_7_0_TON2_TUNE_7_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_7_0_TON2_TUNE_7_Pos)

#define PCC_CORE_SWR_PAR_TAB_7_0_TON1_TUNE_7_Pos                                                 13U
#define PCC_CORE_SWR_PAR_TAB_7_0_TON1_TUNE_7_Msk                                                 (0x1FUL << PCC_CORE_SWR_PAR_TAB_7_0_TON1_TUNE_7_Pos)

#define PCC_CORE_SWR_PAR_TAB_7_0_RESERVED_Pos                                                    18U
#define PCC_CORE_SWR_PAR_TAB_7_0_RESERVED_Msk                                                    (0x1UL << PCC_CORE_SWR_PAR_TAB_7_0_RESERVED_Pos)

#define PCC_CORE_SWR_PAR_TAB_7_0_LDO_TUNE_LDOANA_7_Pos                                           19U
#define PCC_CORE_SWR_PAR_TAB_7_0_LDO_TUNE_LDOANA_7_Msk                                           (0x1FUL << PCC_CORE_SWR_PAR_TAB_7_0_LDO_TUNE_LDOANA_7_Pos)

#define PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDPA_7_Pos                                                24U
#define PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDPA_7_Msk                                                (0xFFUL << PCC_CORE_SWR_PAR_TAB_7_0_TUNE_VDDPA_7_Pos)

/* 0x338    0x4000_0338
    5:0     R/W     CORE_SWR_PAR_TAB_7                              6'h0
    11:6    R/W     CORE_SWR_PAR_TAB_6                              6'h0
    17:12   R/W     CORE_SWR_PAR_TAB_5                              6'h0
    23:18   R/W     CORE_SWR_PAR_TAB_4                              6'h0
    29:24   R/W     CORE_SWR_PAR_TAB_0                              6'h0
    31:30   R/W     DUMMY74                                         2'b00
 */
typedef union _PCC_REG_CORE_PAR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t CORE_SWR_PAR_TAB_7: 6;
        uint32_t CORE_SWR_PAR_TAB_6: 6;
        uint32_t CORE_SWR_PAR_TAB_5: 6;
        uint32_t CORE_SWR_PAR_TAB_4: 6;
        uint32_t CORE_SWR_PAR_TAB_0: 6;
        uint32_t DUMMY74: 2;
    };
} PCC_REG_CORE_PAR_TYPE;

/*0x4000_0338 PCC_REG_CORE_PAR*/
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_7_Pos                                                  0U
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_7_Msk                                                  (0x3FUL << PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_7_Pos)

#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_6_Pos                                                  6U
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_6_Msk                                                  (0x3FUL << PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_6_Pos)

#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_5_Pos                                                  12U
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_5_Msk                                                  (0x3FUL << PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_5_Pos)

#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_4_Pos                                                  18U
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_4_Msk                                                  (0x3FUL << PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_4_Pos)

#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_0_Pos                                                  24U
#define PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_0_Msk                                                  (0x3FUL << PCC_REG_CORE_PAR_CORE_SWR_PAR_TAB_0_Pos)

#define PCC_REG_CORE_PAR_DUMMY74_Pos                                                             30U
#define PCC_REG_CORE_PAR_DUMMY74_Msk                                                             (0x3UL << PCC_REG_CORE_PAR_DUMMY74_Pos)

/* 0x33C    0x4000_033c
    7:0     R/W     PON_PERI_DLYSEL_CTRL                            8'h0
    15:8    R/W     DUMMY79                                         8'h0
    23:16   R/W     DUMMY78                                         8'h0
    24      R/W     R_FLASH0_CLK_INV_EN                             0
    25      R/W     DUMMY77                                         0
    26      R/W     DUMMY76                                         0
    30:27   R/W     DUMMY75                                         4'h0
    31      R/W     R_SPIC2_DMA_TX_REQ_AS_SINGLE                    0
 */
typedef union _PCC_PON_PERI_DLYSEL_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PON_PERI_DLYSEL_CTRL: 8;
        uint32_t DUMMY79: 8;
        uint32_t DUMMY78: 8;
        uint32_t R_FLASH0_CLK_INV_EN: 1;
        uint32_t DUMMY77: 1;
        uint32_t DUMMY76: 1;
        uint32_t DUMMY75: 4;
        uint32_t R_SPIC2_DMA_TX_REQ_AS_SINGLE: 1;
    };
} PCC_PON_PERI_DLYSEL_CTRL_TYPE;

/*0x4000_033c PCC_PON_PERI_DLYSEL_CTRL*/
#define PCC_PON_PERI_DLYSEL_CTRL_PON_PERI_DLYSEL_CTRL_Pos                                        0U
#define PCC_PON_PERI_DLYSEL_CTRL_PON_PERI_DLYSEL_CTRL_Msk                                        (0xFFUL << PCC_PON_PERI_DLYSEL_CTRL_PON_PERI_DLYSEL_CTRL_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY79_Pos                                                     8U
#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY79_Msk                                                     (0xFFUL << PCC_PON_PERI_DLYSEL_CTRL_DUMMY79_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY78_Pos                                                     16U
#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY78_Msk                                                     (0xFFUL << PCC_PON_PERI_DLYSEL_CTRL_DUMMY78_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_R_FLASH0_CLK_INV_EN_Pos                                         24U
#define PCC_PON_PERI_DLYSEL_CTRL_R_FLASH0_CLK_INV_EN_Msk                                         (0x1UL << PCC_PON_PERI_DLYSEL_CTRL_R_FLASH0_CLK_INV_EN_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY77_Pos                                                     25U
#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY77_Msk                                                     (0x1UL << PCC_PON_PERI_DLYSEL_CTRL_DUMMY77_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY76_Pos                                                     26U
#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY76_Msk                                                     (0x1UL << PCC_PON_PERI_DLYSEL_CTRL_DUMMY76_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY75_Pos                                                     27U
#define PCC_PON_PERI_DLYSEL_CTRL_DUMMY75_Msk                                                     (0xFUL << PCC_PON_PERI_DLYSEL_CTRL_DUMMY75_Pos)

#define PCC_PON_PERI_DLYSEL_CTRL_R_SPIC2_DMA_TX_REQ_AS_SINGLE_Pos                                31U
#define PCC_PON_PERI_DLYSEL_CTRL_R_SPIC2_DMA_TX_REQ_AS_SINGLE_Msk                                (0x1UL << PCC_PON_PERI_DLYSEL_CTRL_R_SPIC2_DMA_TX_REQ_AS_SINGLE_Pos)

/* 0x340    0x4000_0340
    19:0    R/W     R_DSS_DATA_IN                                   20'h1543d
    22:20   R/W     R_DSS_RO_SEL                                    3'd0
    23      R/W     R_DSS_WIRE_SEL                                  1'd0
    24      R/W     R_DSS_CLK_EN                                    1'd0
    25      R/W     R_DSS_SPEED_EN                                  1'd0
    31:26   R/W     DUMMY80                                         6'h0
 */
typedef union _PCC_REG_DSS_CTRL0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_DSS_DATA_IN: 20;
        uint32_t R_DSS_RO_SEL: 3;
        uint32_t R_DSS_WIRE_SEL: 1;
        uint32_t R_DSS_CLK_EN: 1;
        uint32_t R_DSS_SPEED_EN: 1;
        uint32_t DUMMY80: 6;
    };
} PCC_REG_DSS_CTRL0_TYPE;

/*0x4000_0340 PCC_REG_DSS_CTRL0*/
#define PCC_REG_DSS_CTRL0_R_DSS_DATA_IN_Pos                                                      0U
#define PCC_REG_DSS_CTRL0_R_DSS_DATA_IN_Msk                                                      (0xFFFFFUL << PCC_REG_DSS_CTRL0_R_DSS_DATA_IN_Pos)

#define PCC_REG_DSS_CTRL0_R_DSS_RO_SEL_Pos                                                       20U
#define PCC_REG_DSS_CTRL0_R_DSS_RO_SEL_Msk                                                       (0x7UL << PCC_REG_DSS_CTRL0_R_DSS_RO_SEL_Pos)

#define PCC_REG_DSS_CTRL0_R_DSS_WIRE_SEL_Pos                                                     23U
#define PCC_REG_DSS_CTRL0_R_DSS_WIRE_SEL_Msk                                                     (0x1UL << PCC_REG_DSS_CTRL0_R_DSS_WIRE_SEL_Pos)

#define PCC_REG_DSS_CTRL0_R_DSS_CLK_EN_Pos                                                       24U
#define PCC_REG_DSS_CTRL0_R_DSS_CLK_EN_Msk                                                       (0x1UL << PCC_REG_DSS_CTRL0_R_DSS_CLK_EN_Pos)

#define PCC_REG_DSS_CTRL0_R_DSS_SPEED_EN_Pos                                                     25U
#define PCC_REG_DSS_CTRL0_R_DSS_SPEED_EN_Msk                                                     (0x1UL << PCC_REG_DSS_CTRL0_R_DSS_SPEED_EN_Pos)

#define PCC_REG_DSS_CTRL0_DUMMY80_Pos                                                            26U
#define PCC_REG_DSS_CTRL0_DUMMY80_Msk                                                            (0x3FUL << PCC_REG_DSS_CTRL0_DUMMY80_Pos)

/* 0x344    0x4000_0344
    19:0    R       DSS_POW_COUNT                                   20'd0
    20      R       DSS_POW_WSORT_GO                                0
    21      R       DSS_POW_READY                                   0
    31:22   R       RSVD                                            10'h0
 */
typedef union _PCC_REG_DSS_CTRL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DSS_POW_COUNT: 20;
        uint32_t DSS_POW_WSORT_GO: 1;
        uint32_t DSS_POW_READY: 1;
        uint32_t RSVD: 10;
    };
} PCC_REG_DSS_CTRL1_TYPE;

/*0x4000_0344 PCC_REG_DSS_CTRL1*/
#define PCC_REG_DSS_CTRL1_DSS_POW_COUNT_Pos                                                      0U
#define PCC_REG_DSS_CTRL1_DSS_POW_COUNT_Msk                                                      (0xFFFFFUL << PCC_REG_DSS_CTRL1_DSS_POW_COUNT_Pos)

#define PCC_REG_DSS_CTRL1_DSS_POW_WSORT_GO_Pos                                                   20U
#define PCC_REG_DSS_CTRL1_DSS_POW_WSORT_GO_Msk                                                   (0x1UL << PCC_REG_DSS_CTRL1_DSS_POW_WSORT_GO_Pos)

#define PCC_REG_DSS_CTRL1_DSS_POW_READY_Pos                                                      21U
#define PCC_REG_DSS_CTRL1_DSS_POW_READY_Msk                                                      (0x1UL << PCC_REG_DSS_CTRL1_DSS_POW_READY_Pos)

#define PCC_REG_DSS_CTRL1_RSVD_Pos                                                               22U
#define PCC_REG_DSS_CTRL1_RSVD_Msk                                                               (0x3FFUL << PCC_REG_DSS_CTRL1_RSVD_Pos)

/* 0x348    0x4000_0348
    19:0    R       DSS_IR_COUNT                                    20'd0
    20      R       DSS_IR_WSORT_GO                                 0
    21      R       DSS_IR_READY                                    0
    31:22   R       RSVD                                            10'h0
 */
typedef union _PCC_REG_DSS_CTRL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DSS_IR_COUNT: 20;
        uint32_t DSS_IR_WSORT_GO: 1;
        uint32_t DSS_IR_READY: 1;
        uint32_t RSVD: 10;
    };
} PCC_REG_DSS_CTRL2_TYPE;

/*0x4000_0348 PCC_REG_DSS_CTRL2*/
#define PCC_REG_DSS_CTRL2_DSS_IR_COUNT_Pos                                                       0U
#define PCC_REG_DSS_CTRL2_DSS_IR_COUNT_Msk                                                       (0xFFFFFUL << PCC_REG_DSS_CTRL2_DSS_IR_COUNT_Pos)

#define PCC_REG_DSS_CTRL2_DSS_IR_WSORT_GO_Pos                                                    20U
#define PCC_REG_DSS_CTRL2_DSS_IR_WSORT_GO_Msk                                                    (0x1UL << PCC_REG_DSS_CTRL2_DSS_IR_WSORT_GO_Pos)

#define PCC_REG_DSS_CTRL2_DSS_IR_READY_Pos                                                       21U
#define PCC_REG_DSS_CTRL2_DSS_IR_READY_Msk                                                       (0x1UL << PCC_REG_DSS_CTRL2_DSS_IR_READY_Pos)

#define PCC_REG_DSS_CTRL2_RSVD_Pos                                                               22U
#define PCC_REG_DSS_CTRL2_RSVD_Msk                                                               (0x3FFUL << PCC_REG_DSS_CTRL2_RSVD_Pos)

/* 0x34C    0x4000_034c
    3:0     R       OSC40_FSET                                      4'h0
    7:4     R       RSVD                                            4'h0
    31:8    R/W     DUMMY84                                         24'h000109
 */
typedef union _PCC_REG_OSC40_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t OSC40_FSET: 4;
        uint32_t RSVD: 4;
        uint32_t DUMMY84: 24;
    };
} PCC_REG_OSC40_CTRL_TYPE;

/*0x4000_034c PCC_REG_OSC40_CTRL*/
#define PCC_REG_OSC40_CTRL_OSC40_FSET_Pos                                                        0U
#define PCC_REG_OSC40_CTRL_OSC40_FSET_Msk                                                        (0xFUL << PCC_REG_OSC40_CTRL_OSC40_FSET_Pos)

#define PCC_REG_OSC40_CTRL_RSVD_Pos                                                              4U
#define PCC_REG_OSC40_CTRL_RSVD_Msk                                                              (0xFUL << PCC_REG_OSC40_CTRL_RSVD_Pos)

#define PCC_REG_OSC40_CTRL_DUMMY84_Pos                                                           8U
#define PCC_REG_OSC40_CTRL_DUMMY84_Msk                                                           (0xFFFFFFUL << PCC_REG_OSC40_CTRL_DUMMY84_Pos)

/* 0x350    0x4000_0350
    0       R/W     RST_N_AAC                                       0
    1       R/W     OFFSET_PLUS                                     0
    7:2     R/W     XAAC_GM_OFFSET                                  6'b000000
    8       R/W     GM_STEP                                         0
    14:9    R/W     GM_INIT                                         6'b111110
    17:15   R/W     XTAL_CLK_SET                                    3'b101
    23:18   R/W     GM_STUP                                         6'b111111
    29:24   R/W     GM_MANUAL                                       6'b111111
    30      R/W     R_EN_XTAL_AAC_DIGI                              0
    31      R/W     R_EN_XTAL_AAC_TRIG                              0
 */
typedef union _PCC_REG_AAC_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RST_N_AAC: 1;
        uint32_t OFFSET_PLUS: 1;
        uint32_t XAAC_GM_OFFSET: 6;
        uint32_t GM_STEP: 1;
        uint32_t GM_INIT: 6;
        uint32_t XTAL_CLK_SET: 3;
        uint32_t GM_STUP: 6;
        uint32_t GM_MANUAL: 6;
        uint32_t R_EN_XTAL_AAC_DIGI: 1;
        uint32_t R_EN_XTAL_AAC_TRIG: 1;
    };
} PCC_REG_AAC_0_TYPE;

/*0x4000_0350 PCC_REG_AAC_0*/
#define PCC_REG_AAC_0_RST_N_AAC_Pos                                                              0U
#define PCC_REG_AAC_0_RST_N_AAC_Msk                                                              (0x1UL << PCC_REG_AAC_0_RST_N_AAC_Pos)

#define PCC_REG_AAC_0_OFFSET_PLUS_Pos                                                            1U
#define PCC_REG_AAC_0_OFFSET_PLUS_Msk                                                            (0x1UL << PCC_REG_AAC_0_OFFSET_PLUS_Pos)

#define PCC_REG_AAC_0_XAAC_GM_OFFSET_Pos                                                         2U
#define PCC_REG_AAC_0_XAAC_GM_OFFSET_Msk                                                         (0x3FUL << PCC_REG_AAC_0_XAAC_GM_OFFSET_Pos)

#define PCC_REG_AAC_0_GM_STEP_Pos                                                                8U
#define PCC_REG_AAC_0_GM_STEP_Msk                                                                (0x1UL << PCC_REG_AAC_0_GM_STEP_Pos)

#define PCC_REG_AAC_0_GM_INIT_Pos                                                                9U
#define PCC_REG_AAC_0_GM_INIT_Msk                                                                (0x3FUL << PCC_REG_AAC_0_GM_INIT_Pos)

#define PCC_REG_AAC_0_XTAL_CLK_SET_Pos                                                           15U
#define PCC_REG_AAC_0_XTAL_CLK_SET_Msk                                                           (0x7UL << PCC_REG_AAC_0_XTAL_CLK_SET_Pos)

#define PCC_REG_AAC_0_GM_STUP_Pos                                                                18U
#define PCC_REG_AAC_0_GM_STUP_Msk                                                                (0x3FUL << PCC_REG_AAC_0_GM_STUP_Pos)

#define PCC_REG_AAC_0_GM_MANUAL_Pos                                                              24U
#define PCC_REG_AAC_0_GM_MANUAL_Msk                                                              (0x3FUL << PCC_REG_AAC_0_GM_MANUAL_Pos)

#define PCC_REG_AAC_0_R_EN_XTAL_AAC_DIGI_Pos                                                     30U
#define PCC_REG_AAC_0_R_EN_XTAL_AAC_DIGI_Msk                                                     (0x1UL << PCC_REG_AAC_0_R_EN_XTAL_AAC_DIGI_Pos)

#define PCC_REG_AAC_0_R_EN_XTAL_AAC_TRIG_Pos                                                     31U
#define PCC_REG_AAC_0_R_EN_XTAL_AAC_TRIG_Msk                                                     (0x1UL << PCC_REG_AAC_0_R_EN_XTAL_AAC_TRIG_Pos)

/* 0x354    0x4000_0354
    0       R       XAAC_BUSY                                       0
    1       R       XTAL_AAC_OK                                     0
    7:2     R       XTAL_GM_OUT                                     6'h3F
    11:8    R       XAAC_CURR_STATE                                 4'h0
    12      R/W     XTAL_EN_DAAC_GM                                 0
    13      R/W     XTAL_EN_AAC_PKDET                               0
    14      R       XTAL_PKDET_OUT                                  0
    15      R/W     DUMMY86                                         0
    31:16   R/W     DUMMY85                                         16'h0129
 */
typedef union _PCC_REG_AAC_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XAAC_BUSY: 1;
        uint32_t XTAL_AAC_OK: 1;
        uint32_t XTAL_GM_OUT: 6;
        uint32_t XAAC_CURR_STATE: 4;
        uint32_t XTAL_EN_DAAC_GM: 1;
        uint32_t XTAL_EN_AAC_PKDET: 1;
        uint32_t XTAL_PKDET_OUT: 1;
        uint32_t DUMMY86: 1;
        uint32_t DUMMY85: 16;
    };
} PCC_REG_AAC_1_TYPE;

/*0x4000_0354 PCC_REG_AAC_1*/
#define PCC_REG_AAC_1_XAAC_BUSY_Pos                                                              0U
#define PCC_REG_AAC_1_XAAC_BUSY_Msk                                                              (0x1UL << PCC_REG_AAC_1_XAAC_BUSY_Pos)

#define PCC_REG_AAC_1_XTAL_AAC_OK_Pos                                                            1U
#define PCC_REG_AAC_1_XTAL_AAC_OK_Msk                                                            (0x1UL << PCC_REG_AAC_1_XTAL_AAC_OK_Pos)

#define PCC_REG_AAC_1_XTAL_GM_OUT_Pos                                                            2U
#define PCC_REG_AAC_1_XTAL_GM_OUT_Msk                                                            (0x3FUL << PCC_REG_AAC_1_XTAL_GM_OUT_Pos)

#define PCC_REG_AAC_1_XAAC_CURR_STATE_Pos                                                        8U
#define PCC_REG_AAC_1_XAAC_CURR_STATE_Msk                                                        (0xFUL << PCC_REG_AAC_1_XAAC_CURR_STATE_Pos)

#define PCC_REG_AAC_1_XTAL_EN_DAAC_GM_Pos                                                        12U
#define PCC_REG_AAC_1_XTAL_EN_DAAC_GM_Msk                                                        (0x1UL << PCC_REG_AAC_1_XTAL_EN_DAAC_GM_Pos)

#define PCC_REG_AAC_1_XTAL_EN_AAC_PKDET_Pos                                                      13U
#define PCC_REG_AAC_1_XTAL_EN_AAC_PKDET_Msk                                                      (0x1UL << PCC_REG_AAC_1_XTAL_EN_AAC_PKDET_Pos)

#define PCC_REG_AAC_1_XTAL_PKDET_OUT_Pos                                                         14U
#define PCC_REG_AAC_1_XTAL_PKDET_OUT_Msk                                                         (0x1UL << PCC_REG_AAC_1_XTAL_PKDET_OUT_Pos)

#define PCC_REG_AAC_1_DUMMY86_Pos                                                                15U
#define PCC_REG_AAC_1_DUMMY86_Msk                                                                (0x1UL << PCC_REG_AAC_1_DUMMY86_Pos)

#define PCC_REG_AAC_1_DUMMY85_Pos                                                                16U
#define PCC_REG_AAC_1_DUMMY85_Msk                                                                (0xFFFFUL << PCC_REG_AAC_1_DUMMY85_Pos)

/* 0x358    0x4000_0358
    0       R/W     DISABLE_PLL_PRE_GATING                          0
    15:1    R/W     DUMMY88                                         15'h0
    17:16   R/W     DUMMY87                                         2'h3
    23:18   R       RSVD_1                                          6'h0
    24      R       BT_PLL_READY                                    0
    25      R       XTAL_OK                                         0
    31:26   R       RSVD                                            6'h0
 */
typedef union _PCC_REG_XTAL_PLL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DISABLE_PLL_PRE_GATING: 1;
        uint32_t DUMMY88: 15;
        uint32_t DUMMY87: 2;
        uint32_t RSVD_1: 6;
        uint32_t BT_PLL_READY: 1;
        uint32_t XTAL_OK: 1;
        uint32_t RSVD: 6;
    };
} PCC_REG_XTAL_PLL_TYPE;

/*0x4000_0358 PCC_REG_XTAL_PLL*/
#define PCC_REG_XTAL_PLL_DISABLE_PLL_PRE_GATING_Pos                                              0U
#define PCC_REG_XTAL_PLL_DISABLE_PLL_PRE_GATING_Msk                                              (0x1UL << PCC_REG_XTAL_PLL_DISABLE_PLL_PRE_GATING_Pos)

#define PCC_REG_XTAL_PLL_DUMMY88_Pos                                                             1U
#define PCC_REG_XTAL_PLL_DUMMY88_Msk                                                             (0x7FFFUL << PCC_REG_XTAL_PLL_DUMMY88_Pos)

#define PCC_REG_XTAL_PLL_DUMMY87_Pos                                                             16U
#define PCC_REG_XTAL_PLL_DUMMY87_Msk                                                             (0x3UL << PCC_REG_XTAL_PLL_DUMMY87_Pos)

#define PCC_REG_XTAL_PLL_RSVD_1_Pos                                                              18U
#define PCC_REG_XTAL_PLL_RSVD_1_Msk                                                              (0x3FUL << PCC_REG_XTAL_PLL_RSVD_1_Pos)

#define PCC_REG_XTAL_PLL_BT_PLL_READY_Pos                                                        24U
#define PCC_REG_XTAL_PLL_BT_PLL_READY_Msk                                                        (0x1UL << PCC_REG_XTAL_PLL_BT_PLL_READY_Pos)

#define PCC_REG_XTAL_PLL_XTAL_OK_Pos                                                             25U
#define PCC_REG_XTAL_PLL_XTAL_OK_Msk                                                             (0x1UL << PCC_REG_XTAL_PLL_XTAL_OK_Pos)

#define PCC_REG_XTAL_PLL_RSVD_Pos                                                                26U
#define PCC_REG_XTAL_PLL_RSVD_Msk                                                                (0x3FUL << PCC_REG_XTAL_PLL_RSVD_Pos)

/* 0x35C    0x4000_035c
    0       R/W     RESERVED_10                                     0
    1       R/W     RESERVED_9                                      1
    2       R/W     RESERVED_8                                      0
    4:3     R/W     RESERVED_7                                      2'b01
    9:5     R/W     RESERVED_6                                      5'b10000
    14:10   R/W     RESERVED_5                                      5'b11111
    16:15   R/W     RESERVED_4                                      2'b10
    21:17   R/W     RESERVED_3                                      5'b00000
    22      R/W     RESERVED_2                                      0
    27:23   R/W     RESERVED_1                                      5'h0
    31:28   R       RESERVED                                        4'h0
 */
typedef union _PCC_REG_XTALPDCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 2;
        uint32_t RESERVED_6: 5;
        uint32_t RESERVED_5: 5;
        uint32_t RESERVED_4: 2;
        uint32_t RESERVED_3: 5;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 5;
        uint32_t RESERVED: 4;
    };
} PCC_REG_XTALPDCK_TYPE;

/*0x4000_035c PCC_REG_XTALPDCK*/
#define PCC_REG_XTALPDCK_RESERVED_10_Pos                                                         0U
#define PCC_REG_XTALPDCK_RESERVED_10_Msk                                                         (0x1UL << PCC_REG_XTALPDCK_RESERVED_10_Pos)

#define PCC_REG_XTALPDCK_RESERVED_9_Pos                                                          1U
#define PCC_REG_XTALPDCK_RESERVED_9_Msk                                                          (0x1UL << PCC_REG_XTALPDCK_RESERVED_9_Pos)

#define PCC_REG_XTALPDCK_RESERVED_8_Pos                                                          2U
#define PCC_REG_XTALPDCK_RESERVED_8_Msk                                                          (0x1UL << PCC_REG_XTALPDCK_RESERVED_8_Pos)

#define PCC_REG_XTALPDCK_RESERVED_7_Pos                                                          3U
#define PCC_REG_XTALPDCK_RESERVED_7_Msk                                                          (0x3UL << PCC_REG_XTALPDCK_RESERVED_7_Pos)

#define PCC_REG_XTALPDCK_RESERVED_6_Pos                                                          5U
#define PCC_REG_XTALPDCK_RESERVED_6_Msk                                                          (0x1FUL << PCC_REG_XTALPDCK_RESERVED_6_Pos)

#define PCC_REG_XTALPDCK_RESERVED_5_Pos                                                          10U
#define PCC_REG_XTALPDCK_RESERVED_5_Msk                                                          (0x1FUL << PCC_REG_XTALPDCK_RESERVED_5_Pos)

#define PCC_REG_XTALPDCK_RESERVED_4_Pos                                                          15U
#define PCC_REG_XTALPDCK_RESERVED_4_Msk                                                          (0x3UL << PCC_REG_XTALPDCK_RESERVED_4_Pos)

#define PCC_REG_XTALPDCK_RESERVED_3_Pos                                                          17U
#define PCC_REG_XTALPDCK_RESERVED_3_Msk                                                          (0x1FUL << PCC_REG_XTALPDCK_RESERVED_3_Pos)

#define PCC_REG_XTALPDCK_RESERVED_2_Pos                                                          22U
#define PCC_REG_XTALPDCK_RESERVED_2_Msk                                                          (0x1UL << PCC_REG_XTALPDCK_RESERVED_2_Pos)

#define PCC_REG_XTALPDCK_RESERVED_1_Pos                                                          23U
#define PCC_REG_XTALPDCK_RESERVED_1_Msk                                                          (0x1FUL << PCC_REG_XTALPDCK_RESERVED_1_Pos)

#define PCC_REG_XTALPDCK_RESERVED_Pos                                                            28U
#define PCC_REG_XTALPDCK_RESERVED_Msk                                                            (0xFUL << PCC_REG_XTALPDCK_RESERVED_Pos)

/* 0x360    0x4000_0360
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG0_TYPE;

/*0x4000_0360 PCC_REG_PADMUX_AS_CFG0*/
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG0_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG0_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG0_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG0_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG0_RESERVED_Pos)

/* 0x364    0x4000_0364
    0       R/W     RESERVED_11                                     1'b0
    1       R/W     RESERVED_10                                     1'b0
    2       R/W     RESERVED_9                                      1'b0
    3       R/W     RESERVED_8                                      1'b0
    7:4     R/W     RESERVED_7                                      4'd0
    8       R/W     RESERVED_6                                      1'b0
    9       R/W     RESERVED_5                                      1'b0
    10      R/W     RESERVED_4                                      1'b0
    11      R/W     RESERVED_3                                      1'b0
    14:12   R/W     RESERVED_2                                      3'd0
    15      R/W     RESERVED_1                                      1'b0
    31:16   R/W     RESERVED                                        16'd0
 */
typedef union _PCC_REG_PADMUX_AS_CFG1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 4;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 16;
    };
} PCC_REG_PADMUX_AS_CFG1_TYPE;

/*0x4000_0364 PCC_REG_PADMUX_AS_CFG1*/
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_11_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_10_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_9_Pos                                                    2U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_8_Pos                                                    3U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_7_Pos                                                    4U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_7_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG1_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_6_Pos                                                    8U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_6_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_5_Pos                                                    9U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_4_Pos                                                    10U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_3_Pos                                                    11U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_2_Pos                                                    12U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_2_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_1_Pos                                                    15U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_1_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG1_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG1_RESERVED_Pos                                                      16U
#define PCC_REG_PADMUX_AS_CFG1_RESERVED_Msk                                                      (0xFFFFUL << PCC_REG_PADMUX_AS_CFG1_RESERVED_Pos)

/* 0x368    0x4000_0368
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG2_TYPE;

/*0x4000_0368 PCC_REG_PADMUX_AS_CFG2*/
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG2_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG2_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG2_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG2_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG2_RESERVED_Pos)

/* 0x36C    0x4000_036c
    0       R/W     RESERVED_11                                     1'b0
    1       R/W     RESERVED_10                                     1'b0
    2       R/W     RESERVED_9                                      1'b0
    3       R/W     RESERVED_8                                      1'b0
    7:4     R/W     RESERVED_7                                      4'd0
    8       R/W     RESERVED_6                                      1'b0
    9       R/W     RESERVED_5                                      1'b0
    10      R/W     RESERVED_4                                      1'b0
    11      R/W     RESERVED_3                                      1'b0
    14:12   R/W     RESERVED_2                                      3'd0
    15      R/W     RESERVED_1                                      1'b0
    31:16   R/W     RESERVED                                        16'd0
 */
typedef union _PCC_REG_PADMUX_AS_CFG3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 4;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 3;
        uint32_t RESERVED_1: 1;
        uint32_t RESERVED: 16;
    };
} PCC_REG_PADMUX_AS_CFG3_TYPE;

/*0x4000_036c PCC_REG_PADMUX_AS_CFG3*/
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_11_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_10_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_9_Pos                                                    2U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_8_Pos                                                    3U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_7_Pos                                                    4U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_7_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG3_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_6_Pos                                                    8U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_6_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_5_Pos                                                    9U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_4_Pos                                                    10U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_3_Pos                                                    11U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_2_Pos                                                    12U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_2_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_1_Pos                                                    15U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_1_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG3_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG3_RESERVED_Pos                                                      16U
#define PCC_REG_PADMUX_AS_CFG3_RESERVED_Msk                                                      (0xFFFFUL << PCC_REG_PADMUX_AS_CFG3_RESERVED_Pos)

/* 0x370    0x4000_0370
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG4_TYPE;

/*0x4000_0370 PCC_REG_PADMUX_AS_CFG4*/
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG4_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG4_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG4_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG4_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG4_RESERVED_Pos)

/* 0x374    0x4000_0374
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG5_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG5_TYPE;

/*0x4000_0374 PCC_REG_PADMUX_AS_CFG5*/
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG5_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG5_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG5_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG5_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG5_RESERVED_Pos)

/* 0x378    0x4000_0378
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG6_TYPE;

/*0x4000_0378 PCC_REG_PADMUX_AS_CFG6*/
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG6_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG6_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG6_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG6_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG6_RESERVED_Pos)

/* 0x37C    0x4000_037c
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG7_TYPE;

/*0x4000_037c PCC_REG_PADMUX_AS_CFG7*/
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG7_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG7_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG7_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG7_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG7_RESERVED_Pos)

/* 0x380    0x4000_0380
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG8_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG8_TYPE;

/*0x4000_0380 PCC_REG_PADMUX_AS_CFG8*/
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG8_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG8_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG8_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG8_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG8_RESERVED_Pos)

/* 0x384    0x4000_0384
    0       R/W     RESERVED_21                                     1'b0
    1       R/W     RESERVED_20                                     1'b0
    2       R/W     RESERVED_19                                     1'b0
    3       R/W     RESERVED_18                                     1'b0
    7:4     R/W     RESERVED_17                                     4'd0
    8       R/W     RESERVED_16                                     1'b0
    9       R/W     RESERVED_15                                     1'b0
    10      R/W     RESERVED_14                                     1'b0
    11      R/W     RESERVED_13                                     1'b0
    14:12   R/W     RESERVED_12                                     3'd0
    15      R/W     RESERVED_11                                     1'b0
    16      R/W     RESERVED_10                                     1'b0
    17      R/W     RESERVED_9                                      1'b0
    18      R/W     RESERVED_8                                      1'b0
    19      R/W     RESERVED_7                                      1'b0
    23:20   R/W     RESERVED_6                                      4'd0
    24      R/W     RESERVED_5                                      1'b0
    25      R/W     RESERVED_4                                      1'b0
    26      R/W     RESERVED_3                                      1'b0
    27      R/W     RESERVED_2                                      1'b0
    30:28   R/W     RESERVED_1                                      3'd0
    31      R/W     RESERVED                                        1'b0
 */
typedef union _PCC_REG_PADMUX_AS_CFG9_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED_21: 1;
        uint32_t RESERVED_20: 1;
        uint32_t RESERVED_19: 1;
        uint32_t RESERVED_18: 1;
        uint32_t RESERVED_17: 4;
        uint32_t RESERVED_16: 1;
        uint32_t RESERVED_15: 1;
        uint32_t RESERVED_14: 1;
        uint32_t RESERVED_13: 1;
        uint32_t RESERVED_12: 3;
        uint32_t RESERVED_11: 1;
        uint32_t RESERVED_10: 1;
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 4;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 3;
        uint32_t RESERVED: 1;
    };
} PCC_REG_PADMUX_AS_CFG9_TYPE;

/*0x4000_0384 PCC_REG_PADMUX_AS_CFG9*/
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_21_Pos                                                   0U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_21_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_21_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_20_Pos                                                   1U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_20_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_20_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_19_Pos                                                   2U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_19_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_19_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_18_Pos                                                   3U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_18_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_18_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_17_Pos                                                   4U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_17_Msk                                                   (0xFUL << PCC_REG_PADMUX_AS_CFG9_RESERVED_17_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_16_Pos                                                   8U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_16_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_16_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_15_Pos                                                   9U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_15_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_15_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_14_Pos                                                   10U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_14_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_14_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_13_Pos                                                   11U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_13_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_13_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_12_Pos                                                   12U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_12_Msk                                                   (0x7UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_12_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_11_Pos                                                   15U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_11_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_11_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_10_Pos                                                   16U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_10_Msk                                                   (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_10_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_9_Pos                                                    17U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_9_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_9_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_8_Pos                                                    18U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_8_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_8_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_7_Pos                                                    19U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_7_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_7_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_6_Pos                                                    20U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_6_Msk                                                    (0xFUL << PCC_REG_PADMUX_AS_CFG9_RESERVED_6_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_5_Pos                                                    24U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_5_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_5_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_4_Pos                                                    25U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_4_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_4_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_3_Pos                                                    26U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_3_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_3_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_2_Pos                                                    27U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_2_Msk                                                    (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_2_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_1_Pos                                                    28U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_1_Msk                                                    (0x7UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_1_Pos)

#define PCC_REG_PADMUX_AS_CFG9_RESERVED_Pos                                                      31U
#define PCC_REG_PADMUX_AS_CFG9_RESERVED_Msk                                                      (0x1UL << PCC_REG_PADMUX_AS_CFG9_RESERVED_Pos)

/* 0x388    0x4000_0388
    0       R       I2C0_BUS_QCH_BUSY_FLAG1                         1'b0
    1       R       I2C0_QCH_BUSY_FLAG1                             1'b0
    2       R       GPIO_DBNC_QCH_BUSY_FLAG1                        1'b0
    3       R       GPIO_BUS_QCH_BUSY_FLAG1                         1'b0
    4       R       GPIO_QCH_BUSY_FLAG1                             1'b0
    5       R       GDMA_BUS_QCH_BUSY_FLAG1                         1'b0
    6       R       ETIMER_PCLK_QCH_BUSY_FLAG1                      1'b0
    7       R       ETIMER_PWM_QCH_BUSY_FLAG1                       1'b0
    8       R       ETIMER_BUS_QCH_BUSY_FLAG1                       1'b0
    9       R       ETIMER_QCH_BUSY_FLAG1                           1'b0
    10      R       EFLASH_BUS_QCH_BUSY_FLAG1                       1'b0
    11      R       EFLASH_QCH_BUSY_FLAG1                           1'b0
    12      R       CPU_BUS_QCH_BUSY_FLAG1                          1'b0
    13      R       CAN_LP_QCH_BUSY_FLAG1                           1'b0
    14      R       CAN_BUS_QCH_BUSY_FLAG1                          1'b0
    15      R       CAN_PWR_QCH_BUSY_FLAG1                          1'b0
    16      R       CAN_QCH_BUSY_FLAG1                              1'b0
    17      R       AES_QCH_BUSY_FLAG1                              1'b0
    31:18   R       RESERVED                                        14'd0
 */
typedef union _PCC_REG_PADMUX_AS_CFG10_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t I2C0_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t I2C0_QCH_BUSY_FLAG1: 1;
        uint32_t GPIO_DBNC_QCH_BUSY_FLAG1: 1;
        uint32_t GPIO_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t GPIO_QCH_BUSY_FLAG1: 1;
        uint32_t GDMA_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t ETIMER_PCLK_QCH_BUSY_FLAG1: 1;
        uint32_t ETIMER_PWM_QCH_BUSY_FLAG1: 1;
        uint32_t ETIMER_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t ETIMER_QCH_BUSY_FLAG1: 1;
        uint32_t EFLASH_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t EFLASH_QCH_BUSY_FLAG1: 1;
        uint32_t CPU_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAN_LP_QCH_BUSY_FLAG1: 1;
        uint32_t CAN_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAN_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t CAN_QCH_BUSY_FLAG1: 1;
        uint32_t AES_QCH_BUSY_FLAG1: 1;
        uint32_t RESERVED: 14;
    };
} PCC_REG_PADMUX_AS_CFG10_TYPE;

/*0x4000_0388 PCC_REG_PADMUX_AS_CFG10*/
#define PCC_REG_PADMUX_AS_CFG10_I2C0_BUS_QCH_BUSY_FLAG1_Pos                                      0U
#define PCC_REG_PADMUX_AS_CFG10_I2C0_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_PADMUX_AS_CFG10_I2C0_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_I2C0_QCH_BUSY_FLAG1_Pos                                          1U
#define PCC_REG_PADMUX_AS_CFG10_I2C0_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_PADMUX_AS_CFG10_I2C0_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_GPIO_DBNC_QCH_BUSY_FLAG1_Pos                                     2U
#define PCC_REG_PADMUX_AS_CFG10_GPIO_DBNC_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_PADMUX_AS_CFG10_GPIO_DBNC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_GPIO_BUS_QCH_BUSY_FLAG1_Pos                                      3U
#define PCC_REG_PADMUX_AS_CFG10_GPIO_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_PADMUX_AS_CFG10_GPIO_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_GPIO_QCH_BUSY_FLAG1_Pos                                          4U
#define PCC_REG_PADMUX_AS_CFG10_GPIO_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_PADMUX_AS_CFG10_GPIO_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_GDMA_BUS_QCH_BUSY_FLAG1_Pos                                      5U
#define PCC_REG_PADMUX_AS_CFG10_GDMA_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_PADMUX_AS_CFG10_GDMA_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_ETIMER_PCLK_QCH_BUSY_FLAG1_Pos                                   6U
#define PCC_REG_PADMUX_AS_CFG10_ETIMER_PCLK_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_PADMUX_AS_CFG10_ETIMER_PCLK_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_ETIMER_PWM_QCH_BUSY_FLAG1_Pos                                    7U
#define PCC_REG_PADMUX_AS_CFG10_ETIMER_PWM_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_PADMUX_AS_CFG10_ETIMER_PWM_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_ETIMER_BUS_QCH_BUSY_FLAG1_Pos                                    8U
#define PCC_REG_PADMUX_AS_CFG10_ETIMER_BUS_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_PADMUX_AS_CFG10_ETIMER_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_ETIMER_QCH_BUSY_FLAG1_Pos                                        9U
#define PCC_REG_PADMUX_AS_CFG10_ETIMER_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_PADMUX_AS_CFG10_ETIMER_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_EFLASH_BUS_QCH_BUSY_FLAG1_Pos                                    10U
#define PCC_REG_PADMUX_AS_CFG10_EFLASH_BUS_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_PADMUX_AS_CFG10_EFLASH_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_EFLASH_QCH_BUSY_FLAG1_Pos                                        11U
#define PCC_REG_PADMUX_AS_CFG10_EFLASH_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_PADMUX_AS_CFG10_EFLASH_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_CPU_BUS_QCH_BUSY_FLAG1_Pos                                       12U
#define PCC_REG_PADMUX_AS_CFG10_CPU_BUS_QCH_BUSY_FLAG1_Msk                                       (0x1UL << PCC_REG_PADMUX_AS_CFG10_CPU_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_CAN_LP_QCH_BUSY_FLAG1_Pos                                        13U
#define PCC_REG_PADMUX_AS_CFG10_CAN_LP_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_PADMUX_AS_CFG10_CAN_LP_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_CAN_BUS_QCH_BUSY_FLAG1_Pos                                       14U
#define PCC_REG_PADMUX_AS_CFG10_CAN_BUS_QCH_BUSY_FLAG1_Msk                                       (0x1UL << PCC_REG_PADMUX_AS_CFG10_CAN_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_CAN_PWR_QCH_BUSY_FLAG1_Pos                                       15U
#define PCC_REG_PADMUX_AS_CFG10_CAN_PWR_QCH_BUSY_FLAG1_Msk                                       (0x1UL << PCC_REG_PADMUX_AS_CFG10_CAN_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_CAN_QCH_BUSY_FLAG1_Pos                                           16U
#define PCC_REG_PADMUX_AS_CFG10_CAN_QCH_BUSY_FLAG1_Msk                                           (0x1UL << PCC_REG_PADMUX_AS_CFG10_CAN_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_AES_QCH_BUSY_FLAG1_Pos                                           17U
#define PCC_REG_PADMUX_AS_CFG10_AES_QCH_BUSY_FLAG1_Msk                                           (0x1UL << PCC_REG_PADMUX_AS_CFG10_AES_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_PADMUX_AS_CFG10_RESERVED_Pos                                                     18U
#define PCC_REG_PADMUX_AS_CFG10_RESERVED_Msk                                                     (0x3FFFUL << PCC_REG_PADMUX_AS_CFG10_RESERVED_Pos)

/* 0x38C    0x4000_038c
    0       R       TIMER3_QCH_BUSY_FLAG1                           1'b0
    1       R       TIMER2_QCH_BUSY_FLAG1                           1'b0
    2       R       TIMER1_PCLK_QCH_BUSY_FLAG1                      1'b0
    3       R       TIMER1_BUS_QCH_BUSY_FLAG1                       1'b0
    4       R       TIMER1_QCH_BUSY_FLAG1                           1'b0
    5       R       SPIC0_QCH_BUSY_FLAG1                            1'b0
    6       R       SPI3W_BUS_QCH_BUSY_FLAG1                        1'b0
    7       R       SPI3W_QCH_BUSY_FLAG1                            1'b0
    8       R       SPI2_PWR_QCH_BUSY_FLAG1                         1'b0
    9       R       SPI2_BUS_QCH_BUSY_FLAG1                         1'b0
    10      R       SPI2_QCH_BUSY_FLAG1                             1'b0
    11      R       SPI1_HS_BUS_QCH_BUSY_FLAG1                      1'b0
    12      R       SPI1_PWR_QCH_BUSY_FLAG1                         1'b0
    13      R       SPI1_BUS_QCH_BUSY_FLAG1                         1'b0
    14      R       SPI1_QCH_BUSY_FLAG1                             1'b0
    15      R       SPI0_HS_BUS_QCH_BUSY_FLAG1                      1'b0
    16      R       SPI0_PWR_QCH_BUSY_FLAG1                         1'b0
    17      R       SPI0_BUS_QCH_BUSY_FLAG1                         1'b0
    18      R       SPI0_QCH_BUSY_FLAG1                             1'b0
    19      R       SHA256_BUS_QCH_BUSY_FLAG1                       1'b0
    20      R       RNG_BUS_QCH_BUSY_FLAG1                          1'b0
    21      R       RNG_QCH_BUSY_FLAG1                              1'b0
    22      R       RXI300_QCH_BUSY_FLAG1                           1'b0
    23      R       KEYSCAN_BUS_QCH_BUSY_FLAG1                      1'b0
    24      R       KEYSCAN_QCH_BUSY_FLAG1                          1'b0
    25      R       IRRC_PWR_QCH_BUSY_FLAG1                         1'b0
    26      R       IRRC_BUS_QCH_BUSY_FLAG1                         1'b0
    27      R       IRRC_QCH_BUSY_FLAG1                             1'b0
    28      R       I2C1_PWR_QCH_BUSY_FLAG1                         1'b0
    29      R       I2C1_BUS_QCH_BUSY_FLAG1                         1'b0
    30      R       I2C1_QCH_BUSY_FLAG1                             1'b0
    31      R       I2C0_PWR_QCH_BUSY_FLAG1                         1'b0
 */
typedef union _PCC_REG_QCH_BUSY_FLAG1_PROC1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TIMER3_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER2_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER1_PCLK_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER1_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER1_QCH_BUSY_FLAG1: 1;
        uint32_t SPIC0_QCH_BUSY_FLAG1: 1;
        uint32_t SPI3W_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI3W_QCH_BUSY_FLAG1: 1;
        uint32_t SPI2_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t SPI2_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI2_QCH_BUSY_FLAG1: 1;
        uint32_t SPI1_HS_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI1_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t SPI1_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI1_QCH_BUSY_FLAG1: 1;
        uint32_t SPI0_HS_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI0_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t SPI0_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPI0_QCH_BUSY_FLAG1: 1;
        uint32_t SHA256_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t RNG_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t RNG_QCH_BUSY_FLAG1: 1;
        uint32_t RXI300_QCH_BUSY_FLAG1: 1;
        uint32_t KEYSCAN_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t KEYSCAN_QCH_BUSY_FLAG1: 1;
        uint32_t IRRC_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t IRRC_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t IRRC_QCH_BUSY_FLAG1: 1;
        uint32_t I2C1_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t I2C1_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t I2C1_QCH_BUSY_FLAG1: 1;
        uint32_t I2C0_PWR_QCH_BUSY_FLAG1: 1;
    };
} PCC_REG_QCH_BUSY_FLAG1_PROC1_TYPE;

/*0x4000_038c PCC_REG_QCH_BUSY_FLAG1_PROC1*/
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER3_QCH_BUSY_FLAG1_Pos                                   0U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER3_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER3_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER2_QCH_BUSY_FLAG1_Pos                                   1U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER2_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER2_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG1_Pos                              2U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_BUS_QCH_BUSY_FLAG1_Pos                               3U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_BUS_QCH_BUSY_FLAG1_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_QCH_BUSY_FLAG1_Pos                                   4U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_TIMER1_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPIC0_QCH_BUSY_FLAG1_Pos                                    5U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPIC0_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPIC0_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_BUS_QCH_BUSY_FLAG1_Pos                                6U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_BUS_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_QCH_BUSY_FLAG1_Pos                                    7U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI3W_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_PWR_QCH_BUSY_FLAG1_Pos                                 8U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_BUS_QCH_BUSY_FLAG1_Pos                                 9U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_QCH_BUSY_FLAG1_Pos                                     10U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI2_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG1_Pos                              11U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_PWR_QCH_BUSY_FLAG1_Pos                                 12U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_BUS_QCH_BUSY_FLAG1_Pos                                 13U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_QCH_BUSY_FLAG1_Pos                                     14U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI1_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG1_Pos                              15U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_PWR_QCH_BUSY_FLAG1_Pos                                 16U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_BUS_QCH_BUSY_FLAG1_Pos                                 17U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_QCH_BUSY_FLAG1_Pos                                     18U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SPI0_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SHA256_BUS_QCH_BUSY_FLAG1_Pos                               19U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_SHA256_BUS_QCH_BUSY_FLAG1_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_SHA256_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_BUS_QCH_BUSY_FLAG1_Pos                                  20U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_BUS_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_QCH_BUSY_FLAG1_Pos                                      21U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_RNG_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RXI300_QCH_BUSY_FLAG1_Pos                                   22U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_RXI300_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_RXI300_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG1_Pos                              23U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_QCH_BUSY_FLAG1_Pos                                  24U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_KEYSCAN_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_PWR_QCH_BUSY_FLAG1_Pos                                 25U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_BUS_QCH_BUSY_FLAG1_Pos                                 26U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_QCH_BUSY_FLAG1_Pos                                     27U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_IRRC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_PWR_QCH_BUSY_FLAG1_Pos                                 28U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_BUS_QCH_BUSY_FLAG1_Pos                                 29U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_QCH_BUSY_FLAG1_Pos                                     30U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C1_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C0_PWR_QCH_BUSY_FLAG1_Pos                                 31U
#define PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C0_PWR_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC1_I2C0_PWR_QCH_BUSY_FLAG1_Pos)

/* 0x390    0x4000_0390
    0       R       USB_PWR_QCH_BUSY_FLAG1                          1'b0
    1       R       USB_BUS_QCH_BUSY_FLAG1                          1'b0
    2       R       USB_QCH_BUSY_FLAG1                              1'b0
    3       R       PCSM_VCORE_OP1_QCH_BUSY_FLAG1                   1'b0
    4       R       VDREG_QCH_BUSY_FLAG1                            1'b0
    5       R       UART3_PWR_QCH_BUSY_FLAG1                        1'b0
    6       R       UART3_BUS_QCH_BUSY_FLAG1                        1'b0
    7       R       UART3_QCH_BUSY_FLAG1                            1'b0
    8       R       UART2_PWR_QCH_BUSY_FLAG1                        1'b0
    9       R       UART2_BUS_QCH_BUSY_FLAG1                        1'b0
    10      R       UART2_QCH_BUSY_FLAG1                            1'b0
    11      R       UART1_PWR_QCH_BUSY_FLAG1                        1'b0
    12      R       UART1_BUS_QCH_BUSY_FLAG1                        1'b0
    13      R       UART1_QCH_BUSY_FLAG1                            1'b0
    14      R       UART0_PWR_QCH_BUSY_FLAG1                        1'b0
    15      R       UART0_BUS_QCH_BUSY_FLAG1                        1'b0
    16      R       UART0_QCH_BUSY_FLAG1                            1'b0
    17      R       TMETER_BUS_QCH_BUSY_FLAG1                       1'b0
    18      R       TMETER_QCH_BUSY_FLAG1                           1'b0
    19      R       TIMER11_PWM_QCH_BUSY_FLAG1                      1'b0
    20      R       TIMER11_QCH_BUSY_FLAG1                          1'b0
    21      R       TIMER10_PWM_QCH_BUSY_FLAG1                      1'b0
    22      R       TIMER10_QCH_BUSY_FLAG1                          1'b0
    23      R       TIMER9_PCLK_QCH_BUSY_FLAG1                      1'b0
    24      R       TIMER9_PWM_QCH_BUSY_FLAG1                       1'b0
    25      R       TIMER9_BUS_QCH_BUSY_FLAG1                       1'b0
    26      R       TIMER9_QCH_BUSY_FLAG1                           1'b0
    27      R       TIMER8_QCH_BUSY_FLAG1                           1'b0
    28      R       TIMER7_QCH_BUSY_FLAG1                           1'b0
    29      R       TIMER6_QCH_BUSY_FLAG1                           1'b0
    30      R       TIMER5_QCH_BUSY_FLAG1                           1'b0
    31      R       TIMER4_QCH_BUSY_FLAG1                           1'b0
 */
typedef union _PCC_REG_QCH_BUSY_FLAG1_PROC2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t USB_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t USB_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t USB_QCH_BUSY_FLAG1: 1;
        uint32_t PCSM_VCORE_OP1_QCH_BUSY_FLAG1: 1;
        uint32_t VDREG_QCH_BUSY_FLAG1: 1;
        uint32_t UART3_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t UART3_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t UART3_QCH_BUSY_FLAG1: 1;
        uint32_t UART2_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t UART2_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t UART2_QCH_BUSY_FLAG1: 1;
        uint32_t UART1_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t UART1_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t UART1_QCH_BUSY_FLAG1: 1;
        uint32_t UART0_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t UART0_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t UART0_QCH_BUSY_FLAG1: 1;
        uint32_t TMETER_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t TMETER_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER11_PWM_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER11_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER10_PWM_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER10_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER9_PCLK_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER9_PWM_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER9_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER9_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER8_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER7_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER6_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER5_QCH_BUSY_FLAG1: 1;
        uint32_t TIMER4_QCH_BUSY_FLAG1: 1;
    };
} PCC_REG_QCH_BUSY_FLAG1_PROC2_TYPE;

/*0x4000_0390 PCC_REG_QCH_BUSY_FLAG1_PROC2*/
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_PWR_QCH_BUSY_FLAG1_Pos                                  0U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_PWR_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_BUS_QCH_BUSY_FLAG1_Pos                                  1U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_BUS_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_QCH_BUSY_FLAG1_Pos                                      2U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_USB_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG1_Pos                           3U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG1_Msk                           (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_VDREG_QCH_BUSY_FLAG1_Pos                                    4U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_VDREG_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_VDREG_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_PWR_QCH_BUSY_FLAG1_Pos                                5U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_PWR_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_BUS_QCH_BUSY_FLAG1_Pos                                6U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_BUS_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_QCH_BUSY_FLAG1_Pos                                    7U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART3_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_PWR_QCH_BUSY_FLAG1_Pos                                8U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_PWR_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_BUS_QCH_BUSY_FLAG1_Pos                                9U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_BUS_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_QCH_BUSY_FLAG1_Pos                                    10U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART2_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_PWR_QCH_BUSY_FLAG1_Pos                                11U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_PWR_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_BUS_QCH_BUSY_FLAG1_Pos                                12U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_BUS_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_QCH_BUSY_FLAG1_Pos                                    13U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART1_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_PWR_QCH_BUSY_FLAG1_Pos                                14U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_PWR_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_BUS_QCH_BUSY_FLAG1_Pos                                15U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_BUS_QCH_BUSY_FLAG1_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_QCH_BUSY_FLAG1_Pos                                    16U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_QCH_BUSY_FLAG1_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_UART0_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_BUS_QCH_BUSY_FLAG1_Pos                               17U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_BUS_QCH_BUSY_FLAG1_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_QCH_BUSY_FLAG1_Pos                                   18U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TMETER_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_PWM_QCH_BUSY_FLAG1_Pos                              19U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_PWM_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_PWM_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_QCH_BUSY_FLAG1_Pos                                  20U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER11_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_PWM_QCH_BUSY_FLAG1_Pos                              21U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_PWM_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_PWM_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_QCH_BUSY_FLAG1_Pos                                  22U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER10_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG1_Pos                              23U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG1_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PWM_QCH_BUSY_FLAG1_Pos                               24U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PWM_QCH_BUSY_FLAG1_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_PWM_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_BUS_QCH_BUSY_FLAG1_Pos                               25U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_BUS_QCH_BUSY_FLAG1_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_QCH_BUSY_FLAG1_Pos                                   26U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER9_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER8_QCH_BUSY_FLAG1_Pos                                   27U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER8_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER8_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER7_QCH_BUSY_FLAG1_Pos                                   28U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER7_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER7_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER6_QCH_BUSY_FLAG1_Pos                                   29U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER6_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER6_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER5_QCH_BUSY_FLAG1_Pos                                   30U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER5_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER5_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER4_QCH_BUSY_FLAG1_Pos                                   31U
#define PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER4_QCH_BUSY_FLAG1_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PROC2_TIMER4_QCH_BUSY_FLAG1_Pos)

/* 0x394    0x4000_0394
    0       R       I2C0_BUS_QCH_BUSY_FLAG0                         1'b1
    1       R       I2C0_QCH_BUSY_FLAG0                             1'b1
    2       R       GPIO_DBNC_QCH_BUSY_FLAG0                        1'b1
    3       R       GPIO_BUS_QCH_BUSY_FLAG0                         1'b1
    4       R       GPIO_QCH_BUSY_FLAG0                             1'b1
    5       R       GDMA_BUS_QCH_BUSY_FLAG0                         1'b1
    6       R       ETIMER_PCLK_QCH_BUSY_FLAG0                      1'b1
    7       R       ETIMER_PWM_QCH_BUSY_FLAG0                       1'b1
    8       R       ETIMER_BUS_QCH_BUSY_FLAG0                       1'b1
    9       R       ETIMER_QCH_BUSY_FLAG0                           1'b1
    10      R       EFLASH_BUS_QCH_BUSY_FLAG0                       1'b1
    11      R       EFLASH_QCH_BUSY_FLAG0                           1'b1
    12      R       CPU_BUS_QCH_BUSY_FLAG0                          1'b1
    13      R       CAN_LP_QCH_BUSY_FLAG0                           1'b1
    14      R       CAN_BUS_QCH_BUSY_FLAG0                          1'b1
    15      R       CAN_PWR_QCH_BUSY_FLAG0                          1'b1
    16      R       CAN_QCH_BUSY_FLAG0                              1'b1
    17      R       AES_QCH_BUSY_FLAG0                              1'b1
    31:18   R       RESERVED                                        14'd0
 */
typedef union _PCC_REG_QCH_BUSY_FLAG0_PROC0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t I2C0_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t I2C0_QCH_BUSY_FLAG0: 1;
        uint32_t GPIO_DBNC_QCH_BUSY_FLAG0: 1;
        uint32_t GPIO_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t GPIO_QCH_BUSY_FLAG0: 1;
        uint32_t GDMA_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t ETIMER_PCLK_QCH_BUSY_FLAG0: 1;
        uint32_t ETIMER_PWM_QCH_BUSY_FLAG0: 1;
        uint32_t ETIMER_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t ETIMER_QCH_BUSY_FLAG0: 1;
        uint32_t EFLASH_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t EFLASH_QCH_BUSY_FLAG0: 1;
        uint32_t CPU_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAN_LP_QCH_BUSY_FLAG0: 1;
        uint32_t CAN_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAN_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t CAN_QCH_BUSY_FLAG0: 1;
        uint32_t AES_QCH_BUSY_FLAG0: 1;
        uint32_t RESERVED: 14;
    };
} PCC_REG_QCH_BUSY_FLAG0_PROC0_TYPE;

/*0x4000_0394 PCC_REG_QCH_BUSY_FLAG0_PROC0*/
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_BUS_QCH_BUSY_FLAG0_Pos                                 0U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_QCH_BUSY_FLAG0_Pos                                     1U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_I2C0_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_DBNC_QCH_BUSY_FLAG0_Pos                                2U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_DBNC_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_DBNC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_BUS_QCH_BUSY_FLAG0_Pos                                 3U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_QCH_BUSY_FLAG0_Pos                                     4U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_GPIO_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GDMA_BUS_QCH_BUSY_FLAG0_Pos                                 5U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_GDMA_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_GDMA_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PCLK_QCH_BUSY_FLAG0_Pos                              6U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PCLK_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PCLK_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PWM_QCH_BUSY_FLAG0_Pos                               7U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PWM_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_PWM_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_BUS_QCH_BUSY_FLAG0_Pos                               8U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_QCH_BUSY_FLAG0_Pos                                   9U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_ETIMER_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_BUS_QCH_BUSY_FLAG0_Pos                               10U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_QCH_BUSY_FLAG0_Pos                                   11U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_EFLASH_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CPU_BUS_QCH_BUSY_FLAG0_Pos                                  12U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CPU_BUS_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_CPU_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_LP_QCH_BUSY_FLAG0_Pos                                   13U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_LP_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_LP_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_BUS_QCH_BUSY_FLAG0_Pos                                  14U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_BUS_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_PWR_QCH_BUSY_FLAG0_Pos                                  15U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_PWR_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_QCH_BUSY_FLAG0_Pos                                      16U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_CAN_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_AES_QCH_BUSY_FLAG0_Pos                                      17U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_AES_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC0_AES_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC0_RESERVED_Pos                                                18U
#define PCC_REG_QCH_BUSY_FLAG0_PROC0_RESERVED_Msk                                                (0x3FFFUL << PCC_REG_QCH_BUSY_FLAG0_PROC0_RESERVED_Pos)

/* 0x398    0x4000_0398
    0       R       TIMER3_QCH_BUSY_FLAG0                           1'b1
    1       R       TIMER2_QCH_BUSY_FLAG0                           1'b1
    2       R       TIMER1_PCLK_QCH_BUSY_FLAG0                      1'b1
    3       R       TIMER1_BUS_QCH_BUSY_FLAG0                       1'b1
    4       R       TIMER1_QCH_BUSY_FLAG0                           1'b1
    5       R       SPIC0_QCH_BUSY_FLAG0                            1'b1
    6       R       SPI3W_BUS_QCH_BUSY_FLAG0                        1'b1
    7       R       SPI3W_QCH_BUSY_FLAG0                            1'b1
    8       R       SPI2_PWR_QCH_BUSY_FLAG0                         1'b1
    9       R       SPI2_BUS_QCH_BUSY_FLAG0                         1'b1
    10      R       SPI2_QCH_BUSY_FLAG0                             1'b1
    11      R       SPI1_HS_BUS_QCH_BUSY_FLAG0                      1'b1
    12      R       SPI1_PWR_QCH_BUSY_FLAG0                         1'b1
    13      R       SPI1_BUS_QCH_BUSY_FLAG0                         1'b1
    14      R       SPI1_QCH_BUSY_FLAG0                             1'b1
    15      R       SPI0_HS_BUS_QCH_BUSY_FLAG0                      1'b1
    16      R       SPI0_PWR_QCH_BUSY_FLAG0                         1'b1
    17      R       SPI0_BUS_QCH_BUSY_FLAG0                         1'b1
    18      R       SPI0_QCH_BUSY_FLAG0                             1'b1
    19      R       SHA256_BUS_QCH_BUSY_FLAG0                       1'b1
    20      R       RNG_BUS_QCH_BUSY_FLAG0                          1'b1
    21      R       RNG_QCH_BUSY_FLAG0                              1'b1
    22      R       RXI300_QCH_BUSY_FLAG0                           1'b1
    23      R       KEYSCAN_BUS_QCH_BUSY_FLAG0                      1'b1
    24      R       KEYSCAN_QCH_BUSY_FLAG0                          1'b1
    25      R       IRRC_PWR_QCH_BUSY_FLAG0                         1'b1
    26      R       IRRC_BUS_QCH_BUSY_FLAG0                         1'b1
    27      R       IRRC_QCH_BUSY_FLAG0                             1'b1
    28      R       I2C1_PWR_QCH_BUSY_FLAG0                         1'b1
    29      R       I2C1_BUS_QCH_BUSY_FLAG0                         1'b1
    30      R       I2C1_QCH_BUSY_FLAG0                             1'b1
    31      R       I2C0_PWR_QCH_BUSY_FLAG0                         1'b1
 */
typedef union _PCC_REG_QCH_BUSY_FLAG0_PROC1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TIMER3_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER2_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER1_PCLK_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER1_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER1_QCH_BUSY_FLAG0: 1;
        uint32_t SPIC0_QCH_BUSY_FLAG0: 1;
        uint32_t SPI3W_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI3W_QCH_BUSY_FLAG0: 1;
        uint32_t SPI2_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t SPI2_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI2_QCH_BUSY_FLAG0: 1;
        uint32_t SPI1_HS_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI1_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t SPI1_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI1_QCH_BUSY_FLAG0: 1;
        uint32_t SPI0_HS_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI0_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t SPI0_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPI0_QCH_BUSY_FLAG0: 1;
        uint32_t SHA256_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t RNG_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t RNG_QCH_BUSY_FLAG0: 1;
        uint32_t RXI300_QCH_BUSY_FLAG0: 1;
        uint32_t KEYSCAN_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t KEYSCAN_QCH_BUSY_FLAG0: 1;
        uint32_t IRRC_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t IRRC_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t IRRC_QCH_BUSY_FLAG0: 1;
        uint32_t I2C1_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t I2C1_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t I2C1_QCH_BUSY_FLAG0: 1;
        uint32_t I2C0_PWR_QCH_BUSY_FLAG0: 1;
    };
} PCC_REG_QCH_BUSY_FLAG0_PROC1_TYPE;

/*0x4000_0398 PCC_REG_QCH_BUSY_FLAG0_PROC1*/
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER3_QCH_BUSY_FLAG0_Pos                                   0U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER3_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER3_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER2_QCH_BUSY_FLAG0_Pos                                   1U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER2_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER2_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG0_Pos                              2U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_PCLK_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_BUS_QCH_BUSY_FLAG0_Pos                               3U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_QCH_BUSY_FLAG0_Pos                                   4U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_TIMER1_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPIC0_QCH_BUSY_FLAG0_Pos                                    5U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPIC0_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPIC0_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_BUS_QCH_BUSY_FLAG0_Pos                                6U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_BUS_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_QCH_BUSY_FLAG0_Pos                                    7U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI3W_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_PWR_QCH_BUSY_FLAG0_Pos                                 8U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_BUS_QCH_BUSY_FLAG0_Pos                                 9U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_QCH_BUSY_FLAG0_Pos                                     10U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI2_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG0_Pos                              11U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_HS_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_PWR_QCH_BUSY_FLAG0_Pos                                 12U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_BUS_QCH_BUSY_FLAG0_Pos                                 13U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_QCH_BUSY_FLAG0_Pos                                     14U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI1_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG0_Pos                              15U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_HS_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_PWR_QCH_BUSY_FLAG0_Pos                                 16U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_BUS_QCH_BUSY_FLAG0_Pos                                 17U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_QCH_BUSY_FLAG0_Pos                                     18U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SPI0_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SHA256_BUS_QCH_BUSY_FLAG0_Pos                               19U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_SHA256_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_SHA256_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_BUS_QCH_BUSY_FLAG0_Pos                                  20U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_BUS_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_QCH_BUSY_FLAG0_Pos                                      21U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_RNG_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RXI300_QCH_BUSY_FLAG0_Pos                                   22U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_RXI300_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_RXI300_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG0_Pos                              23U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_QCH_BUSY_FLAG0_Pos                                  24U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_KEYSCAN_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_PWR_QCH_BUSY_FLAG0_Pos                                 25U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_BUS_QCH_BUSY_FLAG0_Pos                                 26U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_QCH_BUSY_FLAG0_Pos                                     27U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_IRRC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_PWR_QCH_BUSY_FLAG0_Pos                                 28U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_BUS_QCH_BUSY_FLAG0_Pos                                 29U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_QCH_BUSY_FLAG0_Pos                                     30U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C1_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C0_PWR_QCH_BUSY_FLAG0_Pos                                 31U
#define PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C0_PWR_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC1_I2C0_PWR_QCH_BUSY_FLAG0_Pos)

/* 0x39C    0x4000_039c
    0       R       USB_PWR_QCH_BUSY_FLAG0                          1'b1
    1       R       USB_BUS_QCH_BUSY_FLAG0                          1'b1
    2       R       USB_QCH_BUSY_FLAG0                              1'b1
    3       R       PCSM_VCORE_OP1_QCH_BUSY_FLAG0                   1'b1
    4       R       VDREG_QCH_BUSY_FLAG0                            1'b1
    5       R       UART3_PWR_QCH_BUSY_FLAG0                        1'b1
    6       R       UART3_BUS_QCH_BUSY_FLAG0                        1'b1
    7       R       UART3_QCH_BUSY_FLAG0                            1'b1
    8       R       UART2_PWR_QCH_BUSY_FLAG0                        1'b1
    9       R       UART2_BUS_QCH_BUSY_FLAG0                        1'b1
    10      R       UART2_QCH_BUSY_FLAG0                            1'b1
    11      R       UART1_PWR_QCH_BUSY_FLAG0                        1'b1
    12      R       UART1_BUS_QCH_BUSY_FLAG0                        1'b1
    13      R       UART1_QCH_BUSY_FLAG0                            1'b1
    14      R       UART0_PWR_QCH_BUSY_FLAG0                        1'b1
    15      R       UART0_BUS_QCH_BUSY_FLAG0                        1'b1
    16      R       UART0_QCH_BUSY_FLAG0                            1'b1
    17      R       TMETER_BUS_QCH_BUSY_FLAG0                       1'b1
    18      R       TMETER_QCH_BUSY_FLAG0                           1'b1
    19      R       TIMER11_PWM_QCH_BUSY_FLAG0                      1'b1
    20      R       TIMER11_QCH_BUSY_FLAG0                          1'b1
    21      R       TIMER10_PWM_QCH_BUSY_FLAG0                      1'b1
    22      R       TIMER10_QCH_BUSY_FLAG0                          1'b1
    23      R       TIMER9_PCLK_QCH_BUSY_FLAG0                      1'b1
    24      R       TIMER9_PWM_QCH_BUSY_FLAG0                       1'b1
    25      R       TIMER9_BUS_QCH_BUSY_FLAG0                       1'b1
    26      R       TIMER9_QCH_BUSY_FLAG0                           1'b1
    27      R       TIMER8_QCH_BUSY_FLAG0                           1'b1
    28      R       TIMER7_QCH_BUSY_FLAG0                           1'b1
    29      R       TIMER6_QCH_BUSY_FLAG0                           1'b1
    30      R       TIMER5_QCH_BUSY_FLAG0                           1'b1
    31      R       TIMER4_QCH_BUSY_FLAG0                           1'b1
 */
typedef union _PCC_REG_QCH_BUSY_FLAG0_PROC2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t USB_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t USB_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t USB_QCH_BUSY_FLAG0: 1;
        uint32_t PCSM_VCORE_OP1_QCH_BUSY_FLAG0: 1;
        uint32_t VDREG_QCH_BUSY_FLAG0: 1;
        uint32_t UART3_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t UART3_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t UART3_QCH_BUSY_FLAG0: 1;
        uint32_t UART2_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t UART2_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t UART2_QCH_BUSY_FLAG0: 1;
        uint32_t UART1_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t UART1_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t UART1_QCH_BUSY_FLAG0: 1;
        uint32_t UART0_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t UART0_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t UART0_QCH_BUSY_FLAG0: 1;
        uint32_t TMETER_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t TMETER_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER11_PWM_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER11_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER10_PWM_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER10_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER9_PCLK_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER9_PWM_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER9_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER9_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER8_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER7_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER6_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER5_QCH_BUSY_FLAG0: 1;
        uint32_t TIMER4_QCH_BUSY_FLAG0: 1;
    };
} PCC_REG_QCH_BUSY_FLAG0_PROC2_TYPE;

/*0x4000_039c PCC_REG_QCH_BUSY_FLAG0_PROC2*/
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_PWR_QCH_BUSY_FLAG0_Pos                                  0U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_PWR_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_BUS_QCH_BUSY_FLAG0_Pos                                  1U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_BUS_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_QCH_BUSY_FLAG0_Pos                                      2U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_USB_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG0_Pos                           3U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG0_Msk                           (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_PCSM_VCORE_OP1_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_VDREG_QCH_BUSY_FLAG0_Pos                                    4U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_VDREG_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_VDREG_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_PWR_QCH_BUSY_FLAG0_Pos                                5U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_PWR_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_BUS_QCH_BUSY_FLAG0_Pos                                6U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_BUS_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_QCH_BUSY_FLAG0_Pos                                    7U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART3_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_PWR_QCH_BUSY_FLAG0_Pos                                8U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_PWR_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_BUS_QCH_BUSY_FLAG0_Pos                                9U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_BUS_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_QCH_BUSY_FLAG0_Pos                                    10U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART2_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_PWR_QCH_BUSY_FLAG0_Pos                                11U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_PWR_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_BUS_QCH_BUSY_FLAG0_Pos                                12U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_BUS_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_QCH_BUSY_FLAG0_Pos                                    13U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART1_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_PWR_QCH_BUSY_FLAG0_Pos                                14U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_PWR_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_BUS_QCH_BUSY_FLAG0_Pos                                15U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_BUS_QCH_BUSY_FLAG0_Msk                                (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_QCH_BUSY_FLAG0_Pos                                    16U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_QCH_BUSY_FLAG0_Msk                                    (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_UART0_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_BUS_QCH_BUSY_FLAG0_Pos                               17U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_QCH_BUSY_FLAG0_Pos                                   18U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TMETER_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_PWM_QCH_BUSY_FLAG0_Pos                              19U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_PWM_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_PWM_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_QCH_BUSY_FLAG0_Pos                                  20U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER11_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_PWM_QCH_BUSY_FLAG0_Pos                              21U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_PWM_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_PWM_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_QCH_BUSY_FLAG0_Pos                                  22U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER10_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG0_Pos                              23U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG0_Msk                              (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PCLK_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PWM_QCH_BUSY_FLAG0_Pos                               24U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PWM_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_PWM_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_BUS_QCH_BUSY_FLAG0_Pos                               25U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_BUS_QCH_BUSY_FLAG0_Msk                               (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_QCH_BUSY_FLAG0_Pos                                   26U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER9_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER8_QCH_BUSY_FLAG0_Pos                                   27U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER8_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER8_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER7_QCH_BUSY_FLAG0_Pos                                   28U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER7_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER7_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER6_QCH_BUSY_FLAG0_Pos                                   29U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER6_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER6_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER5_QCH_BUSY_FLAG0_Pos                                   30U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER5_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER5_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER4_QCH_BUSY_FLAG0_Pos                                   31U
#define PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER4_QCH_BUSY_FLAG0_Msk                                   (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PROC2_TIMER4_QCH_BUSY_FLAG0_Pos)

/* 0x3A0    0x4000_03a0
    0       R       SPORT_BUS_QCH_BUSY_FLAG1                        1'b0
    1       R       SPORT_QCH_BUSY_FLAG1                            1'b0
    2       R       RFC_QCH_BUSY_FLAG1                              1'b0
    3       R       PRO24G_QCH_BUSY_FLAG1                           1'b0
    4       R       PCC_BUS_QCH_BUSY_FLAG1                          1'b0
    5       R       MODEM_BUS_QCH_BUSY_FLAG1                        1'b0
    6       R       MODEM_QCH_BUSY_FLAG1                            1'b0
    7       R       CAL80M_OSC_QCH_BUSY_FLAG1                       1'b0
    8       R       CAL80M_BUS_QCH_BUSY_FLAG1                       1'b0
    9       R       CAL80M_QCH_BUSY_FLAG1                           1'b0
    10      R       CAL32K_AON_BUS_QCH_BUSY_FLAG1                   1'b0
    11      R       CAL32K_AON_QCH_BUSY_FLAG1                       1'b0
    12      R       CAL32K_QCH_BUSY_FLAG1                           1'b0
    13      R       CAL10M_OSC_BUS_QCH_BUSY_FLAG1                   1'b0
    14      R       CAL10M_BUS_QCH_BUSY_FLAG1                       1'b0
    15      R       CAL10M_QCH_BUSY_FLAG1                           1'b0
    16      R       BTMAC_BUS_QCH_BUSY_FLAG1                        1'b0
    17      R       BTMAC_QCH_BUSY_FLAG1                            1'b0
    18      R       BT_VEN_BUS_QCH_BUSY_FLAG1                       1'b0
    19      R       AUDIO_BUS_BUS_QCH_BUSY_FLAG1                    1'b0
    20      R       AUDIO_QCH_BUSY_FLAG1                            1'b0
    21      R       ADC_PWR_QCH_BUSY_FLAG1                          1'b0
    22      R       ADC_BUS_QCH_BUSY_FLAG1                          1'b0
    23      R       ADC_QCH_BUSY_FLAG1                              1'b0
    24      R       AACK_QCH_BUSY_FLAG1                             1'b0
    31:25   R       RESERVED                                        7'd0
 */
typedef union _PCC_REG_QCH_BUSY_FLAG1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t SPORT_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t SPORT_QCH_BUSY_FLAG1: 1;
        uint32_t RFC_QCH_BUSY_FLAG1: 1;
        uint32_t PRO24G_QCH_BUSY_FLAG1: 1;
        uint32_t PCC_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t MODEM_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t MODEM_QCH_BUSY_FLAG1: 1;
        uint32_t CAL80M_OSC_QCH_BUSY_FLAG1: 1;
        uint32_t CAL80M_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAL80M_QCH_BUSY_FLAG1: 1;
        uint32_t CAL32K_AON_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAL32K_AON_QCH_BUSY_FLAG1: 1;
        uint32_t CAL32K_QCH_BUSY_FLAG1: 1;
        uint32_t CAL10M_OSC_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAL10M_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t CAL10M_QCH_BUSY_FLAG1: 1;
        uint32_t BTMAC_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t BTMAC_QCH_BUSY_FLAG1: 1;
        uint32_t BT_VEN_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t AUDIO_BUS_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t AUDIO_QCH_BUSY_FLAG1: 1;
        uint32_t ADC_PWR_QCH_BUSY_FLAG1: 1;
        uint32_t ADC_BUS_QCH_BUSY_FLAG1: 1;
        uint32_t ADC_QCH_BUSY_FLAG1: 1;
        uint32_t AACK_QCH_BUSY_FLAG1: 1;
        uint32_t RESERVED: 7;
    };
} PCC_REG_QCH_BUSY_FLAG1_TYPE;

/*0x4000_03a0 PCC_REG_QCH_BUSY_FLAG1*/
#define PCC_REG_QCH_BUSY_FLAG1_SPORT_BUS_QCH_BUSY_FLAG1_Pos                                      0U
#define PCC_REG_QCH_BUSY_FLAG1_SPORT_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG1_SPORT_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_SPORT_QCH_BUSY_FLAG1_Pos                                          1U
#define PCC_REG_QCH_BUSY_FLAG1_SPORT_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG1_SPORT_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_RFC_QCH_BUSY_FLAG1_Pos                                            2U
#define PCC_REG_QCH_BUSY_FLAG1_RFC_QCH_BUSY_FLAG1_Msk                                            (0x1UL << PCC_REG_QCH_BUSY_FLAG1_RFC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PRO24G_QCH_BUSY_FLAG1_Pos                                         3U
#define PCC_REG_QCH_BUSY_FLAG1_PRO24G_QCH_BUSY_FLAG1_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PRO24G_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_PCC_BUS_QCH_BUSY_FLAG1_Pos                                        4U
#define PCC_REG_QCH_BUSY_FLAG1_PCC_BUS_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG1_PCC_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_MODEM_BUS_QCH_BUSY_FLAG1_Pos                                      5U
#define PCC_REG_QCH_BUSY_FLAG1_MODEM_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG1_MODEM_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_MODEM_QCH_BUSY_FLAG1_Pos                                          6U
#define PCC_REG_QCH_BUSY_FLAG1_MODEM_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG1_MODEM_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_OSC_QCH_BUSY_FLAG1_Pos                                     7U
#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_OSC_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL80M_OSC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_BUS_QCH_BUSY_FLAG1_Pos                                     8U
#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_BUS_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL80M_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_QCH_BUSY_FLAG1_Pos                                         9U
#define PCC_REG_QCH_BUSY_FLAG1_CAL80M_QCH_BUSY_FLAG1_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL80M_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_BUS_QCH_BUSY_FLAG1_Pos                                 10U
#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_QCH_BUSY_FLAG1_Pos                                     11U
#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL32K_AON_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_QCH_BUSY_FLAG1_Pos                                         12U
#define PCC_REG_QCH_BUSY_FLAG1_CAL32K_QCH_BUSY_FLAG1_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL32K_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_OSC_BUS_QCH_BUSY_FLAG1_Pos                                 13U
#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_OSC_BUS_QCH_BUSY_FLAG1_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL10M_OSC_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_BUS_QCH_BUSY_FLAG1_Pos                                     14U
#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_BUS_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL10M_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_QCH_BUSY_FLAG1_Pos                                         15U
#define PCC_REG_QCH_BUSY_FLAG1_CAL10M_QCH_BUSY_FLAG1_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG1_CAL10M_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_BTMAC_BUS_QCH_BUSY_FLAG1_Pos                                      16U
#define PCC_REG_QCH_BUSY_FLAG1_BTMAC_BUS_QCH_BUSY_FLAG1_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG1_BTMAC_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_BTMAC_QCH_BUSY_FLAG1_Pos                                          17U
#define PCC_REG_QCH_BUSY_FLAG1_BTMAC_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG1_BTMAC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_BT_VEN_BUS_QCH_BUSY_FLAG1_Pos                                     18U
#define PCC_REG_QCH_BUSY_FLAG1_BT_VEN_BUS_QCH_BUSY_FLAG1_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG1_BT_VEN_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_AUDIO_BUS_BUS_QCH_BUSY_FLAG1_Pos                                  19U
#define PCC_REG_QCH_BUSY_FLAG1_AUDIO_BUS_BUS_QCH_BUSY_FLAG1_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG1_AUDIO_BUS_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_AUDIO_QCH_BUSY_FLAG1_Pos                                          20U
#define PCC_REG_QCH_BUSY_FLAG1_AUDIO_QCH_BUSY_FLAG1_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG1_AUDIO_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_ADC_PWR_QCH_BUSY_FLAG1_Pos                                        21U
#define PCC_REG_QCH_BUSY_FLAG1_ADC_PWR_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG1_ADC_PWR_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_ADC_BUS_QCH_BUSY_FLAG1_Pos                                        22U
#define PCC_REG_QCH_BUSY_FLAG1_ADC_BUS_QCH_BUSY_FLAG1_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG1_ADC_BUS_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_ADC_QCH_BUSY_FLAG1_Pos                                            23U
#define PCC_REG_QCH_BUSY_FLAG1_ADC_QCH_BUSY_FLAG1_Msk                                            (0x1UL << PCC_REG_QCH_BUSY_FLAG1_ADC_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_AACK_QCH_BUSY_FLAG1_Pos                                           24U
#define PCC_REG_QCH_BUSY_FLAG1_AACK_QCH_BUSY_FLAG1_Msk                                           (0x1UL << PCC_REG_QCH_BUSY_FLAG1_AACK_QCH_BUSY_FLAG1_Pos)

#define PCC_REG_QCH_BUSY_FLAG1_RESERVED_Pos                                                      25U
#define PCC_REG_QCH_BUSY_FLAG1_RESERVED_Msk                                                      (0x7FUL << PCC_REG_QCH_BUSY_FLAG1_RESERVED_Pos)

/* 0x3A4    0x4000_03a4
    0       R       SPORT_BUS_QCH_BUSY_FLAG0                        1'b1
    1       R       SPORT_QCH_BUSY_FLAG0                            1'b1
    2       R       RFC_QCH_BUSY_FLAG0                              1'b1
    3       R       PRO24G_QCH_BUSY_FLAG0                           1'b1
    4       R       PCC_BUS_QCH_BUSY_FLAG0                          1'b1
    5       R       MODEM_BUS_QCH_BUSY_FLAG0                        1'b1
    6       R       MODEM_QCH_BUSY_FLAG0                            1'b1
    7       R       CAL80M_OSC_QCH_BUSY_FLAG0                       1'b1
    8       R       CAL80M_BUS_QCH_BUSY_FLAG0                       1'b1
    9       R       CAL80M_QCH_BUSY_FLAG0                           1'b1
    10      R       CAL32K_AON_BUS_QCH_BUSY_FLAG0                   1'b1
    11      R       CAL32K_AON_QCH_BUSY_FLAG0                       1'b1
    12      R       CAL32K_QCH_BUSY_FLAG0                           1'b1
    13      R       CAL10M_OSC_BUS_QCH_BUSY_FLAG0                   1'b1
    14      R       CAL10M_BUS_QCH_BUSY_FLAG0                       1'b1
    15      R       CAL10M_QCH_BUSY_FLAG0                           1'b1
    16      R       BTMAC_BUS_QCH_BUSY_FLAG0                        1'b1
    17      R       BTMAC_QCH_BUSY_FLAG0                            1'b1
    18      R       BT_VEN_BUS_QCH_BUSY_FLAG0                       1'b1
    19      R       AUDIO_BUS_BUS_QCH_BUSY_FLAG0                    1'b1
    20      R       AUDIO_QCH_BUSY_FLAG0                            1'b1
    21      R       ADC_PWR_QCH_BUSY_FLAG0                          1'b1
    22      R       ADC_BUS_QCH_BUSY_FLAG0                          1'b1
    23      R       ADC_QCH_BUSY_FLAG0                              1'b1
    24      R       AACK_QCH_BUSY_FLAG0                             1'b1
    30:25   R       RESERVED                                        6'd0
    31      R/W1C   DBG_QCH_BUSY_FLAG_W1C                           1'b0
 */
typedef union _PCC_REG_QCH_BUSY_FLAG0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t SPORT_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t SPORT_QCH_BUSY_FLAG0: 1;
        uint32_t RFC_QCH_BUSY_FLAG0: 1;
        uint32_t PRO24G_QCH_BUSY_FLAG0: 1;
        uint32_t PCC_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t MODEM_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t MODEM_QCH_BUSY_FLAG0: 1;
        uint32_t CAL80M_OSC_QCH_BUSY_FLAG0: 1;
        uint32_t CAL80M_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAL80M_QCH_BUSY_FLAG0: 1;
        uint32_t CAL32K_AON_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAL32K_AON_QCH_BUSY_FLAG0: 1;
        uint32_t CAL32K_QCH_BUSY_FLAG0: 1;
        uint32_t CAL10M_OSC_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAL10M_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t CAL10M_QCH_BUSY_FLAG0: 1;
        uint32_t BTMAC_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t BTMAC_QCH_BUSY_FLAG0: 1;
        uint32_t BT_VEN_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t AUDIO_BUS_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t AUDIO_QCH_BUSY_FLAG0: 1;
        uint32_t ADC_PWR_QCH_BUSY_FLAG0: 1;
        uint32_t ADC_BUS_QCH_BUSY_FLAG0: 1;
        uint32_t ADC_QCH_BUSY_FLAG0: 1;
        uint32_t AACK_QCH_BUSY_FLAG0: 1;
        uint32_t RESERVED: 6;
        uint32_t DBG_QCH_BUSY_FLAG_W1C: 1;
    };
} PCC_REG_QCH_BUSY_FLAG0_TYPE;

/*0x4000_03a4 PCC_REG_QCH_BUSY_FLAG0*/
#define PCC_REG_QCH_BUSY_FLAG0_SPORT_BUS_QCH_BUSY_FLAG0_Pos                                      0U
#define PCC_REG_QCH_BUSY_FLAG0_SPORT_BUS_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_SPORT_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_SPORT_QCH_BUSY_FLAG0_Pos                                          1U
#define PCC_REG_QCH_BUSY_FLAG0_SPORT_QCH_BUSY_FLAG0_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG0_SPORT_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_RFC_QCH_BUSY_FLAG0_Pos                                            2U
#define PCC_REG_QCH_BUSY_FLAG0_RFC_QCH_BUSY_FLAG0_Msk                                            (0x1UL << PCC_REG_QCH_BUSY_FLAG0_RFC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PRO24G_QCH_BUSY_FLAG0_Pos                                         3U
#define PCC_REG_QCH_BUSY_FLAG0_PRO24G_QCH_BUSY_FLAG0_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PRO24G_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_PCC_BUS_QCH_BUSY_FLAG0_Pos                                        4U
#define PCC_REG_QCH_BUSY_FLAG0_PCC_BUS_QCH_BUSY_FLAG0_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG0_PCC_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_MODEM_BUS_QCH_BUSY_FLAG0_Pos                                      5U
#define PCC_REG_QCH_BUSY_FLAG0_MODEM_BUS_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_MODEM_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_MODEM_QCH_BUSY_FLAG0_Pos                                          6U
#define PCC_REG_QCH_BUSY_FLAG0_MODEM_QCH_BUSY_FLAG0_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG0_MODEM_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_OSC_QCH_BUSY_FLAG0_Pos                                     7U
#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_OSC_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL80M_OSC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_BUS_QCH_BUSY_FLAG0_Pos                                     8U
#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_BUS_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL80M_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_QCH_BUSY_FLAG0_Pos                                         9U
#define PCC_REG_QCH_BUSY_FLAG0_CAL80M_QCH_BUSY_FLAG0_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL80M_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_BUS_QCH_BUSY_FLAG0_Pos                                 10U
#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_QCH_BUSY_FLAG0_Pos                                     11U
#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL32K_AON_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_QCH_BUSY_FLAG0_Pos                                         12U
#define PCC_REG_QCH_BUSY_FLAG0_CAL32K_QCH_BUSY_FLAG0_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL32K_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_OSC_BUS_QCH_BUSY_FLAG0_Pos                                 13U
#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_OSC_BUS_QCH_BUSY_FLAG0_Msk                                 (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL10M_OSC_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_BUS_QCH_BUSY_FLAG0_Pos                                     14U
#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_BUS_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL10M_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_QCH_BUSY_FLAG0_Pos                                         15U
#define PCC_REG_QCH_BUSY_FLAG0_CAL10M_QCH_BUSY_FLAG0_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG0_CAL10M_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_BTMAC_BUS_QCH_BUSY_FLAG0_Pos                                      16U
#define PCC_REG_QCH_BUSY_FLAG0_BTMAC_BUS_QCH_BUSY_FLAG0_Msk                                      (0x1UL << PCC_REG_QCH_BUSY_FLAG0_BTMAC_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_BTMAC_QCH_BUSY_FLAG0_Pos                                          17U
#define PCC_REG_QCH_BUSY_FLAG0_BTMAC_QCH_BUSY_FLAG0_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG0_BTMAC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_BT_VEN_BUS_QCH_BUSY_FLAG0_Pos                                     18U
#define PCC_REG_QCH_BUSY_FLAG0_BT_VEN_BUS_QCH_BUSY_FLAG0_Msk                                     (0x1UL << PCC_REG_QCH_BUSY_FLAG0_BT_VEN_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_AUDIO_BUS_BUS_QCH_BUSY_FLAG0_Pos                                  19U
#define PCC_REG_QCH_BUSY_FLAG0_AUDIO_BUS_BUS_QCH_BUSY_FLAG0_Msk                                  (0x1UL << PCC_REG_QCH_BUSY_FLAG0_AUDIO_BUS_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_AUDIO_QCH_BUSY_FLAG0_Pos                                          20U
#define PCC_REG_QCH_BUSY_FLAG0_AUDIO_QCH_BUSY_FLAG0_Msk                                          (0x1UL << PCC_REG_QCH_BUSY_FLAG0_AUDIO_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_ADC_PWR_QCH_BUSY_FLAG0_Pos                                        21U
#define PCC_REG_QCH_BUSY_FLAG0_ADC_PWR_QCH_BUSY_FLAG0_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG0_ADC_PWR_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_ADC_BUS_QCH_BUSY_FLAG0_Pos                                        22U
#define PCC_REG_QCH_BUSY_FLAG0_ADC_BUS_QCH_BUSY_FLAG0_Msk                                        (0x1UL << PCC_REG_QCH_BUSY_FLAG0_ADC_BUS_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_ADC_QCH_BUSY_FLAG0_Pos                                            23U
#define PCC_REG_QCH_BUSY_FLAG0_ADC_QCH_BUSY_FLAG0_Msk                                            (0x1UL << PCC_REG_QCH_BUSY_FLAG0_ADC_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_AACK_QCH_BUSY_FLAG0_Pos                                           24U
#define PCC_REG_QCH_BUSY_FLAG0_AACK_QCH_BUSY_FLAG0_Msk                                           (0x1UL << PCC_REG_QCH_BUSY_FLAG0_AACK_QCH_BUSY_FLAG0_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_RESERVED_Pos                                                      25U
#define PCC_REG_QCH_BUSY_FLAG0_RESERVED_Msk                                                      (0x3FUL << PCC_REG_QCH_BUSY_FLAG0_RESERVED_Pos)

#define PCC_REG_QCH_BUSY_FLAG0_DBG_QCH_BUSY_FLAG_W1C_Pos                                         31U
#define PCC_REG_QCH_BUSY_FLAG0_DBG_QCH_BUSY_FLAG_W1C_Msk                                         (0x1UL << PCC_REG_QCH_BUSY_FLAG0_DBG_QCH_BUSY_FLAG_W1C_Pos)

/* 0x3A8    0x4000_03a8
    0       R/W     R_PDN09                                         1'b0
    1       R/W     UA33PC_EN                                       1'b0
    2       R/W     RSVD_2                                          1'b0
    3       R/W     POW_MBIAS                                       1'b0
    4       R/W     RSVD_1                                          1'b0
    5       R/W     ISO_LV_0                                        1'b1
    6       R/W     POW_BC_L                                        1'b0
    7       R/W     UA33PC_BC_EN                                    1'b0
    8       R/W     ISO_UA2USB                                      1'b0
    9       R/W     USB_BUS_CLK_EN                                  1'b0
    10      R/W     REG_FORCE_DP                                    1'b0
    11      R/W     REG_DP_MODE                                     1'b0
    12      R/W     REG_LDOPW                                       1'b0
    13      R/W     RES1M_EN_L                                      1'b0
    31:14   R/W     RSVD                                            18'b0
 */
typedef union _PCC_REG_USB_POW_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_PDN09: 1;
        uint32_t UA33PC_EN: 1;
        uint32_t RSVD_2: 1;
        uint32_t POW_MBIAS: 1;
        uint32_t RSVD_1: 1;
        uint32_t ISO_LV_0: 1;
        uint32_t POW_BC_L: 1;
        uint32_t UA33PC_BC_EN: 1;
        uint32_t ISO_UA2USB: 1;
        uint32_t USB_BUS_CLK_EN: 1;
        uint32_t REG_FORCE_DP: 1;
        uint32_t REG_DP_MODE: 1;
        uint32_t REG_LDOPW: 1;
        uint32_t RES1M_EN_L: 1;
        uint32_t RSVD: 18;
    };
} PCC_REG_USB_POW_TYPE;

/*0x4000_03a8 PCC_REG_USB_POW*/
#define PCC_REG_USB_POW_R_PDN09_Pos                                                              0U
#define PCC_REG_USB_POW_R_PDN09_Msk                                                              (0x1UL << PCC_REG_USB_POW_R_PDN09_Pos)

#define PCC_REG_USB_POW_UA33PC_EN_Pos                                                            1U
#define PCC_REG_USB_POW_UA33PC_EN_Msk                                                            (0x1UL << PCC_REG_USB_POW_UA33PC_EN_Pos)

#define PCC_REG_USB_POW_RSVD_2_Pos                                                               2U
#define PCC_REG_USB_POW_RSVD_2_Msk                                                               (0x1UL << PCC_REG_USB_POW_RSVD_2_Pos)

#define PCC_REG_USB_POW_POW_MBIAS_Pos                                                            3U
#define PCC_REG_USB_POW_POW_MBIAS_Msk                                                            (0x1UL << PCC_REG_USB_POW_POW_MBIAS_Pos)

#define PCC_REG_USB_POW_RSVD_1_Pos                                                               4U
#define PCC_REG_USB_POW_RSVD_1_Msk                                                               (0x1UL << PCC_REG_USB_POW_RSVD_1_Pos)

#define PCC_REG_USB_POW_ISO_LV_0_Pos                                                             5U
#define PCC_REG_USB_POW_ISO_LV_0_Msk                                                             (0x1UL << PCC_REG_USB_POW_ISO_LV_0_Pos)

#define PCC_REG_USB_POW_POW_BC_L_Pos                                                             6U
#define PCC_REG_USB_POW_POW_BC_L_Msk                                                             (0x1UL << PCC_REG_USB_POW_POW_BC_L_Pos)

#define PCC_REG_USB_POW_UA33PC_BC_EN_Pos                                                         7U
#define PCC_REG_USB_POW_UA33PC_BC_EN_Msk                                                         (0x1UL << PCC_REG_USB_POW_UA33PC_BC_EN_Pos)

#define PCC_REG_USB_POW_ISO_UA2USB_Pos                                                           8U
#define PCC_REG_USB_POW_ISO_UA2USB_Msk                                                           (0x1UL << PCC_REG_USB_POW_ISO_UA2USB_Pos)

#define PCC_REG_USB_POW_USB_BUS_CLK_EN_Pos                                                       9U
#define PCC_REG_USB_POW_USB_BUS_CLK_EN_Msk                                                       (0x1UL << PCC_REG_USB_POW_USB_BUS_CLK_EN_Pos)

#define PCC_REG_USB_POW_REG_FORCE_DP_Pos                                                         10U
#define PCC_REG_USB_POW_REG_FORCE_DP_Msk                                                         (0x1UL << PCC_REG_USB_POW_REG_FORCE_DP_Pos)

#define PCC_REG_USB_POW_REG_DP_MODE_Pos                                                          11U
#define PCC_REG_USB_POW_REG_DP_MODE_Msk                                                          (0x1UL << PCC_REG_USB_POW_REG_DP_MODE_Pos)

#define PCC_REG_USB_POW_REG_LDOPW_Pos                                                            12U
#define PCC_REG_USB_POW_REG_LDOPW_Msk                                                            (0x1UL << PCC_REG_USB_POW_REG_LDOPW_Pos)

#define PCC_REG_USB_POW_RES1M_EN_L_Pos                                                           13U
#define PCC_REG_USB_POW_RES1M_EN_L_Msk                                                           (0x1UL << PCC_REG_USB_POW_RES1M_EN_L_Pos)

#define PCC_REG_USB_POW_RSVD_Pos                                                                 14U
#define PCC_REG_USB_POW_RSVD_Msk                                                                 (0x3FFFFUL << PCC_REG_USB_POW_RSVD_Pos)

/* 0x3AC    0x4000_03ac
    31:0    R       RSVD                                            32'd0
 */
typedef union _PCC_REG_DUMMY_3AC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PCC_REG_DUMMY_3AC_TYPE;

/*0x4000_03ac PCC_REG_DUMMY_3AC*/
#define PCC_REG_DUMMY_3AC_RSVD_Pos                                                               0U
#define PCC_REG_DUMMY_3AC_RSVD_Msk                                                               (0xFFFFFFFFUL << PCC_REG_DUMMY_3AC_RSVD_Pos)

/* 0x3B0    0x4000_03b0
    31:0    R       RSVD                                            32'd0
 */
typedef union _PCC_REG_DUMMY_3B0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PCC_REG_DUMMY_3B0_TYPE;

/*0x4000_03b0 PCC_REG_DUMMY_3B0*/
#define PCC_REG_DUMMY_3B0_RSVD_Pos                                                               0U
#define PCC_REG_DUMMY_3B0_RSVD_Msk                                                               (0xFFFFFFFFUL << PCC_REG_DUMMY_3B0_RSVD_Pos)

/* 0x3B4    0x4000_03b4
    31:0    R       RSVD                                            32'd0
 */
typedef union _PCC_REG_DUMMY_3B4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PCC_REG_DUMMY_3B4_TYPE;

/*0x4000_03b4 PCC_REG_DUMMY_3B4*/
#define PCC_REG_DUMMY_3B4_RSVD_Pos                                                               0U
#define PCC_REG_DUMMY_3B4_RSVD_Msk                                                               (0xFFFFFFFFUL << PCC_REG_DUMMY_3B4_RSVD_Pos)

/* 0x3B8    0x4000_03b8
    31:0    R       DEBUG_PCK_VCORE                                 32'd0
 */
typedef union _PCC_REG_DBG_MUX_PCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DEBUG_PCK_VCORE;
    };
} PCC_REG_DBG_MUX_PCK_TYPE;

/*0x4000_03b8 PCC_REG_DBG_MUX_PCK*/
#define PCC_REG_DBG_MUX_PCK_DEBUG_PCK_VCORE_Pos                                                  0U
#define PCC_REG_DBG_MUX_PCK_DEBUG_PCK_VCORE_Msk                                                  (0xFFFFFFFFUL << PCC_REG_DBG_MUX_PCK_DEBUG_PCK_VCORE_Pos)

/* 0x3BC    0x4000_03bc
    2:0     R/W     R_DBG_MUX_GRP_SEL0                              3'd0
    3       R       RSVD_7                                          1'd0
    6:4     R/W     R_DBG_MUX_GRP_SEL1                              3'd0
    7       R       RSVD_6                                          1'd0
    10:8    R/W     R_DBG_MUX_GRP_SEL2                              3'd0
    11      R       RSVD_5                                          1'd0
    14:12   R/W     R_DBG_MUX_GRP_SEL3                              3'd0
    15      R       RSVD_4                                          1'd0
    18:16   R/W     R_DBG_MUX_GRP_SEL4                              3'd0
    19      R       RSVD_3                                          1'd0
    22:20   R/W     R_DBG_MUX_GRP_SEL5                              3'd0
    23      R       RSVD_2                                          1'd0
    26:24   R/W     R_DBG_MUX_GRP_SEL6                              3'd0
    27      R       RSVD_1                                          1'd0
    30:28   R/W     R_DBG_MUX_GRP_SEL7                              3'd0
    31      R       RSVD                                            1'd0
 */
typedef union _PCC_REG_DBG_MUX_GRP_CFG0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_DBG_MUX_GRP_SEL0: 3;
        uint32_t RSVD_7: 1;
        uint32_t R_DBG_MUX_GRP_SEL1: 3;
        uint32_t RSVD_6: 1;
        uint32_t R_DBG_MUX_GRP_SEL2: 3;
        uint32_t RSVD_5: 1;
        uint32_t R_DBG_MUX_GRP_SEL3: 3;
        uint32_t RSVD_4: 1;
        uint32_t R_DBG_MUX_GRP_SEL4: 3;
        uint32_t RSVD_3: 1;
        uint32_t R_DBG_MUX_GRP_SEL5: 3;
        uint32_t RSVD_2: 1;
        uint32_t R_DBG_MUX_GRP_SEL6: 3;
        uint32_t RSVD_1: 1;
        uint32_t R_DBG_MUX_GRP_SEL7: 3;
        uint32_t RSVD: 1;
    };
} PCC_REG_DBG_MUX_GRP_CFG0_TYPE;

/*0x4000_03bc PCC_REG_DBG_MUX_GRP_CFG0*/
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL0_Pos                                          0U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL0_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL0_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_7_Pos                                                      3U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_7_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_7_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL1_Pos                                          4U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL1_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL1_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_6_Pos                                                      7U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_6_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_6_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL2_Pos                                          8U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL2_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL2_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_5_Pos                                                      11U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_5_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_5_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL3_Pos                                          12U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL3_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL3_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_4_Pos                                                      15U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_4_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_4_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL4_Pos                                          16U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL4_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL4_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_3_Pos                                                      19U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_3_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_3_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL5_Pos                                          20U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL5_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL5_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_2_Pos                                                      23U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_2_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_2_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL6_Pos                                          24U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL6_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL6_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_1_Pos                                                      27U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_1_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_1_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL7_Pos                                          28U
#define PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL7_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG0_R_DBG_MUX_GRP_SEL7_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_Pos                                                        31U
#define PCC_REG_DBG_MUX_GRP_CFG0_RSVD_Msk                                                        (0x1UL << PCC_REG_DBG_MUX_GRP_CFG0_RSVD_Pos)

/* 0x3C0    0x4000_03c0
    2:0     R/W     R_DBG_MUX_GRP_SEL8                              3'd0
    3       R       RSVD_3                                          1'd0
    6:4     R/W     R_DBG_MUX_GRP_SEL9                              3'd0
    7       R       RSVD_2                                          1'd0
    10:8    R/W     R_DBG_MUX_GRP_SEL10                             3'd0
    11      R       RSVD_1                                          1'd0
    14:12   R/W     R_DBG_MUX_GRP_SEL11                             3'd0
    31:15   R       RSVD                                            1'd0
 */
typedef union _PCC_REG_DBG_MUX_GRP_CFG1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t R_DBG_MUX_GRP_SEL8: 3;
        uint32_t RSVD_3: 1;
        uint32_t R_DBG_MUX_GRP_SEL9: 3;
        uint32_t RSVD_2: 1;
        uint32_t R_DBG_MUX_GRP_SEL10: 3;
        uint32_t RSVD_1: 1;
        uint32_t R_DBG_MUX_GRP_SEL11: 3;
        uint32_t RSVD: 17;
    };
} PCC_REG_DBG_MUX_GRP_CFG1_TYPE;

/*0x4000_03c0 PCC_REG_DBG_MUX_GRP_CFG1*/
#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL8_Pos                                          0U
#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL8_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL8_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_3_Pos                                                      3U
#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_3_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG1_RSVD_3_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL9_Pos                                          4U
#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL9_Msk                                          (0x7UL << PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL9_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_2_Pos                                                      7U
#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_2_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG1_RSVD_2_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL10_Pos                                         8U
#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL10_Msk                                         (0x7UL << PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL10_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_1_Pos                                                      11U
#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_1_Msk                                                      (0x1UL << PCC_REG_DBG_MUX_GRP_CFG1_RSVD_1_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL11_Pos                                         12U
#define PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL11_Msk                                         (0x7UL << PCC_REG_DBG_MUX_GRP_CFG1_R_DBG_MUX_GRP_SEL11_Pos)

#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_Pos                                                        15U
#define PCC_REG_DBG_MUX_GRP_CFG1_RSVD_Msk                                                        (0x1FFFFUL << PCC_REG_DBG_MUX_GRP_CFG1_RSVD_Pos)


#define PCC_REG_BASE 0x40000000

#define PCC_REG_READ(Offset)\
    ((uint32_t)*((volatile uint32_t*)(PCC_REG_BASE+(Offset))))

#define PCC_REG_WRITE(Offset, Value)\
    ((*((volatile uint32_t*)(PCC_REG_BASE + (Offset)))) = (Value))

#define PCC_REG_UPDATE(Offset, Mask, Value) \
    do {\
        uint32_t temp;\
        temp = PCC_REG_READ(Offset) & ~(Mask);\
        PCC_REG_WRITE(Offset, (temp | ((Value) & (Mask))));\
    } while(0)

#define PCC_REG_READ_BITFIELD(Offset, Bitfield)                   \
    (((Offset##_TYPE)PCC_REG_READ(Offset)).Bitfield)

#define PCC_REG_WRITE_BITFIELD(Offset, Bitfield, Value)           \
    do {                                                        \
        Offset##_TYPE temp = {.d32 = PCC_REG_READ(Offset)};       \
        temp.Bitfield = Value;                                         \
        PCC_REG_WRITE(Offset, temp.d32);                          \
    } while(0)

#endif //#define PCC_REG_H
