// Copyright 2020-2021 Beken
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

#include "cli.h"

extern void cli_fft_fft_test_cmd(char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv);
extern void cli_fft_ifft_test_cmd(char *pcWriteBuffer, int xWriteBufferLen, int argc, char **argv);

#define FFT_CMD_CNT (sizeof(s_fft_commands) / sizeof(struct cli_command))
static const struct cli_command s_fft_commands[] = {
	{"fft_fft_test", "fft_fft_test {start|stop}", cli_fft_fft_test_cmd},
	{"fft_ifft_test", "fft_ifft_test {start|stop}", cli_fft_ifft_test_cmd},
};

int cli_fft_init(void)
{
	return cli_register_commands(s_fft_commands, FFT_CMD_CNT);
}

