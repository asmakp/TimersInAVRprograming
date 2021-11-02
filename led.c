#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
static int TimeVariable = 0; //variable for blink function
static int dutyCycle  = 0;   //variable for fading function

//DELUPPGIFT 1: BLINKA LED
void LED_init() {
	
    //static int TimeVariable = 0;

	if(TIFR0 & (1<< OCF0A))// Interrupt Flag Register
		{
			TimeVariable++;       //Variable to count till 10
		    TIFR0 |= (1<<OCF0A);  // OCF0A is cleared by writing a logic one to the flag.
		}

         if(TimeVariable >10)
		 {
		 PORTB ^= (1<<LED_PIN);
		 TimeVariable = 0;
		 }
}

//DELUPPGIFT 2: Vary brightness with  PWM
void LED_FadingWitnPWM()
{
	for( dutyCycle = 0; dutyCycle<= 255; dutyCycle+=10 ){
		 _delay_ms(100);
		 OCR0A = dutyCycle;
	}
	for( dutyCycle = 255; dutyCycle >= 0; dutyCycle-=10 ){
		 _delay_ms(100);
		 OCR0A = dutyCycle;
    }
}		