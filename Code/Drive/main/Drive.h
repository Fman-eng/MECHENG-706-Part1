#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>
#include <Servo.h>   // include the library of servo motor control

class Drive {
  private:
    byte leftFront, leftRear, rightFront, rightRear;
    Servo leftFrontMotor, leftRearMotor, rightFrontMotor, rightRearMotor;
    int speedVal; 
    
  public:
    Drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear);
    void Init();
    void EnableMotors();
    void DisableMotors();
    void RotatePID(int turnSpeed, int angle);
    void RotateOL(int turnSpeed, int angle);
    void SetSpeedThroughKinematic(int v_x, int v_y, int omega);
    void DriveRight(int driveSpeed, int distance1, int distance2);
    void Forward();
    void Halt();
};
#endif
