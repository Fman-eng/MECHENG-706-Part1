#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>
#include <Servo.h>   // include the library of servo motor control

class Drive {
  private:
    byte leftFront, leftRear, rightFront, rightRear;
    int speedVar = 100; 
    int speedChange;
    
  public:
    Drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear);
    void init();
    void forward();
    void halt();
};
#endif