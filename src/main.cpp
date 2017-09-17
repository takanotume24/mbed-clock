#include "mbed.h"
#include "clock.h"
#include "pin.h"
#include "lcd.h"
#include "buzzer.h"
#include "alarm.h"
#include "sensor.h"


PwmOut buzzerPin(D11);
Ticker showTime_ticker;
Ticker showTimeToLCD_ticker;

I2C i2c(I2C_SDA, I2C_SCL);
Serial pc(USBTX, USBRX);
const int AQM1602XA_addr = 0x7C;
unsigned char contrast = 32; // 0-63

DigitalIn pushButton1(D2);
DigitalIn pushButton2(D3);
DigitalIn pushButton3(D4);
DigitalIn pushButton4(D5);
DigitalIn pushButton5(D6);
DigitalIn pushButton6(D7);

DigitalOut led1(D8);
DigitalOut led2(D9);
DigitalOut led3(D10);


int nowSec = 0, nowMin = 0, nowHour = 0, nowDay = 1, nowMon = 0, nowYear = 117;

int main()
{
    showTime_ticker.attach(&showTime, 1.0);
    timeInit();
    alarmInit();
    lcd_init();
    testPrint();
    alarmSync();
   // showTimeToLCD();
    while (1)
    {
        modeChange();
    }
}