/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** GPIO.h
**************************************************************************/
#ifndef PORT_H_
#define PORT_H_


/*************************************************************************/
/*                              Includes                                 */
/*************************************************************************/
#include "standardTypes.h"
#include "gpio.h"
/*************************************************************************/
/*                              Macros                                   */
/*************************************************************************/

#define PORT_ON 0xFF
#define PORT_OFF 0x00
#define PORT_OUTPUT_DIR 0xFF
#define PORT_INPUT_DIR 0x00

/*************************************************************************/
/*                               Types                                   */
/*************************************************************************/
typedef enum
{
	DIR_PORT_INPUT_PULLUP,
	DIR_PORT_INPUT_PULLDOWN,
	DIR_PORT_OUTPUT
} portState;

typedef enum port_error
{
	STATE_PORT_SUCCESS,
	STATE_ERROR,

} port_error_t;

/**************************************************************************
** mcal_port_init()
**
** parameters: uint8_t base
** parameters: portState dir
** return    : gpio_error_t
***************************************************************************
** this function is used to initialize all the necessary sequence for port
**************************************************************************/
gpio_error_t mcal_port_init(uint8_t base, portState dir);

/**************************************************************************
** mcal_port_write()
**
** parameters: uint8_t base
** parameters: uint8_t value
** return    : gpio_error_t
***************************************************************************
** this function is used to write a value to all port
**************************************************************************/
gpio_error_t mcal_port_write(uint8_t base, uint8_t value);

/**************************************************************************
** mcal_port_read()
**
** parameters: uint8_t base
** parameters: uint8_t* value
** return    : gpio_error_t
***************************************************************************
** this function is used to read a value from all port
**************************************************************************/
gpio_error_t mcal_port_read(uint8_t base, uint8_t *value);



#endif /* PORT_H_ */