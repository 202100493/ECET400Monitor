// =============================
// SoundSensorModule.h
// =============================
#ifndef SOUND_SENSOR_MODULE_H
#define SOUND_SENSOR_MODULE_H

// Initializes the sound sensor (sets pin mode)
void initSoundSensor();

// Reads and returns the current sound level in dBA
float readSoundLevel();

#endif // SOUND_SENSOR_MODULE_H