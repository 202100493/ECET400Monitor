// =============================
// WiFiModule.cpp
// =============================
#include "WiFiModule.h"
#include <WiFi.h>

// Replace with your actual network credentials
const char* ssid = "HAVEX";
const char* password = "QAZ123";

void initWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("[WiFiModule] Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n[WiFiModule] WiFi connected");
  Serial.print("[WiFiModule] IP address: ");
  Serial.println(WiFi.localIP());
}
