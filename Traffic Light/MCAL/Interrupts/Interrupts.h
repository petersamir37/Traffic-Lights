/*
 * Interrupts.h
 *
 * Created: 10/6/2022 8:42:26 PM
 *  Author: Peter
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/Bit_manipulation.h"
#include "../../Utilities/Registers.h"

//define external interrupt request
 
#define EXT_int_0 __vector_1

//Set global interrupts

#define sei() SET_BIT(SREG,7)

//Clear global interrupts

#define cli() CLR_BIT(SREG,7)

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */