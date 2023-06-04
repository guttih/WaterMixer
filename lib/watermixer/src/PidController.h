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
 * between a measured process variable and a desired set point. The controller
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
    PidController( double minOutPutValue=0, double maxOutPutValue=100, int sampleTimeMs=1000 );

    ~PidController();


    // These functions query the pid for integral values.
    // they were created mainly for the pid front-end,
    // where it's important to know what is actually
    // inside the PID.

    // Get current Proportional gain
    double getKp();

    // Get current Integral gain
    double getKi();

    // Get current Derivative gain
    double getKd();

    /**
     * @brief Get the Desired Value (the set point of the PID controller)
     *
     * @return The desired value
     */
    double getDesiredValue()
    {
        return _values.setPoint;
    }

    /**
     *
     * @brief Get the PID Suggested Value (the output of the PID controller)
     *
     *  @return The value you should set to your device to
     */
    double getSuggestedValue()
    {
        return _values.output;
    }
    /**
     *
     * @brief Get the Current Value
     * @return Current Value the pid controller is working on
     */
    double getCurrentValue()
    {
        return _values.input;
    }
    bool  isAutomaticModeOn()
    {
        return _pid->GetMode();
    }
    int getDirection()
    {
        return _pid->GetDirection();
    };

    void set( double input, double output, double setPoint,
              double Kp, double Ki, double Kd, int controllerDirection, bool automaticMode = false );
    void setMode( int Mode )
    {
        _pid->SetMode( Mode );
    };
    void setOutputLimits( double minValue, double maxValue )
    {
        _pid->SetOutputLimits( minValue, maxValue );
    };

    /**
     * @brief Set desired and current values
     *
     * @param setPoint - The value you want to reach
     * @param currentValue - current value (Update the PID input value (to the newest sensor reading)))
     */
    void setDesiredValue( double setPoint, double currentValue );

    /**
     * @brief Update the desired value
     *
     * @param setPoint
     */
    void setDesiredValue( double setPoint );

    /**
     * @brief Update the Current Value
     *
     * @param currentInput
     */
    void setCurrentValue( double currentInput );

    void setSampleTime( double sampleTimeMs )
    {
        _pid->SetSampleTime( sampleTimeMs );
    };

private:
    PID_STRUCT _values;
    PID* _pid;
};

#endif