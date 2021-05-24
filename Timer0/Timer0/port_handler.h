/*
 * port_handler.h
 *
 * Created: 29/04/18 12:20:04 a. m.
 *  Author: jimmy
 */ 


#ifndef PORT_HANDLER_H_
#define PORT_HANDLER_H_

#include <avr/io.h>

typedef enum {
	B ,C ,D
}_PORT;

typedef enum{
	P0 = 1<<0,
	P1 = 1<<1,
	P2 = 1<<2,
	P3 = 1<<3,
	P4 = 1<<4,
	P5 = 1<<5,
	P6 = 1<<6,
	P7 = 1<<7
	
	} _PIN;	

#ifdef __cplusplus
extern "C"{
#endif
void port_b_set_out( unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
#endif
void port_b_set_in(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_b_set_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_b_clear_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_b_toggle_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_b_out(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_b_in();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_b_pin_in(_PIN);
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C"{
	#endif
void port_c_set_out( unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_c_set_in(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_c_set_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_c_clear_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_c_toggle_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_c_out(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_c_in();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_c_pin_in(_PIN);
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C"{
#endif
void port_d_set_out( unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
#endif
void port_d_set_in(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_d_set_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_d_clear_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_d_toggle_bit(_PIN);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
void port_d_out(unsigned char);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_d_in();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"{
	#endif
unsigned char port_d_pin_in(_PIN);
#ifdef __cplusplus
}
#endif



#ifdef __cplusplus
class PORT
{
	public:
	PORT(_PORT puerto,unsigned char mask);
	void setPin(_PIN pin);
	void clearPin(_PIN pin);
	void togglePin(_PIN pin);
	void out(unsigned char mask);
	unsigned char in();
	unsigned char pinIn(_PIN pin);
	
	protected:
	private:
	_PORT port;
	void setOut(_PORT puerto,unsigned char mask);
	void setIn(_PORT puerto,unsigned char mask);
	void setPin(_PORT puerto,_PIN pin);
	void clearPin(_PORT puerto,_PIN pin);
	void togglePin(_PORT puerto,_PIN pin);
	void out(_PORT puerto,unsigned char mask);
	unsigned char in(_PORT puerto);
	unsigned char pinIn(_PORT puerto,_PIN pin);
	
	
};

#endif


#endif /* PORT_HANDLER_H_ */