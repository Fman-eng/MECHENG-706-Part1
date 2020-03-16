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
   Serial.println("############### Servo Values ##############");
   while(1){
   Serial.println(this->leftFrontMotor.read());
   Serial.println(this->leftRearMotor.read());
   Serial.println(this->rightFrontMotor.read());
   Serial.println(this->rightRearMotor.read());
   this->leftFrontMotor.writeMicroseconds(1500 + turnSpeed);
   this->leftRearMotor.writeMicroseconds(1500 + turnSpeed);
   this->rightFrontMotor.writeMicroseconds(1500 + turnSpeed);
   this->rightRearMotor.writeMicroseconds(1500 + turnSpeed);
   }
  }

void Drive::SetSpeedThroughKinematic(float vx, float vy, float omega){
  float wheelRadius = 28; //wheel radius in mm
  float lx = 80; 
  float ly = 90;

  this->leftFrontMotor.writeMicroseconds(1500 + (vx + vy - (lx + ly)*omega)/wheelRadius);
  this->leftRearMotor.writeMicroseconds(1500 + (vx - vy - (lx + ly)*omega)/wheelRadius);
  this->rightRearMotor.writeMicroseconds(1500 - (vx - vy + (lx + ly)*omega)/wheelRadius);
  this->rightFrontMotor.writeMicroseconds(1500 - (vx + vy + (lx + ly)*omega)/wheelRadius);

  Serial.print("vx: ");
  Serial.println(vx);
  Serial.print("vy: ");
  Serial.println(vy);
  Serial.print("omega: ");
  Serial.println(omega);
  Serial.print("Left Front Wheel = ");
  Serial.println(1500 + (vx + vy - (lx + ly)*omega)/wheelRadius);
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
