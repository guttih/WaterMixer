#ifndef WATERMIXER_H
#define WATERMIXER_H

#include "valve.h"

#include "SD.h"
/**
 * @brief Is the watermixer in manual or automatic mode
 * 
 */
enum WaterMixerMode {
    AUTOMATIC, /*!< Mixer will change opening on valves dependent on the difference between current and desired temperature */
    MANUAL     /*!< Mixer will only change opening on valves when drain and fill functions are used*/
};

struct SYSTEM_SAMPLE {
    float hotValveFlow;
    float coldValveFlow;
    float pressure;
    float temperature;
};

enum WATER_MIXER_UPDATE {
    IDLE, //When no update took place
    SYSTEM_RECORDING_IN_PROGRESS, //when system recording is in progress
    SYSTEM_RECORDING_FINISHED //when system recording had been in progress, but was stopped in this cycle.
};

enum SYSTEM_RECORDING_COLUM {
    HOT_VALVE_FLOW,
    COLD_VALVE_FLOW,
    PRESSURE,
    TEMPERATURE
};

const int RECORD_SYSTEM_WAIT_BEFORE_STARTING = 2 * 60 * 1000; //How long should should we wait until first sample can be collected. minutes * seconds * milliseconds
const int RECORD_SYSTEM_INTERVAL = 1 * 60 * 1000; //How long should pass until a new sample is recorded
class WaterMixer
{
    private:
        unsigned long recordSystemTimer = 0;
        int updateRecordingCount = 0;
        double _currentTemperature = 0;
        double _desiredTemperature = 0;
        double _currentPressure = 0;
        WaterMixerMode _mode;
        Valve *_hotValve = NULL;
        Valve *_coldValve = NULL;
        Valve *_drainValve = NULL;
        String readLine(File file);
        SYSTEM_SAMPLE extractDataFromString(String line);
        void init(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature, double desiredTemperature, double currentPressure, WaterMixerMode mode);
    public:
        WaterMixer(Valve *hotValve, Valve *coldValve, Valve *drainValve, double currentTemperature = 0, double desiredTemperature = 0, double currentPressure = 0);
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
         * @brief Opens opens valves and adjusts them so they will mix water to the desired temperature.
         * 
         */
        void fillDesired();

        /**
         * @brief Closes all valves
         * 
         */
        void stop() { _hotValve->setFlow(0); _coldValve->setFlow(0); _drainValve->setFlow(0);};
        

        /**
         * @brief Deactivates automatic mode, opens the drain valve and closes the hot and cold valve.
         * 
         */
        void drain();

        void setCurrentTemperature(double temperatureInCelsius); 
        double getCurrentTemperature() { return _currentTemperature; }

        void setDesiredTemperature(double temperatureInCelsius);
        double getDesiredTemperature() { return _desiredTemperature; }

        void setCurrentPressure(double pressure); 
        double getCurrentPressure() { return _currentPressure; }

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
            Serial.printf("setHotValveFlow: %f -> %.4f\n", flow, flow /100);
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

        void startRecordingSystem();
        /**
         * @brief scans the system and records the values into a file on the sd card.
         * 
         * @return true if update recording is in process
         * @return false if update has finised
         */
        bool updateRecordingSystem();
        void stopRecordingSystem();
        String recordingSystemHeader();
        String recordingSystemValuesToString(double hotValveFlow, double coldValveFlow, double pressure, double temperature);
        
        SYSTEM_SAMPLE getSavedSystemRecordingClosestTo(SYSTEM_RECORDING_COLUM column, double value);


        WATER_MIXER_UPDATE update();
};
#endif