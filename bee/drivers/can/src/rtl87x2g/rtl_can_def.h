/**
*****************************************************************************************
*     Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
* \file    rtl_can_def.h
* \brief   CAN related definitions for RTL87x2G.
* \author
* \date    2023-11-16
* \version v1.0
* *************************************************************************************
*/

#ifndef RTL_CAN_DEF_H
#define RTL_CAN_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
// #include "access.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          CAN Features
 *============================================================================*/
#define CAN_SUPPORT_EXT_LOOPBACK                         (0) //!< The function is not supported.
#define CAN_SUPPORT_INT_MSK_STS                          (0) //!< The function is not supported.
#define CAN_SUPPORT_SLEEP_MODE                           (0) //!< The function is not supported.

/*============================================================================*
 *                         Types
 *============================================================================*/
/**
* \brief       CAN clock divider definition.
*
* \ingroup     CAN_Exported_Types
*/
typedef enum
{
    CAN_CLOCK_DIVIDER_1 = 0,      //!< DVI = 1 (40M / 1).
    CAN_CLOCK_DIVIDER_2 = 1,      //!< DVI = 2 (40M / 2).
} CANClockDiv_TypeDef;

#define IS_CAN_CLK_DIV(DIV)              (((DIV) == CAN_CLOCK_DIVIDER_1) || \
                                          ((DIV) == CAN_CLOCK_DIVIDER_2)) //!< Check if the input parameter is valid.

/**
* \brief       CAN clock source definition.
*
* \ingroup     CAN_Exported_Types
*/
typedef enum
{
    CAN_CLOCK_SRC_40M,      //!< The clock source of can is 40MHz.
} CANClockSrc_TypeDef;

#define IS_SPI_CLK_SOURCE(PERIPH)     ((PERIPH) == CAN_CLOCK_SRC_40M) //!< Check if the input parameter is valid.

/*============================================================================*
 *                          CAN Registers Memory Map
 *============================================================================*/
typedef struct            /*!< CAN Structure */
{
    __IO uint32_t  CAN_CTL;              /*!< 0x00 */
    __IO uint32_t  CAN_STS;              /*!< 0x04 */
    __IO uint32_t  CAN_FIFO_STS;         /*!< 0x08 */
    __IO uint32_t  CAN_BIT_TIMING;       /*!< 0x0C */
    __IO uint32_t  CAN_RSVD_0X10;        /*!< 0x10 */
    __IO uint32_t  CAN_RSVD_0X14;        /*!< 0x14 */
    __IO uint32_t  CAN_INT_EN;           /*!< 0x18 */
    __IO uint32_t  CAN_MB_RXINT_EN;      /*!< 0x1C */
    __IO uint32_t  CAN_MB_TXINT_EN;      /*!< 0x20 */
    __IO uint32_t  CAN_INT_FLAG;         /*!< 0x24 */
    __IO uint32_t  CAN_ERR_STATUS;       /*!< 0x28 */
    __IO uint32_t  CAN_ERR_CNT_CTL;      /*!< 0x2C */
    __IO uint32_t  CAN_ERR_CNT_STS;      /*!< 0x30 */
    __IO uint32_t  CAN_TX_ERROR_FLAG;    /*!< 0x34 */
    __IO uint32_t  CAN_TX_DONE;          /*!< 0x38 */
    __IO uint32_t  CAN_RX_DONE;          /*!< 0x3C */
    __IO uint32_t  CAN_TIME_STAMP;       /*!< 0x40 */
    __IO uint32_t  CAN_MB_TRIGGER;       /*!< 0x44 */
    __IO uint32_t  CAN_RXDMA_MSIZE;      /*!< 0x48 */
    __IO uint32_t  CAN_RX_DMA_DATA;      /*!< 0x4C */
    __IO uint32_t  CAN_SLEEP_MODE;       /*!< 0x50 */
    __IO uint32_t  CAN_TEST;             /*!< 0x54 */
    uint32_t  CAN_RSVD[42];              /*!< 0x58:0xFC */
    __IO uint32_t  CAN_MB0_15_STS[16];   /*!< 0x100:0x13C */
    uint32_t  CAN_RSVD1[48];             /*!< 0x140:0x1FC */
    __IO uint32_t  CAN_MB0_15_CTRL[16];  /*!< 0x200:0x23C */
    uint32_t  CAN_RSVD2[44];             /*!< 0x240:0x2EC */
    __IO uint32_t  CAN_MB_BA_END;        /*!< 0x2F0 */
    uint32_t  CAN_RSVD3[3];              /*!< 0x2F4:0x2FC */
    uint32_t  CAN_RSVD4[14];             /*!< 0x300:0x334 */
    __IO uint32_t  CAN_RAM_DATA[2];      /*!< 0x338:0x33C */
    __IO uint32_t  CAN_RAM_ARB;          /*!< 0x340 */
    __IO uint32_t  CAN_RAM_MASK;         /*!< 0x344 */
    __IO uint32_t  CAN_RAM_CS;           /*!< 0x348 */
    __IO uint32_t  CAN_RAM_CMD;          /*!< 0x34C */
} CAN_TypeDef;

/*============================================================================*
 *                          CAN Declaration
 *============================================================================*/

#define CAN0                       ((CAN_TypeDef *) CAN_REG_BASE)
#define CAN                         CAN0

/*============================================================================*
 *                          CAN TYPE/API Wrappers
 *============================================================================*/
/** \defgroup CAN         CAN
  * \brief
  * \{
  */

/** \defgroup CAN_Exported_Constants CAN Exported Constants
  * \brief
  * \{
  */

/**
* \brief       To be compatible with the previous driver.
* \defgroup    CAN_Constants_Wrapper CAN Constants Wrapper
* \{
* \ingroup     CAN_Exported_Constants
*/

#define CAN_CLK_DIV_1              CAN_CLOCK_DIVIDER_1  //!< The macro is a wrapper for CAN_CLOCK_DIVIDER_1.
#define CAN_CLK_DIV_2              CAN_CLOCK_DIVIDER_2  //!< The macro is a wrapper for CAN_CLOCK_DIVIDER_2.

/** End of CAN Constants Wrapper
  * \}
  */

/** End of CAN_Exported_Constants
  * \}
  */

/** End of CAN
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_CAN_DEF_H */

