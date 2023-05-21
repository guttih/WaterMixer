#ifndef WATERMIXER_H
#define WATERMIXER_H

#include "SD.h"
#include <Adafruit_MCP4728.h>   

#include "valve.h"
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

struct SYSTEM_SAMPLE_TIMED {
    float hotValveFlow;
    float coldValveFlow;
    float pressure;
    float temperature;
    unsigned long time; /* when was the sample taken time in milliseconds this value represents, 
                           how many milliseconds the micro controller has been running when the
                           sample was taken. */
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
        Adafruit_MCP4728 *_dac;
        Valve _hotValve;
        Valve _coldValve;
        Valve _drainValve;
        String readLine(File file);
        SYSTEM_SAMPLE extractDataFromString(String line);
        SYSTEM_SAMPLE_TIMED extractTimedDataFromString(String line);
        void init(channel hotValve, channel coldValve, channel drainValve, double currentTemperature, double desiredTemperature, double currentPressure,  WaterMixerMode mode);
    
    public:
        WaterMixer(channel hotValve, channel coldValve, channel drainValve, double currentTemperature = 0, double desiredTemperature = 0, double currentPressure = 0);
        void begin(int sdaPin = 21, int sclPin = 22);
        ~WaterMixer();
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
         * @brief Checks if the hot or cold valves are flowing
         * 
         * @return true if eather the hot or cold valves are flowing
         * @return false the cold valve is not flowing and the hot valve is not flowing
         */
        bool isFlowing() { return (_hotValve.getFlow() > 0 || _coldValve.getFlow() > 0);  }


        /**
         * @brief Check if draining is in process
         * 
         * @return true the drain valve is open
         * @return false the drain valve is closed
         */
        bool isDraining() { return _drainValve.getFlow() > 0; }

        /**
         * @brief Check if all valves are closed
         * 
         * @return true all valves are not flowing(closed)
         * @return false one or more valves are flowing
         */
        bool isStopped() { return _drainValve.getFlow() == 0 && _hotValve.getFlow() == 0 && _coldValve.getFlow() == 0; }

        /**
         * @brief Opens opens valves and adjusts them so they will mix water to the desired temperature.
         * 
         */
        void fillDesired();

        /**
         * @brief Closes all valves
         * 
         */
        void stop() { _hotValve.setFlow(0); _coldValve.setFlow(0); _drainValve.setFlow(0);};
        

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

        Valve *getHotValve() { return &_hotValve; }
        Valve *getColdValve() { return &_coldValve; }
        Valve *getDrainValve() { return &_drainValve; }
        
        double getHotValveFlow() { return _hotValve.getFlow(); }
        double getColdValveFlow() { return _coldValve.getFlow(); }
        double getDrainValveFlow() { return _drainValve.getFlow(); }

        /**
         * @brief Set the Hot Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setHotValveFlow(double flow)   {
            Serial.printf("setHotValveFlow: %f\n", flow);
            _hotValve.setFlow(flow); 
            }
        /**
         * @brief Set the Cold Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setColdValveFlow(double flow)  {_coldValve.setFlow(flow); }
        /**
         * @brief Set the Drain Valve Flow object
         * 
         * @param flow How much should the valve be opened? Where 0 is fully closed and 100 is fully opened.
         */
        void setDrainValveFlow(double flow) {_drainValve.setFlow(flow); }

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
        
        /**
         * @brief Get the Saved System Recording Closest To object
         * 
         * @param column 
         * @param value 
         * @return SYSTEM_SAMPLE If there is an error reading values the hotValveFlow and/or coldValveFlow contain the values -1;
         */
        SYSTEM_SAMPLE getSavedSystemRecordingClosestTo(SYSTEM_RECORDING_COLUM column, double value);

        /**
         * @brief Get the All Recorded System Values As CSV formatted document
         * 
         * Records will be separated by '\n' and fields by the separator character.
         * 
         * @param separator The symbol used to separate values in a record
         * @return String containing all records, separated by '\n'.
         *         On error, or no values are already recorded, an empty string is returned.
         */
        String getAllRecordedSystemValuesAsCSV(char separator = ';');

         /**
         * @brief Get the All Recorded System Values As Json array formatted string
         * 
         * 
         * @return Json String containing all records
         */
        String getAllRecordedSystemValuesAsJson();

        /**
         * @brief Formats a sample object as a Json string
         * 
         * @param timpedSample the sample values 
         * 
         * @return String a valid json value
         */
        String sampleToJson(SYSTEM_SAMPLE_TIMED timedSample);

        /**
         * @brief Returns mixer values a json string
         * 
         * @return String 
         */
        String toJson();
        WATER_MIXER_UPDATE update();

        /**
         * @brief Maps a double number to an integer number
         * 
         * @return int number rounded to 0.5
         */
        int mapValue(double dValue, double dValueMax, int iValueMax);
};
#endif