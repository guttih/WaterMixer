# System Requirements
This document (SRD) provides information about what environment and hardware will be needed to make this product work.

## Hardware requirements

In general to make this product work these hardware modules will be needed.

Table column description:
  * __Hardware Id__ A short, unique, one word name of the hardware or device in question.
  * __Name__ Name of the part.
  * __Units__ How many peases of this kind of part is needed.
  * __R__ For what release is this parted needed.  Read about [Releases].

|  Hardware Id        | Name                                            | Units |   R   | The device is needed because                                         |
|:-------------------:|-------------------------------------------------|:------:|-------|---------------------------------------------------------------------|
| [ESP32]             | ESP32 Development Board                         |   1    | [0.5] | Control everything                                                  |
| [DS18B20]           | DS18B20 3/4" temperature sensor                 |   1    | [0.5] | Provide water temperature in the outgoing pipe                      |
| [PWM_TO_VOLTAGE]    | PWM to Voltage Converter Module                 |   3    | [0.5] | Allow esp32 to control the valves                                   |
| [PROPORTIONAL_VALVE]| Proportional Valve Brass controllable with 0-5V |   3    | [0.5] | Allow esp32 to control the valves                                   |
| [LCD_TOUCH_DISPLAY] | 2.8" LCD Touch Display                          |   1    | [0.5] | To pass user information and get input from user                    |
| 12V_POWER_SUPPLY    | 12 volt power supply                            |   1    | [0.5] | Power the three [PROPORTIONAL_VALVE] and the three [PWM_TO_VOLTAGE] |
| [HLK-PM01]          | 5 volt power supply                             |   1    | [0.5] | Power [ESP32], [DS18B20] and [PRESSURE_SENSOR]                      |
| [PRESSURE_SENSOR]   | 5 psi pressure sensor                           |   1    | [1.0] | Needed to test the water level of the hot tub                       |


 ### Related pages
 * [Readme](../../README.md)
 * [Project requirements here](./ProductRequirements.md)
 * [System requirements here](./SystemRequirements.md)
 * [Product requirements](./ProductRequirements.md#features)
 * [User stories](./UserStories.md)
 * [Releases](./Releases.md)


[0.5]: ./Releases.md#release-05---bare-minimum
[0.6]: ./Releases.md#release-06--hardware-installed
[0.7]: ./Releases.md#release-07---additional-features
[0.8]: ./Releases.md#release-08---remote-access
[0.9]: ./Releases.md#release-09---boxed
[1.0]: ./Releases.md#release-10

[PlatformIO]: https://platformio.org/
[VoffCon]: http://voffcon.com/
[HLK-PM01]: https://www.aliexpress.com/item/32504127465.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[ESP32]: https://www.aliexpress.com/item/32801621054.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n
[DS18B20]: https://www.aliexpress.com/item/32881183992.html?spm=a2g0s.12269583.0.0.43c751fcxDyDbt
[PWM_TO_VOLTAGE]: https://www.aliexpress.com/item/4000169156580.html?spm=a2g0s.12269583.0.0.7faa1ca26zCgTQ
[PROPORTIONAL_VALVE]: https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.49d04a42eL9zNl
[PRESSURE_SENSOR]: https://www.aliexpress.com/item/4000263209249.html?spm=a2g0s.12269583.0.0.5dd91d80iwCJ6y
[LCD_TOUCH_DISPLAY]: https://www.aliexpress.com/item/4000030399357.html?spm=a2g0s.12269583.0.0.687d6973QvjfAl

[Readme]: ../../README.md
[Releases]: ./Releases.md

[Product requirements]: ./ProductRequirements.md