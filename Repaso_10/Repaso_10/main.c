#define F_CPU 8e6
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
void portC_OutputMode(uint8_t pinMask)
{
	DDRC |= pinMask;
}
void portC_InputMode(uint8_t pinMask)
{
	DDRC &= ~(pinMask);
}

 void portB_Output(uint8_t output)
{
	PORTB = output;
}
void portC_Output(uint8_t output)
{
	PORTC = output;
}

void setup()
{
	portB_OutputMode(0xFF);
	portC_OutputMode(0x0f);
}


int main(void)
{
	uint8_t number[]={ZERO,ONE,TWO,THREE,FOUR,FIVE};
	
    setup();
	portC_Output(0xf);
    while (1) 
    {
		portC_Output(0xf);
		portB_Output(number[0]);
		PORTC = ~1;//~0b00000001 -> 0b11111110
		//_delay_ms(60);
		portB_Output(number[1]);
		PORTC = ~2;
		//_delay_ms(60);
		portB_Output(number[2]);
		PORTC = ~4;
		//_delay_ms(60);
		portB_Output(number[3]);
		PORTC = ~8;
		//_delay_ms(60);
	}
		
		
		
}

