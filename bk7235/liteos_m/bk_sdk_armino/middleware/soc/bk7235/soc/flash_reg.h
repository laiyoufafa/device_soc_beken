// Copyright (C) 2022 Beken Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define FLASH_R_BASE         (SOC_FLASH_REG_BASE)
#define FLASH_ID_GD25Q32C    (0xC84016)
#define LEN_WRSR_S0_S7       (8)
#define CMD_WRSR_S8_S15      (0x31)

#ifdef __cplusplus
}
#endif

