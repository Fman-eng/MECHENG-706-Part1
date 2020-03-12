#include "PID.h"

PID::PID(float pGain, float iGain, float dGain){
  this->pGain = pGain;
  this->iGain = iGain;
  this->dGain = dGain;
  this->intergratorError = 0;
  this->lastIn = 0;
}

float PID::GetControl(float in, float timeStep, bool isSaturated){
  float out;
  
  // Calculate integrator Error
  if(!isSaturated)intergratorError += in*timeStep;
  
  // Calculate PID control signal
  out =  pGain*in + iGain*intergratorError + dGain*(in-lastIn)/timeStep;
  
  this->lastIn = in;
  return out;
}
