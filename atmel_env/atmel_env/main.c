

#include <avr/io.h>
#include <util/delay.h>

#define SET_BET(REG,BIT) (REG |=(1<<BIT))
#define BIT_IS_SET(REG,BIT) (REG & ((1<<BIT)!=0))
#define CLEAR_BIT(REG,BIT) (REG &= (~(1<<BIT)))

int main(void)
{
    DDRC = 1 << PC0; 
    while (1) 
    {
		if (BIT_IS_SET(PORTC,PC1))
		{
			SET_BET(PORTC,PC0);
		}
		else
		{
			CLEAR_BIT(PORTC,PC0);
		}

    }
	return(0);
}

