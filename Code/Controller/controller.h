/*
  Controller.h - Library for a Controller of a arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

class Controller
{
  private:
    
  public:
    Controller();
    float[3] WallFollow(float frontIR,float backIR);
};
#endif