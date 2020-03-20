
#include "Controller.h"
#include "Drive.h"
#include "IRSensor.h"

double pidIn[3];
double pidOut[3];
double setPoints[3];

PID PIDVx(&pidIn[0],&pidOut[0], &setPoints[0],100,0,0, DIRECT);
PID PIDVy(&pidIn[1],&pidOut[1], &setPoints[1],100.0,0,0, DIRECT);
PID PIDW(&pidIn[2], &pidOut[2], &setPoints[2],1,0,0, DIRECT);


void setup() {
  Serial.begin(9600);
  PIDVx.SetOutputLimits(-100,100);
  PIDVy.SetOutputLimits(-100,100);
  PIDW.SetOutputLimits(-100,100);
  
  
  PIDVx.SetMode(AUTOMATIC);
  PIDVy.SetMode(AUTOMATIC);
  PIDW.SetMode(AUTOMATIC);



  
  // Sensor Instantiation
  IRSensor IRFront(A14, true);
  IRSensor IRBack(A15, true);
  //SonarSensor SonarFront(A12, A13);

  for(int i = 0; i <3; ++i){
    pidIn[i] = 0;
    pidOut[i] = 0;
  }

  setPoints[0] = 0;
  setPoints[1] = 150;
  setPoints[2] = 0;

  
  // Intstantiated the Controller
  Controller mainController;

  // Instantiate Drive
  Drive drive(46, 47, 50, 51);
  drive.Init();
  


  // Super Loop
  while(1){
    //get the starting time of the superloop
    //startTime = micros();
    Serial.println(IRBack.getDistance());
    mainController.WallFollow(IRFront.getDistance(), IRBack.getDistance(), 150, pidIn);
    //mainController.FrontDetect()
    
    PIDVx.Compute();
    PIDVy.Compute();
    PIDW.Compute();
    drive.SetSpeedThroughKinematic(pidOut[0], pidOut[1], pidOut[2]);
    
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
