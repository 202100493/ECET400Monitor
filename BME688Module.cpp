// =============================
// BME688Module.cpp
// =============================
#include "BME688Module.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme;

void initBME688() {
  if (!bme.begin()) {
    Serial.println("[BME688Module] Sensor not found. Check wiring!");
    while (1);
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void readBME688(float& temperature, float& humidity, float& pressure, float& gasResistance) {
  if (!bme.performReading()) {
    Serial.println("[BME688Module] Reading failed");
    temperature = humidity = pressure = gasResistance = 0.0f;
    return;
  }

  temperature = bme.temperature;
  humidity = bme.humidity;
  pressure = bme.pressure / 100.0;
  gasResistance = bme.gas_resistance / 1000.0;
}
