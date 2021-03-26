

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRB  |=   1<<DDB0; // Configuramos el pin 0 del Puerto B como salida
	PORTB |=   1<<PORTB0; // Escribimos un estado alto en el pin 0 del Puerto B
	PORTB &= ~(1<<PORTB0); //Escribimos un estado bajo en el pin 0 del Puerto B
    while (1) 
    {
    }
}

