#include "arduino.h"
#include "valve.h"
#include <unity.h>

const int defaultValvePin = 32;
const int defaultValveChannel = 1;
const int defaultValveMaxPWM = 255;
const double defaultValveFlow = 0.5;
const char *defaultValveStrHot = "Hot";

void test_ValveConstructor(void)
{

    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, defaultValveFlow);
    valve.serialPrintInfo();
    valve.setDebugMode(false);
    TEST_ASSERT_EQUAL(defaultValvePin, valve.getPin());
    TEST_ASSERT_EQUAL(defaultValveChannel, valve.getChannel());
    TEST_ASSERT_EQUAL(defaultValveMaxPWM, valve.getMaxPWM());
    TEST_ASSERT_EQUAL(defaultValveFlow, valve.getFlow());
    TEST_ASSERT_EQUAL_STRING("", valve.getName().c_str());
}

void test_ValveSetFlow(void)
{

    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, 0);
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

void test_ValveSetFlowAndGetPWM()
{
    const int newLimit = 190;
    Serial.println("test_ValveSetFlowAndGetPWM - testing if setFlow and PWM are in sync when pwm is limited");
    Valve valve(defaultValvePin, defaultValveChannel, defaultValveMaxPWM, newLimit, 0, "Test valve");
    valve.serialPrintInfo();
    double percentage;
    percentage  = 0;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL(0, valve.getPWM());

    Serial.println("setFlow should set PWM");
    percentage = 0.33;     valve.setFlow(percentage);   TEST_ASSERT_EQUAL(round(newLimit * percentage), valve.getPWM());
    percentage = 1;        valve.setFlow(percentage);   TEST_ASSERT_EQUAL(round(newLimit * percentage), valve.getPWM());
    percentage = 0.9999999;valve.setFlow(percentage);   TEST_ASSERT_EQUAL(round(newLimit * percentage), valve.getPWM());

    Serial.println("PWM must not exceed max limit");
    percentage = 1.001;    valve.setFlow(percentage);   TEST_ASSERT_EQUAL(newLimit, valve.getPWM());
    percentage =  2;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL(newLimit, valve.getPWM());

    Serial.println("PWM must not be less than null");
    percentage = -2;       valve.setFlow(percentage);   TEST_ASSERT_EQUAL(0, valve.getPWM());
    percentage = -0.1;     valve.setFlow(percentage);   TEST_ASSERT_EQUAL(0, valve.getPWM());
}

void test_ValveGetPWM(void)
{
    const int newLimit = 190;
    const uint16_t maxPWM = 255;

    Serial.println(String("Setting limit to ") + newLimit);
    Serial.println("No flow");
    Valve valve(defaultValvePin, defaultValveChannel, maxPWM, newLimit, 0, defaultValveStrHot);
    valve.serialPrintInfo();
    TEST_ASSERT_EQUAL(0, valve.getPWM());

    Serial.println("Full flow");
    valve.setFlow(1);
    TEST_ASSERT_EQUAL(newLimit, valve.getPWM());

    Serial.println("Half flow");
    valve.setFlow(0.5);
    TEST_ASSERT_EQUAL(newLimit / 2, valve.getPWM());

    Serial.println("10% flow");
    valve.setFlow(0.1);
    TEST_ASSERT_EQUAL(newLimit / 10, valve.getPWM());

    TEST_ASSERT_EQUAL_STRING(defaultValveStrHot, valve.getName().c_str());
}
