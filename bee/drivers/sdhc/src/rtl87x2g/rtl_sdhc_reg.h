#ifndef RTL_SDHC_REG_H
#define RTL_SDHC_REG_H

#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         SDHC Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t CTRL;                   /*!< 0x00 */
    __IO uint32_t PWREN;                  /*!< 0x04 */
    __IO uint32_t CLKDIV;                 /*!< 0x08 */
    __IO uint32_t CLKSRC;                 /*!< 0x0C */
    __IO uint32_t CLKENA;                 /*!< 0x10 */
    __IO uint32_t TMOUT;                  /*!< 0x14 */
    __IO uint32_t CTYPE;                  /*!< 0x18 */
    __IO uint32_t BLKSIZ;                 /*!< 0x1C */
    __IO uint32_t BYTCNT;                 /*!< 0x20 */
    __IO uint32_t INTMASK;                /*!< 0x24 */
    __IO uint32_t CMDARG;                 /*!< 0x28 */
    __IO uint32_t CMD;                    /*!< 0x2C */
    __I  uint32_t RESP0;                  /*!< 0x30 */
    __I  uint32_t RESP1;                  /*!< 0x34 */
    __I  uint32_t RESP2;                  /*!< 0x38 */
    __I  uint32_t RESP3;                  /*!< 0x3C */
    __I  uint32_t MINTSTS;                /*!< 0x40 */
    __IO uint32_t RINTSTS;                /*!< 0x44 */
    __I  uint32_t STATUS;                 /*!< 0x48 */
    __IO uint32_t FIFOTH;                 /*!< 0x4C */
    __I  uint32_t CDETECT;                /*!< 0x50 */
    __I  uint32_t WRTPRT;                 /*!< 0x54 */
    __IO uint32_t GPIO;                   /*!< 0x58 */
    __I  uint32_t TCBCNT;                 /*!< 0x5C */
    __I  uint32_t TBBCNT;                 /*!< 0x60 */
    __IO uint32_t DEBNCE;                 /*!< 0x64 */
    __IO uint32_t USRID;                  /*!< 0x68 */
    __I  uint32_t VERID;                  /*!< 0x6C */
    __I  uint32_t HCON;                   /*!< 0x70 */
    __IO uint32_t UHS_REG;                /*!< 0x74 */
    __IO uint32_t RST_N;                  /*!< 0x78 */
    __I  uint32_t Reserved0;              /*!< 0x7C */
    __IO uint32_t BMOD;                   /*!< 0x80 */
    __O  uint32_t PLDMND;                 /*!< 0x84 */
    __IO uint32_t DBADDR;                 /*!< 0x88 */
    __IO uint32_t IDSTS;                  /*!< 0x8C */
    __IO uint32_t IDINTEN;                /*!< 0x90 */
    __I  uint32_t DSCADDR;                /*!< 0x94 */
    __I  uint32_t BUFADDR;                /*!< 0x98 */
    __I  uint8_t Reserved1[0x100 - 0x9C]; /*!< 0x9C */
    __IO uint32_t CARDTHRCTL;             /*!< 0x100 */
    __IO uint32_t BACK_END_POWER;         /*!< 0x104 */
    __IO uint32_t UHS_REG_EXT;            /*!< 0x108 */
    __IO uint32_t EMMC_DDR_REG;           /*!< 0x10C */
    __IO uint32_t ENABLE_SHIFT;           /*!< 0x110 */
    __IO uint8_t Reserved2[0x100 - 0x14]; /*!< 0x114 */
    __IO uint32_t DATA;                   /*!< >=0x200 */
} SDHC_TypeDef;

/*============================================================================*
 *                         SDHC Declaration
 *============================================================================*/
#define SDHC0                           ((SDHC_TypeDef *) SDHC_REG_BASE)
#define SDHC1                           ((SDHC_TypeDef *) SDHC_REG_BASE)

/*============================================================================*
 *                         SDHC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   0       R/W    controller_reset                1'h0
   1       R/W    fifo_reset                      1'h0
   2       R/W    dma_reset                       1'h0
   3       R/W    reserved000_03                  1'h0
   4       R/W    int_enable                      1'h0
   5       R/W    dma_enable                      1'h0
   6       R/W    read_wait                       1'h0
   7       R/W    send_irq_response               1'h0
   8       R/W    abort_read_data                 1'h0
   9       R/W    send_ccsd                       1'h0
   10      R/W    send_auto_stop_ccsd             1'h0
   11      R/W    ceata_device_interrupt_status   1'h0
   15:12   R/W    reserved000_15_12               4'h0
   19:16   R/W    card_voltage_a                  4'h0
   23:20   R/W    card_voltage_b                  4'h0
   24      R/W    enable_OD_pullup                1'h1
   25      R/W    use_internal_dmac               1'h0
   31:26   R/W    reserved000_31_26               6'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t controller_reset: 1;
        __IO uint32_t fifo_reset: 1;
        __IO uint32_t dma_reset: 1;
        __IO uint32_t reserved_2: 1;
        __IO uint32_t int_enable: 1;
        __IO uint32_t dma_enable: 1;
        __IO uint32_t read_wait: 1;
        __IO uint32_t send_irq_response: 1;
        __IO uint32_t abort_read_data: 1;
        __IO uint32_t send_ccsd: 1;
        __IO uint32_t send_auto_stop_ccsd: 1;
        __IO uint32_t ceata_device_interrupt_status: 1;
        __IO uint32_t reserved_1: 4;
        __IO uint32_t card_voltage_a: 4;
        __IO uint32_t card_voltage_b: 4;
        __IO uint32_t enable_OD_pullup: 1;
        __IO uint32_t use_internal_dmac: 1;
        __IO uint32_t reserved_0: 6;
    } b;
} SDHC_CTRL_t;



/* 0x04
   29:0    R/W    power_enable                    30'h0
   31:30   R/W    reserved000_31_30               2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t power_enable: 30;
        __IO uint32_t reserved_0: 2;
    } b;
} SDHC_PWREN_t;



/* 0x08
   7:0     R/W    clk_divider0                    8'h0
   15:8    R/W    clk_divider1                    8'h0
   23:16   R/W    clk_divider2                    8'h0
   31:24   R/W    clk_divider3                    8'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t clk_divider0: 8;
        __IO uint32_t clk_divider1: 8;
        __IO uint32_t clk_divider2: 8;
        __IO uint32_t clk_divider3: 8;
    } b;
} SDHC_CLKDIV_t;



/* 0x0C
   31:0    R/W    clk_source                      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t clk_source: 32;
    } b;
} SDHC_CLKSRC_t;



/* 0x10
   15:0    R/W    cclk_enable                     16'h0
   31:16   R/W    cclk_low_power                  16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t cclk_enable: 16;
        __IO uint32_t cclk_low_power: 16;
    } b;
} SDHC_CLKENA_t;



/* 0x14
   7:0     R/W    response_timeout                8'h40
   31:8    R/W    data_timeout                    24'hffffff
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t response_timeout: 8;
        __IO uint32_t data_timeout: 24;
    } b;
} SDHC_TMOUT_t;



/* 0x18
   15:0    R/W    card_width_4or1_bit             16'h0
   31:16   R/W    card_width_8bit                 16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t card_width_4or1_bit: 16;
        __IO uint32_t card_width_8bit: 16;
    } b;
} SDHC_CTYPE_t;



/* 0x1C
   15:0    R/W    block_size                      16'h200
   31:16   R/W    reserved01c_31_16               16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t block_size: 16;
        __IO uint32_t reserved_0: 16;
    } b;
} SDHC_BLKSIZ_t;



/* 0x20
   31:0    R/W    byte_count                      32'h200
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t byte_count: 32;
    } b;
} SDHC_BYTCNT_t;



/* 0x24
   15:0    R/W    int_mask                        16'h0
   31:16   R/W    sdhc_int_mask                   16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t CardDetect: 1;
        uint32_t ResponseError: 1;
        uint32_t CommandDone: 1;
        uint32_t DataTransferOver: 1;

        uint32_t TransmitFifoDataRequest: 1;
        uint32_t ReceiveFifoDataRequest: 1;
        uint32_t ResponseCrcError: 1;
        uint32_t DataCrcError: 1;

        uint32_t ResponseTimeout: 1;
        uint32_t DataReadTimeout: 1;
        uint32_t DataStarvatioByHostTimeout_VoltSwitchInt: 1;
        uint32_t FifoUnderrunOverrunError: 1;

        uint32_t HardwareLockedWriteError: 1;
        uint32_t StartBitError_BusyClearInterrupt: 1;
        uint32_t AutoCommandDone: 1;
        uint32_t EndBitError_WriteNoCrc: 1;

        uint32_t sdhc_int_mask: 16;
    } b;
} SDHC_INTMASK_t;



/* 0x28
   31:0    R/W    cmd_arg                         32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t cmd_arg: 32;
    } b;
} SDHC_CMDARG_t;



/* 0x2C
   5:0     R/W    cmd_index                       6'h0
   6       R/W    response_expect                 1'h0
   7       R/W    response_length                 1'h0
   8       R/W    check_response_crc              1'h0
   9       R/W    data_expected                   1'h0
   10      R/W    read/write                      1'h0
   11      R/W    transfer_mode                   1'h0
   12      R/W    send_auto_stop                  1'h0
   13      R/W    wait_prvdata_complete           1'h0
   14      R/W    stop_abort_cmd                  1'h0
   15      R/W    send_initialization             1'h0
   20:16   R/W    card_number                     5'h0
   21      R/W    update_clock_registers_only     1'h0
   22      R/W    read_ceata_device               1'h0
   23      R/W    ccs_expected                    1'h0
   24      R/W    enable_boot                     1'h0
   25      R/W    expect_boot_ack                 1'h0
   26      R/W    disable_boot                    1'h0
   27      R/W    boot_mode                       1'h0
   28      R/W    volt_switch                     1'h0
   29      R/W    use_hold_reg                    1'h1
   30      R/W    reserved02c_30                  1'h0
   31      R/W    start_cmd                       1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t cmd_index: 6;
        __IO uint32_t response_expect: 1;
        __IO uint32_t response_length: 1;
        __IO uint32_t check_response_crc: 1;
        __IO uint32_t data_expected: 1;
        __IO uint32_t read_write: 1;
        __IO uint32_t transfer_mode: 1;
        __IO uint32_t send_auto_stop: 1;
        __IO uint32_t wait_prvdata_complete: 1;
        __IO uint32_t stop_abort_cmd: 1;
        __IO uint32_t send_initialization: 1;
        __IO uint32_t card_number: 5;
        __IO uint32_t update_clock_registers_only: 1;
        __IO uint32_t read_ceata_device: 1;
        __IO uint32_t ccs_expected: 1;
        __IO uint32_t enable_boot: 1;
        __IO uint32_t expect_boot_ack: 1;
        __IO uint32_t disable_boot: 1;
        __IO uint32_t boot_mode: 1;
        __IO uint32_t volt_switch: 1;
        __IO uint32_t use_hold_reg: 1;
        __IO uint32_t reserved_0: 1;
        __IO uint32_t start_cmd: 1;
    } b;
} SDHC_CMD_t;



/* 0x30
   31:0    R      response_0                      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t response_0: 32;
    } b;
} SDHC_RESP0_t;



/* 0x34
   31:0    R      response_1                      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t response_1: 32;
    } b;
} SDHC_RESP1_t;



/* 0x38
   31:0    R      response_2                      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t response_2: 32;
    } b;
} SDHC_RESP2_t;



/* 0x3C
   31:0    R      response_3                      32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t response_3: 32;
    } b;
} SDHC_RESP3_t;



/* 0x40
   15:0    R      int_status                      16'h0
   31:16   R      sdhc_interrupt                  16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t CardDetect: 1;
        uint32_t ResponseError: 1;
        uint32_t CommandDone: 1;
        uint32_t DataTransferOver: 1;

        uint32_t TransmitFifoDataRequest: 1;
        uint32_t ReceiveFifoDataRequest: 1;
        uint32_t ResponseCrcError: 1;
        uint32_t DataCrcError: 1;

        uint32_t ResponseTimeout: 1;
        uint32_t DataReadTimeout: 1;
        uint32_t DataStarvatioByHostTimeout_VoltswitchInt: 1;
        uint32_t FifoUnderrunOverrunError: 1;

        uint32_t HardwareLockedWriteError: 1;
        uint32_t StartBitError_BusyClearInterrupt: 1;
        uint32_t AutoCommandDone: 1;
        uint32_t EndBitError_WriteNoCrc: 1;

        uint32_t sdhc_interrupt: 16;
    } b;
} SDHC_MINITSTS_t;



/* 0x44
   15:0    R/W    int_status                      16'h0
   31:16   R/W    sdhc_interrupt                  16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        uint32_t CardDetect: 1;
        uint32_t ResponseError: 1;
        uint32_t CommandDone: 1;
        uint32_t DataTransferOver: 1;

        uint32_t TransmitFifoDataRequest: 1;
        uint32_t ReceiveFifoDataRequest: 1;
        uint32_t ResponseCrcError: 1;
        uint32_t DataCrcError: 1;

        uint32_t ResponseTimeout: 1;
        uint32_t DataReadTimeout: 1;
        uint32_t DataStarvatioByHostTimeout_VoltswitchInt: 1;
        uint32_t FifoUnderrunOverrunError: 1;

        uint32_t HardwareLockedWriteError: 1;
        uint32_t StartBitError_BusyClearInterrupt: 1;
        uint32_t AutoCommandDone: 1;
        uint32_t EndBitError_WriteNoCrc: 1;

        uint32_t sdhc_interrupt: 16;
    } b;
} SDHC_RINTSTS_t;



/* 0x48
   0       R      fifo_rx_watermark               1'h0
   1       R      fifo_tx_watermark               1'h1
   2       R      fifo_empty                      1'h1
   3       R      fifo_full                       1'h0
   7:4     R      command_fsm_states              4'h0
   8       R      data_3_status                   1'b0
   9       R      data_busy                       1'b0
   10      R      data_state_mc_busy              1'h1
   16:11   R      response_index                  6'h0
   29:17   R      fifo_count                      13'h0
   30      R      dma_ack                         1'h0
   31      R      dma_req                         1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t fifo_rx_watermark: 1;
        __I uint32_t fifo_tx_watermark: 1;
        __I uint32_t fifo_empty: 1;
        __I uint32_t fifo_full: 1;
        __I uint32_t command_fsm_states: 4;
        __I uint32_t data_3_status: 1;
        __I uint32_t data_busy: 1;
        __I uint32_t data_state_mc_busy: 1;
        __I uint32_t response_index: 6;
        __I uint32_t fifo_count: 13;
        __I uint32_t dma_ack: 1;
        __I uint32_t dma_req: 1;
    } b;
} SDHC_STATUS_t;



/* 0x4C
   11:0    R/W    TX_Wmark                        12'h0
   15:12   R/W    reserved04c_15_12               4'h0
   27:16   R/W    RX_Wmark                        12'h1ff
   30:28   R/W    DW_DMA_Mutiple_Transaction_Size 3'h0
   31      R/W    reserved04c_31                  1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t TX_Wmark: 12;
        __IO uint32_t reserved_1: 4;
        __IO uint32_t RX_Wmark: 12;
        __IO uint32_t DW_DMA_Mutiple_Transaction_Size: 3;
        __IO uint32_t reserved_0: 1;
    } b;
} SDHC_FIFOTH_t;



/* 0x50
   29:0    R      card_detect_n                   30'h3fff_ffff
   31:30   R/W    reserved050_31_30               2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t card_detect_n: 30;
        __IO uint32_t reserved_0: 2;
    } b;
} SDHC_CDETECT_t;



/* 0x54
   29:0    R      write_protect                   30'h0
   31:30   R/W    reserved054_31_30               2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t write_protect: 30;
        __IO uint32_t reserved_0: 2;
    } b;
} SDHC_WRTPRT_t;



/* 0x58
   7:0     R/W    gpi                             8'h0
   23:8    R/W    gpo                             16'h0
   31:24   R/W    reserved04c_31                  8'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t gpi: 8;
        __IO uint32_t gpo: 16;
        __IO uint32_t reserved_0: 8;
    } b;
} SDHC_GPIO_t;



/* 0x5C
   31:0    R      trans_card_byte_count           32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t trans_card_byte_count: 32;
    } b;
} SDHC_TCBCNT_t;



/* 0x60
   31:0    R      trans_fifo_byte_count           32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t trans_fifo_byte_count: 32;
    } b;
} SDHC_TBBCNT_t;



/* 0x64
   23:0    R/W    debounce_count                  24'hffffff
   31:24   R/W    reserved064_31_24               8'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t debounce_count: 24;
        __IO uint32_t reserved_0: 8;
    } b;
} SDHC_DEBNCE_t;



/* 0x68
   31:0    R/W    usrid                           32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t usrid: 32;
    } b;
} SDHC_USRID_t;



/* 0x6C
   31:0    R      verid                           32'h5342_270a
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t verid: 32;
    } b;
} SDHC_VERID_t;



/* 0x70
   31:0    R      hcon                            32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t hcon: 32;
    } b;
} SDHC_HCON_t;



/* 0x74
   15:0    R/W    volt_reg                        16'h0
   31:16   R/W    ddr_reg                         16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t volt_reg: 16;
        __IO uint32_t ddr_reg: 16;
    } b;
} SDHC_UHS_REG_t;



/* 0x78
   15:0    R/W    card_reset                      16'h1
   31:16   R/W    reserved078_31_16               16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t card_reset: 16;
        __IO uint32_t reserved_0: 16;
    } b;
} SDHC_RST_N_t;




/* 0x80
   0       R/W    swr                             1'h0
   1       R/W    fd                              1'h0
   6:2     R/W    dsl                             5'h0
   7       R/W    de                              1'h0
   10:8    R/W    pbl                             3'h0
   31:11   R/W    reserved080_31_11               21'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t swr: 1;
        __IO uint32_t fb: 1;
        __IO uint32_t dsl: 5;
        __IO uint32_t de: 1;
        __IO uint32_t pbl: 3;
        __IO uint32_t reserved_0: 21;
    } b;
} SDHC_BMOD_t;



/* 0x84
   31:0    W      pd                              32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __O uint32_t pd: 32;
    } b;
} SDHC_PLDMND_t;



/* 0x88
   31:0    R/W    sdl                             32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t sdl: 32;
    } b;
} SDHC_DBADDR_t;



/* 0x8C
   0       R/W    ti                              1'h0
   1       R/W    ri                              1'h0
   2       R/W    fbe                             1'h0
   3       R/W    reserved08C_3                   1'h0
   4       R/W    du                              1'h0
   5       R/W    ces                             1'h0
   7:6     R/W    reserved08C_7_6                 2'h0
   8       R/W    nis                             1'h0
   9       R/W    ais                             1'h0
   12:10   R/W    fbe_code                        3'h0
   16:13   R/W    fsm                             4'h0
   31:17   R/W    reserved08C_31_17               15'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t ti: 1;
        __IO uint32_t ri: 1;
        __IO uint32_t fbe: 1;
        __IO uint32_t reserved_2: 1;
        __IO uint32_t du: 1;
        __IO uint32_t ces: 1;
        __IO uint32_t reserved_1: 2;
        __IO uint32_t nis: 1;
        __IO uint32_t ais: 1;
        __IO uint32_t fbe_code: 3;
        __IO uint32_t fsm: 4;
        __IO uint32_t reserved_0: 15;
    } b;
} SDHC_IDSTS_t;



/* 0x90
   0       R/W    ti                              1'h0
   1       R/W    ri                              1'h0
   2       R/W    fbe                             1'h0
   3       R/W    reserved08C_3                   1'h0
   4       R/W    du                              1'h0
   5       R/W    ces                             1'h0
   7:6     R/W    reserved090_7_6                 2'h0
   8       R/W    ni                              1'h0
   9       R/W    ai                              1'h0
   31:10   R/W    reserved090_31_10               22'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t ti: 1;
        __IO uint32_t ri: 1;
        __IO uint32_t fbe: 1;
        __IO uint32_t reserved_2: 1;
        __IO uint32_t du: 1;
        __IO uint32_t ces: 1;
        __IO uint32_t reserved_1: 2;
        __IO uint32_t ni: 1;
        __IO uint32_t ai: 1;
        __IO uint32_t reserved_0: 22;
    } b;
} SDHC_IDINTEN_t;



/* 0x94
   31:0    R      hda                             32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t hda: 32;
    } b;
} SDHC_DSCADDR_t;



/* 0x98
   31:0    R      hba                             32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t hba: 32;
    } b;
} SDHC_BUFADDR_t;




/* 0x100
   0       R/W    CardRdThrEn                     1'h0
   1       R/W    BsyClrIntEn                     1'h0
   2       R/W    CardWrThrEn                     1'h0
   15:3    R/W    reserved100_15_3                13'h0
   27:16   R/W    cardthreshold                   12'h0
   31:28   R/W    reserved100_31_28               4'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t CardRdThrEn: 1;
        __IO uint32_t BsyClrIntEn: 1;
        __IO uint32_t CardWrThrEn: 1;
        __IO uint32_t reserved_1: 13;
        __IO uint32_t CardThreshold: 12;
        __IO uint32_t reserved_0: 4;
    } b;
} SDHC_CARDTHRCTL_t;



/* 0x104
   15:0    R/W    back_end_power                  16'h0
   31:16   R/W    reserved104_31_16               16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t back_end_power: 16;
        __IO uint32_t reserved_0: 16;
    } b;
} SDHC_BACK_END_POWER_t;



/* 0x108
   15:0    R/W    mmc_volt_reg                    16'h0
   22:16   R/W    clk_smpl_phase_ctrl             7'h0
   29:23   R/W    clk_drv_phase_ctrl              7'h0
   31:30   R/W    ext_clk_mux_ctrl                2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t mmc_volt_reg: 16;
        __IO uint32_t clk_smpl_phase_ctrl: 7;
        __IO uint32_t clk_drv_phase_ctrl: 7;
        __IO uint32_t ext_clk_mux_ctrl: 2;
    } b;
} SDHC_UHS_REG_EXT_t;



/* 0x10C
   15:0    R/W    clk_smpl_phase_ctrl             16'h0
   30:16   R/W    reserved10c_30_16               15'h0
   31      R/W    hs400_mode                      1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t clk_smpl_phase_ctrl: 16;
        __IO uint32_t reserved_0: 15;
        __IO uint32_t hs400_mode: 1;
    } b;
} SDHC_EMMC_DDR_REG_t;



/* 0x110
   31:0    R/W    enable_shift                    32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t enable_shift: 32;
    } b;
} SDHC_ENABLE_SHIFT_t;


/*============================================================================*
 *              Peri-on Function and Clock Registers Descriptions
 *============================================================================*/
/* 0x374
   0       R/W    sdhc_ck_en                  1'h0
   1       R/W    sdhc_func_en                1'h0
   2       R/W    r_sdhc_clk_src_en           1'h0
   6:3     R/W    r_sdhc_div_sel              4'h0
   7       R/W    r_sdhc_div_en               1'h0
   8       R/W    r_sdhc_mux_clk_cg_en        1'h0
   9       R/W    r_sdhc_clk_src_sel1         1'h0
   10      R/W    r_sdhc_clk_src_sel0         1'h0
   31:11   R/W    RSVD                        21'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t sdhc_ck_en: 1;
        __IO uint32_t sdhc_func_en: 1;
        __IO uint32_t r_sdhc_clk_src_en: 1;
        __IO uint32_t r_sdhc_div_sel: 4;
        __IO uint32_t r_sdhc_div_en: 1;
        __IO uint32_t r_sdhc_mux_clk_cg_en: 1;
        __IO uint32_t r_sdhc_clk_src_sel1: 1;
        __IO uint32_t r_sdhc_clk_src_sel0: 1;
        __IO uint32_t reserved_0: 21;
    } b;
} SDHC_CTL_t;



/* 0x378
   7:0     R/W    r_sdhc_drv_dly_sel           8'h0
   15:8    R/W    r_sdhc_sample_dly_sel        8'h0
   17:16   R/W    r_sdhc_clk_sel_drv           2'h0
   19:18   R/W    r_sdhc_clk_sel_sample        2'h0
   20      R/W    r_sdhc_bypass_shift_drv      1'h0
   21      R/W    r_sdhc_bypass_shift_sample   1'h0
   22      R/W    r_sdhc_bypass_delay_drv      1'h0
   23      R/W    r_sdhc_bypass_delay_sample   1'h0
   31:24   R/W    r_sdhc_clk_out_dly_sel       8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        __IO uint32_t r_sdhc_drv_dly_sel: 8;
        __IO uint32_t r_sdhc_sample_dly_sel: 8;
        __IO uint32_t r_sdhc_clk_sel_drv: 2;
        __IO uint32_t r_sdhc_clk_sel_sample: 2;
        __IO uint32_t r_sdhc_bypass_shift_drv: 1;
        __IO uint32_t r_sdhc_bypass_shift_sample: 1;
        __IO uint32_t r_sdhc_bypass_delay_drv: 1;
        __IO uint32_t r_sdhc_bypass_delay_sample: 1;
        __IO uint32_t r_sdhc_clk_out_dly_sel: 8;
    } b;
} SDHC_PHY0_t;


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_SDHC_REG_H */

