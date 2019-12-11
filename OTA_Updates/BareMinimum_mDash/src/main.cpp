//////////////////////////////////////////////////////
// OTA Bare minimum to connect device to mDash.net	//
//////////////////////////////////////////////////////

// Include the libraries we need
#include <Arduino.h>

#define MDASH_APP_NAME "MinimalApp"
#include <mDash.h>
// #include "auth.h"
#include "auth1.h"

#include <WiFi.h>

/////////////////
//    Setup    //
/////////////////
void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  mDashBegin(DEVICE_TOKEN);
}


////////////////
//    Loop    //
////////////////
void loop() {
  delay(100);
}