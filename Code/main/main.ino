/*
  main.ino - Main file for arduino based wall following program.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "Controller.h"
#include "Drive.h"
#include "IRSensor.h"
#include "SonarSensor.h"

double pidIn[3];
double pidOut[3];
double setPoints[3];

PID PIDVx(&pidIn[0], &pidOut[0], &setPoints[0], 0, 0, 0, REVERSE);
PID PIDVy(&pidIn[1], &pidOut[1], &setPoints[1], 0, 0, 0, REVERSE);
PID PIDW(&pidIn[2], &pidOut[2], &setPoints[2], 1, 2, 1, REVERSE);

void setup()
{
  Serial.begin(9600);
  PIDVx.SetOutputLimits(-10000, 10000);
  PIDVy.SetOutputLimits(-10000, 10000);
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
  double sonarVals[2];

  // Super Loop
  while (1)
  {
    //get the starting time of the superloop
    Serial.println(IRBack.getDistance());
    if (!init_finished)
    {
      sonarVals[0] = sonar.getDistance();
      init_finished = mainController.RotateForWall(sonarVals, pidIn);
    }
    else
    {
      mainController.WallFollow(IRFront.getDistance(), IRBack.getDistance(), 150, pidIn);
      //mainController.FrontDetect()
    }

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
