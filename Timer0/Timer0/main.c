

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRD |= _BV(DDD6);
    TCCR0A |= 1<<WGM01 | _BV(COM0A0); // Activa modo CTC | Bit de Comparacion A
	TCCR0B |= 1<<CS00 | 1<<CS02; //Prescaler de 8
	OCR0A = 255; //Registro de comparacion
	while (1) 
    {
    }
}

