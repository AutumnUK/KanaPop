#include    "../Tools/GBDK/include/gb/gb.h"
#include    "../Tools/GBDK/include/gb/drawing.h"
#include    "logo_animation.h"
#include    "kana_pop_library.h"
#include    "game.h"
#include    "title_screen.h"
#include    "main_menu.h"

struct kana {
    char    romaji[4];
    uint8_t id;
};

void main(void) { 
    struct kana  k1; //a
    k1.romaji[0] = 'a';
    k1.romaji[1] = '\0';

    struct kana  k2; //i
    k2.romaji[0] = 'i';
    k2.romaji[1] = '\0';

    struct kana  k3; //u
    k3.romaji[0] = 'u';
    k3.romaji[1] = '\0';

    struct kana  k4; //e
    k4.romaji[0] = 'e';
    k4.romaji[1] = '\0';  

    struct kana  k5; //o
    k5.romaji[0] = 'o';
    k5.romaji[1] = '\0';

    struct kana  k6; //ka
    k6.romaji[0] = 'k';
    k6.romaji[1] = 'a';
    k6.romaji[1] = '\0';

    struct kana  k7; //ki
    k7.romaji[0] = 'k';
    k7.romaji[1] = 'i';
    k7.romaji[1] = '\0';
    
    struct kana  k8; //ku
    k8.romaji[0] = 'k';
    k8.romaji[1] = 'u';
    k8.romaji[1] = '\0';

    struct kana  k9; //ke
    k9.romaji[0] = 'k';
    k9.romaji[1] = 'e';
    k9.romaji[1] = '\0';

    struct kana k10; //ko
    k10.romaji[0] = 'k';
    k10.romaji[1] = 'o';
    k10.romaji[1] = '\0';

    struct kana k11; //sa
    k11.romaji[0] = 's';
    k11.romaji[1] = 'a';
    k11.romaji[1] = '\0';
    
    struct kana k12; //shi
    k12.romaji[0] = 's';
    k12.romaji[1] = 'h';
    k12.romaji[2] = 'i';
    k11.romaji[3] = '\0';

    struct kana k13; //su
    k13.romaji[0] = 's';
    k13.romaji[1] = 'u';
    k13.romaji[1] = '\0';

    struct kana k14; //se
    k14.romaji[0] = 's';
    k14.romaji[1] = 'e';
    k14.romaji[1] = '\0';
    
    struct kana k15; //so
    k15.romaji[0] = 's';
    k15.romaji[1] = 'o';
    k15.romaji[1] = '\0';

    struct kana k16; //ta
    k16.romaji[0] = 't';
    k16.romaji[1] = 'a';
    k16.romaji[1] = '\0';

    struct kana k17; //chi
    k17.romaji[0] = 'c';
    k17.romaji[1] = 'h';
    k17.romaji[2] = 'i';
    k17.romaji[3] = '\0';

    struct kana k18; //tsu
    k18.romaji[0] = 't';
    k18.romaji[1] = 's';
    k18.romaji[2] = 'u';
    k18.romaji[3] = '\0';

    struct kana k19; //te;
    k19.romaji[0] = 't';
    k19.romaji[1] = 'e';
    k19.romaji[2] = '\0';

    struct kana k20; //to
    k20.romaji[0] = 't';
    k20.romaji[1] = 'o';
    k20.romaji[2] = '\0';

    struct kana k21; //na
    k21.romaji[0] = 'n';
    k21.romaji[1] = 'a';
    k21.romaji[2] = '\0';

    struct kana k22; //ni
    k22.romaji[0] = 'n';
    k22.romaji[1] = 'i';
    k22.romaji[2] = '\0';

    struct kana k23; //nu
    k23.romaji[0] = 'n';
    k23.romaji[1] = 'u';
    k23.romaji[2] = '\0';

    struct kana k24; //ne
    k24.romaji[0] = 'n';
    k24.romaji[1] = 'e';
    k24.romaji[2] = '\0';

    struct kana k25; //no
    k25.romaji[0] = 'n';
    k25.romaji[1] = 'o';
    k25.romaji[2] = '\0';

    struct kana k26; //ha
    k26.romaji[0] = 'h';
    k26.romaji[1] = 'a';
    k26.romaji[2] = '\0';

    struct kana k27; //hi
    k27.romaji[0] = 'h';
    k27.romaji[1] = 'i';
    k27.romaji[2] = '\0';

    struct kana k28; //fu
    k28.romaji[0] = 'f';
    k28.romaji[1] = 'u';
    k28.romaji[2] = '\0';

    struct kana k29; //he
    k29.romaji[0] = 'h';
    k29.romaji[1] = 'e';
    k29.romaji[2] = '\0';

    struct kana k30; //ho
    struct kana k31; //ma
    struct kana k32; //mi
    struct kana k33; //mu
    struct kana k34; //me
    struct kana k35; //mo
    struct kana k36; //ya
    struct kana k37; //yu
    struct kana k38; //yo
    struct kana k39; //ra
    struct kana k40; //ri
    struct kana k41; //ru
    struct kana k42; //re
    struct kana k43; //ro
    struct kana k44; //wa
    struct kana k45; //wo
    struct kana k46; //n



    vsync();    
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;   
    
    logoAnimation();
    titleScreen();
    gotogxy(1,1);
    gprintf("%s",k1.romaji);
    // uint8_t state = 0;
    // while(1) {
    //     switch (state) {
    //         case 0:
    //             state = mainMenu();
    //             break;
    //         case 1:
    //             state = game();
    //             break;
    //     }
    // }


}
