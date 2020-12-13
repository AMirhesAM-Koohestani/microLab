#include <mega16.h>
#include <delay.h>

void main (void) {
    DDRA = 0x01;
    while(1) {
        PORTA.0 = PORTA.0 ^ 0x1;
        delay_ms(500);
    }
}
