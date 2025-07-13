#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "../Tools/GBDK/include/rand.h"

///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////

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

uint8_t game( void ) {
    uint8_t seconds = 60;
    uint8_t frames  = 60;
    uint8_t lives   = 3;
    uint8_t score   = 0;
    uint8_t highscore = 0;

    uint8_t kana;
    uint8_t wrong1;
    uint8_t wrong2;
    uint8_t wrong3;
    

    vsync();
  uint8_t generated = 0;

    while(1) {
        

        while (generated == 0) {
            initrand(DIV_REG);
            kana    = ( rand() % 102 ) + 1;
            wrong1  = ( rand() % 102 ) + 1;
            wrong2  = ( rand() % 102 ) + 1;
            wrong3  = ( rand() % 102 ) + 1;
            uint8_t numbers[] = { kana , wrong1 , wrong2 , wrong3 };

            for (uint8_t i = 0; i < 3; i++) {
                for (uint8_t j = i + 1; j < 4; j++) {
                    if (numbers[i] == numbers[j]) {
                        break;
                    }
                }
            }


            generated = 1;
            
        }
            uint8_t numbers[] = { kana , wrong1 , wrong2 , wrong3 };

        gotogxy(6,6);
        for (uint8_t i = 0; i < 4; i++) {
            gprintf("%d\n",numbers[i]);
        }

        gotogxy(0,0);   
        gprintf("TIMER : %d", seconds);
        gotogxy(11, 0); 
        gprintf("LIVES : %d", lives);
        gotogxy(0,1);   
        gprintf("SCORE : %d", score);
        gotogxy(11,1);  
        gprintf(" HIGH : %d", highscore);

        frames --;
        if ( frames == 0 ) {
            seconds --;
            frames = 60;
        }

        if (frames == 0 && seconds == 0) {
            return 1;
        }

        
    }
}


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
                    game();
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





void main(void) { 
    vsync();    
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;   
    
    logoAnimation();
    titleScreen();
    switch (mainMenu()) {
        case 1 :

            
            break;
    }

}
