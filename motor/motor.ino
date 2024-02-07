#include <AFMotor.h>

AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor(2);

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  leftMotor.setSpeed(100);
  rightMotor.setSpeed(100);
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}

void loop() {
  if (Serial.available() > 0) {
    int receivedData = Serial.parseInt();  // Parse the received integer

    int leftMotorSpeed = leftMotorSpeed + receivedData;
    int rightMotorSpeed = rightMotorSpeed - receivedData;

    if (leftMotorSpeed > 100) {
      leftMotorSpeed = 100;
    }
    if (rightMotorSpeed > 100) {
      rightMotorSpeed = 100;
    }

    if (leftMotorSpeed < 0) {
      leftMotorSpeed = 0;
    }
    if (rightMotorSpeed < 0) {
      rightMotorSpeed = 0;
    }
    leftMotor.setSpeed(leftMotorSpeed);
    rightMotor.setSpeed(rightMotorSpeed);
  }
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}