#include <io.h>
#include <alcd.h>
#include <delay.h>

void main(void)
{
    unsigned char str[2];
    int i;

    DDRD = 0xFF;
    PORTD = 0x00;
    lcd_init(16);

    str[1] = 0; // end of string

while (1)
    {
        lcd_clear();
        for (i=0; i<26; i++)
        {
            str[0] = i+'A';
            lcd_puts(str);
            delay_ms(100);
        }
        delay_ms(2000);

        lcd_clear();
        for (i=0; i<26; i++)
        {
            str[0] = i+'a';
            lcd_puts(str);
            delay_ms(100);
        }
        delay_ms(2000);

    }
}
