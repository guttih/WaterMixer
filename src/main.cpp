/*
 Gets a number (0- 190) from serial and writes it with PWM to pins 32 and 33.
*/

#include <Arduino.h>
#include "valve.h"

const int POWERPIN_1 = 32;
const int POWERPIN_2 = 33;
#define FULL_DUTY 255
#define MAX_DUTY 190
#define CHANNEL_1 1
#define CHANNEL_2 2


Valve hot (POWERPIN_1, CHANNEL_1, FULL_DUTY, MAX_DUTY, 0.0,"Hot valve");
Valve cold(POWERPIN_2,CHANNEL_2, FULL_DUTY, MAX_DUTY, 0.0,"Cold valve");

void analogWrite(double flow) {
    
    hot.setFlow(flow);
    cold.setFlow(flow);
}
void setup() {
    Serial.begin(115200);
    
    hot.serialPrintInfo();
    cold.serialPrintInfo();

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