#include "PID.h"
#include "Arduino.h"
/*
Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
PID::PID(){
  this->pGain = 0;
  this->iGain = 0;
  this->dGain = 0;
  this->intergratorError = 0;
  this->lastIn = 0;
}

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
