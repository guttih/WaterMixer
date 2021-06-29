#include "arduino.h"
#include "valve.h"
#include "watermixer.h"
#include <unity.h>

void test_WaterMixerConstructor(void) {
    const int pin1 = 32;
    const int channel1 = 1;
    const int maxPWM1 = 190;
    const double flow1 = 0.4;
    const char *strHot = "Hot";
    const char *strCold = "Cold";
    const int pin2 = 33;
    const int channel2 = 2;
    const int maxPWM2 = 189;
    const double flow2 = 0.6;
    Valve hotValve(pin1, channel1, maxPWM1, flow1, strHot);
    Valve coldValve(pin2, channel2, maxPWM2, flow2, strCold);
    WaterMixer mixer(&hotValve, &coldValve);
    TEST_ASSERT_EQUAL(pin1, mixer.getHotValve()->getPin());
    TEST_ASSERT_EQUAL(channel1, mixer.getHotValve()->getChannel());
    TEST_ASSERT_EQUAL(maxPWM1, mixer.getHotValve()->getMaxPWM());
    TEST_ASSERT_EQUAL(flow1, mixer.getHotValve()->getFlow());
    TEST_ASSERT_EQUAL_STRING(strHot, mixer.getHotValve()->getName().c_str());

    TEST_ASSERT_EQUAL(pin2, mixer.getColdValve()->getPin());
    TEST_ASSERT_EQUAL(channel2, mixer.getColdValve()->getChannel());
    TEST_ASSERT_EQUAL(maxPWM2, mixer.getColdValve()->getMaxPWM());
    TEST_ASSERT_EQUAL(flow2, mixer.getColdValve()->getFlow());
    TEST_ASSERT_EQUAL_STRING(strCold, mixer.getColdValve()->getName().c_str());
}

// void test_waterMixerChangeTemp() {
//     TEST_ASSERT_EQUAL(1, 1);
// }
