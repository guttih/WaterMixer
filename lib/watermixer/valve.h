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
  uint16_t _pin;
  uint16_t _channel;
  uint16_t _maxPWM;
  uint16_t _PWM;      //the PWM value sent to the duty cycle calculateion.
  double _flow;       //Flow proportion a number from 0 to 1 where 1 is 100% flow and 0.5 is 50% flow
  const char *_name = NULL;
  bool _debugging = false;

  
  void init(uint16_t pin, uint16_t channel, uint16_t maxPWM, double flow, const char *name);

public:
  /**
     * @brief Construct a new Valve object and enable debugging.
     * 
     * @param pin - Signal pin of the microcontroller which the signal wire on the valve is connected to.
     * @param maxPWM - What is the maximum duty cycle allowed to be sent to the pin.
     * @param channel - Choose the pulse width modulation channel (0-7) which should be used to generate the PWM signal for the pin.
     * @param maxUs - Maximum pulse width - for max angle.
     * @param strName - Gives the valve a name and activates the Valve debug mode, resulting an a Serial println statements when giving the valve a command.
     */
  Valve(uint16_t pin, uint16_t channel, uint16_t maxPWM, double flow, const char *strName);


  /**
   * @brief Set the Flow of the valve.
   * 
   * @param flow - A number from 0 to 1, where 0 is fully closed, 0.5 is half open and 1 is fully closed.
   */
  void setFlow(double flow);

  
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
     * @brief Get the maximum travel Angle of the valve.
     * 
     * @return uint16_t 
     */
  uint16_t getMaxPWM() { return _maxPWM; }

  /**
   * @brief Gets the Pulse width modulation value which is beeing sent to the valve.  This PWM value is used to calculate the duty cycle on the pin channel.
   * 
   * @return uint16_t 
   */
  uint16_t getPWM() { return round( _flow * ((double)_maxPWM) ); }
  
  const char *getName() { return _name; }

  void serialPrintInfo();
};

#endif