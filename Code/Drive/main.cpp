#include "Drive.h"
#define LEFT_FRONT 46
#define LEFT_REAR 47
#define RIGHT_REAR 50
#define RIGHT_FRONT 51

Drive drive1(LEFT_FRONT, LEFT_REAR, RIGHT_REAR, RIGHT_FRONT);

void setup() { 
    Serial.begin(9600);}
void loop() {
    drive1.Forward();
    delay(2000);
    drive1.Halt();
    delay(5000);
}