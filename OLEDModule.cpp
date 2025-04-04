// =============================
// OLEDModule.cpp
// =============================
#include "OLEDModule.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1107 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET, 1000000, 100000);

void initOLED() {
  display.begin(0x3D, true);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("OLED Ready");
  display.display();
  delay(1000);
}

void displaySensorData(float temp, float hum, float pres, float gas, float soundDB) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.printf("Temp: %.1f C\n", temp);
  display.printf("Humidity: %.1f %%\n", hum);
  display.printf("Pressure: %.1f hPa\n", pres);
  display.printf("Gas: %.1f KOhms\n", gas);
  display.printf("Sound: %.1f dBA\n", soundDB);
  display.display();
}

void drawHeartWaveform(int* data, int len) {
  if (len < 2) return;

  display.clearDisplay();
  for (int i = 0; i < len - 1; i++) {
    int x1 = map(i, 0, len - 1, 0, SCREEN_WIDTH - 1);
    int x2 = map(i + 1, 0, len - 1, 0, SCREEN_WIDTH - 1);
    int y1 = map(data[i], 50000, 120000, SCREEN_HEIGHT - 1, 0);
    int y2 = map(data[i + 1], 50000, 120000, SCREEN_HEIGHT - 1, 0);
    display.drawLine(x1, y1, x2, y2, SH110X_WHITE);
  }
  display.display();
}
