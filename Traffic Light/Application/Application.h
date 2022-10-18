/*
 * Application.h
 *
 * Created: 10/6/2022 8:37:03 PM
 *  Author: Peter
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED Driver/LED.h"
#include "../ECUAL/Button Driver/Button.h"
#include "../MCAL/Interrupts/Interrupts.h"

void APP_init(void);

void APP_start(void);

void wait5S(void);

void blinkwait(uint8_t port1, uint8_t pin1, uint8_t port2, uint8_t pin2);


#endif /* APPLICATION_H_ */