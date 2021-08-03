#include "watermixer.h"


WaterMixer::WaterMixer(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature, double desiredTemperature)
{
    init(hotValve, coldValve, drainValve, currentTemperature, desiredTemperature, MANUAL);
}

void WaterMixer::init(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature, double desiredTemperature,  WaterMixerMode mode)
{
    _hotValve = hotValve;
    _coldValve = coldValve;
    _drainValve = drainValve;
    _currentTemperature = currentTemperature;
    _desiredTemperature = desiredTemperature;
    setMode(mode);
}

void WaterMixer::setMode(WaterMixerMode mode)
{
    _mode = mode;
}

double WaterMixer::setCurrentTemperature(double temperatureInCelsius)
{
    return _currentTemperature = temperatureInCelsius;
}
double WaterMixer::setDesiredTemperature(double temperatureInCelsius)
{
    return _desiredTemperature = temperatureInCelsius;
}

void WaterMixer::drain()
{
    setMode(MANUAL);
    _drainValve->setFlow(1);
    _hotValve->setFlow(0);
    _coldValve->setFlow(0);
}

void WaterMixer::fill(double hotFlow, double coldFlow)
{
    setMode(MANUAL);
    _drainValve->setFlow(0);
    _hotValve->setFlow(hotFlow);
    _coldValve->setFlow(coldFlow);
}