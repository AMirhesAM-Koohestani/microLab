#include <io.h>
#include <delay.h>

unsigned char states[4] = {0x01, 0x04, 0x02, 0x08};
unsigned char current_state = 0;
unsigned char reverse = 0;

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    if (reverse == 0)
        reverse = 1;
    else
        reverse = 0;
}


void main(void)
{
    DDRC = 0xFF;
    PORTC = 0x00;

    DDRD = 0x00;
    PORTD = 0x00;

    GICR|= 1<<INT0;
    MCUCR |= 1<<ISC01;
    GIFR |= 1<<INTF0;

    #asm("sei")

while (1)
    {
        if (reverse == 0)
        {
            if (current_state < 3)
                current_state++;
            else
                current_state = 0;
        }
        else {
            if (current_state > 0)
                current_state--;
            else
                current_state = 3;
        }

        PORTC = states[current_state];
        delay_ms(50);
    }
}
