// =============================
// SoundSensorModule.cpp
// =============================
#include "SoundSensorModule.h"
#include <Arduino.h>

#define SOUND_SENSOR_PIN 35//need change
#define VREF 3.3

void initSoundSensor() {
  pinMode(SOUND_SENSOR_PIN, INPUT);
}

float readSoundLevel() {
  float voltageValue = analogRead(SOUND_SENSOR_PIN) / 1024.0 * VREF;
  float dbValue = voltageValue * 50.0; // Convert voltage to decibel (dBA)
  return dbValue;
}
