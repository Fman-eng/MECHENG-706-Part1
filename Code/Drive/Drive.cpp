#include "Drive.h"
Drive::Drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear) {
  Serial.println("Init drive class!");
  this->leftFront = leftFront;
  this->leftRear = leftRear;
  this->rightFront = rightFront;
  this->rightRear = rightRear;
  init();
}
void Drive::init() {
  Serial.begin(9600);
  pinMode(leftFront, OUTPUT);
  pinMode(leftRear, OUTPUT);
  pinMode(rightFront, OUTPUT);
  pinMode(rightRear, OUTPUT);

  Servo leftFrontMotor;
  Servo leftRearMotor;
  Servo rightFrontMotor;
  Servo rightRearMotor;
}

void forward(){// moving forward   
  leftFrontMotor.writeMicroseconds(1500 + speedVal);
  leftRearMotor.writeMicroseconds(1500 + speedVal);
  rightFrontMotor.writeMicroseconds(1500 - speedVal);
  rightRearMotor.writeMicroseconds(1500 - speedVal);
}

void halt(){// stop motors   left_front_motor.writeMicroseconds(1500);
  leftFrontMotor.writeMicroseconds(1500);
  leftRearMotor.writeMicroseconds(1500);
  rightFrontMotor.writeMicroseconds(1500);
  rightRearMotor.writeMicroseconds(1500);
}