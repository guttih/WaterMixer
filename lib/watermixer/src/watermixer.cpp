#include "watermixer.h"


#define SYSTEM_RECORDING_FILE_NAME "/system.csv"

WaterMixer::WaterMixer(channel hotValve, channel coldValve, channel drainValve, double currentTemperature, double desiredTemperature, double currentPressure)
{
    init(hotValve, coldValve, drainValve, currentTemperature, desiredTemperature, currentPressure, MANUAL);
}
WaterMixer::~WaterMixer(){
    if (_dac)
        delete _dac;
}

void WaterMixer::begin(int sdaPin, int sclPin){
    Wire.begin(sdaPin, sclPin);
    _dac = new Adafruit_MCP4728();
    const uint8_t  address = 0x60;
    if (!_dac->begin(address))
    {
        Serial.println("!!!!!   ERROR  - Failed to find MCP4728 chip   !!!!!\n");
        Serial.printf("  - SDA should be connected to pin %d on the Esp32 and SCL should be connected to %d\n", sdaPin, sclPin);
        while (1)
        {
            delay(10);
        }
    }
    Serial.printf("dac MCP4728 is connected.  Address:0x%02X, SDA:%d, SCL:%d pointer:%p\n", address, sdaPin, sclPin, _dac);
    _hotValve.setDac(_dac);
    _coldValve.setDac(_dac);
    _drainValve.setDac(_dac);
}

void WaterMixer::init(channel hotValve, channel coldValve, channel drainValve, double currentTemperature, double desiredTemperature, double currentPressure,  WaterMixerMode mode)
{
    _dac = NULL;
    _hotValve.init(hotValve, 0);
    _coldValve.init(coldValve, 0);
    _drainValve.init(drainValve, 0);
    _currentTemperature = currentTemperature;
    _desiredTemperature = desiredTemperature;
    _currentPressure = currentPressure;
    setMode(mode);
}

void WaterMixer::setMode(WaterMixerMode mode)
{
    _mode = mode;
}

void WaterMixer::setCurrentTemperature(double temperatureInCelsius)
{
    _currentTemperature = temperatureInCelsius;
}
void WaterMixer::setDesiredTemperature(double temperatureInCelsius)
{
    _desiredTemperature = temperatureInCelsius;
}

void WaterMixer::setCurrentPressure(double pressure)
{
    _currentPressure = pressure;
}

void WaterMixer::drain()
{
    setMode(MANUAL);
    _drainValve.setFlow(100);
    _hotValve.setFlow(0);
    _coldValve.setFlow(0);
}

void WaterMixer::fill(double hotFlow, double coldFlow)
{
    setMode(MANUAL);
    _drainValve.setFlow(0);
    _hotValve.setFlow(hotFlow);
    _coldValve.setFlow(coldFlow);
}
void WaterMixer::fillDesired()
{
    setMode(AUTOMATIC);
    SYSTEM_SAMPLE sample = getSavedSystemRecordingClosestTo(TEMPERATURE, _desiredTemperature);
    fill(sample.hotValveFlow, sample.coldValveFlow);
}

String WaterMixer::recordingSystemHeader(){
    return "Hot;Cold;Pressure;Temperature;time\n";
}
String WaterMixer::recordingSystemValuesToString(double hotValveFlow, double coldValveFlow, double pressure, double temperature){
    char output[200];
    snprintf(output, 200, "%f;%f;%f;%f;%lu\n", hotValveFlow, coldValveFlow, pressure, temperature, millis());
    Serial.println(output);
    String ret(output);
    return ret;
}

void WaterMixer::startRecordingSystem() {
    
    updateRecordingCount = 0;
    File file = SD.open(SYSTEM_RECORDING_FILE_NAME, FILE_WRITE);
    file.print(recordingSystemHeader());
    file.close();
    fill(100, 100);
    recordSystemTimer = millis()+ RECORD_SYSTEM_WAIT_BEFORE_STARTING/2;
}
bool WaterMixer::updateRecordingSystem() {
    if (updateRecordingCount == 0) {
        //first call so we will set the hot valve to zero
        setHotValveFlow(0);
        recordSystemTimer = millis()+ RECORD_SYSTEM_WAIT_BEFORE_STARTING;
        updateRecordingCount++;
        return true;
    }

    File file = SD.open(SYSTEM_RECORDING_FILE_NAME, FILE_APPEND);
    updateRecordingCount++;
    file.print(recordingSystemValuesToString(getHotValveFlow(), getColdValveFlow(), getCurrentPressure(), getCurrentTemperature()));
    file.close();

    double flow = getHotValveFlow();
    if (flow >= 100)
    {
        stopRecordingSystem();
        return false;
    }
    else
    {
        setHotValveFlow(flow + 0.5);
        recordSystemTimer = millis() + RECORD_SYSTEM_INTERVAL;
        return true;
    }
}

void WaterMixer::stopRecordingSystem() {
    recordSystemTimer = 0;
    updateRecordingCount = 0;
    setHotValveFlow(0);
    setColdValveFlow(0);
    setDrainValveFlow(0);
}

SYSTEM_SAMPLE WaterMixer::extractDataFromString(String line){
   SYSTEM_SAMPLE sample;
   sample.coldValveFlow = 0;
   sample.hotValveFlow = 0;
   sample.pressure = 0;
   sample.temperature = 0;
   int index = line.indexOf(';');
   int column = 0;
   String str;
   while (index > 0) {
       String str = line.substring(0, index);
       switch(column) {
           case 0: sample.hotValveFlow = str.toFloat(); break;
           case 1: sample.coldValveFlow = str.toFloat(); break;
           case 2: sample.pressure = str.toFloat(); break;
           case 3: sample.temperature = str.toFloat(); break;
       }
       
       line.remove(0, index+1);
       index = line.indexOf(';');
       column++;
   }
    //Serial.printf("leftstring(%s)\n", line.c_str()); contains time
   return sample; 
}

String WaterMixer::readLine(File file)
{
    String ret;
    int c;
    while (file.available())
    {
        c = file.read();
        if (c == '\n' || c == EOF)
            return ret;
        ret += (char)c;
    }
    return ret;
}
SYSTEM_SAMPLE WaterMixer::getSavedSystemRecordingClosestTo(SYSTEM_RECORDING_COLUM column, double value) {
    Serial.printf("Searching for value:%f\n",value);
    File file = SD.open(SYSTEM_RECORDING_FILE_NAME, FILE_READ);
    String line = readLine(file); //reading the header
    SYSTEM_SAMPLE ret;
    SYSTEM_SAMPLE sample;
    ret.hotValveFlow = -1;
    ret.coldValveFlow = -1;
    ret.pressure = -1;
    ret.temperature = -1;
    double diffRet, diffSample;
    if (line.length() > 8 )
    {
        line = readLine(file);
        
        // Shortest valid string is 9 chars in length. e.g. "1;1;1;1;1"
        if (line.length() > 8){
            Serial.printf("first val: %s\n", line.c_str());
            ret = extractDataFromString(line);
        }
        while (line.length() > 8)
        {
            sample = extractDataFromString(line);
            Serial.printf("sample: %s", line.c_str());
            switch (column)
            {
            case 0: //Hot valve flow
                diffRet = ret.hotValveFlow > value ? ret.hotValveFlow - value : value - ret.hotValveFlow;
                diffSample = sample.hotValveFlow > value ? sample.hotValveFlow - value : value - sample.hotValveFlow;
                break;
            case 1: // Cold valve flow
                diffRet = ret.coldValveFlow > value ? ret.coldValveFlow - value : value - ret.coldValveFlow;
                diffSample = sample.coldValveFlow > value ? sample.coldValveFlow - value : value - sample.coldValveFlow;
                break;
            case 2: // pressure
                diffRet = ret.pressure > value ? ret.pressure - value : value - ret.pressure;
                diffSample = sample.pressure > value ? sample.pressure - value : value - sample.pressure;
                break;
            case 3: // temperature
                diffRet = ret.temperature > value ? ret.temperature - value : value - ret.temperature;
                diffSample = sample.temperature > value ? sample.temperature - value : value - sample.temperature;
                break;
            }
            if (diffSample < diffRet)
            {
                Serial.println(" Selecting this one");
                    ret = sample;
            }
            else
                Serial.println();
            line = readLine(file);
        }
    }
    file.close();

    return ret;

}

String WaterMixer::toJson() {
    
    String str = "{\"hotValveFlow\":" + String(getHotValveFlow()) +
                 ", \"coldValveFlow\":" + String(getColdValveFlow())  +
                 ", \"drainValveFlow\":" + String(getDrainValveFlow())  +
                 ", \"currentTemperature\":" + String(getCurrentTemperature())  +
                 ", \"desiredTemperature\":" + String(getDesiredTemperature())  +
                 ", \"currentPressure\":" + String(getCurrentPressure())  +
                 ", \"mode\":" + String(getMode())  +
                "}";

    return str;
}


WATER_MIXER_UPDATE WaterMixer::update(){
    if (recordSystemTimer && millis() > recordSystemTimer) {
        if (updateRecordingSystem())
            return SYSTEM_RECORDING_IN_PROGRESS;
        else
            return SYSTEM_RECORDING_FINISHED;
    }
    return IDLE;
}