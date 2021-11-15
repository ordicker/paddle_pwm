/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"


#define LED_BUILTIN1 17
#define LED_BUILTIN2 30
#define P_SWITCH 9
#define P_PWM 10
// clock select 16MHz/256(clock div)/125(counter top) = 500[Hz]
void setup()
{
  // PWM setup
  pinMode(P_PWM, OUTPUT); // OCR1 output
  
  //TCCR1A = _BV(COM0B0)| _BV(COM0B1) |_BV(WGM10) | _BV(WGM11) ;
  //TCCR1B = _BV(CS12) |  _BV(WGM12) | _BV(WGM13);
  //// 
  //OCR1A = 125;
  //OCR1B = 12;

  //switch setup
  pinMode(P_SWITCH, INPUT_PULLUP); //switch pin
  
  //debug
  pinMode(LED_BUILTIN1, OUTPUT);
}

void loop()
{
    if (digitalRead(P_SWITCH) == LOW){
	analogWrite(P_PWM, 229);// 90% pwm
	digitalWrite(LED_BUILTIN1, LOW);
    } else {
	analogWrite(P_PWM, 127);// 50% pwm
	digitalWrite(LED_BUILTIN1, HIGH);
    }
    delay(10);
    //OCR1B = 12; //pwm 10%
    //// wait for a second
    //delay(1000);
    // 
    //OCR1B = 108; //pwm 90%
    //// wait for a second
    //delay(1000);
    
}
