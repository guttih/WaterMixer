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

|  Feature Id             | User Story                                                                                                | P |   R   | Notes |
|:-------------------------------:|-----------------------------------------------------------------------------------------------------------|---|-------|-------|
| [lcd_valve_status]          | As John, I stand in front of the unit and want know how much the hot and cold valves are open           | H | [0.5] |       |
| [lcd_fill]                  | As Kamila, I stand in front of the unit and want to fill the hot tub                                    | H | [0.5] |       |
| [lcd_stop]                  | As Kamila, I stand in front of the unit and want to stop the flow to the hot tub                        | H | [0.5] |       |
| [lcd_drain]                 | As Kamila, I stand in front of the unit and want to drain the hot tub                                   | H | [0.5] |       |
| [lcd_status_temp]           | As Kamila, I stand in front of the unit and want to know the water temperature                          | N | [0.5] |       |
| [lcd_temp]                  | As Kamila, I stand in front of the unit and want to change the water temperature flowing to the hot tub | H | [0.5] |       |
| [lcd_pid_change]            | As John, I stand in front of the unit and want change the PID values                                    | H | [0.5] |       |
| [lcd_system_scan]           | As John, I stand in front of the unit and want the system to learn how to get desired temperature       | H | [0.5] |       |
| [lcd_status_flow]           | As Kamila, I stand in front of the unit and want to know the water flow rate                            | N | [0.7] |       |
| [lcd_flow_slow]             | As Kamila, I stand in front of the unit and want to make water flow slowly to the hot tub               | N | [0.7] |       |
| [lcd_pid_change_auto]       | As John, I stand in front of the unit and want auto tune the PID values                                 | H | [0.7] |       |
| [wifi_fill]                 | As Kamila, I want to fill the hot tub via web browser.                                                  | H | [0.8] |       |
| [wifi_stop]                 | As Kamila, I want to stop flow, to and from the hot tub via web browser.                                | H | [0.8] |       |
| [wifi_drain]                | As Kamila, I want to drain  the hot tub via web browser.                                                | H | [0.8] |       |
| [lcd_status_when_full]      | As Kamila, I stand in front of the unit and want to know when the hot tub will be full                  | L | [1.0] |  This is after some one has initiated the filling process |
| [lcd_status_when_empty]     | As Kamila, I stand in front of the unit and want to know when the hot tub will be fully drained         | L | [1.0] |  This is after some one has initiated the draining process |
| [lcd_water_level_predict]   | As Kamila, I stand in front of the unit and want to know the projected hot tub water level.             | L | [1.0] |       |
| [lcd_status_dim_backlight]  | As John, I stand in front of the unit and want to set the backlight brightness of the LCD display.      | L | [1.1] |       |
| [lcd_water_level_current]   | As John, I stand in front of the unit and want to change the backlight brightness of the LCD display.   | L | [1.1] |       |


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


[Releases]: ./releases.md
[0.5]: ./releases.md#release-05---bare-minimum
[0.6]: ./releases.md#release-06--hardware-installed
[0.7]: ./releases.md#release-07---additional-features
[0.8]: ./releases.md#release-08---remote-access
[0.9]: ./releases.md#release-09---boxed
[1.0]: ./releases.md#release-10
[1.1]: ./releases.md#release-11

[lcd_valve_status]: ./userStories.md#lcd_valve_status
[lcd_fill]: ./userStories.md#lcd_fill
[lcd_stop]: ./userStories.md#lcd_stop
[lcd_drain]: ./userStories.md#lcd_drain           
[lcd_status_temp]: ./userStories.md#lcd_status_temp
[lcd_temp]: ./userStories.md#lcd_temp
[lcd_status_flow]: ./userStories.md#lcd_status_flow
[lcd_flow_slow]: ./userStories.md#lcd_flow_slow
[lcd_status_when_full]: ./userStories.md#lcd_status_when_full
[lcd_status_when_empty]: ./userStories.md#lcd_status_when_empty
[lcd_water_level_predict]: ./userStories.md#lcd_water_level_predict
[lcd_water_level_current]: ./userStories.md#lcd_water_level_current
[lcd_pid_change]: ./userStories.md#lcd_pid_change
[lcd_pid_change_auto]: ./userStories.md#lcd_pid_change_auto
[wifi_fill]: ./userStories.md#wifi_fill
[wifi_stop]: ./userStories.md#wifi_stop
[wifi_drain]: ./userStories.md#wifi_drain 
[lcd_status_dim_backlight]: ./userStories.md#lcd_status_dim_backlight
[lcd_system_scan]: ./userStories.md#lcd_system_scan
