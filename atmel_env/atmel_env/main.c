/*************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** main.c
**************************************************************************/
/*                              Includes                                 */
/*************************************************************************/
#include "standardtypes.h"
#include "app_init.h"
#include "led.h"
/*************************************************************************/
/*                   Static Functions Prototype                          */
/**************************************************************************
** systemInit()
**
** parameters: void
** return    : void
***************************************************************************
** this function is used to initialize all the necessary sequence for app
**************************************************************************/
static void systemInit();


/** init_led()
**
** parameters: void
** return    : void
***************************************************************************
** this function is used to initialize all the necessary sequence for led
**************************************************************************/
static void init_led();

/*************************************************************************/
/*                        Global Declerations                            */
/*************************************************************************/
led_t red_led;


/*************************************************************************/
/*                             Application                               */
/*************************************************************************/
int main(void)
{
	systemInit();
	
	led_set_state(&red_led, ON);

	while(1) {}
		
	return 0;
}

/*************************************************************************/
/*                   Static Functions Implementations                    */
/*************************************************************************/
static void systemInit()
{
	init_led();
}

static void init_led()
{
	red_led.base_addr = BASE_C;
	red_led.pin_num = 0;
	red_led.wiring = CURRENT_SOURCING;
	led_init(&red_led);
}