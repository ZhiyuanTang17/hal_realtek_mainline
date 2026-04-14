#ifndef PPU_REG_H
#define PPU_REG_H
#include <stdint.h>

/* ================================================================================ */
/* ================                PPU Register               ================ */
/* ===========     Reference: Bee5_PPU_Power_Register_Table_20251023A.xlsx     =========== */
/* ================================================================================ */
#define PPU_PPU_PWPR_VPON_PPU   0x0000
#define PPU_PPU_PMER_VPON_PPU   0x0004
#define PPU_PPU_PWSR_VPON_PPU   0x0008
#define PPU_Reserved_VPON_PPU   0x000C
#define PPU_PPU_DISR_VPON_PPU   0x0010
#define PPU_PPU_MISR_VPON_PPU   0x0014
#define PPU_PPU_STSR_VPON_PPU   0x0018
#define PPU_PPU_UNLK_VPON_PPU   0x001C
#define PPU_PPU_PWCR_VPON_PPU   0x0020
#define PPU_PPU_PTCR_VPON_PPU   0x0024
#define PPU_PPU_IMR_VPON_PPU    0x0030
#define PPU_PPU_AIMR_VPON_PPU   0x0034
#define PPU_PPU_ISR_VPON_PPU    0x0038
#define PPU_PPU_AISR_VPON_PPU   0x003C
#define PPU_PPU_IESR_VPON_PPU   0x0040
#define PPU_PPU_OPSR_VPON_PPU   0x0044
#define PPU_PPU_FUNRR_VPON_PPU  0x0050
#define PPU_PPU_FULRR_VPON_PPU  0x0054
#define PPU_PPU_MEMRR_VPON_PPU  0x0058
#define PPU_PPU_EDTR0_VPON_PPU  0x0160
#define PPU_PPU_EDTR1_VPON_PPU  0x0164
#define PPU_PPU_DCDR0_VPON_PPU  0x0170
#define PPU_PPU_DCDR1_VPON_PPU  0x0174
#define PPU_PPU_IDR0_VPON_PPU   0x0FB0
#define PPU_PPU_IDR1_VPON_PPU   0x0FB4
#define PPU_PPU_IIDR_VPON_PPU   0x0FC8
#define PPU_PPU_AIDR_VPON_PPU   0x0FCC
#define PPU_ID_REG_VPON_PPU_1   0x0FD0
#define PPU_ID_REG_VPON_PPU_2   0x0FD4
#define PPU_ID_REG_VPON_PPU_3   0x0FD8
#define PPU_ID_REG_VPON_PPU_4   0x0FDC
#define PPU_ID_REG_VPON_PPU_5   0x0FE0
#define PPU_ID_REG_VPON_PPU_6   0x0FE4
#define PPU_ID_REG_VPON_PPU_7   0x0FE8
#define PPU_ID_REG_VPON_PPU_8   0x0FEC
#define PPU_ID_REG_VPON_PPU_9   0x0FF0
#define PPU_ID_REG_VPON_PPU_10  0x0FF4
#define PPU_ID_REG_VPON_PPU_11  0x0FF8
#define PPU_ID_REG_VPON_PPU_12  0x0FFC

/* 0x0000   0x4000_2000
    3:0     RW      PWR_POLICY                  DEF_PWR_POLICY
    7:4     RO      RESERVED_4                  0x0
    8       RW      PWR_DYN_EN                  DEF_PWR_DYN_EN
    11:9    RO      RESERVED_3                  0x0
    12      RW      LOCK_EN                     0x0
    15:13   RO      RESERVED_2                  0x0
    19:16   RW      OP_POLICY                   DEF_OP_POLICY
    23:20   RO      RESERVED_1                  0x0
    24      RW      OP_DYN_EN                   DEF_OP_DYN_EN
    31:25   RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_PWPR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PWR_POLICY: 4;
        uint32_t RESERVED_4: 4;
        uint32_t PWR_DYN_EN: 1;
        uint32_t RESERVED_3: 3;
        uint32_t LOCK_EN: 1;
        uint32_t RESERVED_2: 3;
        uint32_t OP_POLICY: 4;
        uint32_t RESERVED_1: 4;
        uint32_t OP_DYN_EN: 1;
        uint32_t RESERVED: 7;
    };
} PPU_PPU_PWPR_VPON_PPU_TYPE;

/*0x4000_2000 PPU_PPU_PWPR_VPON_PPU*/
#define PPU_PPU_PWPR_VPON_PPU_PWR_POLICY_Pos                         0U
#define PPU_PPU_PWPR_VPON_PPU_PWR_POLICY_Msk                         (0xFUL << PPU_PPU_PWPR_VPON_PPU_PWR_POLICY_Pos)

#define PPU_PPU_PWPR_VPON_PPU_RESERVED_4_Pos                         4U
#define PPU_PPU_PWPR_VPON_PPU_RESERVED_4_Msk                         (0xFUL << PPU_PPU_PWPR_VPON_PPU_RESERVED_4_Pos)

#define PPU_PPU_PWPR_VPON_PPU_PWR_DYN_EN_Pos                         8U
#define PPU_PPU_PWPR_VPON_PPU_PWR_DYN_EN_Msk                         (0x1UL << PPU_PPU_PWPR_VPON_PPU_PWR_DYN_EN_Pos)

#define PPU_PPU_PWPR_VPON_PPU_RESERVED_3_Pos                         9U
#define PPU_PPU_PWPR_VPON_PPU_RESERVED_3_Msk                         (0x7UL << PPU_PPU_PWPR_VPON_PPU_RESERVED_3_Pos)

#define PPU_PPU_PWPR_VPON_PPU_LOCK_EN_Pos                            12U
#define PPU_PPU_PWPR_VPON_PPU_LOCK_EN_Msk                            (0x1UL << PPU_PPU_PWPR_VPON_PPU_LOCK_EN_Pos)

#define PPU_PPU_PWPR_VPON_PPU_RESERVED_2_Pos                         13U
#define PPU_PPU_PWPR_VPON_PPU_RESERVED_2_Msk                         (0x7UL << PPU_PPU_PWPR_VPON_PPU_RESERVED_2_Pos)

#define PPU_PPU_PWPR_VPON_PPU_OP_POLICY_Pos                          16U
#define PPU_PPU_PWPR_VPON_PPU_OP_POLICY_Msk                          (0xFUL << PPU_PPU_PWPR_VPON_PPU_OP_POLICY_Pos)

#define PPU_PPU_PWPR_VPON_PPU_RESERVED_1_Pos                         20U
#define PPU_PPU_PWPR_VPON_PPU_RESERVED_1_Msk                         (0xFUL << PPU_PPU_PWPR_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_PWPR_VPON_PPU_OP_DYN_EN_Pos                          24U
#define PPU_PPU_PWPR_VPON_PPU_OP_DYN_EN_Msk                          (0x1UL << PPU_PPU_PWPR_VPON_PPU_OP_DYN_EN_Pos)

#define PPU_PPU_PWPR_VPON_PPU_RESERVED_Pos                           25U
#define PPU_PPU_PWPR_VPON_PPU_RESERVED_Msk                           (0x7FUL << PPU_PPU_PWPR_VPON_PPU_RESERVED_Pos)

/* 0x0004   0x4000_2004
    0       RW      EMU_EN                      0x0
    31:1    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_PMER_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t EMU_EN: 1;
        uint32_t RESERVED: 31;
    };
} PPU_PPU_PMER_VPON_PPU_TYPE;

/*0x4000_2004 PPU_PPU_PMER_VPON_PPU*/
#define PPU_PPU_PMER_VPON_PPU_EMU_EN_Pos                             0U
#define PPU_PPU_PMER_VPON_PPU_EMU_EN_Msk                             (0x1UL << PPU_PPU_PMER_VPON_PPU_EMU_EN_Pos)

#define PPU_PPU_PMER_VPON_PPU_RESERVED_Pos                           1U
#define PPU_PPU_PMER_VPON_PPU_RESERVED_Msk                           (0x7FFFFFFFUL << PPU_PPU_PMER_VPON_PPU_RESERVED_Pos)

/* 0x0008   0x4000_2008
    3:0     RO      PWR_STATUS                  PCSMMODESTAT[3:0]
    7:4     RO      RESERVED_4                  0x0
    8       RO      PWR_DYN_STATUS              DEF_PWR_DYN_EN
    11:9    RO      RESERVED_3                  0x0
    12      RO      LOCK_STATUS                 0x0
    15:13   RO      RESERVED_2                  0x0
    19:16   RO      OP_STATUS                   PCSMMODESTAT[7:4]
    23:20   RO      RESERVED_1                  0x0
    24      RO      OP_DYN_STATUS               DEF_OP_DYN_EN
    31:25   RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_PWSR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PWR_STATUS: 4;
        uint32_t RESERVED_4: 4;
        uint32_t PWR_DYN_STATUS: 1;
        uint32_t RESERVED_3: 3;
        uint32_t LOCK_STATUS: 1;
        uint32_t RESERVED_2: 3;
        uint32_t OP_STATUS: 4;
        uint32_t RESERVED_1: 4;
        uint32_t OP_DYN_STATUS: 1;
        uint32_t RESERVED: 7;
    };
} PPU_PPU_PWSR_VPON_PPU_TYPE;

/*0x4000_2008 PPU_PPU_PWSR_VPON_PPU*/
#define PPU_PPU_PWSR_VPON_PPU_PWR_STATUS_Pos                         0U
#define PPU_PPU_PWSR_VPON_PPU_PWR_STATUS_Msk                         (0xFUL << PPU_PPU_PWSR_VPON_PPU_PWR_STATUS_Pos)

#define PPU_PPU_PWSR_VPON_PPU_RESERVED_4_Pos                         4U
#define PPU_PPU_PWSR_VPON_PPU_RESERVED_4_Msk                         (0xFUL << PPU_PPU_PWSR_VPON_PPU_RESERVED_4_Pos)

#define PPU_PPU_PWSR_VPON_PPU_PWR_DYN_STATUS_Pos                     8U
#define PPU_PPU_PWSR_VPON_PPU_PWR_DYN_STATUS_Msk                     (0x1UL << PPU_PPU_PWSR_VPON_PPU_PWR_DYN_STATUS_Pos)

#define PPU_PPU_PWSR_VPON_PPU_RESERVED_3_Pos                         9U
#define PPU_PPU_PWSR_VPON_PPU_RESERVED_3_Msk                         (0x7UL << PPU_PPU_PWSR_VPON_PPU_RESERVED_3_Pos)

#define PPU_PPU_PWSR_VPON_PPU_LOCK_STATUS_Pos                        12U
#define PPU_PPU_PWSR_VPON_PPU_LOCK_STATUS_Msk                        (0x1UL << PPU_PPU_PWSR_VPON_PPU_LOCK_STATUS_Pos)

#define PPU_PPU_PWSR_VPON_PPU_RESERVED_2_Pos                         13U
#define PPU_PPU_PWSR_VPON_PPU_RESERVED_2_Msk                         (0x7UL << PPU_PPU_PWSR_VPON_PPU_RESERVED_2_Pos)

#define PPU_PPU_PWSR_VPON_PPU_OP_STATUS_Pos                          16U
#define PPU_PPU_PWSR_VPON_PPU_OP_STATUS_Msk                          (0xFUL << PPU_PPU_PWSR_VPON_PPU_OP_STATUS_Pos)

#define PPU_PPU_PWSR_VPON_PPU_RESERVED_1_Pos                         20U
#define PPU_PPU_PWSR_VPON_PPU_RESERVED_1_Msk                         (0xFUL << PPU_PPU_PWSR_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_PWSR_VPON_PPU_OP_DYN_STATUS_Pos                      24U
#define PPU_PPU_PWSR_VPON_PPU_OP_DYN_STATUS_Msk                      (0x1UL << PPU_PPU_PWSR_VPON_PPU_OP_DYN_STATUS_Pos)

#define PPU_PPU_PWSR_VPON_PPU_RESERVED_Pos                           25U
#define PPU_PPU_PWSR_VPON_PPU_RESERVED_Msk                           (0x7FUL << PPU_PPU_PWSR_VPON_PPU_RESERVED_Pos)

/* 0x000C   0x4000_200c
    31:0    RO      Reserved                    0x0
 */
typedef union _PPU_Reserved_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t Reserved;
    };
} PPU_Reserved_VPON_PPU_TYPE;

/*0x4000_200c PPU_Reserved_VPON_PPU*/
#define PPU_Reserved_VPON_PPU_Reserved_Pos                           0U
#define PPU_Reserved_VPON_PPU_Reserved_Msk                           (0xFFFFFFFFUL << PPU_Reserved_VPON_PPU_Reserved_Pos)

/* 0x0010   0x4000_2010
    10:0    RO      PWR_DEVACTIVE_STATUS        0x0
    23:11   RO      RESERVED                    0x0
    31:24   RO      OP_DEVACTIVE_STATUS         0x0
 */
typedef union _PPU_PPU_DISR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PWR_DEVACTIVE_STATUS: 11;
        uint32_t RESERVED: 13;
        uint32_t OP_DEVACTIVE_STATUS: 8;
    };
} PPU_PPU_DISR_VPON_PPU_TYPE;

/*0x4000_2010 PPU_PPU_DISR_VPON_PPU*/
#define PPU_PPU_DISR_VPON_PPU_PWR_DEVACTIVE_STATUS_Pos               0U
#define PPU_PPU_DISR_VPON_PPU_PWR_DEVACTIVE_STATUS_Msk               (0x7FFUL << PPU_PPU_DISR_VPON_PPU_PWR_DEVACTIVE_STATUS_Pos)

#define PPU_PPU_DISR_VPON_PPU_RESERVED_Pos                           11U
#define PPU_PPU_DISR_VPON_PPU_RESERVED_Msk                           (0x1FFFUL << PPU_PPU_DISR_VPON_PPU_RESERVED_Pos)

#define PPU_PPU_DISR_VPON_PPU_OP_DEVACTIVE_STATUS_Pos                24U
#define PPU_PPU_DISR_VPON_PPU_OP_DEVACTIVE_STATUS_Msk                (0xFFUL << PPU_PPU_DISR_VPON_PPU_OP_DEVACTIVE_STATUS_Pos)

/* 0x0014   0x4000_2014
    0       RO      PCSMPACCEPT_STATUS          0x0
    7:1     RO      RESERVED_1                  0x0
    15:8    RO      DEVACCEPT_STATUS            0x0
    23:16   RO      DEVDENY_STATUS              0x0
    31:24   RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_MISR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PCSMPACCEPT_STATUS: 1;
        uint32_t RESERVED_1: 7;
        uint32_t DEVACCEPT_STATUS: 8;
        uint32_t DEVDENY_STATUS: 8;
        uint32_t RESERVED: 8;
    };
} PPU_PPU_MISR_VPON_PPU_TYPE;

/*0x4000_2014 PPU_PPU_MISR_VPON_PPU*/
#define PPU_PPU_MISR_VPON_PPU_PCSMPACCEPT_STATUS_Pos                 0U
#define PPU_PPU_MISR_VPON_PPU_PCSMPACCEPT_STATUS_Msk                 (0x1UL << PPU_PPU_MISR_VPON_PPU_PCSMPACCEPT_STATUS_Pos)

#define PPU_PPU_MISR_VPON_PPU_RESERVED_1_Pos                         1U
#define PPU_PPU_MISR_VPON_PPU_RESERVED_1_Msk                         (0x7FUL << PPU_PPU_MISR_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_MISR_VPON_PPU_DEVACCEPT_STATUS_Pos                   8U
#define PPU_PPU_MISR_VPON_PPU_DEVACCEPT_STATUS_Msk                   (0xFFUL << PPU_PPU_MISR_VPON_PPU_DEVACCEPT_STATUS_Pos)

#define PPU_PPU_MISR_VPON_PPU_DEVDENY_STATUS_Pos                     16U
#define PPU_PPU_MISR_VPON_PPU_DEVDENY_STATUS_Msk                     (0xFFUL << PPU_PPU_MISR_VPON_PPU_DEVDENY_STATUS_Pos)

#define PPU_PPU_MISR_VPON_PPU_RESERVED_Pos                           24U
#define PPU_PPU_MISR_VPON_PPU_RESERVED_Msk                           (0xFFUL << PPU_PPU_MISR_VPON_PPU_RESERVED_Pos)

/* 0x0018   0x4000_2018
    7:0     RO      STORED_DEVDENY              0x0
    31:8    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_STSR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t STORED_DEVDENY: 8;
        uint32_t RESERVED: 24;
    };
} PPU_PPU_STSR_VPON_PPU_TYPE;

/*0x4000_2018 PPU_PPU_STSR_VPON_PPU*/
#define PPU_PPU_STSR_VPON_PPU_STORED_DEVDENY_Pos                     0U
#define PPU_PPU_STSR_VPON_PPU_STORED_DEVDENY_Msk                     (0xFFUL << PPU_PPU_STSR_VPON_PPU_STORED_DEVDENY_Pos)

#define PPU_PPU_STSR_VPON_PPU_RESERVED_Pos                           8U
#define PPU_PPU_STSR_VPON_PPU_RESERVED_Msk                           (0xFFFFFFUL << PPU_PPU_STSR_VPON_PPU_RESERVED_Pos)

/* 0x001C   0x4000_201c
    0       WO      UNLOCK                      0x0
    31:1    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_UNLK_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t UNLOCK: 1;
        uint32_t RESERVED: 31;
    };
} PPU_PPU_UNLK_VPON_PPU_TYPE;

/*0x4000_201c PPU_PPU_UNLK_VPON_PPU*/
#define PPU_PPU_UNLK_VPON_PPU_UNLOCK_Pos                             0U
#define PPU_PPU_UNLK_VPON_PPU_UNLOCK_Msk                             (0x1UL << PPU_PPU_UNLK_VPON_PPU_UNLOCK_Pos)

#define PPU_PPU_UNLK_VPON_PPU_RESERVED_Pos                           1U
#define PPU_PPU_UNLK_VPON_PPU_RESERVED_Msk                           (0x7FFFFFFFUL << PPU_PPU_UNLK_VPON_PPU_RESERVED_Pos)

/* 0x0020   0x4000_2020
    7:0     RW      DEVREQEN                    SeeTable
    18:8    RW      PWR_DEVACTIVEEN             SeeTable
    23:19   RO      RESERVED                    0x0
    31:24   RW      OP_DEVACTIVEEN              SeeTable
 */
typedef union _PPU_PPU_PWCR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DEVREQEN: 8;
        uint32_t PWR_DEVACTIVEEN: 11;
        uint32_t RESERVED: 5;
        uint32_t OP_DEVACTIVEEN: 8;
    };
} PPU_PPU_PWCR_VPON_PPU_TYPE;

/*0x4000_2020 PPU_PPU_PWCR_VPON_PPU*/
#define PPU_PPU_PWCR_VPON_PPU_DEVREQEN_Pos                           0U
#define PPU_PPU_PWCR_VPON_PPU_DEVREQEN_Msk                           (0xFFUL << PPU_PPU_PWCR_VPON_PPU_DEVREQEN_Pos)

#define PPU_PPU_PWCR_VPON_PPU_PWR_DEVACTIVEEN_Pos                    8U
#define PPU_PPU_PWCR_VPON_PPU_PWR_DEVACTIVEEN_Msk                    (0x7FFUL << PPU_PPU_PWCR_VPON_PPU_PWR_DEVACTIVEEN_Pos)

#define PPU_PPU_PWCR_VPON_PPU_RESERVED_Pos                           19U
#define PPU_PPU_PWCR_VPON_PPU_RESERVED_Msk                           (0x1FUL << PPU_PPU_PWCR_VPON_PPU_RESERVED_Pos)

#define PPU_PPU_PWCR_VPON_PPU_OP_DEVACTIVEEN_Pos                     24U
#define PPU_PPU_PWCR_VPON_PPU_OP_DEVACTIVEEN_Msk                     (0xFFUL << PPU_PPU_PWCR_VPON_PPU_OP_DEVACTIVEEN_Pos)

/* 0x0024   0x4000_2024
    0       RW      WARM_RST_DEVREQEN           WARM_RST_DEVREQEN_CFG
    1       RW      DBG_RECOV_PORST_EN          DBG_RECOV_PORST_CFG
    31:2    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_PTCR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t WARM_RST_DEVREQEN: 1;
        uint32_t DBG_RECOV_PORST_EN: 1;
        uint32_t RESERVED: 30;
    };
} PPU_PPU_PTCR_VPON_PPU_TYPE;

/*0x4000_2024 PPU_PPU_PTCR_VPON_PPU*/
#define PPU_PPU_PTCR_VPON_PPU_WARM_RST_DEVREQEN_Pos                  0U
#define PPU_PPU_PTCR_VPON_PPU_WARM_RST_DEVREQEN_Msk                  (0x1UL << PPU_PPU_PTCR_VPON_PPU_WARM_RST_DEVREQEN_Pos)

#define PPU_PPU_PTCR_VPON_PPU_DBG_RECOV_PORST_EN_Pos                 1U
#define PPU_PPU_PTCR_VPON_PPU_DBG_RECOV_PORST_EN_Msk                 (0x1UL << PPU_PPU_PTCR_VPON_PPU_DBG_RECOV_PORST_EN_Pos)

#define PPU_PPU_PTCR_VPON_PPU_RESERVED_Pos                           2U
#define PPU_PPU_PTCR_VPON_PPU_RESERVED_Msk                           (0x3FFFFFFFUL << PPU_PPU_PTCR_VPON_PPU_RESERVED_Pos)

/* 0x0030   0x4000_2030
    0       RW      STA_POLICY_TRN_IRQ_MASK     0x0
    1       RW      STA_ACCEPT_IRQ_MASK         0x1
    2       RW      STA_DENY_IRQ_MASK           0x0
    3       RW      EMU_ACCEPT_IRQ_MASK         0x1
    4       RW      EMU_DENY_IRQ_MASK           0x1
    5       RW      LOCKED_IRQ_MASK             0x1
    31:6    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_IMR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t STA_POLICY_TRN_IRQ_MASK: 1;
        uint32_t STA_ACCEPT_IRQ_MASK: 1;
        uint32_t STA_DENY_IRQ_MASK: 1;
        uint32_t EMU_ACCEPT_IRQ_MASK: 1;
        uint32_t EMU_DENY_IRQ_MASK: 1;
        uint32_t LOCKED_IRQ_MASK: 1;
        uint32_t RESERVED: 26;
    };
} PPU_PPU_IMR_VPON_PPU_TYPE;

/*0x4000_2030 PPU_PPU_IMR_VPON_PPU*/
#define PPU_PPU_IMR_VPON_PPU_STA_POLICY_TRN_IRQ_MASK_Pos             0U
#define PPU_PPU_IMR_VPON_PPU_STA_POLICY_TRN_IRQ_MASK_Msk             (0x1UL << PPU_PPU_IMR_VPON_PPU_STA_POLICY_TRN_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_STA_ACCEPT_IRQ_MASK_Pos                 1U
#define PPU_PPU_IMR_VPON_PPU_STA_ACCEPT_IRQ_MASK_Msk                 (0x1UL << PPU_PPU_IMR_VPON_PPU_STA_ACCEPT_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_STA_DENY_IRQ_MASK_Pos                   2U
#define PPU_PPU_IMR_VPON_PPU_STA_DENY_IRQ_MASK_Msk                   (0x1UL << PPU_PPU_IMR_VPON_PPU_STA_DENY_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_EMU_ACCEPT_IRQ_MASK_Pos                 3U
#define PPU_PPU_IMR_VPON_PPU_EMU_ACCEPT_IRQ_MASK_Msk                 (0x1UL << PPU_PPU_IMR_VPON_PPU_EMU_ACCEPT_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_EMU_DENY_IRQ_MASK_Pos                   4U
#define PPU_PPU_IMR_VPON_PPU_EMU_DENY_IRQ_MASK_Msk                   (0x1UL << PPU_PPU_IMR_VPON_PPU_EMU_DENY_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_LOCKED_IRQ_MASK_Pos                     5U
#define PPU_PPU_IMR_VPON_PPU_LOCKED_IRQ_MASK_Msk                     (0x1UL << PPU_PPU_IMR_VPON_PPU_LOCKED_IRQ_MASK_Pos)

#define PPU_PPU_IMR_VPON_PPU_RESERVED_Pos                            6U
#define PPU_PPU_IMR_VPON_PPU_RESERVED_Msk                            (0x3FFFFFFUL << PPU_PPU_IMR_VPON_PPU_RESERVED_Pos)

/* 0x0034   0x4000_2034
    0       RW      UNSPT_POLICY_IRQ_MASK       0x0
    1       RW      DYN_ACCEPT_IRQ_MASK         0x1
    2       RW      DYN_DENY_IRQ_MASK           0x1
    3       RW      STA_POLICY_PWR_IRQ_MASK     0x1
    4       RW      STA_POLICY_OP_IRQ_MASK      0x1
    31:5    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_AIMR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t UNSPT_POLICY_IRQ_MASK: 1;
        uint32_t DYN_ACCEPT_IRQ_MASK: 1;
        uint32_t DYN_DENY_IRQ_MASK: 1;
        uint32_t STA_POLICY_PWR_IRQ_MASK: 1;
        uint32_t STA_POLICY_OP_IRQ_MASK: 1;
        uint32_t RESERVED: 27;
    };
} PPU_PPU_AIMR_VPON_PPU_TYPE;

/*0x4000_2034 PPU_PPU_AIMR_VPON_PPU*/
#define PPU_PPU_AIMR_VPON_PPU_UNSPT_POLICY_IRQ_MASK_Pos              0U
#define PPU_PPU_AIMR_VPON_PPU_UNSPT_POLICY_IRQ_MASK_Msk              (0x1UL << PPU_PPU_AIMR_VPON_PPU_UNSPT_POLICY_IRQ_MASK_Pos)

#define PPU_PPU_AIMR_VPON_PPU_DYN_ACCEPT_IRQ_MASK_Pos                1U
#define PPU_PPU_AIMR_VPON_PPU_DYN_ACCEPT_IRQ_MASK_Msk                (0x1UL << PPU_PPU_AIMR_VPON_PPU_DYN_ACCEPT_IRQ_MASK_Pos)

#define PPU_PPU_AIMR_VPON_PPU_DYN_DENY_IRQ_MASK_Pos                  2U
#define PPU_PPU_AIMR_VPON_PPU_DYN_DENY_IRQ_MASK_Msk                  (0x1UL << PPU_PPU_AIMR_VPON_PPU_DYN_DENY_IRQ_MASK_Pos)

#define PPU_PPU_AIMR_VPON_PPU_STA_POLICY_PWR_IRQ_MASK_Pos            3U
#define PPU_PPU_AIMR_VPON_PPU_STA_POLICY_PWR_IRQ_MASK_Msk            (0x1UL << PPU_PPU_AIMR_VPON_PPU_STA_POLICY_PWR_IRQ_MASK_Pos)

#define PPU_PPU_AIMR_VPON_PPU_STA_POLICY_OP_IRQ_MASK_Pos             4U
#define PPU_PPU_AIMR_VPON_PPU_STA_POLICY_OP_IRQ_MASK_Msk             (0x1UL << PPU_PPU_AIMR_VPON_PPU_STA_POLICY_OP_IRQ_MASK_Pos)

#define PPU_PPU_AIMR_VPON_PPU_RESERVED_Pos                           5U
#define PPU_PPU_AIMR_VPON_PPU_RESERVED_Msk                           (0x7FFFFFFUL << PPU_PPU_AIMR_VPON_PPU_RESERVED_Pos)

/* 0x0038   0x4000_2038
    0       RW      STA_POLICY_TRN_IRQ          0x0
    1       RW      STA_ACCEPT_IRQ              0x0
    2       RW      STA_DENY_IRQ                0x0
    3       RW      EMU_ACCEPT_IRQ              0x0
    4       RW      EMU_DENY_IRQ                0x0
    5       RW      LOCKED_IRQ                  0x0
    6       RW      RESERVED_1                  0x0
    7       RO      OTHER_IRQ                   0x0
    18:8    RW      PWR_ACTIVE_EDGE_IRQ         0x00
    23:19   RO      RESERVED                    0x0
    31:24   RW      OP_ACTIVE_EDGE_IRQ          0x0
 */
typedef union _PPU_PPU_ISR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t STA_POLICY_TRN_IRQ: 1;
        uint32_t STA_ACCEPT_IRQ: 1;
        uint32_t STA_DENY_IRQ: 1;
        uint32_t EMU_ACCEPT_IRQ: 1;
        uint32_t EMU_DENY_IRQ: 1;
        uint32_t LOCKED_IRQ: 1;
        uint32_t RESERVED_1: 1;
        uint32_t OTHER_IRQ: 1;
        uint32_t PWR_ACTIVE_EDGE_IRQ: 11;
        uint32_t RESERVED: 5;
        uint32_t OP_ACTIVE_EDGE_IRQ: 8;
    };
} PPU_PPU_ISR_VPON_PPU_TYPE;

/*0x4000_2038 PPU_PPU_ISR_VPON_PPU*/
#define PPU_PPU_ISR_VPON_PPU_STA_POLICY_TRN_IRQ_Pos                  0U
#define PPU_PPU_ISR_VPON_PPU_STA_POLICY_TRN_IRQ_Msk                  (0x1UL << PPU_PPU_ISR_VPON_PPU_STA_POLICY_TRN_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_STA_ACCEPT_IRQ_Pos                      1U
#define PPU_PPU_ISR_VPON_PPU_STA_ACCEPT_IRQ_Msk                      (0x1UL << PPU_PPU_ISR_VPON_PPU_STA_ACCEPT_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_STA_DENY_IRQ_Pos                        2U
#define PPU_PPU_ISR_VPON_PPU_STA_DENY_IRQ_Msk                        (0x1UL << PPU_PPU_ISR_VPON_PPU_STA_DENY_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_EMU_ACCEPT_IRQ_Pos                      3U
#define PPU_PPU_ISR_VPON_PPU_EMU_ACCEPT_IRQ_Msk                      (0x1UL << PPU_PPU_ISR_VPON_PPU_EMU_ACCEPT_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_EMU_DENY_IRQ_Pos                        4U
#define PPU_PPU_ISR_VPON_PPU_EMU_DENY_IRQ_Msk                        (0x1UL << PPU_PPU_ISR_VPON_PPU_EMU_DENY_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_LOCKED_IRQ_Pos                          5U
#define PPU_PPU_ISR_VPON_PPU_LOCKED_IRQ_Msk                          (0x1UL << PPU_PPU_ISR_VPON_PPU_LOCKED_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_RESERVED_1_Pos                          6U
#define PPU_PPU_ISR_VPON_PPU_RESERVED_1_Msk                          (0x1UL << PPU_PPU_ISR_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_ISR_VPON_PPU_OTHER_IRQ_Pos                           7U
#define PPU_PPU_ISR_VPON_PPU_OTHER_IRQ_Msk                           (0x1UL << PPU_PPU_ISR_VPON_PPU_OTHER_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_PWR_ACTIVE_EDGE_IRQ_Pos                 8U
#define PPU_PPU_ISR_VPON_PPU_PWR_ACTIVE_EDGE_IRQ_Msk                 (0x7FFUL << PPU_PPU_ISR_VPON_PPU_PWR_ACTIVE_EDGE_IRQ_Pos)

#define PPU_PPU_ISR_VPON_PPU_RESERVED_Pos                            19U
#define PPU_PPU_ISR_VPON_PPU_RESERVED_Msk                            (0x1FUL << PPU_PPU_ISR_VPON_PPU_RESERVED_Pos)

#define PPU_PPU_ISR_VPON_PPU_OP_ACTIVE_EDGE_IRQ_Pos                  24U
#define PPU_PPU_ISR_VPON_PPU_OP_ACTIVE_EDGE_IRQ_Msk                  (0xFFUL << PPU_PPU_ISR_VPON_PPU_OP_ACTIVE_EDGE_IRQ_Pos)

/* 0x003C   0x4000_203c
    0       RW      UNSPT_POLICY_IRQ            0x0
    1       RW      DYN_ACCEPT_IRQ              0x0
    2       RW      DYN_DENY_IRQ                0x0
    3       RW      STA_POLICY_PWR_IRQ          0x0
    4       RW      STA_POLICY_OP_IRQ           0x0
    31:5    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_AISR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t UNSPT_POLICY_IRQ: 1;
        uint32_t DYN_ACCEPT_IRQ: 1;
        uint32_t DYN_DENY_IRQ: 1;
        uint32_t STA_POLICY_PWR_IRQ: 1;
        uint32_t STA_POLICY_OP_IRQ: 1;
        uint32_t RESERVED: 27;
    };
} PPU_PPU_AISR_VPON_PPU_TYPE;

/*0x4000_203c PPU_PPU_AISR_VPON_PPU*/
#define PPU_PPU_AISR_VPON_PPU_UNSPT_POLICY_IRQ_Pos                   0U
#define PPU_PPU_AISR_VPON_PPU_UNSPT_POLICY_IRQ_Msk                   (0x1UL << PPU_PPU_AISR_VPON_PPU_UNSPT_POLICY_IRQ_Pos)

#define PPU_PPU_AISR_VPON_PPU_DYN_ACCEPT_IRQ_Pos                     1U
#define PPU_PPU_AISR_VPON_PPU_DYN_ACCEPT_IRQ_Msk                     (0x1UL << PPU_PPU_AISR_VPON_PPU_DYN_ACCEPT_IRQ_Pos)

#define PPU_PPU_AISR_VPON_PPU_DYN_DENY_IRQ_Pos                       2U
#define PPU_PPU_AISR_VPON_PPU_DYN_DENY_IRQ_Msk                       (0x1UL << PPU_PPU_AISR_VPON_PPU_DYN_DENY_IRQ_Pos)

#define PPU_PPU_AISR_VPON_PPU_STA_POLICY_PWR_IRQ_Pos                 3U
#define PPU_PPU_AISR_VPON_PPU_STA_POLICY_PWR_IRQ_Msk                 (0x1UL << PPU_PPU_AISR_VPON_PPU_STA_POLICY_PWR_IRQ_Pos)

#define PPU_PPU_AISR_VPON_PPU_STA_POLICY_OP_IRQ_Pos                  4U
#define PPU_PPU_AISR_VPON_PPU_STA_POLICY_OP_IRQ_Msk                  (0x1UL << PPU_PPU_AISR_VPON_PPU_STA_POLICY_OP_IRQ_Pos)

#define PPU_PPU_AISR_VPON_PPU_RESERVED_Pos                           5U
#define PPU_PPU_AISR_VPON_PPU_RESERVED_Msk                           (0x7FFFFFFUL << PPU_PPU_AISR_VPON_PPU_RESERVED_Pos)

/* 0x0040   0x4000_2040
    1:0     RW      DEVACTIVE00_EDGE            0x0
    3:2     RW      DEVACTIVE01_EDGE            0x0
    5:4     RW      DEVACTIVE02_EDGE            0x0
    7:6     RW      DEVACTIVE03_EDGE            0x0
    9:8     RW      DEVACTIVE04_EDGE            0x0
    11:10   RW      DEVACTIVE05_EDGE            0x0
    13:12   RW      DEVACTIVE06_EDGE            0x0
    15:14   RW      DEVACTIVE07_EDGE            0x0
    17:16   RW      DEVACTIVE08_EDGE            0x0
    19:18   RW      DEVACTIVE09_EDGE            0x0
    21:20   RW      DEVACTIVE10_EDGE            0x0
    31:22   RO      RESERVED                    0x0000
 */
typedef union _PPU_PPU_IESR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DEVACTIVE00_EDGE: 2;
        uint32_t DEVACTIVE01_EDGE: 2;
        uint32_t DEVACTIVE02_EDGE: 2;
        uint32_t DEVACTIVE03_EDGE: 2;
        uint32_t DEVACTIVE04_EDGE: 2;
        uint32_t DEVACTIVE05_EDGE: 2;
        uint32_t DEVACTIVE06_EDGE: 2;
        uint32_t DEVACTIVE07_EDGE: 2;
        uint32_t DEVACTIVE08_EDGE: 2;
        uint32_t DEVACTIVE09_EDGE: 2;
        uint32_t DEVACTIVE10_EDGE: 2;
        uint32_t RESERVED: 10;
    };
} PPU_PPU_IESR_VPON_PPU_TYPE;

/*0x4000_2040 PPU_PPU_IESR_VPON_PPU*/
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE00_EDGE_Pos                   0U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE00_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE00_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE01_EDGE_Pos                   2U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE01_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE01_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE02_EDGE_Pos                   4U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE02_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE02_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE03_EDGE_Pos                   6U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE03_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE03_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE04_EDGE_Pos                   8U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE04_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE04_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE05_EDGE_Pos                   10U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE05_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE05_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE06_EDGE_Pos                   12U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE06_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE06_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE07_EDGE_Pos                   14U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE07_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE07_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE08_EDGE_Pos                   16U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE08_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE08_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE09_EDGE_Pos                   18U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE09_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE09_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE10_EDGE_Pos                   20U
#define PPU_PPU_IESR_VPON_PPU_DEVACTIVE10_EDGE_Msk                   (0x3UL << PPU_PPU_IESR_VPON_PPU_DEVACTIVE10_EDGE_Pos)

#define PPU_PPU_IESR_VPON_PPU_RESERVED_Pos                           22U
#define PPU_PPU_IESR_VPON_PPU_RESERVED_Msk                           (0x3FFUL << PPU_PPU_IESR_VPON_PPU_RESERVED_Pos)

/* 0x0044   0x4000_2044
    1:0     RW      DEVACTIVE16_EDGE            0x0
    3:2     RW      DEVACTIVE17_EDGE            0x0
    5:4     RW      DEVACTIVE18_EDGE            0x0
    7:6     RW      DEVACTIVE19_EDGE            0x0
    9:8     RW      DEVACTIVE20_EDGE            0x0
    11:10   RW      DEVACTIVE21_EDGE            0x0
    13:12   RW      DEVACTIVE22_EDGE            0x0
    15:14   RW      DEVACTIVE23_EDGE            0x0
    31:16   RO      RESERVED                    0x0000
 */
typedef union _PPU_PPU_OPSR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DEVACTIVE16_EDGE: 2;
        uint32_t DEVACTIVE17_EDGE: 2;
        uint32_t DEVACTIVE18_EDGE: 2;
        uint32_t DEVACTIVE19_EDGE: 2;
        uint32_t DEVACTIVE20_EDGE: 2;
        uint32_t DEVACTIVE21_EDGE: 2;
        uint32_t DEVACTIVE22_EDGE: 2;
        uint32_t DEVACTIVE23_EDGE: 2;
        uint32_t RESERVED: 16;
    };
} PPU_PPU_OPSR_VPON_PPU_TYPE;

/*0x4000_2044 PPU_PPU_OPSR_VPON_PPU*/
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE16_EDGE_Pos                   0U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE16_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE16_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE17_EDGE_Pos                   2U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE17_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE17_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE18_EDGE_Pos                   4U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE18_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE18_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE19_EDGE_Pos                   6U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE19_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE19_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE20_EDGE_Pos                   8U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE20_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE20_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE21_EDGE_Pos                   10U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE21_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE21_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE22_EDGE_Pos                   12U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE22_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE22_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE23_EDGE_Pos                   14U
#define PPU_PPU_OPSR_VPON_PPU_DEVACTIVE23_EDGE_Msk                   (0x3UL << PPU_PPU_OPSR_VPON_PPU_DEVACTIVE23_EDGE_Pos)

#define PPU_PPU_OPSR_VPON_PPU_RESERVED_Pos                           16U
#define PPU_PPU_OPSR_VPON_PPU_RESERVED_Msk                           (0xFFFFUL << PPU_PPU_OPSR_VPON_PPU_RESERVED_Pos)

/* 0x0050   0x4000_2050
    7:0     RW      FUNC_RET_RAM_CFG            0x0
    31:8    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_FUNRR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FUNC_RET_RAM_CFG: 8;
        uint32_t RESERVED: 24;
    };
} PPU_PPU_FUNRR_VPON_PPU_TYPE;

/*0x4000_2050 PPU_PPU_FUNRR_VPON_PPU*/
#define PPU_PPU_FUNRR_VPON_PPU_FUNC_RET_RAM_CFG_Pos                  0U
#define PPU_PPU_FUNRR_VPON_PPU_FUNC_RET_RAM_CFG_Msk                  (0xFFUL << PPU_PPU_FUNRR_VPON_PPU_FUNC_RET_RAM_CFG_Pos)

#define PPU_PPU_FUNRR_VPON_PPU_RESERVED_Pos                          8U
#define PPU_PPU_FUNRR_VPON_PPU_RESERVED_Msk                          (0xFFFFFFUL << PPU_PPU_FUNRR_VPON_PPU_RESERVED_Pos)

/* 0x0054   0x4000_2054
    7:0     RW      FULL_RET_RAM_CFG            0x0
    31:8    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_FULRR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FULL_RET_RAM_CFG: 8;
        uint32_t RESERVED: 24;
    };
} PPU_PPU_FULRR_VPON_PPU_TYPE;

/*0x4000_2054 PPU_PPU_FULRR_VPON_PPU*/
#define PPU_PPU_FULRR_VPON_PPU_FULL_RET_RAM_CFG_Pos                  0U
#define PPU_PPU_FULRR_VPON_PPU_FULL_RET_RAM_CFG_Msk                  (0xFFUL << PPU_PPU_FULRR_VPON_PPU_FULL_RET_RAM_CFG_Pos)

#define PPU_PPU_FULRR_VPON_PPU_RESERVED_Pos                          8U
#define PPU_PPU_FULRR_VPON_PPU_RESERVED_Msk                          (0xFFFFFFUL << PPU_PPU_FULRR_VPON_PPU_RESERVED_Pos)

/* 0x0058   0x4000_2058
    7:0     RW      MEM_RET_RAM_CFG             0x0
    31:8    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_MEMRR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MEM_RET_RAM_CFG: 8;
        uint32_t RESERVED: 24;
    };
} PPU_PPU_MEMRR_VPON_PPU_TYPE;

/*0x4000_2058 PPU_PPU_MEMRR_VPON_PPU*/
#define PPU_PPU_MEMRR_VPON_PPU_MEM_RET_RAM_CFG_Pos                   0U
#define PPU_PPU_MEMRR_VPON_PPU_MEM_RET_RAM_CFG_Msk                   (0xFFUL << PPU_PPU_MEMRR_VPON_PPU_MEM_RET_RAM_CFG_Pos)

#define PPU_PPU_MEMRR_VPON_PPU_RESERVED_Pos                          8U
#define PPU_PPU_MEMRR_VPON_PPU_RESERVED_Msk                          (0xFFFFFFUL << PPU_PPU_MEMRR_VPON_PPU_RESERVED_Pos)

/* 0x0160   0x4000_2160
    7:0     RW      OFF_DEL                     0x00
    15:8    RW      MEM_RET_DEL                 0x00
    23:16   RW      LOGIC_RET_DEL               0x00
    31:24   RW      FULL_RET_DEL                0x00
 */
typedef union _PPU_PPU_EDTR0_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t OFF_DEL: 8;
        uint32_t MEM_RET_DEL: 8;
        uint32_t LOGIC_RET_DEL: 8;
        uint32_t FULL_RET_DEL: 8;
    };
} PPU_PPU_EDTR0_VPON_PPU_TYPE;

/*0x4000_2160 PPU_PPU_EDTR0_VPON_PPU*/
#define PPU_PPU_EDTR0_VPON_PPU_OFF_DEL_Pos                           0U
#define PPU_PPU_EDTR0_VPON_PPU_OFF_DEL_Msk                           (0xFFUL << PPU_PPU_EDTR0_VPON_PPU_OFF_DEL_Pos)

#define PPU_PPU_EDTR0_VPON_PPU_MEM_RET_DEL_Pos                       8U
#define PPU_PPU_EDTR0_VPON_PPU_MEM_RET_DEL_Msk                       (0xFFUL << PPU_PPU_EDTR0_VPON_PPU_MEM_RET_DEL_Pos)

#define PPU_PPU_EDTR0_VPON_PPU_LOGIC_RET_DEL_Pos                     16U
#define PPU_PPU_EDTR0_VPON_PPU_LOGIC_RET_DEL_Msk                     (0xFFUL << PPU_PPU_EDTR0_VPON_PPU_LOGIC_RET_DEL_Pos)

#define PPU_PPU_EDTR0_VPON_PPU_FULL_RET_DEL_Pos                      24U
#define PPU_PPU_EDTR0_VPON_PPU_FULL_RET_DEL_Msk                      (0xFFUL << PPU_PPU_EDTR0_VPON_PPU_FULL_RET_DEL_Pos)

/* 0x0164   0x4000_2164
    7:0     RW      MEM_OFF_DEL                 0x00
    15:8    RW      FUNC_RET_DEL                0x00
    31:16   RO      RESERVED                    0x00
 */
typedef union _PPU_PPU_EDTR1_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t MEM_OFF_DEL: 8;
        uint32_t FUNC_RET_DEL: 8;
        uint32_t RESERVED: 16;
    };
} PPU_PPU_EDTR1_VPON_PPU_TYPE;

/*0x4000_2164 PPU_PPU_EDTR1_VPON_PPU*/
#define PPU_PPU_EDTR1_VPON_PPU_MEM_OFF_DEL_Pos                       0U
#define PPU_PPU_EDTR1_VPON_PPU_MEM_OFF_DEL_Msk                       (0xFFUL << PPU_PPU_EDTR1_VPON_PPU_MEM_OFF_DEL_Pos)

#define PPU_PPU_EDTR1_VPON_PPU_FUNC_RET_DEL_Pos                      8U
#define PPU_PPU_EDTR1_VPON_PPU_FUNC_RET_DEL_Msk                      (0xFFUL << PPU_PPU_EDTR1_VPON_PPU_FUNC_RET_DEL_Pos)

#define PPU_PPU_EDTR1_VPON_PPU_RESERVED_Pos                          16U
#define PPU_PPU_EDTR1_VPON_PPU_RESERVED_Msk                          (0xFFFFUL << PPU_PPU_EDTR1_VPON_PPU_RESERVED_Pos)

/* 0x0170   0x4000_2170
    7:0     RW      CLKEN_RST_DLY               CLKEN_RST_DLY_CFG
    15:8    RW      ISO_CLKEN_DLY               ISO_CLKEN_DLY_CFG
    23:16   RW      RST_HWSTAT_DLY              RST_HWSTAT_DLY_CFG
    31:24   RO      RESERVED                    0x000
 */
typedef union _PPU_PPU_DCDR0_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t CLKEN_RST_DLY: 8;
        uint32_t ISO_CLKEN_DLY: 8;
        uint32_t RST_HWSTAT_DLY: 8;
        uint32_t RESERVED: 8;
    };
} PPU_PPU_DCDR0_VPON_PPU_TYPE;

/*0x4000_2170 PPU_PPU_DCDR0_VPON_PPU*/
#define PPU_PPU_DCDR0_VPON_PPU_CLKEN_RST_DLY_Pos                     0U
#define PPU_PPU_DCDR0_VPON_PPU_CLKEN_RST_DLY_Msk                     (0xFFUL << PPU_PPU_DCDR0_VPON_PPU_CLKEN_RST_DLY_Pos)

#define PPU_PPU_DCDR0_VPON_PPU_ISO_CLKEN_DLY_Pos                     8U
#define PPU_PPU_DCDR0_VPON_PPU_ISO_CLKEN_DLY_Msk                     (0xFFUL << PPU_PPU_DCDR0_VPON_PPU_ISO_CLKEN_DLY_Pos)

#define PPU_PPU_DCDR0_VPON_PPU_RST_HWSTAT_DLY_Pos                    16U
#define PPU_PPU_DCDR0_VPON_PPU_RST_HWSTAT_DLY_Msk                    (0xFFUL << PPU_PPU_DCDR0_VPON_PPU_RST_HWSTAT_DLY_Pos)

#define PPU_PPU_DCDR0_VPON_PPU_RESERVED_Pos                          24U
#define PPU_PPU_DCDR0_VPON_PPU_RESERVED_Msk                          (0xFFUL << PPU_PPU_DCDR0_VPON_PPU_RESERVED_Pos)

/* 0x0174   0x4000_2174
    7:0     RW      ISO_RST_DLY                 ISO_RST_DLY_CFG
    15:8    RW      CLKEN_ISO_DLY               CLKEN_ISO_DLY_CFG
    31:16   RO      RESERVED                    0x0000
 */
typedef union _PPU_PPU_DCDR1_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ISO_RST_DLY: 8;
        uint32_t CLKEN_ISO_DLY: 8;
        uint32_t RESERVED: 16;
    };
} PPU_PPU_DCDR1_VPON_PPU_TYPE;

/*0x4000_2174 PPU_PPU_DCDR1_VPON_PPU*/
#define PPU_PPU_DCDR1_VPON_PPU_ISO_RST_DLY_Pos                       0U
#define PPU_PPU_DCDR1_VPON_PPU_ISO_RST_DLY_Msk                       (0xFFUL << PPU_PPU_DCDR1_VPON_PPU_ISO_RST_DLY_Pos)

#define PPU_PPU_DCDR1_VPON_PPU_CLKEN_ISO_DLY_Pos                     8U
#define PPU_PPU_DCDR1_VPON_PPU_CLKEN_ISO_DLY_Msk                     (0xFFUL << PPU_PPU_DCDR1_VPON_PPU_CLKEN_ISO_DLY_Pos)

#define PPU_PPU_DCDR1_VPON_PPU_RESERVED_Pos                          16U
#define PPU_PPU_DCDR1_VPON_PPU_RESERVED_Msk                          (0xFFFFUL << PPU_PPU_DCDR1_VPON_PPU_RESERVED_Pos)

/* 0x0FB0   0x4000_2fb0
    3:0     RO      DEVCHAN                     DEVCHAN_CFG
    7:4     RO      NUM_OPMODE                  NUM_OPMODE_CFG
    8       RO      STA_OFF_SPT                 0x1
    9       RO      STA_OFF_EMU_SPT             STA_OFF_EMU_SPT_CFG
    10      RO      STA_MEM_RET_SPT             STA_MEM_RET_SPT_CFG
    11      RO      STA_MEM_RET_EMU_SPT         STA_MEM_RET_EMU_SPT_CFG
    12      RO      STA_LGC_RET_SPT             STA_LGC_RET_SPT_CFG
    13      RO      STA_MEM_OFF_SPT             STA_MEM_OFF_SPT_CFG
    14      RO      STA_FULL_RET_SPT            STA_FULL_RET_SPT_CFG
    15      RO      STA_FUNC_RET_SPT            STA_FUNC_RET_SPT_CFG
    16      RO      STA_ON_SPT                  0x1
    17      RO      STA_WRM_RST_SPT             0x1
    18      RO      STA_DBG_RECOV_SPT           STA_DBG_RECOV_SPT_CFG
    19      RO      RESERVED_1                  0X0
    20      RO      DYN_OFF_SPT                 DYN_OFF_SPT_CFG
    21      RO      DYN_OFF_EMU_SPT             DYN_OFF_EMU_SPT_CFG
    22      RO      DYN_MEM_RET_SPT             DYN_MEM_RET_SPT_CFG
    23      RO      DYN_MEM_RET_EMU_SPT         DYN_MEM_RET_EMU_SPT_CFG
    24      RO      DYN_LGC_RET_SPT             DYN_LGC_RET_SPT_CFG
    25      RO      DYN_MEM_OFF_SPT             DYN_MEM_OFF_SPT_CFG
    26      RO      DYN_FULL_RET_SPT            DYN_FULL_RET_SPT_CFG
    27      RO      DYN_FUNC_RET_SPT            DYN_FUNC_RET_SPT_CFG
    28      RO      DYN_ON_SPT                  DYN_ON_SPT_CFG
    29      RO      DYN_WRM_RST_SPT             DYN_WRM_RST_SPT_CFG
    31:30   RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_IDR0_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t DEVCHAN: 4;
        uint32_t NUM_OPMODE: 4;
        uint32_t STA_OFF_SPT: 1;
        uint32_t STA_OFF_EMU_SPT: 1;
        uint32_t STA_MEM_RET_SPT: 1;
        uint32_t STA_MEM_RET_EMU_SPT: 1;
        uint32_t STA_LGC_RET_SPT: 1;
        uint32_t STA_MEM_OFF_SPT: 1;
        uint32_t STA_FULL_RET_SPT: 1;
        uint32_t STA_FUNC_RET_SPT: 1;
        uint32_t STA_ON_SPT: 1;
        uint32_t STA_WRM_RST_SPT: 1;
        uint32_t STA_DBG_RECOV_SPT: 1;
        uint32_t RESERVED_1: 1;
        uint32_t DYN_OFF_SPT: 1;
        uint32_t DYN_OFF_EMU_SPT: 1;
        uint32_t DYN_MEM_RET_SPT: 1;
        uint32_t DYN_MEM_RET_EMU_SPT: 1;
        uint32_t DYN_LGC_RET_SPT: 1;
        uint32_t DYN_MEM_OFF_SPT: 1;
        uint32_t DYN_FULL_RET_SPT: 1;
        uint32_t DYN_FUNC_RET_SPT: 1;
        uint32_t DYN_ON_SPT: 1;
        uint32_t DYN_WRM_RST_SPT: 1;
        uint32_t RESERVED: 2;
    };
} PPU_PPU_IDR0_VPON_PPU_TYPE;

/*0x4000_2fb0 PPU_PPU_IDR0_VPON_PPU*/
#define PPU_PPU_IDR0_VPON_PPU_DEVCHAN_Pos                            0U
#define PPU_PPU_IDR0_VPON_PPU_DEVCHAN_Msk                            (0xFUL << PPU_PPU_IDR0_VPON_PPU_DEVCHAN_Pos)

#define PPU_PPU_IDR0_VPON_PPU_NUM_OPMODE_Pos                         4U
#define PPU_PPU_IDR0_VPON_PPU_NUM_OPMODE_Msk                         (0xFUL << PPU_PPU_IDR0_VPON_PPU_NUM_OPMODE_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_OFF_SPT_Pos                        8U
#define PPU_PPU_IDR0_VPON_PPU_STA_OFF_SPT_Msk                        (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_OFF_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_OFF_EMU_SPT_Pos                    9U
#define PPU_PPU_IDR0_VPON_PPU_STA_OFF_EMU_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_OFF_EMU_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_SPT_Pos                    10U
#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_EMU_SPT_Pos                11U
#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_EMU_SPT_Msk                (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_MEM_RET_EMU_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_LGC_RET_SPT_Pos                    12U
#define PPU_PPU_IDR0_VPON_PPU_STA_LGC_RET_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_LGC_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_OFF_SPT_Pos                    13U
#define PPU_PPU_IDR0_VPON_PPU_STA_MEM_OFF_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_MEM_OFF_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_FULL_RET_SPT_Pos                   14U
#define PPU_PPU_IDR0_VPON_PPU_STA_FULL_RET_SPT_Msk                   (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_FULL_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_FUNC_RET_SPT_Pos                   15U
#define PPU_PPU_IDR0_VPON_PPU_STA_FUNC_RET_SPT_Msk                   (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_FUNC_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_ON_SPT_Pos                         16U
#define PPU_PPU_IDR0_VPON_PPU_STA_ON_SPT_Msk                         (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_ON_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_WRM_RST_SPT_Pos                    17U
#define PPU_PPU_IDR0_VPON_PPU_STA_WRM_RST_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_WRM_RST_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_STA_DBG_RECOV_SPT_Pos                  18U
#define PPU_PPU_IDR0_VPON_PPU_STA_DBG_RECOV_SPT_Msk                  (0x1UL << PPU_PPU_IDR0_VPON_PPU_STA_DBG_RECOV_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_RESERVED_1_Pos                         19U
#define PPU_PPU_IDR0_VPON_PPU_RESERVED_1_Msk                         (0x1UL << PPU_PPU_IDR0_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_OFF_SPT_Pos                        20U
#define PPU_PPU_IDR0_VPON_PPU_DYN_OFF_SPT_Msk                        (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_OFF_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_OFF_EMU_SPT_Pos                    21U
#define PPU_PPU_IDR0_VPON_PPU_DYN_OFF_EMU_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_OFF_EMU_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_SPT_Pos                    22U
#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_EMU_SPT_Pos                23U
#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_EMU_SPT_Msk                (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_MEM_RET_EMU_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_LGC_RET_SPT_Pos                    24U
#define PPU_PPU_IDR0_VPON_PPU_DYN_LGC_RET_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_LGC_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_OFF_SPT_Pos                    25U
#define PPU_PPU_IDR0_VPON_PPU_DYN_MEM_OFF_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_MEM_OFF_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_FULL_RET_SPT_Pos                   26U
#define PPU_PPU_IDR0_VPON_PPU_DYN_FULL_RET_SPT_Msk                   (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_FULL_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_FUNC_RET_SPT_Pos                   27U
#define PPU_PPU_IDR0_VPON_PPU_DYN_FUNC_RET_SPT_Msk                   (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_FUNC_RET_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_ON_SPT_Pos                         28U
#define PPU_PPU_IDR0_VPON_PPU_DYN_ON_SPT_Msk                         (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_ON_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_DYN_WRM_RST_SPT_Pos                    29U
#define PPU_PPU_IDR0_VPON_PPU_DYN_WRM_RST_SPT_Msk                    (0x1UL << PPU_PPU_IDR0_VPON_PPU_DYN_WRM_RST_SPT_Pos)

#define PPU_PPU_IDR0_VPON_PPU_RESERVED_Pos                           30U
#define PPU_PPU_IDR0_VPON_PPU_RESERVED_Msk                           (0x3UL << PPU_PPU_IDR0_VPON_PPU_RESERVED_Pos)

/* 0x0FB4   0x4000_2fb4
    0       RO      PWR_MODE_ENTRY_DEL_SPT      PWR_MODE_ENTRY_DEL_CFG
    1       RO      SW_DEV_DEL_SPT              SW_DEV_DEL_CFG
    2       RO      LOCK_SPT                    LOCK_CFG
    3       RO      RESERVED_3                  0x0
    4       RO      MEM_RET_RAM_REG             MEM_RET_RAM_REG_CFG
    5       RO      FULL_RET_RAM_REG            FULL_RET_RAM_REG_CFG
    6       RO      FUNC_RET_RAM_REG            FUNC_RET_RAM_REG_CFG
    7       RO      RESERVED_2                  0x0
    8       RO      STA_POLICY_PWR_IRQ_SPT      STA_POLICY_PWR_IRQ_CFG
    9       RO      STA_POLICY_OP_IRQ_SPT       STA_POLICY_OP_IRQ_CFG
    10      RO      OP_ACTIVE                   OP_ACTIVE_CFG
    11      RO      RESERVED_1                  0x0
    12      RO      OFF_MEM_RET_TRANS           OFF_MEM_RET_TRANS_CFG
    31:13   RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_IDR1_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PWR_MODE_ENTRY_DEL_SPT: 1;
        uint32_t SW_DEV_DEL_SPT: 1;
        uint32_t LOCK_SPT: 1;
        uint32_t RESERVED_3: 1;
        uint32_t MEM_RET_RAM_REG: 1;
        uint32_t FULL_RET_RAM_REG: 1;
        uint32_t FUNC_RET_RAM_REG: 1;
        uint32_t RESERVED_2: 1;
        uint32_t STA_POLICY_PWR_IRQ_SPT: 1;
        uint32_t STA_POLICY_OP_IRQ_SPT: 1;
        uint32_t OP_ACTIVE: 1;
        uint32_t RESERVED_1: 1;
        uint32_t OFF_MEM_RET_TRANS: 1;
        uint32_t RESERVED: 19;
    };
} PPU_PPU_IDR1_VPON_PPU_TYPE;

/*0x4000_2fb4 PPU_PPU_IDR1_VPON_PPU*/
#define PPU_PPU_IDR1_VPON_PPU_PWR_MODE_ENTRY_DEL_SPT_Pos             0U
#define PPU_PPU_IDR1_VPON_PPU_PWR_MODE_ENTRY_DEL_SPT_Msk             (0x1UL << PPU_PPU_IDR1_VPON_PPU_PWR_MODE_ENTRY_DEL_SPT_Pos)

#define PPU_PPU_IDR1_VPON_PPU_SW_DEV_DEL_SPT_Pos                     1U
#define PPU_PPU_IDR1_VPON_PPU_SW_DEV_DEL_SPT_Msk                     (0x1UL << PPU_PPU_IDR1_VPON_PPU_SW_DEV_DEL_SPT_Pos)

#define PPU_PPU_IDR1_VPON_PPU_LOCK_SPT_Pos                           2U
#define PPU_PPU_IDR1_VPON_PPU_LOCK_SPT_Msk                           (0x1UL << PPU_PPU_IDR1_VPON_PPU_LOCK_SPT_Pos)

#define PPU_PPU_IDR1_VPON_PPU_RESERVED_3_Pos                         3U
#define PPU_PPU_IDR1_VPON_PPU_RESERVED_3_Msk                         (0x1UL << PPU_PPU_IDR1_VPON_PPU_RESERVED_3_Pos)

#define PPU_PPU_IDR1_VPON_PPU_MEM_RET_RAM_REG_Pos                    4U
#define PPU_PPU_IDR1_VPON_PPU_MEM_RET_RAM_REG_Msk                    (0x1UL << PPU_PPU_IDR1_VPON_PPU_MEM_RET_RAM_REG_Pos)

#define PPU_PPU_IDR1_VPON_PPU_FULL_RET_RAM_REG_Pos                   5U
#define PPU_PPU_IDR1_VPON_PPU_FULL_RET_RAM_REG_Msk                   (0x1UL << PPU_PPU_IDR1_VPON_PPU_FULL_RET_RAM_REG_Pos)

#define PPU_PPU_IDR1_VPON_PPU_FUNC_RET_RAM_REG_Pos                   6U
#define PPU_PPU_IDR1_VPON_PPU_FUNC_RET_RAM_REG_Msk                   (0x1UL << PPU_PPU_IDR1_VPON_PPU_FUNC_RET_RAM_REG_Pos)

#define PPU_PPU_IDR1_VPON_PPU_RESERVED_2_Pos                         7U
#define PPU_PPU_IDR1_VPON_PPU_RESERVED_2_Msk                         (0x1UL << PPU_PPU_IDR1_VPON_PPU_RESERVED_2_Pos)

#define PPU_PPU_IDR1_VPON_PPU_STA_POLICY_PWR_IRQ_SPT_Pos             8U
#define PPU_PPU_IDR1_VPON_PPU_STA_POLICY_PWR_IRQ_SPT_Msk             (0x1UL << PPU_PPU_IDR1_VPON_PPU_STA_POLICY_PWR_IRQ_SPT_Pos)

#define PPU_PPU_IDR1_VPON_PPU_STA_POLICY_OP_IRQ_SPT_Pos              9U
#define PPU_PPU_IDR1_VPON_PPU_STA_POLICY_OP_IRQ_SPT_Msk              (0x1UL << PPU_PPU_IDR1_VPON_PPU_STA_POLICY_OP_IRQ_SPT_Pos)

#define PPU_PPU_IDR1_VPON_PPU_OP_ACTIVE_Pos                          10U
#define PPU_PPU_IDR1_VPON_PPU_OP_ACTIVE_Msk                          (0x1UL << PPU_PPU_IDR1_VPON_PPU_OP_ACTIVE_Pos)

#define PPU_PPU_IDR1_VPON_PPU_RESERVED_1_Pos                         11U
#define PPU_PPU_IDR1_VPON_PPU_RESERVED_1_Msk                         (0x1UL << PPU_PPU_IDR1_VPON_PPU_RESERVED_1_Pos)

#define PPU_PPU_IDR1_VPON_PPU_OFF_MEM_RET_TRANS_Pos                  12U
#define PPU_PPU_IDR1_VPON_PPU_OFF_MEM_RET_TRANS_Msk                  (0x1UL << PPU_PPU_IDR1_VPON_PPU_OFF_MEM_RET_TRANS_Pos)

#define PPU_PPU_IDR1_VPON_PPU_RESERVED_Pos                           13U
#define PPU_PPU_IDR1_VPON_PPU_RESERVED_Msk                           (0x7FFFFUL << PPU_PPU_IDR1_VPON_PPU_RESERVED_Pos)

/* 0x0FC8   0x4000_2fc8
    11:0    RO      IMPLEMENTER                 -.
    15:12   RO      REVISIONIMPLEMENTATION      -
    19:16   RO      VARIANTIMPLEMENTATION       -
    31:20   RO      PRODUCT_IDIMPLEMENTATION    -
 */
typedef union _PPU_PPU_IIDR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t IMPLEMENTER: 12;
        uint32_t REVISIONIMPLEMENTATION: 4;
        uint32_t VARIANTIMPLEMENTATION: 4;
        uint32_t PRODUCT_IDIMPLEMENTATION: 12;
    };
} PPU_PPU_IIDR_VPON_PPU_TYPE;

/*0x4000_2fc8 PPU_PPU_IIDR_VPON_PPU*/
#define PPU_PPU_IIDR_VPON_PPU_IMPLEMENTER_Pos                        0U
#define PPU_PPU_IIDR_VPON_PPU_IMPLEMENTER_Msk                        (0xFFFUL << PPU_PPU_IIDR_VPON_PPU_IMPLEMENTER_Pos)

#define PPU_PPU_IIDR_VPON_PPU_REVISIONIMPLEMENTATION_Pos             12U
#define PPU_PPU_IIDR_VPON_PPU_REVISIONIMPLEMENTATION_Msk             (0xFUL << PPU_PPU_IIDR_VPON_PPU_REVISIONIMPLEMENTATION_Pos)

#define PPU_PPU_IIDR_VPON_PPU_VARIANTIMPLEMENTATION_Pos              16U
#define PPU_PPU_IIDR_VPON_PPU_VARIANTIMPLEMENTATION_Msk              (0xFUL << PPU_PPU_IIDR_VPON_PPU_VARIANTIMPLEMENTATION_Pos)

#define PPU_PPU_IIDR_VPON_PPU_PRODUCT_IDIMPLEMENTATION_Pos           20U
#define PPU_PPU_IIDR_VPON_PPU_PRODUCT_IDIMPLEMENTATION_Msk           (0xFFFUL << PPU_PPU_IIDR_VPON_PPU_PRODUCT_IDIMPLEMENTATION_Pos)

/* 0x0FCC   0x4000_2fcc
    3:0     RO      ARCH_REV_MINOR              0x1
    7:4     RO      ARCH_REV_MAJOR              0x1
    31:8    RO      RESERVED                    0x0
 */
typedef union _PPU_PPU_AIDR_VPON_PPU_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t ARCH_REV_MINOR: 4;
        uint32_t ARCH_REV_MAJOR: 4;
        uint32_t RESERVED: 24;
    };
} PPU_PPU_AIDR_VPON_PPU_TYPE;

/*0x4000_2fcc PPU_PPU_AIDR_VPON_PPU*/
#define PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MINOR_Pos                     0U
#define PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MINOR_Msk                     (0xFUL << PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MINOR_Pos)

#define PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MAJOR_Pos                     4U
#define PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MAJOR_Msk                     (0xFUL << PPU_PPU_AIDR_VPON_PPU_ARCH_REV_MAJOR_Pos)

#define PPU_PPU_AIDR_VPON_PPU_RESERVED_Pos                           8U
#define PPU_PPU_AIDR_VPON_PPU_RESERVED_Msk                           (0xFFFFFFUL << PPU_PPU_AIDR_VPON_PPU_RESERVED_Pos)

/* 0x0FD0   0x4000_2fd0
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_1_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_1_TYPE;

/*0x4000_2fd0 PPU_ID_REG_VPON_PPU_1*/
#define PPU_ID_REG_VPON_PPU_1_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_1_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_1_RESERVED_Pos)

/* 0x0FD4   0x4000_2fd4
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_2_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_2_TYPE;

/*0x4000_2fd4 PPU_ID_REG_VPON_PPU_2*/
#define PPU_ID_REG_VPON_PPU_2_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_2_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_2_RESERVED_Pos)

/* 0x0FD8   0x4000_2fd8
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_3_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_3_TYPE;

/*0x4000_2fd8 PPU_ID_REG_VPON_PPU_3*/
#define PPU_ID_REG_VPON_PPU_3_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_3_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_3_RESERVED_Pos)

/* 0x0FDC   0x4000_2fdc
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_4_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_4_TYPE;

/*0x4000_2fdc PPU_ID_REG_VPON_PPU_4*/
#define PPU_ID_REG_VPON_PPU_4_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_4_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_4_RESERVED_Pos)

/* 0x0FE0   0x4000_2fe0
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_5_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_5_TYPE;

/*0x4000_2fe0 PPU_ID_REG_VPON_PPU_5*/
#define PPU_ID_REG_VPON_PPU_5_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_5_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_5_RESERVED_Pos)

/* 0x0FE4   0x4000_2fe4
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_6_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_6_TYPE;

/*0x4000_2fe4 PPU_ID_REG_VPON_PPU_6*/
#define PPU_ID_REG_VPON_PPU_6_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_6_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_6_RESERVED_Pos)

/* 0x0FE8   0x4000_2fe8
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_7_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_7_TYPE;

/*0x4000_2fe8 PPU_ID_REG_VPON_PPU_7*/
#define PPU_ID_REG_VPON_PPU_7_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_7_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_7_RESERVED_Pos)

/* 0x0FEC   0x4000_2fec
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_8_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_8_TYPE;

/*0x4000_2fec PPU_ID_REG_VPON_PPU_8*/
#define PPU_ID_REG_VPON_PPU_8_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_8_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_8_RESERVED_Pos)

/* 0x0FF0   0x4000_2ff0
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_9_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_9_TYPE;

/*0x4000_2ff0 PPU_ID_REG_VPON_PPU_9*/
#define PPU_ID_REG_VPON_PPU_9_RESERVED_Pos                           0U
#define PPU_ID_REG_VPON_PPU_9_RESERVED_Msk                           (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_9_RESERVED_Pos)

/* 0x0FF4   0x4000_2ff4
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_10_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_10_TYPE;

/*0x4000_2ff4 PPU_ID_REG_VPON_PPU_10*/
#define PPU_ID_REG_VPON_PPU_10_RESERVED_Pos                          0U
#define PPU_ID_REG_VPON_PPU_10_RESERVED_Msk                          (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_10_RESERVED_Pos)

/* 0x0FF8   0x4000_2ff8
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_11_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_11_TYPE;

/*0x4000_2ff8 PPU_ID_REG_VPON_PPU_11*/
#define PPU_ID_REG_VPON_PPU_11_RESERVED_Pos                          0U
#define PPU_ID_REG_VPON_PPU_11_RESERVED_Msk                          (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_11_RESERVED_Pos)

/* 0x0FFC   0x4000_2ffc
    31:0    RO      RESERVED                    32'h0
 */
typedef union _PPU_ID_REG_VPON_PPU_12_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t RESERVED;
    };
} PPU_ID_REG_VPON_PPU_12_TYPE;

/*0x4000_2ffc PPU_ID_REG_VPON_PPU_12*/
#define PPU_ID_REG_VPON_PPU_12_RESERVED_Pos                          0U
#define PPU_ID_REG_VPON_PPU_12_RESERVED_Msk                          (0xFFFFFFFFUL << PPU_ID_REG_VPON_PPU_12_RESERVED_Pos)

#define PPU_VPON_BASE 0x40002000
#define PPU_VCORE_BASE 0x4001B000

#define PPU_REG_READ(Base, Offset)\
    ((uint32_t)*((volatile uint32_t*)(Base+(Offset))))

#define PPU_REG_WRITE(Base, Offset, Value)\
    ((*((volatile uint32_t*)(Base + (Offset)))) = (Value))

#define PPU_REG_UPDATE(Base, Offset, Mask, Value) \
    do {\
        uint32_t temp;\
        temp = PPU_REG_READ(Base, Offset) & ~(Mask);\
        PPU_REG_WRITE(Base, Offset, (temp | ((Value) & (Mask))));\
    } while(0)

#define PPU_REG_READ_BITFIELD(Base, Offset, Bitfield)                   \
    (((Offset##_TYPE)PPU_REG_READ(Base, Offset)).Bitfield)

#define PPU_REG_WRITE_BITFIELD(Base, Offset, Bitfield, Value)           \
    do {                                                        \
        Offset##_TYPE temp = {.d32 = PPU_REG_READ(Base, Offset)};       \
        temp.Bitfield = Value;                                         \
        PPU_REG_WRITE(Base, Offset, temp.d32);                          \
    } while(0)

#endif //#define PPU_REG_H
