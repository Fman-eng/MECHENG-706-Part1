#include "Controller.h"
#include "Drive.h"
#include "IRSensor.h"

void setup() {
  unsigned long startTime;
  
  // Sensor Instantiation
  IRSensor IRFront(uint8_t pin, bool shortRange);
  IRSensot IRBack(uint8_t pin, bool shortRange);

  // motor saturation speeds for Vx, Vy and W
  float sat[3] = {100,100,100};
  
  // Intstantiated the Controller
  Controller mainController(sat);

  // Instantiate Drive
  Drive drive(byte leftFront, byte leftRear, byte rightFront, byte rightRear);
  drive.Init();
  
  float speedVector[3] = {0,0,0};



  // Super Loop
  while(1){
    //get the starting time of the superloop
    startTime = micros();
    
    mainController.WallFollow(IRFront.getDistance(), IRBack.getDistance(), 1500, speedVector);
    mainController.ApplyPID(speedVector, (micros()- startTime),speedVector);
    
    
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
