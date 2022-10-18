/*
 * LED.c
 *
 * Created: 10/6/2022 8:28:01 PM
 *  Author: Peter
 */ 

#include "LED.h"

void LED_init (uint8_t ledPort, uint8_t ledPin)
{
	 DIO_init(ledPort, ledPin, OUT);
}

void LED_ON (uint8_t ledPort, uint8_t ledPin)
{
	 DIO_write(ledPort, ledPin, HIGH);
}

void LED_OFF (uint8_t ledPort, uint8_t ledPin)
{
	 DIO_write(ledPort, ledPin, LOW);
}

void LED_Toggle (uint8_t ledPort, uint8_t ledPin)
{
	 DIO_toggle(ledPort,ledPin);
}

