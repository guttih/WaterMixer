#ifndef SENSORS_H
#define SENSORS_H

#include "globals.h"

unsigned long timerReadTemperature;

void setupSensors() {
    timerReadTemperature = 0;
    sensors.begin();
}


/**
 * @brief Get the temperature
 * 
 * @return double number in C°(Celsius)
 */
double readTemperature() {
  unsigned long now = millis();
  if (now >= timerReadTemperature) {
    sensors.requestTemperatures();
    timerReadTemperature = now + 500; //read temperature twice per second
}
  return sensors.getTempCByIndex(0);

}

/**
 * @brief Get the pressure
 * 
 * @return double number in PSI(Pound per square inch)
 */
double readPressure() {
  
  // 5 psi should give full power that is 4096
  double proportion = (double)analogRead(PIN_PRESSURE) / (double)4096;
  return  (double)5 * proportion;
}

/**
 * @brief Checks if it's time to read a new value from sensors and updates values if it is time
 * 
 */
void checkAndUpdateSensors() {
   
   unsigned long now = millis();

   currentPressure = readPressure();

  if (now >= timerReadTemperature) {
    currentTemperature = readTemperature();
    timerReadTemperature = now + 500; //read temperature twice per second
  }
}

#endif