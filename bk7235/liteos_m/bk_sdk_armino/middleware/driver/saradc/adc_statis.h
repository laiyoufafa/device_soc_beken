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

#include <driver/hal/hal_adc_types.h>
#include <components/log.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	uint32_t adc_isr_cnt;
	uint32_t adc_rx_total_cnt;
	uint32_t adc_rx_succ_cnt;
	uint32_t adc_rx_drop_cnt;
} adc_statis_t;


#if CONFIG_ADC_STATIS
#define ADC_STATIS_ADD(_statis, _v) do{\
			(_statis) += (_v);\
		} while(0)

bk_err_t adc_statis_init(void);
adc_statis_t* adc_statis_get_statis(void);
void adc_statis_dump(void);
#else
#define ADC_STATIS_SET(_id, _v)
#define ADC_STATIS_ADD(_statis, _v)
#define adc_statis_init()
#define adc_statis_get_statis(id) NULL
#define adc_statis_dump(id)
#endif

#define ADC_STATIS_INC(_statis) ADC_STATIS_ADD((_statis), 1)

#ifdef __cplusplus
}
#endif
