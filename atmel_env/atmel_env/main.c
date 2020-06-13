

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(REG,BIT) (REG |=(1<<BIT))
#define BIT_IS_SET(REG,BIT) (REG & ((1<<BIT)))
#define CLEAR_BIT(REG,BIT) (REG &= (~(1<<BIT)))

int main(void)
{
    DDRC = 1 << PC0; 
	DDRC = 1 << PC7;
    while (1) 
    {
		if (BIT_IS_SET(PINB,PB0))
		{
			SET_BIT(PORTC,PC0);
		}
		else
		{
			CLEAR_BIT(PORTC,PC0);
		}
        if (BIT_IS_SET(PINB,PB7))
          {
             SET_BIT(PORTC,PC7);   
		   } 
        
        else
        {
			CLEAR_BIT(PORTC,PC7);
        }
    }
	return(0);
}

