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
inline void set_bit(u8_t reg_addr, u8_t bit_num){reg_addr |= (1 << bit_num);}
inline void clr_bit(u8_t reg_addr, u8_t bit_num){reg_addr &= ~(1 << bit_num);}
inline void tog_bit(u8_t reg_addr, u8_t bit_num){reg_addr ^= (1 << bit_num);}

inline u8_t bit_is_set(u8_t reg_addr, u8_t bit_num){return reg_addr & (1 << bit_num);}
inline u8_t bit_is_clr(u8_t reg_addr, u8_t bit_num){return !(reg_addr & (1 << bit_num));}

#define ALL_INPUT    0x00
#define ALL_OUTPUT   0xFF
#define ALL_PORT_ON  0xFF
#define ALL_PORT_OFF 0x00

#define HIGH 1
#define LOW  0

#define ON  1
#define OFF 0
/*************************************************************************/
#endif /* STANDARDTYPES_H_ */