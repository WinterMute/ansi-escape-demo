#pragma once

#include <stdbool.h>

#include "platform_defs.h"

void platform_video_init(void);
void platform_vbl_wait(void);
void platform_scan_input(void);
int platform_buttons_down();
bool platform_main_loop();
void platform_exit();

