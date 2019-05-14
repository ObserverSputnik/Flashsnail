#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "libmaple/i2c.h"
#include "Arduino.h"
#include <Wire_slave.h>
#include "libmaple/usart.h"
#include "motor.h"
#include "util.h"
#define END_OF_SIG 'y'


uint8_t GetFlags();
void cmdHandler();
void LinuxUARTInit();
void CheckUSART();
#endif
