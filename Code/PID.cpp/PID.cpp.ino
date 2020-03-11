#include PID.h

PID::PID(float pGain, float iGain, float dGain, float maxControlSignal){
  this->pGain = pGain;
  this->iGain = iGain;
  this->dGain = dGain;
  this->maxControlSignal = maxControlSignal;
  this->intergratorError = 0;
  this->lastIn = 0;
}

float PID::GetControl(float in, float timeStep, bool isSaturated){
  // Calculate intergrator Error
  ifintergratorError += pGain*in
}
