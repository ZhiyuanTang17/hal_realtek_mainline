/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_wakeup.h"
#include "rtl_pinmux.h"
#include "rtl_nvic.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define DEBOUNCE_GROUP_USED_MASK    (0xFFFFFFF0)
static uint32_t debounce_group_allocated_mask = DEBOUNCE_GROUP_USED_MASK;

#define PAD_BIT_TABLE_OFFSET        (11)
#define PAD_ITEM(reg_addr, bit_num) (reg_addr | (bit_num << PAD_BIT_TABLE_OFFSET))
#define PAD_ITEM_ADDR(item)         (item & 0x7FF)
#define PAD_ITEM_BIT_OFFSET(item)   ((item & 0xF800) >> PAD_BIT_TABLE_OFFSET)

#define PAD_INT_STS_W1C_MASK_GROUP0   0x00FFF0FF
#define PAD_INT_STS_W1C_MASK_GROUP1   0x1FEC07FF
#define PAD_INT_STS_W1C_MASK_GROUP2   0x58000000
#define PAD_INT_STS_W1C_MASK_GROUP3   0x7E000000

static void Pad_Handler(void);

static volatile uint64_t pad_int_used_mask = 0x0;

extern const PADAddrTable_TypeDef pad_addr_table;
const PADAddrTable_TypeDef wakeup_status_table =
{
    .reg[P0_0] =        PAD_ITEM(0x17C, 0),
    .reg[P0_1] =        PAD_ITEM(0x17C, 1),
    .reg[P0_2] =        PAD_ITEM(0x17C, 2),
    .reg[P0_3] =        PAD_ITEM(0x17C, 3),
    .reg[P0_4] =        PAD_ITEM(0x17C, 4),
    .reg[P0_5] =        PAD_ITEM(0x17C, 5),
    .reg[P0_6] =        PAD_ITEM(0x17C, 6),
    .reg[P0_7] =        PAD_ITEM(0x17C, 7),
    .reg[P1_0] =        PAD_ITEM(0x17C, 12),
    .reg[P1_1] =        PAD_ITEM(0x17C, 13),
    .reg[P1_6] =        PAD_ITEM(0x17C, 14),
    .reg[P1_7] =        PAD_ITEM(0x17C, 15),
    .reg[P2_0] =        PAD_ITEM(0x17C, 16),
    .reg[P2_1] =        PAD_ITEM(0x17C, 17),
    .reg[P2_2] =        PAD_ITEM(0x17C, 18),
    .reg[P2_3] =        PAD_ITEM(0x17C, 19),
    .reg[P2_4] =        PAD_ITEM(0x17C, 20),
    .reg[P2_5] =        PAD_ITEM(0x17C, 21),
    .reg[P2_6] =        PAD_ITEM(0x17C, 22),
    .reg[P2_7] =        PAD_ITEM(0x17C, 23),
    .reg[P3_0] =        PAD_ITEM(0x180, 0),
    .reg[P3_1] =        PAD_ITEM(0x180, 1),
    .reg[P3_2] =        PAD_ITEM(0x180, 2),
    .reg[P3_3] =        PAD_ITEM(0x180, 3),
    .reg[P3_4] =        PAD_ITEM(0x180, 4),
    .reg[P3_5] =        PAD_ITEM(0x180, 5),
    .reg[P3_6] =        PAD_ITEM(0x180, 6),
    .reg[P4_0] =        PAD_ITEM(0x180, 7),
    .reg[P4_1] =        PAD_ITEM(0x180, 8),
    .reg[P4_2] =        PAD_ITEM(0x180, 9),
    .reg[P4_3] =        PAD_ITEM(0x180, 10),
    .reg[MICBIAS] =     PAD_ITEM(0x184, 30),
    .reg[P5_1] =        PAD_ITEM(0x180, 18),
    .reg[P5_2] =        PAD_ITEM(0x180, 19),
    .reg[P6_0] =        PAD_ITEM(0x180, 21),
    .reg[P6_1] =        PAD_ITEM(0x180, 22),
    .reg[P6_2] =        PAD_ITEM(0x180, 23),
    .reg[P6_3] =        PAD_ITEM(0x180, 24),
    .reg[P6_4] =        PAD_ITEM(0x180, 25),
    .reg[P6_5] =        PAD_ITEM(0x180, 26),
    .reg[P6_6] =        PAD_ITEM(0x180, 27),
    .reg[P6_7] =        PAD_ITEM(0x180, 28),
    .reg[P7_0] =        PAD_ITEM(0x184, 27),
    .reg[P7_1] =        PAD_ITEM(0x184, 28),
    .reg[SPIC_CSN] =    PAD_ITEM(0x198, 30),
    .reg[SPIC_SCK] =    PAD_ITEM(0x198, 29),
    .reg[SPIC_SI] =     PAD_ITEM(0x198, 28),
    .reg[SPIC_SO] =     PAD_ITEM(0x198, 27),
    .reg[SPIC_WEN] =    PAD_ITEM(0x198, 26), /*!< P1_4 */
    .reg[SPIC_HOLDEN] = PAD_ITEM(0x198, 25), /*!< P1_3 */
};

/*============================================================================*
 *                        Public Functions
 *============================================================================*/
#if (PAD_SUPPORT_WAKEUP_DEBOUNCE_MULTI_GROUP == 1)
static uint8_t System_WakeUpDebounceGetGroup(uint8_t Pin_Num)
{
    for (uint8_t i = 0; i <= 3; i++)
    {
        if (((PAD_DEBOUNCE->MUX_SEL >> (i << 3)) & 0x3F) == 0x3F)
        {
            continue;
        }
        if (((PAD_DEBOUNCE->MUX_SEL >> (i << 3)) & 0x3F) == Pin_Num)
        {
            return i;
        }
    }
    return 4;
}

bool System_WakeUpDebounceMultiGroupEnable(uint8_t Pin_Num)
{
    bool is_alloc_success = false;
    uint8_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);

    if (deb_group <= 3)
    {
        /* Already allocate group */
        return true;
    }

    for (deb_group = 0; deb_group < 4; deb_group++)
    {
        if (!(debounce_group_allocated_mask & BIT(deb_group)))
        {
            debounce_group_allocated_mask |= BIT(deb_group);
            is_alloc_success = true;

            PAD_DEBOUNCE->MUX_SEL &= ~(0x3F << (deb_group << 3));
            PAD_DEBOUNCE->MUX_SEL |= (Pin_Num << (deb_group << 3));

            break;
        }
    }

    return is_alloc_success;
}

bool System_WakeUpDebounceMultiGroupDisable(uint8_t Pin_Num)
{
    uint8_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);

    if (deb_group <= 3)
    {
        debounce_group_allocated_mask &= ~BIT(deb_group);
        PAD_DEBOUNCE->MUX_SEL |= (0x3F << (deb_group << 3));

        return true;
    }

    return false;
}
#endif

/**
  * \brief  Enable the function of the wakeup system of the specified pin.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param  Polarity: use high or low level wakeu to wakeup system.
            This parameter is can be PAD_WAKEUP_POL_HIGH and PAD_WAKEUP_POL_LOW.
  * \param  DebounceEn: Enable or disable debounce function.
            This parameter is can be PAD_WK_DEBOUNCE_ENABLE and PAD_WK_DEBOUNCE_DISABLE.
  * \return None
  */
void System_WakeUpPinEnable(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef Polarity,
                            FunctionalState DebounceNewState)
{
    /* Disable PAD interrupt NVIC */
    NVIC_DisableIRQ(PAD_IRQn);

    /* Config PAD wakeup polarity */
    Pad_TableConfig(WAKEUP_POL, Pin_Num, Polarity);

    /* Config PAD wakeup debounce */
    Pad_TableConfig(PAD_DEB, Pin_Num, DebounceNewState);

    if (DebounceNewState == ENABLE)
    {
        System_WakeUpDebounceCmd(Pin_Num, ENABLE);
    }

    /* Enable PAD interrupt wakeup function */
    Pad_TableConfig(WAKEUP_EN, Pin_Num, ENABLE);

    /* Initialize NVIC only on first PIN enable */
    if (pad_int_used_mask == 0)
    {
        /* Record pad int use status */
        pad_int_used_mask |= BIT64(Pin_Num);

        /* Enable PAD interrupt at AON REG */
        AON_REG_WRITE_BITFIELD(AON_REG_SYSTEM_REG29X, GPIO_PORT_INT_EN, ENABLE);

        /* Config NVIC vector and enable */
        ram_vector_table_update(PAD_IRQn, (IRQ_Fun)Pad_Handler);

        NVIC_InitTypeDef pad_nvic;
        pad_nvic.NVIC_IRQChannel = PAD_IRQn;
        pad_nvic.NVIC_IRQChannelPriority = 5;
        pad_nvic.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
        NVIC_Init(&pad_nvic);

        /* Record pad int use status */
        pad_int_used_mask |= BIT64(Pin_Num);
    }
    else
    {
        /* Record pad int use status */
        pad_int_used_mask |= BIT64(Pin_Num);

        /* Re-enable NVIC for subsequent PINs */
        NVIC_EnableIRQ(PAD_IRQn);
    }
}

/**
  * \brief  Disable the function of the wakeup system of the specified pin.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \return None
  */
void System_WakeUpPinDisable(uint8_t Pin_Num)
{
    Pad_TableConfig(WAKEUP_EN, Pin_Num, DISABLE);

    /* Record pad int use status */
    pad_int_used_mask &= ~BIT64(Pin_Num);

    /* If no PAD use interrupt */
    if (pad_int_used_mask == 0)
    {
        /* Pad NVIC Disable */
        AON_REG_WRITE_BITFIELD(AON_REG_SYSTEM_REG29X, GPIO_PORT_INT_EN, DISABLE);

        NVIC_DisableIRQ(PAD_IRQn);
    }

}

/**
  * \brief  Check wake up pin interrupt status.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \return Pin interrupt status
  */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num)
{
    uint32_t reg_address = PAD_REG_BASE + PAD_ITEM_ADDR(wakeup_status_table.reg[Pin_Num]);
    uint32_t reg_value = PAD_REG_READ(reg_address);

    if (reg_value & BIT(PAD_ITEM_BIT_OFFSET(wakeup_status_table.reg[Pin_Num])))
    {
        return SET;
    }
    return RESET;
}

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE == 1)

/**
 * \brief  Enable or disable wakeup debounce function.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 *         \note: Pin_Num is invalid parameter for rtl87x2g series
 *                so that any pin can be filled in.
 * \param  FunctionalState: wakeup system enable or disable.
 *         \arg DISABLE: Disable wakeup.
 *         \arg ENABLE: Enable wakeup.
 * \return None.
 */
bool System_WakeUpDebounceCmd(uint8_t Pin_Num, FunctionalState NewState)
{
    Pad_TableConfig(PAD_DEB, Pin_Num, NewState);
    uint32_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);
    PAD_DEB_CNT_TypeDef pad_deb = {.d32 = PAD_DEBOUNCE->CNT[deb_group / 2]};
    if (deb_group % 2)
    {
        pad_deb.b.deb_cnt_h_en = NewState;
    }
    else
    {
        pad_deb.b.deb_cnt_l_en = NewState;
    }
    PAD_DEBOUNCE->CNT[deb_group / 2] = pad_deb.d32;

    return true;
}

/**
 * \brief  Config wak-up system debounce time.
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
 *         \note: Pin_Num is invalid parameter for rtl87x2g series
 *                so that any pin can be filled in.
 * \param  time: Debounce time, 1 ~ 255ms.
 * \return None.
 */
bool System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t TimeMs)
{
    uint32_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);
    PAD_DEB_CNT_TypeDef pad_deb = {.d32 = PAD_DEBOUNCE->CNT[deb_group / 2]};
    if (deb_group % 2)
    {
        pad_deb.b.deb_cnt_h_clk_div = 5;
        pad_deb.b.deb_cnt_h_cnt_limit = TimeMs - 1;
    }
    else
    {
        pad_deb.b.deb_cnt_l_clk_div = 5;
        pad_deb.b.deb_cnt_l_cnt_limit = TimeMs - 1;
    }
    PAD_DEBOUNCE->CNT[deb_group / 2] = pad_deb.d32;

    return true;
}

bool System_WakeUpDebounceTimeUs(uint8_t Pin_Num, uint32_t TimeUs)
{
    uint8_t deb_div = 0;
    for (deb_div = 0; deb_div <= 6 /* 0x7 is bypass divide */; deb_div++)
    {
        if (TimeUs <= ((1 << deb_div) * 8000))  /* (1 << 8) / (32000 / 1000 / 1000) = 8000 */
        {
            break;
        }
    }

    uint32_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);
    PAD_DEB_CNT_TypeDef pad_deb = {.d32 = PAD_DEBOUNCE->CNT[deb_group / 2]};
    if (deb_group % 2)
    {
        pad_deb.b.deb_cnt_h_clk_div = deb_div;
        pad_deb.b.deb_cnt_h_cnt_limit = TimeUs * 32 / 1000 / (1 << deb_div) - 1;
    }
    else
    {
        pad_deb.b.deb_cnt_l_clk_div = deb_div;
        pad_deb.b.deb_cnt_l_cnt_limit = TimeUs * 32 / 1000 / (1 << deb_div) - 1;
    }
    PAD_DEBOUNCE->CNT[deb_group / 2] = pad_deb.d32;

    return true;
}

/**
  * \brief  Check debounce wake up status.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  *         \note: Pin_Num is invalid parameter for rtl87x2g series
  *                so that any pin can be filled in.
  * \return Debounce wakeup status.
  */
uint8_t System_WakeUpDebounceStatus(uint8_t Pin_Num)
{
    uint32_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);

    return ((PAD_DEBOUNCE->STS & BIT(deb_group)) == BIT(deb_group));
}

/**
  * \brief  Clear debounce wake up status.
  * \note:  Call this API will clear the debunce wakeup status bit.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  *         \note: Pin_Num is invalid parameter for rtl87x2g series
  *                so that any pin can be filled in.
  * \return None.
  */
void System_WakeUpDebounceClear(uint8_t Pin_Num)
{
    uint32_t deb_group = System_WakeUpDebounceGetGroup(Pin_Num);

    PAD_DEBOUNCE->STS = BIT(deb_group);
}
#endif

/**
  * \brief  Enable or disable the function of the wakeup system of the specified pin.
  * \param  Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param  NewState: Enable or disable PAD wake up.
  *            This parameter can be one of the following values:
  *            \arg ENABLE: Enable PAD wake up system.
  *            \arg DISABLE: Disable PAD wake up system.
  * \return None.
  */
void System_WakeUpCmd(uint8_t Pin_Num, FunctionalState NewState)
{
    Pad_TableConfig(WAKEUP_EN, Pin_Num, NewState);
}

/**
  * \brief Set the polarity for the function of the wakeup system of the specified pin.
  * \param Pin_Num: Pin number to be configured. \ref Pin_Number.
  * \param Polarity: Polarity of wakeup system.
  *            This parameter can be the following:
  *            \arg SYSTEM_WAKEUP_POLARITY_HIGH: Use high level wakeup.
  *            \arg SYSTEM_WAKEUP_POLARITY_LOW: Use low level wakeup.
  * \return None.
  */
void System_SetWakeUpPinPolarity(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef WakeUpPolarity)
{
    Pad_TableConfig(WAKEUP_POL, Pin_Num, WakeUpPolarity);
}

/**
 * \brief  Clear the interrupt pendign bit of the specified pin
 * \param  Pin_Num: Pin number to be configured. \ref Pin_Number
 * \return None.
 */
void System_WakeUpClearINTPendingBit(uint8_t Pin_Num)
{
    /* Calculate the absolute register address based on the pin number lookup table */
    uint32_t reg_address = PAD_REG_BASE + PAD_ITEM_ADDR(wakeup_status_table.reg[Pin_Num]);
    /* Get the specific bit mask (Set '1' to the target bit) that needs to be cleared */
    uint32_t reg_value = BIT(PAD_ITEM_BIT_OFFSET(wakeup_status_table.reg[Pin_Num]));
    /* Variable to store the mask of ALL W1C (Write 1 to Clear) bits in the target register */
    uint32_t page_write_mask = 0;
    /* Identify the target register and assign the corresponding W1C bit mask */
    switch (reg_address)
    {
    case PAD_REG_BASE + AON_REG_PAD_REG23X:
        page_write_mask = PAD_INT_STS_W1C_MASK_GROUP0;
        break;

    case PAD_REG_BASE + AON_REG_PAD_REG24X:
        page_write_mask = PAD_INT_STS_W1C_MASK_GROUP1;
        break;

    case PAD_REG_BASE + AON_REG_PAD_REG25X:
        page_write_mask = PAD_INT_STS_W1C_MASK_GROUP2;
        break;

    case PAD_REG_BASE + AON_REG_SPI_PAD_REG30X:
        page_write_mask = PAD_INT_STS_W1C_MASK_GROUP3;
        break;

    default:
        break;
    }
    /*
     * Safe Read-Modify-Write for W1C registers:
     * 1. PAD_REG_READ(reg_address) : Read the current register value.
     * 2. & (~page_write_mask)      : Mask out (set to 0) ALL W1C bits to prevent accidentally
     *                                writing '1' back to other pending bits (which would clear them).
     *                                Normal R/W config bits are preserved.
     * 3. | reg_value               : Set '1' ONLY to the target status bit we want to clear.
     */
    PAD_REG_WRITE(reg_address, (PAD_REG_READ(reg_address) & (~page_write_mask)) | reg_value);
}

/**
 * \brief Clear all wake up pin interrupt pending bit.
 * \param  None.
 * \return None.
 */
void System_WakeUpClearAllINT(void)
{
    uint32_t reg_address0 = PAD_REG_BASE + AON_REG_PAD_REG23X;
    uint32_t reg_address1 = PAD_REG_BASE + AON_REG_PAD_REG24X;
    uint32_t reg_address2 = PAD_REG_BASE + AON_REG_PAD_REG25X;
    uint32_t reg_address3 = PAD_REG_BASE + AON_REG_SPI_PAD_REG30X;
    PAD_REG_WRITE(reg_address0, PAD_REG_READ(reg_address0) | PAD_INT_STS_W1C_MASK_GROUP0);
    PAD_REG_WRITE(reg_address1, PAD_REG_READ(reg_address1) | PAD_INT_STS_W1C_MASK_GROUP1);
    PAD_REG_WRITE(reg_address2, PAD_REG_READ(reg_address2) | PAD_INT_STS_W1C_MASK_GROUP2);
    PAD_REG_WRITE(reg_address3, PAD_REG_READ(reg_address3) | PAD_INT_STS_W1C_MASK_GROUP3);

    PAD_DEBOUNCE->STS = (BIT0 | BIT1 | BIT2 | BIT3 | BIT4);
}

/**
  * \brief  Configure wakeup PPU function for the specified pin.
  * \param  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param  Polarity: Select pin wakeup polarity (high level or low level).
  *         This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param  NewState: Enable or disable the wakeup PPU function.
  *         This parameter can be ENABLE or DISABLE.
  * \return None
  */
void System_WakeUpPPUCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState)
{
    Pad_TableConfig(WAKEUP_POL, Pin_Num, Polarity);
    Pad_TableConfig(WAKEUP_PPU, Pin_Num, NewState);
    AON_REG_WRITE_BITFIELD(AON_REG_SYSTEM_REG29X, EN_PAD_SYSTEM_ON_WAKEUP, NewState);
}

/**
  * \brief  Configure wakeup RAP function for the specified pin.
  * \param  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param  Polarity: Select pin wakeup polarity (high level or low level).
  *         This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param  NewState: Enable or disable wakeup RAP function.
  *         This parameter can be ENABLE or DISABLE.
  * \return None
  */
void System_WakeUpRAPCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState)
{
    Pad_TableConfig(WAKEUP_POL, Pin_Num, Polarity);
    Pad_TableConfig(WAKEUP_RAP, Pin_Num, NewState);
}

/**
  * \brief  Configure wakeup off mode(power down) function for the specified pin.
  * \param  Pin_Num: The number of the pin to configure. See \ref Pin_Number.
  * \param  Polarity: Select pin wakeup polarity (high level or low level).
  *         This parameter can be PAD_WAKEUP_POL_HIGH or PAD_WAKEUP_POL_LOW.
  * \param  NewState: Enable or disable wakeup RAP function.
  *         This parameter can be ENABLE or DISABLE.
  * \return None
  */
void System_WakeUpPDCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState)
{
    Pad_TableConfig(WAKEUP_POL, Pin_Num, Polarity);
    Pad_TableConfig(WAKEUP_EN, Pin_Num, NewState);
}

/*============================================================================*
 *                           PAD INTERRUPT
 *============================================================================*/
/* Define invalid index */
#define PAD_ISR_IDX_INVALID  0xFF

/* Define linked list node structure for PAD ISR */
typedef struct PadIsrNode
{
    P_PAD_CBACK  pad_callback;   /* Pointer to the callback function
                                    to be executed when the pad wakes up. */
    uint32_t     context;        /* User-defined context passed to
                                    the callback function. */
    uint8_t      pin_num;        /* The specific GPIO pin number associated
                                    with this wake-up interrupt. */
    uint8_t      next_idx;       /* Index of the next node in the static
                                    memory pool linked list. */
    bool         is_used;        /* Status flag indicating whether this node
                                    is currently allocated (true) or free (false). */
} T_PAD_ISR_NODE;

/* Define static memory pool: support up to TOTAL_PIN_NUM concurrent wake-up pins */
static T_PAD_ISR_NODE g_pad_node_pool[TOTAL_PIN_NUM];

/* Linked list head index, initialized to invalid value */
static uint8_t g_pad_isr_head_idx = PAD_ISR_IDX_INVALID;

/**
  * \brief  Pad handler function.
  * \return None.
  */
static void Pad_Handler(void)
{
    /* Clear PAD interrupt status */
    AON_REG_WRITE_BITFIELD(AON_REG_SYSTEM_REG29X, GPIO_INTR_PORT, true);

    /* Iterate through the registered callback linked list using index */
    uint8_t curr_idx = g_pad_isr_head_idx;

    while (curr_idx != PAD_ISR_IDX_INVALID)
    {
        /* Get current node pointer via index for easy access */
        T_PAD_ISR_NODE *curr_node = &g_pad_node_pool[curr_idx];

        /* Check if there is a pending interrupt for the current node's PIN */
        if (System_WakeUpInterruptValue(curr_node->pin_num))
        {
            /* Invoke the callback function */
            if (curr_node->pad_callback)
            {
                curr_node->pad_callback(curr_node->context);
            }
        }

        /* Move to the next node */
        curr_idx = curr_node->next_idx;
    }
}

/**
  * \brief  Register the callback function of the wake-up system of the specified pin.
  *
  * \param[in] Pin_Num: Pin number to be configured. \ref Pin_Number.
  *
  * \param[in] Callback: Callback function.
  *
  * \param[in] Context: Context of the callback
  *
  * \return None.
  */
void System_RegisterPadWakeupCallback(uint8_t Pin_Num, P_PAD_CBACK Callback, uint32_t Context)
{
    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    uint16_t pad_item = wakeup_status_table.reg[Pin_Num];
    if (!pad_item)
    {
        return;
    }

    uint8_t curr_idx = g_pad_isr_head_idx;
    uint8_t prev_idx = PAD_ISR_IDX_INVALID;

    /* Check if the Pin_Num is already registered */
    while (curr_idx != PAD_ISR_IDX_INVALID)
    {
        T_PAD_ISR_NODE *curr_node = &g_pad_node_pool[curr_idx];

        if (curr_node->pin_num == Pin_Num)
        {
            /* 1. If the PIN already exists in the list */
            if (Callback != NULL)
            {
                /* Update the existing Callback and Context */
                curr_node->pad_callback = Callback;
                curr_node->context      = Context;
            }
            else
            {
                /* If the given Callback is NULL, it means unregistration.
                   Remove the node and free memory. */
                if (prev_idx == PAD_ISR_IDX_INVALID)
                {
                    /* Remove head node */
                    g_pad_isr_head_idx = curr_node->next_idx;
                }
                else
                {
                    /* Remove middle or tail node */
                    g_pad_node_pool[prev_idx].next_idx = curr_node->next_idx;
                }
                curr_node->is_used = false;
            }
            return;
        }
        prev_idx = curr_idx;
        curr_idx = curr_node->next_idx;
    }

    /* 2. If it doesn't exist and Callback is valid, allocate a new node from the pool */
    if (Callback != NULL)
    {
        uint8_t new_idx = PAD_ISR_IDX_INVALID;

        /* Find a free node from the static pool */
        for (uint8_t i = 0; i < TOTAL_PIN_NUM; i++)
        {
            if (!g_pad_node_pool[i].is_used)
            {
                new_idx = i;
                g_pad_node_pool[i].is_used = true;
                break;
            }
        }

        if (new_idx != PAD_ISR_IDX_INVALID)
        {
            T_PAD_ISR_NODE *new_node = &g_pad_node_pool[new_idx];
            new_node->pin_num      = Pin_Num;
            new_node->pad_callback = Callback;
            new_node->context      = Context;

            /* Insert the new node at the head of the list */
            new_node->next_idx = g_pad_isr_head_idx;
            g_pad_isr_head_idx = new_idx;
        }
    }
}
