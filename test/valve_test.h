#include "arduino.h"
#include "valve.h"
#include <unity.h>

//   WARNING DO NOT USE TEST_ASSERT_EQUAL for float or double.  
// the fraction part will not be compared then.  Use TEST_ASSERT_TRUE instead.

const int defaultValvePin = 32;
const int defaultValveChannel = 1;
const int defaultValveMaxPWM = 255;
const double defaultValveFlow = 0.5;
const char *defaultValveStrHot = "Hot";

void test_ValveConstructor(void)
{
    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, defaultValveFlow, defaultValveStrHot);
    valve.serialPrintInfo();
    TEST_ASSERT_EQUAL_MESSAGE(defaultValvePin, valve.getPin(), "Constructor should have set pin");
    TEST_ASSERT_EQUAL_MESSAGE(defaultValveChannel, valve.getChannel(), "Constructor should have set channel");
    TEST_ASSERT_EQUAL_MESSAGE(defaultValveMaxPWM, valve.getMaxPWM(), "Constructor should have set PWM");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultValveFlow, valve.getFlow(), "Constructor should have set the flow");
    TEST_ASSERT_EQUAL_STRING_MESSAGE(defaultValveStrHot, valve.getName().c_str(), "Constructor should have set the name");

    //testing if correct constructor is selected when name is not specified.
     Valve valve2(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, defaultValveFlow);
     TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultValveFlow, valve2.getFlow(), "Constructor should have set the flow to half");
     TEST_ASSERT_EQUAL_STRING_MESSAGE("", valve2.getName().c_str(), "getName() should have returned empty string because the _name should be NULL.");

     Valve valve3(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, 190, defaultValveFlow, NULL);
     TEST_ASSERT_EQUAL_MESSAGE(190, valve3.getLimitPWM(), "Constructor should have set the PWM limit");
     TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultValveFlow, valve3.getFlow(), "Constructor should have set the flow to half");
     TEST_ASSERT_EQUAL_STRING_MESSAGE("", valve3.getName().c_str(), "getName() should have returned empty string because the _name should be NULL.");

     Valve valve4(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, 190, defaultValveFlow, "another valve name");
     TEST_ASSERT_EQUAL_MESSAGE(190, valve4.getLimitPWM(), "Constructor should have set the PWM limiT");
     TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(defaultValveFlow, valve4.getFlow(), "Constructor should have set the flow to half");
     TEST_ASSERT_EQUAL_STRING_MESSAGE("another valve name", valve4.getName().c_str(), "Name should be 'another valve name'");
}

void test_ValveSetFlow(void)
{
    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, 0);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, valve.getFlow(), "Constructor should have set flow to 0");

    valve.setFlow(0.1);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.1, valve.getFlow(), "setFlow should have set flow");
    valve.setFlow(0.12345678901);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.12345678901, valve.getFlow(), "setFlow should have set flow to 0.12345678901");
    valve.setFlow(1);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1, valve.getFlow(), "setFlow should have set flow to 1");
    valve.setFlow(0.9999999);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.9999999, valve.getFlow(), "setFlow should have set flow to 0.9999999");

    //test off limits
    valve.setFlow(1.001);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1, valve.getFlow(), "flow must not exceed 1");
    valve.setFlow(2);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1, valve.getFlow(), "flow must not exceed 1");

    valve.setFlow(-2);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, valve.getFlow(), "flow must not be less than 0");
    valve.setFlow(-0.1);
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, valve.getFlow(), "flow must not be less than 0");
}

void test_ValveWithLimitSetFlowAndGetPWM()
{
    const int newLimit = 190;
    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, newLimit, 0, NULL);
    //valve.serialPrintInfo();
    double percentage;
    percentage  = 0;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(0, valve.getPWM(), "SetFlow failed to set PWM to 0");
    percentage = 0.33;     valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(round(newLimit * percentage), valve.getPWM(), "SetFlow failed to set PWM to 0.33");
    percentage = 1;        valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(round(newLimit * percentage), valve.getPWM(), "SetFlow failed to set PWM to 1");
    percentage = 0.9999999;valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(round(newLimit * percentage), valve.getPWM(), "SetFlow failed to set PWM to 0.9999999");

    percentage = 1.001;    valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(newLimit, valve.getPWM(), "PWM must not exceed max limit");
    percentage =  2;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(newLimit, valve.getPWM(), "PWM must not exceed max limit");

    percentage = -2;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(0, valve.getPWM(),"PWM must not be less than 0");
    percentage = -0.1;     valve.setFlow(percentage);   TEST_ASSERT_EQUAL_MESSAGE(0, valve.getPWM(),"PWM must not be less than 0");
}

void test_ValveGetPWM(void)
{
    const int newLimit = 190;
    const uint16_t maxPWM = 255;

    //No flow
    Valve valve(defaultValvePin, defaultValveChannel, maxPWM, newLimit, 1, defaultValveStrHot);
    valve.serialPrintInfo();
    TEST_ASSERT_EQUAL_MESSAGE(newLimit, valve.getPWM(), "Constructor should have set flow to 1 and getPWM should return newLimit");

    valve.setFlow(0);
    TEST_ASSERT_EQUAL_MESSAGE(0, valve.getPWM(), "PWM should be 0");

    Serial.println("Half flow");
    valve.setFlow(0.5);
    TEST_ASSERT_EQUAL_MESSAGE(newLimit / 2, valve.getPWM(), "PWM should be half");

    valve.setFlow(0.1);
    TEST_ASSERT_EQUAL_MESSAGE(newLimit / 10, valve.getPWM(), "PWM should be 10%");

    TEST_ASSERT_EQUAL_STRING(defaultValveStrHot, valve.getName().c_str());
}
