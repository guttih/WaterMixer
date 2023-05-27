#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <PID_v1.h>

/**
 * @brief  Values used by the proportional integral derivative controller (PID controller).
 * 
 */
struct PID_STRUCT {
    double input = 0;       // current temperature
    double setPoint = 0;    // desired temperature
    double output = 0;      // suggested temperature from the pid.
};



/**
 * @brief A Proportional-Integral-Derivative controller class
 * 
 * @details This class implements a PID controller. The PID controller is a
 * feedback control algorithm that calculates an error value as the difference
 * between a measured process variable and a desired setpoint. The controller
 * attempts to minimize the error by adjusting the process control inputs.
 * 
 * @see https://en.wikipedia.org/wiki/PID_controller
 * 
 * @note This class is based on the Arduino PID Library by Brett Beauregard
 * 
 * @see Brett Beauregard's Arduino PID Library at https://github.com/br3ttb/Arduino-PID-Library
 * 
 */

class PidController
{
public:
    PidController(double minOutPutValue=0, double maxOutPutValue=80, int sampleTimeMs=1000);
    
    ~PidController();

    
    // These functions query the pid for interal values.
    // they were created mainly for the pid front-end,
    // where it's important to know what is actually 
    // inside the PID.
    
    // Get current Proportional gain
    double getKp(){ return  _pid->GetKp();}            
	
    // Get current Integral gain
    double getKi(){ return  _pid->GetKi();}            
	
    // Get current Derivative gain
    double getKd(){ return  _pid->GetKd();}            
	int  getMode(){ return  _pid->GetMode();}          
	int getDirection(){ return  _pid->GetDirection();};

     void set(double input, double output, double setPoint,
        double Kp, double Ki, double Kd, int controllerDirection, bool automaticMode = false);
    void setMode(int Mode){ _pid->SetMode(Mode);};
    void setOutputLimits(double minValue, double maxValue){ _pid->SetOutputLimits(minValue, maxValue);};
    
    /**
     * @brief Set bot desired and current values
     * 
     * @param setPoint - desired value
     * @param currentInput - current value
     */
    void setDesiredValue(double setPoint, double currentInput);

    /**
     * @brief Update the desired value 
     * 
     * @param setPoint 
     */
    void setDesiredValue(double setPoint);

    /**
     * @brief Update the Current Value 
     * 
     * @param currentInput 
     */
    void setCurrentValue(double currentInput);
    
    void SetSampleTime(double sampleTimeMs){ _pid->SetSampleTime(sampleTimeMs);};
private:
    PID_STRUCT _values;
    PID* _pid;
};

#endif