/*
 * ADC_Precencial.c
 *
 * Created: 28/06/2021 11:37:30 a. m.
 * Author : jimmy
 */ 

#include <avr/io.h>

uint16_t read_ADC(uint8_t adc);

int main(void)
{
    /* Replace with your application code */
	uint16_t adc_0=0;
	DDRB |= 0xFF;
	DDRD |=0xFF;
    ADMUX |= _BV(REFS0);
	ADCSRA |= _BV(ADEN) | _BV(ADSC) | 3<<ADPS0;
    while (1) 
    {
	
		PORTB = read_ADC(0);
		PORTD = read_ADC(1);
    }
}

uint16_t read_ADC(uint8_t adc){
	ADMUX = _BV(REFS0) | adc;
	ADCSRA |=  _BV(ADSC);
	while(!( ADCSRA & 1<<ADIF));
	return ADC;
}