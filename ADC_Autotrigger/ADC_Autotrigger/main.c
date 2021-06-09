

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect){
	PORTB = ADC>>1;
}

int main(void)
{
    /* Replace with your application code */
	DDRB |= 0xFF;
	ADMUX  |= _BV(REFS0);
	ADCSRA |= _BV(ADEN) |_BV(ADATE) | _BV(ADPS0) | _BV(ADPS1);
    ADCSRB |= _BV(ADTS1) | _BV(ADTS0);
	TCCR0A |= _BV(WGM01);
	TCCR0B |= _BV(CS00)|_BV(CS02);
	OCR0A = 255;
	TIMSK0 |= _BV(OCIE0A);
	sei();
	while (1) 
    {
    }
}

