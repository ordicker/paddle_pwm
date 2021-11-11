/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"


#define LED_BUILTIN1 17
#define LED_BUILTIN2 30
// clock select 16mhz/256(clock div)/125(counter top) = 500[Hz]
void setup()
{
  // PWM setup
  pinMode(10, OUTPUT); // ocr1 output

  TCCR1A = _BV(COM0B0)| _BV(COM0B1) |_BV(WGM10) | _BV(WGM11) ;
  TCCR1B = _BV(CS12) |  _BV(WGM12) | _BV(WGM13);
  // 
  OCR1A = 125;
  OCR1B = 12;
}

void loop()
{
    OCR1B = 12; //pwm 10%
    // wait for a second
    delay(1000);

    OCR1B = 108; //pwm 90%
    // wait for a second
    delay(1000);
    
}
