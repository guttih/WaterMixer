#ifndef VALVE_H
#define VALVE_H

#include "arduino.h"

#include <Adafruit_MCP4728.h>

class Valve
{
private:
    Adafruit_MCP4728 *_dac;
    channel _channel;
    uint16_t _value;
    uint16_t _fullOpenValue;
    /**
     * @brief initializing the valve
     * 
     * @param dac 
     * @param channel 
     * @param value 
     * @param fullOpenValue 
     */
    void init(Adafruit_MCP4728 *dac, channel channel, uint16_t value, uint16_t fullOpenValue = 4095);

public:
    Valve();
    /**
     * @brief initializing the valve.
     * 
     * @param channel 
     * @param value 
     * @param fullOpenValue 
     */
    void init(channel channel, uint16_t value, uint16_t fullOpenValue = 4095);

    /**
     * @brief Set the Dac this valve is controlled by.  
     * Before calling this function the dac must have been initialized by calling it's begin() function.
     * 
     * @param dac Dac to be used to control this valve
     * @param sendCurrentValueToDac now that have a dac, should we send the current valve value to it.
     */
    void setDac(Adafruit_MCP4728 *dac, bool sendCurrentValueToDac=true);
    void setValue(uint16_t value);
    void setFullOpenValue(uint16_t value);
    void setFlow(double flow);
    uint16_t getValue();
    uint16_t getFullOpenValue();
    channel getChannel();
    double getFlow();
};

#endif