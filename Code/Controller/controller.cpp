/*
  Controller.cpp - Library for a PID controller.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "controller.h"
#include "PID.h"
Controller::Controller(PID* PIDVx, PID* PIDVy, PID* PIDW, float[3] saturateValues, bool[3] isSaturated){
	this->PIDVx = PIDVx;
    this->PIDVy = PIDVy;
    this->PIDW = PIDW;
	for(int i; i <= 2; i++){
		this->saturateValues[i] = saturateValues[i];
	}
	for(int i; i <= 2; i++){
		this->isSaturated[i] = false;
	}
}

float[3] Controller::WallFollow(float frontIR, float backIR, float targetDistance, float[3] out){
	out[0] = 0;
	out[1] = targetDistance - (frontIR + backIR)/2;
	out[2] = frontIR - backIR;

	return;
}

float[3] Controller::FrontDetect(float sonar, float targetDistance, float[3] out){
	out[0] = targetDistance - sonar;
	out[1] = 0;
	out[2] = 0;

	return;
}

float[3] Controller::ApplyPID(float[3] in, float timeStep, float[3] out){
	// Apply the PID control to the inputs
	out[0] = this->PIDVx.GetControl(in[0], timeStep, this->isSaturated[0]);
	out[1] = this->PIDVy.GetControl(in[1], timeStep, this->isSaturated[1]);
	out[2] = this->PIDW.GetControl(in[2], timeStep, this->isSaturated[2]);

	// Check for saturation and if so set the saturate flag and saturate the output.
	for(int i; i <= 2; i++){
		this->isSaturated[i] = (abs(out[i]) >= this->saturateValues[i]);
		if(this->isSaturated[i])out[i] = (out[i]/abs(out[i]))*this->saturateValues[i];
	}
	return;
}
