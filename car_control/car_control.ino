#include <AFMotor.h>
#define left A0
#define right A1

// defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  // pinMode(left, INPUT);
  // pinMode(right, INPUT);
  Serial.begin(9600);
}


void loop() {
  // printing values of the sensors to the serial monitor
  Serial.print("Left sensor: ");
  Serial.println(digitalRead(left));
  Serial.print("Right sensor: ");
  Serial.println(digitalRead(right));

  // line detected by both sensors
  if (digitalRead(left) == 0 && digitalRead(right) == 0) {
    // move forward
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
  }
  // line detected by left sensor
  else if (digitalRead(left) == 0 && digitalRead(right) == 1) {
    // turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
  }
  // line detected by right sensor
  else if (digitalRead(left) == 1 && digitalRead(right) == 0) {
    // turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }
  // line not detected by either sensor
  else if (digitalRead(left) == 1 && digitalRead(right) == 1) {
    // stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
  }
}