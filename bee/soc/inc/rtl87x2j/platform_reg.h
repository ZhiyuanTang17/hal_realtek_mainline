#ifndef PLATFORM_REG_H
#define PLATFORM_REG_H
#include <stdint.h>

/* ================================================================================ */
/* ================                PLATFORM Register               ================ */
/* ===========     Reference: RL7019_SoC_Vendor_register_table_250812A.xlsx     =========== */
/* ================================================================================ */
#define PLATFORM_REG_RSVD_0000                  0x0000
#define PLATFORM_REG_LOW_PRI_INT_STATUS         0x0004
#define PLATFORM_REG_LOW_PRI_INT_MODE           0x0008
#define PLATFORM_REG_LOW_PRI_INT_EN             0x000c
#define PLATFORM_BTMACinterrupt                 0x0010
#define PLATFORM_RXIinterrupt                   0x0014
#define PLATFORM_Interruptedgeoption            0x0018
#define PLATFORM_REG_DEBUG_SEL                  0x001C
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL        0x0020
#define PLATFORM_DUMMY                          0x0024
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL         0x0028
#define PLATFORM_REG_SYSTICK_TIMER_CTRL         0x002C
#define PLATFORM_REG_SYSTICK_TIMER_CNT          0x0030
#define PLATFORM_REG_TMETER_CTRL                0x0034
#define PLATFORM_REG_TMETER_INT_STS             0x0038
#define PLATFORM_REG_CM33_NMI_INT_EN            0x003C
#define PLATFORM_REG_BIST_RSTN                  0x0040
#define PLATFORM_REG_BIST_MODE                  0x0044
#define PLATFORM_REG_DRF_BIST_MODE              0x0048
#define PLATFORM_REG_BIST_TEST_RESUME           0x004C
#define PLATFORM_REG_BIST_START_PAUSE           0x0050
#define PLATFORM_REG_BIST_DONE                  0x0054
#define PLATFORM_REG_BIST_FAIL                  0x0058
#define PLATFORM_REG_DRF_BIST_DONE              0x005C
#define PLATFORM_REG_DRF_BIST_FAIL              0x0060
#define PLATFORM_REG_MCU_ROM0_MISR0             0x0064
#define PLATFORM_REG_MCU_ROM0_MISR1             0x0068
#define PLATFORM_REG_MCU_ROM1_MISR0             0x006C
#define PLATFORM_REG_MCU_ROM1_MISR1             0x0070
#define PLATFORM_REG_MCU_ROM2_MISR0             0x0074
#define PLATFORM_REG_MCU_ROM2_MISR1             0x0078
#define PLATFORM_REG_MCU_ROM3_MISR0             0x007C
#define PLATFORM_REG_MCU_ROM3_MISR1             0x0080
#define PLATFORM_REG_MCU_ROM4_MISR0             0x0084
#define PLATFORM_REG_MCU_ROM4_MISR1             0x0088
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA0      0x0090
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA1      0x0094
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA0       0x0098
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA1       0x009C
#define PLATFORM_REG_I2C_MAILBOX_CTRL           0x00A0
#define PLATFORM_WIC_HANDSHAKE                  0x00A4
#define PLATFORM_WKUP_REASON_CORE               0x00A8
#define PLATFORM_Reserved                       0x00AC
#define PLATFORM_Reserved_1                     0x00B0
#define PLATFORM_Reserved_2                     0x00B4
#define PLATFORM_REG_SNPS_SRAM_CTRL             0x00B8
#define PLATFORM_Reserved_3                     0x00BC
#define PLATFORM_Reserved_4                     0x00C0
#define PLATFORM_Reserved_5                     0x00C4
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL       0x00C8
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL        0x00CC
#define PLATFORM_REG_MBISR_SRAM_RESULT          0x00D0
#define PLATFORM_REG_DYN_READ_EN                0x00D4
#define PLATFORM_REG_BIST_LOOP_MODE             0x00D8
#define PLATFORM_REG_BT_BIST_LOOP_MODE          0x00DC
#define PLATFORM_REG_BT_BIST_RSTN               0x00E0
#define PLATFORM_REG_BT_BIST_MODE               0x00E4
#define PLATFORM_REG_BT_DRF_BIST_MODE           0x00E8
#define PLATFORM_REG_BT_BIST_TEST_RESUME        0x00EC
#define PLATFORM_REG_BT_BIST_START_PAUSE        0x00F0
#define PLATFORM_REG_BT_BIST_DONE               0x00F4
#define PLATFORM_REG_BT_BIST_FAIL               0x00F8
#define PLATFORM_REG_BT_DRF_BIST_DONE           0x00FC
#define PLATFORM_REG_BT_DRF_BIST_FAIL           0x0100
#define PLATFORM_Reserved_6                     0x0130
#define PLATFORM_Reserved_7                     0x0134
#define PLATFORM_REG_WDT_CTL                    0x01E0
#define PLATFORM_REG_WDT_KICK                   0x01E4
#define PLATFORM_REG_WDT_CURRENT                0x01E8
#define PLATFORM_REG_WDT_VER                    0x01EC
#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL        0x01F0
#define PLATFORM_RNGControlRegister             0x0200
#define PLATFORM_Reserved_8                     0x0204
#define PLATFORM_Reserved_9                     0x0208
#define PLATFORM_Reserved_10                    0x020C
#define PLATFORM_Reserved_11                    0x0210
#define PLATFORM_Reserved_12                    0x0214
#define PLATFORM_Reserved_13                    0x0218
#define PLATFORM_RNG_return0                    0x021C
#define PLATFORM_RNG_return1                    0x0220
#define PLATFORM_RNG_return2                    0x0224
#define PLATFORM_RNG_result                     0x0228
#define PLATFORM_RNG_lfsr_poly_lsb              0x022C
#define PLATFORM_RNG_lfsr_poly_msb              0x0230
#define PLATFORM_Reserved_14                    0x0234
#define PLATFORM_RNG_POWER                      0x0238
#define PLATFORM_RNG_st                         0x023C
#define PLATFORM_RNG_st_return                  0x0240
#define PLATFORM_Reserved_15                    0x0244
#define PLATFORM_Reserved_16                    0x0248
#define PLATFORM_Reserved_17                    0x024C
#define PLATFORM_Reserved_18                    0x0250
#define PLATFORM_RNGinterrupt                   0x0254
#define PLATFORM_Reserved_19                    0x0258
#define PLATFORM_Reserved_20                    0x025C
#define PLATFORM_RNG_st_thr_err                 0x0260
#define PLATFORM_RNGinterruptenable             0x0264
#define PLATFORM_SPIC0PGMfifointerrtup0         0x02cc
#define PLATFORM_SPIC0PGMfifointerrtup1         0x02d0
#define PLATFORM_SPIC0PGMfifointerrtup2         0x02d4
#define PLATFORM_SPIC0PGMfifointerrtup3         0x02d8
#define PLATFORM_SPIC0PGMfifointerrtup4         0x02dc
#define PLATFORM_SPIC0PGMfifointerrtup5         0x02e0
#define PLATFORM_SPIC0PGMfifointerrtup6         0x02e4
#define PLATFORM_SPIC0PGMfifointerrtup7         0x02e8
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS     0x02ec
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS      0x02f0
#define PLATFORM_REG_TIMER1_EVNT_STS            0x02f4
#define PLATFORM_REG_TIMER1_TASK_STS            0x02f8
#define PLATFORM_REG_GPIO_0_EVNT_STS            0x02fc
#define PLATFORM_REG_GPIO_1_EVENT_STS           0x0300
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS      0x0314
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS      0x0318
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS      0x031c
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS      0x0320
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS   0x0324
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS   0x0328
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS        0x0344
#define PLATFORM_REG_I2C0_TASK_EVNT_STS         0x0348
#define PLATFORM_REG_I2C1_TASK_EVNT_STS         0x034c
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS       0x0350
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS     0x0354
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS     0x0358
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS      0x035c
#define PLATFORM_REG_TMETER_TASK_EVNT_STS       0x0364
#define PLATFORM_REG_DMA_TASK_EVNT_STS          0x0368
#define PLATFORM_REG_SDMK_TASK_EVNT_STS         0x036C
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS   0x0370
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS   0x0374

/* 0x0000   0x4000_6000
    31:0    R       RESERVED                                            32'h0
 */
typedef union _PLATFORM_REG_RSVD_0000_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PLATFORM_REG_RSVD_0000_TYPE;

/*0x4000_6000 PLATFORM_REG_RSVD_0000*/
#define PLATFORM_REG_RSVD_0000_RESERVED_Pos                                                                  0U
#define PLATFORM_REG_RSVD_0000_RESERVED_Msk                                                                  (0xFFFFFFFFUL << PLATFORM_REG_RSVD_0000_RESERVED_Pos)

/* 0x0004   0x4000_6004
    0       R       RESERVED_15                                         0
    1       R       RESERVED_14                                         0
    2       R       RESERVED_13                                         0
    3       R       RESERVED_12                                         0
    4       R       RESERVED_11                                         0
    5       R       RESERVED_10                                         0
    6       R       RESERVED_9                                          0
    7       R       RESERVED_8                                          0
    8       R       RESERVED_7                                          0
    9       R       RESERVED_6                                          0
    10      R       RESERVED_5                                          0
    11      R       RESERVED_4                                          0
    12      R       RESERVED_3                                          0
    13      R       RESERVED_2                                          0
    14      R       RESERVED_1                                          0
    15      R/W1C   utmi_resume_intr                                    0
    31:16   R       RESERVED                                            15'h0
 */
typedef union _PLATFORM_REG_LOW_PRI_INT_STATUS_TYPE
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
        uint32_t RESERVED_9: 1;
        uint32_t RESERVED_8: 1;
        uint32_t RESERVED_7: 1;
        uint32_t RESERVED_6: 1;
        uint32_t RESERVED_5: 1;
        uint32_t RESERVED_4: 1;
        uint32_t RESERVED_3: 1;
        uint32_t RESERVED_2: 1;
        uint32_t RESERVED_1: 1;
        uint32_t utmi_resume_intr: 1;
        uint32_t RESERVED: 16;
    };
} PLATFORM_REG_LOW_PRI_INT_STATUS_TYPE;

/*0x4000_6004 PLATFORM_REG_LOW_PRI_INT_STATUS*/
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_15_Pos                                                      0U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_15_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_15_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_14_Pos                                                      1U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_14_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_14_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_13_Pos                                                      2U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_13_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_13_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_12_Pos                                                      3U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_12_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_12_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_11_Pos                                                      4U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_11_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_11_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_10_Pos                                                      5U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_10_Msk                                                      (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_10_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_9_Pos                                                       6U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_9_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_9_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_8_Pos                                                       7U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_8_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_8_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_7_Pos                                                       8U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_7_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_7_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_6_Pos                                                       9U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_6_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_6_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_5_Pos                                                       10U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_5_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_5_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_4_Pos                                                       11U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_4_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_4_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_3_Pos                                                       12U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_3_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_3_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_2_Pos                                                       13U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_2_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_2_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_1_Pos                                                       14U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_1_Msk                                                       (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_1_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_utmi_resume_intr_Pos                                                 15U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_utmi_resume_intr_Msk                                                 (0x1UL << PLATFORM_REG_LOW_PRI_INT_STATUS_utmi_resume_intr_Pos)

#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_Pos                                                         16U
#define PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_Msk                                                         (0xFFFFUL << PLATFORM_REG_LOW_PRI_INT_STATUS_RESERVED_Pos)

/* 0x0008   0x4000_6008
    15:0    R/W     BIT_LOW_PRI_INT_MODE                                16'hFFFF
    31:16   R       RSVD                                                16'h0
 */
typedef union _PLATFORM_REG_LOW_PRI_INT_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BIT_LOW_PRI_INT_MODE: 16;
        uint32_t RSVD: 16;
    };
} PLATFORM_REG_LOW_PRI_INT_MODE_TYPE;

/*0x4000_6008 PLATFORM_REG_LOW_PRI_INT_MODE*/
#define PLATFORM_REG_LOW_PRI_INT_MODE_BIT_LOW_PRI_INT_MODE_Pos                                               0U
#define PLATFORM_REG_LOW_PRI_INT_MODE_BIT_LOW_PRI_INT_MODE_Msk                                               (0xFFFFUL << PLATFORM_REG_LOW_PRI_INT_MODE_BIT_LOW_PRI_INT_MODE_Pos)

#define PLATFORM_REG_LOW_PRI_INT_MODE_RSVD_Pos                                                               16U
#define PLATFORM_REG_LOW_PRI_INT_MODE_RSVD_Msk                                                               (0xFFFFUL << PLATFORM_REG_LOW_PRI_INT_MODE_RSVD_Pos)

/* 0x000c   0x4000_600c
    15:0    R/W     BIT_LOW_PRI_INT_EN                                  16'h0
    31:16   R       RSVD                                                16'h0
 */
typedef union _PLATFORM_REG_LOW_PRI_INT_EN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BIT_LOW_PRI_INT_EN: 16;
        uint32_t RSVD: 16;
    };
} PLATFORM_REG_LOW_PRI_INT_EN_TYPE;

/*0x4000_600c PLATFORM_REG_LOW_PRI_INT_EN*/
#define PLATFORM_REG_LOW_PRI_INT_EN_BIT_LOW_PRI_INT_EN_Pos                                                   0U
#define PLATFORM_REG_LOW_PRI_INT_EN_BIT_LOW_PRI_INT_EN_Msk                                                   (0xFFFFUL << PLATFORM_REG_LOW_PRI_INT_EN_BIT_LOW_PRI_INT_EN_Pos)

#define PLATFORM_REG_LOW_PRI_INT_EN_RSVD_Pos                                                                 16U
#define PLATFORM_REG_LOW_PRI_INT_EN_RSVD_Msk                                                                 (0xFFFFUL << PLATFORM_REG_LOW_PRI_INT_EN_RSVD_Pos)

/* 0x0010   0x4000_6010
    0       R       timer_intr1andtimer_intr0                           0
    1       R       bluewiz_intr_r                                      0
    2       R       hci_dma_intr                                        0
    3       R       btverdor_reg_intr                                   0
    4       R       pro_intr_r                                          0
    31:5    R       RSVD                                                27'h0
 */
typedef union _PLATFORM_BTMACinterrupt_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t timer_intr1andtimer_intr0: 1;
        uint32_t bluewiz_intr_r: 1;
        uint32_t hci_dma_intr: 1;
        uint32_t btverdor_reg_intr: 1;
        uint32_t pro_intr_r: 1;
        uint32_t RSVD: 27;
    };
} PLATFORM_BTMACinterrupt_TYPE;

/*0x4000_6010 PLATFORM_BTMACinterrupt*/
#define PLATFORM_BTMACinterrupt_timer_intr1andtimer_intr0_Pos                                                0U
#define PLATFORM_BTMACinterrupt_timer_intr1andtimer_intr0_Msk                                                (0x1UL << PLATFORM_BTMACinterrupt_timer_intr1andtimer_intr0_Pos)

#define PLATFORM_BTMACinterrupt_bluewiz_intr_r_Pos                                                           1U
#define PLATFORM_BTMACinterrupt_bluewiz_intr_r_Msk                                                           (0x1UL << PLATFORM_BTMACinterrupt_bluewiz_intr_r_Pos)

#define PLATFORM_BTMACinterrupt_hci_dma_intr_Pos                                                             2U
#define PLATFORM_BTMACinterrupt_hci_dma_intr_Msk                                                             (0x1UL << PLATFORM_BTMACinterrupt_hci_dma_intr_Pos)

#define PLATFORM_BTMACinterrupt_btverdor_reg_intr_Pos                                                        3U
#define PLATFORM_BTMACinterrupt_btverdor_reg_intr_Msk                                                        (0x1UL << PLATFORM_BTMACinterrupt_btverdor_reg_intr_Pos)

#define PLATFORM_BTMACinterrupt_pro_intr_r_Pos                                                               4U
#define PLATFORM_BTMACinterrupt_pro_intr_r_Msk                                                               (0x1UL << PLATFORM_BTMACinterrupt_pro_intr_r_Pos)

#define PLATFORM_BTMACinterrupt_RSVD_Pos                                                                     5U
#define PLATFORM_BTMACinterrupt_RSVD_Msk                                                                     (0x7FFFFFFUL << PLATFORM_BTMACinterrupt_RSVD_Pos)

/* 0x0014   0x4000_6014
    15:0    R       RSVD_2                                              16'h0
    16      R       rxi300_intr                                         0
    17      R       rdp_intr                                            0
    18      R       rxi300_ah_intr                                      0
    23:19   R       RSVD_1                                              5'h0
    24      R/W     rxi300_intr_en                                      1
    25      R/W     rdp_intr_en                                         0
    26      R/W     rxi300_ah_intr_en                                   0
    31:27   R       RSVD                                                5'h0
 */
typedef union _PLATFORM_RXIinterrupt_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_2: 16;
        uint32_t rxi300_intr: 1;
        uint32_t rdp_intr: 1;
        uint32_t rxi300_ah_intr: 1;
        uint32_t RSVD_1: 5;
        uint32_t rxi300_intr_en: 1;
        uint32_t rdp_intr_en: 1;
        uint32_t rxi300_ah_intr_en: 1;
        uint32_t RSVD: 5;
    };
} PLATFORM_RXIinterrupt_TYPE;

/*0x4000_6014 PLATFORM_RXIinterrupt*/
#define PLATFORM_RXIinterrupt_RSVD_2_Pos                                                                     0U
#define PLATFORM_RXIinterrupt_RSVD_2_Msk                                                                     (0xFFFFUL << PLATFORM_RXIinterrupt_RSVD_2_Pos)

#define PLATFORM_RXIinterrupt_rxi300_intr_Pos                                                                16U
#define PLATFORM_RXIinterrupt_rxi300_intr_Msk                                                                (0x1UL << PLATFORM_RXIinterrupt_rxi300_intr_Pos)

#define PLATFORM_RXIinterrupt_rdp_intr_Pos                                                                   17U
#define PLATFORM_RXIinterrupt_rdp_intr_Msk                                                                   (0x1UL << PLATFORM_RXIinterrupt_rdp_intr_Pos)

#define PLATFORM_RXIinterrupt_rxi300_ah_intr_Pos                                                             18U
#define PLATFORM_RXIinterrupt_rxi300_ah_intr_Msk                                                             (0x1UL << PLATFORM_RXIinterrupt_rxi300_ah_intr_Pos)

#define PLATFORM_RXIinterrupt_RSVD_1_Pos                                                                     19U
#define PLATFORM_RXIinterrupt_RSVD_1_Msk                                                                     (0x1FUL << PLATFORM_RXIinterrupt_RSVD_1_Pos)

#define PLATFORM_RXIinterrupt_rxi300_intr_en_Pos                                                             24U
#define PLATFORM_RXIinterrupt_rxi300_intr_en_Msk                                                             (0x1UL << PLATFORM_RXIinterrupt_rxi300_intr_en_Pos)

#define PLATFORM_RXIinterrupt_rdp_intr_en_Pos                                                                25U
#define PLATFORM_RXIinterrupt_rdp_intr_en_Msk                                                                (0x1UL << PLATFORM_RXIinterrupt_rdp_intr_en_Pos)

#define PLATFORM_RXIinterrupt_rxi300_ah_intr_en_Pos                                                          26U
#define PLATFORM_RXIinterrupt_rxi300_ah_intr_en_Msk                                                          (0x1UL << PLATFORM_RXIinterrupt_rxi300_ah_intr_en_Pos)

#define PLATFORM_RXIinterrupt_RSVD_Pos                                                                       27U
#define PLATFORM_RXIinterrupt_RSVD_Msk                                                                       (0x1FUL << PLATFORM_RXIinterrupt_RSVD_Pos)

/* 0x0018   0x4000_6018
    15:0    R/W     int_pol                                             16'h0
    31:16   R       RSVD                                                16'h0
 */
typedef union _PLATFORM_Interruptedgeoption_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t int_pol: 16;
        uint32_t RSVD: 16;
    };
} PLATFORM_Interruptedgeoption_TYPE;

/*0x4000_6018 PLATFORM_Interruptedgeoption*/
#define PLATFORM_Interruptedgeoption_int_pol_Pos                                                             0U
#define PLATFORM_Interruptedgeoption_int_pol_Msk                                                             (0xFFFFUL << PLATFORM_Interruptedgeoption_int_pol_Pos)

#define PLATFORM_Interruptedgeoption_RSVD_Pos                                                                16U
#define PLATFORM_Interruptedgeoption_RSVD_Msk                                                                (0xFFFFUL << PLATFORM_Interruptedgeoption_RSVD_Pos)

/* 0x001C   0x4000_601c
    13:0    R/W     debug_sel                                           14'h0
    15:14   R/W     uart_force_cg_en                                    2'h0
    23:16   R/W     IRQLATENCY                                          8'h0
    24      R/W     uart0_pclk_no_latency_en                            1'h0
    25      R/W     uart1_pclk_no_latency_en                            1'h0
    26      R/W     uart2_pclk_no_latency_en                            1'h0
    27      R/W     uart3_pclk_no_latency_en                            1'h0
    28      R       RSVD_1                                              1'h0
    29      R/W     spi_speed_up_sim                                    0
    30      R       RSVD                                                0
    31      R/W     uartlog_sir_inv                                     0
 */
typedef union _PLATFORM_REG_DEBUG_SEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t debug_sel: 14;
        uint32_t uart_force_cg_en: 2;
        uint32_t IRQLATENCY: 8;
        uint32_t uart0_pclk_no_latency_en: 1;
        uint32_t uart1_pclk_no_latency_en: 1;
        uint32_t uart2_pclk_no_latency_en: 1;
        uint32_t uart3_pclk_no_latency_en: 1;
        uint32_t RSVD_1: 1;
        uint32_t spi_speed_up_sim: 1;
        uint32_t RSVD: 1;
        uint32_t uartlog_sir_inv: 1;
    };
} PLATFORM_REG_DEBUG_SEL_TYPE;

/*0x4000_601c PLATFORM_REG_DEBUG_SEL*/
#define PLATFORM_REG_DEBUG_SEL_debug_sel_Pos                                                                 0U
#define PLATFORM_REG_DEBUG_SEL_debug_sel_Msk                                                                 (0x3FFFUL << PLATFORM_REG_DEBUG_SEL_debug_sel_Pos)

#define PLATFORM_REG_DEBUG_SEL_uart_force_cg_en_Pos                                                          14U
#define PLATFORM_REG_DEBUG_SEL_uart_force_cg_en_Msk                                                          (0x3UL << PLATFORM_REG_DEBUG_SEL_uart_force_cg_en_Pos)

#define PLATFORM_REG_DEBUG_SEL_IRQLATENCY_Pos                                                                16U
#define PLATFORM_REG_DEBUG_SEL_IRQLATENCY_Msk                                                                (0xFFUL << PLATFORM_REG_DEBUG_SEL_IRQLATENCY_Pos)

#define PLATFORM_REG_DEBUG_SEL_uart0_pclk_no_latency_en_Pos                                                  24U
#define PLATFORM_REG_DEBUG_SEL_uart0_pclk_no_latency_en_Msk                                                  (0x1UL << PLATFORM_REG_DEBUG_SEL_uart0_pclk_no_latency_en_Pos)

#define PLATFORM_REG_DEBUG_SEL_uart1_pclk_no_latency_en_Pos                                                  25U
#define PLATFORM_REG_DEBUG_SEL_uart1_pclk_no_latency_en_Msk                                                  (0x1UL << PLATFORM_REG_DEBUG_SEL_uart1_pclk_no_latency_en_Pos)

#define PLATFORM_REG_DEBUG_SEL_uart2_pclk_no_latency_en_Pos                                                  26U
#define PLATFORM_REG_DEBUG_SEL_uart2_pclk_no_latency_en_Msk                                                  (0x1UL << PLATFORM_REG_DEBUG_SEL_uart2_pclk_no_latency_en_Pos)

#define PLATFORM_REG_DEBUG_SEL_uart3_pclk_no_latency_en_Pos                                                  27U
#define PLATFORM_REG_DEBUG_SEL_uart3_pclk_no_latency_en_Msk                                                  (0x1UL << PLATFORM_REG_DEBUG_SEL_uart3_pclk_no_latency_en_Pos)

#define PLATFORM_REG_DEBUG_SEL_RSVD_1_Pos                                                                    28U
#define PLATFORM_REG_DEBUG_SEL_RSVD_1_Msk                                                                    (0x1UL << PLATFORM_REG_DEBUG_SEL_RSVD_1_Pos)

#define PLATFORM_REG_DEBUG_SEL_spi_speed_up_sim_Pos                                                          29U
#define PLATFORM_REG_DEBUG_SEL_spi_speed_up_sim_Msk                                                          (0x1UL << PLATFORM_REG_DEBUG_SEL_spi_speed_up_sim_Pos)

#define PLATFORM_REG_DEBUG_SEL_RSVD_Pos                                                                      30U
#define PLATFORM_REG_DEBUG_SEL_RSVD_Msk                                                                      (0x1UL << PLATFORM_REG_DEBUG_SEL_RSVD_Pos)

#define PLATFORM_REG_DEBUG_SEL_uartlog_sir_inv_Pos                                                           31U
#define PLATFORM_REG_DEBUG_SEL_uartlog_sir_inv_Msk                                                           (0x1UL << PLATFORM_REG_DEBUG_SEL_uartlog_sir_inv_Pos)

/* 0x0020   0x4000_6020
    0       R/W     BIT_I2C0_TX_BIT_SWAP_EN                             0
    1       R/W     BIT_I2C0_RX_BIT_SWAP_EN                             0
    2       R/W     BIT_I2C1_TX_BIT_SWAP_EN                             0
    3       R/W     BIT_I2C1_RX_BIT_SWAP_EN                             0
    4       R/W     BIT_I2C2_TX_BIT_SWAP_EN                             0
    5       R/W     BIT_I2C2_RX_BIT_SWAP_EN                             0
    6       R/W     BIT_I2C3_TX_BIT_SWAP_EN                             0
    7       R/W     BIT_I2C3_RX_BIT_SWAP_EN                             0
    8       R/W     BIT_SPI0_TX_BIT_SWAP_EN                             0
    9       R/W     BIT_SPI0_RX_BIT_SWAP_EN                             0
    10      R/W     BIT_SPI1_TX_BIT_SWAP_EN                             0
    11      R/W     BIT_SPI1_RX_BIT_SWAP_EN                             0
    12      R/W     BIT_SPI2_TX_BIT_SWAP_EN                             0
    13      R/W     BIT_SPI2_RX_BIT_SWAP_EN                             0
    15:14   R       RSVD_1                                              2'h0
    16      R/W     SPI0_TX_BYTE_SWAP_EN                                0
    17      R/W     SPI0_RX_BYTE_SWAP_EN                                0
    18      R/W     SPI1_TX_BYTE_SWAP_EN                                0
    19      R/W     SPI1_RX_BYTE_SWAP_EN                                0
    20      R/W     SPI2_TX_BYTE_SWAP_EN                                0
    21      R/W     SPI2_RX_BYTE_SWAP_EN                                0
    28:22   R       RSVD                                                7'h0
    29      W1O     EFUSE_RP_bk1                                        0
    30      W1O     EFUSE_WP                                            0
    31      W1O     EFUSE_RP                                            0
 */
typedef union _PLATFORM_REG_DATA_FIFO_SWAP_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BIT_I2C0_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C0_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C1_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C1_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C2_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C2_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C3_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_I2C3_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI0_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI0_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI1_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI1_RX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI2_TX_BIT_SWAP_EN: 1;
        uint32_t BIT_SPI2_RX_BIT_SWAP_EN: 1;
        uint32_t RSVD_1: 2;
        uint32_t SPI0_TX_BYTE_SWAP_EN: 1;
        uint32_t SPI0_RX_BYTE_SWAP_EN: 1;
        uint32_t SPI1_TX_BYTE_SWAP_EN: 1;
        uint32_t SPI1_RX_BYTE_SWAP_EN: 1;
        uint32_t SPI2_TX_BYTE_SWAP_EN: 1;
        uint32_t SPI2_RX_BYTE_SWAP_EN: 1;
        uint32_t RSVD: 7;
        uint32_t EFUSE_RP_bk1: 1;
        uint32_t EFUSE_WP: 1;
        uint32_t EFUSE_RP: 1;
    };
} PLATFORM_REG_DATA_FIFO_SWAP_CTRL_TYPE;

/*0x4000_6020 PLATFORM_REG_DATA_FIFO_SWAP_CTRL*/
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_TX_BIT_SWAP_EN_Pos                                         0U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_RX_BIT_SWAP_EN_Pos                                         1U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C0_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_TX_BIT_SWAP_EN_Pos                                         2U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_RX_BIT_SWAP_EN_Pos                                         3U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C1_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_TX_BIT_SWAP_EN_Pos                                         4U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_RX_BIT_SWAP_EN_Pos                                         5U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C2_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_TX_BIT_SWAP_EN_Pos                                         6U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_RX_BIT_SWAP_EN_Pos                                         7U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_I2C3_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_TX_BIT_SWAP_EN_Pos                                         8U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_RX_BIT_SWAP_EN_Pos                                         9U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI0_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_TX_BIT_SWAP_EN_Pos                                         10U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_RX_BIT_SWAP_EN_Pos                                         11U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI1_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_TX_BIT_SWAP_EN_Pos                                         12U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_TX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_TX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_RX_BIT_SWAP_EN_Pos                                         13U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_RX_BIT_SWAP_EN_Msk                                         (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_BIT_SPI2_RX_BIT_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_1_Pos                                                          14U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_1_Msk                                                          (0x3UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_1_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_TX_BYTE_SWAP_EN_Pos                                            16U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_TX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_TX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_RX_BYTE_SWAP_EN_Pos                                            17U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_RX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI0_RX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_TX_BYTE_SWAP_EN_Pos                                            18U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_TX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_TX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_RX_BYTE_SWAP_EN_Pos                                            19U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_RX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI1_RX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_TX_BYTE_SWAP_EN_Pos                                            20U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_TX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_TX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_RX_BYTE_SWAP_EN_Pos                                            21U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_RX_BYTE_SWAP_EN_Msk                                            (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_SPI2_RX_BYTE_SWAP_EN_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_Pos                                                            22U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_Msk                                                            (0x7FUL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_RSVD_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_bk1_Pos                                                    29U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_bk1_Msk                                                    (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_bk1_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_WP_Pos                                                        30U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_WP_Msk                                                        (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_WP_Pos)

#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_Pos                                                        31U
#define PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_Msk                                                        (0x1UL << PLATFORM_REG_DATA_FIFO_SWAP_CTRL_EFUSE_RP_Pos)

/* 0x0024   0x4000_6024
    0       R       RSVD_11                                             0
    1       R       RSVD_10                                             0
    2       R       RSVD_9                                              0
    3       R       RSVD_8                                              0
    4       R       RSVD_7                                              0
    5       R       RSVD_6                                              0
    6       R       RSVD_5                                              0
    7       R       RSVD_4                                              0
    8       R/W     spic0_mem_wr_en                                     0
    9       R/W     spic1_mem_wr_en                                     0
    10      W1O     dram_c2s_remap_dis                                  1
    11      R/W     spic_icg_disable                                    0
    12      R/W     ic_icg_disable                                      0
    13      R/W     dmac_clk_always_disable                             0
    14      R/W     dmac_clk_always_enable                              0
    15      R/W     rxi300_auto_icg_en                                  1
    23:16   R/W     RSVD_3                                              8'h0
    24      W1O     dram_c2s_remap_dis_wlock                            0
    25      R/W     RSVD_2                                              0
    26      R/W     RSVD_1                                              0
    30:27   R       RSVD                                                4'd0
    31      R/W     fwpi_enable                                         1
 */
typedef union _PLATFORM_DUMMY_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t spic0_mem_wr_en: 1;
        uint32_t spic1_mem_wr_en: 1;
        uint32_t dram_c2s_remap_dis: 1;
        uint32_t spic_icg_disable: 1;
        uint32_t ic_icg_disable: 1;
        uint32_t dmac_clk_always_disable: 1;
        uint32_t dmac_clk_always_enable: 1;
        uint32_t rxi300_auto_icg_en: 1;
        uint32_t RSVD_3: 8;
        uint32_t dram_c2s_remap_dis_wlock: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 4;
        uint32_t fwpi_enable: 1;
    };
} PLATFORM_DUMMY_TYPE;

/*0x4000_6024 PLATFORM_DUMMY*/
#define PLATFORM_DUMMY_RSVD_11_Pos                                                                           0U
#define PLATFORM_DUMMY_RSVD_11_Msk                                                                           (0x1UL << PLATFORM_DUMMY_RSVD_11_Pos)

#define PLATFORM_DUMMY_RSVD_10_Pos                                                                           1U
#define PLATFORM_DUMMY_RSVD_10_Msk                                                                           (0x1UL << PLATFORM_DUMMY_RSVD_10_Pos)

#define PLATFORM_DUMMY_RSVD_9_Pos                                                                            2U
#define PLATFORM_DUMMY_RSVD_9_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_9_Pos)

#define PLATFORM_DUMMY_RSVD_8_Pos                                                                            3U
#define PLATFORM_DUMMY_RSVD_8_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_8_Pos)

#define PLATFORM_DUMMY_RSVD_7_Pos                                                                            4U
#define PLATFORM_DUMMY_RSVD_7_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_7_Pos)

#define PLATFORM_DUMMY_RSVD_6_Pos                                                                            5U
#define PLATFORM_DUMMY_RSVD_6_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_6_Pos)

#define PLATFORM_DUMMY_RSVD_5_Pos                                                                            6U
#define PLATFORM_DUMMY_RSVD_5_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_5_Pos)

#define PLATFORM_DUMMY_RSVD_4_Pos                                                                            7U
#define PLATFORM_DUMMY_RSVD_4_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_4_Pos)

#define PLATFORM_DUMMY_spic0_mem_wr_en_Pos                                                                   8U
#define PLATFORM_DUMMY_spic0_mem_wr_en_Msk                                                                   (0x1UL << PLATFORM_DUMMY_spic0_mem_wr_en_Pos)

#define PLATFORM_DUMMY_spic1_mem_wr_en_Pos                                                                   9U
#define PLATFORM_DUMMY_spic1_mem_wr_en_Msk                                                                   (0x1UL << PLATFORM_DUMMY_spic1_mem_wr_en_Pos)

#define PLATFORM_DUMMY_dram_c2s_remap_dis_Pos                                                                10U
#define PLATFORM_DUMMY_dram_c2s_remap_dis_Msk                                                                (0x1UL << PLATFORM_DUMMY_dram_c2s_remap_dis_Pos)

#define PLATFORM_DUMMY_spic_icg_disable_Pos                                                                  11U
#define PLATFORM_DUMMY_spic_icg_disable_Msk                                                                  (0x1UL << PLATFORM_DUMMY_spic_icg_disable_Pos)

#define PLATFORM_DUMMY_ic_icg_disable_Pos                                                                    12U
#define PLATFORM_DUMMY_ic_icg_disable_Msk                                                                    (0x1UL << PLATFORM_DUMMY_ic_icg_disable_Pos)

#define PLATFORM_DUMMY_dmac_clk_always_disable_Pos                                                           13U
#define PLATFORM_DUMMY_dmac_clk_always_disable_Msk                                                           (0x1UL << PLATFORM_DUMMY_dmac_clk_always_disable_Pos)

#define PLATFORM_DUMMY_dmac_clk_always_enable_Pos                                                            14U
#define PLATFORM_DUMMY_dmac_clk_always_enable_Msk                                                            (0x1UL << PLATFORM_DUMMY_dmac_clk_always_enable_Pos)

#define PLATFORM_DUMMY_rxi300_auto_icg_en_Pos                                                                15U
#define PLATFORM_DUMMY_rxi300_auto_icg_en_Msk                                                                (0x1UL << PLATFORM_DUMMY_rxi300_auto_icg_en_Pos)

#define PLATFORM_DUMMY_RSVD_3_Pos                                                                            16U
#define PLATFORM_DUMMY_RSVD_3_Msk                                                                            (0xFFUL << PLATFORM_DUMMY_RSVD_3_Pos)

#define PLATFORM_DUMMY_dram_c2s_remap_dis_wlock_Pos                                                          24U
#define PLATFORM_DUMMY_dram_c2s_remap_dis_wlock_Msk                                                          (0x1UL << PLATFORM_DUMMY_dram_c2s_remap_dis_wlock_Pos)

#define PLATFORM_DUMMY_RSVD_2_Pos                                                                            25U
#define PLATFORM_DUMMY_RSVD_2_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_2_Pos)

#define PLATFORM_DUMMY_RSVD_1_Pos                                                                            26U
#define PLATFORM_DUMMY_RSVD_1_Msk                                                                            (0x1UL << PLATFORM_DUMMY_RSVD_1_Pos)

#define PLATFORM_DUMMY_RSVD_Pos                                                                              27U
#define PLATFORM_DUMMY_RSVD_Msk                                                                              (0xFUL << PLATFORM_DUMMY_RSVD_Pos)

#define PLATFORM_DUMMY_fwpi_enable_Pos                                                                       31U
#define PLATFORM_DUMMY_fwpi_enable_Msk                                                                       (0x1UL << PLATFORM_DUMMY_fwpi_enable_Pos)

/* 0x0028   0x4000_6028
    5:0     R/W     enhtimer_gpio_trig_sel                              6'h3f
    6       R/W     RSVD_2                                              0
    7       R/W     RSVD_1                                              0
    23:8    R/W     enhtimer_gpio_trig_deb_cnt_limit                    16'h1
    24      R/W     enhtimer_gpio_trig_deb_en                           1'h0
    25      R       enhtimer_gpio_trig_deb_sts                          1'h0
    29:26   R       RSVD                                                4'h0
    30      R/W     enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_data   1'h0
    31      R/W     enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_en     1'h0
 */
typedef union _PLATFORM_REG_ENHTIMER_TRIG_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t enhtimer_gpio_trig_sel: 6;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t enhtimer_gpio_trig_deb_cnt_limit: 16;
        uint32_t enhtimer_gpio_trig_deb_en: 1;
        uint32_t enhtimer_gpio_trig_deb_sts: 1;
        uint32_t RSVD: 4;
        uint32_t enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_data: 1;
        uint32_t enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_en: 1;
    };
} PLATFORM_REG_ENHTIMER_TRIG_CTRL_TYPE;

/*0x4000_6028 PLATFORM_REG_ENHTIMER_TRIG_CTRL*/
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_sel_Pos                                           0U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_sel_Msk                                           (0x3FUL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_sel_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_2_Pos                                                           6U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_2_Msk                                                           (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_2_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_1_Pos                                                           7U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_1_Msk                                                           (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_1_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_cnt_limit_Pos                                 8U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_cnt_limit_Msk                                 (0xFFFFUL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_cnt_limit_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_en_Pos                                        24U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_en_Msk                                        (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_en_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_sts_Pos                                       25U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_sts_Msk                                       (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_trig_deb_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_Pos                                                             26U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_Msk                                                             (0xFUL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_RSVD_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_data_Pos                30U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_data_Msk                (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_data_Pos)

#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_en_Pos                  31U
#define PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_en_Msk                  (0x1UL << PLATFORM_REG_ENHTIMER_TRIG_CTRL_enhtimer_gpio_deb_clk_q_ch_qactive_fw_manual_en_Pos)

/* 0x002C   0x4000_602c
    0       R/W     r_systick_timer_manual_rstb                         0
    1       R/W     r_systick_timer_rst_sel                             1
    31:2    R       RSVD                                                30'h0
 */
typedef union _PLATFORM_REG_SYSTICK_TIMER_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_systick_timer_manual_rstb: 1;
        uint32_t r_systick_timer_rst_sel: 1;
        uint32_t RSVD: 30;
    };
} PLATFORM_REG_SYSTICK_TIMER_CTRL_TYPE;

/*0x4000_602c PLATFORM_REG_SYSTICK_TIMER_CTRL*/
#define PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_manual_rstb_Pos                                      0U
#define PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_manual_rstb_Msk                                      (0x1UL << PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_manual_rstb_Pos)

#define PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_rst_sel_Pos                                          1U
#define PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_rst_sel_Msk                                          (0x1UL << PLATFORM_REG_SYSTICK_TIMER_CTRL_r_systick_timer_rst_sel_Pos)

#define PLATFORM_REG_SYSTICK_TIMER_CTRL_RSVD_Pos                                                             2U
#define PLATFORM_REG_SYSTICK_TIMER_CTRL_RSVD_Msk                                                             (0x3FFFFFFFUL << PLATFORM_REG_SYSTICK_TIMER_CTRL_RSVD_Pos)

/* 0x0030   0x4000_6030
    31:0    R       cpu_systick_timer_cnt                               32'h0
 */
typedef union _PLATFORM_REG_SYSTICK_TIMER_CNT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t cpu_systick_timer_cnt;
    };
} PLATFORM_REG_SYSTICK_TIMER_CNT_TYPE;

/*0x4000_6030 PLATFORM_REG_SYSTICK_TIMER_CNT*/
#define PLATFORM_REG_SYSTICK_TIMER_CNT_cpu_systick_timer_cnt_Pos                                             0U
#define PLATFORM_REG_SYSTICK_TIMER_CNT_cpu_systick_timer_cnt_Msk                                             (0xFFFFFFFFUL << PLATFORM_REG_SYSTICK_TIMER_CNT_cpu_systick_timer_cnt_Pos)

/* 0x0034   0x4000_6034
    0       R/W     TIMER_INT_EN                                        1'b0
    1       R/W     VLD_TIMER                                           1'b0
    30:2    R       RSVD                                                29'h0
    31      R/W     VLD_TIMER_FAKE_INFPGA                               1'b0
 */
typedef union _PLATFORM_REG_TMETER_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TIMER_INT_EN: 1;
        uint32_t VLD_TIMER: 1;
        uint32_t RSVD: 29;
        uint32_t VLD_TIMER_FAKE_INFPGA: 1;
    };
} PLATFORM_REG_TMETER_CTRL_TYPE;

/*0x4000_6034 PLATFORM_REG_TMETER_CTRL*/
#define PLATFORM_REG_TMETER_CTRL_TIMER_INT_EN_Pos                                                            0U
#define PLATFORM_REG_TMETER_CTRL_TIMER_INT_EN_Msk                                                            (0x1UL << PLATFORM_REG_TMETER_CTRL_TIMER_INT_EN_Pos)

#define PLATFORM_REG_TMETER_CTRL_VLD_TIMER_Pos                                                               1U
#define PLATFORM_REG_TMETER_CTRL_VLD_TIMER_Msk                                                               (0x1UL << PLATFORM_REG_TMETER_CTRL_VLD_TIMER_Pos)

#define PLATFORM_REG_TMETER_CTRL_RSVD_Pos                                                                    2U
#define PLATFORM_REG_TMETER_CTRL_RSVD_Msk                                                                    (0x1FFFFFFFUL << PLATFORM_REG_TMETER_CTRL_RSVD_Pos)

#define PLATFORM_REG_TMETER_CTRL_VLD_TIMER_FAKE_INFPGA_Pos                                                   31U
#define PLATFORM_REG_TMETER_CTRL_VLD_TIMER_FAKE_INFPGA_Msk                                                   (0x1UL << PLATFORM_REG_TMETER_CTRL_VLD_TIMER_FAKE_INFPGA_Pos)

/* 0x0038   0x4000_6038
    0       R/W1C   VLD_TIMER_INT                                       1'b0
    31:1    R       RSVD                                                31'h0
 */
typedef union _PLATFORM_REG_TMETER_INT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t VLD_TIMER_INT: 1;
        uint32_t RSVD: 31;
    };
} PLATFORM_REG_TMETER_INT_STS_TYPE;

/*0x4000_6038 PLATFORM_REG_TMETER_INT_STS*/
#define PLATFORM_REG_TMETER_INT_STS_VLD_TIMER_INT_Pos                                                        0U
#define PLATFORM_REG_TMETER_INT_STS_VLD_TIMER_INT_Msk                                                        (0x1UL << PLATFORM_REG_TMETER_INT_STS_VLD_TIMER_INT_Pos)

#define PLATFORM_REG_TMETER_INT_STS_RSVD_Pos                                                                 1U
#define PLATFORM_REG_TMETER_INT_STS_RSVD_Msk                                                                 (0x7FFFFFFFUL << PLATFORM_REG_TMETER_INT_STS_RSVD_Pos)

/* 0x003C   0x4000_603c
    0       R/W     cm33_nmi_int_enable                                 1'b0
    31:1    R       RSVD                                                31'h0
 */
typedef union _PLATFORM_REG_CM33_NMI_INT_EN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t cm33_nmi_int_enable: 1;
        uint32_t RSVD: 31;
    };
} PLATFORM_REG_CM33_NMI_INT_EN_TYPE;

/*0x4000_603c PLATFORM_REG_CM33_NMI_INT_EN*/
#define PLATFORM_REG_CM33_NMI_INT_EN_cm33_nmi_int_enable_Pos                                                 0U
#define PLATFORM_REG_CM33_NMI_INT_EN_cm33_nmi_int_enable_Msk                                                 (0x1UL << PLATFORM_REG_CM33_NMI_INT_EN_cm33_nmi_int_enable_Pos)

#define PLATFORM_REG_CM33_NMI_INT_EN_RSVD_Pos                                                                1U
#define PLATFORM_REG_CM33_NMI_INT_EN_RSVD_Msk                                                                (0x7FFFFFFFUL << PLATFORM_REG_CM33_NMI_INT_EN_RSVD_Pos)

/* 0x0040   0x4000_6040
    0       R/W     bist_rstn_mcu_rom                                   0
    1       R/W     bist_rstn_data_ram                                  0
    2       R/W     bist_rstn_cpu_ram                                   0
    3       R/W     bist_rstn_usb_ram                                   0
    4       R/W     bist_rstn_can_ram                                   0
    5       R/W     bist_rstn_cache_ram                                 0
    6       R/W     bist_rstn_amu_ram                                   0
    31:7    R       RSVD                                                25'h0
 */
typedef union _PLATFORM_REG_BIST_RSTN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_rstn_mcu_rom: 1;
        uint32_t bist_rstn_data_ram: 1;
        uint32_t bist_rstn_cpu_ram: 1;
        uint32_t bist_rstn_usb_ram: 1;
        uint32_t bist_rstn_can_ram: 1;
        uint32_t bist_rstn_cache_ram: 1;
        uint32_t bist_rstn_amu_ram: 1;
        uint32_t RSVD: 25;
    };
} PLATFORM_REG_BIST_RSTN_TYPE;

/*0x4000_6040 PLATFORM_REG_BIST_RSTN*/
#define PLATFORM_REG_BIST_RSTN_bist_rstn_mcu_rom_Pos                                                         0U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_mcu_rom_Msk                                                         (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_mcu_rom_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_data_ram_Pos                                                        1U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_data_ram_Msk                                                        (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_data_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_cpu_ram_Pos                                                         2U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_cpu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_cpu_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_usb_ram_Pos                                                         3U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_usb_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_usb_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_can_ram_Pos                                                         4U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_can_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_can_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_cache_ram_Pos                                                       5U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_cache_ram_Msk                                                       (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_cache_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_bist_rstn_amu_ram_Pos                                                         6U
#define PLATFORM_REG_BIST_RSTN_bist_rstn_amu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_RSTN_bist_rstn_amu_ram_Pos)

#define PLATFORM_REG_BIST_RSTN_RSVD_Pos                                                                      7U
#define PLATFORM_REG_BIST_RSTN_RSVD_Msk                                                                      (0x1FFFFFFUL << PLATFORM_REG_BIST_RSTN_RSVD_Pos)

/* 0x0044   0x4000_6044
    0       R/W     bist_mode_mcu_rom                                   0
    1       R/W     bist_mode_data_ram                                  0
    2       R/W     bist_mode_cpu_ram                                   0
    3       R/W     bist_mode_usb_ram                                   0
    4       R/W     bist_mode_can_ram                                   0
    5       R/W     bist_mode_cache_ram                                 0
    6       R/W     bist_mode_amu_ram                                   0
    31:7    R       RSVD                                                25'h0
 */
typedef union _PLATFORM_REG_BIST_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_mode_mcu_rom: 1;
        uint32_t bist_mode_data_ram: 1;
        uint32_t bist_mode_cpu_ram: 1;
        uint32_t bist_mode_usb_ram: 1;
        uint32_t bist_mode_can_ram: 1;
        uint32_t bist_mode_cache_ram: 1;
        uint32_t bist_mode_amu_ram: 1;
        uint32_t RSVD: 25;
    };
} PLATFORM_REG_BIST_MODE_TYPE;

/*0x4000_6044 PLATFORM_REG_BIST_MODE*/
#define PLATFORM_REG_BIST_MODE_bist_mode_mcu_rom_Pos                                                         0U
#define PLATFORM_REG_BIST_MODE_bist_mode_mcu_rom_Msk                                                         (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_mcu_rom_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_data_ram_Pos                                                        1U
#define PLATFORM_REG_BIST_MODE_bist_mode_data_ram_Msk                                                        (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_data_ram_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_cpu_ram_Pos                                                         2U
#define PLATFORM_REG_BIST_MODE_bist_mode_cpu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_cpu_ram_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_usb_ram_Pos                                                         3U
#define PLATFORM_REG_BIST_MODE_bist_mode_usb_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_usb_ram_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_can_ram_Pos                                                         4U
#define PLATFORM_REG_BIST_MODE_bist_mode_can_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_can_ram_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_cache_ram_Pos                                                       5U
#define PLATFORM_REG_BIST_MODE_bist_mode_cache_ram_Msk                                                       (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_cache_ram_Pos)

#define PLATFORM_REG_BIST_MODE_bist_mode_amu_ram_Pos                                                         6U
#define PLATFORM_REG_BIST_MODE_bist_mode_amu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_MODE_bist_mode_amu_ram_Pos)

#define PLATFORM_REG_BIST_MODE_RSVD_Pos                                                                      7U
#define PLATFORM_REG_BIST_MODE_RSVD_Msk                                                                      (0x1FFFFFFUL << PLATFORM_REG_BIST_MODE_RSVD_Pos)

/* 0x0048   0x4000_6048
    0       R/W     bist_mode_drf_data_ram                              0
    1       R/W     bist_mode_drf_cpu_ram                               0
    2       R/W     bist_mode_drf_usb_ram                               0
    3       R/W     bist_mode_drf_can_ram                               0
    4       R/W     bist_mode_drf_cache_ram                             0
    5       R/W     bist_mode_drf_amu_ram                               0
    31:6    R       RSVD                                                26'h0
 */
typedef union _PLATFORM_REG_DRF_BIST_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_mode_drf_data_ram: 1;
        uint32_t bist_mode_drf_cpu_ram: 1;
        uint32_t bist_mode_drf_usb_ram: 1;
        uint32_t bist_mode_drf_can_ram: 1;
        uint32_t bist_mode_drf_cache_ram: 1;
        uint32_t bist_mode_drf_amu_ram: 1;
        uint32_t RSVD: 26;
    };
} PLATFORM_REG_DRF_BIST_MODE_TYPE;

/*0x4000_6048 PLATFORM_REG_DRF_BIST_MODE*/
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_data_ram_Pos                                                0U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_data_ram_Msk                                                (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_data_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cpu_ram_Pos                                                 1U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cpu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cpu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_usb_ram_Pos                                                 2U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_usb_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_usb_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_can_ram_Pos                                                 3U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_can_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_can_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cache_ram_Pos                                               4U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cache_ram_Msk                                               (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_cache_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_amu_ram_Pos                                                 5U
#define PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_amu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_MODE_bist_mode_drf_amu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_MODE_RSVD_Pos                                                                  6U
#define PLATFORM_REG_DRF_BIST_MODE_RSVD_Msk                                                                  (0x3FFFFFFUL << PLATFORM_REG_DRF_BIST_MODE_RSVD_Pos)

/* 0x004C   0x4000_604c
    0       R/W     bist_test_resume_data_ram                           0
    1       R/W     bist_test_resume_cpu_ram                            0
    2       R/W     bist_test_resume_usb_ram                            0
    3       R/W     bist_test_resume_can_ram                            0
    4       R/W     bist_test_resume_cache_ram                          0
    5       R/W     bist_test_resume_amu_ram                            0
    31:6    R       RSVD                                                26'h0
 */
typedef union _PLATFORM_REG_BIST_TEST_RESUME_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_test_resume_data_ram: 1;
        uint32_t bist_test_resume_cpu_ram: 1;
        uint32_t bist_test_resume_usb_ram: 1;
        uint32_t bist_test_resume_can_ram: 1;
        uint32_t bist_test_resume_cache_ram: 1;
        uint32_t bist_test_resume_amu_ram: 1;
        uint32_t RSVD: 26;
    };
} PLATFORM_REG_BIST_TEST_RESUME_TYPE;

/*0x4000_604c PLATFORM_REG_BIST_TEST_RESUME*/
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_data_ram_Pos                                          0U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_data_ram_Msk                                          (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_data_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cpu_ram_Pos                                           1U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cpu_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cpu_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_usb_ram_Pos                                           2U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_usb_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_usb_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_can_ram_Pos                                           3U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_can_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_can_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cache_ram_Pos                                         4U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cache_ram_Msk                                         (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_cache_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_amu_ram_Pos                                           5U
#define PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_amu_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_TEST_RESUME_bist_test_resume_amu_ram_Pos)

#define PLATFORM_REG_BIST_TEST_RESUME_RSVD_Pos                                                               6U
#define PLATFORM_REG_BIST_TEST_RESUME_RSVD_Msk                                                               (0x3FFFFFFUL << PLATFORM_REG_BIST_TEST_RESUME_RSVD_Pos)

/* 0x0050   0x4000_6050
    0       R       bist_start_pause_data_ram                           0
    1       R       bist_start_pause_cpu_ram                            0
    2       R       bist_start_pause_usb_ram                            0
    3       R       bist_start_pause_can_ram                            0
    4       R       bist_start_pause_cache_ram                          0
    5       R       bist_start_pause_amu_ram                            0
    31:6    R       RSVD                                                26'h0
 */
typedef union _PLATFORM_REG_BIST_START_PAUSE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_start_pause_data_ram: 1;
        uint32_t bist_start_pause_cpu_ram: 1;
        uint32_t bist_start_pause_usb_ram: 1;
        uint32_t bist_start_pause_can_ram: 1;
        uint32_t bist_start_pause_cache_ram: 1;
        uint32_t bist_start_pause_amu_ram: 1;
        uint32_t RSVD: 26;
    };
} PLATFORM_REG_BIST_START_PAUSE_TYPE;

/*0x4000_6050 PLATFORM_REG_BIST_START_PAUSE*/
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_data_ram_Pos                                          0U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_data_ram_Msk                                          (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_data_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cpu_ram_Pos                                           1U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cpu_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cpu_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_usb_ram_Pos                                           2U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_usb_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_usb_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_can_ram_Pos                                           3U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_can_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_can_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cache_ram_Pos                                         4U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cache_ram_Msk                                         (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_cache_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_amu_ram_Pos                                           5U
#define PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_amu_ram_Msk                                           (0x1UL << PLATFORM_REG_BIST_START_PAUSE_bist_start_pause_amu_ram_Pos)

#define PLATFORM_REG_BIST_START_PAUSE_RSVD_Pos                                                               6U
#define PLATFORM_REG_BIST_START_PAUSE_RSVD_Msk                                                               (0x3FFFFFFUL << PLATFORM_REG_BIST_START_PAUSE_RSVD_Pos)

/* 0x0054   0x4000_6054
    0       R       bist_done_mcu_rom                                   0
    1       R       bist_done_data_ram                                  0
    2       R       bisr_done_data_ram                                  0
    3       R       bist_done_cpu_ram                                   0
    4       R       bist_done_usb_ram                                   0
    5       R       bist_done_can_ram                                   0
    6       R       bist_done_cache_ram                                 0
    7       R       bist_done_amu_ram                                   0
    31:8    R       RSVD                                                25'h0
 */
typedef union _PLATFORM_REG_BIST_DONE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_done_mcu_rom: 1;
        uint32_t bist_done_data_ram: 1;
        uint32_t bisr_done_data_ram: 1;
        uint32_t bist_done_cpu_ram: 1;
        uint32_t bist_done_usb_ram: 1;
        uint32_t bist_done_can_ram: 1;
        uint32_t bist_done_cache_ram: 1;
        uint32_t bist_done_amu_ram: 1;
        uint32_t RSVD: 24;
    };
} PLATFORM_REG_BIST_DONE_TYPE;

/*0x4000_6054 PLATFORM_REG_BIST_DONE*/
#define PLATFORM_REG_BIST_DONE_bist_done_mcu_rom_Pos                                                         0U
#define PLATFORM_REG_BIST_DONE_bist_done_mcu_rom_Msk                                                         (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_mcu_rom_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_data_ram_Pos                                                        1U
#define PLATFORM_REG_BIST_DONE_bist_done_data_ram_Msk                                                        (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_data_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bisr_done_data_ram_Pos                                                        2U
#define PLATFORM_REG_BIST_DONE_bisr_done_data_ram_Msk                                                        (0x1UL << PLATFORM_REG_BIST_DONE_bisr_done_data_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_cpu_ram_Pos                                                         3U
#define PLATFORM_REG_BIST_DONE_bist_done_cpu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_cpu_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_usb_ram_Pos                                                         4U
#define PLATFORM_REG_BIST_DONE_bist_done_usb_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_usb_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_can_ram_Pos                                                         5U
#define PLATFORM_REG_BIST_DONE_bist_done_can_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_can_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_cache_ram_Pos                                                       6U
#define PLATFORM_REG_BIST_DONE_bist_done_cache_ram_Msk                                                       (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_cache_ram_Pos)

#define PLATFORM_REG_BIST_DONE_bist_done_amu_ram_Pos                                                         7U
#define PLATFORM_REG_BIST_DONE_bist_done_amu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_DONE_bist_done_amu_ram_Pos)

#define PLATFORM_REG_BIST_DONE_RSVD_Pos                                                                      8U
#define PLATFORM_REG_BIST_DONE_RSVD_Msk                                                                      (0xFFFFFFUL << PLATFORM_REG_BIST_DONE_RSVD_Pos)

/* 0x0058   0x4000_6058
    4:0     R       bist_fail_data_ram                                  5'h0
    5       R       bist_fail_cpu_ram                                   0
    6       R       bist_fail_usb_ram                                   0
    7       R       bist_fail_can_ram                                   0
    16:8    R       bist_fail_cache_ram                                 9'h0
    17      R       bist_fail_amu_ram                                   0
    31:18   R       RSVD                                                14'h0
 */
typedef union _PLATFORM_REG_BIST_FAIL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_fail_data_ram: 5;
        uint32_t bist_fail_cpu_ram: 1;
        uint32_t bist_fail_usb_ram: 1;
        uint32_t bist_fail_can_ram: 1;
        uint32_t bist_fail_cache_ram: 9;
        uint32_t bist_fail_amu_ram: 1;
        uint32_t RSVD: 14;
    };
} PLATFORM_REG_BIST_FAIL_TYPE;

/*0x4000_6058 PLATFORM_REG_BIST_FAIL*/
#define PLATFORM_REG_BIST_FAIL_bist_fail_data_ram_Pos                                                        0U
#define PLATFORM_REG_BIST_FAIL_bist_fail_data_ram_Msk                                                        (0x1FUL << PLATFORM_REG_BIST_FAIL_bist_fail_data_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_bist_fail_cpu_ram_Pos                                                         5U
#define PLATFORM_REG_BIST_FAIL_bist_fail_cpu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_FAIL_bist_fail_cpu_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_bist_fail_usb_ram_Pos                                                         6U
#define PLATFORM_REG_BIST_FAIL_bist_fail_usb_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_FAIL_bist_fail_usb_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_bist_fail_can_ram_Pos                                                         7U
#define PLATFORM_REG_BIST_FAIL_bist_fail_can_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_FAIL_bist_fail_can_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_bist_fail_cache_ram_Pos                                                       8U
#define PLATFORM_REG_BIST_FAIL_bist_fail_cache_ram_Msk                                                       (0x1FFUL << PLATFORM_REG_BIST_FAIL_bist_fail_cache_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_bist_fail_amu_ram_Pos                                                         17U
#define PLATFORM_REG_BIST_FAIL_bist_fail_amu_ram_Msk                                                         (0x1UL << PLATFORM_REG_BIST_FAIL_bist_fail_amu_ram_Pos)

#define PLATFORM_REG_BIST_FAIL_RSVD_Pos                                                                      18U
#define PLATFORM_REG_BIST_FAIL_RSVD_Msk                                                                      (0x3FFFUL << PLATFORM_REG_BIST_FAIL_RSVD_Pos)

/* 0x005C   0x4000_605c
    0       R       bist_done_drf_data_ram                              0
    1       R       bist_done_drf_cpu_ram                               0
    2       R       bist_done_drf_usb_ram                               0
    3       R       bist_done_drf_can_ram                               0
    4       R       bist_done_drf_cache_ram                             0
    5       R       bist_done_drf_amu_ram                               0
    6       R       bisr_done_drf_data_ram                              0
    31:7    R       RSVD                                                26'h0
 */
typedef union _PLATFORM_REG_DRF_BIST_DONE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_done_drf_data_ram: 1;
        uint32_t bist_done_drf_cpu_ram: 1;
        uint32_t bist_done_drf_usb_ram: 1;
        uint32_t bist_done_drf_can_ram: 1;
        uint32_t bist_done_drf_cache_ram: 1;
        uint32_t bist_done_drf_amu_ram: 1;
        uint32_t bisr_done_drf_data_ram: 1;
        uint32_t RSVD: 25;
    };
} PLATFORM_REG_DRF_BIST_DONE_TYPE;

/*0x4000_605c PLATFORM_REG_DRF_BIST_DONE*/
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_data_ram_Pos                                                0U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_data_ram_Msk                                                (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_data_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cpu_ram_Pos                                                 1U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cpu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cpu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_usb_ram_Pos                                                 2U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_usb_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_usb_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_can_ram_Pos                                                 3U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_can_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_can_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cache_ram_Pos                                               4U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cache_ram_Msk                                               (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_cache_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_amu_ram_Pos                                                 5U
#define PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_amu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bist_done_drf_amu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_bisr_done_drf_data_ram_Pos                                                6U
#define PLATFORM_REG_DRF_BIST_DONE_bisr_done_drf_data_ram_Msk                                                (0x1UL << PLATFORM_REG_DRF_BIST_DONE_bisr_done_drf_data_ram_Pos)

#define PLATFORM_REG_DRF_BIST_DONE_RSVD_Pos                                                                  7U
#define PLATFORM_REG_DRF_BIST_DONE_RSVD_Msk                                                                  (0x1FFFFFFUL << PLATFORM_REG_DRF_BIST_DONE_RSVD_Pos)

/* 0x0060   0x4000_6060
    4:0     R       bist_fail_drf_data_ram                              5'h0
    5       R       bist_fail_drf_cpu_ram                               0
    6       R       bist_fail_drf_usb_ram                               0
    7       R       bist_fail_drf_can_ram                               0
    16:8    R       bist_fail_drf_cache_ram                             9'h0
    17      R       bist_fail_drf_amu_ram                               0
    31:18   R       RSVD                                                14'h0
 */
typedef union _PLATFORM_REG_DRF_BIST_FAIL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_fail_drf_data_ram: 5;
        uint32_t bist_fail_drf_cpu_ram: 1;
        uint32_t bist_fail_drf_usb_ram: 1;
        uint32_t bist_fail_drf_can_ram: 1;
        uint32_t bist_fail_drf_cache_ram: 9;
        uint32_t bist_fail_drf_amu_ram: 1;
        uint32_t RSVD: 14;
    };
} PLATFORM_REG_DRF_BIST_FAIL_TYPE;

/*0x4000_6060 PLATFORM_REG_DRF_BIST_FAIL*/
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_data_ram_Pos                                                0U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_data_ram_Msk                                                (0x1FUL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_data_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cpu_ram_Pos                                                 5U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cpu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cpu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_usb_ram_Pos                                                 6U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_usb_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_usb_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_can_ram_Pos                                                 7U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_can_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_can_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cache_ram_Pos                                               8U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cache_ram_Msk                                               (0x1FFUL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_cache_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_amu_ram_Pos                                                 17U
#define PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_amu_ram_Msk                                                 (0x1UL << PLATFORM_REG_DRF_BIST_FAIL_bist_fail_drf_amu_ram_Pos)

#define PLATFORM_REG_DRF_BIST_FAIL_RSVD_Pos                                                                  18U
#define PLATFORM_REG_DRF_BIST_FAIL_RSVD_Msk                                                                  (0x3FFFUL << PLATFORM_REG_DRF_BIST_FAIL_RSVD_Pos)

/* 0x0064   0x4000_6064
    31:0    R       mcu_rom0_misr31_0                                   32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM0_MISR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t mcu_rom0_misr31_0;
    };
} PLATFORM_REG_MCU_ROM0_MISR0_TYPE;

/*0x4000_6064 PLATFORM_REG_MCU_ROM0_MISR0*/
#define PLATFORM_REG_MCU_ROM0_MISR0_mcu_rom0_misr31_0_Pos                                                    0U
#define PLATFORM_REG_MCU_ROM0_MISR0_mcu_rom0_misr31_0_Msk                                                    (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM0_MISR0_mcu_rom0_misr31_0_Pos)

/* 0x0068   0x4000_6068
    31:0    R       mcu_rom0_misr63_32                                  32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM0_MISR1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t mcu_rom0_misr63_32;
    };
} PLATFORM_REG_MCU_ROM0_MISR1_TYPE;

/*0x4000_6068 PLATFORM_REG_MCU_ROM0_MISR1*/
#define PLATFORM_REG_MCU_ROM0_MISR1_mcu_rom0_misr63_32_Pos                                                   0U
#define PLATFORM_REG_MCU_ROM0_MISR1_mcu_rom0_misr63_32_Msk                                                   (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM0_MISR1_mcu_rom0_misr63_32_Pos)

/* 0x006C   0x4000_606c
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM1_MISR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM1_MISR0_TYPE;

/*0x4000_606c PLATFORM_REG_MCU_ROM1_MISR0*/
#define PLATFORM_REG_MCU_ROM1_MISR0_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM1_MISR0_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM1_MISR0_RSVD_Pos)

/* 0x0070   0x4000_6070
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM1_MISR1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM1_MISR1_TYPE;

/*0x4000_6070 PLATFORM_REG_MCU_ROM1_MISR1*/
#define PLATFORM_REG_MCU_ROM1_MISR1_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM1_MISR1_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM1_MISR1_RSVD_Pos)

/* 0x0074   0x4000_6074
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM2_MISR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM2_MISR0_TYPE;

/*0x4000_6074 PLATFORM_REG_MCU_ROM2_MISR0*/
#define PLATFORM_REG_MCU_ROM2_MISR0_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM2_MISR0_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM2_MISR0_RSVD_Pos)

/* 0x0078   0x4000_6078
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM2_MISR1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM2_MISR1_TYPE;

/*0x4000_6078 PLATFORM_REG_MCU_ROM2_MISR1*/
#define PLATFORM_REG_MCU_ROM2_MISR1_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM2_MISR1_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM2_MISR1_RSVD_Pos)

/* 0x007C   0x4000_607c
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM3_MISR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM3_MISR0_TYPE;

/*0x4000_607c PLATFORM_REG_MCU_ROM3_MISR0*/
#define PLATFORM_REG_MCU_ROM3_MISR0_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM3_MISR0_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM3_MISR0_RSVD_Pos)

/* 0x0080   0x4000_6080
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM3_MISR1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM3_MISR1_TYPE;

/*0x4000_6080 PLATFORM_REG_MCU_ROM3_MISR1*/
#define PLATFORM_REG_MCU_ROM3_MISR1_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM3_MISR1_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM3_MISR1_RSVD_Pos)

/* 0x0084   0x4000_6084
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM4_MISR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM4_MISR0_TYPE;

/*0x4000_6084 PLATFORM_REG_MCU_ROM4_MISR0*/
#define PLATFORM_REG_MCU_ROM4_MISR0_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM4_MISR0_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM4_MISR0_RSVD_Pos)

/* 0x0088   0x4000_6088
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_REG_MCU_ROM4_MISR1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_REG_MCU_ROM4_MISR1_TYPE;

/*0x4000_6088 PLATFORM_REG_MCU_ROM4_MISR1*/
#define PLATFORM_REG_MCU_ROM4_MISR1_RSVD_Pos                                                                 0U
#define PLATFORM_REG_MCU_ROM4_MISR1_RSVD_Msk                                                                 (0xFFFFFFFFUL << PLATFORM_REG_MCU_ROM4_MISR1_RSVD_Pos)

/* 0x0090   0x4000_6090
    31:0    R/W     OUT_DATA0                                           32'h0
 */
typedef union _PLATFORM_REG_I2C_MAILBOX_OUT_DATA0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t OUT_DATA0;
    };
} PLATFORM_REG_I2C_MAILBOX_OUT_DATA0_TYPE;

/*0x4000_6090 PLATFORM_REG_I2C_MAILBOX_OUT_DATA0*/
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA0_OUT_DATA0_Pos                                                     0U
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA0_OUT_DATA0_Msk                                                     (0xFFFFFFFFUL << PLATFORM_REG_I2C_MAILBOX_OUT_DATA0_OUT_DATA0_Pos)

/* 0x0094   0x4000_6094
    31:0    R/W     OUT_DATA1                                           32'h0
 */
typedef union _PLATFORM_REG_I2C_MAILBOX_OUT_DATA1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t OUT_DATA1;
    };
} PLATFORM_REG_I2C_MAILBOX_OUT_DATA1_TYPE;

/*0x4000_6094 PLATFORM_REG_I2C_MAILBOX_OUT_DATA1*/
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA1_OUT_DATA1_Pos                                                     0U
#define PLATFORM_REG_I2C_MAILBOX_OUT_DATA1_OUT_DATA1_Msk                                                     (0xFFFFFFFFUL << PLATFORM_REG_I2C_MAILBOX_OUT_DATA1_OUT_DATA1_Pos)

/* 0x0098   0x4000_6098
    31:0    R       IN_DATA0                                            32'h0
 */
typedef union _PLATFORM_REG_I2C_MAILBOX_IN_DATA0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t IN_DATA0;
    };
} PLATFORM_REG_I2C_MAILBOX_IN_DATA0_TYPE;

/*0x4000_6098 PLATFORM_REG_I2C_MAILBOX_IN_DATA0*/
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA0_IN_DATA0_Pos                                                       0U
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA0_IN_DATA0_Msk                                                       (0xFFFFFFFFUL << PLATFORM_REG_I2C_MAILBOX_IN_DATA0_IN_DATA0_Pos)

/* 0x009C   0x4000_609c
    31:0    R       IN_DATA1                                            32'h0
 */
typedef union _PLATFORM_REG_I2C_MAILBOX_IN_DATA1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t IN_DATA1;
    };
} PLATFORM_REG_I2C_MAILBOX_IN_DATA1_TYPE;

/*0x4000_609c PLATFORM_REG_I2C_MAILBOX_IN_DATA1*/
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA1_IN_DATA1_Pos                                                       0U
#define PLATFORM_REG_I2C_MAILBOX_IN_DATA1_IN_DATA1_Msk                                                       (0xFFFFFFFFUL << PLATFORM_REG_I2C_MAILBOX_IN_DATA1_IN_DATA1_Pos)

/* 0x00A0   0x4000_60a0
    0       R/W1C   outbox_rdy_r                                        0
    1       R/W     out_empty_inten                                     0
    2       R/W     out_int_mode                                        0
    3       R/W1C   out_edge_sts                                        0
    4       R       rx_data_crc_ok                                      0
    15:5    R       RSVD_1                                              11'h0
    16      R/W1C   inbox_rdy_r                                         0
    17      R/W     in_rdy_inten                                        0
    30:18   R       RSVD                                                13'h0
    31      R/W     pta_i2c_en                                          0
 */
typedef union _PLATFORM_REG_I2C_MAILBOX_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t outbox_rdy_r: 1;
        uint32_t out_empty_inten: 1;
        uint32_t out_int_mode: 1;
        uint32_t out_edge_sts: 1;
        uint32_t rx_data_crc_ok: 1;
        uint32_t RSVD_1: 11;
        uint32_t inbox_rdy_r: 1;
        uint32_t in_rdy_inten: 1;
        uint32_t RSVD: 13;
        uint32_t pta_i2c_en: 1;
    };
} PLATFORM_REG_I2C_MAILBOX_CTRL_TYPE;

/*0x4000_60a0 PLATFORM_REG_I2C_MAILBOX_CTRL*/
#define PLATFORM_REG_I2C_MAILBOX_CTRL_outbox_rdy_r_Pos                                                       0U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_outbox_rdy_r_Msk                                                       (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_outbox_rdy_r_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_empty_inten_Pos                                                    1U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_empty_inten_Msk                                                    (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_out_empty_inten_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_int_mode_Pos                                                       2U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_int_mode_Msk                                                       (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_out_int_mode_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_edge_sts_Pos                                                       3U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_out_edge_sts_Msk                                                       (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_out_edge_sts_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_rx_data_crc_ok_Pos                                                     4U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_rx_data_crc_ok_Msk                                                     (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_rx_data_crc_ok_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_1_Pos                                                             5U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_1_Msk                                                             (0x7FFUL << PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_1_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_inbox_rdy_r_Pos                                                        16U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_inbox_rdy_r_Msk                                                        (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_inbox_rdy_r_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_in_rdy_inten_Pos                                                       17U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_in_rdy_inten_Msk                                                       (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_in_rdy_inten_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_Pos                                                               18U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_Msk                                                               (0x1FFFUL << PLATFORM_REG_I2C_MAILBOX_CTRL_RSVD_Pos)

#define PLATFORM_REG_I2C_MAILBOX_CTRL_pta_i2c_en_Pos                                                         31U
#define PLATFORM_REG_I2C_MAILBOX_CTRL_pta_i2c_en_Msk                                                         (0x1UL << PLATFORM_REG_I2C_MAILBOX_CTRL_pta_i2c_en_Pos)

/* 0x00A4   0x4000_60a4
    0       R/W     CM33_WICEN_REQ                                      1'b0
    1       R       CM33_WICEN_ACK                                      1'b0
    31:2    R       RSVD                                                30'h0
 */
typedef union _PLATFORM_WIC_HANDSHAKE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t CM33_WICEN_REQ: 1;
        uint32_t CM33_WICEN_ACK: 1;
        uint32_t RSVD: 30;
    };
} PLATFORM_WIC_HANDSHAKE_TYPE;

/*0x4000_60a4 PLATFORM_WIC_HANDSHAKE*/
#define PLATFORM_WIC_HANDSHAKE_CM33_WICEN_REQ_Pos                                                            0U
#define PLATFORM_WIC_HANDSHAKE_CM33_WICEN_REQ_Msk                                                            (0x1UL << PLATFORM_WIC_HANDSHAKE_CM33_WICEN_REQ_Pos)

#define PLATFORM_WIC_HANDSHAKE_CM33_WICEN_ACK_Pos                                                            1U
#define PLATFORM_WIC_HANDSHAKE_CM33_WICEN_ACK_Msk                                                            (0x1UL << PLATFORM_WIC_HANDSHAKE_CM33_WICEN_ACK_Pos)

#define PLATFORM_WIC_HANDSHAKE_RSVD_Pos                                                                      2U
#define PLATFORM_WIC_HANDSHAKE_RSVD_Msk                                                                      (0x3FFFFFFFUL << PLATFORM_WIC_HANDSHAKE_RSVD_Pos)

/* 0x00A8   0x4000_60a8
    3:0     R/W1C   WKUP_REASON_W1C                                     4'd0
    15:4    R       RSVD_1                                              12'd0
    19:16   R       RO_WKUP_REASON                                      4'd0
    31:20   R       RSVD                                                12'd0
 */
typedef union _PLATFORM_WKUP_REASON_CORE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WKUP_REASON_W1C: 4;
        uint32_t RSVD_1: 12;
        uint32_t RO_WKUP_REASON: 4;
        uint32_t RSVD: 12;
    };
} PLATFORM_WKUP_REASON_CORE_TYPE;

/*0x4000_60a8 PLATFORM_WKUP_REASON_CORE*/
#define PLATFORM_WKUP_REASON_CORE_WKUP_REASON_W1C_Pos                                                        0U
#define PLATFORM_WKUP_REASON_CORE_WKUP_REASON_W1C_Msk                                                        (0xFUL << PLATFORM_WKUP_REASON_CORE_WKUP_REASON_W1C_Pos)

#define PLATFORM_WKUP_REASON_CORE_RSVD_1_Pos                                                                 4U
#define PLATFORM_WKUP_REASON_CORE_RSVD_1_Msk                                                                 (0xFFFUL << PLATFORM_WKUP_REASON_CORE_RSVD_1_Pos)

#define PLATFORM_WKUP_REASON_CORE_RO_WKUP_REASON_Pos                                                         16U
#define PLATFORM_WKUP_REASON_CORE_RO_WKUP_REASON_Msk                                                         (0xFUL << PLATFORM_WKUP_REASON_CORE_RO_WKUP_REASON_Pos)

#define PLATFORM_WKUP_REASON_CORE_RSVD_Pos                                                                   20U
#define PLATFORM_WKUP_REASON_CORE_RSVD_Msk                                                                   (0xFFFUL << PLATFORM_WKUP_REASON_CORE_RSVD_Pos)

/* 0x00AC   0x4000_60ac
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_TYPE;

/*0x4000_60ac PLATFORM_Reserved*/
#define PLATFORM_Reserved_RSVD_Pos                                                                           0U
#define PLATFORM_Reserved_RSVD_Msk                                                                           (0xFFFFFFFFUL << PLATFORM_Reserved_RSVD_Pos)

/* 0x00B0   0x4000_60b0
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_1_TYPE;

/*0x4000_60b0 PLATFORM_Reserved_1*/
#define PLATFORM_Reserved_1_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_1_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_1_RSVD_Pos)

/* 0x00B4   0x4000_60b4
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_2_TYPE;

/*0x4000_60b4 PLATFORM_Reserved_2*/
#define PLATFORM_Reserved_2_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_2_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_2_RSVD_Pos)

/* 0x00B8   0x4000_60b8
    1:0     R/W     RSVD_3                                              2'h0
    4:2     R       RSVD_2                                              3'h0
    7:5     R/W     RSVD_1                                              3'h0
    31:8    R       RSVD                                                24'h0
 */
typedef union _PLATFORM_REG_SNPS_SRAM_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_3: 2;
        uint32_t RSVD_2: 3;
        uint32_t RSVD_1: 3;
        uint32_t RSVD: 24;
    };
} PLATFORM_REG_SNPS_SRAM_CTRL_TYPE;

/*0x4000_60b8 PLATFORM_REG_SNPS_SRAM_CTRL*/
#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_3_Pos                                                               0U
#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_3_Msk                                                               (0x3UL << PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_3_Pos)

#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_2_Pos                                                               2U
#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_2_Msk                                                               (0x7UL << PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_2_Pos)

#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_1_Pos                                                               5U
#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_1_Msk                                                               (0x7UL << PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_1_Pos)

#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_Pos                                                                 8U
#define PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_Msk                                                                 (0xFFFFFFUL << PLATFORM_REG_SNPS_SRAM_CTRL_RSVD_Pos)

/* 0x00BC   0x4000_60bc
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_3_TYPE;

/*0x4000_60bc PLATFORM_Reserved_3*/
#define PLATFORM_Reserved_3_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_3_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_3_RSVD_Pos)

/* 0x00C0   0x4000_60c0
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_4_TYPE;

/*0x4000_60c0 PLATFORM_Reserved_4*/
#define PLATFORM_Reserved_4_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_4_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_4_RSVD_Pos)

/* 0x00C4   0x4000_60c4
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_5_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_5_TYPE;

/*0x4000_60c4 PLATFORM_Reserved_5*/
#define PLATFORM_Reserved_5_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_5_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_5_RSVD_Pos)

/* 0x00C8   0x4000_60c8
    0       R/W     bisr_remap_rstn_data_ram                            1'b0
    1       R/W     bisr_load_fuse_data_ram                             1'b0
    19:2    R/W     bisr_remap_sig_data_ram                             18'h0
    20      R/W     bisr_second_run_data_ram                            1'b0
    21      R/W     bisr_hold_remap_data_ram                            1'b0
    22      R/W     bisr_pwr_rstn_data_ram                              1'b1
    31:23   R       RSVD                                                9'h0
 */
typedef union _PLATFORM_REG_MBISR_DATA_SRAM_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bisr_remap_rstn_data_ram: 1;
        uint32_t bisr_load_fuse_data_ram: 1;
        uint32_t bisr_remap_sig_data_ram: 18;
        uint32_t bisr_second_run_data_ram: 1;
        uint32_t bisr_hold_remap_data_ram: 1;
        uint32_t bisr_pwr_rstn_data_ram: 1;
        uint32_t RSVD: 9;
    };
} PLATFORM_REG_MBISR_DATA_SRAM_CTRL_TYPE;

/*0x4000_60c8 PLATFORM_REG_MBISR_DATA_SRAM_CTRL*/
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_rstn_data_ram_Pos                                       0U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_rstn_data_ram_Msk                                       (0x1UL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_rstn_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_load_fuse_data_ram_Pos                                        1U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_load_fuse_data_ram_Msk                                        (0x1UL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_load_fuse_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_sig_data_ram_Pos                                        2U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_sig_data_ram_Msk                                        (0x3FFFFUL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_remap_sig_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_second_run_data_ram_Pos                                       20U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_second_run_data_ram_Msk                                       (0x1UL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_second_run_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_hold_remap_data_ram_Pos                                       21U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_hold_remap_data_ram_Msk                                       (0x1UL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_hold_remap_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_pwr_rstn_data_ram_Pos                                         22U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_pwr_rstn_data_ram_Msk                                         (0x1UL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_bisr_pwr_rstn_data_ram_Pos)

#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_RSVD_Pos                                                           23U
#define PLATFORM_REG_MBISR_DATA_SRAM_CTRL_RSVD_Msk                                                           (0x1FFUL << PLATFORM_REG_MBISR_DATA_SRAM_CTRL_RSVD_Pos)

/* 0x00CC   0x4000_60cc
    0       R/W     bisr_remap_rstn_buffer_ram                          1'b0
    1       R/W     bisr_load_fuse_buffer_ram                           1'b0
    8:2     R/W     bisr_remap_sig_buffer_ram                           7'h0
    9       R/W     bisr_second_run_buffer_ram                          1'b0
    10      R/W     bisr_hold_remap_buffer_ram                          1'b0
    11      R/W     bisr_pwr_rstn_buffer_ram                            1'b1
    31:12   R       RSVD                                                20'h0
 */
typedef union _PLATFORM_REG_MBISR_BUF_SRAM_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bisr_remap_rstn_buffer_ram: 1;
        uint32_t bisr_load_fuse_buffer_ram: 1;
        uint32_t bisr_remap_sig_buffer_ram: 7;
        uint32_t bisr_second_run_buffer_ram: 1;
        uint32_t bisr_hold_remap_buffer_ram: 1;
        uint32_t bisr_pwr_rstn_buffer_ram: 1;
        uint32_t RSVD: 20;
    };
} PLATFORM_REG_MBISR_BUF_SRAM_CTRL_TYPE;

/*0x4000_60cc PLATFORM_REG_MBISR_BUF_SRAM_CTRL*/
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_rstn_buffer_ram_Pos                                      0U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_rstn_buffer_ram_Msk                                      (0x1UL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_rstn_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_load_fuse_buffer_ram_Pos                                       1U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_load_fuse_buffer_ram_Msk                                       (0x1UL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_load_fuse_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_sig_buffer_ram_Pos                                       2U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_sig_buffer_ram_Msk                                       (0x7FUL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_remap_sig_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_second_run_buffer_ram_Pos                                      9U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_second_run_buffer_ram_Msk                                      (0x1UL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_second_run_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_hold_remap_buffer_ram_Pos                                      10U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_hold_remap_buffer_ram_Msk                                      (0x1UL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_hold_remap_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_pwr_rstn_buffer_ram_Pos                                        11U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_pwr_rstn_buffer_ram_Msk                                        (0x1UL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_bisr_pwr_rstn_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_RSVD_Pos                                                            12U
#define PLATFORM_REG_MBISR_BUF_SRAM_CTRL_RSVD_Msk                                                            (0xFFFFFUL << PLATFORM_REG_MBISR_BUF_SRAM_CTRL_RSVD_Pos)

/* 0x00D0   0x4000_60d0
    6:0     R       bisr_out_buffer_ram                                 7'h0
    7       R       bisr_repaired_buffer_ram                            0
    9:8     R       RSVD_1                                              2'h0
    27:10   R       bisr_out_data_ram                                   18'h0
    28      R       bisr_repaired_data_ram                              0
    31:29   R       RSVD                                                3'h0
 */
typedef union _PLATFORM_REG_MBISR_SRAM_RESULT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bisr_out_buffer_ram: 7;
        uint32_t bisr_repaired_buffer_ram: 1;
        uint32_t RSVD_1: 2;
        uint32_t bisr_out_data_ram: 18;
        uint32_t bisr_repaired_data_ram: 1;
        uint32_t RSVD: 3;
    };
} PLATFORM_REG_MBISR_SRAM_RESULT_TYPE;

/*0x4000_60d0 PLATFORM_REG_MBISR_SRAM_RESULT*/
#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_buffer_ram_Pos                                               0U
#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_buffer_ram_Msk                                               (0x7FUL << PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_buffer_ram_Pos                                          7U
#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_buffer_ram_Msk                                          (0x1UL << PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_buffer_ram_Pos)

#define PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_1_Pos                                                            8U
#define PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_1_Msk                                                            (0x3UL << PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_1_Pos)

#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_data_ram_Pos                                                 10U
#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_data_ram_Msk                                                 (0x3FFFFUL << PLATFORM_REG_MBISR_SRAM_RESULT_bisr_out_data_ram_Pos)

#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_data_ram_Pos                                            28U
#define PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_data_ram_Msk                                            (0x1UL << PLATFORM_REG_MBISR_SRAM_RESULT_bisr_repaired_data_ram_Pos)

#define PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_Pos                                                              29U
#define PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_Msk                                                              (0x7UL << PLATFORM_REG_MBISR_SRAM_RESULT_RSVD_Pos)

/* 0x00D4   0x4000_60d4
    0       R/W     bist_dyn_read_en_data_ram                           0
    1       R/W     bist_dyn_read_en_cpu_ram                            0
    2       R/W     bist_dyn_read_en_usb_ram                            0
    3       R/W     bist_dyn_read_en_can_ram                            0
    4       R/W     bist_dyn_read_en_leslv_ram                          0
    5       R/W     bist_dyn_read_en_lecis_ram                          0
    6       R/W     bist_dyn_read_en_lebis_ram                          0
    7       R/W     bist_dyn_read_en_buffer_ram                         0
    8       R/W     bist_dyn_read_en_audio_ram                          0
    9       R/W     bist_dyn_read_en_btphy_ram                          0
    10      R/W     bist_dyn_read_en_ccmp_ram                           0
    11      R/W     bist_dyn_read_en_btrx_ram                           0
    12      R/W     bist_dyn_read_en_bttx_ram                           0
    13      R/W     bist_dyn_read_en_lepa_ram                           0
    14      R/W     bist_dyn_read_en_lemst_ram                          0
    15      R/W     bist_dyn_read_en_cache_ram                          0
    16      R/W     bist_dyn_read_en_amu_ram                            0
    31:17   R       RSVD                                                15'h0
 */
typedef union _PLATFORM_REG_DYN_READ_EN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_dyn_read_en_data_ram: 1;
        uint32_t bist_dyn_read_en_cpu_ram: 1;
        uint32_t bist_dyn_read_en_usb_ram: 1;
        uint32_t bist_dyn_read_en_can_ram: 1;
        uint32_t bist_dyn_read_en_leslv_ram: 1;
        uint32_t bist_dyn_read_en_lecis_ram: 1;
        uint32_t bist_dyn_read_en_lebis_ram: 1;
        uint32_t bist_dyn_read_en_buffer_ram: 1;
        uint32_t bist_dyn_read_en_audio_ram: 1;
        uint32_t bist_dyn_read_en_btphy_ram: 1;
        uint32_t bist_dyn_read_en_ccmp_ram: 1;
        uint32_t bist_dyn_read_en_btrx_ram: 1;
        uint32_t bist_dyn_read_en_bttx_ram: 1;
        uint32_t bist_dyn_read_en_lepa_ram: 1;
        uint32_t bist_dyn_read_en_lemst_ram: 1;
        uint32_t bist_dyn_read_en_cache_ram: 1;
        uint32_t bist_dyn_read_en_amu_ram: 1;
        uint32_t RSVD: 15;
    };
} PLATFORM_REG_DYN_READ_EN_TYPE;

/*0x4000_60d4 PLATFORM_REG_DYN_READ_EN*/
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_data_ram_Pos                                               0U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_data_ram_Msk                                               (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_data_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cpu_ram_Pos                                                1U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cpu_ram_Msk                                                (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cpu_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_usb_ram_Pos                                                2U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_usb_ram_Msk                                                (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_usb_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_can_ram_Pos                                                3U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_can_ram_Msk                                                (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_can_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_leslv_ram_Pos                                              4U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_leslv_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_leslv_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lecis_ram_Pos                                              5U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lecis_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lecis_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lebis_ram_Pos                                              6U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lebis_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lebis_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_buffer_ram_Pos                                             7U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_buffer_ram_Msk                                             (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_buffer_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_audio_ram_Pos                                              8U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_audio_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_audio_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btphy_ram_Pos                                              9U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btphy_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btphy_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_ccmp_ram_Pos                                               10U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_ccmp_ram_Msk                                               (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_ccmp_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btrx_ram_Pos                                               11U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btrx_ram_Msk                                               (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_btrx_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_bttx_ram_Pos                                               12U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_bttx_ram_Msk                                               (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_bttx_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lepa_ram_Pos                                               13U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lepa_ram_Msk                                               (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lepa_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lemst_ram_Pos                                              14U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lemst_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_lemst_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cache_ram_Pos                                              15U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cache_ram_Msk                                              (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_cache_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_amu_ram_Pos                                                16U
#define PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_amu_ram_Msk                                                (0x1UL << PLATFORM_REG_DYN_READ_EN_bist_dyn_read_en_amu_ram_Pos)

#define PLATFORM_REG_DYN_READ_EN_RSVD_Pos                                                                    17U
#define PLATFORM_REG_DYN_READ_EN_RSVD_Msk                                                                    (0x7FFFUL << PLATFORM_REG_DYN_READ_EN_RSVD_Pos)

/* 0x00D8   0x4000_60d8
    0       R/W     bist_loop_mode_data_ram                             0
    1       R/W     bist_loop_mode_cpu_ram                              0
    2       R/W     bist_loop_mode_usb_ram                              0
    3       R/W     bist_loop_mode_can_ram                              0
    4       R/W     bist_loop_mode_cache_ram                            0
    5       R/W     bist_loop_mode_amu_ram                              0
    31:6    R       RSVD                                                26'h0
 */
typedef union _PLATFORM_REG_BIST_LOOP_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_loop_mode_data_ram: 1;
        uint32_t bist_loop_mode_cpu_ram: 1;
        uint32_t bist_loop_mode_usb_ram: 1;
        uint32_t bist_loop_mode_can_ram: 1;
        uint32_t bist_loop_mode_cache_ram: 1;
        uint32_t bist_loop_mode_amu_ram: 1;
        uint32_t RSVD: 26;
    };
} PLATFORM_REG_BIST_LOOP_MODE_TYPE;

/*0x4000_60d8 PLATFORM_REG_BIST_LOOP_MODE*/
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_data_ram_Pos                                              0U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_data_ram_Msk                                              (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_data_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cpu_ram_Pos                                               1U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cpu_ram_Msk                                               (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cpu_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_usb_ram_Pos                                               2U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_usb_ram_Msk                                               (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_usb_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_can_ram_Pos                                               3U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_can_ram_Msk                                               (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_can_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cache_ram_Pos                                             4U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cache_ram_Msk                                             (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_cache_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_amu_ram_Pos                                               5U
#define PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_amu_ram_Msk                                               (0x1UL << PLATFORM_REG_BIST_LOOP_MODE_bist_loop_mode_amu_ram_Pos)

#define PLATFORM_REG_BIST_LOOP_MODE_RSVD_Pos                                                                 6U
#define PLATFORM_REG_BIST_LOOP_MODE_RSVD_Msk                                                                 (0x3FFFFFFUL << PLATFORM_REG_BIST_LOOP_MODE_RSVD_Pos)

/* 0x00DC   0x4000_60dc
    0       R/W     bist_loop_mode_leslv_ram                            0
    1       R/W     bist_loop_mode_lecis_ram                            0
    2       R/W     bist_loop_mode_lebis_ram                            0
    3       R/W     bist_loop_mode_buffer_ram                           0
    4       R/W     bist_loop_mode_audio_ram                            0
    5       R/W     bist_loop_mode_btphy_ram                            0
    6       R/W     bist_loop_mode_ccmp_ram                             0
    7       R/W     bist_loop_mode_btrx_ram                             0
    8       R/W     bist_loop_mode_bttx_ram                             0
    9       R/W     bist_loop_mode_lepa_ram                             0
    10      R/W     bist_loop_mode_lemst_ram                            0
    11      R       RSVD_2                                              0
    12      R/W     RSVD_1                                              0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_LOOP_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_loop_mode_leslv_ram: 1;
        uint32_t bist_loop_mode_lecis_ram: 1;
        uint32_t bist_loop_mode_lebis_ram: 1;
        uint32_t bist_loop_mode_buffer_ram: 1;
        uint32_t bist_loop_mode_audio_ram: 1;
        uint32_t bist_loop_mode_btphy_ram: 1;
        uint32_t bist_loop_mode_ccmp_ram: 1;
        uint32_t bist_loop_mode_btrx_ram: 1;
        uint32_t bist_loop_mode_bttx_ram: 1;
        uint32_t bist_loop_mode_lepa_ram: 1;
        uint32_t bist_loop_mode_lemst_ram: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_LOOP_MODE_TYPE;

/*0x4000_60dc PLATFORM_REG_BT_BIST_LOOP_MODE*/
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_leslv_ram_Pos                                          0U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_leslv_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lecis_ram_Pos                                          1U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lecis_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lebis_ram_Pos                                          2U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lebis_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_buffer_ram_Pos                                         3U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_buffer_ram_Msk                                         (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_audio_ram_Pos                                          4U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_audio_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btphy_ram_Pos                                          5U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btphy_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_ccmp_ram_Pos                                           6U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_ccmp_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btrx_ram_Pos                                           7U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btrx_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_bttx_ram_Pos                                           8U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_bttx_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lepa_ram_Pos                                           9U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lepa_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lemst_ram_Pos                                          10U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lemst_ram_Msk                                          (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_bist_loop_mode_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_2_Pos                                                            11U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_2_Msk                                                            (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_2_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_1_Pos                                                            12U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_1_Msk                                                            (0x1UL << PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_Pos                                                              13U
#define PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_Msk                                                              (0x7FFFFUL << PLATFORM_REG_BT_BIST_LOOP_MODE_RSVD_Pos)

/* 0x00E0   0x4000_60e0
    0       R/W     bist_rstn_leslv_ram                                 0
    1       R/W     bist_rstn_lecis_ram                                 0
    2       R/W     bist_rstn_lebis_ram                                 0
    3       R/W     bist_rstn_buffer_ram                                0
    4       R/W     bist_rstn_audio_ram                                 0
    5       R/W     bist_rstn_btphy_ram                                 0
    6       R/W     bist_rstn_ccmp_ram                                  0
    7       R/W     bist_rstn_btrx_ram                                  0
    8       R/W     bist_rstn_bttx_ram                                  0
    9       R/W     bist_rstn_lepa_ram                                  0
    10      R/W     bist_rstn_lemst_ram                                 0
    11      R       RSVD_2                                              0
    12      R/W     RSVD_1                                              0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_RSTN_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_rstn_leslv_ram: 1;
        uint32_t bist_rstn_lecis_ram: 1;
        uint32_t bist_rstn_lebis_ram: 1;
        uint32_t bist_rstn_buffer_ram: 1;
        uint32_t bist_rstn_audio_ram: 1;
        uint32_t bist_rstn_btphy_ram: 1;
        uint32_t bist_rstn_ccmp_ram: 1;
        uint32_t bist_rstn_btrx_ram: 1;
        uint32_t bist_rstn_bttx_ram: 1;
        uint32_t bist_rstn_lepa_ram: 1;
        uint32_t bist_rstn_lemst_ram: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_RSTN_TYPE;

/*0x4000_60e0 PLATFORM_REG_BT_BIST_RSTN*/
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_leslv_ram_Pos                                                    0U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_leslv_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lecis_ram_Pos                                                    1U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lecis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lebis_ram_Pos                                                    2U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lebis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_buffer_ram_Pos                                                   3U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_buffer_ram_Msk                                                   (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_audio_ram_Pos                                                    4U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_audio_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btphy_ram_Pos                                                    5U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btphy_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_ccmp_ram_Pos                                                     6U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_ccmp_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btrx_ram_Pos                                                     7U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btrx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_bttx_ram_Pos                                                     8U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_bttx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lepa_ram_Pos                                                     9U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lepa_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lemst_ram_Pos                                                    10U
#define PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lemst_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_RSTN_bist_rstn_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_RSVD_2_Pos                                                                 11U
#define PLATFORM_REG_BT_BIST_RSTN_RSVD_2_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_RSTN_RSVD_2_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_RSVD_1_Pos                                                                 12U
#define PLATFORM_REG_BT_BIST_RSTN_RSVD_1_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_RSTN_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_RSTN_RSVD_Pos                                                                   13U
#define PLATFORM_REG_BT_BIST_RSTN_RSVD_Msk                                                                   (0x7FFFFUL << PLATFORM_REG_BT_BIST_RSTN_RSVD_Pos)

/* 0x00E4   0x4000_60e4
    0       R/W     bist_mode_leslv_ram                                 0
    1       R/W     bist_mode_lecis_ram                                 0
    2       R/W     bist_mode_lebis_ram                                 0
    3       R/W     bist_mode_buffer_ram                                0
    4       R/W     bist_mode_audio_ram                                 0
    5       R/W     bist_mode_btphy_ram                                 0
    6       R/W     bist_mode_ccmp_ram                                  0
    7       R/W     bist_mode_btrx_ram                                  0
    8       R/W     bist_mode_bttx_ram                                  0
    9       R/W     bist_mode_lepa_ram                                  0
    10      R/W     bist_mode_lemst_ram                                 0
    11      R       RSVD_2                                              0
    12      R/W     RSVD_1                                              0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_mode_leslv_ram: 1;
        uint32_t bist_mode_lecis_ram: 1;
        uint32_t bist_mode_lebis_ram: 1;
        uint32_t bist_mode_buffer_ram: 1;
        uint32_t bist_mode_audio_ram: 1;
        uint32_t bist_mode_btphy_ram: 1;
        uint32_t bist_mode_ccmp_ram: 1;
        uint32_t bist_mode_btrx_ram: 1;
        uint32_t bist_mode_bttx_ram: 1;
        uint32_t bist_mode_lepa_ram: 1;
        uint32_t bist_mode_lemst_ram: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_MODE_TYPE;

/*0x4000_60e4 PLATFORM_REG_BT_BIST_MODE*/
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_leslv_ram_Pos                                                    0U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_leslv_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lecis_ram_Pos                                                    1U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lecis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lebis_ram_Pos                                                    2U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lebis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_buffer_ram_Pos                                                   3U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_buffer_ram_Msk                                                   (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_audio_ram_Pos                                                    4U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_audio_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_btphy_ram_Pos                                                    5U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_btphy_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_ccmp_ram_Pos                                                     6U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_ccmp_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_btrx_ram_Pos                                                     7U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_btrx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_bttx_ram_Pos                                                     8U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_bttx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lepa_ram_Pos                                                     9U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lepa_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lemst_ram_Pos                                                    10U
#define PLATFORM_REG_BT_BIST_MODE_bist_mode_lemst_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_MODE_bist_mode_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_MODE_RSVD_2_Pos                                                                 11U
#define PLATFORM_REG_BT_BIST_MODE_RSVD_2_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_MODE_RSVD_2_Pos)

#define PLATFORM_REG_BT_BIST_MODE_RSVD_1_Pos                                                                 12U
#define PLATFORM_REG_BT_BIST_MODE_RSVD_1_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_MODE_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_MODE_RSVD_Pos                                                                   13U
#define PLATFORM_REG_BT_BIST_MODE_RSVD_Msk                                                                   (0x7FFFFUL << PLATFORM_REG_BT_BIST_MODE_RSVD_Pos)

/* 0x00E8   0x4000_60e8
    0       R/W     bist_mode_drf_leslv_ram                             0
    1       R/W     bist_mode_drf_lecis_ram                             0
    2       R/W     bist_mode_drf_lebis_ram                             0
    3       R/W     bist_mode_drf_buffer_ram                            0
    4       R/W     bist_mode_drf_audio_ram                             0
    5       R/W     bist_mode_drf_btphy_ram                             0
    6       R/W     bist_mode_drf_ccmp_ram                              0
    7       R/W     bist_mode_drf_btrx_ram                              0
    8       R/W     bist_mode_drf_bttx_ram                              0
    9       R/W     bist_mode_drf_lepa_ram                              0
    10      R/W     bist_mode_drf_lemst_ram                             0
    11      R       RSVD_2                                              0
    12      R/W     RSVD_1                                              0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_DRF_BIST_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_mode_drf_leslv_ram: 1;
        uint32_t bist_mode_drf_lecis_ram: 1;
        uint32_t bist_mode_drf_lebis_ram: 1;
        uint32_t bist_mode_drf_buffer_ram: 1;
        uint32_t bist_mode_drf_audio_ram: 1;
        uint32_t bist_mode_drf_btphy_ram: 1;
        uint32_t bist_mode_drf_ccmp_ram: 1;
        uint32_t bist_mode_drf_btrx_ram: 1;
        uint32_t bist_mode_drf_bttx_ram: 1;
        uint32_t bist_mode_drf_lepa_ram: 1;
        uint32_t bist_mode_drf_lemst_ram: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_DRF_BIST_MODE_TYPE;

/*0x4000_60e8 PLATFORM_REG_BT_DRF_BIST_MODE*/
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_leslv_ram_Pos                                            0U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_leslv_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_leslv_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lecis_ram_Pos                                            1U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lecis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lecis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lebis_ram_Pos                                            2U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lebis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lebis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_buffer_ram_Pos                                           3U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_buffer_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_buffer_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_audio_ram_Pos                                            4U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_audio_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_audio_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btphy_ram_Pos                                            5U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btphy_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btphy_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_ccmp_ram_Pos                                             6U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_ccmp_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_ccmp_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btrx_ram_Pos                                             7U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btrx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_btrx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_bttx_ram_Pos                                             8U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_bttx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_bttx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lepa_ram_Pos                                             9U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lepa_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lepa_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lemst_ram_Pos                                            10U
#define PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lemst_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_bist_mode_drf_lemst_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_2_Pos                                                             11U
#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_2_Msk                                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_2_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_1_Pos                                                             12U
#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_1_Msk                                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_1_Pos)

#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_Pos                                                               13U
#define PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_Msk                                                               (0x7FFFFUL << PLATFORM_REG_BT_DRF_BIST_MODE_RSVD_Pos)

/* 0x00EC   0x4000_60ec
    0       R/W     bist_test_resume_leslv_ram                          0
    1       R/W     bist_test_resume_lecis_ram                          0
    2       R/W     bist_test_resume_lebis_ram                          0
    3       R/W     bist_test_resume_buffer_ram                         0
    4       R/W     bist_test_resume_audio_ram                          0
    5       R/W     bist_test_resume_btphy_ram                          0
    6       R/W     bist_test_resume_ccmp_ram                           0
    7       R/W     bist_test_resume_btrx_ram                           0
    8       R/W     bist_test_resume_bttx_ram                           0
    9       R/W     bist_test_resume_lepa_ram                           0
    10      R/W     bist_test_resume_lemst_ram                          0
    11      R       RSVD_2                                              0
    12      R/W     RSVD_1                                              0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_TEST_RESUME_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_test_resume_leslv_ram: 1;
        uint32_t bist_test_resume_lecis_ram: 1;
        uint32_t bist_test_resume_lebis_ram: 1;
        uint32_t bist_test_resume_buffer_ram: 1;
        uint32_t bist_test_resume_audio_ram: 1;
        uint32_t bist_test_resume_btphy_ram: 1;
        uint32_t bist_test_resume_ccmp_ram: 1;
        uint32_t bist_test_resume_btrx_ram: 1;
        uint32_t bist_test_resume_bttx_ram: 1;
        uint32_t bist_test_resume_lepa_ram: 1;
        uint32_t bist_test_resume_lemst_ram: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_TEST_RESUME_TYPE;

/*0x4000_60ec PLATFORM_REG_BT_BIST_TEST_RESUME*/
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_leslv_ram_Pos                                      0U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_leslv_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lecis_ram_Pos                                      1U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lecis_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lebis_ram_Pos                                      2U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lebis_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_buffer_ram_Pos                                     3U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_buffer_ram_Msk                                     (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_audio_ram_Pos                                      4U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_audio_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btphy_ram_Pos                                      5U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btphy_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_ccmp_ram_Pos                                       6U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_ccmp_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btrx_ram_Pos                                       7U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btrx_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_bttx_ram_Pos                                       8U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_bttx_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lepa_ram_Pos                                       9U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lepa_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lemst_ram_Pos                                      10U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lemst_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_bist_test_resume_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_2_Pos                                                          11U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_2_Msk                                                          (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_2_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_1_Pos                                                          12U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_1_Msk                                                          (0x1UL << PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_Pos                                                            13U
#define PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_Msk                                                            (0x7FFFFUL << PLATFORM_REG_BT_BIST_TEST_RESUME_RSVD_Pos)

/* 0x00F0   0x4000_60f0
    0       R       bist_start_pause_leslv_ram                          0
    1       R       bist_start_pause_lecis_ram                          0
    2       R       bist_start_pause_lebis_ram                          0
    3       R       bist_start_pause_buffer_ram                         0
    4       R       bist_start_pause_audio_ram                          0
    5       R       bist_start_pause_btphy_ram                          0
    6       R       bist_start_pause_ccmp_ram                           0
    7       R       bist_start_pause_btrx_ram                           0
    8       R       bist_start_pause_bttx_ram                           0
    9       R       bist_start_pause_lepa_ram                           0
    10      R       bist_start_pause_lemst_ram                          0
    11      R       RSVD_1                                              0
    12      R       bist_start_pause_buffer_8k_ram                      0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_START_PAUSE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_start_pause_leslv_ram: 1;
        uint32_t bist_start_pause_lecis_ram: 1;
        uint32_t bist_start_pause_lebis_ram: 1;
        uint32_t bist_start_pause_buffer_ram: 1;
        uint32_t bist_start_pause_audio_ram: 1;
        uint32_t bist_start_pause_btphy_ram: 1;
        uint32_t bist_start_pause_ccmp_ram: 1;
        uint32_t bist_start_pause_btrx_ram: 1;
        uint32_t bist_start_pause_bttx_ram: 1;
        uint32_t bist_start_pause_lepa_ram: 1;
        uint32_t bist_start_pause_lemst_ram: 1;
        uint32_t RSVD_1: 1;
        uint32_t bist_start_pause_buffer_8k_ram: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_START_PAUSE_TYPE;

/*0x4000_60f0 PLATFORM_REG_BT_BIST_START_PAUSE*/
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_leslv_ram_Pos                                      0U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_leslv_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lecis_ram_Pos                                      1U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lecis_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lebis_ram_Pos                                      2U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lebis_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_ram_Pos                                     3U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_ram_Msk                                     (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_audio_ram_Pos                                      4U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_audio_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btphy_ram_Pos                                      5U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btphy_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_ccmp_ram_Pos                                       6U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_ccmp_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btrx_ram_Pos                                       7U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btrx_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_bttx_ram_Pos                                       8U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_bttx_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lepa_ram_Pos                                       9U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lepa_ram_Msk                                       (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lemst_ram_Pos                                      10U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lemst_ram_Msk                                      (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_1_Pos                                                          11U
#define PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_1_Msk                                                          (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_8k_ram_Pos                                  12U
#define PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_8k_ram_Msk                                  (0x1UL << PLATFORM_REG_BT_BIST_START_PAUSE_bist_start_pause_buffer_8k_ram_Pos)

#define PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_Pos                                                            13U
#define PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_Msk                                                            (0x7FFFFUL << PLATFORM_REG_BT_BIST_START_PAUSE_RSVD_Pos)

/* 0x00F4   0x4000_60f4
    0       R       bist_done_leslv_ram                                 0
    1       R       bist_done_lecis_ram                                 0
    2       R       bist_done_lebis_ram                                 0
    3       R       bist_done_buffer_ram                                0
    4       R       bist_done_audio_ram                                 0
    5       R       bist_done_btphy_ram                                 0
    6       R       bist_done_ccmp_ram                                  0
    7       R       bist_done_btrx_ram                                  0
    8       R       bist_done_bttx_ram                                  0
    9       R       bist_done_lepa_ram                                  0
    10      R       bist_done_lemst_ram                                 0
    11      R       RSVD_1                                              0
    12      R       bist_done_buffer_8k_ram                             0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_BIST_DONE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_done_leslv_ram: 1;
        uint32_t bist_done_lecis_ram: 1;
        uint32_t bist_done_lebis_ram: 1;
        uint32_t bist_done_buffer_ram: 1;
        uint32_t bist_done_audio_ram: 1;
        uint32_t bist_done_btphy_ram: 1;
        uint32_t bist_done_ccmp_ram: 1;
        uint32_t bist_done_btrx_ram: 1;
        uint32_t bist_done_bttx_ram: 1;
        uint32_t bist_done_lepa_ram: 1;
        uint32_t bist_done_lemst_ram: 1;
        uint32_t RSVD_1: 1;
        uint32_t bist_done_buffer_8k_ram: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_BIST_DONE_TYPE;

/*0x4000_60f4 PLATFORM_REG_BT_BIST_DONE*/
#define PLATFORM_REG_BT_BIST_DONE_bist_done_leslv_ram_Pos                                                    0U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_leslv_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_lecis_ram_Pos                                                    1U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_lecis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_lebis_ram_Pos                                                    2U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_lebis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_ram_Pos                                                   3U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_ram_Msk                                                   (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_audio_ram_Pos                                                    4U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_audio_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_btphy_ram_Pos                                                    5U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_btphy_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_ccmp_ram_Pos                                                     6U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_ccmp_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_btrx_ram_Pos                                                     7U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_btrx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_bttx_ram_Pos                                                     8U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_bttx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_lepa_ram_Pos                                                     9U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_lepa_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_lemst_ram_Pos                                                    10U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_lemst_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_RSVD_1_Pos                                                                 11U
#define PLATFORM_REG_BT_BIST_DONE_RSVD_1_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_DONE_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_8k_ram_Pos                                                12U
#define PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_8k_ram_Msk                                                (0x1UL << PLATFORM_REG_BT_BIST_DONE_bist_done_buffer_8k_ram_Pos)

#define PLATFORM_REG_BT_BIST_DONE_RSVD_Pos                                                                   13U
#define PLATFORM_REG_BT_BIST_DONE_RSVD_Msk                                                                   (0x7FFFFUL << PLATFORM_REG_BT_BIST_DONE_RSVD_Pos)

/* 0x00F8   0x4000_60f8
    0       R       bist_fail_leslv_ram                                 0
    1       R       bist_fail_lecis_ram                                 0
    2       R       bist_fail_lebis_ram                                 0
    3       R       bist_fail_buffer_ram                                0
    4       R       bist_fail_audio_ram                                 0
    8:5     R       bist_fail_btphy_ram                                 4'b0000
    11:9    R       bist_fail_ccmp_ram                                  3'b000
    12      R       bist_fail_btrx_ram                                  0
    13      R       bist_fail_bttx_ram                                  0
    14      R       bist_fail_lepa_ram                                  0
    15      R       bist_fail_lemst_ram                                 0
    16      R       RSVD_1                                              0
    17      R       bist_fail_buffer_8k_ram                             0
    31:18   R       RSVD                                                14'h0
 */
typedef union _PLATFORM_REG_BT_BIST_FAIL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_fail_leslv_ram: 1;
        uint32_t bist_fail_lecis_ram: 1;
        uint32_t bist_fail_lebis_ram: 1;
        uint32_t bist_fail_buffer_ram: 1;
        uint32_t bist_fail_audio_ram: 1;
        uint32_t bist_fail_btphy_ram: 4;
        uint32_t bist_fail_ccmp_ram: 3;
        uint32_t bist_fail_btrx_ram: 1;
        uint32_t bist_fail_bttx_ram: 1;
        uint32_t bist_fail_lepa_ram: 1;
        uint32_t bist_fail_lemst_ram: 1;
        uint32_t RSVD_1: 1;
        uint32_t bist_fail_buffer_8k_ram: 1;
        uint32_t RSVD: 14;
    };
} PLATFORM_REG_BT_BIST_FAIL_TYPE;

/*0x4000_60f8 PLATFORM_REG_BT_BIST_FAIL*/
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_leslv_ram_Pos                                                    0U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_leslv_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_leslv_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lecis_ram_Pos                                                    1U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lecis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_lecis_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lebis_ram_Pos                                                    2U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lebis_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_lebis_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_ram_Pos                                                   3U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_ram_Msk                                                   (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_audio_ram_Pos                                                    4U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_audio_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_audio_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_btphy_ram_Pos                                                    5U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_btphy_ram_Msk                                                    (0xFUL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_btphy_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_ccmp_ram_Pos                                                     9U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_ccmp_ram_Msk                                                     (0x7UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_ccmp_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_btrx_ram_Pos                                                     12U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_btrx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_btrx_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_bttx_ram_Pos                                                     13U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_bttx_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_bttx_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lepa_ram_Pos                                                     14U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lepa_ram_Msk                                                     (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_lepa_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lemst_ram_Pos                                                    15U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_lemst_ram_Msk                                                    (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_lemst_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_RSVD_1_Pos                                                                 16U
#define PLATFORM_REG_BT_BIST_FAIL_RSVD_1_Msk                                                                 (0x1UL << PLATFORM_REG_BT_BIST_FAIL_RSVD_1_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_8k_ram_Pos                                                17U
#define PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_8k_ram_Msk                                                (0x1UL << PLATFORM_REG_BT_BIST_FAIL_bist_fail_buffer_8k_ram_Pos)

#define PLATFORM_REG_BT_BIST_FAIL_RSVD_Pos                                                                   18U
#define PLATFORM_REG_BT_BIST_FAIL_RSVD_Msk                                                                   (0x3FFFUL << PLATFORM_REG_BT_BIST_FAIL_RSVD_Pos)

/* 0x00FC   0x4000_60fc
    0       R       bist_done_drf_leslv_ram                             0
    1       R       bist_done_drf_lecis_ram                             0
    2       R       bist_done_drf_lebis_ram                             0
    3       R       bist_done_drf_buffer_ram                            0
    4       R       bist_done_drf_audio_ram                             0
    5       R       bist_done_drf_btphy_ram                             0
    6       R       bist_done_drf_ccmp_ram                              0
    7       R       bist_done_drf_btrx_ram                              0
    8       R       bist_done_drf_bttx_ram                              0
    9       R       bist_done_drf_lepa_ram                              0
    10      R       bist_done_drf_lemst_ram                             0
    11      R       RSVD_1                                              0
    12      R       bist_done_drf_buffer_8k_ram                         0
    31:13   R       RSVD                                                19'h0
 */
typedef union _PLATFORM_REG_BT_DRF_BIST_DONE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_done_drf_leslv_ram: 1;
        uint32_t bist_done_drf_lecis_ram: 1;
        uint32_t bist_done_drf_lebis_ram: 1;
        uint32_t bist_done_drf_buffer_ram: 1;
        uint32_t bist_done_drf_audio_ram: 1;
        uint32_t bist_done_drf_btphy_ram: 1;
        uint32_t bist_done_drf_ccmp_ram: 1;
        uint32_t bist_done_drf_btrx_ram: 1;
        uint32_t bist_done_drf_bttx_ram: 1;
        uint32_t bist_done_drf_lepa_ram: 1;
        uint32_t bist_done_drf_lemst_ram: 1;
        uint32_t RSVD_1: 1;
        uint32_t bist_done_drf_buffer_8k_ram: 1;
        uint32_t RSVD: 19;
    };
} PLATFORM_REG_BT_DRF_BIST_DONE_TYPE;

/*0x4000_60fc PLATFORM_REG_BT_DRF_BIST_DONE*/
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_leslv_ram_Pos                                            0U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_leslv_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_leslv_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lecis_ram_Pos                                            1U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lecis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lecis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lebis_ram_Pos                                            2U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lebis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lebis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_ram_Pos                                           3U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_audio_ram_Pos                                            4U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_audio_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_audio_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btphy_ram_Pos                                            5U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btphy_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btphy_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_ccmp_ram_Pos                                             6U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_ccmp_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_ccmp_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btrx_ram_Pos                                             7U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btrx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_btrx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_bttx_ram_Pos                                             8U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_bttx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_bttx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lepa_ram_Pos                                             9U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lepa_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lepa_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lemst_ram_Pos                                            10U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lemst_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_lemst_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_1_Pos                                                             11U
#define PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_1_Msk                                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_1_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_8k_ram_Pos                                        12U
#define PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_8k_ram_Msk                                        (0x1UL << PLATFORM_REG_BT_DRF_BIST_DONE_bist_done_drf_buffer_8k_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_Pos                                                               13U
#define PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_Msk                                                               (0x7FFFFUL << PLATFORM_REG_BT_DRF_BIST_DONE_RSVD_Pos)

/* 0x0100   0x4000_6100
    0       R       bist_fail_drf_leslv_ram                             0
    1       R       bist_fail_drf_lecis_ram                             0
    2       R       bist_fail_drf_lebis_ram                             0
    3       R       bist_fail_drf_buffer_ram                            0
    4       R       bist_fail_drf_audio_ram                             0
    8:5     R       bist_fail_drf_btphy_ram                             4'b0000
    11:9    R       bist_fail_drf_ccmp_ram                              3'b000
    12      R       bist_fail_drf_btrx_ram                              0
    13      R       bist_fail_drf_bttx_ram                              0
    14      R       bist_fail_drf_lepa_ram                              0
    15      R       bist_fail_drf_lemst_ram                             0
    16      R       RSVD_1                                              0
    17      R       bist_fail_drf_buffer_8k_ram                         0
    31:18   R       RSVD                                                14'h0
 */
typedef union _PLATFORM_REG_BT_DRF_BIST_FAIL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bist_fail_drf_leslv_ram: 1;
        uint32_t bist_fail_drf_lecis_ram: 1;
        uint32_t bist_fail_drf_lebis_ram: 1;
        uint32_t bist_fail_drf_buffer_ram: 1;
        uint32_t bist_fail_drf_audio_ram: 1;
        uint32_t bist_fail_drf_btphy_ram: 4;
        uint32_t bist_fail_drf_ccmp_ram: 3;
        uint32_t bist_fail_drf_btrx_ram: 1;
        uint32_t bist_fail_drf_bttx_ram: 1;
        uint32_t bist_fail_drf_lepa_ram: 1;
        uint32_t bist_fail_drf_lemst_ram: 1;
        uint32_t RSVD_1: 1;
        uint32_t bist_fail_drf_buffer_8k_ram: 1;
        uint32_t RSVD: 14;
    };
} PLATFORM_REG_BT_DRF_BIST_FAIL_TYPE;

/*0x4000_6100 PLATFORM_REG_BT_DRF_BIST_FAIL*/
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_leslv_ram_Pos                                            0U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_leslv_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_leslv_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lecis_ram_Pos                                            1U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lecis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lecis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lebis_ram_Pos                                            2U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lebis_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lebis_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_ram_Pos                                           3U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_ram_Msk                                           (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_audio_ram_Pos                                            4U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_audio_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_audio_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btphy_ram_Pos                                            5U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btphy_ram_Msk                                            (0xFUL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btphy_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_ccmp_ram_Pos                                             9U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_ccmp_ram_Msk                                             (0x7UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_ccmp_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btrx_ram_Pos                                             12U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btrx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_btrx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_bttx_ram_Pos                                             13U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_bttx_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_bttx_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lepa_ram_Pos                                             14U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lepa_ram_Msk                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lepa_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lemst_ram_Pos                                            15U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lemst_ram_Msk                                            (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_lemst_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_1_Pos                                                             16U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_1_Msk                                                             (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_1_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_8k_ram_Pos                                        17U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_8k_ram_Msk                                        (0x1UL << PLATFORM_REG_BT_DRF_BIST_FAIL_bist_fail_drf_buffer_8k_ram_Pos)

#define PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_Pos                                                               18U
#define PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_Msk                                                               (0x3FFFUL << PLATFORM_REG_BT_DRF_BIST_FAIL_RSVD_Pos)

/* 0x0130   0x4000_6130
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_6_TYPE;

/*0x4000_6130 PLATFORM_Reserved_6*/
#define PLATFORM_Reserved_6_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_6_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_6_RSVD_Pos)

/* 0x0134   0x4000_6134
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_7_TYPE;

/*0x4000_6134 PLATFORM_Reserved_7*/
#define PLATFORM_Reserved_7_RSVD_Pos                                                                         0U
#define PLATFORM_Reserved_7_RSVD_Msk                                                                         (0xFFFFFFFFUL << PLATFORM_Reserved_7_RSVD_Pos)

/* 0x01E0   0x4000_61e0
    27:0    R/W     WDT_CNT_LIMIT                                       28'h4E200
    29:28   R/W     WDT_MODE                                            2'h0
    30      R/W1C   WDT_TO                                              1'h0
    31      R/W     WDT_EN                                              1'h0
 */
typedef union _PLATFORM_REG_WDT_CTL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WDT_CNT_LIMIT: 28;
        uint32_t WDT_MODE: 2;
        uint32_t WDT_TO: 1;
        uint32_t WDT_EN: 1;
    };
} PLATFORM_REG_WDT_CTL_TYPE;

/*0x4000_61e0 PLATFORM_REG_WDT_CTL*/
#define PLATFORM_REG_WDT_CTL_WDT_CNT_LIMIT_Pos                                                               0U
#define PLATFORM_REG_WDT_CTL_WDT_CNT_LIMIT_Msk                                                               (0xFFFFFFFUL << PLATFORM_REG_WDT_CTL_WDT_CNT_LIMIT_Pos)

#define PLATFORM_REG_WDT_CTL_WDT_MODE_Pos                                                                    28U
#define PLATFORM_REG_WDT_CTL_WDT_MODE_Msk                                                                    (0x3UL << PLATFORM_REG_WDT_CTL_WDT_MODE_Pos)

#define PLATFORM_REG_WDT_CTL_WDT_TO_Pos                                                                      30U
#define PLATFORM_REG_WDT_CTL_WDT_TO_Msk                                                                      (0x1UL << PLATFORM_REG_WDT_CTL_WDT_TO_Pos)

#define PLATFORM_REG_WDT_CTL_WDT_EN_Pos                                                                      31U
#define PLATFORM_REG_WDT_CTL_WDT_EN_Msk                                                                      (0x1UL << PLATFORM_REG_WDT_CTL_WDT_EN_Pos)

/* 0x01E4   0x4000_61e4
    15:0    R/WAC   WDT_KICK                                            16'h0
    31:16   R       RESERVED                                            16'h0
 */
typedef union _PLATFORM_REG_WDT_KICK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WDT_KICK: 16;
        uint32_t RESERVED: 16;
    };
} PLATFORM_REG_WDT_KICK_TYPE;

/*0x4000_61e4 PLATFORM_REG_WDT_KICK*/
#define PLATFORM_REG_WDT_KICK_WDT_KICK_Pos                                                                   0U
#define PLATFORM_REG_WDT_KICK_WDT_KICK_Msk                                                                   (0xFFFFUL << PLATFORM_REG_WDT_KICK_WDT_KICK_Pos)

#define PLATFORM_REG_WDT_KICK_RESERVED_Pos                                                                   16U
#define PLATFORM_REG_WDT_KICK_RESERVED_Msk                                                                   (0xFFFFUL << PLATFORM_REG_WDT_KICK_RESERVED_Pos)

/* 0x01E8   0x4000_61e8
    27:0    R       WDT_CURRENT                                         28'h0
    31:28   R       RESERVED                                            4'h0
 */
typedef union _PLATFORM_REG_WDT_CURRENT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WDT_CURRENT: 28;
        uint32_t RESERVED: 4;
    };
} PLATFORM_REG_WDT_CURRENT_TYPE;

/*0x4000_61e8 PLATFORM_REG_WDT_CURRENT*/
#define PLATFORM_REG_WDT_CURRENT_WDT_CURRENT_Pos                                                             0U
#define PLATFORM_REG_WDT_CURRENT_WDT_CURRENT_Msk                                                             (0xFFFFFFFUL << PLATFORM_REG_WDT_CURRENT_WDT_CURRENT_Pos)

#define PLATFORM_REG_WDT_CURRENT_RESERVED_Pos                                                                28U
#define PLATFORM_REG_WDT_CURRENT_RESERVED_Msk                                                                (0xFUL << PLATFORM_REG_WDT_CURRENT_RESERVED_Pos)

/* 0x01EC   0x4000_61ec
    31:0    R       WDT_VER                                             32'h2409030A
 */
typedef union _PLATFORM_REG_WDT_VER_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WDT_VER;
    };
} PLATFORM_REG_WDT_VER_TYPE;

/*0x4000_61ec PLATFORM_REG_WDT_VER*/
#define PLATFORM_REG_WDT_VER_WDT_VER_Pos                                                                     0U
#define PLATFORM_REG_WDT_VER_WDT_VER_Msk                                                                     (0xFFFFFFFFUL << PLATFORM_REG_WDT_VER_WDT_VER_Pos)

/* 0x01F0   0x4000_61f0
    0       R/W     WDT_CLK_QACTIVE_MAN_DATA                            1'h0
    1       R/W     WDT_CLK_QACTIVE_MAN_ENABLE                          1'h0
    31:2    R       RESERVED                                            30'h0
 */
typedef union _PLATFORM_REG_WDT_CLK_QACTIVE_CTL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WDT_CLK_QACTIVE_MAN_DATA: 1;
        uint32_t WDT_CLK_QACTIVE_MAN_ENABLE: 1;
        uint32_t RESERVED: 30;
    };
} PLATFORM_REG_WDT_CLK_QACTIVE_CTL_TYPE;

/*0x4000_61f0 PLATFORM_REG_WDT_CLK_QACTIVE_CTL*/
#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_DATA_Pos                                        0U
#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_DATA_Msk                                        (0x1UL << PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_DATA_Pos)

#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_ENABLE_Pos                                      1U
#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_ENABLE_Msk                                      (0x1UL << PLATFORM_REG_WDT_CLK_QACTIVE_CTL_WDT_CLK_QACTIVE_MAN_ENABLE_Pos)

#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_RESERVED_Pos                                                        2U
#define PLATFORM_REG_WDT_CLK_QACTIVE_CTL_RESERVED_Msk                                                        (0x3FFFFFFFUL << PLATFORM_REG_WDT_CLK_QACTIVE_CTL_RESERVED_Pos)

/* 0x0200   0x4000_6200
    0       R/W     rng_srst                                            0
    1       R/W     clk_hf_sel                                          0
    2       R/W     corrector_bypass                                    0
    3       R/W     cali_srst                                           0
    4       R       RSVD_1                                              0
    5       R/W     corrector_imode                                     0
    10:6    R/W     dbg0_sel                                            5'h0
    15:11   R/W     dbg1_sel                                            5'h1
    16      R/W     lfsr_bypass_1                                       1
    17      R/W     lfsr_mode                                           0
    18      R/W     st_en                                               0
    19      R/W     mode                                                0
    31:20   R       RSVD                                                12'h0
 */
typedef union _PLATFORM_RNGControlRegister_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t rng_srst: 1;
        uint32_t clk_hf_sel: 1;
        uint32_t corrector_bypass: 1;
        uint32_t cali_srst: 1;
        uint32_t RSVD_1: 1;
        uint32_t corrector_imode: 1;
        uint32_t dbg0_sel: 5;
        uint32_t dbg1_sel: 5;
        uint32_t lfsr_bypass_1: 1;
        uint32_t lfsr_mode: 1;
        uint32_t st_en: 1;
        uint32_t mode: 1;
        uint32_t RSVD: 12;
    };
} PLATFORM_RNGControlRegister_TYPE;

/*0x4000_6200 PLATFORM_RNGControlRegister*/
#define PLATFORM_RNGControlRegister_rng_srst_Pos                                                             0U
#define PLATFORM_RNGControlRegister_rng_srst_Msk                                                             (0x1UL << PLATFORM_RNGControlRegister_rng_srst_Pos)

#define PLATFORM_RNGControlRegister_clk_hf_sel_Pos                                                           1U
#define PLATFORM_RNGControlRegister_clk_hf_sel_Msk                                                           (0x1UL << PLATFORM_RNGControlRegister_clk_hf_sel_Pos)

#define PLATFORM_RNGControlRegister_corrector_bypass_Pos                                                     2U
#define PLATFORM_RNGControlRegister_corrector_bypass_Msk                                                     (0x1UL << PLATFORM_RNGControlRegister_corrector_bypass_Pos)

#define PLATFORM_RNGControlRegister_cali_srst_Pos                                                            3U
#define PLATFORM_RNGControlRegister_cali_srst_Msk                                                            (0x1UL << PLATFORM_RNGControlRegister_cali_srst_Pos)

#define PLATFORM_RNGControlRegister_RSVD_1_Pos                                                               4U
#define PLATFORM_RNGControlRegister_RSVD_1_Msk                                                               (0x1UL << PLATFORM_RNGControlRegister_RSVD_1_Pos)

#define PLATFORM_RNGControlRegister_corrector_imode_Pos                                                      5U
#define PLATFORM_RNGControlRegister_corrector_imode_Msk                                                      (0x1UL << PLATFORM_RNGControlRegister_corrector_imode_Pos)

#define PLATFORM_RNGControlRegister_dbg0_sel_Pos                                                             6U
#define PLATFORM_RNGControlRegister_dbg0_sel_Msk                                                             (0x1FUL << PLATFORM_RNGControlRegister_dbg0_sel_Pos)

#define PLATFORM_RNGControlRegister_dbg1_sel_Pos                                                             11U
#define PLATFORM_RNGControlRegister_dbg1_sel_Msk                                                             (0x1FUL << PLATFORM_RNGControlRegister_dbg1_sel_Pos)

#define PLATFORM_RNGControlRegister_lfsr_bypass_1_Pos                                                        16U
#define PLATFORM_RNGControlRegister_lfsr_bypass_1_Msk                                                        (0x1UL << PLATFORM_RNGControlRegister_lfsr_bypass_1_Pos)

#define PLATFORM_RNGControlRegister_lfsr_mode_Pos                                                            17U
#define PLATFORM_RNGControlRegister_lfsr_mode_Msk                                                            (0x1UL << PLATFORM_RNGControlRegister_lfsr_mode_Pos)

#define PLATFORM_RNGControlRegister_st_en_Pos                                                                18U
#define PLATFORM_RNGControlRegister_st_en_Msk                                                                (0x1UL << PLATFORM_RNGControlRegister_st_en_Pos)

#define PLATFORM_RNGControlRegister_mode_Pos                                                                 19U
#define PLATFORM_RNGControlRegister_mode_Msk                                                                 (0x1UL << PLATFORM_RNGControlRegister_mode_Pos)

#define PLATFORM_RNGControlRegister_RSVD_Pos                                                                 20U
#define PLATFORM_RNGControlRegister_RSVD_Msk                                                                 (0xFFFUL << PLATFORM_RNGControlRegister_RSVD_Pos)

/* 0x0204   0x4000_6204
    1:0     R/W     DUMMY_1                                             2'b0
    3:2     R       RSVD_1                                              2'b0
    15:4    R/W     DUMMY                                               12'h889
    31:16   R       RSVD                                                16'h0
 */
typedef union _PLATFORM_Reserved_8_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY_1: 2;
        uint32_t RSVD_1: 2;
        uint32_t DUMMY: 12;
        uint32_t RSVD: 16;
    };
} PLATFORM_Reserved_8_TYPE;

/*0x4000_6204 PLATFORM_Reserved_8*/
#define PLATFORM_Reserved_8_DUMMY_1_Pos                                                                      0U
#define PLATFORM_Reserved_8_DUMMY_1_Msk                                                                      (0x3UL << PLATFORM_Reserved_8_DUMMY_1_Pos)

#define PLATFORM_Reserved_8_RSVD_1_Pos                                                                       2U
#define PLATFORM_Reserved_8_RSVD_1_Msk                                                                       (0x3UL << PLATFORM_Reserved_8_RSVD_1_Pos)

#define PLATFORM_Reserved_8_DUMMY_Pos                                                                        4U
#define PLATFORM_Reserved_8_DUMMY_Msk                                                                        (0xFFFUL << PLATFORM_Reserved_8_DUMMY_Pos)

#define PLATFORM_Reserved_8_RSVD_Pos                                                                         16U
#define PLATFORM_Reserved_8_RSVD_Msk                                                                         (0xFFFFUL << PLATFORM_Reserved_8_RSVD_Pos)

/* 0x0208   0x4000_6208
    31:0    R/W     DUMMY                                               32'h28001a00
 */
typedef union _PLATFORM_Reserved_9_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY;
    };
} PLATFORM_Reserved_9_TYPE;

/*0x4000_6208 PLATFORM_Reserved_9*/
#define PLATFORM_Reserved_9_DUMMY_Pos                                                                        0U
#define PLATFORM_Reserved_9_DUMMY_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_9_DUMMY_Pos)

/* 0x020C   0x4000_620c
    8:0     R/W     DUMMY_1                                             9'h101
    11:9    R       RSVD                                                3'h0
    31:12   R/W     DUMMY                                               20'h10d0
 */
typedef union _PLATFORM_Reserved_10_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY_1: 9;
        uint32_t RSVD: 3;
        uint32_t DUMMY: 20;
    };
} PLATFORM_Reserved_10_TYPE;

/*0x4000_620c PLATFORM_Reserved_10*/
#define PLATFORM_Reserved_10_DUMMY_1_Pos                                                                     0U
#define PLATFORM_Reserved_10_DUMMY_1_Msk                                                                     (0x1FFUL << PLATFORM_Reserved_10_DUMMY_1_Pos)

#define PLATFORM_Reserved_10_RSVD_Pos                                                                        9U
#define PLATFORM_Reserved_10_RSVD_Msk                                                                        (0x7UL << PLATFORM_Reserved_10_RSVD_Pos)

#define PLATFORM_Reserved_10_DUMMY_Pos                                                                       12U
#define PLATFORM_Reserved_10_DUMMY_Msk                                                                       (0xFFFFFUL << PLATFORM_Reserved_10_DUMMY_Pos)

/* 0x0210   0x4000_6210
    31:0    R       RSVD                                                32'h00020000
 */
typedef union _PLATFORM_Reserved_11_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_11_TYPE;

/*0x4000_6210 PLATFORM_Reserved_11*/
#define PLATFORM_Reserved_11_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_11_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_11_RSVD_Pos)

/* 0x0214   0x4000_6214
    31:0    R/W     DUMMY                                               32'h2b001800
 */
typedef union _PLATFORM_Reserved_12_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY;
    };
} PLATFORM_Reserved_12_TYPE;

/*0x4000_6214 PLATFORM_Reserved_12*/
#define PLATFORM_Reserved_12_DUMMY_Pos                                                                       0U
#define PLATFORM_Reserved_12_DUMMY_Msk                                                                       (0xFFFFFFFFUL << PLATFORM_Reserved_12_DUMMY_Pos)

/* 0x0218   0x4000_6218
    3:0     R/W     DUMMY_1                                             4'h8
    15:4    R/W     RSVD_1                                              12'h0
    19:16   R/W     DUMMY                                               4'h4
    31:20   R/W     RSVD                                                12'h0
 */
typedef union _PLATFORM_Reserved_13_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY_1: 4;
        uint32_t RSVD_1: 12;
        uint32_t DUMMY: 4;
        uint32_t RSVD: 12;
    };
} PLATFORM_Reserved_13_TYPE;

/*0x4000_6218 PLATFORM_Reserved_13*/
#define PLATFORM_Reserved_13_DUMMY_1_Pos                                                                     0U
#define PLATFORM_Reserved_13_DUMMY_1_Msk                                                                     (0xFUL << PLATFORM_Reserved_13_DUMMY_1_Pos)

#define PLATFORM_Reserved_13_RSVD_1_Pos                                                                      4U
#define PLATFORM_Reserved_13_RSVD_1_Msk                                                                      (0xFFFUL << PLATFORM_Reserved_13_RSVD_1_Pos)

#define PLATFORM_Reserved_13_DUMMY_Pos                                                                       16U
#define PLATFORM_Reserved_13_DUMMY_Msk                                                                       (0xFUL << PLATFORM_Reserved_13_DUMMY_Pos)

#define PLATFORM_Reserved_13_RSVD_Pos                                                                        20U
#define PLATFORM_Reserved_13_RSVD_Msk                                                                        (0xFFFUL << PLATFORM_Reserved_13_RSVD_Pos)

/* 0x021C   0x4000_621c
    0       R       out_ready                                           0
    1       R       init_ready                                          0
    31:2    R       RSVD                                                30'h0
 */
typedef union _PLATFORM_RNG_return0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t out_ready: 1;
        uint32_t init_ready: 1;
        uint32_t RSVD: 30;
    };
} PLATFORM_RNG_return0_TYPE;

/*0x4000_621c PLATFORM_RNG_return0*/
#define PLATFORM_RNG_return0_out_ready_Pos                                                                   0U
#define PLATFORM_RNG_return0_out_ready_Msk                                                                   (0x1UL << PLATFORM_RNG_return0_out_ready_Pos)

#define PLATFORM_RNG_return0_init_ready_Pos                                                                  1U
#define PLATFORM_RNG_return0_init_ready_Msk                                                                  (0x1UL << PLATFORM_RNG_return0_init_ready_Pos)

#define PLATFORM_RNG_return0_RSVD_Pos                                                                        2U
#define PLATFORM_RNG_return0_RSVD_Msk                                                                        (0x3FFFFFFFUL << PLATFORM_RNG_return0_RSVD_Pos)

/* 0x0220   0x4000_6220
    31:0    R       valid_bit_num                                       32'h0
 */
typedef union _PLATFORM_RNG_return1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t valid_bit_num;
    };
} PLATFORM_RNG_return1_TYPE;

/*0x4000_6220 PLATFORM_RNG_return1*/
#define PLATFORM_RNG_return1_valid_bit_num_Pos                                                               0U
#define PLATFORM_RNG_return1_valid_bit_num_Msk                                                               (0xFFFFFFFFUL << PLATFORM_RNG_return1_valid_bit_num_Pos)

/* 0x0224   0x4000_6224
    31:0    R       drop_num                                            32'h0
 */
typedef union _PLATFORM_RNG_return2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t drop_num;
    };
} PLATFORM_RNG_return2_TYPE;

/*0x4000_6224 PLATFORM_RNG_return2*/
#define PLATFORM_RNG_return2_drop_num_Pos                                                                    0U
#define PLATFORM_RNG_return2_drop_num_Msk                                                                    (0xFFFFFFFFUL << PLATFORM_RNG_return2_drop_num_Pos)

/* 0x0228   0x4000_6228
    31:0    R       random_out                                          32'h0
 */
typedef union _PLATFORM_RNG_result_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t random_out;
    };
} PLATFORM_RNG_result_TYPE;

/*0x4000_6228 PLATFORM_RNG_result*/
#define PLATFORM_RNG_result_random_out_Pos                                                                   0U
#define PLATFORM_RNG_result_random_out_Msk                                                                   (0xFFFFFFFFUL << PLATFORM_RNG_result_random_out_Pos)

/* 0x022C   0x4000_622c
    31:0    R/W     lfsr_poly_lsb                                       32'h0
 */
typedef union _PLATFORM_RNG_lfsr_poly_lsb_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t lfsr_poly_lsb;
    };
} PLATFORM_RNG_lfsr_poly_lsb_TYPE;

/*0x4000_622c PLATFORM_RNG_lfsr_poly_lsb*/
#define PLATFORM_RNG_lfsr_poly_lsb_lfsr_poly_lsb_Pos                                                         0U
#define PLATFORM_RNG_lfsr_poly_lsb_lfsr_poly_lsb_Msk                                                         (0xFFFFFFFFUL << PLATFORM_RNG_lfsr_poly_lsb_lfsr_poly_lsb_Pos)

/* 0x0230   0x4000_6230
    31:0    R/W     lfsr_poly_msb                                       32'h0
 */
typedef union _PLATFORM_RNG_lfsr_poly_msb_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t lfsr_poly_msb;
    };
} PLATFORM_RNG_lfsr_poly_msb_TYPE;

/*0x4000_6230 PLATFORM_RNG_lfsr_poly_msb*/
#define PLATFORM_RNG_lfsr_poly_msb_lfsr_poly_msb_Pos                                                         0U
#define PLATFORM_RNG_lfsr_poly_msb_lfsr_poly_msb_Msk                                                         (0xFFFFFFFFUL << PLATFORM_RNG_lfsr_poly_msb_lfsr_poly_msb_Pos)

/* 0x0234   0x4000_6234
    31:0    R/W     DUMMY                                               32'hffff0000
 */
typedef union _PLATFORM_Reserved_14_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DUMMY;
    };
} PLATFORM_Reserved_14_TYPE;

/*0x4000_6234 PLATFORM_Reserved_14*/
#define PLATFORM_Reserved_14_DUMMY_Pos                                                                       0U
#define PLATFORM_Reserved_14_DUMMY_Msk                                                                       (0xFFFFFFFFUL << PLATFORM_Reserved_14_DUMMY_Pos)

/* 0x0238   0x4000_6238
    0       R/W     gating_en                                           1
    31:1    R       RSVD                                                31'h0
 */
typedef union _PLATFORM_RNG_POWER_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t gating_en: 1;
        uint32_t RSVD: 31;
    };
} PLATFORM_RNG_POWER_TYPE;

/*0x4000_6238 PLATFORM_RNG_POWER*/
#define PLATFORM_RNG_POWER_gating_en_Pos                                                                     0U
#define PLATFORM_RNG_POWER_gating_en_Msk                                                                     (0x1UL << PLATFORM_RNG_POWER_gating_en_Pos)

#define PLATFORM_RNG_POWER_RSVD_Pos                                                                          1U
#define PLATFORM_RNG_POWER_RSVD_Msk                                                                          (0x7FFFFFFFUL << PLATFORM_RNG_POWER_RSVD_Pos)

/* 0x023C   0x4000_623c
    7:0     R/W     thr_done_rep                                        8'h0
    15:8    R/W     thr_err_rep                                         8'h5
    17:16   R/W     window_size_adap2                                   2'b1
    19:18   R/W     window_size_adap1                                   2'b1
    20      R/W     compare_unit_adap2                                  0
    21      R/W     compare_unit_adap1                                  0
    22      R/W     compare_unit_rep                                    1
    23      R       RSVD                                                0
    27:24   R/W     thr_done_adap2                                      4'h4
    31:28   R/W     thr_done_adap1                                      4'h4
 */
typedef union _PLATFORM_RNG_st_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t thr_done_rep: 8;
        uint32_t thr_err_rep: 8;
        uint32_t window_size_adap2: 2;
        uint32_t window_size_adap1: 2;
        uint32_t compare_unit_adap2: 1;
        uint32_t compare_unit_adap1: 1;
        uint32_t compare_unit_rep: 1;
        uint32_t RSVD: 1;
        uint32_t thr_done_adap2: 4;
        uint32_t thr_done_adap1: 4;
    };
} PLATFORM_RNG_st_TYPE;

/*0x4000_623c PLATFORM_RNG_st*/
#define PLATFORM_RNG_st_thr_done_rep_Pos                                                                     0U
#define PLATFORM_RNG_st_thr_done_rep_Msk                                                                     (0xFFUL << PLATFORM_RNG_st_thr_done_rep_Pos)

#define PLATFORM_RNG_st_thr_err_rep_Pos                                                                      8U
#define PLATFORM_RNG_st_thr_err_rep_Msk                                                                      (0xFFUL << PLATFORM_RNG_st_thr_err_rep_Pos)

#define PLATFORM_RNG_st_window_size_adap2_Pos                                                                16U
#define PLATFORM_RNG_st_window_size_adap2_Msk                                                                (0x3UL << PLATFORM_RNG_st_window_size_adap2_Pos)

#define PLATFORM_RNG_st_window_size_adap1_Pos                                                                18U
#define PLATFORM_RNG_st_window_size_adap1_Msk                                                                (0x3UL << PLATFORM_RNG_st_window_size_adap1_Pos)

#define PLATFORM_RNG_st_compare_unit_adap2_Pos                                                               20U
#define PLATFORM_RNG_st_compare_unit_adap2_Msk                                                               (0x1UL << PLATFORM_RNG_st_compare_unit_adap2_Pos)

#define PLATFORM_RNG_st_compare_unit_adap1_Pos                                                               21U
#define PLATFORM_RNG_st_compare_unit_adap1_Msk                                                               (0x1UL << PLATFORM_RNG_st_compare_unit_adap1_Pos)

#define PLATFORM_RNG_st_compare_unit_rep_Pos                                                                 22U
#define PLATFORM_RNG_st_compare_unit_rep_Msk                                                                 (0x1UL << PLATFORM_RNG_st_compare_unit_rep_Pos)

#define PLATFORM_RNG_st_RSVD_Pos                                                                             23U
#define PLATFORM_RNG_st_RSVD_Msk                                                                             (0x1UL << PLATFORM_RNG_st_RSVD_Pos)

#define PLATFORM_RNG_st_thr_done_adap2_Pos                                                                   24U
#define PLATFORM_RNG_st_thr_done_adap2_Msk                                                                   (0xFUL << PLATFORM_RNG_st_thr_done_adap2_Pos)

#define PLATFORM_RNG_st_thr_done_adap1_Pos                                                                   28U
#define PLATFORM_RNG_st_thr_done_adap1_Msk                                                                   (0xFUL << PLATFORM_RNG_st_thr_done_adap1_Pos)

/* 0x0240   0x4000_6240
    0       R/W     err_adap2                                           0
    1       R/W     err_adap1                                           0
    2       R/W     err_rep                                             0
    3       R/W     err                                                 0
    4       R       done_adap2                                          0
    5       R       done_adap1                                          0
    6       R       done_rep                                            0
    7       R       done                                                0
    31:8    R       RSVD                                                24'h0
 */
typedef union _PLATFORM_RNG_st_return_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t err_adap2: 1;
        uint32_t err_adap1: 1;
        uint32_t err_rep: 1;
        uint32_t err: 1;
        uint32_t done_adap2: 1;
        uint32_t done_adap1: 1;
        uint32_t done_rep: 1;
        uint32_t done: 1;
        uint32_t RSVD: 24;
    };
} PLATFORM_RNG_st_return_TYPE;

/*0x4000_6240 PLATFORM_RNG_st_return*/
#define PLATFORM_RNG_st_return_err_adap2_Pos                                                                 0U
#define PLATFORM_RNG_st_return_err_adap2_Msk                                                                 (0x1UL << PLATFORM_RNG_st_return_err_adap2_Pos)

#define PLATFORM_RNG_st_return_err_adap1_Pos                                                                 1U
#define PLATFORM_RNG_st_return_err_adap1_Msk                                                                 (0x1UL << PLATFORM_RNG_st_return_err_adap1_Pos)

#define PLATFORM_RNG_st_return_err_rep_Pos                                                                   2U
#define PLATFORM_RNG_st_return_err_rep_Msk                                                                   (0x1UL << PLATFORM_RNG_st_return_err_rep_Pos)

#define PLATFORM_RNG_st_return_err_Pos                                                                       3U
#define PLATFORM_RNG_st_return_err_Msk                                                                       (0x1UL << PLATFORM_RNG_st_return_err_Pos)

#define PLATFORM_RNG_st_return_done_adap2_Pos                                                                4U
#define PLATFORM_RNG_st_return_done_adap2_Msk                                                                (0x1UL << PLATFORM_RNG_st_return_done_adap2_Pos)

#define PLATFORM_RNG_st_return_done_adap1_Pos                                                                5U
#define PLATFORM_RNG_st_return_done_adap1_Msk                                                                (0x1UL << PLATFORM_RNG_st_return_done_adap1_Pos)

#define PLATFORM_RNG_st_return_done_rep_Pos                                                                  6U
#define PLATFORM_RNG_st_return_done_rep_Msk                                                                  (0x1UL << PLATFORM_RNG_st_return_done_rep_Pos)

#define PLATFORM_RNG_st_return_done_Pos                                                                      7U
#define PLATFORM_RNG_st_return_done_Msk                                                                      (0x1UL << PLATFORM_RNG_st_return_done_Pos)

#define PLATFORM_RNG_st_return_RSVD_Pos                                                                      8U
#define PLATFORM_RNG_st_return_RSVD_Msk                                                                      (0xFFFFFFUL << PLATFORM_RNG_st_return_RSVD_Pos)

/* 0x0244   0x4000_6244
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_15_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_15_TYPE;

/*0x4000_6244 PLATFORM_Reserved_15*/
#define PLATFORM_Reserved_15_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_15_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_15_RSVD_Pos)

/* 0x0248   0x4000_6248
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_16_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_16_TYPE;

/*0x4000_6248 PLATFORM_Reserved_16*/
#define PLATFORM_Reserved_16_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_16_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_16_RSVD_Pos)

/* 0x024C   0x4000_624c
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_17_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_17_TYPE;

/*0x4000_624c PLATFORM_Reserved_17*/
#define PLATFORM_Reserved_17_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_17_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_17_RSVD_Pos)

/* 0x0250   0x4000_6250
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_18_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_18_TYPE;

/*0x4000_6250 PLATFORM_Reserved_18*/
#define PLATFORM_Reserved_18_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_18_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_18_RSVD_Pos)

/* 0x0254   0x4000_6254
    0       W       write_data                                          0
    1       R/W1S   otp                                                 0
    2       R/W1S   parity                                              0
    3       R/W1S   st_err                                              0
    31:4    R       RSVD                                                28'h0
 */
typedef union _PLATFORM_RNGinterrupt_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t write_data: 1;
        uint32_t otp: 1;
        uint32_t parity: 1;
        uint32_t st_err: 1;
        uint32_t RSVD: 28;
    };
} PLATFORM_RNGinterrupt_TYPE;

/*0x4000_6254 PLATFORM_RNGinterrupt*/
#define PLATFORM_RNGinterrupt_write_data_Pos                                                                 0U
#define PLATFORM_RNGinterrupt_write_data_Msk                                                                 (0x1UL << PLATFORM_RNGinterrupt_write_data_Pos)

#define PLATFORM_RNGinterrupt_otp_Pos                                                                        1U
#define PLATFORM_RNGinterrupt_otp_Msk                                                                        (0x1UL << PLATFORM_RNGinterrupt_otp_Pos)

#define PLATFORM_RNGinterrupt_parity_Pos                                                                     2U
#define PLATFORM_RNGinterrupt_parity_Msk                                                                     (0x1UL << PLATFORM_RNGinterrupt_parity_Pos)

#define PLATFORM_RNGinterrupt_st_err_Pos                                                                     3U
#define PLATFORM_RNGinterrupt_st_err_Msk                                                                     (0x1UL << PLATFORM_RNGinterrupt_st_err_Pos)

#define PLATFORM_RNGinterrupt_RSVD_Pos                                                                       4U
#define PLATFORM_RNGinterrupt_RSVD_Msk                                                                       (0xFFFFFFFUL << PLATFORM_RNGinterrupt_RSVD_Pos)

/* 0x0258   0x4000_6258
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_19_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_19_TYPE;

/*0x4000_6258 PLATFORM_Reserved_19*/
#define PLATFORM_Reserved_19_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_19_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_19_RSVD_Pos)

/* 0x025C   0x4000_625c
    31:0    R       RSVD                                                32'h0
 */
typedef union _PLATFORM_Reserved_20_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} PLATFORM_Reserved_20_TYPE;

/*0x4000_625c PLATFORM_Reserved_20*/
#define PLATFORM_Reserved_20_RSVD_Pos                                                                        0U
#define PLATFORM_Reserved_20_RSVD_Msk                                                                        (0xFFFFFFFFUL << PLATFORM_Reserved_20_RSVD_Pos)

/* 0x0260   0x4000_6260
    15:0    R/W     adap2                                               16'h270
    31:16   R/W     adap1                                               16'h270
 */
typedef union _PLATFORM_RNG_st_thr_err_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t adap2: 16;
        uint32_t adap1: 16;
    };
} PLATFORM_RNG_st_thr_err_TYPE;

/*0x4000_6260 PLATFORM_RNG_st_thr_err*/
#define PLATFORM_RNG_st_thr_err_adap2_Pos                                                                    0U
#define PLATFORM_RNG_st_thr_err_adap2_Msk                                                                    (0xFFFFUL << PLATFORM_RNG_st_thr_err_adap2_Pos)

#define PLATFORM_RNG_st_thr_err_adap1_Pos                                                                    16U
#define PLATFORM_RNG_st_thr_err_adap1_Msk                                                                    (0xFFFFUL << PLATFORM_RNG_st_thr_err_adap1_Pos)

/* 0x0264   0x4000_6264
    0       W       write_data                                          0
    1       R/W     otp                                                 0
    2       R/W     parity                                              0
    3       R/W     st_err                                              0
    31:4    R       RSVD                                                28'h0
 */
typedef union _PLATFORM_RNGinterruptenable_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t write_data: 1;
        uint32_t otp: 1;
        uint32_t parity: 1;
        uint32_t st_err: 1;
        uint32_t RSVD: 28;
    };
} PLATFORM_RNGinterruptenable_TYPE;

/*0x4000_6264 PLATFORM_RNGinterruptenable*/
#define PLATFORM_RNGinterruptenable_write_data_Pos                                                           0U
#define PLATFORM_RNGinterruptenable_write_data_Msk                                                           (0x1UL << PLATFORM_RNGinterruptenable_write_data_Pos)

#define PLATFORM_RNGinterruptenable_otp_Pos                                                                  1U
#define PLATFORM_RNGinterruptenable_otp_Msk                                                                  (0x1UL << PLATFORM_RNGinterruptenable_otp_Pos)

#define PLATFORM_RNGinterruptenable_parity_Pos                                                               2U
#define PLATFORM_RNGinterruptenable_parity_Msk                                                               (0x1UL << PLATFORM_RNGinterruptenable_parity_Pos)

#define PLATFORM_RNGinterruptenable_st_err_Pos                                                               3U
#define PLATFORM_RNGinterruptenable_st_err_Msk                                                               (0x1UL << PLATFORM_RNGinterruptenable_st_err_Pos)

#define PLATFORM_RNGinterruptenable_RSVD_Pos                                                                 4U
#define PLATFORM_RNGinterruptenable_RSVD_Msk                                                                 (0xFFFFFFFUL << PLATFORM_RNGinterruptenable_RSVD_Pos)

/* 0x02cc   0x4000_62cc
    31:0    R/W     spic0_pgm_fifo_init_0                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_0;
    };
} PLATFORM_SPIC0PGMfifointerrtup0_TYPE;

/*0x4000_62cc PLATFORM_SPIC0PGMfifointerrtup0*/
#define PLATFORM_SPIC0PGMfifointerrtup0_spic0_pgm_fifo_init_0_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup0_spic0_pgm_fifo_init_0_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup0_spic0_pgm_fifo_init_0_Pos)

/* 0x02d0   0x4000_62d0
    31:0    R/W     spic0_pgm_fifo_init_1                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_1;
    };
} PLATFORM_SPIC0PGMfifointerrtup1_TYPE;

/*0x4000_62d0 PLATFORM_SPIC0PGMfifointerrtup1*/
#define PLATFORM_SPIC0PGMfifointerrtup1_spic0_pgm_fifo_init_1_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup1_spic0_pgm_fifo_init_1_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup1_spic0_pgm_fifo_init_1_Pos)

/* 0x02d4   0x4000_62d4
    31:0    R/W     spic0_pgm_fifo_init_2                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_2;
    };
} PLATFORM_SPIC0PGMfifointerrtup2_TYPE;

/*0x4000_62d4 PLATFORM_SPIC0PGMfifointerrtup2*/
#define PLATFORM_SPIC0PGMfifointerrtup2_spic0_pgm_fifo_init_2_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup2_spic0_pgm_fifo_init_2_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup2_spic0_pgm_fifo_init_2_Pos)

/* 0x02d8   0x4000_62d8
    31:0    R/W     spic0_pgm_fifo_init_3                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_3;
    };
} PLATFORM_SPIC0PGMfifointerrtup3_TYPE;

/*0x4000_62d8 PLATFORM_SPIC0PGMfifointerrtup3*/
#define PLATFORM_SPIC0PGMfifointerrtup3_spic0_pgm_fifo_init_3_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup3_spic0_pgm_fifo_init_3_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup3_spic0_pgm_fifo_init_3_Pos)

/* 0x02dc   0x4000_62dc
    31:0    R/W     spic0_pgm_fifo_init_4                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_4;
    };
} PLATFORM_SPIC0PGMfifointerrtup4_TYPE;

/*0x4000_62dc PLATFORM_SPIC0PGMfifointerrtup4*/
#define PLATFORM_SPIC0PGMfifointerrtup4_spic0_pgm_fifo_init_4_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup4_spic0_pgm_fifo_init_4_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup4_spic0_pgm_fifo_init_4_Pos)

/* 0x02e0   0x4000_62e0
    31:0    R/W     spic0_pgm_fifo_init_5                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup5_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_5;
    };
} PLATFORM_SPIC0PGMfifointerrtup5_TYPE;

/*0x4000_62e0 PLATFORM_SPIC0PGMfifointerrtup5*/
#define PLATFORM_SPIC0PGMfifointerrtup5_spic0_pgm_fifo_init_5_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup5_spic0_pgm_fifo_init_5_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup5_spic0_pgm_fifo_init_5_Pos)

/* 0x02e4   0x4000_62e4
    31:0    R/W     spic0_pgm_fifo_init_6                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_6;
    };
} PLATFORM_SPIC0PGMfifointerrtup6_TYPE;

/*0x4000_62e4 PLATFORM_SPIC0PGMfifointerrtup6*/
#define PLATFORM_SPIC0PGMfifointerrtup6_spic0_pgm_fifo_init_6_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup6_spic0_pgm_fifo_init_6_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup6_spic0_pgm_fifo_init_6_Pos)

/* 0x02e8   0x4000_62e8
    31:0    R/W     spic0_pgm_fifo_init_7                               32'h0
 */
typedef union _PLATFORM_SPIC0PGMfifointerrtup7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t spic0_pgm_fifo_init_7;
    };
} PLATFORM_SPIC0PGMfifointerrtup7_TYPE;

/*0x4000_62e8 PLATFORM_SPIC0PGMfifointerrtup7*/
#define PLATFORM_SPIC0PGMfifointerrtup7_spic0_pgm_fifo_init_7_Pos                                            0U
#define PLATFORM_SPIC0PGMfifointerrtup7_spic0_pgm_fifo_init_7_Msk                                            (0xFFFFFFFFUL << PLATFORM_SPIC0PGMfifointerrtup7_spic0_pgm_fifo_init_7_Pos)

/* 0x02ec   0x4000_62ec
    0       R/W1C   r_ENHTIMER_EVNT_ACTIVE_sts                          1'b0
    1       R/W1C   r_ENHTIMER_EVNT_LCH_CNT0_FIFO_FULL_sts              1'b0
    2       R/W1C   r_ENHTIMER_EVNT_LCH_CNT0_FIFO_MET_TH_sts            1'b0
    3       R/W1C   r_ENHTIMER_EVNT_STOP_sts                            1'b0
    4       R/W1C   r_ENHTIMER_EVNT_TIMEOUT_sts                         1'b0
    15:5    R       reserved_1                                          11'h0000
    16      R/W1C   r_ENHTIMER_TASK_DISABLE_sts                         1'b0
    17      R/W1C   r_ENHTIMER_TASK_PAUSE_sts                           1'b0
    18      R/W1C   r_ENHTIMER_TASK_START_sts                           1'b0
    31:19   R       reserved                                            13'h0000
 */
typedef union _PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_ENHTIMER_EVNT_ACTIVE_sts: 1;
        uint32_t r_ENHTIMER_EVNT_LCH_CNT0_FIFO_FULL_sts: 1;
        uint32_t r_ENHTIMER_EVNT_LCH_CNT0_FIFO_MET_TH_sts: 1;
        uint32_t r_ENHTIMER_EVNT_STOP_sts: 1;
        uint32_t r_ENHTIMER_EVNT_TIMEOUT_sts: 1;
        uint32_t reserved_1: 11;
        uint32_t r_ENHTIMER_TASK_DISABLE_sts: 1;
        uint32_t r_ENHTIMER_TASK_PAUSE_sts: 1;
        uint32_t r_ENHTIMER_TASK_START_sts: 1;
        uint32_t reserved: 13;
    };
} PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_TYPE;

/*0x4000_62ec PLATFORM_REG_ENHTIMER_TASK_EVNT_STS*/
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_ACTIVE_sts_Pos                                   0U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_ACTIVE_sts_Msk                                   (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_FULL_sts_Pos                       1U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_FULL_sts_Msk                       (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_FULL_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_MET_TH_sts_Pos                     2U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_MET_TH_sts_Msk                     (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_LCH_CNT0_FIFO_MET_TH_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_STOP_sts_Pos                                     3U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_STOP_sts_Msk                                     (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_TIMEOUT_sts_Pos                                  4U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_TIMEOUT_sts_Msk                                  (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_1_Pos                                                   5U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_1_Msk                                                   (0x7FFUL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_DISABLE_sts_Pos                                  16U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_DISABLE_sts_Msk                                  (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_PAUSE_sts_Pos                                    17U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_PAUSE_sts_Msk                                    (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_START_sts_Pos                                    18U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_START_sts_Msk                                    (0x1UL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_r_ENHTIMER_TASK_START_sts_Pos)

#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_Pos                                                     19U
#define PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_Msk                                                     (0x1FFFUL << PLATFORM_REG_ENHTIMER_TASK_EVNT_STS_reserved_Pos)

/* 0x02f0   0x4000_62f0
    0       R/W1C   r_KEYSCAN_EVNT_MANUAL_DONE_sts                      1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_KEYSCAN_TASK_MANUAL_sts                           1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_KEYSCAN_EVNT_MANUAL_DONE_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_KEYSCAN_TASK_MANUAL_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_TYPE;

/*0x4000_62f0 PLATFORM_REG_KEYSCAN_TASK_EVNT_STS*/
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_EVNT_MANUAL_DONE_sts_Pos                                0U
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_EVNT_MANUAL_DONE_sts_Msk                                (0x1UL << PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_EVNT_MANUAL_DONE_sts_Pos)

#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_1_Pos                                                    1U
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_1_Msk                                                    (0x7FFFUL << PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_TASK_MANUAL_sts_Pos                                     16U
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_TASK_MANUAL_sts_Msk                                     (0x1UL << PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_r_KEYSCAN_TASK_MANUAL_sts_Pos)

#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_Pos                                                      17U
#define PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_Msk                                                      (0x7FFFUL << PLATFORM_REG_KEYSCAN_TASK_EVNT_STS_reserved_Pos)

/* 0x02f4   0x4000_62f4
    0       R/W1C   r_TIMER1_CH0_EVNT_ACTIVE_sts                        1'b0
    1       R/W1C   r_TIMER1_CH0_EVNT_STOP_sts                          1'b0
    2       R/W1C   r_TIMER1_CH0_EVNT_TIMEOUT_sts                       1'b0
    3       R/W1C   r_TIMER1_CH1_EVNT_ACTIVE_sts                        1'b0
    4       R/W1C   r_TIMER1_CH1_EVNT_STOP_sts                          1'b0
    5       R/W1C   r_TIMER1_CH1_EVNT_TIMEOUT_sts                       1'b0
    6       R/W1C   r_TIMER1_CH2_EVNT_ACTIVE_sts                        1'b0
    7       R/W1C   r_TIMER1_CH2_EVNT_STOP_sts                          1'b0
    8       R/W1C   r_TIMER1_CH2_EVNT_TIMEOUT_sts                       1'b0
    9       R/W1C   r_TIMER1_CH3_EVNT_ACTIVE_sts                        1'b0
    10      R/W1C   r_TIMER1_CH3_EVNT_STOP_sts                          1'b0
    11      R/W1C   r_TIMER1_CH3_EVNT_TIMEOUT_sts                       1'b0
    12      R/W1C   r_TIMER1_CH4_EVNT_ACTIVE_sts                        1'b0
    13      R/W1C   r_TIMER1_CH4_EVNT_STOP_sts                          1'b0
    14      R/W1C   r_TIMER1_CH4_EVNT_TIMEOUT_sts                       1'b0
    15      R/W1C   r_TIMER1_CH5_EVNT_ACTIVE_sts                        1'b0
    16      R/W1C   r_TIMER1_CH5_EVNT_STOP_sts                          1'b0
    17      R/W1C   r_TIMER1_CH5_EVNT_TIMEOUT_sts                       1'b0
    18      R/W1C   r_TIMER1_CH6_EVNT_ACTIVE_sts                        1'b0
    19      R/W1C   r_TIMER1_CH6_EVNT_STOP_sts                          1'b0
    20      R/W1C   r_TIMER1_CH6_EVNT_TIMEOUT_sts                       1'b0
    21      R/W1C   r_TIMER1_CH7_EVNT_ACTIVE_sts                        1'b0
    22      R/W1C   r_TIMER1_CH7_EVNT_STOP_sts                          1'b0
    23      R/W1C   r_TIMER1_CH7_EVNT_TIMEOUT_sts                       1'b0
    24      R/W1C   r_TIMER1_CH8_EVNT_ACTIVE_sts                        1'b0
    25      R/W1C   r_TIMER1_CH8_EVNT_STOP_sts                          1'b0
    26      R/W1C   r_TIMER1_CH8_EVNT_TIMEOUT_sts                       1'b0
    31:27   R       reserved                                            5'h00
 */
typedef union _PLATFORM_REG_TIMER1_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_TIMER1_CH0_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH0_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH0_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH1_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH1_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH1_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH2_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH2_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH2_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH3_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH3_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH3_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH4_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH4_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH4_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH5_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH5_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH5_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH6_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH6_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH6_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH7_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH7_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH7_EVNT_TIMEOUT_sts: 1;
        uint32_t r_TIMER1_CH8_EVNT_ACTIVE_sts: 1;
        uint32_t r_TIMER1_CH8_EVNT_STOP_sts: 1;
        uint32_t r_TIMER1_CH8_EVNT_TIMEOUT_sts: 1;
        uint32_t reserved: 5;
    };
} PLATFORM_REG_TIMER1_EVNT_STS_TYPE;

/*0x4000_62f4 PLATFORM_REG_TIMER1_EVNT_STS*/
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_ACTIVE_sts_Pos                                        0U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_STOP_sts_Pos                                          1U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_TIMEOUT_sts_Pos                                       2U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH0_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_ACTIVE_sts_Pos                                        3U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_STOP_sts_Pos                                          4U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_TIMEOUT_sts_Pos                                       5U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH1_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_ACTIVE_sts_Pos                                        6U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_STOP_sts_Pos                                          7U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_TIMEOUT_sts_Pos                                       8U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH2_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_ACTIVE_sts_Pos                                        9U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_STOP_sts_Pos                                          10U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_TIMEOUT_sts_Pos                                       11U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH3_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_ACTIVE_sts_Pos                                        12U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_STOP_sts_Pos                                          13U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_TIMEOUT_sts_Pos                                       14U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH4_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_ACTIVE_sts_Pos                                        15U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_STOP_sts_Pos                                          16U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_TIMEOUT_sts_Pos                                       17U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH5_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_ACTIVE_sts_Pos                                        18U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_STOP_sts_Pos                                          19U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_TIMEOUT_sts_Pos                                       20U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH6_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_ACTIVE_sts_Pos                                        21U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_STOP_sts_Pos                                          22U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_TIMEOUT_sts_Pos                                       23U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH7_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_ACTIVE_sts_Pos                                        24U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_ACTIVE_sts_Msk                                        (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_ACTIVE_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_STOP_sts_Pos                                          25U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_STOP_sts_Msk                                          (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_STOP_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_TIMEOUT_sts_Pos                                       26U
#define PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_TIMEOUT_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_EVNT_STS_r_TIMER1_CH8_EVNT_TIMEOUT_sts_Pos)

#define PLATFORM_REG_TIMER1_EVNT_STS_reserved_Pos                                                            27U
#define PLATFORM_REG_TIMER1_EVNT_STS_reserved_Msk                                                            (0x1FUL << PLATFORM_REG_TIMER1_EVNT_STS_reserved_Pos)

/* 0x02f8   0x4000_62f8
    0       R/W1C   r_TIMER1_CH0_TASK_DISABLE_sts                       1'b0
    1       R/W1C   r_TIMER1_CH0_TASK_PAUSE_sts                         1'b0
    2       R/W1C   r_TIMER1_CH0_TASK_START_sts                         1'b0
    3       R/W1C   r_TIMER1_CH1_TASK_DISABLE_sts                       1'b0
    4       R/W1C   r_TIMER1_CH1_TASK_PAUSE_sts                         1'b0
    5       R/W1C   r_TIMER1_CH1_TASK_START_sts                         1'b0
    6       R/W1C   r_TIMER1_CH2_TASK_DISABLE_sts                       1'b0
    7       R/W1C   r_TIMER1_CH2_TASK_PAUSE_sts                         1'b0
    8       R/W1C   r_TIMER1_CH2_TASK_START_sts                         1'b0
    9       R/W1C   r_TIMER1_CH3_TASK_DISABLE_sts                       1'b0
    10      R/W1C   r_TIMER1_CH3_TASK_PAUSE_sts                         1'b0
    11      R/W1C   r_TIMER1_CH3_TASK_START_sts                         1'b0
    12      R/W1C   r_TIMER1_CH4_TASK_DISABLE_sts                       1'b0
    13      R/W1C   r_TIMER1_CH4_TASK_PAUSE_sts                         1'b0
    14      R/W1C   r_TIMER1_CH4_TASK_START_sts                         1'b0
    15      R/W1C   r_TIMER1_CH5_TASK_DISABLE_sts                       1'b0
    16      R/W1C   r_TIMER1_CH5_TASK_PAUSE_sts                         1'b0
    17      R/W1C   r_TIMER1_CH5_TASK_START_sts                         1'b0
    18      R/W1C   r_TIMER1_CH6_TASK_DISABLE_sts                       1'b0
    19      R/W1C   r_TIMER1_CH6_TASK_PAUSE_sts                         1'b0
    20      R/W1C   r_TIMER1_CH6_TASK_START_sts                         1'b0
    21      R/W1C   r_TIMER1_CH7_TASK_DISABLE_sts                       1'b0
    22      R/W1C   r_TIMER1_CH7_TASK_PAUSE_sts                         1'b0
    23      R/W1C   r_TIMER1_CH7_TASK_START_sts                         1'b0
    24      R/W1C   r_TIMER1_CH8_TASK_DISABLE_sts                       1'b0
    25      R/W1C   r_TIMER1_CH8_TASK_PAUSE_sts                         1'b0
    26      R/W1C   r_TIMER1_CH8_TASK_START_sts                         1'b0
    31:27   R       reserved                                            5'h00
 */
typedef union _PLATFORM_REG_TIMER1_TASK_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_TIMER1_CH0_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH0_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH0_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH1_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH1_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH1_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH2_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH2_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH2_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH3_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH3_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH3_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH4_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH4_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH4_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH5_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH5_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH5_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH6_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH6_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH6_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH7_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH7_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH7_TASK_START_sts: 1;
        uint32_t r_TIMER1_CH8_TASK_DISABLE_sts: 1;
        uint32_t r_TIMER1_CH8_TASK_PAUSE_sts: 1;
        uint32_t r_TIMER1_CH8_TASK_START_sts: 1;
        uint32_t reserved: 5;
    };
} PLATFORM_REG_TIMER1_TASK_STS_TYPE;

/*0x4000_62f8 PLATFORM_REG_TIMER1_TASK_STS*/
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_DISABLE_sts_Pos                                       0U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_PAUSE_sts_Pos                                         1U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_START_sts_Pos                                         2U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH0_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_DISABLE_sts_Pos                                       3U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_PAUSE_sts_Pos                                         4U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_START_sts_Pos                                         5U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH1_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_DISABLE_sts_Pos                                       6U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_PAUSE_sts_Pos                                         7U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_START_sts_Pos                                         8U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH2_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_DISABLE_sts_Pos                                       9U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_PAUSE_sts_Pos                                         10U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_START_sts_Pos                                         11U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH3_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_DISABLE_sts_Pos                                       12U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_PAUSE_sts_Pos                                         13U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_START_sts_Pos                                         14U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH4_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_DISABLE_sts_Pos                                       15U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_PAUSE_sts_Pos                                         16U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_START_sts_Pos                                         17U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH5_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_DISABLE_sts_Pos                                       18U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_PAUSE_sts_Pos                                         19U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_START_sts_Pos                                         20U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH6_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_DISABLE_sts_Pos                                       21U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_PAUSE_sts_Pos                                         22U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_START_sts_Pos                                         23U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH7_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_DISABLE_sts_Pos                                       24U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_DISABLE_sts_Msk                                       (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_DISABLE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_PAUSE_sts_Pos                                         25U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_PAUSE_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_PAUSE_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_START_sts_Pos                                         26U
#define PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_TIMER1_TASK_STS_r_TIMER1_CH8_TASK_START_sts_Pos)

#define PLATFORM_REG_TIMER1_TASK_STS_reserved_Pos                                                            27U
#define PLATFORM_REG_TIMER1_TASK_STS_reserved_Msk                                                            (0x1FUL << PLATFORM_REG_TIMER1_TASK_STS_reserved_Pos)

/* 0x02fc   0x4000_62fc
    0       R/W1C   r_GPIO0_0_EVNT_IN_sts                               1'b0
    1       R/W1C   r_GPIO0_1_EVNT_IN_sts                               1'b0
    2       R/W1C   r_GPIO0_2_EVNT_IN_sts                               1'b0
    3       R/W1C   r_GPIO0_3_EVNT_IN_sts                               1'b0
    4       R/W1C   r_GPIO0_4_EVNT_IN_sts                               1'b0
    5       R/W1C   r_GPIO0_5_EVNT_IN_sts                               1'b0
    6       R/W1C   r_GPIO0_6_EVNT_IN_sts                               1'b0
    7       R/W1C   r_GPIO0_7_EVNT_IN_sts                               1'b0
    8       R/W1C   r_GPIO0_8_EVNT_IN_sts                               1'b0
    9       R/W1C   r_GPIO0_9_EVNT_IN_sts                               1'b0
    10      R/W1C   r_GPIO0_10_EVNT_IN_sts                              1'b0
    11      R/W1C   r_GPIO0_11_EVNT_IN_sts                              1'b0
    12      R/W1C   r_GPIO0_12_EVNT_IN_sts                              1'b0
    13      R/W1C   r_GPIO0_13_EVNT_IN_sts                              1'b0
    14      R/W1C   r_GPIO0_14_EVNT_IN_sts                              1'b0
    15      R/W1C   r_GPIO0_15_EVNT_IN_sts                              1'b0
    16      R/W1C   r_GPIO0_16_EVNT_IN_sts                              1'b0
    17      R/W1C   r_GPIO0_17_EVNT_IN_sts                              1'b0
    18      R/W1C   r_GPIO0_18_EVNT_IN_sts                              1'b0
    19      R/W1C   r_GPIO0_19_EVNT_IN_sts                              1'b0
    20      R/W1C   r_GPIO0_20_EVNT_IN_sts                              1'b0
    21      R/W1C   r_GPIO0_21_EVNT_IN_sts                              1'b0
    22      R/W1C   r_GPIO0_22_EVNT_IN_sts                              1'b0
    23      R/W1C   r_GPIO0_23_EVNT_IN_sts                              1'b0
    24      R/W1C   r_GPIO0_24_EVNT_IN_sts                              1'b0
    25      R/W1C   r_GPIO0_25_EVNT_IN_sts                              1'b0
    26      R/W1C   r_GPIO0_26_EVNT_IN_sts                              1'b0
    27      R/W1C   r_GPIO0_27_EVNT_IN_sts                              1'b0
    28      R/W1C   r_GPIO0_28_EVNT_IN_sts                              1'b0
    29      R/W1C   r_GPIO0_29_EVNT_IN_sts                              1'b0
    30      R/W1C   r_GPIO0_30_EVNT_IN_sts                              1'b0
    31      R/W1C   r_GPIO0_31_EVNT_IN_sts                              1'b0
 */
typedef union _PLATFORM_REG_GPIO_0_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_0_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_1_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_2_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_3_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_4_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_5_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_6_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_7_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_8_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_9_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_10_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_11_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_12_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_13_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_14_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_15_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_16_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_17_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_18_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_19_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_20_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_21_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_22_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_23_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_24_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_25_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_26_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_27_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_28_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_29_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_30_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_31_EVNT_IN_sts: 1;
    };
} PLATFORM_REG_GPIO_0_EVNT_STS_TYPE;

/*0x4000_62fc PLATFORM_REG_GPIO_0_EVNT_STS*/
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_0_EVNT_IN_sts_Pos                                               0U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_0_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_0_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_1_EVNT_IN_sts_Pos                                               1U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_1_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_1_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_2_EVNT_IN_sts_Pos                                               2U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_2_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_2_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_3_EVNT_IN_sts_Pos                                               3U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_3_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_3_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_4_EVNT_IN_sts_Pos                                               4U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_4_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_4_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_5_EVNT_IN_sts_Pos                                               5U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_5_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_5_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_6_EVNT_IN_sts_Pos                                               6U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_6_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_6_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_7_EVNT_IN_sts_Pos                                               7U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_7_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_7_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_8_EVNT_IN_sts_Pos                                               8U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_8_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_8_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_9_EVNT_IN_sts_Pos                                               9U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_9_EVNT_IN_sts_Msk                                               (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_9_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_10_EVNT_IN_sts_Pos                                              10U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_10_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_10_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_11_EVNT_IN_sts_Pos                                              11U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_11_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_11_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_12_EVNT_IN_sts_Pos                                              12U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_12_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_12_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_13_EVNT_IN_sts_Pos                                              13U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_13_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_13_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_14_EVNT_IN_sts_Pos                                              14U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_14_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_14_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_15_EVNT_IN_sts_Pos                                              15U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_15_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_15_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_16_EVNT_IN_sts_Pos                                              16U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_16_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_16_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_17_EVNT_IN_sts_Pos                                              17U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_17_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_17_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_18_EVNT_IN_sts_Pos                                              18U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_18_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_18_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_19_EVNT_IN_sts_Pos                                              19U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_19_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_19_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_20_EVNT_IN_sts_Pos                                              20U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_20_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_20_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_21_EVNT_IN_sts_Pos                                              21U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_21_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_21_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_22_EVNT_IN_sts_Pos                                              22U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_22_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_22_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_23_EVNT_IN_sts_Pos                                              23U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_23_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_23_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_24_EVNT_IN_sts_Pos                                              24U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_24_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_24_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_25_EVNT_IN_sts_Pos                                              25U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_25_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_25_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_26_EVNT_IN_sts_Pos                                              26U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_26_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_26_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_27_EVNT_IN_sts_Pos                                              27U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_27_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_27_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_28_EVNT_IN_sts_Pos                                              28U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_28_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_28_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_29_EVNT_IN_sts_Pos                                              29U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_29_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_29_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_30_EVNT_IN_sts_Pos                                              30U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_30_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_30_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_31_EVNT_IN_sts_Pos                                              31U
#define PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_31_EVNT_IN_sts_Msk                                              (0x1UL << PLATFORM_REG_GPIO_0_EVNT_STS_r_GPIO0_31_EVNT_IN_sts_Pos)

/* 0x0300   0x4000_6300
    0       R/W1C   r_GPIO0_32_EVNT_IN_sts                              1'b0
    1       R/W1C   r_GPIO0_33_EVNT_IN_sts                              1'b0
    2       R/W1C   r_GPIO0_34_EVNT_IN_sts                              1'b0
    3       R/W1C   r_GPIO0_35_EVNT_IN_sts                              1'b0
    4       R/W1C   r_GPIO0_36_EVNT_IN_sts                              1'b0
    5       R/W1C   r_GPIO0_37_EVNT_IN_sts                              1'b0
    6       R/W1C   r_GPIO0_38_EVNT_IN_sts                              1'b0
    7       R/W1C   r_GPIO0_39_EVNT_IN_sts                              1'b0
    8       R/W1C   r_GPIO0_40_EVNT_IN_sts                              1'b0
    9       R/W1C   r_GPIO0_41_EVNT_IN_sts                              1'b0
    10      R/W1C   r_GPIO0_42_EVNT_IN_sts                              1'b0
    11      R/W1C   r_GPIO0_43_EVNT_IN_sts                              1'b0
    12      R/W1C   r_GPIO0_44_EVNT_IN_sts                              1'b0
    13      R/W1C   r_GPIO0_45_EVNT_IN_sts                              1'b0
    14      R/W1C   r_GPIO0_46_EVNT_IN_sts                              1'b0
    15      R/W1C   r_GPIO0_47_EVNT_IN_sts                              1'b0
    16      R/W1C   r_GPIO0_48_EVNT_IN_sts                              1'b0
    17      R/W1C   r_GPIO0_49_EVNT_IN_sts                              1'b0
    31:18   R       reserved                                            14'h0000
 */
typedef union _PLATFORM_REG_GPIO_1_EVENT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_32_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_33_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_34_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_35_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_36_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_37_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_38_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_39_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_40_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_41_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_42_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_43_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_44_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_45_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_46_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_47_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_48_EVNT_IN_sts: 1;
        uint32_t r_GPIO0_49_EVNT_IN_sts: 1;
        uint32_t reserved: 14;
    };
} PLATFORM_REG_GPIO_1_EVENT_STS_TYPE;

/*0x4000_6300 PLATFORM_REG_GPIO_1_EVENT_STS*/
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_32_EVNT_IN_sts_Pos                                             0U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_32_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_32_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_33_EVNT_IN_sts_Pos                                             1U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_33_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_33_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_34_EVNT_IN_sts_Pos                                             2U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_34_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_34_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_35_EVNT_IN_sts_Pos                                             3U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_35_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_35_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_36_EVNT_IN_sts_Pos                                             4U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_36_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_36_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_37_EVNT_IN_sts_Pos                                             5U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_37_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_37_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_38_EVNT_IN_sts_Pos                                             6U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_38_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_38_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_39_EVNT_IN_sts_Pos                                             7U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_39_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_39_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_40_EVNT_IN_sts_Pos                                             8U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_40_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_40_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_41_EVNT_IN_sts_Pos                                             9U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_41_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_41_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_42_EVNT_IN_sts_Pos                                             10U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_42_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_42_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_43_EVNT_IN_sts_Pos                                             11U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_43_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_43_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_44_EVNT_IN_sts_Pos                                             12U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_44_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_44_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_45_EVNT_IN_sts_Pos                                             13U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_45_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_45_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_46_EVNT_IN_sts_Pos                                             14U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_46_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_46_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_47_EVNT_IN_sts_Pos                                             15U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_47_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_47_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_48_EVNT_IN_sts_Pos                                             16U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_48_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_48_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_49_EVNT_IN_sts_Pos                                             17U
#define PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_49_EVNT_IN_sts_Msk                                             (0x1UL << PLATFORM_REG_GPIO_1_EVENT_STS_r_GPIO0_49_EVNT_IN_sts_Pos)

#define PLATFORM_REG_GPIO_1_EVENT_STS_reserved_Pos                                                           18U
#define PLATFORM_REG_GPIO_1_EVENT_STS_reserved_Msk                                                           (0x3FFFUL << PLATFORM_REG_GPIO_1_EVENT_STS_reserved_Pos)

/* 0x0314   0x4000_6314
    0       R/W1C   r_GPIO0_0_TASK_DRCLR_sts                            1'b0
    1       R/W1C   r_GPIO0_1_TASK_DRCLR_sts                            1'b0
    2       R/W1C   r_GPIO0_2_TASK_DRCLR_sts                            1'b0
    3       R/W1C   r_GPIO0_3_TASK_DRCLR_sts                            1'b0
    4       R/W1C   r_GPIO0_4_TASK_DRCLR_sts                            1'b0
    5       R/W1C   r_GPIO0_5_TASK_DRCLR_sts                            1'b0
    6       R/W1C   r_GPIO0_6_TASK_DRCLR_sts                            1'b0
    7       R/W1C   r_GPIO0_7_TASK_DRCLR_sts                            1'b0
    8       R/W1C   r_GPIO0_8_TASK_DRCLR_sts                            1'b0
    9       R/W1C   r_GPIO0_9_TASK_DRCLR_sts                            1'b0
    10      R/W1C   r_GPIO0_10_TASK_DRCLR_sts                           1'b0
    11      R/W1C   r_GPIO0_11_TASK_DRCLR_sts                           1'b0
    12      R/W1C   r_GPIO0_12_TASK_DRCLR_sts                           1'b0
    13      R/W1C   r_GPIO0_13_TASK_DRCLR_sts                           1'b0
    14      R/W1C   r_GPIO0_14_TASK_DRCLR_sts                           1'b0
    15      R/W1C   r_GPIO0_15_TASK_DRCLR_sts                           1'b0
    16      R/W1C   r_GPIO0_16_TASK_DRCLR_sts                           1'b0
    17      R/W1C   r_GPIO0_17_TASK_DRCLR_sts                           1'b0
    18      R/W1C   r_GPIO0_18_TASK_DRCLR_sts                           1'b0
    19      R/W1C   r_GPIO0_19_TASK_DRCLR_sts                           1'b0
    20      R/W1C   r_GPIO0_20_TASK_DRCLR_sts                           1'b0
    21      R/W1C   r_GPIO0_21_TASK_DRCLR_sts                           1'b0
    22      R/W1C   r_GPIO0_22_TASK_DRCLR_sts                           1'b0
    23      R/W1C   r_GPIO0_23_TASK_DRCLR_sts                           1'b0
    24      R/W1C   r_GPIO0_24_TASK_DRCLR_sts                           1'b0
    25      R/W1C   r_GPIO0_25_TASK_DRCLR_sts                           1'b0
    26      R/W1C   r_GPIO0_26_TASK_DRCLR_sts                           1'b0
    27      R/W1C   r_GPIO0_27_TASK_DRCLR_sts                           1'b0
    28      R/W1C   r_GPIO0_28_TASK_DRCLR_sts                           1'b0
    29      R/W1C   r_GPIO0_29_TASK_DRCLR_sts                           1'b0
    30      R/W1C   r_GPIO0_30_TASK_DRCLR_sts                           1'b0
    31      R/W1C   r_GPIO0_31_TASK_DRCLR_sts                           1'b0
 */
typedef union _PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_0_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_1_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_2_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_3_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_4_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_5_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_6_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_7_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_8_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_9_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_10_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_11_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_12_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_13_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_14_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_15_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_16_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_17_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_18_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_19_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_20_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_21_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_22_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_23_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_24_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_25_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_26_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_27_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_28_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_29_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_30_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_31_TASK_DRCLR_sts: 1;
    };
} PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_TYPE;

/*0x4000_6314 PLATFORM_REG_GPIO_0_TASK_DRCLR_STS*/
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_0_TASK_DRCLR_sts_Pos                                      0U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_0_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_0_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_1_TASK_DRCLR_sts_Pos                                      1U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_1_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_1_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_2_TASK_DRCLR_sts_Pos                                      2U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_2_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_2_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_3_TASK_DRCLR_sts_Pos                                      3U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_3_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_3_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_4_TASK_DRCLR_sts_Pos                                      4U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_4_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_4_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_5_TASK_DRCLR_sts_Pos                                      5U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_5_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_5_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_6_TASK_DRCLR_sts_Pos                                      6U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_6_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_6_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_7_TASK_DRCLR_sts_Pos                                      7U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_7_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_7_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_8_TASK_DRCLR_sts_Pos                                      8U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_8_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_8_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_9_TASK_DRCLR_sts_Pos                                      9U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_9_TASK_DRCLR_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_9_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_10_TASK_DRCLR_sts_Pos                                     10U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_10_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_10_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_11_TASK_DRCLR_sts_Pos                                     11U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_11_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_11_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_12_TASK_DRCLR_sts_Pos                                     12U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_12_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_12_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_13_TASK_DRCLR_sts_Pos                                     13U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_13_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_13_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_14_TASK_DRCLR_sts_Pos                                     14U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_14_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_14_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_15_TASK_DRCLR_sts_Pos                                     15U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_15_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_15_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_16_TASK_DRCLR_sts_Pos                                     16U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_16_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_16_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_17_TASK_DRCLR_sts_Pos                                     17U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_17_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_17_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_18_TASK_DRCLR_sts_Pos                                     18U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_18_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_18_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_19_TASK_DRCLR_sts_Pos                                     19U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_19_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_19_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_20_TASK_DRCLR_sts_Pos                                     20U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_20_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_20_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_21_TASK_DRCLR_sts_Pos                                     21U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_21_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_21_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_22_TASK_DRCLR_sts_Pos                                     22U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_22_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_22_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_23_TASK_DRCLR_sts_Pos                                     23U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_23_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_23_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_24_TASK_DRCLR_sts_Pos                                     24U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_24_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_24_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_25_TASK_DRCLR_sts_Pos                                     25U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_25_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_25_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_26_TASK_DRCLR_sts_Pos                                     26U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_26_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_26_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_27_TASK_DRCLR_sts_Pos                                     27U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_27_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_27_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_28_TASK_DRCLR_sts_Pos                                     28U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_28_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_28_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_29_TASK_DRCLR_sts_Pos                                     29U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_29_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_29_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_30_TASK_DRCLR_sts_Pos                                     30U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_30_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_30_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_31_TASK_DRCLR_sts_Pos                                     31U
#define PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_31_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRCLR_STS_r_GPIO0_31_TASK_DRCLR_sts_Pos)

/* 0x0318   0x4000_6318
    0       R/W1C   r_GPIO0_32_TASK_DRCLR_sts                           1'b0
    1       R/W1C   r_GPIO0_33_TASK_DRCLR_sts                           1'b0
    2       R/W1C   r_GPIO0_34_TASK_DRCLR_sts                           1'b0
    3       R/W1C   r_GPIO0_35_TASK_DRCLR_sts                           1'b0
    4       R/W1C   r_GPIO0_36_TASK_DRCLR_sts                           1'b0
    5       R/W1C   r_GPIO0_37_TASK_DRCLR_sts                           1'b0
    6       R/W1C   r_GPIO0_38_TASK_DRCLR_sts                           1'b0
    7       R/W1C   r_GPIO0_39_TASK_DRCLR_sts                           1'b0
    8       R/W1C   r_GPIO0_40_TASK_DRCLR_sts                           1'b0
    9       R/W1C   r_GPIO0_41_TASK_DRCLR_sts                           1'b0
    10      R/W1C   r_GPIO0_42_TASK_DRCLR_sts                           1'b0
    11      R/W1C   r_GPIO0_43_TASK_DRCLR_sts                           1'b0
    12      R/W1C   r_GPIO0_44_TASK_DRCLR_sts                           1'b0
    13      R/W1C   r_GPIO0_45_TASK_DRCLR_sts                           1'b0
    14      R/W1C   r_GPIO0_46_TASK_DRCLR_sts                           1'b0
    15      R/W1C   r_GPIO0_47_TASK_DRCLR_sts                           1'b0
    16      R/W1C   r_GPIO0_48_TASK_DRCLR_sts                           1'b0
    17      R/W1C   r_GPIO0_49_TASK_DRCLR_sts                           1'b0
    31:18   R       reserved                                            14'h0000
 */
typedef union _PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_32_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_33_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_34_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_35_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_36_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_37_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_38_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_39_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_40_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_41_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_42_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_43_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_44_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_45_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_46_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_47_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_48_TASK_DRCLR_sts: 1;
        uint32_t r_GPIO0_49_TASK_DRCLR_sts: 1;
        uint32_t reserved: 14;
    };
} PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_TYPE;

/*0x4000_6318 PLATFORM_REG_GPIO_1_TASK_DRCLR_STS*/
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_32_TASK_DRCLR_sts_Pos                                     0U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_32_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_32_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_33_TASK_DRCLR_sts_Pos                                     1U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_33_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_33_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_34_TASK_DRCLR_sts_Pos                                     2U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_34_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_34_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_35_TASK_DRCLR_sts_Pos                                     3U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_35_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_35_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_36_TASK_DRCLR_sts_Pos                                     4U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_36_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_36_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_37_TASK_DRCLR_sts_Pos                                     5U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_37_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_37_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_38_TASK_DRCLR_sts_Pos                                     6U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_38_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_38_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_39_TASK_DRCLR_sts_Pos                                     7U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_39_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_39_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_40_TASK_DRCLR_sts_Pos                                     8U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_40_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_40_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_41_TASK_DRCLR_sts_Pos                                     9U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_41_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_41_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_42_TASK_DRCLR_sts_Pos                                     10U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_42_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_42_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_43_TASK_DRCLR_sts_Pos                                     11U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_43_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_43_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_44_TASK_DRCLR_sts_Pos                                     12U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_44_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_44_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_45_TASK_DRCLR_sts_Pos                                     13U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_45_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_45_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_46_TASK_DRCLR_sts_Pos                                     14U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_46_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_46_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_47_TASK_DRCLR_sts_Pos                                     15U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_47_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_47_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_48_TASK_DRCLR_sts_Pos                                     16U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_48_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_48_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_49_TASK_DRCLR_sts_Pos                                     17U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_49_TASK_DRCLR_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_r_GPIO0_49_TASK_DRCLR_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_reserved_Pos                                                      18U
#define PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_reserved_Msk                                                      (0x3FFFUL << PLATFORM_REG_GPIO_1_TASK_DRCLR_STS_reserved_Pos)

/* 0x031c   0x4000_631c
    0       R/W1C   r_GPIO0_0_TASK_DRSET_sts                            1'b0
    1       R/W1C   r_GPIO0_1_TASK_DRSET_sts                            1'b0
    2       R/W1C   r_GPIO0_2_TASK_DRSET_sts                            1'b0
    3       R/W1C   r_GPIO0_3_TASK_DRSET_sts                            1'b0
    4       R/W1C   r_GPIO0_4_TASK_DRSET_sts                            1'b0
    5       R/W1C   r_GPIO0_5_TASK_DRSET_sts                            1'b0
    6       R/W1C   r_GPIO0_6_TASK_DRSET_sts                            1'b0
    7       R/W1C   r_GPIO0_7_TASK_DRSET_sts                            1'b0
    8       R/W1C   r_GPIO0_8_TASK_DRSET_sts                            1'b0
    9       R/W1C   r_GPIO0_9_TASK_DRSET_sts                            1'b0
    10      R/W1C   r_GPIO0_10_TASK_DRSET_sts                           1'b0
    11      R/W1C   r_GPIO0_11_TASK_DRSET_sts                           1'b0
    12      R/W1C   r_GPIO0_12_TASK_DRSET_sts                           1'b0
    13      R/W1C   r_GPIO0_13_TASK_DRSET_sts                           1'b0
    14      R/W1C   r_GPIO0_14_TASK_DRSET_sts                           1'b0
    15      R/W1C   r_GPIO0_15_TASK_DRSET_sts                           1'b0
    16      R/W1C   r_GPIO0_16_TASK_DRSET_sts                           1'b0
    17      R/W1C   r_GPIO0_17_TASK_DRSET_sts                           1'b0
    18      R/W1C   r_GPIO0_18_TASK_DRSET_sts                           1'b0
    19      R/W1C   r_GPIO0_19_TASK_DRSET_sts                           1'b0
    20      R/W1C   r_GPIO0_20_TASK_DRSET_sts                           1'b0
    21      R/W1C   r_GPIO0_21_TASK_DRSET_sts                           1'b0
    22      R/W1C   r_GPIO0_22_TASK_DRSET_sts                           1'b0
    23      R/W1C   r_GPIO0_23_TASK_DRSET_sts                           1'b0
    24      R/W1C   r_GPIO0_24_TASK_DRSET_sts                           1'b0
    25      R/W1C   r_GPIO0_25_TASK_DRSET_sts                           1'b0
    26      R/W1C   r_GPIO0_26_TASK_DRSET_sts                           1'b0
    27      R/W1C   r_GPIO0_27_TASK_DRSET_sts                           1'b0
    28      R/W1C   r_GPIO0_28_TASK_DRSET_sts                           1'b0
    29      R/W1C   r_GPIO0_29_TASK_DRSET_sts                           1'b0
    30      R/W1C   r_GPIO0_30_TASK_DRSET_sts                           1'b0
    31      R/W1C   r_GPIO0_31_TASK_DRSET_sts                           1'b0
 */
typedef union _PLATFORM_REG_GPIO_0_TASK_DRSET_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_0_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_1_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_2_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_3_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_4_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_5_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_6_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_7_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_8_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_9_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_10_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_11_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_12_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_13_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_14_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_15_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_16_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_17_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_18_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_19_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_20_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_21_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_22_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_23_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_24_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_25_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_26_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_27_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_28_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_29_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_30_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_31_TASK_DRSET_sts: 1;
    };
} PLATFORM_REG_GPIO_0_TASK_DRSET_STS_TYPE;

/*0x4000_631c PLATFORM_REG_GPIO_0_TASK_DRSET_STS*/
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_0_TASK_DRSET_sts_Pos                                      0U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_0_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_0_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_1_TASK_DRSET_sts_Pos                                      1U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_1_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_1_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_2_TASK_DRSET_sts_Pos                                      2U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_2_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_2_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_3_TASK_DRSET_sts_Pos                                      3U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_3_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_3_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_4_TASK_DRSET_sts_Pos                                      4U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_4_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_4_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_5_TASK_DRSET_sts_Pos                                      5U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_5_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_5_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_6_TASK_DRSET_sts_Pos                                      6U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_6_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_6_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_7_TASK_DRSET_sts_Pos                                      7U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_7_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_7_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_8_TASK_DRSET_sts_Pos                                      8U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_8_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_8_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_9_TASK_DRSET_sts_Pos                                      9U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_9_TASK_DRSET_sts_Msk                                      (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_9_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_10_TASK_DRSET_sts_Pos                                     10U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_10_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_10_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_11_TASK_DRSET_sts_Pos                                     11U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_11_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_11_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_12_TASK_DRSET_sts_Pos                                     12U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_12_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_12_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_13_TASK_DRSET_sts_Pos                                     13U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_13_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_13_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_14_TASK_DRSET_sts_Pos                                     14U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_14_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_14_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_15_TASK_DRSET_sts_Pos                                     15U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_15_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_15_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_16_TASK_DRSET_sts_Pos                                     16U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_16_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_16_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_17_TASK_DRSET_sts_Pos                                     17U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_17_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_17_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_18_TASK_DRSET_sts_Pos                                     18U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_18_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_18_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_19_TASK_DRSET_sts_Pos                                     19U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_19_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_19_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_20_TASK_DRSET_sts_Pos                                     20U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_20_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_20_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_21_TASK_DRSET_sts_Pos                                     21U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_21_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_21_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_22_TASK_DRSET_sts_Pos                                     22U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_22_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_22_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_23_TASK_DRSET_sts_Pos                                     23U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_23_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_23_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_24_TASK_DRSET_sts_Pos                                     24U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_24_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_24_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_25_TASK_DRSET_sts_Pos                                     25U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_25_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_25_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_26_TASK_DRSET_sts_Pos                                     26U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_26_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_26_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_27_TASK_DRSET_sts_Pos                                     27U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_27_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_27_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_28_TASK_DRSET_sts_Pos                                     28U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_28_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_28_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_29_TASK_DRSET_sts_Pos                                     29U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_29_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_29_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_30_TASK_DRSET_sts_Pos                                     30U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_30_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_30_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_31_TASK_DRSET_sts_Pos                                     31U
#define PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_31_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRSET_STS_r_GPIO0_31_TASK_DRSET_sts_Pos)

/* 0x0320   0x4000_6320
    0       R/W1C   r_GPIO0_32_TASK_DRSET_sts                           1'b0
    1       R/W1C   r_GPIO0_33_TASK_DRSET_sts                           1'b0
    2       R/W1C   r_GPIO0_34_TASK_DRSET_sts                           1'b0
    3       R/W1C   r_GPIO0_35_TASK_DRSET_sts                           1'b0
    4       R/W1C   r_GPIO0_36_TASK_DRSET_sts                           1'b0
    5       R/W1C   r_GPIO0_37_TASK_DRSET_sts                           1'b0
    6       R/W1C   r_GPIO0_38_TASK_DRSET_sts                           1'b0
    7       R/W1C   r_GPIO0_39_TASK_DRSET_sts                           1'b0
    8       R/W1C   r_GPIO0_40_TASK_DRSET_sts                           1'b0
    9       R/W1C   r_GPIO0_41_TASK_DRSET_sts                           1'b0
    10      R/W1C   r_GPIO0_42_TASK_DRSET_sts                           1'b0
    11      R/W1C   r_GPIO0_43_TASK_DRSET_sts                           1'b0
    12      R/W1C   r_GPIO0_44_TASK_DRSET_sts                           1'b0
    13      R/W1C   r_GPIO0_45_TASK_DRSET_sts                           1'b0
    14      R/W1C   r_GPIO0_46_TASK_DRSET_sts                           1'b0
    15      R/W1C   r_GPIO0_47_TASK_DRSET_sts                           1'b0
    16      R/W1C   r_GPIO0_48_TASK_DRSET_sts                           1'b0
    17      R/W1C   r_GPIO0_49_TASK_DRSET_sts                           1'b0
    31:18   R       reserved                                            14'h0000
 */
typedef union _PLATFORM_REG_GPIO_1_TASK_DRSET_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_32_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_33_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_34_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_35_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_36_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_37_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_38_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_39_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_40_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_41_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_42_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_43_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_44_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_45_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_46_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_47_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_48_TASK_DRSET_sts: 1;
        uint32_t r_GPIO0_49_TASK_DRSET_sts: 1;
        uint32_t reserved: 14;
    };
} PLATFORM_REG_GPIO_1_TASK_DRSET_STS_TYPE;

/*0x4000_6320 PLATFORM_REG_GPIO_1_TASK_DRSET_STS*/
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_32_TASK_DRSET_sts_Pos                                     0U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_32_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_32_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_33_TASK_DRSET_sts_Pos                                     1U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_33_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_33_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_34_TASK_DRSET_sts_Pos                                     2U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_34_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_34_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_35_TASK_DRSET_sts_Pos                                     3U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_35_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_35_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_36_TASK_DRSET_sts_Pos                                     4U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_36_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_36_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_37_TASK_DRSET_sts_Pos                                     5U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_37_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_37_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_38_TASK_DRSET_sts_Pos                                     6U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_38_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_38_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_39_TASK_DRSET_sts_Pos                                     7U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_39_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_39_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_40_TASK_DRSET_sts_Pos                                     8U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_40_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_40_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_41_TASK_DRSET_sts_Pos                                     9U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_41_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_41_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_42_TASK_DRSET_sts_Pos                                     10U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_42_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_42_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_43_TASK_DRSET_sts_Pos                                     11U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_43_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_43_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_44_TASK_DRSET_sts_Pos                                     12U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_44_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_44_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_45_TASK_DRSET_sts_Pos                                     13U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_45_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_45_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_46_TASK_DRSET_sts_Pos                                     14U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_46_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_46_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_47_TASK_DRSET_sts_Pos                                     15U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_47_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_47_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_48_TASK_DRSET_sts_Pos                                     16U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_48_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_48_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_49_TASK_DRSET_sts_Pos                                     17U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_49_TASK_DRSET_sts_Msk                                     (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_r_GPIO0_49_TASK_DRSET_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_reserved_Pos                                                      18U
#define PLATFORM_REG_GPIO_1_TASK_DRSET_STS_reserved_Msk                                                      (0x3FFFUL << PLATFORM_REG_GPIO_1_TASK_DRSET_STS_reserved_Pos)

/* 0x0324   0x4000_6324
    0       R/W1C   r_GPIO0_0_TASK_DRTOGGLE_sts                         1'b0
    1       R/W1C   r_GPIO0_1_TASK_DRTOGGLE_sts                         1'b0
    2       R/W1C   r_GPIO0_2_TASK_DRTOGGLE_sts                         1'b0
    3       R/W1C   r_GPIO0_3_TASK_DRTOGGLE_sts                         1'b0
    4       R/W1C   r_GPIO0_4_TASK_DRTOGGLE_sts                         1'b0
    5       R/W1C   r_GPIO0_5_TASK_DRTOGGLE_sts                         1'b0
    6       R/W1C   r_GPIO0_6_TASK_DRTOGGLE_sts                         1'b0
    7       R/W1C   r_GPIO0_7_TASK_DRTOGGLE_sts                         1'b0
    8       R/W1C   r_GPIO0_8_TASK_DRTOGGLE_sts                         1'b0
    9       R/W1C   r_GPIO0_9_TASK_DRTOGGLE_sts                         1'b0
    10      R/W1C   r_GPIO0_10_TASK_DRTOGGLE_sts                        1'b0
    11      R/W1C   r_GPIO0_11_TASK_DRTOGGLE_sts                        1'b0
    12      R/W1C   r_GPIO0_12_TASK_DRTOGGLE_sts                        1'b0
    13      R/W1C   r_GPIO0_13_TASK_DRTOGGLE_sts                        1'b0
    14      R/W1C   r_GPIO0_14_TASK_DRTOGGLE_sts                        1'b0
    15      R/W1C   r_GPIO0_15_TASK_DRTOGGLE_sts                        1'b0
    16      R/W1C   r_GPIO0_16_TASK_DRTOGGLE_sts                        1'b0
    17      R/W1C   r_GPIO0_17_TASK_DRTOGGLE_sts                        1'b0
    18      R/W1C   r_GPIO0_18_TASK_DRTOGGLE_sts                        1'b0
    19      R/W1C   r_GPIO0_19_TASK_DRTOGGLE_sts                        1'b0
    20      R/W1C   r_GPIO0_20_TASK_DRTOGGLE_sts                        1'b0
    21      R/W1C   r_GPIO0_21_TASK_DRTOGGLE_sts                        1'b0
    22      R/W1C   r_GPIO0_22_TASK_DRTOGGLE_sts                        1'b0
    23      R/W1C   r_GPIO0_23_TASK_DRTOGGLE_sts                        1'b0
    24      R/W1C   r_GPIO0_24_TASK_DRTOGGLE_sts                        1'b0
    25      R/W1C   r_GPIO0_25_TASK_DRTOGGLE_sts                        1'b0
    26      R/W1C   r_GPIO0_26_TASK_DRTOGGLE_sts                        1'b0
    27      R/W1C   r_GPIO0_27_TASK_DRTOGGLE_sts                        1'b0
    28      R/W1C   r_GPIO0_28_TASK_DRTOGGLE_sts                        1'b0
    29      R/W1C   r_GPIO0_29_TASK_DRTOGGLE_sts                        1'b0
    30      R/W1C   r_GPIO0_30_TASK_DRTOGGLE_sts                        1'b0
    31      R/W1C   r_GPIO0_31_TASK_DRTOGGLE_sts                        1'b0
 */
typedef union _PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_0_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_1_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_2_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_3_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_4_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_5_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_6_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_7_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_8_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_9_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_10_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_11_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_12_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_13_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_14_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_15_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_16_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_17_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_18_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_19_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_20_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_21_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_22_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_23_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_24_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_25_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_26_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_27_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_28_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_29_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_30_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_31_TASK_DRTOGGLE_sts: 1;
    };
} PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_TYPE;

/*0x4000_6324 PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS*/
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_0_TASK_DRTOGGLE_sts_Pos                                0U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_0_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_0_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_1_TASK_DRTOGGLE_sts_Pos                                1U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_1_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_1_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_2_TASK_DRTOGGLE_sts_Pos                                2U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_2_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_2_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_3_TASK_DRTOGGLE_sts_Pos                                3U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_3_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_3_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_4_TASK_DRTOGGLE_sts_Pos                                4U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_4_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_4_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_5_TASK_DRTOGGLE_sts_Pos                                5U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_5_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_5_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_6_TASK_DRTOGGLE_sts_Pos                                6U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_6_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_6_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_7_TASK_DRTOGGLE_sts_Pos                                7U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_7_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_7_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_8_TASK_DRTOGGLE_sts_Pos                                8U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_8_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_8_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_9_TASK_DRTOGGLE_sts_Pos                                9U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_9_TASK_DRTOGGLE_sts_Msk                                (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_9_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_10_TASK_DRTOGGLE_sts_Pos                               10U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_10_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_10_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_11_TASK_DRTOGGLE_sts_Pos                               11U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_11_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_11_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_12_TASK_DRTOGGLE_sts_Pos                               12U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_12_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_12_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_13_TASK_DRTOGGLE_sts_Pos                               13U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_13_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_13_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_14_TASK_DRTOGGLE_sts_Pos                               14U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_14_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_14_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_15_TASK_DRTOGGLE_sts_Pos                               15U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_15_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_15_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_16_TASK_DRTOGGLE_sts_Pos                               16U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_16_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_16_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_17_TASK_DRTOGGLE_sts_Pos                               17U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_17_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_17_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_18_TASK_DRTOGGLE_sts_Pos                               18U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_18_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_18_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_19_TASK_DRTOGGLE_sts_Pos                               19U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_19_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_19_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_20_TASK_DRTOGGLE_sts_Pos                               20U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_20_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_20_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_21_TASK_DRTOGGLE_sts_Pos                               21U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_21_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_21_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_22_TASK_DRTOGGLE_sts_Pos                               22U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_22_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_22_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_23_TASK_DRTOGGLE_sts_Pos                               23U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_23_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_23_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_24_TASK_DRTOGGLE_sts_Pos                               24U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_24_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_24_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_25_TASK_DRTOGGLE_sts_Pos                               25U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_25_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_25_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_26_TASK_DRTOGGLE_sts_Pos                               26U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_26_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_26_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_27_TASK_DRTOGGLE_sts_Pos                               27U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_27_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_27_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_28_TASK_DRTOGGLE_sts_Pos                               28U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_28_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_28_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_29_TASK_DRTOGGLE_sts_Pos                               29U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_29_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_29_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_30_TASK_DRTOGGLE_sts_Pos                               30U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_30_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_30_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_31_TASK_DRTOGGLE_sts_Pos                               31U
#define PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_31_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_0_TASK_DRTOGGLE_STS_r_GPIO0_31_TASK_DRTOGGLE_sts_Pos)

/* 0x0328   0x4000_6328
    0       R/W1C   r_GPIO0_32_TASK_DRTOGGLE_sts                        1'b0
    1       R/W1C   r_GPIO0_33_TASK_DRTOGGLE_sts                        1'b0
    2       R/W1C   r_GPIO0_34_TASK_DRTOGGLE_sts                        1'b0
    3       R/W1C   r_GPIO0_35_TASK_DRTOGGLE_sts                        1'b0
    4       R/W1C   r_GPIO0_36_TASK_DRTOGGLE_sts                        1'b0
    5       R/W1C   r_GPIO0_37_TASK_DRTOGGLE_sts                        1'b0
    6       R/W1C   r_GPIO0_38_TASK_DRTOGGLE_sts                        1'b0
    7       R/W1C   r_GPIO0_39_TASK_DRTOGGLE_sts                        1'b0
    8       R/W1C   r_GPIO0_40_TASK_DRTOGGLE_sts                        1'b0
    9       R/W1C   r_GPIO0_41_TASK_DRTOGGLE_sts                        1'b0
    10      R/W1C   r_GPIO0_42_TASK_DRTOGGLE_sts                        1'b0
    11      R/W1C   r_GPIO0_43_TASK_DRTOGGLE_sts                        1'b0
    12      R/W1C   r_GPIO0_44_TASK_DRTOGGLE_sts                        1'b0
    13      R/W1C   r_GPIO0_45_TASK_DRTOGGLE_sts                        1'b0
    14      R/W1C   r_GPIO0_46_TASK_DRTOGGLE_sts                        1'b0
    15      R/W1C   r_GPIO0_47_TASK_DRTOGGLE_sts                        1'b0
    16      R/W1C   r_GPIO0_48_TASK_DRTOGGLE_sts                        1'b0
    17      R/W1C   r_GPIO0_49_TASK_DRTOGGLE_sts                        1'b0
    30:18   R       reserved                                            13'h0000
    31      R       r_GPIO0_TASK_NOP_sts                                1'b0
 */
typedef union _PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GPIO0_32_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_33_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_34_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_35_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_36_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_37_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_38_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_39_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_40_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_41_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_42_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_43_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_44_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_45_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_46_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_47_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_48_TASK_DRTOGGLE_sts: 1;
        uint32_t r_GPIO0_49_TASK_DRTOGGLE_sts: 1;
        uint32_t reserved: 13;
        uint32_t r_GPIO0_TASK_NOP_sts: 1;
    };
} PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_TYPE;

/*0x4000_6328 PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS*/
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_32_TASK_DRTOGGLE_sts_Pos                               0U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_32_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_32_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_33_TASK_DRTOGGLE_sts_Pos                               1U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_33_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_33_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_34_TASK_DRTOGGLE_sts_Pos                               2U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_34_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_34_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_35_TASK_DRTOGGLE_sts_Pos                               3U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_35_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_35_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_36_TASK_DRTOGGLE_sts_Pos                               4U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_36_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_36_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_37_TASK_DRTOGGLE_sts_Pos                               5U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_37_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_37_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_38_TASK_DRTOGGLE_sts_Pos                               6U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_38_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_38_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_39_TASK_DRTOGGLE_sts_Pos                               7U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_39_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_39_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_40_TASK_DRTOGGLE_sts_Pos                               8U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_40_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_40_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_41_TASK_DRTOGGLE_sts_Pos                               9U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_41_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_41_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_42_TASK_DRTOGGLE_sts_Pos                               10U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_42_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_42_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_43_TASK_DRTOGGLE_sts_Pos                               11U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_43_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_43_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_44_TASK_DRTOGGLE_sts_Pos                               12U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_44_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_44_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_45_TASK_DRTOGGLE_sts_Pos                               13U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_45_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_45_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_46_TASK_DRTOGGLE_sts_Pos                               14U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_46_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_46_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_47_TASK_DRTOGGLE_sts_Pos                               15U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_47_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_47_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_48_TASK_DRTOGGLE_sts_Pos                               16U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_48_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_48_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_49_TASK_DRTOGGLE_sts_Pos                               17U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_49_TASK_DRTOGGLE_sts_Msk                               (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_49_TASK_DRTOGGLE_sts_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_reserved_Pos                                                   18U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_reserved_Msk                                                   (0x1FFFUL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_reserved_Pos)

#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_TASK_NOP_sts_Pos                                       31U
#define PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_TASK_NOP_sts_Msk                                       (0x1UL << PLATFORM_REG_GPIO_1_TASK_DRTOGGLE_STS_r_GPIO0_TASK_NOP_sts_Pos)

/* 0x0344   0x4000_6344
    0       R/W1C   r_GIRDA_EVNT_TXDONE_sts                             1'b0
    1       R/W1C   r_GIRDA_EVNT_RXDONE_sts                             1'b0
    15:2    R       reserved_1                                          14'h0000
    16      R/W1C   r_GIRDA_TASK_START_TX_sts                           1'b0
    17      R/W1C   r_GIRDA_TASK_START_RX_sts                           1'b0
    31:18   R       reserved                                            14'h0000
 */
typedef union _PLATFORM_REG_GIRDA_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_GIRDA_EVNT_TXDONE_sts: 1;
        uint32_t r_GIRDA_EVNT_RXDONE_sts: 1;
        uint32_t reserved_1: 14;
        uint32_t r_GIRDA_TASK_START_TX_sts: 1;
        uint32_t r_GIRDA_TASK_START_RX_sts: 1;
        uint32_t reserved: 14;
    };
} PLATFORM_REG_GIRDA_TASK_EVNT_STS_TYPE;

/*0x4000_6344 PLATFORM_REG_GIRDA_TASK_EVNT_STS*/
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_TXDONE_sts_Pos                                         0U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_TXDONE_sts_Msk                                         (0x1UL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_TXDONE_sts_Pos)

#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_RXDONE_sts_Pos                                         1U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_RXDONE_sts_Msk                                         (0x1UL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_EVNT_RXDONE_sts_Pos)

#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_1_Pos                                                      2U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_1_Msk                                                      (0x3FFFUL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_TX_sts_Pos                                       16U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_TX_sts_Msk                                       (0x1UL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_TX_sts_Pos)

#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_RX_sts_Pos                                       17U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_RX_sts_Msk                                       (0x1UL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_r_GIRDA_TASK_START_RX_sts_Pos)

#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_Pos                                                        18U
#define PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_Msk                                                        (0x3FFFUL << PLATFORM_REG_GIRDA_TASK_EVNT_STS_reserved_Pos)

/* 0x0348   0x4000_6348
    0       R/W1C   r_I2C0_EVNT_ERROR_sts                               1'b0
    1       R/W1C   r_I2C0_EVNT_STARTED_sts                             1'b0
    2       R/W1C   r_I2C0_EVNT_STOPPED_sts                             1'b0
    15:3    R       reserved_1                                          13'h0000
    16      R/W1C   r_I2C0_TASK_START_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_I2C0_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_I2C0_EVNT_ERROR_sts: 1;
        uint32_t r_I2C0_EVNT_STARTED_sts: 1;
        uint32_t r_I2C0_EVNT_STOPPED_sts: 1;
        uint32_t reserved_1: 13;
        uint32_t r_I2C0_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_I2C0_TASK_EVNT_STS_TYPE;

/*0x4000_6348 PLATFORM_REG_I2C0_TASK_EVNT_STS*/
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_ERROR_sts_Pos                                            0U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_ERROR_sts_Msk                                            (0x1UL << PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_ERROR_sts_Pos)

#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STARTED_sts_Pos                                          1U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STARTED_sts_Msk                                          (0x1UL << PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STARTED_sts_Pos)

#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STOPPED_sts_Pos                                          2U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STOPPED_sts_Msk                                          (0x1UL << PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_EVNT_STOPPED_sts_Pos)

#define PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_1_Pos                                                       3U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_1_Msk                                                       (0x1FFFUL << PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_TASK_START_sts_Pos                                            16U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_TASK_START_sts_Msk                                            (0x1UL << PLATFORM_REG_I2C0_TASK_EVNT_STS_r_I2C0_TASK_START_sts_Pos)

#define PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_Pos                                                         17U
#define PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_Msk                                                         (0x7FFFUL << PLATFORM_REG_I2C0_TASK_EVNT_STS_reserved_Pos)

/* 0x034c   0x4000_634c
    0       R/W1C   r_I2C1_EVNT_ERROR_sts                               1'b0
    1       R/W1C   r_I2C1_EVNT_STARTED_sts                             1'b0
    2       R/W1C   r_I2C1_EVNT_STOPPED_sts                             1'b0
    15:3    R       reserved_1                                          13'h0000
    16      R/W1C   r_I2C1_TASK_START_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_I2C1_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_I2C1_EVNT_ERROR_sts: 1;
        uint32_t r_I2C1_EVNT_STARTED_sts: 1;
        uint32_t r_I2C1_EVNT_STOPPED_sts: 1;
        uint32_t reserved_1: 13;
        uint32_t r_I2C1_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_I2C1_TASK_EVNT_STS_TYPE;

/*0x4000_634c PLATFORM_REG_I2C1_TASK_EVNT_STS*/
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_ERROR_sts_Pos                                            0U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_ERROR_sts_Msk                                            (0x1UL << PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_ERROR_sts_Pos)

#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STARTED_sts_Pos                                          1U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STARTED_sts_Msk                                          (0x1UL << PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STARTED_sts_Pos)

#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STOPPED_sts_Pos                                          2U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STOPPED_sts_Msk                                          (0x1UL << PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_EVNT_STOPPED_sts_Pos)

#define PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_1_Pos                                                       3U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_1_Msk                                                       (0x1FFFUL << PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_TASK_START_sts_Pos                                            16U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_TASK_START_sts_Msk                                            (0x1UL << PLATFORM_REG_I2C1_TASK_EVNT_STS_r_I2C1_TASK_START_sts_Pos)

#define PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_Pos                                                         17U
#define PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_Msk                                                         (0x7FFFUL << PLATFORM_REG_I2C1_TASK_EVNT_STS_reserved_Pos)

/* 0x0350   0x4000_6350
    0       R/W1C   r_AUXADC_EVNT_DONE_sts                              1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_AUXADC_TASK_ONE_SHOT_SAMPLE_sts                   1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_AUXADC_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_AUXADC_EVNT_DONE_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_AUXADC_TASK_ONE_SHOT_SAMPLE_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_AUXADC_TASK_EVNT_STS_TYPE;

/*0x4000_6350 PLATFORM_REG_AUXADC_TASK_EVNT_STS*/
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_EVNT_DONE_sts_Pos                                         0U
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_EVNT_DONE_sts_Msk                                         (0x1UL << PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_EVNT_DONE_sts_Pos)

#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_1_Pos                                                     1U
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_1_Msk                                                     (0x7FFFUL << PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_TASK_ONE_SHOT_SAMPLE_sts_Pos                              16U
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_TASK_ONE_SHOT_SAMPLE_sts_Msk                              (0x1UL << PLATFORM_REG_AUXADC_TASK_EVNT_STS_r_AUXADC_TASK_ONE_SHOT_SAMPLE_sts_Pos)

#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_Pos                                                       17U
#define PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_Msk                                                       (0x7FFFUL << PLATFORM_REG_AUXADC_TASK_EVNT_STS_reserved_Pos)

/* 0x0354   0x4000_6354
    0       R/W1C   r_SPI3W_EVNT_END_sts                                1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_SPI3W_TASK_START_sts                              1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_SPI3W_EVNT_END_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_SPI3W_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_TYPE;

/*0x4000_6354 PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS*/
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_EVNT_END_sts_Pos                                         0U
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_EVNT_END_sts_Msk                                         (0x1UL << PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_EVNT_END_sts_Pos)

#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_1_Pos                                                   1U
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_1_Msk                                                   (0x7FFFUL << PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_TASK_START_sts_Pos                                       16U
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_TASK_START_sts_Msk                                       (0x1UL << PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_r_SPI3W_TASK_START_sts_Pos)

#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_Pos                                                     17U
#define PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_Msk                                                     (0x7FFFUL << PLATFORM_REG_SPI3WIRE_TASK_EVNT_STS_reserved_Pos)

/* 0x0358   0x4000_6358
    0       R/W1C   r_SPI0_EVNT_START_sts                               1'b0
    1       R/W1C   r_SPI0_EVNT_END_sts                                 1'b0
    15:2    R       reserved_1                                          14'h0000
    16      R/W1C   r_SPI0_TASK_START_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_SPI0_EVNT_START_sts: 1;
        uint32_t r_SPI0_EVNT_END_sts: 1;
        uint32_t reserved_1: 14;
        uint32_t r_SPI0_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_TYPE;

/*0x4000_6358 PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS*/
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_START_sts_Pos                                        0U
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_START_sts_Msk                                        (0x1UL << PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_START_sts_Pos)

#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_END_sts_Pos                                          1U
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_END_sts_Msk                                          (0x1UL << PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_EVNT_END_sts_Pos)

#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_1_Pos                                                   2U
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_1_Msk                                                   (0x3FFFUL << PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_TASK_START_sts_Pos                                        16U
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_TASK_START_sts_Msk                                        (0x1UL << PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_r_SPI0_TASK_START_sts_Pos)

#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_Pos                                                     17U
#define PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_Msk                                                     (0x7FFFUL << PLATFORM_REG_SPI0DUAL_TASK_EVNT_STS_reserved_Pos)

/* 0x035c   0x4000_635c
    0       R/W1C   r_SPI1_EVNT_START_sts                               1'b0
    1       R/W1C   r_SPI1_EVNT_END_sts                                 1'b0
    15:2    R       reserved_1                                          14'h0000
    16      R/W1C   r_SPI1_TASK_START_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_SPI1MST_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_SPI1_EVNT_START_sts: 1;
        uint32_t r_SPI1_EVNT_END_sts: 1;
        uint32_t reserved_1: 14;
        uint32_t r_SPI1_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_SPI1MST_TASK_EVNT_STS_TYPE;

/*0x4000_635c PLATFORM_REG_SPI1MST_TASK_EVNT_STS*/
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_START_sts_Pos                                         0U
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_START_sts_Msk                                         (0x1UL << PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_START_sts_Pos)

#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_END_sts_Pos                                           1U
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_END_sts_Msk                                           (0x1UL << PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_EVNT_END_sts_Pos)

#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_1_Pos                                                    2U
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_1_Msk                                                    (0x3FFFUL << PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_TASK_START_sts_Pos                                         16U
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_TASK_START_sts_Msk                                         (0x1UL << PLATFORM_REG_SPI1MST_TASK_EVNT_STS_r_SPI1_TASK_START_sts_Pos)

#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_Pos                                                      17U
#define PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_Msk                                                      (0x7FFFUL << PLATFORM_REG_SPI1MST_TASK_EVNT_STS_reserved_Pos)

/* 0x0364   0x4000_6364
    0       R/W1C   r_METER_EVNT_DATARDY_sts                            1'b0
    1       R/W1C   r_METER_EVNT_ABS_COMP0_sts                          1'b0
    2       R/W1C   r_METER_EVNT_ABS_COMP1_sts                          1'b0
    3       R/W1C   r_METER_EVNT_ABS_COMP2_sts                          1'b0
    4       R/W1C   r_METER_EVNT_ABS_COMP3_sts                          1'b0
    5       R/W1C   r_METER_EVNT_REL_COMP0_sts                          1'b0
    6       R/W1C   r_METER_EVNT_REL_COMP1_sts                          1'b0
    7       R/W1C   r_METER_EVNT_REL_COMP2_sts                          1'b0
    8       R/W1C   r_METER_EVNT_REL_COMP3_sts                          1'b0
    9       R/W1C   r_METER_EVNT_FW_REL_COMP_sts                        1'b0
    15:10   R       reserved_1                                          6'h0
    16      R/W1C   r_METER_TASK_ONE_SHOT_sts                           1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_TMETER_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_METER_EVNT_DATARDY_sts: 1;
        uint32_t r_METER_EVNT_ABS_COMP0_sts: 1;
        uint32_t r_METER_EVNT_ABS_COMP1_sts: 1;
        uint32_t r_METER_EVNT_ABS_COMP2_sts: 1;
        uint32_t r_METER_EVNT_ABS_COMP3_sts: 1;
        uint32_t r_METER_EVNT_REL_COMP0_sts: 1;
        uint32_t r_METER_EVNT_REL_COMP1_sts: 1;
        uint32_t r_METER_EVNT_REL_COMP2_sts: 1;
        uint32_t r_METER_EVNT_REL_COMP3_sts: 1;
        uint32_t r_METER_EVNT_FW_REL_COMP_sts: 1;
        uint32_t reserved_1: 6;
        uint32_t r_METER_TASK_ONE_SHOT_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_TMETER_TASK_EVNT_STS_TYPE;

/*0x4000_6364 PLATFORM_REG_TMETER_TASK_EVNT_STS*/
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_DATARDY_sts_Pos                                       0U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_DATARDY_sts_Msk                                       (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_DATARDY_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP0_sts_Pos                                     1U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP0_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP0_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP1_sts_Pos                                     2U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP1_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP1_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP2_sts_Pos                                     3U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP2_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP2_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP3_sts_Pos                                     4U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP3_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_ABS_COMP3_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP0_sts_Pos                                     5U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP0_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP0_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP1_sts_Pos                                     6U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP1_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP1_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP2_sts_Pos                                     7U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP2_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP2_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP3_sts_Pos                                     8U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP3_sts_Msk                                     (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_REL_COMP3_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_FW_REL_COMP_sts_Pos                                   9U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_FW_REL_COMP_sts_Msk                                   (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_EVNT_FW_REL_COMP_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_1_Pos                                                     10U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_1_Msk                                                     (0x3FUL << PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_TASK_ONE_SHOT_sts_Pos                                      16U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_TASK_ONE_SHOT_sts_Msk                                      (0x1UL << PLATFORM_REG_TMETER_TASK_EVNT_STS_r_METER_TASK_ONE_SHOT_sts_Pos)

#define PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_Pos                                                       17U
#define PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_Msk                                                       (0x7FFFUL << PLATFORM_REG_TMETER_TASK_EVNT_STS_reserved_Pos)

/* 0x0368   0x4000_6368
    0       R/W1C   r_DMA_EVNT_INT_TFR3_sts                             1'b0
    1       R/W1C   r_DMA_EVNT_INT_TFR4_sts                             1'b0
    2       R/W1C   r_DMA_EVNT_INT_BLK3_sts                             1'b0
    3       R/W1C   r_DMA_EVNT_INT_BLK4_sts                             1'b0
    15:4    R       reserved_1                                          12'd0
    16      R/W1C   r_DMA_TASK_CHN_EN3_sts                              1'b0
    17      R/W1C   r_DMA_TASK_CHN_EN4_sts                              1'b0
    31:18   R       reserved                                            14'd0
 */
typedef union _PLATFORM_REG_DMA_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_DMA_EVNT_INT_TFR3_sts: 1;
        uint32_t r_DMA_EVNT_INT_TFR4_sts: 1;
        uint32_t r_DMA_EVNT_INT_BLK3_sts: 1;
        uint32_t r_DMA_EVNT_INT_BLK4_sts: 1;
        uint32_t reserved_1: 12;
        uint32_t r_DMA_TASK_CHN_EN3_sts: 1;
        uint32_t r_DMA_TASK_CHN_EN4_sts: 1;
        uint32_t reserved: 14;
    };
} PLATFORM_REG_DMA_TASK_EVNT_STS_TYPE;

/*0x4000_6368 PLATFORM_REG_DMA_TASK_EVNT_STS*/
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR3_sts_Pos                                           0U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR3_sts_Msk                                           (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR3_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR4_sts_Pos                                           1U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR4_sts_Msk                                           (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_TFR4_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK3_sts_Pos                                           2U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK3_sts_Msk                                           (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK3_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK4_sts_Pos                                           3U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK4_sts_Msk                                           (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_EVNT_INT_BLK4_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_1_Pos                                                        4U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_1_Msk                                                        (0xFFFUL << PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN3_sts_Pos                                            16U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN3_sts_Msk                                            (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN3_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN4_sts_Pos                                            17U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN4_sts_Msk                                            (0x1UL << PLATFORM_REG_DMA_TASK_EVNT_STS_r_DMA_TASK_CHN_EN4_sts_Pos)

#define PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_Pos                                                          18U
#define PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_Msk                                                          (0x3FFFUL << PLATFORM_REG_DMA_TASK_EVNT_STS_reserved_Pos)

/* 0x036C   0x4000_636c
    0       R/W1C   r_SDMK_EVNT_DONE_sts                                1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_SDMK_TASK_START_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_SDMK_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_SDMK_EVNT_DONE_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_SDMK_TASK_START_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_SDMK_TASK_EVNT_STS_TYPE;

/*0x4000_636c PLATFORM_REG_SDMK_TASK_EVNT_STS*/
#define PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_EVNT_DONE_sts_Pos                                             0U
#define PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_EVNT_DONE_sts_Msk                                             (0x1UL << PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_EVNT_DONE_sts_Pos)

#define PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_1_Pos                                                       1U
#define PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_1_Msk                                                       (0x7FFFUL << PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_TASK_START_sts_Pos                                            16U
#define PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_TASK_START_sts_Msk                                            (0x1UL << PLATFORM_REG_SDMK_TASK_EVNT_STS_r_SDMK_TASK_START_sts_Pos)

#define PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_Pos                                                         17U
#define PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_Msk                                                         (0x7FFFUL << PLATFORM_REG_SDMK_TASK_EVNT_STS_reserved_Pos)

/* 0x0370   0x4000_6370
    0       R/W1C   r_OSC10M_EVNT_CAL_DONE_sts                          1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_OSC10M_TASK_CAL_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_OSC10M_EVNT_CAL_DONE_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_OSC10M_TASK_CAL_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_TYPE;

/*0x4000_6370 PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS*/
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_EVNT_CAL_DONE_sts_Pos                                 0U
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_EVNT_CAL_DONE_sts_Msk                                 (0x1UL << PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_EVNT_CAL_DONE_sts_Pos)

#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_1_Pos                                                 1U
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_1_Msk                                                 (0x7FFFUL << PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_TASK_CAL_sts_Pos                                      16U
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_TASK_CAL_sts_Msk                                      (0x1UL << PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_r_OSC10M_TASK_CAL_sts_Pos)

#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_Pos                                                   17U
#define PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_Msk                                                   (0x7FFFUL << PLATFORM_REG_OSC10M_CAL_TASK_EVNT_STS_reserved_Pos)

/* 0x0374   0x4000_6374
    0       R/W1C   r_OSC80M_EVNT_CAL_DONE_sts                          1'b0
    15:1    R       reserved_1                                          15'h0000
    16      R/W1C   r_OSC80M_TASK_CAL_sts                               1'b0
    31:17   R       reserved                                            15'h0000
 */
typedef union _PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_OSC80M_EVNT_CAL_DONE_sts: 1;
        uint32_t reserved_1: 15;
        uint32_t r_OSC80M_TASK_CAL_sts: 1;
        uint32_t reserved: 15;
    };
} PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_TYPE;

/*0x4000_6374 PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS*/
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_EVNT_CAL_DONE_sts_Pos                                 0U
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_EVNT_CAL_DONE_sts_Msk                                 (0x1UL << PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_EVNT_CAL_DONE_sts_Pos)

#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_1_Pos                                                 1U
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_1_Msk                                                 (0x7FFFUL << PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_1_Pos)

#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_TASK_CAL_sts_Pos                                      16U
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_TASK_CAL_sts_Msk                                      (0x1UL << PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_r_OSC80M_TASK_CAL_sts_Pos)

#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_Pos                                                   17U
#define PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_Msk                                                   (0x7FFFUL << PLATFORM_REG_OSC80M_CAL_TASK_EVNT_STS_reserved_Pos)


#define PLATFORM_REG_BASE 0x40006000

#define PLATFORM_REG_READ(Offset)\
    ((uint32_t)*((volatile uint32_t*)(PLATFORM_REG_BASE+(Offset))))

#define PLATFORM_REG_WRITE(Offset, Value)\
    ((*((volatile uint32_t*)(PLATFORM_REG_BASE + (Offset)))) = (Value))

#define PLATFORM_REG_UPDATE(Offset, Mask, Value) \
    do {\
        uint32_t temp;\
        temp = PLATFORM_REG_READ(Offset) & ~(Mask);\
        PLATFORM_REG_WRITE(Offset, (temp | ((Value) & (Mask))));\
    } while(0)

#define PLATFORM_REG_READ_BITFIELD(Offset, Bitfield)                   \
    (((Offset##_TYPE)PLATFORM_REG_READ(Offset)).Bitfield)

#define PLATFORM_REG_WRITE_BITFIELD(Offset, Bitfield, Value)           \
    do {                                                        \
        Offset##_TYPE temp = {.d32 = PLATFORM_REG_READ(Offset)};       \
        temp.Bitfield = Value;                                         \
        PLATFORM_REG_WRITE(Offset, temp.d32);                          \
    } while(0)

#endif //#define PLATFORM_REG_H
