// =============================
// BME688Module.h
// =============================
#ifndef BME688_MODULE_H
#define BME688_MODULE_H

// Initializes the BME688 environmental sensor
void initBME688();

// Reads temperature, humidity, pressure, and gas resistance values
void readBME688(float& temperature, float& humidity, float& pressure, float& gasResistance);

#endif // BME688_MODULE_H

