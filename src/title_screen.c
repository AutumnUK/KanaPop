#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "title/title_map.c"
#include    "title/title_tiles.c"
void titleScreen( void ) {
    set_bkg_data(0,80,TitleTiles);
    set_bkg_tiles(0,0,20,18,TitleMap);
    while(1){
        uint8_t joy = joypad();
        waitpad(J_START);
        waitpadup();
        return;
    }
}