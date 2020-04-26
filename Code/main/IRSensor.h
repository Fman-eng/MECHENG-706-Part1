
/*
  IRSensor.h - A header file for IRSensors class for an arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#ifndef IRSensor_h
#define IRSensor_h

#include "Arduino.h"

class IRSensor
{
public:
    IRSensor(uint8_t pin, bool sensorOne);
    int getDistance();
    int getSensorReading();

private:
    uint8_t _pin;
    bool _sensorOne;
    int sensorReadings[5];
    float sensorOneCoeffs[4] = {909, -0.02958, 282.9, -0.003827};
    float sensorTwoCoeffs[4] = {898.9, -0.0263, 246.8, -0.003013};
    int sum;
    int averageSensorReading;
    int calculatedDistance;
};

#endif