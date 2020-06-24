/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** GPIO.h
**************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

void GPIO_Read(int IP_REG, int IP_PIN,int Status);
void GPIO_Write(int OP_REG,int OP_PIN,int Status);


#endif /* GPIO_H_ */