/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** port.c
***************************************************************************
**                              Includes                                 **
**************************************************************************/
#include "port.h"

/*************************************************************************/
/*                     Functions Implementation                          */
/*************************************************************************/

gpio_error_t mcal_port_init(uint8_t base, portState dir)
{
	gpio_error_t error = STATE_SUCCESS;

	if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
	{
		switch (dir)
		{
			case DIR_PORT_OUTPUT:
			reg_write(base + OFFSET_DIR, PORT_OUTPUT_DIR);
			break;

			case DIR_PORT_INPUT_PULLDOWN:
			reg_write(base + OFFSET_DIR, PORT_INPUT_DIR);
			reg_write(base + OFFSET_PORT, PORT_OFF);
			break;

			case DIR_PORT_INPUT_PULLUP:
			reg_write(base + OFFSET_DIR, PORT_INPUT_DIR);
			reg_write(base + OFFSET_PORT, PORT_ON);
			break;

			default:
			error = STATE_INVALID_DIR;
			break;
		}
	}
	else
	{
		error = STATE_INVALID_ADDR;
	}

	return error;
}

gpio_error_t mcal_port_write(uint8_t base, uint8_t value)
{
	gpio_error_t error = STATE_SUCCESS;

	if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
	{
		reg_write(base + OFFSET_PORT, value);
	}
	else
	{
		error = STATE_INVALID_ADDR;
	}

	return error;
}

gpio_error_t mcal_port_read(uint8_t base, uint8_t *value)
{
	gpio_error_t error = STATE_SUCCESS;

	if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
	{
		reg_read(base + OFFSET_PIN, &value);
	}
	else
	{
		error = STATE_INVALID_ADDR;
	}
	return error;
}