// Include the libraries we need
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
#include "auth.h"

/////////////////
//    DHT11    //
/////////////////
#define DHTTYPE DHT11
uint8_t DHTPin = 4;
DHT dht(DHTPin, DHTTYPE);

float temperature = 0;
float humidity = 0;
void readDataFromDth11()
{
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
}

// LED Pin
const int LED_PIN = 5;

////////////////
//    WiFi    //
////////////////
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi()
{
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *message, unsigned int length)
{
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.print(". Message: ");
    String messageTemp;

    for (int i = 0; i < length; i++)
    {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
    }
    Serial.println();

    // Feel free to add more if statements to control more GPIOs with MQTT

    // If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
    // Changes the output state according to the message
    if (String(topic) == "esp32/output")
    {
        Serial.print("Changing output to ");
        if (messageTemp == "on")
        {
            Serial.println("on");
            digitalWrite(LED_PIN, HIGH);
        }
        else if (messageTemp == "off")
        {
            Serial.println("off");
            digitalWrite(LED_PIN, LOW);
        }
    }
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP8266Client"))
        {
            Serial.println("connected");
            // Subscribe
            client.subscribe("esp32/output");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

/////////////////
//    Setup    //
/////////////////
void setup()
{
    Serial.begin(115200);

    // DHT Sensor
    pinMode(DHTPin, INPUT);
    dht.begin();

    // LED_PIN
    pinMode(LED_PIN, OUTPUT);

    // Connect to WiFi
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

////////////////
//    Loop    //
////////////////
void loop()
{
    readDataFromDth11();
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();

    long now = millis();
    if (now - lastMsg > 5000)
    {
        lastMsg = now;

        // Convert the value to a char array
        char tempString[8];
        dtostrf(temperature, 1, 2, tempString);
        Serial.print("Temperature: ");
        Serial.println(tempString);
        client.publish("esp32/temperature", tempString);

        // Convert the value to a char array
        char humString[8];
        dtostrf(humidity, 1, 2, humString);
        Serial.print("Humidity: ");
        Serial.println(humString);
        client.publish("esp32/humidity", humString);
    }
}