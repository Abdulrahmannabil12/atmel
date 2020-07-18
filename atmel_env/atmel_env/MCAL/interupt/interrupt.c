/*
 * interrupt.c
 *
 * Created: 7/17/2020 3:22:02 AM
 *  Author: Abdulrahman Nabil
 */
#include "interrupt.h"

interrupt_error MCAL_interrupt_initialize(
	interrupt_t INT_X,
	interrupt_t the_mode)
{

	/* set_bit(SREG,SREG_interrupt_bit);       */ /*enable interrupt*/
	interrupt_error error = INTERRUPT_STATE_SUCCESS;

	switch (INT_X)
	{

	case (INT_X->bit == INT0):

		switch (the_mode)
		{
		case (the_mode->mode == falling_edge):
			set_bit(MCUCR, ISC01);
			clr_bit(MCUCR, ISC00);
			break;
		case (the_mode->mode == rising_edge):
			set_bit(MCUCR, ISC00);
			set_bit(MCUCR, ISC01);
			break;
		case (the_mode->mode == changing_edge):
			set_bit(MCUCR, ISC00);
			clr_bit(MCUCR, ISC01);
			break;
		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;

	case (INT_X->bit == INT1):
		switch (the_mode)
		{
		case (the_mode->mode == falling_edge):
			set_bit(MCUCR, ISC11);
			clr_bit(MCUCR, ISC10);
			break;
		case (the_mode->mode == rising_edge):
			set_bit(MCUCR, ISC11);
			set_bit(MCUCR, ISC10);
			break;
		case (the_mode->mode == changing_edge):
			set_bit(MCUCR, ISC10);
			clr_bit(MCUCR, ISC11);
			break;

		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
	case (INT_X->bit == INT2):
		switch (the_mode)
		{
		case (the_mode->mode == falling_edge):
			clr_bit(MCUCSR, ISC2);
			break;
		case (the_mode->mode == rising_edge):
			set_bit(MCUCR, ISC2);
			break;
		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
	default:
		error = INTERRUPT_STATE_INVAILD_external_interrupt;
	}
}

interrupt_error MCAL_interrupt_read(uint8_t *result, interrupt_flag *INTF_X)
{
	interrupt_error error = INTERRUPT_STATE_SUCCESS;
	uint8_t value;

	if (INTF_X->GIFR_bit == INTF0)
	{
		*result = value;
	}
	else if (INTF_X->GIFR_bit == INTF1)
	{
		*result = !value;
	}
	/*	 else if (INTF_X->GIFR_bit == INTF1)
		 { 
			 
		 }  */
	else
	{
		error = INTERRUPT_STATE_INVAILD_external_interrupt;
	}
	return error;
}
}
