/*
 * LED.h
 *
 * Created: 10/6/2022 8:27:49 PM
 *  Author: Peter
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/DIO.h"

void LED_init (uint8_t ledPort, uint8_t ledPin);

void LED_ON (uint8_t ledPort, uint8_t ledPin);

void LED_OFF (uint8_t ledPort, uint8_t ledPin);

void LED_Toggle (uint8_t ledPort, uint8_t ledPin);

#endif /* LED_H_ */