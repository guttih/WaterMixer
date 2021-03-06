# Hardware
This document describes each device, what voltage it uses and where it was bought.

## esp32
__Esp32 Development board__

This device handles all the work and is connected to all other devices.

 - Bought [here](https://www.aliexpress.com/item/32801621054.html?spm=a2g0s.9042311.0.0.27424c4dOggB1n)
 - Inventory [Here](http://parts.guttih.com/parts/view/5bfab5e0ec065a5ac2786934)


## temperature_sensor
__DS18B20 3/4" temperature sensor__ 

The sensor provides information on the water pressure in the pipe connected to the hot tub.  
It can run on both 5V and 3.3V power.

- Bought [DS18B20 Color L30mm Thread Specification 3/4"](https://www.aliexpress.com/item/32881183992.html?spm=a2g0s.12269583.0.0.43c751fcxDyDbt) 
- Inventory [Here](http://parts.guttih.com/parts/view/60c1c1c063ec3e056918c551)

## LLC 
__Logic level converter__

This device is used to convert 3.3V logic signals from the esp32 to 5V logic signals for the DAC.


- Bought [here](https://www.aliexpress.com/item/Free-shipping-4-channel-IIC-I2C-Logic-Level-Converter-Bi-Directional-Module-5V-to-3-3V/32308653416.html?spm=a2g0s.9042311.0.0.27424c4dy510IB)
- Inventory [Here](http://parts.guttih.com/parts/view/5bf9e9d1a66f3c7ee749efc5)


## MCP4728 
__DAC MCP4728 Module__

This device is used to send voltage ranging from 0-5 volts which a proportional
valve understands.


- Bought [here](https://www.aliexpress.com/item/32975252305.html?spm=a2g0s.12269583.0.0.142b3d73bl1KXq)
- Inventory [Here](http://parts.guttih.com/parts/view/61110ca1643bf7053b856df2)

## proportional_valve
__12V Proportional Valve__

There are three valves in this project, one 3/8" and two 3/4" valves.  They work exactly the same so we will consider 
them all three units of the same device.  The 3/8" unit will be controlling the drain water flow.

- Bought 2 x [Voltage: DC9V to DC24V, Specification: DN20 BSP Thread, Wiring Control: 0V to 5V Signal](https://www.aliexpress.com/item/32819881011.html?spm=a2g0s.12269583.0.0.112c1eaeyGDt8f)
- Bought 1 x [Voltage:DC9V-24V 0-5V, Specification: DN10 Brass Valve, Thread Type: NPT](https://www.aliexpress.com/item/33037988030.html?spm=a2g0s.12269583.0.0.6c674a42N25diC)
- Inventory [Here](http://parts.guttih.com/parts/view/5e2589736d7d870510d99be2)

## lcd_touch_display
  __3.2 Display module with touch and SD card reader__

  The device __needs 3.3V__ power to work.  The J1 has been soldered so 5V is out of the question.


- Bought [here](https://www.aliexpress.com/item/33040270372.html?spm=a2g0s.12269583.0.0.437c3e40dV19J4)
- Inventory [Here](http://parts.guttih.com/parts/view/60f1a0d4ea0ad5055e96116e)

## 12v_power_supply

Needed to power the three _12V Proportional Valves_

__Not selected yet__
- Bought todo: select product
- Inventory todo: add product to inventory

## 5v_power_supply

__DC_STEPDOWN__ 

This small adjustable step down power supply is needed to supply the pressure sensor and the Esp32 with power.
This unit will get power from the __12v_power_supply__ and will be be adjusted to give __5.05V__ output power.

- Bought [DC_STEPDOWN](https://www.aliexpress.com/item/32531438467.html?spm=a2g0s.9042311.0.0.27424c4dWJSXmG)
- Inventory [Here](http://192.168.1.79:6300/parts/view/5bfae6c1ec065a5ac278698f)


## 3v3_power_supply

__DC_STEPDOWN__ 

This small adjustable step down power supply is needed to supply the temperature sensor and the lcd touch display with power.
This unit will get power from the __12v_power_supply__ and will be be adjusted to give __3.2V__ output power.

- Bought [DC_STEPDOWN](https://www.aliexpress.com/item/32531438467.html?spm=a2g0s.9042311.0.0.27424c4dWJSXmG)
- Inventory [Here](http://192.168.1.79:6300/parts/view/5bfae6c1ec065a5ac278698f)



## pressure_sensor

This sensor needs 5V power to work and provides information on the water pressure in the pipe connected to the hot tub.

- Bought ~~[Pressure Sensor 5V 1/8" 5 Psi](https://www.aliexpress.com/item/4000263209249.html?spm=a2g0s.12269583.0.0.5dd91d80iwCJ6y)~~ which is incorrect because it woks on 0-0.345 bars
- Should have bought [Pressure Sensor 5V 1/8" 60 Psi](https://www.aliexpress.com/item/4000263209249.html?spm=a2g0s.12269583.0.0.5dd91d80iwCJ6y) which works on 0-4 bars.
- Inventory [Here](http://parts.guttih.com/parts/view/60cc6e7b395390058cb396d8)


 ### Related pages
 * [Readme]
 * [Product requirements]
 * [System requirements]
 * [Product requirements]
 * [User stories]
 * [Hardware]
 * [Releases]


[Readme]: ../../README.md
[Product requirements]: ./productRequirements.md
[System requirements]: ./systemRequirements.md
[User stories]: ./userStories.md
[Hardware]: ./hardware.md
[Releases]: ./releases.md

