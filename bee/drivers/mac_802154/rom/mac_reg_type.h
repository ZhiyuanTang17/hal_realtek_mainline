/**************************************************************************//**
 * @file      mac_reg_type.h
 * @brief
 * @version   V1.00
 * @date      2023-7-12 18:32:16
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2022 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef _MAC_REG_TYPE_H_
#define _MAC_REG_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_MAC_REG_TYPE

/**
 * @addtogroup ls_hal_mac_reg MAC Registers.
 * @ingroup ls_hal_mac
 * @{
 */

/**
  \brief Union type to access mac_device_ctrl (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) MAC Device Control Register                                */

  struct {
    __IOM uint32_t coord      : 1;            /*!< [0..0] Coordinator: 0: (default) Device is not set as coordinator;
                                                   1: Set device as coordinator                                              */
    __IOM uint32_t pancoord   : 1;            /*!< [1..1] PAN Coordinator: 0: (default) Device is not set as PAN
                                                   coordinator; 1: Set device as PAN coordinator                             */
    __IOM uint32_t mac_lpbk   : 1;            /*!< [2..2] MAC loopback function enable                                       */
    __IOM uint32_t noackrsp   : 1;            /*!< [3..3] Automatic Acknowledgement Response: 0: (default) Enables
                                                   automatic acknowledgement response; 1: Disables automatic
                                                   acknowledgement response                                                  */
          uint32_t            : 1;
    __IOM uint32_t nocrc      : 1;            /*!< [5..5] No CRC data appended with normal fifo                              */
    __IOM uint32_t fifoen     : 1;            /*!< [6..6] The TXFIFO and RXFIFO output enable control: 0: The TXFIFO
                                                   and RXFIFO are always output enabled; 1: The enabled signal
                                                   for the TXFIFO and RXFIFO output is controlled by the internal
                                                   state machine                                                             */
          uint32_t            : 1;
    __IOM uint32_t split_irq  : 1;            /*!< [8..8] Split security IRQ with normal IRQ                                 */
    __IOM uint32_t irqpol     : 1;            /*!< [9..9] Interrupt Edge Polarity: 0: (default) Falling edge; 1:
                                                   Rising edge                                                               */
          uint32_t            : 6;
    __IOM uint32_t tickp      : 9;            /*!< [24..16] Ticks period representing a symbol.Unit in system clock
                                                   (20MHz). Default a symbol time is 16us. Tickp = 16/(1/20)
                                                   = 320d = 140H                                                             */
          uint32_t            : 7;
  } b;                                        /*!< bit fields for mac_device_ctrl */
} mac_device_ctrl_t, *pmac_device_ctrl_t;

/**
  \brief Union type to access mac_panid (@ 0x00000004).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000004) PAN ID Configuration Register                              */

  struct {
    __IOM uint16_t panid      : 16;           /*!< [15..0] 16-bits PAN identifier of this device                             */
  } b;                                        /*!< bit fields for mac_panid */
} mac_panid_t, *pmac_panid_t;

/**
  \brief Union type to access mac_sadr (@ 0x00000006).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000006) Short Address Configuration Register                       */

  struct {
    __IOM uint16_t sadr       : 16;           /*!< [15..0] 16-bits Short Address of this device                              */
  } b;                                        /*!< bit fields for mac_sadr */
} mac_sadr_t, *pmac_sadr_t;

/**
  \brief Union type to access mac_eadr_l (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) Extended Address Lower Bytes Register                      */

  struct {
    __IOM uint32_t eadr_l     : 32;           /*!< [31..0] Bits[31:0] of Extended Address of this device                     */
  } b;                                        /*!< bit fields for mac_eadr_l */
} mac_eadr_l_t, *pmac_eadr_l_t;

/**
  \brief Union type to access mac_eadr_h (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) Extended Address Higher Bytes Register                     */

  struct {
    __IOM uint32_t eadr_h     : 32;           /*!< [31..0] Bits[63:32] of Extended Address of this device                    */
  } b;                                        /*!< bit fields for mac_eadr_h */
} mac_eadr_h_t, *pmac_eadr_h_t;

/**
  \brief Union type to access mac_clk_ctrl (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000010) Clock Gated Control Register                               */

  struct {
    __IOM uint32_t ctrl_sec   : 1;            /*!< [0..0] Security clock controller                                          */
    __IOM uint32_t en_sec     : 1;            /*!< [1..1] Security clock enable/disable when CTRL_SEC is '1'                 */
    __IOM uint32_t entxm      : 1;            /*!< [2..2] TX MAC Clock Enable: 0: (default) Disable; 1: Enable               */
    __IOM uint32_t engts      : 1;            /*!< [3..3] GTS FIFO Clock: 0: (default) Disable; 1: Enable                    */
    __IOM uint32_t enrxm      : 1;            /*!< [4..4] RX MAC Clock Enable: 0: (default) Disable; 1: Enable               */
    __IOM uint32_t txn_off    : 1;            /*!< [5..5] TXNFIFO clock always off                                           */
    __IOM uint32_t txb_on     : 1;            /*!< [6..6] Beacon FIFO clock always on                                        */
    __IOM uint32_t ffidle     : 1;            /*!< [7..7] Force Clock Enable (Rx / Source Match Filter / GTS FIFO
                                                   / TX Normal)0: (default) Disable1: Enable                                 */
    __IOM uint32_t ed_scan_clkon : 1;         /*!< [8..8] Force enable clock of ED scan block0: (default) Disable,
                                                   clock is auto-gated1: Enable                                              */
    __IOM uint32_t phy_arb_clkon : 1;         /*!< [9..9] Force enable clock of PHY arbitration block0: (default)
                                                   Disable, clock is auto-gated1: Enable                                     */
    __IOM uint32_t fifo_clkon : 1;            /*!< [10..10] Force enable Beacon / Normal / GTS / RX / SEC KEY FIFO
                                                   Clock:0: (default) Disable1: Enable                                       */
    __IOM uint32_t dbg_clkon  : 1;            /*!< [11..11] Force enable Debug counter circuit clock:0: (default)
                                                   Disable1: Enable                                                          */
          uint32_t            : 20;
  } b;                                        /*!< bit fields for mac_clk_ctrl */
} mac_clk_ctrl_t, *pmac_clk_ctrl_t;

/**
  \brief Union type to access mac_mac_timer (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) MAC Timer Control Register                                 */

  struct {
    __OM  uint32_t mactmr_l   : 8;            /*!< [7..0] 16-Bit MAC Timer, Low Byte                                         */
    __OM  uint32_t mactmr_h   : 8;            /*!< [15..8] 16-Bit MAC Timer, High Byte. Unit: 8us. FW writing this
                                                   field will trigger MAC timer start to count down                          */
    __IOM uint32_t mactmrfr   : 1;            /*!< [16..16] MAC Timer Free Run: 0: (default) Disable; 1: Enable.
                                                   If the free-run value of MAC timer is selected to be attached
                                                   to every received packet behind RSSI, this MAC timer free
                                                   run should be enabled.                                                    */
          uint32_t            : 7;
    __OM  uint32_t btcmp0_dis : 1;            /*!< [24..24] BT-MAC Timer (BT Clock comparator) 0 disable.0: (default)
                                                   malfunction1: Disable BT-MAC timer comparator function.
                                                   FW can write this bit as 1 to stop the BT-MAC timer 0 if
                                                   it is running.This bit is cleared to '0' by hardware automatically.       */
    __OM  uint32_t btcmp1_dis : 1;            /*!< [25..25] BT-MAC Timer (BT Clock comparator) 1 disable.0: (default)
                                                   malfunction1: Disable BT-MAC timer comparator function.
                                                   FW can write this bit as 1 to stop the BT-MAC timer 1 if
                                                   it is running.This bit is cleared to '0' by hardware automatically
                                                   .                                                                         */
    __OM  uint32_t btcmp2_dis : 1;            /*!< [26..26] BT-MAC Timer (BT Clock comparator) 2 disable.0: (default)
                                                   malfunction1: Disable BT-MAC timer comparator function.
                                                   FW can write this bit as 1 to stop the BT-MAC timer 2 if
                                                   it is running.This bit is cleared to '0' by hardware automatically
                                                   .                                                                         */
    __OM  uint32_t btcmp3_dis : 1;            /*!< [27..27] BT-MAC Timer (BT Clock comparator) 3 disable.0: (default)
                                                   malfunction1: Disable BT-MAC timer comparator function.
                                                   FW can write this bit as 1 to stop the BT-MAC timer 3 if
                                                   it is running.This bit is cleared to '0' by hardware automatically
                                                   .                                                                         */
          uint32_t            : 4;
  } b;                                        /*!< bit fields for mac_mac_timer */
} mac_mac_timer_t, *pmac_mac_timer_t;

/**
  \brief Union type to access mac_rst_ctrl (@ 0x00000018).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000018) MAC Reset Control Register                                 */

  struct {
          uint32_t            : 16;
    __OM  uint32_t rstmac     : 1;            /*!< [16..16] MAC and Registers Reset: 1: Reset MAC circuitry and
                                                   all registers. Initialization is needed after RSTMAC reset.
                                                   Bit is automatically cleared to '0' by hardware                           */
          uint32_t            : 15;
  } b;                                        /*!< bit fields for mac_rst_ctrl */
} mac_rst_ctrl_t, *pmac_rst_ctrl_t;

/**
  \brief Union type to access mac_rx_frm_length (@ 0x0000001C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000001C) RX Decryption Header Length Control Register               */

  struct {
    __IOM uint32_t hlen       : 7;            /*!< [6..0] Header Length for Decryption Process in RX FIFO. Header
                                                   length of the received packet including frame control field,
                                                   sequence number and address information. If a user-defined
                                                   header length (including auxiliary header length) is used,
                                                   user shall update the length value by writing HLEN[5:0]
                                                   back after security interrupt received. 000000: (default)                 */
          uint32_t            : 1;
    __IM  uint32_t flen       : 7;            /*!< [14..8] Internal frame length                                             */
          uint32_t            : 17;
  } b;                                        /*!< bit fields for mac_rx_frm_length */
} mac_rx_frm_length_t, *pmac_rx_frm_length_t;

/**
  \brief Union type to access mac_intmsk (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) Interrupt Mask Control Register                            */

  struct {
    __IOM uint32_t txnmsk     : 1;            /*!< [0..0] TX Normal FIFO Transmission Interrupt Mask: 0: Enable
                                                   the TX Normal FIFO transmission interrupt; 1: (default)
                                                   Disable the TX Normal FIFO transmission interrupt                         */
    __IOM uint32_t txg1msk    : 1;            /*!< [1..1] TX GTS1 FIFO Transmission Interrupt Mask: 0: Enable the
                                                   TX GTS1 FIFO transmission interrupt; 1: (default) Disable
                                                   the TX GTS1 FIFO transmission interrupt                                   */
    __IOM uint32_t txg2msk    : 1;            /*!< [2..2] TX GTS2 FIFO Transmission Interrupt Mask: 0: Enable the
                                                   TX GTS2 FIFO transmission interrupt; 1: (default) Disable
                                                   the TX GTS2 FIFO transmission interrupt                                   */
    __IOM uint32_t txnterrmsk : 1;            /*!< [3..3] TX at given time error Interrupt Mask: 0: Enable the
                                                   TX at given time error interrupt; 1: (default) Disable
                                                   the TX at given time error interrupt TX at given time error
                                                   interrupt is triggered when a Normal FIFO TX at a scheduled
                                                   TX time error is occurred. This error could be caused by
                                                   an invalid TX time or CCA failure                                         */
    __IOM uint32_t rxelymsk   : 1;            /*!< [4..4] RX eraly Interrupt Mask: 0: Enable the RX eraly interrupt;
                                                   1: (default) Disable the RX eraly interrupt RX early interrupt
                                                   is triggered when on the receiving of an incoming frame
                                                   and its MAC header and Secure AUX Header (if present) are
                                                   received complete and pass the RX filter check                            */
    __IOM uint32_t secmsk     : 1;            /*!< [5..5] Security Key Request Interrupt Mask: 0: Enable security
                                                   key request interrupt; 1: (default) Disable the security
                                                   key request interrupt                                                     */
    __IOM uint32_t rxmsk      : 1;            /*!< [6..6] RX FIFO Reception Interrupt Mask: 0: Enable the RX FIFO
                                                   reception interrupt; 1: (default) Disable the RX FIFO reception
                                                   interrupt                                                                 */
    __IOM uint32_t mactmrmsk  : 1;            /*!< [7..7] MAC Timer Interrupt Mask: 0: Enable the MAC timer interrupt;
                                                   1: (default) Disable the MAC timer interrupt                              */
    __IOM uint32_t btcmp0msk  : 1;            /*!< [8..8] BT-MAC timer 0 Interrupt Mask: 0: Enable the BT-MAC timer
                                                   interrupt; 1: (default) Disable the BT-MAC timer interrupt
                                                   BT-MAC timer interrupt is triggered when the counter value
                                                   of the free run BT-MAC timer is matched with the BT-MAC
                                                   timer comparator value.                                                   */
    __IOM uint32_t btcmp1msk  : 1;            /*!< [9..9] BT-MAC timer 1 Interrupt Mask: 0: Enable the BT-MAC timer
                                                   interrupt; 1: (default) Disable the BT-MAC timer interrupt
                                                   BT-MAC timer interrupt is triggered when the counter value
                                                   of the free run BT-MAC timer is matched with the BT-MAC
                                                   timer comparator value.                                                   */
    __IOM uint32_t gntmsk     : 1;            /*!< [10..10] PHY grant update Interrupt Mask: 0: Enable PHY grant
                                                   update interrupt; 1: (default) Disable the PHY grant update
                                                   interrupt PHY grant update interrupt is triggered when
                                                   the PHY grant request success or failed, or PHY grant is
                                                   de-asserted by Arbitration Coordinator.                                   */
    __IOM uint32_t edscanmsk  : 1;            /*!< [11..11] ED scan done Interrupt Mask: 0: Enable ED scan done
                                                   interrupt; 1: (default) Disable the ED scan done interrupt
                                                   ED scan done interrupt is triggered when an ED scan procedure
                                                   is done                                                                   */
    __IOM uint32_t sfstartmsk : 1;            /*!< [12..12] Slotted enable Superframe start Interrupt Mask: 0:
                                                   Enable the superframe start interrupt; 1: (default) Disable
                                                   the superframe start interrupt                                            */
    __IOM uint32_t sfendmsk   : 1;            /*!< [13..13] Slotted enable Superframe end Interrupt Mask: 0: Enable
                                                   the superframe end interrupt; 1: (default) Disable the
                                                   superframe end interrupt                                                  */
    __IOM uint32_t btcmp2msk  : 1;            /*!< [14..14] BT-MAC timer 2 Interrupt Mask: 0: Enable the BT-MAC
                                                   timer interrupt; 1: (default) Disable the BT-MAC timer
                                                   interrupt BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value.                                        */
    __IOM uint32_t btcmp3msk  : 1;            /*!< [15..15] BT-MAC timer 3 Interrupt Mask: 0: Enable the BT-MAC
                                                   timer interrupt; 1: (default) Disable the BT-MAC timer
                                                   interrupt BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value.                                        */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_intmsk */
} mac_intmsk_t, *pmac_intmsk_t;

/**
  \brief Union type to access mac_isrsts (@ 0x00000024).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000024) Interrupt Status Register                                  */

  struct {
    __IOM uint32_t txnif      : 1;            /*!< [0..0] TX Normal FIFO Transmission Interrupt: 0: (default) No
                                                   TX Normal FIFO transmission interrupt occurred; 1: TX Normal
                                                   FIFO transmission interrupt occurred, Write 1 clear                       */
    __IOM uint32_t txg1if     : 1;            /*!< [1..1] TX GTS1 FIFO Transmission Interrupt: 0: (default) No
                                                   TX GTS1 FIFO transmission interrupt occurred; 1: A TX GTS1
                                                   FIFO transmission interrupt occurred, Write 1 clear                       */
    __IOM uint32_t txg2if     : 1;            /*!< [2..2] TX GTS2 FIFO Transmission Interrupt: 0: (default) No
                                                   TX GTS2 FIFO transmission interrupt occurred; 1: A TX GTS2
                                                   FIFO transmission interrupt occurred, Write 1 clear                       */
    __IOM uint32_t txnterrif  : 1;            /*!< [3..3] TX at given time error Interrupt status: 0: (default)
                                                   no TX at given time error interrupt occurred; 1: the TX
                                                   at given time error interrupt is occurred. TX at given
                                                   time error interrupt is triggered when a Normal FIFO TX
                                                   at a scheduled TX time error is occurred. This error could
                                                   be caused by an invalid TX time or CCA failure. Write 1
                                                   clear.                                                                    */
    __IOM uint32_t rxelyif    : 1;            /*!< [4..4] RX eraly Interrupt status: 0: (default)no RX eraly interrupt
                                                   occurred; 1: the RX eraly interrupt is occurred. RX early
                                                   interrupt is triggered when on the receiving of an incoming
                                                   frame and its MAC header and Secure AUX Header (if present)
                                                   are received complete and pass the RX filter check. Write
                                                   1 clear.                                                                  */
    __IOM uint32_t secif      : 1;            /*!< [5..5] Security Key Request Interrupt: 0: (default) No security
                                                   key request interrupt occurred; 1: A security key request
                                                   interrupt occurred, Write 1 clear                                         */
    __IOM uint32_t rxif       : 1;            /*!< [6..6] RX FIFO Reception Interrupt: 0: (default) No RX FIFO
                                                   reception interrupt occurred; 1: An RX FIFO reception interrupt
                                                   occurred, Write 1 clear                                                   */
    __IOM uint32_t mactmrif   : 1;            /*!< [7..7] MAC timer Interrupt: 0: (default) No MAC timer interrupt
                                                   occurred; 1: A MAC timer interrupt occurred, Write 1 clear                */
    __IOM uint32_t btcmp0if   : 1;            /*!< [8..8] BT-MAC timer 0 Interrupt status: 0: (default) no BT-MAC
                                                   timer interrupt occurred; 1: the BT-MAC timer interrupt
                                                   is occurred. BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value. Write 1 clear.                         */
    __IOM uint32_t btcmp1if   : 1;            /*!< [9..9] BT-MAC timer 1 Interrupt status: 0: (default) no BT-MAC
                                                   timer interrupt occurred; 1: the BT-MAC timer interrupt
                                                   is occurred. BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value. Write 1 clear.                         */
    __IOM uint32_t gntif      : 1;            /*!< [10..10] PHY grant update Interrupt status: 0: no PHY grant
                                                   update interrupt is occurred; 1: PHY grant update interrupt
                                                   is occurred. PHY grant update interrupt is triggered when
                                                   the PHY grant request success or failed, or PHY grant is
                                                   de-asserted by Arbitration Coordinator.                                   */
    __IOM uint32_t edscanif   : 1;            /*!< [11..11] ED scan done Interrupt status: 0: no ED scan done interrupt
                                                   occurred; 1: the ED scan done interrupt is occurred ED
                                                   scan done interrupt is triggered when an ED scan procedure
                                                   is done                                                                   */
    __IOM uint32_t sfstartif  : 1;            /*!< [12..12] Slotted enable Superframe start Interrupt status: 0:
                                                   no superframe start interrupt is pending; 1: the superframe
                                                   start interrupt is occurred and pending                                   */
    __IOM uint32_t sfendif    : 1;            /*!< [13..13] Slotted enable Superframe end Interrupt status: 0:
                                                   no superframe end interrupt is pending; 1: the superframe
                                                   end interrupt is occurred and pending                                     */
    __IOM uint32_t btcmp2if   : 1;            /*!< [14..14] BT-MAC timer 2 Interrupt status: 0: (default) no BT-MAC
                                                   timer interrupt occurred; 1: the BT-MAC timer interrupt
                                                   is occurred. BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value. Write 1 clear.                         */
    __IOM uint32_t btcmp3if   : 1;            /*!< [15..15] BT-MAC timer 3 Interrupt status: 0: (default) no BT-MAC
                                                   timer interrupt occurred; 1: the BT-MAC timer interrupt
                                                   is occurred. BT-MAC timer interrupt is triggered when the
                                                   counter value of the free run BT-MAC timer is matched with
                                                   the BT-MAC timer comparator value. Write 1 clear.                         */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_isrsts */
} mac_isrsts_t, *pmac_isrsts_t;

/**
  \brief Union type to access mac_bt_clk_cmp0 (@ 0x00000028).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000028) BT Clock Comparator 0 Register                             */

  struct {
    __IOM uint32_t bt_ckc     : 10;           /*!< [9..0] The clock counter value of the BT-MAC timer comparator.When
                                                   the (BT NativeClock[22:1] || ClockCounter[9:0]) timer value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator0 interrupt.                                              */
    __IOM uint32_t bt_nclk    : 22;           /*!< [31..10] The native clock value of the BT-MAC timer comparator.
                                                   When the (BT NativeClock[22:1] || ClockCounter[9:0]) value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator interrupt.                                               */
  } b;                                        /*!< bit fields for mac_bt_clk_cmp0 */
} mac_bt_clk_cmp0_t, *pmac_bt_clk_cmp0_t;

/**
  \brief Union type to access mac_bt_clk_cmp1 (@ 0x0000002C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000002C) BT Clock Comparator 1 Register                             */

  struct {
    __IOM uint32_t bt_ckc     : 10;           /*!< [9..0] The clock counter value of the BT-MAC timer comparator.When
                                                   the (BT NativeClock[22:1] || ClockCounter[9:0]) timer value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator1 interrupt.                                              */
    __IOM uint32_t bt_nclk    : 22;           /*!< [31..10] The native clock value of the BT-MAC timer comparator.
                                                   When the (BT NativeClock[22:1] || ClockCounter[9:0]) value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator interrupt.                                               */
  } b;                                        /*!< bit fields for mac_bt_clk_cmp1 */
} mac_bt_clk_cmp1_t, *pmac_bt_clk_cmp1_t;

/**
  \brief Union type to access mac_bt_clk_cmp2 (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) BT Clock Comparator 2 Register                             */

  struct {
    __IOM uint32_t bt_ckc     : 10;           /*!< [9..0] The clock counter value of the BT-MAC timer comparator.When
                                                   the (BT NativeClock[22:1] || ClockCounter[9:0]) timer value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator2 interrupt.                                              */
    __IOM uint32_t bt_nclk    : 22;           /*!< [31..10] The native clock value of the BT-MAC timer comparator.
                                                   When the (BT NativeClock[22:1] || ClockCounter[9:0]) value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator interrupt.                                               */
  } b;                                        /*!< bit fields for mac_bt_clk_cmp2 */
} mac_bt_clk_cmp2_t, *pmac_bt_clk_cmp2_t;

/**
  \brief Union type to access mac_bt_clk_cmp3 (@ 0x00000034).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000034) BT Clock Comparator 3 Register                             */

  struct {
    __IOM uint32_t bt_ckc     : 10;           /*!< [9..0] The clock counter value of the BT-MAC timer comparator.When
                                                   the (BT NativeClock[22:1] || ClockCounter[9:0]) timer value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator3 interrupt.                                              */
    __IOM uint32_t bt_nclk    : 22;           /*!< [31..10] The native clock value of the BT-MAC timer comparator.
                                                   When the (BT NativeClock[22:1] || ClockCounter[9:0]) value
                                                   is matched with (bt_nclk || bt_ckc) then trigger the BT-MAC
                                                   timer comparator interrupt.                                               */
  } b;                                        /*!< bit fields for mac_bt_clk_cmp3 */
} mac_bt_clk_cmp3_t, *pmac_bt_clk_cmp3_t;

/**
  \brief Union type to access mac_ed_scan_ctrl0 (@ 0x00000038).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000038) ED Scan Control Register 0                                 */

  struct {
    __IOM uint32_t scan_enable : 1;           /*!< [0..0] write this bit to start or stop ED scan procedure: 1:
                                                   trigger the ED scan start; 0: cancel a running ED scan;
                                                   HW will clear this bit when ED scan procedure is done.
                                                   The ED scan status is updated in bits[29:26] and ED level
                                                   is updated in peak_value (bits[21:14])                                    */
    __IOM uint32_t scan_round : 13;           /*!< [13..1] set the round of symbols (default 8 symbols) ED scan
                                                   to run for a whole ED scan procedure. Scan round = ed_scan_round
                                                   + 1, ed_scan_round valid value is 0 ~ 8191.                               */
    __IM  uint32_t peak_value : 8;            /*!< [21..14] keep the peak value of ED scan result                            */
    __IOM uint32_t scan_symbol : 4;           /*!< [25..22] number of symbol for a round of ED scan, default a
                                                   round scan 8 symbols                                                      */
    __IM  uint32_t ed_scan_encounter_tx_trig_sts : 1;/*!< [26..26] indicates ED scan is canceled due to conflict with
                                                   TX trigger.                                                               */
    __IM  uint32_t scan_fw_cancel_sts : 1;    /*!< [27..27] indicates the ED scan procedure is finished due to
                                                   FW cancel                                                                 */
    __IM  uint32_t scan_gnt_deassert_sts : 1; /*!< [28..28] indicates the ED scan procedure is finished due to
                                                   PHY grant is de-asserted                                                  */
    __IM  uint32_t scan_ed_vld_tmo_sts : 1;   /*!< [29..29] indicates the ED scan procedure is finished due to
                                                   wait PHY report valid timeout                                             */
    __IM  uint32_t scan_finish_sts : 1;       /*!< [30..30] ed scan finish status:1: ED scan is finished normally            */
    __IOM uint32_t scan_done  : 1;            /*!< [31..31] MAC HW set this bit to indicates current ED scan is
                                                   done. Once this bit is set, bits [30:27] indicates the
                                                   ED scan status. This bit is cleaned by write 1.                           */
  } b;                                        /*!< bit fields for mac_ed_scan_ctrl0 */
} mac_ed_scan_ctrl0_t, *pmac_ed_scan_ctrl0_t;

/**
  \brief Union type to access mac_ed_scan_ctrl1 (@ 0x0000003C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000003C) ED Scan Control Register 1                                 */

  struct {
    __IM  uint32_t scan_cnt   : 14;           /*!< [13..0] indicates how many round of ED symbols scan has ran               */
    __IOM uint32_t scan_vld_tmo_cnt_limit : 6;/*!< [19..14] set the timeout for PHY scan report valid waitting.
                                                   Unit is 1T (0.05us for 20MHz)                                             */
    __IOM uint32_t scan_first_ed_scan_symbol : 4;/*!< [23..20] Timing adjustment before of the 1st round of ED symbols
                                                   scan. Unit is symbol. Timing adjustment = symbol + cnt.                   */
    __IOM uint32_t scan_first_ed_scan_cnt : 8;/*!< [31..24] Timing adjustment before of the 1st round of ED symbols
                                                   scan. Unit is 1 clock (0.05us for 20MHz).                                 */
  } b;                                        /*!< bit fields for mac_ed_scan_ctrl1 */
} mac_ed_scan_ctrl1_t, *pmac_ed_scan_ctrl1_t;

/**
  \brief Union type to access mac_ed_scan_dbg (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) ED Scan Status Register for Debugging                      */

  struct {
    __IM  uint32_t ed_scan_cst : 4;           /*!< [3..0] ED scan current state for debugging.                               */
          uint32_t            : 28;
  } b;                                        /*!< bit fields for mac_ed_scan_dbg */
} mac_ed_scan_dbg_t, *pmac_ed_scan_dbg_t;

/**
  \brief Union type to access mac_phy_arb_ctrl (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) PHY Arbitration Control Register                           */

  struct {
    __IOM uint32_t fw_active_entry : 1;       /*!< [0..0] this bit is controlled by FW to indicates whether the
                                                   MAC FW intend to use PHY and active the meu_zb_fsm HW to
                                                   issue PHY request: 1: FW intend to use PHY for RX/TX, active
                                                   the men_zb_fsm to request PHY; 0: FW write 0 to this bit
                                                   when it no need to use PHY (ex. entering sleep mode), the
                                                   men_zb_fsm will issue 'term' signal to Arbitration Coordinator.           */
    __IOM uint32_t zb_only    : 1;            /*!< [1..1] to control whether to disable ZB MAC PHY grant mechanism
                                                   and MAC assume that it always own the PHY: 0: PHY is shared
                                                   by multiple protocol (BLE/ZB concurrent); 1: PHY is used
                                                   by ZB MAC only, no concurrent multiple protocol                           */
    __IOM uint32_t anchor_point : 18;         /*!< [19..2] the anchor point (in unit of slot, 625us) for PHY grant
                                                   request.                                                                  */
    __IOM uint32_t anch_pt_jump_value : 4;    /*!< [23..20] the anchor point jump value (in unit of slot, 625us)
                                                   for auto PHY request. HW will auto retry the PHY grant
                                                   request with current BT slot + anch_pt_jump_value                         */
    __IM  uint32_t zbrf_gnt_deassert_sts : 1; /*!< [24..24] Indicates the status of PHY grant for ZB MAC: 1: MAC
                                                   lost the PHY grant. This is caused by PHY is granted to
                                                   BLE or FW set the fw_active_entry to low and HW has sent
                                                   term signal to Arbitration Coordinator; 0: MAC still own
                                                   the PHY grant.                                                            */
    __IM  uint32_t zbrf_gnt_fail_sts : 1;     /*!< [25..25] Indicates the PHY grant request execution result: 1:
                                                   PHY is not granted at the assigned anchor point(BT Clock);
                                                   0: PHY grant successfully                                                 */
    __IM  uint32_t zbrf_gnt_sts : 1;          /*!< [26..26] Indicates the PHY grant status when the grant interrupt
                                                   is asserted: 1: PHY is granted; 0: PHY is not granted (grant
                                                   failed or lost PHY grant)                                                 */
          uint32_t            : 5;
  } b;                                        /*!< bit fields for mac_phy_arb_ctrl */
} mac_phy_arb_ctrl_t, *pmac_phy_arb_ctrl_t;

/**
  \brief Union type to access mac_phy_arb_status (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) PHY Arbitration Status Register                            */

  struct {
    __IM  uint32_t zbrf_meu_cs : 2;           /*!< [1..0] current state of men_zb_fsm, for debugging                         */
    __IM  uint32_t zbrf_meu_anchor_point : 18;/*!< [19..2] the current anchor point of meu_zb_fsm requesting PHY
                                                   grant                                                                     */
          uint32_t            : 12;
  } b;                                        /*!< bit fields for mac_phy_arb_status */
} mac_phy_arb_status_t, *pmac_phy_arb_status_t;

/**
  \brief Union type to access mac_bt_clk_latch_ctrl (@ 0x0000004C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000004C) BT Clock Latch Control Register                            */

  struct {
    __IM  uint32_t bt_timer_native_h : 5;     /*!< [4..0] latched BT native clock value bits[27:23]                          */
          uint32_t            : 26;
    __IOM uint32_t bt_timer_latch : 1;        /*!< [31..31] Write 1 to this bit will trigger the MAC HW to latch
                                                   BT free run timer(BT native clock and clock counter) value
                                                   and store them in BT_CLK_LATCH register. HW will auto-clear
                                                   this bit when BT timer value latch is done.                               */
  } b;                                        /*!< bit fields for mac_bt_clk_latch_ctrl */
} mac_bt_clk_latch_ctrl_t, *pmac_bt_clk_latch_ctrl_t;

/**
  \brief Union type to access mac_bt_clk_latch (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) BT Clock Latch Value                                       */

  struct {
    __IM  uint32_t bt_timer_cgn : 10;         /*!< [9..0] latched BT clock counter value                                     */
    __IM  uint32_t bt_timer_native : 22;      /*!< [31..10] latched BT native clock value bits[22:1]                         */
  } b;                                        /*!< bit fields for mac_bt_clk_latch */
} mac_bt_clk_latch_t, *pmac_bt_clk_latch_t;

/**
  \brief Union type to access mac_mac_version (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) MAC HW Version Number                                      */

  struct {
    __IM  uint32_t version    : 32;           /*!< [31..0] MAC HW version number                                             */
  } b;                                        /*!< bit fields for mac_mac_version */
} mac_mac_version_t, *pmac_mac_version_t;

/**
  \brief Union type to access mac_rssi (@ 0x00000058).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000058) Base Band RSSI Value Register                              */

  struct {
    __IM  uint32_t rssi       : 16;           /*!< [15..0] The BB RSSI value                                                 */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_rssi */
} mac_rssi_t, *pmac_rssi_t;

/**
  \brief Union type to access mac_tx_term_sts (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) TX Termed (Lost PHY Grant) Status Register                 */

  struct {
    __IM  uint32_t zbrf_gts2_tx_termed : 1;   /*!< [0..0] to indicates the GTS2 FIFO TX is finished due to PHY
                                                   grant is terminated (PHY is granted to BLE)                               */
    __IM  uint32_t zbrf_gts1_tx_termed : 1;   /*!< [1..1] to indicates the GTS1 FIFO TX is finished due to PHY
                                                   grant is terminated (PHY is granted to BLE) or due to the
                                                   header length is 0 for a secure TX                                        */
    __IM  uint32_t zbrf_normal_tx_termed : 1; /*!< [2..2] to indicates the Normal FIFO TX is finished due to PHY
                                                   grant is terminated (PHY is granted to BLE) or due to the
                                                   header length is 0 for a secure TX                                        */
    __IM  uint32_t zbrf_beacon_tx_termed : 1; /*!< [3..3] to indicates the Beacon FIFO TX is finished due to PHY
                                                   grant is terminated (PHY is granted to BLE)                               */
          uint32_t            : 28;
  } b;                                        /*!< bit fields for mac_tx_term_sts */
} mac_tx_term_sts_t, *pmac_tx_term_sts_t;

/**
  \brief Union type to access mac_rfctl (@ 0x00000060).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000060) RF Mode Control Register                                   */

  struct {
    __IOM uint32_t rfrxmode   : 1;            /*!< [0..0] Force RX Mode: 0: (default) Normal operation of RX mode;
                                                   1: RF state machine is forced to RX mode;                                 */
    __IOM uint32_t rftxmode   : 1;            /*!< [1..1] Force TX Mode: 0: (default) Normal operation of TX mode;
                                                   1: RF state machine is forced to TX mode;                                 */
    __IOM uint32_t rfrst      : 1;            /*!< [2..2] RF State Machine Reset: 0: Normal operation of RF state
                                                   machine; 1: (default) Hold RF state machine in Reset;                     */
          uint32_t            : 29;
  } b;                                        /*!< bit fields for mac_rfctl */
} mac_rfctl_t, *pmac_rfctl_t;

/**
  \brief Union type to access mac_wakeup_remaincnt (@ 0x00000064).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000064) Wakeup Remain Counter Register                             */

  struct {
    __IOM uint32_t remcnt     : 16;           /*!< [15..0] In the system wakeup procedure, the Remain Counter to
                                                   wait to switch to high speed clock                                        */
    __IOM uint32_t wakecnt    : 9;            /*!< [24..16] System Clock Recovery Time. The time to wait system
                                                   resume from sleep.                                                        */
          uint32_t            : 7;
  } b;                                        /*!< bit fields for mac_wakeup_remaincnt */
} mac_wakeup_remaincnt_t, *pmac_wakeup_remaincnt_t;

/**
  \brief Union type to access mac_wakeup_maincnt (@ 0x00000068).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000068) Wakeup Main Counter Control Register                       */

  struct {
    __IOM uint32_t maincnt    : 26;           /*!< [25..0] Main Counter. Main counter is a 26-bit counter for sleep
                                                   time counting. Units: Sleep Clock Period                                  */
    __OM  uint32_t startcnt   : 1;            /*!< [26..26] Start Sleep Counters. 1 = Trigger sleep for Non-beacon
                                                   mode (BO = 0b1111 and Slotted = 0b0). Bit is automatically
                                                   cleared to '0' by hardware                                                */
    __IOM uint32_t regwake    : 1;            /*!< [27..27] Register Triggered Wake-up Signal: 1: To wake up MAC.
                                                   Bit is automatically cleared to '0' by hardware.                          */
    __IOM uint32_t immwake    : 1;            /*!< [28..28] Immediate Wake-up Mode Enable: 0: (default) Disable
                                                   Immediate Wake-up mode; 1: Enable Immediate Wake-up mode                  */
          uint32_t            : 2;
    __OM  uint32_t slpack     : 1;            /*!< [31..31] Sleep Acknowledgement. Place the MAC to Power Saving
                                                   Mode. Bit is automatically cleared to '0' by hardware                     */
  } b;                                        /*!< bit fields for mac_wakeup_maincnt */
} mac_wakeup_maincnt_t, *pmac_wakeup_maincnt_t;

/**
  \brief Union type to access mac_wakeup_waketime (@ 0x0000006C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000006C) Wakeup Time Match Register                                 */

  struct {
    __IOM uint32_t waketime   : 11;           /*!< [10..0] Wake Time Match Value: WAKETIME is an 11-bit value.
                                                   In sleep mode, when the Main Counter is down counting to
                                                   the value of WAKETIME, the 32 MHz main oscillator will
                                                   start to be recovered. Note that the value of WAKETIME
                                                   has to be greater than that of WAKECNT.                                   */
          uint32_t            : 21;
  } b;                                        /*!< bit fields for mac_wakeup_waketime */
} mac_wakeup_waketime_t, *pmac_wakeup_waketime_t;

/**
  \brief Union type to access mac_dbgport_sel (@ 0x00000090).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000090) TX/RX Machine Debug Port Selection Control Register        */

  struct {
    __IOM uint32_t gr_dbg_sel_o : 4;          /*!< [3..0] Debug Port mux sel: 0: zb_rf_debug_out; 1: txm_fc_debug_out;
                                                   2: rxm_debug_out; 3: src_debug_out; 4: secure; 5: TXM CSMA;
                                                   6: reserved; 7: short register; 8: txm_gts; 9 ~ 15 : Reserved             */
    __IOM uint32_t gr_dbg_rxm_sel_o : 1;      /*!< [4..4] Debug Rxm mux sel, 0: dbg_rxm_fifo; 1: dbg_rxm_fsm                 */
    __IOM uint32_t gr_dbg_cnt_reset_o : 1;    /*!< [5..5] FW can write 1 this bit to reset all debug counter as
                                                   0. HW will automatically clear this bit.                                  */
    __IOM uint32_t gr_dbg_src_sel_o : 1;      /*!< [6..6] Debug Src Match filter mux sel: 0: dbg_src_ctrl; 1: dbg_src_entry  */
          uint32_t            : 25;
  } b;                                        /*!< bit fields for mac_dbgport_sel */
} mac_dbgport_sel_t, *pmac_dbgport_sel_t;

/**
  \brief Union type to access mac_dbg_reg0 (@ 0x00000094).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000094) Debug Register 0                                           */

  struct {
          uint32_t            : 8;
    __IM  uint32_t sh_back    : 8;            /*!< [15..8] the backoff random number of TXM. FW can get pseudo
                                                   random number from this register for a SW level TX backoff
                                                   or key generation.                                                        */
    __IM  uint32_t dbg_rxm_frm_end_cnt : 16;  /*!< [31..16] number of times a Frame end occurs for debugging                 */
  } b;                                        /*!< bit fields for mac_dbg_reg0 */
} mac_dbg_reg0_t, *pmac_dbg_reg0_t;

/**
  \brief Union type to access mac_rxm_dbg (@ 0x00000098).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000098) RXM Debug Register                                         */

  struct {
    __IM  uint32_t dbg_crc_ok_cnt : 16;       /*!< [15..0] number of times of received frame with CRC OK occurs
                                                   for debugging                                                             */
    __IM  uint32_t dbg_discard_cnt : 16;      /*!< [31..16] number of times of receiving pkt discarded occurs for
                                                   debugging                                                                 */
  } b;                                        /*!< bit fields for mac_rxm_dbg */
} mac_rxm_dbg_t, *pmac_rxm_dbg_t;

/**
  \brief Union type to access mac_sf_order_ctrl (@ 0x00000300).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000300) Superframe Order Control Register                          */

  struct {
    __IOM uint8_t so          : 4;            /*!< [3..0] Superframe Order (macSuperframeOrder), Specifies the
                                                   length of the active portion of the superframe, including
                                                   the beacon frame: 0000: 0;  ... 1110: 14; 1111: (default);
                                                   The superframe will not be active following the beacon.
                                                   (i.e., no active portion in the superframe)                               */
    __IOM uint8_t bo          : 4;            /*!< [7..4] Beacon Order (macBeaconOrder), Specifies how often the
                                                   coordinator will transmit a beacon: 0000: 0;  ... 1110:
                                                   14; 1111: (default) The coordinator will not transmit a
                                                   beacon and the Superframe Order (SO)                                      */
  } b;                                        /*!< bit fields for mac_sf_order_ctrl */
} mac_sf_order_ctrl_t, *pmac_sf_order_ctrl_t;

/**
  \brief Union type to access mac_min_lifs (@ 0x00000301).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000301) Minimum LIFS Configuration Register                        */

  struct {
    __IOM uint8_t milp        : 6;            /*!< [5..0] aMinLIFSPeriod, 40 symbols, need to take care txpe turn
                                                   on period (max. 7 symbols). For unslotted CSMA-CA and GTS
                                                   to guarantee IFS period.                                                  */
          uint8_t             : 2;
  } b;                                        /*!< bit fields for mac_min_lifs */
} mac_min_lifs_t, *pmac_min_lifs_t;

/**
  \brief Union type to access mac_ifs_ctrl (@ 0x00000302).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000302) Inter Frame Space Control Register                         */

  struct {
    __IOM uint16_t misp       : 4;            /*!< [3..0] Minimum Short Interframe Spacing: 0101: (default - Do
                                                   Not Change)                                                               */
    __IOM uint16_t txpet      : 4;            /*!< [7..4] VCO Settling Time: 0101: (default - Do Not Change);                */
    __IOM uint16_t ccachkp    : 4;            /*!< [11..8] The time for CCA check point Ccachkp 0x8 is recommended           */
    __IOM uint16_t aturn      : 4;            /*!< [15..12] ACK turnaround time after receiving a packet. Minimum
                                                   value is 0x2. In unit of 16us (a symbol time)                             */
  } b;                                        /*!< bit fields for mac_ifs_ctrl */
} mac_ifs_ctrl_t, *pmac_ifs_ctrl_t;

/**
  \brief Union type to access mac_tx_ctrl (@ 0x00000304).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000304) TX Control Register                                        */

  struct {
          uint32_t            : 16;
    __IOM uint32_t pend       : 1;            /*!< [16..16] Pending bit in ACK header                                        */
    __IOM uint32_t indirect   : 1;            /*!< [17..17] Activate Indirect Transmission bit (coordinator only):
                                                   0: (default) Indirect transmission disabled; 1: Indirect
                                                   transmission enabled                                                      */
          uint32_t            : 6;
    __IOM uint32_t mawd       : 7;            /*!< [30..24] The maximum number of symbols to wait for an acknowledgment
                                                   frame to arrive following a transmitted data frame. This
                                                   value is dependent on the currently selected logical channel
                                                   For 0 <= phyCurrentChannel <= 10, this value is equal to
                                                   120. For 11 <= phyCurrentChannel <= 26, this value is equal
                                                   to 54.Consider the timing align issue, suggest use 0x39                   */
          uint32_t            : 1;
  } b;                                        /*!< bit fields for mac_tx_ctrl */
} mac_tx_ctrl_t, *pmac_tx_ctrl_t;

/**
  \brief Union type to access mac_beacon_ctrl (@ 0x00000308).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000308) Beacon Control Register                                    */

  struct {
    __IOM uint32_t intl       : 6;            /*!< [5..0] Interval to Start Beacon: The timing interval between
                                                   slotted mode triggered (set by REG0x300[7:4]) and the first
                                                   time to send beacon frame: 000000: 0 (default); 000011:
                                                   3 (optimized - Do Not Change); in unit of symbol time                     */
          uint32_t            : 10;
    __IOM uint32_t aoffset    : 8;            /*!< [23..16] Offset to Align Beacon Boundary. Superframe counter
                                                   offset to align with beacon boundary. Alignment will happen
                                                   whenever a beacon is received. Only for device mode: 00000000:
                                                   (default); 00010101: (optimized - Do Not Change) in unit
                                                   of symbol time                                                            */
          uint32_t            : 8;
  } b;                                        /*!< bit fields for mac_beacon_ctrl */
} mac_beacon_ctrl_t, *pmac_beacon_ctrl_t;

/**
  \brief Union type to access mac_txm_state (@ 0x0000030C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000030C) TX State Machine Status Register                           */

  struct {
    __IM  uint32_t txm_mac_state : 5;         /*!< [4..0] txm_mac_state: MAC state machine for debug use                     */
    __IM  uint32_t txm_busn_state : 2;        /*!< [6..5] Normal packet fifo bus state for debug use                         */
    __IM  uint32_t txm_busb_state : 2;        /*!< [8..7] Beacon fifo bus state for debug use                                */
    __IM  uint32_t txm_busg1_state : 2;       /*!< [10..9] GTS fifo1 bus state for debug use                                 */
    __IM  uint32_t txm_busg2_state : 2;       /*!< [12..11] GTS fifo2 bus state for debug use                                */
    __IM  uint32_t cfp_state  : 3;            /*!< [15..13] GTS state in CFP for debug use                                   */
    __IM  uint32_t csma_state : 5;            /*!< [20..16] TXM CSMA state for debug use                                     */
    __IM  uint32_t sf_state   : 3;            /*!< [23..21] superframe structure state for debug use                         */
    __IM  uint32_t rf_mode_state : 4;         /*!< [27..24] RF mode state for debug use                                      */
    __IM  uint32_t gts_state  : 4;            /*!< [31..28] GTS state machine for debug use                                  */
  } b;                                        /*!< bit fields for mac_txm_state */
} mac_txm_state_t, *pmac_txm_state_t;

/**
  \brief Union type to access mac_txb_trig (@ 0x00000310).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000310) Beacon TX FIFO Trigger Control Register                    */

  struct {
    __IOM uint8_t txbcntrig   : 1;            /*!< [0..0] Transmit Frame in TX Beacon FIFO bit: 1: Transmit the
                                                   frame in the TX Beacon FIFO; bit is automatically cleared
                                                   by hardware.                                                              */
    __IOM uint8_t txbsecen    : 1;            /*!< [1..1] TX Beacon FIFO Security Enabled bit: 0: (default) Security
                                                   disabled; 1: Security enabled                                             */
          uint8_t             : 6;
  } b;                                        /*!< bit fields for mac_txb_trig */
} mac_txb_trig_t, *pmac_txb_trig_t;

/**
  \brief Union type to access mac_txn_trig (@ 0x00000311).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000311) Normal TX FIFO Trigger Control Register                    */

  struct {
    __IOM uint8_t txntrig     : 1;            /*!< [0..0] Transmit Frame in TX Normal FIFO bit: 1: Transmit the
                                                   frame in the TX Normal FIFO. Bit is automatically cleared
                                                   to '0' by hardware.                                                       */
    __IOM uint8_t txnsecen    : 1;            /*!< [1..1] TX Normal FIFO Security Enabled bit: 0: (default) Security
                                                   disabled; 1: Security enabled;                                            */
    __IOM uint8_t txnackreq   : 1;            /*!< [2..2] TX Normal FIFO Acknowledgement Request bit. Transmit
                                                   a packet with Acknowledgement request. If Acknowledgement
                                                   is not received, theMAC HW retransmits up to TXNFRMTRY
                                                   times: 0: (default) No Acknowledgement packet requested;
                                                   1: Acknowledgement packet requested                                       */
    __IOM uint8_t ack_type    : 1;            /*!< [3..3] the ACK frame version for the TXM should wait: 0: (default)
                                                   Imm-Ack; 1: Enh-Ack; The firmware should according to the
                                                   frame version of the frame is going to be transmitted to
                                                   fill this bit's value                                                     */
          uint8_t             : 1;
    __IOM uint8_t txnfrmtry   : 3;            /*!< [7..5] normal fifo max retry times                                        */
  } b;                                        /*!< bit fields for mac_txn_trig */
} mac_txn_trig_t, *pmac_txn_trig_t;

/**
  \brief Union type to access mac_txg1_trig (@ 0x00000312).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000312) GTS1 TX FIFO Trigger Control Register                      */

  struct {
    __IOM uint8_t txg1trig    : 1;            /*!< [0..0] Transmit Frame in TX GTS1 FIFO: 1: Transmit the frame
                                                   in the TX GTS1 FIFO. Bit is automatically cleared to '0'
                                                   by hardware                                                               */
    __IOM uint8_t txg1secen   : 1;            /*!< [1..1] TX GTS1 FIFO Security Enabled: 0: (default) Security
                                                   disabled; 1: Security enabled                                             */
    __IOM uint8_t txg1ackreq  : 1;            /*!< [2..2] TX GTS1 FIFO Acknowledgement Request. Transmit a packet
                                                   with Acknowledgement request. If Acknowledgement is not
                                                   received, theMAC HW retransmits up to the times set by
                                                   txg1ifetry(Reg 0x312[7:6]): 0: (default) Acknowledgement
                                                   Request disabled; 1: Acknowledgement Request enabled                      */
    __IOM uint8_t txg1slot    : 3;            /*!< [5..3] GTS Slot that GTS1 FIFO Occupies: 000: 0 (default);
                                                   ... 111: 7                                                                */
    __IOM uint8_t txg1ifetry  : 2;            /*!< [7..6] GTS1 FIFO Retry Times. Set the limit of retry times of
                                                   the packet: 00: 0;  ... 11: 3 (default)                                   */
  } b;                                        /*!< bit fields for mac_txg1_trig */
} mac_txg1_trig_t, *pmac_txg1_trig_t;

/**
  \brief Union type to access mac_txg2_trig (@ 0x00000313).
*/
typedef union {
  __IOM uint8_t w;                            /*!< (@ 0x00000313) GTS2 TX FIFO Trigger Control Register                      */

  struct {
    __IOM uint8_t txg2trig    : 1;            /*!< [0..0] Transmit Frame in TX GTS2 FIFO: 1: Transmit the frame
                                                   in the TX GTS2 FIFO. Bit is automatically cleared to '0'
                                                   by hardware                                                               */
    __IOM uint8_t txg2secen   : 1;            /*!< [1..1] TX GTS2 FIFO Security Enabled: 0: (default) Security
                                                   disabled; 1: Security enabled;                                            */
    __IOM uint8_t txg2ackreq  : 1;            /*!< [2..2] TX GTS2 FIFO Acknowledgement Request. Transmit a packet
                                                   with Acknowledgement request. If Acknowledgement is not
                                                   received, the MAC HW retransmits up to the times set by
                                                   txg2ifetry (Reg 0x313[7:6]) 0: (default) Acknowledgement
                                                   Request disabled; 1: Acknowledgement Request enabled;                     */
    __IOM uint8_t txg2slot    : 3;            /*!< [5..3] GTS Slot that GTS2 FIFO Occupies: 000: 0 (default);
                                                   ... 111: 7                                                                */
    __IOM uint8_t txg2ifetry  : 2;            /*!< [7..6] GTS2 FIFO Retry Times. Set the limit of retry times of
                                                   the packet: 00: 0;  ... 11: 3 (default)                                   */
  } b;                                        /*!< bit fields for mac_txg2_trig */
} mac_txg2_trig_t, *pmac_txg2_trig_t;

/**
  \brief Union type to access mac_txm_status (@ 0x00000314).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000314) TX Machine Status Register                                 */

  struct {
    __IM  uint32_t sfcntr     : 24;           /*!< [23..0] Superframe counter value                                          */
    __IM  uint32_t txg1retryn : 2;            /*!< [25..24] The number of retry times of the latest successfully
                                                   transmitted packet on GTS1 FIFO.                                          */
    __IM  uint32_t txg2retryn : 2;            /*!< [27..26] The number of retry times of the latest successfully
                                                   transmitted packet on GTS2 FIFO.                                          */
    __IM  uint32_t pendack    : 1;            /*!< [28..28] Frame Pending Status bit. Status of the frame pending
                                                   bit in the received Acknowledgement frame: 0: (default)
                                                   Frame pending bit = 0; 1: Frame pending bit = 1                           */
          uint32_t            : 3;
  } b;                                        /*!< bit fields for mac_txm_status */
} mac_txm_status_t, *pmac_txm_status_t;

/**
  \brief Union type to access mac_gts_ctrl (@ 0x00000318).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000318) GTS FIFO TX Control Register                               */

  struct {
    __IOM uint32_t enh_ack_trig : 1;          /*!< [0..0] Enh-Ack TX trigger. FW set this bit to trigger the Enh-Ack
                                                   frame which is prepared in the GTS1 TX FIFO. MAC HW will
                                                   start the Enh-Ack frame transmission at the time of rxif
                                                   + gts_enh_ack_timer + rx2tx_enh_ack_delay. To prevent the
                                                   FW set this bit too late or at inproper time, this bit
                                                   is available to write only in the time window from rxif
                                                   to (rxif + gts_enh_ack_timer)                                             */
    __IOM uint32_t sec_enh_ack : 1;           /*!< [1..1] enable the encryption of Enh-Ack frame. The value of
                                                   this bit will be copied to txg1secen when the Enh-Ack frame
                                                   (GTS1) TX is triggered.                                                   */
    __IOM uint32_t gtsswitch  : 1;            /*!< [2..2] Continue TX GTS FIFO Switch: 0: (default) GTS1 and GTS2
                                                   FIFO will stop toggling with each other if the transmission
                                                   fails; 1: GTS1 and GTS2 FIFO will toggle with each other                  */
    __IOM uint32_t nocsmag    : 1;            /*!< [3..3] Carrier Sense Multiple Access with Collision Avoidance
                                                   (CSMA-CA) for TX GTS FIFO: 0: (default) Enable CSMA-CA
                                                   for TX GTS FIFO; 1: Disable CSMA-CA for TX GTS FIFO;                      */
    __IOM uint32_t cap        : 4;            /*!< [7..4] End Slot of Contention Access Period (CAP): 0000: 0 (default);
                                                   ... 1111: 15                                                              */
    __IOM uint32_t gts1       : 4;            /*!< [11..8] End Slot of 1st GTS: 0000: 0 (default);  ... 1111: 15             */
    __IOM uint32_t gts2       : 4;            /*!< [15..12] End Slot of 2nd GTS: 0000: 0 (default);  ... 1111:
                                                   15;                                                                       */
    __IOM uint32_t gts3       : 4;            /*!< [19..16] End Slot of 3rd GTS: 0000: 0 (default) ;  ... 1111:
                                                   15;                                                                       */
    __IOM uint32_t gts4       : 4;            /*!< [23..20] End Slot of 4th GTS: 0000: 0 (default);  ... 1111:
                                                   15;                                                                       */
    __IOM uint32_t gts5       : 4;            /*!< [27..24] End Slot of 5th GTS: 0000: 0 (default);  ... 1111:
                                                   15;                                                                       */
    __IOM uint32_t gts6       : 4;            /*!< [31..28] End Slot of 6th GTS: 0000: 0 (default);  ... 1111:
                                                   15; If 7th GTS exists, the end slot must be 15.                           */
  } b;                                        /*!< bit fields for mac_gts_ctrl */
} mac_gts_ctrl_t, *pmac_gts_ctrl_t;

/**
  \brief Union type to access mac_csma_ctrl (@ 0x0000031C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000031C) CSMA Control and Status Register                           */

  struct {
    __IM  uint32_t csma_cw    : 2;            /*!< [1..0] the contention window length in the CSMA-CA algorithm              */
    __IM  uint32_t csma_be    : 4;            /*!< [5..2] the backoff exponent in the CSMA-CA algorithm                      */
    __IM  uint32_t csma_nb    : 4;            /*!< [9..6] the number of times required to backoff in the CSMA-CA
                                                   algorithm                                                                 */
    __IM  uint32_t txretry    : 3;            /*!< [12..10] TX Normal FIFO Retry Times. Number of retrys of the
                                                   most recent TX Normal FIFO transmission: 00: 0 (default);
                                                   ... 111: 7;                                                               */
          uint32_t            : 2;
    __IOM uint32_t nocsman    : 1;            /*!< [15..15] Carrier Sense Multiple Access with Collision Avoidance
                                                   (CSMA-CA) for TX Normal FIFO: 0: (default) Enable CSMA-CA
                                                   for TX normal FIFO; 1: Disable CSMA-CA for TX normal FIFO                 */
    __IOM uint32_t macminbe   : 4;            /*!< [19..16] MAC Minimum Backoff Exponent (macMinBE). The minimum
                                                   value of the backoff exponent in the CSMA-CA algorithm:
                                                   0000: Collision avoidance is disabled; 0011: 3 (default)                  */
    __IOM uint32_t macmaxbe   : 4;            /*!< [23..20] MAC Maximal Backoff Exponent (macMaxBE). The maximal
                                                   value of the backoff exponent in the CSMA-CA algorithm:
                                                   0000: Collision avoidance is disabled; 0101: 5 (default)                  */
    __IOM uint32_t csmabf     : 4;            /*!< [27..24] Maximum CSMA Backoff (macMaxCSMABackoff). The maximum
                                                   number of backoffs the CSMA-CA algorithm will attempt before
                                                   declaring a hannel access failure, default value is 4.                    */
    __IOM uint32_t slotted    : 1;            /*!< [28..28] Slotted CSMA-CA Mode: 0: (default) Disable Slotted
                                                   CSMA-CA mode; 1: Enable Slotted CSMA-CA mode;                             */
    __IOM uint32_t batlifeext : 1;            /*!< [29..29] Battery Life Extention Mode: 0: (default) Disable Battery
                                                   Life Extention Mode; 1: Enable Battery Life Extention Mode                */
    __IOM uint32_t backoff_nb_gain : 2;       /*!< [31..30] Gain of csma_nb for next backoff periods increas, the
                                                   new(next) backoff periods is backoff_p + backoff_nb_gain
                                                   * csma_nb, backoff_p = (random(2^be -1); 00: periods is
                                                   backoff_p; 01: periods is backoff_p + csma_nb; 10: periods
                                                   is backoff_p + 2*csma_nb; 11: periods is backoff_p + 3*csma_nb;           */
  } b;                                        /*!< bit fields for mac_csma_ctrl */
} mac_csma_ctrl_t, *pmac_csma_ctrl_t;

/**
  \brief Union type to access mac_tx_settle_ctrl (@ 0x00000320).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000320) TX Settling Time Control Register                          */

  struct {
    __IOM uint32_t txont      : 9;            /*!< [8..0] TX Settling Time 0. Transmitter settling time to begin
                                                   packet transmission. TXONT is a 9-bit value. 0101000: (default
                                                   - Do Not Change)                                                          */
    __IOM uint32_t txonts     : 4;            /*!< [12..9] TX Settling Time 1. Transmitter settling time to begin
                                                   packet transmission:0010: (default); 0101: (optimized -
                                                   Do Not Change)                                                            */
          uint32_t            : 3;
    __IOM uint32_t pacont     : 9;            /*!< [24..16] Power Amplifier Settling Time 0. Power amplifier settling
                                                   time to begin packet transmission. PACONT is a 9-bit value.
                                                   00101001: (default - Do Not Change)                                       */
    __IOM uint32_t paonts     : 4;            /*!< [28..25] Power Amplifier Settling Time 1. Power amplifier settling
                                                   time to begin packet transmission: 0001: (default); 0100:
                                                   (optimized - Do Not Change)                                               */
          uint32_t            : 3;
  } b;                                        /*!< bit fields for mac_tx_settle_ctrl */
} mac_tx_settle_ctrl_t, *pmac_tx_settle_ctrl_t;

/**
  \brief Union type to access mac_tx_frm_len_err (@ 0x00000324).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000324) TX Frame Length Error Status Register                      */

  struct {
    __IM  uint32_t txg2lerr   : 1;            /*!< [0..0] Indicates the error of packet in GTSFIFO2 with the frame
                                                   length is zero for TX or the header length is 0 for encryption            */
    __IM  uint32_t txg1lerr   : 1;            /*!< [1..1] Indicates the error of packet in GTSFIFO1 with the frame
                                                   length is zero for TX or the header length is 0 for encryption            */
    __IM  uint32_t txnlerr    : 1;            /*!< [2..2] Indicates the error of packet in TX Normal FIFO with
                                                   the frame length is zero for TX or the header length is
                                                   0 for encryption                                                          */
    __IM  uint32_t txblerr    : 1;            /*!< [3..3] Indicates the error of packet in Beacon FIFO with the
                                                   frame length is zero for TX or the header length is 0 for
                                                   encryption                                                                */
          uint32_t            : 28;
  } b;                                        /*!< bit fields for mac_tx_frm_len_err */
} mac_tx_frm_len_err_t, *pmac_tx_frm_len_err_t;

/**
  \brief Union type to access mac_txsr (@ 0x00000328).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000328) TX Status Register                                         */

  struct {
    __IM  uint32_t txns       : 1;            /*!< [0..0] Normal FIFO Release Status: 0: (default) Succeeded; 1:
                                                   Fail, retry count exceed or TX is termed (lost PHY grant)                 */
    __IM  uint32_t txg1s      : 1;            /*!< [1..1] GTS1 FIFO Release Status: 0: (default) Succeeded; 1:
                                                   Fail, retry count exceed or TX is termed (lost PHY grant)                 */
    __IM  uint32_t txg2s      : 1;            /*!< [2..2] GTS2 FIFO Release Status: 0: (default) Succeeded; 1:
                                                   Fail, retry count exceed or TX is termed(lost PHY grant)                  */
    __IM  uint32_t txg1fnt    : 1;            /*!< [3..3] GTS1 FIFO Transmission Status: 0: (default) Succeeded;
                                                   1: Fail, no enough time to transmit before the end of a
                                                   GTS or TX is termed (lost PHY grant)                                      */
    __IM  uint32_t txg2fnt    : 1;            /*!< [4..4] GTS2 FIFO Transmission Status: 0: (default) Succeeded;
                                                   1: Fail, no enough time to transmit before the end of a
                                                   GTS or TX is termed (loat PHY grant)                                      */
    __IM  uint32_t ccafail    : 1;            /*!< [5..5] Clear Channel Assessment (CCA) Status of Last Transmission:
                                                   0: (default) Channel Idle; 1: Channel busy                                */
          uint32_t            : 26;
  } b;                                        /*!< bit fields for mac_txsr */
} mac_txsr_t, *pmac_txsr_t;

/**
  \brief Union type to access mac_tx_time_stamp (@ 0x00000330).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000330) Frame TX Timestamp Register                                */

  struct {
    __IM  uint32_t txm_tx_timestmp_clk : 22;  /*!< [21..0] the BT native clock(BT NativeClock[22:1]) of TX timestamp,
                                                   which is latched at the 1st symbol of the MAC Header (Frame
                                                   Control) transmitting is started                                          */
    __IM  uint32_t txm_tx_timestmp_cntr : 10; /*!< [31..22] the BT clock counter of TX timestamp, which is latched
                                                   at the 1st symbol of the MAC Header (Frame Control) transmitting
                                                   is started                                                                */
  } b;                                        /*!< bit fields for mac_tx_time_stamp */
} mac_tx_time_stamp_t, *pmac_tx_time_stamp_t;

/**
  \brief Union type to access mac_tx_given_time_set (@ 0x00000334).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000334) BT Time Comparator for TX Trigger Time Control
                                                                  Register                                                   */

  struct {
    __IOM uint32_t txn_nclk   : 18;           /*!< [17..0] The native clock value of the BT-MAC timer comparator
                                                   for FW to setup the MAC time to trigger the normal TX FIFO
                                                   transmission. When the (BT NativeClock[18:1] || ClockCounter[9:0])
                                                   value is matched with (txn_nclk || txn_ckc) then trigger
                                                   the normal TX FIFO transmission.                                          */
    __IOM uint32_t txn_ckc    : 10;           /*!< [27..18] The clock counter value of the BT-MAC timer comparator
                                                   for FW to setup the MAC time to trigger the normal TX FIFO
                                                   transmission. When the BT-MAC timer value is matched with
                                                   (txn_nclk || txn_ckc) then trigger the normal TX FIFO transmission.       */
    __IOM uint32_t schtxnocca : 1;            /*!< [28..28] To indicate whether the MAC TX machine should do CCA
                                                   to acquire the channel for Schedule TX mode transmissions:
                                                   0: The MAC TX machine should do CCA for the Scheduled TX
                                                   mode transmission; 1: The MAC TX machine do NOT do CCA
                                                   for the Scheduled TX mode transmission. The HW should re-latch
                                                   this bit on txntmren is set.                                              */
          uint32_t            : 2;
    __IOM uint32_t txntmren   : 1;            /*!< [31..31] BT-MAC Timer comparator for normal FIFO TX time enable
                                                   control: 0: Disable the BT-MAC Timer comparator which will
                                                   trigger the normal FIFO transmission; 1: Enable the BT-MAC
                                                   Timer comparator which will trigger the normal FIFO transmission.The
                                                   FW should fill the normal TX FIFO with the frame to be
                                                   transmitted, setup the TX Time comparator value and the
                                                   TX option (with CCA or not) before enable this Timer comparator.The
                                                   TX machine should clear this bit once the BT-MAC timer
                                                   value is matched with (txn_                                               */
  } b;                                        /*!< bit fields for mac_tx_given_time_set */
} mac_tx_given_time_set_t, *pmac_tx_given_time_set_t;

/**
  \brief Union type to access mac_tx_given_time_status (@ 0x00000338).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000338) Given Time TX Status Register                              */

  struct {
    __IM  uint32_t zbrf_tx_given_time_encoun_tx : 1;/*!< [0..0] to report the TX at given time procedure is conflict
                                                   with another TX process. 1 means this conflict is happened.               */
    __IM  uint32_t zbrf_tx_given_time_encoun_rx : 1;/*!< [1..1] to report the TX at given time procedure is conflict
                                                   with a RX process. 1 means this conflict is happened.                     */
    __IM  uint32_t zbrf_tx_given_time_obsolete : 1;/*!< [2..2] to report the TX at given time procedure is failed due
                                                   to the specified TX trigger time is past or it has no enough
                                                   time to settle PHY.                                                       */
    __IM  uint32_t zbrf_tx_given_time_not_gnt : 1;/*!< [3..3] to report the TX at given time procedure is failed due
                                                   to the PHY is not granted at the specified TX trigger time.               */
    __IM  uint32_t zbrf_tx_given_time_not_in_recv : 1;/*!< [4..4] to report the TX at given time procedure is failed due
                                                   to the PHY is not ready (in RX state) at the specified
                                                   TX trigger time. This case normaly is caused by the scheduled
                                                   TX is triggered when the PHY is re-granted and still in
                                                   PHY re-initialization.                                                    */
          uint32_t            : 27;
  } b;                                        /*!< bit fields for mac_tx_given_time_status */
} mac_tx_given_time_status_t, *pmac_tx_given_time_status_t;

/**
  \brief Union type to access mac_gts_slot_cfg (@ 0x0000033C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000033C) GTS Slots Configuration Register                           */

  struct {
    __IOM uint32_t gts_slot_en : 7;           /*!< [6..0] GTS slot enable control, bit 0 ~ 6 correspond to GTS
                                                   slot 1 ~7: 0: disable the corresponding GTS slot (default)1:
                                                   enable the corresponding GTS slot                                         */
          uint32_t            : 1;
    __IOM uint32_t gts_slot_trx : 7;          /*!< [14..8] GTS slot TX/RX configuration, bit 0 ~ 6 correspond to
                                                   GTS slot 1 ~7: 0: configure the corresponding GTS slot
                                                   for RX1: configure the corresponding GTS slot for TX                      */
          uint32_t            : 17;
  } b;                                        /*!< bit fields for mac_gts_slot_cfg */
} mac_gts_slot_cfg_t, *pmac_gts_slot_cfg_t;

/**
  \brief Union type to access mac_rx_fltr_ctrl (@ 0x00000380).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000380) RX Filter Control Register                                 */

  struct {
    __IOM uint32_t promi      : 1;            /*!< [0..0] Accept all packets with CRC OK                                     */
    __IOM uint32_t errpkt     : 1;            /*!< [1..1] Accept all kinds of pkt(including CRC error)                       */
    __IOM uint32_t scanmode   : 1;            /*!< [2..2] enable RX Filter scan mode. When scan mode is enabled,
                                                   only Beacon frame with FCS correct will be accepted by
                                                   RX filter.                                                                */
    __IOM uint32_t group_rxmode : 1;          /*!< [3..3] macGroupRxMode Enable. When group RX mode is enabled,
                                                   frames with EUI-64 group address as its destination address
                                                   are accepted by RX filter.                                                */
    __IOM uint32_t implicit_broadcast : 1;    /*!< [4..4] RX Filter macImplicitBroadcast Enable. When implicit
                                                   broadcast mode is enabled, frames without destination address
                                                   are accepted by RX filter                                                 */
    __IOM uint32_t rf_early_term : 1;         /*!< [5..5] Enable the PHY RX early term for RX packet discard:1:
                                                   enable the PHY RX early term for power saving. The RX will
                                                   be truned off for the period of RX discarded frame transmission;
                                                   0: disable the PHY RX early term                                          */
    __IOM uint32_t frm06_rx_early : 1;        /*!< [6..6] Enable the RX early interrupt for non-secure 2006 frame:
                                                   0 : RX early interrupt will be asserted for receiving 2006
                                                   Security Frame or all 2015 Frame excluding ack frame type;
                                                   1 : RX early interrupt will be asserted for all receiving
                                                   frame, including 2006 non-secure frame, excluding ack frame
                                                   type                                                                      */
          uint32_t            : 1;
    __IOM uint32_t rxm_force_crc : 1;         /*!< [8..8] Force RXM Received CRC result is error: 0: (default)
                                                   Force CRC error disabled; 1: Force CRC error enabled For
                                                   MAC function test purpose                                                 */
          uint32_t            : 23;
  } b;                                        /*!< bit fields for mac_rx_fltr_ctrl */
} mac_rx_fltr_ctrl_t, *pmac_rx_fltr_ctrl_t;

/**
  \brief Union type to access mac_rxfrmtype (@ 0x00000384).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000384) RX Frame Type Filter Control Register                      */

  struct {
    __IOM uint32_t rxftype    : 8;            /*!< [7..0] RX Frame Type Filter. 00001011: (default - Do Not Change)Packet
                                                   type field in Frame control byte of IEEE802.15.4 is 3 bits,
                                                   meaning 8 types of packets. Each bit of RXFRM_TYPE correlated
                                                   to the 8 types. When correlated bit is '1', RXMAC receives
                                                   the type of packet without filtering out. bit 0 : 000 (beacon);
                                                   bit 1 : 001 (data); bit 2 : 010 (ack); bit 3 : 011 (command);
                                                   bit 4 : (reserved)bit 5: 101 (multipurpose): bit 6~7 :
                                                   (reserved)                                                                */
    __IOM uint32_t rxftype15  : 8;            /*!< [15..8] RX Frame Type Filter for IEEE802.15.4 version2015. 00001111:
                                                   (default)Packet type field in Frame control byte of IEEE802.15.4
                                                   is 3 bits, meaning 8 types of packets. Each bit of RXFRM_TYPE
                                                   correlated to the 8 types. When correlated bit is '1',
                                                   RXMAC receives the type of packet without filtering out.
                                                   bit 0 : 000 (beacon); bit 1 : 001 (data); bit 2 : 010 (ack);
                                                   bit 3 : 011 (command); bit 4~5 : (reserved); bit 6: 110
                                                   (Fragement or Frak): bit 7: 111 (Extended):                               */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_rxfrmtype */
} mac_rxfrmtype_t, *pmac_rxfrmtype_t;

/**
  \brief Union type to access mac_group_eadr_l (@ 0x00000388).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000388) Group Extended Address Lower Bytes                         */

  struct {
    __IOM uint32_t group_ext_addr_l : 32;     /*!< [31..0] EUI-64 group address lower bits (bits[31:0])                      */
  } b;                                        /*!< bit fields for mac_group_eadr_l */
} mac_group_eadr_l_t, *pmac_group_eadr_l_t;

/**
  \brief Union type to access mac_group_eadr_h (@ 0x0000038C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000038C) Group Extended Address Higher Bytes                        */

  struct {
    __IOM uint32_t group_ext_addr_h : 32;     /*!< [31..0] EUI-64 group address higher bits (bits[63:32])                    */
  } b;                                        /*!< bit fields for mac_group_eadr_h */
} mac_group_eadr_h_t, *pmac_group_eadr_h_t;

/**
  \brief Union type to access mac_assoc_eadr_l (@ 0x00000390).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000390) Associated Coordinator Extended Address Lower
                                                                  Bytes                                                      */

  struct {
    __IOM uint32_t assoeadr_l : 32;           /*!< [31..0] Lower bits(bits[31:0]) of Associated Coordinator's 64-Bit
                                                   Extended Address                                                          */
  } b;                                        /*!< bit fields for mac_assoc_eadr_l */
} mac_assoc_eadr_l_t, *pmac_assoc_eadr_l_t;

/**
  \brief Union type to access mac_assoc_eadr_h (@ 0x00000394).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000394) Associated Coordinator Extended Address Higher
                                                                  Bytes                                                      */

  struct {
    __IOM uint32_t assoeadr_h : 32;           /*!< [31..0] Higher bits(bits[63:32]) of Associated Coordinator's
                                                   64-Bit Extended Address                                                   */
  } b;                                        /*!< bit fields for mac_assoc_eadr_h */
} mac_assoc_eadr_h_t, *pmac_assoc_eadr_h_t;

/**
  \brief Union type to access mac_assoc_sadr (@ 0x00000398).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000398) Associated Coordinator Short Address Low Byte              */

  struct {
    __IOM uint32_t assosadr   : 16;           /*!< [15..0] 16-Bits Short Address of Associated Coordinator                   */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_assoc_sadr */
} mac_assoc_sadr_t, *pmac_assoc_sadr_t;

/**
  \brief Union type to access mac_assoc_bcn_ctrl (@ 0x0000039C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000039C) Association Beacon Source Address Control Register         */

  struct {
    __IOM uint32_t abctrl     : 1;            /*!< [0..0] Associate beacon source address enable. 1: disable; 0:
                                                   enable                                                                    */
          uint32_t            : 31;
  } b;                                        /*!< bit fields for mac_assoc_bcn_ctrl */
} mac_assoc_bcn_ctrl_t, *pmac_assoc_bcn_ctrl_t;

/**
  \brief Union type to access mac_rxm_fch (@ 0x000003A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003A0) Received Frame Control Fields Store Register               */

  struct {
    __IM  uint32_t frame_type : 3;            /*!< [2..0] the frame type of the latest received frame, for debug             */
    __IM  uint32_t sec_en     : 1;            /*!< [3..3] the security enable bit of the latest received frame,
                                                   for debug                                                                 */
    __IM  uint32_t pend       : 1;            /*!< [4..4] the frame pending bit of the latest received frame, for
                                                   debug                                                                     */
    __IM  uint32_t ack_req    : 1;            /*!< [5..5] the ACK request bit of the latest received frame, for
                                                   debug                                                                     */
    __IM  uint32_t panid_comp : 1;            /*!< [6..6] the PAN ID compressed bit of the latest received frame,
                                                   for debug                                                                 */
          uint32_t            : 1;
    __IM  uint32_t seq_comp   : 1;            /*!< [8..8] the sequence number compressed bit of the latest received
                                                   frame, for debug                                                          */
    __IM  uint32_t ie_exist   : 1;            /*!< [9..9] the IE present bit of the latest received frame, for
                                                   debug                                                                     */
    __IM  uint32_t dst_adr_mode : 2;          /*!< [11..10] the destination address mode of the latest received
                                                   frame, for debug00: None; 01: Reserved; 10: 16-bit short
                                                   address; 11: 64-bit extended address                                      */
    __IM  uint32_t frm_ver    : 2;            /*!< [13..12] the frame version of the latest received frame, for
                                                   debug                                                                     */
    __IM  uint32_t src_adr_mode : 2;          /*!< [15..14] the source address mode of the latest received frame:00:
                                                   None; 01: Reserved; 10: 16-bit short address; 11: 64-bit
                                                   extended address                                                          */
    __IM  uint32_t mp_frame_type : 3;         /*!< [18..16] the frame type of the latest received frame, for debug           */
    __IM  uint32_t mp_long_frm : 1;           /*!< [19..19] the Long Frame bit of the latest received MP frame,
                                                   for debug                                                                 */
    __IM  uint32_t mp_dst_adr_mode : 2;       /*!< [21..20] the destination address mode of the latest received
                                                   MP frame, for debug00: None; 01: Reserved; 10: 16-bit short
                                                   address; 11: 64-bit extended address                                      */
    __IM  uint32_t mp_src_adr_mode : 2;       /*!< [23..22] the source address mode of the latest received MP frame,
                                                   for debug00: None; 01: Reserved; 10: 16-bit short address;
                                                   11: 64-bit extended address                                               */
    __IM  uint32_t mp_panid_exist : 1;        /*!< [24..24] indicates whether the PAN ID is present in received
                                                   MP frame, for debug                                                       */
    __IM  uint32_t mp_sec_en  : 1;            /*!< [25..25] the security enable bit of the latest received MP frame,
                                                   for debug                                                                 */
    __IM  uint32_t mp_seq_comp : 1;           /*!< [26..26] the Sequence Number Suppression bit of the latest received
                                                   MP frame, for debug                                                       */
    __IM  uint32_t mp_frm_pend : 1;           /*!< [27..27] the Frame Pending bit of the latest received MP frame,
                                                   for debug                                                                 */
    __IM  uint32_t mp_frm_ver : 2;            /*!< [29..28] the frame version of the latest received MP frame,
                                                   for debug                                                                 */
    __IM  uint32_t mp_ack_req : 1;            /*!< [30..30] the ACK request bit of the latest received MP frame,
                                                   for debug                                                                 */
    __IM  uint32_t rxm_fchmp_ie_exist : 1;    /*!< [31..31] the IE present bit of the latest received mp frame,
                                                   for debug                                                                 */
  } b;                                        /*!< bit fields for mac_rxm_fch */
} mac_rxm_fch_t, *pmac_rxm_fch_t;

/**
  \brief Union type to access mac_rx_sn_ie_update (@ 0x000003A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003A4) Received Frame's Sequence Number and IE Updated
                                                                  Status                                                     */

  struct {
    __IM  uint32_t seq_num    : 8;            /*!< [7..0] the sequence number of the latest received frame, for
                                                   debug                                                                     */
    __IM  uint32_t hdr_ie_term : 1;           /*!< [8..8] MAC HW set this bit to indicated the Header IEs parsing
                                                   is finished (Header Termination IE is detected).                          */
    __IM  uint32_t csl_update : 1;            /*!< [9..9] CSL IE Parser have been update in the transaction which
                                                   will be set to 1. Auto Clear when next Rx reception starts                */
    __IM  uint32_t tc_update  : 1;            /*!< [10..10] Time Correction IE have been update in the transaction
                                                   which will be set to 1. Auto Clear when next Rx reception
                                                   starts.                                                                   */
          uint32_t            : 21;
  } b;                                        /*!< bit fields for mac_rx_sn_ie_update */
} mac_rx_sn_ie_update_t, *pmac_rx_sn_ie_update_t;

/**
  \brief Union type to access mac_rx_csl_ie (@ 0x000003A8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003A8) CSL IE In Received Frame                                   */

  struct {
    __IM  uint32_t csl_period : 16;           /*!< [15..0] the CSL period of the CSL IE in received frame                    */
    __IM  uint32_t csl_phase  : 16;           /*!< [31..16] the CSL phase of the CSL IE in received frame                    */
  } b;                                        /*!< bit fields for mac_rx_csl_ie */
} mac_rx_csl_ie_t, *pmac_rx_csl_ie_t;

/**
  \brief Union type to access mac_rx_tmcor_ie (@ 0x000003AC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003AC) Time Correction IE In Received Frame                       */

  struct {
    __IM  uint32_t tm_sync_info : 16;         /*!< [15..0] the Time Sync Info of the Time Correction IE in received
                                                   frame                                                                     */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_rx_tmcor_ie */
} mac_rx_tmcor_ie_t, *pmac_rx_tmcor_ie_t;

/**
  \brief Union type to access mac_rx_aux_sec_hdr (@ 0x000003B0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003B0) RX Security Aux Header Information Register                */

  struct {
    __IM  uint32_t rxm_sec_level : 3;         /*!< [2..0] 'the Security Level field of the received Aux security
                                                   header. Value of this field indicates the security level
                                                   (method) of the received secured frame: 0: none; 1: MIC-32;
                                                   2: MIC-64; 3: MIC-128; 4: AES; 5: AES-MIC-32; 6: AES-MIC-64;
                                                   7: AES-MIC-128;                                                           */
    __IM  uint32_t rxm_keyid_mode : 2;        /*!< [4..3] 'the Key Indetifier Mode field of the received Aux security
                                                   header. Value of this field indicates how many of bis of
                                                   rxm_keyid is valid.                                                       */
    __IM  uint32_t rxm_sec_frm_cnt_comp : 1;  /*!< [5..5] the Frame Counter Suppression bit of the Security Control
                                                   field in the Aux Security header of the latest received
                                                   frame                                                                     */
    __IM  uint32_t rxm_sec_asn_nonce : 1;     /*!< [6..6] the 'ASN in Nonce' bit of the Security Control field
                                                   in the Aux Security header of the latest received frame                   */
          uint32_t            : 1;
    __IM  uint32_t rxm_key_index : 8;         /*!< [15..8] the key index of the key identifier in the Aux security
                                                   header of received incoming frame. This field is valid
                                                   only when the rxm_keyid_mode != 0                                         */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_rx_aux_sec_hdr */
} mac_rx_aux_sec_hdr_t, *pmac_rx_aux_sec_hdr_t;

/**
  \brief Union type to access mac_rx_aux_frmcnt (@ 0x000003B4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003B4) RX Security Aux Header Frame Counter Information
                                                                  Register                                                   */

  struct {
    __IM  uint32_t rxm_sec_frm_cnt : 32;      /*!< [31..0] the frame counter field in the Aux security header of
                                                   the latest received security frame                                        */
  } b;                                        /*!< bit fields for mac_rx_aux_frmcnt */
} mac_rx_aux_frmcnt_t, *pmac_rx_aux_frmcnt_t;

/**
  \brief Union type to access mac_rx_aux_key_src_l (@ 0x000003B8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003B8) RX Security Aux Key Source Lower Bytes Register            */

  struct {
    __IM  uint32_t rxm_key_src_l : 32;        /*!< [31..0] the bits [31:0] of the Key source field of the received
                                                   Aux security header. The number of valid bits of the Key
                                                   source is depends on the Key Identifier Mode: 0: key identifier
                                                   size is 0, ignore the value of rxm_key_index and rxm_key_src;
                                                   1: key identifier size is 1 byte, only rxm_key_index is
                                                   valid; 2: key identifier size is 5 bytes, only rxm_key_indx
                                                   and rxm_key_src[31:0] are valid; 3: key identifier size
                                                   is 9 bytes, the rxm_key_indx and whole rxm_key_src are
                                                   valid;                                                                    */
  } b;                                        /*!< bit fields for mac_rx_aux_key_src_l */
} mac_rx_aux_key_src_l_t, *pmac_rx_aux_key_src_l_t;

/**
  \brief Union type to access mac_rx_aux_key_src_h (@ 0x000003BC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003BC) RX Security Aux Key Source Higher Bytes Register           */

  struct {
    __IM  uint32_t rxm_key_src_h : 32;        /*!< [31..0] the bits [63:32] of the Key source field of the received
                                                   Aux security header. The number of valid bits of the Key
                                                   source is depends on the Key Identifier Mode: 0: key identifier
                                                   size is 0, ignore the value of rxm_key_index and rxm_key_src;
                                                   1: key identifier size is 1 byte, only rxm_key_index is
                                                   valid; 2: key identifier size is 5 bytes, only rxm_key_indx
                                                   and rxm_key_src[31:0] are valid; 3: key identifier size
                                                   is 9 bytes, the rxm_key_indx and whole rxm_key_src are
                                                   valid;                                                                    */
  } b;                                        /*!< bit fields for mac_rx_aux_key_src_h */
} mac_rx_aux_key_src_h_t, *pmac_rx_aux_key_src_h_t;

/**
  \brief Union type to access mac_rx_fifo_ctrl (@ 0x000003C0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003C0) RX FIFO Control Register                                   */

  struct {
    __IOM uint32_t rxfifo2    : 1;            /*!< [0..0] RX Ping-pong FIFO Enable: 0: (default) Disable; 1: Enable          */
          uint32_t            : 1;
    __IOM uint32_t rxffwr     : 1;            /*!< [2..2] enable FW to access RX FIFO: 1: RX FIFO is owned by FW
                                                   and FW can read/wrire RX FIFO; 0: RX FIFO is owned by MAC
                                                   HW, FW cannot access RX FIFO                                              */
          uint32_t            : 5;
    __IOM uint32_t rxflush    : 1;            /*!< [8..8] Flush the RX FIFO: 1: Flush RX FIFO. RX FIFO data is
                                                   not modified. If Ping-pong FIFO is enabled (rxfifo2 = 1),
                                                   both FIFOs are flushed at the same time. Bit is automatically
                                                   cleared to '0' by hardware                                                */
          uint32_t            : 23;
  } b;                                        /*!< bit fields for mac_rx_fifo_ctrl */
} mac_rx_fifo_ctrl_t, *pmac_rx_fifo_ctrl_t;

/**
  \brief Union type to access mac_rx_early_fw_sts (@ 0x000003C4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003C4) RX early interrupt FW process status                       */

  struct {
    __IOM uint32_t rx_early_sts : 8;          /*!< [7..0] for FW to store the RX early interrupt process status
                                                   to assist the incoming frame receiving pre-processing.
                                                   MAC HW will clear this field on every start of a new incoming
                                                   frame receiving.                                                          */
          uint32_t            : 24;
  } b;                                        /*!< bit fields for mac_rx_early_fw_sts */
} mac_rx_early_fw_sts_t, *pmac_rx_early_fw_sts_t;

/**
  \brief Union type to access mac_bt_clk_sel (@ 0x000003C8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003C8) RX Timestamp Timer Selection Control Register              */

  struct {
    __IOM uint32_t rx_tim_sel : 1;            /*!< [0..0] Controls the RX machine to select the time for RX timestamp
                                                   latching: 0 : Used 16 bits MAC down count timer; 1 : Used
                                                   10 bits BT clock counter and BT Native clock[22:1] value                  */
          uint32_t            : 31;
  } b;                                        /*!< bit fields for mac_bt_clk_sel */
} mac_bt_clk_sel_t, *pmac_bt_clk_sel_t;

/**
  \brief Union type to access mac_rxm_sts (@ 0x000003CC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003CC) RX Machine Status Register                                 */

  struct {
    __IOM uint32_t pidconflict : 1;           /*!< [0..0] PAN ID conflict. Write '1' to clear                                */
    __IM  uint32_t rxm_hdr_rdy : 1;           /*!< [1..1] RX Header ready, this bit is set to indicates the MAC
                                                   header (includes Security Aux. header if present) of the
                                                   incoming frame is received. It is cleared automatically
                                                   when a new frame receiving is started.                                    */
    __IM  uint32_t sec_dec_err : 1;           /*!< [2..2] Security MIC check Error (incorrect): 0: (default) Security
                                                   decryption and MIC is correct; 1: Security decryption done
                                                   and MIC is inclrrect this bit is set when use the Security
                                                   engine to do the RX FIFO secure frame decryption and the
                                                   result of MIC check is error                                              */
    __IM  uint32_t rxm_crc_err : 1;           /*!< [3..3] RX CRC Error: 0: (default) RX CRC correct; 1: RX CRC
                                                   error this bit is set when an incoming frame receiving
                                                   is finished and the FCS check result is error                             */
    __IM  uint32_t rxfifo_overflow : 1;       /*!< [4..4] RX FIFO Overflow: 0: (default) Not overflow; 1: Overflow
                                                   RX FIFO overflow is occurred when RX FIFO is full and a
                                                   new incoming frame is attempts to be stored into RX FIFO.                 */
    __IM  uint32_t sec_dec_ignored : 1;       /*!< [5..5] rx decryption is ignored for the latest received secure
                                                   frame, this bit is valid only when the ping-pong FIFO mode
                                                   is enabled0 : RX decryption is not ignored (start decryption
                                                   is triggered)1 : RX decryption is ignored                                 */
          uint32_t            : 1;
    __IM  uint32_t rxfifo_full : 1;           /*!< [7..7] RX FIFO Full: 0: (default) RX FIFO available for data
                                                   receiving; 1: RX FIFO not available for data receiving
                                                   for single RX FIFO operation mode, RX FIFO full is occurred
                                                   when a received frame is stored into RX FIFO. RX FIFO full
                                                   status is cleared once the FW read frame data from the
                                                   RX FIFO. for ping-pong RX FIFO operation mode. RX FIFO
                                                   full is occurred when 2 received frames are stored into
                                                   RX FIFO seprately and FW cannot read RX FIFO in time. the
                                                   RX FIFO full status is cleared once FW read one fr                        */
    __IM  uint32_t rdff1      : 1;            /*!< [8..8] RX FIFO read selection flag for RX FIFO Reading: 0: (default)
                                                   Read data from RX FIFO 0; 1: Read data from RX FIFO 1 if
                                                   the RX FIFO operation mode is single RX FIFO, this flag
                                                   always is 0; if the RX FIFO operation mode is ping-pong
                                                   RX FIFO, this flag will toggle for every RX FIFO read.                    */
    __IM  uint32_t wrff1      : 1;            /*!< [9..9] RX FIFO write selection flag for PHY to select the RX
                                                   FIFO to store received frame: 0: write data to RX FIFO
                                                   0; 1: write data to RX FIFO 1 if the RX FIFO operation
                                                   mode is single RX FIFO, this flag always is 0; if the RX
                                                   FIFO operation mode is ping-pong RX FIFO, this flag will
                                                   toggle for every RX FIFO write.                                           */
          uint32_t            : 15;
    __IM  uint32_t last_rxm_hdr_rdy : 1;      /*!< [25..25] the latched value of rxm_hdr_rdy bit. It keep update
                                                   the latched value during RXM state is busy and hold the
                                                   latest latched value when RXM state is idle                               */
          uint32_t            : 1;
    __IM  uint32_t last_rxm_crc_err : 1;      /*!< [27..27] the latched value of rxm_crc_err bit. It keep update
                                                   the latched value during RXM state is busy and hold the
                                                   latest latched value when RXM state is idle                               */
    __IM  uint32_t last_rxfifo_overflow : 1;  /*!< [28..28] the latched value of rxfifo_overflow bit. It keep update
                                                   the latched value during RXM state is busy and hold the
                                                   latest latched value when RXM state is idle                               */
          uint32_t            : 1;
    __IM  uint32_t lwrff1     : 1;            /*!< [30..30] the latched value of wrff1 bit. It keep update the
                                                   latched value during RXM state is busy and hold the latest
                                                   latched value when RXM state is idle                                      */
    __IM  uint32_t last_rxfifo_full : 1;      /*!< [31..31] the latched value of rxfifo_full bit. It keep update
                                                   the latched value during RXM state is busy and hold the
                                                   latest latched value when RXM state is idle                               */
  } b;                                        /*!< bit fields for mac_rxm_sts */
} mac_rxm_sts_t, *pmac_rxm_sts_t;

/**
  \brief Union type to access mac_rx_src_addr_l (@ 0x000003D0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003D0) RX Source Address Lower Bytes Register                     */

  struct {
    __IM  uint32_t srcadr_l   : 32;           /*!< [31..0] Received Packet Source Address lower bits [31:0]                  */
  } b;                                        /*!< bit fields for mac_rx_src_addr_l */
} mac_rx_src_addr_l_t, *pmac_rx_src_addr_l_t;

/**
  \brief Union type to access mac_rx_src_addr_h (@ 0x000003D4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003D4) RX Source Address Higher Bytes Register                    */

  struct {
    __IM  uint32_t srcadr_h   : 32;           /*!< [31..0] Received Packet Source Address higher bits [63:32]                */
  } b;                                        /*!< bit fields for mac_rx_src_addr_h */
} mac_rx_src_addr_h_t, *pmac_rx_src_addr_h_t;

/**
  \brief Union type to access mac_rxmbcnt_fsm (@ 0x000003D8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000003D8) RX Machine Received Byte Count and RXM State
                                                                  Register                                                   */

  struct {
    __IM  uint32_t rxmbytecnt : 8;            /*!< [7..0] RXM receiving byte counter, used to make sure 'superframe
                                                   specification' of beacon frame is in RXFIFO. It is for
                                                   decryption of beacon frame                                                */
    __IOM uint32_t frm_cs     : 6;            /*!< [13..8] RXM frame current state                                           */
          uint32_t            : 2;
    __IM  uint32_t frm_ack_cs : 3;            /*!< [18..16] RXM ACK frame current state, for debug                           */
          uint32_t            : 13;
  } b;                                        /*!< bit fields for mac_rxmbcnt_fsm */
} mac_rxmbcnt_fsm_t, *pmac_rxmbcnt_fsm_t;

/**
  \brief Union type to access mac_src_addr_filter_ctrl (@ 0x00000400).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000400) Source Address Match Filter Control Register               */

  struct {
    __IOM uint32_t enh_frmpend_en : 1;        /*!< [0..0] enable the enhanced frame pending mechanism (defined
                                                   by Thread 1.2 Spec.) of auto frame pending bit fill in
                                                   the Frame Control of Imm-Ack. 0: enhanced frame pending
                                                   is disabled. The source address match filter HW will set
                                                   the Frame Pending bit of a Imm-Ack frame which response
                                                   to a Data Request command frame. 1: enhanced frame pending
                                                   is enabled. The source address match filter HW will set
                                                   the Frame Pending bit of Imm-Ack frames those response
                                                   to Data frames or Command frames.                                         */
    __IOM uint32_t pending_ack : 1;           /*!< [1..1] the pending bit value of Imm-Ack to response to an incoming
                                                   MAC frame other than Data Request command and its source
                                                   address does not match to any Source Address Match Filter
                                                   entry.                                                                    */
    __IOM uint32_t datreq_cmd_pending_ack : 1;/*!< [2..2] the pending bit value of Imm-Ack to response to a Data
                                                   Request command frame and its source address do not match
                                                   to any Source Address Match Filter entry.                                 */
          uint32_t            : 29;
  } b;                                        /*!< bit fields for mac_src_addr_filter_ctrl */
} mac_src_addr_filter_ctrl_t, *pmac_src_addr_filter_ctrl_t;

/**
  \brief Union type to access mac_src_ext_match_entry_en (@ 0x00000404).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000404) Extended Address Entries of Source Address Match
                                                                  Filter Enable Control Register                             */

  struct {
    __IOM uint32_t ext_entry_en : 16;         /*!< [15..0] enable control of each extended address entry of source
                                                   address match filter. Bit 0 ~ bit 15 control entry 0 ~
                                                   entry15 corresponding.                                                    */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_src_ext_match_entry_en */
} mac_src_ext_match_entry_en_t, *pmac_src_ext_match_entry_en_t;

/**
  \brief Union type to access mac_src_short_match_entry_en (@ 0x00000408).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000408) Short Address Entries of Source Address Match
                                                                  Filter Enable Control Register                             */

  struct {
    __IOM uint32_t ext_entry_en : 32;         /*!< [31..0] enable control of each short address entry of source
                                                   address match filter. Bit 0 ~ bit 31 control entry 0 ~
                                                   entry31 corresponding.                                                    */
  } b;                                        /*!< bit fields for mac_src_short_match_entry_en */
} mac_src_short_match_entry_en_t, *pmac_src_short_match_entry_en_t;

/**
  \brief Union type to access mac_src_addr_match_sts (@ 0x0000040C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000040C) Source Address Match Filter Status Register                */

  struct {
    __IOM uint32_t src_match_entry_id : 5;    /*!< [4..0] Indicates the entry index of Source Address Match Filter
                                                   of the latest matched result.                                             */
    __IOM uint32_t src_match_entry_type : 1;  /*!< [5..5] Indicates the entry type of Source Address Match Filter
                                                   of the latest matched result. 0: match to a short address
                                                   entry; 1: match to a extended address entry;                              */
    __IOM uint32_t src_match_status_update : 1;/*!< [6..6] indicates the source address of an incoming RX frame
                                                   is matched with one of entry of source address filter.
                                                   FW write 1 to clear.                                                      */
          uint32_t            : 25;
  } b;                                        /*!< bit fields for mac_src_addr_match_sts */
} mac_src_addr_match_sts_t, *pmac_src_addr_match_sts_t;

/**
  \brief Union type to access mac_src_short_match0 (@ 0x00000410).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000410) Short Source Address Match Filter Entry 0                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 0                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 0                        */
  } b;                                        /*!< bit fields for mac_src_short_match0 */
} mac_src_short_match0_t, *pmac_src_short_match0_t;

/**
  \brief Union type to access mac_src_ext_match0_l (@ 0x00000410).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000410) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 0                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 0                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match0_l */
} mac_src_ext_match0_l_t, *pmac_src_ext_match0_l_t;

/**
  \brief Union type to access mac_src_short_match1 (@ 0x00000414).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000414) Short Source Address Match Filter Entry 1                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 1                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 1                        */
  } b;                                        /*!< bit fields for mac_src_short_match1 */
} mac_src_short_match1_t, *pmac_src_short_match1_t;

/**
  \brief Union type to access mac_src_ext_match0_h (@ 0x00000414).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000414) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 0                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 0                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match0_h */
} mac_src_ext_match0_h_t, *pmac_src_ext_match0_h_t;

/**
  \brief Union type to access mac_src_short_match2 (@ 0x00000418).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000418) Short Source Address Match Filter Entry 2                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 2                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 2                        */
  } b;                                        /*!< bit fields for mac_src_short_match2 */
} mac_src_short_match2_t, *pmac_src_short_match2_t;

/**
  \brief Union type to access mac_src_ext_match1_l (@ 0x00000418).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000418) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 1                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 1                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match1_l */
} mac_src_ext_match1_l_t, *pmac_src_ext_match1_l_t;

/**
  \brief Union type to access mac_src_short_match3 (@ 0x0000041C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000041C) Short Source Address Match Filter Entry 3                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 3                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 3                        */
  } b;                                        /*!< bit fields for mac_src_short_match3 */
} mac_src_short_match3_t, *pmac_src_short_match3_t;

/**
  \brief Union type to access mac_src_ext_match1_h (@ 0x0000041C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000041C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 1                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 1                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match1_h */
} mac_src_ext_match1_h_t, *pmac_src_ext_match1_h_t;

/**
  \brief Union type to access mac_src_short_match4 (@ 0x00000420).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000420) Short Source Address Match Filter Entry 4                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 4                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 4                        */
  } b;                                        /*!< bit fields for mac_src_short_match4 */
} mac_src_short_match4_t, *pmac_src_short_match4_t;

/**
  \brief Union type to access mac_src_ext_match2_l (@ 0x00000420).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000420) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 2                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 2                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match2_l */
} mac_src_ext_match2_l_t, *pmac_src_ext_match2_l_t;

/**
  \brief Union type to access mac_src_short_match5 (@ 0x00000424).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000424) Short Source Address Match Filter Entry 5                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 5                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 5                        */
  } b;                                        /*!< bit fields for mac_src_short_match5 */
} mac_src_short_match5_t, *pmac_src_short_match5_t;

/**
  \brief Union type to access mac_src_ext_match2_h (@ 0x00000424).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000424) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 2                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 2                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match2_h */
} mac_src_ext_match2_h_t, *pmac_src_ext_match2_h_t;

/**
  \brief Union type to access mac_src_short_match6 (@ 0x00000428).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000428) Short Source Address Match Filter Entry 6                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 6                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 6                        */
  } b;                                        /*!< bit fields for mac_src_short_match6 */
} mac_src_short_match6_t, *pmac_src_short_match6_t;

/**
  \brief Union type to access mac_src_ext_match3_l (@ 0x00000428).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000428) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 3                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 3                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match3_l */
} mac_src_ext_match3_l_t, *pmac_src_ext_match3_l_t;

/**
  \brief Union type to access mac_src_short_match7 (@ 0x0000042C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000042C) Short Source Address Match Filter Entry 7                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 7                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 7                        */
  } b;                                        /*!< bit fields for mac_src_short_match7 */
} mac_src_short_match7_t, *pmac_src_short_match7_t;

/**
  \brief Union type to access mac_src_ext_match3_h (@ 0x0000042C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000042C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 3                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 3                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match3_h */
} mac_src_ext_match3_h_t, *pmac_src_ext_match3_h_t;

/**
  \brief Union type to access mac_src_short_match8 (@ 0x00000430).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000430) Short Source Address Match Filter Entry 8                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 8                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 8                        */
  } b;                                        /*!< bit fields for mac_src_short_match8 */
} mac_src_short_match8_t, *pmac_src_short_match8_t;

/**
  \brief Union type to access mac_src_ext_match4_l (@ 0x00000430).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000430) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 4                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 4                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match4_l */
} mac_src_ext_match4_l_t, *pmac_src_ext_match4_l_t;

/**
  \brief Union type to access mac_src_short_match9 (@ 0x00000434).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000434) Short Source Address Match Filter Entry 9                  */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 9                  */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 9                        */
  } b;                                        /*!< bit fields for mac_src_short_match9 */
} mac_src_short_match9_t, *pmac_src_short_match9_t;

/**
  \brief Union type to access mac_src_ext_match4_h (@ 0x00000434).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000434) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 4                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 4                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match4_h */
} mac_src_ext_match4_h_t, *pmac_src_ext_match4_h_t;

/**
  \brief Union type to access mac_src_short_match10 (@ 0x00000438).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000438) Short Source Address Match Filter Entry 10                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 10                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 10                       */
  } b;                                        /*!< bit fields for mac_src_short_match10 */
} mac_src_short_match10_t, *pmac_src_short_match10_t;

/**
  \brief Union type to access mac_src_ext_match5_l (@ 0x00000438).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000438) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 5                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 5                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match5_l */
} mac_src_ext_match5_l_t, *pmac_src_ext_match5_l_t;

/**
  \brief Union type to access mac_src_short_match11 (@ 0x0000043C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000043C) Short Source Address Match Filter Entry 11                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 11                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 11                       */
  } b;                                        /*!< bit fields for mac_src_short_match11 */
} mac_src_short_match11_t, *pmac_src_short_match11_t;

/**
  \brief Union type to access mac_src_ext_match5_h (@ 0x0000043C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000043C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 5                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 5                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match5_h */
} mac_src_ext_match5_h_t, *pmac_src_ext_match5_h_t;

/**
  \brief Union type to access mac_src_short_match12 (@ 0x00000440).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000440) Short Source Address Match Filter Entry 12                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 12                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 12                       */
  } b;                                        /*!< bit fields for mac_src_short_match12 */
} mac_src_short_match12_t, *pmac_src_short_match12_t;

/**
  \brief Union type to access mac_src_ext_match6_l (@ 0x00000440).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000440) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 6                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 6                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match6_l */
} mac_src_ext_match6_l_t, *pmac_src_ext_match6_l_t;

/**
  \brief Union type to access mac_src_short_match13 (@ 0x00000444).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000444) Short Source Address Match Filter Entry 13                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 13                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 13                       */
  } b;                                        /*!< bit fields for mac_src_short_match13 */
} mac_src_short_match13_t, *pmac_src_short_match13_t;

/**
  \brief Union type to access mac_src_ext_match6_h (@ 0x00000444).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000444) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 6                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 6                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match6_h */
} mac_src_ext_match6_h_t, *pmac_src_ext_match6_h_t;

/**
  \brief Union type to access mac_src_short_match14 (@ 0x00000448).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000448) Short Source Address Match Filter Entry 14                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 14                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 14                       */
  } b;                                        /*!< bit fields for mac_src_short_match14 */
} mac_src_short_match14_t, *pmac_src_short_match14_t;

/**
  \brief Union type to access mac_src_ext_match7_l (@ 0x00000448).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000448) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 7                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 7                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match7_l */
} mac_src_ext_match7_l_t, *pmac_src_ext_match7_l_t;

/**
  \brief Union type to access mac_src_short_match15 (@ 0x0000044C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000044C) Short Source Address Match Filter Entry 15                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 15                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 15                       */
  } b;                                        /*!< bit fields for mac_src_short_match15 */
} mac_src_short_match15_t, *pmac_src_short_match15_t;

/**
  \brief Union type to access mac_src_ext_match7_h (@ 0x0000044C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000044C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 7                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 7                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match7_h */
} mac_src_ext_match7_h_t, *pmac_src_ext_match7_h_t;

/**
  \brief Union type to access mac_src_short_match16 (@ 0x00000450).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000450) Short Source Address Match Filter Entry 16                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 16                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 16                       */
  } b;                                        /*!< bit fields for mac_src_short_match16 */
} mac_src_short_match16_t, *pmac_src_short_match16_t;

/**
  \brief Union type to access mac_src_ext_match8_l (@ 0x00000450).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000450) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 8                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 8                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match8_l */
} mac_src_ext_match8_l_t, *pmac_src_ext_match8_l_t;

/**
  \brief Union type to access mac_src_short_match17 (@ 0x00000454).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000454) Short Source Address Match Filter Entry 17                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 17                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 17                       */
  } b;                                        /*!< bit fields for mac_src_short_match17 */
} mac_src_short_match17_t, *pmac_src_short_match17_t;

/**
  \brief Union type to access mac_src_ext_match8_h (@ 0x00000454).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000454) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 8                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 7                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match8_h */
} mac_src_ext_match8_h_t, *pmac_src_ext_match8_h_t;

/**
  \brief Union type to access mac_src_short_match18 (@ 0x00000458).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000458) Short Source Address Match Filter Entry 18                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 18                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 18                       */
  } b;                                        /*!< bit fields for mac_src_short_match18 */
} mac_src_short_match18_t, *pmac_src_short_match18_t;

/**
  \brief Union type to access mac_src_ext_match9_l (@ 0x00000458).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000458) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 9                                             */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 9                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match9_l */
} mac_src_ext_match9_l_t, *pmac_src_ext_match9_l_t;

/**
  \brief Union type to access mac_src_short_match19 (@ 0x0000045C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000045C) Short Source Address Match Filter Entry 19                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 19                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 19                       */
  } b;                                        /*!< bit fields for mac_src_short_match19 */
} mac_src_short_match19_t, *pmac_src_short_match19_t;

/**
  \brief Union type to access mac_src_ext_match9_h (@ 0x0000045C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000045C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 9                                             */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 9                                                             */
  } b;                                        /*!< bit fields for mac_src_ext_match9_h */
} mac_src_ext_match9_h_t, *pmac_src_ext_match9_h_t;

/**
  \brief Union type to access mac_src_short_match20 (@ 0x00000460).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000460) Short Source Address Match Filter Entry 20                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 20                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 20                       */
  } b;                                        /*!< bit fields for mac_src_short_match20 */
} mac_src_short_match20_t, *pmac_src_short_match20_t;

/**
  \brief Union type to access mac_src_ext_match10_l (@ 0x00000460).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000460) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 10                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 10                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match10_l */
} mac_src_ext_match10_l_t, *pmac_src_ext_match10_l_t;

/**
  \brief Union type to access mac_src_short_match21 (@ 0x00000464).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000464) Short Source Address Match Filter Entry 21                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 21                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 21                       */
  } b;                                        /*!< bit fields for mac_src_short_match21 */
} mac_src_short_match21_t, *pmac_src_short_match21_t;

/**
  \brief Union type to access mac_src_ext_match10_h (@ 0x00000464).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000464) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 10                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 10                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match10_h */
} mac_src_ext_match10_h_t, *pmac_src_ext_match10_h_t;

/**
  \brief Union type to access mac_src_short_match22 (@ 0x00000468).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000468) Short Source Address Match Filter Entry 22                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 22                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 22                       */
  } b;                                        /*!< bit fields for mac_src_short_match22 */
} mac_src_short_match22_t, *pmac_src_short_match22_t;

/**
  \brief Union type to access mac_src_ext_match11_l (@ 0x00000468).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000468) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 11                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 11                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match11_l */
} mac_src_ext_match11_l_t, *pmac_src_ext_match11_l_t;

/**
  \brief Union type to access mac_src_short_match23 (@ 0x0000046C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000046C) Short Source Address Match Filter Entry 23                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 23                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 23                       */
  } b;                                        /*!< bit fields for mac_src_short_match23 */
} mac_src_short_match23_t, *pmac_src_short_match23_t;

/**
  \brief Union type to access mac_src_ext_match11_h (@ 0x0000046C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000046C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 11                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 11                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match11_h */
} mac_src_ext_match11_h_t, *pmac_src_ext_match11_h_t;

/**
  \brief Union type to access mac_src_short_match24 (@ 0x00000470).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000470) Short Source Address Match Filter Entry 24                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 24                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 24                       */
  } b;                                        /*!< bit fields for mac_src_short_match24 */
} mac_src_short_match24_t, *pmac_src_short_match24_t;

/**
  \brief Union type to access mac_src_ext_match12_l (@ 0x00000470).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000470) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 12                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 12                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match12_l */
} mac_src_ext_match12_l_t, *pmac_src_ext_match12_l_t;

/**
  \brief Union type to access mac_src_short_match25 (@ 0x00000474).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000474) Short Source Address Match Filter Entry 25                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 25                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 25                       */
  } b;                                        /*!< bit fields for mac_src_short_match25 */
} mac_src_short_match25_t, *pmac_src_short_match25_t;

/**
  \brief Union type to access mac_src_ext_match12_h (@ 0x00000474).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000474) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 12                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 12                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match12_h */
} mac_src_ext_match12_h_t, *pmac_src_ext_match12_h_t;

/**
  \brief Union type to access mac_src_short_match26 (@ 0x00000478).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000478) Short Source Address Match Filter Entry 26                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 26                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 26                       */
  } b;                                        /*!< bit fields for mac_src_short_match26 */
} mac_src_short_match26_t, *pmac_src_short_match26_t;

/**
  \brief Union type to access mac_src_ext_match13_l (@ 0x00000478).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000478) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 13                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 13                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match13_l */
} mac_src_ext_match13_l_t, *pmac_src_ext_match13_l_t;

/**
  \brief Union type to access mac_src_short_match27 (@ 0x0000047C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000047C) Short Source Address Match Filter Entry 27                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 27                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 27                       */
  } b;                                        /*!< bit fields for mac_src_short_match27 */
} mac_src_short_match27_t, *pmac_src_short_match27_t;

/**
  \brief Union type to access mac_src_ext_match13_h (@ 0x0000047C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000047C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 13                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 13                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match13_h */
} mac_src_ext_match13_h_t, *pmac_src_ext_match13_h_t;

/**
  \brief Union type to access mac_src_short_match28 (@ 0x00000480).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000480) Short Source Address Match Filter Entry 28                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 28                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 28                       */
  } b;                                        /*!< bit fields for mac_src_short_match28 */
} mac_src_short_match28_t, *pmac_src_short_match28_t;

/**
  \brief Union type to access mac_src_ext_match14_l (@ 0x00000480).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000480) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 14                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 14                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match14_l */
} mac_src_ext_match14_l_t, *pmac_src_ext_match14_l_t;

/**
  \brief Union type to access mac_src_short_match29 (@ 0x00000484).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000484) Short Source Address Match Filter Entry 29                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 29                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 29                       */
  } b;                                        /*!< bit fields for mac_src_short_match29 */
} mac_src_short_match29_t, *pmac_src_short_match29_t;

/**
  \brief Union type to access mac_src_ext_match14_h (@ 0x00000484).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000484) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 14                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 14                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match14_h */
} mac_src_ext_match14_h_t, *pmac_src_ext_match14_h_t;

/**
  \brief Union type to access mac_src_short_match30 (@ 0x00000488).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000488) Short Source Address Match Filter Entry 30                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 30                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 30                       */
  } b;                                        /*!< bit fields for mac_src_short_match30 */
} mac_src_short_match30_t, *pmac_src_short_match30_t;

/**
  \brief Union type to access mac_src_ext_match15_l (@ 0x00000488).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x00000488) Lower 4-bytes of Extended Source Address Match
                                                                Filter Entry 15                                            */

  struct {
    __IOM uint32_t ext_addr_l : 32;         /*!< [31..0] the lower 4-bytes of extended address of extended address
                                                 match entry 15                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match15_l */
} mac_src_ext_match15_l_t, *pmac_src_ext_match15_l_t;

/**
  \brief Union type to access mac_src_short_match31 (@ 0x0000048C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000048C) Short Source Address Match Filter Entry 31                 */

  struct {
    __IOM uint32_t addr     : 16;           /*!< [15..0] the short address of short address match entry 31                 */
    __IOM uint32_t panid    : 16;           /*!< [31..16] the PAN ID of short address match entry 31                       */
  } b;                                        /*!< bit fields for mac_src_short_match31 */
} mac_src_short_match31_t, *pmac_src_short_match31_t;

/**
  \brief Union type to access mac_src_ext_match15_h (@ 0x0000048C).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x0000048C) Higher 4-bytes of Extended Source Address Match
                                                                Filter Entry 15                                            */

  struct {
    __IOM uint32_t ext_addr_h : 32;         /*!< [31..0] the higher 4-bytes of extended address of extended address
                                                 match entry 15                                                            */
  } b;                                        /*!< bit fields for mac_src_ext_match15_h */
} mac_src_ext_match15_h_t, *pmac_src_ext_match15_h_t;

/**
  \brief Union type to access mac_seccr0 (@ 0x00000500).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000500) Security Engine Control Register 0                         */

  struct {
    __IOM uint32_t txncipher  : 3;            /*!< [2..0] TX Normal FIFO Security Suite Select: 000: (default)
                                                   Undefined; 001: AES-ENC; 010: AES-ENC-MIC-128; 011: AES-ENC-MIC-64;
                                                   100: AES-ENC-MIC-32; 101: AES-MIC-128; 110: AES-MIC-64;
                                                   111: AES-MIC-32;                                                          */
    __IOM uint32_t rxcipher   : 3;            /*!< [5..3] RX FIFO Security Suite Select: 000: (default) Undefined;
                                                   001: AES-ENC; 010: AES-ENC-MIC-128; 011: AES-ENC-MIC-64;
                                                   100: AES-ENC-MIC-32; 101: AES-MIC-128; 110: AES-MIC-64;
                                                   111: AES-MIC-32;                                                          */
    __OM  uint32_t secstart   : 1;            /*!< [6..6] RX Security Decryption Start: 1: Start decryption process.
                                                   Bit is automatically cleared to '0' by hardware                           */
    __OM  uint32_t secignore  : 1;            /*!< [7..7] RX Security Decryption Ignore: 1: Ignore decryption process.
                                                   Bit is automatically cleared to '0' by hardware                           */
    __IOM uint32_t disenc     : 1;            /*!< [8..8] Disable Encryption Function: 0: (default) Enable encryption
                                                   function; 1: Disable the encryption process. The MAC TXM
                                                   does not encrypt the data, even if the TX security is enabled             */
    __IOM uint32_t disdec     : 1;            /*!< [9..9] Disable Decryption Function: 0: (default) Enable decryption
                                                   process; 1: Disable the decryption process. The MAC RXM
                                                   does not generate a security interrupt, even if 'security'
                                                   bit in the MAC header is detected                                         */
          uint32_t            : 6;
    __IOM uint32_t txbcipher  : 3;            /*!< [18..16] TXBCIPHER: TX Beacon FIFO Security Suite Select: 000:
                                                   (default) Undefined; 001: AES-ENC; 010: AES-ENC-MIC-128;
                                                   011: AES-ENC-MIC-64; 100: AES-ENC-MIC-32; 101: AES-MIC-128;
                                                   110: AES-MIC-64; 111: AES-MIC-32;                                         */
          uint32_t            : 5;
    __IOM uint32_t txg1cipher : 3;            /*!< [26..24] TX GTS1 FIFO Security Suite Select: 000: (default)
                                                   Undefined; 001: AES-ENC; 010: AES-ENC-MIC-128; 011: AES-ENC-MIC-64;
                                                   100: AES-ENC-MIC-32; 101: AES-MIC-128; 110: AES-MIC-64;
                                                   111: AES-MIC-32;                                                          */
    __IOM uint32_t txg2cipher : 3;            /*!< [29..27] TX GTS2 FIFO Security Suite Select: 000: (default)
                                                   Undefined; 001: AES-ENC; 010: AES-ENC-MIC-128; 011: AES-ENC-MIC-64;
                                                   100: AES-ENC-MIC-32; 101: AES-MIC-128; 110: AES-MIC-64;
                                                   111: AES-MIC-32;                                                          */
          uint32_t            : 2;
  } b;                                        /*!< bit fields for mac_seccr0 */
} mac_seccr0_t, *pmac_seccr0_t;

/**
  \brief Union type to access mac_seccr1 (@ 0x00000504).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000504) Security Engine Control Register 1                         */

  struct {
    __IOM uint32_t usrflag    : 1;            /*!< [0..0] User Defined Flag and initial Counter: 0: (default) Disable;
                                                   1: Enable; User-defined flag is defined in ENCFLG(0x004[15:8])
                                                   and AUTFLG(0x004[23:16]). User-defined counter is defined
                                                   in LREG0x27A and LREG0x27B.                                               */
    __IOM uint32_t sec_2006   : 1;            /*!< [1..1] Enable IEEE802.15.4-2006-compliant Block Cipher Mode:
                                                   0: (default) Disable; 1: Enable                                           */
    __IOM uint32_t aes_only   : 1;            /*!< [2..2] Trigger AES only mode. SW should set it '0' to come back.
                                                   Trigger when '0' to '1'                                                   */
          uint32_t            : 5;
    __IOM uint32_t encflg     : 8;            /*!< [15..8] Encryption Flag. User-defined flag for encryption in
                                                   CCM/CCM* mode of Upper Cipher operation. Only works when
                                                   USRFLAG (0x504[0]) = '1'. 00000000: (default)                             */
    __IOM uint32_t autflg     : 8;            /*!< [23..16] Authentication Flag. User-defined flag for authentication
                                                   in CBC-MAC mode of Upper Cipher operation. Only works when
                                                   USRFLAG (0x504[0]) = '1'. 00000000: (default)                             */
          uint32_t            : 8;
  } b;                                        /*!< bit fields for mac_seccr1 */
} mac_seccr1_t, *pmac_seccr1_t;

/**
  \brief Union type to access mac_sec_upper_ctrl (@ 0x00000508).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000508) Upper Layer Security Control Register                      */

  struct {
    __IOM uint32_t upenc      : 1;            /*!< [0..0] Upper Layer Security Encryption Mode: 1: Perform upper
                                                   layer encryption using TX Normal FIFO. Bit is automatically
                                                   cleared to '0' by hardware.                                               */
    __IOM uint32_t updec      : 1;            /*!< [1..1] Upper Layer Security Decryption Mode: 1: Perform upper
                                                   layer decryption using TX Normal FIFO. Bit is automatically
                                                   cleared to '0' by hardware.                                               */
          uint32_t            : 30;
  } b;                                        /*!< bit fields for mac_sec_upper_ctrl */
} mac_sec_upper_ctrl_t, *pmac_sec_upper_ctrl_t;

/**
  \brief Union type to access mac_sec_proc_sts (@ 0x0000050C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000050C) Security Process Status Register                           */

  struct {
    __IOM uint32_t sec_enc_done : 1;          /*!< [0..0] security engine process done indicator, write 1 clear:
                                                   0: (default) Security engine process is not started or
                                                   not done yet; 1: security engine process is done; FW write
                                                   1 to clear this bit before start a new security engine
                                                   process                                                                   */
    __IOM uint32_t upsecerr   : 1;            /*!< [1..1] MIC Error in Upper Layer Security Mode: 0: (default)
                                                   MIC error did not occur; 1: MIC error occurred. Write '1'
                                                   to clear                                                                  */
          uint32_t            : 6;
    __IM  uint32_t txsecdone  : 1;            /*!< [8..8] Tx frame encryption process done status: 0: data encryption
                                                   process is running; 1: data encryption is done (or data
                                                   encryption is not triggered). FW can know whether the security
                                                   HW engine is doing data encryption or not by read this
                                                   bit. Ex. A secure frame transmission is failed due to the
                                                   PHY grant is lost, FW can re-trigger the transmission when
                                                   PHY is re-granted if the frame data encryption is done.                   */
    __IM  uint32_t secdecerr  : 1;            /*!< [9..9] Security decryption error. Security engine set this bit
                                                   as 1 to indicate the RX decryption is finished with MIC
                                                   check error.                                                              */
    __IM  uint32_t sec_upper_enclerr : 1;     /*!< [10..10] Security engine will set this bit as 1 to indicate
                                                   the error of Frame length or Header length is 0 when doing
                                                   upper layer encryption                                                    */
          uint32_t            : 5;
    __IM  uint32_t aes_only_rdy : 1;          /*!< [16..16] AES only mode complete. Setting AES_ONLY bit clears
                                                   the status. Report '1' when complete AES process                          */
          uint32_t            : 15;
  } b;                                        /*!< bit fields for mac_sec_proc_sts */
} mac_sec_proc_sts_t, *pmac_sec_proc_sts_t;

/**
  \brief Union type to access mac_sec_sts_stccmp (@ 0x00000510).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000510) Security State and Status Register                         */

  struct {
    __IM  uint32_t scu_cs     : 3;            /*!< [2..0] Security current state                                             */
    __IM  uint32_t parse_cs   : 3;            /*!< [5..3] Parser current state                                               */
    __IM  uint32_t key_sr_cs  : 2;            /*!< [7..6] Key search current state                                           */
    __IM  uint32_t st_ccmp    : 4;            /*!< [11..8] CTR/CCM/CBC-MAC current state                                     */
          uint32_t            : 20;
  } b;                                        /*!< bit fields for mac_sec_sts_stccmp */
} mac_sec_sts_stccmp_t, *pmac_sec_sts_stccmp_t;

/**
  \brief Union type to access mac_sec_par_order (@ 0x00000514).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000514) Security Parameters Bytes Order Control Register           */

  struct {
    __IOM uint32_t extadr_odr : 1;            /*!< [0..0] For security, device's extension address order setting.
                                                   Setting this bit reverses extension address byte order                    */
    __IOM uint32_t rxmadr_odr : 1;            /*!< [1..1] For security, receiver extension address order. Setting
                                                   this bit reverses extension address byte order                            */
    __IOM uint32_t frmctr_odr : 1;            /*!< [2..2] For security, frame counter field order. Setting this
                                                   bit reverses frame counter byte order                                     */
          uint32_t            : 29;
  } b;                                        /*!< bit fields for mac_sec_par_order */
} mac_sec_par_order_t, *pmac_sec_par_order_t;

/**
  \brief Union type to access mac_upnonce_0_3 (@ 0x00000518).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000518) Upper Security Nonce Bytes 0 ~ 3                           */

  struct {
    __IOM uint32_t upnonce    : 32;           /*!< [31..0] bits[31:0] of 104-Bit Upper NONCE Value                           */
  } b;                                        /*!< bit fields for mac_upnonce_0_3 */
} mac_upnonce_0_3_t, *pmac_upnonce_0_3_t;

/**
  \brief Union type to access mac_upnonce_4_7 (@ 0x0000051C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000051C) Upper Security Nonce Bytes 4 ~ 7                           */

  struct {
    __IOM uint32_t upnonce    : 32;           /*!< [31..0] bits[63:32] of 104-Bit Upper NONCE Value                          */
  } b;                                        /*!< bit fields for mac_upnonce_4_7 */
} mac_upnonce_4_7_t, *pmac_upnonce_4_7_t;

/**
  \brief Union type to access mac_upnonce_8_11 (@ 0x00000520).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000520) Upper Security Nonce Bytes 8 ~ 11                          */

  struct {
    __IOM uint32_t upnonce    : 32;           /*!< [31..0] bits[95:64] of 104-Bit Upper NONCE Value                          */
  } b;                                        /*!< bit fields for mac_upnonce_8_11 */
} mac_upnonce_8_11_t, *pmac_upnonce_8_11_t;

/**
  \brief Union type to access mac_upnonce_12 (@ 0x00000524).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000524) Upper Security Nonce Byte 12                               */

  struct {
    __IOM uint32_t upnonce    : 8;            /*!< [7..0] bits[103:96] of 104-Bit Upper NONCE Value                          */
          uint32_t            : 24;
  } b;                                        /*!< bit fields for mac_upnonce_12 */
} mac_upnonce_12_t, *pmac_upnonce_12_t;

/**
  \brief Union type to access mac_sec_initcntl (@ 0x00000528).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000528) Security Engine AES-CBC Initial Counter Value              */

  struct {
    __IOM uint32_t initcnt    : 16;           /*!< [15..0] User defined Frame Counter Initial value. User-defined
                                                   initial counter for Upper Cipher operation. Only works
                                                   when USRFLAG (0x004[0]) = '1'.                                            */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_sec_initcntl */
} mac_sec_initcntl_t, *pmac_sec_initcntl_t;

/**
  \brief Union type to access mac_tx_set (@ 0x00000580).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000580) PHY TX Set Control Register                                */

  struct {
    __IOM uint32_t txagc      : 8;            /*!< [7..0] TX Gain ControlTBD: output power mapping table                     */
    __IOM uint32_t sel_tpm    : 1;            /*!< [8..8] TX pattern format before TX On:1: TPM modulation0: IQM
                                                   modulation                                                                */
    __IOM uint32_t lna_en     : 1;            /*!< [9..9] enable external LNA for Zigbee                                     */
          uint32_t            : 2;
    __IOM uint32_t en_early_txon_tgl : 1;     /*!< [12..12] TX pattern format before TX On:1: 10b0: tail of previous
                                                   TX packet                                                                 */
    __IOM uint32_t radio_off  : 1;            /*!< [13..13] radio off indication: 0: radio on; 1(default): radio
                                                   off, FW use this bit to indicate MAC HW that the RF is
                                                   un-accessable due to the RF is under certen condition,
                                                   like RF calibration                                                       */
    __IOM uint32_t prestby_dly_zb : 3;        /*!< [16..14] the time delay for PHY entering standby state from
                                                   idle state, in 1us, this field is valid when prestdby_dly_en
                                                   = 1                                                                       */
    __IOM uint32_t preturnon_delay_zb : 5;    /*!< [21..17] the time delay for PHY entering turn-on state from
                                                   standby state, in 1us                                                     */
    __IOM uint32_t rampstby_delay_zb : 5;     /*!< [26..22] the time delay for PHY entering standby state, in 1us            */
    __IOM uint32_t sd_pos_delay_zb : 4;       /*!< [30..27] the time delay for PHY TX Turning off entering PHY
                                                   Off state, in unit of 1us                                                 */
    __IOM uint32_t tx_bkprg0_en : 1;          /*!< [31..31] TX backup0 programming enable                                    */
  } b;                                        /*!< bit fields for mac_tx_set */
} mac_tx_set_t, *pmac_tx_set_t;

/**
  \brief Union type to access mac_rx_set (@ 0x00000584).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000584) PHY RX Set Control Register                                */

  struct {
    __IOM uint32_t dis_rf_ps  : 1;            /*!< [0..0] disable RF shut-down power saving: RF do not enter shout-down
                                                   mode and keep in standby mode when idle                                   */
    __IOM uint32_t prestby_dly_en : 1;        /*!< [1..1] enable time delay for PHY entering standby state                   */
    __IOM uint32_t cca_threshold : 4;         /*!< [5..2] CCA CS mode threashold for channel busy detection, not
                                                   use currently (FW will write the threshold value to the
                                                   BB register directly)                                                     */
    __IOM uint32_t cca_ed_threshold : 8;      /*!< [13..6] CCA energy detection mode threashold for channel busy
                                                   detection, not use currently (FW will write the threshold
                                                   value to the BB register directly)                                        */
          uint32_t            : 2;
    __IOM uint32_t txon_early : 6;            /*!< [21..16] the time between RIF_TX_ON and TX_PKT                            */
    __IOM uint32_t cca_mode   : 2;            /*!< [23..22] Clear Channel Assessment (CCA) Mode Select: 00: Disable
                                                   CCA mode(normal data RX); 01: Energy detection (ED) mode,
                                                   which detects in-band signals; 10: Carrier sense (CS) mode,
                                                   which detects IEEE 802.15.4 signals; 11: Combination of
                                                   carrier sense mode and energy detection mode;                             */
    __IOM uint32_t standby_pg_adress : 8;     /*!< [31..24] register address for resume register programing                  */
  } b;                                        /*!< bit fields for mac_rx_set */
} mac_rx_set_t, *pmac_rx_set_t;

/**
  \brief Union type to access mac_phy_trx_dly (@ 0x00000588).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000588) PHY TX/RX Delay Control Register                           */

  struct {
    __IOM uint32_t txon_delay : 8;            /*!< [7..0] when txrx_timing is from initial to initial tx(such as
                                                   tx beacon), the wait time for tx rfup                                     */
    __IOM uint32_t rxon_delay : 8;            /*!< [15..8] when txrx_timing is from initial to initial rx or from
                                                   tx to received-ack rx, the wait time for rx rfup. In unit
                                                   of 1us.                                                                   */
    __IOM uint32_t cca_rxon_delay : 8;        /*!< [23..16] when txrx_timing is from rx to cca rx, the wait time
                                                   for cca rx rfup. In unit of 1us                                           */
    __IOM uint32_t rx2rx_delay : 8;           /*!< [31..24] when txrx_timing is from rx to rx, the wait time for
                                                   rx rfup. In unit of 1us.                                                  */
  } b;                                        /*!< bit fields for mac_phy_trx_dly */
} mac_phy_trx_dly_t, *pmac_phy_trx_dly_t;

/**
  \brief Union type to access mac_phy_to_dly (@ 0x0000058C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000058C) PHY Timeout and Delay Control Register                     */

  struct {
    __IOM uint32_t rx_timeout_delay : 8;      /*!< [7..0] when txrx_timing is in normal rx(rx on for receiving
                                                   packet), the timeout for rx on, reserved for future                       */
    __IOM uint32_t cca_rx_timeout_delay : 8;  /*!< [15..8] when txrx_timing is in cca rx, the timeout for cca processing,
                                                   reserved for future                                                       */
    __IOM uint32_t rx2tx_delay : 8;           /*!< [23..16] when txrx_timing is from rx to tx, the wait time for
                                                   tx rfup                                                                   */
    __IOM uint32_t tx2rx_delay : 8;           /*!< [31..24] when txrx_timing is from tx to rx, the wait time for
                                                   rx rfup                                                                   */
  } b;                                        /*!< bit fields for mac_phy_to_dly */
} mac_phy_to_dly_t, *pmac_phy_to_dly_t;

/**
  \brief Union type to access mac_tx_prg_reg_0 (@ 0x00000590).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000590) MAC TX backup register 0                                   */

  struct {
    __IOM uint32_t standby_pg_data : 16;      /*!< [15..0] the PHY register programming data when PHY enternign
                                                   standby state                                                             */
    __IOM uint32_t tx_bkprg0_pg_data : 16;    /*!< [31..16] PHY 'TX register backup 0 programming data                       */
  } b;                                        /*!< bit fields for mac_tx_prg_reg_0 */
} mac_tx_prg_reg_0_t, *pmac_tx_prg_reg_0_t;

/**
  \brief Union type to access mac_tx_prg_reg_1 (@ 0x00000594).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000594) MAC TX backup register 1                                   */

  struct {
    __IOM uint32_t tx_bkprg2_pg_data : 16;    /*!< [15..0] PHY 'TX register backup 2 programming data                        */
    __IOM uint32_t tx_bkprg1_pg_data : 16;    /*!< [31..16] PHY 'TX register backup 1 programming data                       */
  } b;                                        /*!< bit fields for mac_tx_prg_reg_1 */
} mac_tx_prg_reg_1_t, *pmac_tx_prg_reg_1_t;

/**
  \brief Union type to access mac_tx_prg_reg_2 (@ 0x00000598).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000598) MAC TX backup register 2                                   */

  struct {
    __IOM uint32_t tx_bkprg0_pg_addr : 8;     /*!< [7..0] PHY TX register backup 0 programming address                       */
    __IOM uint32_t tx_bkprg1_pg_addr : 8;     /*!< [15..8] PHY TX register backup 1 programming address                      */
    __IOM uint32_t tx_bkprg2_pg_addr : 8;     /*!< [23..16] PHY TX register backup 2 programming address                     */
    __IOM uint32_t tx_bkprg1_en : 1;          /*!< [24..24] tx backup programming1 enable; it programmed start
                                                   from radio GAIN state in order(bkprg0 first, and bkprg1/2
                                                   as following) by HW:0: disable; 1:enable                                  */
    __IOM uint32_t tx_bkprg2_en : 1;          /*!< [25..25] tx backup programming2 enable; it programmed start
                                                   from radio GAIN state in order(bkprg0->bkprg1->bkprg2)
                                                   by HW: 0: disable; 1:enable                                               */
    __IOM uint32_t rx_bkprg0_en : 1;          /*!< [26..26] rx backup programming0 enable; it programmed in order(bkprg0->bkprg1-
                                                   bkprg2) by HW:0: disable; 1:enable                                        */
    __IOM uint32_t rx_bkprg1_en : 1;          /*!< [27..27] rx backup programming1 enable; it programmed in order(bkprg0
                                                   first, and bkprg1/2 as following) by HW: 0: disable; 1:enable             */
    __IOM uint32_t rx_bkprg2_en : 1;          /*!< [28..28] rx backup programming2 enable; it programmed in order(bkprg0
                                                   first, and bkprg1/2 as following) by HW: 0: disable; 1:enable             */
    __IOM uint32_t rx_bkprg0_mode_en : 1;     /*!< [29..29] rx backup programming0 mode enable;mode enable indicator
                                                   the programming setting is before RECV or after RECV state;
                                                   0: before RECV; 1: after RECV                                             */
    __IOM uint32_t rx_bkprg1_mode_en : 1;     /*!< [30..30] rx backup programming1 mode enable;mode enable indicator
                                                   the programming setting is before RECV or after RECV state;0:
                                                   before RECV; 1: after RECV                                                */
    __IOM uint32_t rx_bkprg2_mode_en : 1;     /*!< [31..31] rx backup programming2 mode enable;mode enable indicator
                                                   the programming setting is before RECV or after RECV state;
                                                   0: before RECV; 1: after RECV                                             */
  } b;                                        /*!< bit fields for mac_tx_prg_reg_2 */
} mac_tx_prg_reg_2_t, *pmac_tx_prg_reg_2_t;

/**
  \brief Union type to access mac_rx_prg_reg_0 (@ 0x0000059C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000059C) MAC RX backup register 0                                   */

  struct {
    __IOM uint32_t rx_bkprg0_pg_data : 16;    /*!< [15..0] PHY RX register backup 0 programming data                         */
    __IOM uint32_t rx_bkprg1_pg_data : 16;    /*!< [31..16] PHY RX register backup 1 programming data                        */
  } b;                                        /*!< bit fields for mac_rx_prg_reg_0 */
} mac_rx_prg_reg_0_t, *pmac_rx_prg_reg_0_t;

/**
  \brief Union type to access mac_rx_prg_reg_1 (@ 0x000005A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005A0) MAC RX backup register 1                                   */

  struct {
    __IOM uint32_t rx_bkprg2_pg_data : 16;    /*!< [15..0] PHY RX register backup 2 programming data                         */
    __IOM uint32_t rx_bkprg0_pg_addr : 8;     /*!< [23..16] PHY RX register backup 0 programming address                     */
    __IOM uint32_t rx_bkprg1_pg_addr : 8;     /*!< [31..24] PHY RX register backup 1 programming address                     */
  } b;                                        /*!< bit fields for mac_rx_prg_reg_1 */
} mac_rx_prg_reg_1_t, *pmac_rx_prg_reg_1_t;

/**
  \brief Union type to access mac_rx_prg_reg_2r (@ 0x000005A4).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x000005A4) MAC/PHY RX backup register 2                               */

  struct {
    __IM  uint32_t rx_bkprg2_pg_addr : 8;   /*!< [7..0] PHY RX register backup 2 programming address                       */
    __IM  uint32_t channel  : 7;            /*!< [14..8] Channel Number: IEEE 802.15.4 2.4GHz band channels:
                                                 Channel Frq. = 2402 MHz + channel (MHz)                                   */
    __IM  uint32_t opt_cca_ed_or : 1;       /*!< [15..15] 1: use phy_cca_busy equals ed_busy or cca busy when
                                                 cca_mode equals 3 ; 0 : use phy_cca_busy equals ed_busy
                                                 and cca busy when cca_mode equals 3                                       */
    __IM  uint32_t bkrpt0_read_data : 16;   /*!< [31..16] PHY register report 0 read data                                  */
  } b;                                        /*!< bit fields for mac_rx_prg_reg_2r */
} mac_rx_prg_reg_2r_t, *pmac_rx_prg_reg_2r_t;

/**
  \brief Union type to access mac_rx_prg_reg_2w (@ 0x000005A4).
*/
typedef union {
  __OM  uint32_t w;                         /*!< (@ 0x000005A4) MAC/PHY RX backup register 2                               */

  struct {
    __OM  uint32_t rx_bkprg2_pg_addr : 8;   /*!< [7..0] PHY RX register backup 2 programming address                       */
    __OM  uint32_t channel  : 7;            /*!< [14..8] Channel Number: IEEE 802.15.4 2.4GHz band channels:
                                                 Channel Frq. = 2402 MHz + channel (MHz)                                   */
    __OM  uint32_t opt_cca_ed_or : 1;       /*!< [15..15] 1: use phy_cca_busy equals ed_busy or cca busy when
                                                 cca_mode equals 3 ; 0 : use phy_cca_busy equals ed_busy
                                                 and cca busy when cca_mode equals 3                                       */
    __OM  uint32_t bkrpt0_reg_addr : 8;     /*!< [23..16] PHY register report 0 address. Set bit 7 = 0 for register
                                                 read                                                                      */
    __OM  uint32_t bkrpt0_en : 1;           /*!< [24..24] rx backup report0 enable; it programmed only after
                                                 RECV and report it in order(bkrpt0 first, and bkrpt1/2/3/4
                                                 as following) by HW: 0: disable; 1:enable                                 */
          uint32_t          : 7;
  } b;                                        /*!< bit fields for mac_rx_prg_reg_2w */
} mac_rx_prg_reg_2w_t, *pmac_rx_prg_reg_2w_t;

/**
  \brief Union type to access mac_rx_bkrpt0r (@ 0x000005A8).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x000005A8) PHY RX backup register 0                                   */

  struct {
    __IM  uint32_t bkrpt2_read_data : 16;   /*!< [15..0] PHY register report 2 read data                                   */
    __IM  uint32_t bkrpt1_read_data : 16;   /*!< [31..16] PHY register report 1 read data                                  */
  } b;                                        /*!< bit fields for mac_rx_bkrpt0r */
} mac_rx_bkrpt0r_t, *pmac_rx_bkrpt0r_t;

/**
  \brief Union type to access mac_rx_bkrpt0w (@ 0x000005A8).
*/
typedef union {
  __OM  uint32_t w;                         /*!< (@ 0x000005A8) PHY RX backup register 0                                   */

  struct {
    __OM  uint32_t bkrpt2_reg_addr : 8;     /*!< [7..0] PHY register report 2 address. Set bit 7 = 0 for register
                                                 read.                                                                     */
    __OM  uint32_t bkrpt2_en : 1;           /*!< [8..8] rx backup report2 enable; it programmed only after RECV
                                                 and report it in order(bkrpt0 first, and bkrpt1/2/3/4 as
                                                 following) by HW:0: disable; 1:enable                                     */
          uint32_t          : 7;
    __OM  uint32_t bkrpt1_reg_addr : 8;     /*!< [23..16] PHY register report 1 address. Set bit 7 = 0 for register
                                                 read.                                                                     */
    __OM  uint32_t bkrpt1_en : 1;           /*!< [24..24] rx backup report1 enable; it programmed only after
                                                 RECV and report it in order(bkrpt0 first, and bkrpt1/2/3/4
                                                 as following) by HW:0: disable; 1:enable                                  */
          uint32_t          : 7;
  } b;                                        /*!< bit fields for mac_rx_bkrpt0w */
} mac_rx_bkrpt0w_t, *pmac_rx_bkrpt0w_t;

/**
  \brief Union type to access mac_rx_bkrpt1r (@ 0x000005AC).
*/
typedef union {
  __IOM uint32_t w;                         /*!< (@ 0x000005AC) PHY RX backup register 1                                   */

  struct {
    __IM  uint32_t bkrpt4_read_data : 16;   /*!< [15..0] PHY register report 4 read data                                   */
    __IM  uint32_t bkrpt3_read_data : 16;   /*!< [31..16] PHY register report 3 read data                                  */
  } b;                                        /*!< bit fields for mac_rx_bkrpt1r */
} mac_rx_bkrpt1r_t, *pmac_rx_bkrpt1r_t;

/**
  \brief Union type to access mac_rx_bkrpt1w (@ 0x000005AC).
*/
typedef union {
  __OM  uint32_t w;                         /*!< (@ 0x000005AC) PHY RX backup register 1                                   */

  struct {
    __OM  uint32_t bkrpt4_reg_addr : 8;     /*!< [7..0] PHY register report 4 address. Set bit 7 = 0 for register
                                                 read.                                                                     */
    __OM  uint32_t bkrpt4_en : 1;           /*!< [8..8] rx backup report4 enable; it programmed only after RECV
                                                 and report it in order(bkrpt0 first, and bkrpt1/2/3/4 as
                                                 following) by HW:0: disable; 1:enable                                     */
          uint32_t          : 7;
    __OM  uint32_t bkrpt3_reg_addr : 8;     /*!< [23..16] PHY register report 3 address. Set bit 7 = 0 for register
                                                 read.                                                                     */
    __OM  uint32_t bkrpt3_en : 1;           /*!< [24..24] rx backup report3 enable; it programmed only after
                                                 RECV and report it in order(bkrpt0 first, and bkrpt1/2/3/4
                                                 as following) by HW:0: disable; 1:enable                                  */
          uint32_t          : 7;
  } b;                                        /*!< bit fields for mac_rx_bkrpt1w */
} mac_rx_bkrpt1w_t, *pmac_rx_bkrpt1w_t;

/**
  \brief Union type to access mac_phy_early_afe (@ 0x000005B0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005B0) PHY Early Analog Fron End On Time Control Register         */

  struct {
    __IOM uint32_t rxon_early_afe : 8;        /*!< [7..0] time to eraly trun on RF before entering RX ON state               */
    __IOM uint32_t txon_early_afe : 8;        /*!< [15..8] time to eraly trun on RF before entering TX ON state              */
    __IOM uint32_t rampdown_delay_zb : 6;     /*!< [21..16] the time delay for PHY entering ramp-standby state
                                                   from TRAN state, in 1us                                                   */
          uint32_t            : 10;
  } b;                                        /*!< bit fields for mac_phy_early_afe */
} mac_phy_early_afe_t, *pmac_phy_early_afe_t;

/**
  \brief Union type to access mac_mac_rf_state (@ 0x000005B4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005B4) RF State Indication Register for MAC-PHY interface         */

  struct {
    __IM  uint32_t txrx_cst   : 5;            /*!< [4..0] TX/RX current state                                                */
    __IM  uint32_t radio_cst  : 5;            /*!< [9..5] Radio current state0: IDLE; 6: PRETURNON; 7: RECV;                 */
    __IOM uint32_t dbg_sel    : 4;            /*!< [13..10] debug port selection bit[3:0], bit[4] at REG0x5B4[24]zb_rf_debug
                                                   port select: 0: tx/rx state machine debug port 0 1: tx/rx
                                                   state machine debug port 1 2: radio state machine debug
                                                   port 0 3: radio state machine debug port 1 4: radio state
                                                   machine debug port 2 5: radio state machine debug port
                                                   3                                                                         */
    __IM  uint32_t zb_rx_hit_flg : 1;         /*!< [14..14] latch zb_rx_hit , and be cleared when leave RX state(for
                                                   debug)                                                                    */
    __IM  uint32_t rxframe    : 1;            /*!< [15..15] latch rxm enable(for debug)                                      */
    __IM  uint32_t rxlength   : 7;            /*!< [22..16] the frame length of receiving frame, it will be cleared
                                                   on next RXON (for debug)                                                  */
    __IM  uint32_t zb_rx_full_and_hit_flg : 1;/*!< [23..23] latch zb_rx_hit and rxfifo_full2(for debug)                      */
    __IOM uint32_t dbg_sel_b4 : 1;            /*!< [24..24] bit4 of dbg_sel                                                  */
    __IM  uint32_t zb_lut_state : 2;          /*!< [26..25] PHY arbitration state with BT BR/EDR concurrent (for
                                                   debug)when PHY is granted, TXM/RXM/Radio state will wait
                                                   le_block = 0                                                              */
          uint32_t            : 5;
  } b;                                        /*!< bit fields for mac_mac_rf_state */
} mac_mac_rf_state_t, *pmac_mac_rf_state_t;

/**
  \brief Union type to access mac_dbg_sig (@ 0x000005B8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005B8) Signal Latch for Debug                                     */

  struct {
    __IM  uint32_t zb_rx_hit_cnt : 16;        /*!< [15..0] zb_rx_hit count, increase 1 on every zb_rx_hit. Write
                                                   1 to gr_dbg_cnt_reset_o (reg 0x90[5]) to clear this count.                */
          uint32_t            : 16;
  } b;                                        /*!< bit fields for mac_dbg_sig */
} mac_dbg_sig_t, *pmac_dbg_sig_t;

/**
  \brief Union type to access mac_cca_dbg (@ 0x000005BC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005BC) CCA Machine signal latch for debug register                */

  struct {
    __IM  uint32_t zb_cca_rpt : 4;            /*!< [3..0] latch zb_cca_rpt for debugging                                     */
    __IM  uint32_t zb_ed_rpt  : 8;            /*!< [11..4] latch zb_ed_rpt for debugging                                     */
    __IM  uint32_t rx_cca_duration : 1;       /*!< [12..12] latch rx_cca_duration for debugging                              */
    __IM  uint32_t not_cca_turn_tx : 1;       /*!< [13..13] latch not_cca_trun_tx for debugging                              */
    __IM  uint32_t not_cca_turn_rx : 1;       /*!< [14..14] latch not_cca_trun_rx for debugging                              */
    __IM  uint32_t phy_cca_i  : 1;            /*!< [15..15] latch phy_cca_i for debugging                                    */
    __IM  uint32_t txm_txpe   : 1;            /*!< [16..16] latch txm_txpe for debugging                                     */
    __IM  uint32_t no_cca_vld_flg : 1;        /*!< [17..17] latch no_cca_vld_flg for debugging                               */
          uint32_t            : 14;
  } b;                                        /*!< bit fields for mac_cca_dbg */
} mac_cca_dbg_t, *pmac_cca_dbg_t;

/**
  \brief Union type to access mac_cca_dbg1 (@ 0x000005C0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005C0) CCA Machine signal latch for debug register                */

  struct {
    __IM  uint32_t zb_rx_cca_cnt : 16;        /*!< [15..0] CCA process count, increase 1 on every CCA process start.
                                                   Write 1 to reg 0x63[6] to clear this count.                               */
    __IM  uint32_t zb_cca_vld_cnt : 16;       /*!< [31..16] zb_cca_vld count, increase 1 on every zb_cca_vld. Write
                                                   1 to reg 0x63[6] to clear this count.                                     */
  } b;                                        /*!< bit fields for mac_cca_dbg1 */
} mac_cca_dbg1_t, *pmac_cca_dbg1_t;

/**
  \brief Union type to access mac_rx_set1 (@ 0x000005C4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005C4) PHY RX Setup Control Register1                             */

  struct {
    __IOM uint32_t rx_min_len : 3;            /*!< [2..0] set the minimum frame length of RX Filter. Frame_length
                                                   < rx_min_len will not be received.                                        */
    __IOM uint32_t rxon_off_dly : 7;          /*!< [9..3] in us, last phy_rxrdy to rxm_frm end time duration and
                                                   add a little delay                                                        */
    __IOM uint32_t rxon2ccadt_dly : 4;        /*!< [13..10] in us, means rxon to csma_state==CCADT delay, used
                                                   in scheduled TX mode.                                                     */
          uint32_t            : 2;
    __IOM uint32_t ed_scan_rxon_delay : 8;    /*!< [23..16] in us, means rxon to ED Scan start delay                         */
    __IOM uint32_t rx2tx_imm_ack_delay : 8;   /*!< [31..24] in us, RX to TX delay for Imm-Ack TX.                            */
  } b;                                        /*!< bit fields for mac_rx_set1 */
} mac_rx_set1_t, *pmac_rx_set1_t;

/**
  \brief Union type to access mac_tx_enh_ack_ctrl (@ 0x000005C8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005C8) Enhance Ack(GTS1) TX Control Register                      */

  struct {
    __IOM uint32_t gts_enh_ack_timer : 8;     /*!< [7..0] the time window, in unit of us, for FW to set the Enh-Ack
                                                   TX trigger. The time window is opened when the rxif is
                                                   asserted and the received frame is a 2015 version frame
                                                   with ACK request, if the Enh-Ack frame for this response
                                                   is ready the the FW need to set the GTS FIFO TX trigger
                                                   during this time window.                                                  */
    __IOM uint32_t rx2tx_enh_ack_delay : 8;   /*!< [15..8] in us, the time delay for the trunning of PHY from RX
                                                   to TX to transmite Enh-Ack frame (in GTS1 FIFO)                           */
    __IM  uint32_t gts_enh_ack_trig_en : 1;   /*!< [16..16] indicates whether the time window is opened and the
                                                   Enh-Ack TX trigger is available. 0: the time windows is
                                                   closed (it's too late to trigger the Enh-Ack TX); 1: the
                                                   time windows is opened, set the Enh-Ack TX trigger is available.          */
    __IOM uint32_t alt_gts_enh_ack_mask : 1;  /*!< [17..17] FW set this bit to select the timer value for the RXM
                                                   to apply to the GTS Enh-Ack timer.0: use gts_enh_ack_timer
                                                   value; 1: use alt_gts_enh_ack_timer value;Normally, FW
                                                   set this bit to select a different time window for the
                                                   Enh-Ack trigger bit writting. Ex. the FW select a wider
                                                   time window when it will write the Enh-Ack TX trigger bit
                                                   in RX done interrupt handler rather than in RX early interrupt
                                                   handler. The RXM will latch this bit value when it starting
                                                   the Enh-Ack timer.                                                        */
          uint32_t            : 6;
    __IOM uint32_t alt_gts_enh_ack_timer : 8; /*!< [31..24] an alternate timer window, in unit of us, for FW to
                                                   set the timer for Enh-Ack TX trigger. The time window is
                                                   opened when the rxif is asserted and the received frame
                                                   is a 2015 version frame with ACK request, if the Enh-Ack
                                                   frame for this response is ready the the FW need to set
                                                   the GTS FIFO TX trigger during this time window. The GTS
                                                   TX FIFO encryption will takes time depends on the frame
                                                   length to encrypt, so the FW may need to adjust the timer
                                                   value to make the Enh-Ack frame TX at a proper time to
                                                   have a                                                                    */
  } b;                                        /*!< bit fields for mac_tx_enh_ack_ctrl */
} mac_tx_enh_ack_ctrl_t, *pmac_tx_enh_ack_ctrl_t;

/**
  \brief Union type to access mac_pta_ctrl1 (@ 0x000005F8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005F8) PTA Control Register 1                                     */

  struct {
    __IOM uint32_t pta_en     : 1;            /*!< [0..0] PTA (packet transmission arbitration) for WIFI + 802.15.4
                                                   function enable control:0: disable PTA function (default),
                                                   ignore PTA WL_ACT signal and no abort TX/RX1: enable PTA
                                                   function, abort TX/RX when PTA WL_ACT is high                             */
    __IOM uint32_t pta_share_lna : 1;         /*!< [1..1] FW use this bit to indicate the PTA HW whether BT PHY
                                                   share LAN with WIFI: 1: wifi/BT share LNA. 0: wifi/BT dedicated
                                                   LNA and zigbee acc hit will trigger high priority request
                                                   if original RX PTA priority is low                                        */
    __IOM uint32_t cca_req    : 1;            /*!< [2..2] Dedicated PTA request for the CCA of a packet TX: 0:
                                                   no dedicated PTA request for CCA. Only issue 1 PTA request
                                                   for CCA + TX. 1: issue a RX PTA request for CCA and then
                                                   another PTA request for TX. The priority of the PTA request
                                                   for CCA follows the priority setting of TX PTA request
                                                   (tx_priority).                                                            */
    __IOM uint32_t tx_priority : 1;           /*!< [3..3] The priority of PTA request for a packet TX: 0: issue
                                                   low priority PTA request for packet TX (include its CCA).
                                                   1: issue high priority PTA request for packet TX (include
                                                   its CCA).                                                                 */
          uint32_t            : 28;
  } b;                                        /*!< bit fields for mac_pta_ctrl1 */
} mac_pta_ctrl1_t, *pmac_pta_ctrl1_t;

/**
  \brief Union type to access mac_pta_ctrl0 (@ 0x000005FC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000005FC) PTA Control Register 0                                     */

  struct {
    __IOM uint32_t pta_duty_en : 1;           /*!< [0..0] enable PTA priority duty control function. When this
                                                   function is enabled, MAC will send high priority PTA request
                                                   for idle RX periodically. 0: disable PTA priority duty
                                                   control function (default); 1: enable PTA priority duty
                                                   control function the PTA duty interval will start with
                                                   high priority period when PTA priority duty control is
                                                   enabled.                                                                  */
    __IOM uint32_t dis_lo_rx_req : 1;         /*!< [1..1] disable low priority PTA request: 0: when RX is low priority,
                                                   issue a low priority PTA request. 1: when RX is low priority,
                                                   do not issue PTA request and ignore PTA WL_ACT signal.                    */
          uint32_t            : 2;
    __IOM uint32_t pta_tick_ctrl : 12;        /*!< [15..4] this field set the unit, in us, of a tick for the PTA
                                                   priority duty control function. The duty ratio of the PTA
                                                   with high priority control is based on this tick counting.
                                                   Time of a tick = 1 + the value of this field, in unit of
                                                   us. Example, set this field as 1 means time of a tick is
                                                   2us. default value is 1000us (1ms).                                       */
    __IOM uint32_t pta_low_duty_tick : 8;     /*!< [23..16] this field is used to set the time period of the low
                                                   priority part in a PTA priority duty control interval,
                                                   in unit of a tick. Low priority period = (1 + value of
                                                   this filed)* (tick time). Example, set this filed value
                                                   as 1 means the time period of low priority is 2 ticks time.
                                                   default value is 100 ticks (100ms).                                       */
    __IOM uint32_t pta_high_duty_tick : 8;    /*!< [31..24] this field is used to set the time period of the high
                                                   priority part in a PTA priority duty control interval,
                                                   in unit of a tick. High priority period = (1 + value of
                                                   this filed)* (tick time). Example, set this filed value
                                                   as 3 means the time period of high priority is 4 ticks
                                                   time. default value is 100 ticks (100ms).                                 */
  } b;                                        /*!< bit fields for mac_pta_ctrl0 */
} mac_pta_ctrl0_t, *pmac_pta_ctrl0_t;

/** @} */ /* End of group ls_hal_mac_reg */
/// @endcond /* End of condition DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_MAC_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _MAC_REG_TYPE_H_

