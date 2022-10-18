/*
 * Bit_manipulation.h
 *
 * Created: 10/6/2022 8:41:29 PM
 *  Author: Peter
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(x,BIT_NO) x |= (1<<BIT_NO)
#define CLR_BIT(x,BIT_NO) x &= ~(1<<BIT_NO)
#define TOGGLE_BIT(x,BIT_NO) x ^= (1<<BIT_NO)
#define READ_BIT(x,BIT_NO) (x&(1<<BIT_NO))>>BIT_NO


#endif /* BIT_MANIPULATION_H_ */