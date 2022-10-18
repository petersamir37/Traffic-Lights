/*
 * DIO.C
 *
 * Created: 10/6/2022 8:26:13 PM
 *  Author: Peter
 */ 

#include "DIO.h"

void DIO_init(uint8_t portName, uint8_t pinNumber, uint8_t direction)
{
	if(pinNumber<=7){
		switch(portName)
		{
		case 'A':
			if(direction == IN){
				CLR_BIT(DDRA,pinNumber);
			}
			else if(direction == OUT)
			{
				SET_BIT(DDRA,pinNumber);
			}
			else
			{
				errorhandler(DIO_WRONG_DIRECTION);	
			}
			errorhandler(DIO_OK);
			break;
		
		case 'B':
			if(direction == IN){
				CLR_BIT(DDRB,pinNumber);
			}
			else if(direction == OUT)
			{
				SET_BIT(DDRB,pinNumber);
			}
			else
			{
				errorhandler(DIO_WRONG_DIRECTION);		
			}
			errorhandler(DIO_OK);
			break;
		
		case 'C':
			if(direction == IN){
				CLR_BIT(DDRC,pinNumber);
			}
			else if(direction == OUT)
			{
				SET_BIT(DDRC,pinNumber);
			}
			else
			{
				errorhandler(DIO_WRONG_DIRECTION);
			}
			errorhandler(DIO_OK);
			break;
		
		case 'D':
			if(direction == IN){
				CLR_BIT(DDRD,pinNumber);
			}
			else if(direction == OUT)
			{
				SET_BIT(DDRD,pinNumber);
			}
			else
			{
				errorhandler(DIO_WRONG_DIRECTION);
			}
			errorhandler(DIO_OK);
			break;
		default: errorhandler(DIO_WRONG_PORT_NUMBER);
		}	
	
	}
	else errorhandler(DIO_WRONG_PIN_NUMBER);
	
}

void DIO_write(uint8_t portName, uint8_t pinNumber, uint8_t value)
{
	if(pinNumber<=7){
	switch(portName)
		{
		case 'A':
		if(value == LOW){
			CLR_BIT(PORTA,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else
		{
			errorhandler(DIO_WRONG_VALUE);	
		}
		errorhandler(DIO_OK);
		break;
		
		case 'B':
		if(value == LOW){
			CLR_BIT(PORTB,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
			errorhandler(DIO_WRONG_VALUE);
		}
		errorhandler(DIO_OK);
		break;
		
		case 'C':
		if(value == LOW){
			CLR_BIT(PORTC,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
			errorhandler(DIO_WRONG_VALUE);
		}
		errorhandler(DIO_OK);
		break;
		
		case 'D':
		if(value == LOW){
			CLR_BIT(PORTD,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
			errorhandler(DIO_WRONG_VALUE);
		}
		errorhandler(DIO_OK);
		break;
		
		default: errorhandler(DIO_WRONG_PORT_NUMBER);
		}
	}
	else errorhandler(DIO_WRONG_PIN_NUMBER);
}

void DIO_toggle(uint8_t portName, uint8_t pinNumber)
{
	if(pinNumber <=7){
	switch(portName)
		{
		case 'A':
			TOGGLE_BIT(PORTA,pinNumber);
			errorhandler(DIO_OK);
			break;
		case 'B':
			TOGGLE_BIT(PORTB,pinNumber);
			errorhandler(DIO_OK);
			break;
		case 'C':
			TOGGLE_BIT(PORTC,pinNumber);
			errorhandler(DIO_OK);
			break;
		case 'D':
			TOGGLE_BIT(PORTD,pinNumber);
			errorhandler(DIO_OK);
			break;
		default: errorhandler(DIO_WRONG_PORT_NUMBER);
		}
	}
	else errorhandler(DIO_WRONG_PIN_NUMBER);
}

void DIO_read(uint8_t portName, uint8_t pinNumber, uint8_t *value)
{
	if(pinNumber<=7){
	switch(portName)
	{
		case 'A':
		*value = READ_BIT(PINA,pinNumber);
		errorhandler(DIO_OK);
		break;
		case 'B':
		*value = READ_BIT(PINB,pinNumber);
		errorhandler(DIO_OK);
		break;
		case 'C':
		*value = READ_BIT(PINC,pinNumber);
		errorhandler(DIO_OK);
		break;
		case 'D':
		*value = READ_BIT(PIND,pinNumber);
		errorhandler(DIO_OK);
		break;
		default: errorhandler(DIO_WRONG_PORT_NUMBER);
	}
	}
	else errorhandler(DIO_WRONG_PIN_NUMBER);
}


// Define error handler

void errorhandler(EN_DIO_error_t status){
	while(status!=0){
	CLR_BIT(PORTC,0);		
	SET_BIT(DDRC,status);
	SET_BIT(PORTC,status);	
	}
	SET_BIT(DDRC,0);
	SET_BIT(PORTC,0);
}
