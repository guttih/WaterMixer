#include "valve.h"

Valve::Valve()
{
    //init(MCP4728_CHANNEL_A, 0);
}

void Valve::init(Adafruit_MCP4728 *dac, channel channel, uint16_t value, uint16_t fullOpenValue)
{
    _dac = dac;
    _channel = channel;
    setFullOpenValue(fullOpenValue);
    setValue(value);
}

void Valve::init(channel channel, uint16_t value, uint16_t fullOpenValue)
{
    init(NULL, channel, value, fullOpenValue);
}
void Valve::setDac(Adafruit_MCP4728 *dac, bool sendCurrentValueToDac) {
    if (sendCurrentValueToDac)
        init(dac, getChannel(), getValue());
    else
        _dac = dac;
}
void Valve::setValue(uint16_t value) {
    _value = constrain(value, 0, _fullOpenValue);

    if (_dac)
    {
        Serial.printf("dac value: %d (sending to dac channel %d)\n", value, getChannel());
        _dac->setChannelValue(getChannel(), getValue());
    }
    else
    {
        Serial.printf("value: %d (Not sending to dac)\n", value);
    }
}

void Valve::setFullOpenValue(uint16_t fullOpenValue) {
    _fullOpenValue = fullOpenValue;
}

uint16_t Valve::getFullOpenValue()
{
    return _fullOpenValue;
}

uint16_t Valve::getValue()
{
    return _value;
}

channel Valve::getChannel()
{
    return _channel;
}

double Valve::getFlow() {
    return ((double)_value / (double)_fullOpenValue) * 100;
}

void Valve::setFlow(double flow)
{
    if (flow > 100)
    {
        flow = 100;
    }
    else if (flow < 0)
    {
        flow = 0;
    }
    
    Serial.printf("setFlow: flow:%f fullOpen:%d ", flow, _fullOpenValue);
    setValue(round((flow/100) * ((double)_fullOpenValue)));
}