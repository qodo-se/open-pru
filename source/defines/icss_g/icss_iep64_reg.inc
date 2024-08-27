; BSD 3-Clause License

; Copyright (c) 2024, Texas Instruments

; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are met:

; 1. Redistributions of source code must retain the above copyright notice, this
;    list of conditions and the following disclaimer.

; 2. Redistributions in binary form must reproduce the above copyright notice,
;    this list of conditions and the following disclaimer in the documentation
;    and/or other materials provided with the distribution.

; 3. Neither the name of the copyright holder nor the names of its
;    contributors may be used to endorse or promote products derived from
;    this software without specific prior written permission.

; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
; CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
; OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

; file name: icss_iep64_reg.inc

;/**************************************************************************
;* IEP IEP_PD_WD_TIM_REG base address  :
;**************************************************************************/
; C26 is IEP0 base address 
IEP0_CONST                                           .set     c26
IEP1_CONST                                           .set     c1

IEP0_0X100_CONST                                     .set     c8
IEP1_0X100_CONST                                     .set     c2

IEP0_BASE_ADDR                                       .set     0x0002e000
IEP1_BASE_ADDR                                       .set     0x0002f000

;/**************************************************************************
;* Register Macros
;**************************************************************************/

IEP_GLOBAL_CFG_REG          .set     0x00000000
IEP_GLOBAL_STATUS_REG       .set     0x00000004
IEP_COMPEN_REG              .set     0x00000008
IEP_SLOW_COMPEN_REG         .set     0x0000000C
IEP_COUNT_REG0              .set     0x00000010
IEP_COUNT_REG1              .set     0x00000014
IEP_CAP_CFG_REG             .set     0x00000018
IEP_CAP_STATUS_REG          .set     0x0000001C
IEP_CAPR0_REG0              .set     0x00000020
IEP_CAPR0_REG1              .set     0x00000024
IEP_CAPR1_REG0              .set     0x00000028
IEP_CAPR1_REG1              .set     0x0000002C
IEP_CAPR2_REG0              .set     0x00000030
IEP_CAPR2_REG1              .set     0x00000034
IEP_CAPR3_REG0              .set     0x00000038
IEP_CAPR3_REG1              .set     0x0000003C
IEP_CAPR4_REG0              .set     0x00000040
IEP_CAPR4_REG1              .set     0x00000044
IEP_CAPR5_REG0              .set     0x00000048
IEP_CAPR5_REG1              .set     0x0000004C
IEP_CAPR6_REG0              .set     0x00000050
IEP_CAPR6_REG1              .set     0x00000054
IEP_CAPF6_REG0              .set     0x00000058
IEP_CAPF6_REG1              .set     0x0000005C
IEP_CAPR7_REG0              .set     0x00000060
IEP_CAPR7_REG1              .set     0x00000064
IEP_CAPF7_REG0              .set     0x00000068
IEP_CAPF7_REG1              .set     0x0000006C
IEP_CMP_CFG_REG             .set     0x00000070
IEP_CMP_STATUS_REG          .set     0x00000074
IEP_CMP0_REG0               .set     0x00000078
IEP_CMP0_REG1               .set     0x0000007C
IEP_CMP1_REG0               .set     0x00000080
IEP_CMP1_REG1               .set     0x00000084
IEP_CMP2_REG0               .set     0x00000088
IEP_CMP2_REG1               .set     0x0000008C
IEP_CMP3_REG0               .set     0x00000090
IEP_CMP3_REG1               .set     0x00000094
IEP_CMP4_REG0               .set     0x00000098
IEP_CMP4_REG1               .set     0x0000009C
IEP_CMP5_REG0               .set     0x000000A0
IEP_CMP5_REG1               .set     0x000000A4
IEP_CMP6_REG0               .set     0x000000A8
IEP_CMP6_REG1               .set     0x000000AC
IEP_CMP7_REG0               .set     0x000000B0
IEP_CMP7_REG1               .set     0x000000B4
IEP_RXIPG0_REG              .set     0x000000B8
IEP_RXIPG1_REG              .set     0x000000BC
IEP_CMP8_REG0               .set     0x000000C0
IEP_CMP8_REG1               .set     0x000000C4
IEP_CMP9_REG0               .set     0x000000C8
IEP_CMP9_REG1               .set     0x000000CC
IEP_CMP10_REG0              .set     0x000000D0
IEP_CMP10_REG1              .set     0x000000D4
IEP_CMP11_REG0              .set     0x000000D8
IEP_CMP11_REG1              .set     0x000000DC
IEP_CMP12_REG0              .set     0x000000E0
IEP_CMP12_REG1              .set     0x000000E4
IEP_CMP13_REG0              .set     0x000000E8
IEP_CMP13_REG1              .set     0x000000EC
IEP_CMP14_REG0              .set     0x000000F0
IEP_CMP14_REG1              .set     0x000000F4
IEP_CMP15_REG0              .set     0x000000F8
IEP_CMP15_REG1              .set     0x000000FC
IEP_COUNT_RESET_VAL_REG0    .set     0x00000100
IEP_COUNT_RESET_VAL_REG1    .set     0x00000104
IEP_PWM_REG                 .set     0x00000108
IEP_CAPR0_BI_REG0           .set     0x0000010C
IEP_CAPR0_BI_REG1           .set     0x00000110
IEP_CAPR1_BI_REG0           .set     0x00000114
IEP_CAPR1_BI_REG1           .set     0x00000118
IEP_CAPR2_BI_REG0           .set     0x0000011C
IEP_CAPR2_BI_REG1           .set     0x00000120
IEP_CAPR3_BI_REG0           .set     0x00000124
IEP_CAPR3_BI_REG1           .set     0x00000128
IEP_CAPR4_BI_REG0           .set     0x0000012C
IEP_CAPR4_BI_REG1           .set     0x00000130
IEP_CAPR5_BI_REG0           .set     0x00000134
IEP_CAPR5_BI_REG1           .set     0x00000138
IEP_CAPR6_BI_REG0           .set     0x0000013C
IEP_CAPR6_BI_REG1           .set     0x00000140
IEP_CAPF6_BI_REG0           .set     0x00000144
IEP_CAPF6_BI_REG1           .set     0x00000148
IEP_CAPR7_BI_REG0           .set     0x0000014C
IEP_CAPR7_BI_REG1           .set     0x00000150
IEP_CAPF7_BI_REG0           .set     0x00000154
IEP_CAPF7_BI_REG1           .set     0x00000158
IEP_SYNC_CTRL_REG           .set     0x00000180
IEP_SYNC_FIRST_STAT_REG     .set     0x00000184
IEP_SYNC0_STAT_REG          .set     0x00000188
IEP_SYNC1_STAT_REG          .set     0x0000018C
IEP_SYNC_PWIDTH_REG         .set     0x00000190
IEP_SYNC0_PERIOD_REG        .set     0x00000194
IEP_SYNC1_DELAY_REG         .set     0x00000198
IEP_SYNC_START_REG          .set     0x0000019C
IEP_WD_PREDIV_REG           .set     0x00000200
IEP_PDI_WD_TIM_REG          .set     0x00000204
IEP_PD_WD_TIM_REG           .set     0x00000208
IEP_WD_STATUS_REG           .set     0x0000020C
IEP_WD_EXP_CNT_REG          .set     0x00000210
IEP_WD_CTRL_REG             .set     0x00000214
IEP_DIGIO_CTRL_REG          .set     0x00000300
IEP_DIGIO_STATUS_REG        .set     0x00000304
IEP_DIGIO_DATA_IN_REG       .set     0x00000308
IEP_DIGIO_DATA_IN_RAW_REG   .set     0x0000030C
IEP_DIGIO_DATA_OUT_REG      .set     0x00000310
IEP_DIGIO_DATA_OUT_EN_REG   .set     0x00000314
IEP_DIGIO_EXP_REG           .set     0x00000318

;/**************************************************************************
;* Field Definition Macros
;**************************************************************************/

;/* GLOBAL_CFG_REG */

GLOBAL_CFG_REG_CNT_ENABLE_MASK      .set       0x00000001
GLOBAL_CFG_REG_CNT_ENABLE_SHIFT     .set       0x00000000
GLOBAL_CFG_REG_CNT_ENABLE_MAX       .set       0x00000001
GLOBAL_CFG_REG_DEFAULT_INC_MASK     .set       0x000000F0
GLOBAL_CFG_REG_DEFAULT_INC_SHIFT    .set       0x00000004
GLOBAL_CFG_REG_DEFAULT_INC_MAX      .set       0x0000000F
GLOBAL_CFG_REG_CMP_INC_MASK         .set       0x000FFF00
GLOBAL_CFG_REG_CMP_INC_SHIFT        .set       0x00000008
GLOBAL_CFG_REG_CMP_INC_MAX          .set       0x00000FFF

;/* GLOBAL_STATUS_REG */

GLOBAL_STATUS_REG_CNT_OVF_MASK      .set       0x00000001
GLOBAL_STATUS_REG_CNT_OVF_SHIFT     .set       0x00000000
GLOBAL_STATUS_REG_CNT_OVF_MAX       .set       0x00000001

;/* COMPEN_REG */

COMPEN_REG_COMPEN_CNT_MASK          .set       0x007FFFFF
COMPEN_REG_COMPEN_CNT_SHIFT         .set       0x00000000
COMPEN_REG_COMPEN_CNT_MAX           .set       0x007FFFFF

;/* SLOW_COMPEN_REG */

SLOW_COMPEN_REG_SLOW_COMPEN_CNT_MASK  .set     0xFFFFFFFF
SLOW_COMPEN_REG_SLOW_COMPEN_CNT_SHIFT .set     0x00000000
SLOW_COMPEN_REG_SLOW_COMPEN_CNT_MAX   .set     0xFFFFFFFF

;/* COUNT_REG0 */

COUNT_REG0_COUNT_LO_MASK             .set      0xFFFFFFFF
COUNT_REG0_COUNT_LO_SHIFT            .set      0x00000000
COUNT_REG0_COUNT_LO_MAX              .set      0xFFFFFFFF

;/* COUNT_REG1 */

COUNT_REG1_COUNT_HI_MASK             .set      0xFFFFFFFF
COUNT_REG1_COUNT_HI_SHIFT            .set      0x00000000
COUNT_REG1_COUNT_HI_MAX              .set      0xFFFFFFFF

;/* CAP_CFG_REG */

CAP_CFG_REG_CAP_EN_MASK              .set      0x000003FF
CAP_CFG_REG_CAP_EN_SHIFT             .set      0x00000000
CAP_CFG_REG_CAP_EN_MAX               .set      0x000003FF

CAP_CFG_REG_CAP_ASYNC_EN_MASK        .set      0x0003FC00
CAP_CFG_REG_CAP_ASYNC_EN_SHIFT       .set      0x0000000A
CAP_CFG_REG_CAP_ASYNC_EN_MAX         .set      0x000000FF

CAP_CFG_REG_EXT_CAP_EN_MASK          .set      0x00FC0000
CAP_CFG_REG_EXT_CAP_EN_SHIFT         .set      0x00000012
CAP_CFG_REG_EXT_CAP_EN_MAX           .set      0x0000003F

;/* CAP_STATUS_REG */

CAP_STATUS_REG_CAP_VALID_MASK        .set      0x000007FF
CAP_STATUS_REG_CAP_VALID_SHIFT       .set      0x00000000
CAP_STATUS_REG_CAP_VALID_MAX         .set      0x000007FF

CAP_STATUS_REG_CAP_RAW_MASK          .set      0x00FF0000
CAP_STATUS_REG_CAP_RAW_SHIFT         .set      0x00000010
CAP_STATUS_REG_CAP_RAW_MAX           .set      0x000000FF

;/* CMP_CFG_REG */

CMP_CFG_REG_CMP0_RST_CNT_EN_MASK     .set      0x00000001
CMP_CFG_REG_CMP0_RST_CNT_EN_SHIFT    .set      0x00000000
CMP_CFG_REG_CMP0_RST_CNT_EN_MAX      .set      0x00000001

CMP_CFG_REG_CMP_EN_MASK              .set      0x0001FFFE
CMP_CFG_REG_CMP_EN_SHIFT             .set      0x00000001
CMP_CFG_REG_CMP_EN_MAX               .set      0x0000FFFF

CMP_CFG_REG_SHADOW_EN_MASK           .set      0x00020000
CMP_CFG_REG_SHADOW_EN_SHIFT          .set      0x00000011
CMP_CFG_REG_SHADOW_EN_MAX            .set      0x00000001

;/* CMP_STATUS_REG */

CMP_STATUS_REG_CMP_STATUS_MASK       .set      0x0000FFFF
CMP_STATUS_REG_CMP_STATUS_SHIFT      .set      0x00000000
CMP_STATUS_REG_CMP_STATUS_MAX        .set      0x0000FFFF

;/* RXIPG0_REG */

RXIPG0_REG_RX_IPG0_MASK              .set      0x0000FFFF
RXIPG0_REG_RX_IPG0_SHIFT             .set      0x00000000
RXIPG0_REG_RX_IPG0_MAX               .set      0x0000FFFF

RXIPG0_REG_RX_MIN_IPG0_MASK          .set      0xFFFF0000
RXIPG0_REG_RX_MIN_IPG0_SHIFT         .set      0x00000010
RXIPG0_REG_RX_MIN_IPG0_MAX           .set      0x0000FFFF

;/* RXIPG1_REG */

RXIPG1_REG_RX_IPG1_MASK              .set      0x0000FFFF
RXIPG1_REG_RX_IPG1_SHIFT             .set      0x00000000
RXIPG1_REG_RX_IPG1_MAX               .set      0x0000FFFF

RXIPG1_REG_RX_MIN_IPG1_MASK          .set      0xFFFF0000
RXIPG1_REG_RX_MIN_IPG1_SHIFT         .set      0x00000010
RXIPG1_REG_RX_MIN_IPG1_MAX           .set      0x0000FFFF

;/* PWM_REG */

PWM_REG_PWM0_RST_CNT_EN_MASK         .set      0x00000001
PWM_REG_PWM0_RST_CNT_EN_SHIFT        .set      0x00000000
PWM_REG_PWM0_RST_CNT_EN_MAX          .set      0x00000001

PWM_REG_PWM0_HIT_MASK                .set      0x00000002
PWM_REG_PWM0_HIT_SHIFT               .set      0x00000001
PWM_REG_PWM0_HIT_MAX                 .set      0x00000001

PWM_REG_PWM3_RST_CNT_EN_MASK         .set      0x00000004
PWM_REG_PWM3_RST_CNT_EN_SHIFT        .set      0x00000002
PWM_REG_PWM3_RST_CNT_EN_MAX          .set      0x00000001

PWM_REG_PWM3_HIT_MASK                .set      0x00000008
PWM_REG_PWM3_HIT_SHIFT               .set      0x00000003
PWM_REG_PWM3_HIT_MAX                 .set      0x00000001

;/* SYNC_CTRL_REG */

SYNC_CTRL_REG_SYNC_EN_MASK            .set     0x00000001
SYNC_CTRL_REG_SYNC_EN_SHIFT           .set     0x00000000
SYNC_CTRL_REG_SYNC_EN_MAX             .set     0x00000001

SYNC_CTRL_REG_SYNC0_EN_MASK           .set     0x00000002
SYNC_CTRL_REG_SYNC0_EN_SHIFT          .set     0x00000001
SYNC_CTRL_REG_SYNC0_EN_MAX            .set     0x00000001

SYNC_CTRL_REG_SYNC1_EN_MASK           .set     0x00000004
SYNC_CTRL_REG_SYNC1_EN_SHIFT          .set     0x00000002
SYNC_CTRL_REG_SYNC1_EN_MAX            .set     0x00000001

SYNC_CTRL_REG_SYNC0_ACK_EN_MASK       .set     0x00000010
SYNC_CTRL_REG_SYNC0_ACK_EN_SHIFT      .set     0x00000004
SYNC_CTRL_REG_SYNC0_ACK_EN_MAX        .set     0x00000001

SYNC_CTRL_REG_SYNC0_CYCLIC_EN_MASK    .set     0x00000020
SYNC_CTRL_REG_SYNC0_CYCLIC_EN_SHIFT   .set     0x00000005
SYNC_CTRL_REG_SYNC0_CYCLIC_EN_MAX     .set     0x00000001

SYNC_CTRL_REG_SYNC1_ACK_EN_MASK       .set     0x00000040
SYNC_CTRL_REG_SYNC1_ACK_EN_SHIFT      .set     0x00000006
SYNC_CTRL_REG_SYNC1_ACK_EN_MAX        .set     0x00000001

SYNC_CTRL_REG_SYNC1_CYCLIC_EN_MASK    .set     0x00000080
SYNC_CTRL_REG_SYNC1_CYCLIC_EN_SHIFT   .set     0x00000007
SYNC_CTRL_REG_SYNC1_CYCLIC_EN_MAX     .set     0x00000001

SYNC_CTRL_REG_SYNC1_IND_EN_MASK       .set     0x00000100
SYNC_CTRL_REG_SYNC1_IND_EN_SHIFT      .set     0x00000008
SYNC_CTRL_REG_SYNC1_IND_EN_MAX        .set     0x00000001

SYNC_CTRL_REG_SYNC0_OUT_NV_EN_MASK    .set     0x00000200
SYNC_CTRL_REG_SYNC0_OUT_NV_EN_SHIFT   .set     0x00000009
SYNC_CTRL_REG_SYNC0_OUT_NV_EN_MAX     .set     0x00000001

SYNC_CTRL_REG_SYNC1_OUT_NV_EN_MASK    .set     0x00000400
SYNC_CTRL_REG_SYNC1_OUT_NV_EN_SHIFT   .set     0x0000000A
SYNC_CTRL_REG_SYNC1_OUT_NV_EN_MAX     .set     0x00000001

;/* SYNC_FIRST_STAT_REG */

SYNC_FIRST_STAT_REG_FIRST_SYNC0_MASK  .set     0x00000001
SYNC_FIRST_STAT_REG_FIRST_SYNC0_SHIFT .set     0x00000000
SYNC_FIRST_STAT_REG_FIRST_SYNC0_MAX   .set     0x00000001

SYNC_FIRST_STAT_REG_FIRST_SYNC1_MASK  .set     0x00000002
SYNC_FIRST_STAT_REG_FIRST_SYNC1_SHIFT .set     0x00000001
SYNC_FIRST_STAT_REG_FIRST_SYNC1_MAX   .set     0x00000001

;/* SYNC0_STAT_REG */

SYNC0_STAT_REG_SYNC0_PEND_MASK        .set     0x00000001
SYNC0_STAT_REG_SYNC0_PEND_SHIFT       .set     0x00000000
SYNC0_STAT_REG_SYNC0_PEND_MAX         .set     0x00000001

;/* SYNC1_STAT_REG */

SYNC1_STAT_REG_SYNC1_PEND_MASK        .set     0x00000001
SYNC1_STAT_REG_SYNC1_PEND_SHIFT       .set     0x00000000
SYNC1_STAT_REG_SYNC1_PEND_MAX         .set     0x00000001

;/* WD_STATUS_REG */

WD_STATUS_REG_PD_WD_STAT_MASK         .set     0x00000001
WD_STATUS_REG_PD_WD_STAT_SHIFT        .set     0x00000000
WD_STATUS_REG_PD_WD_STAT_MAX          .set     0x00000001

WD_STATUS_REG_PDI_WD_STAT_MASK        .set     0x00010000U)
WD_STATUS_REG_PDI_WD_STAT_SHIFT       .set     0x00000010U)
WD_STATUS_REG_PDI_WD_STAT_MAX         .set     0x00000001U)

;/* WD_EXP_CNT_REG */

WD_EXP_CNT_REG_PDI_EXP_CNT_MASK       .set     0x000000FF
WD_EXP_CNT_REG_PDI_EXP_CNT_SHIFT      .set     0x00000000
WD_EXP_CNT_REG_PDI_EXP_CNT_MAX        .set     0x000000FF

WD_EXP_CNT_REG_PD_EXP_CNT_MASK        .set    0x0000F00
WD_EXP_CNT_REG_PD_EXP_CNT_SHIFT       .set    0x0000008
WD_EXP_CNT_REG_PD_EXP_CNT_MAX         .set    0x00000FF

;/* WD_CTRL_REG */

WD_CTRL_REG_PD_WD_EN_MASK             .set    0x00000001
WD_CTRL_REG_PD_WD_EN_SHIFT            .set    0x00000000
WD_CTRL_REG_PD_WD_EN_MAX              .set    0x00000001

WD_CTRL_REG_PDI_WD_EN_MASK            .set    0x00010000
WD_CTRL_REG_PDI_WD_EN_SHIFT           .set    0x00000010
WD_CTRL_REG_PDI_WD_EN_MAX             .set    0x00000001

;/* DIGIO_CTRL_REG */

DIGIO_CTRL_REG_OUTVALID_POL_MASK      .set    0x00000001
DIGIO_CTRL_REG_OUTVALID_POL_SHIFT     .set    0x00000000
DIGIO_CTRL_REG_OUTVALID_POL_MAX       .set    0x00000001
DIGIO_CTRL_REG_OUTVALID_MODE_MASK     .set    0x00000002
DIGIO_CTRL_REG_OUTVALID_MODE_SHIFT    .set    0x00000001
DIGIO_CTRL_REG_OUTVALID_MODE_MAX      .set    0x00000001
DIGIO_CTRL_REG_BIDI_MODE_MASK         .set    0x00000004
DIGIO_CTRL_REG_BIDI_MODE_SHIFT        .set    0x00000002
DIGIO_CTRL_REG_BIDI_MODE_MAX          .set    0x00000001
DIGIO_CTRL_REG_WD_MODE_MASK           .set    0x00000008
DIGIO_CTRL_REG_WD_MODE_SHIFT          .set    0x00000003
DIGIO_CTRL_REG_WD_MODE_MAX            .set    0x00000001
DIGIO_CTRL_REG_IN_MODE_MASK           .set    0x00000030
DIGIO_CTRL_REG_IN_MODE_SHIFT          .set    0x00000004
DIGIO_CTRL_REG_IN_MODE_MAX            .set    0x00000003
DIGIO_CTRL_REG_OUT_MODE_MASK          .set    0x000000C0
DIGIO_CTRL_REG_OUT_MODE_SHIFT         .set    0x00000006
DIGIO_CTRL_REG_OUT_MODE_MAX           .set    0x00000003

;/* DIGIO_EXP_REG */

DIGIO_EXP_REG_SW_DATA_OUT_UP_MASK     .set   0x00000001
DIGIO_EXP_REG_SW_DATA_OUT_UP_SHIFT    .set   0x00000000
DIGIO_EXP_REG_SW_DATA_OUT_UP_MAX      .set   0x00000001

DIGIO_EXP_REG_OUTVALID_OVR_EN_MASK    .set   0x00000002
DIGIO_EXP_REG_OUTVALID_OVR_EN_SHIFT   .set   0x00000001
DIGIO_EXP_REG_OUTVALID_OVR_EN_MAX     .set   0x00000001

DIGIO_EXP_REG_SW_OUTVALID_MASK        .set   0x00000004
DIGIO_EXP_REG_SW_OUTVALID_SHIFT       .set   0x00000002
DIGIO_EXP_REG_SW_OUTVALID_MAX         .set   0x00000001

DIGIO_EXP_REG_OUTVALID_DLY_MASK       .set   0x000000F0
DIGIO_EXP_REG_OUTVALID_DLY_SHIFT      .set   0x00000004
DIGIO_EXP_REG_OUTVALID_DLY_MAX        .set   0x0000000F

DIGIO_EXP_REG_SOF_DLY_MASK            .set   0x00000F00
DIGIO_EXP_REG_SOF_DLY_SHIFT           .set   0x00000008
DIGIO_EXP_REG_SOF_DLY_MAX             .set   0x0000000F

DIGIO_EXP_REG_SOF_SEL_MASK            .set   0x00001000
DIGIO_EXP_REG_SOF_SEL_SHIFT           .set   0x0000000C
DIGIO_EXP_REG_SOF_SEL_MAX             .set   0x00000001

DIGIO_EXP_REG_EOF_SEL_MASK            .set   0x00002000
DIGIO_EXP_REG_EOF_SEL_SHIFT           .set   0x0000000D
DIGIO_EXP_REG_EOF_SEL_MAX             .set   0x00000001