/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AON_REG_H
#define _AON_REG_H
#include <stdint.h>

/* Auto gen based on RL6920_B_Cut_AON_Autogen_table_2023_0612_V1.xlsx */
#define AON_FAST_BOOT                   0x400
#define AON_FAST_REBOOT_SW_INFO0        0x404
#define AON_REG4X_FW_GENERAL            0x408
#define AON_DEBUG_PASSWORD              0x40C   // 0x40C ~ 0x41B store the debug password
#define AON_REG8X_FW_GENERAL            0x410
#define AON_REG10X_FW_GENERAL           0x414
#define AON_REG12X_FW_GENERAL           0x418
#define AON_REG14X_FW_GENERAL           0x41C
#define AON_REG16X_FW_GENERAL           0x420
#define AON_REG18X_FW_GENERAL           0x424
#define AON_REG20X_FW_GENERAL           0x428
#define AON_REG22X_FW_GENERAL           0x42C
#define AON_REG0X_FUNC_DIS              0x460
#define AON_REG0X_SAF                   0x464
#define AON_REG1X_SAF                   0x468
#define AON_REG0X_SC                    0x46C
#define AON_REG0X_KM4_DBG_CTRL          0x470
#define AON_RTC_PF_COMP_CONTROLLER_REG  0x4B0
#define AON_RTC_PF_COMP0_REG            0x4B4
#define AON_RTC_PF_COMP1_REG            0x4B8
#define AON_RTC_PF_COMP2_REG            0x4BC
#define AON_RTC_PF_COMP3_REG            0x4C0
#define AON_RTC_PF_COMP_MANUAL_INT_REG  0x4C4
#define AON_RTC_PF_CNT_REG              0x4C8
#define AON_RTC_PF_COMP_INT_WK_CLR_REG  0x4CC
#define AON_RTC_PF_COMP_INT_WK_SR_REG   0x4D0
#define AON_RTC_PF_RTL_VERSION_REG      0x4D4
#define AON_BT_MAC_VSEL                 0x580
#define AON_BT_MAC_SNPS_HV_LV           0x584
#define AON_BT_MAC_1024x16_PWR          0x588
#define AON_BT_MAC_512x16_PWR           0x58C
#define AON_BT_MAC_128x32_0_PWR         0x590
#define AON_BT_MAC_128x32_1_PWR         0x594
#define AON_BT_MAC_640x32_HV_LV         0x598
#define AON_BT_MAC_640x32_PWR           0x59C
#define AON_BT_MAC_96x32_HV_LV          0x5A0
#define AON_BT_MAC_96x32_PWR            0x5A4
#define AON_BT_MAC_64x32_HV_LV          0x5A8
#define AON_BT_MAC_64x32_PWR            0x5AC
#define AON_ZB_MAC_VSEL                 0x5B0
#define AON_ZB_MAC_HV_LV                0x5B4
#define AON_ZB_MAC_16x32_PWR            0x5B8
#define AON_ZB_MAC_40x32_PWR            0x5BC
#define AON_ZB_MAC_32x32_PWR            0x5C0
#define AON_BT_PHY_VSEL                 0x5C4
#define AON_BT_PHY_HV_LV                0x5C8
#define AON_BT_PHY_128x12x4_PWR         0x5CC
#define AON_BT_PHY_LR_RAM_PWR           0x5D0
#define AON_KM4_VSEL                    0x5D4
#define AON_KM4_ITCM0_HV_LV             0x5D8
#define AON_KM4_ITCM0_LS                0x5DC
#define AON_KM4_TCM_HV_LV               0x5E0
#define AON_KM4_ITCM1_PWR_0             0x5E4
#define AON_KM4_ITCM1_PWR_1             0x5E8
#define AON_KM4_DTCM0_PWR               0x5EC
#define AON_KM4_DTCM1_PWR               0x5F0
#define AON_KM4_IC_DATA_HV_LV           0x5F4
#define AON_KM4_IC_DATA_PWR             0x5F8
#define AON_KM4_IC_TAG_HV_LV            0x5FC
#define AON_KM4_IC_TAG_PWR              0x600
#define AON_KM4_DC_DATA_HV_LV           0x604
#define AON_KM4_DC_DATA_PWR             0x608
#define AON_KM4_DC_TAG_HV_LV            0x60C
#define AON_KM4_DC_TAG_PWR              0x610
#define AON_BUFFER_RAM_VSEL             0x614
#define AON_BUFFER_RAM_HV_LV            0x618
#define AON_BUFFER_RAM_PWR              0x61C
#define AON_DATA_RAM_VSEL               0x620
#define AON_DATA_RAM_HV_LV              0x624
#define AON_DATA_RAM_PWR                0x628
#define AON_USB_VSEL                    0x62C
#define AON_USB_HV_LV                   0x630
#define AON_USB_PWR                     0x634
#define AON_SDIO_RAM_PWR                0x638
#define AON_DISPLAY_128x32_PWR          0x63C
#define AON_DISPLAY_672x24_PWR          0x640
#define AON_GMAC_PWR                    0x644
#define AON_PKE_ROM_HV                  0x648
#define AON_PKE_ROM_PWR                 0x64C
#define AON_PKE_MMEM_PWR                0x650
#define AON_PKE_TMEM_PWR                0x654
#define AON_AUDIO_VSEL                  0x658
#define AON_AUDIO_HV_LV                 0x65C
#define AON_AUDIO_AD_PWR                0x660
#define AON_AUDIO_DA_PWR                0x664
#define AON_CAN_VSEL                    0x668
#define AON_CAN_HV_LV                   0x66C
#define AON_CAN_PWR                     0x670
#define AON_REG0X_SYS                   0x800
#define AON_REG1X_SYS                   0x804
#define AON_REG2X_SYS                   0x808
#define AON_REG3X_SYS                   0x80C
#define AON_REG4X_SYS                   0x810
#define AON_REG5X_SYS                   0x814
#define AON_REG6X_SYS                   0x818
#define AON_REG7X_SYS                   0x81C
#define AON_REG8X_SYS                   0x820
#define AON_REG9X_SYS                   0x824
#define AON_REG10X_SYS                  0x828
#define AON_REG0X_EFUSE                 0x82C
#define AON_REG0X_XPDCK                 0x830
#define AON_REG0X_PWM_POS               0x834
#define AON_REG0X_PFM_POS               0x838
#define AON_REG0X_300K                  0x83C
#define AON_REG1X_300K                  0x840
#define AON_AON_READ_RG0X               0x844
#define AON_AON_READ_RG1X               0x848
#define AON_AON_READ_RG2X               0x84C
#define AON_AON_READ_RG3X               0x850
#define AON_AON_READ_RG4X               0x854
#define AON_AON_READ_RG5X               0x858
#define AON_AON_READ_RG6X               0x85C
#define AON_AON_READ_RG7X               0x860
#define AON_AON_READ_RG8X               0x864
#define AON_AON_READ_RG9X               0x868
#define AON_AON_READ_RG10X              0x86C
#define AON_AON_READ_RG11X              0x870
#define AON_AON_READ_RG12X              0x874
#define AON_AON_READ_RG13X              0x878
#define AON_AON_READ_RG14X              0x87C
#define AON_AON_READ_RG15X              0x880
#define AON_AON_READ_RG16X              0x884
#define AON_LOP_RG0X                    0xAB0
#define AON_LOP_RG1X                    0xAB4
#define AON_LOP_RG2X                    0xAB8
#define AON_LOP_RG3X                    0xABC
#define AON_LOP_RG4X                    0xAC0
#define AON_LOP_RG5X                    0xAC4
#define AON_LOP_RG6X                    0xAC8
#define AON_LOP_RG7X                    0xACC
#define AON_LOP_RG8X                    0xAD0
#define AON_LOP_RG9X                    0xAD4
#define AON_LOP_RG10X                   0xAD8
#define AON_REG0X_MBIAS                 0xC00
#define AON_REG2X_MBIAS                 0xC04
#define AON_C_KOUT0X_MBIAS              0xC08
#define AON_REG0X_LDO                   0xC10
#define AON_REG2X_LDO                   0xC14
#define AON_REG0X_LCD                   0xC18
#define AON_REG0X_BUCK                  0xC20
#define AON_REG2X_BUCK                  0xC24
#define AON_REG4X_BUCK                  0xC28
#define AON_REG6X_BUCK                  0xC2C
#define AON_REG8X_BUCK                  0xC30
#define AON_C_KOUT0X_BUCK               0xC34
#define AON_REG0X_32KXTAL               0xC80
#define AON_REG2X_32KXTAL               0xC84
#define AON_REG0X_32KOSC                0xC88
#define AON_REG_POW                     0xC8C
#define AON_REG0X_40MOSC                0xC90
#define AON_REG0X_RCAL                  0xC94
#define AON_BT_ANAPAR_XTAL_mode         0xCA0
#define AON_BT_ANAPAR_XTAL0             0xCA4
#define AON_BT_ANAPAR_XTAL2             0xCA8
#define AON_BT_ANAPAR_XTAL4             0xCAC
#define AON_BT_ANAPAR_XTAL6             0xCB0
#define AON_BT_ANAPAR_XTAL8             0xCB4
#define AON_BT_ANAPAR_XTAL10            0xCB8
#define AON_BT_ANAPAR_XTAL12            0xCBC
#define AON_BT_ANAPAR_XTAL14            0xCC0
#define AON_BT_ANAPAR_XTAL16            0xCC4
#define AON_REG0X_XTAL                  0xCC8
#define AON_REG1X_XTAL                  0xCCC
#define AON_REG0X_BT_ANAPAR_LDO         0xCD0
#define AON_REG0X_RF_LDO318             0xCD4
#define AON_REG0X_LDO_PLL1              0xD00
#define AON_REG_USB_POWER_CTL           0xD40
#define AON_REG_USB_CLK_CTL             0xD44
#define AON_REG_XTAL0                   0xD60
#define AON_REG_XTAL1                   0xD64
#define AON_REG0X_PLL1                  0xD80
#define AON_REG2X_PLL1                  0xD84
#define AON_REG0X_PLL2                  0xD88
#define AON_REG2X_PLL2                  0xD8C
#define AON_REG4X_PLL2                  0xD90
#define AON_RO_PLL                      0xD94
#define AON_NS_RTC_CR0                  0x1800
#define AON_NS_RTC_INT_clear            0x1804
#define AON_NS_RTC_INT_SR               0x1808
#define AON_NS_RTC_PRESCALER0           0x180C
#define AON_NS_RTC_COMP_0               0x1810
#define AON_NS_RTC_COMP_1               0x1814
#define AON_NS_RTC_COMP_2               0x1818
#define AON_NS_RTC_COMP_3               0x181C
#define AON_NS_RTC_COMP0_GT             0x1820
#define AON_NS_RTC_COMP1_GT             0x1824
#define AON_NS_RTC_COMP2_GT             0x1828
#define AON_NS_RTC_COMP3_GT             0x182C
#define AON_NS_RTC_CNT0                 0x1830
#define AON_NS_RTC_PRESCALE_CNT0        0x1834
#define AON_NS_RTC_PRESCALE_CMP0        0x1838
#define AON_NS_RTC_BACKUP_REG           0x183C
#define AON_NS_RTC_RTL_VERSION0         0x1840
#define AON_NS_LPC0_CR0                 0x1850
#define AON_NS_LPC0_SR                  0x1854
#define AON_NS_LPC0_MBIAS               0x1858
#define AON_NS_P0_0_P0_1_PAD_CFG        0x1900
#define AON_NS_P0_2_P0_3_PAD_CFG        0x1904
#define AON_NS_P0_4_P0_5_PAD_CFG        0x1908
#define AON_NS_P0_6_P0_7_PAD_CFG        0x190C
#define AON_NS_P1_0_P1_1_PAD_CFG        0x1910
#define AON_NS_P1_2_P1_3_PAD_CFG        0x1914
#define AON_NS_P1_4_P1_5_PAD_CFG        0x1918
#define AON_NS_P1_6_P1_7_PAD_CFG        0x191C
#define AON_NS_P2_0_P2_1_PAD_CFG        0x1920
#define AON_NS_P2_2_P2_3_PAD_CFG        0x1924
#define AON_NS_P2_4_P2_5_PAD_CFG        0x1928
#define AON_NS_P2_6_P2_7_PAD_CFG        0x192C
#define AON_NS_P3_0_P3_1_PAD_CFG        0x1930
#define AON_NS_P3_2_P3_3_PAD_CFG        0x1934
#define AON_NS_P3_4_P3_5_PAD_CFG        0x1938
#define AON_NS_P3_6_P3_7_PAD_CFG        0x193C
#define AON_NS_P4_0_P4_1_PAD_CFG        0x1940
#define AON_NS_P4_2_P4_3_PAD_CFG        0x1944
#define AON_NS_P32K_XI_P32K_XO_PAD_CFG  0x1948
#define AON_NS_P_MICBIAS_PAD_CFG        0x194C
#define AON_NS_COMMON_PAD_CFG           0x1950
#define AON_NS_P_SPI_PAD_CFG            0x1954
#define AON_NS_DAC_P_DAC_N_PAD_CFG      0x1958
#define AON_NS_P4_4_P4_5_PAD_CFG        0x195C
#define AON_NS_P4_6_P4_7_PAD_CFG        0x1960
#define AON_NS_P5_0_P5_1_PAD_CFG        0x1964
#define AON_NS_P5_2_P5_3_PAD_CFG        0x1968
#define AON_NS_P5_4_P5_5_PAD_CFG        0x196C
#define AON_NS_P5_6_P5_7_PAD_CFG        0x1970
#define AON_NS_P6_0_P6_1_PAD_CFG        0x1974
#define AON_NS_P6_2_P6_3_PAD_CFG        0x1978
#define AON_NS_P6_4_P6_5_PAD_CFG        0x197C
#define AON_NS_P6_6_P6_7_PAD_CFG        0x1980
#define AON_NS_P7_0_P7_1_PAD_CFG        0x1984
#define AON_NS_P7_2_P7_3_PAD_CFG        0x1988
#define AON_NS_P7_4_P7_5_PAD_CFG        0x198C
#define AON_NS_P7_6_P7_7_PAD_CFG        0x1990
#define AON_NS_SPIC0_PAD_CFG0           0x1994
#define AON_NS_SPIC0_PAD_CFG1           0x1998
#define AON_NS_SPIC0_PAD_CFG2           0x199C
#define AON_NS_P8_0_P8_1_PAD_CFG        0x19A0
#define AON_NS_P8_2_P8_3_PAD_CFG        0x19A4
#define AON_NS_P8_4_P8_5_PAD_CFG        0x19A8
#define AON_NS_P8_6_P8_7_PAD_CFG        0x19AC
#define AON_NS_P9_0_P9_1_PAD_CFG        0x19B0
#define AON_NS_P9_2_P9_3_PAD_CFG        0x19B4
#define AON_NS_P9_4_P9_5_PAD_CFG        0x19B8
#define AON_NS_P9_6_P9_7_PAD_CFG        0x19BC
#define AON_NS_P10_0_P10_1_PAD_CFG      0x19C0
#define AON_NS_P10_2_P10_3_PAD_CFG      0x19C4
#define AON_NS_PAD_E3_CFG               0x19C8
#define AON_NS_PAD_Status_0             0x1AA0
#define AON_NS_PAD_Status_1             0x1AA4
#define AON_NS_PAD_Status_2             0x1AA8
#define AON_NS_REG0X_DEBIO              0x1AAC
#define AON_NS_PAD_Status_3             0x1AB0
#define AON_NS_REG0X_APP                0x1AE0
#define AON_NS_REG1X_APP                0x1AE4
#define AON_NS_REG2X_APP                0x1AE8
#define AON_NS_REG3X_APP                0x1AEC
#define AON_NS_REG4X_APP                0x1AF0
#define AON_NS_REG5X_APP                0x1AF4
#define AON_NS_REG6X_APP                0x1AF8
#define AON_NS_REG7X_APP                0x1AFC
#define AON_NS_REG8X_APP                0x1B00
#define AON_NS_REG9X_APP                0x1B04
#define AON_NS_REG10X_APP               0x1B08
#define AON_NS_REG11X_APP               0x1B0C
#define AON_NS_REG12X_APP               0x1B10
#define AON_NS_REG13X_APP               0x1B14
#define AON_NS_REG14X_APP               0x1B18
#define AON_NS_REG15X_APP               0x1B1C
#define AON_NS_AON_WDG_WP0              0x1B60
#define AON_NS_AON_WDG_CONFIG           0x1B64
#define AON_NS_AON_WDG_CNT_RESET0       0x1B68
#define AON_NS_AON_WDG_SEC_CTL          0x1B6C
#define AON_NS_REG0X_LDO                0x1B90
#define AON_NS_REG0X_AUX_V09            0x1B94
#define AON_NS_REG0X_SD                 0x1B98
#define AON_NS_REG_CONFIG               0x1BD0
#define AON_NS_REG_SR_X                 0x1BD4
#define AON_NS_INT_CLR                  0x1BD8
#define AON_NS_REG30_CORE_KM4_PC        0x1C00
#define AON_NS_REG34_CORE_KM4_LR        0x1C04
#define AON_NS_REG38_CORE_KM4_PC_EX     0x1C08
#define AON_NS_REG3C_CORE_KM4_XPSR_R    0x1C0C
#define AON_NS_REG40_CORE_KM4_MSP_S     0x1C10
#define AON_NS_REG44_CORE_KM4_PSP_S     0x1C14
#define AON_NS_REG48_CORE_KM4_MSP_NS    0x1C18
#define AON_NS_REG4C_CORE_KM4_PSP_NS    0x1C1C
#define AON_NS_REG50_AON_KM4_PC         0x1C20
#define AON_NS_REG54_AON_KM4_LR         0x1C24
#define AON_NS_REG58_AON_KM4_PC_EX      0x1C28
#define AON_NS_REG5C_AON_KM4_XPSR_R     0x1C2C
#define AON_NS_REG60_AON_KM4_MSP_S      0x1C30
#define AON_NS_REG64_AON_KM4_PSP_S      0x1C34
#define AON_NS_REG68_AON_KM4_MSP_NS     0x1C38
#define AON_NS_REG6C_AON_KM4_PSP_NS     0x1C3C
#define AON_NS_REG_AON_WDT_MODE         0x1C40
#define AON_NS_REG_KM4_WDT_MODE         0x1C44
#define AON_NS_REG0X_FW_GENERAL_NS      0x1D00
#define AON_NS_REG2X_FW_GENERAL_NS      0x1D04
#define AON_NS_REG4X_FW_GENERAL_NS      0x1D08
#define AON_NS_REG6X_FW_GENERAL_NS      0x1D0C
#define AON_NS_REG8X_FW_GENERAL_NS      0x1D10
#define AON_NS_REG10X_FW_GENERAL_NS     0x1D14
#define AON_NS_P3_P1_PAD_E_LCD_CFG      0x1D80
#define AON_NS_P7_P4_PAD_E_LCD_CFG      0x1D84
#define AON_NS_P11_P8_PAD_E_LCD_CFG     0x1D88
#define AON_NS_P3_P1_PAD_SHDN_LCD_CFG   0x1D8C
#define AON_NS_P7_P4_PAD_SHDN_LCD_CFG   0x1D90
#define AON_NS_P11_P8_PAD_SHDN_LCD_CFG  0x1D94
#define AON_NS_REG0X_SDADC_LDO          0x1DC0
/* 0x400    0x4000_0400
    15:0    R/W FW_GENERAL_REG0X                        16'h0
    31:16   R/W FW_GENERAL_REG1X                        16'h0
 */
typedef volatile union _AON_FAST_BOOT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG0X: 16;
        uint32_t FW_GENERAL_REG1X: 16;
    };
} AON_FAST_BOOT_TYPE;

/* 0x404    0x4000_0404
    15:0    R/W FW_GENERAL_REG2X                        16'h0
    31:16   R/W FW_GENERAL_REG3X                        16'h0
 */
typedef volatile union _AON_FAST_REBOOT_SW_INFO0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG2X: 16;
        uint32_t FW_GENERAL_REG3X: 16;
    };
} AON_FAST_REBOOT_SW_INFO0_TYPE;

/* 0x408    0x4000_0408
    15:0    R/W FW_GENERAL_REG4X                        16'h0
    31:16   R/W FW_GENERAL_REG5X                        16'h0
 */
typedef volatile union _AON_REG4X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ota_valid: 1;                  /* bit[0]: ota valid */
        uint32_t is_rom_code_patch: 1;          /* bit[1]: is rom code patch ? */
        uint32_t is_fw_trig_wdg_to: 1;          /* bit[2]: does fw trigger watchdog timeout ? */
        uint32_t is_send_patch_end_evt: 1;      /* bit[3]: does we send patch end event ? */
        uint32_t rsvd: 2;                       /* bit[5:4]: reserved */
        uint32_t is_airplane_mode : 1;          /* bit[6]: is airplane mode ? */
        uint32_t REBOOT_SW_INFO1: 6;            /* bit[12:7] for AON_FAST_REBOOT_SW_INFO1 */
        uint32_t is_password_mpl_cmd: 1;
        uint32_t reg_aon_hwspi_en: 1;
        uint32_t reg_aon_debug_port: 1;
        uint32_t FW_GENERAL_REG5X: 16;
    };
} AON_REG4X_FW_GENERAL_TYPE;

/* 0x40C    0x4000_040c
    15:0    R/W freg2                        16'h0
    31:16   R/W freg3                        16'h0
 */
typedef volatile union _AON_DEBUG_PASSWORD_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t freg2: 16;
        uint32_t freg3: 16;
    };
} AON_DEBUG_PASSWORD_TYPE;

/* 0x410    0x4000_0410
    15:0    R/W FW_GENERAL_REG8X                        16'h0
    31:16   R/W FW_GENERAL_REG9X                        16'h0
 */
typedef volatile union _AON_REG8X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG8X: 16;
        uint32_t FW_GENERAL_REG9X: 16;
    };
} AON_REG8X_FW_GENERAL_TYPE;

/* 0x414    0x4000_0414
    15:0    R/W FW_GENERAL_REG10X                       16'h0
    31:16   R/W FW_GENERAL_REG11X                       16'h0
 */
typedef volatile union _AON_REG10X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG10X: 16;
        uint32_t FW_GENERAL_REG11X: 16;
    };
} AON_REG10X_FW_GENERAL_TYPE;

/* 0x418    0x4000_0418
    15:0    R/W FW_GENERAL_REG12X                       16'h0
    31:16   R/W FW_GENERAL_REG13X                       16'h0
 */
typedef volatile union _AON_REG12X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG12X: 16;
        uint32_t FW_GENERAL_REG13X: 16;
    };
} AON_REG12X_FW_GENERAL_TYPE;

/* 0x41C    0x4000_041c
    0       w1o reg_dsp_flash_prot                  1'b0
    1       w1o reg_aon_hwspi_en_rp                 1'b0
    2       w1o reg_aon_debug_port_wp               1'b0
    3       w1o reg_aon_dbg_boot_dis                1'b0
    11:04   w1o XTAL32K_Reserved16[13:6]            8'h0
    31:12   w1o RSVD                                20'h0

 */
typedef volatile union _AON_REG14X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_dsp_flash_prot: 1;
        uint32_t reg_aon_hwspi_en_rp: 1;
        uint32_t reg_aon_debug_port_wp: 1;
        uint32_t reg_aon_dbg_boot_dis: 1;
        uint32_t XTAL32K_Reserved16_13_6: 8;
        uint32_t RSVD: 20;
    };
} AON_REG14X_FW_GENERAL_TYPE;

/* 0x420    0x4000_0420
    0       w1o is_efuse_invalid                    1'b0
    1       w1o is_enable_efuse_bank0_read_protect  1'b0
    2       w1o is_enable_efuse_bank0_write_protect 1'b0
    3       w1o is_enable_efuse_bank0_read_protect  1'b0
    4       w1o is_enable_efuse_bank0_write_protect 1'b0
    5       w1o is_hw_aes_dma_mode                  1'b0
    6       w1o is_debug_password_invalid           1'b0
    7       w1o is_disable_set_reg_by_otp           1'b0
    8       w1o is_enable_image_auth_when_resume    1'b0
    9       w1o is_enable_pmc_platform              1'b0
    10      w1o is_enable_bt_platform               1'b0
    15:11   w1o reg_aon_w1o_gpr_2                   5'h0
    31:16   w1o reg_aon_w1o_gpr_3                   16'h0
 */
typedef volatile union _AON_REG16X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t is_efuse_invalid: 1;
        uint32_t is_enable_efuse_bank0_read_protect: 1;
        uint32_t is_enable_efuse_bank0_write_protect: 1;
        uint32_t is_enable_efuse_bank1_read_protect: 1;
        uint32_t is_enable_efuse_bank1_write_protect: 1;
        uint32_t is_hw_aes_dma_mode: 1;
        uint32_t is_debug_password_invalid: 1;
        uint32_t is_disable_set_reg_by_otp: 1;
        uint32_t is_enable_image_auth_when_resume: 1;
        uint32_t is_enable_pmc_platform: 1;
        uint32_t is_enable_bt_platform: 1;
        uint32_t reg_aon_w1o_gpr_2: 5;
        uint32_t reg_aon_w1o_gpr_3: 16;
    };
} AON_REG16X_FW_GENERAL_TYPE;

/* 0x424    0x4000_0424
    0       w1o is_disable_hci_read_chip_info       1'b0
    1       w1o is_disable_hci_mac_rf_access        1'b0
    2       w1o is_disable_hci_wifi_coexist_func    1'b0
    3       w1o is_disable_hci_set_uart_baudrate    1'b0
    4       w1o is_disable_hci_rf_dbg_func          1'b0
    5       w1o is_disable_hci_bt_extension         1'b0
    6       w1o is_disable_hci_bt_dbg_func          1'b0
    7       w1o is_disable_hci_bt_test              1'b0
    8       w1o is_disable_hci_rf_test              1'b0
    9       w1o is_disable_mpl_ram_patch            1'b0
    10      w1o is_disable_mpl_flash_access         1'b0
    11      w1o is_disable_mpl_system_access        1'b0
    12      w1o is_disable_mpl_otp_access           1'b0
    15:13   w1o reg_aon_w1o_gpr_4                   3'h0
    31:16   w1o reg_aon_w1o_gpr_5                   16'h0
 */
typedef volatile union _AON_REG18X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t is_disable_hci_read_chip_info: 1;
        uint32_t is_disable_hci_mac_rf_access: 1;
        uint32_t is_disable_hci_wifi_coexist_func: 1;
        uint32_t is_disable_hci_set_uart_baudrate: 1;
        uint32_t is_disable_hci_rf_dbg_func: 1;
        uint32_t is_disable_hci_bt_extension: 1;
        uint32_t is_disable_hci_bt_dbg_func: 1;
        uint32_t is_disable_hci_bt_test: 1;
        uint32_t is_disable_hci_rf_test: 1;
        uint32_t is_disable_mpl_ram_patch: 1;
        uint32_t is_disable_mpl_flash_access: 1;
        uint32_t is_disable_mpl_system_access: 1;
        uint32_t is_disable_mpl_otp_access: 1;
        uint32_t reg_aon_w1o_gpr_4: 3;
        uint32_t reg_aon_w1o_gpr_5: 16;
    };
} AON_REG18X_FW_GENERAL_TYPE;

/* 0x428    0x4000_0428
    15:0    R/W FW_GENERAL_REG20X                       16'h0
    31:16   R/W FW_GENERAL_REG21X                       16'h0
 */
typedef volatile union _AON_REG20X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG20X: 16;
        uint32_t FW_GENERAL_REG21X: 16;
    };
} AON_REG20X_FW_GENERAL_TYPE;

/* 0x42C    0x4000_042c
    15:0    R/W FW_GENERAL_REG22X                       16'h0
    31:16   R/W FW_GENERAL_REG23X                       16'h0
 */
typedef volatile union _AON_REG22X_FW_GENERAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_REG22X: 16;
        uint32_t FW_GENERAL_REG23X: 16;
    };
} AON_REG22X_FW_GENERAL_TYPE;

/* 0x460    0x4000_0460
    0       W1O reg_aon_w1o_dumm0                       1'b0
    1       W1O reg_aon_w1o_dumm1                       1'b0
    2       W1O reg_rom_trace_prot                      1'h0
    3       W1O reg_aon_w1o_pn_cfo_comp_dis             1'h0
    4       W1O reg_aon_w1o_detail_rxrpt_dis            1'h0
    5       W1O reg_aon_w1o_detail_rxrpt_cfoe_dis       1'h0
    6       W1O reg_aon_w1o_pa_func_dis                 1'h0
    7       W1O reg_aon_w1o_cis_func_dis                1'h0
    8       W1O reg_aon_w1o_bis_func_dis                1'h0
    31:9    R   RSVD                                    23'b0
 */
typedef volatile union _AON_REG0X_FUNC_DIS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_aon_w1o_dumm0: 1;
        uint32_t reg_aon_w1o_dumm1: 1;
        uint32_t reg_rom_trace_prot: 1;
        uint32_t reg_aon_w1o_pn_cfo_comp_dis: 1;
        uint32_t reg_aon_w1o_detail_rxrpt_dis: 1;
        uint32_t reg_aon_w1o_detail_rxrpt_cfoe_dis: 1;
        uint32_t reg_aon_w1o_pa_func_dis: 1;
        uint32_t reg_aon_w1o_cis_func_dis: 1;
        uint32_t reg_aon_w1o_bis_func_dis: 1;
        uint32_t RSVD: 23;
    };
} AON_REG0X_FUNC_DIS_TYPE;

/* 0x464    0x4000_0464
    0       R/W saf_aon_nonsec_slave                    1'b1                    !saf_nonsec_slave_lock
    1       R/W saf_peri_on_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    2       R/W saf_soc_vendor_reg_nonsec_slave         1'b1                    !saf_nonsec_slave_lock
    3       R/W saf_ir_rc_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    4       R/W saf_qdec_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    5       R/W saf_gmac_ctrl_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
    6       R/W saf_spic0_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    7       R/W saf_spic1_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    8       R/W saf_spic2_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    9       R/W saf_spi0_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    10      R/W saf_spi1_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    11      R/W saf_spi_slave_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
    12      R/W saf_rtzip_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    13      R/W saf_enhanced_timer_nonsec_slave         1'b1                    !saf_nonsec_slave_lock
    14      R/W saf_modemrfcpi_nonsec_slave             1'b1                    !saf_nonsec_slave_lock
    15      R/W saf_usb_otg_cfg_nonsec_slave            1'b1                    !saf_nonsec_slave_lock
    16      R/W saf_i2s0_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    17      R/W saf_i2s1_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    18      R/W saf_spi_codec_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
    19      R/W saf_display_ctrl_nonsec_slave           1'b1                    !saf_nonsec_slave_lock
    20      R/W saf_iso7816_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    21      R/W saf_segcom_ctl_nonsec_slave             1'b1                    !saf_nonsec_slave_lock
    22      R/W saf_bluewiz_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    23      R/W saf_bt_vendor_reg_nonsec_slave          1'b1                    !saf_nonsec_slave_lock
    24      R/W saf_zigbee_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    25      R/W saf_sdio_host0_cfg_nonsec_slave         1'b1                    !saf_nonsec_slave_lock
    26      R/W saf_gpioa_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    27      R/W saf_gpiob_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    28      R/W saf_timer_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    29      R/W saf_sar_adc_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    30      R/W saf_adc_24bit_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
    31      R/W saf_spi_3wire_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
 */
typedef volatile union _AON_REG0X_SAF_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t saf_aon_nonsec_slave: 1;
        uint32_t saf_peri_on_nonsec_slave: 1;
        uint32_t saf_soc_vendor_reg_nonsec_slave: 1;
        uint32_t saf_ir_rc_nonsec_slave: 1;
        uint32_t saf_qdec_nonsec_slave: 1;
        uint32_t saf_gmac_ctrl_nonsec_slave: 1;
        uint32_t saf_spic0_nonsec_slave: 1;
        uint32_t saf_spic1_nonsec_slave: 1;
        uint32_t saf_spic2_nonsec_slave: 1;
        uint32_t saf_spi0_nonsec_slave: 1;
        uint32_t saf_spi1_nonsec_slave: 1;
        uint32_t saf_spi_slave_nonsec_slave: 1;
        uint32_t saf_rtzip_nonsec_slave: 1;
        uint32_t saf_enhanced_timer_nonsec_slave: 1;
        uint32_t saf_modemrfcpi_nonsec_slave: 1;
        uint32_t saf_usb_otg_cfg_nonsec_slave: 1;
        uint32_t saf_i2s0_nonsec_slave: 1;
        uint32_t saf_i2s1_nonsec_slave: 1;
        uint32_t saf_spi_codec_nonsec_slave: 1;
        uint32_t saf_display_ctrl_nonsec_slave: 1;
        uint32_t saf_iso7816_nonsec_slave: 1;
        uint32_t saf_segcom_ctl_nonsec_slave: 1;
        uint32_t saf_bluewiz_nonsec_slave: 1;
        uint32_t saf_bt_vendor_reg_nonsec_slave: 1;
        uint32_t saf_zigbee_nonsec_slave: 1;
        uint32_t saf_sdio_host0_cfg_nonsec_slave: 1;
        uint32_t saf_gpioa_nonsec_slave: 1;
        uint32_t saf_gpiob_nonsec_slave: 1;
        uint32_t saf_timer_nonsec_slave: 1;
        uint32_t saf_sar_adc_nonsec_slave: 1;
        uint32_t saf_adc_24bit_nonsec_slave: 1;
        uint32_t saf_spi_3wire_nonsec_slave: 1;
    };
} AON_REG0X_SAF_TYPE;

/* 0x468    0x4000_0468
    0       R/W saf_uart0_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    1       R/W saf_uart1_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    2       R/W saf_uart2_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    3       R/W saf_uart3_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    4       R/W saf_i2c0_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    5       R/W saf_i2c1_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    6       R/W saf_key_scan_nonsec_slave               1'b1                    !saf_nonsec_slave_lock
    7       R/W saf_public_key_engine_nonsec_slave      1'b1                    !saf_nonsec_slave_lock
    8       R/W saf_flash_sec_nonsec_slave              1'b1                    !saf_nonsec_slave_lock
    9       R/W saf_aes_nonsec_slave                    1'b1                    !saf_nonsec_slave_lock
    10      R/W saf_sha256_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    11      R/W saf_trng_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    12      R/W saf_efuse_controller_nonsec_slave       1'b1                    !saf_nonsec_slave_lock
    13      R/W saf_spi0_hs_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    14      R/W saf_rxi350_dmac_cfg_nonsec_slave        1'b1                    !saf_nonsec_slave_lock
    15      R/W saf_ppe_cfg_nonsec_slave                1'b1                    !saf_nonsec_slave_lock
    16      R/W saf_can_nonsec_slave                    1'b1                    !saf_nonsec_slave_lock
    17      R/W saf_spic_phy_nonsec_slave               1'b1                    !saf_nonsec_slave_lock
    18      R/W saf_i2c2_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    19      R/W saf_i2c3_nonsec_slave                   1'b1                    !saf_nonsec_slave_lock
    20      R/W saf_uart4_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    21      R/W saf_uart5_nonsec_slave                  1'b1                    !saf_nonsec_slave_lock
    22      R   RSVD                                    1'b0
    23      R   RSVD                                    1'b0
    24      R   RSVD                                    1'b0
    25      R   RSVD                                    1'b0
    26      R   RSVD                                    1'b0
    27      R/W saf_dummy0_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    28      R/W saf_dummy1_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    29      R/W saf_dummy2_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    30      R/W saf_dummy3_nonsec_slave                 1'b1                    !saf_nonsec_slave_lock
    31      W1O saf_nonsec_slave_lock                   1'b0
 */
typedef volatile union _AON_REG1X_SAF_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t saf_uart0_nonsec_slave: 1;
        uint32_t saf_uart1_nonsec_slave: 1;
        uint32_t saf_uart2_nonsec_slave: 1;
        uint32_t saf_uart3_nonsec_slave: 1;
        uint32_t saf_i2c0_nonsec_slave: 1;
        uint32_t saf_i2c1_nonsec_slave: 1;
        uint32_t saf_key_scan_nonsec_slave: 1;
        uint32_t saf_public_key_engine_nonsec_slave: 1;
        uint32_t saf_flash_sec_nonsec_slave: 1;
        uint32_t saf_aes_nonsec_slave: 1;
        uint32_t saf_sha256_nonsec_slave: 1;
        uint32_t saf_trng_nonsec_slave: 1;
        uint32_t saf_efuse_controller_nonsec_slave: 1;
        uint32_t saf_spi0_hs_nonsec_slave: 1;
        uint32_t saf_rxi350_dmac_cfg_nonsec_slave: 1;
        uint32_t saf_ppe_cfg_nonsec_slave: 1;
        uint32_t saf_can_nonsec_slave: 1;
        uint32_t saf_spic_phy_nonsec_slave: 1;
        uint32_t saf_i2c2_nonsec_slave: 1;
        uint32_t saf_i2c3_nonsec_slave: 1;
        uint32_t saf_uart4_nonsec_slave: 1;
        uint32_t saf_uart5_nonsec_slave: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
        uint32_t saf_dummy0_nonsec_slave: 1;
        uint32_t saf_dummy1_nonsec_slave: 1;
        uint32_t saf_dummy2_nonsec_slave: 1;
        uint32_t saf_dummy3_nonsec_slave: 1;
        uint32_t saf_nonsec_slave_lock: 1;
    };
} AON_REG1X_SAF_TYPE;

/* 0x46C    0x4000_046c
    0       R/W usbotg_hnonsec                          1'b1                    !sc_hnonsec_lock
    1       R/W sdio_host0_hnonsec                      1'b1                    !sc_hnonsec_lock
    2       R/W display_arprot_1                        1'b1                    !sc_hnonsec_lock
    3       R   RSVD                                    1'b0
    4       R/W gmac_m_arprot_1                         1'b1                    !sc_hnonsec_lock
    5       R/W gmac_m_awprot_1                         1'b1                    !sc_hnonsec_lock
    6       R   RSVD                                    1'b0
    7       R   RSVD                                    1'b0
    8       R   RSVD                                    1'b0
    9       R   RSVD                                    1'b0
    10      R   RSVD                                    1'b0
    11      R   RSVD                                    1'b0
    12      R   RSVD                                    1'b0
    13      R   RSVD                                    1'b0
    14      R   RSVD                                    1'b0
    15      R   RSVD                                    1'b0
    16      R   RSVD                                    1'b0
    17      R   RSVD                                    1'b0
    18      R   RSVD                                    1'b0
    19      R   RSVD                                    1'b0
    20      R   RSVD                                    1'b0
    21      R   RSVD                                    1'b0
    22      R   RSVD                                    1'b0
    23      R   RSVD                                    1'b0
    24      R   RSVD                                    1'b0
    25      R   RSVD                                    1'b0
    26      R   RSVD                                    1'b0
    27      R   RSVD                                    1'b0
    28      R   RSVD                                    1'b0
    29      R   RSVD                                    1'b0
    30      R   RSVD                                    1'b0
    31      W1O sc_hnonsec_lock                         1'b0
 */
typedef volatile union _AON_REG0X_SC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t usbotg_hnonsec: 1;
        uint32_t sdio_host0_hnonsec: 1;
        uint32_t display_arprot_1: 1;
        uint32_t RSVD_25: 1;
        uint32_t gmac_m_arprot_1: 1;
        uint32_t gmac_m_awprot_1: 1;
        uint32_t RSVD_24: 1;
        uint32_t RSVD_23: 1;
        uint32_t RSVD_22: 1;
        uint32_t RSVD_21: 1;
        uint32_t RSVD_20: 1;
        uint32_t RSVD_19: 1;
        uint32_t RSVD_18: 1;
        uint32_t RSVD_17: 1;
        uint32_t RSVD_16: 1;
        uint32_t RSVD_15: 1;
        uint32_t RSVD_14: 1;
        uint32_t RSVD_13: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
        uint32_t sc_hnonsec_lock: 1;
    };
} AON_REG0X_SC_TYPE;

/* 0x470    0x4000_0470
    0       R/W km4_dbgen                               1'b1                    !km4_dbgen_lock
    1       R/W km4_niden                               1'b1                    !km4_niden_lock
    2       R/W km4_spiden                              1'b0                    !km4_spiden_lock
    3       R/W km4_spniden                             1'b1                    !km4_spniden_lock
    4       W1O km4_dbgen_lock                          1'b0
    5       W1O km4_niden_lock                          1'b0
    6       W1O km4_spiden_lock                         1'b0
    7       W1O km4_spniden_lock                        1'b0
    8       R   RSVD                                    1'b0
    9       R   RSVD                                    1'b0
    10      R   RSVD                                    1'b0
    11      R   RSVD                                    1'b0
    12      R   RSVD                                    1'b0
    13      R   RSVD                                    1'b0
    14      R   RSVD                                    1'b0
    15      R   RSVD                                    1'b0
    16      R   RSVD                                    1'b0
    17      R   RSVD                                    1'b0
    18      R   RSVD                                    1'b0
    19      R   RSVD                                    1'b0
    20      R   RSVD                                    1'b0
    21      R   RSVD                                    1'b0
    22      R   RSVD                                    1'b0
    23      R   RSVD                                    1'b0
    24      R   RSVD                                    1'b0
    25      R   RSVD                                    1'b0
    26      R   RSVD                                    1'b0
    27      R   RSVD                                    1'b0
    28      R   RSVD                                    1'b0
    29      R   RSVD                                    1'b0
    30      R   RSVD                                    1'b0
    31      R   RSVD                                    1'b0
 */
typedef volatile union _AON_REG0X_KM4_DBG_CTRL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dbgen: 1;
        uint32_t km4_niden: 1;
        uint32_t km4_spiden: 1;
        uint32_t km4_spniden: 1;
        uint32_t km4_dbgen_lock: 1;
        uint32_t km4_niden_lock: 1;
        uint32_t km4_spiden_lock: 1;
        uint32_t km4_spniden_lock: 1;
        uint32_t RSVD_23: 1;
        uint32_t RSVD_22: 1;
        uint32_t RSVD_21: 1;
        uint32_t RSVD_20: 1;
        uint32_t RSVD_19: 1;
        uint32_t RSVD_18: 1;
        uint32_t RSVD_17: 1;
        uint32_t RSVD_16: 1;
        uint32_t RSVD_15: 1;
        uint32_t RSVD_14: 1;
        uint32_t RSVD_13: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
    };
} AON_REG0X_KM4_DBG_CTRL_TYPE;

/* 0x4B0    0x4000_04b0
    0       R/W RTC_PF_CNT_START                        1'b0
    1       R/W RTC_PF_CNT_RST                          1'b0
    7:2     R/W RTC_PF_COMP_CONTROLLER_DUMMY0           6'b0
    8       R/W RTC_PF_COMP0_WK_EN                      1'b0
    9       R/W RTC_PF_COMP1_WK_EN                      1'b0
    10      R/W RTC_PF_COMP2_WK_EN                      1'b0
    11      R/W RTC_PF_COMP3_WK_EN                      1'b0
    12      R/W RTC_PF_COMP0_INT_EN                     1'b0
    13      R/W RTC_PF_COMP1_INT_EN                     1'b0
    14      R/W RTC_PF_COMP2_INT_EN                     1'b0
    15      R/W RTC_PF_COMP3_INT_EN                     1'b0
    19:16   R/W RTC_PF_COMP_CONTROLLER_DUMMY1           4'b0
    20      R/W RTC_PF_COMP0_ISR_TYPE                   1'b0
    21      R/W RTC_PF_COMP1_ISR_TYPE                   1'b0
    22      R/W RTC_PF_COMP2_ISR_TYPE                   1'b0
    23      R/W RTC_PF_COMP3_ISR_TYPE                   1'b0
    28:24   R/W RTC_PF_COMP_CONTROLLER_DUMMY1           5'b0
    29      R/W RTC_PF_WK_EN                            1'b0
    30      R/W RTC_PF_INT_EN                           1'b0
    31      R/W RTC_PF_RST                              1'b0
 */
typedef volatile union _AON_RTC_PF_COMP_CONTROLLER_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_CNT_START: 1;
        uint32_t RTC_PF_CNT_RST: 1;
        uint32_t RTC_PF_COMP_CONTROLLER_DUMMY0: 6;
        uint32_t RTC_PF_COMP0_WK_EN: 1;
        uint32_t RTC_PF_COMP1_WK_EN: 1;
        uint32_t RTC_PF_COMP2_WK_EN: 1;
        uint32_t RTC_PF_COMP3_WK_EN: 1;
        uint32_t RTC_PF_COMP0_INT_EN: 1;
        uint32_t RTC_PF_COMP1_INT_EN: 1;
        uint32_t RTC_PF_COMP2_INT_EN: 1;
        uint32_t RTC_PF_COMP3_INT_EN: 1;
        uint32_t RTC_PF_COMP_CONTROLLER_DUMMY1_1: 4;
        uint32_t RTC_PF_COMP0_ISR_TYPE: 1;
        uint32_t RTC_PF_COMP1_ISR_TYPE: 1;
        uint32_t RTC_PF_COMP2_ISR_TYPE: 1;
        uint32_t RTC_PF_COMP3_ISR_TYPE: 1;
        uint32_t RTC_PF_COMP_CONTROLLER_DUMMY1: 5;
        uint32_t RTC_PF_WK_EN: 1;
        uint32_t RTC_PF_INT_EN: 1;
        uint32_t RTC_PF_RST: 1;
    };
    struct
    {
        uint32_t RTC_PF_COMP_CONTROLLER_ASSEMBLE0: 8;
        uint32_t RTC_PF_COMP_WK_EN: 4;
        uint32_t RTC_PF_COMP_INT_EN: 4;
        uint32_t RTC_PF_COMP_CONTROLLER_ASSEMBLE1: 4;
        uint32_t RTC_PF_COMP_ISR_TYPE: 4;
        uint32_t RTC_PF_COMP_CONTROLLER_ASSEMBLE2: 8;
    };
} AON_RTC_PF_COMP_CONTROLLER_REG_TYPE;

/* 0x4B4    0x4000_04b4
    31:0    R/W RTC_PF_COMP0                            32'd0
 */
typedef volatile union _AON_RTC_PF_COMP0_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP0;
    };
} AON_RTC_PF_COMP0_REG_TYPE;

/* 0x4B8    0x4000_04b8
    31:0    R/W RTC_PF_COMP1                            32'd0
 */
typedef volatile union _AON_RTC_PF_COMP1_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP1;
    };
} AON_RTC_PF_COMP1_REG_TYPE;

/* 0x4BC    0x4000_04bc
    31:0    R/W RTC_PF_COMP2                            32'd0
 */
typedef volatile union _AON_RTC_PF_COMP2_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP2;
    };
} AON_RTC_PF_COMP2_REG_TYPE;

/* 0x4C0    0x4000_04c0
    31:0    R/W RTC_PF_COMP3                            32'd0
 */
typedef volatile union _AON_RTC_PF_COMP3_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP3;
    };
} AON_RTC_PF_COMP3_REG_TYPE;

/* 0x4C4    0x4000_04c4
    0       R/W RTC_PF_COMP0_MANUAL_INT                 1'b0
    1       R/W RTC_PF_COMP1_MANUAL_INT                 1'b0
    2       R/W RTC_PF_COMP2_MANUAL_INT                 1'b0
    3       R/W RTC_PF_COMP3_MANUAL_INT                 1'b0
    31:4    R/W RTC_PF_COMP_MANUAL_INT_DUMMY            28'b0
 */
typedef volatile union _AON_RTC_PF_COMP_MANUAL_INT_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP0_MANUAL_INT: 1;
        uint32_t RTC_PF_COMP1_MANUAL_INT: 1;
        uint32_t RTC_PF_COMP2_MANUAL_INT: 1;
        uint32_t RTC_PF_COMP3_MANUAL_INT: 1;
        uint32_t RTC_PF_COMP_MANUAL_INT_DUMMY: 28;
    };
    struct
    {
        uint32_t RTC_PF_COMP_MANUAL_INT: 4;
        uint32_t RTC_PF_COMP_MANUAL_INT_ASSEMBLE: 28;
    };
} AON_RTC_PF_COMP_MANUAL_INT_REG_TYPE;

/* 0x4C8    0x4000_04c8
    31:0    R   RTC_PF_CNT                              32'd0
 */
typedef volatile union _AON_RTC_PF_CNT_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_CNT;
    };
} AON_RTC_PF_CNT_REG_TYPE;

/* 0x4CC    0x4000_04cc
    0       R/WACRTC_PF_COMP0_WK_CLR                     1'b0
    1       R/WACRTC_PF_COMP1_WK_CLR                     1'b0
    2       R/WACRTC_PF_COMP2_WK_CLR                     1'b0
    3       R/WACRTC_PF_COMP3_WK_CLR                     1'b0
    4       R/WACRTC_PF_COMP0_INT_CLR                    1'b0
    5       R/WACRTC_PF_COMP1_INT_CLR                    1'b0
    6       R/WACRTC_PF_COMP2_INT_CLR                    1'b0
    7       R/WACRTC_PF_COMP3_INT_CLR                    1'b0
    31:8    R/W RTC_PF_COMP_INT_WK_CLR_DUMMY            24'b0
 */
typedef volatile union _AON_RTC_PF_COMP_INT_WK_CLR_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP0_WK_CLR: 1;
        uint32_t RTC_PF_COMP1_WK_CLR: 1;
        uint32_t RTC_PF_COMP2_WK_CLR: 1;
        uint32_t RTC_PF_COMP3_WK_CLR: 1;
        uint32_t RTC_PF_COMP0_INT_CLR: 1;
        uint32_t RTC_PF_COMP1_INT_CLR: 1;
        uint32_t RTC_PF_COMP2_INT_CLR: 1;
        uint32_t RTC_PF_COMP3_INT_CLR: 1;
        uint32_t RTC_PF_COMP_INT_WK_CLR_DUMMY: 24;
    };
    struct
    {
        uint32_t RTC_PF_COMP_WK_CLR: 4;
        uint32_t RTC_PF_COMP_INT_CLR: 4;
        uint32_t RTC_PF_COMP_INT_WK_CLR_ASSEMBLE: 24;
    };
} AON_RTC_PF_COMP_INT_WK_CLR_REG_TYPE;

/* 0x4D0    0x4000_04d0
    0       R/W1CRTC_PF_COMP0_WK_SR                      1'b0
    1       R/W1CRTC_PF_COMP1_WK_SR                      1'b0
    2       R/W1CRTC_PF_COMP2_WK_SR                      1'b0
    3       R/W1CRTC_PF_COMP3_WK_SR                      1'b0
    4       R/W1CRTC_PF_COMP0_INT_SR                     1'b0
    5       R/W1CRTC_PF_COMP1_INT_SR                     1'b0
    6       R/W1CRTC_PF_COMP2_INT_SR                     1'b0
    7       R/W1CRTC_PF_COMP3_INT_SR                     1'b0
    31:8    R/W RTC_PF_COMP_INT_WK_SR_DUMMY             24'b0
 */
typedef volatile union _AON_RTC_PF_COMP_INT_WK_SR_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_COMP0_WK_SR: 1;
        uint32_t RTC_PF_COMP1_WK_SR: 1;
        uint32_t RTC_PF_COMP2_WK_SR: 1;
        uint32_t RTC_PF_COMP3_WK_SR: 1;
        uint32_t RTC_PF_COMP0_INT_SR: 1;
        uint32_t RTC_PF_COMP1_INT_SR: 1;
        uint32_t RTC_PF_COMP2_INT_SR: 1;
        uint32_t RTC_PF_COMP3_INT_SR: 1;
        uint32_t RTC_PF_COMP_INT_WK_SR_DUMMY: 24;
    };
    struct
    {
        uint32_t RTC_PF_COMP_WK_SR: 4;
        uint32_t RTC_PF_COMP_INT_SR: 4;
        uint32_t RTC_PF_COMP_INT_WK_SR_ASSEMBLE: 24;
    };
} AON_RTC_PF_COMP_INT_WK_SR_REG_TYPE;

/* 0x4D4    0x4000_04d4
    31:0    R   RTC_PF_RTL_VERSION                      32'h2208230A
 */
typedef volatile union _AON_RTC_PF_RTL_VERSION_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PF_RTL_VERSION;
    };
} AON_RTC_PF_RTL_VERSION_REG_TYPE;

/* 0x580    0x4000_0580
    0       R/W bt_mac_vsel                             1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_BT_MAC_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_BT_MAC_VSEL_TYPE;

/* 0x584    0x4000_0584
    13:0    R/W bt_mac_snps_lv                          14'h292
    27:14   R/W bt_mac_snps_hv                          14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BT_MAC_SNPS_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_snps_lv: 14;
        uint32_t bt_mac_snps_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BT_MAC_SNPS_HV_LV_TYPE;

/* 0x588    0x4000_0588
    0       R/W bt_mac_1024x16_sd_iso0                  1'h0
    1       R/W bt_mac_1024x16_sd_iso1                  1'h0
    2       R/W bt_mac_1024x16_ds_iso0                  1'h0
    3       R/W bt_mac_1024x16_ds_iso1                  1'h0
    4       R/W bt_mac_1024x16_ls_iso0                  1'h0
    5       R/W bt_mac_1024x16_ls_iso1                  1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_BT_MAC_1024x16_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_1024x16_sd_iso0: 1;
        uint32_t bt_mac_1024x16_sd_iso1: 1;
        uint32_t bt_mac_1024x16_ds_iso0: 1;
        uint32_t bt_mac_1024x16_ds_iso1: 1;
        uint32_t bt_mac_1024x16_ls_iso0: 1;
        uint32_t bt_mac_1024x16_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_BT_MAC_1024x16_PWR_TYPE;

/* 0x58C    0x4000_058c
    0       R/W bt_mac_512x16_sd_iso0                   1'h0
    1       R/W bt_mac_512x16_sd_iso1                   1'h0
    2       R/W bt_mac_512x16_ds_iso0                   1'h0
    3       R/W bt_mac_512x16_ds_iso1                   1'h0
    4       R/W bt_mac_512x16_ls_iso0                   1'h0
    5       R/W bt_mac_512x16_ls_iso1                   1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_BT_MAC_512x16_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_512x16_sd_iso0: 1;
        uint32_t bt_mac_512x16_sd_iso1: 1;
        uint32_t bt_mac_512x16_ds_iso0: 1;
        uint32_t bt_mac_512x16_ds_iso1: 1;
        uint32_t bt_mac_512x16_ls_iso0: 1;
        uint32_t bt_mac_512x16_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_BT_MAC_512x16_PWR_TYPE;

/* 0x590    0x4000_0590
    0       R/W bt_mac_128x32_0_sd_iso0                 1'h0
    1       R/W bt_mac_128x32_0_sd_iso1                 1'h0
    2       R/W bt_mac_128x32_0_ds_iso0                 1'h0
    3       R/W bt_mac_128x32_0_ds_iso1                 1'h0
    4       R/W bt_mac_128x32_0_ls_iso0                 1'h0
    5       R/W bt_mac_128x32_0_ls_iso1                 1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_BT_MAC_128x32_0_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_128x32_0_sd_iso0: 1;
        uint32_t bt_mac_128x32_0_sd_iso1: 1;
        uint32_t bt_mac_128x32_0_ds_iso0: 1;
        uint32_t bt_mac_128x32_0_ds_iso1: 1;
        uint32_t bt_mac_128x32_0_ls_iso0: 1;
        uint32_t bt_mac_128x32_0_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_BT_MAC_128x32_0_PWR_TYPE;

/* 0x594    0x4000_0594
    0       R/W bt_mac_128x32_1_sd_iso0                 1'h0
    1       R/W bt_mac_128x32_1_sd_iso1                 1'h0
    2       R/W bt_mac_128x32_1_ds_iso0                 1'h0
    3       R/W bt_mac_128x32_1_ds_iso1                 1'h0
    4       R/W bt_mac_128x32_1_ls_iso0                 1'h0
    5       R/W bt_mac_128x32_1_ls_iso1                 1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_BT_MAC_128x32_1_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_128x32_1_sd_iso0: 1;
        uint32_t bt_mac_128x32_1_sd_iso1: 1;
        uint32_t bt_mac_128x32_1_ds_iso0: 1;
        uint32_t bt_mac_128x32_1_ds_iso1: 1;
        uint32_t bt_mac_128x32_1_ls_iso0: 1;
        uint32_t bt_mac_128x32_1_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_BT_MAC_128x32_1_PWR_TYPE;

/* 0x598    0x4000_0598
    13:0    R/W bt_mac_640x32_lv                        14'b11000100100010
    27:14   R/W bt_mac_640x32_hv                        14'b11000010100010
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BT_MAC_640x32_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_640x32_lv: 14;
        uint32_t bt_mac_640x32_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BT_MAC_640x32_HV_LV_TYPE;

/* 0x59C    0x4000_059c
    0       R/W bt_mac_640x32_sd_iso0                   1'h0
    1       R/W bt_mac_640x32_sd_iso1                   1'h0
    2       R/W bt_mac_640x32_ds_iso0                   1'h0
    3       R/W bt_mac_640x32_ds_iso1                   1'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_BT_MAC_640x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_640x32_sd_iso0: 1;
        uint32_t bt_mac_640x32_sd_iso1: 1;
        uint32_t bt_mac_640x32_ds_iso0: 1;
        uint32_t bt_mac_640x32_ds_iso1: 1;
        uint32_t RSVD: 28;
    };
} AON_BT_MAC_640x32_PWR_TYPE;

/* 0x5A0    0x4000_05a0
    13:0    R/W bt_mac_96x32_lv                         14'b11000001100010
    27:14   R/W bt_mac_96x32_hv                         14'b11000010100010
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BT_MAC_96x32_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_96x32_lv: 14;
        uint32_t bt_mac_96x32_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BT_MAC_96x32_HV_LV_TYPE;

/* 0x5A4    0x4000_05a4
    0       R/W bt_mac_96x32_sd_iso0                    1'h0
    1       R/W bt_mac_96x32_sd_iso1                    1'h0
    2       R/W bt_mac_96x32_ds_iso0                    1'h0
    3       R/W bt_mac_96x32_ds_iso1                    1'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_BT_MAC_96x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_96x32_sd_iso0: 1;
        uint32_t bt_mac_96x32_sd_iso1: 1;
        uint32_t bt_mac_96x32_ds_iso0: 1;
        uint32_t bt_mac_96x32_ds_iso1: 1;
        uint32_t RSVD: 28;
    };
} AON_BT_MAC_96x32_PWR_TYPE;

/* 0x5A8    0x4000_05a8
    13:0    R/W bt_mac_64x32_lv                         14'b11000001100010
    27:14   R/W bt_mac_64x32_hv                         14'b11000010100010
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BT_MAC_64x32_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_64x32_lv: 14;
        uint32_t bt_mac_64x32_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BT_MAC_64x32_HV_LV_TYPE;

/* 0x5AC    0x4000_05ac
    0       R/W bt_mac_64x32_sd_iso0                    1'h0
    1       R/W bt_mac_64x32_sd_iso1                    1'h0
    2       R/W bt_mac_64x32_ds_iso0                    1'h0
    3       R/W bt_mac_64x32_ds_iso1                    1'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_BT_MAC_64x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_mac_64x32_sd_iso0: 1;
        uint32_t bt_mac_64x32_sd_iso1: 1;
        uint32_t bt_mac_64x32_ds_iso0: 1;
        uint32_t bt_mac_64x32_ds_iso1: 1;
        uint32_t RSVD: 28;
    };
} AON_BT_MAC_64x32_PWR_TYPE;

/* 0x5B0    0x4000_05b0
    0       R/W zb_mac_vsel                             1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_ZB_MAC_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t zb_mac_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_ZB_MAC_VSEL_TYPE;

/* 0x5B4    0x4000_05b4
    13:0    R/W zb_mac_lv                               14'h292
    27:14   R/W zb_mac_hv                               14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_ZB_MAC_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t zb_mac_lv: 14;
        uint32_t zb_mac_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_ZB_MAC_HV_LV_TYPE;

/* 0x5B8    0x4000_05b8
    0       R/W zb_mac_16x32_ds_iso0                    1'h0
    1       R/W zb_mac_16x32_ds_iso1                    1'h0
    2       R/W zb_mac_16x32_ls_iso0                    1'h0
    3       R/W zb_mac_16x32_ls_iso1                    1'h0
    4       R/W zb_mac_16x32_sd_iso0                    1'h0
    5       R/W zb_mac_16x32_sd_iso1                    1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_ZB_MAC_16x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t zb_mac_16x32_ds_iso0: 1;
        uint32_t zb_mac_16x32_ds_iso1: 1;
        uint32_t zb_mac_16x32_ls_iso0: 1;
        uint32_t zb_mac_16x32_ls_iso1: 1;
        uint32_t zb_mac_16x32_sd_iso0: 1;
        uint32_t zb_mac_16x32_sd_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_ZB_MAC_16x32_PWR_TYPE;

/* 0x5BC    0x4000_05bc
    1:0     R/W zb_mac_40x32_sd_iso0                    2'h0
    3:2     R/W zb_mac_40x32_sd_iso1                    2'h0
    5:4     R/W zb_mac_40x32_ds_iso0                    2'h0
    7:6     R/W zb_mac_40x32_ds_iso1                    2'h0
    9:8     R/W zb_mac_40x32_ls_iso0                    2'h0
    11:10   R/W zb_mac_40x32_ls_iso1                    2'h0
    31:12   R   RSVD                                    20'h0
 */
typedef volatile union _AON_ZB_MAC_40x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t zb_mac_40x32_sd_iso0: 2;
        uint32_t zb_mac_40x32_sd_iso1: 2;
        uint32_t zb_mac_40x32_ds_iso0: 2;
        uint32_t zb_mac_40x32_ds_iso1: 2;
        uint32_t zb_mac_40x32_ls_iso0: 2;
        uint32_t zb_mac_40x32_ls_iso1: 2;
        uint32_t RSVD: 20;
    };
} AON_ZB_MAC_40x32_PWR_TYPE;

/* 0x5C0    0x4000_05c0
    3:0     R/W zb_mac_32x32_sd_iso0                    4'h0
    7:4     R/W zb_mac_32x32_sd_iso1                    4'h0
    11:8    R/W zb_mac_32x32_ds_iso0                    4'h0
    15:12   R/W zb_mac_32x32_ds_iso1                    4'h0
    19:16   R/W zb_mac_32x32_ls_iso0                    4'h0
    23:20   R/W zb_mac_32x32_ls_iso1                    4'h0
    31:24   R   RSVD                                    8'h0
 */
typedef volatile union _AON_ZB_MAC_32x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t zb_mac_32x32_sd_iso0: 4;
        uint32_t zb_mac_32x32_sd_iso1: 4;
        uint32_t zb_mac_32x32_ds_iso0: 4;
        uint32_t zb_mac_32x32_ds_iso1: 4;
        uint32_t zb_mac_32x32_ls_iso0: 4;
        uint32_t zb_mac_32x32_ls_iso1: 4;
        uint32_t RSVD: 8;
    };
} AON_ZB_MAC_32x32_PWR_TYPE;

/* 0x5C4    0x4000_05c4
    0       R/W bt_phy_vsel                             1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_BT_PHY_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_phy_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_BT_PHY_VSEL_TYPE;

/* 0x5C8    0x4000_05c8
    13:0    R/W bt_phy_lv                               14'h292
    27:14   R/W bt_phy_hv                               14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BT_PHY_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t bt_phy_lv: 14;
        uint32_t bt_phy_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BT_PHY_HV_LV_TYPE;

/* 0x5CC    0x4000_05cc
    3:0     R/W btphy_128x12x4_sd_iso0                  4'h0
    7:4     R/W btphy_128x12x4_sd_iso1                  4'h0
    11:8    R/W btphy_128x12x4_ds_iso0                  4'h0
    15:12   R/W btphy_128x12x4_ds_iso1                  4'h0
    19:16   R/W btphy_128x12x4_ls_iso0                  4'h0
    23:20   R/W btphy_128x12x4_ls_iso1                  4'h0
    31:24   R   RSVD                                    8'h0
 */
typedef volatile union _AON_BT_PHY_128x12x4_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t btphy_128x12x4_sd_iso0: 4;
        uint32_t btphy_128x12x4_sd_iso1: 4;
        uint32_t btphy_128x12x4_ds_iso0: 4;
        uint32_t btphy_128x12x4_ds_iso1: 4;
        uint32_t btphy_128x12x4_ls_iso0: 4;
        uint32_t btphy_128x12x4_ls_iso1: 4;
        uint32_t RSVD: 8;
    };
} AON_BT_PHY_128x12x4_PWR_TYPE;

/* 0x5D0    0x4000_05d0
    4:0     R/W btphy_lr_ram_sd_iso0                    5'h0
    9:5     R/W btphy_lr_ram_sd_iso1                    5'h0
    14:10   R/W btphy_lr_ram_ds_iso0                    5'h0
    19:15   R/W btphy_lr_ram_ds_iso1                    5'h0
    24:20   R/W btphy_lr_ram_ls_iso0                    5'h0
    29:25   R/W btphy_lr_ram_ls_iso1                    5'h0
    31:30   R   RSVD                                    2'h0
 */
typedef volatile union _AON_BT_PHY_LR_RAM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t btphy_lr_ram_sd_iso0: 5;
        uint32_t btphy_lr_ram_sd_iso1: 5;
        uint32_t btphy_lr_ram_ds_iso0: 5;
        uint32_t btphy_lr_ram_ds_iso1: 5;
        uint32_t btphy_lr_ram_ls_iso0: 5;
        uint32_t btphy_lr_ram_ls_iso1: 5;
        uint32_t RSVD: 2;
    };
} AON_BT_PHY_LR_RAM_PWR_TYPE;

/* 0x5D4    0x4000_05d4
    0       R/W km4_vsel                                1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_KM4_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_KM4_VSEL_TYPE;

/* 0x5D8    0x4000_05d8
    5:0     R/W km4_itcm0_lv                            6'h12
    11:6    R/W km4_itcm0_hv                            6'h13
    31:12   R   RSVD                                    20'h0
 */
typedef volatile union _AON_KM4_ITCM0_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_itcm0_lv: 6;
        uint32_t km4_itcm0_hv: 6;
        uint32_t RSVD: 20;
    };
} AON_KM4_ITCM0_HV_LV_TYPE;

/* 0x5DC    0x4000_05dc
    3:0     R/W km4_itcm0_ls_iso0                       4'h0
    7:4     R/W km4_itcm0_ls_iso1                       4'h0
    31:8    R   RSVD                                    24'h0
 */
typedef volatile union _AON_KM4_ITCM0_LS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_itcm0_ls_iso0: 4;
        uint32_t km4_itcm0_ls_iso1: 4;
        uint32_t RSVD: 24;
    };
} AON_KM4_ITCM0_LS_TYPE;

/* 0x5E0    0x4000_05e0
    13:0    R/W km4_tcm_lv                              14'b11000101100010
    27:14   R/W km4_tcm_hv                              14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_KM4_TCM_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_tcm_lv: 14;
        uint32_t km4_tcm_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_KM4_TCM_HV_LV_TYPE;

/* 0x5E4    0x4000_05e4
    11:0    R/W km4_itcm1_ds_iso0                       12'h0
    23:12   R/W km4_itcm1_ds_iso1                       12'h0
    31:24   R   RSVD                                    8'h0
 */
typedef volatile union _AON_KM4_ITCM1_PWR_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_itcm1_ds_iso0: 12;
        uint32_t km4_itcm1_ds_iso1: 12;
        uint32_t RSVD: 8;
    };
} AON_KM4_ITCM1_PWR_0_TYPE;

/* 0x5E8    0x4000_05e8
    11:0    R/W km4_itcm1_sd_iso0                       12'h0
    23:12   R/W km4_itcm1_sd_iso1                       12'h0
    31:24   R   RSVD                                    8'h
 */
typedef volatile union _AON_KM4_ITCM1_PWR_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_itcm1_sd_iso0: 12;
        uint32_t km4_itcm1_sd_iso1: 12;
        uint32_t RSVD: 8;
    };
} AON_KM4_ITCM1_PWR_1_TYPE;

/* 0x5EC    0x4000_05ec
    3:0     R/W km4_dtcm0_sd_iso0                       4'h0
    7:4     R/W km4_dtcm0_sd_iso1                       4'h0
    11:8    R/W km4_dtcm0_ds_iso0                       4'h0
    15:12   R/W km4_dtcm0_ds_iso1                       4'h0
    31:16   R   RSVD                                    16'h0
 */
typedef volatile union _AON_KM4_DTCM0_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dtcm0_sd_iso0: 4;
        uint32_t km4_dtcm0_sd_iso1: 4;
        uint32_t km4_dtcm0_ds_iso0: 4;
        uint32_t km4_dtcm0_ds_iso1: 4;
        uint32_t RSVD: 16;
    };
} AON_KM4_DTCM0_PWR_TYPE;

/* 0x5F0    0x4000_05f0
    3:0     R/W km4_dtcm1_sd_iso0                       4'h0
    7:4     R/W km4_dtcm1_sd_iso1                       4'h0
    11:8    R/W km4_dtcm1_ds_iso0                       4'h0
    15:12   R/W km4_dtcm1_ds_iso1                       4'h0
    31:16   R   RSVD                                    16'h0
 */
typedef volatile union _AON_KM4_DTCM1_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dtcm1_sd_iso0: 4;
        uint32_t km4_dtcm1_sd_iso1: 4;
        uint32_t km4_dtcm1_ds_iso0: 4;
        uint32_t km4_dtcm1_ds_iso1: 4;
        uint32_t RSVD: 16;
    };
} AON_KM4_DTCM1_PWR_TYPE;

/* 0x5F4    0x4000_05f4
    13:0    R/W km4_ic_data_lv                          14'b11000101100010
    27:14   R/W km4_ic_data_hv                          14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_KM4_IC_DATA_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_ic_data_lv: 14;
        uint32_t km4_ic_data_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_KM4_IC_DATA_HV_LV_TYPE;

/* 0x5F8    0x4000_05f8
    1:0     R/W km4_ic_data_sd_iso0                     2'h0
    3:2     R/W km4_ic_data_sd_iso1                     2'h0
    5:4     R/W km4_ic_data_ds_iso0                     2'h0
    7:6     R/W km4_ic_data_ds_iso1                     2'h0
    31:8    R   RSVD                                    24'h0
 */
typedef volatile union _AON_KM4_IC_DATA_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_ic_data_sd_iso0: 2;
        uint32_t km4_ic_data_sd_iso1: 2;
        uint32_t km4_ic_data_ds_iso0: 2;
        uint32_t km4_ic_data_ds_iso1: 2;
        uint32_t RSVD: 24;
    };
} AON_KM4_IC_DATA_PWR_TYPE;

/* 0x5FC    0x4000_05fc
    13:0    R/W km4_ic_tag_lv                           14'b11000100100010
    27:14   R/W km4_ic_tag_hv                           14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_KM4_IC_TAG_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_ic_tag_lv: 14;
        uint32_t km4_ic_tag_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_KM4_IC_TAG_HV_LV_TYPE;

/* 0x600    0x4000_0600
    1:0     R/W km4_ic_tag_sd_iso0                      2'h0
    3:2     R/W km4_ic_tag_sd_iso1                      2'h0
    5:4     R/W km4_ic_tag_ds_iso0                      2'h0
    7:6     R/W km4_ic_tag_ds_iso1                      2'h0
    31:8    R   RSVD                                    24'h0
 */
typedef volatile union _AON_KM4_IC_TAG_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_ic_tag_sd_iso0: 2;
        uint32_t km4_ic_tag_sd_iso1: 2;
        uint32_t km4_ic_tag_ds_iso0: 2;
        uint32_t km4_ic_tag_ds_iso1: 2;
        uint32_t RSVD: 24;
    };
} AON_KM4_IC_TAG_PWR_TYPE;

/* 0x604    0x4000_0604
    13:0    R/W km4_dc_data_lv                          14'b11000101100010
    27:14   R/W km4_dc_data_hv                          14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_KM4_DC_DATA_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dc_data_lv: 14;
        uint32_t km4_dc_data_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_KM4_DC_DATA_HV_LV_TYPE;

/* 0x608    0x4000_0608
    3:0     R/W km4_dc_data_sd_iso0                     4'h0
    7:4     R/W km4_dc_data_sd_iso1                     4'h0
    11:8    R/W km4_dc_data_ds_iso0                     4'h0
    15:12   R/W km4_dc_data_ds_iso1                     4'h0
    31:16   R   RSVD                                    16'h0
 */
typedef volatile union _AON_KM4_DC_DATA_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dc_data_sd_iso0: 4;
        uint32_t km4_dc_data_sd_iso1: 4;
        uint32_t km4_dc_data_ds_iso0: 4;
        uint32_t km4_dc_data_ds_iso1: 4;
        uint32_t RSVD: 16;
    };
} AON_KM4_DC_DATA_PWR_TYPE;

/* 0x60C    0x4000_060c
    13:0    R/W km4_dc_tag_lv                           14'b11000100100010
    27:14   R/W km4_dc_tag_hv                           14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_KM4_DC_TAG_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dc_tag_lv: 14;
        uint32_t km4_dc_tag_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_KM4_DC_TAG_HV_LV_TYPE;

/* 0x610    0x4000_0610
    1:0     R/W km4_dc_tag_sd_iso0                      2'h0
    3:2     R/W km4_dc_tag_sd_iso1                      2'h0
    5:4     R/W km4_dc_tag_ds_iso0                      2'h0
    7:6     R/W km4_dc_tag_ds_iso1                      2'h0
    31:8    R   RSVD                                    24'h0
 */
typedef volatile union _AON_KM4_DC_TAG_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_dc_tag_sd_iso0: 2;
        uint32_t km4_dc_tag_sd_iso1: 2;
        uint32_t km4_dc_tag_ds_iso0: 2;
        uint32_t km4_dc_tag_ds_iso1: 2;
        uint32_t RSVD: 24;
    };
} AON_KM4_DC_TAG_PWR_TYPE;

/* 0x614    0x4000_0614
    0       R/W buffer_ram_vsel                         1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_BUFFER_RAM_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t buffer_ram_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_BUFFER_RAM_VSEL_TYPE;

/* 0x618    0x4000_0618
    13:0    R/W buffer_ram_lv                           14'b11000101100010
    27:14   R/W buffer_ram_hv                           14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_BUFFER_RAM_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t buffer_ram_lv: 14;
        uint32_t buffer_ram_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_BUFFER_RAM_HV_LV_TYPE;

/* 0x61C    0x4000_061c
    2:0     R/W buffer_ram_sd_iso0                      3'h0
    5:3     R/W buffer_ram_sd_iso1                      3'h0
    8:6     R/W buffer_ram_ds_iso0                      3'h0
    11:9    R/W buffer_ram_ds_iso1                      3'h0
    31:12   R   RSVD                                    20'h0
 */
typedef volatile union _AON_BUFFER_RAM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t buffer_ram_sd_iso0: 3;
        uint32_t buffer_ram_sd_iso1: 3;
        uint32_t buffer_ram_ds_iso0: 3;
        uint32_t buffer_ram_ds_iso1: 3;
        uint32_t RSVD: 20;
    };
} AON_BUFFER_RAM_PWR_TYPE;

/* 0x620    0x4000_0620
    0       R/W data_ram_vsel                           1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_DATA_RAM_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t data_ram_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_DATA_RAM_VSEL_TYPE;

/* 0x624    0x4000_0624
    13:0    R/W data_ram_lv                             14'b11000101100010
    27:14   R/W data_ram_hv                             14'b11000010101100
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_DATA_RAM_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t data_ram_lv: 14;
        uint32_t data_ram_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_DATA_RAM_HV_LV_TYPE;

/* 0x628    0x4000_0628
    0       R/W data_ram_sd_iso0                        1'h0
    1       R/W data_ram_sd_iso1                        1'h0
    2       R/W data_ram_ds_iso0                        1'h0
    3       R/W data_ram_ds_iso1                        1'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_DATA_RAM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t data_ram_sd_iso0: 1;
        uint32_t data_ram_sd_iso1: 1;
        uint32_t data_ram_ds_iso0: 1;
        uint32_t data_ram_ds_iso1: 1;
        uint32_t RSVD: 28;
    };
} AON_DATA_RAM_PWR_TYPE;

/* 0x62C    0x4000_062c
    0       R/W usb_vsel                                1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_USB_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t usb_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_USB_VSEL_TYPE;

/* 0x630    0x4000_0630
    13:0    R/W usb_lv                                  14'h292
    27:14   R/W usb_hv                                  14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_USB_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t usb_lv: 14;
        uint32_t usb_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_USB_HV_LV_TYPE;

/* 0x634    0x4000_0634
    0       R/W usb_2176x35_sd_iso0                     1'h0
    1       R/W usb_2176x35_sd_iso1                     1'h0
    2       R/W usb_2176x35_ds_iso0                     1'h0
    3       R/W usb_2176x35_ds_iso1                     1'h0
    4       R/W usb_2176x35_ls_iso0                     1'h0
    5       R/W usb_2176x35_ls_iso1                     1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_USB_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t usb_2176x35_sd_iso0: 1;
        uint32_t usb_2176x35_sd_iso1: 1;
        uint32_t usb_2176x35_ds_iso0: 1;
        uint32_t usb_2176x35_ds_iso1: 1;
        uint32_t usb_2176x35_ls_iso0: 1;
        uint32_t usb_2176x35_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_USB_PWR_TYPE;

/* 0x638    0x4000_0638
    0       R/W sdio_ram_pd_iso0                        1'h0
    1       R/W sdio_ram_pd_iso1                        1'h0
    31:2    R   RSVD                                    30'h0
 */
typedef volatile union _AON_SDIO_RAM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t sdio_ram_pd_iso0: 1;
        uint32_t sdio_ram_pd_iso1: 1;
        uint32_t RSVD: 30;
    };
} AON_SDIO_RAM_PWR_TYPE;

/* 0x63C    0x4000_063c
    0       R/W display_128x32_pd_iso0                  1'h0
    1       R/W display_128x32_pd_iso1                  1'h0
    31:2    R   RSVD                                    30'h0
 */
typedef volatile union _AON_DISPLAY_128x32_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t display_128x32_pd_iso0: 1;
        uint32_t display_128x32_pd_iso1: 1;
        uint32_t RSVD: 30;
    };
} AON_DISPLAY_128x32_PWR_TYPE;

/* 0x640    0x4000_0640
    0       R/W display_672x24_pd_iso0                  1'h0
    1       R/W display_672x24_pd_iso1                  1'h0
    31:2    R   RSVD                                    30'h0
 */
typedef volatile union _AON_DISPLAY_672x24_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t display_672x24_pd_iso0: 1;
        uint32_t display_672x24_pd_iso1: 1;
        uint32_t RSVD: 30;
    };
} AON_DISPLAY_672x24_PWR_TYPE;

/* 0x644    0x4000_0644
    1:0     R/W gmac_512x32_pd_iso0                     2'h0
    3:2     R/W gmac_512x32_pd_iso1                     2'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_GMAC_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t gmac_512x32_pd_iso0: 2;
        uint32_t gmac_512x32_pd_iso1: 2;
        uint32_t RSVD: 28;
    };
} AON_GMAC_PWR_TYPE;

/* 0x648    0x4000_0648
    5:0     R/W pke_rom_hv                              6'h13
    31:6    R/W RSVD                                    26'h0
 */
typedef volatile union _AON_PKE_ROM_HV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t pke_rom_hv: 6;
        uint32_t RSVD: 26;
    };
} AON_PKE_ROM_HV_TYPE;

/* 0x64C    0x4000_064c
    0       R/W pke_rom_sd_iso1                         1'h0
    1       R/W pke_rom_sd_iso0                         1'h0
    2       R/W pke_rom_ls_iso1                         1'h0
    3       R/W pke_rom_ls_iso0                         1'h0
    31:4    R/W RSVD                                    28'h0
 */
typedef volatile union _AON_PKE_ROM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t pke_rom_sd_iso1: 1;
        uint32_t pke_rom_sd_iso0: 1;
        uint32_t pke_rom_ls_iso1: 1;
        uint32_t pke_rom_ls_iso0: 1;
        uint32_t RSVD: 28;
    };
} AON_PKE_ROM_PWR_TYPE;

/* 0x650    0x4000_0650
    1:0     R/W pke_mmem_pd_iso0                        2'h0
    3:2     R/W pke_mmem_pd_iso1                        2'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_PKE_MMEM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t pke_mmem_pd_iso0: 2;
        uint32_t pke_mmem_pd_iso1: 2;
        uint32_t RSVD: 28;
    };
} AON_PKE_MMEM_PWR_TYPE;

/* 0x654    0x4000_0654
    1:0     R/W pke_tmem_pd_iso0                        2'h0
    3:2     R/W pke_tmem_pd_iso1                        2'h0
    31:4    R   RSVD                                    28'h0
 */
typedef volatile union _AON_PKE_TMEM_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t pke_tmem_pd_iso0: 2;
        uint32_t pke_tmem_pd_iso1: 2;
        uint32_t RSVD: 28;
    };
} AON_PKE_TMEM_PWR_TYPE;

/* 0x658    0x4000_0658
    0       R/W audio_vsel                              1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_AUDIO_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t audio_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_AUDIO_VSEL_TYPE;

/* 0x65C    0x4000_065c
    13:0    R/W audio_lv                                14'h292
    27:14   R/W audio_hv                                14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_AUDIO_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t audio_lv: 14;
        uint32_t audio_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_AUDIO_HV_LV_TYPE;

/* 0x660    0x4000_0660
    1:0     R/W audio_ad_ram_sd_iso0                    2'h0
    3:2     R/W audio_ad_ram_sd_iso1                    2'h0
    5:4     R/W audio_ad_ram_ds_iso0                    2'h0
    7:6     R/W audio_ad_ram_ds_iso1                    2'h0
    9:8     R/W audio_ad_ram_ls_iso0                    2'h0
    11:10   R/W audio_ad_ram_ls_iso1                    2'h0
    31:12   R   RSVD                                    20'h0
 */
typedef volatile union _AON_AUDIO_AD_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t audio_ad_ram_sd_iso0: 2;
        uint32_t audio_ad_ram_sd_iso1: 2;
        uint32_t audio_ad_ram_ds_iso0: 2;
        uint32_t audio_ad_ram_ds_iso1: 2;
        uint32_t audio_ad_ram_ls_iso0: 2;
        uint32_t audio_ad_ram_ls_iso1: 2;
        uint32_t RSVD: 20;
    };
} AON_AUDIO_AD_PWR_TYPE;

/* 0x664    0x4000_0664
    0       R/W audio_da_ram_sd_iso0                    1'h0
    1       R/W audio_da_ram_sd_iso1                    1'h0
    2       R/W audio_da_ram_ds_iso0                    1'h0
    3       R/W audio_da_ram_ds_iso1                    1'h0
    4       R/W audio_da_ram_ls_iso0                    1'h0
    5       R/W audio_da_ram_ls_iso1                    1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_AUDIO_DA_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t audio_da_ram_sd_iso0: 1;
        uint32_t audio_da_ram_sd_iso1: 1;
        uint32_t audio_da_ram_ds_iso0: 1;
        uint32_t audio_da_ram_ds_iso1: 1;
        uint32_t audio_da_ram_ls_iso0: 1;
        uint32_t audio_da_ram_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_AUDIO_DA_PWR_TYPE;

/* 0x668    0x4000_0668
    0       R/W can_vsel                                1'h1
    31:1    R   RSVD                                    31'h0
 */
typedef volatile union _AON_CAN_VSEL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t can_vsel: 1;
        uint32_t RSVD: 31;
    };
} AON_CAN_VSEL_TYPE;

/* 0x66C    0x4000_066c
    13:0    R/W can_lv                                  14'h292
    27:14   R/W can_hv                                  14'h213
    31:28   R   RSVD                                    4'h0
 */
typedef volatile union _AON_CAN_HV_LV_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t can_lv: 14;
        uint32_t can_hv: 14;
        uint32_t RSVD: 4;
    };
} AON_CAN_HV_LV_TYPE;

/* 0x670    0x4000_0670
    0       R/W can_ram_sd_iso0                         1'h0
    1       R/W can_ram_sd_iso1                         1'h0
    2       R/W can_ram_ds_iso0                         1'h0
    3       R/W can_ram_ds_iso1                         1'h0
    4       R/W can_ram_ls_iso0                         1'h0
    5       R/W can_ram_ls_iso1                         1'h0
    31:6    R   RSVD                                    26'h0
 */
typedef volatile union _AON_CAN_PWR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t can_ram_sd_iso0: 1;
        uint32_t can_ram_sd_iso1: 1;
        uint32_t can_ram_ds_iso0: 1;
        uint32_t can_ram_ds_iso1: 1;
        uint32_t can_ram_ls_iso0: 1;
        uint32_t can_ram_ls_iso1: 1;
        uint32_t RSVD: 26;
    };
} AON_CAN_PWR_TYPE;

/* 0x800    0x4000_0800
    0       R/W BT_CORE_RSTB                            1'b0
    1       R/W BT_PON_RSTB                             1'b0
    2       R/W BT_RET_RSTB                             1'b0
    3       R/W ISO_XTAL                                1'b1
    4       R/W ISO_BT_CORE                             1'b1
    5       R/W ISO_BT_PON                              1'b1
    6       R/W ISO_VDDON_XTAL                          1'b1
    7       R/W ISO_OSC                                 1'b1
    8       R/W ISO_AFE_PLL                             1'b1
    9       R/W BT_PON2_RSTB                            1'b0
    10      R/W ISO_BT_PON2                             1'b1
    11      R/W BT_CORE3_RSTB                           1'b0
    12      R/W ISO_BT_CORE3                            1'b1
    13      R/W BT_AON_ACTIVE_CLK_RSTB                  1'b0
    14      R/W ISO_EF2AON                              1'b1
    15      R/W ISO_USB_VON                             1'b1
    16      R/W ISO_DIG_40M                             1'b1
    17      R/W ISO_AFE_PLL2                            1'b1
    31:18   R   RSVD                                    14'b0
 */
typedef volatile union _AON_REG0X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BT_CORE_RSTB: 1;
        uint32_t BT_PON_RSTB: 1;
        uint32_t BT_RET_RSTB: 1;
        uint32_t ISO_XTAL: 1;
        uint32_t ISO_BT_CORE: 1;
        uint32_t ISO_BT_PON: 1;
        uint32_t ISO_VDDON_XTAL: 1;
        uint32_t ISO_OSC: 1;
        uint32_t ISO_AFE_PLL: 1;
        uint32_t BT_PON2_RSTB: 1;
        uint32_t ISO_BT_PON2: 1;
        uint32_t BT_CORE3_RSTB: 1;
        uint32_t ISO_BT_CORE3: 1;
        uint32_t BT_AON_ACTIVE_CLK_RSTB: 1;
        uint32_t ISO_EF2AON: 1;
        uint32_t ISO_USB_VON: 1;
        uint32_t ISO_DIG_40M: 1;
        uint32_t ISO_AFE_PLL2: 1;
        uint32_t RSVD: 14;
    };
} AON_REG0X_SYS_TYPE;

/* 0x804    0x4000_0804
    0       R/W RFC_STORE                               1'b0
    1       R/W RFC_RESTORE                             1'b0
    2       R/W MODEM_STORE                             1'b0
    3       R/W MODEM_RESTORE                           1'b0
    4       R/W BZ_STORE                                1'b0
    5       R/W BZ_RESTORE                              1'b0
    6       R/W BLE_STORE                               1'b0
    7       R/W BLE_RESTORE                             1'b0
    8       R/W PF_STORE                                1'b0
    9       R/W PF_RESTORE                              1'b0
    10      R/W DP_MODEM_STORE                          1'b0
    11      R/W DP_MODEM_RESTORE                        1'b0
    12      R/W ZB_STORE                                1'b0
    13      R/W ZB_RESTORE                              1'b0
    31:14   R   RSVD                                    18'b0
 */
typedef volatile union _AON_REG1X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RFC_STORE: 1;
        uint32_t RFC_RESTORE: 1;
        uint32_t MODEM_STORE: 1;
        uint32_t MODEM_RESTORE: 1;
        uint32_t BZ_STORE: 1;
        uint32_t BZ_RESTORE: 1;
        uint32_t BLE_STORE: 1;
        uint32_t BLE_RESTORE: 1;
        uint32_t PF_STORE: 1;
        uint32_t PF_RESTORE: 1;
        uint32_t DP_MODEM_STORE: 1;
        uint32_t DP_MODEM_RESTORE: 1;
        uint32_t ZB_STORE: 1;
        uint32_t ZB_RESTORE: 1;
        uint32_t RSVD: 18;
    };
} AON_REG1X_SYS_TYPE;

/* 0x808    0x4000_0808
    0       R/W FW_enter_lps                            1'b0
    1       R/W FW_PON_SEQ_RST_N                        1'b0
    2       R/W AON_GATED_EN                            1'b1
    3       R/W PMU_SETTING_ENABLE                      1'b1
    4       R/W WAIT_XTAL_CLK_OK                        1'b1
    5       R/W PMU_OFF_SEQUENCE                        1'b0
    6       R/W AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN          1'b0
    12:7    R/W REG2X_SYS_DUMMY                         6'h2a
    15:13   R/W AON_DBG_SEL                             3'h0
    31:16   R/W REG2X_SYS_DUMMY2                        16'b0
 */
typedef volatile union _AON_REG2X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_enter_lps: 1;
        uint32_t FW_PON_SEQ_RST_N: 1;
        uint32_t AON_GATED_EN: 1;
        uint32_t PMU_SETTING_ENABLE: 1;
        uint32_t WAIT_XTAL_CLK_OK: 1;
        uint32_t PMU_OFF_SEQUENCE: 1;
        uint32_t AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN: 1;
        uint32_t REG2X_SYS_DUMMY: 6;
        uint32_t AON_DBG_SEL: 3;
        uint32_t REG2X_SYS_DUMMY2: 16;
    };
} AON_REG2X_SYS_TYPE;

/* 0x80C    0x4000_080c
    0       R/W AON_ACTIVE_CLK_EN                       1'b0
    1       R/W SRC_AON_ACTIVE_CLK_SEL                  1'b1
    2       R/W aon_loader_en                           1'b0
    3       R/W SWR_BY_CORE                             1'b0
    5:4     R/W PIN_CLK_OUT_SEL                         2'b1
    7:6     R/W REG3X_SYS_dummy2                        2'b1
    9:8     R/W rtc_in_sel                              2'b0
    10      R/W en_gpio_32k                             1'b0
    12:11   R/W REG3X_SYS_dummy3                        2'b0
    13      R   reg_aon_wdt_reset                       1'b0
    14      R/W TX_BIG_POUT                             1'b0
    16:15   R/W aonqcode_ph_pin_sel                     2'b0
    17      W1O REG_EN_CLK_REQ_FROM_IO                  1'b0
    31:18   R/W RSVD                                    14'b0
 */
typedef volatile union _AON_REG3X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_ACTIVE_CLK_EN: 1;
        uint32_t SRC_AON_ACTIVE_CLK_SEL: 1;
        uint32_t aon_loader_en: 1;
        uint32_t SWR_BY_CORE: 1;
        uint32_t PIN_CLK_OUT_SEL: 2;
        uint32_t REG3X_SYS_dummy2: 2;
        uint32_t rtc_in_sel: 2;
        uint32_t en_gpio_32k: 1;
        uint32_t REG3X_SYS_dummy3: 2;
        uint32_t reg_aon_wdt_reset: 1;
        uint32_t TX_BIG_POUT: 1;
        uint32_t aonqcode_ph_pin_sel: 2;
        uint32_t REG_EN_CLK_REQ_FROM_IO: 1;
        uint32_t RSVD: 14;
    };
} AON_REG3X_SYS_TYPE;

/* 0x810    0x4000_0810
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_REG4X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_REG4X_SYS_TYPE;

/* 0x814    0x4000_0814
    0       R/W SEL_32K_XTAL                            1'b0
    1       R/W SEL_32K_SDM                             1'b0
    3:2     R/W SEL_32K_dummy                           2'b0
    4       R/W SEL_32K_XTAL_sys                        1'b0
    5       R/W SEL_32K_SDM_sys                         1'b0
    7:6     R/W SEL_32K_sys_dummy                       2'b0
    8       R/W SEL_32K_XTAL_rtc                        1'b0
    9       R/W SEL_32K_SDM_rtc                         1'b0
    10      R/W SEL_32K_GPIO_rtc                        1'b0
    11      R/W SEL_32K_rtc_dummy                       1'b0
    12      R/W SEL_32K_XTAL_bt                         1'b0
    13      R/W SEL_32K_SDM_bt                          1'b0
    15:14   R/W SEL_32K_bt_dummy                        2'b0
    16      R/W SEL_32K_XTAL_wdg                        1'b0
    17      R/W SEL_32K_SDM_wdg                         1'b0
    19:18   R/W SEL_32K_wdt_dummy                       2'b0
    20      R/W SEL_32K_XTAL_qd                         1'b0
    21      R/W SEL_32K_SDM_qd                          1'b0
    23:22   R/W SEL_32K_qd_dummy                        2'b0
    24      R/W SEL_32K_XTAL_segcom                     1'b0
    25      R/W SEL_32K_SDM_segcom                      1'b0
    27:26   R/W SEL_32K_segcom_dummy                    2'b0
    28      R/W SEL_32K_XTAL_pf_rtc                     1'b0
    29      R/W SEL_32K_SDM_pf_rtc                      1'b0
    31:30   R   RSVD                                    2'b0
 */
typedef volatile union _AON_REG5X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t SEL_32K_XTAL: 1;
        uint32_t SEL_32K_SDM: 1;
        uint32_t SEL_32K_dummy: 2;
        uint32_t SEL_32K_XTAL_sys: 1;
        uint32_t SEL_32K_SDM_sys: 1;
        uint32_t SEL_32K_sys_dummy: 2;
        uint32_t SEL_32K_XTAL_rtc: 1;
        uint32_t SEL_32K_SDM_rtc: 1;
        uint32_t SEL_32K_GPIO_rtc: 1;
        uint32_t SEL_32K_rtc_dummy: 1;
        uint32_t SEL_32K_XTAL_bt: 1;
        uint32_t SEL_32K_SDM_bt: 1;
        uint32_t SEL_32K_bt_dummy: 2;
        uint32_t SEL_32K_XTAL_wdg: 1;
        uint32_t SEL_32K_SDM_wdg: 1;
        uint32_t SEL_32K_wdt_dummy: 2;
        uint32_t SEL_32K_XTAL_qd: 1;
        uint32_t SEL_32K_SDM_qd: 1;
        uint32_t SEL_32K_qd_dummy: 2;
        uint32_t SEL_32K_XTAL_segcom: 1;
        uint32_t SEL_32K_SDM_segcom: 1;
        uint32_t SEL_32K_segcom_dummy: 2;
        uint32_t SEL_32K_XTAL_pf_rtc: 1;
        uint32_t SEL_32K_SDM_pf_rtc: 1;
        uint32_t RSVD: 2;
    };
} AON_REG5X_SYS_TYPE;

/* 0x818    0x4000_0818
    0       R/W r_cpu_clk_dummy0                        1'b0
    1       R/W r_cpu_clk_dummy1                        1'b0
    2       R/W r_aon_cpu_pll_src_sel                   1'b0
    31:3    R   RSVD                                    29'b0
 */
typedef volatile union _AON_REG6X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_cpu_clk_dummy0: 1;
        uint32_t r_cpu_clk_dummy1: 1;
        uint32_t r_aon_cpu_pll_src_sel: 1;
        uint32_t RSVD: 29;
    };
} AON_REG6X_SYS_TYPE;

/* 0x81C    0x4000_081c
    0       R/W short_pulse_wkup_en                     1'b0
    1       W1C short_pulse_wkup_event_latch            1'b1
    3:2     R   RSVD                                    2'b0
    4       R/W USB_WKEN                                1'b0
    5       R/W USB_WKPOL                               1'b0
    6       R/W usb_wakeup_sel                          1'b1
    31:7    R   RSVD                                    25'b0
 */
typedef volatile union _AON_REG7X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t short_pulse_wkup_en: 1;
        uint32_t short_pulse_wkup_event_latch: 1;
        uint32_t RSVD_1: 2;
        uint32_t USB_WKEN: 1;
        uint32_t USB_WKPOL: 1;
        uint32_t usb_wakeup_sel: 1;
        uint32_t RSVD: 25;
    };
} AON_REG7X_SYS_TYPE;

/* 0x820    0x4000_0820
    0       W1C gpio_wkup_sts                           1'b1
    1       W1C rtc_wkup_sts                            1'b1
    2       W1C rtc_pf_wkup_sts                         1'b1
    3       W1C rif_wkup_sts                            1'b1
    4       W1C usb_wkup_sts                            1'b1
    5       W1C aonqd_wkup_sts                          1'b1
    6       W1C lpcomp0_wkup_sts                        1'b1
    31:7    R   RSVD                                    25'b0
 */
typedef volatile union _AON_REG8X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t gpio_wkup_sts: 1;
        uint32_t rtc_wkup_sts: 1;
        uint32_t rtc_pf_wkup_sts: 1;
        uint32_t rif_wkup_sts: 1;
        uint32_t usb_wkup_sts: 1;
        uint32_t aonqd_wkup_sts: 1;
        uint32_t lpcomp0_wkup_sts: 1;
        uint32_t RSVD: 25;
    };
} AON_REG8X_SYS_TYPE;

/* 0x824    0x4000_0824
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_REG9X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_REG9X_SYS_TYPE;

/* 0x828    0x4000_0828
    0       R/W reg_SCAN_MODE                           1'b0
    1       R/W PAD_BONDING_SHDN                        1'b1
    3:2     R   RSVD                                    2'b0
    4       R/W PAD_VDDIO_FLASH_E                       1'b0
    5       R/W PAD_VDDIO_FLASH_POW_VG1                 1'b0
    6       R/W PAD_VDDIO_FLASH_POW_VG2                 1'b0
    7       R/W PAD_VDDIO_PSRAM_E                       1'b0
    8       R/W PAD_VDDIO_PSRAM_POW_VG1                 1'b0
    9       R/W PAD_VDDIO_PSRAM_POW_VG2                 1'b0
    31:10   R   RSVD                                    22'b0
 */
typedef volatile union _AON_REG10X_SYS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_SCAN_MODE: 1;
        uint32_t PAD_BONDING_SHDN: 1;
        uint32_t RSVD_1: 2;
        uint32_t PAD_VDDIO_FLASH_E: 1;
        uint32_t PAD_VDDIO_FLASH_POW_VG1: 1;
        uint32_t PAD_VDDIO_FLASH_POW_VG2: 1;
        uint32_t PAD_VDDIO_PSRAM_E: 1;
        uint32_t PAD_VDDIO_PSRAM_POW_VG1: 1;
        uint32_t PAD_VDDIO_PSRAM_POW_VG2: 1;
        uint32_t RSVD: 22;
    };
} AON_REG10X_SYS_TYPE;

/* 0x82C    0x4000_082c
    0       R/W DIGI_Efuse_CK_L                         1'b0
    31:1    R   RSVD                                    31'b0
 */
typedef volatile union _AON_REG0X_EFUSE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DIGI_Efuse_CK_L: 1;
        uint32_t RSVD: 31;
    };
} AON_REG0X_EFUSE_TYPE;

/* 0x830    0x4000_0830
    4:0     R   XTAL_PDCK_LP                            5'd0
    5       R   XTAL_PDCK_OK                            1'b0
    6       R   XTAL_PDCK_BUSY                          1'b0
    7       R/W xtal_pdck_rslt_latch                    1'b0
    12:8    R   XPDCK_VREF_OUT                          5'b11111
    13      R   XPDCK_READY                             1'b0
    14      R   XPDCK_BUSY                              1'b0
    15      R   XTAL_PDCK_LP[5]                         1'b0
    16      R   XPDCK_VREF_OUT[5]                       1'b0
    31:17   R   RSVD                                    15'b0
 */
typedef volatile union _AON_REG0X_XPDCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_PDCK_LP: 5;
        uint32_t XTAL_PDCK_OK: 1;
        uint32_t XTAL_PDCK_BUSY: 1;
        uint32_t xtal_pdck_rslt_latch: 1;
        uint32_t XPDCK_VREF_OUT: 5;
        uint32_t XPDCK_READY: 1;
        uint32_t XPDCK_BUSY: 1;
        uint32_t XTAL_PDCK_LP_5: 1;
        uint32_t XPDCK_VREF_OUT_5: 1;
        uint32_t RSVD: 15;
    };
} AON_REG0X_XPDCK_TYPE;

/* 0x834    0x4000_0834
    0       R/W PWM_EN_POS                              1'b0
    1       R/W PWM_POS_RSTB                            1'b1
    9:2     R   RSVD                                    8'b0
    12:10   R/W PWM_PON_STEP_WAIT                       3'b0
    15:13   R/W PWM_PON_WAIT                            3'b0
    20:16   R/W PWM_PON_STEP                            5'b1
    25:21   R/W PWM_PON_START                           5'b0
    30:26   R/W PWM_PON_OVER                            5'b11111
    31      R   RSVD                                    1'h0
 */
typedef volatile union _AON_REG0X_PWM_POS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PWM_EN_POS: 1;
        uint32_t PWM_POS_RSTB: 1;
        uint32_t RSVD_1: 8;
        uint32_t PWM_PON_STEP_WAIT: 3;
        uint32_t PWM_PON_WAIT: 3;
        uint32_t PWM_PON_STEP: 5;
        uint32_t PWM_PON_START: 5;
        uint32_t PWM_PON_OVER: 5;
        uint32_t RSVD: 1;
    };
} AON_REG0X_PWM_POS_TYPE;

/* 0x838    0x4000_0838
    0       R/W PFM_EN_POS                              1'b0
    1       R/W PFM_POS_RSTB                            1'b1
    12:2    R   RSVD                                    11'b0
    15:13   R/W PFM_PON_STEP_WAIT                       3'b0
    19:16   R/W PFM_PON_STEP                            4'b1
    23:20   R/W PFM_PON_START                           4'b0
    27:24   R/W PFM_PON_OVER                            4'b1011
    30:28   R/W PFM_PON_WAIT                            3'b1
    31      R   RSVD                                    1'h0
 */
typedef volatile union _AON_REG0X_PFM_POS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PFM_EN_POS: 1;
        uint32_t PFM_POS_RSTB: 1;
        uint32_t RSVD_1: 11;
        uint32_t PFM_PON_STEP_WAIT: 3;
        uint32_t PFM_PON_STEP: 4;
        uint32_t PFM_PON_START: 4;
        uint32_t PFM_PON_OVER: 4;
        uint32_t PFM_PON_WAIT: 3;
        uint32_t RSVD: 1;
    };
} AON_REG0X_PFM_POS_TYPE;

/* 0x83C    0x4000_083c
    1:0     R   RSVD                                    2'b0
    11:2    R/W D300k_PFM_LOWER_BND                     10'b0000001010
    12      R/W D300k_EN_VDROP_DET                      1'b0
    13      R/W D300k_EN_32K_AUDIO                      1'b0
    14      R/W D300k_RSTB                              1'b0
    15      R/W D300k_SEL_NI_ON                         1'b0
    16      R/W D300k_REG_MANU_MODE_CCOT                1'b1
    22:17   R/W D300k_REG_MANU_CCOT                     6'b001000
    31:23   R   RSVD                                    9'b0
 */
typedef volatile union _AON_REG0X_300K_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_1: 2;
        uint32_t D300k_PFM_LOWER_BND: 10;
        uint32_t D300k_EN_VDROP_DET: 1;
        uint32_t D300k_EN_32K_AUDIO: 1;
        uint32_t D300k_RSTB: 1;
        uint32_t D300k_SEL_NI_ON: 1;
        uint32_t D300k_REG_MANU_MODE_CCOT: 1;
        uint32_t D300k_REG_MANU_CCOT: 6;
        uint32_t RSVD: 9;
    };
} AON_REG0X_300K_TYPE;

/* 0x840    0x4000_0840
    1:0     R/W D300k_PFM_COMP_SAMPLE_CYC               2'b0
    3:2     R/W D300k_SAMPLE_CYC                        2'b0
    9:4     R/W D300k_CCOT_FORCE                        6'b010000
    15:10   R/W D300k_CCOT_INIT                         6'b001000
    21:16   R   RSVD                                    6'b0
    31:22   R/W D300k_PFM_UPPER_BND                     10'b0000010100
 */
typedef volatile union _AON_REG1X_300K_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t D300k_PFM_COMP_SAMPLE_CYC: 2;
        uint32_t D300k_SAMPLE_CYC: 2;
        uint32_t D300k_CCOT_FORCE: 6;
        uint32_t D300k_CCOT_INIT: 6;
        uint32_t RSVD: 6;
        uint32_t D300k_PFM_UPPER_BND: 10;
    };
} AON_REG1X_300K_TYPE;

/* 0x844    0x4000_0844
    15:0    R   RO_AON_CNT_EXTRA_DELAY_PON_XTAL         16'h0
    22:16   R   RO_WK_REASON                            7'h0
    31:23   R   RSVD                                    9'h0
 */
typedef volatile union _AON_AON_READ_RG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RO_AON_CNT_EXTRA_DELAY_PON_XTAL: 16;
        uint32_t RO_WK_REASON: 7;
        uint32_t RSVD: 9;
    };
} AON_AON_READ_RG0X_TYPE;

/* 0x848    0x4000_0848
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG1X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG1X_TYPE;

/* 0x84C    0x4000_084c
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG2X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG2X_TYPE;

/* 0x850    0x4000_0850
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG3X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG3X_TYPE;

/* 0x854    0x4000_0854
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG4X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG4X_TYPE;

/* 0x858    0x4000_0858
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG5X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG5X_TYPE;

/* 0x85C    0x4000_085c
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG6X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG6X_TYPE;

/* 0x860    0x4000_0860
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG7X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG7X_TYPE;

/* 0x864    0x4000_0864
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG8X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG8X_TYPE;

/* 0x868    0x4000_0868
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG9X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG9X_TYPE;

/* 0x86C    0x4000_086c
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG10X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG10X_TYPE;

/* 0x870    0x4000_0870
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG11X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG11X_TYPE;

/* 0x874    0x4000_0874
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG12X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG12X_TYPE;

/* 0x878    0x4000_0878
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG13X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG13X_TYPE;

/* 0x87C    0x4000_087c
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG14X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG14X_TYPE;

/* 0x880    0x4000_0880
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG15X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG15X_TYPE;

/* 0x884    0x4000_0884
    31:0    R   RSVD                                    32'b0
 */
typedef volatile union _AON_AON_READ_RG16X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_AON_READ_RG16X_TYPE;

/* 0xAB0    0x4000_0ab0
    0       R/W LOP_PON_ENPC_DIGI                       1'b0
    1       R/W LOP_PON_PFM                             1'b0
    2       R/W LOP_PON_SWR                             1'b0
    3       R/W LOP_PON_POW_32KOSC                      1'b1
    4       R/W LOP_PON_ACTIVE_CLK_SEL                  1'b1
    5       R/W LOP_PON_XTAL                            1'b1
    6       R/W LOP_PON_POW_32KXTAL                     1'b0
    7       R/W LOP_PON_VDDIO_PSRAM_PC_EN               1'b1
    8       R/W LOP_PON_VDDIO_FLASH_PC_EN               1'b1
    9       R/W LOP_PON_ENPC_AON                        1'b1
    10      R/W LOP_PON_VDDIO_PC_CTRL                   1'b1
    11      R/W LOP_PON_PLL1                            1'b0
    12      R/W LOP_PON_PLL2                            1'b0
    18:13   R/W LOP_RG0_dummy1                          6'b011101
    21:19   R/W LOP_PON_XTAL_MODE                       3'b100
    22      R/W LOP_PON_PWM_EN_POS                      1'b1
    23      R/W LOP_PON_PFM_EN_POS                      1'b1
    24      R/W LOP_PON_OSC                             1'b1
    31:25   R   RSVD                                    7'h0
 */
typedef volatile union _AON_LOP_RG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_PON_ENPC_DIGI: 1;
        uint32_t LOP_PON_PFM: 1;
        uint32_t LOP_PON_SWR: 1;
        uint32_t LOP_PON_POW_32KOSC: 1;
        uint32_t LOP_PON_ACTIVE_CLK_SEL: 1;
        uint32_t LOP_PON_XTAL: 1;
        uint32_t LOP_PON_POW_32KXTAL: 1;
        uint32_t LOP_PON_VDDIO_PSRAM_PC_EN: 1;
        uint32_t LOP_PON_VDDIO_FLASH_PC_EN: 1;
        uint32_t LOP_PON_ENPC_AON: 1;
        uint32_t LOP_PON_VDDIO_PC_CTRL: 1;
        uint32_t LOP_PON_PLL1: 1;
        uint32_t LOP_PON_PLL2: 1;
        uint32_t LOP_RG0_dummy1: 6;
        uint32_t LOP_PON_XTAL_MODE: 3;
        uint32_t LOP_PON_PWM_EN_POS: 1;
        uint32_t LOP_PON_PFM_EN_POS: 1;
        uint32_t LOP_PON_OSC: 1;
        uint32_t RSVD: 7;
    };
} AON_LOP_RG0X_TYPE;

/* 0xAB4    0x4000_0ab4
    0       R/W LOP_PON_BUCK_PFM_IHALF                  1'b0
    1       R/W LOP_PON_BUCK_EN_OCP_IBON                1'b1
    5:2     R/W LOP_PON_BUCK_PFM_ICOMP                  4'b0010
    9:6     R/W LOP_PON_BUCK_PFM_ISCH                   4'b0010
    10      R/W LOP_PON_BUCK_ENOCPPS_H                  1'b0
    11      R/W LOP_PON_LDO_ENLDO311_IB20nA             1'b1
    14:12   R/W LOP_PON_MBIAS_VR_SEL_LDO311             3'b010
    15      R/W LOP_PON_BUCK_ENOCPPFM_H                 1'b1
    18:16   R/W LOP_PON_LDO_EN_DL_LDO311                3'b111
    20:19   R/W LOP_PON_BUCK_OCPRES_H                   2'b10
    21      R/W LOP_PON_BUCK_OCPSEL_H                   1'b1
    24:22   R/W LOP_PON_BUCK_VREFOCP_H                  3'b001
    25      R/W LOP_PON_BUCK_ENOFFSAWPFM_H              1'b1
    26      R/W LOP_PON_BUCK_PFM_COT_EN                 1'b0
    27      R/W LOP_PON_BUCK_PFM_AOT_EN                 1'b1
    29:28   R/W LOP_PON_IBSEL_TONCOMP                   2'b01
    30      R/W LOP_PON_LDO_POW_LDODIGI                 1'b1
    31      R/W LOP_PON_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN  1'b0
 */
typedef volatile union _AON_LOP_RG1X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_PON_BUCK_PFM_IHALF: 1;
        uint32_t LOP_PON_BUCK_EN_OCP_IBON: 1;
        uint32_t LOP_PON_BUCK_PFM_ICOMP: 4;
        uint32_t LOP_PON_BUCK_PFM_ISCH: 4;
        uint32_t LOP_PON_BUCK_ENOCPPS_H: 1;
        uint32_t LOP_PON_LDO_ENLDO311_IB20nA: 1;
        uint32_t LOP_PON_MBIAS_VR_SEL_LDO311: 3;
        uint32_t LOP_PON_BUCK_ENOCPPFM_H: 1;
        uint32_t LOP_PON_LDO_EN_DL_LDO311: 3;
        uint32_t LOP_PON_BUCK_OCPRES_H: 2;
        uint32_t LOP_PON_BUCK_OCPSEL_H: 1;
        uint32_t LOP_PON_BUCK_VREFOCP_H: 3;
        uint32_t LOP_PON_BUCK_ENOFFSAWPFM_H: 1;
        uint32_t LOP_PON_BUCK_PFM_COT_EN: 1;
        uint32_t LOP_PON_BUCK_PFM_AOT_EN: 1;
        uint32_t LOP_PON_IBSEL_TONCOMP: 2;
        uint32_t LOP_PON_LDO_POW_LDODIGI: 1;
        uint32_t LOP_PON_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN: 1;
    };
} AON_LOP_RG1X_TYPE;

/* 0xAB8    0x4000_0ab8
    0       R/W LOP_PON_BUCK_ENOCPS                     1'b1
    1       R/W LOP_PON_BUCK_POW_ZCD                    1'b1
    2       R/W LOP_PON_LDO_EN_DMYL_50U_LDODIGI         1'b0
    3       R/W LOP_PON_LDO_EN_DMYL_200U_LDODIGI        1'b0
    4       R/W LOP_PON_IB_500N_TONCOMP_EN              1'b1
    5       R/W LOP_PON_IB_500N_COTCOMP_EN              1'b1
    12:6    R/W LOP_PON_BUCK_ZCDOFFSET                  7'b0
    13      R/W LOP_PON_BUCK_POW_LowIq_ZCD              1'b0
    14      R/W LOP_PON_BUCK_STICKY_CODE_STATE1         1'b0
    15      R/W LOP_PON_BUCK_FORCE_CODE_STATE1          1'b0
    22:16   R   RSVD                                    7'b0
    23      R   RSVD                                    1'b0
    24      R/W LOP_PON_BUCK_STICKY_CODE_STATE2         1'b0
    25      R/W LOP_PON_BUCK_FORCE_CODE_STATE2          1'b0
    31:26   R/W LOP_PON_D300k_REG_MANU_CCOT             6'b001000
 */
typedef volatile union _AON_LOP_RG2X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_PON_BUCK_ENOCPS: 1;
        uint32_t LOP_PON_BUCK_POW_ZCD: 1;
        uint32_t LOP_PON_LDO_EN_DMYL_50U_LDODIGI: 1;
        uint32_t LOP_PON_LDO_EN_DMYL_200U_LDODIGI: 1;
        uint32_t LOP_PON_IB_500N_TONCOMP_EN: 1;
        uint32_t LOP_PON_IB_500N_COTCOMP_EN: 1;
        uint32_t LOP_PON_BUCK_ZCDOFFSET: 7;
        uint32_t LOP_PON_BUCK_POW_LowIq_ZCD: 1;
        uint32_t LOP_PON_BUCK_STICKY_CODE_STATE1: 1;
        uint32_t LOP_PON_BUCK_FORCE_CODE_STATE1: 1;
        uint32_t RSVD_1: 7;
        uint32_t RSVD: 1;
        uint32_t LOP_PON_BUCK_STICKY_CODE_STATE2: 1;
        uint32_t LOP_PON_BUCK_FORCE_CODE_STATE2: 1;
        uint32_t LOP_PON_D300k_REG_MANU_CCOT: 6;
    };
} AON_LOP_RG2X_TYPE;

/* 0xABC    0x4000_0abc
    0       R   RSVD                                    1'b0
    1       R/W LOP_POF_ENPC_DIGI                       1'b1
    2       R/W LOP_POF_POWLDO_DIGI                     1'b1
    3       R/W LOP_POF_ENPC_CORE                       1'b0
    4       R/W LOP_POF_POW_BIAS                        1'b0
    5       R/W LOP_POF_POW_32KOSC                      1'b1
    6       R/W LOP_POF_POW_32KXTAL                     1'b0
    8:7     R/W LOP_POF_SWR_CFG                         2'b0
    9       R/W LOP_POF_ENPC_AON                        1'b0
    15:10   R   RSVD                                    6'b0
    16      R/W LOP_POF_VDDIO_PSRAM_PC_EN               1'b1
    17      R/W LOP_POF_VDDIO_FLASH_PC_EN               1'b1
    18      R/W LOP_POF_XTAL                            1'b0
    19      R/W LOP_POF_AON_GATED_EN                    1'b0
    20      R/W LOP_POF_CAL                             1'b1
    23:21   R   RSVD                                    3'b0
    26:24   R/W LOP_POF_XTAL_MODE                       3'b100
    31:27   R   RSVD                                    5'b0
 */
typedef volatile union _AON_LOP_RG3X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_3: 1;
        uint32_t LOP_POF_ENPC_DIGI: 1;
        uint32_t LOP_POF_POWLDO_DIGI: 1;
        uint32_t LOP_POF_ENPC_CORE: 1;
        uint32_t LOP_POF_POW_BIAS: 1;
        uint32_t LOP_POF_POW_32KOSC: 1;
        uint32_t LOP_POF_POW_32KXTAL: 1;
        uint32_t LOP_POF_SWR_CFG: 2;
        uint32_t LOP_POF_ENPC_AON: 1;
        uint32_t RSVD_2: 6;
        uint32_t LOP_POF_VDDIO_PSRAM_PC_EN: 1;
        uint32_t LOP_POF_VDDIO_FLASH_PC_EN: 1;
        uint32_t LOP_POF_XTAL: 1;
        uint32_t LOP_POF_AON_GATED_EN: 1;
        uint32_t LOP_POF_CAL: 1;
        uint32_t RSVD_1: 3;
        uint32_t LOP_POF_XTAL_MODE: 3;
        uint32_t RSVD: 5;
    };
} AON_LOP_RG3X_TYPE;

/* 0xAC0    0x4000_0ac0
    0       R/W LOP_POF_BUCK_PFM_IHALF                  1'b1
    1       R/W LOP_POF_BUCK_EN_OCP_IBON                1'b0
    5:2     R/W LOP_POF_BUCK_PFM_ICOMP                  4'b0010
    9:6     R/W LOP_POF_BUCK_PFM_ISCH                   4'b0010
    10      R/W LOP_POF_BUCK_ENOCPPS_H                  1'b1
    11      R/W LOP_POF_LDO_ENLDO311_IB20nA             1'b1
    14:12   R   RSVD                                    3'b0
    15      R/W LOP_POF_BUCK_ENOCPPFM_H                 1'b1
    18:16   R/W LOP_POF_LDO_EN_DL_LDO311                3'b111
    20:19   R/W LOP_POF_BUCK_OCPRES_H                   2'b01
    21      R/W LOP_POF_BUCK_OCPSEL_H                   1'b1
    24:22   R/W LOP_POF_BUCK_VREFOCP_H                  3'b110
    25      R/W LOP_POF_BUCK_ENOFFSAWPFM_H              1'b1
    26      R/W LOP_POF_BUCK_PFM_COT_EN                 1'b0
    27      R/W LOP_POF_BUCK_PFM_AOT_EN                 1'b0
    29:28   R/W LOP_POF_IBSEL_TONCOMP                   2'b00
    30      R/W LOP_POF_MBIAS_POW_EBIAS_AUXADC          1'b1
    31      R/W LOP_POF_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN  1'b1
 */
typedef volatile union _AON_LOP_RG4X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_POF_BUCK_PFM_IHALF: 1;
        uint32_t LOP_POF_BUCK_EN_OCP_IBON: 1;
        uint32_t LOP_POF_BUCK_PFM_ICOMP: 4;
        uint32_t LOP_POF_BUCK_PFM_ISCH: 4;
        uint32_t LOP_POF_BUCK_ENOCPPS_H: 1;
        uint32_t LOP_POF_LDO_ENLDO311_IB20nA: 1;
        uint32_t RSVD: 3;
        uint32_t LOP_POF_BUCK_ENOCPPFM_H: 1;
        uint32_t LOP_POF_LDO_EN_DL_LDO311: 3;
        uint32_t LOP_POF_BUCK_OCPRES_H: 2;
        uint32_t LOP_POF_BUCK_OCPSEL_H: 1;
        uint32_t LOP_POF_BUCK_VREFOCP_H: 3;
        uint32_t LOP_POF_BUCK_ENOFFSAWPFM_H: 1;
        uint32_t LOP_POF_BUCK_PFM_COT_EN: 1;
        uint32_t LOP_POF_BUCK_PFM_AOT_EN: 1;
        uint32_t LOP_POF_IBSEL_TONCOMP: 2;
        uint32_t LOP_POF_MBIAS_POW_EBIAS_AUXADC: 1;
        uint32_t LOP_POF_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN: 1;
    };
} AON_LOP_RG4X_TYPE;

/* 0xAC4    0x4000_0ac4
    0       R/W LOP_POF_BUCK_ENOCPS                     1'b1
    1       R/W LOP_POF_BUCK_POW_ZCD                    1'b1
    2       R/W LOP_POF_LDO_EN_DMYL_50U_LDODIGI         1'b0
    3       R/W LOP_POF_LDO_EN_DMYL_200U_LDODIGI        1'b0
    4       R/W LOP_POF_IB_500N_TONCOMP_EN              1'b0
    5       R/W LOP_POF_IB_500N_COTCOMP_EN              1'b0
    12:6    R/W LOP_POF_BUCK_ZCDOFFSET                  7'b0
    13      R/W LOP_POF_BUCK_POW_LowIq_ZCD              1'b0
    14      R/W LOP_POF_BUCK_STICKY_CODE_STATE1         1'b0
    15      R/W LOP_POF_BUCK_FORCE_CODE_STATE1          1'b0
    22:16   R   RSVD                                    7'b0
    23      R   RSVD                                    1'b0
    24      R/W LOP_POF_BUCK_STICKY_CODE_STATE2         1'b0
    25      R/W LOP_POF_BUCK_FORCE_CODE_STATE2          1'b0
    31:26   R/W LOP_POF_D300k_REG_MANU_CCOT             6'b001000
 */
typedef volatile union _AON_LOP_RG5X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_POF_BUCK_ENOCPS: 1;
        uint32_t LOP_POF_BUCK_POW_ZCD: 1;
        uint32_t LOP_POF_LDO_EN_DMYL_50U_LDODIGI: 1;
        uint32_t LOP_POF_LDO_EN_DMYL_200U_LDODIGI: 1;
        uint32_t LOP_POF_IB_500N_TONCOMP_EN: 1;
        uint32_t LOP_POF_IB_500N_COTCOMP_EN: 1;
        uint32_t LOP_POF_BUCK_ZCDOFFSET: 7;
        uint32_t LOP_POF_BUCK_POW_LowIq_ZCD: 1;
        uint32_t LOP_POF_BUCK_STICKY_CODE_STATE1: 1;
        uint32_t LOP_POF_BUCK_FORCE_CODE_STATE1: 1;
        uint32_t RSVD_1: 7;
        uint32_t RSVD: 1;
        uint32_t LOP_POF_BUCK_STICKY_CODE_STATE2: 1;
        uint32_t LOP_POF_BUCK_FORCE_CODE_STATE2: 1;
        uint32_t LOP_POF_D300k_REG_MANU_CCOT: 6;
    };
} AON_LOP_RG5X_TYPE;

/* 0xAC8    0x4000_0ac8
    0       R/W LOP_LPS_TIMER_WAKEUP                    1'b0
    1       R/W LOP_RFC_RET                             1'b0
    2       R/W LOP_MODEM_RET                           1'b0
    3       R/W LOP_BZ_RET                              1'b0
    4       R/W LOP_BLE_RET                             1'b0
    5       R/W LOP_PF_RET                              1'b0
    6       R/W LOP_DP_MODEM_RET                        1'b0
    7       R/W LOP_ZB_RET                              1'b0
    31:8    R   RSVD                                    24'h0
 */
typedef volatile union _AON_LOP_RG6X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_LPS_TIMER_WAKEUP: 1;
        uint32_t LOP_RFC_RET: 1;
        uint32_t LOP_MODEM_RET: 1;
        uint32_t LOP_BZ_RET: 1;
        uint32_t LOP_BLE_RET: 1;
        uint32_t LOP_PF_RET: 1;
        uint32_t LOP_DP_MODEM_RET: 1;
        uint32_t LOP_ZB_RET: 1;
        uint32_t RSVD: 24;
    };
} AON_LOP_RG6X_TYPE;

/* 0xACC    0x4000_0acc
    5:0     R/W LOP_BIAS_delay                          6'h30
    11:6    R/W LOP_LDO_delay                           6'h30
    15:12   R/W LOP_PLL_delay                           4'h3
    23:16   R/W LOP_SWR_delay                           8'hc0
    31:24   R/W LOP_XTAL_delay                          8'hc0
 */
typedef volatile union _AON_LOP_RG7X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_BIAS_delay: 6;
        uint32_t LOP_LDO_delay: 6;
        uint32_t LOP_PLL_delay: 4;
        uint32_t LOP_SWR_delay: 8;
        uint32_t LOP_XTAL_delay: 8;
    };
} AON_LOP_RG7X_TYPE;

/* 0xAD0    0x4000_0ad0
    5:0     R/W LOP_ENPC_CORE_BIG_delay                 6'h20
    11:6    R/W LOP_ENPC_CORE_SMALL_delay               6'h20
    15:12   R/W LOP_RG8X_Dummy_0                        4'h3
    23:16   R/W LOP_VDDIO_PC_VG2_delay                  8'hc0
    31:24   R/W LOP_VDDIO_PC_VG1_delay                  8'hc0
 */
typedef volatile union _AON_LOP_RG8X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_ENPC_CORE_BIG_delay: 6;
        uint32_t LOP_ENPC_CORE_SMALL_delay: 6;
        uint32_t LOP_RG8X_Dummy_0: 4;
        uint32_t LOP_VDDIO_PC_VG2_delay: 8;
        uint32_t LOP_VDDIO_PC_VG1_delay: 8;
    };
} AON_LOP_RG8X_TYPE;

/* 0xAD4    0x4000_0ad4
    4:0     R/W LOP_PON_VDIGI_TUNE_STATE1               5'b10000
    9:5     R/W LOP_PON_VDIGI_TUNE_STATE2               5'b10100
    14:10   R/W LOP_PON_VDIGI_TUNE_STATE3               5'b10100
    15      R   RSVD                                    1'b0
    31:16   R   RSVD                                    16'h0
 */
typedef volatile union _AON_LOP_RG9X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_PON_VDIGI_TUNE_STATE1: 5;
        uint32_t LOP_PON_VDIGI_TUNE_STATE2: 5;
        uint32_t LOP_PON_VDIGI_TUNE_STATE3: 5;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 16;
    };
} AON_LOP_RG9X_TYPE;

/* 0xAD8    0x4000_0ad8
    4:0     R/W LOP_POF_VDIGI_TUNE_STATE1               5'b10100
    9:5     R/W LOP_POF_VDIGI_TUNE_STATE2               5'b10000
    12:10   R/W LOP_POF_MBIAS_VR_SEL_LDO311_STATE1      3'b101
    15:13   R/W LOP_POF_MBIAS_VR_SEL_LDO311_STATE2      3'b010
    20:16   R/W LOP_VAON2VPON_PC_OFF_delay              5'h0f
    31:21   R   RSVD                                    11'h0
 */
typedef volatile union _AON_LOP_RG10X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LOP_POF_VDIGI_TUNE_STATE1: 5;
        uint32_t LOP_POF_VDIGI_TUNE_STATE2: 5;
        uint32_t LOP_POF_MBIAS_VR_SEL_LDO311_STATE1: 3;
        uint32_t LOP_POF_MBIAS_VR_SEL_LDO311_STATE2: 3;
        uint32_t LOP_VAON2VPON_PC_OFF_delay: 5;
        uint32_t RSVD: 11;
    };
} AON_LOP_RG10X_TYPE;

/* 0xC00    0x4000_0c00
    5:0     R   MBIAS_REG0X_SD_TUNE_RO                  6'b0
    15:6    R/W MBIAS_REG0X_DUMMY1                      10'b1010101010
    18:16   R/W MBIAS_LPBG_VR1200                       3'b100
    21:19   R/W MBIAS_LPBG_R2                           3'b100
    24:22   R/W MBIAS_BG_BG_R1                          3'b100
    25      R/W MBIAS_POW_EBIAS_AUXADC                  1'b1
    28:26   R/W MBIAS_VR_SEL_LDO311                     3'b010
    30:29   R/W MBIAS_REG1X_DUMMY2                      2'b0
    31      R/W MBIAS_REG1X_DUMMY1                      1'b1
 */
typedef volatile union _AON_REG0X_MBIAS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MBIAS_REG0X_SD_TUNE_RO: 6;
        uint32_t MBIAS_REG0X_DUMMY1: 10;
        uint32_t MBIAS_LPBG_VR1200: 3;
        uint32_t MBIAS_LPBG_R2: 3;
        uint32_t MBIAS_BG_BG_R1: 3;
        uint32_t MBIAS_POW_EBIAS_AUXADC: 1;
        uint32_t MBIAS_VR_SEL_LDO311: 3;
        uint32_t MBIAS_REG1X_DUMMY2: 2;
        uint32_t MBIAS_REG1X_DUMMY1: 1;
    };
} AON_REG0X_MBIAS_TYPE;

/* 0xC04    0x4000_0c04
    2:0     R/W MBIAS_REG2X_DUMMY1                      3'b101
    6:3     R/W MBIAS_VR_SEL_LDORET                     4'b1100
    9:7     R/W MBIAS_BG_VREF_SEL_L                     3'b100
    12:10   R/W MBIAS_BG_VREF_SEL_H                     3'b100
    13      R/W MBIAS_BG_Efuse_Data_H                   1'b0
    14      R/W MBIAS_BG_DIGI_RST_H                     1'b0
    15      R/W MBIAS_REG2X_DUMMY2                      1'b1
    31:16   R   RSVD                                    16'b1111111100000000
 */
typedef volatile union _AON_REG2X_MBIAS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MBIAS_REG2X_DUMMY1: 3;
        uint32_t MBIAS_VR_SEL_LDORET: 4;
        uint32_t MBIAS_BG_VREF_SEL_L: 3;
        uint32_t MBIAS_BG_VREF_SEL_H: 3;
        uint32_t MBIAS_BG_Efuse_Data_H: 1;
        uint32_t MBIAS_BG_DIGI_RST_H: 1;
        uint32_t MBIAS_REG2X_DUMMY2: 1;
        uint32_t RSVD: 16;
    };
} AON_REG2X_MBIAS_TYPE;

/* 0xC08    0x4000_0c08
    0       R   MBIAS_Q1_Efuse                          1'b0
    1       R   MBIAS_Q2_Efuse                          1'b0
    2       R   MBIAS_CKOUT0X_DUMMY2                    1'b0
    3       R   MBIAS_CKOUT0X_DUMMY3                    1'b0
    4       R   MBIAS_CKOUT0X_DUMMY4                    1'b0
    5       R   MBIAS_CKOUT0X_DUMMY5                    1'b0
    6       R   MBIAS_CKOUT0X_DUMMY6                    1'b0
    7       R   MBIAS_CKOUT0X_DUMMY7                    1'b0
    8       R   MBIAS_CKOUT0X_DUMMY8                    1'b0
    9       R   MBIAS_CKOUT0X_DUMMY9                    1'b0
    10      R   MBIAS_CKOUT0X_DUMMY10                   1'b0
    11      R   MBIAS_CKOUT0X_DUMMY11                   1'b0
    12      R   MBIAS_CKOUT0X_DUMMY12                   1'b0
    13      R   MBIAS_CKOUT0X_DUMMY13                   1'b0
    14      R   MBIAS_BGOK_L                            1'b0
    15      R   MBIAS_PORB_LDO311_L                     1'b0
    31:16   R   MBIAS_CKOUT0X_DUMMY14                   16'b0
 */
typedef volatile union _AON_C_KOUT0X_MBIAS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MBIAS_Q1_Efuse: 1;
        uint32_t MBIAS_Q2_Efuse: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY2: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY3: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY4: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY5: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY6: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY7: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY8: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY9: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY10: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY11: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY12: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY13: 1;
        uint32_t MBIAS_BGOK_L: 1;
        uint32_t MBIAS_PORB_LDO311_L: 1;
        uint32_t MBIAS_CKOUT0X_DUMMY14: 16;
    };
} AON_C_KOUT0X_MBIAS_TYPE;

/* 0xC10    0x4000_0c10
    0       R/W LDO_REG0X_DUMMY1                        1'b0
    1       R/W LDO_ENPC_LDODIGI                        1'b0
    2       R/W LDO_POW_LDODIGI                         1'b1
    5:3     R/W LDO_EN_DL_LDO311                        3'b000
    7:6     R/W LDO_REG0X_DUMMY0                        2'b01
    8       R/W LDO_ENLDO311_IB20nA                     1'b0
    13:9    R/W LDO_TUNE_LDODIGI                        5'b10100
    14      R/W LDO_EN_DMYL_50U_LDODIGI                 1'b0
    15      R/W LDO_EN_DMYL_200U_LDODIGI                1'b0
    17:16   R/W LDO_REG1X_DUMMY1                        2'b11
    18      R/W LDO_ENPC_CORE_SMALL                     1'b0
    19      R/W LDO_ENPC_CORE_BIG                       1'b0
    21:20   R/W LDO_REG1X_DUMMY1                        2'b01
    22      R/W LDO_POW_LDODIGI_FB                      1'b0
    24:23   R/W LDO_COMPTUNE_LDORET                     2'b11
    30:25   R/W LDO_REG1X_DUMMY2                        6'b011111
    31      R/W LDO_POW_LDORET                          1'b1
 */
typedef volatile union _AON_REG0X_LDO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LDO_REG0X_DUMMY1: 1;
        uint32_t LDO_ENPC_LDODIGI: 1;
        uint32_t LDO_POW_LDODIGI: 1;
        uint32_t LDO_EN_DL_LDO311: 3;
        uint32_t LDO_REG0X_DUMMY0: 2;
        uint32_t LDO_ENLDO311_IB20nA: 1;
        uint32_t LDO_TUNE_LDODIGI: 5;
        uint32_t LDO_EN_DMYL_50U_LDODIGI: 1;
        uint32_t LDO_EN_DMYL_200U_LDODIGI: 1;
        uint32_t LDO_REG1X_DUMMY1_1: 2;
        uint32_t LDO_ENPC_CORE_SMALL: 1;
        uint32_t LDO_ENPC_CORE_BIG: 1;
        uint32_t LDO_REG1X_DUMMY1: 2;
        uint32_t LDO_POW_LDODIGI_FB: 1;
        uint32_t LDO_COMPTUNE_LDORET: 2;
        uint32_t LDO_REG1X_DUMMY2: 6;
        uint32_t LDO_POW_LDORET: 1;
    };
} AON_REG0X_LDO_TYPE;

/* 0xC14    0x4000_0c14
    0       R/W LDO_POW_EFUSE                           1'b0
    1       R/W LDO_POW_EFUSE_DL_PC1                    1'b0
    2       R/W LDO_POW_EFUSE_DL_PC2                    1'b0
    3       R/W LDO_POW_EFUSE_PC1                       1'b0
    4       R/W LDO_POW_EFUSE_PC2                       1'b0
    5       R/W LDO_PCUT_EHVT_VCORE                     1'b0
    6       R/W LDO_PCUT_EHVT_DVDD                      1'b1
    7       R/W LDO_PCUT_VPONSEGLCD                     1'b0
    8       R/W LDO_PCUT_VAONVDIGUSB                    1'b1
    14:9    R/W LDO_REG2X_DUMMY1                        6'b111010
    15      R/W LDO_ENPC_VPONVAON                       1'b1
    18:16   R/W LDO_EFUSE_CSET                          3'b100
    21:19   R/W LDO_EFUSE_ISET                          3'b100
    24:22   R/W LDO_EFUSE_RSET                          3'b100
    31:25   R/W LDO_EFUSE_TUNE                          7'b0111010
 */
typedef volatile union _AON_REG2X_LDO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LDO_POW_EFUSE: 1;
        uint32_t LDO_POW_EFUSE_DL_PC1: 1;
        uint32_t LDO_POW_EFUSE_DL_PC2: 1;
        uint32_t LDO_POW_EFUSE_PC1: 1;
        uint32_t LDO_POW_EFUSE_PC2: 1;
        uint32_t LDO_PCUT_EHVT_VCORE: 1;
        uint32_t LDO_PCUT_EHVT_DVDD: 1;
        uint32_t LDO_PCUT_VPONSEGLCD: 1;
        uint32_t LDO_PCUT_VAONVDIGUSB: 1;
        uint32_t LDO_REG2X_DUMMY1: 6;
        uint32_t LDO_ENPC_VPONVAON: 1;
        uint32_t LDO_EFUSE_CSET: 3;
        uint32_t LDO_EFUSE_ISET: 3;
        uint32_t LDO_EFUSE_RSET: 3;
        uint32_t LDO_EFUSE_TUNE: 7;
    };
} AON_REG2X_LDO_TYPE;

/* 0xC18    0x4000_0c18
    0       R/W LCD_REG0X_DUMMY1                        1'b0
    1       R/W LCD_EN_LCD                              1'b0
    2       R/W LCD_BIAS_SEL                            1'b0
    3       R   LCD_EN_RES_L                            1'b1
    13:4    R/W LCD_REG0X_DUMMY2                        10'b0101010101
    14      R/W CKOUT_EN_DEBUG                          1'b1
    15      R/W LCD_REG0X_DUMMY3                        1'b0
    31:16   R   RSVD                                    16'b1010101010101010
 */
typedef volatile union _AON_REG0X_LCD_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LCD_REG0X_DUMMY1: 1;
        uint32_t LCD_EN_LCD: 1;
        uint32_t LCD_BIAS_SEL: 1;
        uint32_t LCD_EN_RES_L: 1;
        uint32_t LCD_REG0X_DUMMY2: 10;
        uint32_t CKOUT_EN_DEBUG: 1;
        uint32_t LCD_REG0X_DUMMY3: 1;
        uint32_t RSVD: 16;
    };
} AON_REG0X_LCD_TYPE;

/* 0xC20    0x4000_0c20
    5:0     R/W BUCK_SWRTUNE_H                          6'b011101
    6       R/W BUCK_ADD_SAW_CURRENT                    1'b1
    7       R/W BUCK_OCFB_SEL_H                         1'b0
    9:8     R/W BUCK_R3_H                               2'b01
    11:10   R/W BUCK_R2_H                               2'b01
    13:12   R/W BUCK_R1_H                               2'b01
    15:14   R/W BUCK_C3_H                               2'b01
    17:16   R/W BUCK_C2_H                               2'b01
    19:18   R/W BUCK_C1_H                               2'b01
    20      R/W BUCK_BPSSR_H                            1'b1
    21      R/W BUCK_ENSR_H                             1'b1
    22      R/W BUCK_PFM_COT_EN                         1'b0
    23      R/W BUCK_PFM_AOT_EN                         1'b1
    29:24   R/W BUCK_LDOTUNE_H                          6'b011101
    31:30   R/W BUCK_NONOVERLAP_SDZ_H                   2'b01
 */
typedef volatile union _AON_REG0X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_SWRTUNE_H: 6;
        uint32_t BUCK_ADD_SAW_CURRENT: 1;
        uint32_t BUCK_OCFB_SEL_H: 1;
        uint32_t BUCK_R3_H: 2;
        uint32_t BUCK_R2_H: 2;
        uint32_t BUCK_R1_H: 2;
        uint32_t BUCK_C3_H: 2;
        uint32_t BUCK_C2_H: 2;
        uint32_t BUCK_C1_H: 2;
        uint32_t BUCK_BPSSR_H: 1;
        uint32_t BUCK_ENSR_H: 1;
        uint32_t BUCK_PFM_COT_EN: 1;
        uint32_t BUCK_PFM_AOT_EN: 1;
        uint32_t BUCK_LDOTUNE_H: 6;
        uint32_t BUCK_NONOVERLAP_SDZ_H: 2;
    };
} AON_REG0X_BUCK_TYPE;

/* 0xC24    0x4000_0c24
    0       R   BUCK_SS_OVER_H                          1'b1
    1       R   BUCK_SS_START_H                         1'b1
    5:2     R   BUCK_VREFPFM_H                          4'b1011
    6       R/W BUCK_IB_500N_TONCOMP_EN                 1'b1
    7       R/W BUCK_IB_500N_COTCOMP_EN                 1'b1
    11:8    R/W BUCK_PFM_ICOMP                          4'b0010
    12      R/W BUCK_ENPFMDIV_H                         1'b0
    13      R/W BUCK_PFM_IHALF                          1'b0
    14      R/W BUCK_ICOT2X                             1'b1
    15      R/W BUCK_VR_COT_SET                         1'b0
    19:16   R/W BUCK_PFM_ISCH                           4'b0010
    21:20   R/W BUCK_ClampH_VCH_SEL                     2'b01
    22      R/W BUCK_EN_WaitSampleOver                  1'b1
    23      R/W BUCK_EN_ForceOFFtoZCD                   1'b1
    24      R/W BUCK_PFM_SEL                            1'b0
    25      R/W BUCK_EN_OCPrst_sel                      1'b0
    26      R/W BUCK_EN_MinON_RAMP                      1'b1
    27      R/W BUCK_PFM_COMP_SEL                       1'b1
    28      R/W BUCK_REG3X_DUMMY1                       1'b1
    29      R/W BUCK_ENOCPPS_H                          1'b0
    31:30   R/W BUCK_ClampL_RTUNE                       2'b10
 */
typedef volatile union _AON_REG2X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_SS_OVER_H: 1;
        uint32_t BUCK_SS_START_H: 1;
        uint32_t BUCK_VREFPFM_H: 4;
        uint32_t BUCK_IB_500N_TONCOMP_EN: 1;
        uint32_t BUCK_IB_500N_COTCOMP_EN: 1;
        uint32_t BUCK_PFM_ICOMP: 4;
        uint32_t BUCK_ENPFMDIV_H: 1;
        uint32_t BUCK_PFM_IHALF: 1;
        uint32_t BUCK_ICOT2X: 1;
        uint32_t BUCK_VR_COT_SET: 1;
        uint32_t BUCK_PFM_ISCH: 4;
        uint32_t BUCK_ClampH_VCH_SEL: 2;
        uint32_t BUCK_EN_WaitSampleOver: 1;
        uint32_t BUCK_EN_ForceOFFtoZCD: 1;
        uint32_t BUCK_PFM_SEL: 1;
        uint32_t BUCK_EN_OCPrst_sel: 1;
        uint32_t BUCK_EN_MinON_RAMP: 1;
        uint32_t BUCK_PFM_COMP_SEL: 1;
        uint32_t BUCK_REG3X_DUMMY1: 1;
        uint32_t BUCK_ENOCPPS_H: 1;
        uint32_t BUCK_ClampL_RTUNE: 2;
    };
} AON_REG2X_BUCK_TYPE;

/* 0xC28    0x4000_0c28
    3:0     R/W BUCK_SAW_FREQ                           4'b1000
    4       R/W BUCK_SAW_VALID                          1'b0
    5       R/W BUCK_SAWCTL_H                           1'b1
    6       R/W BUCK_ENOFFSAWPFM_H                      1'b1
    7       R/W BUCK_ENOFFSAWLDO_H                      1'b1
    10:8    R/W BUCK_VREFOCP_H                          3'b001
    11      R/W BUCK_OCPSEL_H                           1'b1
    13:12   R/W BUCK_OCPRES_H                           2'b10
    14      R/W BUCK_ENOCPPFM_H                         1'b1
    15      R/W BUCK_ENOCPPWM_H                         1'b1
    16      R/W BUCK_BP_MiniON_RAMPdelay                1'b0
    19:17   R/W BUCK_OFFT_H                             3'b100
    24:20   R   BUCK_VREFPWMSS_H                        5'b00000
    25      R/W BUCK_FPWMANA_H                          1'b1
    26      R/W BUCK_ENFPWMDELAY_H                      1'b1
    27      R/W BUCK_TYPE3_H                            1'b1
    29:28   R/W BUCK_FPWMCTL_H                          2'b00
    30      R/W BUCK_ENOCPMUX_H                         1'b0
    31      R/W BUCK_ENVREFSS_H                         1'b1
 */
typedef volatile union _AON_REG4X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_SAW_FREQ: 4;
        uint32_t BUCK_SAW_VALID: 1;
        uint32_t BUCK_SAWCTL_H: 1;
        uint32_t BUCK_ENOFFSAWPFM_H: 1;
        uint32_t BUCK_ENOFFSAWLDO_H: 1;
        uint32_t BUCK_VREFOCP_H: 3;
        uint32_t BUCK_OCPSEL_H: 1;
        uint32_t BUCK_OCPRES_H: 2;
        uint32_t BUCK_ENOCPPFM_H: 1;
        uint32_t BUCK_ENOCPPWM_H: 1;
        uint32_t BUCK_BP_MiniON_RAMPdelay: 1;
        uint32_t BUCK_OFFT_H: 3;
        uint32_t BUCK_VREFPWMSS_H: 5;
        uint32_t BUCK_FPWMANA_H: 1;
        uint32_t BUCK_ENFPWMDELAY_H: 1;
        uint32_t BUCK_TYPE3_H: 1;
        uint32_t BUCK_FPWMCTL_H: 2;
        uint32_t BUCK_ENOCPMUX_H: 1;
        uint32_t BUCK_ENVREFSS_H: 1;
    };
} AON_REG4X_BUCK_TYPE;

/* 0xC2C    0x4000_0c2c
    0       R/W BUCK_EN_MinON                           1'b1
    1       R/W BUCK_ENOCPS                             1'b1
    7:2     R   BUCK_CCOT_H                             6'b001000
    8       R/W BUCK_POW_CLAMP_H                        1'b0
    9       R/W BUCK_POW_EA_Initial                     1'b1
    10      R/W BUCK_ENLDO15_LXFB                       1'b0
    13:11   R/W BUCK_VREFPWM_H                          3'b011
    14      R/W BUCK_PMOS_DRIL_H                        1'b1
    15      R/W BUCK_PMOS_DRIH_H                        1'b1
    16      R/W BUCK_ZCD_NIZCD_SEL                      1'b0
    17      R/W BUCK_ZCD_NI_delay_SEL                   1'b0
    18      R/W BUCK_ZCD_NI_SEL                         1'b0
    19      R/W BUCK_OCPrst_ext                         1'b0
    20      R/W BUCK_LDO_OCP_ENB                        1'b0
    21      R/W BUCK_CK_PWM_SEL                         1'b0
    22      R/W BUCK_EN_R1OFF_H                         1'b0
    23      R/W BUCK_POW_EA_IqEhance_H                  1'b0
    24      R/W BUCK_POW_EA_Iqx3_H                      1'b0
    25      R/W BUCK_POW_EA_Iqx2_H                      1'b0
    26      R/W BUCK_EN_PDMC_H                          1'b0
    27      R/W BUCK_EN_IMIRROR_IPTAT_Gating            1'b0
    28      R/W BUCK_FPWM_H                             1'b0
    29      R/W BUCK_ENLDO_H                            1'b0
    30      R/W BUCK_ENSWR_H                            1'b0
    31      R/W BUCK_ENBIAS_H                           1'b0
 */
typedef volatile union _AON_REG6X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_EN_MinON: 1;
        uint32_t BUCK_ENOCPS: 1;
        uint32_t BUCK_CCOT_H: 6;
        uint32_t BUCK_POW_CLAMP_H: 1;
        uint32_t BUCK_POW_EA_Initial: 1;
        uint32_t BUCK_ENLDO15_LXFB: 1;
        uint32_t BUCK_VREFPWM_H: 3;
        uint32_t BUCK_PMOS_DRIL_H: 1;
        uint32_t BUCK_PMOS_DRIH_H: 1;
        uint32_t BUCK_ZCD_NIZCD_SEL: 1;
        uint32_t BUCK_ZCD_NI_delay_SEL: 1;
        uint32_t BUCK_ZCD_NI_SEL: 1;
        uint32_t BUCK_OCPrst_ext: 1;
        uint32_t BUCK_LDO_OCP_ENB: 1;
        uint32_t BUCK_CK_PWM_SEL: 1;
        uint32_t BUCK_EN_R1OFF_H: 1;
        uint32_t BUCK_POW_EA_IqEhance_H: 1;
        uint32_t BUCK_POW_EA_Iqx3_H: 1;
        uint32_t BUCK_POW_EA_Iqx2_H: 1;
        uint32_t BUCK_EN_PDMC_H: 1;
        uint32_t BUCK_EN_IMIRROR_IPTAT_Gating: 1;
        uint32_t BUCK_FPWM_H: 1;
        uint32_t BUCK_ENLDO_H: 1;
        uint32_t BUCK_ENSWR_H: 1;
        uint32_t BUCK_ENBIAS_H: 1;
    };
} AON_REG6X_BUCK_TYPE;

/* 0xC30    0x4000_0c30
    6:0     R/W BUCK_ZCDOFFSET                          7'b0110000
    7       R/W BUCK_EN_OCP_IBON                        1'b1
    8       R/W BUCK_PFM_COMP_AFTER_OCP                 1'b0
    9       R/W BUCK_TON_PS_HV                          1'b0
    11:10   R/W BUCK_IBSEL_TONCOMP                      2'b01
    13:12   R/W BUCK_MinONtime_sel                      2'b01
    15:14   R/W BUCK_ZCD_LOWIQ_LOGIC_TUNE_STICKY        2'b10
    16      R   BUCK_32K_CLK_IN                         1'b0
    17      R/W BUCK_POW_LowIq_ZCD                      1'b0
    18      R/W BUCK_STICKY_CODE                        1'b0
    19      R/W BUCK_FORCE_CODE                         1'b0
    20      R/W BUCK_POW_ClampLX                        1'b1
    21      R/W BUCK_POW_ZCD                            1'b0
    23:22   R/W BUCK_ZCD_LOWIQ_LOGIC_TUNE_WAIT          2'b00
    25:24   R/W BUCK_ZCD_SDZ2d                          2'b10
    28:26   R/W BUCK_ZCD_SDZ2                           3'b100
    30:29   R/W BUCK_ZCD_SDZ1                           2'b10
    31      R/W BUCK_SEL_ZCD_LowIQ                      1'b0
 */
typedef volatile union _AON_REG8X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_ZCDOFFSET: 7;
        uint32_t BUCK_EN_OCP_IBON: 1;
        uint32_t BUCK_PFM_COMP_AFTER_OCP: 1;
        uint32_t BUCK_TON_PS_HV: 1;
        uint32_t BUCK_IBSEL_TONCOMP: 2;
        uint32_t BUCK_MinONtime_sel: 2;
        uint32_t BUCK_ZCD_LOWIQ_LOGIC_TUNE_STICKY: 2;
        uint32_t BUCK_32K_CLK_IN: 1;
        uint32_t BUCK_POW_LowIq_ZCD: 1;
        uint32_t BUCK_STICKY_CODE: 1;
        uint32_t BUCK_FORCE_CODE: 1;
        uint32_t BUCK_POW_ClampLX: 1;
        uint32_t BUCK_POW_ZCD: 1;
        uint32_t BUCK_ZCD_LOWIQ_LOGIC_TUNE_WAIT: 2;
        uint32_t BUCK_ZCD_SDZ2d: 2;
        uint32_t BUCK_ZCD_SDZ2: 3;
        uint32_t BUCK_ZCD_SDZ1: 2;
        uint32_t BUCK_SEL_ZCD_LowIQ: 1;
    };
} AON_REG8X_BUCK_TYPE;

/* 0xC34    0x4000_0c34
    0       R   BUCK_VREFSS_OVER_H                      1'b0
    1       R   BUCK_LX_DET                             1'b0
    2       R   BUCK_SampleOver                         1'b0
    3       R   BUCK_LowIQ_ZCD                          1'b0
    4       R   BUCK_UPDATE_CK                          1'b0
    5       R   BUCK_UD_H                               1'b0
    6       R   BUCK_PFM_RESET                          1'b0
    7       R   BUCK_PI                                 1'b0
    8       R   BUCK_NI                                 1'b0
    9       R   BUCK_OCP_H                              1'b0
    10      R   BUCK_CK_CTRL                            1'b0
    11      R   BUCK_FPWM_H                             1'b0
    12      R   BUCK_NGATE_HV                           1'b0
    13      R   BUCK_PFM_COMP                           1'b0
    14      R   BUCK_ZCD                                1'b0
    15      R   BUCK_PFM_CTRL_FORDIG                    1'b0
    16      R   AGND33_HG_APAD                          1'b0
    17      R   AGND33_HG_APAD                          1'b0
    18      R   AGND33_HG_APAD                          1'b0
    19      R   AGND33_HG_APAD                          1'b0
    20      R   AGND33_HG_APAD                          1'b0
    21      R   AGND33_HG_APAD                          1'b0
    22      R   ZCDQ<0>                                 1'b0
    23      R   ZCDQ<1>                                 1'b0
    24      R   ZCDQ<2>                                 1'b0
    25      R   ZCDQ<3>                                 1'b0
    26      R   ZCDQ<4>                                 1'b0
    27      R   ZCDQ<5>                                 1'b0
    28      R   ZCDQ<6>                                 1'b0
    29      R   BUCK_CKSS                               1'b0
    30      R   BUCK_PORB33V_H                          1'b0
    31      R   BUCK_VREFSS_START_H                     1'b0
 */
typedef volatile union _AON_C_KOUT0X_BUCK_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BUCK_VREFSS_OVER_H: 1;
        uint32_t BUCK_LX_DET: 1;
        uint32_t BUCK_SampleOver: 1;
        uint32_t BUCK_LowIQ_ZCD: 1;
        uint32_t BUCK_UPDATE_CK: 1;
        uint32_t BUCK_UD_H: 1;
        uint32_t BUCK_PFM_RESET: 1;
        uint32_t BUCK_PI: 1;
        uint32_t BUCK_NI: 1;
        uint32_t BUCK_OCP_H: 1;
        uint32_t BUCK_CK_CTRL: 1;
        uint32_t BUCK_FPWM_H: 1;
        uint32_t BUCK_NGATE_HV: 1;
        uint32_t BUCK_PFM_COMP: 1;
        uint32_t BUCK_ZCD: 1;
        uint32_t BUCK_PFM_CTRL_FORDIG: 1;
        uint32_t AGND33_HG_APAD_5: 1;
        uint32_t AGND33_HG_APAD_4: 1;
        uint32_t AGND33_HG_APAD_3: 1;
        uint32_t AGND33_HG_APAD_2: 1;
        uint32_t AGND33_HG_APAD_1: 1;
        uint32_t AGND33_HG_APAD: 1;
        uint32_t ZCDQ_0: 1;
        uint32_t ZCDQ_1: 1;
        uint32_t ZCDQ_2: 1;
        uint32_t ZCDQ_3: 1;
        uint32_t ZCDQ_4: 1;
        uint32_t ZCDQ_5: 1;
        uint32_t ZCDQ_6: 1;
        uint32_t BUCK_CKSS: 1;
        uint32_t BUCK_PORB33V_H: 1;
        uint32_t BUCK_VREFSS_START_H: 1;
    };
} AON_C_KOUT0X_BUCK_TYPE;

/* 0xC80    0x4000_0c80
    1:0     R/W XTAL32K_CUR_MAIN                        2'b01
    5:2     R/W XTAL32K_CUR_GM_INI                      4'b1001
    9:6     R/W XTAL32K_CUR_GM                          4'b0101
    11:10   R/W XTAL32K_CUR_REP                         2'b01
    15:12   R/W XTAL32K_GM                              4'b1111
    16      R/W EN_XTAL32K_CAP_INITIAL                  1'b1
    17      R/W EN_XTAL32K_CAP_AWAKE                    1'b1
    23:18   R/W XTAL32K_SC_XI                           6'b100000
    29:24   R/W XTAL32K_SC_XO                           6'b100000
    31:30   R/W XTAL32K_TOK                             2'b11
 */
typedef volatile union _AON_REG0X_32KXTAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL32K_CUR_MAIN: 2;
        uint32_t XTAL32K_CUR_GM_INI: 4;
        uint32_t XTAL32K_CUR_GM: 4;
        uint32_t XTAL32K_CUR_REP: 2;
        uint32_t XTAL32K_GM: 4;
        uint32_t EN_XTAL32K_CAP_INITIAL: 1;
        uint32_t EN_XTAL32K_CAP_AWAKE: 1;
        uint32_t XTAL32K_SC_XI: 6;
        uint32_t XTAL32K_SC_XO: 6;
        uint32_t XTAL32K_TOK: 2;
    };
} AON_REG0X_32KXTAL_TYPE;

/* 0xC84    0x4000_0c84
    0       R/W ENB_XTAL32K_FBRES                       1'b0
    3:1     R/W XTAL32K_GM_REP                          3'b111
    4       R/W XTAL32K_SC_XI_EXTRA                     1'b0
    5       R/W XTAL32K_SC_XO_EXTRA                     1'b0
    6       R/W XTAL32K_GPIO_SEL                        1'b1
    7       R/W REG2X_32KXTAL_DUMMY                     1'b0
    15:8    R/W RSVD                                    8'b0
    31:16   R/W RSVD                                    16'b0
 */
typedef volatile union _AON_REG2X_32KXTAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ENB_XTAL32K_FBRES: 1;
        uint32_t XTAL32K_GM_REP: 3;
        uint32_t XTAL32K_SC_XI_EXTRA: 1;
        uint32_t XTAL32K_SC_XO_EXTRA: 1;
        uint32_t XTAL32K_GPIO_SEL: 1;
        uint32_t REG2X_32KXTAL_DUMMY: 1;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 16;
    };
} AON_REG2X_32KXTAL_TYPE;

/* 0xC88    0x4000_0c88
    5:0     R/W RCAL                                    6'b100000
    14:6    R/W REG0X_32KOSC_DUMMY                      9'b0
    15      R/W SEL_LDO_VREF                            1'b0
    31:16   R/W RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_32KOSC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RCAL: 6;
        uint32_t REG0X_32KOSC_DUMMY: 9;
        uint32_t SEL_LDO_VREF: 1;
        uint32_t RSVD: 16;
    };
} AON_REG0X_32KOSC_TYPE;

/* 0xC8C    0x4000_0c8c
    0       R/W POW_32KOSC                              1'b1
    1       R/W POW_32KXTAL                             1'b1
    2       R   OSC32K_OK                               1'b1
    3       R   XTAL32K_OK                              1'b0
    31:4    R/W RSVD                                    28'b0
 */
typedef volatile union _AON_REG_POW_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t POW_32KOSC: 1;
        uint32_t POW_32KXTAL: 1;
        uint32_t OSC32K_OK: 1;
        uint32_t XTAL32K_OK: 1;
        uint32_t RSVD: 28;
    };
} AON_REG_POW_TYPE;

/* 0xC90    0x4000_0c90
    0       R/W POW_40MOSC                              1'b0
    4:1     R/W FSET_40MOSC                             4'b1000
    15:5    R/W REG0X_40MOSC_DUMMY                      11'b0
    31:16   R   RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_40MOSC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t POW_40MOSC: 1;
        uint32_t FSET_40MOSC: 4;
        uint32_t REG0X_40MOSC_DUMMY: 11;
        uint32_t RSVD: 16;
    };
} AON_REG0X_40MOSC_TYPE;

/* 0xC94    0x4000_0c94
    0       R/W RCAL_32K_SEL                            1'b0
    31:1    R/W RSVD                                    31'b0
 */
typedef volatile union _AON_REG0X_RCAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RCAL_32K_SEL: 1;
        uint32_t RSVD: 31;
    };
} AON_REG0X_RCAL_TYPE;

/* 0xCA0    0x4000_0ca0
    2:0     R   AON2PON_XTAL_MODE                       3'b100
    3       R/W XTAL_DEBUG                              1'b0
    6:4     R/W XTAL_MODE_DEBUG                         3'b100
    7       R   AON2PON_ISO_XTAL_MODE_CTRL              1'b1
    8       R/W XTAL_MODE_NMPC                          1'b0
    9       R   AON2PON_POW_XTAL                        1'b0
    15:10   R/W XTAL_MODE_DUMMY0                        6'b0
    31:16   R/W XTAL_MODE_DUMMY1                        16'b0
 */
typedef volatile union _AON_BT_ANAPAR_XTAL_mode_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON2PON_XTAL_MODE: 3;
        uint32_t XTAL_DEBUG: 1;
        uint32_t XTAL_MODE_DEBUG: 3;
        uint32_t AON2PON_ISO_XTAL_MODE_CTRL: 1;
        uint32_t XTAL_MODE_NMPC: 1;
        uint32_t AON2PON_POW_XTAL: 1;
        uint32_t XTAL_MODE_DUMMY0: 6;
        uint32_t XTAL_MODE_DUMMY1: 16;
    };
} AON_BT_ANAPAR_XTAL_mode_TYPE;

/* 0xCA4    0x4000_0ca4
    0       R/W XTAL_EN_XTAL_AAC_GM                     1'b0
    1       R/W XTAL_EN_XTAL_AAC_PKDET                  1'b0
    2       R/W XTAL_EN_XTAL_LPS                        1'b0
    3       R/W XTAL_GATED_XTAL_OK0                     1'b0
    6:4     R/W XTAL_AAC_PK_SEL                         3'b101
    10:7    R/W XTAL_AAC_PK_LP_SEL                      4'b0101
    15:11   R/W XTAL_BUF_GMN                            5'b01000
    20:16   R/W XTAL_BUF_GMN_LP                         5'b01000
    25:21   R/W XTAL_BUF_GMP                            5'b01000
    30:26   R/W XTAL_BUF_GMP_LP                         5'b01000
    31      R/W XTAL_BK_BG                              1'b0
 */
typedef volatile union _AON_BT_ANAPAR_XTAL0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_EN_XTAL_AAC_GM: 1;
        uint32_t XTAL_EN_XTAL_AAC_PKDET: 1;
        uint32_t XTAL_EN_XTAL_LPS: 1;
        uint32_t XTAL_GATED_XTAL_OK0: 1;
        uint32_t XTAL_AAC_PK_SEL: 3;
        uint32_t XTAL_AAC_PK_LP_SEL: 4;
        uint32_t XTAL_BUF_GMN: 5;
        uint32_t XTAL_BUF_GMN_LP: 5;
        uint32_t XTAL_BUF_GMP: 5;
        uint32_t XTAL_BUF_GMP_LP: 5;
        uint32_t XTAL_BK_BG: 1;
    };
} AON_BT_ANAPAR_XTAL0_TYPE;

/* 0xCA8    0x4000_0ca8
    0       R/W XTAL_DELAY_AFE                          1'b0
    1       R/W XTAL_DELAY_USB                          1'b0
    2       R/W XTAL_DOUBLE_OP_I                        1'b0
    4:3     R/W XTAL_DRV_AFE                            2'b11
    6:5     R/W XTAL_DRV_USB                            2'b11
    8:7     R/W XTAL_DRV_RF                             2'b11
    9       R/W XTAL_DRV_RF_LATCH                       1'b0
    10      R/W XTAL_GATED_AFEP                         1'b0
    11      R/W XTAL_GATED_AFEN                         1'b0
    12      R/W XTAL_GATED_USBP                         1'b0
    13      R/W XTAL_GATED_USBN                         1'b0
    14      R/W XTAL_GATED_RFP                          1'b0
    15      R/W XTAL_GATED_RFN                          1'b0
    21:16   R/W XTAL_GM                                 6'b111111
    27:22   R/W XTAL_GM_LP                              6'b111111
    28      R/W XTAL_GM_SEP                             1'b0
    29      R/W XTAL_IDOUBLE                            1'b0
    30      R/W XTAL_IS_FINE_MANU                       1'b0
    31      R/W XTAL_SW_LDO2PWRCUT                      1'b0
 */
typedef volatile union _AON_BT_ANAPAR_XTAL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_DELAY_AFE: 1;
        uint32_t XTAL_DELAY_USB: 1;
        uint32_t XTAL_DOUBLE_OP_I: 1;
        uint32_t XTAL_DRV_AFE: 2;
        uint32_t XTAL_DRV_USB: 2;
        uint32_t XTAL_DRV_RF: 2;
        uint32_t XTAL_DRV_RF_LATCH: 1;
        uint32_t XTAL_GATED_AFEP: 1;
        uint32_t XTAL_GATED_AFEN: 1;
        uint32_t XTAL_GATED_USBP: 1;
        uint32_t XTAL_GATED_USBN: 1;
        uint32_t XTAL_GATED_RFP: 1;
        uint32_t XTAL_GATED_RFN: 1;
        uint32_t XTAL_GM: 6;
        uint32_t XTAL_GM_LP: 6;
        uint32_t XTAL_GM_SEP: 1;
        uint32_t XTAL_IDOUBLE: 1;
        uint32_t XTAL_IS_FINE_MANU: 1;
        uint32_t XTAL_SW_LDO2PWRCUT: 1;
    };
} AON_BT_ANAPAR_XTAL2_TYPE;

/* 0xCAC    0x4000_0cac
    5:0     R/W XTAL_GM_OK0                             6'b111111
    11:6    R/W XTAL_IS                                 6'b111111
    13:12   R/W XTAL_DRV_DIGI_LP                        2'b11
    14      R/W XTAL_GDIGI_LP                           1'b0
    15      R/W XTAL_REG4X_DUMMY1                       1'b0
    23:16   R/W XTAL_IS_FINE                            8'b11111111
    29:24   R/W XTAL_IS_LP                              6'b000000
    31:30   R/W XTAL_PKDET_LP_TSEL                      2'b01
 */
typedef volatile union _AON_BT_ANAPAR_XTAL4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_GM_OK0: 6;
        uint32_t XTAL_IS: 6;
        uint32_t XTAL_DRV_DIGI_LP: 2;
        uint32_t XTAL_GDIGI_LP: 1;
        uint32_t XTAL_REG4X_DUMMY1: 1;
        uint32_t XTAL_IS_FINE: 8;
        uint32_t XTAL_IS_LP: 6;
        uint32_t XTAL_PKDET_LP_TSEL: 2;
    };
} AON_BT_ANAPAR_XTAL4_TYPE;

/* 0xCB0    0x4000_0cb0
    2:0     R/W XTAL_LPS_CKMODE                         3'b110
    5:3     R   AON2PON_XTAL_LDO                        3'b011
    8:6     R   AON2PON_XTAL_LDO_OK                     3'b011
    11:9    R/W XTAL_LPM_CKO_SEL                        3'b011
    14:12   R   AON2PON_XTAL_SEL_TOK                    3'b101
    15      R/W XTAL_reg_fast_settling                  1'b1
    23:16   R/W XTAL_SC_XI                              8'b00111111
    31:24   R/W XTAL_SC_XI_LP                           8'b11111111
 */
typedef volatile union _AON_BT_ANAPAR_XTAL6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_LPS_CKMODE: 3;
        uint32_t AON2PON_XTAL_LDO: 3;
        uint32_t AON2PON_XTAL_LDO_OK: 3;
        uint32_t XTAL_LPM_CKO_SEL: 3;
        uint32_t AON2PON_XTAL_SEL_TOK: 3;
        uint32_t XTAL_reg_fast_settling: 1;
        uint32_t XTAL_SC_XI: 8;
        uint32_t XTAL_SC_XI_LP: 8;
    };
} AON_BT_ANAPAR_XTAL6_TYPE;

/* 0xCB4    0x4000_0cb4
    7:0     R   AON2PON_XTAL_SC_XI_OK0                  8'b11110000
    15:8    R/W XTAL_SC_XO                              8'b00111111
    23:16   R/W XTAL_SC_XO_LP                           8'b11111111
    31:24   R   AON2PON_XTAL_SC_XO_OK0                  8'b11110000
 */
typedef volatile union _AON_BT_ANAPAR_XTAL8_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON2PON_XTAL_SC_XI_OK0: 8;
        uint32_t XTAL_SC_XO: 8;
        uint32_t XTAL_SC_XO_LP: 8;
        uint32_t AON2PON_XTAL_SC_XO_OK0: 8;
    };
} AON_BT_ANAPAR_XTAL8_TYPE;

/* 0xCB8    0x4000_0cb8
    2:0     R/W XTAL_XORES_SEL                          3'b000
    4:3     R/W XTAL_reg_stp                            2'b00
    8:5     R/W XTAL_reg_dout_offset                    4'b0011
    9       R/W XTAL_GATED_LPMODE                       1'b0
    10      R/W XTAL_GATED_EN_PEAKDET_LP                1'b0
    11      R/W XTAL_LDOPC_SEL                          1'b0
    12      R   AON2PON_XTAL_BUF_LPS_SEL                1'b0
    13      R/W XTAL_LPMODE_CLK_SEL                     1'b0
    14      R/W XTAL_reg_fast_always_on                 1'b0
    15      R/W XTAL_LPMODE_CLK_AON                     1'b0
    16      R/W XTAL_IOP_SEL                            1'b0
    17      R/W XTAL_EN_XTAL_PDCK_LP                    1'b0
    20:18   R/W XTAL_LDO_SW_LP                          3'b000
    25:21   R/W BT_ANAPAR_XTAL11_DUMMY                  5'b10000
    26      R/W XTAL_PDC_MANUAL                         1'b0
    27      R/W XTAL_PKDET_CMP_SWAP                     1'b0
    28      R/W XTAL_PKDET_LOAD_SWAP                    1'b0
    31:29   R   AON2PON_XTAL_SEL_TOK01                  3'b100
 */
typedef volatile union _AON_BT_ANAPAR_XTAL10_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_XORES_SEL: 3;
        uint32_t XTAL_reg_stp: 2;
        uint32_t XTAL_reg_dout_offset: 4;
        uint32_t XTAL_GATED_LPMODE: 1;
        uint32_t XTAL_GATED_EN_PEAKDET_LP: 1;
        uint32_t XTAL_LDOPC_SEL: 1;
        uint32_t AON2PON_XTAL_BUF_LPS_SEL: 1;
        uint32_t XTAL_LPMODE_CLK_SEL: 1;
        uint32_t XTAL_reg_fast_always_on: 1;
        uint32_t XTAL_LPMODE_CLK_AON: 1;
        uint32_t XTAL_IOP_SEL: 1;
        uint32_t XTAL_EN_XTAL_PDCK_LP: 1;
        uint32_t XTAL_LDO_SW_LP: 3;
        uint32_t BT_ANAPAR_XTAL11_DUMMY: 5;
        uint32_t XTAL_PDC_MANUAL: 1;
        uint32_t XTAL_PKDET_CMP_SWAP: 1;
        uint32_t XTAL_PKDET_LOAD_SWAP: 1;
        uint32_t AON2PON_XTAL_SEL_TOK01: 3;
    };
} AON_BT_ANAPAR_XTAL10_TYPE;

/* 0xCBC    0x4000_0cbc
    3:0     R/W XTAL_LPSCLK_CNTRL                       4'b0000
    4       R   AON2PON_XTAL_EN_XTAL_SEL_TOK01          1'b0
    5       R   AON2PON_XTAL_EN_XO_CLK_SW               1'b0
    6       R/W XTAL_FASTSET_MANU                       1'b0
    8:7     R/W XTAL_OV_RATIO                           2'b01
    11:9    R/W XTAL_OV_UNIT                            3'b010
    12      R/W XTAL_LPS_CAP_CTRL                       1'b1
    14:13   R/W XTAL_LPS_CAP_CYC                        2'b00
    15      R/W XTAL_MD_LPOW                            1'b0
    21:16   R/W XTAL_WAIT_CYC                           6'b000010
    23:22   R/W XTAL_LPS_CAP_STEP                       2'b01
    24      R/W XTAL_BYPASS_CTRL                        1'b0
    27:25   R/W XTAL_RDY_SEL_TOK                        3'b100
    31:28   R/W XTAL_CTRL_OUT_SEL                       4'b0000
 */
typedef volatile union _AON_BT_ANAPAR_XTAL12_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_LPSCLK_CNTRL: 4;
        uint32_t AON2PON_XTAL_EN_XTAL_SEL_TOK01: 1;
        uint32_t AON2PON_XTAL_EN_XO_CLK_SW: 1;
        uint32_t XTAL_FASTSET_MANU: 1;
        uint32_t XTAL_OV_RATIO: 2;
        uint32_t XTAL_OV_UNIT: 3;
        uint32_t XTAL_LPS_CAP_CTRL: 1;
        uint32_t XTAL_LPS_CAP_CYC: 2;
        uint32_t XTAL_MD_LPOW: 1;
        uint32_t XTAL_WAIT_CYC: 6;
        uint32_t XTAL_LPS_CAP_STEP: 2;
        uint32_t XTAL_BYPASS_CTRL: 1;
        uint32_t XTAL_RDY_SEL_TOK: 3;
        uint32_t XTAL_CTRL_OUT_SEL: 4;
    };
} AON_BT_ANAPAR_XTAL12_TYPE;

/* 0xCC0    0x4000_0cc0
    0       R/W BT_ANAPAR_XTAL14_DUMMY0                 1'b0
    2:1     R/W XTAL_MODE_DLY                           2'b10
    15:3    R/W BT_ANAPAR_XTAL14_DUMMY3                 13'h0
    21:16   R/W XTAL_PDC_LP                             6'b100000
    31:22   R/W BT_ANAPAR_XTAL15_DUMMY                  10'b0000000000
 */
typedef volatile union _AON_BT_ANAPAR_XTAL14_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BT_ANAPAR_XTAL14_DUMMY0: 1;
        uint32_t XTAL_MODE_DLY: 2;
        uint32_t BT_ANAPAR_XTAL14_DUMMY3: 13;
        uint32_t XTAL_PDC_LP: 6;
        uint32_t BT_ANAPAR_XTAL15_DUMMY: 10;
    };
} AON_BT_ANAPAR_XTAL14_TYPE;

/* 0xCC4    0x4000_0cc4
    15:0    R/W BT_ANAPAR_XTAL16_DUMMY                  16'b0
    31:16   R/W BT_ANAPAR_XTAL17_DUMMY                  16'hffff
 */
typedef volatile union _AON_BT_ANAPAR_XTAL16_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BT_ANAPAR_XTAL16_DUMMY: 16;
        uint32_t BT_ANAPAR_XTAL17_DUMMY: 16;
    };
} AON_BT_ANAPAR_XTAL16_TYPE;

/* 0xCC8    0x4000_0cc8
    2:0     R   RSVD                                    3'b0
    3       R/W AAC_SEL                                 1'b0
    9:4     R/W AAC_GM1                                 6'h1f
    15:10   R   AON2PON_XTAL_GM_AAC                     6'h0f
    23:16   R/W CLK_REQ_XTAL_SC_XI                      8'b00111111
    31:24   R/W CLK_REQ_XTAL_SC_XO                      8'b00111111
 */
typedef volatile union _AON_REG0X_XTAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD: 3;
        uint32_t AAC_SEL: 1;
        uint32_t AAC_GM1: 6;
        uint32_t AON2PON_XTAL_GM_AAC: 6;
        uint32_t CLK_REQ_XTAL_SC_XI: 8;
        uint32_t CLK_REQ_XTAL_SC_XO: 8;
    };
} AON_REG0X_XTAL_TYPE;

/* 0xCCC    0x4000_0ccc
    7:0     R   XTAL_IS_FINEO                           8'b11111111
    8       R   XTAL_CLK_OK                             1'b0
    9       R   XTAL_CLK_CHANGE_OK                      1'b0
    10      R   XTAL_NM_MODE_O                          1'b0
    11      R   XTAL_MODE_READY_O                       1'b0
    14:12   R   XTAL_MODE_O                             3'b0
    15      R   XTAL_LPS_MODE_O                         1'b0
    16      R   XTAL_HP_MODE_O                          1'b0
    17      R   XTAL_FASTSET_O                          1'b0
    23:18   R   RSVD                                    6'b0
    31:24   R   XTAL_CTRL_DEBUG_OUT                     8'b0
 */
typedef volatile union _AON_REG1X_XTAL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_IS_FINEO: 8;
        uint32_t XTAL_CLK_OK: 1;
        uint32_t XTAL_CLK_CHANGE_OK: 1;
        uint32_t XTAL_NM_MODE_O: 1;
        uint32_t XTAL_MODE_READY_O: 1;
        uint32_t XTAL_MODE_O: 3;
        uint32_t XTAL_LPS_MODE_O: 1;
        uint32_t XTAL_HP_MODE_O: 1;
        uint32_t XTAL_FASTSET_O: 1;
        uint32_t RSVD: 6;
        uint32_t XTAL_CTRL_DEBUG_OUT: 8;
    };
} AON_REG1X_XTAL_TYPE;

/* 0xCD0    0x4000_0cd0
    0       R/W ADDA_SW_LDO2PWRCUT                      1'b0
    1       R/W ADDA_POW_LDO_VREF                       1'b1
    2       R/W ADDA_POW_LDO_OP                         1'b1
    3       R/W ADDA_LDO_VPULSE                         1'b0
    7:4     R/W ADDA_LDO_SW                             4'b0010
    8       R/W ADDA_DOUBLE_OP_I                        1'b0
    15:9    R   RSVD                                    7'b0
    31:16   R   RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_BT_ANAPAR_LDO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ADDA_SW_LDO2PWRCUT: 1;
        uint32_t ADDA_POW_LDO_VREF: 1;
        uint32_t ADDA_POW_LDO_OP: 1;
        uint32_t ADDA_LDO_VPULSE: 1;
        uint32_t ADDA_LDO_SW: 4;
        uint32_t ADDA_DOUBLE_OP_I: 1;
        uint32_t RSVD_1: 7;
        uint32_t RSVD: 16;
    };
} AON_REG0X_BT_ANAPAR_LDO_TYPE;

/* 0xCD4    0x4000_0cd4
    0       R/W SW_LDO2PWRCUT                           1'b0
    1       R/W POW_LDO                                 1'b0
    2       R/W EN_SW                                   1'b0
    5:3     R/W LDO_SW                                  3'b100
    15:6    R   RSVD                                    10'b0
    31:16   R   RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_RF_LDO318_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t SW_LDO2PWRCUT: 1;
        uint32_t POW_LDO: 1;
        uint32_t EN_SW: 1;
        uint32_t LDO_SW: 3;
        uint32_t RSVD_1: 10;
        uint32_t RSVD: 16;
    };
} AON_REG0X_RF_LDO318_TYPE;

/* 0xD00    0x4000_0d00
    8:0     R/W REG0X_LDO_PLL1_DUMMY                    9'b0
    9       R/W DOUBLE_OP_I                             1'b0
    10      R/W PLL_SW_LDO2PWRCUT                       1'b0
    11      R/W POW_LDO_OP                              1'b0
    12      R/W PLL_LDO_VPULSE                          1'b0
    15:13   R/W PLL_LDO_SW                              3'b010
    31:16   R   RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_LDO_PLL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t REG0X_LDO_PLL1_DUMMY: 9;
        uint32_t DOUBLE_OP_I: 1;
        uint32_t PLL_SW_LDO2PWRCUT: 1;
        uint32_t POW_LDO_OP: 1;
        uint32_t PLL_LDO_VPULSE: 1;
        uint32_t PLL_LDO_SW: 3;
        uint32_t RSVD: 16;
    };
} AON_REG0X_LDO_PLL1_TYPE;

/* 0xD40    0x4000_0d40
    23:0    R   RSVD                                    24'h0
    24      R/W REG0X_USB_DUMMY0                        1'b0
    25      R/W UA33PC_EN                               1'b0
    26      R/W UA11PC_EN                               1'b0
    27      R/W UD11PC_EN                               1'b0
    28      R/W USB_POW_BG                              1'b0
    29      R/W USB_POW_BC_L                            1'b0
    30      R/W ISO_LV                                  1'b1
    31      R/W ISO_UA2USB                              1'b1
 */
typedef volatile union _AON_REG_USB_POWER_CTL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD: 24;
        uint32_t REG0X_USB_DUMMY0: 1;
        uint32_t UA33PC_EN: 1;
        uint32_t UA11PC_EN: 1;
        uint32_t UD11PC_EN: 1;
        uint32_t USB_POW_BG: 1;
        uint32_t USB_POW_BC_L: 1;
        uint32_t ISO_LV: 1;
        uint32_t ISO_UA2USB: 1;
    };
} AON_REG_USB_POWER_CTL_TYPE;

/* 0xD44    0x4000_0d44
    0       R/W r_usb_clk_src_en                        1'h0
    4:1     R/W r_usb_div_sel                           4'h0
    5       R/W r_usb_div_en                            1'h0
    6       R/W r_usb_mux_clk_cg_en                     1'h0
    7       R/W r_usb_clk_src_sel1                      1'h0
    8       R/W r_usb_clk_src_sel0                      1'h0
    20:9    R/W iso_int_out_en                          12'h0
    26:21   R   RSVD                                    6'h0
    27      R/W usb_func_en                             1'h0
    28      R/W usb_ck_en                               1'h0
    31:29   R   RSVD                                    3'h0
 */
typedef volatile union _AON_REG_USB_CLK_CTL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_usb_clk_src_en: 1;
        uint32_t r_usb_div_sel: 4;
        uint32_t r_usb_div_en: 1;
        uint32_t r_usb_mux_clk_cg_en: 1;
        uint32_t r_usb_clk_src_sel1: 1;
        uint32_t r_usb_clk_src_sel0: 1;
        uint32_t iso_int_out_en: 12;
        uint32_t RSVD_1: 6;
        uint32_t usb_func_en: 1;
        uint32_t usb_ck_en: 1;
        uint32_t RSVD: 3;
    };
} AON_REG_USB_CLK_CTL_TYPE;

/* 0xD60    0x4000_0d60
    0       R/W POW_XTAL                                1'b0
    3:1     R/W XTAL_MODE                               3'b100
    4       R/W ISO_XTAL_MODE_CTRL                      1'b1
    7:5     R/W XTAL_LDO                                3'b011
    10:8    R/W XTAL_LDO_OK                             3'b011
    13:11   R/W XTAL_SEL_TOK                            3'b101
    21:14   R/W XTAL_SC_XI_OK0                          8'b11110000
    29:22   R/W XTAL_SC_XO_OK0                          8'b11110000
    31:30   R   RSVD                                    2'b0
 */
typedef volatile union _AON_REG_XTAL0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t POW_XTAL: 1;
        uint32_t XTAL_MODE: 3;
        uint32_t ISO_XTAL_MODE_CTRL: 1;
        uint32_t XTAL_LDO: 3;
        uint32_t XTAL_LDO_OK: 3;
        uint32_t XTAL_SEL_TOK: 3;
        uint32_t XTAL_SC_XI_OK0: 8;
        uint32_t XTAL_SC_XO_OK0: 8;
        uint32_t RSVD: 2;
    };
} AON_REG_XTAL0_TYPE;

/* 0xD64    0x4000_0d64
    0       R/W XTAL_BUF_LPS_SEL                        1'b0
    3:1     R/W XTAL_SEL_TOK01                          3'b100
    4       R/W XTAL_EN_XTAL_SEL_TOK01                  1'b0
    5       R/W XTAL_EN_XO_CLK_SW                       1'b0
    11:6    R/W XTAL_GM_AAC                             6'h0f
    31:12   R   RSVD                                    20'b0
 */
typedef volatile union _AON_REG_XTAL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t XTAL_BUF_LPS_SEL: 1;
        uint32_t XTAL_SEL_TOK01: 3;
        uint32_t XTAL_EN_XTAL_SEL_TOK01: 1;
        uint32_t XTAL_EN_XO_CLK_SW: 1;
        uint32_t XTAL_GM_AAC: 6;
        uint32_t RSVD: 20;
    };
} AON_REG_XTAL1_TYPE;

/* 0xD80    0x4000_0d80
    9:0     R/W REG0X_PLL1_dummy                        10'b0
    15:10   R/W DIV<5:0>                                6'b010111
    31:16   R   RSVD                                    16'b0
 */
typedef volatile union _AON_REG0X_PLL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t REG0X_PLL1_dummy: 10;
        uint32_t DIV_5_0: 6;
        uint32_t RSVD: 16;
    };
} AON_REG0X_PLL1_TYPE;

/* 0xD84    0x4000_0d84
    0       R/W REG2X_PLL1_dummy                        1'b0
    2:1     R/W debugout_sel<1:0>                       2'b00
    3       R/W debugout_en                             1'b0
    5:4     R/W reg_ck_out_peri_sel<1:0>                2'b00
    6       R/W reg_ck_out_peri_div5                    1'b0
    8:7     R/W reg_ck_out_mac_sel<1:0>                 2'b00
    9       R/W reg_ck_out_mac_div5                     1'b0
    10      R/W reg_CKO_CPU_en                          1'b0
    11      R/W reg_CKO_PERI_en                         1'b0
    12      R/W reg_CKO_MAC50M_en                       1'b0
    13      R/W reg_CKO_MAC_en                          1'b0
    15:14   R/W VC_THL<1:0>                             2'b00
    18:16   R/W r3_set<2:0>                             3'b000
    19      R/W c3_set                                  1'b0
    22:20   R/W rs_set<2:0>                             3'b100
    24:23   R/W cs_set<1:0>                             2'b10
    26:25   R/W cp_set<1:0>                             2'b01
    27      R/W reg_ck_frefpn_sel                       1'b1
    28      R/W pow_cpop                                1'b1
    29      R/W dogenb                                  1'b0
    30      R/W fref_edge                               1'b0
    31      R/W pow_pll                                 1'b0
 */
typedef volatile union _AON_REG2X_PLL1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t REG2X_PLL1_dummy: 1;
        uint32_t debugout_sel_1_0: 2;
        uint32_t debugout_en: 1;
        uint32_t reg_ck_out_peri_sel_1_0: 2;
        uint32_t reg_ck_out_peri_div5: 1;
        uint32_t reg_ck_out_mac_sel_1_0: 2;
        uint32_t reg_ck_out_mac_div5: 1;
        uint32_t reg_CKO_CPU_en: 1;
        uint32_t reg_CKO_PERI_en: 1;
        uint32_t reg_CKO_MAC50M_en: 1;
        uint32_t reg_CKO_MAC_en: 1;
        uint32_t VC_THL_1_0: 2;
        uint32_t r3_set_2_0: 3;
        uint32_t c3_set: 1;
        uint32_t rs_set_2_0: 3;
        uint32_t cs_set_1_0: 2;
        uint32_t cp_set_1_0: 2;
        uint32_t reg_ck_frefpn_sel: 1;
        uint32_t pow_cpop: 1;
        uint32_t dogenb: 1;
        uint32_t fref_edge: 1;
        uint32_t pow_pll: 1;
    };
} AON_REG2X_PLL1_TYPE;

/* 0xD88    0x4000_0d88
    2:0     R/W reg_rs_set<2:0>                         3'b100
    5:3     R/W reg_r3_set<2:0>                         3'b010
    7:6     R/W reg_cs_set<1:0>                         2'b10
    9:8     R/W reg_cp_set<1:0>                         2'b10
    11:10   R/W reg_c3_set<1:0>                         2'b10
    14:12   R/W reg_cp_bia<2:0>                         3'b000
    15      R/W ref_lpf_en                              1'b1
    16      R/W pow_erc                                 1'b0
    23:17   R/W DIV_SDM<6:0>                            7'b0011100
    24      R/W CP_DISABLE                              1'b0
    26:25   R/W reg_xtal_dn_sel<1:0>                    2'b11
    27      R/W reg_ck_ext_sel                          1'b1
    28      R/W pow_div                                 1'b0
    29      R/W reg_dogenb                              1'b0
    30      R/W ref_fref_edge                           1'b0
    31      R/W pow_pll2                                1'b0
 */
typedef volatile union _AON_REG0X_PLL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_rs_set_2_0: 3;
        uint32_t reg_r3_set_2_0: 3;
        uint32_t reg_cs_set_1_0: 2;
        uint32_t reg_cp_set_1_0: 2;
        uint32_t reg_c3_set_1_0: 2;
        uint32_t reg_cp_bia_2_0: 3;
        uint32_t ref_lpf_en: 1;
        uint32_t pow_erc: 1;
        uint32_t DIV_SDM_6_0: 7;
        uint32_t CP_DISABLE: 1;
        uint32_t reg_xtal_dn_sel_1_0: 2;
        uint32_t reg_ck_ext_sel: 1;
        uint32_t pow_div: 1;
        uint32_t reg_dogenb: 1;
        uint32_t ref_fref_edge: 1;
        uint32_t pow_pll2: 1;
    };
} AON_REG0X_PLL2_TYPE;

/* 0xD8C    0x4000_0d8c
    15:0    R/W FOF_SDM_15_0_                           16'b0
    20:16   R/W FOF_SDM_20_16_                          5'b0
    23:21   R/W FON_SDM<2:0>                            3'b000
    24      R/W ORDER_SDM                               1'b0
    28:25   R/W BB_DBG_SEL_AFE_SDM<3:0>                 4'b0000
    29      R/W NF_COFE_SYNC_EN                         1'b0
    30      R/W NF_CODE_LOAD                            1'b0
    31      R/W REG2X_PLL2_dummy                        1'b0
 */
typedef volatile union _AON_REG2X_PLL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FOF_SDM_15_0_: 16;
        uint32_t FOF_SDM_20_16_: 5;
        uint32_t FON_SDM_2_0: 3;
        uint32_t ORDER_SDM: 1;
        uint32_t BB_DBG_SEL_AFE_SDM_3_0: 4;
        uint32_t NF_COFE_SYNC_EN: 1;
        uint32_t NF_CODE_LOAD: 1;
        uint32_t REG2X_PLL2_dummy: 1;
    };
} AON_REG2X_PLL2_TYPE;

/* 0xD90    0x4000_0d90
    15:0    R   RSVD                                    16'b0
    28:16   R/W REG4X_PLL2_dummy                        13'b0
    29      R/W reg_CKO1_sel                            1'b0
    30      R/W reg_CKO1_d2                             1'b0
    31      R/W reg_CKO1_en                             1'b0
 */
typedef volatile union _AON_REG4X_PLL2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD: 16;
        uint32_t REG4X_PLL2_dummy: 13;
        uint32_t reg_CKO1_sel: 1;
        uint32_t reg_CKO1_d2: 1;
        uint32_t reg_CKO1_en: 1;
    };
} AON_REG4X_PLL2_TYPE;

/* 0xD94    0x4000_0d94
    0       R   BT_READY_PLL                            1'b0
    1       R   BT_READY_PLL2                           1'b0
    31:2    R/W RSVD                                    30'b0
 */
typedef volatile union _AON_RO_PLL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t BT_READY_PLL: 1;
        uint32_t BT_READY_PLL2: 1;
        uint32_t RSVD: 30;
    };
} AON_RO_PLL_TYPE;

/* 0x1800   0x4000_1800
    0       R/W RTC_CNT_START                   1'b0
    1       R/W RTC_CNT_RST                     1'b0
    2       R/W RTC_PRE_CNT_RST                 1'b0
    7:3     R/W RTC_CR0_DUMMY0                  5'b0
    8       R/W RTC_TICK_IE                     1'b0
    9       R/W RTC_CNT_OV_IE                   1'b0
    10      R/W RTC_PRECMP_IE                   1'b0
    11      R/W RTC_PRECMP_CMP3_IE              1'b0
    12      R/W RTC_CMP0GT_IE                   1'b0
    13      R/W RTC_CMP1GT_IE                   1'b0
    14      R/W RTC_CMP2GT_IE                   1'b0
    15      R/W RTC_CMP3GT_IE                   1'b0
    16      R/W RTC_CMP0_NV_IE                  1'b0
    17      R/W RTC_CMP1_NV_IE                  1'b0
    18      R/W RTC_CMP2_NV_IE                  1'b0
    19      R/W RTC_CMP3_NV_IE                  1'b0
    20      R/W RTC_CMP0_WK_IE                  1'b0
    21      R/W RTC_CMP1_WK_IE                  1'b0
    22      R/W RTC_CMP2_WK_IE                  1'b0
    23      R/W RTC_CMP3_WK_IE                  1'b0
    28:24   R/W RTC_CR0_DUMMY1                  5'b0
    29      R/W RTC_WK_IE                       1'b0
    30      R/W RTC_NV_IE                       1'b0
    31      R/W RTC_RST                         1'b0
 */
typedef volatile union _AON_NS_RTC_CR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CNT_START: 1;
        uint32_t RTC_CNT_RST: 1;
        uint32_t RTC_PRE_CNT_RST: 1;
        uint32_t RTC_CR0_DUMMY0: 5;
        uint32_t RTC_TICK_IE: 1;
        uint32_t RTC_CNT_OV_IE: 1;
        uint32_t RTC_PRECMP_IE: 1;
        uint32_t RTC_PRECMP_CMP3_IE: 1;
        uint32_t RTC_CMP0GT_IE: 1;
        uint32_t RTC_CMP1GT_IE: 1;
        uint32_t RTC_CMP2GT_IE: 1;
        uint32_t RTC_CMP3GT_IE: 1;
        uint32_t RTC_CMP0_NV_IE: 1;
        uint32_t RTC_CMP1_NV_IE: 1;
        uint32_t RTC_CMP2_NV_IE: 1;
        uint32_t RTC_CMP3_NV_IE: 1;
        uint32_t RTC_CMP0_WK_IE: 1;
        uint32_t RTC_CMP1_WK_IE: 1;
        uint32_t RTC_CMP2_WK_IE: 1;
        uint32_t RTC_CMP3_WK_IE: 1;
        uint32_t RTC_CR0_DUMMY1: 5;
        uint32_t RTC_WK_IE: 1;
        uint32_t RTC_NV_IE: 1;
        uint32_t RTC_RST: 1;
    };
} AON_NS_RTC_CR0_TYPE;

/* 0x1804   0x4000_1804
    0       R/WACRTC_TICK_CLR                    1'b0
    1       R/WACRTC_CNT_OV_CLR                  1'b0
    2       R/WACRTC_PRECMP_CLR                  1'b0
    3       R/WACRTC_PRECMP_CMP3_CLR             1'b0
    4       R/WACRTC_CMP0GT_CLR                  1'b0
    5       R/WACRTC_CMP1GT_CLR                  1'b0
    6       R/WACRTC_CMP2GT_CLR                  1'b0
    7       R/WACRTC_CMP3GT_CLR                  1'b0
    8       R/WACRTC_CMP0_NV_CLR                 1'b0
    9       R/WACRTC_CMP1_NV_CLR                 1'b0
    10      R/WACRTC_CMP2_NV_CLR                 1'b0
    11      R/WACRTC_CMP3_NV_CLR                 1'b0
    12      R/WACRTC_CMP0_WK_CLR                 1'b0
    13      R/WACRTC_CMP1_WK_CLR                 1'b0
    14      R/WACRTC_CMP2_WK_CLR                 1'b0
    15      R/WACRTC_CMP3_WK_CLR                 1'b0
    31:16   R/W RTC_INT_clear_DUMMY             16'b0
 */
typedef volatile union _AON_NS_RTC_INT_clear_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_TICK_CLR: 1;
        uint32_t RTC_CNT_OV_CLR: 1;
        uint32_t RTC_PRECMP_CLR: 1;
        uint32_t RTC_PRECMP_CMP3_CLR: 1;
        uint32_t RTC_CMP0GT_CLR: 1;
        uint32_t RTC_CMP1GT_CLR: 1;
        uint32_t RTC_CMP2GT_CLR: 1;
        uint32_t RTC_CMP3GT_CLR: 1;
        uint32_t RTC_CMP0_NV_CLR: 1;
        uint32_t RTC_CMP1_NV_CLR: 1;
        uint32_t RTC_CMP2_NV_CLR: 1;
        uint32_t RTC_CMP3_NV_CLR: 1;
        uint32_t RTC_CMP0_WK_CLR: 1;
        uint32_t RTC_CMP1_WK_CLR: 1;
        uint32_t RTC_CMP2_WK_CLR: 1;
        uint32_t RTC_CMP3_WK_CLR: 1;
        uint32_t RTC_INT_clear_DUMMY: 16;
    };
} AON_NS_RTC_INT_clear_TYPE;

/* 0x1808   0x4000_1808
    0       R/W1CRTC_TICK_SR                     1'b0
    1       R/W1CRTC_CNT_OV_SR                   1'b0
    2       R/W1CRTC_PRECMP_SR                   1'b0
    3       R/W1CRTC_PRECMP_CMP3_SR              1'b0
    4       R/W1CRTC_CMP0GT_SR                   1'b0
    5       R/W1CRTC_CMP1GT_SR                   1'b0
    6       R/W1CRTC_CMP2GT_SR                   1'b0
    7       R/W1CRTC_CMP3GT_SR                   1'b0
    8       R/W1CRTC_CMP0_NV_SR                  1'b0
    9       R/W1CRTC_CMP1_NV_SR                  1'b0
    10      R/W1CRTC_CMP2_NV_SR                  1'b0
    11      R/W1CRTC_CMP3_NV_SR                  1'b0
    12      R/W1CRTC_CMP0_WK_SR                  1'b0
    13      R/W1CRTC_CMP1_WK_SR                  1'b0
    14      R/W1CRTC_CMP2_WK_SR                  1'b0
    15      R/W1CRTC_CMP3_WK_SR                  1'b0
    31:16   R/W RTC_INT_SR_DUMMY                16'b0
 */
typedef volatile union _AON_NS_RTC_INT_SR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_TICK_SR: 1;
        uint32_t RTC_CNT_OV_SR: 1;
        uint32_t RTC_PRECMP_SR: 1;
        uint32_t RTC_PRECMP_CMP3_SR: 1;
        uint32_t RTC_CMP0GT_SR: 1;
        uint32_t RTC_CMP1GT_SR: 1;
        uint32_t RTC_CMP2GT_SR: 1;
        uint32_t RTC_CMP3GT_SR: 1;
        uint32_t RTC_CMP0_NV_SR: 1;
        uint32_t RTC_CMP1_NV_SR: 1;
        uint32_t RTC_CMP2_NV_SR: 1;
        uint32_t RTC_CMP3_NV_SR: 1;
        uint32_t RTC_CMP0_WK_SR: 1;
        uint32_t RTC_CMP1_WK_SR: 1;
        uint32_t RTC_CMP2_WK_SR: 1;
        uint32_t RTC_CMP3_WK_SR: 1;
        uint32_t RTC_INT_SR_DUMMY: 16;
    };
} AON_NS_RTC_INT_SR_TYPE;

/* 0x180C   0x4000_180c
    11:0    R/W RTC_PRESCALER                   12'b0
    31:12   R/W RTC_PRESCALER_DUMMY             20'b0
 */
typedef volatile union _AON_NS_RTC_PRESCALER0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PRESCALER: 12;
        uint32_t RTC_PRESCALER_DUMMY: 20;
    };
} AON_NS_RTC_PRESCALER0_TYPE;

/* 0x1810   0x4000_1810
    31:0    R/W RTC_CMP0                        32'b0
 */
typedef volatile union _AON_NS_RTC_COMP_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP0;
    };
} AON_NS_RTC_COMP_0_TYPE;

/* 0x1814   0x4000_1814
    31:0    R/W RTC_CMP1                        32'b0
 */
typedef volatile union _AON_NS_RTC_COMP_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP1;
    };
} AON_NS_RTC_COMP_1_TYPE;

/* 0x1818   0x4000_1818
    31:0    R/W RTC_CMP2                        32'b0
 */
typedef volatile union _AON_NS_RTC_COMP_2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP2;
    };
} AON_NS_RTC_COMP_2_TYPE;

/* 0x181C   0x4000_181c
    31:0    R/W RTC_CMP3                        32'b0
 */
typedef volatile union _AON_NS_RTC_COMP_3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP3;
    };
} AON_NS_RTC_COMP_3_TYPE;

/* 0x1820   0x4000_1820
    31:0    R/W RTC_CMP0GT                      32'b0
 */
typedef volatile union _AON_NS_RTC_COMP0_GT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP0GT;
    };
} AON_NS_RTC_COMP0_GT_TYPE;

/* 0x1824   0x4000_1824
    31:0    R/W RTC_CMP1GT                      32'b0
 */
typedef volatile union _AON_NS_RTC_COMP1_GT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP1GT;
    };
} AON_NS_RTC_COMP1_GT_TYPE;

/* 0x1828   0x4000_1828
    31:0    R/W RTC_CMP2GT                      32'b0
 */
typedef volatile union _AON_NS_RTC_COMP2_GT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP2GT;
    };
} AON_NS_RTC_COMP2_GT_TYPE;

/* 0x182C   0x4000_182c
    31:0    R/W RTC_CMP3GT                      32'b0
 */
typedef volatile union _AON_NS_RTC_COMP3_GT_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CMP3GT;
    };
} AON_NS_RTC_COMP3_GT_TYPE;

/* 0x1830   0x4000_1830
    31:0    R   RTC_CNT                         32'b0
 */
typedef volatile union _AON_NS_RTC_CNT0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_CNT;
    };
} AON_NS_RTC_CNT0_TYPE;

/* 0x1834   0x4000_1834
    11:0    R   RTC_PRESCALE_CNT                12'b0
    31:12   R/W RTC_PRESCALE_CNT_DUMMY          20'b0
 */
typedef volatile union _AON_NS_RTC_PRESCALE_CNT0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PRESCALE_CNT: 12;
        uint32_t RTC_PRESCALE_CNT_DUMMY: 20;
    };
} AON_NS_RTC_PRESCALE_CNT0_TYPE;

/* 0x1838   0x4000_1838
    11:0    R/W RTC_PRESCALE_CMP                12'b0
    31:12   R/W RTC_PRESCALE_CMP_DUMMY          20'b0
 */
typedef volatile union _AON_NS_RTC_PRESCALE_CMP0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_PRESCALE_CMP: 12;
        uint32_t RTC_PRESCALE_CMP_DUMMY: 20;
    };
} AON_NS_RTC_PRESCALE_CMP0_TYPE;

/* 0x183C   0x4000_183c
    31:0    R/W RTC_BACKUP                      32'b0
 */
typedef volatile union _AON_NS_RTC_BACKUP_REG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_BACKUP;
    };
} AON_NS_RTC_BACKUP_REG_TYPE;

/* 0x1840   0x4000_1840
    31:0    R   RTC_RTL_VERSION                 32'h2112180A
 */
typedef volatile union _AON_NS_RTC_RTL_VERSION0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RTC_RTL_VERSION;
    };
} AON_NS_RTC_RTL_VERSION0_TYPE;

/* 0x1850   0x4000_1850
    7:0     R/W reg_lpcomp0_deb_cnt             8'b0
    10:8    R/W reg_lpcomp0_deb_div             3'b0
    11      R/W reg_lpcomp0_deb_en              1'b0
    12      R/W RSVD                            1'b0
    13      R/W reg_lpcomp0_single_output_en    1'b0
    14      R/W RSVD                            1'b0
    15      R/W RSVD                            1'b0
    16      R/W reg_lpcomp0_ie                  1'b0
    17      R/W reg_lpcomp0_src_int_en          1'b0
    18      R/W reg_lpcomp0_src_aon_int_en      1'b0
    19      R/W reg_lpcomp0_deb_sel             1'b0
    30:20   R/W LPC0_CR0_Dummy                  11'b0
    31      R/W LPC0_CR1_Dummy                  1'b0
 */
typedef volatile union _AON_NS_LPC0_CR0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_lpcomp0_deb_cnt: 8;
        uint32_t reg_lpcomp0_deb_div: 3;
        uint32_t reg_lpcomp0_deb_en: 1;
        uint32_t RSVD_2: 1;
        uint32_t reg_lpcomp0_single_output_en: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 1;
        uint32_t reg_lpcomp0_ie: 1;
        uint32_t reg_lpcomp0_src_int_en: 1;
        uint32_t reg_lpcomp0_src_aon_int_en: 1;
        uint32_t reg_lpcomp0_deb_sel: 1;
        uint32_t LPC0_CR0_Dummy: 11;
        uint32_t LPC0_CR1_Dummy: 1;
    };
} AON_NS_LPC0_CR0_TYPE;

/* 0x1854   0x4000_1854
    0       R   reg_lpcomp0_flag                1'b0
    1       R   reg_lpcomp0_out_aon_flag        1'b0
    31:2    R/W LPC0_SR_Dummy                   30'b0
 */
typedef volatile union _AON_NS_LPC0_SR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reg_lpcomp0_flag: 1;
        uint32_t reg_lpcomp0_out_aon_flag: 1;
        uint32_t LPC0_SR_Dummy: 30;
    };
} AON_NS_LPC0_SR_TYPE;

/* 0x1858   0x4000_1858
    5:0     R/W MBIAS_REG0X_SD_TUNE             6'b0
    31:6    R   RSVD                            26'b0
 */
typedef volatile union _AON_NS_LPC0_MBIAS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MBIAS_REG0X_SD_TUNE: 6;
        uint32_t RSVD: 26;
    };
} AON_NS_LPC0_MBIAS_TYPE;

/* 0x1900   0x4000_1900
    0       R/W PAD_P0_O[0]                     1'b0
    1       R/W PAD_P0_E[0]                     1'b0
    2       R/W PAD_P0_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P0_PD[0]                1'b1
    4       R/W PAD_P0_PUPDC[0]                 1'b0
    5       R/W PAD_P0_WKEN[0]                  1'b0
    6       R/W PAD_P0_WKPOL[0]                 1'b0
    7       R/W PAD_P0_E2[0]                    1'b1
    8       R/W PAD_P0_SHDN[0]                  1'b1
    9       R/W PAD_P0_S[0]                     1'b0
    10      R/W PAD_P0_DEB[0]                   1'b0
    11      R/W PAD_P0_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'h0
    15      R/W PAD_P0_O_EN[0]                  1'h1
    16      R/W PAD_P0_O[1]                     1'b0
    17      R/W PAD_P0_E[1]                     1'b0
    18      R/W PAD_P0_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P0_PD[1]                1'b1
    20      R/W PAD_P0_PUPDC[1]                 1'b0
    21      R/W PAD_P0_WKEN[1]                  1'b0
    22      R/W PAD_P0_WKPOL[1]                 1'b0
    23      R/W PAD_P0_E2[1]                    1'b1
    24      R/W PAD_P0_SHDN[1]                  1'b1
    25      R/W PAD_P0_S[1]                     1'b0
    26      R/W PAD_P0_DEB[1]                   1'b0
    27      R/W PAD_P0_HS_MUX[1]                1'b0
    28      R   RSVD                            1'b0
    29      R/W PAD_P0_1_CLK_OUT                1'b0
    30      R   RSVD                            1'h0
    31      R/W PAD_P0_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P0_0_P0_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_O_0: 1;
        uint32_t PAD_P0_E_0: 1;
        uint32_t PAD_P0_PU_EN_0: 1;
        uint32_t AON_PAD_P0_PD_0: 1;
        uint32_t PAD_P0_PUPDC_0: 1;
        uint32_t PAD_P0_WKEN_0: 1;
        uint32_t PAD_P0_WKPOL_0: 1;
        uint32_t PAD_P0_E2_0: 1;
        uint32_t PAD_P0_SHDN_0: 1;
        uint32_t PAD_P0_S_0: 1;
        uint32_t PAD_P0_DEB_0: 1;
        uint32_t PAD_P0_HS_MUX_0: 1;
        uint32_t RSVD_2: 3;
        uint32_t PAD_P0_O_EN_0: 1;
        uint32_t PAD_P0_O_1: 1;
        uint32_t PAD_P0_E_1: 1;
        uint32_t PAD_P0_PU_EN_1: 1;
        uint32_t AON_PAD_P0_PD_1: 1;
        uint32_t PAD_P0_PUPDC_1: 1;
        uint32_t PAD_P0_WKEN_1: 1;
        uint32_t PAD_P0_WKPOL_1: 1;
        uint32_t PAD_P0_E2_1: 1;
        uint32_t PAD_P0_SHDN_1: 1;
        uint32_t PAD_P0_S_1: 1;
        uint32_t PAD_P0_DEB_1: 1;
        uint32_t PAD_P0_HS_MUX_1: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_P0_1_CLK_OUT: 1;
        uint32_t RSVD: 1;
        uint32_t PAD_P0_O_EN_1: 1;
    };
} AON_NS_P0_0_P0_1_PAD_CFG_TYPE;

/* 0x1904   0x4000_1904
    0       R/W PAD_P0_O[2]                     1'b0
    1       R/W PAD_P0_E[2]                     1'b0
    2       R/W PAD_P0_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P0_PD[2]                1'b1
    4       R/W PAD_P0_PUPDC[2]                 1'b0
    5       R/W PAD_P0_WKEN[2]                  1'b0
    6       R/W PAD_P0_WKPOL[2]                 1'b0
    7       R/W PAD_P0_E2[2]                    1'b1
    8       R/W PAD_P0_SHDN[2]                  1'b1
    9       R/W PAD_P0_S[2]                     1'b0
    10      R/W PAD_P0_DEB[2]                   1'b0
    11      R/W PAD_P0_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'h0
    15      R/W PAD_P0_O_EN[2]                  1'h1
    16      R/W PAD_P0_O[3]                     1'b0
    17      R/W PAD_P0_E[3]                     1'b0
    18      R/W PAD_P0_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P0_PD[3]                1'b0
    20      R/W PAD_P0_PUPDC[3]                 1'b0
    21      R/W PAD_P0_WKEN[3]                  1'b0
    22      R/W PAD_P0_WKPOL[3]                 1'b0
    23      R/W PAD_P0_E2[3]                    1'b1
    24      R/W PAD_P0_SHDN[3]                  1'b1
    25      R/W PAD_P0_S[3]                     1'b0
    26      R/W PAD_P0_DEB[3]                   1'b0
    27      R/W PAD_P0_HS_MUX[3]                1'b0
    28      R   PAD_P0_3_I                      1'b0
    29      R/W PAD_P0_3_CLK_OUT                1'b0
    30      R   RSVD                            1'h0
    31      R/W PAD_P0_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P0_2_P0_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_O_2: 1;
        uint32_t PAD_P0_E_2: 1;
        uint32_t PAD_P0_PU_EN_2: 1;
        uint32_t AON_PAD_P0_PD_2: 1;
        uint32_t PAD_P0_PUPDC_2: 1;
        uint32_t PAD_P0_WKEN_2: 1;
        uint32_t PAD_P0_WKPOL_2: 1;
        uint32_t PAD_P0_E2_2: 1;
        uint32_t PAD_P0_SHDN_2: 1;
        uint32_t PAD_P0_S_2: 1;
        uint32_t PAD_P0_DEB_2: 1;
        uint32_t PAD_P0_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P0_O_EN_2: 1;
        uint32_t PAD_P0_O_3: 1;
        uint32_t PAD_P0_E_3: 1;
        uint32_t PAD_P0_PU_EN_3: 1;
        uint32_t AON_PAD_P0_PD_3: 1;
        uint32_t PAD_P0_PUPDC_3: 1;
        uint32_t PAD_P0_WKEN_3: 1;
        uint32_t PAD_P0_WKPOL_3: 1;
        uint32_t PAD_P0_E2_3: 1;
        uint32_t PAD_P0_SHDN_3: 1;
        uint32_t PAD_P0_S_3: 1;
        uint32_t PAD_P0_DEB_3: 1;
        uint32_t PAD_P0_HS_MUX_3: 1;
        uint32_t PAD_P0_3_I: 1;
        uint32_t PAD_P0_3_CLK_OUT: 1;
        uint32_t RSVD: 1;
        uint32_t PAD_P0_O_EN_3: 1;
    };
} AON_NS_P0_2_P0_3_PAD_CFG_TYPE;

/* 0x1908   0x4000_1908
    0       R/W PAD_P0_O[4]                     1'b0
    1       R/W PAD_P0_E[4]                     1'b0
    2       R/W PAD_P0_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P0_PD[4]                1'b1
    4       R/W PAD_P0_PUPDC[4]                 1'b0
    5       R/W PAD_P0_WKEN[4]                  1'b0
    6       R/W PAD_P0_WKPOL[4]                 1'b0
    7       R/W PAD_P0_E2[4]                    1'b1
    8       R/W PAD_P0_SHDN[4]                  1'b1
    9       R/W PAD_P0_S[4]                     1'b0
    10      R/W PAD_P0_DEB[4]                   1'b0
    11      R/W PAD_P0_HS_MUX[4]                1'b0
    12      R   RSVD                            1'b0
    13      R/W PAD_P0_4_dbg_en                 1'b0
    14      R   RSVD                            1'h0
    15      R/W PAD_P0_O_EN[4]                  1'h1
    16      R/W PAD_P0_O[5]                     1'b0
    17      R/W PAD_P0_E[5]                     1'b0
    18      R/W PAD_P0_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P0_PD[5]                1'b1
    20      R/W PAD_P0_PUPDC[5]                 1'b0
    21      R/W PAD_P0_WKEN[5]                  1'b0
    22      R/W PAD_P0_WKPOL[5]                 1'b0
    23      R/W PAD_P0_E2[5]                    1'b1
    24      R/W PAD_P0_SHDN[5]                  1'b1
    25      R/W PAD_P0_S[5]                     1'b0
    26      R/W PAD_P0_DEB[5]                   1'b0
    27      R/W PAD_P0_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P0_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P0_4_P0_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_O_4: 1;
        uint32_t PAD_P0_E_4: 1;
        uint32_t PAD_P0_PU_EN_4: 1;
        uint32_t AON_PAD_P0_PD_4: 1;
        uint32_t PAD_P0_PUPDC_4: 1;
        uint32_t PAD_P0_WKEN_4: 1;
        uint32_t PAD_P0_WKPOL_4: 1;
        uint32_t PAD_P0_E2_4: 1;
        uint32_t PAD_P0_SHDN_4: 1;
        uint32_t PAD_P0_S_4: 1;
        uint32_t PAD_P0_DEB_4: 1;
        uint32_t PAD_P0_HS_MUX_4: 1;
        uint32_t RSVD_2: 1;
        uint32_t PAD_P0_4_dbg_en: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_P0_O_EN_4: 1;
        uint32_t PAD_P0_O_5: 1;
        uint32_t PAD_P0_E_5: 1;
        uint32_t PAD_P0_PU_EN_5: 1;
        uint32_t AON_PAD_P0_PD_5: 1;
        uint32_t PAD_P0_PUPDC_5: 1;
        uint32_t PAD_P0_WKEN_5: 1;
        uint32_t PAD_P0_WKPOL_5: 1;
        uint32_t PAD_P0_E2_5: 1;
        uint32_t PAD_P0_SHDN_5: 1;
        uint32_t PAD_P0_S_5: 1;
        uint32_t PAD_P0_DEB_5: 1;
        uint32_t PAD_P0_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P0_O_EN_5: 1;
    };
} AON_NS_P0_4_P0_5_PAD_CFG_TYPE;

/* 0x190C   0x4000_190c
    0       R/W PAD_P0_O[6]                     1'b0
    1       R/W PAD_P0_E[6]                     1'b0
    2       R/W PAD_P0_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P0_PD[6]                1'b1
    4       R/W PAD_P0_PUPDC[6]                 1'b0
    5       R/W PAD_P0_WKEN[6]                  1'b0
    6       R/W PAD_P0_WKPOL[6]                 1'b0
    7       R/W PAD_P0_E2[6]                    1'b1
    8       R/W PAD_P0_SHDN[6]                  1'b1
    9       R/W PAD_P0_S[6]                     1'b0
    10      R/W PAD_P0_DEB[6]                   1'b0
    11      R/W PAD_P0_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P0_O_EN[6]                  1'h1
    16      R/W PAD_P0_O[7]                     1'b0
    17      R/W PAD_P0_E[7]                     1'b0
    18      R/W PAD_P0_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P0_PD[7]                1'b1
    20      R/W PAD_P0_PUPDC[7]                 1'b0
    21      R/W PAD_P0_WKEN[7]                  1'b0
    22      R/W PAD_P0_WKPOL[7]                 1'b0
    23      R/W PAD_P0_E2[7]                    1'b1
    24      R/W PAD_P0_SHDN[7]                  1'b1
    25      R/W PAD_P0_S[7]                     1'b0
    26      R/W PAD_P0_DEB[7]                   1'b0
    27      R/W PAD_P0_HS_MUX[7]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P0_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P0_6_P0_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_O_6: 1;
        uint32_t PAD_P0_E_6: 1;
        uint32_t PAD_P0_PU_EN_6: 1;
        uint32_t AON_PAD_P0_PD_6: 1;
        uint32_t PAD_P0_PUPDC_6: 1;
        uint32_t PAD_P0_WKEN_6: 1;
        uint32_t PAD_P0_WKPOL_6: 1;
        uint32_t PAD_P0_E2_6: 1;
        uint32_t PAD_P0_SHDN_6: 1;
        uint32_t PAD_P0_S_6: 1;
        uint32_t PAD_P0_DEB_6: 1;
        uint32_t PAD_P0_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P0_O_EN_6: 1;
        uint32_t PAD_P0_O_7: 1;
        uint32_t PAD_P0_E_7: 1;
        uint32_t PAD_P0_PU_EN_7: 1;
        uint32_t AON_PAD_P0_PD_7: 1;
        uint32_t PAD_P0_PUPDC_7: 1;
        uint32_t PAD_P0_WKEN_7: 1;
        uint32_t PAD_P0_WKPOL_7: 1;
        uint32_t PAD_P0_E2_7: 1;
        uint32_t PAD_P0_SHDN_7: 1;
        uint32_t PAD_P0_S_7: 1;
        uint32_t PAD_P0_DEB_7: 1;
        uint32_t PAD_P0_HS_MUX_7: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P0_O_EN_7: 1;
    };
} AON_NS_P0_6_P0_7_PAD_CFG_TYPE;

/* 0x1910   0x4000_1910
    0       R/W PAD_P1_O[0]                     1'b0
    1       R/W PAD_P1_E[0]                     1'b0
    2       R/W PAD_P1_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P1_PD[0]                1'b0
    4       R/W PAD_P1_PUPDC[0]                 1'b0
    5       R/W PAD_P1_WKEN[0]                  1'b0
    6       R/W PAD_P1_WKPOL[0]                 1'b0
    7       R/W PAD_P1_E2[0]                    1'b1
    8       R/W PAD_P1_SHDN[0]                  1'b1
    9       R/W PAD_P1_S[0]                     1'b1
    10      R/W PAD_P1_DEB[0]                   1'b0
    14:11   R   RSVD                            4'h0
    15      R/W PAD_P1_O_EN[0]                  1'h1
    16      R/W PAD_P1_O[1]                     1'b0
    17      R/W PAD_P1_E[1]                     1'b0
    18      R/W PAD_P1_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P1_PD[1]                1'b0
    20      R/W PAD_P1_PUPDC[1]                 1'b0
    21      R/W PAD_P1_WKEN[1]                  1'b0
    22      R/W PAD_P1_WKPOL[1]                 1'b0
    23      R/W PAD_P1_E2[1]                    1'b1
    24      R/W PAD_P1_SHDN[1]                  1'b1
    25      R/W PAD_P1_S[1]                     1'b1
    26      R/W PAD_P1_DEB[1]                   1'b0
    30:27   R   RSVD                            4'h0
    31      R/W PAD_P1_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P1_0_P1_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P1_O_0: 1;
        uint32_t PAD_P1_E_0: 1;
        uint32_t PAD_P1_PU_EN_0: 1;
        uint32_t AON_PAD_P1_PD_0: 1;
        uint32_t PAD_P1_PUPDC_0: 1;
        uint32_t PAD_P1_WKEN_0: 1;
        uint32_t PAD_P1_WKPOL_0: 1;
        uint32_t PAD_P1_E2_0: 1;
        uint32_t PAD_P1_SHDN_0: 1;
        uint32_t PAD_P1_S_0: 1;
        uint32_t PAD_P1_DEB_0: 1;
        uint32_t RSVD_1: 4;
        uint32_t PAD_P1_O_EN_0: 1;
        uint32_t PAD_P1_O_1: 1;
        uint32_t PAD_P1_E_1: 1;
        uint32_t PAD_P1_PU_EN_1: 1;
        uint32_t AON_PAD_P1_PD_1: 1;
        uint32_t PAD_P1_PUPDC_1: 1;
        uint32_t PAD_P1_WKEN_1: 1;
        uint32_t PAD_P1_WKPOL_1: 1;
        uint32_t PAD_P1_E2_1: 1;
        uint32_t PAD_P1_SHDN_1: 1;
        uint32_t PAD_P1_S_1: 1;
        uint32_t PAD_P1_DEB_1: 1;
        uint32_t RSVD: 4;
        uint32_t PAD_P1_O_EN_1: 1;
    };
} AON_NS_P1_0_P1_1_PAD_CFG_TYPE;

/* 0x1914   0x4000_1914
    0       R/W PAD_P1_O[2]                     1'b0
    1       R/W PAD_P1_E[2]                     1'b0
    2       R/W PAD_P1_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P1_PD[2]                1'b1
    4       R/W PAD_P1_PUPDC[2]                 1'b0
    5       R/W PAD_P1_WKEN[2]                  1'b0
    6       R/W PAD_P1_WKPOL[2]                 1'b0
    7       R/W PAD_P1_E2[2]                    1'b1
    8       R/W PAD_P1_SHDN[2]                  1'b1
    9       R/W PAD_P1_S[2]                     1'b0
    10      R/W PAD_P1_DEB[2]                   1'b0
    11      R/W PAD_P1_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'h0
    15      R/W PAD_P1_O_EN[2]                  1'h1
    16      R/W PAD_P1_O[3]                     1'b0
    17      R/W PAD_P1_E[3]                     1'b0
    18      R/W PAD_P1_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P1_PD[3]                1'b1
    20      R/W PAD_P1_PUPDC[3]                 1'b0
    21      R/W PAD_P1_WKEN[3]                  1'b0
    22      R/W PAD_P1_WKPOL[3]                 1'b0
    23      R/W PAD_P1_E2[3]                    1'b1
    24      R/W PAD_P1_SHDN[3]                  1'b1
    25      R/W PAD_P1_S[3]                     1'b0
    26      R/W PAD_P1_DEB[3]                   1'b0
    27      R/W PAD_P1_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'h0
    31      R/W PAD_P1_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P1_2_P1_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P1_O_2: 1;
        uint32_t PAD_P1_E_2: 1;
        uint32_t PAD_P1_PU_EN_2: 1;
        uint32_t AON_PAD_P1_PD_2: 1;
        uint32_t PAD_P1_PUPDC_2: 1;
        uint32_t PAD_P1_WKEN_2: 1;
        uint32_t PAD_P1_WKPOL_2: 1;
        uint32_t PAD_P1_E2_2: 1;
        uint32_t PAD_P1_SHDN_2: 1;
        uint32_t PAD_P1_S_2: 1;
        uint32_t PAD_P1_DEB_2: 1;
        uint32_t PAD_P1_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P1_O_EN_2: 1;
        uint32_t PAD_P1_O_3: 1;
        uint32_t PAD_P1_E_3: 1;
        uint32_t PAD_P1_PU_EN_3: 1;
        uint32_t AON_PAD_P1_PD_3: 1;
        uint32_t PAD_P1_PUPDC_3: 1;
        uint32_t PAD_P1_WKEN_3: 1;
        uint32_t PAD_P1_WKPOL_3: 1;
        uint32_t PAD_P1_E2_3: 1;
        uint32_t PAD_P1_SHDN_3: 1;
        uint32_t PAD_P1_S_3: 1;
        uint32_t PAD_P1_DEB_3: 1;
        uint32_t PAD_P1_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P1_O_EN_3: 1;
    };
} AON_NS_P1_2_P1_3_PAD_CFG_TYPE;

/* 0x1918   0x4000_1918
    0       R/W PAD_P1_O[4]                     1'b0
    1       R/W PAD_P1_E[4]                     1'b0
    2       R/W PAD_P1_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P1_PD[4]                1'b1
    4       R/W PAD_P1_PUPDC[4]                 1'b0
    5       R/W PAD_P1_WKEN[4]                  1'b0
    6       R/W PAD_P1_WKPOL[4]                 1'b0
    7       R/W PAD_P1_E2[4]                    1'b1
    8       R/W PAD_P1_SHDN[4]                  1'b1
    9       R/W PAD_P1_S[4]                     1'b0
    10      R/W PAD_P1_DEB[4]                   1'b0
    11      R/W PAD_P1_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'h0
    15      R/W PAD_P1_O_EN[4]                  1'h1
    16      R/W PAD_P1_O[5]                     1'b0
    17      R/W PAD_P1_E[5]                     1'b0
    18      R/W PAD_P1_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P1_PD[5]                1'b0
    20      R/W PAD_P1_PUPDC[5]                 1'b0
    21      R/W PAD_P1_WKEN[5]                  1'b0
    22      R/W PAD_P1_WKPOL[5]                 1'b0
    23      R/W PAD_P1_E2[5]                    1'b1
    24      R/W PAD_P1_SHDN[5]                  1'b1
    25      R/W PAD_P1_S[5]                     1'b0
    26      R/W PAD_P1_DEB[5]                   1'b0
    27      R/W PAD_P1_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P1_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P1_4_P1_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P1_O_4: 1;
        uint32_t PAD_P1_E_4: 1;
        uint32_t PAD_P1_PU_EN_4: 1;
        uint32_t AON_PAD_P1_PD_4: 1;
        uint32_t PAD_P1_PUPDC_4: 1;
        uint32_t PAD_P1_WKEN_4: 1;
        uint32_t PAD_P1_WKPOL_4: 1;
        uint32_t PAD_P1_E2_4: 1;
        uint32_t PAD_P1_SHDN_4: 1;
        uint32_t PAD_P1_S_4: 1;
        uint32_t PAD_P1_DEB_4: 1;
        uint32_t PAD_P1_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P1_O_EN_4: 1;
        uint32_t PAD_P1_O_5: 1;
        uint32_t PAD_P1_E_5: 1;
        uint32_t PAD_P1_PU_EN_5: 1;
        uint32_t AON_PAD_P1_PD_5: 1;
        uint32_t PAD_P1_PUPDC_5: 1;
        uint32_t PAD_P1_WKEN_5: 1;
        uint32_t PAD_P1_WKPOL_5: 1;
        uint32_t PAD_P1_E2_5: 1;
        uint32_t PAD_P1_SHDN_5: 1;
        uint32_t PAD_P1_S_5: 1;
        uint32_t PAD_P1_DEB_5: 1;
        uint32_t PAD_P1_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P1_O_EN_5: 1;
    };
} AON_NS_P1_4_P1_5_PAD_CFG_TYPE;

/* 0x191C   0x4000_191c
    0       R/W PAD_P1_O[6]                     1'b0
    1       R/W PAD_P1_E[6]                     1'b0
    2       R/W PAD_P1_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P1_PD[6]                1'b1
    4       R/W PAD_P1_PUPDC[6]                 1'b0
    5       R/W PAD_P1_WKEN[6]                  1'b0
    6       R/W PAD_P1_WKPOL[6]                 1'b0
    7       R/W PAD_P1_E2[6]                    1'b1
    8       R/W PAD_P1_SHDN[6]                  1'b1
    9       R/W PAD_P1_S[6]                     1'b0
    10      R/W PAD_P1_DEB[6]                   1'b0
    11      R/W PAD_P1_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P1_O_EN[6]                  1'h1
    16      R/W PAD_P1_O[7]                     1'b0
    17      R/W PAD_P1_E[7]                     1'b0
    18      R/W PAD_P1_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P1_PD[7]                1'b1
    20      R/W PAD_P1_PUPDC[7]                 1'b0
    21      R/W PAD_P1_WKEN[7]                  1'b0
    22      R/W PAD_P1_WKPOL[7]                 1'b0
    23      R/W PAD_P1_E2[7]                    1'b1
    24      R/W PAD_P1_SHDN[7]                  1'b1
    25      R/W PAD_P1_S[7]                     1'b0
    26      R/W PAD_P1_DEB[7]                   1'b0
    27      R/W PAD_P1_HS_MUX[7]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P1_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P1_6_P1_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P1_O_6: 1;
        uint32_t PAD_P1_E_6: 1;
        uint32_t PAD_P1_PU_EN_6: 1;
        uint32_t AON_PAD_P1_PD_6: 1;
        uint32_t PAD_P1_PUPDC_6: 1;
        uint32_t PAD_P1_WKEN_6: 1;
        uint32_t PAD_P1_WKPOL_6: 1;
        uint32_t PAD_P1_E2_6: 1;
        uint32_t PAD_P1_SHDN_6: 1;
        uint32_t PAD_P1_S_6: 1;
        uint32_t PAD_P1_DEB_6: 1;
        uint32_t PAD_P1_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P1_O_EN_6: 1;
        uint32_t PAD_P1_O_7: 1;
        uint32_t PAD_P1_E_7: 1;
        uint32_t PAD_P1_PU_EN_7: 1;
        uint32_t AON_PAD_P1_PD_7: 1;
        uint32_t PAD_P1_PUPDC_7: 1;
        uint32_t PAD_P1_WKEN_7: 1;
        uint32_t PAD_P1_WKPOL_7: 1;
        uint32_t PAD_P1_E2_7: 1;
        uint32_t PAD_P1_SHDN_7: 1;
        uint32_t PAD_P1_S_7: 1;
        uint32_t PAD_P1_DEB_7: 1;
        uint32_t PAD_P1_HS_MUX_7: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P1_O_EN_7: 1;
    };
} AON_NS_P1_6_P1_7_PAD_CFG_TYPE;

/* 0x1920   0x4000_1920
    0       R/W PAD_P2_O[0]                     1'b0
    1       R/W PAD_P2_E[0]                     1'b0
    2       R/W PAD_P2_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P2_PD[0]                1'b1
    4       R/W PAD_P2_PUPDC[0]                 1'b0
    5       R/W PAD_P2_WKEN[0]                  1'b0
    6       R/W PAD_P2_WKPOL[0]                 1'b0
    7       R/W PAD_P2_E2[0]                    1'b1
    8       R/W PAD_P2_SHDN[0]                  1'b1
    9       R/W PAD_P2_S[0]                     1'b0
    10      R/W PAD_P2_DEB[0]                   1'b0
    11      R/W PAD_P2_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P2_O_EN[0]                  1'h1
    16      R/W PAD_P2_O[1]                     1'b0
    17      R/W PAD_P2_E[1]                     1'b0
    18      R/W PAD_P2_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P2_PD[1]                1'b1
    20      R/W PAD_P2_PUPDC[1]                 1'b0
    21      R/W PAD_P2_WKEN[1]                  1'b0
    22      R/W PAD_P2_WKPOL[1]                 1'b0
    23      R/W PAD_P2_E2[1]                    1'b1
    24      R/W PAD_P2_SHDN[1]                  1'b1
    25      R/W PAD_P2_S[1]                     1'b0
    26      R/W PAD_P2_DEB[1]                   1'b0
    27      R/W PAD_P2_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P2_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P2_0_P2_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P2_O_0: 1;
        uint32_t PAD_P2_E_0: 1;
        uint32_t PAD_P2_PU_EN_0: 1;
        uint32_t AON_PAD_P2_PD_0: 1;
        uint32_t PAD_P2_PUPDC_0: 1;
        uint32_t PAD_P2_WKEN_0: 1;
        uint32_t PAD_P2_WKPOL_0: 1;
        uint32_t PAD_P2_E2_0: 1;
        uint32_t PAD_P2_SHDN_0: 1;
        uint32_t PAD_P2_S_0: 1;
        uint32_t PAD_P2_DEB_0: 1;
        uint32_t PAD_P2_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P2_O_EN_0: 1;
        uint32_t PAD_P2_O_1: 1;
        uint32_t PAD_P2_E_1: 1;
        uint32_t PAD_P2_PU_EN_1: 1;
        uint32_t AON_PAD_P2_PD_1: 1;
        uint32_t PAD_P2_PUPDC_1: 1;
        uint32_t PAD_P2_WKEN_1: 1;
        uint32_t PAD_P2_WKPOL_1: 1;
        uint32_t PAD_P2_E2_1: 1;
        uint32_t PAD_P2_SHDN_1: 1;
        uint32_t PAD_P2_S_1: 1;
        uint32_t PAD_P2_DEB_1: 1;
        uint32_t PAD_P2_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P2_O_EN_1: 1;
    };
} AON_NS_P2_0_P2_1_PAD_CFG_TYPE;

/* 0x1924   0x4000_1924
    0       R/W PAD_P2_O[2]                     1'b0
    1       R/W PAD_P2_E[2]                     1'b0
    2       R/W PAD_P2_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P2_PD[2]                1'b1
    4       R/W PAD_P2_PUPDC[2]                 1'b0
    5       R/W PAD_P2_WKEN[2]                  1'b0
    6       R/W PAD_P2_WKPOL[2]                 1'b0
    7       R/W PAD_P2_E2[2]                    1'b1
    8       R/W PAD_P2_SHDN[2]                  1'b1
    9       R/W PAD_P2_S[2]                     1'b0
    10      R/W PAD_P2_DEB[2]                   1'b0
    14:11   R   RSVD                            4'b0
    15      R/W PAD_P2_O_EN[2]                  1'h1
    16      R/W PAD_P2_O[3]                     1'b0
    17      R/W PAD_P2_E[3]                     1'b0
    18      R/W PAD_P2_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P2_PD[3]                1'b1
    20      R/W PAD_P2_PUPDC[3]                 1'b0
    21      R/W PAD_P2_WKEN[3]                  1'b0
    22      R/W PAD_P2_WKPOL[3]                 1'b0
    23      R/W PAD_P2_E2[3]                    1'b1
    24      R/W PAD_P2_SHDN[3]                  1'b1
    25      R/W PAD_P2_S[3]                     1'b0
    26      R/W PAD_P2_DEB[3]                   1'b0
    30:27   R   RSVD                            4'b0
    31      R/W PAD_P2_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P2_2_P2_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P2_O_2: 1;
        uint32_t PAD_P2_E_2: 1;
        uint32_t PAD_P2_PU_EN_2: 1;
        uint32_t AON_PAD_P2_PD_2: 1;
        uint32_t PAD_P2_PUPDC_2: 1;
        uint32_t PAD_P2_WKEN_2: 1;
        uint32_t PAD_P2_WKPOL_2: 1;
        uint32_t PAD_P2_E2_2: 1;
        uint32_t PAD_P2_SHDN_2: 1;
        uint32_t PAD_P2_S_2: 1;
        uint32_t PAD_P2_DEB_2: 1;
        uint32_t RSVD_1: 4;
        uint32_t PAD_P2_O_EN_2: 1;
        uint32_t PAD_P2_O_3: 1;
        uint32_t PAD_P2_E_3: 1;
        uint32_t PAD_P2_PU_EN_3: 1;
        uint32_t AON_PAD_P2_PD_3: 1;
        uint32_t PAD_P2_PUPDC_3: 1;
        uint32_t PAD_P2_WKEN_3: 1;
        uint32_t PAD_P2_WKPOL_3: 1;
        uint32_t PAD_P2_E2_3: 1;
        uint32_t PAD_P2_SHDN_3: 1;
        uint32_t PAD_P2_S_3: 1;
        uint32_t PAD_P2_DEB_3: 1;
        uint32_t RSVD: 4;
        uint32_t PAD_P2_O_EN_3: 1;
    };
} AON_NS_P2_2_P2_3_PAD_CFG_TYPE;

/* 0x1928   0x4000_1928
    0       R/W PAD_P2_O[4]                     1'b0
    1       R/W PAD_P2_E[4]                     1'b0
    2       R/W PAD_P2_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P2_PD[4]                1'b1
    4       R/W PAD_P2_PUPDC[4]                 1'b0
    5       R/W PAD_P2_WKEN[4]                  1'b0
    6       R/W PAD_P2_WKPOL[4]                 1'b0
    7       R/W PAD_P2_E2[4]                    1'b1
    8       R/W PAD_P2_SHDN[4]                  1'b1
    9       R/W PAD_P2_S[4]                     1'b0
    10      R/W PAD_P2_DEB[4]                   1'b0
    11      R   RSVD                            1'b0
    14:12   R/W PAD_P2_4_CFG                    3'h0
    15      R/W PAD_P2_O_EN[4]                  1'h1
    16      R/W PAD_P2_O[5]                     1'b0
    17      R/W PAD_P2_E[5]                     1'b0
    18      R/W PAD_P2_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P2_PD[5]                1'b1
    20      R/W PAD_P2_PUPDC[5]                 1'b0
    21      R/W PAD_P2_WKEN[5]                  1'b0
    22      R/W PAD_P2_WKPOL[5]                 1'b0
    23      R/W PAD_P2_E2[5]                    1'b1
    24      R/W PAD_P2_SHDN[5]                  1'b1
    25      R/W PAD_P2_S[5]                     1'b0
    26      R/W PAD_P2_DEB[5]                   1'b0
    28:27   R   RSVD                            2'b0
    30:29   R/W PAD_P2_5_CFG                    2'h0
    31      R/W PAD_P2_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P2_4_P2_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P2_O_4: 1;
        uint32_t PAD_P2_E_4: 1;
        uint32_t PAD_P2_PU_EN_4: 1;
        uint32_t AON_PAD_P2_PD_4: 1;
        uint32_t PAD_P2_PUPDC_4: 1;
        uint32_t PAD_P2_WKEN_4: 1;
        uint32_t PAD_P2_WKPOL_4: 1;
        uint32_t PAD_P2_E2_4: 1;
        uint32_t PAD_P2_SHDN_4: 1;
        uint32_t PAD_P2_S_4: 1;
        uint32_t PAD_P2_DEB_4: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_P2_4_CFG: 3;
        uint32_t PAD_P2_O_EN_4: 1;
        uint32_t PAD_P2_O_5: 1;
        uint32_t PAD_P2_E_5: 1;
        uint32_t PAD_P2_PU_EN_5: 1;
        uint32_t AON_PAD_P2_PD_5: 1;
        uint32_t PAD_P2_PUPDC_5: 1;
        uint32_t PAD_P2_WKEN_5: 1;
        uint32_t PAD_P2_WKPOL_5: 1;
        uint32_t PAD_P2_E2_5: 1;
        uint32_t PAD_P2_SHDN_5: 1;
        uint32_t PAD_P2_S_5: 1;
        uint32_t PAD_P2_DEB_5: 1;
        uint32_t RSVD: 2;
        uint32_t PAD_P2_5_CFG: 2;
        uint32_t PAD_P2_O_EN_5: 1;
    };
} AON_NS_P2_4_P2_5_PAD_CFG_TYPE;

/* 0x192C   0x4000_192c
    0       R/W PAD_P2_O[6]                     1'b0
    1       R/W PAD_P2_E[6]                     1'b0
    2       R/W PAD_P2_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P2_PD[6]                1'b1
    4       R/W PAD_P2_PUPDC[6]                 1'b0
    5       R/W PAD_P2_WKEN[6]                  1'b0
    6       R/W PAD_P2_WKPOL[6]                 1'b0
    7       R/W PAD_P2_E2[6]                    1'b1
    8       R/W PAD_P2_SHDN[6]                  1'b1
    9       R/W PAD_P2_S[6]                     1'b0
    10      R/W PAD_P2_DEB[6]                   1'b0
    12:11   R   RSVD                            2'b0
    13      R/W PAD_P2_6_dbg_en                 1'b0
    14      R   RSVD                            1'h0
    15      R/W PAD_P2_O_EN[6]                  1'h1
    16      R/W PAD_P2_O[7]                     1'b0
    17      R/W PAD_P2_E[7]                     1'b0
    18      R/W PAD_P2_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P2_PD[7]                1'b1
    20      R/W PAD_P2_PUPDC[7]                 1'b0
    21      R/W PAD_P2_WKEN[7]                  1'b0
    22      R/W PAD_P2_WKPOL[7]                 1'b0
    23      R/W PAD_P2_E2[7]                    1'b1
    24      R/W PAD_P2_SHDN[7]                  1'b1
    25      R/W PAD_P2_S[7]                     1'b0
    26      R/W PAD_P2_DEB[7]                   1'b0
    28:27   R   RSVD                            2'b0
    29      R/W PAD_P2_7_dbg_en                 1'b0
    30      R   RSVD                            1'h0
    31      R/W PAD_P2_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P2_6_P2_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P2_O_6: 1;
        uint32_t PAD_P2_E_6: 1;
        uint32_t PAD_P2_PU_EN_6: 1;
        uint32_t AON_PAD_P2_PD_6: 1;
        uint32_t PAD_P2_PUPDC_6: 1;
        uint32_t PAD_P2_WKEN_6: 1;
        uint32_t PAD_P2_WKPOL_6: 1;
        uint32_t PAD_P2_E2_6: 1;
        uint32_t PAD_P2_SHDN_6: 1;
        uint32_t PAD_P2_S_6: 1;
        uint32_t PAD_P2_DEB_6: 1;
        uint32_t RSVD_3: 2;
        uint32_t PAD_P2_6_dbg_en: 1;
        uint32_t RSVD_2: 1;
        uint32_t PAD_P2_O_EN_6: 1;
        uint32_t PAD_P2_O_7: 1;
        uint32_t PAD_P2_E_7: 1;
        uint32_t PAD_P2_PU_EN_7: 1;
        uint32_t AON_PAD_P2_PD_7: 1;
        uint32_t PAD_P2_PUPDC_7: 1;
        uint32_t PAD_P2_WKEN_7: 1;
        uint32_t PAD_P2_WKPOL_7: 1;
        uint32_t PAD_P2_E2_7: 1;
        uint32_t PAD_P2_SHDN_7: 1;
        uint32_t PAD_P2_S_7: 1;
        uint32_t PAD_P2_DEB_7: 1;
        uint32_t RSVD_1: 2;
        uint32_t PAD_P2_7_dbg_en: 1;
        uint32_t RSVD: 1;
        uint32_t PAD_P2_O_EN_7: 1;
    };
} AON_NS_P2_6_P2_7_PAD_CFG_TYPE;

/* 0x1930   0x4000_1930
    0       R/W PAD_P3_O[0]                     1'b0
    1       R/W PAD_P3_E[0]                     1'b0
    2       R/W PAD_P3_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P3_PD[0]                1'b0
    4       R/W PAD_P3_PUPDC[0]                 1'b0
    5       R/W PAD_P3_WKEN[0]                  1'b0
    6       R/W PAD_P3_WKPOL[0]                 1'b0
    7       R/W PAD_P3_E2[0]                    1'b1
    8       R/W PAD_P3_SHDN[0]                  1'b1
    9       R/W PAD_P3_S[0]                     1'b0
    10      R/W PAD_P3_DEB[0]                   1'b0
    14:11   R   RSVD                            4'b0
    15      R/W PAD_P3_O_EN[0]                  1'h1
    16      R/W PAD_P3_O[1]                     1'b0
    17      R/W PAD_P3_E[1]                     1'b0
    18      R/W PAD_P3_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P3_PD[1]                1'b0
    20      R/W PAD_P3_PUPDC[1]                 1'b0
    21      R/W PAD_P3_WKEN[1]                  1'b0
    22      R/W PAD_P3_WKPOL[1]                 1'b0
    23      R/W PAD_P3_E2[1]                    1'b1
    24      R/W PAD_P3_SHDN[1]                  1'b1
    25      R/W PAD_P3_S[1]                     1'b0
    26      R/W PAD_P3_DEB[1]                   1'b0
    30:27   R   RSVD                            4'b0
    31      R/W PAD_P3_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P3_0_P3_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P3_O_0: 1;
        uint32_t PAD_P3_E_0: 1;
        uint32_t PAD_P3_PU_EN_0: 1;
        uint32_t AON_PAD_P3_PD_0: 1;
        uint32_t PAD_P3_PUPDC_0: 1;
        uint32_t PAD_P3_WKEN_0: 1;
        uint32_t PAD_P3_WKPOL_0: 1;
        uint32_t PAD_P3_E2_0: 1;
        uint32_t PAD_P3_SHDN_0: 1;
        uint32_t PAD_P3_S_0: 1;
        uint32_t PAD_P3_DEB_0: 1;
        uint32_t RSVD_1: 4;
        uint32_t PAD_P3_O_EN_0: 1;
        uint32_t PAD_P3_O_1: 1;
        uint32_t PAD_P3_E_1: 1;
        uint32_t PAD_P3_PU_EN_1: 1;
        uint32_t AON_PAD_P3_PD_1: 1;
        uint32_t PAD_P3_PUPDC_1: 1;
        uint32_t PAD_P3_WKEN_1: 1;
        uint32_t PAD_P3_WKPOL_1: 1;
        uint32_t PAD_P3_E2_1: 1;
        uint32_t PAD_P3_SHDN_1: 1;
        uint32_t PAD_P3_S_1: 1;
        uint32_t PAD_P3_DEB_1: 1;
        uint32_t RSVD: 4;
        uint32_t PAD_P3_O_EN_1: 1;
    };
} AON_NS_P3_0_P3_1_PAD_CFG_TYPE;

/* 0x1934   0x4000_1934
    0       R/W PAD_P3_O[2]                     1'b0
    1       R/W PAD_P3_E[2]                     1'b0
    2       R/W PAD_P3_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P3_PD[2]                1'b1
    4       R/W PAD_P3_PUPDC[2]                 1'b0
    5       R/W PAD_P3_WKEN[2]                  1'b0
    6       R/W PAD_P3_WKPOL[2]                 1'b0
    7       R/W PAD_P3_E2[2]                    1'b1
    8       R/W PAD_P3_SHDN[2]                  1'b1
    9       R/W PAD_P3_S[2]                     1'b0
    10      R/W PAD_P3_DEB[2]                   1'b0
    11      R/W PAD_P3_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P3_O_EN[2]                  1'h1
    16      R/W PAD_P3_O[3]                     1'b0
    17      R/W PAD_P3_E[3]                     1'b0
    18      R/W PAD_P3_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P3_PD[3]                1'b1
    20      R/W PAD_P3_PUPDC[3]                 1'b0
    21      R/W PAD_P3_WKEN[3]                  1'b0
    22      R/W PAD_P3_WKPOL[3]                 1'b0
    23      R/W PAD_P3_E2[3]                    1'b1
    24      R/W PAD_P3_SHDN[3]                  1'b1
    25      R/W PAD_P3_S[3]                     1'b0
    26      R/W PAD_P3_DEB[3]                   1'b0
    27      R/W PAD_P3_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P3_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P3_2_P3_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P3_O_2: 1;
        uint32_t PAD_P3_E_2: 1;
        uint32_t PAD_P3_PU_EN_2: 1;
        uint32_t AON_PAD_P3_PD_2: 1;
        uint32_t PAD_P3_PUPDC_2: 1;
        uint32_t PAD_P3_WKEN_2: 1;
        uint32_t PAD_P3_WKPOL_2: 1;
        uint32_t PAD_P3_E2_2: 1;
        uint32_t PAD_P3_SHDN_2: 1;
        uint32_t PAD_P3_S_2: 1;
        uint32_t PAD_P3_DEB_2: 1;
        uint32_t PAD_P3_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P3_O_EN_2: 1;
        uint32_t PAD_P3_O_3: 1;
        uint32_t PAD_P3_E_3: 1;
        uint32_t PAD_P3_PU_EN_3: 1;
        uint32_t AON_PAD_P3_PD_3: 1;
        uint32_t PAD_P3_PUPDC_3: 1;
        uint32_t PAD_P3_WKEN_3: 1;
        uint32_t PAD_P3_WKPOL_3: 1;
        uint32_t PAD_P3_E2_3: 1;
        uint32_t PAD_P3_SHDN_3: 1;
        uint32_t PAD_P3_S_3: 1;
        uint32_t PAD_P3_DEB_3: 1;
        uint32_t PAD_P3_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P3_O_EN_3: 1;
    };
} AON_NS_P3_2_P3_3_PAD_CFG_TYPE;

/* 0x1938   0x4000_1938
    0       R/W PAD_P3_O[4]                     1'b0
    1       R/W PAD_P3_E[4]                     1'b0
    2       R/W PAD_P3_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P3_PD[4]                1'b1
    4       R/W PAD_P3_PUPDC[4]                 1'b0
    5       R/W PAD_P3_WKEN[4]                  1'b0
    6       R/W PAD_P3_WKPOL[4]                 1'b0
    7       R/W PAD_P3_E2[4]                    1'b1
    8       R/W PAD_P3_SHDN[4]                  1'b1
    9       R/W PAD_P3_S[4]                     1'b0
    10      R/W PAD_P3_DEB[4]                   1'b0
    11      R/W PAD_P3_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P3_O_EN[4]                  1'h1
    16      R/W PAD_P3_O[5]                     1'b0
    17      R/W PAD_P3_E[5]                     1'b0
    18      R/W PAD_P3_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P3_PD[5]                1'b1
    20      R/W PAD_P3_PUPDC[5]                 1'b0
    21      R/W PAD_P3_WKEN[5]                  1'b0
    22      R/W PAD_P3_WKPOL[5]                 1'b0
    23      R/W PAD_P3_E2[5]                    1'b1
    24      R/W PAD_P3_SHDN[5]                  1'b1
    25      R/W PAD_P3_S[5]                     1'b0
    26      R/W PAD_P3_DEB[5]                   1'b0
    27      R/W PAD_P3_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P3_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P3_4_P3_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P3_O_4: 1;
        uint32_t PAD_P3_E_4: 1;
        uint32_t PAD_P3_PU_EN_4: 1;
        uint32_t AON_PAD_P3_PD_4: 1;
        uint32_t PAD_P3_PUPDC_4: 1;
        uint32_t PAD_P3_WKEN_4: 1;
        uint32_t PAD_P3_WKPOL_4: 1;
        uint32_t PAD_P3_E2_4: 1;
        uint32_t PAD_P3_SHDN_4: 1;
        uint32_t PAD_P3_S_4: 1;
        uint32_t PAD_P3_DEB_4: 1;
        uint32_t PAD_P3_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P3_O_EN_4: 1;
        uint32_t PAD_P3_O_5: 1;
        uint32_t PAD_P3_E_5: 1;
        uint32_t PAD_P3_PU_EN_5: 1;
        uint32_t AON_PAD_P3_PD_5: 1;
        uint32_t PAD_P3_PUPDC_5: 1;
        uint32_t PAD_P3_WKEN_5: 1;
        uint32_t PAD_P3_WKPOL_5: 1;
        uint32_t PAD_P3_E2_5: 1;
        uint32_t PAD_P3_SHDN_5: 1;
        uint32_t PAD_P3_S_5: 1;
        uint32_t PAD_P3_DEB_5: 1;
        uint32_t PAD_P3_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P3_O_EN_5: 1;
    };
} AON_NS_P3_4_P3_5_PAD_CFG_TYPE;

/* 0x193C   0x4000_193c
    0       R/W PAD_P3_O[6]                     1'b0
    1       R/W PAD_P3_E[6]                     1'b0
    2       R/W PAD_P3_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P3_PD[6]                1'b1
    4       R/W PAD_P3_PUPDC[6]                 1'b0
    5       R/W PAD_P3_WKEN[6]                  1'b0
    6       R/W PAD_P3_WKPOL[6]                 1'b0
    7       R/W PAD_P3_E2[6]                    1'b1
    8       R/W PAD_P3_SHDN[6]                  1'b1
    9       R/W PAD_P3_S[6]                     1'b0
    10      R/W PAD_P3_DEB[6]                   1'b0
    11      R/W PAD_P3_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P3_O_EN[6]                  1'h1
    16      R/W PAD_P3_O[7]                     1'b0
    17      R/W PAD_P3_E[7]                     1'b0
    18      R/W PAD_P3_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P3_PD[7]                1'b1
    20      R/W PAD_P3_PUPDC[7]                 1'b0
    21      R/W PAD_P3_WKEN[7]                  1'b0
    22      R/W PAD_P3_WKPOL[7]                 1'b0
    23      R/W PAD_P3_E2[7]                    1'b1
    24      R/W PAD_P3_SHDN[7]                  1'b1
    25      R/W PAD_P3_S[7]                     1'b0
    26      R/W PAD_P3_DEB[7]                   1'b0
    27      R/W PAD_P3_HS_MUX[7]                1'b0
    29:28   R   RSVD                            2'b0
    30      R/W PAD_P3_7_CFG                    1'h0
    31      R/W PAD_P3_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P3_6_P3_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P3_O_6: 1;
        uint32_t PAD_P3_E_6: 1;
        uint32_t PAD_P3_PU_EN_6: 1;
        uint32_t AON_PAD_P3_PD_6: 1;
        uint32_t PAD_P3_PUPDC_6: 1;
        uint32_t PAD_P3_WKEN_6: 1;
        uint32_t PAD_P3_WKPOL_6: 1;
        uint32_t PAD_P3_E2_6: 1;
        uint32_t PAD_P3_SHDN_6: 1;
        uint32_t PAD_P3_S_6: 1;
        uint32_t PAD_P3_DEB_6: 1;
        uint32_t PAD_P3_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P3_O_EN_6: 1;
        uint32_t PAD_P3_O_7: 1;
        uint32_t PAD_P3_E_7: 1;
        uint32_t PAD_P3_PU_EN_7: 1;
        uint32_t AON_PAD_P3_PD_7: 1;
        uint32_t PAD_P3_PUPDC_7: 1;
        uint32_t PAD_P3_WKEN_7: 1;
        uint32_t PAD_P3_WKPOL_7: 1;
        uint32_t PAD_P3_E2_7: 1;
        uint32_t PAD_P3_SHDN_7: 1;
        uint32_t PAD_P3_S_7: 1;
        uint32_t PAD_P3_DEB_7: 1;
        uint32_t PAD_P3_HS_MUX_7: 1;
        uint32_t RSVD: 2;
        uint32_t PAD_P3_7_CFG: 1;
        uint32_t PAD_P3_O_EN_7: 1;
    };
} AON_NS_P3_6_P3_7_PAD_CFG_TYPE;

/* 0x1940   0x4000_1940
    0       R/W PAD_P4_O[0]                     1'b0
    1       R/W PAD_P4_E[0]                     1'b0
    2       R/W PAD_P4_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P4_PD[0]                1'b1
    4       R/W PAD_P4_PUPDC[0]                 1'b0
    5       R/W PAD_P4_WKEN[0]                  1'b0
    6       R/W PAD_P4_WKPOL[0]                 1'b0
    7       R/W PAD_P4_E2[0]                    1'b1
    8       R/W PAD_P4_SHDN[0]                  1'b1
    9       R/W PAD_P4_S[0]                     1'b0
    10      R/W PAD_P4_DEB[0]                   1'b0
    11      R/W PAD_P4_HS_MUX[0]                1'b0
    13:12   R/W PAD_P4_0_CFG                    2'h0
    14      R/W PAD_P4_O_EN[0]                  1'h1
    15      R   RSVD                            1'b0
    16      R/W PAD_P4_O[1]                     1'b0
    17      R/W PAD_P4_E[1]                     1'b0
    18      R/W PAD_P4_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P4_PD[1]                1'b1
    20      R/W PAD_P4_PUPDC[1]                 1'b0
    21      R/W PAD_P4_WKEN[1]                  1'b0
    22      R/W PAD_P4_WKPOL[1]                 1'b0
    23      R/W PAD_P4_E2[1]                    1'b1
    24      R/W PAD_P4_SHDN[1]                  1'b1
    25      R/W PAD_P4_S[1]                     1'b0
    26      R/W PAD_P4_DEB[1]                   1'b0
    27      R/W PAD_P4_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P4_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P4_0_P4_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_O_0: 1;
        uint32_t PAD_P4_E_0: 1;
        uint32_t PAD_P4_PU_EN_0: 1;
        uint32_t AON_PAD_P4_PD_0: 1;
        uint32_t PAD_P4_PUPDC_0: 1;
        uint32_t PAD_P4_WKEN_0: 1;
        uint32_t PAD_P4_WKPOL_0: 1;
        uint32_t PAD_P4_E2_0: 1;
        uint32_t PAD_P4_SHDN_0: 1;
        uint32_t PAD_P4_S_0: 1;
        uint32_t PAD_P4_DEB_0: 1;
        uint32_t PAD_P4_HS_MUX_0: 1;
        uint32_t PAD_P4_0_CFG: 2;
        uint32_t PAD_P4_O_EN_0: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_P4_O_1: 1;
        uint32_t PAD_P4_E_1: 1;
        uint32_t PAD_P4_PU_EN_1: 1;
        uint32_t AON_PAD_P4_PD_1: 1;
        uint32_t PAD_P4_PUPDC_1: 1;
        uint32_t PAD_P4_WKEN_1: 1;
        uint32_t PAD_P4_WKPOL_1: 1;
        uint32_t PAD_P4_E2_1: 1;
        uint32_t PAD_P4_SHDN_1: 1;
        uint32_t PAD_P4_S_1: 1;
        uint32_t PAD_P4_DEB_1: 1;
        uint32_t PAD_P4_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P4_O_EN_1: 1;
    };
} AON_NS_P4_0_P4_1_PAD_CFG_TYPE;

/* 0x1944   0x4000_1944
    0       R/W PAD_P4_O[2]                     1'b0
    1       R/W PAD_P4_E[2]                     1'b0
    2       R/W PAD_P4_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P4_PD[2]                1'b1
    4       R/W PAD_P4_PUPDC[2]                 1'b0
    5       R/W PAD_P4_WKEN[2]                  1'b0
    6       R/W PAD_P4_WKPOL[2]                 1'b0
    7       R/W PAD_P4_E2[2]                    1'b1
    8       R/W PAD_P4_SHDN[2]                  1'b1
    9       R/W PAD_P4_S[2]                     1'b0
    10      R/W PAD_P4_DEB[2]                   1'b0
    11      R/W PAD_P4_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P4_O_EN[2]                  1'h1
    16      R/W PAD_P4_O[3]                     1'b0
    17      R/W PAD_P4_E[3]                     1'b0
    18      R/W PAD_P4_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P4_PD[3]                1'b0
    20      R/W PAD_P4_PUPDC[3]                 1'b0
    21      R/W PAD_P4_WKEN[3]                  1'b0
    22      R/W PAD_P4_WKPOL[3]                 1'b0
    23      R/W PAD_P4_E2[3]                    1'b1
    24      R/W PAD_P4_SHDN[3]                  1'b1
    25      R/W PAD_P4_S[3]                     1'b0
    26      R/W PAD_P4_DEB[3]                   1'b0
    27      R/W PAD_P4_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P4_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P4_2_P4_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_O_2: 1;
        uint32_t PAD_P4_E_2: 1;
        uint32_t PAD_P4_PU_EN_2: 1;
        uint32_t AON_PAD_P4_PD_2: 1;
        uint32_t PAD_P4_PUPDC_2: 1;
        uint32_t PAD_P4_WKEN_2: 1;
        uint32_t PAD_P4_WKPOL_2: 1;
        uint32_t PAD_P4_E2_2: 1;
        uint32_t PAD_P4_SHDN_2: 1;
        uint32_t PAD_P4_S_2: 1;
        uint32_t PAD_P4_DEB_2: 1;
        uint32_t PAD_P4_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P4_O_EN_2: 1;
        uint32_t PAD_P4_O_3: 1;
        uint32_t PAD_P4_E_3: 1;
        uint32_t PAD_P4_PU_EN_3: 1;
        uint32_t AON_PAD_P4_PD_3: 1;
        uint32_t PAD_P4_PUPDC_3: 1;
        uint32_t PAD_P4_WKEN_3: 1;
        uint32_t PAD_P4_WKPOL_3: 1;
        uint32_t PAD_P4_E2_3: 1;
        uint32_t PAD_P4_SHDN_3: 1;
        uint32_t PAD_P4_S_3: 1;
        uint32_t PAD_P4_DEB_3: 1;
        uint32_t PAD_P4_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P4_O_EN_3: 1;
    };
} AON_NS_P4_2_P4_3_PAD_CFG_TYPE;

/* 0x1948   0x4000_1948
    0       R/W PAD_32K_XI_O                    1'b0
    1       R/W PAD_32K_XI_E                    1'b0
    2       R/W PAD_32K_XI_PU_EN                1'b1
    3       R/W AON_PAD_32K_XI_PD               1'b1
    4       R/W PAD_32K_XI_PUPDC                1'b0
    5       R/W PAD_32K_XI_WKEN                 1'b0
    6       R/W PAD_32K_XI_WKPOL                1'b0
    7       R/W PAD_32K_XI_E2                   1'b1
    8       R/W PAD_32K_XI_SHDN                 1'b1
    9       R/W PAD_32K_XI_S                    1'b0
    10      R/W PAD_32K_XI_DEB                  1'b0
    12:11   R   RSVD                            2'b0
    13      R/W PAD_32K_XI_dbg_en               1'b0
    14      R   RSVD                            1'h0
    15      R/W PAD_32K_XI_O_EN                 1'h1
    16      R/W PAD_32K_XO_O                    1'b0
    17      R/W PAD_32K_XO_E                    1'b0
    18      R/W PAD_32K_XO_PU_EN                1'b1
    19      R/W AON_PAD_32K_XO_PD               1'b1
    20      R/W PAD_32K_XO_PUPDC                1'b0
    21      R/W PAD_32K_XO_WKEN                 1'b0
    22      R/W PAD_32K_XO_WKPOL                1'b0
    23      R/W PAD_32K_XO_E2                   1'b1
    24      R/W PAD_32K_XO_SHDN                 1'b1
    25      R/W PAD_32K_XO_S                    1'b0
    26      R/W PAD_32K_XO_DEB                  1'b0
    28:27   R   RSVD                            2'b0
    29      R/W PAD_32K_XO_dbg_en               1'b0
    30      R   RSVD                            1'h0
    31      R/W PAD_32K_XO_O_EN                 1'h1
 */
typedef volatile union _AON_NS_P32K_XI_P32K_XO_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_32K_XI_O: 1;
        uint32_t PAD_32K_XI_E: 1;
        uint32_t PAD_32K_XI_PU_EN: 1;
        uint32_t AON_PAD_32K_XI_PD: 1;
        uint32_t PAD_32K_XI_PUPDC: 1;
        uint32_t PAD_32K_XI_WKEN: 1;
        uint32_t PAD_32K_XI_WKPOL: 1;
        uint32_t PAD_32K_XI_E2: 1;
        uint32_t PAD_32K_XI_SHDN: 1;
        uint32_t PAD_32K_XI_S: 1;
        uint32_t PAD_32K_XI_DEB: 1;
        uint32_t RSVD_3: 2;
        uint32_t PAD_32K_XI_dbg_en: 1;
        uint32_t RSVD_2: 1;
        uint32_t PAD_32K_XI_O_EN: 1;
        uint32_t PAD_32K_XO_O: 1;
        uint32_t PAD_32K_XO_E: 1;
        uint32_t PAD_32K_XO_PU_EN: 1;
        uint32_t AON_PAD_32K_XO_PD: 1;
        uint32_t PAD_32K_XO_PUPDC: 1;
        uint32_t PAD_32K_XO_WKEN: 1;
        uint32_t PAD_32K_XO_WKPOL: 1;
        uint32_t PAD_32K_XO_E2: 1;
        uint32_t PAD_32K_XO_SHDN: 1;
        uint32_t PAD_32K_XO_S: 1;
        uint32_t PAD_32K_XO_DEB: 1;
        uint32_t RSVD_1: 2;
        uint32_t PAD_32K_XO_dbg_en: 1;
        uint32_t RSVD: 1;
        uint32_t PAD_32K_XO_O_EN: 1;
    };
} AON_NS_P32K_XI_P32K_XO_PAD_CFG_TYPE;

/* 0x194C   0x4000_194c
    0       R/W PAD_MICBIAS_O                   1'b0
    1       R/W PAD_MICBIAS_E                   1'b0
    2       R/W PAD_MICBIAS_PU_EN               1'b1
    3       R/W AON_PAD_MICBIAS_PD              1'b1
    4       R/W PAD_MICBIAS_PUPDC               1'b0
    5       R/W PAD_MICBIAS_WKEN                1'b0
    6       R/W PAD_MICBIAS_WKPOL               1'b0
    7       R/W PAD_MICBIAS_E2                  1'b1
    8       R/W PAD_MICBIAS_SHDN                1'b1
    9       R/W PAD_MICBIAS_S                   1'b0
    10      R/W PAD_MICBIAS_DEB                 1'b0
    12:11   R   RSVD                            2'b0
    13      R/W PAD_MICBIAS_dbg_en              1'b0
    14      R   RSVD                            1'h0
    15      R/W PAD_MICBIAS_O_EN                1'h1
    16      R   RSVD                            1'b0
    17      R   RSVD                            1'b0
    18      R   RSVD                            1'b1
    19      R   RSVD                            1'b1
    20      R   RSVD                            1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R   RSVD                            1'b0
    24      R   RSVD                            1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    28:27   R   RSVD                            2'b0
    29      R   RSVD                            1'b0
    31:30   R   RSVD                            2'h0
 */
typedef volatile union _AON_NS_P_MICBIAS_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_MICBIAS_O: 1;
        uint32_t PAD_MICBIAS_E: 1;
        uint32_t PAD_MICBIAS_PU_EN: 1;
        uint32_t AON_PAD_MICBIAS_PD: 1;
        uint32_t PAD_MICBIAS_PUPDC: 1;
        uint32_t PAD_MICBIAS_WKEN: 1;
        uint32_t PAD_MICBIAS_WKPOL: 1;
        uint32_t PAD_MICBIAS_E2: 1;
        uint32_t PAD_MICBIAS_SHDN: 1;
        uint32_t PAD_MICBIAS_S: 1;
        uint32_t PAD_MICBIAS_DEB: 1;
        uint32_t RSVD_15: 2;
        uint32_t PAD_MICBIAS_dbg_en: 1;
        uint32_t RSVD_14: 1;
        uint32_t PAD_MICBIAS_O_EN: 1;
        uint32_t RSVD_13: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 2;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 2;
    };
} AON_NS_P_MICBIAS_PAD_CFG_TYPE;

/* 0x1950   0x4000_1950
    0       R/W TOP_PAD_SMT                     1'b0
    1       R/W BOT_PAD_SMT                     1'b0
    2       R/W LEFT_PAD_SMT                    1'b0
    3       R/W RIGHT_PAD_SMT                   1'b0
    4       R/W POWPAD1                         1'b1
    31:5    R   RSVD                            27'h0
 */
typedef volatile union _AON_NS_COMMON_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t TOP_PAD_SMT: 1;
        uint32_t BOT_PAD_SMT: 1;
        uint32_t LEFT_PAD_SMT: 1;
        uint32_t RIGHT_PAD_SMT: 1;
        uint32_t POWPAD1: 1;
        uint32_t RSVD: 27;
    };
} AON_NS_COMMON_PAD_CFG_TYPE;

/* 0x1954   0x4000_1954
    0       R   RSVD                            1'b1
    1       R   RSVD                            1'b1
    2       R   RSVD                            1'b0
    3       R   RSVD                            1'b0
    4       R   RSVD                            1'b0
    5       R   RSVD                            1'b0
    6       R   RSVD                            1'b0
    7       R   RSVD                            1'b0
    8       R   RSVD                            1'b0
    9       R   RSVD                            1'b0
    10      R   RSVD                            1'b0
    11      R   RSVD                            1'b0
    12      R   RSVD                            1'b0
    13      R   RSVD                            1'b0
    14      R   RSVD                            1'b1
    15      R   RSVD                            1'b1
    16      R   RSVD                            1'b0
    17      R   RSVD                            1'b0
    18      R   RSVD                            1'b0
    19      R   RSVD                            1'b0
    20      R   RSVD                            1'b0
    21      R   RSVD                            1'b0
    31:22   R   RSVD                            10'h0
 */
typedef volatile union _AON_NS_P_SPI_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_22: 1;
        uint32_t RSVD_21: 1;
        uint32_t RSVD_20: 1;
        uint32_t RSVD_19: 1;
        uint32_t RSVD_18: 1;
        uint32_t RSVD_17: 1;
        uint32_t RSVD_16: 1;
        uint32_t RSVD_15: 1;
        uint32_t RSVD_14: 1;
        uint32_t RSVD_13: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 10;
    };
} AON_NS_P_SPI_PAD_CFG_TYPE;

/* 0x1958   0x4000_1958
    0       R/W PAD_DAC_N_O                     1'b0
    1       R/W PAD_DAC_N_E                     1'b0
    2       R/W PAD_DAC_N_PU_EN                 1'b1
    3       R/W AON_PAD_DAC_N_PD                1'b1
    4       R/W PAD_DAC_N_PUPDC                 1'b0
    5       R/W PAD_DAC_N_WKEN                  1'b0
    6       R/W PAD_DAC_N_WKPOL                 1'b0
    7       R/W PAD_DAC_N_E2                    1'b1
    8       R/W PAD_DAC_N_SHDN                  1'b1
    9       R/W PAD_DAC_N_S                     1'b0
    10      R/W PAD_DAC_N_DEB                   1'b0
    12:11   R   RSVD                            2'b0
    13      R/W PAD_DAC_N_dummy                 1'b0
    14      R   RSVD                            1'h0
    15      R/W PAD_DAC_N_O_EN                  1'h1
    16      R/W PAD_DAC_P_O                     1'b0
    17      R/W PAD_DAC_P_E                     1'b0
    18      R/W PAD_DAC_P_PU_EN                 1'b1
    19      R/W AON_PAD_DAC_P_PD                1'b1
    20      R/W PAD_DAC_P_PUPDC                 1'b0
    21      R/W PAD_DAC_P_WKEN                  1'b0
    22      R/W PAD_DAC_P_WKPOL                 1'b0
    23      R/W PAD_DAC_N_E2                    1'b1
    24      R/W PAD_DAC_P_SHDN                  1'b1
    25      R/W PAD_DAC_P_S                     1'b0
    26      R/W PAD_DAC_P_DEB                   1'b0
    28:27   R   RSVD                            2'b0
    29      R/W PAD_DAC_P_dummy                 1'b0
    30      R   RSVD                            1'h0
    31      R/W PAD_DAC_P_O_EN                  1'h1
 */
typedef volatile union _AON_NS_DAC_P_DAC_N_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_DAC_N_O: 1;
        uint32_t PAD_DAC_N_E: 1;
        uint32_t PAD_DAC_N_PU_EN: 1;
        uint32_t AON_PAD_DAC_N_PD: 1;
        uint32_t PAD_DAC_N_PUPDC: 1;
        uint32_t PAD_DAC_N_WKEN: 1;
        uint32_t PAD_DAC_N_WKPOL: 1;
        uint32_t PAD_DAC_N_E2_1: 1;
        uint32_t PAD_DAC_N_SHDN: 1;
        uint32_t PAD_DAC_N_S: 1;
        uint32_t PAD_DAC_N_DEB: 1;
        uint32_t RSVD_3: 2;
        uint32_t PAD_DAC_N_dummy: 1;
        uint32_t RSVD_2: 1;
        uint32_t PAD_DAC_N_O_EN: 1;
        uint32_t PAD_DAC_P_O: 1;
        uint32_t PAD_DAC_P_E: 1;
        uint32_t PAD_DAC_P_PU_EN: 1;
        uint32_t AON_PAD_DAC_P_PD: 1;
        uint32_t PAD_DAC_P_PUPDC: 1;
        uint32_t PAD_DAC_P_WKEN: 1;
        uint32_t PAD_DAC_P_WKPOL: 1;
        uint32_t PAD_DAC_N_E2: 1;
        uint32_t PAD_DAC_P_SHDN: 1;
        uint32_t PAD_DAC_P_S: 1;
        uint32_t PAD_DAC_P_DEB: 1;
        uint32_t RSVD_1: 2;
        uint32_t PAD_DAC_P_dummy: 1;
        uint32_t RSVD: 1;
        uint32_t PAD_DAC_P_O_EN: 1;
    };
} AON_NS_DAC_P_DAC_N_PAD_CFG_TYPE;

/* 0x195C   0x4000_195c
    0       R/W PAD_P4_O[4]                     1'b0
    1       R/W PAD_P4_E[4]                     1'b0
    2       R/W PAD_P4_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P4_PD[4]                1'b1
    4       R/W PAD_P4_PUPDC[4]                 1'b0
    5       R/W PAD_P4_WKEN[4]                  1'b0
    6       R/W PAD_P4_WKPOL[4]                 1'b0
    7       R/W PAD_P4_E2[4]                    1'b1
    8       R/W PAD_P4_SHDN[4]                  1'b1
    9       R/W PAD_P4_S[4]                     1'b0
    10      R/W PAD_P4_DEB[4]                   1'b0
    11      R/W PAD_P4_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P4_O_EN[4]                  1'h1
    16      R/W PAD_P4_O[5]                     1'b0
    17      R/W PAD_P4_E[5]                     1'b0
    18      R/W PAD_P4_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P4_PD[5]                1'b1
    20      R/W PAD_P4_PUPDC[5]                 1'b0
    21      R/W PAD_P4_WKEN[5]                  1'b0
    22      R/W PAD_P4_WKPOL[5]                 1'b0
    23      R/W PAD_P4_E2[5]                    1'b1
    24      R/W PAD_P4_SHDN[5]                  1'b1
    25      R/W PAD_P4_S[5]                     1'b0
    26      R/W PAD_P4_DEB[5]                   1'b0
    27      R/W PAD_P4_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P4_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P4_4_P4_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_O_4: 1;
        uint32_t PAD_P4_E_4: 1;
        uint32_t PAD_P4_PU_EN_4: 1;
        uint32_t AON_PAD_P4_PD_4: 1;
        uint32_t PAD_P4_PUPDC_4: 1;
        uint32_t PAD_P4_WKEN_4: 1;
        uint32_t PAD_P4_WKPOL_4: 1;
        uint32_t PAD_P4_E2_4: 1;
        uint32_t PAD_P4_SHDN_4: 1;
        uint32_t PAD_P4_S_4: 1;
        uint32_t PAD_P4_DEB_4: 1;
        uint32_t PAD_P4_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P4_O_EN_4: 1;
        uint32_t PAD_P4_O_5: 1;
        uint32_t PAD_P4_E_5: 1;
        uint32_t PAD_P4_PU_EN_5: 1;
        uint32_t AON_PAD_P4_PD_5: 1;
        uint32_t PAD_P4_PUPDC_5: 1;
        uint32_t PAD_P4_WKEN_5: 1;
        uint32_t PAD_P4_WKPOL_5: 1;
        uint32_t PAD_P4_E2_5: 1;
        uint32_t PAD_P4_SHDN_5: 1;
        uint32_t PAD_P4_S_5: 1;
        uint32_t PAD_P4_DEB_5: 1;
        uint32_t PAD_P4_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P4_O_EN_5: 1;
    };
} AON_NS_P4_4_P4_5_PAD_CFG_TYPE;

/* 0x1960   0x4000_1960
    0       R/W PAD_P4_O[6]                     1'b0
    1       R/W PAD_P4_E[6]                     1'b0
    2       R/W PAD_P4_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P4_PD[6]                1'b1
    4       R/W PAD_P4_PUPDC[6]                 1'b0
    5       R/W PAD_P4_WKEN[6]                  1'b0
    6       R/W PAD_P4_WKPOL[6]                 1'b0
    7       R/W PAD_P4_E2[6]                    1'b1
    8       R/W PAD_P4_SHDN[6]                  1'b1
    9       R/W PAD_P4_S[6]                     1'b0
    10      R/W PAD_P4_DEB[6]                   1'b0
    11      R/W PAD_P4_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P4_O_EN[6]                  1'h1
    16      R/W PAD_P4_O[7]                     1'b0
    17      R/W PAD_P4_E[7]                     1'b0
    18      R/W PAD_P4_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P4_PD[7]                1'b1
    20      R/W PAD_P4_PUPDC[7]                 1'b0
    21      R/W PAD_P4_WKEN[7]                  1'b0
    22      R/W PAD_P4_WKPOL[7]                 1'b0
    23      R/W PAD_P4_E2[7]                    1'b1
    24      R/W PAD_P4_SHDN[7]                  1'b1
    25      R/W PAD_P4_S[7]                     1'b0
    26      R/W PAD_P4_DEB[7]                   1'b0
    27      R/W PAD_P4_HS_MUX[7]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P4_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P4_6_P4_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_O_6: 1;
        uint32_t PAD_P4_E_6: 1;
        uint32_t PAD_P4_PU_EN_6: 1;
        uint32_t AON_PAD_P4_PD_6: 1;
        uint32_t PAD_P4_PUPDC_6: 1;
        uint32_t PAD_P4_WKEN_6: 1;
        uint32_t PAD_P4_WKPOL_6: 1;
        uint32_t PAD_P4_E2_6: 1;
        uint32_t PAD_P4_SHDN_6: 1;
        uint32_t PAD_P4_S_6: 1;
        uint32_t PAD_P4_DEB_6: 1;
        uint32_t PAD_P4_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P4_O_EN_6: 1;
        uint32_t PAD_P4_O_7: 1;
        uint32_t PAD_P4_E_7: 1;
        uint32_t PAD_P4_PU_EN_7: 1;
        uint32_t AON_PAD_P4_PD_7: 1;
        uint32_t PAD_P4_PUPDC_7: 1;
        uint32_t PAD_P4_WKEN_7: 1;
        uint32_t PAD_P4_WKPOL_7: 1;
        uint32_t PAD_P4_E2_7: 1;
        uint32_t PAD_P4_SHDN_7: 1;
        uint32_t PAD_P4_S_7: 1;
        uint32_t PAD_P4_DEB_7: 1;
        uint32_t PAD_P4_HS_MUX_7: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P4_O_EN_7: 1;
    };
} AON_NS_P4_6_P4_7_PAD_CFG_TYPE;

/* 0x1964   0x4000_1964
    0       R/W PAD_P5_O[0]                     1'b0
    1       R/W PAD_P5_E[0]                     1'b0
    2       R/W PAD_P5_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P5_PD[0]                1'b1
    4       R/W PAD_P5_PUPDC[0]                 1'b0
    5       R/W PAD_P5_WKEN[0]                  1'b0
    6       R/W PAD_P5_WKPOL[0]                 1'b0
    7       R/W PAD_P5_E2[0]                    1'b1
    8       R/W PAD_P5_SHDN[0]                  1'b1
    9       R/W PAD_P5_S[0]                     1'b0
    10      R/W PAD_P5_DEB[0]                   1'b0
    11      R/W PAD_P5_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P5_O_EN[0]                  1'h1
    16      R/W PAD_P5_O[1]                     1'b0
    17      R/W PAD_P5_E[1]                     1'b0
    18      R/W PAD_P5_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P5_PD[1]                1'b1
    20      R/W PAD_P5_PUPDC[1]                 1'b0
    21      R/W PAD_P5_WKEN[1]                  1'b0
    22      R/W PAD_P5_WKPOL[1]                 1'b0
    23      R/W PAD_P5_E2[1]                    1'b1
    24      R/W PAD_P5_SHDN[1]                  1'b1
    25      R/W PAD_P5_S[1]                     1'b0
    26      R/W PAD_P5_DEB[1]                   1'b0
    27      R/W PAD_P5_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P5_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P5_0_P5_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P5_O_0: 1;
        uint32_t PAD_P5_E_0: 1;
        uint32_t PAD_P5_PU_EN_0: 1;
        uint32_t AON_PAD_P5_PD_0: 1;
        uint32_t PAD_P5_PUPDC_0: 1;
        uint32_t PAD_P5_WKEN_0: 1;
        uint32_t PAD_P5_WKPOL_0: 1;
        uint32_t PAD_P5_E2_0: 1;
        uint32_t PAD_P5_SHDN_0: 1;
        uint32_t PAD_P5_S_0: 1;
        uint32_t PAD_P5_DEB_0: 1;
        uint32_t PAD_P5_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P5_O_EN_0: 1;
        uint32_t PAD_P5_O_1: 1;
        uint32_t PAD_P5_E_1: 1;
        uint32_t PAD_P5_PU_EN_1: 1;
        uint32_t AON_PAD_P5_PD_1: 1;
        uint32_t PAD_P5_PUPDC_1: 1;
        uint32_t PAD_P5_WKEN_1: 1;
        uint32_t PAD_P5_WKPOL_1: 1;
        uint32_t PAD_P5_E2_1: 1;
        uint32_t PAD_P5_SHDN_1: 1;
        uint32_t PAD_P5_S_1: 1;
        uint32_t PAD_P5_DEB_1: 1;
        uint32_t PAD_P5_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P5_O_EN_1: 1;
    };
} AON_NS_P5_0_P5_1_PAD_CFG_TYPE;

/* 0x1968   0x4000_1968
    0       R/W PAD_P5_O[2]                     1'b0
    1       R/W PAD_P5_E[2]                     1'b0
    2       R/W PAD_P5_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P5_PD[2]                1'b0
    4       R/W PAD_P5_PUPDC[2]                 1'b0
    5       R/W PAD_P5_WKEN[2]                  1'b0
    6       R/W PAD_P5_WKPOL[2]                 1'b0
    7       R/W PAD_P5_E2[2]                    1'b1
    8       R/W PAD_P5_SHDN[2]                  1'b1
    9       R/W PAD_P5_S[2]                     1'b0
    10      R/W PAD_P5_DEB[2]                   1'b0
    11      R/W PAD_P5_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P5_O_EN[2]                  1'h1
    16      R/W PAD_P5_O[3]                     1'b0
    17      R/W PAD_P5_E[3]                     1'b0
    18      R/W PAD_P5_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P5_PD[3]                1'b1
    20      R/W PAD_P5_PUPDC[3]                 1'b0
    21      R/W PAD_P5_WKEN[3]                  1'b0
    22      R/W PAD_P5_WKPOL[3]                 1'b0
    23      R/W PAD_P5_E2[3]                    1'b1
    24      R/W PAD_P5_SHDN[3]                  1'b1
    25      R/W PAD_P5_S[3]                     1'b0
    26      R/W PAD_P5_DEB[3]                   1'b0
    27      R/W PAD_P5_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P5_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P5_2_P5_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P5_O_2: 1;
        uint32_t PAD_P5_E_2: 1;
        uint32_t PAD_P5_PU_EN_2: 1;
        uint32_t AON_PAD_P5_PD_2: 1;
        uint32_t PAD_P5_PUPDC_2: 1;
        uint32_t PAD_P5_WKEN_2: 1;
        uint32_t PAD_P5_WKPOL_2: 1;
        uint32_t PAD_P5_E2_2: 1;
        uint32_t PAD_P5_SHDN_2: 1;
        uint32_t PAD_P5_S_2: 1;
        uint32_t PAD_P5_DEB_2: 1;
        uint32_t PAD_P5_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P5_O_EN_2: 1;
        uint32_t PAD_P5_O_3: 1;
        uint32_t PAD_P5_E_3: 1;
        uint32_t PAD_P5_PU_EN_3: 1;
        uint32_t AON_PAD_P5_PD_3: 1;
        uint32_t PAD_P5_PUPDC_3: 1;
        uint32_t PAD_P5_WKEN_3: 1;
        uint32_t PAD_P5_WKPOL_3: 1;
        uint32_t PAD_P5_E2_3: 1;
        uint32_t PAD_P5_SHDN_3: 1;
        uint32_t PAD_P5_S_3: 1;
        uint32_t PAD_P5_DEB_3: 1;
        uint32_t PAD_P5_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P5_O_EN_3: 1;
    };
} AON_NS_P5_2_P5_3_PAD_CFG_TYPE;

/* 0x196C   0x4000_196c
    0       R/W PAD_P5_O[4]                     1'b0
    1       R/W PAD_P5_E[4]                     1'b0
    2       R/W PAD_P5_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P5_PD[4]                1'b1
    4       R/W PAD_P5_PUPDC[4]                 1'b0
    5       R/W PAD_P5_WKEN[4]                  1'b0
    6       R/W PAD_P5_WKPOL[4]                 1'b0
    7       R/W PAD_P5_E2[4]                    1'b1
    8       R/W PAD_P5_SHDN[4]                  1'b1
    9       R/W PAD_P5_S[4]                     1'b0
    10      R/W PAD_P5_DEB[4]                   1'b0
    11      R/W PAD_P5_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P5_O_EN[4]                  1'h1
    16      R/W PAD_P5_O[5]                     1'b0
    17      R/W PAD_P5_E[5]                     1'b0
    18      R/W PAD_P5_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P5_PD[5]                1'b1
    20      R/W PAD_P5_PUPDC[5]                 1'b0
    21      R/W PAD_P5_WKEN[5]                  1'b0
    22      R/W PAD_P5_WKPOL[5]                 1'b0
    23      R/W PAD_P5_E2[5]                    1'b1
    24      R/W PAD_P5_SHDN[5]                  1'b1
    25      R/W PAD_P5_S[5]                     1'b0
    26      R/W PAD_P5_DEB[5]                   1'b0
    27      R/W PAD_P5_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P5_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P5_4_P5_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P5_O_4: 1;
        uint32_t PAD_P5_E_4: 1;
        uint32_t PAD_P5_PU_EN_4: 1;
        uint32_t AON_PAD_P5_PD_4: 1;
        uint32_t PAD_P5_PUPDC_4: 1;
        uint32_t PAD_P5_WKEN_4: 1;
        uint32_t PAD_P5_WKPOL_4: 1;
        uint32_t PAD_P5_E2_4: 1;
        uint32_t PAD_P5_SHDN_4: 1;
        uint32_t PAD_P5_S_4: 1;
        uint32_t PAD_P5_DEB_4: 1;
        uint32_t PAD_P5_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P5_O_EN_4: 1;
        uint32_t PAD_P5_O_5: 1;
        uint32_t PAD_P5_E_5: 1;
        uint32_t PAD_P5_PU_EN_5: 1;
        uint32_t AON_PAD_P5_PD_5: 1;
        uint32_t PAD_P5_PUPDC_5: 1;
        uint32_t PAD_P5_WKEN_5: 1;
        uint32_t PAD_P5_WKPOL_5: 1;
        uint32_t PAD_P5_E2_5: 1;
        uint32_t PAD_P5_SHDN_5: 1;
        uint32_t PAD_P5_S_5: 1;
        uint32_t PAD_P5_DEB_5: 1;
        uint32_t PAD_P5_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P5_O_EN_5: 1;
    };
} AON_NS_P5_4_P5_5_PAD_CFG_TYPE;

/* 0x1970   0x4000_1970
    0       R/W PAD_P5_O[6]                     1'b0
    1       R/W PAD_P5_E[6]                     1'b0
    2       R/W PAD_P5_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P5_PD[6]                1'b1
    4       R/W PAD_P5_PUPDC[6]                 1'b0
    5       R/W PAD_P5_WKEN[6]                  1'b0
    6       R/W PAD_P5_WKPOL[6]                 1'b0
    7       R/W PAD_P5_E2[6]                    1'b1
    8       R/W PAD_P5_SHDN[6]                  1'b1
    9       R/W PAD_P5_S[6]                     1'b0
    10      R/W PAD_P5_DEB[6]                   1'b0
    14:11   R   RSVD                            4'b0
    15      R/W PAD_P5_O_EN[6]                  1'h1
    16      R/W PAD_P5_O[7]                     1'b0
    17      R/W PAD_P5_E[7]                     1'b0
    18      R/W PAD_P5_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P5_PD[7]                1'b1
    20      R/W PAD_P5_PUPDC[7]                 1'b0
    21      R/W PAD_P5_WKEN[7]                  1'b0
    22      R/W PAD_P5_WKPOL[7]                 1'b0
    23      R/W PAD_P5_E2[7]                    1'b1
    24      R/W PAD_P5_SHDN[7]                  1'b1
    25      R/W PAD_P5_S[7]                     1'b0
    26      R/W PAD_P5_DEB[7]                   1'b0
    30:27   R   RSVD                            4'b0
    31      R/W PAD_P5_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P5_6_P5_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P5_O_6: 1;
        uint32_t PAD_P5_E_6: 1;
        uint32_t PAD_P5_PU_EN_6: 1;
        uint32_t AON_PAD_P5_PD_6: 1;
        uint32_t PAD_P5_PUPDC_6: 1;
        uint32_t PAD_P5_WKEN_6: 1;
        uint32_t PAD_P5_WKPOL_6: 1;
        uint32_t PAD_P5_E2_6: 1;
        uint32_t PAD_P5_SHDN_6: 1;
        uint32_t PAD_P5_S_6: 1;
        uint32_t PAD_P5_DEB_6: 1;
        uint32_t RSVD_1: 4;
        uint32_t PAD_P5_O_EN_6: 1;
        uint32_t PAD_P5_O_7: 1;
        uint32_t PAD_P5_E_7: 1;
        uint32_t PAD_P5_PU_EN_7: 1;
        uint32_t AON_PAD_P5_PD_7: 1;
        uint32_t PAD_P5_PUPDC_7: 1;
        uint32_t PAD_P5_WKEN_7: 1;
        uint32_t PAD_P5_WKPOL_7: 1;
        uint32_t PAD_P5_E2_7: 1;
        uint32_t PAD_P5_SHDN_7: 1;
        uint32_t PAD_P5_S_7: 1;
        uint32_t PAD_P5_DEB_7: 1;
        uint32_t RSVD: 4;
        uint32_t PAD_P5_O_EN_7: 1;
    };
} AON_NS_P5_6_P5_7_PAD_CFG_TYPE;

/* 0x1974   0x4000_1974
    0       R/W PAD_P6_O[0]                     1'b0
    1       R/W PAD_P6_E[0]                     1'b0
    2       R/W PAD_P6_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P6_PD[0]                1'b1
    4       R/W PAD_P6_PUPDC[0]                 1'b0
    5       R/W PAD_P6_WKEN[0]                  1'b0
    6       R/W PAD_P6_WKPOL[0]                 1'b0
    7       R/W PAD_P6_E2[0]                    1'b1
    8       R/W PAD_P6_SHDN[0]                  1'b1
    9       R/W PAD_P6_S[0]                     1'b0
    10      R/W PAD_P6_DEB[0]                   1'b0
    11      R/W PAD_P6_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P6_O_EN[0]                  1'h1
    16      R/W PAD_P6_O[1]                     1'b0
    17      R/W PAD_P6_E[1]                     1'b0
    18      R/W PAD_P6_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P6_PD[1]                1'b1
    20      R/W PAD_P6_PUPDC[1]                 1'b0
    21      R/W PAD_P6_WKEN[1]                  1'b0
    22      R/W PAD_P6_WKPOL[1]                 1'b0
    23      R/W PAD_P6_E2[1]                    1'b1
    24      R/W PAD_P6_SHDN[1]                  1'b1
    25      R/W PAD_P6_S[1]                     1'b0
    26      R/W PAD_P6_DEB[1]                   1'b0
    27      R/W PAD_P6_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P6_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P6_0_P6_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P6_O_0: 1;
        uint32_t PAD_P6_E_0: 1;
        uint32_t PAD_P6_PU_EN_0: 1;
        uint32_t AON_PAD_P6_PD_0: 1;
        uint32_t PAD_P6_PUPDC_0: 1;
        uint32_t PAD_P6_WKEN_0: 1;
        uint32_t PAD_P6_WKPOL_0: 1;
        uint32_t PAD_P6_E2_0: 1;
        uint32_t PAD_P6_SHDN_0: 1;
        uint32_t PAD_P6_S_0: 1;
        uint32_t PAD_P6_DEB_0: 1;
        uint32_t PAD_P6_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P6_O_EN_0: 1;
        uint32_t PAD_P6_O_1: 1;
        uint32_t PAD_P6_E_1: 1;
        uint32_t PAD_P6_PU_EN_1: 1;
        uint32_t AON_PAD_P6_PD_1: 1;
        uint32_t PAD_P6_PUPDC_1: 1;
        uint32_t PAD_P6_WKEN_1: 1;
        uint32_t PAD_P6_WKPOL_1: 1;
        uint32_t PAD_P6_E2_1: 1;
        uint32_t PAD_P6_SHDN_1: 1;
        uint32_t PAD_P6_S_1: 1;
        uint32_t PAD_P6_DEB_1: 1;
        uint32_t PAD_P6_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P6_O_EN_1: 1;
    };
} AON_NS_P6_0_P6_1_PAD_CFG_TYPE;

/* 0x1978   0x4000_1978
    0       R/W PAD_P6_O[2]                     1'b0
    1       R/W PAD_P6_E[2]                     1'b0
    2       R/W PAD_P6_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P6_PD[2]                1'b1
    4       R/W PAD_P6_PUPDC[2]                 1'b0
    5       R/W PAD_P6_WKEN[2]                  1'b0
    6       R/W PAD_P6_WKPOL[2]                 1'b0
    7       R/W PAD_P6_E2[2]                    1'b1
    8       R/W PAD_P6_SHDN[2]                  1'b1
    9       R/W PAD_P6_S[2]                     1'b0
    10      R/W PAD_P6_DEB[2]                   1'b0
    11      R/W PAD_P6_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P6_O_EN[2]                  1'h1
    16      R/W PAD_P6_O[3]                     1'b0
    17      R/W PAD_P6_E[3]                     1'b0
    18      R/W PAD_P6_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P6_PD[3]                1'b1
    20      R/W PAD_P6_PUPDC[3]                 1'b0
    21      R/W PAD_P6_WKEN[3]                  1'b0
    22      R/W PAD_P6_WKPOL[3]                 1'b0
    23      R/W PAD_P6_E2[3]                    1'b1
    24      R/W PAD_P6_SHDN[3]                  1'b1
    25      R/W PAD_P6_S[3]                     1'b0
    26      R/W PAD_P6_DEB[3]                   1'b0
    27      R/W PAD_P6_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P6_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P6_2_P6_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P6_O_2: 1;
        uint32_t PAD_P6_E_2: 1;
        uint32_t PAD_P6_PU_EN_2: 1;
        uint32_t AON_PAD_P6_PD_2: 1;
        uint32_t PAD_P6_PUPDC_2: 1;
        uint32_t PAD_P6_WKEN_2: 1;
        uint32_t PAD_P6_WKPOL_2: 1;
        uint32_t PAD_P6_E2_2: 1;
        uint32_t PAD_P6_SHDN_2: 1;
        uint32_t PAD_P6_S_2: 1;
        uint32_t PAD_P6_DEB_2: 1;
        uint32_t PAD_P6_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P6_O_EN_2: 1;
        uint32_t PAD_P6_O_3: 1;
        uint32_t PAD_P6_E_3: 1;
        uint32_t PAD_P6_PU_EN_3: 1;
        uint32_t AON_PAD_P6_PD_3: 1;
        uint32_t PAD_P6_PUPDC_3: 1;
        uint32_t PAD_P6_WKEN_3: 1;
        uint32_t PAD_P6_WKPOL_3: 1;
        uint32_t PAD_P6_E2_3: 1;
        uint32_t PAD_P6_SHDN_3: 1;
        uint32_t PAD_P6_S_3: 1;
        uint32_t PAD_P6_DEB_3: 1;
        uint32_t PAD_P6_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P6_O_EN_3: 1;
    };
} AON_NS_P6_2_P6_3_PAD_CFG_TYPE;

/* 0x197C   0x4000_197c
    0       R/W PAD_P6_O[4]                     1'b0
    1       R/W PAD_P6_E[4]                     1'b0
    2       R/W PAD_P6_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P6_PD[4]                1'b1
    4       R/W PAD_P6_PUPDC[4]                 1'b0
    5       R/W PAD_P6_WKEN[4]                  1'b0
    6       R/W PAD_P6_WKPOL[4]                 1'b0
    7       R/W PAD_P6_E2[4]                    1'b1
    8       R/W PAD_P6_SHDN[4]                  1'b1
    9       R/W PAD_P6_S[4]                     1'b0
    10      R/W PAD_P6_DEB[4]                   1'b0
    11      R/W PAD_P6_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P6_O_EN[4]                  1'h1
    16      R/W PAD_P6_O[5]                     1'b0
    17      R/W PAD_P6_E[5]                     1'b0
    18      R/W PAD_P6_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P6_PD[5]                1'b0
    20      R/W PAD_P6_PUPDC[5]                 1'b0
    21      R/W PAD_P6_WKEN[5]                  1'b0
    22      R/W PAD_P6_WKPOL[5]                 1'b0
    23      R/W PAD_P6_E2[5]                    1'b1
    24      R/W PAD_P6_SHDN[5]                  1'b1
    25      R/W PAD_P6_S[5]                     1'b0
    26      R/W PAD_P6_DEB[5]                   1'b0
    27      R/W PAD_P6_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P6_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P6_4_P6_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P6_O_4: 1;
        uint32_t PAD_P6_E_4: 1;
        uint32_t PAD_P6_PU_EN_4: 1;
        uint32_t AON_PAD_P6_PD_4: 1;
        uint32_t PAD_P6_PUPDC_4: 1;
        uint32_t PAD_P6_WKEN_4: 1;
        uint32_t PAD_P6_WKPOL_4: 1;
        uint32_t PAD_P6_E2_4: 1;
        uint32_t PAD_P6_SHDN_4: 1;
        uint32_t PAD_P6_S_4: 1;
        uint32_t PAD_P6_DEB_4: 1;
        uint32_t PAD_P6_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P6_O_EN_4: 1;
        uint32_t PAD_P6_O_5: 1;
        uint32_t PAD_P6_E_5: 1;
        uint32_t PAD_P6_PU_EN_5: 1;
        uint32_t AON_PAD_P6_PD_5: 1;
        uint32_t PAD_P6_PUPDC_5: 1;
        uint32_t PAD_P6_WKEN_5: 1;
        uint32_t PAD_P6_WKPOL_5: 1;
        uint32_t PAD_P6_E2_5: 1;
        uint32_t PAD_P6_SHDN_5: 1;
        uint32_t PAD_P6_S_5: 1;
        uint32_t PAD_P6_DEB_5: 1;
        uint32_t PAD_P6_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P6_O_EN_5: 1;
    };
} AON_NS_P6_4_P6_5_PAD_CFG_TYPE;

/* 0x1980   0x4000_1980
    0       R/W PAD_P6_O[6]                     1'b0
    1       R/W PAD_P6_E[6]                     1'b0
    2       R/W PAD_P6_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P6_PD[6]                1'b1
    4       R/W PAD_P6_PUPDC[6]                 1'b0
    5       R/W PAD_P6_WKEN[6]                  1'b0
    6       R/W PAD_P6_WKPOL[6]                 1'b0
    7       R/W PAD_P6_E2[6]                    1'b1
    8       R/W PAD_P6_SHDN[6]                  1'b1
    9       R/W PAD_P6_S[6]                     1'b0
    10      R/W PAD_P6_DEB[6]                   1'b0
    11      R/W PAD_P6_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P6_O_EN[6]                  1'h1
    16      R/W PAD_P6_O[7]                     1'b0
    17      R/W PAD_P6_E[7]                     1'b0
    18      R/W PAD_P6_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P6_PD[7]                1'b0
    20      R/W PAD_P6_PUPDC[7]                 1'b0
    21      R/W PAD_P6_WKEN[7]                  1'b0
    22      R/W PAD_P6_WKPOL[7]                 1'b0
    23      R/W PAD_P6_E2[7]                    1'b1
    24      R/W PAD_P6_SHDN[7]                  1'b1
    25      R/W PAD_P6_S[7]                     1'b0
    26      R/W PAD_P6_DEB[7]                   1'b0
    27      R/W PAD_P6_HS_MUX[7]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P6_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P6_6_P6_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P6_O_6: 1;
        uint32_t PAD_P6_E_6: 1;
        uint32_t PAD_P6_PU_EN_6: 1;
        uint32_t AON_PAD_P6_PD_6: 1;
        uint32_t PAD_P6_PUPDC_6: 1;
        uint32_t PAD_P6_WKEN_6: 1;
        uint32_t PAD_P6_WKPOL_6: 1;
        uint32_t PAD_P6_E2_6: 1;
        uint32_t PAD_P6_SHDN_6: 1;
        uint32_t PAD_P6_S_6: 1;
        uint32_t PAD_P6_DEB_6: 1;
        uint32_t PAD_P6_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P6_O_EN_6: 1;
        uint32_t PAD_P6_O_7: 1;
        uint32_t PAD_P6_E_7: 1;
        uint32_t PAD_P6_PU_EN_7: 1;
        uint32_t AON_PAD_P6_PD_7: 1;
        uint32_t PAD_P6_PUPDC_7: 1;
        uint32_t PAD_P6_WKEN_7: 1;
        uint32_t PAD_P6_WKPOL_7: 1;
        uint32_t PAD_P6_E2_7: 1;
        uint32_t PAD_P6_SHDN_7: 1;
        uint32_t PAD_P6_S_7: 1;
        uint32_t PAD_P6_DEB_7: 1;
        uint32_t PAD_P6_HS_MUX_7: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P6_O_EN_7: 1;
    };
} AON_NS_P6_6_P6_7_PAD_CFG_TYPE;

/* 0x1984   0x4000_1984
    0       R/W PAD_P7_O[0]                     1'b0
    1       R/W PAD_P7_E[0]                     1'b0
    2       R/W PAD_P7_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P7_PD[0]                1'b1
    4       R/W PAD_P7_PUPDC[0]                 1'b0
    5       R/W PAD_P7_WKEN[0]                  1'b0
    6       R/W PAD_P7_WKPOL[0]                 1'b0
    7       R/W PAD_P7_E2[0]                    1'b1
    8       R/W PAD_P7_SHDN[0]                  1'b1
    9       R/W PAD_P7_S[0]                     1'b0
    10      R/W PAD_P7_DEB[0]                   1'b0
    11      R/W PAD_P7_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P7_O_EN[0]                  1'h1
    16      R/W PAD_P7_O[1]                     1'b0
    17      R/W PAD_P7_E[1]                     1'b0
    18      R/W PAD_P7_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P7_PD[1]                1'b1
    20      R/W PAD_P7_PUPDC[1]                 1'b0
    21      R/W PAD_P7_WKEN[1]                  1'b0
    22      R/W PAD_P7_WKPOL[1]                 1'b0
    23      R/W PAD_P7_E2[1]                    1'b1
    24      R/W PAD_P7_SHDN[1]                  1'b1
    25      R/W PAD_P7_S[1]                     1'b0
    26      R/W PAD_P7_DEB[1]                   1'b0
    27      R/W PAD_P7_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P7_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P7_0_P7_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P7_O_0: 1;
        uint32_t PAD_P7_E_0: 1;
        uint32_t PAD_P7_PU_EN_0: 1;
        uint32_t AON_PAD_P7_PD_0: 1;
        uint32_t PAD_P7_PUPDC_0: 1;
        uint32_t PAD_P7_WKEN_0: 1;
        uint32_t PAD_P7_WKPOL_0: 1;
        uint32_t PAD_P7_E2_0: 1;
        uint32_t PAD_P7_SHDN_0: 1;
        uint32_t PAD_P7_S_0: 1;
        uint32_t PAD_P7_DEB_0: 1;
        uint32_t PAD_P7_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P7_O_EN_0: 1;
        uint32_t PAD_P7_O_1: 1;
        uint32_t PAD_P7_E_1: 1;
        uint32_t PAD_P7_PU_EN_1: 1;
        uint32_t AON_PAD_P7_PD_1: 1;
        uint32_t PAD_P7_PUPDC_1: 1;
        uint32_t PAD_P7_WKEN_1: 1;
        uint32_t PAD_P7_WKPOL_1: 1;
        uint32_t PAD_P7_E2_1: 1;
        uint32_t PAD_P7_SHDN_1: 1;
        uint32_t PAD_P7_S_1: 1;
        uint32_t PAD_P7_DEB_1: 1;
        uint32_t PAD_P7_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P7_O_EN_1: 1;
    };
} AON_NS_P7_0_P7_1_PAD_CFG_TYPE;

/* 0x1988   0x4000_1988
    0       R/W PAD_P7_O[2]                     1'b0
    1       R/W PAD_P7_E[2]                     1'b0
    2       R/W PAD_P7_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P7_PD[2]                1'b1
    4       R/W PAD_P7_PUPDC[2]                 1'b0
    5       R/W PAD_P7_WKEN[2]                  1'b0
    6       R/W PAD_P7_WKPOL[2]                 1'b0
    7       R/W PAD_P7_E2[2]                    1'b1
    8       R/W PAD_P7_SHDN[2]                  1'b1
    9       R/W PAD_P7_S[2]                     1'b0
    10      R/W PAD_P7_DEB[2]                   1'b0
    11      R/W PAD_P7_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P7_O_EN[2]                  1'h1
    16      R/W PAD_P7_O[3]                     1'b0
    17      R/W PAD_P7_E[3]                     1'b0
    18      R/W PAD_P7_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P7_PD[3]                1'b1
    20      R/W PAD_P7_PUPDC[3]                 1'b0
    21      R/W PAD_P7_WKEN[3]                  1'b0
    22      R/W PAD_P7_WKPOL[3]                 1'b0
    23      R/W PAD_P7_E2[3]                    1'b1
    24      R/W PAD_P7_SHDN[3]                  1'b1
    25      R/W PAD_P7_S[3]                     1'b0
    26      R/W PAD_P7_DEB[3]                   1'b0
    27      R/W PAD_P7_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P7_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P7_2_P7_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P7_O_2: 1;
        uint32_t PAD_P7_E_2: 1;
        uint32_t PAD_P7_PU_EN_2: 1;
        uint32_t AON_PAD_P7_PD_2: 1;
        uint32_t PAD_P7_PUPDC_2: 1;
        uint32_t PAD_P7_WKEN_2: 1;
        uint32_t PAD_P7_WKPOL_2: 1;
        uint32_t PAD_P7_E2_2: 1;
        uint32_t PAD_P7_SHDN_2: 1;
        uint32_t PAD_P7_S_2: 1;
        uint32_t PAD_P7_DEB_2: 1;
        uint32_t PAD_P7_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P7_O_EN_2: 1;
        uint32_t PAD_P7_O_3: 1;
        uint32_t PAD_P7_E_3: 1;
        uint32_t PAD_P7_PU_EN_3: 1;
        uint32_t AON_PAD_P7_PD_3: 1;
        uint32_t PAD_P7_PUPDC_3: 1;
        uint32_t PAD_P7_WKEN_3: 1;
        uint32_t PAD_P7_WKPOL_3: 1;
        uint32_t PAD_P7_E2_3: 1;
        uint32_t PAD_P7_SHDN_3: 1;
        uint32_t PAD_P7_S_3: 1;
        uint32_t PAD_P7_DEB_3: 1;
        uint32_t PAD_P7_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P7_O_EN_3: 1;
    };
} AON_NS_P7_2_P7_3_PAD_CFG_TYPE;

/* 0x198C   0x4000_198c
    0       R/W PAD_P7_O[4]                     1'b0
    1       R/W PAD_P7_E[4]                     1'b0
    2       R/W PAD_P7_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P7_PD[4]                1'b1
    4       R/W PAD_P7_PUPDC[4]                 1'b0
    5       R/W PAD_P7_WKEN[4]                  1'b0
    6       R/W PAD_P7_WKPOL[4]                 1'b0
    7       R/W PAD_P7_E2[4]                    1'b1
    8       R/W PAD_P7_SHDN[4]                  1'b1
    9       R/W PAD_P7_S[4]                     1'b0
    10      R/W PAD_P7_DEB[4]                   1'b0
    11      R/W PAD_P7_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P7_O_EN[4]                  1'h1
    16      R   RSVD                            1'b0
    17      R   RSVD                            1'b0
    18      R   RSVD                            1'b1
    19      R   RSVD                            1'b0
    20      R   RSVD                            1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R   RSVD                            1'b0
    24      R   RSVD                            1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    31:27   R   RSVD                            5'b0
 */
typedef volatile union _AON_NS_P7_4_P7_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P7_O_4: 1;
        uint32_t PAD_P7_E_4: 1;
        uint32_t PAD_P7_PU_EN_4: 1;
        uint32_t AON_PAD_P7_PD_4: 1;
        uint32_t PAD_P7_PUPDC_4: 1;
        uint32_t PAD_P7_WKEN_4: 1;
        uint32_t PAD_P7_WKPOL_4: 1;
        uint32_t PAD_P7_E2_4: 1;
        uint32_t PAD_P7_SHDN_4: 1;
        uint32_t PAD_P7_S_4: 1;
        uint32_t PAD_P7_DEB_4: 1;
        uint32_t PAD_P7_HS_MUX_4: 1;
        uint32_t RSVD_12: 3;
        uint32_t PAD_P7_O_EN_4: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 5;
    };
} AON_NS_P7_4_P7_5_PAD_CFG_TYPE;

/* 0x1990   0x4000_1990
    31:0    R   RSVD                            32'b0
 */
typedef volatile union _AON_NS_P7_6_P7_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_NS_P7_6_P7_7_PAD_CFG_TYPE;

/* 0x1994   0x4000_1994
    0       R/W PAD_SPI_SCK_O                   1'b0
    1       R/W PAD_SPI_SCK_E                   1'b0
    2       R/W PAD_SPI_SCK_PU_EN               1'b1
    3       R/W AON_PAD_SPI_SCK_PD              1'b0
    4       R/W PAD_SPI_SCK_PUPDC               1'b0
    5       R   RSVD                            1'b0
    6       R   RSVD                            1'b0
    7       R/W PAD_SPI_SCK_E2                  1'b1
    8       R/W PAD_SPI_SCK_SHDN                1'b1
    9       R   RSVD                            1'b0
    10      R   RSVD                            1'b0
    11      R/W PAD_SPI_SCK_HS_MUX              1'b0
    15:12   R   RSVD                            4'b0
    16      R/W PAD_SPI_CSN_O                   1'b0
    17      R/W PAD_SPI_CSN_E                   1'b0
    18      R/W PAD_SPI_CSN_PU_EN               1'b1
    19      R/W AON_PAD_SPI_CSN_PD              1'b0
    20      R/W PAD_SPI_CSN_PUPDC               1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R/W PAD_SPI_CSN_E2                  1'b1
    24      R/W PAD_SPI_CSN_SHDN                1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    27      R/W PAD_SPI_CSN_HS_MUX              1'b0
    31:28   R   RSVD                            4'b0
 */
typedef volatile union _AON_NS_SPIC0_PAD_CFG0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_SPI_SCK_O: 1;
        uint32_t PAD_SPI_SCK_E: 1;
        uint32_t PAD_SPI_SCK_PU_EN: 1;
        uint32_t AON_PAD_SPI_SCK_PD: 1;
        uint32_t PAD_SPI_SCK_PUPDC: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t PAD_SPI_SCK_E2: 1;
        uint32_t PAD_SPI_SCK_SHDN: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t PAD_SPI_SCK_HS_MUX: 1;
        uint32_t RSVD_5: 4;
        uint32_t PAD_SPI_CSN_O: 1;
        uint32_t PAD_SPI_CSN_E: 1;
        uint32_t PAD_SPI_CSN_PU_EN: 1;
        uint32_t AON_PAD_SPI_CSN_PD: 1;
        uint32_t PAD_SPI_CSN_PUPDC: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t PAD_SPI_CSN_E2: 1;
        uint32_t PAD_SPI_CSN_SHDN: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_SPI_CSN_HS_MUX: 1;
        uint32_t RSVD: 4;
    };
} AON_NS_SPIC0_PAD_CFG0_TYPE;

/* 0x1998   0x4000_1998
    0       R/W PAD_SPI_SIO0_O                  1'b0
    1       R/W PAD_SPI_SIO0_E                  1'b0
    2       R/W PAD_SPI_SIO0_PU_EN              1'b1
    3       R/W AON_PAD_SPI_SIO0_PD             1'b1
    4       R/W PAD_SPI_SIO0_PUPDC              1'b0
    5       R   RSVD                            1'b0
    6       R   RSVD                            1'b0
    7       R/W PAD_SPI_SIO0_E2                 1'b1
    8       R/W PAD_SPI_SIO0_SHDN               1'b1
    9       R   RSVD                            1'b0
    10      R   RSVD                            1'b0
    11      R/W PAD_SPI_SIO0_HS_MUX             1'b0
    15:12   R   RSVD                            4'b0
    16      R/W PAD_SPI_SIO1_O                  1'b0
    17      R/W PAD_SPI_SIO1_E                  1'b0
    18      R/W PAD_SPI_SIO1_PU_EN              1'b1
    19      R/W AON_PAD_SPI_SIO1_PD             1'b1
    20      R/W PAD_SPI_SIO1_PUPDC              1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R/W PAD_SPI_SIO1_E2                 1'b1
    24      R/W PAD_SPI_SIO1_SHDN               1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    27      R/W PAD_SPI_SIO1_HS_MUX             1'b0
    31:28   R   RSVD                            4'b0
 */
typedef volatile union _AON_NS_SPIC0_PAD_CFG1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_SPI_SIO0_O: 1;
        uint32_t PAD_SPI_SIO0_E: 1;
        uint32_t PAD_SPI_SIO0_PU_EN: 1;
        uint32_t AON_PAD_SPI_SIO0_PD: 1;
        uint32_t PAD_SPI_SIO0_PUPDC: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t PAD_SPI_SIO0_E2: 1;
        uint32_t PAD_SPI_SIO0_SHDN: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t PAD_SPI_SIO0_HS_MUX: 1;
        uint32_t RSVD_5: 4;
        uint32_t PAD_SPI_SIO1_O: 1;
        uint32_t PAD_SPI_SIO1_E: 1;
        uint32_t PAD_SPI_SIO1_PU_EN: 1;
        uint32_t AON_PAD_SPI_SIO1_PD: 1;
        uint32_t PAD_SPI_SIO1_PUPDC: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t PAD_SPI_SIO1_E2: 1;
        uint32_t PAD_SPI_SIO1_SHDN: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_SPI_SIO1_HS_MUX: 1;
        uint32_t RSVD: 4;
    };
} AON_NS_SPIC0_PAD_CFG1_TYPE;

/* 0x199C   0x4000_199c
    0       R/W PAD_SPI_SIO2_O                  1'b0
    1       R/W PAD_SPI_SIO2_E                  1'b0
    2       R/W PAD_SPI_SIO2_PU_EN              1'b1
    3       R/W AON_PAD_SPI_SIO2_PD             1'b1
    4       R/W PAD_SPI_SIO2_PUPDC              1'b0
    5       R   RSVD                            1'b0
    6       R   RSVD                            1'b0
    7       R/W PAD_SPI_SIO2_E2                 1'b1
    8       R/W PAD_SPI_SIO2_SHDN               1'b1
    9       R   RSVD                            1'b0
    10      R   RSVD                            1'b0
    11      R/W PAD_SPI_SIO2_HS_MUX             1'b0
    15:12   R   RSVD                            4'b0
    16      R/W PAD_SPI_SIO3_O                  1'b0
    17      R/W PAD_SPI_SIO3_E                  1'b0
    18      R/W PAD_SPI_SIO3_PU_EN              1'b1
    19      R/W AON_PAD_SPI_SIO3_PD             1'b1
    20      R/W PAD_SPI_SIO3_PUPDC              1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R/W PAD_SPI_SIO3_E2                 1'b1
    24      R/W PAD_SPI_SIO3_SHDN               1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    27      R/W PAD_SPI_SIO3_HS_MUX             1'b0
    31:28   R   RSVD                            4'b0
 */
typedef volatile union _AON_NS_SPIC0_PAD_CFG2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_SPI_SIO2_O: 1;
        uint32_t PAD_SPI_SIO2_E: 1;
        uint32_t PAD_SPI_SIO2_PU_EN: 1;
        uint32_t AON_PAD_SPI_SIO2_PD: 1;
        uint32_t PAD_SPI_SIO2_PUPDC: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t PAD_SPI_SIO2_E2: 1;
        uint32_t PAD_SPI_SIO2_SHDN: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t PAD_SPI_SIO2_HS_MUX: 1;
        uint32_t RSVD_5: 4;
        uint32_t PAD_SPI_SIO3_O: 1;
        uint32_t PAD_SPI_SIO3_E: 1;
        uint32_t PAD_SPI_SIO3_PU_EN: 1;
        uint32_t AON_PAD_SPI_SIO3_PD: 1;
        uint32_t PAD_SPI_SIO3_PUPDC: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t PAD_SPI_SIO3_E2: 1;
        uint32_t PAD_SPI_SIO3_SHDN: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t PAD_SPI_SIO3_HS_MUX: 1;
        uint32_t RSVD: 4;
    };
} AON_NS_SPIC0_PAD_CFG2_TYPE;

/* 0x19A0   0x4000_19a0
    31:0    R   RSVD                            32'b0
 */
typedef volatile union _AON_NS_P8_0_P8_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_NS_P8_0_P8_1_PAD_CFG_TYPE;

/* 0x19A4   0x4000_19a4
    31:0    R   RSVD                            32'b0
 */
typedef volatile union _AON_NS_P8_2_P8_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_NS_P8_2_P8_3_PAD_CFG_TYPE;

/* 0x19A8   0x4000_19a8
    31:0    R   RSVD                            32'b0
 */
typedef volatile union _AON_NS_P8_4_P8_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_NS_P8_4_P8_5_PAD_CFG_TYPE;

/* 0x19AC   0x4000_19ac
    31:0    R   RSVD                            32'b0
 */
typedef volatile union _AON_NS_P8_6_P8_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD;
    };
} AON_NS_P8_6_P8_7_PAD_CFG_TYPE;

/* 0x19B0   0x4000_19b0
    0       R/W PAD_P9_O[0]                     1'b0
    1       R/W PAD_P9_E[0]                     1'b0
    2       R/W PAD_P9_PU_EN[0]                 1'b1
    3       R/W AON_PAD_P9_PD[0]                1'b1
    4       R/W PAD_P9_PUPDC[0]                 1'b0
    5       R/W PAD_P9_WKEN[0]                  1'b0
    6       R/W PAD_P9_WKPOL[0]                 1'b0
    7       R/W PAD_P9_E2[0]                    1'b1
    8       R/W PAD_P9_SHDN[0]                  1'b1
    9       R/W PAD_P9_S[0]                     1'b0
    10      R/W PAD_P9_DEB[0]                   1'b0
    11      R/W PAD_P9_HS_MUX[0]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P9_O_EN[0]                  1'h1
    16      R/W PAD_P9_O[1]                     1'b0
    17      R/W PAD_P9_E[1]                     1'b0
    18      R/W PAD_P9_PU_EN[1]                 1'b1
    19      R/W AON_PAD_P9_PD[1]                1'b1
    20      R/W PAD_P9_PUPDC[1]                 1'b0
    21      R/W PAD_P9_WKEN[1]                  1'b0
    22      R/W PAD_P9_WKPOL[1]                 1'b0
    23      R/W PAD_P9_E2[1]                    1'b1
    24      R/W PAD_P9_SHDN[1]                  1'b1
    25      R/W PAD_P9_S[1]                     1'b0
    26      R/W PAD_P9_DEB[1]                   1'b0
    27      R/W PAD_P9_HS_MUX[1]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P9_O_EN[1]                  1'h1
 */
typedef volatile union _AON_NS_P9_0_P9_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P9_O_0: 1;
        uint32_t PAD_P9_E_0: 1;
        uint32_t PAD_P9_PU_EN_0: 1;
        uint32_t AON_PAD_P9_PD_0: 1;
        uint32_t PAD_P9_PUPDC_0: 1;
        uint32_t PAD_P9_WKEN_0: 1;
        uint32_t PAD_P9_WKPOL_0: 1;
        uint32_t PAD_P9_E2_0: 1;
        uint32_t PAD_P9_SHDN_0: 1;
        uint32_t PAD_P9_S_0: 1;
        uint32_t PAD_P9_DEB_0: 1;
        uint32_t PAD_P9_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P9_O_EN_0: 1;
        uint32_t PAD_P9_O_1: 1;
        uint32_t PAD_P9_E_1: 1;
        uint32_t PAD_P9_PU_EN_1: 1;
        uint32_t AON_PAD_P9_PD_1: 1;
        uint32_t PAD_P9_PUPDC_1: 1;
        uint32_t PAD_P9_WKEN_1: 1;
        uint32_t PAD_P9_WKPOL_1: 1;
        uint32_t PAD_P9_E2_1: 1;
        uint32_t PAD_P9_SHDN_1: 1;
        uint32_t PAD_P9_S_1: 1;
        uint32_t PAD_P9_DEB_1: 1;
        uint32_t PAD_P9_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P9_O_EN_1: 1;
    };
} AON_NS_P9_0_P9_1_PAD_CFG_TYPE;

/* 0x19B4   0x4000_19b4
    0       R/W PAD_P9_O[2]                     1'b0
    1       R/W PAD_P9_E[2]                     1'b0
    2       R/W PAD_P9_PU_EN[2]                 1'b1
    3       R/W AON_PAD_P9_PD[2]                1'b1
    4       R/W PAD_P9_PUPDC[2]                 1'b0
    5       R/W PAD_P9_WKEN[2]                  1'b0
    6       R/W PAD_P9_WKPOL[2]                 1'b0
    7       R/W PAD_P9_E2[2]                    1'b1
    8       R/W PAD_P9_SHDN[2]                  1'b1
    9       R/W PAD_P9_S[2]                     1'b0
    10      R/W PAD_P9_DEB[2]                   1'b0
    11      R/W PAD_P9_HS_MUX[2]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P9_O_EN[2]                  1'h1
    16      R/W PAD_P9_O[3]                     1'b0
    17      R/W PAD_P9_E[3]                     1'b0
    18      R/W PAD_P9_PU_EN[3]                 1'b1
    19      R/W AON_PAD_P9_PD[3]                1'b0
    20      R/W PAD_P9_PUPDC[3]                 1'b0
    21      R/W PAD_P9_WKEN[3]                  1'b0
    22      R/W PAD_P9_WKPOL[3]                 1'b0
    23      R/W PAD_P9_E2[3]                    1'b1
    24      R/W PAD_P9_SHDN[3]                  1'b1
    25      R/W PAD_P9_S[3]                     1'b0
    26      R/W PAD_P9_DEB[3]                   1'b0
    27      R/W PAD_P9_HS_MUX[3]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P9_O_EN[3]                  1'h1
 */
typedef volatile union _AON_NS_P9_2_P9_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P9_O_2: 1;
        uint32_t PAD_P9_E_2: 1;
        uint32_t PAD_P9_PU_EN_2: 1;
        uint32_t AON_PAD_P9_PD_2: 1;
        uint32_t PAD_P9_PUPDC_2: 1;
        uint32_t PAD_P9_WKEN_2: 1;
        uint32_t PAD_P9_WKPOL_2: 1;
        uint32_t PAD_P9_E2_2: 1;
        uint32_t PAD_P9_SHDN_2: 1;
        uint32_t PAD_P9_S_2: 1;
        uint32_t PAD_P9_DEB_2: 1;
        uint32_t PAD_P9_HS_MUX_2: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P9_O_EN_2: 1;
        uint32_t PAD_P9_O_3: 1;
        uint32_t PAD_P9_E_3: 1;
        uint32_t PAD_P9_PU_EN_3: 1;
        uint32_t AON_PAD_P9_PD_3: 1;
        uint32_t PAD_P9_PUPDC_3: 1;
        uint32_t PAD_P9_WKEN_3: 1;
        uint32_t PAD_P9_WKPOL_3: 1;
        uint32_t PAD_P9_E2_3: 1;
        uint32_t PAD_P9_SHDN_3: 1;
        uint32_t PAD_P9_S_3: 1;
        uint32_t PAD_P9_DEB_3: 1;
        uint32_t PAD_P9_HS_MUX_3: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P9_O_EN_3: 1;
    };
} AON_NS_P9_2_P9_3_PAD_CFG_TYPE;

/* 0x19B8   0x4000_19b8
    0       R/W PAD_P9_O[4]                     1'b0
    1       R/W PAD_P9_E[4]                     1'b0
    2       R/W PAD_P9_PU_EN[4]                 1'b1
    3       R/W AON_PAD_P9_PD[4]                1'b0
    4       R/W PAD_P9_PUPDC[4]                 1'b0
    5       R/W PAD_P9_WKEN[4]                  1'b0
    6       R/W PAD_P9_WKPOL[4]                 1'b0
    7       R/W PAD_P9_E2[4]                    1'b1
    8       R/W PAD_P9_SHDN[4]                  1'b1
    9       R/W PAD_P9_S[4]                     1'b0
    10      R/W PAD_P9_DEB[4]                   1'b0
    11      R/W PAD_P9_HS_MUX[4]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P9_O_EN[4]                  1'h1
    16      R/W PAD_P9_O[5]                     1'b0
    17      R/W PAD_P9_E[5]                     1'b0
    18      R/W PAD_P9_PU_EN[5]                 1'b1
    19      R/W AON_PAD_P9_PD[5]                1'b1
    20      R/W PAD_P9_PUPDC[5]                 1'b0
    21      R/W PAD_P9_WKEN[5]                  1'b0
    22      R/W PAD_P9_WKPOL[5]                 1'b0
    23      R/W PAD_P9_E2[5]                    1'b1
    24      R/W PAD_P9_SHDN[5]                  1'b1
    25      R/W PAD_P9_S[5]                     1'b0
    26      R/W PAD_P9_DEB[5]                   1'b0
    27      R/W PAD_P9_HS_MUX[5]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P9_O_EN[5]                  1'h1
 */
typedef volatile union _AON_NS_P9_4_P9_5_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P9_O_4: 1;
        uint32_t PAD_P9_E_4: 1;
        uint32_t PAD_P9_PU_EN_4: 1;
        uint32_t AON_PAD_P9_PD_4: 1;
        uint32_t PAD_P9_PUPDC_4: 1;
        uint32_t PAD_P9_WKEN_4: 1;
        uint32_t PAD_P9_WKPOL_4: 1;
        uint32_t PAD_P9_E2_4: 1;
        uint32_t PAD_P9_SHDN_4: 1;
        uint32_t PAD_P9_S_4: 1;
        uint32_t PAD_P9_DEB_4: 1;
        uint32_t PAD_P9_HS_MUX_4: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P9_O_EN_4: 1;
        uint32_t PAD_P9_O_5: 1;
        uint32_t PAD_P9_E_5: 1;
        uint32_t PAD_P9_PU_EN_5: 1;
        uint32_t AON_PAD_P9_PD_5: 1;
        uint32_t PAD_P9_PUPDC_5: 1;
        uint32_t PAD_P9_WKEN_5: 1;
        uint32_t PAD_P9_WKPOL_5: 1;
        uint32_t PAD_P9_E2_5: 1;
        uint32_t PAD_P9_SHDN_5: 1;
        uint32_t PAD_P9_S_5: 1;
        uint32_t PAD_P9_DEB_5: 1;
        uint32_t PAD_P9_HS_MUX_5: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P9_O_EN_5: 1;
    };
} AON_NS_P9_4_P9_5_PAD_CFG_TYPE;

/* 0x19BC   0x4000_19bc
    0       R/W PAD_P9_O[6]                     1'b0
    1       R/W PAD_P9_E[6]                     1'b0
    2       R/W PAD_P9_PU_EN[6]                 1'b1
    3       R/W AON_PAD_P9_PD[6]                1'b1
    4       R/W PAD_P9_PUPDC[6]                 1'b0
    5       R/W PAD_P9_WKEN[6]                  1'b0
    6       R/W PAD_P9_WKPOL[6]                 1'b0
    7       R/W PAD_P9_E2[6]                    1'b1
    8       R/W PAD_P9_SHDN[6]                  1'b1
    9       R/W PAD_P9_S[6]                     1'b0
    10      R/W PAD_P9_DEB[6]                   1'b0
    11      R/W PAD_P9_HS_MUX[6]                1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P9_O_EN[6]                  1'h1
    16      R/W PAD_P9_O[7]                     1'b0
    17      R/W PAD_P9_E[7]                     1'b0
    18      R/W PAD_P9_PU_EN[7]                 1'b1
    19      R/W AON_PAD_P9_PD[7]                1'b1
    20      R/W PAD_P9_PUPDC[7]                 1'b0
    21      R/W PAD_P9_WKEN[7]                  1'b0
    22      R/W PAD_P9_WKPOL[7]                 1'b0
    23      R/W PAD_P9_E2[7]                    1'b1
    24      R/W PAD_P9_SHDN[7]                  1'b1
    25      R/W PAD_P9_S[7]                     1'b0
    26      R/W PAD_P9_DEB[7]                   1'b0
    27      R/W PAD_P9_HS_MUX[7]                1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P9_O_EN[7]                  1'h1
 */
typedef volatile union _AON_NS_P9_6_P9_7_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P9_O_6: 1;
        uint32_t PAD_P9_E_6: 1;
        uint32_t PAD_P9_PU_EN_6: 1;
        uint32_t AON_PAD_P9_PD_6: 1;
        uint32_t PAD_P9_PUPDC_6: 1;
        uint32_t PAD_P9_WKEN_6: 1;
        uint32_t PAD_P9_WKPOL_6: 1;
        uint32_t PAD_P9_E2_6: 1;
        uint32_t PAD_P9_SHDN_6: 1;
        uint32_t PAD_P9_S_6: 1;
        uint32_t PAD_P9_DEB_6: 1;
        uint32_t PAD_P9_HS_MUX_6: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P9_O_EN_6: 1;
        uint32_t PAD_P9_O_7: 1;
        uint32_t PAD_P9_E_7: 1;
        uint32_t PAD_P9_PU_EN_7: 1;
        uint32_t AON_PAD_P9_PD_7: 1;
        uint32_t PAD_P9_PUPDC_7: 1;
        uint32_t PAD_P9_WKEN_7: 1;
        uint32_t PAD_P9_WKPOL_7: 1;
        uint32_t PAD_P9_E2_7: 1;
        uint32_t PAD_P9_SHDN_7: 1;
        uint32_t PAD_P9_S_7: 1;
        uint32_t PAD_P9_DEB_7: 1;
        uint32_t PAD_P9_HS_MUX_7: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P9_O_EN_7: 1;
    };
} AON_NS_P9_6_P9_7_PAD_CFG_TYPE;

/* 0x19C0   0x4000_19c0
    0       R/W PAD_P10_O[0]                    1'b0
    1       R/W PAD_P10_E[0]                    1'b0
    2       R/W PAD_P10_PU_EN[0]                1'b1
    3       R/W AON_PAD_P10_PD[0]               1'b1
    4       R/W PAD_P10_PUPDC[0]                1'b0
    5       R/W PAD_P10_WKEN[0]                 1'b0
    6       R/W PAD_P10_WKPOL[0]                1'b0
    7       R/W PAD_P10_E2[0]                   1'b1
    8       R/W PAD_P10_SHDN[0]                 1'b1
    9       R/W PAD_P10_S[0]                    1'b0
    10      R/W PAD_P10_DEB[0]                  1'b0
    11      R/W PAD_P10_HS_MUX[0]               1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P10_O_EN[0]                 1'h1
    16      R/W PAD_P10_O[1]                    1'b0
    17      R/W PAD_P10_E[1]                    1'b0
    18      R/W PAD_P10_PU_EN[1]                1'b1
    19      R/W AON_PAD_P10_PD[1]               1'b1
    20      R/W PAD_P10_PUPDC[1]                1'b0
    21      R/W PAD_P10_WKEN[1]                 1'b0
    22      R/W PAD_P10_WKPOL[1]                1'b0
    23      R/W PAD_P10_E2[1]                   1'b1
    24      R/W PAD_P10_SHDN[1]                 1'b1
    25      R/W PAD_P10_S[1]                    1'b0
    26      R/W PAD_P10_DEB[1]                  1'b0
    27      R/W PAD_P10_HS_MUX[1]               1'b0
    30:28   R   RSVD                            3'b0
    31      R/W PAD_P10_O_EN[1]                 1'h1
 */
typedef volatile union _AON_NS_P10_0_P10_1_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P10_O_0: 1;
        uint32_t PAD_P10_E_0: 1;
        uint32_t PAD_P10_PU_EN_0: 1;
        uint32_t AON_PAD_P10_PD_0: 1;
        uint32_t PAD_P10_PUPDC_0: 1;
        uint32_t PAD_P10_WKEN_0: 1;
        uint32_t PAD_P10_WKPOL_0: 1;
        uint32_t PAD_P10_E2_0: 1;
        uint32_t PAD_P10_SHDN_0: 1;
        uint32_t PAD_P10_S_0: 1;
        uint32_t PAD_P10_DEB_0: 1;
        uint32_t PAD_P10_HS_MUX_0: 1;
        uint32_t RSVD_1: 3;
        uint32_t PAD_P10_O_EN_0: 1;
        uint32_t PAD_P10_O_1: 1;
        uint32_t PAD_P10_E_1: 1;
        uint32_t PAD_P10_PU_EN_1: 1;
        uint32_t AON_PAD_P10_PD_1: 1;
        uint32_t PAD_P10_PUPDC_1: 1;
        uint32_t PAD_P10_WKEN_1: 1;
        uint32_t PAD_P10_WKPOL_1: 1;
        uint32_t PAD_P10_E2_1: 1;
        uint32_t PAD_P10_SHDN_1: 1;
        uint32_t PAD_P10_S_1: 1;
        uint32_t PAD_P10_DEB_1: 1;
        uint32_t PAD_P10_HS_MUX_1: 1;
        uint32_t RSVD: 3;
        uint32_t PAD_P10_O_EN_1: 1;
    };
} AON_NS_P10_0_P10_1_PAD_CFG_TYPE;

/* 0x19C4   0x4000_19c4
    0       R/W PAD_P10_O[2]                    1'b0
    1       R/W PAD_P10_E[2]                    1'b0
    2       R/W PAD_P10_PU_EN[2]                1'b1
    3       R/W AON_PAD_P10_PD[2]               1'b1
    4       R/W PAD_P10_PUPDC[2]                1'b0
    5       R/W PAD_P10_WKEN[2]                 1'b0
    6       R/W PAD_P10_WKPOL[2]                1'b0
    7       R/W PAD_P10_E2[2]                   1'b1
    8       R/W PAD_P10_SHDN[2]                 1'b1
    9       R/W PAD_P10_S[2]                    1'b0
    10      R/W PAD_P10_DEB[2]                  1'b0
    11      R/W PAD_P10_HS_MUX[2]               1'b0
    14:12   R   RSVD                            3'b0
    15      R/W PAD_P10_O_EN[2]                 1'h1
    16      R   RSVD                            1'b0
    17      R   RSVD                            1'b0
    18      R   RSVD                            1'b1
    19      R   RSVD                            1'b1
    20      R   RSVD                            1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R   RSVD                            1'b1
    24      R   RSVD                            1'b1
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    27      R   RSVD                            1'b0
    31:28   R   RSVD                            4'b0
 */
typedef volatile union _AON_NS_P10_2_P10_3_PAD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P10_O_2: 1;
        uint32_t PAD_P10_E_2: 1;
        uint32_t PAD_P10_PU_EN_2: 1;
        uint32_t AON_PAD_P10_PD_2: 1;
        uint32_t PAD_P10_PUPDC_2: 1;
        uint32_t PAD_P10_WKEN_2: 1;
        uint32_t PAD_P10_WKPOL_2: 1;
        uint32_t PAD_P10_E2_2: 1;
        uint32_t PAD_P10_SHDN_2: 1;
        uint32_t PAD_P10_S_2: 1;
        uint32_t PAD_P10_DEB_2: 1;
        uint32_t PAD_P10_HS_MUX_2: 1;
        uint32_t RSVD_13: 3;
        uint32_t PAD_P10_O_EN_2: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 4;
    };
} AON_NS_P10_2_P10_3_PAD_CFG_TYPE;

/* 0x19C8   0x4000_19c8
    0       R/W PAD_E3                          1'b0
    31:1    R   RSVD                            31'b0
 */
typedef volatile union _AON_NS_PAD_E3_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_E3: 1;
        uint32_t RSVD: 31;
    };
} AON_NS_PAD_E3_CFG_TYPE;

/* 0x1AA0   0x4000_1aa0
    0       w1c PAD_P0_STS[0]                   1'b1
    1       w1c PAD_P0_STS[1]                   1'b1
    2       w1c PAD_P0_STS[2]                   1'b1
    3       w1c PAD_P0_STS[3]                   1'b1
    4       w1c PAD_P0_STS[4]                   1'b1
    5       w1c PAD_P0_STS[5]                   1'b1
    6       w1c PAD_P0_STS[6]                   1'b1
    7       w1c PAD_P0_STS[7]                   1'b1
    8       w1c PAD_P1_STS[0]                   1'b1
    9       w1c PAD_P1_STS[1]                   1'b1
    10      w1c PAD_P1_STS[2]                   1'b1
    11      w1c PAD_P1_STS[3]                   1'b1
    12      w1c PAD_P1_STS[4]                   1'b1
    13      w1c PAD_P1_STS[5]                   1'b1
    14      w1c PAD_P1_STS[6]                   1'b1
    15      w1c PAD_P1_STS[7]                   1'b1
    16      w1c PAD_P2_STS[0]                   1'b1
    17      w1c PAD_P2_STS[1]                   1'b1
    18      w1c PAD_P2_STS[2]                   1'b1
    19      w1c PAD_P2_STS[3]                   1'b1
    20      w1c PAD_P2_STS[4]                   1'b1
    21      w1c PAD_P2_STS[5]                   1'b1
    22      w1c PAD_P2_STS[6]                   1'b1
    23      w1c PAD_P2_STS[7]                   1'b1
    24      w1c PAD_P3_STS[0]                   1'b1
    25      w1c PAD_P3_STS[1]                   1'b1
    26      w1c PAD_P3_STS[2]                   1'b1
    27      w1c PAD_P3_STS[3]                   1'b1
    28      w1c PAD_P3_STS[4]                   1'b1
    29      w1c PAD_P3_STS[5]                   1'b1
    30      w1c PAD_P3_STS[6]                   1'b1
    31      w1c PAD_P3_STS[7]                   1'b1
 */
typedef volatile union _AON_NS_PAD_Status_0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_STS_0: 1;
        uint32_t PAD_P0_STS_1: 1;
        uint32_t PAD_P0_STS_2: 1;
        uint32_t PAD_P0_STS_3: 1;
        uint32_t PAD_P0_STS_4: 1;
        uint32_t PAD_P0_STS_5: 1;
        uint32_t PAD_P0_STS_6: 1;
        uint32_t PAD_P0_STS_7: 1;
        uint32_t PAD_P1_STS_0: 1;
        uint32_t PAD_P1_STS_1: 1;
        uint32_t PAD_P1_STS_2: 1;
        uint32_t PAD_P1_STS_3: 1;
        uint32_t PAD_P1_STS_4: 1;
        uint32_t PAD_P1_STS_5: 1;
        uint32_t PAD_P1_STS_6: 1;
        uint32_t PAD_P1_STS_7: 1;
        uint32_t PAD_P2_STS_0: 1;
        uint32_t PAD_P2_STS_1: 1;
        uint32_t PAD_P2_STS_2: 1;
        uint32_t PAD_P2_STS_3: 1;
        uint32_t PAD_P2_STS_4: 1;
        uint32_t PAD_P2_STS_5: 1;
        uint32_t PAD_P2_STS_6: 1;
        uint32_t PAD_P2_STS_7: 1;
        uint32_t PAD_P3_STS_0: 1;
        uint32_t PAD_P3_STS_1: 1;
        uint32_t PAD_P3_STS_2: 1;
        uint32_t PAD_P3_STS_3: 1;
        uint32_t PAD_P3_STS_4: 1;
        uint32_t PAD_P3_STS_5: 1;
        uint32_t PAD_P3_STS_6: 1;
        uint32_t PAD_P3_STS_7: 1;
    };
} AON_NS_PAD_Status_0_TYPE;

/* 0x1AA4   0x4000_1aa4
    0       w1c PAD_P4_STS[0]                   1'b1
    1       w1c PAD_P4_STS[1]                   1'b1
    2       w1c PAD_P4_STS[2]                   1'b1
    3       w1c PAD_P4_STS[3]                   1'b1
    4       w1c PAD_P4_STS[4]                   1'b1
    5       w1c PAD_P4_STS[5]                   1'b1
    6       w1c PAD_P4_STS[6]                   1'b1
    7       w1c PAD_P4_STS[7]                   1'b1
    8       w1c PAD_P5_STS[0]                   1'b1
    9       w1c PAD_P5_STS[1]                   1'b1
    10      w1c PAD_P5_STS[2]                   1'b1
    11      w1c PAD_P5_STS[3]                   1'b1
    12      w1c PAD_P5_STS[4]                   1'b1
    13      w1c PAD_P5_STS[5]                   1'b1
    14      w1c PAD_P5_STS[6]                   1'b1
    15      w1c PAD_P5_STS[7]                   1'b1
    16      w1c PAD_P6_STS[0]                   1'b1
    17      w1c PAD_P6_STS[1]                   1'b1
    18      w1c PAD_P6_STS[2]                   1'b1
    19      w1c PAD_P6_STS[3]                   1'b1
    20      w1c PAD_P6_STS[4]                   1'b1
    21      w1c PAD_P6_STS[5]                   1'b1
    22      w1c PAD_P6_STS[6]                   1'b1
    23      w1c PAD_P6_STS[7]                   1'b1
    24      w1c PAD_P7_STS[0]                   1'b1
    25      w1c PAD_P7_STS[1]                   1'b1
    26      w1c PAD_P7_STS[2]                   1'b1
    27      w1c PAD_P7_STS[3]                   1'b1
    28      w1c PAD_P7_STS[4]                   1'b1
    31:29   R   RSVD                            3'b0
 */
typedef volatile union _AON_NS_PAD_Status_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_STS_0: 1;
        uint32_t PAD_P4_STS_1: 1;
        uint32_t PAD_P4_STS_2: 1;
        uint32_t PAD_P4_STS_3: 1;
        uint32_t PAD_P4_STS_4: 1;
        uint32_t PAD_P4_STS_5: 1;
        uint32_t PAD_P4_STS_6: 1;
        uint32_t PAD_P4_STS_7: 1;
        uint32_t PAD_P5_STS_0: 1;
        uint32_t PAD_P5_STS_1: 1;
        uint32_t PAD_P5_STS_2: 1;
        uint32_t PAD_P5_STS_3: 1;
        uint32_t PAD_P5_STS_4: 1;
        uint32_t PAD_P5_STS_5: 1;
        uint32_t PAD_P5_STS_6: 1;
        uint32_t PAD_P5_STS_7: 1;
        uint32_t PAD_P6_STS_0: 1;
        uint32_t PAD_P6_STS_1: 1;
        uint32_t PAD_P6_STS_2: 1;
        uint32_t PAD_P6_STS_3: 1;
        uint32_t PAD_P6_STS_4: 1;
        uint32_t PAD_P6_STS_5: 1;
        uint32_t PAD_P6_STS_6: 1;
        uint32_t PAD_P6_STS_7: 1;
        uint32_t PAD_P7_STS_0: 1;
        uint32_t PAD_P7_STS_1: 1;
        uint32_t PAD_P7_STS_2: 1;
        uint32_t PAD_P7_STS_3: 1;
        uint32_t PAD_P7_STS_4: 1;
        uint32_t RSVD: 3;
    };
} AON_NS_PAD_Status_1_TYPE;

/* 0x1AA8   0x4000_1aa8
    0       w1c PAD_32K_XI_STS                  1'b1
    1       w1c PAD_32K_XO_STS                  1'b1
    2       w1c PAD_MICBIAS_STS                 1'b1
    3       w1c PAD_DAC_N_STS                   1'b1
    4       w1c PAD_DAC_P_STS                   1'b1
    31:5    R   RSVD                            27'b0
 */
typedef volatile union _AON_NS_PAD_Status_2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_32K_XI_STS: 1;
        uint32_t PAD_32K_XO_STS: 1;
        uint32_t PAD_MICBIAS_STS: 1;
        uint32_t PAD_DAC_N_STS: 1;
        uint32_t PAD_DAC_P_STS: 1;
        uint32_t RSVD: 27;
    };
} AON_NS_PAD_Status_2_TYPE;

/* 0x1AAC   0x4000_1aac
    7:0     R   RSVD                            8'b0
    13:8    R/W debIO_cnt_lmt                   6'b0
    14      R/W debIO_wakeup_en                 1'b0
    15      w1c debIO_wakeup_sts                1'b1
    31:16   R   RSVD                            16'b0
 */
typedef volatile union _AON_NS_REG0X_DEBIO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_1: 8;
        uint32_t debIO_cnt_lmt: 6;
        uint32_t debIO_wakeup_en: 1;
        uint32_t debIO_wakeup_sts: 1;
        uint32_t RSVD: 16;
    };
} AON_NS_REG0X_DEBIO_TYPE;

/* 0x1AB0   0x4000_1ab0
    0       w1c PAD_P9_STS[0]                   1'b1
    1       w1c PAD_P9_STS[1]                   1'b1
    2       w1c PAD_P9_STS[2]                   1'b1
    3       w1c PAD_P9_STS[3]                   1'b1
    4       w1c PAD_P9_STS[4]                   1'b1
    5       w1c PAD_P9_STS[5]                   1'b1
    6       w1c PAD_P9_STS[6]                   1'b1
    7       w1c PAD_P9_STS[7]                   1'b1
    8       w1c PAD_P10_STS[0]                  1'b1
    9       w1c PAD_P10_STS[1]                  1'b1
    10      w1c PAD_P10_STS[2]                  1'b1
    11      R   RSVD                            1'b0
    12      R   RSVD                            1'b0
    13      R   RSVD                            1'b0
    14      R   RSVD                            1'b0
    15      R   RSVD                            1'b0
    16      R   RSVD                            1'b0
    17      R   RSVD                            1'b0
    18      R   RSVD                            1'b0
    19      R   RSVD                            1'b0
    20      R   RSVD                            1'b0
    21      R   RSVD                            1'b0
    22      R   RSVD                            1'b0
    23      R   RSVD                            1'b0
    24      R   RSVD                            1'b0
    25      R   RSVD                            1'b0
    26      R   RSVD                            1'b0
    27      R   RSVD                            1'b0
    28      R   RSVD                            1'b0
    31:29   R   RSVD                            3'b0
 */
typedef volatile union _AON_NS_PAD_Status_3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P9_STS_0: 1;
        uint32_t PAD_P9_STS_1: 1;
        uint32_t PAD_P9_STS_2: 1;
        uint32_t PAD_P9_STS_3: 1;
        uint32_t PAD_P9_STS_4: 1;
        uint32_t PAD_P9_STS_5: 1;
        uint32_t PAD_P9_STS_6: 1;
        uint32_t PAD_P9_STS_7: 1;
        uint32_t PAD_P10_STS_0: 1;
        uint32_t PAD_P10_STS_1: 1;
        uint32_t PAD_P10_STS_2: 1;
        uint32_t RSVD_18: 1;
        uint32_t RSVD_17: 1;
        uint32_t RSVD_16: 1;
        uint32_t RSVD_15: 1;
        uint32_t RSVD_14: 1;
        uint32_t RSVD_13: 1;
        uint32_t RSVD_12: 1;
        uint32_t RSVD_11: 1;
        uint32_t RSVD_10: 1;
        uint32_t RSVD_9: 1;
        uint32_t RSVD_8: 1;
        uint32_t RSVD_7: 1;
        uint32_t RSVD_6: 1;
        uint32_t RSVD_5: 1;
        uint32_t RSVD_4: 1;
        uint32_t RSVD_3: 1;
        uint32_t RSVD_2: 1;
        uint32_t RSVD_1: 1;
        uint32_t RSVD: 3;
    };
} AON_NS_PAD_Status_3_TYPE;

/* 0x1AE0   0x4000_1ae0
    31:0    R/W FW_APP_0X                       32'h0
 */
typedef volatile union _AON_NS_REG0X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reset_reason: 8;
        uint32_t RSVD: 24;
    };
} AON_NS_REG0X_APP_TYPE;

/* 0x1AE4   0x4000_1ae4
    31:0    R/W FW_APP_1X                       32'h0
 */
typedef volatile union _AON_NS_REG1X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_1X;
    };
} AON_NS_REG1X_APP_TYPE;

/* 0x1AE8   0x4000_1ae8
    31:0    R/W FW_APP_2X                       32'h0
 */
typedef volatile union _AON_NS_REG2X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_2X;
    };
} AON_NS_REG2X_APP_TYPE;

/* 0x1AEC   0x4000_1aec
    31:0    R/W FW_APP_3X                       32'h0
 */
typedef volatile union _AON_NS_REG3X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_3X;
    };
} AON_NS_REG3X_APP_TYPE;

/* 0x1AF0   0x4000_1af0
    31:0    R/W FW_APP_4X                       32'h0
 */
typedef volatile union _AON_NS_REG4X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_4X;
    };
} AON_NS_REG4X_APP_TYPE;

/* 0x1AF4   0x4000_1af4
    31:0    R/W FW_APP_5X                       32'h0
 */
typedef volatile union _AON_NS_REG5X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_5X;
    };
} AON_NS_REG5X_APP_TYPE;

/* 0x1AF8   0x4000_1af8
    31:0    R/W FW_APP_6X                       32'h0
 */
typedef volatile union _AON_NS_REG6X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_6X;
    };
} AON_NS_REG6X_APP_TYPE;

/* 0x1AFC   0x4000_1afc
    31:0    R/W FW_APP_7X                       32'h0
 */
typedef volatile union _AON_NS_REG7X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_7X;
    };
} AON_NS_REG7X_APP_TYPE;

/* 0x1B00   0x4000_1b00
    31:0    R/W FW_APP_8X                       32'h0
 */
typedef volatile union _AON_NS_REG8X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_8X;
    };
} AON_NS_REG8X_APP_TYPE;

/* 0x1B04   0x4000_1b04
    31:0    R/W FW_APP_9X                       32'h0
 */
typedef volatile union _AON_NS_REG9X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_9X;
    };
} AON_NS_REG9X_APP_TYPE;

/* 0x1B08   0x4000_1b08
    31:0    R/W FW_APP_10X                      32'h0
 */
typedef volatile union _AON_NS_REG10X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_10X;
    };
} AON_NS_REG10X_APP_TYPE;

/* 0x1B0C   0x4000_1b0c
    31:0    R/W FW_APP_11X                      32'h0
 */
typedef volatile union _AON_NS_REG11X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_11X;
    };
} AON_NS_REG11X_APP_TYPE;

/* 0x1B10   0x4000_1b10
    31:0    R/W FW_APP_12X                      32'h0
 */
typedef volatile union _AON_NS_REG12X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_12X;
    };
} AON_NS_REG12X_APP_TYPE;

/* 0x1B14   0x4000_1b14
    31:0    R/W FW_APP_13X                      32'h0
 */
typedef volatile union _AON_NS_REG13X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_13X;
    };
} AON_NS_REG13X_APP_TYPE;

/* 0x1B18   0x4000_1b18
    31:0    R/W FW_APP_14X                      32'h0
 */
typedef volatile union _AON_NS_REG14X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_14X;
    };
} AON_NS_REG14X_APP_TYPE;

/* 0x1B1C   0x4000_1b1c
    31:0    R/W FW_APP_15X                      32'h0
 */
typedef volatile union _AON_NS_REG15X_APP_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_APP_15X;
    };
} AON_NS_REG15X_APP_TYPE;

/* 0x1B60   0x4000_1b60
    15:0    R/W AON_WDG_WP                      16'h0
    31:16   R/W RSVD                            16'h0
 */
typedef volatile union _AON_NS_AON_WDG_WP0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_WDG_WP: 16;
        uint32_t RSVD: 16;
    };
} AON_NS_AON_WDG_WP0_TYPE;

/* 0x1B64   0x4000_1b64
    15:0    R/W AON_WDG_CLK_DIV_FACTOR          16'hC80
    27:16   R/W AON_WDG_CNT_LIMIT               12'h6E
    28      R/W AON_WDG_MODE                    1'b0
    29      R/W AON_WDG_CNT_CTL                 1'b0
    30      R/W AON_WDG_CNT_RELOAD              1'b0
    31      R/W AON_WDG_ENABLE                  1'b0
 */
typedef volatile union _AON_NS_AON_WDG_CONFIG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_WDG_CLK_DIV_FACTOR: 16;
        uint32_t AON_WDG_CNT_LIMIT: 12;
        uint32_t AON_WDG_MODE: 1;
        uint32_t AON_WDG_CNT_CTL: 1;
        uint32_t AON_WDG_CNT_RELOAD: 1;
        uint32_t AON_WDG_ENABLE: 1;
    };
} AON_NS_AON_WDG_CONFIG_TYPE;

/* 0x1B68   0x4000_1b68
    15:0    R/WACAON_WDG_CNT_RESET               16'h0
    31:16   R/WACRSVD                            16'h0
 */
typedef volatile union _AON_NS_AON_WDG_CNT_RESET0_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_WDG_CNT_RESET: 16;
        uint32_t RSVD: 16;
    };
} AON_NS_AON_WDG_CNT_RESET0_TYPE;

/* 0x1B6C   0x4000_1b6c
    0       R/W AON_WDG_WP_SEC                  1'b0
    1       R/W AON_WDG_CONFIG_SEC              1'b0
    2       R/W AON_WDG_RESET_SEC               1'b0
    31:3    R/W RSVD                            29'b0
 */
typedef volatile union _AON_NS_AON_WDG_SEC_CTL_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_WDG_WP_SEC: 1;
        uint32_t AON_WDG_CONFIG_SEC: 1;
        uint32_t AON_WDG_RESET_SEC: 1;
        uint32_t RSVD: 29;
    };
} AON_NS_AON_WDG_SEC_CTL_TYPE;

/* 0x1B90   0x4000_1b90
    0       R/W anapar_pow_ad<0>                1'b0
    1       R/W anapar_pow_ad<1>                1'b0
    2       R/W anapar_pow_ad<2>                1'b0
    3       R/W EN_ILIMIT                       1'b0
    4       R/W EN_VREF_SW                      1'b0
    5       R/W EN_VREF_RC_BYPASS               1'b0
    6       R/W REG0X_LDO_DUMMY                 1'b0
    7       R/W hw_pd                           1'b1
    15:8    R/W REG0X_LDO_DUMMY2                8'b0
    22:16   R/W REG_LDO_TUNE<6:0>               7'b1011111
    25:23   R/W LDO_SW[2:0]                     3'b100
    26      R/W AUX_LDO_VPULSE                  1'b0
    27      R/W SELLDO                          1'b1
    28      R/W AUX_DOUBLE_OP_I                 1'b0
    30:29   R/W LDOBW                           2'b11
    31      R/W Power                           1'b1
 */
typedef volatile union _AON_NS_REG0X_LDO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t anapar_pow_ad_0: 1;
        uint32_t anapar_pow_ad_1: 1;
        uint32_t anapar_pow_ad_2: 1;
        uint32_t EN_ILIMIT: 1;
        uint32_t EN_VREF_SW: 1;
        uint32_t EN_VREF_RC_BYPASS: 1;
        uint32_t REG0X_LDO_DUMMY: 1;
        uint32_t hw_pd: 1;
        uint32_t REG0X_LDO_DUMMY2: 8;
        uint32_t REG_LDO_TUNE_6_0: 7;
        uint32_t LDO_SW_2_0: 3;
        uint32_t AUX_LDO_VPULSE: 1;
        uint32_t SELLDO: 1;
        uint32_t AUX_DOUBLE_OP_I: 1;
        uint32_t LDOBW: 2;
        uint32_t Power: 1;
    };
} AON_NS_REG0X_LDO_TYPE;

/* 0x1B94   0x4000_1b94
    0       R/W pow                             1'b0
    1       R/W pow_ref                         1'b0
    2       R/W reg_ck                          1'b0
    3       R/W reg_delay                       1'b0
    5:4     R/W reg_vref_sel[1:0]               2'b10
    6       R/W reg_revck                       1'b0
    8:7     R/W reg_cmpdec[1:0]                 2'b00
    9       R/W reg_meta                        1'b0
    10      R/W sel_ln                          1'b0
    11      R/W sel_lna                         1'b1
    13:12   R/W reg_vcm_sel<1:0>                2'b01
    15:14   R/W REG0X_AUX_V09_DUMMY             2'b00
    23:16   R/W bypassen[7:0]                   8'b00000000
    31:24   R/W REG1X_AUX_dummy                 8'b0
 */
typedef volatile union _AON_NS_REG0X_AUX_V09_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t pow: 1;
        uint32_t pow_ref: 1;
        uint32_t reg_ck: 1;
        uint32_t reg_delay: 1;
        uint32_t reg_vref_sel_1_0: 2;
        uint32_t reg_revck: 1;
        uint32_t reg_cmpdec_1_0: 2;
        uint32_t reg_meta: 1;
        uint32_t sel_ln: 1;
        uint32_t sel_lna: 1;
        uint32_t reg_vcm_sel_1_0: 2;
        uint32_t REG0X_AUX_V09_DUMMY: 2;
        uint32_t bypassen_7_0: 8;
        uint32_t REG1X_AUX_dummy: 8;
    };
} AON_NS_REG0X_AUX_V09_TYPE;

/* 0x1B98   0x4000_1b98
    0       R/W POW_SD_H                        1'b0
    4:1     R/W CH_NUM_H[3:0]                   4'b0000
    5       R/W SD_POSEDGE_H                    1'b1
    7:6     R/W REG0X_SD_DUMMY                  2'b00
    15:8    R/W REG0X_SD_DUMMY2                 8'b0
    31:16   R   RSVD                            16'b0
 */
typedef volatile union _AON_NS_REG0X_SD_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t POW_SD_H: 1;
        uint32_t CH_NUM_H_3_0: 4;
        uint32_t SD_POSEDGE_H: 1;
        uint32_t REG0X_SD_DUMMY: 2;
        uint32_t REG0X_SD_DUMMY2: 8;
        uint32_t RSVD: 16;
    };
} AON_NS_REG0X_SD_TYPE;

/* 0x1BD0   0x4000_1bd0
    1:0     R/W X_INITIAL_PHASE                 2'b0
    2       R/W X_SET_INITAL_PHASE              1'b0
    3       R/W X_CNT_PAUSE                     1'b0
    4       R/W X_CNT_SCALE                     1'b0
    5       R/W X_ILLEGAL_INT_EN                1'b0
    6       R/W X_CNT_INT_EN                    1'b0
    7       R/W ILLEGAL_INT_MASK                1'b1
    8       R/W CNT_INT_MASK                    1'b1
    21:9    R/W X_DEBOUNCE_CNT                  13'b0
    22      R/W X_DEBOUNCE_EN                   1'b0
    23      R/W X_WAKE_AON_MASK                 1'b1
    24      R/W X_INT_MASK                      1'b1
    28:25   R/W REG_CONFIG_DUMMY1               4'b0
    29      R/W X_RST                           1'b0
    30      R/WACX_FSM_EN                        1'b0
    31      R/W X_AXIS_EN                       1'b0
 */
typedef volatile union _AON_NS_REG_CONFIG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t X_INITIAL_PHASE: 2;
        uint32_t X_SET_INITAL_PHASE: 1;
        uint32_t X_CNT_PAUSE: 1;
        uint32_t X_CNT_SCALE: 1;
        uint32_t X_ILLEGAL_INT_EN: 1;
        uint32_t X_CNT_INT_EN: 1;
        uint32_t ILLEGAL_INT_MASK: 1;
        uint32_t CNT_INT_MASK: 1;
        uint32_t X_DEBOUNCE_CNT: 13;
        uint32_t X_DEBOUNCE_EN: 1;
        uint32_t X_WAKE_AON_MASK: 1;
        uint32_t X_INT_MASK: 1;
        uint32_t REG_CONFIG_DUMMY1: 4;
        uint32_t X_RST: 1;
        uint32_t X_FSM_EN: 1;
        uint32_t X_AXIS_EN: 1;
    };
} AON_NS_REG_CONFIG_TYPE;

/* 0x1BD4   0x4000_1bd4
    15:0    R   ACC_CNT                         1'b0
    16      R/W1CCNT_OF_FLG                      1'b0
    17      R/W1CCNT_UF_FLG                      1'b0
    18      R/W1CCNT_INT_STA                     1'b0
    19      R/W1CILLEGAL_INT_STA                 1'b0
    20      R   CNT_DIR                         1'b0
    21      R/W REG_SR_X_DUMMY                  1'b0
    23:22   R   debug_state_x                   1'b0
    31:24   R   debug_illegal_counter_x         1'b0
 */
typedef volatile union _AON_NS_REG_SR_X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ACC_CNT: 16;
        uint32_t CNT_OF_FLG: 1;
        uint32_t CNT_UF_FLG: 1;
        uint32_t CNT_INT_STA: 1;
        uint32_t ILLEGAL_INT_STA: 1;
        uint32_t CNT_DIR: 1;
        uint32_t REG_SR_X_DUMMY: 1;
        uint32_t debug_state_x: 2;
        uint32_t debug_illegal_counter_x: 8;
    };
} AON_NS_REG_SR_X_TYPE;

/* 0x1BD8   0x4000_1bd8
    0       R/WACACC_CNT_CLR                     1'b0
    1       R/WACCNT_INT_CLR                     1'b0
    2       R/WACOF_FLG_CLR                      1'b0
    3       R/WACUF_FLG_CLR                      1'b0
    4       R/WACILLEGAL_INT_CLR                 1'b0
    5       R/WACILLEGAL_CNT_CLR                 1'b0
    31:6    R/W INT_CLR_DUMMY                   26'b0
 */
typedef volatile union _AON_NS_INT_CLR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ACC_CNT_CLR: 1;
        uint32_t CNT_INT_CLR: 1;
        uint32_t OF_FLG_CLR: 1;
        uint32_t UF_FLG_CLR: 1;
        uint32_t ILLEGAL_INT_CLR: 1;
        uint32_t ILLEGAL_CNT_CLR: 1;
        uint32_t INT_CLR_DUMMY: 26;
    };
} AON_NS_INT_CLR_TYPE;

/* 0x1C00   0x4000_1c00
    31:0    R   r_km4_core_wdt_lat_km4_pc_value 32'b0
 */
typedef volatile union _AON_NS_REG30_CORE_KM4_PC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_pc_value;
    };
} AON_NS_REG30_CORE_KM4_PC_TYPE;

/* 0x1C04   0x4000_1c04
    31:0    R   r_km4_core_wdt_lat_km4_lr       32'b0
 */
typedef volatile union _AON_NS_REG34_CORE_KM4_LR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_lr;
    };
} AON_NS_REG34_CORE_KM4_LR_TYPE;

/* 0x1C08   0x4000_1c08
    31:0    R   r_km4_core_wdt_lat_km4_pc_ex    32'b0
 */
typedef volatile union _AON_NS_REG38_CORE_KM4_PC_EX_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_pc_ex;
    };
} AON_NS_REG38_CORE_KM4_PC_EX_TYPE;

/* 0x1C0C   0x4000_1c0c
    31:0    R   r_km4_core_wdt_lat_km4_xpsr_r   32'b0
 */
typedef volatile union _AON_NS_REG3C_CORE_KM4_XPSR_R_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_xpsr_r;
    };
} AON_NS_REG3C_CORE_KM4_XPSR_R_TYPE;

/* 0x1C10   0x4000_1c10
    31:0    R   r_km4_core_wdt_lat_km4_msp_s    32'b0
 */
typedef volatile union _AON_NS_REG40_CORE_KM4_MSP_S_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_msp_s;
    };
} AON_NS_REG40_CORE_KM4_MSP_S_TYPE;

/* 0x1C14   0x4000_1c14
    31:0    R   r_km4_core_wdt_lat_km4_psp_s    32'b0
 */
typedef volatile union _AON_NS_REG44_CORE_KM4_PSP_S_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_psp_s;
    };
} AON_NS_REG44_CORE_KM4_PSP_S_TYPE;

/* 0x1C18   0x4000_1c18
    31:0    R   r_km4_core_wdt_lat_km4_msp_ns   32'b0
 */
typedef volatile union _AON_NS_REG48_CORE_KM4_MSP_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_msp_ns;
    };
} AON_NS_REG48_CORE_KM4_MSP_NS_TYPE;

/* 0x1C1C   0x4000_1c1c
    31:0    R   r_km4_core_wdt_lat_km4_psp_ns   32'b0
 */
typedef volatile union _AON_NS_REG4C_CORE_KM4_PSP_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_core_wdt_lat_km4_psp_ns;
    };
} AON_NS_REG4C_CORE_KM4_PSP_NS_TYPE;

/* 0x1C20   0x4000_1c20
    31:0    R   r_km4_aon_wdt_lat_km4_pc_value  32'b0
 */
typedef volatile union _AON_NS_REG50_AON_KM4_PC_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_pc_value;
    };
} AON_NS_REG50_AON_KM4_PC_TYPE;

/* 0x1C24   0x4000_1c24
    31:0    R   r_km4_aon_wdt_lat_km4_lr        32'b0
 */
typedef volatile union _AON_NS_REG54_AON_KM4_LR_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_lr;
    };
} AON_NS_REG54_AON_KM4_LR_TYPE;

/* 0x1C28   0x4000_1c28
    31:0    R   r_km4_aon_wdt_lat_km4_pc_ex     32'b0
 */
typedef volatile union _AON_NS_REG58_AON_KM4_PC_EX_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_pc_ex;
    };
} AON_NS_REG58_AON_KM4_PC_EX_TYPE;

/* 0x1C2C   0x4000_1c2c
    31:0    R   r_km4_aon_wdt_lat_km4_xpsr_r    32'b0
 */
typedef volatile union _AON_NS_REG5C_AON_KM4_XPSR_R_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_xpsr_r;
    };
} AON_NS_REG5C_AON_KM4_XPSR_R_TYPE;

/* 0x1C30   0x4000_1c30
    31:0    R   r_km4_aon_wdt_lat_km4_msp_s     32'b0
 */
typedef volatile union _AON_NS_REG60_AON_KM4_MSP_S_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_msp_s;
    };
} AON_NS_REG60_AON_KM4_MSP_S_TYPE;

/* 0x1C34   0x4000_1c34
    31:0    R   r_km4_aon_wdt_lat_km4_psp_s     32'b0
 */
typedef volatile union _AON_NS_REG64_AON_KM4_PSP_S_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_psp_s;
    };
} AON_NS_REG64_AON_KM4_PSP_S_TYPE;

/* 0x1C38   0x4000_1c38
    31:0    R   r_km4_aon_wdt_lat_km4_msp_ns    32'b0
 */
typedef volatile union _AON_NS_REG68_AON_KM4_MSP_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_msp_ns;
    };
} AON_NS_REG68_AON_KM4_MSP_NS_TYPE;

/* 0x1C3C   0x4000_1c3c
    31:0    R   r_km4_aon_wdt_lat_km4_psp_ns    32'b0
 */
typedef volatile union _AON_NS_REG6C_AON_KM4_PSP_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_aon_wdt_lat_km4_psp_ns;
    };
} AON_NS_REG6C_AON_KM4_PSP_NS_TYPE;

/* 0x1C40   0x4000_1c40
    1:0     R   r_aon_wdt_mode                  2'b0
    2       R   r_aon_wdt_timeout_flag          1'b0
    31:3    R   RSVD                            29'b0
 */
typedef volatile union _AON_NS_REG_AON_WDT_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_aon_wdt_mode: 2;
        uint32_t r_aon_wdt_timeout_flag: 1;
        uint32_t RSVD: 29;
    };
} AON_NS_REG_AON_WDT_MODE_TYPE;

/* 0x1C44   0x4000_1c44
    1:0     R   r_km4_wdt_mode                  2'b0
    2       R   r_km4_wdt_timeout_flag          1'b0
    31:3    R   RSVD                            29'b0
 */
typedef volatile union _AON_NS_REG_KM4_WDT_MODE_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t r_km4_wdt_mode: 2;
        uint32_t r_km4_wdt_timeout_flag: 1;
        uint32_t RSVD: 29;
    };
} AON_NS_REG_KM4_WDT_MODE_TYPE;

/* 0x1D00   0x4000_1d00
    0       R/W km4_aon_boot_done               1'b0
    1       R/W km4_pon_boot_done               1'b0
    2       R/W km4_dvfs_normal_vdd_mode        1'b0
    3       R/W km4_boot_rsvd0                  1'b0
    4       R/W is_pf_rtc_clk_32000Hz           1'b0
    5       R/W is_user_rtc_clk_32000Hz         1'b0
    6       R/W is_btmac_clk_32000Hz            1'b0
    7       R/W is_aon_clk_32000Hz              1'b0
    8       R/W is_systick_clk_32000Hz          1'b0
    31:9    R/W km4_boot_rsvd1                  23'b0
 */
typedef volatile union _AON_NS_REG0X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t km4_aon_boot_done: 1;
        uint32_t km4_pon_boot_done: 1;
        uint32_t km4_dvfs_normal_vdd_mode: 1;
        uint32_t km4_boot_rsvd0: 1;
        uint32_t is_pf_rtc_clk_32000Hz: 1;
        uint32_t is_user_rtc_clk_32000Hz: 1;
        uint32_t is_btmac_clk_32000Hz: 1;
        uint32_t is_aon_clk_32000Hz: 1;
        uint32_t is_systick_clk_32000Hz: 1;
        uint32_t km4_boot_rsvd1: 23;
    };
} AON_NS_REG0X_FW_GENERAL_NS_TYPE;

/* 0x1D04   0x4000_1d04
    15:0    R/W FW_GENERAL_NS_REG2X             16'h0
    31:16   R/W FW_GENERAL_NS_REG3X             16'h0
 */
typedef volatile union _AON_NS_REG2X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_NS_REG2X: 16;
        uint32_t FW_GENERAL_NS_REG3X: 16;
    };
} AON_NS_REG2X_FW_GENERAL_NS_TYPE;

/* 0x1D08   0x4000_1d08
    15:0    R/W FW_GENERAL_NS_REG4X             16'h0
    31:16   R/W FW_GENERAL_NS_REG5X             16'h0
 */
typedef volatile union _AON_NS_REG4X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_NS_REG4X: 16;
        uint32_t FW_GENERAL_NS_REG5X: 16;
    };
} AON_NS_REG4X_FW_GENERAL_NS_TYPE;

/* 0x1D0C   0x4000_1d0c
    15:0    R/W FW_GENERAL_NS_REG6X             16'h0
    31:16   R/W FW_GENERAL_NS_REG7X             16'h0
 */
typedef volatile union _AON_NS_REG6X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_NS_REG6X: 16;
        uint32_t FW_GENERAL_NS_REG7X: 16;
    };
} AON_NS_REG6X_FW_GENERAL_NS_TYPE;

/* 0x1D10   0x4000_1d10
    0       R/W ota_mode                        1'b0
    1       R/W is_ft_mode                      1'b0
    2       R/W is_hci_mode                     1'b0
    3       R/W is_single_tone_mode             1'b0
    15:4    R/W rsvd                            12'h0
    31:16   R/W FW_GENERAL_NS_REG9X             16'h0
 */
typedef volatile union _AON_NS_REG8X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ota_mode: 1;
        uint32_t is_ft_mode: 1;
        uint32_t is_hci_mode: 1;
        uint32_t is_single_tone_mode: 1;
        uint32_t rsvd: 12;
        uint32_t FW_GENERAL_NS_REG9X: 16;
    };
} AON_NS_REG8X_FW_GENERAL_NS_TYPE;

/* 0x1D14   0x4000_1d14
    15:0    R/W FW_GENERAL_NS_REG10X            16'h0
    31:16   R/W FW_GENERAL_NS_REG11X            16'h0
 */
typedef volatile union _AON_NS_REG10X_FW_GENERAL_NS_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_GENERAL_NS_REG10X: 16;
        uint32_t FW_GENERAL_NS_REG11X: 16;
    };
} AON_NS_REG10X_FW_GENERAL_NS_TYPE;

/* 0x1D80   0x4000_1d80
    7:0     R/W PAD_P0_E_LCD[7:0]               8'b0
    9:8     R   RSVD                            2'b0
    15:10   R/W PAD_P1_E_LCD[7:2]               6'b0
    23:16   R   RSVD                            8'b0
    25:24   R   RSVD                            2'b0
    31:26   R/W PAD_P3_E_LCD[7:2]               6'b0
 */
typedef volatile union _AON_NS_P3_P1_PAD_E_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_E_LCD_7_0: 8;
        uint32_t RSVD_2: 2;
        uint32_t PAD_P1_E_LCD_7_2: 6;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 2;
        uint32_t PAD_P3_E_LCD_7_2: 6;
    };
} AON_NS_P3_P1_PAD_E_LCD_CFG_TYPE;

/* 0x1D84   0x4000_1d84
    7:0     R/W PAD_P4_E_LCD[7:0]               8'b0
    13:8    R/W PAD_P5_E_LCD[5:0]               6'b0
    15:14   R   RSVD                            2'b0
    23:16   R   RSVD                            8'b0
    31:24   R   RSVD                            8'b0
 */
typedef volatile union _AON_NS_P7_P4_PAD_E_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_E_LCD_7_0: 8;
        uint32_t PAD_P5_E_LCD_5_0: 6;
        uint32_t RSVD_2: 2;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 8;
    };
} AON_NS_P7_P4_PAD_E_LCD_CFG_TYPE;

/* 0x1D88   0x4000_1d88
    7:0     R   RSVD                            8'b0
    10:8    R/W PAD_P9_E_LCD[2:0]               3'b0
    15:11   R   RSVD                            5'b0
    23:16   R   RSVD                            8'b0
    31:24   R   RSVD                            8'b0
 */
typedef volatile union _AON_NS_P11_P8_PAD_E_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_3: 8;
        uint32_t PAD_P9_E_LCD_2_0: 3;
        uint32_t RSVD_2: 5;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 8;
    };
} AON_NS_P11_P8_PAD_E_LCD_CFG_TYPE;

/* 0x1D8C   0x4000_1d8c
    7:0     R/W PAD_P0_SHDN_LCD[7:0]            8'b0
    9:8     R   RSVD                            2'b0
    15:10   R/W PAD_P1_SHDN_LCD[7:2]            6'b0
    23:16   R   RSVD                            8'b0
    25:24   R   RSVD                            2'b0
    31:26   R/W PAD_P3_SHDN_LCD[7:2]            6'b0
 */
typedef volatile union _AON_NS_P3_P1_PAD_SHDN_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P0_SHDN_LCD_7_0: 8;
        uint32_t RSVD_2: 2;
        uint32_t PAD_P1_SHDN_LCD_7_2: 6;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 2;
        uint32_t PAD_P3_SHDN_LCD_7_2: 6;
    };
} AON_NS_P3_P1_PAD_SHDN_LCD_CFG_TYPE;

/* 0x1D90   0x4000_1d90
    7:0     R/W PAD_P4_SHDN_LCD[7:0]            8'b0
    13:8    R/W PAD_P5_SHDN_LCD[5:0]            6'b0
    15:14   R   RSVD                            2'b0
    23:16   R   RSVD                            8'b0
    31:24   R   RSVD                            8'b0
 */
typedef volatile union _AON_NS_P7_P4_PAD_SHDN_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PAD_P4_SHDN_LCD_7_0: 8;
        uint32_t PAD_P5_SHDN_LCD_5_0: 6;
        uint32_t RSVD_2: 2;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 8;
    };
} AON_NS_P7_P4_PAD_SHDN_LCD_CFG_TYPE;

/* 0x1D94   0x4000_1d94
    7:0     R   RSVD                            8'b0
    10:8    R/W PAD_P9_SHDN_LCD[2:0]            3'b0
    15:11   R   RSVD                            5'b0
    23:16   R   RSVD                            8'b0
    31:24   R   RSVD                            8'b0
 */
typedef volatile union _AON_NS_P11_P8_PAD_SHDN_LCD_CFG_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RSVD_3: 8;
        uint32_t PAD_P9_SHDN_LCD_2_0: 3;
        uint32_t RSVD_2: 5;
        uint32_t RSVD_1: 8;
        uint32_t RSVD: 8;
    };
} AON_NS_P11_P8_PAD_SHDN_LCD_CFG_TYPE;

/* 0x1DC0   0x4000_1dc0
    4:0     R/W REG0X_SDADC_LDO_DUMMY           5'b01010
    5       R/W REG_POCDB_SDADC                 1'b0
    6       R/W REG_ANAPAR_POW_LDO<0>           1'b0
    7       R/W REG_ANAPAR_POW_LDO<1>           1'b0
    12:8    R/W REG_ANAPAR_LDO<4:0>             5'b10000
    13      R/W REG_ANAPAR_LDO<5>               1'b0
    14      R/W REG_ANAPAR_LDO<6>               1'b0
    15      R/W REG_ANAPAR_LDO<7>               1'b0
    17:16   R/W REG_ANAPAR_LDO<9:8>             2'b00
    18      R/W REG_ANAPAR_LDO<10>              1'b0
    21:19   R/W REG_ANAPAR_LDO<13:11>           3'b100
    24:22   R/W REG_ANAPAR_LDO<16:14>           3'b100
    25      R/W REG_ANAPAR_LDO<17>              1'b0
    26      R/W REG_ANAPAR_LDO<18>              1'b0
    31:27   R/W REG_ANAPAR_LDO<23:17>           5'b10101
 */
typedef volatile union _AON_NS_REG0X_SDADC_LDO_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t REG0X_SDADC_LDO_DUMMY: 5;
        uint32_t REG_POCDB_SDADC: 1;
        uint32_t REG_ANAPAR_POW_LDO_0: 1;
        uint32_t REG_ANAPAR_POW_LDO_1: 1;
        uint32_t REG_ANAPAR_LDO_4_0: 5;
        uint32_t REG_ANAPAR_LDO_5: 1;
        uint32_t REG_ANAPAR_LDO_6: 1;
        uint32_t REG_ANAPAR_LDO_7: 1;
        uint32_t REG_ANAPAR_LDO_9_8: 2;
        uint32_t REG_ANAPAR_LDO_10: 1;
        uint32_t REG_ANAPAR_LDO_13_11: 3;
        uint32_t REG_ANAPAR_LDO_16_14: 3;
        uint32_t REG_ANAPAR_LDO_17: 1;
        uint32_t REG_ANAPAR_LDO_18: 1;
        uint32_t REG_ANAPAR_LDO_23_17: 5;
    } b;
} AON_NS_REG0X_SDADC_LDO_TYPE;

#define AON_REG_BASE 0x40000000

#define AON_REG_READ(Offset)                                            \
    ((uint32_t)*((volatile uint32_t*)(AON_REG_BASE+(Offset))))

#define AON_REG_WRITE(Offset, Value)                                    \
    ((*((volatile uint32_t*)(AON_REG_BASE + (Offset)))) = (Value))

#define AON_REG_UPDATE(Offset, Mask, Value)                             \
    do {                                                                \
        uint32_t temp;                                                  \
        temp = AON_REG_READ(Offset) & ~(Mask);                          \
        AON_REG_WRITE(Offset, (temp | ((Value) & (Mask))));             \
    } while(0)

#define AON_REG_READ_BITFIELD(Offset, Bitfield)                         \
    (((Offset##_TYPE)AON_REG_READ(Offset)).Bitfield)

#define AON_REG_WRITE_BITFIELD(Offset, Bitfield, Value)                 \
    do {                                                                \
        Offset##_TYPE temp = {.d32 = AON_REG_READ(Offset)};             \
        temp.Bitfield = Value;                                          \
        AON_REG_WRITE(Offset, temp.d32);                                \
    } while(0)
#endif
