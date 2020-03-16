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


void Drive::RotatePID(int turnSpeed, int angle){
  //Use gyro and PID controller to control rotation
  }

void Drive::RotateOL(int turnSpeed, int angle){
  
  }

void Drive::SetSpeedThroughKinematic(int v_x, int v_y, int omega){
  int wheelRadius = 20; //wheel radius in mm
  int lx
  }
  
void Drive::Forward(){// moving forward USED FOR DEBUGGING
  Serial.println("Driving forward");
  this->leftFrontMotor.writeMicroseconds(1500 + this->speedVal);
  this->leftRearMotor.writeMicroseconds(1500 + this->speedVal);
  this->rightFrontMotor.writeMicroseconds(1500 - this->speedVal);
  this->rightRearMotor.writeMicroseconds(1500 - this->speedVal);
}

void Drive::Halt(){
  Serial.println("Halting");
  this->leftFrontMotor.writeMicroseconds(1500);
  this->leftRearMotor.writeMicroseconds(1500);
  this->rightFrontMotor.writeMicroseconds(1500);
  this->rightRearMotor.writeMicroseconds(1500);
  Serial.println("Ending Halt");
}
