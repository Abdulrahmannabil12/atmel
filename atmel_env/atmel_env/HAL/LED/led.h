/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** led.h
**************************************************************************/
#ifndef _LED_H_
#define _LED_H_

/*************************************************************************/
/*                              Includes                                 */
/*************************************************************************/
#include "standardTypes.h"
#include "gpio.h"

/*************************************************************************/
/*                                 Types                                 */
/*************************************************************************/
typedef enum
{
	CURRENT_SOURCING,
	CURRENT_SINKING
} current_t;

typedef enum
{
	LED_STATE_SUCCESS,
	LED_STATE_INVALID_CURRENT,
	LED_GPIO_ERROR
} led_error_t;

typedef struct
{
	uint8_t base_addr;
	uint8_t pin_num;
	current_t wiring;
} led_t;

/*************************************************************************/
/*                           Public Functions                            */
/**************************************************************************
** hal_led_init()
**
** parameters: led_t* the_led
** return    : led_error_t
***************************************************************************
** this function is used to initialize all the necessary sequence for LED
**************************************************************************/
led_error_t hal_led_init(led_t *the_led);

/**************************************************************************
** hal_led_set_state()
**
** parameters: led_t* the_led
** parameters: uint8_t value
** return    : led_error_t
***************************************************************************
** this function set the states of the LED on or off
**************************************************************************/
led_error_t hal_led_set_state(led_t *the_led, uint8_t value);

/**************************************************************************
** hal_led_get_state()
**
** parameters: led_t* the_led
** parameters: uint8_t* value
** return    : led_error_t
***************************************************************************
** this function get the states of the LED on or off
**************************************************************************/
led_error_t hal_led_get_state(led_t *the_led, uint8_t *value);

#endif /*_LED_H_*/
/**************************************************************************/
