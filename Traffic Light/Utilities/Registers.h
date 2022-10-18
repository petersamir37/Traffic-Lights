/*
 * Registers.h
 *
 * Created: 10/6/2022 8:41:14 PM
 *  Author: Peter
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Types.h"

/************************************************************************/
/* DIO REGISTERS                                                        */
/************************************************************************/
//Port A

#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)


//Port B

#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//Port C

#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//Port D

#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


/************************************************************************/
/* TIMER 0 REGISTERS                                                    */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)	//timer mode
#define TCNT0  *((volatile uint8_t*)0x52)	//timer register
#define OCR0 *((volatile uint8_t*)0x5C)		//timer compare value
#define TIFR *((volatile uint8_t*)0x58)		//overflow flag counter


/************************************************************************/
/* EXTERNAL INTERRUPT REGISTERS                                         */
/************************************************************************/

#define GICR *((volatile uint8_t*)0x5B)		//for enabling specific external interrupt pin
#define GIFR *((volatile uint8_t*)0x5A)		//for detecting interrupt request from specific pin
#define MCUCR *((volatile uint8_t*)0x55)	//for int0 and int1 sense
#define MCUCSR *((volatile uint8_t*)0x54)	//for int2 sense


//Status register

#define SREG *((volatile uint8_t*)0x5F)


#endif /* REGISTERS_H_ */