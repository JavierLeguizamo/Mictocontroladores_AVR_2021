#ifndef __MAX7219_DEF_H_INCLUDED__
#define __MAX7219_DEF_H_INCLUDED__
#endif
#include <avr/io.h>

/************************************************************************/
/*                 BIBLIOTECA MAX7219  DEFINICIONES                     */
/************************************************************************/
#define NO_OP			0x00
#define DIGIT_0			0x01
#define DIGIT_1			0x02
#define DIGIT_2			0x03
#define DIGIT_3			0x04
#define DIGIT_4			0x05
#define DIGIT_5			0x06
#define DIGIT_6			0x07
#define DIGIT_7			0x08

#ifdef __cplusplus
extern "C" {
#endif 
const uint8_t DIGIT[] ={DIGIT_0,
						DIGIT_1,
						DIGIT_2,
						DIGIT_3,
						DIGIT_4,
						DIGIT_5,
						DIGIT_6,
						DIGIT_7};
#ifdef __cplusplus
}
#endif

#define DECODE_MODE		0x09
#define INTENSITY		0x0A
#define SCAN_LIMIT		0x0B
#define SHUTDOWN		0x0C
#define DISPLAY_TEST	0x0F

#define SHUTDOWN_MODE	0x00
#define NORMAL_MODE		0x01
#define NO_DECODE		0x00
#define CODE_B_0		0x01
#define CODE_B_3_0		0x0F
#define CODE_B_7_0		0xFF

#define CHAR_0			0x00
#define CHAR_1			0x01
#define CHAR_2			0x02
#define CHAR_3			0x03
#define CHAR_4			0x04
#define CHAR_5			0x05
#define CHAR_6			0x06
#define CHAR_7			0x07
#define CHAR_8			0x08
#define CHAR_9			0x09
#define CHAR_LINE		0x0A
#define CHAR_E			0x0B
#define CHAR_H			0x0C
#define CHAR_L			0x0D
#define CHAR_P			0x0E
#define CHAR_BLANK		0x0F

#define INTENSITY_1_32	0x00
#define INTENSITY_3_32	0x01
#define INTENSITY_5_32	0x02
#define INTENSITY_7_32	0x03
#define INTENSITY_9_32	0x04
#define INTENSITY_11_32 0x05
#define INTENSITY_13_32 0x06
#define INTENSITY_15_32 0x07
#define INTENSITY_17_32 0x08
#define INTENSITY_19_32 0x09
#define INTENSITY_21_32 0x0A
#define INTENSITY_23_32 0x0B
#define INTENSITY_25_32 0x0C
#define INTENSITY_27_32 0x0D
#define INTENSITY_29_32 0x0E
#define INTENSITY_31_32 0x0F

#define DISPLAY_ONE_DIGIT	0x00
#define DISPLAY_TWO_DIGIT	0x01
#define DISPLAY_THREE_DIGIT 0x02
#define DISPLAY_FOUR_DIGIT	0x03
#define DISPLAY_FIVE_DIGIT	0x04
#define DISPLAY_SIX_DIGIT	0x05
#define DISPLAY_SEVEN_DIGIT 0x06
#define DISPLAY_EIGHT_DIGIT 0x07

#define NORMAL_OPERATION	0x00
#define DISPLAY_TEST_MODE	0x01

/************************************************************************/
/*                      Pin Definitions                                 */
/************************************************************************/

#define SS		PB2
#define MOSI	PB3
#define MISO	PB4
#define SCK		PB5

/************************************************************************/
/*                      Class Definition                                */
/************************************************************************/
class MAX7219 {
	public:
	MAX7219();
	void init(uint8_t no_matrices);
	void send_end(uint8_t addrs, uint8_t data);
	void send_data(uint8_t addrs, uint8_t *data, uint8_t matrix);
	void send_16bits(uint16_t data);
	void set_intensity(uint8_t intensity);
	void decode_mode(uint8_t mode);
	void shutdown(uint8_t shutdown_mode);
	void scan_limit(uint8_t limit);
	void display_test(uint8_t test);
	void no_op();
	void send_end_(uint8_t addres, uint8_t data, uint8_t matriz);
	void send_char(uint8_t *data, uint8_t matriz);
	void send_text(uint8_t **data, uint8_t no_matrices);
	void limpiar_matriz(uint8_t no_matrices);
	void limpiar_todo();
	private:
	void wait_end_transmit();
	uint8_t matrices;
	
};

