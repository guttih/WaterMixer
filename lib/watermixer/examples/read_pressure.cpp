
/* 
    Sketch to read from a 5V pressure sensor.  When pressure is at max the sensor 
    output voltage on the green wire should be around 5 volts. When the sensor 
    is mesuring 0 pressure the voltage should be around 0, but is really about 
    300 milli volts.  (0.3v)

    To read the sensor output on a esp32 we will need a voltage devider to convert
    the output from 5V to 3V.  The devider consists of two resistors, R1 which is
    3.3 kilo ohm and R2 which is 4.7 kilo ohm.
 
    Wire the sensor like this.

 GND                                5V
  │                                  │
  │                                  │                  ╔══════════╗
  │  ╔═══════════╗                   │                  ║ Pressure ║
  │  ║   ESP32   ║                   │                  ║  Sensor  ║
  │  ║           ║                   │                  ║          ║
  │  ║      VIN -╟───────────────────┴──────────────────╢- Red     ║
  │  ║      G34 -╟────────────────────┐                 ║          ║
  │  ║           ║     ╔═══════════╗  │  ╔═══════════╗  ║          ║
  │  ║           ║     ║-Resistor -║  │  ║-Resistor -║  ║          ║
  │  ║           ║  ┌──╢-  4.7kΩ  -╟──┴──╢-  3.3kΩ  -╟──╢- Green   ║
  │  ║           ║  │  ╚═══════════╝     ╚═══════════╝  ║          ║
  │  ║      GND -╟──┼───────────────────────────────────╢- Black   ║
  │  ╚═══════════╝  │                                   ╚══════════╝
  │                 │
  └─────────────────┘

**legend
    GND    : ground.
    G34    : GPIO 34 Esp32 pin, which is used to read the sensor output.
    Black  : Black or blue sensor wire, which is ground.
    Red    : The Red sensor wire, which is VCC 5 volts.
    Green  : The Green sensor wire, which is signal out.
*/

#include <Arduino.h>

const int pressurePin = 34;

// variable for storing the potentiometer value
int pressureValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  pressureValue = analogRead(pressurePin);
  Serial.println(pressureValue);
  delay(500);
}