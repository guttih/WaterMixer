#include "PidController.h"

PidController::PidController(double minOutPutValue, double maxOutPutValue, int sampleTimeMs)
{

    _pid = new PID(&_values.input, &_values.output, &_values.setPoint, 0.1, 0.1, 0.1, DIRECT);
    setOutputLimits(minOutPutValue, maxOutPutValue);
    SetSampleTime(sampleTimeMs);

}

void PidController::set(double input, double output, double setPoint,
        double kP, double kI, double kD, int controllerDirection, bool automaticMode) {
    
    _values.input = input;
    _values.output = output;
    _values.setPoint = setPoint;
    _pid->SetTunings(kP, kI, kD, P_ON_E);
    _pid->SetSampleTime(1000);							//default Controller Sample Time is 0.1 seconds    
    _pid->SetControllerDirection(controllerDirection);
    _pid->SetTunings(kP, kI, kD, P_ON_E);
    setMode(automaticMode);
}

void PidController::setDesiredValue(double setPoint, double currentInput)
{
    _values.setPoint = setPoint;
    _values.input = currentInput;
}

void PidController::setDesiredValue(double setPoint)
{
    _values.setPoint = setPoint;
}

void PidController::setCurrentValue(double currentInput)
{
    _values.input = currentInput;
}

PidController::~PidController()
{
    delete _pid;
}