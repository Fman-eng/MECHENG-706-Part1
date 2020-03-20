/*
  Controller.h - Library for a Controller of a arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef Controller_h
#define Controller_h
#include <PID_v1.h>
#include "Arduino.h"

class Controller
{
  private:
    
  public:
    Controller();
    void WallFollow(double frontIR, double backIR, double targetDistance, double out[3]);
    void FrontDetect(double sonar, double targetDistance, double out[3]);
};
#endif
