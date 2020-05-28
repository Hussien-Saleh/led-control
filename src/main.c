/*
    program to control two leds using two push buttons
	requirements:
	if the first button is pressed, the first led is on
	if the second button is pressed, the second led is on
	if both buttons are pressed, both leds are on
	if no buttons are pressed, leds are off
*/

#include <avr/io.h>

int main(void)
{
	DDRB &= (~(1<<PB0)); // pin 0 of PORTB as input pin
	DDRB &= (~(1<<PB1)); // pin 1 of PORTB as input pin
	DDRC |= (1<<PC0);    // pin 0 of PORTC as output pin
	DDRC |= (1<<PC1);    // pin 1 of PORTC as output pin
	
	/*
	        LEDs configuration - positive logic 
			leds initially off
	*/

	PORTC &= (~(1<<PC0)); 
	PORTC &= (~(1<<PC1));  
	
    while(1)
    {
		// check if the first button is pressed, mask pin 0 port B
    	if(PINB & (1<<PB0)) 
    	{
    		PORTC |= (1<<PC0); // LED1 ON
    	}
    	else
    	{
    		PORTC &= (~(1<<PC0)); // LED1 OFF
    	}
    	if(PINB & (1<<PB1)) // Check if the second button is pressed
    	{
    		PORTC |= (1<<PC1); // LED2 ON
    	}
    	else
    	{
    		PORTC &= (~(1<<PC1)); // LED2 OFF
    	}
    }
}
