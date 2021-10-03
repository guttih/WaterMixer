#ifndef SENSORS_H
#define SENSORS_H

#include "globals.h"

unsigned long timerReadTemperature;

void setupSensorTemperature() {
    Serial.println("Setting up sensors");
    timerReadTemperature = 0;
    sensors.begin();
    sensors.setWaitForConversion(false);
    sensors.requestTemperatures(); 
    sensors.setResolution(9);
}

void setupSensorAdc() {
  // Getting single-ended readings from AIN0..3
  // ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)
  // Try to initialize ADC!
  Serial.println("Setting up the Analog to Digital Converter ADS1115");
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
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

/**
 * @brief Get the pressure
 * 
 * @return double number in BAR
 */
double readPressure() {
  
  // 5 psi should give full power that is 4096
  // todo: bought a new sensor which is 60 psi
  // todo: this scale should be in bars not volts when the new sensor arrives
  int16_t adc0 = ads.readADC_SingleEnded(0);
  
  //float volts0 = ads.computeVolts(adc0);
  
  //if volts is 5 then PSI = 60 PSI (pounds per square inch) and BAR = 4.13685438
  //The 5 PSI sensor sends 5.05 volts when filling the hot tub so I'm setting that as the max value
  //The 5 PSI sensor sends 26906 value when filling the hot tub so I'm setting that as the max value
  // so 26906 / 4.13685438 = 6503.975613 which is the ratio between the value and BAR units 

  double ret = adc0 / (double)6503.975613;
  
  return ret;
  
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