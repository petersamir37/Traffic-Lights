/*
 * Button.h
 *
 * Created: 10/6/2022 8:38:18 PM
 *  Author: Peter
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/DIO.h"

void button_init(uint8_t buttonPort, uint8_t buttonPin);

void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonvalue);


#endif /* BUTTON_H_ */