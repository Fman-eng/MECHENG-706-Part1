/*
  Controller.cpp - Library for a PID controller.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "controller.h"
#include "PID.h"
Controller::Controller(){
	
}

float[3] Controller::WallFollow(float frontIR, float backIR, float targetDistance){
	float[3] out;
	out[0] = 0;
	out[1] = targetDistance - (frontIR + backIR)/2;
	out[2] = frontIR - backIR;
	
}