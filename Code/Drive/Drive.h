#define LED_1_PIN 9
class Led {
    // class definition
};
Led led1(LED_1_PIN);
void setup() { }
void loop() {
    led1.on();
    delay(500);
    led.off();
    delay(500);
 