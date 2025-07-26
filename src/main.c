#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "logo_animation.h"
#include    "kana_pop_library.h"
#include    "game.h"
#include    "title_screen.h"
#include    "main_menu.h"

void main(void) { 
    vsync();    
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;   
    
    logoAnimation();
    titleScreen();

    uint8_t state = 0;
    while(1) {
        switch (state) {
            case 0:
                state = mainMenu();
                break;
            case 1:
                state = game();
                break;
        }
    }


}
