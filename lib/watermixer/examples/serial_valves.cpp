/*
    serial_valves.cpp
 Gets values (0 - 1) from serial and writes it with PWM to pins 32 and 33.

 Type to the serial character c or h followed by a real number to 
 change the opining of one of the two valves.
*/

#include <Arduino.h>
#include "valve.h"

const int pinHot = 32;
const int pinCold = 33;
#define FULL_DUTY 255
#define MAX_DUTY 190
#define CHANNEL_1 1
#define CHANNEL_2 2

Valve hot(pinHot, CHANNEL_1, FULL_DUTY, MAX_DUTY, 0.0, "Hot valve");
Valve cold(pinCold, CHANNEL_2, FULL_DUTY, MAX_DUTY, 0.0, "Cold valve");

void setup()
{
    Serial.begin(115200);

    hot.serialPrintInfo();
    cold.serialPrintInfo();
    Serial.println("Type character c or h followed by a real number to change the opining of one of the two valves.\n");
    Serial.println("Where values:");
    Serial.println("   h0 : Fully closes the hot valve.");
    Serial.println(" c0.5 : Opens the cold valve half way.");
    Serial.println("   c1 : Fully opens the cold valve.");
}

String strInput = "";
char c;

void loop()
{
    while (Serial.available() > 0)
    {
        c = Serial.read();
        if (c == '\n')
        {
            Serial.print("Got string : \"");
            strInput.toUpperCase();
            Serial.print(strInput + "\" ");
            if (strInput.length() < 2)
            {
                Serial.println(" Invalid input");
            }
            else
            {
                if (strInput.startsWith("H"))
                {
                    double value = strInput.substring(1).toFloat();
                    Serial.print(String(" New value: ") + String(value) + " -> ");
                    hot.setFlow(value);
                }
                else if (strInput.startsWith("C"))
                {
                    double value = strInput.substring(1).toFloat();
                    Serial.print(String(" New value: ") + String(value) + " -> ");
                    cold.setFlow(value);
                }
                else
                {
                    Serial.println(" Invalid input");
                }
            }
            strInput = "";
        }
        else
        {
            strInput += c;
        }
    }
    delay(200);
}