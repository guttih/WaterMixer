#include "valve.h"

/**
 * @brief Construct a new Servo:: Servo object
 * 
 * @param pin 
 * @param maxAngle 
 * @param channel 
 */
Valve::Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, const char *name)
{
  //use the defaults
  init(pin, channel, maxPWM, name);
}

void Valve::init(uint16_t pin, uint16_t channel, uint16_t maxPWM, const char *name)
{
  _pin = pin;
  _maxPWM = _maxPWM;
  _channel = channel;
  _name = name;
  setDebugMode(_name != NULL);
  pinMode(_pin, OUTPUT);
  ledcAttachPin(_pin, _channel);
  ledcSetup(_channel, 50, 16);

}

void Valve::setDebugMode(bool activate)
{
  _debugging = activate;
}