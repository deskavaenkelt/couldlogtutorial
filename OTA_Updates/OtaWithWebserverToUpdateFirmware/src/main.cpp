////////////////////////////////////////////
// OTA with webserver to update firmware  //
////////////////////////////////////////////

// Include the libraries we need
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

#include "auth.h"
#include "webserverCode.h"


//////////////////
//  Web Server  //
//////////////////
WebServer server(80);

/////////////////
//  Device ID  //
/////////////////
// The purpouse is to be able to use the same firmware for identically configured board+sensor setup
// Since GPIO: 36, 39, 34, 35 is "INPUT ONLY" 
// witch of Loloin32 only have 34 & 35 so we will use these for ID'ing our boards
// +----------------------+
// | Device | ID0  | ID1  |
// +----------------------+
// |    0   | LOW  | LOW  |
// |    1   | HIGH | LOW  |
// |    2   | LOW  | HIGH |
// |    3   | HIGH | HIGH |
// +----------------------+
const int ID0 = 34;
const int ID1 = 35;

char* getMyHostname(){
	int id = (digitalRead(ID0) * 1) + (digitalRead(ID1) * 2);
	Serial.print("ID = ");
	Serial.println(id);
    switch (id)
    {
    case 0:
        return HOSTNAME_DEVICE_0;
        break;
    case 1:
        return HOSTNAME_DEVICE_1;
        break;
    case 2:
        return HOSTNAME_DEVICE_2;
        break;
    case 3:
        return HOSTNAME_DEVICE_3;
        break;

    default:
		return HOSTNAME_DEFAULT;
        break;
    }
}


/////////////////
//    Setup    //
/////////////////
void setup()
{
	Serial.begin(115200);

	pinMode(ID0, INPUT);
	pinMode(ID1, INPUT);

	Serial.println("Booting");
	WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	while (WiFi.waitForConnectResult() != WL_CONNECTED)
	{
		Serial.println("Connection Failed! Rebooting...");
		delay(2000);
		ESP.restart();
	}
	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(WIFI_SSID);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	/*Using mDNS Protocol for mapping hostname to IP Address*/
	MDNS.begin(getMyHostname());
	Serial.println("mDNS responder started");
	Serial.print("Access the webserver at http://");
	Serial.print(getMyHostname());
	Serial.print(".local/");

	/*Returns Login page which is stored in the string loginIndex */
	server.on("/", HTTP_GET, []() {
		server.sendHeader("Connection", "close");
		server.send(200, "text/html", loginIndex);
	});

	/*Returns Index page which is stored in the string serverIndex */
	server.on("/serverIndex", HTTP_GET, []() {
		server.sendHeader("Connection", "close");
		server.send(200, "text/html", serverIndex);
	});

	/*handling uploading firmware file */
	server.on("/update", HTTP_POST, []() {
          server.sendHeader("Connection", "close");
          server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
          ESP.restart(); }, []() {
          HTTPUpload& upload = server.upload();
          
          if (upload.status == UPLOAD_FILE_START) 
            {
              Serial.printf("Update: %s\n", upload.filename.c_str());
              if (!Update.begin(UPDATE_SIZE_UNKNOWN)) 
                { 
                 Update.printError(Serial);
                }
            } 
          else if (upload.status == UPLOAD_FILE_WRITE) 
            {
              
         /* flashing firmware to ESP*/
              if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) 
                {
                 Update.printError(Serial);
                 }
             } 
          else if (upload.status == UPLOAD_FILE_END) {
               if (Update.end(true)) 
                  { 
                  Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
                   } 
          else 
            {
              Update.printError(Serial);
            }
            
          } });

	server.begin();
}

////////////////
//    Loop    //
////////////////
void loop()
{
	server.handleClient();	// Handle all the ota updates
	delay(1);
}