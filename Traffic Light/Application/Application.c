/*
 * Application.c
 *
 * Created: 10/6/2022 8:36:42 PM
 *  Author: Peter
 */ 


#include "Application.h"

#define CAR 'A' // Define port A as car

#define PEDESTRIAN 'B' // Define port B as pedestrian

#define R 0 // Define R,Y,G as 0,1,2
#define Y 1
#define G 2

#define INT_port 'D' // Define button port and pin
#define INT_pin 2

#define error_port 'C' // Define port C for errors

#define OVERFLOWS 19532 // Define number of overflows for 5 seconds - no prescaling

unsigned int overflowcounter = 0;

uint8_t interrupt=0;


// Define wait 5 seconds function

void wait5S(void)
{
	TCNT0 = 0x00;		//set timer to 0
	SET_BIT(TCCR0,0);	//start timer
	overflowcounter = 0;
	while(overflowcounter<=OVERFLOWS){
		while(!READ_BIT(TIFR,0));
		SET_BIT(TIFR,0);
		overflowcounter++;
	}
}



// Define blink for 5 seconds

void blinkwait(uint8_t port1, uint8_t pin1, uint8_t port2, uint8_t pin2)
{
		unsigned int togglecounter;
		TCNT0 = 0x00;		//set timer to 0
		SET_BIT(TCCR0,0);	//start timer
		overflowcounter = 0;
		while(overflowcounter<=OVERFLOWS){
			while(!READ_BIT(TIFR,0));
			SET_BIT(TIFR,0);
			overflowcounter++;
			togglecounter++;
			if(togglecounter ==2000){
				LED_Toggle(port1,pin1);
				togglecounter=0;
				if(port2){
				LED_Toggle(port2,pin2);
				}
			}
		}
}
 
 
 
// Define app initialization

void APP_init(void){		
	
// Enable global interrupts

sei();

// Choose external interrupt sense, rising edge

SET_BIT(MCUCR,0);
SET_BIT(MCUCR,1);

// Enable external interrupt INT0 

SET_BIT(GICR,6);

// Choose timer mode

TCCR0 = 0x00;

// Set timer initial value

TCNT0 = 0x00;


// Initialize LED pins as outputs

LED_init(CAR,R);
LED_init(CAR,Y);
LED_init(CAR,G);

LED_init(PEDESTRIAN,R);
LED_init(PEDESTRIAN,Y);
LED_init(PEDESTRIAN,G);

// Initialize button pin as input

button_init(INT_port, INT_pin);


}



// Define normal mode function

/*
Normal mode

Cars LEDs will switch every 5 seconds starting from G to Y to R then backwards
Yellow LED blinks when on

*/

void APP_start(void)
{
	while(1){
	interrupt = 0;
	if(interrupt == 0) LED_ON(PEDESTRIAN,R);	
	if(interrupt == 0) LED_ON(CAR, G);
	if(interrupt == 0) wait5S();
	if(interrupt == 0) LED_OFF(CAR,G);
	if(interrupt == 0) blinkwait(CAR,Y,0,0);
	if(interrupt == 0) LED_OFF(CAR,Y);
	if(interrupt == 0) LED_ON(CAR,R);
	if(interrupt == 0) wait5S();
	if(interrupt == 0) LED_OFF(CAR,R);
	if(interrupt == 0) blinkwait(CAR,Y,0,0);
	if(interrupt == 0) LED_OFF(CAR,Y);
	}
}



// Define ISR

/*
Pedestrian mode

When button is pressed switch to pedestrian mode
If pressed when cars red is on, pedestrian's green turns on and and car's red will remain on for five seconds
If pressed when cars green is on, or car yellow is blinking, the pedestrian red will be on then both yellows start blinking for 5 seconds
then car red and pedestrian green turn on
At the end of both states, cars red will be off and both yellows start blinking for 5 seconds while pedestrian green remains on
After 5 seconds pedestrian green turns off and both pedestrian red and car green turn on
Operation returns to normal mode

*/

ISR(EXT_int_0)
{	
	interrupt = 1;
	uint8_t value;
	DIO_read(CAR,R,&value);
	if(value)
	{
		LED_OFF(PEDESTRIAN,R);
		LED_ON(PEDESTRIAN,G);
		wait5S();
		LED_OFF(CAR,R);
		blinkwait(CAR,Y,PEDESTRIAN,Y);
		LED_OFF(PEDESTRIAN,Y);
		LED_OFF(CAR,Y);
		LED_OFF(PEDESTRIAN,G);
	}
	else
	{
		LED_OFF(CAR,G);
		blinkwait(CAR,Y,PEDESTRIAN,Y);
		LED_OFF(CAR,Y);
		LED_OFF(PEDESTRIAN,Y);
		LED_ON(CAR,R);
		LED_OFF(PEDESTRIAN,R);
		LED_ON(PEDESTRIAN,G);
		wait5S();
		LED_OFF(CAR,R);
		blinkwait(CAR,Y,PEDESTRIAN,Y);		
		LED_OFF(CAR,Y);
		LED_OFF(PEDESTRIAN,Y);
		LED_OFF(PEDESTRIAN,G);
	}
	
}


