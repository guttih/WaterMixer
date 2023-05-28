#include "arduino.h"
#include "watermixer_test.h"
#include "pid_test.h"
#include <unity.h>



void testWaterMixer(){
    
    header("Testing WaterMixer");
    RUN_TEST(test_waterMixerMapValue);
    RUN_TEST(test_waterMixerToJson);
    RUN_TEST(test_WaterMixerConstructor);
    RUN_TEST(test_WaterMixerConstructorWithValues);
    // RUN_TEST(test_waterMixerChangeValues);
    
}

void testPID(){
    
    header("Testing PID");
    RUN_TEST(test_PidConstructor);
    RUN_TEST(test_PidChangeValue);
    
    
}


PidController pid();

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    
    Serial.begin(115200);
    delay(2000);
    header("Verbose printing tests");

    UNITY_BEGIN();    
        testWaterMixer();
        testPID();

    UNITY_END();
}

void loop() {
}