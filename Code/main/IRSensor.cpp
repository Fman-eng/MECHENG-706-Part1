/*
  IRSensor.cpp - A source file for IRSensors class for an arduino based robot.
  Group 2: Freeman Porten, Lachlan Barnes, Jake Olliff, Calvin Lee
*/
#include "Arduino.h"
#include "IRSensor.h"

IRSensor::IRSensor(uint8_t pin, bool sensorOne)
{
    _pin = pin;
    _sensorOne = sensorOne;
    pinMode(pin, INPUT);
}

int IRSensor::getDistance()
{
    sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sensorReadings[i] = analogRead(_pin);
        sum += sensorReadings[i];
    }
    averageSensorReading = sum / 5;

    if (_shortRange == true)
    {
        calculatedDistance = sensorOneCoeffs[0] * exp(sensorOneCoeffs[1] * averageSensorReading) + sensorOneCoeffs[2] * exp(sensorOneCoeffs[3] * averageSensorReading);
    }
    else if (_shortRange == false)
    {
        calculatedDistance = sensorTwoCoeffs[0] * exp(sensorTwoCoeffs[1] * averageSensorReading) + sensorTwoCoeffs[2] * exp(sensorTwoCoeffs[3] * averageSensorReading);
    }

    return calculatedDistance;
}

int IRSensor::getSensorReading()
{
    return analogRead(_pin);
}
