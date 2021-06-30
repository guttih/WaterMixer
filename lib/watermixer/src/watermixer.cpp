#include "watermixer.h"

WaterMixer::WaterMixer(Valve *hotValve, Valve *coldValve, double currentTemperature, double desiredTemperature, bool activate)
{
    init(hotValve, coldValve, currentTemperature, desiredTemperature, activate);
}

void WaterMixer::init(Valve *hotValve, Valve *coldValve, double currentTemperature, double desiredTemperature, bool activate)
{
    _hotValve = hotValve;
    _coldValve = coldValve;
    _currentTemperature = currentTemperature;
    _desiredTemperature = desiredTemperature;
    setActive(activate);
}

void WaterMixer::setActive(bool activate)
{
    _active = activate;
}

double WaterMixer::setCurrentTemperature(double temperatureInCelsius)
{
    return _currentTemperature = temperatureInCelsius;
}
double WaterMixer::setDesiredTemperature(double temperatureInCelsius)
{
    return _desiredTemperature = temperatureInCelsius;
}