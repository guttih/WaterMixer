/*
  This program asks for a serial number from 0-4095 to be used to 
  tell the dac to output voltage from 0 - 5 volts which the ADC 
  can then read.

  libraires to use are named:
   - Adafruit_MCP4728
   - Adafruit_ADS1X15

  Connect the computer serial port to the micro usb on the Esp32
  and then wire the pins like shown in the table below.

  Wiring pins:
  
  Column description
      Adapter: Power adapter outputing 5 volts
      Esp32  : Micro controller
      DAC    : Digital to analog converter
      ADC    : Analog to digital converter
      LLC    : Logic level converter

  5V Power  Controller  MCP4728  ADS1115  Converter
  adapter     Esp32       DAC      ADC     LCC
  -------    ---------  -------  -------  -----
    VCC                    V       VDD    HV
    GND       GND          G       GND    H-GND
              3V3                         LV
              GND                         L-GND
              14                          LV3
              13                          LV4
                           CL      SCL    HV3
                           DA      SDA    HV4
                           A              A0
                           B              A1
                           C              A2
                           D              A3
*/
#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_MCP4728.h>
#include <Adafruit_ADS1X15.h>



const int sdaPin = 13, 
          sclPin = 14;

Adafruit_MCP4728 mcp; //Digital to analog converter (DAC)
Adafruit_ADS1115 ads; //Analog to digital converter (ADC)

const int SAVE_MAX = 4095;
int outputValue = SAVE_MAX;
int inputValue = SAVE_MAX;

int16_t adc0, adc1, adc2, adc3;
float volts0, volts1, volts2, volts3;

void analogWrite(int outputA, int outputB, int outputC, int outputD)
{

  Serial.print("Output A:");Serial.print(outputA);
  Serial.print(" B:");Serial.print(outputB);
  Serial.print(" C:");Serial.print(outputC);
  Serial.print(" D:");Serial.print(outputD);
  Serial.println();
  mcp.setChannelValue(MCP4728_CHANNEL_A, outputA);
  mcp.setChannelValue(MCP4728_CHANNEL_B, outputB);
  mcp.setChannelValue(MCP4728_CHANNEL_C, outputC);
  mcp.setChannelValue(MCP4728_CHANNEL_D, outputD);
}
void analogWrite(int output)
{
  analogWrite(output, output / 2, output / 4, output / 8);
}

void setup(void)
{
  Serial.begin(115200);
  Wire.begin(sdaPin, sclPin);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("+-----------------------------------+ ");
  Serial.println("| Adafruit MCP4728 and ADS1115 test |");
  Serial.println("|   Write a number from 0 to 4095   |");
  Serial.println("|        and press return           |");
  Serial.println("+-----------------------------------+ ");

  // Try to initialize DAC!
  if (!mcp.begin(0x60, &Wire))
  {
    Serial.println("Failed to find MCP4728 chip");
    while (1)
    {
      delay(10);
    }
  }

  // Getting single-ended readings from AIN0..3
  // ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)
  // Try to initialize ADC!
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  analogWrite(outputValue);
}

void loop()
{
  while (Serial.available() > 0)
  {
    int didRead = Serial.parseInt();
    if (Serial.read() == '\n')
    {
      outputValue = constrain(didRead, 0, SAVE_MAX);
      Serial.print("Got value : ");
      Serial.print(didRead);
      if (didRead != outputValue)
      {
        Serial.print(".  Converted it to ");
        Serial.print(outputValue);
      }
      Serial.println();
    }
    analogWrite(outputValue);
  }

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  volts0 = ads.computeVolts(adc0);
  volts1 = ads.computeVolts(adc1);
  volts2 = ads.computeVolts(adc2);
  volts3 = ads.computeVolts(adc3);

    Serial.print("A0: "); Serial.print(adc0); Serial.print(" "); Serial.print(volts0); Serial.print("V");
  Serial.print("  A1: "); Serial.print(adc1); Serial.print(" "); Serial.print(volts1); Serial.print("V");
  Serial.print("  A2: "); Serial.print(adc2); Serial.print(" "); Serial.print(volts2); Serial.print("V");
  Serial.print("  A3: "); Serial.print(adc3); Serial.print(" "); Serial.print(volts3); Serial.println("V");
  delay(1000);
}