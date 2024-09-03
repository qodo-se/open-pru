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

; file name: icss_tm_reg.inc


;/**************************************************************************
;* Task Manager base address  :
;**************************************************************************/
; c10 is TM base address for PRU and RTU, TX_PRU has same as PRU base address
TM_BASE_CONST                                        .set     c10

TM_PRU0_BASE_ADDR                                    .set     (0x0002a000)
TM_RTU0_BASE_ADDR                                    .set     (0x0002a100)
TM_PRU1_BASE_ADDR                                    .set     (0x0002a200)
TM_RTU1_BASE_ADDR                                    .set     (0x0002a300)
TM_TX_PRU0_BASE_ADDR                                 .set     (0x0002a400)
TM_TX_PRU1_BASE_ADDR                                 .set     (0x0002a500)

;/**************************************************************************
;* Task Manager defines which are identical for all PRU cores  :
;**************************************************************************/

TM_GLOBAL_CFG                                        .set      (0x00000000U)
TM_GLOBAL_STATUS                                     .set      (0x00000004U)
TM_TS1_PC_S0                                         .set      (0x00000008U)
TM_TS1_PC_S1                                         .set      (0x0000000CU)
TM_TS1_PC_S2                                         .set      (0x00000010U)
TM_TS1_PC_S3                                         .set      (0x00000014U)
TM_TS1_PC_S4                                         .set      (0x00000018U)
TM_TS2_PC_S0                                         .set      (0x0000001CU)
TM_TS2_PC_S1                                         .set      (0x00000020U)
TM_TS2_PC_S2                                         .set      (0x00000024U)
TM_TS2_PC_S3                                         .set      (0x00000028U)
TM_TS2_PC_S4                                         .set      (0x0000002CU)
TM_RX_CFG                                            .set      (0x00000030U)
TM_TX_CFG                                            .set      (0x00000034U)
TM_TS1_GEN_CFG1                                      .set      (0x00000038U)
TM_TS1_GEN_CFG2                                      .set      (0x0000003CU)
TM_TS2_GEN_CFG1                                      .set      (0x00000040U)
TM_TS2_GEN_CFG2                                      .set      (0x00000044U)
TM_CAP_EN_CFG                                        .set      (0x00000048U)

;/**************************************************************************
;* Field Definition Macros
;**************************************************************************/


;/* GLOBAL_CFG */

TM_GLOBAL_CFG_MODE_MASK                              .set      (0x00000003U)
TM_GLOBAL_CFG_MODE_SHIFT                             .set      (0x00000000U)
TM_GLOBAL_CFG_MODE_MAX                               .set      (0x00000003U)

TM_GLOBAL_CFG_TS1_EN_S0_MASK                         .set      (0x00000004U)
TM_GLOBAL_CFG_TS1_EN_S0_SHIFT                        .set      (0x00000002U)
TM_GLOBAL_CFG_TS1_EN_S0_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS1_EN_S1_MASK                         .set      (0x00000008U)
TM_GLOBAL_CFG_TS1_EN_S1_SHIFT                        .set      (0x00000003U)
TM_GLOBAL_CFG_TS1_EN_S1_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS1_EN_S2_MASK                         .set      (0x00000010U)
TM_GLOBAL_CFG_TS1_EN_S2_SHIFT                        .set      (0x00000004U)
TM_GLOBAL_CFG_TS1_EN_S2_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS1_EN_S3_MASK                         .set      (0x00000020U)
TM_GLOBAL_CFG_TS1_EN_S3_SHIFT                        .set      (0x00000005U)
TM_GLOBAL_CFG_TS1_EN_S3_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS1_EN_S4_MASK                         .set      (0x00000040U)
TM_GLOBAL_CFG_TS1_EN_S4_SHIFT                        .set      (0x00000006U)
TM_GLOBAL_CFG_TS1_EN_S4_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS2_EN_S0_MASK                         .set      (0x00000080U)
TM_GLOBAL_CFG_TS2_EN_S0_SHIFT                        .set      (0x00000007U)
TM_GLOBAL_CFG_TS2_EN_S0_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS2_EN_S1_MASK                         .set      (0x00000100U)
TM_GLOBAL_CFG_TS2_EN_S1_SHIFT                        .set      (0x00000008U)
TM_GLOBAL_CFG_TS2_EN_S1_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS2_EN_S2_MASK                         .set      (0x00000200U)
TM_GLOBAL_CFG_TS2_EN_S2_SHIFT                        .set      (0x00000009U)
TM_GLOBAL_CFG_TS2_EN_S2_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS2_EN_S3_MASK                         .set      (0x00000400U)
TM_GLOBAL_CFG_TS2_EN_S3_SHIFT                        .set      (0x0000000AU)
TM_GLOBAL_CFG_TS2_EN_S3_MAX                          .set      (0x00000001U)

TM_GLOBAL_CFG_TS2_EN_S4_MASK                         .set      (0x00000800U)
TM_GLOBAL_CFG_TS2_EN_S4_SHIFT                        .set      (0x0000000BU)
TM_GLOBAL_CFG_TS2_EN_S4_MAX                          .set      (0x00000001U)

;/* GLOBAL_STATUS */

TM_GLOBAL_STATUS_TS1_STATE_MASK                      .set      (0x0000000FU)
TM_GLOBAL_STATUS_TS1_STATE_SHIFT                     .set      (0x00000000U)
TM_GLOBAL_STATUS_TS1_STATE_MAX                       .set      (0x0000000FU)

TM_GLOBAL_STATUS_TS2_STATE_MASK                      .set      (0x000000F0U)
TM_GLOBAL_STATUS_TS2_STATE_SHIFT                     .set      (0x00000004U)
TM_GLOBAL_STATUS_TS2_STATE_MAX                       .set      (0x0000000FU)

TM_GLOBAL_STATUS_TS1_SUB_PEND_0_MASK                 .set      (0x00000100U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_0_SHIFT                .set      (0x00000008U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_0_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS1_SUB_PEND_1_MASK                 .set      (0x00000200U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_1_SHIFT                .set      (0x00000009U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_1_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS1_SUB_PEND_2_MASK                 .set      (0x00000400U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_2_SHIFT                .set      (0x0000000AU)
TM_GLOBAL_STATUS_TS1_SUB_PEND_2_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS1_SUB_PEND_3_MASK                 .set      (0x00000800U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_3_SHIFT                .set      (0x0000000BU)
TM_GLOBAL_STATUS_TS1_SUB_PEND_3_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS1_SUB_PEND_4_MASK                 .set      (0x00001000U)
TM_GLOBAL_STATUS_TS1_SUB_PEND_4_SHIFT                .set      (0x0000000CU)
TM_GLOBAL_STATUS_TS1_SUB_PEND_4_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS2_SUB_PEND_0_MASK                 .set      (0x00002000U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_0_SHIFT                .set      (0x0000000DU)
TM_GLOBAL_STATUS_TS2_SUB_PEND_0_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS2_SUB_PEND_1_MASK                 .set      (0x00004000U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_1_SHIFT                .set      (0x0000000EU)
TM_GLOBAL_STATUS_TS2_SUB_PEND_1_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS2_SUB_PEND_2_MASK                 .set      (0x00008000U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_2_SHIFT                .set      (0x0000000FU)
TM_GLOBAL_STATUS_TS2_SUB_PEND_2_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS2_SUB_PEND_3_MASK                 .set      (0x00010000U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_3_SHIFT                .set      (0x00000010U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_3_MAX                  .set      (0x00000001U)

TM_GLOBAL_STATUS_TS2_SUB_PEND_4_MASK                 .set      (0x00020000U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_4_SHIFT                .set      (0x00000011U)
TM_GLOBAL_STATUS_TS2_SUB_PEND_4_MAX                  .set      (0x00000001U)

;/* TS1_PC_S0 */

TM_TS1_PC_S0_MASK                                    .set      (0x00003FFFU)
TM_TS1_PC_S0_SHIFT                                   .set      (0x00000000U)
TM_TS1_PC_S0_MAX                                     .set      (0x00003FFFU)

;/* TS1_PC_S1 */

TM_TS1_PC_S1_MASK                                    .set      (0x00003FFFU)
TM_TS1_PC_S1_SHIFT                                   .set      (0x00000000U)
TM_TS1_PC_S1_MAX                                     .set      (0x00003FFFU)

;/* TS1_PC_S2 */

TM_TS1_PC_S2_MASK                                    .set      (0x00003FFFU)
TM_TS1_PC_S2_SHIFT                                   .set      (0x00000000U)
TM_TS1_PC_S2_MAX                                     .set      (0x00003FFFU)

;/* TS1_PC_S3 */

TM_TS1_PC_S3_MASK                                    .set      (0x00003FFFU)
TM_TS1_PC_S3_SHIFT                                   .set      (0x00000000U)
TM_TS1_PC_S3_MAX                                     .set      (0x00003FFFU)

;/* TS1_PC_S4 */

TM_TS1_PC_S4_MASK                                    .set      (0x00003FFFU)
TM_TS1_PC_S4_SHIFT                                   .set      (0x00000000U)
TM_TS1_PC_S4_MAX                                     .set      (0x00003FFFU)

;/* TS2_PC_S0 */

TM_TS2_PC_S0_MASK                                    .set      (0x00003FFFU)
TM_TS2_PC_S0_SHIFT                                   .set      (0x00000000U)
TM_TS2_PC_S0_MAX                                     .set      (0x00003FFFU)

;/* TS2_PC_S1 */

TM_TS2_PC_S1_MASK                                    .set      (0x00003FFFU)
TM_TS2_PC_S1_SHIFT                                   .set      (0x00000000U)
TM_TS2_PC_S1_MAX                                     .set      (0x00003FFFU)

;/* TS2_PC_S2 */

TM_TS2_PC_S2_MASK                                    .set      (0x00003FFFU)
TM_TS2_PC_S2_SHIFT                                   .set      (0x00000000U)
TM_TS2_PC_S2_MAX                                     .set      (0x00003FFFU)

;/* TS2_PC_S3 */

TM_TS2_PC_S3_MASK                                    .set      (0x00003FFFU)
TM_TS2_PC_S3_SHIFT                                   .set      (0x00000000U)
TM_TS2_PC_S3_MAX                                     .set      (0x00003FFFU)

;/* TS2_PC_S4 */

TM_TS2_PC_S4_MASK                                    .set      (0x00003FFFU)
TM_TS2_PC_S4_SHIFT                                   .set      (0x00000000U)
TM_TS2_PC_S4_MAX                                     .set      (0x00003FFFU)

;/* RX_CFG */

TM_RX_CFG_BK1_SIZE_MASK                              .set      (0x0000001FU)
TM_RX_CFG_BK1_SIZE_SHIFT                             .set      (0x00000000U)
TM_RX_CFG_BK1_SIZE_MAX                               .set      (0x0000001FU)

TM_RX_CFG_BK2_SIZE_MASK                              .set      (0x000003E0U)
TM_RX_CFG_BK2_SIZE_SHIFT                             .set      (0x00000005U)
TM_RX_CFG_BK2_SIZE_MAX                               .set      (0x0000001FU)

TM_RX_CFG_BKN_SIZE_MASK                              .set      (0x00007C00U)
TM_RX_CFG_BKN_SIZE_SHIFT                             .set      (0x0000000AU)
TM_RX_CFG_BKN_SIZE_MAX                               .set      (0x0000001FU)

;/* TX_CFG */

TM_TX_CFG_WM_MASK                                    .set      (0x0000003FU)
TM_TX_CFG_WM_SHIFT                                   .set      (0x00000000U)
TM_TX_CFG_WM_MAX                                     .set      (0x0000003FU)

;/* TS1_GEN_CFG1 */

TM_TS1_GEN_CFG1_S0_MX_MASK                           .set      (0x000000FFU)
TM_TS1_GEN_CFG1_S0_MX_SHIFT                          .set      (0x00000000U)
TM_TS1_GEN_CFG1_S0_MX_MAX                            .set      (0x000000FFU)

TM_TS1_GEN_CFG1_S1_MX_MASK                           .set      (0x0000FF00U)
TM_TS1_GEN_CFG1_S1_MX_SHIFT                          .set      (0x00000008U)
TM_TS1_GEN_CFG1_S1_MX_MAX                            .set      (0x000000FFU)

TM_TS1_GEN_CFG1_S2_MX_MASK                           .set      (0x00FF0000U)
TM_TS1_GEN_CFG1_S2_MX_SHIFT                          .set      (0x00000010U)
TM_TS1_GEN_CFG1_S2_MX_MAX                            .set      (0x000000FFU)

TM_TS1_GEN_CFG1_S3_MX_MASK                           .set      (0xFF000000U)
TM_TS1_GEN_CFG1_S3_MX_SHIFT                          .set      (0x00000018U)
TM_TS1_GEN_CFG1_S3_MX_MAX                            .set      (0x000000FFU)

;/* TS1_GEN_CFG2 */

TM_TS1_GEN_CFG2_S4_MX_MASK                           .set      (0x000000FFU)
TM_TS1_GEN_CFG2_S4_MX_SHIFT                          .set      (0x00000000U)
TM_TS1_GEN_CFG2_S4_MX_MAX                            .set      (0x000000FFU)

;/* TS2_GEN_CFG1 */

TM_TS2_GEN_CFG1_S0_MX_MASK                           .set      (0x000000FFU)
TM_TS2_GEN_CFG1_S0_MX_SHIFT                          .set      (0x00000000U)
TM_TS2_GEN_CFG1_S0_MX_MAX                            .set      (0x000000FFU)

TM_TS2_GEN_CFG1_S1_MX_MASK                           .set      (0x0000FF00U)
TM_TS2_GEN_CFG1_S1_MX_SHIFT                          .set      (0x00000008U)
TM_TS2_GEN_CFG1_S1_MX_MAX                            .set      (0x000000FFU)

TM_TS2_GEN_CFG1_S2_MX_MASK                           .set      (0x00FF0000U)
TM_TS2_GEN_CFG1_S2_MX_SHIFT                          .set      (0x00000010U)
TM_TS2_GEN_CFG1_S2_MX_MAX                            .set      (0x000000FFU)

TM_TS2_GEN_CFG1_S3_MX_MASK                           .set      (0xFF000000U)
TM_TS2_GEN_CFG1_S3_MX_SHIFT                          .set      (0x00000018U)
TM_TS2_GEN_CFG1_S3_MX_MAX                            .set      (0x000000FFU)

;/* TS2_GEN_CFG2 */

TM_TS2_GEN_CFG2_S4_MX_MASK                           .set      (0x000000FFU)
TM_TS2_GEN_CFG2_S4_MX_SHIFT                          .set      (0x00000000U)
TM_TS2_GEN_CFG2_S4_MX_MAX                            .set      (0x000000FFU)

;/* CAP_EN_CFG */

TM_CAP_EN_CFG_NEW_MASK                               .set      (0x000003FFU)
TM_CAP_EN_CFG_NEW_SHIFT                              .set      (0x00000000U)
