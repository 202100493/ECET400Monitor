// =============================
// HeartRateReceiverModule.cpp
// =============================
#include "HeartRateReceiverModule.h"
#include <WiFi.h>
#include <ArduinoJson.h>

WiFiServer heartServer(8080);  // TCP server on port 8080

void initHeartRate() {
  heartServer.begin();
  Serial.println("[HeartRateReceiver] TCP server started on port 8080");
}

int receiveHeartRateJSON(int* buffer, int maxLength) {
  WiFiClient client = heartServer.available();
  if (client && client.connected()) {
    StaticJsonDocument<256> doc;
    String jsonStr = client.readStringUntil('\n');

    DeserializationError error = deserializeJson(doc, jsonStr);
    if (error) {
      Serial.println("[HeartRateReceiver] JSON parse failed");
      client.stop();
      return 0;
    }

    JsonArray irArray = doc["ir"];
    int count = 0;
    for (JsonVariant value : irArray) {
      if (count < maxLength) {
        buffer[count++] = value.as<int>();
      } else {
        break;
      }
    }

    client.stop();
    return count;
  }
  return 0;
}
