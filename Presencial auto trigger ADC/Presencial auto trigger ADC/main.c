/*
 * Presencial auto trigger ADC.c
 *
 * Created: 28/06/2021 01:36:16 p. m.
 * Author : jimmy
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define CTC_MODE TCCR0A |= _BV(WGM01)
#define TIM0_PREESCALER_1024 TCCR0B |= 5<<CS00
#define COMPARATION_A OCR0A = 255
#define TIM_INT_COM_A_EN TIMSK0 |= _BV(OCIE0A)

#define ADC_REFERENCE ADMUX |= _BV(REFS0)
#define ADC_TO_READ(x) ADMUX |= _BV(REFS0) | x
#define ADC_ENABLE ADCSRA |= _BV(ADEN)
#define ADC_Start_Convertion ADCSRA |= _BV(ADSC)
#define ADC_AUTOTRIGGER ADCSRA |= _BV(ADATE)
#define ADC_PREESCALER_8 ADCSRA |= 3<<ADPS0
#define ADC_INTERRUPT_EN ADCSRA |= _BV(ADIE)
#define ADC_COMPA0_TRIGG ADCSRB |= 3<<ADTS0


uint8_t _adc=0;


ISR(ADC_vect){
	uint16_t adc_read = ADC;
	if (adc_read > 716)
	{
		PORTB |= 1<<0;
	}else{
		PORTB &= ~(1<<0);
	}
	//Acciones a realizar con el valor del ADC
	/*if(_adc++>5){
		_adc =0;
	}*/
	/*ADC_TO_READ(_adc);
	PORTB = _adc;*/
}

ISR(TIMER0_COMPA_vect){
	PINB |= 1<<7;
}

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	CTC_MODE;
	TIM0_PREESCALER_1024;
	COMPARATION_A;
	TIM_INT_COM_A_EN;
	ADC_REFERENCE;
	ADC_ENABLE;
	ADC_AUTOTRIGGER;
	ADC_PREESCALER_8;
	ADC_INTERRUPT_EN;
	ADC_COMPA0_TRIGG;
	ADC_TO_READ(_adc);
	sei();
    while (1) 
    {
		asm("nop");
    }
}

