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

#include <soc/soc.h>
#include "icu_hw.h"


#ifdef __cplusplus
extern "C" {
#endif

#define ICU_LL_REG_BASE() (SOC_ICU_REG_BASE)


static inline void power_ll_pwm_pwr_up(icu_hw_t *hw, uint32_t chan)
{
	REG_MCHAN_SET_FIELD(chan, ICU_R_PWM_CHAN_PWR, ICU_F_PWM_CHAN_PWR, ICU_V_PWM_CHAN_PWR_UP);
}

static inline void power_ll_pwm_pwr_down(icu_hw_t *hw, uint32_t chan)
{
	REG_MCHAN_SET_FIELD(chan, ICU_R_PWM_CHAN_PWR, ICU_F_PWM_CHAN_PWR, ICU_V_PWM_CHAN_PWR_DOWN);
}

static inline void power_ll_pwr_up_timer(icu_hw_t *hw, uint32_t timer_id)
{
    REG_MCHAN_SET_FIELD(timer_id, ICU_R_TIMER_CHAN_PWR, ICU_F_TIMER_CHAN_PWR, ICU_V_TIMER_CHAN_PWR_UP);
}

static inline void power_ll_pwr_down_timer(icu_hw_t *hw, uint32_t timer_id)
{
    REG_MCHAN_SET_FIELD(timer_id, ICU_R_TIMER_CHAN_PWR, ICU_F_TIMER_CHAN_PWR, ICU_V_TIMER_CHAN_PWR_DOWN);
}


static inline void power_ll_pwr_up_qspi(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_qspi(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_jpeg(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_jpeg(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_fft(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_fft(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_usb(icu_hw_t *hw, uint32 id)
{
}
static inline void power_ll_pwr_down_usb(icu_hw_t *hw, uint32 id)
{
}

static inline void power_ll_pwr_up_sdio(icu_hw_t *hw)
{
	hw->clk_pwr_down.sdio= 0;
}
static inline void power_ll_pwr_down_sdio(icu_hw_t *hw)
{
	hw->clk_pwr_down.sdio= 1;
}

static inline void power_ll_pwr_up_tl410_wdt(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_tl410_wdt(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_audio(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_audio(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_arm_wdt(icu_hw_t *hw)
{
	hw->clk_pwr_down.arm_watchdog= 0;
}
static inline void power_ll_pwr_down_arm_wdt(icu_hw_t *hw)
{
	hw->clk_pwr_down.arm_watchdog= 1;
}

static inline void power_ll_pwr_up_saradc(icu_hw_t *hw)
{
	hw->clk_pwr_down.saradc= 0;
}
static inline void power_ll_pwr_down_saradc(icu_hw_t *hw)
{
	hw->clk_pwr_down.saradc= 1;
}

static inline void power_ll_pwr_up_spi(icu_hw_t *hw, uint32 id)
{
	hw->clk_pwr_down.spi= 0;
}
static inline void power_ll_pwr_down_spi(icu_hw_t *hw, uint32 id)
{
	hw->clk_pwr_down.spi= 1;
}

static inline void power_ll_pwr_up_i2s_pcm(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_i2s_pcm(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_irda(icu_hw_t *hw)
{
	hw->clk_pwr_down.irda= 0;
}
static inline void power_ll_pwr_down_irda(icu_hw_t *hw)
{
	hw->clk_pwr_down.irda= 1;
}

static inline void power_ll_pwr_up_i2c(icu_hw_t *hw, uint32 id)
{
	if(id == 1)
		hw->clk_pwr_down.i2c1= 0;
	else
		hw->clk_pwr_down.i2c2= 0;

}
static inline void power_ll_pwr_down_i2c(icu_hw_t *hw, uint32 id)
{
	if(id == 1)
		hw->clk_pwr_down.i2c1= 1;
	else
		hw->clk_pwr_down.i2c2= 1;
}

static inline void power_ll_pwr_up_uart(icu_hw_t *hw, uint32_t id)
{
	REG_CLR_BIT(&hw->clk_pwr_down, 1 << (id  & 0x1));
}

static inline void power_ll_pwr_down_uart(icu_hw_t *hw, uint32_t id)
{
	REG_SET_BIT(&hw->clk_pwr_down, 1 << (id  & 0x1));
}


static inline void power_ll_pwr_up_ble(icu_hw_t *hw)
{
	hw->clk_pwr_down_2.ble = 0;
}
static inline void power_ll_pwr_down_ble(icu_hw_t *hw)
{
	hw->clk_pwr_down_2.ble = 1;
}

static inline void power_ll_pwr_up_tl410(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_tl410(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_security(icu_hw_t *hw)
{
	hw->clk_pwr_down.security= 0;
}
static inline void power_ll_pwr_down_security(icu_hw_t *hw)
{
	hw->clk_pwr_down.security= 1;
}

static inline void power_ll_pwr_up_cec(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_cec(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_sdio_dma(icu_hw_t *hw)
{
}
static inline void power_ll_pwr_down_sdio_dma(icu_hw_t *hw)
{
}

static inline void power_ll_pwr_up_wdt(icu_hw_t *hw)
{
	hw->clk_pwr_down.arm_watchdog = 0;
}

static inline void power_ll_pwr_down_wdt(icu_hw_t *hw)
{
	hw->clk_pwr_down.arm_watchdog = 1;
}

#ifdef __cplusplus
}
#endif
