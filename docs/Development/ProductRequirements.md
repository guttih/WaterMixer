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
and other lower priority features will be released later.

### Users
Description of the two main personas this product is intended for.
 
   * __John__ is a 30 years old DIY kind a guy.  John knows a little programming, knows about GitHub and knows 
   JavaScript.  He understands the concept of a API and what a PID controller does, but is no specialist.

   * __Kamila__ is a 11 years old non technical kind a girl.  She knows how to use a web browser on a phone and 
   a computer.

Table column description:
  * __Feature Id__ A short, unique, one word name of a feature
  * __User Story__ As a [persona], I [want to], [so that]
  * __P__ Priority/Importance of the feature. Available values: `H` `N` `L`. Where H=High, N=Normal and L = Low.
  * __R__ Feature is selected into a release numbered something. Read about [Releases].
  * __Notes__ Additional considerations or better explanation of the story.

|  Feature Id            | User Story                                                                                                | P |   R   | Notes |
|:----------------------:|-----------------------------------------------------------------------------------------------------------|---|-------|-------|
| [LCD_VALVE_STATUS]       | As John, I stand in front of the unit and want know how much the hot and cold valves are open           | H | [0.5] |       |
| [LCD_FILL]               | As Kamila, I stand in front of the unit and want to fill the hot tub                                    | H | [0.5] |       |
| [LCD_STOP]               | As Kamila, I stand in front of the unit and want to stop the flow to the hot tub                        | H | [0.5] |       |
| [LCD_DRAIN]              | As Kamila, I stand in front of the unit and want to drain the hot tub                                   | H | [0.5] |       |
| [LCD_STATUS_TEMP]        | As Kamila, I stand in front of the unit and want to know the water temperature                          | N | [0.5] |       |
| [LCD_TEMP]               | As Kamila, I stand in front of the unit and want to change the water temperature flowing to the hot tub | H | [0.5] |       |
| [LCD_STATUS_FLOW]        | As Kamila, I stand in front of the unit and want to know the water flow rate                            | N | [0.7] |       |
| [LCD_FLOW_SLOW]          | As Kamila, I stand in front of the unit and want to make water flow slowly to the hot tub               | N | [0.7] |       |
| [LCD_STATUS_WHEN_FULL]   | As Kamila, I stand in front of the unit and want to know when the hot tub will be full                  | L | [1.0] |  This is after some one has initiated the filling process |
| [LCD_STATUS_WHEN_EMPTY]  | As Kamila, I stand in front of the unit and want to know when the hot tub will be fully drained         | L | [1.0] |  This is after some one has initiated the draining process |
| [LCD_STATUS_WATER_LEVEL] | As Kamila, I stand in front of the unit and want to know the current hot tub water level                | L | [1.0] |       |


### Related pages
 * [Readme](../../README.md)
 * [System requirements here](./SystemRequirements.md)
 * [Product requirements](./ProductRequirements.md#features)
 * [User stories](./UserStories.md)
 * [Releases](./Releases.md)


[Releases]: ./Releases.md
[0.5]: ./Releases.md#release-05---bare-minimum
[0.6]: ./Releases.md#release-06--hardware-installed
[0.7]: ./Releases.md#release-07---additional-features
[0.8]: ./Releases.md#release-08---remote-access
[0.9]: ./Releases.md#release-09---boxed
[1.0]: ./Releases.md#release-10

[LCD_VALVE_STATUS]: ./UserStories.md#lcd_valve_status
[LCD_FILL]: ./UserStories.md#lcd_fill
[LCD_STOP]: ./UserStories.md#lcd_stop
[LCD_DRAIN]: ./UserStories.md#lcd_drain           
[LCD_STATUS_TEMP]: ./UserStories.md#lcd_status_temp
[LCD_TEMP]: ./UserStories.md#lcd_temp
[LCD_STATUS_FLOW]: ./UserStories.md#lcd_status_flow
[LCD_FLOW_SLOW]: ./UserStories.md#lcd_flow_slow
[LCD_STATUS_WHEN_FULL]: ./UserStories.md#lcd_status_when_full
[LCD_STATUS_WHEN_EMPTY]: ./UserStories.md#lcd_status_when_empty
[LCD_STATUS_WATER_LEVEL]: ./UserStories.md#lcd_status_water_level