<article>
    <h1>Cayenne tutorial on ESP32-Dev-Kit C</h1>
    <p>I used LOLIN32 for this project, if you use some other devices just change or add the board to platformio.ini.</p>
    <p>Links</p>
    <ul>
        <li><a href="https://developers.mydevices.com/cayenne/docs/cayenne-mqtt-api/">Cayenne MQTT API</a></li>
        <li><a href="https://community.mydevices.com/t/data-types-for-cayenne-mqtt-api/3714">Data types</a> for Cayenne MQTT API</li>
        <li><a href="https://docs.platformio.org/en/latest/boards/espressif32/fm-devkit.html">ESP32 DevKit C</a> at PlatformIO</li>
    </ul>
</article>
<article>
    <h2>Prerequisites</h2>
    <p>Libraries in PlatformIO</p>
    <ul>
        <li><a href="https://platformio.org/lib/show/1/OneWire?utm_source=platformio&utm_medium=piohome">OneWire</a> Control 1-Wire protocol (DS18S20, DS18B20, DS2408 and etc)</li>
        <li><a href="https://platformio.org/lib/show/54/DallasTemperature?utm_source=platformio&utm_medium=piohome">DallasTemperature</a> Arduino Library for Dallas Temperature ICs (DS18B20, DS18S20, DS1822, DS1820)</li>
    </ul>
    <p>Components</p>
    <ul>
        <li>ESP32 board</li>
        <li>Breadboard</li>
        <li>Cables</li>
        <li>3x DS18B20 Sensors (I used the waterproof model)</li>
        <li>1x resistor for pull-up</li>
        <li>4x LEDs (I used one of each: , blue, red, yellow, green)</li>
        <li>4x resistors for the LEDs</li>
    </ul>
    <img src="layout.png" alt="schematics of breadboard">
    <h4>Note, The schematics may not be 100% accurate, verify with data sheet for you'r components</h4>
</article>
<article>
    <h2>How to use</h2>
    <p>Start by adding the libraries to PlatformIO in VSCode, then restart VSCode.</p>
    <p>The code is configured to send data every 5sek.</p>
    <p>Download the code and unzip, open the folder in VSCode. Test to build the code to confirm that the libraries are imported correctly.</p>
    <ul>
        <li>Connect your board to your computer</li>
        <li>In the left tab in VSCode click on The PlatformIO icon.</li>
        <li>Click Devices and copy the address that corresponds to your board (Windows "ComX", Mac "/dev/cu.xxx"</li>
        <li>Replace the port address on row 18 in platformio.ini</li>
        <li>Then click "Upload and Monitor"</li>
    </ul>
    <p>The ESP32 should connect to the Cayenne service if your network credentials are valid.</p>
    <p>If there is any errors, check the console for error messages to solve them.</p>
</article>