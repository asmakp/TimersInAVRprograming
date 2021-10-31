#include <avr/io.h>
#include <avr/pgmspace.h> //Program Space Utilities
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

#define LED_PIN 2

void main (void) {
	DDRB |= (1 << LED_PIN);
	uart_init();
	int TimeVariable = 0;
	
	
    TCCR0A = (1<<WGM01 ) | (0<<WGM00);//select CTC mode Ca 19.9.1 page 138
	TCCR0B = (0<<WGM02 ); //selecst CTC mode,normal opration, OC0A(PD6) is disconnected
	
	//TCCR0A = (1<<COM0A1); //Clear OC0A on Compare Match.
	
	TCCR0B |= (1<<CS02 ) | (0<<CS01 )|(1<<CS00 ) ;//setting the prescalar to 1024 ,this sets the clock,ATmel 42735 datasheet page 141 ,142
  
  
    OCR0A = 156; // f_OCnx = f_clk_i/o / (2*N(1+OCRnx))  //    OCR0A = 16000000HZ/(2*1024*100HZ)


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
