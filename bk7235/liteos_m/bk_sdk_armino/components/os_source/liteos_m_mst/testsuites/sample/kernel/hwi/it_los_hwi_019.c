/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "osTest.h"
#include "it_los_hwi.h"


static VOID HwiF01(VOID)
{
    UINT32 ret;
    TestHwiClear(HWI_NUM_TEST);

    if (g_testCount == 1) {
        ret = LOS_TaskSuspend(g_testTaskID01);
        ICUNIT_GOTO_EQUAL(ret, LOS_OK, ret, EXIT);
    }
    g_testCount++;

    if (g_testCount == 4) { // when g_testCount is 4, Resume the task id is 4
        ret = LOS_TaskResume(g_testTaskID01);
        ICUNIT_GOTO_EQUAL(ret, LOS_OK, ret, EXIT);
        g_testCount++;
    }

    return;

EXIT:
    LOS_TaskDelete(g_testTaskID01);
    return;
}

static VOID TaskF01(VOID)
{
    g_testCount++;

    TestHwiTrigger(HWI_NUM_TEST);

    ICUNIT_GOTO_EQUAL(g_testCount, 5, g_testCount, EXIT); // Compare wiht the expected value 5.
    g_testCount++;

EXIT:
    TestHwiDelete(HWI_NUM_TEST);
    LOS_TaskDelete(g_testTaskID01);

    return;
}

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    HWI_PRIOR_T hwiPrio = OS_HWI_PRIO_LOWEST;
    HWI_MODE_T mode = 0;
    HwiIrqParam irqParam;
    (void)memset_s(&irqParam, sizeof(HwiIrqParam), 0, sizeof(HwiIrqParam));
    irqParam.pDevId = 0;

    TSK_INIT_PARAM_S task = {0};

    task.pfnTaskEntry = (TSK_ENTRY_FUNC)TaskF01;
    task.pcName = "HwiTsk019A";
    task.uwStackSize = TASK_STACK_SIZE_TEST;
    task.usTaskPrio = TASK_PRIO_TEST - 1;
    task.uwResved = LOS_TASK_STATUS_DETACHED;

    g_testCount = 0;

    ret = LOS_HwiCreate(HWI_NUM_TEST, hwiPrio, mode, (HWI_PROC_FUNC)HwiF01, &irqParam);
    ICUNIT_ASSERT_EQUAL(ret, LOS_OK, ret);

    ret = LOS_TaskCreate(&g_testTaskID01, &task);
    ICUNIT_GOTO_EQUAL(ret, LOS_OK, ret, EXIT1);

    ICUNIT_GOTO_EQUAL(g_testCount, 2, g_testCount, EXIT2); // Compare wiht the expected value 2.
    g_testCount++;

    TestHwiTrigger(HWI_NUM_TEST);
    ICUNIT_TRACK_EQUAL(g_testCount, 6, g_testCount); // Compare wiht the expected value 6.

EXIT2:
    TestHwiDelete(HWI_NUM_TEST);
    LOS_TaskDelete(g_testTaskID01);

    return LOS_OK;

EXIT1:
    TestHwiDelete(HWI_NUM_TEST);

    return LOS_OK;
}

VOID ItLosHwi019(VOID) // IT_Layer_ModuleORFeature_No
{
    TEST_ADD_CASE("ItLosHwi019", Testcase, TEST_LOS, TEST_HWI, TEST_LEVEL2, TEST_FUNCTION);
}
