/*
  PID.h - Library for a PID controller.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef PID_h
#define PID_h

#include "Arduino.h"
class PID
{
  private:
    float pGain;
    float iGain;
    float dGain;
    float intergratorError;
    float lastIn;
  public:
    PID(float pGain, float iGain, float dGain);
    float GetControl(float in, float timeStep, bool isSaturated);
};
#endif
