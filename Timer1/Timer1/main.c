#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DDRB |= _BV(DDB1);
    TCCR1A |= _BV(WGM10) | _BV(WGM11) | _BV(COM1A1);
	TCCR1B |= _BV(WGM12) | _BV(CS11) ;
	OCR1A = 1;
	while (1) 
    {
		for (OCR1A=1; OCR1A<=1000;OCR1A +=10)
		{
			_delay_ms(25);
		}
		_delay_ms(1000);
		for (OCR1A = 1000; OCR1A>0;OCR1A -=10)
		{
			_delay_ms(25);
		}
	_delay_ms(1000);
    }
}

