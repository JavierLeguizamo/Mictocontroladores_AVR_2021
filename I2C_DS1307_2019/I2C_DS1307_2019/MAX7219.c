#ifndef F_CPU
#define  F_CPU 8000000UL
#endif

#include "MAX7219.h"
#include <util/delay.h>

void MAX7219_init(uint8_t no_matrices){
	/*asm("cli");*/
	matrices=no_matrices;
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK);
	SPCR |= (1<<SPE) | (1<<MSTR) /*| (1<<DORD) | (1<<SPR1)*/ ;
	SPSR |= 1<<SPI2X;
	PORTB |= (1<<SS);
	
	
	MAX7219_shutdown(NORMAL_MODE);
	MAX7219_decode_mode(NO_DECODE);
	MAX7219_set_intensity(INTENSITY_31_32);
	MAX7219_scan_limit(DISPLAY_EIGHT_DIGIT);
	MAX7219_display_test(NORMAL_OPERATION);
}

void MAX7219_send_end_(uint8_t addres, uint8_t data, uint8_t matriz){
	//init(matrices);
	if (matriz>matrices)
	{
		matriz = 1;
	}
	PORTB &= ~(1<<SS);
	SPDR = addres;
	MAX7219_wait_end_transmit();
	SPDR = data;
	MAX7219_wait_end_transmit();
	if (matriz>=1)
	{
		for (int i = 0; i < matriz-1 ; i++)
		{
			MAX7219_no_op();
		}	
	}
	
	PORTB |= (1<<SS);
	//_delay_ms(250);
}

void MAX7219_send_char(uint8_t *data, uint8_t matriz){
	uint8_t j = 0;
	for (int i = 7; i >= 0 ; i--)
	{
		
		MAX7219_send_end_(DIGIT[i],data[j],matriz);
		j++;
		
	}
	
}

void MAX7219_send_text(uint8_t **data, uint8_t no_matrices){
	for (int k = 1; k<=no_matrices;k++)
	{
		MAX7219_send_char(data[k-1],k);
		//_delay_ms(1000);
	}
}

void MAX7219_limpiar_matriz(uint8_t no_matriz){
 
	for (int i = 7; i >= 0 ; i--)
	{
		MAX7219_send_end_(DIGIT[i],0,no_matriz);
		
// 		_delay_us(100000);
	}
	
}

void MAX7219_limpiar_todo(){
	for (int i = 1; i<=matrices;i++)
	{
		MAX7219_limpiar_matriz(i);
	}
}

void MAX7219_send_end(uint8_t addrs, uint8_t data){
	
	PORTB &= ~(1<<SS);
	
	SPDR = addrs;
	MAX7219_wait_end_transmit();
	SPDR = data;
	MAX7219_wait_end_transmit();
	/*PORTB |= (1<<SS);*/
	
	
}

void MAX7219_send_data(uint8_t addrs, uint8_t* data, uint8_t matrix){
	for (int i = 0; i<8; i++)
	{
		//MAX7219_send(addrs+i,*data++, matrix);	
	}
	
}

void MAX7219_wait_end_transmit(){
	while (!(SPSR & (1<<SPIF)));
}

void MAX7219_set_intensity(uint8_t intensity){
	uint8_t j=matrices;
	do 
	{
		PORTB &= ~(1<<SS);
		MAX7219_send_end_(INTENSITY,intensity,j);
		for (int i = j-1; i > 0 ; i--)
			MAX7219_no_op();
		PORTB |= (1<<SS);
		j--;
	} while (j>0);
		
	
}

void MAX7219_decode_mode(uint8_t mode){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	MAX7219_send_end_(DECODE_MODE,mode,j);
	for (int i = j-1; i > 0 ; i--)
	{
		MAX7219_no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219_scan_limit(uint8_t limit){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	MAX7219_send_end_(SCAN_LIMIT,limit,j);
	for (int i = j; i > 0 ; i--)
	{
		MAX7219_no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219_display_test(uint8_t test){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	MAX7219_send_end_(DISPLAY_TEST,test,j);
	for (int i = j-1; i > 0 ; i--)
	{
		MAX7219_no_op();
	}
	PORTB |= (1<<SS);
	j--;
} while (j>0);
}

void MAX7219_shutdown(uint8_t shutdown_mode){
	uint8_t j=matrices;
	do
	{
	PORTB &= ~(1<<SS);
	MAX7219_send_end_(SHUTDOWN,shutdown_mode,j);
	for (int i = j-1; i > 0 ; i--)
	{
		MAX7219_no_op();
	}
	PORTB |= (1<<SS);
		j--;
	} while (j>0);
}

void MAX7219_no_op(){
	//PORTB &= ~(1<<SS);
	SPDR = NO_OP;
	MAX7219_wait_end_transmit();
	SPDR = NO_OP;
	MAX7219_wait_end_transmit();
}





