#ifndef ShortIRSensor_h
#define ShortIRSensor_h

#include "Arduino.h"

class ShortIRSensor
{
    public:
        ShortIRSensor(uint8_t pin);
        int getDistance();
        int getSensorReading();
    private:
        uint8_t _pin;
        int sensorReadings[5];
        float modelCoeffs[4] = {992.4, -0.02274, 197.6, -0.002979};
        int sum;
        int averageSensorReading;
        int calculatedDistance;
};

#endif