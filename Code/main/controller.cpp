/*
  Controller.cpp - Library for a PID controller.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/

#include "Controller.h"

Controller::Controller(){
}

bool Controller::InitForWall(double frontIR, double backIR, double out[3])
{
  double IRTolerence = 5;
  bool finished = abs(frontIR - backIR) < IRTolerence;
  out[0] = 0;
  out[1] = 0;
  out[2] = -20; // Turning speed initially, CW
  return finished ? 1 : -1;
}

void Controller::WallFollow(double frontIR, double backIR, double targetDistance, double out[3])
{
  float l_IR = 185; //Distance between IR sensors
  out[1] = targetDistance - (frontIR + backIR) / 2;
  out[2] = (frontIR - backIR) / (2*l_IR);
  return;
}

void Controller::FrontDetect(double sonar, double targetDistance, double out[3])
{
  out[0] = sonar - targetDistance;

  return;
}
