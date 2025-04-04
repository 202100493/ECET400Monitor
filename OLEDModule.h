// =============================
// OLEDModule.h
// =============================
#ifndef OLED_MODULE_H
#define OLED_MODULE_H

// Initializes the OLED display
void initOLED();

// Displays environmental and sound sensor data
void displaySensorData(float temp, float hum, float pres, float gas, float soundDB);

// Draws a waveform of heart rate IR values
void drawHeartWaveform(int* data, int len);

#endif // OLED_MODULE_H