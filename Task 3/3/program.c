#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

unsigned int counter;
unsigned int frequency;

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    frequency = 1.9073486328125 * counter;
    counter = 0;
}

interrupt [TIM1_CAPT] void timer1_capt_isr(void)
{
    counter++;
}

void main(void)
{
    unsigned char str[32];

    DDRC = 0xFF;
    PORTC = 0x00;

    DDRD = 0x00;
    PORTD = 0x00;

    DDRB = 0xFF;
    PORTB = 0x00;
    lcd_init(16);

    TCCR1A = 0x00;
    TCCR1B = 0x43;
    TIMSK = 0x24;
    #asm("sei")

while (1)
    {
        lcd_clear();
        sprintf(str, "Freq: %d Hz", frequency);
        lcd_puts(str);
        lcd_gotoxy(0,1);
        lcd_puts("2Hz<Freq<60KHz");
        delay_ms(2000);

    }
}
