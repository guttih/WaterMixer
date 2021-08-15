# Development

This document contains information about the development decisions of this project.

## System Requirements
What is needed to make this product possible.  What environment? What hardware? The plumbing?
Read about the [System requirements] for more details.

## Product Requirements
What are the [Product requirements] for this project?
What use cases will the project solve?  Who will be using it?
Which [features] will be selected into which [Releases]?

## Upload program

### Via serial
To upload this program firmware using usb you will need to change the file `platformio.ini`.  In that file change the `upload-port` to something like **COM4**, that is if you computer gave the esp32 usb connection the name COM4.  Next, comment out the `upload_protocol` because it does not need to be specified when uploading via serial.  This can be done by adding `;` in front of the line `upload_protocol = espota`.

Example
```
;upload_protocol = espota
upload_port = 192.168.1.231
```

### Via wifi
To upload this program firmware over the air (OTA), you will need to change the file `platformio.ini`. In that file, change the `upload-port` to the **Ip** address of the device.  And change the `upload_protocol` **espota** 

Example
```
upload_protocol = espota
upload_port = 192.168.1.187
```

## Wire frame
The [wireframe] for the project is created in figma, I do not have a professional account so I cannot share it here.

## Tests
See [tests] for information tests for this project.


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
[wireframe]: https://www.figma.com/file/y1b4Cv2xqcNgusC35FyHj3/Water-mixer


[features]: ./productRequirements.md#features
[tests]: ../../test/README.md