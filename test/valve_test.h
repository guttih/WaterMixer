#include "arduino.h"
#include "valve.h"
#include <unity.h>

 const int defaultValvePin = 32;
const int defaultValveChannel = 1;
const int defaultValveMaxPWM = 255;
const double defaultValveFlow = 0.5;
const char *defaultValveStrHot = "Hot";

void test_ValveConstructor(void) {

    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, defaultValveFlow, defaultValveStrHot);
    TEST_ASSERT_EQUAL(defaultValvePin, valve.getPin());
    TEST_ASSERT_EQUAL(defaultValveChannel, valve.getChannel());
    TEST_ASSERT_EQUAL(defaultValveMaxPWM, valve.getMaxPWM());
    TEST_ASSERT_EQUAL(defaultValveFlow, valve.getFlow());
    TEST_ASSERT_EQUAL_STRING(defaultValveStrHot, valve.getName());
}

void test_ValveChangeFlow(void) {


    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, 0, defaultValveStrHot);
    TEST_ASSERT_EQUAL(0, valve.getFlow());


    valve.setFlow(0);
    TEST_ASSERT_EQUAL(0, valve.getFlow());
    valve.setFlow(0.3);
    TEST_ASSERT_EQUAL(0.3, valve.getFlow());
    valve.setFlow(1);
    TEST_ASSERT_EQUAL(1, valve.getFlow());
    valve.setFlow(0.9999999);
    TEST_ASSERT_EQUAL(0.9999999, valve.getFlow());

    //test off limits
    valve.setFlow(1.001);
    TEST_ASSERT_EQUAL(1, valve.getFlow());
    valve.setFlow(2);
    TEST_ASSERT_EQUAL(1, valve.getFlow());

    valve.setFlow(-2);
    TEST_ASSERT_EQUAL(0, valve.getFlow());
    valve.setFlow(-0.1);
    TEST_ASSERT_EQUAL(0, valve.getFlow());
}

void test_ValveGetPWM(void) {
    const uint16_t maxPWM = 255;
    const uint16_t halfPWM = 128;
    Valve valve(defaultValvePin, defaultValveChannel, maxPWM, 0, defaultValveStrHot);
    TEST_ASSERT_EQUAL(0, valve.getPWM());
    
    valve.setFlow(0.5);
    TEST_ASSERT_EQUAL(halfPWM, valve.getPWM());

    valve.setFlow(1);
    TEST_ASSERT_EQUAL(maxPWM, valve.getPWM());

     valve.setFlow(0.1);
    TEST_ASSERT_EQUAL(26, valve.getPWM());
}
