
#ifndef SonarSensor_h
#define SonarSensor_h

#include "Arduino.h"


class SonarSensor
{
    public:
    SonarSensor(int triggerPin, int echoPin);
    int getDistance();
    
    private:
    int _triggerPin;
    int _echoPin;
    
    long startMicros;
    long endMicros;
    long duration;

    int timeoutCounter;
};

#endif