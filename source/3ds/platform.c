#include <3ds.h>

#include "platform_defs.h"

void platform_video_init(void) {
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
}

bool platform_main_loop() {
	return aptMainLoop();
}

void platform_vbl_wait(void) {
	gspWaitForVBlank();
	gfxSwapBuffers();
}

void platform_exit(void) {
	gfxExit();
}

void platform_scan_input(void) {
	hidScanInput();
}

int platform_buttons_down() {
	return hidKeysDown();
}