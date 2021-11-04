//ASMA KHALID PATEL
//IOT 2020
#include <avr/io.h>
#include <avr/pgmspace.h> //Program Space Utilities
#include <util/delay.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"



void main (void) {

	uart_init();

	//DELUPPGIFT 1: BLINKA LED
	// DDRB |= (1<<LED_PIN);
    // timer_init();

 
 	//DELUPPGIFT 2: Vary brightness with  PWM
	// DDRD |= (1<<LED_PIN_PWM);
	// timer_intitPWM();


	//DELUPPGIFT 3: LED-RAMPNING
	 DDRD |= (1<<LED_PIN_PWM);
	 timer2_init();

	while (1){

		//printf_P(PSTR("in while loop\n"));
         
        //DELUPPGIFT 1: BLINKA LED
	    //LED_init();
 		
		
		//DELUPPGIFT 2: Vary brightness with  PWM
        //f_OCnx PWM = f_(clk i/o)/(N*256)  gives frequency 10MHz after rounding.
 		//LED_FadingWitnPWM();


		//DELUPPGIFT 3:LED-RAMPNING
		 LED_Rampning();
	    
  }
}


