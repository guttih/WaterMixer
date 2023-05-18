#include "arduino.h"
#include "valve.h"
#include "watermixer.h"
#include <unity.h>

#include <Adafruit_MCP4728.h>    

//   WARNING DO NOT USE TEST_ASSERT_EQUAL for float or double.  
// the fraction part will not be compared then.  Use TEST_ASSERT_TRUE instead

const channel channelHot = MCP4728_CHANNEL_A;
const channel channelCold = MCP4728_CHANNEL_B;
const channel channelDrain = MCP4728_CHANNEL_D;

void test_WaterMixerConstructor(void) {

    

    WaterMixer mixer(MCP4728_CHANNEL_A, MCP4728_CHANNEL_B, MCP4728_CHANNEL_D, 0, 0);

    // TEST_ASSERT_NOT_NULL_MESSAGE(mixer.getHotValve(), "getHotValve() should not be null NULL");
    // TEST_ASSERT_NOT_NULL_MESSAGE(mixer.getColdValve(), "getColdValve() should not be null NULL");

    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, mixer.getCurrentTemperature(), "Defaut constructor should construct a WaterMixer object with current temperature as 0");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, mixer.getDesiredTemperature(), "Defaut constructor should construct a WaterMixer object with desired temperature as 0");
    TEST_ASSERT_TRUE_MESSAGE(mixer.getMode() == MANUAL, "Defaut constructor should construct WaterMixer object set to mode MANUAL");
    
    TEST_ASSERT_EQUAL(channelHot, mixer.getHotValve()->getChannel());
    mixer.getHotValve()->setFullOpenValue(1000);
    TEST_ASSERT_EQUAL(1000, mixer.getHotValve()->getFullOpenValue());

    mixer.getHotValve()->setFlow(60);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(60, mixer.getHotValve()->getFlow(), "Defaut constructor should HAVE set the flow on hot valve");

    TEST_ASSERT_EQUAL(channelCold, mixer.getColdValve()->getChannel());

    mixer.getColdValve()->setFullOpenValue(2000);
    TEST_ASSERT_EQUAL(2000, mixer.getColdValve()->getFullOpenValue());
    mixer.getColdValve()->setFlow(90);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(90, mixer.getColdValve()->getFlow(), "Defaut constructor should HAVE set the flow on cold valve");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(2000 * 0.9, mixer.getColdValve()->getValue(), "Defaut constructor should HAVE set the flow on cold valve");
    
    mixer.getDrainValve()->setFullOpenValue(3000);
    TEST_ASSERT_EQUAL(3000, mixer.getDrainValve()->getFullOpenValue());
}

void test_WaterMixerConstructorWithValues(void) {

    WaterMixer mixer(channelHot, channelCold, channelDrain, 1.1, 2.001, 4.33);
    
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.1,  mixer.getCurrentTemperature(), "Constructor should have set current temperature");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(2.001,  mixer.getDesiredTemperature(), "Constructor should have set  desired temperature");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(4.33,  mixer.getCurrentPressure(), "Constructor should have set  current pressure");
    TEST_ASSERT_TRUE_MESSAGE(MANUAL == mixer.getMode(), "Constructor should set manual");
    
}

void test_waterMixerChangeValues() {
    WaterMixer mixer(channelHot, channelCold, channelDrain, 0, 0, 0);
    mixer.getHotValve()->setValue(5000);
    mixer.begin(13, 14);
    TEST_ASSERT_EQUAL(4095, mixer.getHotValve()->getValue());
    
    mixer.setCurrentTemperature(11.123456789);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(11.123456789 , mixer.getCurrentTemperature(), "setCurrentTemperature failed");

    mixer.setDesiredTemperature(22.12345678901);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(22.12345678901, mixer.getDesiredTemperature(), "getDesiredTemperature failed.");
    TEST_ASSERT_TRUE_MESSAGE(MANUAL == mixer.getMode(), "default Constructor should set mode to MANUAL");
    mixer.setMode(AUTOMATIC);
    TEST_ASSERT_TRUE_MESSAGE(AUTOMATIC == mixer.getMode(), "getMode should set active to true");
}

void test_waterMixerToJson() {
    
    WaterMixer mixer(channelHot, channelCold, channelDrain, 1, 2, 3);
    // mixer.getHotValve()->setValue(5000);
    // mixer.begin(13, 14);
    String str = mixer.toJson();
    TEST_ASSERT_TRUE_MESSAGE(str.startsWith("{"),"json string should start with {" );
    TEST_ASSERT_TRUE_MESSAGE(str.endsWith("}"),"json string should end with }" );
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"hotValveFlow\":")       > -1,"json string missing hotValveFlow");
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"coldValveFlow\":")      > -1,"json string missing coldValveFlow");
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"drainValveFlow\":")     > -1,"json string missing drainValveFlow");
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"currentTemperature\":") > -1,"json string missing currentTemperature");
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"desiredTemperature\":") > -1,"json string missing desiredTemperature");
    TEST_ASSERT_TRUE_MESSAGE(str.indexOf("\"currentPressure\":")   > -1,"json string missing currentPressure");
    
    Serial.println(str);

}

void test_waterMixerMapValue() {
    
    WaterMixer mixer(channelHot, channelCold, channelDrain, 1, 2, 3);
    TEST_ASSERT_EQUAL_DOUBLE(   0, mixer.mapValue(0,     100, 1023));
    TEST_ASSERT_EQUAL_DOUBLE(   1, mixer.mapValue(0.1,   100, 1023));
    TEST_ASSERT_EQUAL_DOUBLE(   2, mixer.mapValue(0.244, 100, 1023));
    TEST_ASSERT_EQUAL_DOUBLE(   3, mixer.mapValue(0.245, 100, 1023));
    TEST_ASSERT_EQUAL_DOUBLE( 512, mixer.mapValue(50,    100, 1023));
    TEST_ASSERT_EQUAL_DOUBLE(1023, mixer.mapValue(100,   100, 1023));
}
