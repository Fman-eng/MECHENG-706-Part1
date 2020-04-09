#include "Drive.h"
Drive::Drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear)
{
  Serial.println("Init drive class!");
  this->leftFront = leftFront;
  this->leftRear = leftRear;
  this->rightFront = rightFront;
  this->rightRear = rightRear;
  speedVal = 100;
}
void Drive::Init()
{
  pinMode(leftFront, OUTPUT);
  pinMode(leftRear, OUTPUT);
  pinMode(rightFront, OUTPUT);
  pinMode(rightRear, OUTPUT);
  EnableMotors();
}

void Drive::EnableMotors()
{
  this->leftFrontMotor.attach(leftFront);
  this->leftRearMotor.attach(leftRear);
  this->rightFrontMotor.attach(rightFront);
  this->rightRearMotor.attach(rightRear);
}

void Drive::DisableMotors()
{
  this->leftFrontMotor.detach();
  this->leftRearMotor.detach();
  this->rightFrontMotor.detach();
  this->rightRearMotor.detach();
}

void Drive::RotatePID(int turnSpeed, int angle)
{
  //Use gyro and PID controller to control rotation
}

void Drive::RotateOL(int turnSpeed, int angle)
{ /* 
    Take an turn speed and angle and turn the robot for
    that angle. Positive angle (i.e. 90) corrisponds
    to clockwise rotation of the robot.
  */
  long startTime = millis();
  float angleToTime = 10;
  while (millis() < startTime + angleToTime * abs(angle))
  {
    int turnDirection = angle/abs(angle);
    this->leftFrontMotor.writeMicroseconds(1500 + turnSpeed*turnDirection);
    this->leftRearMotor.writeMicroseconds(1500 + turnSpeed*turnDirection);
    this->rightFrontMotor.writeMicroseconds(1500 + turnSpeed*turnDirection);
    this->rightRearMotor.writeMicroseconds(1500 + turnSpeed*turnDirection);
  }
}

void Drive::SetSpeedThroughKinematic(float vx, float vy, float omega)
{
  float wheelRadius = 28; //wheel radius in mm
  float lx = 80;
  float ly = 90;

  this->leftFrontMotor.writeMicroseconds(1500 + (vx + vy - (lx + ly) * omega) / wheelRadius);
  this->leftRearMotor.writeMicroseconds(1500 + (vx - vy - (lx + ly) * omega) / wheelRadius);
  this->rightRearMotor.writeMicroseconds(1500 - (vx - vy + (lx + ly) * omega) / wheelRadius);
  this->rightFrontMotor.writeMicroseconds(1500 - (vx + vy + (lx + ly) * omega) / wheelRadius);

  Serial.print("vx: ");
  Serial.println(vx);
  Serial.print("vy: ");
  Serial.println(vy);
  Serial.print("omega: ");
  Serial.println(omega);
  Serial.print("Left Front Wheel = ");
  Serial.println(1500 + (vx + vy - (lx + ly) * omega) / wheelRadius);
}

void Drive::Forward()
{ // moving forward USED FOR DEBUGGING
  Serial.println("Driving forward");
  this->leftFrontMotor.writeMicroseconds(1500 + this->speedVal);
  this->leftRearMotor.writeMicroseconds(1500 + this->speedVal);
  this->rightFrontMotor.writeMicroseconds(1500 - this->speedVal);
  this->rightRearMotor.writeMicroseconds(1500 - this->speedVal);
}

void Drive::Halt()
{
  Serial.println("Halting");
  this->leftFrontMotor.writeMicroseconds(1500);
  this->leftRearMotor.writeMicroseconds(1500);
  this->rightFrontMotor.writeMicroseconds(1500);
  this->rightRearMotor.writeMicroseconds(1500);
  Serial.println("Ending Halt");
}
