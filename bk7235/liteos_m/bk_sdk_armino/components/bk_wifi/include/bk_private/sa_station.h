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
#ifndef _SA_STATION_H_
#define _SA_STATION_H_

#include "rw_msg_tx.h"

//TODO Move this file to better place
#define SASTA_DEBUG

#ifdef SASTA_DEBUG
#define SASTA_PRT                 os_printf
#define SASTA_WPRT                warning_prf
#else
#define SASTA_PRT                 os_null_printf
#define SASTA_WPRT                os_null_printf
#endif

#define SCANU_IND_PAYLOAD_LEN                   512

typedef struct _scan_result_
{
    /// Length of the frame
    UINT16 length;
    /// Frame control field of the frame.
    UINT16 framectrl;
    /// Center frequency on which we received the packet
    UINT16 center_freq;
    /// PHY band
    UINT8 band;
    /// Index of the station that sent the frame. 0xFF if unknown.
    UINT8 sta_idx;
    /// Index of the VIF that received the frame. 0xFF if unknown.
    UINT8 inst_nbr;
    /// RSSI of the received frame.
    INT8 rssi;
    /// Frame payload.
    UINT32 payload[1];
} SCAN_IND_T, *SCAN_IND_PTR;

typedef struct probe_rsp
{
    UINT8 timestamp[8];
    UINT16 beacon_int;
    UINT16 capab_info;

    /* followed by some of SSID, Supported rates,
     * FH Params, DS Params, CF Params, IBSS Params */
    UINT8 variable[1];
} __attribute__ ((packed)) PROBE_RSP_T;

typedef struct ieee802_11_probe_rsp
{
    UINT16 frame_control;
    UINT16 duration;
    UINT8 da[6];
    UINT8 sa[6];
    UINT8 bssid[6];
    UINT16 seq_ctrl;
    struct probe_rsp rsp;
} __attribute__ ((packed)) IEEE802_11_PROBE_RSP_T, *IEEE802_11_PROBE_RSP_PTR;

void sa_station_init(void);
void sa_station_uninit(void);
void sa_station_set_reconnect_timer(void);
void sa_reconnect_init(void);
#ifdef CONFIG_SME
int sa_station_send_associate_cmd(ASSOC_PARAM_T *assoc_param);
#else
int sa_station_send_associate_cmd(CONNECT_PARAM_T *connect_param);
#endif

#endif // _SA_STATION_H_
// eof

