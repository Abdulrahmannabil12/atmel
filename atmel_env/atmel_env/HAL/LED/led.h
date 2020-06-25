/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** led.h
**************************************************************************/
#ifndef _LED_H_
#define _LED_H_

#include "standardTypes.h"
#include "gpio.h"

typedef enum  {
	CURRENT_SOURCING,
	CURRENT_SINKING
} current_t;

typedef enum  {
	LED_STATE_SUCCESS,
	LED_STATE_INVALID_CURRENT,
	LED_GPIO_ERROR
} led_error_t;

typedef struct  {
	u8_t base_addr;
	u8_t pin_num;
	current_t wiring;
} led_t;


led_error_t hal_led_init(led_t* the_led);

led_error_t hal_led_set_state(led_t* the_led, u8_t value);

led_error_t hal_led_get_state(led_t* the_led, u8_t* value);


#endif /*_LED_H_*/