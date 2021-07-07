

#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
    /* Replace with your application code */
    DDRB |= _BV(DDB1);
	TCCR1A |=  _BV(COM1A0);
	TCCR1B |= _BV(WGM12) |_BV(CS11);
	OCR1A = 65535;
	while (1) 
    {
    }
}

