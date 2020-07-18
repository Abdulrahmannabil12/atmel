<<<<<<< HEAD
/*
 * interrupt.h
 *
 * Created: 7/17/2020 3:21:49 AM
 *  Author: Abdulrahman Nabil
 */ 

#include "standardtypes.h"

#ifndef INTERRUPT_H_
#define INTERRUPT_H_




	/* define interrupt registers */
	#define SREG   0X5F
	#define GIFR   0x5A
	#define GICR   0x5B
	#define MCUCR  0x55
	#define MCUCSR 0x54
 
    /*enable and disable interrupt by setting and clearing I bit in SREG */

    #define SREG_interrupt_bit    7
    #define setGlobalInterrupt    set_bit(SREG,SREG_interrupt_bit)
    #define clearGlobalInterrupt  clr_bit( SREG, SREG_interrupt_bit )

	/*MCUCR (MCU Control Register)*/
	#define ISC00	0
	#define ISC01	1
	#define ISC10	2
	#define ISC11	3
	/*MCUCSR (MCU Control Register)*/
	#define ISC2	6
	
typedef enum {
	/* GICR choose External interrupt*/
	INT0 =6
	INT1 =7
	INT2 =5
	}external_interrupt;
	

typedef enum {
	/* GIFR READ General Interrupt Flag Register*/
	INTF0 =6
	INTF1 =7
	INTF2 =5

}interrupt_flag;

typedef enum {
    rising_edge ,
    falling_edge,
    changing_edge
	}operat_mode_t;


typedef enum {
		INTERRUPT_STATE_SUCCESS,

		INTERRUPT_STATE_INVALID_OPERATION_MODE,

		INTERRUPT_STATE_INVAILD_external_interrupt,
	
	}interrupt_error;
	
	typedef struct{
		
	interrupt_flag GIFR_bit;
	external_interrupt bit;
	operat_mode_t mode;
    } interrupt_t;
	/*************************************************************************/
	/*                           Public Functions                            */
	/**************************************************************************
	** MCAL_interrupt_initialize( ,)
	**
	** parameters: interrupt_t INT_X
	** parameters: interrupt_t the_mode
	** return    : interrupt_error
	***************************************************************************
	** this function is used to initialize all the necessary sequence for interrupt
	**************************************************************************/
	interrupt_error MCAL_interrupt_initialize( interrupt_t INT_X,interrupt_t the_mode);
	/**************************************************************************
	** MCAL_interrupt_read(,)
	**
	** parameters: uint8_t  *result 
	** parameters: interrupt_flag *INTF_X 
	** return    : interrupt_error
	***************************************************************************
	** this function is used read a value from GIFR register
	**************************************************************************/
	interrupt_error MCAL_interrupt_read(uint8_t *result ,interrupt_flag *INTF_X );
	
#endif /* INTERRUPT_H_ */
=======
/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** interrupt.h
**************************************************************************/
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*************************************************************************/
/*                              Includes                                 */
/*************************************************************************/
#include "standardtypes.h"

/*************************************************************************/
/*                              Macros                                   */
/*************************************************************************/

/*enable and disable interrupt by setting and clearing I bit in SREG */
#define SREG_interrupt_bit 7
#define setGlobalInterrupt set_bit(SREG, SREG_interrupt_bit)
#define clearGlobalInterrupt clr_bit(SREG, SREG_interrupt_bit)

/* define interrupt registers */
#define SREG 0X5F
#define GIFR 0x5A
#define GICR 0x5B
#define MCUCR 0x55
#define MCUCSR 0x54

/*MCUCR (MCU Control Register)*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6

/*Interrupts Number*/
#define INT0 6
#define INT1 7
#define INT2 5

/*Interrupts Flags*/
#define INTF0 6
#define INTF1 7
#define INTF2 5

/*************************************************************************/
/*                               Types                                   */
/*************************************************************************/

typedef enum
{
	RISING_EDGE,
	FALLING_EDGE,
	CHANGING_EDGE
} interrupt_mode_t;

typedef enum
{
	INTERRUPT_STATE_SUCCESS,
	INTERRUPT_STATE_INVALID_OPERATION_MODE,
	INTERRUPT_STATE_INVAILD_INTERRUPT_NUMBER
} interrupt_error;

/*************************************************************************/
/*                           Public Functions                            */
/**************************************************************************
** mcal_interrupt_initialize()
**
** parameters: uint8_t interruptNo
** parameters: interrupt_mode_t mode
** return    : interrupt_error
***************************************************************************
** this function is used to initialize all the necessary sequence for interrupt
**************************************************************************/
interrupt_error mcal_interrupt_initialize(uint8_t interruptNo,
										  interrupt_mode_t mode);
/**************************************************************************
** mcal_interrupt_read_flag()
**
** parameters: uint8_t flag
** parameters: uint8_t *result
** return    : interrupt_error
***************************************************************************
** this function is used read a interrupts flags from GIFR register
**************************************************************************/
interrupt_error mcal_interrupt_read_flag(uint8_t flag , uint8_t *result);

/**************************************************************************
** mcal_interrupt_clear_flag()
**
** parameters: uint8_t flag
** return    : interrupt_error
***************************************************************************
** this function is used to clear flag from GIFR register
**************************************************************************/
interrupt_error mcal_interrupt_clear_flag(uint8_t flag);

#endif /* INTERRUPT_H_ */
>>>>>>> c701280584a1083a8e9836eaa5c7b66d38ba1cdd
