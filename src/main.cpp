/*
 Gets a number (0 - 1) from serial and writes it with PWM to pins 32 and 33.
*/

#include <Arduino.h>
#include "valve.h"

const int pinHot = 32;
const int pinCold = 33;
#define FULL_DUTY 255
#define MAX_DUTY 190
#define CHANNEL_1 1
#define CHANNEL_2 2


Valve hot (pinHot, CHANNEL_1, FULL_DUTY, MAX_DUTY, 0.0, "Hot valve");
Valve cold(pinCold,CHANNEL_2, FULL_DUTY, MAX_DUTY, 0.0, "Cold valve");

void analogWrite(double flow) {
    hot.setFlow(flow);
    cold.setFlow(flow);
}
void setup() {
    Serial.begin(115200);
    
    hot.serialPrintInfo();
    cold.serialPrintInfo();
    Serial.println("Type in a real number from 0 to 1.\n");
    Serial.println("Where values:");
    Serial.println("    0 : Fully closes the valve.");
    Serial.println("  0.5 : Opens the valve half way.");
    Serial.println("    1 : Fully opens the valve.");
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