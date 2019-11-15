#include <Arduino.h>
#include <CayenneMQTTESP32.h>
#include <OneWire.h>

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

// WiFi network info.
char ssid[] = "Bahu";
char wifiPassword[] = "anders070";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "7960fec0-0633-11ea-a4a3-7d841ff78abf";
char password[] = "167890b2262ec5c2fa0aaf340e58bd6c041b0b73";
char clientID[] = "b3f37c50-063a-11ea-8221-599f77add412";

unsigned long lastMillis = 0;


////////////////
//    LEDs    //
////////////////
const int BLUE_LED = 25;
const int RED_LED = 26;
const int YELLOW_LED = 27;
const int GREEN_LED = 14;

String BLUE_BUTTON_STATE;
String RED_BUTTON_STATE;
String YELLOW_BUTTON_STATE;
String GREEN_BUTTON_STATE;

//------***** (Tempertaure/ Humidity Sensor)-------------------------
#include <DHTesp.h>
 
#define DHTpin 15    //D15 of ESP32 DevKit
 
DHTesp dht;

float humidity ;
float temperature;

void DHTTemperature() {
delay(dht.getMinimumSamplingPeriod());
 
   humidity = dht.getHumidity();
   temperature = dht.getTemperature();
}

//////////////////////
// Built-in sensors	//
//////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
	uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

float espTemperature = 0;
int espHallSensorValue = 0;
void readDataFromEsp()
{
	espTemperature = (temprature_sens_read() - 32) / 1.8;
	espHallSensorValue = hallRead();
}
//------*****--------------------------------------------------------


void setup() {

  Serial.begin(9600);

  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17

	Cayenne.begin(username, password, clientID, ssid, wifiPassword);

}

void loop() {
  DHTTemperature();
  Cayenne.loop();

  if (millis() - lastMillis > 5000)
	{
		lastMillis = millis();
    float temperature_F = (temperature + 32) * 1.8;

		Cayenne.virtualWrite(0, temperature, TYPE_TEMPERATURE, UNIT_CELSIUS);
    Cayenne.virtualWrite(1, temperature_F, TYPE_TEMPERATURE, UNIT_FAHRENHEIT);
		Cayenne.virtualWrite(2, humidity, "humidity", UNIT_PERCENT);
		Cayenne.virtualWrite(4, espTemperature, "esptemperature", UNIT_CELSIUS);
	}

}
// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
	// Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
	Cayenne.virtualWrite(0, millis());
	// Some examples of other functions you can use to send data.
	//Cayenne.celsiusWrite(1, 22.0);
	//Cayenne.luxWrite(2, 700);
	//Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
CAYENNE_IN(4)
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	BLUE_BUTTON_STATE = getValue.asString();
	if (BLUE_BUTTON_STATE == "1")
	{
		digitalWrite(BLUE_LED, HIGH);
	}
	else
	{
		digitalWrite(BLUE_LED, LOW);
	}
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
CAYENNE_IN(5)
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	RED_BUTTON_STATE = getValue.asString();
	if (RED_BUTTON_STATE == "1")
	{
		digitalWrite(RED_LED, HIGH);
	}
	else
	{
		digitalWrite(RED_LED, LOW);
	}
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
CAYENNE_IN(6)
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	YELLOW_BUTTON_STATE = getValue.asString();
	if (YELLOW_BUTTON_STATE == "1")
	{
		digitalWrite(YELLOW_LED, HIGH);
	}
	else
	{
		digitalWrite(YELLOW_LED, LOW);
	}
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
CAYENNE_IN(7)
{
	CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
	GREEN_BUTTON_STATE = getValue.asString();
	if (GREEN_BUTTON_STATE == "1")
	{
		digitalWrite(GREEN_LED, HIGH);
	}
	else
	{
		digitalWrite(GREEN_LED, LOW);
	}
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}