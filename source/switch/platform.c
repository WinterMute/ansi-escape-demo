#include <switch.h>

#include "platform_defs.h"

 static  PadState pad;
 
 void platform_video_init(void) {
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    padInitializeDefault(&pad);
}

bool platform_main_loop() {
	return appletMainLoop();
}

void platform_vbl_wait(void) {
	consoleUpdate(NULL);
}

void platform_exit(void) {
	consoleExit(NULL);
}

void platform_scan_input(void) {
	padUpdate(&pad);
}

int platform_buttons_down() {
	return padGetButtonsDown(&pad);
}