#include "Controller.h"
#include "Drive.h"
#include "IRSensor.h"

void setup() {
  Serial.begin(9600);
  unsigned long startTime;
  
  // Sensor Instantiation
  IRSensor IRFront(A14, true);
  IRSensor IRBack(A15, true);
  //SonarSensor SonarFront(A12, A13);
  
  // motor saturation speeds for Vx, Vy and W
  float sat[3] = {100,100,100};
  
  // Intstantiated the Controller
  Controller mainController(sat);

  // Instantiate Drive
  Drive drive(46, 47, 50, 51);
  drive.Init();
  
  float speedVector[3] = {0,0,0};
  float speedVector2[3] = {0,0,0};


  // Super Loop
  while(1){
    //get the starting time of the superloop
    startTime = micros();
    Serial.println(IRBack.getDistance());
    delay(250);
    mainController.WallFollow(IRFront.getDistance(), IRBack.getDistance(), 150, speedVector2);
    //mainController.FrontDetect()
    //mainController.ApplyPID(speedVector, (float)(micros()- startTime),speedVector2);
    drive.SetSpeedThroughKinematic(speedVector2[0], speedVector2[1], speedVector2[2]);
    
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
