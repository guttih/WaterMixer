# Water Mixer

This project mixes water temperature from a 1/2" hot water pipe and a 1/2" cold water pipe out to a single 3/4" output 
water pipe.  A electrical valve controls the flow from the hot water pipe and another electrical valve controls the cold
water pipe.  A Temperature sensor is put into the 3/4" output water pipe to sense the current heat of the outgoing water.
Finally the third electrical valve is used to drain the hot tub. 

### Related links

- Project page (todo:)
- [Experiment page]
- [Hot-tub]
- [Setting up PWM to Voltage Converter]
- [Project development documents]

### Parts in project

- 1 x 12V Power supply
- 1 x [HLK-PM01]
- 1 x [ESP32 Development Board]
- 1 x [DS18B20 Digital Temperature Sensor G1/2] or 1 x [DS18B20 Digital Temperature Sensor G3/4]
- 3 x [PWM to Voltage Converter Module]
- 3 x [Proportional Valve Brass controllable with 0-5V]
- 1 x [LCD touch display]

### Wiring the project

When you setup the PWM to Voltage converter make sure that when the esp32 is
sending out PWM 190 of

```
                        ╔═══════════╗
                        ║  DS18B20  ║
                        ║  Sensor   ║
                        ║           ║
┌──────────────────(BL)─╢-GND       ║            
│ ┌────────────────(RD)─╢-VCC       ║
│ │ ╔══════════╗        ║           ║
│ │ ║-Resistor-║        ║           ║
│ ├─╢-  4.7kΩ -╟─┬─(YE)─╢-SIGNAL    ║                                      Power
│ │ ╚══════════╝ │      ╚═══════════╝                                     source
│ │              │                                                          -GND
│ │            ┌─┘             ┌─────────────────┬────────────────────────────┤
│ │            │               │ ╔═════════════╗ │                            │
│ │            │               │ ║   PWM to    ║ │      ╔════════════╗        │
│ │            │ ╔═══════════╗ │ ║   voltage   ║ │      ║   Valve 1  ║        │ 
│ │            │ ║  -ESP32-  ║ │ ║ converter 1 ║ │      ║            ║        │
│ │            │ ║           ║ │ ║         GND-╟─┘      ║    PWM Out-╟─(WT)─  │
│ │            └─╢-G25  GND -╟─┴─╢-GND    VOUT-╟───(GR)─╢-LIN    ERR-╟─(YE)─  │
│ └──────────────╢-3V3       ║   ║             ║        ║            ║        │
│ ╔══════════╗   ║      G32 -╟───╢-PWM     VCC-╟─┬─(RD)─╢-VCC    GND-╟─(BL)───┤
│ ║-HLK-PM01-║   ║      G33 -╟─┐ ╚═════════════╝ │      ╚════════════╝        │
│ ║          ║   ║           ║ │                 │                      Power │  
│ ║+Vo (+5V)-╟───╢-VIN       ║ │ ╔═════════════╗ │                      Source│  
│ ║-Vo (GND)-╟─┬─╢-GND       ║ │ ║    PWM to   ║ ├───────────────────── +12V  │
│ ╚══════════╝ │ ╚═══════════╝ │ ║   voltage   ║ │      ╔════════════╗        │
│              │               │ ║ converter 2 ║ │      ║   Valve 2  ║        │
│              │               │ ║             ║ │      ║    PWM Out-╟─(WT)─  │
│              │               │ ║         VCC-╟─┴─(RD)─╢-VCC    ERR-╟─(YE)─  │
│              │               └─╢-PWM    VOUT-╟───(GR)─╢-LIN    GND-╟─(BL)───┤
│              │               ┌─╢-GND     GND-╟─┐      ╚════════════╝        │
│              │               │ ╚═════════════╝ │                            │
└──────────────┴───────────────┴─────────────────┴────────────────────────────┘
```

Legend

- <span style="background: black; color: white">(BL) = Black wire (-Ground)</span>
- <span style="background: red; color: white">(RD) = Red wire (+VCC)</span>
- <span style="background: yellow; color: black">(YE) = Yellow wire</span>
- <span style="background: green; color: white">(GR) = Green wire (voltage signal)</span>
- <span style="background: white; color: black">(WT) = White wire</span>
- GND    : Esp32 GND pin which is ground.
- 3V3    : Esp32 3.3 volts pin.
- G25    : Esp32 GPIO 25 pin which is used to communicate with the sensor.
- G32    : Esp32 GPIO 32 pin which is used control the hot water valve.
- G33    : Esp32 GPIO 33 pin which is used control the cold water valve.

### Software development

The software for this project was developed using [PlatformIO].

#### Tests

There are two kinds of tests in this project, *integration tests* and *unit tests*.

__Integration tests__:
*integration tests* are located in the `./test` directory.

On windows 10, best would be if you would add this location to your PATH system environment variable __C:\Users\your_user_name\.platformio\penv\Scripts__ to get access to the pio.exe application.
C:\Users\gudjons\.platformio\penv\Scripts
Then you can run the tests with this command `pio test`



[HLK-PM01]:https://www.aliexpress.com/item/32504127465.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[ESP32 Development Board]:https://www.aliexpress.com/item/32801621054.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[DS18B20 Digital Temperature Sensor G1/2]:https://www.aliexpress.com/item/32827650291.html?spm=a2g0s.12269583.0.0.36871f7dTzfCfF
[DS18B20 Digital Temperature Sensor G3/4]:https://www.aliexpress.com/item/32881183992.html?spm=a2g0s.12269583.0.0.43c751fcxDyDbt
[PWM to Voltage Converter Module]:https://www.aliexpress.com/item/4000169156580.html?spm=a2g0s.12269583.0.0.7faa1ca26zCgTQ
[Proportional Valve Brass controllable with 0-5V]:https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.49d04a42eL9zNl
[Experiment page]: https://guttih.com/list/project-hottub-temp
[Hot-tub]:http://192.168.1.79/list/project-hottub
[Setting up PWM to Voltage Converter]:docs/Development/pwmToVoltateConverter.md
[cmake]:https://cmake.org/download/#latest
[PlatformIO]:https://platformio.org/
[Project development documents]: docs/Development/development.md
[LCD touch display]: https://www.aliexpress.com/item/4000030399357.html?spm=a2g0s.12269583.0.0.687d6973QvjfAl