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

const int RECORD_SYSTEM_WAIT_BEFORE_STARTING = 15000; //How long should should we wait until first sample can be collected.
const int RECORD_SYSTEM_INTERVAL = 10000; //How long should pass until a new sample is recorded
class WaterMixer
{
    private:
        unsigned long recordSystemTimer = 0;
        int recordSystemSampleCount = 0;
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
         * @param hotflow   How much should the  hot valve be opened? Where 0 is fully closed and 100 is fully opened.
         * @param coldflow  How much should the cold valve be opened? Where 0 is fully closed and 100 is fully opened.
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

        // Valve *getHotValve() {return _hotValve; }
        // Valve *getColdValve() {return _coldValve; }
        // Valve *getDrainValve() {return _drainValve; }

        double getHotValveFlow() {return _hotValve->getFlow() * 100; }
        double getColdValveFlow() {return _coldValve->getFlow() * 100; }
        double getDrainValveFlow() {return _drainValve->getFlow() * 100; }

        /**
         * @brief Set the Hot Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setHotValveFlow(double flow)   {
            Serial.printf("setHotValveFlow: %.f -> %.4f\n", flow, flow /100);
            _hotValve->setFlow(flow /100); 
            }
        /**
         * @brief Set the Cold Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setColdValveFlow(double flow)  {_coldValve->setFlow(flow /100); }
        /**
         * @brief Set the Drain Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setDrainValveFlow(double flow) {_drainValve->setFlow(flow /100); }

        bool startRecordingSystem();
        bool updateRecordingSystem();
        bool stopRecordingSystem();
};
#endif