# Product requirements
This Product Requirements Document(PRD) describes the requirements the Water mixer project needs to fulfill.  In this 
document, the Water mixer project and all its components will be referred to as the unit.

## Purpose
The main purpose of this project is to provide a user with an easy way to control water flow to and from a hot tub.  
A user should be able to command the unit to fill a hot tub at a specific temperature.  The user should be able to use 
it to control how fast the water flows to the hot tub and also to drain the hot tub.

To achieve this the unit will need to provide the user with information about it’s status and a way to give it commands.
  The user should be able to get the status and and give commands in two ways:

  * __At premises__ When the user is standing in front of the device he should be able to see it’s status, that is, 
  view the value of any status variable and to be able to give any of the available commands.

  * __Remotely__   When the user is not standing in front of the unit, he should be able to see it’s status, that is, 
  view the value of any status variable and to be able to give any of the available commands.



## Features
To be able to fulfill the purpose of this product the features will need to be described and implemented before release.  
They need to be prioritized and later selected into releases.  High priority features will be released first, 
and other lower priority features will be selected and released later.

### Users
Description of the two main personas this product is intended for.
 
   * __John__ is a 30 years old DIY kind a guy.  John knows a little programming, knows about GitHub and knows 
   JavaScript.  He understands the concept of a API and what a PID controller does, but is no specialist.

   * __Kamila__ is a non 11 years old non technical kind a girl.  She knows how to use a computer and a phone and 
   knows how to use a web browser.

Table column description:
  * __Feature Id__ Short one word name of feature
  * __User Story__ As a [persona], I [want to], [so that]
  * __P__ Priority/Importance of the feature. Available values: `H` `N` `L`. Where H=High, N=Normal and L = Low.
  * __R__ Feature is selected into a [release](#releases) numbered something. 
  * __Notes__ Additional considerations or better explanation of the story.

|  Feature Id            | User Story                                                                                              | P |  R  | Notes |
|:----------------------:|---------------------------------------------------------------------------------------------------------|---|-----|-------|
| LCD_FILL               | As Kamila, I stand in front of the unit and want to fill the hot tub                                    | H | 0.5 |       |
| LCD_STOP               | As Kamila, I stand in front of the unit and want to stop the flow to the hot tub                        | H | 0.5 |       |
| LCD_DRAIN              | As Kamila, I stand in front of the unit and want to drain the hot tub                                   | H | 0.5 |       |
| LCD_STATUS_TEMP        | As Kamila, I stand in front of the unit and want to know the water temperature                          | N | 0.5 |       |
| LCD_TEMP               | As Kamila, I stand in front of the unit and want to change the water temperature flowing to the hot tub | H | 0.5 |       |
| LCD_STATUS_FLOW        | As Kamila, I stand in front of the unit and want to know the water flow rate                            | N | 0.7 |       |
| LCD_FLOW_SLOW          | As Kamila, I stand in front of the unit and want to make water flow slowly to the hot tub               | N | 0.7 |       |
| LCD_STATUS_WHEN_FULL   | As Kamila, I stand in front of the unit and want to know when the hot tub will be full                  | L | 1.0 |  This is after some one has initiated the fylling process |
| LCD_STATUS_WHEN_EMPTY  | As Kamila, I stand in front of the unit and want to know when the hot tub will be fully drained         | L | 1.0 |  This is after some one has initiated the draining process |
| LCD_STATUS_WATER_LEVEL | As Kamila, I stand in front of the unit and want to know the current hot tub water level                | L | 1.0 |       |

In order

## Releases
The product will not be released all at ones, but rather in stages.  Features will be selected into releases which will 
be released on different dates.  From release 1.0 and onward the product will be considered a usable product, but all 
releases below 1 will be considered experimental.

### Release 0.5 - Bare minimum
This release will have the bare minimum features to work.  The product has been installed and contains a LCD 
touch Display which can be used to give the unit commands.  The unit is connected to [VoffCon] via wifi but no emphasis
is put on the remote part of the unit.  All hardware that should be connected to the unit are not necessarily installed.
  * Date: unknown

### Release 0.6- Hardware installed
All hardware devices are installed and wired to the unit but the software does not necessarily has a interface for them yet.
  * Date: unknown

### Release 0.7 - Additional features
Additional features have been added to the bare minimum number of features.
  * Date: unknown

### Release 0.8 - Remote access
The user can get status from the unit and give it commands remotely.  This is done using [VoffCon].
  * Date: unknown

### Release 0.9 - Boxed
The unit has been put into a box and all wires hidden from the user.  The user can only touch the LSD display every
thing else is protected from the user touch.
  * Date: unknown
file:///C:/Users/gutti/source/repos/WaterMixer/docs/Development/Requirements.md#release-10
### Release 1.0
The unit has been packaged and tested and is ready for the world.
  * Date: unknown



[releases] :./#releases
[VoffCon] :http://voffcon.com/
