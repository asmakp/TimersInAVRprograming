#include <avr/io.h>
#include <avr/pgmspace.h> //Program Space Utilities
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

#define LED_PIN 2

void main (void) {
	DDRB |= (1 << LED_PIN); //set pin 

	int TimeVariable = 0;

	uart_init();
	timer_init();


	while (1){
		printf_P(PSTR("in while loop\n"));
 		if(TIFR0 & (1<< OCF0A))// Interrupt Flag Register
		{
		
		TimeVariable++;
		//TIFR0 = (0<<OCF0A);
			
		}
         if(TimeVariable >10){
		
			 PORTB ^= (1<<LED_PIN);
			// TIFR0 &= ~(1<<OCF0A);   // OCF0A is cleared by writing a logic one to the flag.
			
			 TimeVariable = 0;
		}
		
		
	}
}
