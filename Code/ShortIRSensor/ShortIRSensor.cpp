#include "Arduino.h"
#include "ShortIRSensor.h"

ShortIRSensor::ShortIRSensor(uint8_t pin){
    _pin = pin;
    pinMode(pin, INPUT);

}

ShortIRSensor::getDistance(){
    sum = 0;

    for(int i = 0; i<5; i++){
        sensorReadings[i] = analogRead(_pin);
        sum += sensorReadings[i];
    }
        averageSensorReading = sum/5;

        calculatedDistance = modelCoeffs[0]*exp(modelCoeffs[1]*averageSensorReading)+modelCoeffs[2]*exp(modelCoeffs[3]*averageSensorReading);

    return calculatedDistance;
}

ShortIRSensor::getSensorReading(){
    return analogRead(_pin);
}