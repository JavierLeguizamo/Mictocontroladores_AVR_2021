

#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

void portBMode(uint8_t mask);
void portBWrite(uint8_t out);
uint8_t portBRead();
void portBWriteBit(uint8_t bit);

#endif /* PORTS_H_ */