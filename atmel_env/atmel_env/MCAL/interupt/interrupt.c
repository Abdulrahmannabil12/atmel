<<<<<<< HEAD
/*
 * interrupt.c
 *
 * Created: 7/17/2020 3:22:02 AM
 *  Author: Abdulrahman Nabil
 */ 
#include "interrupt.h"

interrupt_error MCAL_interrupt_initialize(interrupt_t INT_X , interrupt_t the_mode){
	
	/* set_bit(SREG,SREG_interrupt_bit);       */                                               /*enable interrupt*/ 
	interrupt_error error = INTERRUPT_STATE_SUCCESS;
	
	switch (INT_X){
		
	  case (INT_X -> bit == INT0 ) :
		
		  switch (the_mode  )
		{
			case (the_mode -> mode == falling_edge)  :
			   set_bit(MCUCR , ISC01);
			   clr_bit(MCUCR , ISC00);
			   break;
			case (the_mode -> mode == rising_edge)   :
			   set_bit(MCUCR , ISC00);
			   set_bit(MCUCR , ISC01);
			   break;
			case (the_mode -> mode == changing_edge) :
			set_bit(MCUCR , ISC00);
			clr_bit(MCUCR , ISC01);
			break;
			default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
		
	  case (INT_X -> bit == INT1 ) :
	     switch(the_mode)
		 {
			 	case (the_mode -> mode == falling_edge)  :
			 	set_bit(MCUCR , ISC11);
			 	clr_bit(MCUCR , ISC10);
				 break;
			 	case (the_mode -> mode == rising_edge)   :
			 	set_bit(MCUCR , ISC11);
			 	set_bit(MCUCR , ISC10);
			 	break;
				 case (the_mode -> mode == changing_edge) :
			 	set_bit(MCUCR , ISC10);
			    clr_bit(MCUCR , ISC11);
				break;
				
				default:
				error = INTERRUPT_STATE_INVALID_OPERATION_MODE ;
				
		 }
		 break;
	   case (INT_X -> bit == INT2):
	    switch(the_mode)
		{
                case (the_mode -> mode == falling_edge)  :
                clr_bit(MCUCSR , ISC2);
				break;
                case (the_mode -> mode == rising_edge)   :
                set_bit(MCUCR , ISC2);
                break;
                default:
				error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
	
		}
	   break;
	   default:
	   error = INTERRUPT_STATE_INVAILD_external_interrupt;
	}
}


interrupt_error MCAL_interrupt_read(uint8_t *result ,interrupt_flag * INTF_X )
{
	interrupt_error error = INTERRUPT_STATE_SUCCESS ;
	uint8_t value ;
	
	if (INTF_X -> GIFR_bit == INTF0)
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
=======
/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** interrupt.c
***************************************************************************
**                              Includes                                 **
**************************************************************************/
#include "interrupt.h"

/*************************************************************************/
/*                     Functions Implementation                          */
/*************************************************************************/

interrupt_error mcal_interrupt_initialize(uint8_t interruptNo,
										  interrupt_mode_t mode)
{
	interrupt_error error = INTERRUPT_STATE_SUCCESS;

	/*enable global interrupts*/
	setGlobalInterrupt;

	switch (interruptNo)
	{

	case INT0:
	{
		switch (mode)
		{
		case RISING_EDGE:
			set_bit(MCUCR, ISC00);
			set_bit(MCUCR, ISC01);
			break;

		case FALLING_EDGE:
			set_bit(MCUCR, ISC01);
			clr_bit(MCUCR, ISC00);
			break;

		case CHANGING_EDGE:
			set_bit(MCUCR, ISC00);
			clr_bit(MCUCR, ISC01);
			break;

		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
	}

	case INT1:
	{
		switch (mode)
		{
		case RISING_EDGE:
			set_bit(MCUCR, ISC11);
			set_bit(MCUCR, ISC10);
			break;

		case FALLING_EDGE:
			set_bit(MCUCR, ISC11);
			clr_bit(MCUCR, ISC10);
			break;

		case CHANGING_EDGE:
			set_bit(MCUCR, ISC10);
			clr_bit(MCUCR, ISC11);
			break;

		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
	}

	case INT2:
	{
		switch (mode)
		{
		case RISING_EDGE:
			set_bit(MCUCR, ISC2);
			break;

		case FALLING_EDGE:
			clr_bit(MCUCSR, ISC2);
			break;

		default:
			error = INTERRUPT_STATE_INVALID_OPERATION_MODE;
		}
		break;
	}

	default:
	{
		error = INTERRUPT_STATE_INVAILD_INTERRUPT_NUMBER;
	}
	}
	return error;
}

interrupt_error mcal_interrupt_read_flag(uint8_t flag, uint8_t *result)
{
	interrupt_error error = INTERRUPT_STATE_SUCCESS;
	uint8_t value;

	switch (flag)
	{
	case INTF0:
		*result = bit_is_set(GIFR, INTF0);
		break;

	case INTF1:
		*result = bit_is_set(GIFR, INTF1);
		break;

	case INTF2:
		*result = bit_is_set(GIFR, INTF2);
		break;

	default:
		error = INTERRUPT_STATE_INVAILD_INTERRUPT_NUMBER;
		break;
	}
	return error;
}

interrupt_error mcal_interrupt_clear_flag(uint8_t flag)
{
	interrupt_error error = INTERRUPT_STATE_SUCCESS;
	uint8_t value;

	switch (flag)
	{
	case INTF0:
		clr_bit(GIFR, INTF0);
		break;

	case INTF1:
		clr_bit(GIFR, INTF1);
		break;

	case INTF2:
		clr_bit(GIFR, INTF2);
		break;

	default:
		error = INTERRUPT_STATE_INVAILD_INTERRUPT_NUMBER;
		break;
	}
	return error;
}
>>>>>>> c701280584a1083a8e9836eaa5c7b66d38ba1cdd
