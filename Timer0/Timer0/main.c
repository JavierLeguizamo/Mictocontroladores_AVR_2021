

#include <avr/io.h>

int main(void)
{
    /* Replace with your application code */
    //TCCR0A |=  1<<WGM01 | _BV(COM0A0); // Activa modo CTC | Bit de Comparacion A
	TCCR0A |=  1<<WGM00 | _BV(COM0A1) | _BV(COM0B1) | _BV(COM0B0);
	TCCR0B |= 1<<CS00; //Prescaler de 8
	OCR0A = 100; //Registro de comparacion
	OCR0B = OCR0A; 
	
	while (1) 
    {
    }
}

