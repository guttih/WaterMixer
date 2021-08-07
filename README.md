# Water Mixer

This project mixes water temperature from a 1/2" hot water pipe and a 1/2" cold water pipe out to a single 3/4" output 
water pipe.  A electrical valve controls the flow from the hot water pipe and another electrical valve controls the cold
water pipe.  A Temperature sensor is put into the 3/4" output water pipe to sense the current heat of the outgoing water.
Finally the third electrical valve is used to drain the hot tub. 

## Related links

- Project page (todo:)
- [Experiment page]
- [Hot-tub]
- [Setting up PWM to Voltage Converter]
- Project [Development documents]

## Parts in project

- 1 x 12V Power supply
- 2 x [DC_STEPDOWN]
- 1 x [ESP32 Development Board]
- 1 x [DS18B20 Digital Temperature Sensor G3/4]
- 3 x [PWM to Voltage Converter Module]
- 3 x [Proportional Valve Brass controllable with 0-5V]
- 1 x [LCD touch display]

## Wiring the project

When you setup the PWM to Voltage converter make sure that when the esp32 is never sending more than 190 of 255 to the 
PWM to voltage converts because that will result in a 5V output voltage to the valves.

### Schematic

```
                          ╔═════════════╗ ╔══════════════╗
  +5V                     ║ DC_STEPDOWN ║ ║ POWER SOURCE ║
   ┌──────────────────────╢-  +Vo(+5V) -╟ ║              ║
   │  ┌─────────────────┬─╢-  -Vo(GND) -╟ ║              ║
   │  │ ╔═══════════╗   │ ║             ║ ║              ║                                +12V
   │  │ ║ Resistor  ║   │ ║         VIN-╟─╢-    +12V    -╟───────────────────────────────────┐
   │  ├─╢-  4.7kΩ  -╟─┐ │ ║         GND-╟─╢-    -GND    -╟────────────────────────────────┐  │
   │  │ ╚═══════════╝ │ │ ╚═════════════╝ ╚══════════════╝                                │  │
   │  │ ╔═══════════╗ │ └─────────────────┬───────────────────┬───────────────────────────┤  │
   │  │ ║ Pressure  ║ │                   │   ╔═════════════╗ │                           │  │
   │  │ ║  Sensor   ║ │                   │   ║   PWM to    ║ │      ╔════════════╗       │  │
   │  │ ║           ║ │                   │   ║ converter H ║ │      ║            ║       │  │
   │  └─╢-Black     ║ │                   │   ║   voltage   ║ │      ║   Valve H  ║       │  │
   ├────╢-Red       ║ │                   │   ║         GND-╟─┘      ║    PWM Out-╟─(WT)─ │  │
   │ ┌──╢-Green     ║ │                   ├───╢-GND    VOUT-╟───(GR)─╢-LIN    ERR-╟─(YE)─ │  │
   │ │  ╚═══════════╝ │     ╔═══════════╗ │ ┌─╢-PWM     VCC-╟─┬─(RD)─╢-VCC    GND-╟─(BL)──┤  │
   │ │  ╔═══════════╗ │     ║  -ESP32-  ║ │ │ ╚═════════════╝ │      ╚════════════╝       ┴  │
   │ │  ║ Resistor  ║ │     ║           ║ │ │                 │                          GND │
   │ └──╢-  3.3kΩ  -╟─┴─────╢-G34  GND -╟─┘ │ ╔═════════════╗ │                              │
   │    ╚═══════════╝       ║           ║   │ ║    PWM to   ║ ├──────────────────────────────┤
   └────────────────────────╢-VIN       ║   │ ║   voltage   ║ │      ╔════════════╗          │
        ╔═══════════╗     ┌─╢-G25  G12 -╟───┘ ║ converter C ║ │      ║   Valve C  ║          │
+3V3    ║  Resistor ║     │ ║      G14 -╟───┐ ║             ║ │      ║    PWM Out-╟─(WT)─    │
┌───────╢-  4.7kΩ  -╟─────┤ ║      G32 -╟─┐ │ ║         VCC-╟─┴─(RD)─╢-VCC    ERR-╟─(YE)─    │
│       ╚═══════════╝     │ ║           ║ │ └─╢-PWM    VOUT-╟───(GR)─╢-LIN    GND-╟─(BL)──┐  │
│       ╔═══════════╗     │ ║           ║ │ ┌─╢-GND     GND-╟─┐      ╚════════════╝       │  │
│       ║  DS18B20  ║     │ ║           ║ │ │ ╚═════════════╝ ├───────────────────────────┤  │
│       ║   Temp    ║     │ ║           ║ │ └─────────────────┘                           ┴  │
│       ║  Sensor   ║     │ ║           ║ │   ╔═════════════╗                            GND │
│       ║           ║     │ ║  -ESP32-  ║ │   ║    PWM to   ║ ┌──────────────────────────────┤
│       ║    SIGNAL-╟─(YE)┘ ║           ║ │   ║   voltage   ║ │      ╔════════════╗          │
├──(RD)─╢-VCC       ║       ║           ║ │   ║ converter D ║ │      ║   Valve D  ║          │
│ ┌(BL)─╢-GND       ║       ║           ║ │   ║             ║ │      ║    PWM Out-╟─(WT)─    │
│ │     ╚═══════════╝       ║           ║ │   ║         VCC-╟─┴─(RD)─╢-VCC    ERR-╟─(YE)─    │
│ ├─────────────────────┬───╢-GND       ║ └───╢-PWM    VOUT-╟───(GR)─╢-LIN    GND-╟─(BL)──┐  │
│ │  ╔══════════════╗   │   ║           ║   ┌─╢-GND     GND-╟─┐      ╚════════════╝       │  │
│ │  ║   LCD TOUCH  ║   │   ║           ║   │ ╚═════════════╝ │                           │  │
│ │  ║    DISPLAY   ║   │   ║           ║   └─────────────────┴───────────────────────────┤  │
│ │  ║              ║   │   ║           ║                                                 │  │
│ │  ║          GND-╟───┘   ║  -ESP32-  ║                                                 │  │
│ │  ║      SD_MOSI-╟─┐     ║           ║                                                 │  │
│ │  ║         MOSI-╟─┼───┐ ║           ║                                                 │  │
│ │  ║        T_DIN-╟─┘   │ ║           ║                                                 │  │
│ │  ║       SD_SCK-╟─┐   │ ║           ║                                                 │  │
│ │  ║          SCK-╟─┼─┐ │ ║           ║                                                 │  │
│ │  ║        T_CLK-╟─┘ │ └─╢-G23       ║                                                 │  │
│ │  ║         T_DO-╟─┐ └───╢-G18       ║                                                 │  │
│ │  ║      SD_MISO-╟─┴─────╢-G19       ║                                                 │  │
│ │  ║           CS-╟───────╢-G15       ║                                                 │  │
│ │  ║        RESET-╟───────╢-G4        ║                                                 │  │
│ │  ║           DC-╟───────╢-G2        ║  ┌─────────────────────────┐                    │  │
│ │  ║        SD_CS-╟───────╢-G5        ║  │        ╔═════════════╗  │                    │  │
│ │  ║         T_CS-╟───────╢-G21       ║  │        ║ DC_STEPDOWN ║  │                    │  │
│ │  ║              ║       ║  -ESP32-  ║  │        ║             ║  │                    │  │
│ │  ║          VCC-╟─┐     ╚═══════════╝  │  ┌─────╢- -Vo( GND) -╟  │                    │  │
│ │  ║          LED-╟─┴────────────────────┘  │  ┌──╢- +Vo(+3V3) -╟──┘                    │  │
│ │  ╚══════════════╝                         │  │  ║         GND-╟───────────────────────┘  │
│ └───────────────────────────────────────────┘  │  ║         VIN-╟──────────────────────────┘
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
[PWM to Voltage Converter Module]:https://www.aliexpress.com/item/4000169156580.html?spm=a2g0s.12269583.0.0.7faa1ca26zCgTQ
[Proportional Valve Brass controllable with 0-5V]:https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.49d04a42eL9zNl
[Experiment page]: https://guttih.com/list/project-hottub-temp
[Hot-tub]:http://192.168.1.79/list/project-hottub
[Setting up PWM to Voltage Converter]:docs/development/pwmToVoltateConverter.md
[cmake]:https://cmake.org/download/#latest
[PlatformIO]:https://platformio.org/
[Development documents]: docs/development/development.md
[LCD touch display]: https://www.aliexpress.com/item/4000030399357.html?spm=a2g0s.12269583.0.0.687d6973QvjfAl