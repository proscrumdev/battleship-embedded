## This is a beta version which means this code has not been verified in a class scenario. So if you are the first person using this in class, you should spend some more time testing it upfront and we would be very happy to hear any issues or successes with it. 



# Battleship Embedded
A simple game of Battleship, written in C++ for embedded devices (ESP32).

The battleship case study for embedded development for the Professional Scrum Developer (PSD) training from scrum.org (www-scrum.org/psd)

While the code might work with other development tools, it has been created and tested by using VSCode (https://code.visualstudio.com) with the PlatformIO extension (https://platformio.org).

## Build and upload firmware to device
To build and upload the firmware, use the tasks provided by PlatformIO within VSCode.

## Run unit-tests
To allow running unit-tests on a development machine or in a build process, the code is part of a platform independent library. You can use the PlatformIO CLI to execute these tests 

```bash
pio test -e native
```
This requires a locally installed g++ compiler. Alternatively you can execute the tests within a docker container that comes with all necessary tools.

```bash
docker run -it -v ${PWD}:/battleship -w /battleship infinitecoding/platformio-for-ci bash
```
