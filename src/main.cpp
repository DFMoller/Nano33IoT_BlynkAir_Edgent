/*
 * Required libraries:
 *  - WiFiNINA
 *  - ArduinoOTA
 *  - ArduinoHttpClient
 *  - Timer5
 *  
 * Please also update the WiFi module firmware, if needed
 */

// Fill-in information from your Blynk Template here
// #define BLYNK_TEMPLATE_ID ""
// #define BLYNK_DEVICE_NAME ""

#include <Arduino.h>

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#include "BlynkEdgent.h"

BlynkTimer timer;
uint32_t start_time = 0;

void BlynkTimerHandler()
{
  Blynk.virtualWrite(V0, millis() / 1000);
}

void setup()
{
  start_time = millis();
  Serial.begin(115200);
  while(!Serial && (millis() - start_time) < 10000);
  BlynkEdgent.begin();
  timer.setInterval(1000L, BlynkTimerHandler);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
  Blynk.run();
}
