#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"

uint8_t mainMenu( void ) {
    #define     MENU_START      1
    #define     MENU_HISCORE    2
    #define     MENU_OPTION     3

    uint8_t     selection   =   MENU_START;

    gotogxy(3,3);   
    gprintf("start");
    gotogxy(3,4);   
    gprintf("hiscore");
    gotogxy(3,5);   
    gprintf("options");

    while(1) {
        uint8_t joy = joypad();

        if (joy & J_UP)     { 
            delay(200); 
            selection --; 
        }

        if (joy & J_DOWN)   { 
            delay(200); 
            selection ++; 
        }

        if (selection == 0) { 
            selection = 3; 
        }

        if (selection == 4) { 
            selection = 1; 
        }

        if (selection == MENU_START) {
                gotogxy(2,3);   
                gprintf("x");
                gotogxy(2,4);   
                gprintf(" ");
                gotogxy(2,5);   
                gprintf(" ");
                if (joy & J_A)     { 
                    delay(200); 
                    gotogxy(0,0);
                    for (uint16_t i = 0; i < 360; i++) {
                        gprintf( " " );
                    }
                    return 1;
                }
        }

        if (selection == MENU_HISCORE) {
                gotogxy(2,3);   
                gprintf(" ");
                gotogxy(2,4);   
                gprintf("x");
                gotogxy(2,5);   
                gprintf(" ");
        }
 
        if (selection == MENU_OPTION) {
                gotogxy(2,3);   
                gprintf(" ");
                gotogxy(2,4);   
                gprintf(" ");
                gotogxy(2,5);   
                gprintf("x");
        }

    }
}