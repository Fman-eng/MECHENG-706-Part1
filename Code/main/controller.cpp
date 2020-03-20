/*
  Controller.cpp - Library for a PID controller.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include <PID_v1.h>
#include "Controller.h"


Controller::Controller(){
}

void Controller::WallFollow(double frontIR, double backIR, double targetDistance, double out[3]){
	out[0] = 100;
	out[1] = targetDistance - (frontIR + backIR)/2;
	out[2] = frontIR - backIR;
	return;
}

void Controller::FrontDetect(double sonar, double targetDistance, double out[3]){
	out[0] = targetDistance - sonar;
	out[1] = 0;
	out[2] = 0;

	return;
}



