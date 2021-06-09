/*
 * ADC.c
 *
 * Created: 26/05/2021 07:20:03 a. m.
 * Author : jimmy
 */ 
#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>
uint8_t adc[2];
uint16_t readADC(uint8_t adc)
{
	ADMUX = _BV(REFS0) | adc;
	ADCSRA |= _BV(ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	return ADC;
}

int main(void)
{
    /* Replace with your application code */
   
    DDRB = 0xFF;
	DDRD = 0xFF;
	ADMUX = _BV(REFS0) ;
	ADCSRA |= _BV(ADPS0) | _BV(ADEN) | _BV(ADSC);
	
	while (1) 
    {
		PORTB = readADC(0);
		PORTD = readADC(1);
    }
}

