#include "arduino.h"
#include "PidController.h"
#include "test_functions.h"


//   WARNING DO NOT USE TEST_ASSERT_EQUAL for float or double.  
// the fraction part will not be compared then.  Use TEST_ASSERT_TRUE instead

void test_PidConstructor(void) {
    PidController pid;
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.1, pid.getKp(), "Kp should be 0.1");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.1, pid.getKi(), "Ki should be 0.1");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.1, pid.getKd(), "Kd should be 0.1");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0, pid.getSuggestedValue(), "SuggestedValue should be 0.0");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0, pid.getCurrentValue(), "CurrentValue should be 0.0");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0, pid.getDesiredValue(), "DesiredValue should be 0.0");
    TEST_ASSERT_EQUAL(false, pid.isAutomaticModeOn());
    double d = pid.getDesiredValue();
       
}

void test_PidChangeValue(void) {
    header("test_PidChangeValue");
    PidController pid;
    pid.setDesiredValue(-10.0);
    TEST_ASSERT_EQUAL_DOUBLE(-10.0, pid.getDesiredValue());
    pid.setDesiredValue(20.123456);
    TEST_ASSERT_EQUAL_DOUBLE(20.123456, pid.getDesiredValue());
    
       
}

