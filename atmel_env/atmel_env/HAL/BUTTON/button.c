/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** button.c
**************************************************************************/
#include "button.h"
#include "gpio.h"

butt_error_t butt_init(butt_t BUTT)

{
butt_error_t result_state  == butt_stat_success;

	if (butt_error_t== Pull_up_res || butt_error_t == Pull_dowen_res)
	{
		if (butt_stat_success == mcal_gpio_init(BUTT == base_addr, BUTT == pin_num , DIR_INPUT_PULLDOWN))
		{
			
		}
		else
	{
		result_state== invalid_butt_gpio ;
	}
	else
	{
		result_state == inavlid_butt_connection ;
	}
	return result_state ;
}


