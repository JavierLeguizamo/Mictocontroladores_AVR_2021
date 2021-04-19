#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>
#define ZERO 63
#define ONE 6
#define TWO 0X5B
#define THREE 0X4F
#define FOUR 0x66
#define FIVE 0x77
#define START_BUTTON PINC0
#define STOP_BUTTON PINC1
#define READ_BIT_PC(BIT) (PINC & (1<<BIT))

uint8_t encendido=0 , i=0;

void portB_OutputMode(uint8_t pinMask)
{
	DDRB |= pinMask;
}

void portC_InputMode(uint8_t pinMask)
{
	DDRC &= ~(pinMask);
}

 void portB_Output(uint8_t output)
{
	PORTB = output;
}

void setup()
{
	portB_OutputMode(0xFF);
	portC_InputMode(1<<DDC0 | 1<<DDC1);
}

void displayNumber(uint8_t  number[6])
{
	portB_Output(number[i]);
	i = (i>=5)? 0 : i+1;
	_delay_ms(250);
}

int main(void)
{
	uint8_t number[]={ZERO,ONE,TWO,THREE,FOUR,FIVE};
	
    setup();

    while (1) 
    {
		
		if (PINC == 65){
			encendido = 1;
		}
		else if(PINC == 66){
			encendido = 0;
			i=0;
		}
					
		if (encendido == 1)
		{
			displayNumber(number);
		} 
		else
		{
			portB_Output(0);
		}
    }
}

