#ifndef _LED_H_
#define _LED_H_

#define LED_PIN 2 // pin 10 (arduino) on portB
#define LED_PIN_PWM 6 //pin 6 on port D

void LED_init(void);

void LED_FadingWitnPWM(void);

#endif // _LED_H_

