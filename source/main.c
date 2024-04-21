#include <stdio.h>
#include <stdlib.h>

#include "platform.h"

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	platform_video_init();

	// The console understands VT terminal escape codes
    // clear screen and home cursor
    printf( CONSOLE_ESC(2J) );

    // Set print co-ordinates
    // /x1b[row;columnH
    printf(CONSOLE_ESC(22;10H) "Ansi codes demo");

    // move cursor up
    // /x1b[linesA
    printf(CONSOLE_ESC(21A)"Line 1");

    // move cursor left
    // /x1b[columnsD
    printf(CONSOLE_ESC(28D)"Column1");

    // move cursor down
    // /x1b[linesB
    printf(CONSOLE_ESC(19B)"Line 19");

    // move cursor right
    // /x1b[columnsC
    printf(CONSOLE_ESC(5C)"Column 20");

    printf(CONSOLE_ESC(2;1H));

    // Color codes and attributes
    for(int i=0; i<8; i++)
    {
        printf(
       		    CONSOLE_ESC(%1$d;1m) /* Set color */
                "Default "
                CONSOLE_ESC(1m) "Bold "
                CONSOLE_ESC(7m) "Reverse "

                CONSOLE_ESC(0m) /* revert attributes*/
                CONSOLE_ESC(%1$d;1m)

                CONSOLE_ESC(2m) "Light "
                CONSOLE_ESC(7m) "Reverse "

                CONSOLE_ESC(0m) /* revert attributes*/
                CONSOLE_ESC(%1$d;1m)
                CONSOLE_ESC(4m) "Under "

                CONSOLE_ESC(0m) /* revert attributes*/
                CONSOLE_ESC(%1$d;1m)
                CONSOLE_ESC(9m) "Strike "
                "\n"
                CONSOLE_ESC(0m) /* revert attributes*/
                , i + 30);
    }

	while(platform_main_loop()) {

		platform_scan_input();

		int buttonsDown = platform_buttons_down();

		if( buttonsDown & PLATFORM_BUTTON_A ) {
			printf("Button A pressed.\n");
		}

		if( buttonsDown & PLATFORM_BUTTON_B ) {
			printf("Button A pressed.\n");
		}

		if (buttonsDown & PLATFORM_BUTTON_EXIT) {
			break;
		}

		// Wait for the next frame
		platform_vbl_wait();
	}

	platform_exit();

	return 0;
}
