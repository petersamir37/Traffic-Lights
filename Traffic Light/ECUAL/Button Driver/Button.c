/*
 * Button.c
 *
 * Created: 10/6/2022 8:38:04 PM
 *  Author: Peter
 */ 

#include "Button.h"

void button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	 DIO_init(buttonPort, buttonPin, IN);
}

void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonvalue)
{
	 DIO_read(buttonPort, buttonPin, buttonvalue);
}