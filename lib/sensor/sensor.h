#ifndef THERMAL_H
#define THERMAL_H

#include "pin.h"
#include "lcd.h"
#include "mbed.h"
#include "LPS25H.h"

int printTemperature(void);
extern LPS25H tempSensor;

#endif