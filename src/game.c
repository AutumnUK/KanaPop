#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "kana_pop_library.h"



void draw_static_ui( uint8_t sec, uint8_t liv, uint8_t sco, uint8_t hsc ) {
    gotogxy(0,0);   gprintf("TIMER : %d", sec);
    gotogxy(11, 0); gprintf("LIVES : %d", liv);
    gotogxy(0,1);   gprintf("SCORE : %d", sco);
    gotogxy(11,1);  gprintf(" HIGH : %d", hsc);
}

uint8_t game( void ) {
    uint8_t seconds     = 60;
    uint8_t frames      = 60;
    uint8_t lives       = 3;
    uint8_t score       = 0;
    uint8_t highscore   = 0;
    uint8_t kana        = 0;
    uint8_t numbers[4]  = { 0 , 0 , 0 , 0 };
    uint8_t generated   = 0;
    uint8_t userans     = 255;
    
    draw_static_ui(seconds, lives, score, highscore);

    while(1) {
        vsync();
        while (generated == 0) {
            uint8_t duplicates  = 0;
            kana        = genNumber(103);
            numbers[0] = kana;
            numbers[1] = genNumber(103);
            numbers[2] = genNumber(103);
            numbers[3] = genNumber(103);

            // Check for duplicates. Redo if any are found.
            for (uint8_t i = 0; i < 3; i++) {
                for (uint8_t j = i+1; j < 4; j++) {
                    if (numbers[i] == numbers[j]) {
                        duplicates = 1;
                    }
                }
            }

            // Fisher-Yates Shuffle
            for (uint8_t i = 3; i > 0; i--) {
                uint8_t swap = genNumber(i);  // random number in [0, i]
                uint8_t temp = numbers[i];
                numbers[i]   = numbers[swap];
                numbers[swap]= temp;
            }

            gotogxy(0,3);   gprintf("     Ans :    ");
            gotogxy(0,4);   gprintf("Option 1 :    ");
            gotogxy(0,5);   gprintf("Option 2 :    ");
            gotogxy(0,6);   gprintf("Option 3 :    ");
            gotogxy(0,7);   gprintf("Option 4 :    ");

            gotogxy(0,3);   gprintf("     Ans : %d", kana);
            gotogxy(0,4);   gprintf("    Left : %d", numbers[0]);
            gotogxy(0,5);   gprintf("   Right : %d", numbers[1]);
            gotogxy(0,6);   gprintf("      Up : %d", numbers[2]);
            gotogxy(0,7);   gprintf("    Down : %d", numbers[3]);
  
            if (duplicates == 0) { generated   = 1; }
        }

        // Timer
        frames --; 
        if ( frames == 0 ) { 
            seconds --; 
            frames = 60; 
            gotogxy(0,0);   gprintf("TIMER : %d", seconds); 
        } 

        if (joypad() & J_LEFT)  { userans = numbers[0]; }
        if (joypad() & J_RIGHT) { userans = numbers[1]; }        
        if (joypad() & J_UP)    { userans = numbers[2]; }
        if (joypad() & J_DOWN)  { userans = numbers[3]; }



        if (userans != 255) {
            if (userans == kana) {
                gotogxy(0,1);   gprintf("SCORE : %d", score);
                score++;
                userans = 255;
                generated = 0;
            }
            if (userans != kana) {
                lives --;
                gotogxy(11, 0); gprintf("LIVES : %d", lives);
                userans = 255;
                generated = 0;
            }
        }

        // Gameover screen followed by results screen should go here.
        if (seconds <= 0 || lives == 0) { 
            clear_screen();
            return 0; 
            
        }

    }
}