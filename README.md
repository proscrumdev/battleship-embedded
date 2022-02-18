# Battleship Embedded
A simple game of Battleship, written in C++ for embedded devices (ESP32).

<img src="https://user-images.githubusercontent.com/11467601/154758318-84eafd62-75f5-4113-8d49-7534f8db370a.jpg" width="400px">

## Tools
While the code might work with other development tools, it has been created and tested by using VSCode (https://code.visualstudio.com) with the PlatformIO extension (https://platformio.org). For just executing task on the CLI, PlatformIO Core is sufficient (https://docs.platformio.org/en/latest/core/installation.html)

## Using Docker 
If you do not want to install PlatformIO and other needed tools locally, you can use a docker container to run the commands.

```bash
docker run -it -v ${PWD}:/battleship -w /battleship infinitecoding/platformio-for-ci bash
```

## Build and upload firmware to device
To build the project, use

```bash
pio run
```

To upload the firmware to the device, use

```bash
pio run --target upload
```

## Run unit-tests
To allow running unit-tests on a development machine or in a build process, the code is part of a platform independent library. You can use the PlatformIO CLI to execute these tests. You might have to run a `pio run -e native` once to install the native platform first.

```bash
pio test -e native
```
This requires a locally installed g++ compiler. Alternatively you can execute the tests within a docker container (see above) that comes with all necessary tools.

## Deployment
You might find some helpful scripts in the _deploy folder.

To flash the firmware on the device, the esptool can be used. This is installed together with PlatformIO or can be installed separately by running

```bash
pip install esptool
```
