#ifndef SENSORS_H
#define SENSORS_H

#include "globals.h"

unsigned long timerReadTemperature;

void setupSensors() {
    timerReadTemperature = 0;
    sensors.begin();
    sensors.setWaitForConversion(false);
    sensors.requestTemperatures(); 
    sensors.setResolution(9);
}


/**
 * @brief Get the temperature
 * 
 * @param value to store the temperature
 * @return true when read a new value and stored it.
 * @return false when no new value was read and therefore the value is unchanged.
 */
bool readTemperature(double *value) {
  
  unsigned long now = millis();
  if (now >= timerReadTemperature) {
    double readTemperature = sensors.getTempCByIndex(0); //this takes about 27 milliseconds 3 more ms are added when setWaitForConversion true
    bool readWithSuccess = readTemperature != -127;
    if (readWithSuccess)
      *value = readTemperature;
    sensors.requestTemperatures();//this takes about 3 milliseconds when setWaitForConversion is false on otherwise 597 milliseconds
    // default resolution is 9, and formula for needed delay = 750/ (1 << (12-resolution)) -> and there for 750/ (1 << 3) is equal to 93 ms
    timerReadTemperature = millis() + (750/ (1 << (12-sensors.getResolution()))); //read temperature tent times per second.
    return readWithSuccess;
}
  return false;

}

const int pressureSampleCount = 20;
float pressureSamples[pressureSampleCount];
unsigned long pressureSampleNumber = 0;

/**
 * @brief Get the pressure
 * 
 * @return double number in PSI(Pound per square inch)
 */
double readPressure() {
  
  // 5 psi should give full power that is 4096
  // todo: bought a new sensor which is 60 psi which is on it's way from china.
  // todo: this scale should be in bars not PSI when the new sensor arrives

  pressureSamples[pressureSampleNumber % pressureSampleCount] = ((float)analogRead(PIN_PRESSURE) / (float)4096) * 5;
  //Serial.printf("%lu index:%d\n", pressureSampleNumber, pressureSampleNumber % pressureSampleCount);
  pressureSampleNumber++;
  int samplePull = pressureSampleNumber < pressureSampleCount? pressureSampleCount:pressureSampleCount;

  //get the average
  double res = 0;
  for(int i = 0; i<samplePull; i++) {
    res+=pressureSamples[i];
  }
  return res/samplePull;
  
}

/**
 * @brief Checks if it's time to read a new value from sensors and updates values if it is time
 * 
 */
void checkAndUpdateSensors() {
   
   currentPressure = readPressure();
   water.setCurrentPressure(currentPressure);

   readTemperature(&currentTemperature);
   water.setCurrentTemperature(currentTemperature);
   
}

#endif