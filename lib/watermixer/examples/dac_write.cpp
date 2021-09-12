#include <Arduino.h>

#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

const int SAVE_MAX = 4095;

int outputValue = SAVE_MAX;
int inputValue = SAVE_MAX;

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
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MCP4728 test, write a number to the serial");

  // Try to initialize!
  if (!mcp.begin())
  {
    Serial.println("Failed to find MCP4728 chip");
    while (1)
    {
      delay(10);
    }
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
  delay(200);
}