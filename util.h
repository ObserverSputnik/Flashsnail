#ifndef UTIL_H_
#define UTIL_H_

#include "Arduino.h"
#include "libmaple/gpio.h"
#include "protocols.h"
#define CYCLE_MS 72
#define BIT_16 0xffff
#define TX_LED PA11
#define RX_LED PA12
#define batteryPin PA2

void tickInit(HardwareTimer timer);
void pinInit();
void tickHandler();
int getTime();
void flashLED(uint8_t LED, uint8_t state);
int readBattery();
#endif
