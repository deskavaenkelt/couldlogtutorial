<article>
    <h1>Cayenne tutorials</h1>
    <p>More information is provided in the separate projects</p>
</article>
<article>
    <h2>Common prerequisites for all projects</h2>
    <p>Libraries in PlatformIO</p>
    <ul>
        <li><a href="https://platformio.org/lib/show/1451/Cayenne-MQTT-ESP">Cayenne-MQTT-ESP32</a></li>
    </ul>
    <p>Detailed tutorial for DHT sensors</p>
    <ul>
        <li><a href="https://lastminuteengineers.com/esp32-dht11-dht22-web-server-tutorial/">lastminuteengineers.com</a></li>
    </ul>
        
</article>
<article>
    <h2>Cayenne setup</h2>
    <p>You need to have an account over at the <a href="https://accounts.mydevices.com/auth/realms/cayenne/protocol/openid-connect/auth?response_type=code&scope=email+profile&client_id=cayenne-web-app&state=vH0lUaJskkgJ4xnpu8cJnc89snnUcx56VUk9clC3&redirect_uri=https%3A%2F%2Fcayenne.mydevices.com%2Fauth%2Fcallback">Cayenne</a> website, if you don't have an account create one by clicking "SIGN UP". You need to create a new device for every new ESP/Arduino/Raspberry Pi that you add.</p>
    <p>For convenience I have added the datatype's in a txt-file with the same name.</p>
    <p>Since Cayenne don't support ESP32 out of the box we add everything manually</p>
</article>
<article>
    <h3>Add new device</h3>
    <ul>
        <li>In the Menu to the left <code>Add new...</code></li>
        <li>Click on <code>Device/Widget</code></li>
        <li>Click <code>Bring Your Own Thing</code></li>
        <li>Here you will se the necessary credentials you need and you can give your device a name</li>
        <li>There is an auth.h file in the src-folder that you need to copy this information to</li>
        <li>When your device connects you will automatically be sent back to the dashboard</li>
    </ul>
</article>
<article>
    <h2>Dashboard</h2>
    <p>Your sensor data should show up per default, just add them with the + icon in the top right corner.</p>
    <p>The datatype's is specified in the project files for the ESP32 and therefore is working out of the box.</p>
    <p>If you click the settings wheel in top right corner of a widget you can change its settings here.</p>
</article>
<article>
    <h3>Add new Widget manually</h3>
    <p>Since Cayenne don't support ESP32 out of the box we add everything manually</p>
    <p>I'll assume that you use the code in CayenneWithDth11 witch have four sensors (DTH11 Temp/Hum and Temperature/Hall-sensor data from the ESP32 itself)</p>
    <ol>
        <li>In the Menu to the left <code>Add new...</code></li>
        <li>Click on <code>Device/Widget</code></li>
        <li>Click <code>Custom Widgets</code></li>
        <li>You can click on "Example" for every widget</li>
    </ol>
    <h4>Add temperature reading</h4>
    <ul>
        <li>Click <code>Value</code></li>
        <li>Give it a name, for Example "Temperature"</li>
        <li>Choose witch devise its connected to</li>
        <li>Under Sensor:</li>
        <li>Data: Temperature</li>
        <li>Unit: Celsius</li>
        <li>Channel: 0</li>
        <li>Icon: Temperature/Temp Probe</li>
        <li><code>Add widget</code></li>
    </ul>
    <h4>Add Line Chart temperature reading</h4>
        <ul>
            <li>Click <code>Line Chart</code></li>
            <li>Give it a name, for Example "Temperature Graph"</li>
            <li>Choose witch devise its connected to</li>
            <li>Under Sensor:</li>
            <li>Data: Temperature</li>
            <li>Unit: Celsius</li>
            <li>Channel: 0</li>
            <li>Min and Max Scale values are optional</li>
            <li><code>Add widget</code></li>
        </ul>
    <p>The procedure for adding sensors and charts are the same, the only difference is the datatype's and channels.</p>
    <h4>Note: I'm not sure about the correct unit for the hall sensor but I used tesla just to have a unit related to magnetism.</h4>
</article>
