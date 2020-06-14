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

typedef unsigned char         u8_t;   // Define unsigned char as U8_t
typedef char                  s8_t;   // Define  char as S8_t

typedef unsigned short       u16_t;   // Define unsigned short as U16_t
typedef short                s16_t;   // Define  short as S16_t

typedef unsigned long        u32_t;   // Define unsigned long as U32_t
typedef long                 s32_t;   // Define  long as S32_t

typedef unsigned long long   u64_t;   // Define unsigned long long U64_t
typedef long long            s64_t;   // Define  long long as S64_t

/*************************************************************************/
/*                          Common Macros                                */  
/*************************************************************************/
#define SET_BIT(REG,BIT) (REG |=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG &= (~(1<<BIT)))
#define TOG_BIT(REG,BIT) (REG ^=(1<<BIT))


#define BIT_IS_SET(REG,BIT) (REG & ((1<<BIT)))
#define BIT_IS_CLEAR(REG,BIT) !((REG & ((1<<BIT))))

#define ALL_INPUT    0x00
#define ALL_OUTPUT   0xFF
#define ALL_PORT_ON  0xFF
#define ALL_PORT_OFF 0x00
/*************************************************************************/
#endif /* STANDARDTYPES_H_ */