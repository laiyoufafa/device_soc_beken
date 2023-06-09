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

#include "hal_config.h"
#include "gpio_hw.h"
#include "gpio_hal.h"
#include "gpio_ll.h"

//TODO finally we will automatically generate this code

#if CFG_HAL_DEBUG_GPIO
void gpio_struct_dump(gpio_id_t gpio_index)
{
	gpio_hw_t *hw = (gpio_hw_t *)GPIO_LL_REG_BASE; //gpio base address
	SOC_LOGI("base=%x\n", (uint32_t)hw);

	SOC_LOGI("  gpio[%d]: %x\n", gpio_index, hw->gpio_num[gpio_index].cfg.v);
	SOC_LOGI("  gpio_input : %x\n", hw->gpio_num[gpio_index].cfg.gpio_input);
	SOC_LOGI("  gpio_output: %x\n", hw->gpio_num[gpio_index].cfg.gpio_output);
	SOC_LOGI("  gpio_input_en: %x\n", hw->gpio_num[gpio_index].cfg.gpio_input_en);
	SOC_LOGI("  gpio_output_en: %x\n", hw->gpio_num[gpio_index].cfg.gpio_output_en);
	SOC_LOGI("  gpio_pull_mode: %x\n", hw->gpio_num[gpio_index].cfg.gpio_pull_mode);
	SOC_LOGI("  gpio_pull_mode_en: %x\n", hw->gpio_num[gpio_index].cfg.gpio_pull_mode_en);
	SOC_LOGI("  gpio_input_monitor: %x\n", hw->gpio_num[gpio_index].cfg.gpio_input_monitor);
	SOC_LOGI("  gpio_capacity: %x\n", hw->gpio_num[gpio_index].cfg.gpio_capacity);
	SOC_LOGI("  gpio_0_15_int_type: %x\n", hw->gpio_0_15_int_type.v);
	SOC_LOGI("  gpio_16_31_int_type: %x\n", hw->gpio_16_31_int_type.v);
	SOC_LOGI("  gpio_32_47_int_type: %x\n", hw->gpio_32_47_int_type.v);
	SOC_LOGI("  gpio_0_31_int_st: %x\n", hw->gpio_0_31_int_st.v);
	SOC_LOGI("  gpio_32_47_int_st: %x\n", hw->gpio_32_47_int_st.v);

}

#endif
