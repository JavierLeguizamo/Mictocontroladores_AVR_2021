
#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>
#define DIRECCION_PB(x) DDRB |= x
#define DIRECCION_PD(x) DDRD |= x
#define ESCRIBIR_PB(X)  PORTB = X
#define ESCRIBIR_PD(X)  PORTD = X
#define TODOS_BITS_SALIDA 0xff

void setup(void);
void secuencia(void);

int main(void)
{
    setup();
    while (1) //loop()
    {
		secuencia();	
    }
}

void setup(){ 
	DIRECCION_PB(TODOS_BITS_SALIDA);//<-DDRB|=255
	DIRECCION_PD(TODOS_BITS_SALIDA);//<-DDRD|=255
	DDRB &= ~(1<<DDB0|1<<DDB5);
	
}
void secuencia(){
	for (int i=1; i<=256;i=i<<1) 
	{
		ESCRIBIR_PB(i);
		_delay_ms(250);
	}
	for (int i=1; i<=256;i=i<<1)
	{
		ESCRIBIR_PD(i);
		_delay_ms(250);
	}
}

// i=i<<1