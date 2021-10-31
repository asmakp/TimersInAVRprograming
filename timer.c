#include <avr/io.h>

#include "timer.h"

void timer_init() {
	 TCCR0A = (1<<WGM01 ) | (0<<WGM00);//select CTC mode Ca 19.9.1 page 138
	TCCR0B = (0<<WGM02 ); //selecst CTC mode,normal opration, OC0A(PD6) is disconnected
	
	//TCCR0A = (1<<COM0A1); //Clear OC0A on Compare Match.
	
	TCCR0B |= (1<<CS02 ) | (0<<CS01 )|(1<<CS00 ) ;//setting the prescalar to 1024 ,this sets the clock,ATmel 42735 datasheet page 141 ,142
  
  
    OCR0A = 156; // f_OCnx = f_clk_i/o / (2*N(1+OCRnx))  //    OCR0A = 16000000HZ/(2*1024*100HZ)
}

