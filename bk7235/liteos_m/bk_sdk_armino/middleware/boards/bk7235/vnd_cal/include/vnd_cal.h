/*
// Copyright (C) 2022 Beken Corporation
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef VND_CAL_H
#define VND_CAL_H


#include "bk_arm_arch.h"
#include "bk_misc.h"

typedef struct tmp_pwr_st {//do
    unsigned trx0x0c_12_15 : 4; //not used on BK7231N actually
    signed p_index_delta : 6;
    signed p_index_delta_g : 6;
    signed p_index_delta_ble : 6;
    signed xtal_c_dlta : 8;
} TMP_PWR_ST;

typedef struct txpwr_st {
    UINT8 value;
} TXPWR_ST, *TXPWR_PTR;

void vnd_cal_overlay(void);

//typedef void (*hook_function_t)(void);

extern void vnd_cal_txpwr_tab_def_b_overlay(TXPWR_ST *txpwr_tab_def_ptr);
extern void vnd_cal_txpwr_tab_def_g_overlay(TXPWR_ST *txpwr_tab_def_ptr);
extern void vnd_cal_txpwr_tab_def_n40_overlay(TXPWR_ST *txpwr_tab_def_ptr);
extern void vnd_cal_txpwr_tab_def_ble_overlay(TXPWR_ST *txpwr_tab_def_ptr);
extern void vnd_cal_tmp_pwr_tab_overlay(TMP_PWR_ST *tmp_pwr_tab_def_ptr);
extern void vnd_cal_gxtal_overlay(uint32 overlay_xtal);
extern void vnd_cal_gcmtag_overlay(uint32 overlay_cmtag);
extern void vnd_cal_pwr_shift_b_tab_overlay(INT16 *pwr_shift_b_def_ptr);
extern void vnd_cal_pwr_shift_g_tab_overlay(INT16 *pwr_shift_g_def_ptr);
extern void vnd_cal_pwr_shift_n_tab_overlay(INT16 *pwr_shift_n_def_ptr);
extern void vnd_cal_pwr_shift_n40_tab_overlay(INT16 *pwr_shift_n40_def_ptr);
extern void vnd_cal_pwr_gain_base_ble_overlay(uint32 pwr_gain_base_ble_value);
extern void vnd_cal_set_ble_pwr_level(uint8 level);
#endif