# User stories
This document describes all user stories in more detail.  It should answer what is needs to finish the story.
Each story has a unique identifier and this identifier will be the section name.

## lcd_valve_status
As John, I stand in front of the unit and want know how much the hot and cold valves are open
## lcd_fill
As Kamila, I stand in front of the unit and want to fill the hot tub


## lcd_stop
As Kamila, I stand in front of the unit and want to stop the flow to the hot tub


## lcd_drain
As Kamila, I stand in front of the unit and want to drain the hot tub


## lcd_status_temp
As Kamila, I stand in front of the unit and want to know the water temperature


## lcd_temp
As Kamila, I stand in front of the unit and want to change the water temperature flowing to the hot tub


## lcd_status_flow
As Kamila, I stand in front of the unit and want to know the water flow rate

## lcd_flow_slow
As Kamila, I stand in front of the unit and want to make water flow slowly to the hot tub


## lcd_status_when_full
As Kamila, I stand in front of the unit and want to know when the hot tub will be full


## lcd_status_when_empty
As Kamila, I stand in front of the unit and want to know when the hot tub will be fully drained


## lcd_water_level_predict
As Kamila, I stand in front of the unit and want to know the projected hot tub water level.

## lcd_water_level_current
As Kamila, I stand in front of the unit and want to know the current hot tub water level.  This will be measured using
the [pressure_sensor].


## lcd_pid_change
As John, I stand in front of the unit and want change the PID values 

## lcd_pid_change_auto
As John, I stand in front of the unit and want auto tune the PID values.

## wifi_fill
As Kamila, I want to fill the hot tub via web browser. 

#### How to implement

- Use the custom post request route with these three parameters.
  - __parameters__
    - __cmd__ "flow"
    - __hot__ how much in percentages do you want to open the *hot* valve.
    - __cold__ how much in percentages do you want to open the *cold* valve.

__example post request__ 
__path__: `http://192.168.1.79:6100/custom`

__request object__
```
{
    "cmd":"flow",
    "hot":27.67,
    "cold":100
}
```

- Use the custom post request route with these two parameters.
  - __parameters__
    - __cmd__ "fill"
    - __temperature__ how hot in celsius should the water be, flowing to the hot tub.

__example post request__ 
__path__: `http://192.168.1.79:6100/custom`

__request object__
```
{
    "cmd":"fill",
    "temperature":41.67
}
```

## wifi_stop
As Kamila, I want to stop flow, to and from the hot tub via web browser. 

#### How to implement

- Use the custom post request route with this parameter.
  - __parameters__
    - __cmd__ "stop"

__example post request__ 
__path__: `http://192.168.1.79:6100/custom`

__request object__
```
{
    "cmd":"stop"
}
```




## wifi_drain
As Kamila, I want to drain the hot tub via web browser. 

#### How to implement

- Use the custom post request route with this parameter.
  - __parameters__
    - __cmd__ "drain"

__example post request__ 
__path__: `http://192.168.1.79:6100/custom`

__request object__
```
{
    "cmd":"drain"
}
```

## lcd_status_dim_backlight
As John, I stand in front of the unit and want to change the backlight brightness of the LCD display.

This can be useful to lower the current draw of the display if needed, but this will also allow the device to go dim the
display when it has not been in use for some period of time.

In order for this to be possible a dimmer will need to be added and I would think that the [BC337] Transistor would be
a good candidate.

## lcd_system_scan
As John, I stand in front of the unit and want to make the unit learn how much valves need to open to get desired temperature.
This feature I call "System scan" and it will test and store the results in a file called `system.csv` on a sd card which 
can be later used to search for valve settings for a desired temperature. example file [system.csv](./system.csv)

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
[pressure_sensor]:./hardware.md#pressure_sensor