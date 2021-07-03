#include "flowmocker.h"

FlowMocker::FlowMocker(double currentTemperature, unsigned long changeRate)
{
  init(currentTemperature, changeRate);
}

void FlowMocker::init(double currentTemperature, unsigned long changeRate)
{
  _currentTemperature = currentTemperature;
  setChangeRate(changeRate);
}

void FlowMocker::setChangeRate(unsigned long changeRate)
{
  _changeRate = changeRate;
  _changeStepCount = (float)_changeRate / (float)_changeStepDeltaInterval;
};

void FlowMocker::resetTemperatureChange()
{
  _changeStarted = 0;
  _changeWillEnd = 0;
  _changeStepDelta = 0;
}

void FlowMocker::setTemperature(double temperature)
{
  _targetTemperature = temperature;

  if (_targetTemperature == _currentTemperature)
  {
    resetTemperatureChange();
    return; //nothing to do
  }

  //dived time into steps

  Serial.print("changeRate_changeStepCount : ");
  Serial.println(_changeStepCount, 6);

  double totalChange = _targetTemperature - _currentTemperature;
  _changeStepDelta = totalChange / _changeStepCount;
  _changeStarted = millis();
  _changeWillEnd = _changeStarted + _changeRate;
};
void FlowMocker::calculateChange()
{

  if (_changeWillEnd == 0)
    return;

  unsigned long now = millis();
  if (now >= _changeWillEnd)
  {
    resetTemperatureChange();
    _currentTemperature = _targetTemperature;
    return;
  }

  unsigned long stepTime = now - _changeStarted;

  // Now we need to find which step we are in
  unsigned int stepNo = (stepTime / _changeStepDeltaInterval);
  unsigned int stepsFromTarget = _changeStepCount - stepNo;
  _currentTemperature = _targetTemperature - ((double)stepsFromTarget * _changeStepDelta);
};

void FlowMocker::setChangeStepInterval(unsigned long interval)
{
  _changeStepDeltaInterval = interval;
}