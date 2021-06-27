# Water Mixer

This project mixes water temperature from a 1/2" hot water pipe and a 1/2" cold
water pipe out to a single 3/4" output water pipe.  A electrical valve controls 
the flow from the hot water pipe and another electrical valve controls the cold
water pipe.  A Temperature sensor is put into the 3/4" output water pipe to sense
the current heat of the outgoing water.


### Parts in project

 - 1 x 12V Power supply
 - 1 x [HLK-PM01]
 - 1 x [ESP32 Development Board]
 - 1 x [DS18B20 Digital Temperature Sensor G1/2] or 1 x [DS18B20 Digital Temperature Sensor G3/4]
 - 2 x [PWM to Voltage Converter Module]
 - 2 x [Proportional Valve Brass controllable with 0-5V]



### Wiring the project

```
         ╔═══════════╗
         ║  DS18B20  ║
         ║  Sensor   ║                                                      Power
         ║           ║                                                      source
┌───(BL)─╢-GND       ║                                                      -GND
│┌──(RD)─╢-VCC       ║         ┌─────────────────┬────────────────────────────┤
││┌─(YE)─╢-SIGNAL    ║         │ ╔═════════════╗ │                            │
│││      ╚═══════════╝         │ ║   PWM to    ║ │      ╔════════════╗        │
│││              ╔═══════════╗ │ ║   voltage   ║ │      ║   Valve 1  ║        │ 
│││              ║  -ESP32-  ║ │ ║ converter 1 ║ │      ║            ║        │
│││              ║           ║ │ ║         GND-╟─┘      ║    PWM Out-╟─(WT)─  │
││└──────────────╢-D12  GND -╟─┴─╢-GND    VOUT-╟───(GR)─╢-LIN    ERR-╟─(YE)─  │
│└───────────────╢-3V3       ║   ║             ║        ║            ║        │
│ ╔══════════╗   ║      D32 -╟───╢-PWM     VCC-╟─┬─(RD)─╢-VCC    GND-╟─(BL)───┤
│ ║-HLK-PM01-║   ║      D33 -╟─┐ ╚═════════════╝ │      ╚════════════╝        │
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


[HLK-PM01]:https://www.aliexpress.com/item/32504127465.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[ESP32 Development Board]:https://www.aliexpress.com/item/32801621054.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[DS18B20 Digital Temperature Sensor G1/2]:https://www.aliexpress.com/item/32827650291.html?spm=a2g0s.12269583.0.0.36871f7dTzfCfF
[DS18B20 Digital Temperature Sensor G3/4]:https://www.aliexpress.com/item/32881183992.html?spm=a2g0s.12269583.0.0.43c751fcxDyDbt
[PWM to Voltage Converter Module]:https://www.aliexpress.com/item/4000169156580.html?spm=a2g0s.12269583.0.0.7faa1ca26zCgTQ
[Proportional Valve Brass controllable with 0-5V]:https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.49d04a42eL9zNl
