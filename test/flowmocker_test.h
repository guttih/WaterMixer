#include "arduino.h"
#include "flowmocker.h"
#include <unity.h>

void test_FlowMockerConstructor()
{
	FlowMocker flowA;
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0, flowA.getTemperature(), "Default constructor with no parameter should set temperature to 0");
	TEST_ASSERT_EQUAL_MESSAGE(1000, flowA.getChangeRate(), "Default constructor should set change rate to 1000");
	
	FlowMocker flowB(2.234);
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(2.234, flowB.getTemperature(), "Default constructor should set temperature to 2.234");
	TEST_ASSERT_EQUAL_MESSAGE(1000, flowB.getChangeRate(), "Default constructor should set change rate to 1000");
	
	FlowMocker flowC(4.321, 1234);
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(4.321, flowC.getTemperature(), "Default constructor should set temperature to 4.321");
	TEST_ASSERT_EQUAL_MESSAGE(1234, flowC.getChangeRate(), "Default constructor should set change rate to 1234");
}

void test_FlowMockerSetChangeRate()
{
	FlowMocker flow;
	flow.setChangeRate(21000);
	TEST_ASSERT_EQUAL_MESSAGE(21000, flow.getChangeRate(), "Default constructor should set temperature to 2.234");
}

void test_FlowMockerExecuteChange()
{
	bool printToSerial = true;
	double targetTemp = 12;
	double beforeTemp = 3;
	double valueShouldBe;

	unsigned long changeTimeMs = 2000;
	FlowMocker flow(beforeTemp, changeTimeMs);
	flow.setTemperature(targetTemp);
	flow.calculateChange();
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(beforeTemp, flow.getTemperature(), "Current temperature should be un changed.");

	unsigned int stepCount = flow.getChangeRate()/flow.getChangeStepInterval();
	if (printToSerial)
		Serial.println(String("stepCount:")+String(stepCount).toInt());

	double stepDeltaValue = (targetTemp-beforeTemp)/(double)stepCount;
	if (printToSerial)
		Serial.println(String("Step delta:")+String(stepDeltaValue).toDouble());

	for(int i = 1; i < stepCount+1; i++) {
		delay(flow.getChangeStepInterval());
		flow.calculateChange();
		valueShouldBe = i * stepDeltaValue + beforeTemp;
		if (printToSerial)
			Serial.println(String(i)+String(": ")+String("Temp:")+String(flow.getTemperature()+String("  valueShouldBe:")+String(valueShouldBe).toDouble()));
		TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(valueShouldBe, flow.getTemperature(), String(String("Current temperature should be ") + String(valueShouldBe).toDouble()).c_str());
		
	}
	
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(12, flow.getTemperature(), "Current temperature should be target temp now");

}