// =============================
// HeartRateReceiverModule.h
// =============================
#ifndef HEART_RATE_RECEIVER_MODULE_H
#define HEART_RATE_RECEIVER_MODULE_H

// Initializes the TCP server for receiving heart rate data
void initHeartRate();

// Receives JSON-formatted heart rate data over TCP
// Returns the number of data points stored in the buffer
int receiveHeartRateJSON(int* buffer, int maxLength);

#endif // HEART_RATE_RECEIVER_MODULE_Hv