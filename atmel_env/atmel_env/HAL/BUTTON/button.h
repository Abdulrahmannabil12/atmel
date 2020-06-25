/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** button.h
**************************************************************************/
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "standardTypes.h"
#include "gpio.h"

typedef enum  {
	PULLUP_CONNECTION,
	PULLDOWN_CONNECTION
} buttonConnection_t;

typedef enum  {
	BUTTON_STATE_SUCCESS,
	BUTTON_STATE_INVALID_CONNECTION,
	BUTTON_GPIO_ERROR
} button_error_t;

typedef enum {
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
} button_states_t;

typedef struct button {
	u8_t base_addr;
	u8_t pin_num;
	buttonConnection_t connection;
} button_t;

button_error_t hal_button_init(button_t* the_button);

button_error_t hal_button_get_state(button_t* the_button, button_states_t* result);

#endif /*_BUTTON_H_*/