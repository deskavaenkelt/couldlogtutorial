<article>
    <h1>Cayenne tutorial on LOLIN32</h1>
    <p>I used LOLIN32 for this project, if you use some other devices just change or add the board to platformio.ini.</p>
    <p>Links</p>
    <ul>
        <li><a href="https://developers.mydevices.com/cayenne/docs/cayenne-mqtt-api/">Cayenne MQTT API</a></li>
        <li><a href="https://community.mydevices.com/t/data-types-for-cayenne-mqtt-api/3714">Data types</a> for Cayenne MQTT API</li>
        <li><a href="https://wiki.wemos.cc/products:lolin32:lolin32">LOLIN32</a> at WEMOS</li>
        <li><a href="https://docs.platformio.org/en/latest/boards/espressif32/lolin32.html">LOLIN32</a> at PlatformIO</li>
    </ul>
</article>
<article>
    <h2>Prerequisites</h2>
    <p>Libraries in PlatformIO</p>
    <ul>
        <li><a href="https://platformio.org/lib/show/31/Adafruit%20Unified%20Sensor?utm_source=platformio&utm_medium=piohome">Adafruit Unified Sensor</a> by Adafruit</li>
        <li><a href="https://platformio.org/lib/show/19/DHT%20sensor%20library?utm_source=platformio&utm_medium=piohome">DHT sensor library</a> by Adafruit</li>
    </ul>
    <img src="layout.png" alt="schematics of breadboard">
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