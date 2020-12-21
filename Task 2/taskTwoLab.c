#include <mega16.h>
#include <stdio.h>

// Declare your global variables here
unsigned int timer0_OvrFlw=0;
unsigned int timer1_OvrFlw=0;
int sevenSegmentDigits[4] = {0, 0, 0, 0};
int zeroToNineNumbers[10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 ,0x7F ,0x6F};
int turn=0;
int i =0;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    timer0_OvrFlw++;
    if(timer0_OvrFlw == 2){
        PORTD = Numbers[sevenSegmentDigits[turn]];
        if(turn == 0){
            PORTC = 0b11111110;
        }else{
            PORTC= ((PORTC ^ 0b11111111) * 2 ) ^ 0b11111111;
        }

        if(PORTC == 0b11101111){
            PORTC = 0b11111110;
        }

        timer0_OvrFlw=0;
        turn++;
        if(turn == 4 ){
            turn = 0;
        }
    }
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    ++timer1_OvrFlw;
    if(timer1_OvrFlw == 20){
        sevenSegmentDigits[0]++;
        while (i<=4){
            if( sevenSegmentDigits[i] == 0b1010){
            sevenSegmentDigits[++i]++;
            sevenSegmentDigits[i]=0;
            }
            i++;
        }
        i=0;
        timer1_OvrFlw=0;
    }
    TCNT1H=0xFF;
    TCNT1L=0x00;
}

void main(void)
{
DDRC = 0xFF;
  DDRD = 0xFF;
  PORTD = 0x00;
  PORTC = 0xFF;
  TCCR0 = 0x05;
  TCCR1B = 0x05;
  TCNT1H = 0xFF;
  TCNT1L = 0x00;
  TIMSK = 0x05;
  #asm("sei")
  while (1){
    //do nothing
  }
}