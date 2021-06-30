#include <OneWire.h>
#include <DallasTemperature.h>

/* 
    Sketch to test if the DS18B20 temperature sensor is wired correctly.


    You will need a 4.7k ohm resistor to wire the sensor and 
    to use this sketch, you will need to install these two libraries: 
      - OneWire library by Paul Stoffregen 
      - DallasTemperature by Miles Burton

    
    Wire the sensor like this.

 ╔═══════════╗                        ╔═══════════╗
 ║   ESP32   ║                        ║  DS18B20  ║
 ║           ║                        ║  Sensor   ║
 ║           ║                        ║           ║
 ║      GND -╟────────────────────────╢- Black    ║
 ║      3V3 -╟──┬─────────────────────╢- Red      ║
 ║           ║  │  ╔═══════════╗      ║           ║
 ║           ║  │  ║-Resistor -║      ║           ║
 ║           ║  └──╢-  4.7kΩ  -╟──┬───╢- Yellow   ║
 ║           ║     ╚═══════════╝  │   ╚═══════════╝
 ║      G25 -╟────────────────────┘
 ╚═══════════╝

**legend
    GND    : Esp32 GND pin which is ground.
    3V3    : Esp32 3.3 volts pin.
    G25    : Esp32 GPIO 25 pin which is used to communicate with the sensor.
    Black  : DS18B20 sensor black or blue wire which is ground.
    Red    : DS18B20 sensor red wire which is VCC.
    Yellow : DS18B20 sensor yellow or white which is the data wire.
*/

// GPIO where the DS18B20 signal wire is connected to
const int oneWireBus = 25;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  delay(1000);
}