/*
  main.ino - Main file for arduino based wall following program.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "Controller.h"
#include "Drive.h"
#include "IRSensor.h"
#include "SonarSensor.h"
#include "PID_v1.h"


double pidIn[3];
double pidOut[3];
double setPoints[3];

PID PIDVx(&pidIn[0], &pidOut[0], &setPoints[0], 200, 0, 0, REVERSE);
PID PIDVy(&pidIn[1], &pidOut[1], &setPoints[1], 170, 483, 40, REVERSE);
PID PIDW(&pidIn[2], &pidOut[2], &setPoints[2], 130, 420, 27, REVERSE);

//PID PIDVx(&pidIn[0], &pidOut[0], &setPoints[0], 100, 0, 0, REVERSE);
//PID PIDVy(&pidIn[1], &pidOut[1], &setPoints[1], 120, 400, 0, REVERSE);
//PID PIDW(&pidIn[2], &pidOut[2], &setPoints[2], 270, 300, 0, REVERSE);

void setup()
{
  Serial.begin(9600);
  PIDVx.SetOutputLimits(-5000, 5000);
  PIDVy.SetOutputLimits(-3000, 3000);
  PIDW.SetOutputLimits(-20, 20);

  PIDVx.SetMode(AUTOMATIC);
  PIDVy.SetMode(AUTOMATIC);
  PIDW.SetMode(AUTOMATIC);

  // Sensor Instantiation
  IRSensor IRFront(A14, true);
  IRSensor IRBack(A15, true);

  //SonarSensor SonarFront(A12, A13);

  for (int i = 0; i < 3; ++i)
  {
    pidIn[i] = 0;
    pidOut[i] = 0;
  }

  setPoints[0] = 0;
  setPoints[1] = 0;
  setPoints[2] = 0;

  // Intstantiated the Controller
  Controller mainController;

  // Instantiate Drive
  Drive drive(46, 47, 50, 51);
  drive.Init();

  // Insantiate SonarSensor
  SonarSensor sonar(48, 49);

  // Initalisation variables
  bool init_finished = false;

  // Setup for the 4th order FIR filter
  float frontIRValues[5];
  float rearIRValues[5];
  for(int i = 0; i < 5; i++){
    frontIRValues[i] = IRFront.getDistance();
    rearIRValues[i]  = IRBack.getDistance();
  }
  float frontAvg;
  float rearAvg;
  int firItr = 0;

  
  // Super Loop
  while (1)
  {
    /* Use a shift register to store the previous values of the IR sensors
    to apply a fourth order FIR filter, this prevents noise interfering
    with the derivative terms of the PID controllers. firItr iterates
    through each value in the arrays and updates them with the new
    values from the sensors. The arrays are then averaged bfore being
    input into the controller*/
    frontIRValues[firItr] = IRFront.getDistance();
    rearIRValues[firItr]  = IRBack.getDistance();
    firItr = (firItr+1)%5;
    frontAvg = 0;
    rearAvg = 0;    
    for(int i = 0; i < 5; i++){
      frontAvg += frontIRValues[i];
      rearAvg  += rearIRValues[i];
    }
    frontAvg = frontAvg/5;
    rearAvg  = rearAvg/5;
    
    mainController.WallFollow(frontAvg, rearAvg, 145, pidIn);
    mainController.FrontDetect(sonar.getDistance(), 80, pidIn);

    PIDVx.Compute();
    PIDVy.Compute();
    PIDW.Compute();
    drive.SetSpeedThroughKinematic(pidOut[0], pidOut[1], pidOut[2]);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}
