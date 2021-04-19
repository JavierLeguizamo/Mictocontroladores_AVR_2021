
#include <avr/io.h>
#include "ports.h"

/* Replace with your library code */


void portBMode(uint8_t mask){
	DDRB = mask;
}

void portBWrite(uint8_t out){
	PORTB = out;
}

uint8_t portBRead(){
	return PINC;
}

void portBWriteBit(uint8_t bit){
	PORTB |= 1<<bit;
}

