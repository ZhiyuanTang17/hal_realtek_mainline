/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_NVIC_H
#define RTL_NVIC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "rtl_nvic_def.h"

/** \defgroup NVIC        NVIC
  * \brief
  * \{
  */
/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup NVIC_Exported_Types NVIC Exported Types
  * \brief
  * \{
  */

/**
 * \brief       NVIC init structure definition
 *
 * \ingroup     NVIC_Exported_Types
 */

typedef struct
{
    int NVIC_IRQChannel;                    /*!< Specify the IRQ channel.
                                                 This parameter can be a value of \ref IRQn_Type */

    uint32_t NVIC_IRQChannelPriority;       /*!< Specify the priority for the IRQ channel.
                                                 This parameter can be a value between 0 and x as described in the table.*/

    FunctionalState NVIC_IRQChannelCmd;     /*!< Specify the IRQ channel to be enabled or disabled.*/
} NVIC_InitTypeDef;

/** End of NVIC_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup NVIC_Exported_Functions NVIC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief   Initialize the NVIC peripheral according to the specified
 *          parameters in NVIC_InitStruct.
 *
 * \param[in] NVIC_InitStruct  Pointer to a NVIC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void nvic_config(void)
 * {
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = RTC_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * \endcode
 */
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct);

/** End of NVIC_Exported_Functions
  * \}
  */

/** End of NVIC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_NVIC_H */

