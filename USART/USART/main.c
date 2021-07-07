
#define F_CPU 8e6
#include <avr/io.h>

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
int main(void)
{
    /* Replace with your application code */
	USART_Init(51);
	USART_Transmit( 'H' );
	USART_Transmit( 'o' );
	USART_Transmit( 'l' );
	USART_Transmit( 'a' );
    while (1) 
    {
		uint8_t data_recived = USART_Receive();
    }
}

void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (3<<UCSZ00);
	}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}