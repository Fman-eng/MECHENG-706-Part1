/*
  Controller.h - Library for a Controller of a arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef Controller_h
#define Controller_h
#include "PID.h"
#include "Arduino.h"
#include <cstdlib>

class Controller
{
  private:
    PID* PIDVx;
    PID* PIDVy;
    PID* PIDW;
    float[3] SaturateValues;
    bool[3] isSaturated;
  public:
    Controller(PID* PIDVx, PID* PIDVy, PID* PIDW, float[3] saturateValues, bool[3] isSaturated);
    float[3] WallFollow(float frontIR, float backIR, float targetDistance);
    float[3] FrontDetect(float sonar, float targetDistance);
    float[3] ApplyPID(float[3] in, float timeStep);
};
#endif