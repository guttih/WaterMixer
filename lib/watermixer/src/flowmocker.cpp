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
  _changeStepCount = (double)_changeRate / (double)_changeStepDeltaInterval;
};

void FlowMocker::setChangeStepInterval(unsigned long interval)
{
  _changeStepDeltaInterval = interval;
  _changeStepCount = (double)_changeRate / (double)_changeStepDeltaInterval;
}

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

  if (stepNo < 1)
    return; //We will not change current _currentTemperature until first interval is reached

  unsigned int stepsFromTarget = _changeStepCount - stepNo;
  _currentTemperature = _targetTemperature - ((double)stepsFromTarget * _changeStepDelta);
};

