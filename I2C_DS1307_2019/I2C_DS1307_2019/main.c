/*
 * I2C_DS1307_2019.c
 *
 * Created: 20/06/19 04:16:09 p. m.
 * Author : jimmy
 */ 
#define F_CPU 8000000UL
#define FOSC 8e6 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "i2c_master.h"

#define DS1307_ADDRS 0xD0
uint8_t datos[8] = {0x00,0x26,0x59,0x23,0x04,0x31,0x12,0x99},d[8];



void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);
	}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
char palabra[40];
int main(void)
{
	USART_Init(MYUBRR);
	/*i2c_init();*/

	
	
	i2c_transmit(DS1307_ADDRS,datos,8);
	
	d[0]=0x00;
	
	i2c_transmit(DS1307_ADDRS,&d[0],1);
	i2c_receive(DS1307_ADDRS,&d[1],7);
	
	sprintf(palabra,"S%x M%x H%x D%x F%x m%x A%x\n\r",d[1],d[2],d[3],d[4],d[5],d[6],d[7]);
	for (int i = 0; i<sizeof(palabra);i++)
	{
		USART_Transmit(palabra[i]);
	}
	
	_delay_ms(5000);
	i2c_transmit(DS1307_ADDRS,&d[0],1);
	i2c_receive(DS1307_ADDRS,&d[1],7);
	
	sprintf(palabra,"%x %x %x %x %x %x %x\n\r",d[1],d[2],d[3],d[4],d[5],d[6],d[7]);
	for (int i = 0; i<sizeof(palabra);i++)
	{
		USART_Transmit(palabra[i]);
	}
	
	i2c_transmit(DS1307_ADDRS,datos,8);
	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

