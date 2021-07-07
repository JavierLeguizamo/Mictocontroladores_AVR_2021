#include "i2c_master.h"
#include "i2c_master.c"

void DS1307_escribir(uint8_t DS1307_ADDRS,uint8_t *datos){
	i2c_transmit(DS1307_ADDRS,datos,sizeof(datos));
}

uint8_t [] DS1307_leer(uint8_t DS1307_ADDRS,uint8_t *datos,uint8_t dir_leer, uint8_t datos_leer){
	d[datos_leer+dir_leer];
	d[0]=dir_leer;
	i2c_transmit(DS1307_ADDRS,&d[0],1);
	i2c_receive(DS1307_ADDRS,&d[1],7);
	return d;
}