/*
 * Traffic Light.c
 *
 * Created: 10/6/2022 8:07:21 PM
 * Author : Peter
 */ 

//#include <avr/io.h>

#include "Application/Application.h"

void DIO_test()
{
	DIO_init('D',7,OUT);
	DIO_write('D',7,3);
	DIO_toggle('D',7);
	uint8_t value=0;
	DIO_init('D',2,IN);
	DIO_read('D',2,&value);
	if(value)
	{
		DIO_write('D',7,HIGH);
	}
}

void LED_test()
{
	LED_init ('C',0);
	LED_ON ('C',0);
	LED_OFF ('C',0);
	LED_Toggle ('C',0);
}

void button_test()
{	
	button_init('D',2);
	uint8_t value=0;
	button_read('D',2,&value);
}

int main(void)
{	
	
	
	APP_init();		
		
	APP_start();
	
}

