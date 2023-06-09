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
#include "sys_rtos.h"
#include "bk_fake_clock.h"
#include "bk_timer.h"
#include "bk_icu.h"
#include "bk_drv_model.h"
#include "bk_uart.h"
#include <os/os.h>
#include <components/system.h>

#include <components/log.h>
#include "bk_ps_time.h"

#include "bk_wdt.h"
#include <driver/timer.h>
#include "tick_timer_id.h"

#define TAG "tick"

static int s_tick_timer_id = TICK_TIMER_ID;

int bk_get_tick_timer_id(void)
{
	return s_tick_timer_id;
}

int bk_tick_init(void)
{
	s_tick_timer_id = TICK_TIMER_ID;
	bk_timer_start(s_tick_timer_id, bk_get_ms_per_tick(), (timer_isr_t)bk_tick_handle);

#if CONFIG_TICK_CALI
	extern uint32_t bk_cal_init(uint32_t setting); //TODO fix it
	bk_cal_init(0);
#endif
	return BK_OK;
}

int bk_tick_reload(uint32_t time_ms)
{
	bk_timer_start(s_tick_timer_id, time_ms, (timer_isr_t)bk_tick_handle);
	return BK_OK;
}