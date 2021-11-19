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
  
  //switch setup
  pinMode(P_SWITCH, INPUT_PULLUP); //switch pin
  
  //debug
  pinMode(LED_BUILTIN1, OUTPUT);
}

void loop()
{
    if (digitalRead(P_SWITCH) == LOW){
	analogWrite(P_PWM, 242);// 95% pwm
	digitalWrite(LED_BUILTIN1, LOW);
    } else {
	analogWrite(P_PWM, 127);// 50% pwm
	digitalWrite(LED_BUILTIN1, HIGH);
    }
    delay(10);    
}
