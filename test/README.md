# Tests

These are the standard tests provided by PlatformIO.  These tests run on the
device. More information about [PlatformIO Unit Testing].

__Running the tests__

Assuming the esp32 is connected to the usb on port COM4
```
pio test -e esp32dev --test-port COM6
```

Showing serial print monitor
```
pio test -e esp32dev -v --test-port COM6
```


[PlatformIO Unit Testing]:https://docs.platformio.org/page/plus/unit-testing.html