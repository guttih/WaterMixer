#include "arduino.h"
#include "valve.h"
#include "watermixer.h"
#include <unity.h>
    

//   WARNING DO NOT USE TEST_ASSERT_EQUAL for float or double.  
// the fraction part will not be compared then.  Use TEST_ASSERT_TRUE instead

const int defaultMixerPin1 = 32;
const int defaultMixerChannel1 = 1;
const int defaultMixerMaxPWM1 = 190;
const double defaultMixerFlow1 = 0.4;
const int defaultMixerPin2 = 33;
const int defaultMixerChannel2 = 2;
const int defaultMixerMaxPWM2 = 189;
const double defaultMixerFlow2 = 0.6;


void test_WaterMixerConstructor(void) {

    Valve hotValve(defaultMixerPin1, defaultMixerChannel1, defaultMixerMaxPWM1, defaultMixerFlow1, NULL);
    Valve coldValve(defaultMixerPin2, defaultMixerChannel2, defaultMixerMaxPWM2, defaultMixerFlow2, NULL);

    WaterMixer mixer(&hotValve, &coldValve);
    
    TEST_ASSERT_NOT_NULL_MESSAGE(mixer.getHotValve(), "getHotValve() should not be null NULL");
    TEST_ASSERT_NOT_NULL_MESSAGE(mixer.getColdValve(), "getColdValve() should not be null NULL");

    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, mixer.getCurrentTemperature(), "Defaut constructor should construct a WaterMixer object with current temperature as 0");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, mixer.getDesiredTemperature(), "Defaut constructor should construct a WaterMixer object with desired temperature as 0");
    TEST_ASSERT_TRUE_MESSAGE(mixer.getActive() == false, "Defaut constructor should construct an inactive WaterMixer object");
    
    TEST_ASSERT_EQUAL(defaultMixerPin1, mixer.getHotValve()->getPin());
    TEST_ASSERT_EQUAL(defaultMixerChannel1, mixer.getHotValve()->getChannel());
    TEST_ASSERT_EQUAL(defaultMixerMaxPWM1, mixer.getHotValve()->getMaxPWM());
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultMixerFlow1, mixer.getHotValve()->getFlow(), "Defaut constructor should HAVE set the flow on hot valve");

    TEST_ASSERT_EQUAL(defaultMixerPin2, mixer.getColdValve()->getPin());
    TEST_ASSERT_EQUAL(defaultMixerChannel2, mixer.getColdValve()->getChannel());
    TEST_ASSERT_EQUAL(defaultMixerMaxPWM2, mixer.getColdValve()->getMaxPWM());
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultMixerFlow2, mixer.getColdValve()->getFlow(), "Defaut constructor should HAVE set the flow on cold valve");
}

void test_WaterMixerConstructorWithValues(void) {

    Valve hotValve(defaultMixerPin1, defaultMixerChannel1, defaultMixerMaxPWM1, defaultMixerFlow1, NULL);
    Valve coldValve(defaultMixerPin2, defaultMixerChannel2, defaultMixerMaxPWM2, defaultMixerFlow2, NULL);

    WaterMixer mixer(&hotValve, &coldValve, 1.1, 2.001, true);
    
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.1,  mixer.getCurrentTemperature(), "Constructor should have set current temperature");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(2.001,  mixer.getDesiredTemperature(), "Constructor should have set  desired temperature");
    TEST_ASSERT_TRUE_MESSAGE(mixer.getActive(), "Constructor should set active to true");
    
}

void test_waterMixerChangeValues() {
    Valve hotValve(defaultMixerPin1, defaultMixerChannel1, defaultMixerMaxPWM1, defaultMixerFlow1, NULL);
    Valve coldValve(defaultMixerPin2, defaultMixerChannel2, defaultMixerMaxPWM2, defaultMixerFlow2, NULL);

    WaterMixer mixer(&hotValve, &coldValve);
    
    mixer.setCurrentTemperature(11.123456789);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(11.123456789 , mixer.getCurrentTemperature(), "setCurrentTemperature failed");

    mixer.setDesiredTemperature(22.12345678901);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(22.12345678901, mixer.getDesiredTemperature(), "getDesiredTemperature failed.");

    TEST_ASSERT_TRUE_MESSAGE(!mixer.getActive(), "default Constructor should set active to false");
    mixer.setActive(true);
    TEST_ASSERT_TRUE_MESSAGE(mixer.getActive(), "getActive should set active to true");
    

}
