#include "Drive.h"
Drive::Drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear) {
  Serial.println("Init drive class!");
  this->leftFront = leftFront;
  this->leftRear = leftRear;
  this->rightFront = rightFront;
  this->rightRear = rightRear;
  speedVal = 100;
}
void Drive::Init() {
  pinMode(leftFront, OUTPUT);
  pinMode(leftRear, OUTPUT);
  pinMode(rightFront, OUTPUT);
  pinMode(rightRear, OUTPUT);
  EnableMotors();
}

void Drive::EnableMotors() {
  this->leftFrontMotor.attach(leftFront);
  this->leftRearMotor.attach(leftRear);
  this->rightFrontMotor.attach(rightFront);
  this->rightRearMotor.attach(rightRear);
  }

void Drive::DisableMotors() {
 this->leftFrontMotor.detach();  
 this->leftRearMotor.detach();
 this->rightFrontMotor.detach();
 this->rightRearMotor.detach();
}

void Drive::Forward(){// moving forward   
  Serial.println("Driving forward");
  this->leftFrontMotor.writeMicroseconds(1500 + this->speedVal);
  this->leftRearMotor.writeMicroseconds(1500 + this->speedVal);
  this->rightFrontMotor.writeMicroseconds(1500 - this->speedVal);
  this->rightRearMotor.writeMicroseconds(1500 - this->speedVal);
  Serial.println("Ending Driving forward");
}

void Drive::Halt(){// stop motors   left_front_motor.writeMicroseconds(1500);
  Serial.println("Halting");
  this->leftFrontMotor.writeMicroseconds(1500);
  this->leftRearMotor.writeMicroseconds(1500);
  this->rightFrontMotor.writeMicroseconds(1500);
  this->rightRearMotor.writeMicroseconds(1500);
  Serial.println("Ending Halt");
}
