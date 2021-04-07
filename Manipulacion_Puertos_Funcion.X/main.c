/* 
 * File:   main.c
 * Author: javierleguizamo
 *
 * Created on 7 de abril de 2021, 07:47 AM
 */

#include <avr/io.h>

#define MODE_PB DDRB
#define MODE_PC DDRC
#define ALL_BIT_OUT 0xFF
#define ALL_BIT_ON 0xFF
#define START_BUTTON PINC2

void modePortB(uint8_t);
void writePortB(uint8_t);
void waitStartButton(uint8_t);

int main() {
    modePortB(ALL_BIT_OUT);
    waitStartButton(START_BUTTON);
    //1<<PINC0 -> 0b00000001
    //PINC = 0b00000101
    //MASK = 0b00000001
    //AND  = 0b00000001
    while(1){
        writePortB(ALL_BIT_ON);
    }
    return 0;
}

void modePortB(uint8_t mask){
    MODE_PB = mask;//pinMode
}
void writePortB(uint8_t out){
    PORTB = out;//digitalWrite
}
void waitStartButton(uint8_t start_button){
    while((PINC & (1<<start_button))==0);//digitalRead
}