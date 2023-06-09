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

#pragma once

#include <components/log.h>

#define AON_WDT_TAG      "aon_wdt"
#define AON_WDT_LOGI(...) BK_LOGI(AON_WDT_TAG, ##__VA_ARGS__)
#define AON_WDT_LOGW(...) BK_LOGW(AON_WDT_TAG, ##__VA_ARGS__)
#define AON_WDT_LOGE(...) BK_LOGE(AON_WDT_TAG, ##__VA_ARGS__)
#define AON_WDT_LOGD(...) BK_LOGD(AON_WDT_TAG, ##__VA_ARGS__)

