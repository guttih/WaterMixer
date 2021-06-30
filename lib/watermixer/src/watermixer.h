#ifndef WATERMIXER_H
#define WATERMIXER_H

#include "valve.h"

class WaterMixer
{
    private:
        double _currentTemperature = 0;
        double _desiredTemperature = 0;
        bool _active = false;
        Valve *_hotValve = NULL;
        Valve *_coldValve = NULL;
        void init(Valve *hotValve, Valve *coldValve, double currentTemperature, double desiredTemperature, bool activate);
    public:
        WaterMixer(Valve *hotValve, Valve *coldValve, double currentTemperature = 0, double desiredTemperature = 0, bool activate = false);
        void setActive(bool activate);
        bool getActive() { return _active; };

        double setCurrentTemperature(double temperatureInCelsius); 
        double getCurrentTemperature() { return _currentTemperature; }

        double setDesiredTemperature(double temperatureInCelsius);
        double getDesiredTemperature() { return _desiredTemperature; }

        Valve *getHotValve() {return _hotValve; }
        Valve *getColdValve() {return _coldValve; }

};
#endif