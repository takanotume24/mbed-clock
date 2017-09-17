#ifndef PIN_H
#define PIN_H

#include "mbed.h"

#define ON 1
#define OFF 0
extern DigitalIn pushButton1;
extern DigitalIn pushButton2;
extern DigitalIn pushButton3;
extern DigitalIn pushButton4;
extern DigitalIn pushButton5;
extern DigitalIn pushButton6;

extern PwmOut buzzerPin;

extern Serial pc;
extern I2C i2c;
extern int nowSec, nowMin, nowHour, nowDay, nowMon, nowYear;

#endif
