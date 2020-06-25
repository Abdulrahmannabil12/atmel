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

typedef enum butt_connected{
	Pull_up_res,
	Pull_dowen_res
	}butt_connected_t;

typedef enum butt_error{
	butt_stat_success,
	inavlid_butt_connection,
	invalid_butt_gpio
	}butt_error_t;

typedef struct butt {
	u8_t base_addr;
	u8_t pin_num;
	butt_connected_t wiring;
	
} butt_t;


butt_error_t butt_init(butt_t BUTT);

butt_error_t butt_set_state(butt_t BUTT, u8_t value);

butt_error_t butt_get_state(butt_t BUTT, u8_t* value);



#endif /*_BUTTON_H_*/