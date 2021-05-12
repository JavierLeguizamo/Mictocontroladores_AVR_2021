#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

#define RS 1<<DDC0
#define RW 1<<DDC1
#define E 1<<DDC2
#define DATA_PORT PORTB
#define CONTROL_PORT PORTC

int main(void)
{
    DDRB |= 0xFF;
	DDRC |= RS | RW | E; 
	
	_delay_ms(15);
	CONTROL_PORT &= ~(RS|RW|E); 
	DATA_PORT = 0x30;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
	
	_delay_ms(5);
	
	DATA_PORT = 0x30;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
	
	_delay_us(100);
	
	DATA_PORT = 0x30;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
	DATA_PORT = 0x38;
	CONTROL_PORT &= ~(E);
	
	DATA_PORT = 0x08;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);

	DATA_PORT = 0x01;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);

	DATA_PORT = 0x06;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
	
	
	DATA_PORT = 0x0e;
	//DATA_PORT = 0x0f;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
	DATA_PORT = 0x0f;
	CONTROL_PORT |= E;
	CONTROL_PORT &= ~(E);
    while (1) 
    {
    }
}

