#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "logo_animation.h"
#include    "kana_pop_library.h"
#include    "game.h"
#include    "title_screen.h"
#include    "main_menu.h"
#include    "logo/logo_tiles.h"
#include    "logo/logo_background_1.h"

void main(void) { 

    vsync();    
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;   
    
    logoAnimation();
    titleScreen();

    set_bkg_data(0,80,LogoTiles);
    set_bkg_tiles(0,0,20,18,LogoBackground1); 
    
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
