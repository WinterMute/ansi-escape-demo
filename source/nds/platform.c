#include "platform_defs.h"


// Wait for the next frame
void platform_vbl_wait (void) {
	swiWaitForVBlank();	
}

void platform_video_init(void) {

	consoleDemoInit();

}

void platform_scan_input() {
	scanKeys();
}

int platform_buttons_down() {
	return keysDown();
}

bool platform_main_loop() {
	return pmMainLoop();
}

void platform_exit(void) {

}