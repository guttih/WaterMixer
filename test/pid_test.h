#include "arduino.h"
#include "PidController.h"
#include <unity.h>

//   WARNING DO NOT USE TEST_ASSERT_EQUAL for float or double.  
// the fraction part will not be compared then.  Use TEST_ASSERT_TRUE instead

void test_PidConstructor(void) {
    PidController pid();
    TEST_ASSERT_EQUAL(1, pid.GetKp());
    TEST_ASSERT_EQUAL(2, pid.GetKi());
    TEST_ASSERT_EQUAL(1.5, pid.GetKd());
    TEST_ASSERT_EQUAL(0.1, pid.GetSetpoint());
    TEST_ASSERT_EQUAL(0.2, pid.GetInput());
    TEST_ASSERT_EQUAL(0.3, pid.GetOutput());
    TEST_ASSERT_EQUAL(0.4, pid.GetSampleTime());
    TEST_ASSERT_EQUAL(0, pid.GetMode());
    TEST_ASSERT_EQUAL(0, pid.GetDirection());
    TEST_ASSERT_EQUAL(0, pid.GetPOn());
       
}

