/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lpqdec.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Get LPQDEC X-Axis direction.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter parameter can be one of the following values:
  *         \arg  LPQDEC_AXIS_X: The LPQDEC X axis.
  * \return The direction of the axis. This parameter parameter can be one of the following values:
  *         \retval LPQDEC_AXIS_DIR_UP: The axis is rolling up.
  *         \retval LPQDEC_AXIS_DIR_DOWN: The axis is rolling down.
  */
bool LPQDEC_GetAxisDirection(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS_DIR(LPQDEC_AXIS));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr1x = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    return lpqdec_sr1x.b.cnt_dir;
}

/**
  * \brief  Get current state of phase.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \return The current state of phase. \ref LPQDECPhase_TypeDef
  */
LPQDECPhase_TypeDef LPQDEC_GetPhaseState(LPQDEC_TypeDef *LPQDECx)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr_1 = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    LPQDECPhase_TypeDef phase = LPQDEC_PHASE_MODE0;

    phase = lpqdec_sr_1.b.pha_sta | (lpqdec_sr_1.b.phb_sta << 1);

    return phase;
}


