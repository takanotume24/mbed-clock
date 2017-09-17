#ifndef ALARM_H
#define ALARM_H

#include "mbed.h"
#include "lcd.h"
#include "pin.h"
#include "clock.h"

int checkNowIsAlarm();
int alarmSync();
int alarmInit();
int alarmSetup();
int alarmSet();
int alarmTimeUpdate();
int alarmBuzzer();
int alarmYearSetup();
int alarmMonSetup();
int alarmDaySetup();
int alarmHourSetup();
int alarmMinSetup();
int alarmSecSetup();
char *getTimeAlarmChar(const char *);


extern int alarmYear;
extern int alarmMon;
extern int alarmDay;
extern int alarmHour;
extern int alarmMin;
extern int alarmSec;
extern char alarmBuffuer[32];

#endif