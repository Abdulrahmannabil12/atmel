/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** GPIO.h
**************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "standardTypes.h"

#define BASE_A 0x39
#define BASE_B 0x36
#define BASE_C 0x33
#define BASE_D 0x30

#define OFFSET_PIN 0x00
#define OFFSET_DIR 0x01
#define OFFSET_PORT 0x02

#define MAX_PIN_NUMBER 8

typedef enum
{
	DIR_INPUT_PULLUP,
	DIR_INPUT_PULLDOWN,
	DIR_OUTPUT
} pinState;

typedef enum gpio_error {
	STATE_SUCCESS,
	STATE_ERROR,
	STATE_INVALID_ADDR,
	STATE_INVAILD_PIN,
	STATE_INVALID_DIR,
	STATE_INVALID_VALUE
} gpio_error_t;

gpio_error_t mcal_gpio_init(u8_t base, u8_t pin, pinState dir);

gpio_error_t mcal_gpio_write(u8_t base, u8_t value);

gpio_error_t mcal_gpio_read(u8_t base, u8_t pin, u8_t* value);

#endif /* GPIO_H_ */