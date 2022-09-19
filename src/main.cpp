/*
 * Modification of MRK1010 Blynk Edgent example to be
 * compatible with the Arduino Nano 33 IoT, specifically
 * to be used with PlatformIO. NOT for Arduino IDE!
 * 
 * Modifications by:
 *  - Daniel Moller
 *  - 19 September 2022
 *  - https://github.com/DFMoller/Nano33IoT_BlynkAir_Edgent
 * 
 * Required libraries:
 *  - WiFiNINA
 *  - ArduinoOTA
 *  - ArduinoHttpClient
 *  - Timer5
 *  - Blynk
 * 
 * Additional Notes:
 *  - Ensure WIFI module has latest firmware
 * 
 */

// Fill-in information from your Blynk Template here
// #define BLYNK_TEMPLATE_ID ""
// #define BLYNK_DEVICE_NAME ""

#include <Arduino.h>

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#define USE_NANO_33_IOT // Refer to settings.h to see how this is implemented

#include "BlynkEdgent.h"

BlynkTimer timer;
uint32_t start_time = 0;

void BlynkTimerHandler()
{
  // An example of writing device uptime (in seconds) to virtual pin V0
  Blynk.virtualWrite(V0, millis() / 1000);
}

void setup()
{
  start_time = millis();
  Serial.begin(115200);
  while(!Serial && (millis() - start_time) < 10000); // Wait for Serial no longer than 10s
  BlynkEdgent.begin();
  while(WiFi.status() != WL_CONNECTED || !Blynk.connected()) // Wait for connection
  {
    BlynkEdgent.run();
  }
  timer.setInterval(1000L, BlynkTimerHandler); // 1000ms interval
  // YOUR SETUP CODE REQUIRING A CONNECTION HERE

  // SETUP CODE END
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
