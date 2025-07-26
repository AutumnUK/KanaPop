#include    "../Tools/GBDK/include/rand.h"
#include    "../Tools/GBDK/include/gb/gb.h"
// Returns a number from 0 to the number -1.
// genNumber(10) = 0 to 9, 10 values
uint8_t genNumber(uint8_t range) {
    initrand(DIV_REG);
    uint8_t num = (rand() % range);
    delay(5);
    return num;
}