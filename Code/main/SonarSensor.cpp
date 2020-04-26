/*
  SonarSensor.cpp - A source file for the sonar sensor class for an arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "Arduino.h"
#include "SonarSensor.h"

SonarSensor::SonarSensor(int triggerPin, int echoPin)
{
    _triggerPin = triggerPin;
    _echoPin = echoPin;

    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

int SonarSensor::getDistance()
{
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    startMicros = micros();
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(_triggerPin, LOW);

    duration = pulseIn(_echoPin, HIGH);

    if(duration == 0){
      return 2000;
    }else{
      return (int)(duration / 2.9 / 2);
    }
    
}
