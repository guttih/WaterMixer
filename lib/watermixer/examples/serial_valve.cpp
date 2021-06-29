/*
 Gets a number (0 - 1) from serial and writes it with PWM to pins 32.
*/

#include <Arduino.h>
#include "valve.h"

const int pinHot = 32;
#define FULL_DUTY 255
#define MAX_DUTY 190
#define CHANNEL_1 1

Valve hot (pinHot, CHANNEL_1, FULL_DUTY, MAX_DUTY, 0.0, "Hot valve");

void analogWrite(double flow) {
    
    hot.setFlow(flow);
}
void setup() {
    Serial.begin(115200);
    hot.serialPrintInfo();

    Serial.println("Type in a real number from 0 to 1.  For example 0.23");
}

void loop() {
    while (Serial.available() > 0) {
        double didRead = Serial.parseFloat();
        if (Serial.read() == '\n') 
        {
            Serial.print("Got value : "); Serial.println(didRead );
        }
        analogWrite(didRead);
    }
    delay(200);
}