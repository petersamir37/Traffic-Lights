/*
 * DIO.h
 *
 * Created: 10/6/2022 8:26:43 PM
 *  Author: Peter
 */ 


#ifndef DIO_H_
#define DIO_H_

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

#include "../../Utilities/Registers.h"
#include "../../Utilities/Bit_manipulation.h"

void DIO_init(uint8_t portName, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portName, uint8_t pinNumber, uint8_t value);
void DIO_toggle(uint8_t portName, uint8_t pinNumber);
void DIO_read(uint8_t portName, uint8_t pinNumber, uint8_t *value);
void errorhandler(EN_DIO_error_t error);

#endif /* DIO_H_ */