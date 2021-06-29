#include "arduino.h"
#include "valve_test.h"
#include "watermixer_test.h"
#include <unity.h>


void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN();    // IMPORTANT LINE!
    RUN_TEST(test_ValveConstructor);
    RUN_TEST(test_ValveSetFlow); 
    RUN_TEST(test_ValveSetFlowAndGetPWM); 
    RUN_TEST(test_WaterMixerConstructor); 
    RUN_TEST(test_ValveGetPWM);
    
    UNITY_END();
}

void loop() {
}