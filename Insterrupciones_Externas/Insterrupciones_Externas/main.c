
#define F_CPU 1e6
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define ANY_INT0		1<<ISC00
#define RISING_INT0		1<<ISC01 | 1<<ISC00
#define FALLING_INT0	1<<ISC01
#define INT_0			1<<INT0
#define ANY_INT1		1<<ISC10
#define RISING_INT1		1<<ISC11 | 1<<ISC10
#define FALLING_INT1	1<<ISC11
#define INT_1			1<<INT1
#define BOTH_INTERRUPT	INT_0 | INT_1
#define INT_MODE(MODE)	EICRA |= MODE
#define INT_MASK(INT)	EIMSK |= INT

#define TOGGLE_PIN_PB(PIN)	PINB |= 1<<PIN;
#define INTERRUPT_FUNCTION ISR(INT0_vect)

INTERRUPT_FUNCTION{
	TOGGLE_PIN_PB(PINB0)
}
ISR(INT1_vect){
	TOGGLE_PIN_PB(PINB1)
}

int main(void)
{
    /* Replace with your application code */
	DDRD &= ~(1<<DDD2);
	DDRB |= 3<<DDB0;
	//EICRA |=  1<<ISC00;
	INT_MODE(RISING_INT0);
	//EIMSK |= 1<<INT0;
	INT_MASK(BOTH_INTERRUPT);
	sei();// HABILITA LAS INTERRUPCIONES GLOBALES
    while (1) 
    {
		
    }
}

