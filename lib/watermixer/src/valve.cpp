#include "valve.h"

Valve::Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, double flow, const char *name)
{
    init(pin, channel, maxPWM, maxPWM, flow, name);
}

Valve::Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, uint16_t limitPWM, double flow, const char *name)
{
    init(pin, channel, maxPWM, limitPWM, flow, name);
}

void Valve::init(uint16_t pin, uint16_t channel, uint16_t maxPWM, uint16_t limitPWM, double flow, const char *name)
{
    _pin = pin;
    _maxPWM = maxPWM;
    _limitPWM = limitPWM;
    _channel = channel;
    _name = name;
    setDebugMode(_name != NULL);
    pinMode(_pin, OUTPUT);
    ledcAttachPin(_pin, _channel);
    ledcSetup(_channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT); //setup the LEDC_CHANNEL which is index
    setFlow(flow);
}

void Valve::setDebugMode(bool activate)
{
    _debugging = activate;
}

void Valve::setFlow(double flow)
{
    if (flow > 1)
    {
        flow = 1;
    }
    else if (flow < 0)
    {
        flow = 0;
    }
    _flow = flow;

    analogWriteToPin();
}

/**
 * @brief Calculates duty cycle from a value and sends it to the pin the valve is connected to.
 * 
 * @param channel Pulse width modulation channel (0-7) which should be used to generate the PWM signal for the pin.
 * @param value Value to be sent
 * @param valueMax Maximum allowed value, this value will be 100% duty cycle.
 */
void Valve::ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax)
{
    // calculate duty
    uint32_t duty = round(  
        ((double)LEDC_BASE_FREQ / (double)valueMax) * (double)min(value, valueMax)
    );

    if (_debugging)
    {
        String str ="Valve:" + getName() +
                    " value:" + String(value) +
                    " valueMax:" + String(valueMax) + 
                    " Analog Writing duty:" + String(duty) +
                    " Max duty:" + String(LEDC_BASE_FREQ) +
                     " to channel:" + String(channel) +
                     " pin: " + String(_pin);

        if (_name != NULL)
        {
            str += " , valve:" + getName();
        }
        Serial.println(str);
    }

    // write duty to LEDC
    ledcWrite(channel, duty);
}

/**
 * @brief Write current class values to the pin
 * 
 */
void Valve::analogWriteToPin()
{
    ledcAnalogWrite(_channel, getPWM(), _maxPWM);
}

void Valve::serialPrintInfo() 
{
    String  str = "------ V A L V E ------" +
    String     ("\n name     :") + getName() +
    String     ("\n pin      :") + getPin() +
    String     ("\n channel  :") + getChannel() +
    String     ("\n maxPWM   :") + getMaxPWM() +
    String     ("\n limitPWM :") + getLimitPWM() +
    String     ("\n flow     :") + getFlow() +
    String     ("\n debugging:") + getDebugging() +
    String     ("\n PWM      :") + getPWM() +
    String     ("\n------------------------");
    Serial.println(str);
}