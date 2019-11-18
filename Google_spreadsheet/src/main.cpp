#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Bahu";    // name of your wifi network!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const char* password = "anders070";     // wifi pasword !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const char* host = "script.google.com";
const int httpsPort = 443; 

// Use WiFiClientSecure class to create TLS connection
WiFiClientSecure client;

// SHA1 fingerprint of the certificate, don't care with your GAS service
//String GAS_ID = "https://script.google.com/macros/s/AKfycbwxuD616oBDeSikjhUh21xmh_kYAXIN0Prkcd1w0CDTHIJxIDdl/exec"; 

const char* fingerprint = "19 eb 43 ea a0 8d b7 ad 52 36 58 8d 15 9c e2 6d 49 9c ac 28"; // obtained from certificate

String GAS_ID = "AKfycbwxuD616oBDeSikjhUh21xmh_kYAXIN0Prkcd1w0CDTHIJxIDdl"; 	// Replace by your GAS service id           !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//------***** (Tempertaure/ Humidity Sensor)-------------------------
#include <DHT_U.h>
#include <DHT.h>
 
//#define DHTpin 15    //D15 of ESP32 DevKit
#define DHTTYPE DHT11   // DHT 11
// DHT Sensor
uint8_t DHTPin = 15; 
               
// combining of DHT sensor.
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;

//---------- rounding float to two decimal ------------------------------
float round(float var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

//****************----------------***********************


//******************---- Function for Sending data into Google Spreadsheet -----------****************
void sendData(float Temperaturestat, float Humiditystat)
{
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  if (client.verify(fingerprint, host)) {
  Serial.println("certificate matches");
  } else {
  Serial.println("certificate doesn't match");
  }
  String string_temperature =  String(Temperaturestat); 
  String string_humidity =  String(Humiditystat); 
  String url = "/macros/s/" + GAS_ID + "/exec?temperature=" + string_temperature + "&humidity=" + string_humidity;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
  Serial.println("esp8266/Arduino CI successfull!");
  } else {
  Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
} 

//************* This method will intialize and send data to google sheets ****************
void handle_OnConnect() {
  pinMode(DHTPin, INPUT);
  dht.begin();  

  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity(); // Gets the values of the humidity 
  sendData(Temperature,Humidity); 
}


void setup() 
{
  Serial.begin(115200); //Serial port intializer
  delay(100);
  Serial.println();

  //connecting to internet
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 

}

void loop() 
{
  handle_OnConnect();
  //----------to show the teperatuere/humidity data on serial monitor------------------
  Serial.print("Temperature = ");
  Serial.print(Temperature);
  Serial.print(" Humidity= ");
  Serial.println(Humidity);
 
 delay(2000);
}
