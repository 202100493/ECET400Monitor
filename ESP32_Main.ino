// ===== esp32_sensor_hub.ino (Main File) =====
#include "WiFiModule.h"
#include "OLEDModule.h"
#include "BME688Module.h"
#include "SoundSensorModule.h"
#include "HeartRateReceiverModule.h"

void setup() {
  Serial.begin(115200);

  initWiFi();         // Connect to WiFi
  initOLED();         // Initialize OLED display
  initBME688();       // Initialize BME688 sensor
  initSoundSensor();  // Initialize sound sensor module
  initHeartRate();    // Initialize heart rate receiver module (TCP Server)
}

void loop() {
  // Read data from each sensor module
  float temperature, humidity, pressure, gas;
  readBME688(temperature, humidity, pressure, gas);

  float soundDB = readSoundLevel();

  int heartData[10];
  int heartLen = receiveHeartRateJSON(heartData, 10); // Receive up to 10 heart rate samples

  // Display data on OLED
  displaySensorData(temperature, humidity, pressure, gas, soundDB);
  if (heartLen > 0) {
    drawHeartWaveform(heartData, heartLen);
  }

  delay(2000);
}