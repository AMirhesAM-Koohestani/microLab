#include <io.h>
#include <alcd.h>

void main(void)
{
    DDRD = 0xFF;
    PORTD = 0x00;
    lcd_init(16);

    lcd_clear();
    lcd_puts("  Hello World!");

while (1)
    {
        // do nothing
    }
}
