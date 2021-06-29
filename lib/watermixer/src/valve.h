#ifndef VALVE_H
#define VALVE_H

#include "arduino.h"

/**
 * @brief This library is for driving a proportional valves using a 
 * PWM to voltage converter.
 * 
 */
class Valve
{

private:
    uint16_t _pin;            // Pin connected to the valve (or to be more exact,  PWM connection on the PWM to voltage converter which is connected to the valve).
    uint16_t _channel;        // Pulse width modulation channel for the pin
    uint16_t _maxPWM;         // When is duty cycle 100%
    uint16_t _limitPWM;       // Usually same as _maxPWM but can be limited to lower value insuring duty cycle never reaches 100% or fully on.
    double _flow;             // Flow proportion a number from 0 to 1 where 1 is 100% flow and 0.5 is 50% flow
    const char *_name = NULL; // Given name of the valve, this name is used when printing debug messages to the serial port.
    bool _debugging = false;  // Should extra information be sent to the serial port.

    const int LEDC_TIMER_13_BIT = 13;
    const int LEDC_BASE_FREQ = 8100;

    void init(uint16_t pin, uint16_t channel, uint16_t maxPWM, uint16_t limitPWM, double flow, const char *name);
    void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax);
    void analogWriteToPin();
public:

    /**
             * @brief Construct a new Valve object and enable debugging.
             * 
             * @param pin Signal pin of the microcontroller which the signal wire on the valve is connected to.
             * @param channel Choose the pulse width modulation channel (0-7) which should be used to generate the PWM signal for the pin.
             * @param maxPWM What is the maximum duty cycle allowed to be sent to the pin.
             * @param limitPWM If you do never want 100% duty cycle you can limit it with this value.  That is when flow is 1 then PWM is this number.
             * @param flow A number from 0 to 1, where 0 is fully closed, 0.5 is half open and 1 is fully closed.
             * @param strName Gives the valve a name and activates the Valve debug mode, resulting an a Serial println statements when giving the valve a command.
             * @example 
             * @code {.language-cpp}
             * Valve hot (POWERPIN_1, CHANNEL_1, 255, 190, 0.0,"Hot valve");
             * @endcode
             * 
             */
    Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, uint16_t limitPWM, double flow, const char *name = NULL);

    /**
             * @brief Construct a new Valve object and enable debugging.
             * 
             * @param pin Signal pin of the microcontroller which the signal wire on the valve is connected to.
             * @param channel Choose the pulse width modulation channel (0-7) which should be used to generate the PWM signal for the pin.
             * @param maxPWM What is the maximum duty cycle allowed to be sent to the pin.
             * @param flow A number from 0 to 1, where 0 is fully closed, 0.5 is half open and 1 is fully closed.
             * @param strName Gives the valve a name and activates the Valve debug mode, resulting an a Serial println statements when giving the valve a command.
             */
    Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, double flow, const char *strName = NULL);

    /**
      * @brief How much water should be flowing through the valve. 
      * 
      * @param flow A number from 0 to 1, where 
      *               0   is fully closed, 
      *               0.5 is half open and 
      *               1   is fully closed.
      */
    void setFlow(double flow);

    bool getDebugging() { return _debugging; }
    double getFlow() { return _flow; }

    /**
       * @brief Set the server debugging mode on or off. setting it on 
       * will add print serial statements when executing commands.
       * 
       * @param activate 
       */
    void setDebugMode(bool activate);

    /**
       * @brief Get the Pin number this valve is connected to.
       * 
       * @return uint8_t 
       */
    uint8_t getPin() { return _pin; }

    /**
       * @brief Get the PWM Channel this pin is connected to.
       * 
       * @return uint8_t 
       */
    uint8_t getChannel() { return _channel; }

    /**
       * @brief Get the value which represents 100% duty cycle.
       * 
       * @return uint16_t 
       */
    uint16_t getMaxPWM() { return _maxPWM; }

    /**
       * @brief Get the maximum value allowed to be sent to the duty cycle calculation.
       * 
       * @return uint16_t 
       */
    uint16_t getLimitPWM() { return _limitPWM; }

    /**
      * @brief Gets the Pulse width modulation value which is beeing sent to the valve.  This PWM value is used to calculate the duty cycle on the pin channel.
      * 
      * @return uint16_t 
      */
    uint16_t getPWM() { 
                            uint16_t maxLimitPWM = round(_flow * ((double)_limitPWM));
                            uint16_t pwm = round(_flow * ((double)_maxPWM));
                            return min(maxLimitPWM, pwm);
                        }

    /**
     * @brief Get the Name valve.  returns a empty string if Name is null
     * 
     * @return String 
     */
    String getName() { return _name == NULL ? String("") : String(_name); }

    void serialPrintInfo();
};

#endif