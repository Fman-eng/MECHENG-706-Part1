#include "Arduino.h"
#include "IRSensor.h"

IRSensor::IRSensor(uint8_t pin, bool shortRange){
    _pin = pin;
    _shortRange = shortRange;
    pinMode(pin, INPUT);
}

int IRSensor::getDistance(){
    sum = 0;

    for(int i = 0; i<5; i++){
        sensorReadings[i] = analogRead(_pin);
        sum += sensorReadings[i];
    }
        averageSensorReading = sum/5;
        
        if(_shortRange == true){
            calculatedDistance = shortModelCoeffs[0]*exp(shortModelCoeffs[1]*averageSensorReading)+shortModelCoeffs[2]*exp(shortModelCoeffs[3]*averageSensorReading);
        }else if(_shortRange == false){
            calculatedDistance = longModelCoeffs[0]*exp(longModelCoeffs[1]*averageSensorReading)+longModelCoeffs[2]*exp(longModelCoeffs[3]*averageSensorReading);
        }

    return calculatedDistance;
}

int IRSensor::getSensorReading(){
    return analogRead(_pin);
}