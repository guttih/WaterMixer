#ifndef FLOWMOCKER_H
#define FLOWMOCKER_H

#include <Arduino.h>

class FlowMocker
{
    private:
      double _currentTemperature;
      double _targetTemperature;
      unsigned long _changeRate;
      unsigned long _changeStepDeltaInterval = 100; //100 millis is the minimum wait for any change
      unsigned long _changeStarted = 0;
      unsigned long _changeWillEnd = 0;
      double _changeStepCount = 0;
      double _changeStepDelta;
      
      void init(double currentTemperature, unsigned long changeRate);
      void resetTemperatureChange();
    public:
      FlowMocker(double currentTemperature = 0, unsigned long changeRate = 1000);
      double getTemperature() {return _currentTemperature;}
      unsigned long getChangeRate(){ return _changeRate; }
      void calculateChange();

      /**
      * @brief After setting a new temperature, how long should it take to change form current temperature to the new temperature. 
      * 
      * @param changeRate delay in in milliseconds.
      */
      void setChangeRate(unsigned long changeRate);
      void setChangeStepInterval(unsigned long interval);
      unsigned long getChangeStepInterval() { return _changeStepDeltaInterval; };
      void setTemperature(double temperature);
};

#endif