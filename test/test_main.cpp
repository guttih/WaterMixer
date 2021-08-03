#include "arduino.h"
#include "valve_test.h"
#include "watermixer_test.h"
#include "flowmocker_test.h"
#include <unity.h>


String repeat(String s, unsigned int count) {
    String str ="";
    for(unsigned int ui = 0; ui < count; ui++) {
        str.concat(s);
    }
    return str;
}
String concat(String str1, String str2, String str3) {
    String str = str1;
    str.concat(str2);
    str.concat(str3);
    return str;
}
void header(const char *strHeader) {
    String text = String(" - ") + String(strHeader) + String(" - ");
    int textLen = text.length();
    //frame length default is 50
    const int len = textLen > 46? (textLen+4) : 50;
    const int spaces = (len - textLen)-2;

    Serial.println(concat("┌", repeat("─", len-2), "┐"));
    Serial.println(concat("│", repeat(" ", len-2), "│"));
    int spaceLeft = spaces/2;
    int spaceRight = spaces - spaceLeft;    
    String frameLeft = concat("│", repeat(" ", spaceLeft), text);
    Serial.println(concat(frameLeft, repeat(" ", spaceRight), "│"));
    Serial.println(concat("│", repeat(" ", len-2), "│"));
    Serial.println(concat("└", repeat("─", len-2), "┘"));
}

void testValve(){
    header("Testing Valve");
    RUN_TEST(test_ValveConstructor);
    RUN_TEST(test_ValveSetFlow); 
    RUN_TEST(test_ValveWithLimitSetFlowAndGetPWM); 
    RUN_TEST(test_ValveGetPWM);
}
void testWaterMixer(){
    
    header("Testing WaterMixer");
    RUN_TEST(test_WaterMixerConstructor);
    RUN_TEST(test_WaterMixerConstructorWithValues);
    RUN_TEST(test_waterMixerChangeValues);
}

void testFlowMocker() {
    header("Thesting FlowMocker");
    RUN_TEST(test_FlowMockerConstructor);
    RUN_TEST(test_FlowMockerSetChangeRate);
    RUN_TEST(test_FlowMockerCalTwicePerIterateChange);
    RUN_TEST(test_FlowMockerTestChange);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN();    
        testValve();
        //testFlowMocker();
        testWaterMixer();
    UNITY_END();
}

void loop() {
}