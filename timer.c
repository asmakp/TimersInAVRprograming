#include <avr/io.h>

#include "timer.h"



void timer_init() {
	TCCR0A = (1<<WGM01 ) | (0<<WGM00);//select CTC mode ATmel 42735 Datasheet Ca 19.9.1 page 138
	TCCR0B &= ~(1<<WGM02 ); //select CTC mode,set WGM02 to 0, normal opration, OC0A(PD6) is disconnected
	
	//TCCR0A = (1<<COM0A1); //Clear OC0A on Compare Match.
	
	TCCR0B |= (1<<CS02 ) |(1<<CS00 ) ;//setting the prescalar to 1024 ,this sets the clock,ATmel 42735 datasheet page 141 ,142
    TCCR0B &= ~(1<<CS01 );
    // An 8-bit comparator continuously compares TCNT0 with the Output Compare Registers (OCR0A)
    OCR0A = 156; // f_OCnx = f_clk_i/o / (2*N(1+OCRnx))  //    OCR0A = 16000000HZ/(2*1024*100HZ)
}



void timer_intitPWM(){

	TCCR0A = (1<<COM0A1);    //Clear OC0A on Compare Match, set OC0A at BOTTOM (non-inverting mode)
	TCCR0A &=  ~(1<<COM0A0); //19.9.1. TC0 Control Register A, page 123

	TCCR0A |= (1<<WGM01 ) | (1<<WGM00 ); //sett fast PWM mode TOP as 0XFF , Update of OCR0X at BOTTOM
	TCCR0B &=  ~(1 << WGM02);

	TCCR0B &= ~(1<<FOC0A ); //set these bits to zero for future device compatibility.
	TCCR0B &= ~(1<<FOC0B );
	  
    TCCR0B |= (1<<CS01) | (1<<CS00); //setting clock  64 prescaler
}

