
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect){
	PINB |= 1<<PINB0;
	
}
ISR(TIMER0_COMPB_vect){
	//PORTB |= 1<<PORTB0;
}
ISR(TIMER0_OVF_vect){
	PINB |= 1<<PINB1;
}

int main(void)
{
    /* Replace with your application code */
    DDRB |= 7<<DDB0;
	DDRD |= 3<<DDD5;
	TCCR0A |= _BV(WGM00) | _BV(WGM00) | _BV(COM0A0) | _BV(COM0A1) | _BV(COM0B1)  | _BV(COM0B0);
	TCCR0B |= _BV(CS01);
	OCR0A = 100;
	OCR0B = 150;
	TIMSK0 |= 7<<TOIE0;//0b111
	sei();
	while (1) 
    {
    }
}

