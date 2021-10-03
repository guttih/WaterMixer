# Water Mixer

This project mixes water temperature from a 1/2" hot water pipe and a 1/2" cold water pipe out to a single 3/4" output 
water pipe.  A electrical valve controls the flow from the hot water pipe and another electrical valve controls the cold
water pipe.  A Temperature sensor is put into the 3/4" output water pipe to sense the current heat of the outgoing water.
Finally the third electrical valve is used to drain the hot tub. 

## Related links

- Project page (todo:)
- [Experiment page]
- [Hot-tub]
- Project [Development documents]

## Parts in project

- 1 x 12V Power supply
- 2 x [DC_STEPDOWN]
- 1 x [ESP32 Development Board]
- 1 x [DS18B20 Digital Temperature Sensor G3/4]
- 1 x [Logic level converter]
- 1 x [Dac MCP4728]
- 3 x [Proportional Valve Brass controllable with 0-5V]
- 1 x [LCD touch display]

## Wiring the project

### Schematic

```
                                                                                         +12V
                                                                                          ┬
  ┌───────────────────────────────────────────────────────────────────────────────────────┤
  │ ┌───────────────────┬──────────────────┬────────────────┬───────────────────────┬──┐  │
  │ │                   │                  │  ╔══════════╗  │  ╔═════════════╗      ┴  │  │
  │ │ ╔══════════════╗  │  ╔═════════════╗ │  ║ Pressure ║  │  ║     ADC     ║     GND │  │
  │ │ ║ POWER SOURCE ║  │  ║ DC_STEPDOWN ║ │  ║  Sensor  ║  │  ║   ADS1115   ║         │  │
  │ │ ║              ║  │  ║   -Vo(GND) -╟─┘  ║          ║  │  ║             ║         │  │
  │ │ ║              ║  │  ║   +Vo(+5V) -╟─┐  ║    Black-╟──┴──╢-G           ║         │  │
  │ │ ║              ║  │  ║             ║ │  ║    Green-╟─────╢-A0          ║         │  │
  │ └─╢-     GND    -╟──┴──╢-GND         ║ │  ║          ║     ╢-A1          ║         │  │
  └───╢-    +12V    -╟─────╢-VIN         ║ │  ║          ║     ╢-A2          ║         │  │
      ╚══════════════╝     ╚═════════════╝ │  ║          ║     ╢-A3          ║         │  │
                                           │  ║      Red-╟─┬───╢-V           ║         │  │
                      +5V                  │  ╚══════════╝ │ ┌─╢-CL       DA-╟─┐       │  │
                       ┬  ┌────────────────┴───────────────┘ │ ╚═════════════╝ │       │  │
                       └──┤                                  │                 │       │  │
                          │ ╔═══════════╗                    │ ╔═════════════╗ │       │  │
                          │ ║  -ESP32-  ║  ╔═════════════╗   │ ║     DAC     ║ │       │  │
                          │ ║           ║  ║ Logic Level ║   │ ║   MCP4728   ║ │       │  │
                          │ ║           ║  ║  converter  ║   │ ║             ║ │       │  │
                          └─╢-VIN   G14-╟──╢-LV3     HV3-╟───┴─╢-CL          ║ │       │  │
                            ║       G13-╟──╢-LV4     HV4-╟─────╢-DA───────DA-╟─┘       │  │
 +3V3   ╔═══════════╗       ║           ║  ║             ║     ║             ║         │  │
  ┬     ║  Resistor ║       ║           ║  ║             ║ +5V ║           D-╟──────┐  │  │
┌─┴─────╢-  4.7kΩ  -╟─────┬─╢-G25       ║  ║             ║  ┬  ║           C-╟      │  │  │
│       ╚═══════════╝     │ ║       3V3-╟──╢-LV       HV-╟──┴──╢-V         B-╟────┐ │  │  │
│       ╔═══════════╗     │ ║       GND-╟──╢-GND     GND-╟──┬──╢-G         A-╟──┐ │ │  │  │
│       ║  DS18B20  ║     │ ║           ║  ╚═════════════╝  ┴  ╚═════════════╝  │ │ │  │  │
│       ║   Temp    ║     │ ║           ║                  GND                  │ │ │  │  │
│       ║           ║     │ ║           ║                                       │ │ │  │  │
│       ║    SIGNAL-╟─(YE)┘ ║           ║   ┌───────────────────────────────────┘ │ │  │  │
├──(RD)─╢-VCC       ║       ║           ║   │    ┌────────────────────────────────┘ │  │  │
│ ┌(BL)─╢-GND       ║       ║           ║   │    │    ┌─────────────────────────────┘  │  │
│ │     ╚═══════════╝       ║  -ESP32-  ║   │    │    │        ╔════════════╗          │  │
│ │                         ║           ║   │    │    │        ║   Valve D  ║          │  │
│ │                         ║           ║   │    │    │        ║        GND-╟─(BL)─────┤  │
│ │                         ║           ║   │    │    └───(GR)─╢-LIN    ERR-╟─(YE)─    ┴  │
│ │                         ║           ║   │    │             ║    PWM Out-╟─(WT)─   GND │
│ ├─────────────────────┬───╢-GND       ║   │    │             ║        VCC-╟─(RD)────────┤
│ │  ╔══════════════╗   │   ║           ║   │    │             ╚════════════╝             │
│ │  ║   LCD TOUCH  ║   │   ║           ║   │    │             ╔════════════╗             │
│ │  ║    DISPLAY   ║   │   ║           ║   │    │             ║   Valve C  ║             │
│ │  ║              ║   │   ║           ║   │    │             ║        GND-╟─(BL)─────┐  │
│ │  ║          GND-╟───┘   ║  -ESP32-  ║   │    └─────── (GR)─╢-LIN    ERR-╟─(YE)─    ┴  │
│ │  ║      SD_MOSI-╟─┐     ║           ║   │                  ║    PWM Out-╟─(WT)─   GND │
│ │  ║         MOSI-╟─┼───┐ ║           ║   │                  ║        VCC-╟─(RD)────────┤
│ │  ║        T_DIN-╟─┘   │ ║           ║   │                  ╚════════════╝             │
│ │  ║       SD_SCK-╟─┐   │ ║           ║   │                  ╔════════════╗             │
│ │  ║          SCK-╟─┼─┐ │ ║           ║   │                  ║   Valve H  ║             │
│ │  ║        T_CLK-╟─┘ │ └─╢-G23       ║   │                  ║        GND-╟─(BL)─────┐  │
│ │  ║         T_DO-╟─┐ └───╢-G18       ║   └─────────────(GR)─╢-LIN    ERR-╟─(YE)─    ┴  │
│ │  ║      SD_MISO-╟─┴─────╢-G19       ║                      ║    PWM Out-╟─(WT)─   GND │
│ │  ║           CS-╟───────╢-G15       ║                      ║        VCC-╟─(RD)────────┤
│ │  ║        RESET-╟───────╢-G4        ║                      ╚════════════╝             │
│ │  ║           DC-╟───────╢-G2        ║  ┌─────────────────────────┐                    │
│ │  ║        SD_CS-╟───────╢-G5        ║  │        ╔═════════════╗  │                    │
│ │  ║         T_CS-╟───────╢-G21       ║  │        ║ DC_STEPDOWN ║  │                    │
│ │  ║              ║       ║  -ESP32-  ║  │        ║             ║  │                    │
│ │  ║          VCC-╟─┐     ╚═══════════╝  │  ┌─────╢- -Vo( GND) -╟  │  ┌────┐            │
│ │  ║          LED-╟─┴────────────────────┘  │  ┌──╢- +Vo(+3V3) -╟──┘  │    ┴            │
│ │  ╚══════════════╝                         │  │  ║         GND-╟─────┘   GND           │
│ └───────────────────────────────────────────┘  │  ║         VIN-╟───────────────────────┘
└────────────────────────────────────────────────┘  ╚═════════════╝                         
```
Legend

- <span style="background: black; color: white">(BL) = Black wire (-Ground)</span>
- <span style="background: red; color: white">(RD) = Red wire (+VCC)</span>
- <span style="background: yellow; color: black">(YE) = Yellow wire</span>
- <span style="background: green; color: white">(GR) = Green wire (voltage signal)</span>
- <span style="background: white; color: black">(WT) = White wire</span>
- GND    : Ground.
- ` ┴` 
- `GND`  : Ground.  When there is no room to connect the GND on the drawing, this notation is used.  Note, *all grounds are connected together*.
- VIN    : 5V pin on the esp32 pin.
- G34    : Esp32 GPIO 34 pin which is used to measure voltage coming from pressure sensor.
- G25    : Esp32 GPIO 25 pin which is used to communicate with the temperature sensor.
- G12    : Esp32 GPIO 12 pin which is used control the hot water valve.
- G14    : Esp32 GPIO 14 pin which is used control the cold water valve.
- G32    : Esp32 GPIO 32 pin which is used control the drain water valve.
- G##    : Other esp32 pins used to control the touch display and read and write to a sd card.
- Valve H: Hot valve
- Valve C: Cold valve
- Valve D: Drain valve

## Software development

The software for this project was developed using [PlatformIO].

### Tests

There are two kinds of tests in this project, *integration tests* and *unit tests*.

__Integration tests__:
*integration tests* are located in the `./test` directory.

On windows 10, best would be if you would add this location to your PATH system environment variable __C:\Users\your_user_name\.platformio\penv\Scripts__ to get access to the pio.exe application.
C:\Users\gudjons\.platformio\penv\Scripts
Then you can run the tests with this command `pio test`



[DC_STEPDOWN]:https://www.aliexpress.com/item/32531438467.html?spm=a2g0s.9042311.0.0.27424c4dWJSXmG
[ESP32 Development Board]:https://www.aliexpress.com/item/32801621054.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[DS18B20 Digital Temperature Sensor G3/4]:https://www.aliexpress.com/item/32881183992.html?spm=a2g0s.12269583.0.0.43c751fcxDyDbt
[Logic level converter]:https://www.aliexpress.com/item/32308653416.html?spm=a2g0s.9042311.0.0.27424c4dy510IB
[Dac MCP4728]:https://www.aliexpress.com/item/32975252305.html?spm=a2g0s.12269583.0.0.142b3d73bl1KXq
[Proportional Valve Brass controllable with 0-5V]:https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.49d04a42eL9zNl
[Experiment page]: https://guttih.com/list/project-hottub-temp
[Hot-tub]:http://192.168.1.79/list/project-hottub
[cmake]:https://cmake.org/download/#latest
[PlatformIO]:https://platformio.org/
[Development documents]: docs/development/development.md
[LCD touch display]: https://www.aliexpress.com/item/4000030399357.html?spm=a2g0s.12269583.0.0.687d6973QvjfAl