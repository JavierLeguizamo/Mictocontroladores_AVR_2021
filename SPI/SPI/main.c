

#include <avr/io.h>

#define MISO	PORTB4
#define MOSI	PORTB3
#define SCK		PORTB5
#define SS		PORTB2
#define DDR_SPI DDRB

#define DECODE_MODE		0x09
#define INTENSITY		0x0A
#define SCAN_LIMIT		0x0B
#define SHUTDOWN		0x0C

#define DIGIT_0			0x01
#define DIGIT_1			0x02

int main(void)
{
    DDR_SPI |= 1<<MOSI | 1<<SCK |1<<SS;
	SPCR |= 1<<SPE | 1<<MSTR;// Habilitar SPI | Confugurarlo como Maestro
	//SPSR |= 1<<SPI2X;//Preescaler 2
	
	/************************************************************************/
	/* Configuracion MAX7219                                                */
	/************************************************************************/
	PORTB &= ~(1<<SS);
	SPDR = SHUTDOWN;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x01;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
	PORTB &= ~(1<<SS);
	SPDR = DECODE_MODE;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x0F;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
	PORTB &= ~(1<<SS);
	SPDR = INTENSITY;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x0F;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
	PORTB &= ~(1<<SS);
	SPDR = SCAN_LIMIT;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x01;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
	PORTB &= ~(1<<SS);
	
	/************************************************************************/
	/* Digitos                                                              */
	/************************************************************************/
	SPDR = DIGIT_0;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x05;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
	PORTB &= ~(1<<SS);
	SPDR = DIGIT_1	;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0x07;
	while(!(SPSR & (1<<SPIF)));
	PORTB |= 1<<SS;
    while (1) 
    {
    }
}

