# Cayenne tutorials
More information is provided in the separate projects

## Common prerequisites for all projects
Libraries in PlatformIO
* [Cayenne-MQTT-ESP32](https://platformio.org/lib/show/1451/Cayenne-MQTT-ESP)
* or type `pio lib install "Cayenne-MQTT-ESP"` in terminal

Detailed tutorial for DHT sensors
* [Detailed tutorial for DHT sensors][tutorialDth11]

## Cayenne setup
You need to have an account over at the [Cayenne website][Cayenne website], if you don't have an account create one by clicking "SIGN UP". You need to create a new device for every new ESP/Arduino/Raspberry Pi that you add.

For convenience I have added the datatype's in a txt-file with the same name

Since Cayenne don't support ESP32 out of the box we add everything manually

### Add new device
* In the Menu to the left <code>Add new...</code>
* Click on <code>Device/Widget</code>
* Click <code>Bring Your Own Thing</code>
* Here you will se the necessary credentials you need and you can give your device a name
* There is an auth.h file in the src-folder that you need to copy this information to
* When your device connects you will automatically be sent back to the dashboard


## Dashboard
Your sensor data should show up per default, just add them with the + icon in the top right corner.

The datatype's is specified in the project files for the ESP32 and therefore is working out of the box.

If you click the settings wheel in top right corner of a widget you can change its settings here.

### Add new Widget manually
Since Cayenne don't support ESP32 out of the box we add everything manually

I'll assume that you use the code in CayenneWithDth11 witch have four sensors (DTH11 Temp/Hum and Temperature/Hall-sensor data from the ESP32 itself)
1. In the Menu to the left <code>Add new...</code>
2. Click on <code>Device/Widget</code>
3. Click <code>Custom Widgets</code>
4. You can click on "Example" for every widget

#### Add temperature reading
* Click <code>Value</code>
* Give it a name, for Example "Temperature"
* Choose witch devise its connected to
* Under Sensor:
* Data: Temperature
* Unit: Celsius
* Channel: 0
* Icon: Temperature/Temp Probe
* <code>Add widget</code>

#### Add Line Chart temperature reading
* Click <code>Line Chart</code>
* Give it a name, for Example "Temperature Graph"
* Choose witch devise its connected to
* Under Sensor:
* Data: Temperature
* Unit: Celsius
* Channel: 0
* Min and Max Scale values are optional
* <code>Add widget</code>

The procedure for adding sensors and charts are the same, the only difference is the datatype's and channels.

#### Note: I'm not sure about the correct unit for the hall sensor but I used tesla just to have a unit related to magnetism.

[tutorialDth11]: https://lastminuteengineers.com/esp32-dht11-dht22-web-server-tutorial/
[Cayenne website]: https://accounts.mydevices.com/auth/realms/cayenne/protocol/openid-connect/auth?response_type=code&scope=email+profile&client_id=cayenne-web-app&state=vH0lUaJskkgJ4xnpu8cJnc89snnUcx56VUk9clC3&redirect_uri=https%3A%2F%2Fcayenne.mydevices.com%2Fauth%2Fcallback