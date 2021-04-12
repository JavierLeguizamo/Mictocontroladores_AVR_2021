#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>
#define ZERO 63
#define ONE 6
#define TWO 0X5B
#define THREE 0X4F
#define FOUR 0x66
#define FIVE 0x77


void portB_OutputMode(uint8_t pinMask)
{
	DDRB |= pinMask;
}

void portC_InputMode(uint8_t pinMask)
{
	DDRC &= ~(pinMask);
}

void setup()
{
	portB_OutputMode(0xFF);
	portC_InputMode(1<<DDC0 | 1<<DDC1);
}

 void portB_Output(uint8_t output)
{
	PORTB = output;
}

void displayNumber(uint8_t  number[6])
{
	for (int i=0; i<=5;i++)
	{
		portB_Output(number[i]);
		_delay_ms(250);
	}
}

int main(void)
{
	uint8_t number[]={ZERO,ONE,TWO,THREE,FOUR,FIVE};
    setup();

    while (1) 
    {
		while((PINC&(1<<DDC0))==1){
			displayNumber(number);
		}
    }
}

