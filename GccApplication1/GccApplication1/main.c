#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

#define TIME 250
#define READ_PORT_MASK(PORT,MASK) PORT & (MASK)
#define PORT_OUTPUT_MODE(PORT,MASK) PORT |= MASK
#define PORT_INPUT_MODE(PORT,MASK) PORT &= ~MASK
#define PORT_C_MODE DDRC
#define PORT_D_MODE DDRD
#define PORT_OUT PORTD
#define INPUT_PORT_C PINC
#define ALL_BITS_OUTPUTS 0XFF
#define INPUT_BITS (_BV(DDC0)|_BV(DDC1))
#define START_BUTTON _BV(DDC0)
#define POLARITY_BUTTON _BV(DDC1)
#define END_FORWARD_TRUE PORT_OUT == 128 || PORT_OUT == 127
#define END_BACKWARD_TRUE PORT_OUT == 1 || PORT_OUT == 254
#define START_FORWARD (_BV(PORTD0))
#define START_BACKWARD (_BV(PORTD7))
#define FORWARD 0
#define BACKWARD 1
#define OFF 0
#define ON 1
#define PORT_SHIFT_LEFT(POLARITY)
#define PORT_SHIFT_RIGHT(POLARITY)
#define READ_BIT_IS_TRUE(BIT) INPUT_PORT_C & (BIT)

void setup(void);
void waitStartButton(void);
void waitReleaseButton(void);
void readPolarityButton(unsigned char *);
unsigned char portShiftLeft(unsigned char *);
unsigned char portShiftRight(unsigned char *);
void rotation(unsigned char *, unsigned char *);

int main() {
	unsigned char direction = FORWARD, polarity = OFF;
	setup();
	waitStartButton();
	PORT_OUT = START_FORWARD;
	while(1){
		readPolarityButton(&polarity);
		rotation(&direction,&polarity);
		_delay_ms(TIME);
	}
	return 0;
}

void setup(){
	PORT_OUTPUT_MODE(PORT_D_MODE,ALL_BITS_OUTPUTS);
	PORT_INPUT_MODE(PORT_C_MODE,INPUT_BITS);
}
void waitStartButton(){
	while(!(READ_BIT_IS_TRUE(START_BUTTON)));
}
void waitReleaseButton(){
	while(READ_BIT_IS_TRUE(POLARITY_BUTTON));
}
void readPolarityButton(unsigned char *polarity){
	if(READ_BIT_IS_TRUE(POLARITY_BUTTON)){
		waitReleaseButton();
		PORT_OUT = ~PORT_OUT;
		*polarity ^= _BV(0);
		_delay_ms(TIME);
	}
}
unsigned char portShiftLeft(unsigned char *polarity){
	return PORT_OUT<<1 | ((*polarity==OFF)?0:(_BV(0)));
}
unsigned char portShiftRight(unsigned char *polarity){
	return PORT_OUT>>1 | ((*polarity==OFF)?0:(_BV(7)));
}
void rotation(unsigned char *direction, unsigned char *polarity){
	*direction = (END_FORWARD_TRUE)?
	BACKWARD:
	(END_BACKWARD_TRUE)?
	FORWARD:
	*direction;
	PORT_OUT = (*direction == FORWARD)?
	portShiftLeft(polarity):
	portShiftRight(polarity);
}

