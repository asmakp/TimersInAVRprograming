#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
static int TimeVariable = 0; //variable for blink function
static int dutyCycle  = 0;   //variable for fading function
static int counter = 0;      //variable for led rampling  function

//DELUPPGIFT 1: BLINKA LED
void LED_init() {
	
    //static int TimeVariable = 0;

	if(TIFR0 & (1<< OCF0A))// Interrupt Flag Register
		{
			TimeVariable++;       //increment TimeVariable  
		    TIFR0 |= (1<<OCF0A);  // OCF0A is cleared by writing a logic one to the flag.
		}

         if(TimeVariable >10)     //check if variable reached 10 then enter loop   
		 {
		 PORTB ^= (1<<LED_PIN);   //toggle/blink the led 
		 TimeVariable = 0;        //reset the variable to 0
		 }
}

//DELUPPGIFT 2: Vary brightness with  PWM
void LED_FadingWitnPWM()
{

	/* OCR0A = 10;                         
	 _delay_ms(200);
	  OCR0A = 200;
	 _delay_ms(200);
	  OCR0A = 100;
	 _delay_ms(200);
	 OCR0A = 0;
	 _delay_ms(200);*/

	for( dutyCycle = 0; dutyCycle<= 255; dutyCycle+=25 ){
		 _delay_ms(100);
		 OCR0A = dutyCycle;                                //setting the Output Compare Register register with value(dutyCycle)
	}
	for( dutyCycle = 255; dutyCycle >= 0; dutyCycle-=10 ){
		 _delay_ms(100);
		 OCR0A = dutyCycle;                               //setting the Output Compare Register register with value(dutyCycle)
    }
}		

void LED_Rampning()
{
	  if(TIFR2 & (1<< OCF2A)) // Interrupt Flag Register is set to 1 on compare match.
	   	{
			OCR0A = simple_ramp();
			TIFR2 |= (1<<OCF2A);  // OCF0A is cleared by writing a logic one to the flag.
		}
}

uint8_t simple_ramp() {
	counter++;
	if (counter >=255){
		counter = 0;
		return counter;
	}
	else return counter;

}