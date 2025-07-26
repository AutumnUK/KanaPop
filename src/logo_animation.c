#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"

#include    "logo/logo_tiles.c"
#include    "logo/logo_background_1.c"
#include    "logo/logo_background_2.c"
#include    "logo/logo_background_3.c"
#include    "logo/logo_background_4.c"
#include    "logo/logo_background_5.c"
#include    "logo/logo_background_6.c"
#include    "logo/logo_background_7.c"

void logoAnimation( void ) {
    set_bkg_data(0,80,LogoTiles);
    while(1) {
                        set_bkg_tiles(0,0,20,18,LogoBackground1); 
        delay(500);     set_bkg_tiles(0,0,20,18,LogoBackground2); 
        delay(50);      set_bkg_tiles(0,0,20,18,LogoBackground3);
        delay(100);     set_bkg_tiles(0,0,20,18,LogoBackground4);
        delay(3000);    set_bkg_tiles(0,0,20,18,LogoBackground5);   
        delay(50);      set_bkg_tiles(0,0,20,18,LogoBackground6);
        delay(100);     set_bkg_tiles(0,0,20,18,LogoBackground7);   
        delay(1000);
        break;
    }
}