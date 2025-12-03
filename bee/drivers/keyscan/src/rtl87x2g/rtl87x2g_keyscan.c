/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_keyscan.c
* \brief    This file provides all the KEYSCAN firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_keyscan.h"
#include "rtl_rcc.h"
#include "app_section.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Store buffer to store KEYSCAN register data.
  * \return None.
  */
RAM_FUNCTION
void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    store_buf->keyscan_reg[0] = KEYSCAN->KEYSCAN_CLK_DIV;         /* 0x00 */
    store_buf->keyscan_reg[1] = KEYSCAN->KEYSCAN_CONFIG1;         /* 0x04 */
    store_buf->keyscan_reg[2] = KEYSCAN->KEYSCAN_CONFIG2;         /* 0x08 */
    store_buf->keyscan_reg[3] = KEYSCAN->KEYSCAN_COLUMN_CONFIG;   /* 0x0C */
    store_buf->keyscan_reg[4] = KEYSCAN->KEYSCAN_ROW_CONFIG;      /* 0x10 */
    store_buf->keyscan_reg[6] = KEYSCAN->KEYSCAN_INT_MASK;        /* 0x18 */

    return;
}

/**
  * \brief  Restore KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Restore buffer to restore KEYSCAN register data.
  * \return None
  */
RAM_FUNCTION
void KEYSCAN_DLPSExit(void *PeriReg, void *StoreBuf)
{
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    /* Set FSM to idle state */
    KEYSCAN->KEYSCAN_CONFIG2 &= ~BIT31;
    KEYSCAN->KEYSCAN_CLK_DIV = store_buf->keyscan_reg[0];
    KEYSCAN->KEYSCAN_CONFIG2 = (store_buf->keyscan_reg[2] & (~(BIT31)));
    KEYSCAN->KEYSCAN_CONFIG1 = store_buf->keyscan_reg[1];
    KEYSCAN->KEYSCAN_COLUMN_CONFIG = store_buf->keyscan_reg[3];
    KEYSCAN->KEYSCAN_ROW_CONFIG = store_buf->keyscan_reg[4];
    KEYSCAN->KEYSCAN_INT_MASK = store_buf->keyscan_reg[6];
    KEYSCAN->KEYSCAN_CONFIG2 |= (store_buf->keyscan_reg[2] & ((BIT31)));

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

