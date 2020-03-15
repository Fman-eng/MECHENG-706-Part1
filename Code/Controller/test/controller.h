/*
  Controller.h - Library for a Controller of a arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef Controller_h
#define Controller_h
#include "PID.h"
#include "Arduino.h"

class Controller
{
  private:
    PID PIDVx;
    PID PIDVy;
    PID PIDW;
    float saturateValues[3];
    bool isSaturated[3];
  public:
    Controller(float saturateValues[3]);
    void WallFollow(float frontIR, float backIR, float targetDistance, float out[3]);
    void FrontDetect(float sonar, float targetDistance, float out[3]);
    void ApplyPID(float in[3], float timeStep, float out[3]);
};
#endif
