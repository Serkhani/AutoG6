// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>


// DC motor on M2
AF_DCMotor motor(1, );
// DC hobby servo

// Stepper motor on M3+M4 48 steps per revolution


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
  // turn on servo

   
  // turn on motor #2
  motor.setSpeed(200);
  motor.run(RELEASE);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(3);
 }
}
