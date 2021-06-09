/*
 * Repso timers.c
 *
 * Created: 27/05/2021 12:41:24 p. m.
 * Author : jimmy
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
   DDRD |= 1<<DDD6;
   OCR0A = 230;
   OCR0B = 100;
   TCCR0A |= 1<<WGM00 | 1<<WGM01 | 1<<COM0A0  | 1<<COM0A1;
   TCCR0B |= 1<<CS00 | 1<<CS01;
   
    while (1) 
    {
		asm("nop");
    }
}

