/*************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** StandardTypes.h
**************************************************************************/
#ifndef STANDARDTYPES_H_
#define STANDARDTYPES_H_
/*************************************************************************/
/*                          standard types                               */
/*************************************************************************/

typedef unsigned char uint8_t; // Define unsigned char as uint8_t
typedef char sint8_t;          // Define  char as sint8_t

typedef unsigned short uint16_t; // Define unsigned short as uint16_t
typedef short sint16_t;          // Define  short as sint16_t

typedef unsigned long uint32_t; // Define unsigned long as uint32_t
typedef long sint32_t;          // Define  long as sint32_t

typedef unsigned long long uint64_t; // Define unsigned long long uint64_t
typedef long long sint64_t;          // Define  long long as sint64_t

/*************************************************************************/
/*                          Common Macros                                */
/*************************************************************************/

#define HIGH 1
#define LOW 0

#define ON 1
#define OFF 0

/*************************************************************************/
/*                      Register Access Functions Macros                 */
/*************************************************************************/

#define REGISTER (*((volatile uint8_t *)(uint16_t)reg_addr))

inline void set_bit(uint8_t reg_addr, uint8_t bit_num)
{
    REGISTER |= (1 << bit_num);
}
inline void clr_bit(uint8_t reg_addr, uint8_t bit_num)
{
    REGISTER &= ~(1 << bit_num);
}
inline void tog_bit(uint8_t reg_addr, uint8_t bit_num)
{
    REGISTER ^= (1 << bit_num);
}

inline void reg_write(uint8_t reg_addr, uint8_t value)
{
    REGISTER = value;
}
inline void reg_read(uint8_t reg_addr, uint8_t *value)
{
    *value = REGISTER;
}

inline uint8_t bit_is_set(uint8_t reg_addr, uint8_t bit_num)
{
    return (REGISTER & (1 << bit_num)) ? HIGH : LOW;
}
inline uint8_t bit_is_clr(uint8_t reg_addr, uint8_t bit_num)
{
    return (REGISTER & (1 << bit_num)) ? LOW : HIGH;
}

#endif /* STANDARDTYPES_H_ */
       /*************************************************************************/