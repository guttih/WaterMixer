#include "arduino.h"
#include "valve_test.h"
#include "watermixer_test.h"
#include <unity.h>

void testValve(){
    Serial.println("------ Testing Valve -------");
    RUN_TEST(test_ValveConstructor);
    RUN_TEST(test_ValveSetFlow); 
    RUN_TEST(test_ValveWithLimitSetFlowAndGetPWM); 
    RUN_TEST(test_ValveGetPWM);
}

void testWaterMixer(){
    Serial.println("---- Testing WaterMixer ----");
    RUN_TEST(test_WaterMixerConstructor);
    RUN_TEST(test_WaterMixerConstructorWithValues);
    RUN_TEST(test_waterMixerChangeValues);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN();    
        testValve();
        testWaterMixer();
    UNITY_END();
}

void loop() {
}