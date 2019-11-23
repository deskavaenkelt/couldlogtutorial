# Cayenne tutorial on ESP32-Dev-Kit C
I used LOLIN32 for this project, if you use some other devices just change or add the board to platformio.ini.

Links
* [Cayenne MQTT API][Cayenne MQTT API]
* [Data types][Data types] for Cayenne MQTT API
* [ESP32 DevKit C][ESP32 DevKit C] at PlatformIO

## Prerequisites
Libraries in PlatformIO
* [OneWire][OneWire] Control 1-Wire protocol (DS18S20, DS18B20, DS2408 and etc)
* [DallasTemperature][DallasTemperature] Arduino Library for Dallas Temperature ICs (DS18B20, DS18S20, DS1822, DS1820)

Components
* ESP32 board
* Breadboard
* Cables
* 3x DS18B20 Sensors (I used the waterproof model)
* 1x resistor for pull-up
* 4x LEDs (I used one of each: , blue, red, yellow, green)
* 4x resistors for the LEDs

Schematics of breadboard
![layout.png](layout.png)

#### Note
The schematics may not be 100% accurate, verify with data sheet for you'r components.

## How to use
Start by adding the libraries to PlatformIO in VSCode, then restart VSCode.

The code is configured to send data every 5sek.

Download the code and unzip, open the folder in VSCode. Test to build the code to confirm that the libraries are imported correctly.
* Connect your board to your computer
* In the left tab in VSCode click on The PlatformIO icon.
* Click Devices and copy the address that corresponds to your board (Windows `COMX`, Mac `/dev/cu.xxx`
* Replace the port address on row 18 in platformio.ini
* Then click "Upload and Monitor"

The ESP32 should connect to the Cayenne service if your network credentials are valid.

If there is any errors, check the console for error messages to solve them.

[Cayenne MQTT API]: https://developers.mydevices.com/cayenne/docs/cayenne-mqtt-api/
[Data types]: https://community.mydevices.com/t/data-types-for-cayenne-mqtt-api/3714
[ESP32 DevKit C]: https://docs.platformio.org/en/latest/boards/espressif32/fm-devkit.html
[OneWire]: https://platformio.org/lib/show/1/OneWire?utm_source=platformio&utm_medium=piohome
[DallasTemperature]: https://platformio.org/lib/show/54/DallasTemperature?utm_source=platformio&utm_medium=piohome