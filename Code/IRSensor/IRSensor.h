#ifndef IRSensor_h
#define IRSensor_h

#include "Arduino.h"

class IRSensor
{
    public:
        IRSensor(uint8_t pin, bool shortRange);
        int getDistance();
        int getSensorReading();
    private:
        uint8_t _pin;
        bool _shortRange;
        int sensorReadings[5];
        float shortModelCoeffs[4] = {992.4, -0.02274, 197.6, -0.002979};
        float longModelCoeffs[4] = {99.24, -0.002274, 19.76, -0.0002979};
        int sum;
        int averageSensorReading;
        int calculatedDistance;
};

#endif