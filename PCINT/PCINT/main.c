 

#include <avr/io.h>
#include <avr/interrupt.h>

#define PCINT_INT(PCINT) PCICR  |= 1<<PCINT
#define PCINT_MASK(MASK) PCMSK0 |= MASK

ISR(PCINT0_vect){
	if (PINB & (1<<PINB0) )
	{
		PORTB |= 1<<PINB5;
	}
	if (PINB & (1<<PINB1) )
	{
		PORTB &= ~(1<<PINB5);
	}
	
}

int main(void)
{
	cli();
    PCINT_INT(PCIE0);
	PCINT_MASK(1<<PCINT0 | 1<<PCINT1);
	DDRB   |= 1<<DDB5;
	sei();
    while (1) 
    {
		asm("nop");
    }
}

