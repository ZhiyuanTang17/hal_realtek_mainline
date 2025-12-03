/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PLATFORM_REG_H
#define PLATFORM_REG_H
#include <stdint.h>

/* ================================================================================ */
/* ================                PLATFORM Register               ================ */
/* ===========     Reference: rtl87x2g_Reg_SoC_202201012_v0.xlsx     =========== */
/* ================================================================================ */
typedef struct
{
    /* 0x0000       0x4000_3000
        31:0    R/W    RSVD                            32'h0
    */
    __IO uint32_t RSVD_0000;

    /* 0x0004       0x4000_3004
        0       R/W1C  spic0_intr_r                    1'h0
        1       R/W1C  spic1_intr_r                    1'h0
        2       R/W1C  spic2_intr_r                    1'h0
        3       R/W1C  trng_intr_r                     1'h0
        4       R/W1C  lpcomp_intr_r                   1'h0
        5       R/W1C  spi_phy1_intr_r                 1'h0
        30:6    R      RSVD                            25'h0
        31      R/W1C  utmi_suspend_n_r                1'h0
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_STATUS;
        struct
        {
            __IO uint32_t spic0_intr_r: 1;
            __IO uint32_t spic1_intr_r: 1;
            __IO uint32_t spic2_intr_r: 1;
            __IO uint32_t trng_intr_r: 1;
            __IO uint32_t lpcomp_intr_r: 1;
            __IO uint32_t spi_phy1_intr_r: 1;
            __I uint32_t RESERVED_0: 25;
            __IO uint32_t utmi_suspend_n_r: 1;
        } BITS_004;
    } u_004;

    /* 0x0008       0x4000_3008
        31:0    R/W    low_pri_int_mode                32'hFFFFFFFF
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_MODE;
        struct
        {
            __IO uint32_t low_pri_int_mode: 32;
        } BITS_008;
    } u_008;

    /* 0x000C       0x4000_300c
        31:0    R/W    low_pri_int_en                  32'h0
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_EN;
        struct
        {
            __IO uint32_t low_pri_int_en: 32;
        } BITS_00C;
    } u_00C;

    /* 0x0010       0x4000_3010
        0       R      timer_intr1_intr0_r             1'h0
        1       R      bluewiz_intr_r                  1'h0
        2       R      RSVD                            1'h0
        3       R      bluewiz_dma_intr_r              1'h0
        4       R      pro_intr_r                      1'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t BT_MAC_INTERRUPT;
        struct
        {
            __I uint32_t timer_intr1_intr0_r: 1;
            __I uint32_t bluewiz_intr_r: 1;
            __I uint32_t RESERVED_1: 1;
            __I uint32_t bluewiz_dma_intr_r: 1;
            __I uint32_t pro_intr_r: 1;
            __I uint32_t RESERVED_0: 27;
        } BITS_010;
    } u_010;

    /* 0x0014       0x4000_3014
        23:0     R       RSVD                                           24'h0
        26:24    R/W     RSVD                                           3'h0
        31:27    R       RSVD                                           5'h0
    */
    union
    {
        __IO uint32_t RXI_INTERRUPT;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_014;
    } u_014;

    /* 0x0018       0x4000_3018
        31:0    R/W    low_pri_int_pol                 32'h0
    */
    union
    {
        __IO uint32_t INTERRUPT_EDGE_OPTION;
        struct
        {
            __IO uint32_t low_pri_int_pol: 32;
        } BITS_018;
    } u_018;

    /* 0x001C       0x4000_301c
        11:0    RW     debug_sel                       12'h0
        15:12   R      RSVD                            4'h0
        23:16   R/W    can_dbg_sel                     8'h0
        24      R/W    can_dbg_en                      1'h0
        28:25   R      RSVD                            4'h0
        29      R/W    spi_speed_up_sim                1'h0
        30      R      RSVD                            1'h0
        31      R/W    RSVD                            1'h0
    */
    union
    {
        __IO uint32_t REG_DEBUG_SEL;
        struct
        {
            __IO uint32_t debug_sel: 12;
            __I uint32_t RESERVED_3: 4;
            __IO uint32_t can_dbg_sel: 8;
            __IO uint32_t can_dbg_en: 1;
            __I uint32_t RESERVED_2: 4;
            __IO uint32_t spi_speed_up_sim: 1;
            __I uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 1;
        } BITS_01C;
    } u_01C;

    /* 0x0014       0x4000_3014
        11:0     R       RSVD                                           12'h0
        31:12    R/W     RSVD                                           12'h0
    */
    union
    {
        __IO uint32_t REG_DATA_FIFO_SWAP_CTRL;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_020;
    } u_020;

    /* 0x0024       0x4000_3024
        0       R      timer0_toggle                   1'h0
        1       R      timer1_toggle                   1'h0
        2       R      timer2_toggle                   1'h0
        3       R      timer3_toggle                   1'h0
        4       R      timer4_toggle                   1'h0
        5       R      timer5_toggle                   1'h0
        6       R      timer6_toggle                   1'h0
        7       R      timer7_toggle                   1'h0
        8       R/W    spic0_mem_wr_en                 1'h0
        9       R/W    spic1_mem_wr_en                 1'h0
        10      R/W    spic2_mem_wr_en                 1'h0
        11      W1O    spic_mem_wr_lock                1'h0
        12      R/W    RSVD                            1'h0
        13      R/W    RSVD                            1'h0
        14      R/W    dmac_clk_always_disable         1'h0
        15      R/W    dmac_clk_always_enable          1'h1
        16      R/W    RSVD                            1'h0
        24:17   W1O    timer_dma_en                    1'h0
        26:25   R/W    uart_force_cg_en                2'h3
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t REG_MISC;
        struct
        {
            __I uint32_t timer0_toggle: 1;
            __I uint32_t timer1_toggle: 1;
            __I uint32_t timer2_toggle: 1;
            __I uint32_t timer3_toggle: 1;
            __I uint32_t timer4_toggle: 1;
            __I uint32_t timer5_toggle: 1;
            __I uint32_t timer6_toggle: 1;
            __I uint32_t timer7_toggle: 1;
            __IO uint32_t spic0_mem_wr_en: 1;
            __IO uint32_t spic1_mem_wr_en: 1;
            __IO uint32_t spic2_mem_wr_en: 1;
            __IO uint32_t spic_mem_wr_lock: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t dmac_clk_always_disable: 1;
            __IO uint32_t dmac_clk_always_enable: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t timer_dma_en: 8;
            __IO uint32_t uart_force_cg_en: 2;
            __I uint32_t RESERVED_0: 5;
        } BITS_024;
    } u_024;

    /* 0x0028       0x4000_3028
        0       R/W    spic0_dma_tx_sel                1'h0
        1       R/W    spic0_dma_rx_sel                1'h0
        2       R/W    spic1_dma_tx_sel                1'h0
        3       R/W    spic1_dma_rx_sel                1'h0
        4       R/W    spic2_dma_tx_sel                1'h0
        5       R/W    spic2_dma_rx_sel                1'h0
        31:6    R      RSVD                            26'h0
    */
    union
    {
        __IO uint32_t REG_SPIC_DMAC_HS_SHARE;
        struct
        {
            __IO uint32_t spic0_dma_tx_sel: 1;
            __IO uint32_t spic0_dma_rx_sel: 1;
            __IO uint32_t spic1_dma_tx_sel: 1;
            __IO uint32_t spic1_dma_rx_sel: 1;
            __IO uint32_t spic2_dma_tx_sel: 1;
            __IO uint32_t spic2_dma_rx_sel: 1;
            __I uint32_t RESERVED_0: 26;
        } BITS_028;
    } u_028;

    /* 0x002C       0x4000_302c
        31:0    R      RSVD                            32'h0
    */
    union
    {
        __IO uint32_t REG_DMAC_SUSPEND_RESUME;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_02C;
    } u_02C;

    /* 0x0030       0x4000_3030
        0       R      km4_mve_inactive                1'h1
        1       R      km4_pbus_inactive               1'h1
        2       R      km4_tcm_dma_inactive            1'h1
        3       R      rxi350_dmac0_inactive           1'h1
        4       R      spic0_inactive                  1'h1
        5       R      spic1_inactive                  1'h1
        6       R      spic2_inactive                  1'h1
        7       R      spic0_mem_inactive              1'h1
        8       R      spic1_mem_inactive              1'h1
        9       R      spic2_mem_inactive              1'h1
        10      R      ppe_inactive                    1'h1
        11      R      display_inactive                1'h1
        12      R      usbotg_inactive                 1'h1
        13      R      sdio_host0_inactive             1'h1
        14      R      gmac_inactive                   1'h1
        15      R      gmac_ctrl_inactive              1'h1
        31:16   R      RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_PLATFORM_STATUS;
        struct
        {
            __I uint32_t km4_mve_inactive: 1;
            __I uint32_t km4_pbus_inactive: 1;
            __I uint32_t km4_tcm_dma_inactive: 1;
            __I uint32_t rxi350_dmac0_inactive: 1;
            __I uint32_t spic0_inactive: 1;
            __I uint32_t spic1_inactive: 1;
            __I uint32_t spic2_inactive: 1;
            __I uint32_t spic0_mem_inactive: 1;
            __I uint32_t spic1_mem_inactive: 1;
            __I uint32_t spic2_mem_inactive: 1;
            __I uint32_t ppe_inactive: 1;
            __I uint32_t display_inactive: 1;
            __I uint32_t usbotg_inactive: 1;
            __I uint32_t sdio_host0_inactive: 1;
            __I uint32_t gmac_inactive: 1;
            __I uint32_t gmac_ctrl_inactive: 1;
            __I uint32_t RESERVED_0: 16;
        } BITS_030;
    } u_030;

    /* 0x0034       0x4000_3034
        0       R/W    km4_nmi_ctrl_enable             1'h0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_NMI_CTRL;
        struct
        {
            __IO uint32_t km4_nmi_ctrl_enable: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_034;
    } u_034;

    __IO uint32_t RSVD_0x38[5];

    /* 0x004C       0x4000_304c
        0       R/W    data_ram_err_flag_en            1'h0
        1       R/W    data_ram_err_int_en             1'h0
        2       R/W    data_ram_err_flag_clr           1'h0
        3       R/W    data_ram_err_int_clr            1'h0
        10:4    R      RSVD                            7'h0
        27:11   R      data_ram_err_flag_addr          17'h0
        28      R      data_ram_err_flag_we            1'h0
        29      R      data_ram_err_flag_re            1'h0
        30      R      data_ram_err_flag_valid         1'h0
        31      R      data_ram_err_int                1'h0
    */
    union
    {
        __IO uint32_t REG_DATA_RAM_ERR_FLAG;
        struct
        {
            __IO uint32_t data_ram_err_flag_en: 1;
            __IO uint32_t data_ram_err_int_en: 1;
            __IO uint32_t data_ram_err_flag_clr: 1;
            __IO uint32_t data_ram_err_int_clr: 1;
            __I uint32_t RESERVED_0: 7;
            __I uint32_t data_ram_err_flag_addr: 17;
            __I uint32_t data_ram_err_flag_we: 1;
            __I uint32_t data_ram_err_flag_re: 1;
            __I uint32_t data_ram_err_flag_valid: 1;
            __I uint32_t data_ram_err_int: 1;
        } BITS_04C;
    } u_04C;

    /* 0x0050       0x4000_3050
        31:0    R/W    km4_keep_0                      32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_KEEP_0_BOUNDARY;
        struct
        {
            __IO uint32_t km4_keep_0: 32;
        } BITS_050;
    } u_050;

    /* 0x0054       0x4000_3054
        31:0    R/W    km4_keep_1                      32'hFFFFFFFF
    */
    union
    {
        __IO uint32_t REG_KM4_KEEP_1_BOUNDARY;
        struct
        {
            __IO uint32_t km4_keep_1: 32;
        } BITS_054;
    } u_054;

    /* 0x0058       0x4000_3058
        31:0    R/W    km4_initpbusrange               32'h4000E000
    */
    union
    {
        __IO uint32_t REG_KM4_INITPBUSRANGE;
        struct
        {
            __IO uint32_t km4_initpbusrange: 32;
        } BITS_058;
    } u_058;

    /* 0x005C       0x4000_305c
        31:0    R/W    km4_initzwfrange                32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_INITZWFRANGE;
        struct
        {
            __IO uint32_t km4_initzwfrange: 32;
        } BITS_05C;
    } u_05C;

    /* 0x0060       0x4000_3060
        26:0    R/W    km4_init_xo_range_top           27'h00000ff
        27      R/W    km4_init_xo_range_en            1'h1
        28      W1O    km4_xo_range_lock               1'h0
        31:29   R      RSVD                            3'h0
    */
    union
    {
        __IO uint32_t REG_KM4_XO_CFG_0;
        struct
        {
            __IO uint32_t km4_init_xo_range_top: 27;
            __IO uint32_t km4_init_xo_range_en: 1;
            __IO uint32_t km4_xo_range_lock: 1;
            __I uint32_t RESERVED_0: 3;
        } BITS_060;
    } u_060;

    /* 0x0064       0x4000_3064
        26:0    R/W    km4_init_xo_range_base          27'h0
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t REG_KM4_XO_CFG_1;
        struct
        {
            __IO uint32_t km4_init_xo_range_base: 27;
            __I uint32_t RESERVED_0: 5;
        } BITS_064;
    } u_064;

    /* 0x0068       0x4000_3068
        0       R/W    km4_retention_mode              1'h0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_RET_CFG_0;
        struct
        {
            __IO uint32_t km4_retention_mode: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_068;
    } u_068;

    /* 0x006C       0x4000_306c
        0       R/W    r_km4_dvfs_en                   1'h0
        31:1   R      RSVD                             31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_DVFS_CTRL;
        struct
        {
            __IO uint32_t r_km4_dvfs_en: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_06C;
    } u_06C;

    /* 0x0070       0x4000_3070
        29:0    R      RSVD                            30'h0
        30      R/W    ppe_clk_always_disable          1'h0
        31      R/W    ppe_clk_always_enable           1'h1
    */
    union
    {
        __IO uint32_t REG_PPE_CTRL;
        struct
        {
            __I uint32_t RESERVED_0: 30;
            __IO uint32_t ppe_clk_always_disable: 1;
            __IO uint32_t ppe_clk_always_enable: 1;
        } BITS_070;
    } u_070;

    __IO uint32_t RSVD_0x74[3];

    /* 0x0080       0x4000_3080
        0       R/W    r_sys_32bits_timer_rst_sel      1'h1
        1       R/W    r_sys_32bits_timer_manual_rstb  1'h0
        31:2    R      RSVD                            30'h0
    */
    union
    {
        __IO uint32_t REG_KM4_SYS_CNT_CFG_0;
        struct
        {
            __IO uint32_t r_sys_32bits_timer_rst_sel: 1;
            __IO uint32_t r_sys_32bits_timer_manual_rstb: 1;
            __I uint32_t RESERVED_0: 30;
        } BITS_080;
    } u_080;

    /* 0x0084       0x4000_3084
        31:0    R      cpu_sys_32bits_timer_cnt        32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_SYS_CNT_CFG_1;
        struct
        {
            __I uint32_t cpu_sys_32bits_timer_cnt: 32;
        } BITS_084;
    } u_084;

    /* 0x0088       0x4000_3088
        0       R/W    r_epalna_od                     1'b0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_TESTMODE_SEL_RF;
        struct
        {
            __IO uint32_t r_epalna_od: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_088;
    } u_088;

    __IO uint32_t RSVD_0x8c[1];

    /* 0x0090       0x4000_3090
        31:0    R/W    OUT_DATA0                       32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_0;
        struct
        {
            __IO uint32_t OUT_DATA0: 32;
        } BITS_090;
    } u_090;

    /* 0x0094       0x4000_3094
        31:0    R/W    OUT_DATA1                       32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_1;
        struct
        {
            __IO uint32_t OUT_DATA1: 32;
        } BITS_094;
    } u_094;

    /* 0x0098       0x4000_3098
        31:0    R      IN_DATA0                        32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_2;
        struct
        {
            __I uint32_t IN_DATA0: 32;
        } BITS_098;
    } u_098;

    /* 0x009C       0x4000_309c
        31:0    R      IN_DATA1                        32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_3;
        struct
        {
            __I uint32_t IN_DATA1: 32;
        } BITS_09C;
    } u_09C;

    /* 0x00A0       0x4000_30a0
        0       WAC    outbox_rdy_r                    1'h0
        1       R/W    out_empty_inten                 1'h0
        2       R/W    out_int_mode                    1'h0
        3       W1C    out_edge_sts                    1'h0
        4       R      rx_data_crc_ok                  1'h0
        15:5    R      RSVD                            11'h0
        16      W1C    inbox_rdy_r                     1'h0
        17      R/W    in_rdy_inten                    1'h0
        30:18   R      RSVD                            13'h0
        31      R/W    pta_i2c_en                      1'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_4;
        struct
        {
            __IO uint32_t outbox_rdy_r: 1;
            __IO uint32_t out_empty_inten: 1;
            __IO uint32_t out_int_mode: 1;
            __IO uint32_t out_edge_sts: 1;
            __I uint32_t rx_data_crc_ok: 1;
            __I uint32_t RESERVED_1: 11;
            __IO uint32_t inbox_rdy_r: 1;
            __IO uint32_t in_rdy_inten: 1;
            __I uint32_t RESERVED_0: 13;
            __IO uint32_t pta_i2c_en: 1;
        } BITS_0A0;
    } u_0A0;

    __IO uint32_t RSVD_0xa4[5];

    /* 0x00B8       0x4000_30b8
        0       R/W    reg_fwpi_enable                 1'h1
        31:1    R      RSVD                            30'h0
    */
    union
    {
        __IO uint32_t REG_MODEMRFCPI_APB_WRAPPER;
        struct
        {
            __IO uint32_t reg_fwpi_enable: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_0B8;
    } u_0B8;

    __IO uint32_t RSVD_0xbc[1];

    /* 0x00C0       0x4000_30c0
        31:0    R/W    reg_enhtimer_0_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_0_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_0_latch_trig_0_sel: 32;
        } BITS_0C0;
    } u_0C0;

    /* 0x00C4       0x4000_30c4
        31:0    R/W    reg_enhtimer_1_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_1_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_1_latch_trig_0_sel: 32;
        } BITS_0C4;
    } u_0C4;

    /* 0x00C8       0x4000_30c8
        31:0    R/W    reg_enhtimer_2_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_2_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_2_latch_trig_0_sel: 32;
        } BITS_0C8;
    } u_0C8;

    /* 0x00CC       0x4000_30cc
        31:0    R/W    reg_enhtimer_3_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_3_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_3_latch_trig_0_sel: 32;
        } BITS_0CC;
    } u_0CC;

    /* 0x00D0       0x4000_30d0
        2:0     R/W    reg_bt_gpio_trig_sel            3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_GPIO_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_gpio_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D0;
    } u_0D0;

    /* 0x00D4       0x4000_30d4
        2:0     R/W    reg_bt_tx_on_trig_sel           3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_TX_ON_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_tx_on_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D4;
    } u_0D4;

    /* 0x00D8       0x4000_30d8
        2:0     R/W    reg_bt_acc_hit_trig_sel         3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_acc_hit_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D8;
    } u_0D8;

    __IO uint32_t RSVD_0xdc[5];

    /* 0x00F0       0x4000_30f0
        31:0    R/W    soc_vendor_dummy_reg_0          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_0;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_0: 32;
        } BITS_0F0;
    } u_0F0;

    /* 0x00F4       0x4000_30f4
        31:0    R/W    soc_vendor_dummy_reg_1          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_1;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_1: 32;
        } BITS_0F4;
    } u_0F4;

    /* 0x00F8       0x4000_30f8
        31:0    R/W    soc_vendor_dummy_reg_2          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_2;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_2: 32;
        } BITS_0F8;
    } u_0F8;

    /* 0x00FC       0x4000_30fc
        31:0    R/W    soc_vendor_dummy_reg_3          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_3;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_3: 32;
        } BITS_0FC;
    } u_0FC;

    /* 0x0100       0x4000_3100
        15:0    R/W    km4_wdt_wp                      16'h0
        31:16   R/W    RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_WP;
        struct
        {
            __IO uint32_t km4_wdt_wp: 16;
            __IO uint32_t RESERVED_0: 16;
        } BITS_100;
    } u_100;

    /* 0x0104       0x4000_3104
        15:0    R/W    km4_wdt_clk_div_factor          16'hC80
        27:16   R/W    km4_wdt_cnt_limit               12'h64
        29:28   R/W    km4_wdt_mode                    2'h3
        30      R/W1C  km4_wdt_timeout_flag            1'h0
        31      R/W    km4_wdt_enable                  1'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_CONFIG;
        struct
        {
            __IO uint32_t km4_wdt_clk_div_factor: 16;
            __IO uint32_t km4_wdt_cnt_limit: 12;
            __IO uint32_t km4_wdt_mode: 2;
            __IO uint32_t km4_wdt_timeout_flag: 1;
            __IO uint32_t km4_wdt_enable: 1;
        } BITS_104;
    } u_104;

    /* 0x0108       0x4000_3108
        15:0    R/WAC  km4_wdt_cnt_reset               16'h0
        31:16   R/WAC  RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_CNT_RESET;
        struct
        {
            __IO uint32_t km4_wdt_cnt_reset: 16;
            __IO uint32_t RESERVED_0: 16;
        } BITS_108;
    } u_108;

    /* 0x010C       0x4000_310c
        0       R/W    km4_wdt_wp_sec                  1'h0
        1       R/W    km4_wdt_config_sec              1'h0
        2       R/W    km4_wdt_cnt_reset_sec           1'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_SEC;
        struct
        {
            __IO uint32_t km4_wdt_wp_sec: 1;
            __IO uint32_t km4_wdt_config_sec: 1;
            __IO uint32_t km4_wdt_cnt_reset_sec: 1;
            __IO uint32_t RESERVED_0: 29;
        } BITS_10C;
    } u_10C;

    __IO uint32_t RSVD_0x110[60];

    /* 0x200        0x4000_3200
        0       R      bt_mac_1024x16_drf_start_pause  1'h0
        1       R      bt_mac_1024x16_drf_bist_fail    1'h0
        2       R      bt_mac_1024x16_drf_bist_done    1'h0
        3       R      bt_mac_1024x16_bist_fail        1'h0
        4       R      bt_mac_1024x16_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_1024x16_bist_grp_en      1'h0
        26      R/W    bt_mac_1024x16_dyn_read_en      1'h0
        27      R/W    bt_mac_1024x16_bist_loop_mode   1'h0
        28      R/W    bt_mac_1024x16_drf_test_resume  1'h0
        29      R/W    bt_mac_1024x16_drf_bist_mode    1'h0
        30      R/W    bt_mac_1024x16_bist_mode        1'h0
        31      R/W    bt_mac_1024x16_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x200;
        struct
        {
            __I uint32_t bt_mac_1024x16_drf_start_pause: 1;
            __I uint32_t bt_mac_1024x16_drf_bist_fail: 1;
            __I uint32_t bt_mac_1024x16_drf_bist_done: 1;
            __I uint32_t bt_mac_1024x16_bist_fail: 1;
            __I uint32_t bt_mac_1024x16_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_1024x16_bist_grp_en: 1;
            __IO uint32_t bt_mac_1024x16_dyn_read_en: 1;
            __IO uint32_t bt_mac_1024x16_bist_loop_mode: 1;
            __IO uint32_t bt_mac_1024x16_drf_test_resume: 1;
            __IO uint32_t bt_mac_1024x16_drf_bist_mode: 1;
            __IO uint32_t bt_mac_1024x16_bist_mode: 1;
            __IO uint32_t bt_mac_1024x16_bist_rstn: 1;
        } BITS_200;
    } u_200;

    /* 0x204        0x4000_3204
        0       R      bt_mac_512x16_drf_start_pause   1'h0
        1       R      bt_mac_512x16_drf_bist_fail     1'h0
        2       R      bt_mac_512x16_drf_bist_done     1'h0
        3       R      bt_mac_512x16_bist_fail         1'h0
        4       R      bt_mac_512x16_bist_done         1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_512x16_bist_grp_en       1'h0
        26      R/W    bt_mac_512x16_dyn_read_en       1'h0
        27      R/W    bt_mac_512x16_bist_loop_mode    1'h0
        28      R/W    bt_mac_512x16_drf_test_resume   1'h0
        29      R/W    bt_mac_512x16_drf_bist_mode     1'h0
        30      R/W    bt_mac_512x16_bist_mode         1'h0
        31      R/W    bt_mac_512x16_bist_rstn         1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x204;
        struct
        {
            __I uint32_t bt_mac_512x16_drf_start_pause: 1;
            __I uint32_t bt_mac_512x16_drf_bist_fail: 1;
            __I uint32_t bt_mac_512x16_drf_bist_done: 1;
            __I uint32_t bt_mac_512x16_bist_fail: 1;
            __I uint32_t bt_mac_512x16_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_512x16_bist_grp_en: 1;
            __IO uint32_t bt_mac_512x16_dyn_read_en: 1;
            __IO uint32_t bt_mac_512x16_bist_loop_mode: 1;
            __IO uint32_t bt_mac_512x16_drf_test_resume: 1;
            __IO uint32_t bt_mac_512x16_drf_bist_mode: 1;
            __IO uint32_t bt_mac_512x16_bist_mode: 1;
            __IO uint32_t bt_mac_512x16_bist_rstn: 1;
        } BITS_204;
    } u_204;

    /* 0x208        0x4000_3208
        0       R      bt_mac_128x32_0_drf_start_pause 1'h0
        1       R      bt_mac_128x32_0_drf_bist_fail   1'h0
        2       R      bt_mac_128x32_0_drf_bist_done   1'h0
        3       R      bt_mac_128x32_0_bist_fail       1'h0
        4       R      bt_mac_128x32_0_bist_done       1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_128x32_0_bist_grp_en     1'h0
        26      R/W    bt_mac_128x32_0_dyn_read_en     1'h0
        27      R/W    bt_mac_128x32_0_bist_loop_mode  1'h0
        28      R/W    bt_mac_128x32_0_drf_test_resume 1'h0
        29      R/W    bt_mac_128x32_0_drf_bist_mode   1'h0
        30      R/W    bt_mac_128x32_0_bist_mode       1'h0
        31      R/W    bt_mac_128x32_0_bist_rstn       1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x208;
        struct
        {
            __I uint32_t bt_mac_128x32_0_drf_start_pause: 1;
            __I uint32_t bt_mac_128x32_0_drf_bist_fail: 1;
            __I uint32_t bt_mac_128x32_0_drf_bist_done: 1;
            __I uint32_t bt_mac_128x32_0_bist_fail: 1;
            __I uint32_t bt_mac_128x32_0_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_128x32_0_bist_grp_en: 1;
            __IO uint32_t bt_mac_128x32_0_dyn_read_en: 1;
            __IO uint32_t bt_mac_128x32_0_bist_loop_mode: 1;
            __IO uint32_t bt_mac_128x32_0_drf_test_resume: 1;
            __IO uint32_t bt_mac_128x32_0_drf_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_0_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_0_bist_rstn: 1;
        } BITS_208;
    } u_208;

    /* 0x20C        0x4000_320c
        0       R      bt_mac_128x32_1_drf_start_pause 1'h0
        1       R      bt_mac_128x32_1_drf_bist_fail   1'h0
        2       R      bt_mac_128x32_1_drf_bist_done   1'h0
        3       R      bt_mac_128x32_1_bist_fail       1'h0
        4       R      bt_mac_128x32_1_bist_done       1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_128x32_1_bist_grp_en     1'h0
        26      R/W    bt_mac_128x32_1_dyn_read_en     1'h0
        27      R/W    bt_mac_128x32_1_bist_loop_mode  1'h0
        28      R/W    bt_mac_128x32_1_drf_test_resume 1'h0
        29      R/W    bt_mac_128x32_1_drf_bist_mode   1'h0
        30      R/W    bt_mac_128x32_1_bist_mode       1'h0
        31      R/W    bt_mac_128x32_1_bist_rstn       1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x20C;
        struct
        {
            __I uint32_t bt_mac_128x32_1_drf_start_pause: 1;
            __I uint32_t bt_mac_128x32_1_drf_bist_fail: 1;
            __I uint32_t bt_mac_128x32_1_drf_bist_done: 1;
            __I uint32_t bt_mac_128x32_1_bist_fail: 1;
            __I uint32_t bt_mac_128x32_1_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_128x32_1_bist_grp_en: 1;
            __IO uint32_t bt_mac_128x32_1_dyn_read_en: 1;
            __IO uint32_t bt_mac_128x32_1_bist_loop_mode: 1;
            __IO uint32_t bt_mac_128x32_1_drf_test_resume: 1;
            __IO uint32_t bt_mac_128x32_1_drf_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_1_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_1_bist_rstn: 1;
        } BITS_20C;
    } u_20C;

    /* 0x210        0x4000_3210
        0       R      bt_mac_640x32_drf_start_pause   1'h0
        1       R      bt_mac_640x32_drf_bist_fail     1'h0
        2       R      bt_mac_640x32_drf_bist_done     1'h0
        3       R      bt_mac_640x32_bist_fail         1'h0
        4       R      bt_mac_640x32_bist_done         1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_640x32_bist_grp_en       1'h0
        26      R/W    bt_mac_640x32_dyn_read_en       1'h0
        27      R/W    bt_mac_640x32_bist_loop_mode    1'h0
        28      R/W    bt_mac_640x32_drf_test_resume   1'h0
        29      R/W    bt_mac_640x32_drf_bist_mode     1'h0
        30      R/W    bt_mac_640x32_bist_mode         1'h0
        31      R/W    bt_mac_640x32_bist_rstn         1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x210;
        struct
        {
            __I uint32_t bt_mac_640x32_drf_start_pause: 1;
            __I uint32_t bt_mac_640x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_640x32_drf_bist_done: 1;
            __I uint32_t bt_mac_640x32_bist_fail: 1;
            __I uint32_t bt_mac_640x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_640x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_640x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_640x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_640x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_640x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_640x32_bist_mode: 1;
            __IO uint32_t bt_mac_640x32_bist_rstn: 1;
        } BITS_210;
    } u_210;

    /* 0x214        0x4000_3214
        0       R      bt_mac_96x32_drf_start_pause    1'h0
        1       R      bt_mac_96x32_drf_bist_fail      1'h0
        2       R      bt_mac_96x32_drf_bist_done      1'h0
        3       R      bt_mac_96x32_bist_fail          1'h0
        4       R      bt_mac_96x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_96x32_bist_grp_en        1'h0
        26      R/W    bt_mac_96x32_dyn_read_en        1'h0
        27      R/W    bt_mac_96x32_bist_loop_mode     1'h0
        28      R/W    bt_mac_96x32_drf_test_resume    1'h0
        29      R/W    bt_mac_96x32_drf_bist_mode      1'h0
        30      R/W    bt_mac_96x32_bist_mode          1'h0
        31      R/W    bt_mac_96x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x214;
        struct
        {
            __I uint32_t bt_mac_96x32_drf_start_pause: 1;
            __I uint32_t bt_mac_96x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_96x32_drf_bist_done: 1;
            __I uint32_t bt_mac_96x32_bist_fail: 1;
            __I uint32_t bt_mac_96x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_96x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_96x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_96x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_96x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_96x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_96x32_bist_mode: 1;
            __IO uint32_t bt_mac_96x32_bist_rstn: 1;
        } BITS_214;
    } u_214;

    /* 0x218        0x4000_3218
        0       R      bt_mac_64x32_drf_start_pause    1'h0
        1       R      bt_mac_64x32_drf_bist_fail      1'h0
        2       R      bt_mac_64x32_drf_bist_done      1'h0
        3       R      bt_mac_64x32_bist_fail          1'h0
        4       R      bt_mac_64x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_64x32_bist_grp_en        1'h0
        26      R/W    bt_mac_64x32_dyn_read_en        1'h0
        27      R/W    bt_mac_64x32_bist_loop_mode     1'h0
        28      R/W    bt_mac_64x32_drf_test_resume    1'h0
        29      R/W    bt_mac_64x32_drf_bist_mode      1'h0
        30      R/W    bt_mac_64x32_bist_mode          1'h0
        31      R/W    bt_mac_64x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x218;
        struct
        {
            __I uint32_t bt_mac_64x32_drf_start_pause: 1;
            __I uint32_t bt_mac_64x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_64x32_drf_bist_done: 1;
            __I uint32_t bt_mac_64x32_bist_fail: 1;
            __I uint32_t bt_mac_64x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_64x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_64x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_64x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_64x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_64x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_64x32_bist_mode: 1;
            __IO uint32_t bt_mac_64x32_bist_rstn: 1;
        } BITS_218;
    } u_218;

    /* 0x21C        0x4000_321c
        0       R      zb_mac_16x32_drf_start_pause    1'h0
        1       R      zb_mac_16x32_drf_bist_fail      1'h0
        2       R      zb_mac_16x32_drf_bist_done      1'h0
        3       R      zb_mac_16x32_bist_fail          1'h0
        4       R      zb_mac_16x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    zb_mac_16x32_bist_grp_en        1'h0
        26      R/W    zb_mac_16x32_dyn_read_en        1'h0
        27      R/W    zb_mac_16x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_16x32_drf_test_resume    1'h0
        29      R/W    zb_mac_16x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_16x32_bist_mode          1'h0
        31      R/W    zb_mac_16x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x21C;
        struct
        {
            __I uint32_t zb_mac_16x32_drf_start_pause: 1;
            __I uint32_t zb_mac_16x32_drf_bist_fail: 1;
            __I uint32_t zb_mac_16x32_drf_bist_done: 1;
            __I uint32_t zb_mac_16x32_bist_fail: 1;
            __I uint32_t zb_mac_16x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t zb_mac_16x32_bist_grp_en: 1;
            __IO uint32_t zb_mac_16x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_16x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_16x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_16x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_16x32_bist_mode: 1;
            __IO uint32_t zb_mac_16x32_bist_rstn: 1;
        } BITS_21C;
    } u_21C;

    /* 0x220        0x4000_3220
        0       R      zb_mac_40x32_drf_start_pause    1'h0
        2:1     R      zb_mac_40x32_drf_bist_fail      2'h0
        3       R      zb_mac_40x32_drf_bist_done      1'h0
        5:4     R      zb_mac_40x32_bist_fail          2'h0
        6       R      zb_mac_40x32_bist_done          1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    zb_mac_40x32_bist_grp_en        2'h0
        26      R/W    zb_mac_40x32_dyn_read_en        1'h0
        27      R/W    zb_mac_40x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_40x32_drf_test_resume    1'h0
        29      R/W    zb_mac_40x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_40x32_bist_mode          1'h0
        31      R/W    zb_mac_40x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x220;
        struct
        {
            __I uint32_t zb_mac_40x32_drf_start_pause: 1;
            __I uint32_t zb_mac_40x32_drf_bist_fail: 2;
            __I uint32_t zb_mac_40x32_drf_bist_done: 1;
            __I uint32_t zb_mac_40x32_bist_fail: 2;
            __I uint32_t zb_mac_40x32_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t zb_mac_40x32_bist_grp_en: 2;
            __IO uint32_t zb_mac_40x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_40x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_40x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_40x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_40x32_bist_mode: 1;
            __IO uint32_t zb_mac_40x32_bist_rstn: 1;
        } BITS_220;
    } u_220;

    /* 0x224        0x4000_3224
        0       R      zb_mac_32x32_drf_start_pause    1'h0
        4:1     R      zb_mac_32x32_drf_bist_fail      4'h0
        5       R      zb_mac_32x32_drf_bist_done      1'h0
        9:6     R      zb_mac_32x32_bist_fail          4'h0
        10      R      zb_mac_32x32_bist_done          1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    zb_mac_32x32_bist_grp_en        4'h0
        26      R/W    zb_mac_32x32_dyn_read_en        1'h0
        27      R/W    zb_mac_32x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_32x32_drf_test_resume    1'h0
        29      R/W    zb_mac_32x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_32x32_bist_mode          1'h0
        31      R/W    zb_mac_32x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x224;
        struct
        {
            __I uint32_t zb_mac_32x32_drf_start_pause: 1;
            __I uint32_t zb_mac_32x32_drf_bist_fail: 4;
            __I uint32_t zb_mac_32x32_drf_bist_done: 1;
            __I uint32_t zb_mac_32x32_bist_fail: 4;
            __I uint32_t zb_mac_32x32_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t zb_mac_32x32_bist_grp_en: 4;
            __IO uint32_t zb_mac_32x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_32x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_32x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_32x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_32x32_bist_mode: 1;
            __IO uint32_t zb_mac_32x32_bist_rstn: 1;
        } BITS_224;
    } u_224;

    /* 0x228        0x4000_3228
        0       R      btphy_128x12x4_drf_start_pause  1'h0
        4:1     R      btphy_128x12x4_drf_bist_fail    4'h0
        5       R      btphy_128x12x4_drf_bist_done    1'h0
        9:6     R      btphy_128x12x4_bist_fail        4'h0
        10      R      btphy_128x12x4_bist_done        1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    btphy_128x12x4_bist_grp_en      4'h0
        26      R/W    btphy_128x12x4_dyn_read_en      1'h0
        27      R/W    btphy_128x12x4_bist_loop_mode   1'h0
        28      R/W    btphy_128x12x4_drf_test_resume  1'h0
        29      R/W    btphy_128x12x4_drf_bist_mode    1'h0
        30      R/W    btphy_128x12x4_bist_mode        1'h0
        31      R/W    btphy_128x12x4_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x228;
        struct
        {
            __I uint32_t btphy_128x12x4_drf_start_pause: 1;
            __I uint32_t btphy_128x12x4_drf_bist_fail: 4;
            __I uint32_t btphy_128x12x4_drf_bist_done: 1;
            __I uint32_t btphy_128x12x4_bist_fail: 4;
            __I uint32_t btphy_128x12x4_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t btphy_128x12x4_bist_grp_en: 4;
            __IO uint32_t btphy_128x12x4_dyn_read_en: 1;
            __IO uint32_t btphy_128x12x4_bist_loop_mode: 1;
            __IO uint32_t btphy_128x12x4_drf_test_resume: 1;
            __IO uint32_t btphy_128x12x4_drf_bist_mode: 1;
            __IO uint32_t btphy_128x12x4_bist_mode: 1;
            __IO uint32_t btphy_128x12x4_bist_rstn: 1;
        } BITS_228;
    } u_228;

    /* 0x22C        0x4000_322c
        0       R      btphy_lr_ram_drf_start_pause    1'h0
        5:1     R      btphy_lr_ram_drf_bist_fail      5'h0
        6       R      btphy_lr_ram_drf_bist_done      1'h0
        11:7    R      btphy_lr_ram_bist_fail          5'h0
        12      R      btphy_lr_ram_bist_done          1'h0
        20:13   R      RSVD                            8'h0
        25:21   R/W    btphy_lr_ram_bist_grp_en        5'h0
        26      R/W    btphy_lr_ram_dyn_read_en        1'h0
        27      R/W    btphy_lr_ram_bist_loop_mode     1'h0
        28      R/W    btphy_lr_ram_drf_test_resume    1'h0
        29      R/W    btphy_lr_ram_drf_bist_mode      1'h0
        30      R/W    btphy_lr_ram_bist_mode          1'h0
        31      R/W    btphy_lr_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x22C;
        struct
        {
            __I uint32_t btphy_lr_ram_drf_start_pause: 1;
            __I uint32_t btphy_lr_ram_drf_bist_fail: 5;
            __I uint32_t btphy_lr_ram_drf_bist_done: 1;
            __I uint32_t btphy_lr_ram_bist_fail: 5;
            __I uint32_t btphy_lr_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 8;
            __IO uint32_t btphy_lr_ram_bist_grp_en: 5;
            __IO uint32_t btphy_lr_ram_dyn_read_en: 1;
            __IO uint32_t btphy_lr_ram_bist_loop_mode: 1;
            __IO uint32_t btphy_lr_ram_drf_test_resume: 1;
            __IO uint32_t btphy_lr_ram_drf_bist_mode: 1;
            __IO uint32_t btphy_lr_ram_bist_mode: 1;
            __IO uint32_t btphy_lr_ram_bist_rstn: 1;
        } BITS_22C;
    } u_22C;

    /* 0x230        0x4000_3230
        0       R      km4_itcm0_bist_done             1'h0
        25:1    R      RSVD                            25'h0
        29:26   R/W    km4_itcm0_bist_grp_en           4'h0
        30      R/W    km4_itcm0_bist_mode             1'h0
        31      R/W    km4_itcm0_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x230;
        struct
        {
            __I uint32_t km4_itcm0_bist_done: 1;
            __I uint32_t RESERVED_0: 25;
            __IO uint32_t km4_itcm0_bist_grp_en: 4;
            __IO uint32_t km4_itcm0_bist_mode: 1;
            __IO uint32_t km4_itcm0_bist_rstn: 1;
        } BITS_230;
    } u_230;

    /* 0x234        0x4000_3234
        31:0    R      km4_itcm0_misr_dataout_0_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x234;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_0_31_00: 32;
        } BITS_234;
    } u_234;

    /* 0x238        0x4000_3238
        31:0    R      km4_itcm0_misr_dataout_0_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x238;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_0_63_32: 32;
        } BITS_238;
    } u_238;

    /* 0x23C        0x4000_323c
        31:0    R      km4_itcm0_misr_dataout_1_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x23C;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_1_31_00: 32;
        } BITS_23C;
    } u_23C;

    /* 0x240        0x4000_3240
        31:0    R      km4_itcm0_misr_dataout_1_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x240;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_1_63_32: 32;
        } BITS_240;
    } u_240;

    /* 0x244        0x4000_3244
        31:0    R      km4_itcm0_misr_dataout_2_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x244;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_2_31_00: 32;
        } BITS_244;
    } u_244;

    /* 0x248        0x4000_3248
        31:0    R      km4_itcm0_misr_dataout_2_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x248;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_2_63_32: 32;
        } BITS_248;
    } u_248;

    /* 0x24C        0x4000_324c
        31:0    R      km4_itcm0_misr_dataout_3_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x24C;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_3_31_00: 32;
        } BITS_24C;
    } u_24C;

    /* 0x250        0x4000_3250
        31:0    R      km4_itcm0_misr_dataout_3_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x250;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_3_63_32: 32;
        } BITS_250;
    } u_250;

    /* 0x254        0x4000_3254
        13:0    R      RSVD                            14'h0
        25:14   R/W    km4_itcm1_bist_grp_en           12'h0
        26      R/W    km4_itcm1_dyn_read_en           1'h0
        27      R/W    km4_itcm1_bist_loop_mode        1'h0
        28      R/W    km4_itcm1_drf_test_resume       1'h0
        29      R/W    km4_itcm1_drf_bist_mode         1'h0
        30      R/W    km4_itcm1_bist_mode             1'h0
        31      R/W    km4_itcm1_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x254;
        struct
        {
            __I uint32_t RESERVED_0: 14;
            __IO uint32_t km4_itcm1_bist_grp_en: 12;
            __IO uint32_t km4_itcm1_dyn_read_en: 1;
            __IO uint32_t km4_itcm1_bist_loop_mode: 1;
            __IO uint32_t km4_itcm1_drf_test_resume: 1;
            __IO uint32_t km4_itcm1_drf_bist_mode: 1;
            __IO uint32_t km4_itcm1_bist_mode: 1;
            __IO uint32_t km4_itcm1_bist_rstn: 1;
        } BITS_254;
    } u_254;

    /* 0x258        0x4000_3258
        0       R      km4_itcm1_drf_start_pause       1'h0
        12:1    R      km4_itcm1_drf_bist_fail         12'h0
        13      R      km4_itcm1_drf_bist_done         1'h0
        25:14   R      km4_itcm1_bist_fail             12'h0
        26      R      km4_itcm1_bist_done             1'h0
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x258;
        struct
        {
            __I uint32_t km4_itcm1_drf_start_pause: 1;
            __I uint32_t km4_itcm1_drf_bist_fail: 12;
            __I uint32_t km4_itcm1_drf_bist_done: 1;
            __I uint32_t km4_itcm1_bist_fail: 12;
            __I uint32_t km4_itcm1_bist_done: 1;
            __I uint32_t RESERVED_0: 5;
        } BITS_258;
    } u_258;

    /* 0x25C        0x4000_325c
        0       R      km4_dtcm0_drf_start_pause       1'h0
        4:1     R      km4_dtcm0_drf_bist_fail         4'h0
        5       R      km4_dtcm0_drf_bist_done         1'h0
        9:6     R      km4_dtcm0_bist_fail             4'h0
        10      R      km4_dtcm0_bist_done             1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    km4_dtcm0_bist_grp_en           4'h0
        26      R/W    km4_dtcm0_dyn_read_en           1'h0
        27      R/W    km4_dtcm0_bist_loop_mode        1'h0
        28      R/W    km4_dtcm0_drf_test_resume       1'h0
        29      R/W    km4_dtcm0_drf_bist_mode         1'h0
        30      R/W    km4_dtcm0_bist_mode             1'h0
        31      R/W    km4_dtcm0_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x25C;
        struct
        {
            __I uint32_t km4_dtcm0_drf_start_pause: 1;
            __I uint32_t km4_dtcm0_drf_bist_fail: 4;
            __I uint32_t km4_dtcm0_drf_bist_done: 1;
            __I uint32_t km4_dtcm0_bist_fail: 4;
            __I uint32_t km4_dtcm0_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t km4_dtcm0_bist_grp_en: 4;
            __IO uint32_t km4_dtcm0_dyn_read_en: 1;
            __IO uint32_t km4_dtcm0_bist_loop_mode: 1;
            __IO uint32_t km4_dtcm0_drf_test_resume: 1;
            __IO uint32_t km4_dtcm0_drf_bist_mode: 1;
            __IO uint32_t km4_dtcm0_bist_mode: 1;
            __IO uint32_t km4_dtcm0_bist_rstn: 1;
        } BITS_25C;
    } u_25C;

    /* 0x260        0x4000_3260
        0       R      km4_dtcm1_drf_start_pause       1'h0
        4:1     R      km4_dtcm1_drf_bist_fail         4'h0
        5       R      km4_dtcm1_drf_bist_done         1'h0
        9:6     R      km4_dtcm1_bist_fail             4'h0
        10      R      km4_dtcm1_bist_done             1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    km4_dtcm1_bist_grp_en           4'h0
        26      R/W    km4_dtcm1_dyn_read_en           1'h0
        27      R/W    km4_dtcm1_bist_loop_mode        1'h0
        28      R/W    km4_dtcm1_drf_test_resume       1'h0
        29      R/W    km4_dtcm1_drf_bist_mode         1'h0
        30      R/W    km4_dtcm1_bist_mode             1'h0
        31      R/W    km4_dtcm1_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x260;
        struct
        {
            __I uint32_t km4_dtcm1_drf_start_pause: 1;
            __I uint32_t km4_dtcm1_drf_bist_fail: 4;
            __I uint32_t km4_dtcm1_drf_bist_done: 1;
            __I uint32_t km4_dtcm1_bist_fail: 4;
            __I uint32_t km4_dtcm1_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t km4_dtcm1_bist_grp_en: 4;
            __IO uint32_t km4_dtcm1_dyn_read_en: 1;
            __IO uint32_t km4_dtcm1_bist_loop_mode: 1;
            __IO uint32_t km4_dtcm1_drf_test_resume: 1;
            __IO uint32_t km4_dtcm1_drf_bist_mode: 1;
            __IO uint32_t km4_dtcm1_bist_mode: 1;
            __IO uint32_t km4_dtcm1_bist_rstn: 1;
        } BITS_260;
    } u_260;

    /* 0x264        0x4000_3264
        15:0    R      RSVD                            16'h0
        25:16   R/W    km4_cache_bist_grp_en           10'h0
        26      R/W    km4_cache_dyn_read_en           1'h0
        27      R/W    km4_cache_bist_loop_mode        1'h0
        28      R/W    km4_cache_drf_test_resume       1'h0
        29      R/W    km4_cache_drf_bist_mode         1'h0
        30      R/W    km4_cache_bist_mode             1'h0
        31      R/W    km4_cache_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x264;
        struct
        {
            __I uint32_t RESERVED_0: 16;
            __IO uint32_t km4_cache_bist_grp_en: 10;
            __IO uint32_t km4_cache_dyn_read_en: 1;
            __IO uint32_t km4_cache_bist_loop_mode: 1;
            __IO uint32_t km4_cache_drf_test_resume: 1;
            __IO uint32_t km4_cache_drf_bist_mode: 1;
            __IO uint32_t km4_cache_bist_mode: 1;
            __IO uint32_t km4_cache_bist_rstn: 1;
        } BITS_264;
    } u_264;

    /* 0x268        0x4000_3268
        0       R      km4_cache_drf_start_pause       1'h0
        10:1    R      km4_cache_drf_bist_fail         10'h0
        11      R      km4_cache_drf_bist_done         1'h0
        21:12   R      km4_cache_bist_fail             10'h0
        22      R      km4_cache_bist_done             1'h0
        31:23   R      RSVD                            9'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x268;
        struct
        {
            __I uint32_t km4_cache_drf_start_pause: 1;
            __I uint32_t km4_cache_drf_bist_fail: 10;
            __I uint32_t km4_cache_drf_bist_done: 1;
            __I uint32_t km4_cache_bist_fail: 10;
            __I uint32_t km4_cache_bist_done: 1;
            __I uint32_t RESERVED_0: 9;
        } BITS_268;
    } u_268;

    /* 0x26C        0x4000_326c
        0       R      buffer_ram_drf_start_pause      1'h0
        3:1     R      buffer_ram_drf_bist_fail        3'h0
        4       R      buffer_ram_drf_bist_done        1'h0
        7:5     R      buffer_ram_bist_fail            3'h0
        8       R      buffer_ram_bist_done            1'h0
        22:9    R      RSVD                            14'h0
        25:23   R/W    buffer_ram_bist_grp_en          3'h0
        26      R/W    buffer_ram_dyn_read_en          1'h0
        27      R/W    buffer_ram_bist_loop_mode       1'h0
        28      R/W    buffer_ram_drf_test_resume      1'h0
        29      R/W    buffer_ram_drf_bist_mode        1'h0
        30      R/W    buffer_ram_bist_mode            1'h0
        31      R/W    buffer_ram_bist_rstn            1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x26C;
        struct
        {
            __I uint32_t buffer_ram_drf_start_pause: 1;
            __I uint32_t buffer_ram_drf_bist_fail: 3;
            __I uint32_t buffer_ram_drf_bist_done: 1;
            __I uint32_t buffer_ram_bist_fail: 3;
            __I uint32_t buffer_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 14;
            __IO uint32_t buffer_ram_bist_grp_en: 3;
            __IO uint32_t buffer_ram_dyn_read_en: 1;
            __IO uint32_t buffer_ram_bist_loop_mode: 1;
            __IO uint32_t buffer_ram_drf_test_resume: 1;
            __IO uint32_t buffer_ram_drf_bist_mode: 1;
            __IO uint32_t buffer_ram_bist_mode: 1;
            __IO uint32_t buffer_ram_bist_rstn: 1;
        } BITS_26C;
    } u_26C;

    /* 0x270        0x4000_3270
        0       R      data_ram_drf_start_pause        1'h0
        1       R      data_ram_drf_bist_fail          1'h0
        2       R      data_ram_drf_bist_done          1'h0
        3       R      data_ram_bist_fail              1'h0
        4       R      data_ram_bist_done              1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    data_ram_bist_grp_en            1'h0
        26      R/W    data_ram_dyn_read_en            1'h0
        27      R/W    data_ram_bist_loop_mode         1'h0
        28      R/W    data_ram_drf_test_resume        1'h0
        29      R/W    data_ram_drf_bist_mode          1'h0
        30      R/W    data_ram_bist_mode              1'h0
        31      R/W    data_ram_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x270;
        struct
        {
            __I uint32_t data_ram_drf_start_pause: 1;
            __I uint32_t data_ram_drf_bist_fail: 1;
            __I uint32_t data_ram_drf_bist_done: 1;
            __I uint32_t data_ram_bist_fail: 1;
            __I uint32_t data_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t data_ram_bist_grp_en: 1;
            __IO uint32_t data_ram_dyn_read_en: 1;
            __IO uint32_t data_ram_bist_loop_mode: 1;
            __IO uint32_t data_ram_drf_test_resume: 1;
            __IO uint32_t data_ram_drf_bist_mode: 1;
            __IO uint32_t data_ram_bist_mode: 1;
            __IO uint32_t data_ram_bist_rstn: 1;
        } BITS_270;
    } u_270;

    /* 0x274        0x4000_3274
        0       R      usb_2176x35_drf_start_pause     1'h0
        1       R      usb_2176x35_drf_bist_fail       1'h0
        2       R      usb_2176x35_drf_bist_done       1'h0
        3       R      usb_2176x35_bist_fail           1'h0
        4       R      usb_2176x35_bist_done           1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    usb_2176x35_bist_grp_en         1'h0
        26      R/W    usb_2176x35_dyn_read_en         1'h0
        27      R/W    usb_2176x35_bist_loop_mode      1'h0
        28      R/W    usb_2176x35_drf_test_resume     1'h0
        29      R/W    usb_2176x35_drf_bist_mode       1'h0
        30      R/W    usb_2176x35_bist_mode           1'h0
        31      R/W    usb_2176x35_bist_rstn           1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x274;
        struct
        {
            __I uint32_t usb_2176x35_drf_start_pause: 1;
            __I uint32_t usb_2176x35_drf_bist_fail: 1;
            __I uint32_t usb_2176x35_drf_bist_done: 1;
            __I uint32_t usb_2176x35_bist_fail: 1;
            __I uint32_t usb_2176x35_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t usb_2176x35_bist_grp_en: 1;
            __IO uint32_t usb_2176x35_dyn_read_en: 1;
            __IO uint32_t usb_2176x35_bist_loop_mode: 1;
            __IO uint32_t usb_2176x35_drf_test_resume: 1;
            __IO uint32_t usb_2176x35_drf_bist_mode: 1;
            __IO uint32_t usb_2176x35_bist_mode: 1;
            __IO uint32_t usb_2176x35_bist_rstn: 1;
        } BITS_274;
    } u_274;

    /* 0x278        0x4000_3278
        0       R      sdio_ram_drf_start_pause        1'h0
        1       R      sdio_ram_drf_bist_fail          1'h0
        2       R      sdio_ram_drf_bist_done          1'h0
        3       R      sdio_ram_bist_fail              1'h0
        4       R      sdio_ram_bist_done              1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    sdio_ram_bist_grp_en            1'h0
        26      R/W    sdio_ram_dyn_read_en            1'h0
        27      R/W    sdio_ram_bist_loop_mode         1'h0
        28      R/W    sdio_ram_drf_test_resume        1'h0
        29      R/W    sdio_ram_drf_bist_mode          1'h0
        30      R/W    sdio_ram_bist_mode              1'h0
        31      R/W    sdio_ram_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x278;
        struct
        {
            __I uint32_t sdio_ram_drf_start_pause: 1;
            __I uint32_t sdio_ram_drf_bist_fail: 1;
            __I uint32_t sdio_ram_drf_bist_done: 1;
            __I uint32_t sdio_ram_bist_fail: 1;
            __I uint32_t sdio_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t sdio_ram_bist_grp_en: 1;
            __IO uint32_t sdio_ram_dyn_read_en: 1;
            __IO uint32_t sdio_ram_bist_loop_mode: 1;
            __IO uint32_t sdio_ram_drf_test_resume: 1;
            __IO uint32_t sdio_ram_drf_bist_mode: 1;
            __IO uint32_t sdio_ram_bist_mode: 1;
            __IO uint32_t sdio_ram_bist_rstn: 1;
        } BITS_278;
    } u_278;

    /* 0x27C        0x4000_327c
        0       R      display_128x32_drf_start_pause  1'h0
        1       R      display_128x32_drf_bist_fail    1'h0
        2       R      display_128x32_drf_bist_done    1'h0
        3       R      display_128x32_bist_fail        1'h0
        4       R      display_128x32_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    display_128x32_bist_grp_en      1'h0
        26      R/W    display_128x32_dyn_read_en      1'h0
        27      R/W    display_128x32_bist_loop_mode   1'h0
        28      R/W    display_128x32_drf_test_resume  1'h0
        29      R/W    display_128x32_drf_bist_mode    1'h0
        30      R/W    display_128x32_bist_mode        1'h0
        31      R/W    display_128x32_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x27C;
        struct
        {
            __I uint32_t display_128x32_drf_start_pause: 1;
            __I uint32_t display_128x32_drf_bist_fail: 1;
            __I uint32_t display_128x32_drf_bist_done: 1;
            __I uint32_t display_128x32_bist_fail: 1;
            __I uint32_t display_128x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t display_128x32_bist_grp_en: 1;
            __IO uint32_t display_128x32_dyn_read_en: 1;
            __IO uint32_t display_128x32_bist_loop_mode: 1;
            __IO uint32_t display_128x32_drf_test_resume: 1;
            __IO uint32_t display_128x32_drf_bist_mode: 1;
            __IO uint32_t display_128x32_bist_mode: 1;
            __IO uint32_t display_128x32_bist_rstn: 1;
        } BITS_27C;
    } u_27C;

    /* 0x280        0x4000_3280
        0       R      display_672x24_drf_start_pause  1'h0
        1       R      display_672x24_drf_bist_fail    1'h0
        2       R      display_672x24_drf_bist_done    1'h0
        3       R      display_672x24_bist_fail        1'h0
        4       R      display_672x24_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    display_672x24_bist_grp_en      1'h0
        26      R/W    display_672x24_dyn_read_en      1'h0
        27      R/W    display_672x24_bist_loop_mode   1'h0
        28      R/W    display_672x24_drf_test_resume  1'h0
        29      R/W    display_672x24_drf_bist_mode    1'h0
        30      R/W    display_672x24_bist_mode        1'h0
        31      R/W    display_672x24_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x280;
        struct
        {
            __I uint32_t display_672x24_drf_start_pause: 1;
            __I uint32_t display_672x24_drf_bist_fail: 1;
            __I uint32_t display_672x24_drf_bist_done: 1;
            __I uint32_t display_672x24_bist_fail: 1;
            __I uint32_t display_672x24_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t display_672x24_bist_grp_en: 1;
            __IO uint32_t display_672x24_dyn_read_en: 1;
            __IO uint32_t display_672x24_bist_loop_mode: 1;
            __IO uint32_t display_672x24_drf_test_resume: 1;
            __IO uint32_t display_672x24_drf_bist_mode: 1;
            __IO uint32_t display_672x24_bist_mode: 1;
            __IO uint32_t display_672x24_bist_rstn: 1;
        } BITS_280;
    } u_280;

    /* 0x284        0x4000_3284
        0       R      gmac_512x32_drf_start_pause     1'h0
        2:1     R      gmac_512x32_drf_bist_fail       2'h0
        3       R      gmac_512x32_drf_bist_done       1'h0
        5:4     R      gmac_512x32_bist_fail           2'h0
        6       R      gmac_512x32_bist_done           1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    gmac_512x32_bist_grp_en         2'h0
        26      R/W    gmac_512x32_dyn_read_en         1'h0
        27      R/W    gmac_512x32_bist_loop_mode      1'h0
        28      R/W    gmac_512x32_drf_test_resume     1'h0
        29      R/W    gmac_512x32_drf_bist_mode       1'h0
        30      R/W    gmac_512x32_bist_mode           1'h0
        31      R/W    gmac_512x32_bist_rstn           1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x284;
        struct
        {
            __I uint32_t gmac_512x32_drf_start_pause: 1;
            __I uint32_t gmac_512x32_drf_bist_fail: 2;
            __I uint32_t gmac_512x32_drf_bist_done: 1;
            __I uint32_t gmac_512x32_bist_fail: 2;
            __I uint32_t gmac_512x32_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t gmac_512x32_bist_grp_en: 2;
            __IO uint32_t gmac_512x32_dyn_read_en: 1;
            __IO uint32_t gmac_512x32_bist_loop_mode: 1;
            __IO uint32_t gmac_512x32_drf_test_resume: 1;
            __IO uint32_t gmac_512x32_drf_bist_mode: 1;
            __IO uint32_t gmac_512x32_bist_mode: 1;
            __IO uint32_t gmac_512x32_bist_rstn: 1;
        } BITS_284;
    } u_284;

    /* 0x288        0x4000_3288
        0       R      pke_rom_bist_done               1'h0
        28:1    R      RSVD                            28'h0
        29      R/W    pke_rom_bist_grp_en             1'h0
        30      R/W    pke_rom_bist_mode               1'h0
        31      R/W    pke_rom_bist_rstn               1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x288;
        struct
        {
            __I uint32_t pke_rom_bist_done: 1;
            __I uint32_t RESERVED_0: 28;
            __IO uint32_t pke_rom_bist_grp_en: 1;
            __IO uint32_t pke_rom_bist_mode: 1;
            __IO uint32_t pke_rom_bist_rstn: 1;
        } BITS_288;
    } u_288;

    /* 0x28C        0x4000_328c
        31:0    R      pke_rom_misr_dataout_0_31_00    32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x28C;
        struct
        {
            __I uint32_t pke_rom_misr_dataout_0_31_00: 32;
        } BITS_28C;
    } u_28C;

    /* 0x290        0x4000_3290
        31:0    R      pke_rom_misr_dataout_0_63_32    32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x290;
        struct
        {
            __I uint32_t pke_rom_misr_dataout_0_63_32: 32;
        } BITS_290;
    } u_290;

    /* 0x294        0x4000_3294
        0       R      pke_mmem_drf_start_pause        1'h0
        2:1     R      pke_mmem_drf_bist_fail          2'h0
        3       R      pke_mmem_drf_bist_done          1'h0
        5:4     R      pke_mmem_bist_fail              2'h0
        6       R      pke_mmem_bist_done              1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    pke_mmem_bist_grp_en            2'h0
        26      R/W    pke_mmem_dyn_read_en            1'h0
        27      R/W    pke_mmem_bist_loop_mode         1'h0
        28      R/W    pke_mmem_drf_test_resume        1'h0
        29      R/W    pke_mmem_drf_bist_mode          1'h0
        30      R/W    pke_mmem_bist_mode              1'h0
        31      R/W    pke_mmem_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x294;
        struct
        {
            __I uint32_t pke_mmem_drf_start_pause: 1;
            __I uint32_t pke_mmem_drf_bist_fail: 2;
            __I uint32_t pke_mmem_drf_bist_done: 1;
            __I uint32_t pke_mmem_bist_fail: 2;
            __I uint32_t pke_mmem_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t pke_mmem_bist_grp_en: 2;
            __IO uint32_t pke_mmem_dyn_read_en: 1;
            __IO uint32_t pke_mmem_bist_loop_mode: 1;
            __IO uint32_t pke_mmem_drf_test_resume: 1;
            __IO uint32_t pke_mmem_drf_bist_mode: 1;
            __IO uint32_t pke_mmem_bist_mode: 1;
            __IO uint32_t pke_mmem_bist_rstn: 1;
        } BITS_294;
    } u_294;

    /* 0x298        0x4000_3298
        0       R      pke_tmem_drf_start_pause        1'h0
        2:1     R      pke_tmem_drf_bist_fail          2'h0
        3       R      pke_tmem_drf_bist_done          1'h0
        5:4     R      pke_tmem_bist_fail              2'h0
        6       R      pke_tmem_bist_done              1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    pke_tmem_bist_grp_en            2'h0
        26      R/W    pke_tmem_dyn_read_en            1'h0
        27      R/W    pke_tmem_bist_loop_mode         1'h0
        28      R/W    pke_tmem_drf_test_resume        1'h0
        29      R/W    pke_tmem_drf_bist_mode          1'h0
        30      R/W    pke_tmem_bist_mode              1'h0
        31      R/W    pke_tmem_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x298;
        struct
        {
            __I uint32_t pke_tmem_drf_start_pause: 1;
            __I uint32_t pke_tmem_drf_bist_fail: 2;
            __I uint32_t pke_tmem_drf_bist_done: 1;
            __I uint32_t pke_tmem_bist_fail: 2;
            __I uint32_t pke_tmem_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t pke_tmem_bist_grp_en: 2;
            __IO uint32_t pke_tmem_dyn_read_en: 1;
            __IO uint32_t pke_tmem_bist_loop_mode: 1;
            __IO uint32_t pke_tmem_drf_test_resume: 1;
            __IO uint32_t pke_tmem_drf_bist_mode: 1;
            __IO uint32_t pke_tmem_bist_mode: 1;
            __IO uint32_t pke_tmem_bist_rstn: 1;
        } BITS_298;
    } u_298;

    /* 0x29C        0x4000_329c
        0       R      audio_ad_ram_drf_start_pause    1'h0
        2:1     R      audio_ad_ram_drf_bist_fail      2'h0
        3       R      audio_ad_ram_drf_bist_done      1'h0
        5:4     R      audio_ad_ram_bist_fail          2'h0
        6       R      audio_ad_ram_bist_done          1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    audio_ad_ram_bist_grp_en        2'h0
        26      R/W    audio_ad_ram_dyn_read_en        1'h0
        27      R/W    audio_ad_ram_bist_loop_mode     1'h0
        28      R/W    audio_ad_ram_drf_test_resume    1'h0
        29      R/W    audio_ad_ram_drf_bist_mode      1'h0
        30      R/W    audio_ad_ram_bist_mode          1'h0
        31      R/W    audio_ad_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x29C;
        struct
        {
            __I uint32_t audio_ad_ram_drf_start_pause: 1;
            __I uint32_t audio_ad_ram_drf_bist_fail: 2;
            __I uint32_t audio_ad_ram_drf_bist_done: 1;
            __I uint32_t audio_ad_ram_bist_fail: 2;
            __I uint32_t audio_ad_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t audio_ad_ram_bist_grp_en: 2;
            __IO uint32_t audio_ad_ram_dyn_read_en: 1;
            __IO uint32_t audio_ad_ram_bist_loop_mode: 1;
            __IO uint32_t audio_ad_ram_drf_test_resume: 1;
            __IO uint32_t audio_ad_ram_drf_bist_mode: 1;
            __IO uint32_t audio_ad_ram_bist_mode: 1;
            __IO uint32_t audio_ad_ram_bist_rstn: 1;
        } BITS_29C;
    } u_29C;

    /* 0x2A0        0x4000_32a0
        0       R      audio_da_ram_drf_start_pause    1'h0
        1       R      audio_da_ram_drf_bist_fail      1'h0
        2       R      audio_da_ram_drf_bist_done      1'h0
        3       R      audio_da_ram_bist_fail          1'h0
        4       R      audio_da_ram_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    audio_da_ram_bist_grp_en        1'h0
        26      R/W    audio_da_ram_dyn_read_en        1'h0
        27      R/W    audio_da_ram_bist_loop_mode     1'h0
        28      R/W    audio_da_ram_drf_test_resume    1'h0
        29      R/W    audio_da_ram_drf_bist_mode      1'h0
        30      R/W    audio_da_ram_bist_mode          1'h0
        31      R/W    audio_da_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x2A0;
        struct
        {
            __I uint32_t audio_da_ram_drf_start_pause: 1;
            __I uint32_t audio_da_ram_drf_bist_fail: 1;
            __I uint32_t audio_da_ram_drf_bist_done: 1;
            __I uint32_t audio_da_ram_bist_fail: 1;
            __I uint32_t audio_da_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t audio_da_ram_bist_grp_en: 1;
            __IO uint32_t audio_da_ram_dyn_read_en: 1;
            __IO uint32_t audio_da_ram_bist_loop_mode: 1;
            __IO uint32_t audio_da_ram_drf_test_resume: 1;
            __IO uint32_t audio_da_ram_drf_bist_mode: 1;
            __IO uint32_t audio_da_ram_bist_mode: 1;
            __IO uint32_t audio_da_ram_bist_rstn: 1;
        } BITS_2A0;
    } u_2A0;

    /* 0x2A4        0x4000_32a4
        0       R      can_ram_drf_start_pause         1'h0
        1       R      can_ram_drf_bist_fail           1'h0
        2       R      can_ram_drf_bist_done           1'h0
        3       R      can_ram_bist_fail               1'h0
        4       R      can_ram_bist_done               1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    can_ram_bist_grp_en             1'h0
        26      R/W    can_ram_dyn_read_en             1'h0
        27      R/W    can_ram_bist_loop_mode          1'h0
        28      R/W    can_ram_drf_test_resume         1'h0
        29      R/W    can_ram_drf_bist_mode           1'h0
        30      R/W    can_ram_bist_mode               1'h0
        31      R/W    can_ram_bist_rstn               1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x2A4;
        struct
        {
            __I uint32_t can_ram_drf_start_pause: 1;
            __I uint32_t can_ram_drf_bist_fail: 1;
            __I uint32_t can_ram_drf_bist_done: 1;
            __I uint32_t can_ram_bist_fail: 1;
            __I uint32_t can_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t can_ram_bist_grp_en: 1;
            __IO uint32_t can_ram_dyn_read_en: 1;
            __IO uint32_t can_ram_bist_loop_mode: 1;
            __IO uint32_t can_ram_drf_test_resume: 1;
            __IO uint32_t can_ram_drf_bist_mode: 1;
            __IO uint32_t can_ram_bist_mode: 1;
            __IO uint32_t can_ram_bist_rstn: 1;
        } BITS_2A4;
    } u_2A4;

    __IO uint32_t RSVD_0x2a8[9];

    /* 0x2CC        0x4000_32cc
        31:0    R/W    spic0_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_0: 32;
        } BITS_2CC;
    } u_2CC;

    /* 0x2D0        0x4000_32d0
        31:0    R/W    spic0_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_1: 32;
        } BITS_2D0;
    } u_2D0;

    /* 0x2D4        0x4000_32d4
        31:0    R/W    spic0_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_2: 32;
        } BITS_2D4;
    } u_2D4;

    /* 0x2D8        0x4000_32d8
        31:0    R/W    spic0_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_3: 32;
        } BITS_2D8;
    } u_2D8;

    /* 0x2DC        0x4000_32dc
        31:0    R/W    spic0_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_4: 32;
        } BITS_2DC;
    } u_2DC;

    /* 0x2E0        0x4000_32e0
        31:0    R/W    spic0_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_5: 32;
        } BITS_2E0;
    } u_2E0;

    /* 0x2E4        0x4000_32e4
        31:0    R/W    spic0_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_6: 32;
        } BITS_2E4;
    } u_2E4;

    /* 0x2E8        0x4000_32e8
        31:0    R/W    spic0_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_7: 32;
        } BITS_2E8;
    } u_2E8;

    /* 0x2EC        0x4000_32ec
        4:0     R/W    spic0_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_2EC;
    } u_2EC;

    /* 0x2F0        0x4000_32f0
        31:0    R/W    spic1_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_0: 32;
        } BITS_2F0;
    } u_2F0;

    /* 0x2F4        0x4000_32f4
        31:0    R/W    spic1_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_1: 32;
        } BITS_2F4;
    } u_2F4;

    /* 0x2F8        0x4000_32f8
        31:0    R/W    spic1_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_2: 32;
        } BITS_2F8;
    } u_2F8;

    /* 0x2FC        0x4000_32fc
        31:0    R/W    spic1_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_3: 32;
        } BITS_2FC;
    } u_2FC;

    /* 0x300        0x4000_3300
        31:0    R/W    spic1_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_4: 32;
        } BITS_300;
    } u_300;

    /* 0x304        0x4000_3304
        31:0    R/W    spic1_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_5: 32;
        } BITS_304;
    } u_304;

    /* 0x308        0x4000_3308
        31:0    R/W    spic1_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_6: 32;
        } BITS_308;
    } u_308;

    /* 0x30C        0x4000_330c
        31:0    R/W    spic1_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_7: 32;
        } BITS_30C;
    } u_30C;

    /* 0x310        0x4000_3310
        4:0     R/W    spic1_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_310;
    } u_310;

    /* 0x314        0x4000_3314
        31:0    R/W    spic2_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_0: 32;
        } BITS_314;
    } u_314;

    /* 0x318        0x4000_3318
        31:0    R/W    spic2_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_1: 32;
        } BITS_318;
    } u_318;

    /* 0x31C        0x4000_331c
        31:0    R/W    spic2_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_2: 32;
        } BITS_31C;
    } u_31C;

    /* 0x320        0x4000_3320
        31:0    R/W    spic2_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_3: 32;
        } BITS_320;
    } u_320;

    /* 0x324        0x4000_3324
        31:0    R/W    spic2_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_4: 32;
        } BITS_324;
    } u_324;

    /* 0x328        0x4000_3328
        31:0    R/W    spic2_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_5: 32;
        } BITS_328;
    } u_328;

    /* 0x32C        0x4000_332c
        31:0    R/W    spic2_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_6: 32;
        } BITS_32C;
    } u_32C;

    /* 0x330        0x4000_3330
        31:0    R/W    spic2_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_7: 32;
        } BITS_330;
    } u_330;

    /* 0x334        0x4000_3334
        4:0     R/W    spic2_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_334;
    } u_334;

} SoC_VENDOR_REG_TypeDef;


#define SOC_VENDOR_REG_BASE             0x40003000UL
#define VENDOR_REG_BASE                 SOC_VENDOR_REG_BASE

#define SoC_VENDOR                      ((SoC_VENDOR_REG_TypeDef    *) SOC_VENDOR_REG_BASE)

#endif //#define PLATFORM_REG_H 
