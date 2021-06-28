/*
 Gets a number (0- 190) from serial and writes it with PWM to pins 32 and 33.
*/

#include <Arduino.h>
#include "valve.h"

const int POWERPIN_1 = 32;
const int POWERPIN_2 = 33;
#define MAXINPUT 255
#define CHANNEL_1 1
#define CHANNEL_2 2
const int SAVE_MAX = 190; //value must not be more because voltage must not go over 5 volts (excact 5.06V)


 #define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     8100

int outputValue = 0;
int inputValue = 0;  
     
void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax) {
    // calculate duty    
    uint32_t duty = (LEDC_BASE_FREQ / valueMax) * ((value) < (valueMax) ? (value) : (valueMax));
    Serial.print("Analog Writing duty " + String(duty) + " to channel " + String(channel));
    Serial.println(" pin: " + String(channel == CHANNEL_1? POWERPIN_1 : POWERPIN_2));
   
    // write duty to LEDC
    ledcWrite(channel, duty);
}
void analogWrite(int power) {
    ledcAnalogWrite(CHANNEL_1, power, MAXINPUT);
    ledcAnalogWrite(CHANNEL_2, power, MAXINPUT);
}
void setup() {
    Valve hot(1,2,3, "Hot valve");
    Valve cold(4,5,5, "Cold valve");
    ledcAttachPin(POWERPIN_1, CHANNEL_1);
    ledcAttachPin(POWERPIN_2, CHANNEL_2);
    ledcSetup(CHANNEL_1, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
    ledcSetup(CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
    Serial.begin(115200);
    Serial.print("OUTPUT pin 1 is number: ");Serial.print(POWERPIN_1);
    Serial.print(" and pin 2 is number: ");Serial.println(POWERPIN_2);
    analogWrite(outputValue);
}

void loop() {
    while (Serial.available() > 0) {
        int didRead = Serial.parseInt();
        if (Serial.read() == '\n') {
            outputValue = constrain(didRead, 0, SAVE_MAX);
            Serial.print("Got value : "); Serial.print(didRead );
            if  (didRead != outputValue){
                Serial.print(".  Converted it to "); Serial.print(outputValue );
            }
            Serial.println();
        }
        analogWrite(outputValue);
        Serial.print("Output: (0 - ");
        Serial.print(MAXINPUT);Serial.print("): ");  
        Serial.println(outputValue);
    }
    delay(200);
}