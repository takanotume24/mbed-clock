
#ifndef CLOCK_H
#define CLOCK_H

#include "pin.h"
#include "buzzer.h"
int checkButton();
int timeInit();
int waitPushButton();
void showTime();
int modeChange();

int timeSetup();
int yearSetup();
int monthSetup();
int daySetup();
int hourSetup();
int minSetup();
int secSetup();

int loop();

int backToHomeScreen();
char *getTimeChar(const char *);

#endif