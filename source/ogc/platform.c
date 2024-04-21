#include <gccore.h>
#include <wiiuse/wpad.h>

#include "platform_defs.h"

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

// Wait for the next frame
void platform_vbl_wait (void) {
	VIDEO_WaitVSync();	
}

void platform_video_init(void) {
	// Initialise the video system
	VIDEO_Init();

#if __wii__
	// This function initialises the attached controllers
	WPAD_Init();
#elif __gamecube__
	PAD_Init();
#endif

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb,0,0,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

}


void platform_scan_input() {

#if __wii__
	WPAD_ScanPads();
#elif __gamecube__
	PAD_ScanPads();
#endif

}


int platform_buttons_down() {

#if __wii__
	// WPAD_ButtonsDown tells us which buttons were pressed in this loop
	// this is a "one shot" state which will not fire again until the button has been released
	return WPAD_ButtonsDown(0);
#elif __gamecube__
	return PAD_ButtonsDown(0);
#endif

}

bool platform_main_loop() {
	return true;
}

void platform_exit(void) {

}