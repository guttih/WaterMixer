#ifndef WATERMIXER_H
#define WATERMIXER_H

#include "valve.h"

/**
 * @brief Is the watermixer in manual or automatic mode
 * 
 */
enum WaterMixerMode {
    AUTOMATIC, /*!< Mixer will change opening on valves dependent on the difference between current and desired temperature */
    MANUAL     /*!< Mixer will only change opening on valves when drain and fill functions are used*/
};

class WaterMixer
{
    private:
        double _currentTemperature = 0;
        double _desiredTemperature = 0;
        WaterMixerMode _mode;
        Valve *_hotValve = NULL;
        Valve *_coldValve = NULL;
        Valve *_drainValve = NULL;
        void init(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature, double desiredTemperature, WaterMixerMode mode);
    public:
        WaterMixer(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature = 0, double desiredTemperature = 0);
        void setMode(WaterMixerMode mode);
        WaterMixerMode getMode() { return _mode; };

        /**
         * @brief Deactivates automatic mode, closes the drain valve and opens the hot and cold valve.
         * 
         * @param hotflow   How much should the  hot valve be opened? Where 0 is fully closed and 1 is fully opened.
         * @param coldflow  How much should the cold valve be opened? Where 0 is fully closed and 1 is fully opened.
         */
        void fill(double hotflow, double coldflow);

        /**
         * @brief Deactivates automatic mode, opens the drain valve and closes the hot and cold valve.
         * 
         */
        void drain();

        double setCurrentTemperature(double temperatureInCelsius); 
        double getCurrentTemperature() { return _currentTemperature; }

        double setDesiredTemperature(double temperatureInCelsius);
        double getDesiredTemperature() { return _desiredTemperature; }

        Valve *getHotValve() {return _hotValve; }
        Valve *getColdValve() {return _coldValve; }
        Valve *getDrainValve() {return _drainValve; }

};
#endif