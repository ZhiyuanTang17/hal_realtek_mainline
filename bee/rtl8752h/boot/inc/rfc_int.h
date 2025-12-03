/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _RFC_INT_H_
#define _RFC_INT_H_

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "phy_common_int.h"
#include "rfc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Types
 *============================================================================*/
/* Pmax */
typedef struct
{
    int8_t celsius;
    int8_t txpower_pmax;
} PMAX_TABLE_TYPE;

/* RFC system */
typedef struct
{
    uint8_t rfc_reg_invalid_platform:       1;
    uint8_t rfc_reg_invalid_mac:            1;
    uint8_t rsvd:                           6;

#if (SUPPORT_LEGACY == 1)
    uint8_t edr_txgain_backoff; //unit: 0.5dB
#endif

    /* Tx Gain Index Register Boundry */
    uint8_t txgain_upperbound[NUM_RF_MODE];
    uint8_t txgain_lowerbound[NUM_RF_MODE];

    /* Post Processing */
    uint8_t (*post_processing_table[NUM_TXGAIN_TYPE])[2];
    uint8_t post_processing_table_size[NUM_TXGAIN_TYPE];

    /* Tx Power Boundry */
    int8_t tx_power_upperbound[NUM_RF_MODE];
    int8_t tx_power_lowerbound[NUM_RF_MODE];

    /* TX Power <-> Txgain index */
#if (SUPPORT_POLAR_TX == 1)
    uint8_t polar_tx_txgain_mapping_0dBm;
#endif
#if (SUPPORT_IQM_MODE == 1)
    uint8_t iqm_txgain_mapping_0dBm;
#endif
#if (SUPPORT_TPM_MODE == 1)
    int8_t *tpm_txpower_table;
    uint8_t tpm_txpower_table_size;
#endif

    /* Pmax */
    PMAX_TABLE_TYPE *pmax_table[NUM_TXGAIN_TYPE];
    uint8_t pmax_table_size[NUM_TXGAIN_TYPE];

    uint8_t mac_ctrl_stack;
} RFC_SYSTEM;

/* RFC config */
typedef struct
{
    uint8_t flatk_log:                      1;
    uint8_t rsvd:                           7;
} RFC_LOG_OPTION;

typedef union
{
    uint8_t u8;
    struct
    {
#if (SUPPORT_POLAR_TX == 1)
        uint8_t polar_tx:   1;
#endif
#if (SUPPORT_IQM_MODE == 1)
        uint8_t iqm_mode:   1;
#endif
#if (SUPPORT_TPM_MODE == 1)
        uint8_t tpm_mode:   1;
#endif
uint8_t rsvd: (8 - (SUPPORT_POLAR_TX + SUPPORT_IQM_MODE + SUPPORT_TPM_MODE));
    };
} RF_MODE_VALID_TYPE;

typedef struct
{
    RF_MODE_VALID_TYPE rf_mode_valid;

    uint8_t enable_pmax:                    1;
    uint8_t rsvd0:                          7;

    int8_t max_tx_power[NUM_RF_MODE][NUM_TXGAIN_TYPE];

    RFC_LOG_OPTION log_option;

    uint8_t rsvd1[16];
} __attribute__((packed)) RFC_CFG;

/*============================================================================*
 *                              Variables
 *============================================================================*/
extern RFC_SYSTEM rfc_system;
extern RFC_CFG rfc_cfg;

extern PHY_SCRIPT_TYPE rfc_init_script;
extern PHY_SCRIPT_TYPE rfc_init_fw_ret_script_mac;
extern PHY_SCRIPT_TYPE rfc_init_fw_ret_script_platform;

#if (SUPPORT_TPM_MODE == 1)
extern int8_t tpm_txpower_table[18];
#endif

/* ========== APIs registered from lowerstack ========== */
extern void (*pf_mac_set_radio_control_bit)(bool);
extern bool (*pf_mac_check_radio_control_ready)(void);
/* ========== End of APIs registered from lowerstack ========== */

extern void (*mac_rfc_function_register)(MAC_RFC_FUNC_NAME, void *);

extern void (*rfc_hw_control_init)(bool);
extern void (*rfc_control_set)(bool);
extern bool (*rfc_control_get)(void);
extern bool (*rfc_control_wait_ready_us)(uint32_t);
extern bool (*rfc_control_wait_ready)(uint32_t);

extern uint8_t (*rfc_get_rck)(void);
extern void (*rfc_set_rck)(uint8_t);
#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
extern void (*rf_set_flatk)(int8_t *);
#endif
#if (SUPPORT_IQM_MODE == 1)
extern void (*rfc_set_vco_tx_currentk)(uint8_t);
extern void (*rfc_set_vco_rx_currentk)(uint8_t);
extern uint16_t (*rfc_get_lok)(void);
extern void (*rfc_set_lok)(uint16_t);
#endif
extern void (*rfc_set_rxiqk)(uint8_t);

/* RFC restore flow */
extern void (*rfc_store_platform)(void);
extern void (*rfc_restore_platform)(void);
extern void (*rfc_restore_mac)(void);

/* Tx power <-> Txgain index */
extern void (*execute_post_processing)(uint8_t *, TXGAIN_TYPE, RF_MODE, bool);
extern int8_t (*(txgain_to_power_conversion[NUM_RF_MODE]))(uint8_t, TXGAIN_TYPE);
extern uint8_t (*(power_to_txgain_conversion[NUM_RF_MODE]))(int8_t, TXGAIN_TYPE);

/* Tx Power */
extern int8_t (*get_config_max_tx_power)(TXGAIN_TYPE, RF_MODE);
extern int8_t (*get_tx_power_upperbound)(TXGAIN_TYPE, RF_MODE);
extern int8_t (*get_tx_power_lowerbound)(TXGAIN_TYPE, RF_MODE);
extern int8_t (*tx_power_fit_pmax)(int8_t, TXGAIN_TYPE, RF_MODE);

extern void (*rfc_set_lut_syn_if_table)(uint16_t, uint32_t);

/*============================================================================*
 *                              Functions
 *============================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* _RFC_INT_H_ */

