/*
 * port_mannager.c
 *
 * Created: 29/04/18 12:19:38 a. m.
 * Author : jimmy
 */ 

#include <avr/io.h>
#include "port_handler.h"


	
void port_b_set_out( unsigned char mask){
	DDRB |= mask; 
}

void port_b_set_in( unsigned char mask){
	DDRB &= ~(mask);
}
void port_b_set_bit(_PIN PIN){
	PORTB |= PIN; 
}
void port_b_clear_bit(_PIN PIN){
	PORTB &= ~(PIN);
}

void port_b_toggle_bit(_PIN PIN){
	
	PINB |= PIN;
}

void port_b_out(unsigned char mask){
	PORTB = mask;
}
unsigned char port_b_in(){
	return PINB;
}
unsigned char port_b_pin_in(_PIN PIN){
	return (PINB & (PIN));
}



void port_c_set_out( unsigned char mask){
	DDRC |= mask;
}

void port_c_set_in( unsigned char mask){
	DDRC &= ~(mask);
}
void port_c_set_bit(_PIN PIN){
	PORTC |= PIN;
}
void port_c_clear_bit(_PIN PIN){
	PORTC &= ~(PIN);
}

void port_c_toggle_bit(_PIN PIN){
		
	PINC |= PIN;
}

void port_c_out(unsigned char mask){
	PORTC = mask;
}
unsigned char port_c_in(){
	return PINC;
}
unsigned char port_c_pin_in(_PIN PIN){
	return (PINC & (PIN));
}



void set_port_d_out( unsigned char mask){
	DDRD |= mask;
}

void set_port_d_in( unsigned char mask){
	DDRD &= ~(mask);
}
void set_port_d_bit(_PIN PIN){
	PORTD |= PIN;
}
void clear_port_d_bit(_PIN PIN){
	PORTD &= ~(PIN);
}

void toggle_port_d_bit(_PIN PIN){
	
	PIND |= PIN;
}

void port_d_out(unsigned char mask){
	PORTD = mask;
}
unsigned char port_d_in(){
	return PIND;
}
unsigned char port_d_pin_in(_PIN PIN){
	return (PIND & (PIN));
}


#ifdef __cplusplus
PORT::PORT(_PORT puerto, unsigned char mask){
	port=puerto;
	setOut(puerto,mask);
}
void PORT::setPin(_PIN pin){
	setPin(port,pin);
}
void PORT::clearPin(_PIN pin){
	clearPin(port,pin);
}
void PORT::togglePin(_PIN pin){
	togglePin(port,pin);
}
void PORT::out(unsigned char mask){
	out(port,mask);
}
unsigned char PORT::in(){
	return in(port);
}
unsigned char PORT::pinIn(_PIN pin){
	return pinIn(port,pin);
}



void PORT::setOut(_PORT puerto,unsigned char mask){
	switch (puerto)
	{
		case B:
		DDRB |= mask;
		break;
		case C:
		DDRC |= mask;
		break;
		case D:
		DDRD |= mask;
		break;
	}
}

void PORT::setIn(_PORT puerto,unsigned char mask){
	switch (puerto)
	{
		case B:
		DDRB &= ~mask;
		break;
		case C:
		DDRC &= ~mask;
		break;
		case D:
		DDRD &= ~mask;
		break;
	}
}

void PORT::setPin(_PORT puerto,_PIN pin){
	switch (puerto)
	{
		case B:
		PORTB |= pin;
		break;
		case C:
		PORTC |= pin;
		break;
		
		case D:
		PORTD |= pin;
		break;
		
	}
}

void PORT::clearPin(_PORT puerto,_PIN pin){
	switch (puerto)
	{
		case B:
		PORTB &= ~(pin);
		break;
		case C:
		PORTC &= ~(pin);
		break;
		case D:
		PORTD &= ~(pin);
		break;
		
	}
}

void PORT::togglePin(_PORT puerto,_PIN pin){
	switch (puerto)
	{
		case B:
		PINB |= pin;
		break;
		case C:
		PINC |= pin;
		break;
		case D:
		PIND |= pin;
		break;
	}
	
}

void PORT::out(_PORT puerto,unsigned char mask){
	switch (puerto)
	{
		case B:
		PORTB |= mask;
		break;
		case C:
		PORTC |= mask;
		break;
		
		case D:
		PORTD |= mask;
		break;
		
	}
}

unsigned char PORT::in(_PORT puerto){
	switch (puerto)
	{
		case B:
		return PINB;
		break;
		case C:
		return PINC;
		break;
		case D:
		return PIND;
		break;
		default:
		return 0;
	}
	
}

unsigned char PORT::pinIn(_PORT puerto,_PIN pin){
	switch (puerto)
	{
		case B:
		return PINB & (pin);
		break;
		case C:
		return PINC & (pin);
		break;
		case D:
		return PIND & (pin);
		break;
		default:
		return 0;
	}
}

#endif
