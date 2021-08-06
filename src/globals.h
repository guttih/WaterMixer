#ifndef GLOBALS_H
#define GLOBALS_H

#include <FS.h>
#include "SD.h"
#include <SPI.h>

#include <TFT_eSPI.h> // Hardware-specific library


#include <OneWire.h>
#include <DallasTemperature.h>

#include "DisplayMenu.h"
#include "valve.h"
#include "watermixer.h"

#define CALIBRATION_FILE "/TouchCalData3"

// Decleration of global variables


/*
  Valves openings will be a number from 0-100 where 0 is fully closed and 100 fully open.
  To be able to use the pid to control two valves we need the WaterMixer to understand how to convert 
  desired temperature to a linear opening of the valves.


  
 */

const int PIN_PRESSURE = 34;
const int PIN_TEMPERATURE = 25;

const int PIN_HOT = 12;
const int PIN_COLD = 14;
const int PIN_DRAIN = 32;
#define FULL_DUTY 255
#define MAX_DUTY 190
#define CHANNEL_1 1
#define CHANNEL_2 2
#define CHANNEL_3 3

double currentTemperature = 0;
double currentPressure = 0;

OneWire oneWire(PIN_TEMPERATURE);
DallasTemperature sensors(&oneWire);

Valve   hot(PIN_HOT,  CHANNEL_1, FULL_DUTY, MAX_DUTY, 0.01, "Hot valve");
Valve  cold(PIN_COLD, CHANNEL_2, FULL_DUTY, MAX_DUTY, 0.02, "Cold valve");
Valve drain(PIN_DRAIN, CHANNEL_3, FULL_DUTY, 255,      0.03, "Drain valve");
WaterMixer water(&hot, &cold, &drain, 24, 24);

/**
 * @brief  Values used by the proportional integral derivative controller (PID controller).
 * 
 */
struct PID_STRUCT {
    double input;       // current temperature
    double setpoint;    // desired temperature
    double output;      // suggested temperature from the pid.
                        
    // outputMin and outputMax are the range of values your output can be set to.
    double outputMin;   // outputMin is the lowest value your output can be set to.  (Should use the same units as output)
    double outputMax;   // outputMax is the highest value your output can be set to.  (Should use the same units as output)
    double Kp;          //  proportional gain
    double Ki;          // integral gain
    double Kd;          // derivative gain
};

/**
 * @brief Global variables in the program
 * 
 */
struct GLOBAL_STRUCT {
    float temperature = 0;   // Current temperature read from the Temperature sensor.
    float desiredTemp = 24;  // The desired temperature which should be fed as the setpoint to the PID controller.
    float coldValveFlow = 0; // A number from 0 to 100 describing the opening of the COLD valve, 0 is fully closed and 100 fully open.
    float hotValveFlow = 0;  // A number from 0 to 100 describing the opening of the HOT  valve, 0 is fully closed and 100 fully open.
    PID_STRUCT pid;
} values;

TFT_eSPI tft = TFT_eSPI();
DisplayMenu menu = DisplayMenu(&tft);


void touch_calibrate(bool REPEAT_CAL)
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // check file system exists
  if (!SPIFFS.begin())
  {
    Serial.println("Formating file system");
    SPIFFS.format();
    SPIFFS.begin();
  }

  // check if calibration file exists and size is correct
  if (SPIFFS.exists(CALIBRATION_FILE))
  {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      SPIFFS.remove(CALIBRATION_FILE);
    }
    else
    {
      File f = SPIFFS.open(CALIBRATION_FILE, "r");
      if (f)
      {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL)
  {
    // calibration data valid
    tft.setTouch(calData);
  }
  else
  {
    // data not valid so recalibrate
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.println("Touch corners as indicated");

    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL)
    {
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("Set REPEAT_CAL to false to stop this running again!");
    }

    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibration complete!");

    // store data
    File f = SPIFFS.open(CALIBRATION_FILE, "w");
    if (f)
    {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}


#endif