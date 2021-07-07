#ifndef F_CPU
#define  F_CPU 8000000UL
#endif

#include "MAX7219_def.h"
#include <util/delay.h>

MAX7219::MAX7219(){
	
}

void MAX7219::init(uint8_t no_matrices){
	/*asm("cli");*/
	matrices=no_matrices;
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK);
	SPCR |= (1<<SPE) | (1<<MSTR) /*| (1<<DORD) | (1<<SPR1)*/ ;
	SPSR |= 1<<SPI2X;
	PORTB |= (1<<SS);
	
	
	shutdown(NORMAL_MODE);
	decode_mode(NO_DECODE);
	set_intensity(INTENSITY_31_32);
	scan_limit(DISPLAY_EIGHT_DIGIT);
	display_test(NORMAL_OPERATION);
}

void MAX7219::send_end_(uint8_t addres, uint8_t data, uint8_t matriz){
	//init(matrices);
	if (matriz>matrices)
	{
		matriz = 1;
	}
	PORTB &= ~(1<<SS);
	SPDR = addres;
	wait_end_transmit();
	SPDR = data;
	wait_end_transmit();
	if (matriz>=1)
	{
		for (int i = 0; i < matriz-1 ; i++)
		{
			no_op();
		}	
	}
	
	PORTB |= (1<<SS);
	//_delay_ms(250);
}

void MAX7219::send_char(uint8_t *data, uint8_t matriz){
	uint8_t j = 0;
	for (int i = 7; i >= 0 ; i--)
	{
		
		send_end_(DIGIT[i],data[j],matriz);
		j++;
		
	}
	
}

void MAX7219::send_text(uint8_t **data, uint8_t no_matrices){
	for (int k = 1; k<=no_matrices;k++)
	{
		send_char(data[k-1],k);
		//_delay_ms(1000);
	}
}

void MAX7219::limpiar_matriz(uint8_t no_matriz){
 
	for (int i = 7; i >= 0 ; i--)
	{
		send_end_(DIGIT[i],0,no_matriz);
		
// 		_delay_us(100000);
	}
	
}

void MAX7219::limpiar_todo(){
	for (int i = 1; i<=matrices;i++)
	{
		limpiar_matriz(i);
	}
}

void MAX7219::send_end(uint8_t addrs, uint8_t data){
	
	PORTB &= ~(1<<SS);
	
	SPDR = addrs;
	wait_end_transmit();
	SPDR = data;
	wait_end_transmit();
	/*PORTB |= (1<<SS);*/
	
	
}

void MAX7219::send_data(uint8_t addrs, uint8_t* data, uint8_t matrix){
	for (int i = 0; i<8; i++)
	{
		//send(addrs+i,*data++, matrix);	
	}
	
}

void MAX7219::wait_end_transmit(){
	while (!(SPSR & (1<<SPIF)));
}

void MAX7219::set_intensity(uint8_t intensity){
	uint8_t j=matrices;
	do 
	{
		PORTB &= ~(1<<SS);
		send_end_(INTENSITY,intensity,j);
		for (int i = j-1; i > 0 ; i--)
			no_op();
		PORTB |= (1<<SS);
		j--;
	} while (j>0);
		
	
}

void MAX7219::decode_mode(uint8_t mode){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	send_end_(DECODE_MODE,mode,j);
	for (int i = j-1; i > 0 ; i--)
	{
		no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219::scan_limit(uint8_t limit){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	send_end_(SCAN_LIMIT,limit,j);
	for (int i = j; i > 0 ; i--)
	{
		no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219::display_test(uint8_t test){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	send_end_(DISPLAY_TEST,test,j);
	for (int i = j-1; i > 0 ; i--)
	{
		no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219::shutdown(uint8_t shutdown_mode){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	send_end_(SHUTDOWN,shutdown_mode,j);
	for (int i = j-1; i > 0 ; i--)
	{
		no_op();
	}
	PORTB |= (1<<SS);
		j--;
	} while (j>0);
}

void MAX7219::no_op(){
	//PORTB &= ~(1<<SS);
	SPDR = NO_OP;
	wait_end_transmit();
	SPDR = NO_OP;
	wait_end_transmit();
}

