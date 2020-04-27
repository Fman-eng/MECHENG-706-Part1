
#ifndef SonarSensor_h
#define SonarSensor_h

#include "Arduino.h"


class SonarSensor
{
    public:
    SonarSensor(int triggerPin, int echoPin);
    float getDistance();
    
    private:
    int _triggerPin;
    int _echoPin;
    
    //float duration;
};

#endif
