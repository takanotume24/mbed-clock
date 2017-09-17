#include "mbed.h"
#include "clock.h"
#include "pin.h"
#include "alarm.h"
#include "lcd.h"
#include "sensor.h"

static char buffer[32];

int checkButton()
{
    if (pushButton1 == ON)
    {
        //pc.printf("1:ON  2:OFF 3:OFF 4:OFF \n");
        return 1;
    }
    if (pushButton2 == ON)
    {
        //pc.printf("1:OFF 2:ON  3:OFF 4:OFF \n");
        return 2;
    }
    if (pushButton3 == ON)
    {
        //pc.printf("1:OFF 2:OFF 3:ON  4:OFF \n");
        return 3;
    }
    if (pushButton4 == ON)
    {
        //pc.printf("1:OFF 2:OFF 3:OFF 4:ON \n");
        return 4;
    }
    if (pushButton5 == ON)
    {
        return 5;
    }
    if (pushButton6 == ON)
    {
        return 6;
        pc.printf("6 is pushed\n");
    }
    else
    {
        return 0;
        //pc.printf("no button is pushed\n");
    }
}

int timeInit()
{
    struct tm t ={0};
    t.tm_sec = nowSec;        // 0-59
    t.tm_min = nowMin;        // 0-59
    t.tm_hour = nowHour;      // 0-23
    t.tm_mday = nowDay;       // 1-31
    t.tm_mon = nowMon;        // 0-11
    t.tm_year = nowYear; // year since 1900

    // convert to timestamp and set (1256729737)
    time_t seconds = mktime(&t);
    set_time(seconds);
    //lcdSecondPrintStr("time setup is complete",OFF);
    wait(0.3);
    printf("seconds : %ld\n",seconds);
    return seconds;
}

int waitPushButton()
{
    int buttonState = 0;
    while (buttonState <= 0)
    {
        buttonState = checkButton();
        loop();
    }
    wait(0.2);

    return buttonState;
}

char *getTimeChar(const char *selectTime)
{
    time_t seconds = time(NULL);
    if (!strcmp(selectTime, "year"))
    {
        strftime(buffer, 32, "%Y", localtime(&seconds));
        return buffer;
    }
    if (!strcmp(selectTime, "month"))
    {
        strftime(buffer, 32, "%m", localtime(&seconds));
        return buffer;
    }
    if (!strcmp(selectTime, "day"))
    {
        strftime(buffer, 32, "%d", localtime(&seconds));
        return buffer;
    }
    if (!strcmp(selectTime, "hour"))
    {
        strftime(buffer, 32, "%I", localtime(&seconds));
        return buffer;
    }
    if (!strcmp(selectTime, "minute"))
    {
        strftime(buffer, 32, "%M", localtime(&seconds));
        return buffer;
    }
    if (!strcmp(selectTime, "second"))
    {
        strftime(buffer, 32, "%S", localtime(&seconds));
        return buffer;
    }

    return 0;
}

void showTime()
{
    time_t seconds = time(NULL); // JST
    
    char buffer[32];
    strftime(buffer, 32, "%Y/%m/%d %H:%M:%S %p", localtime(&seconds));
    pc.printf("Time as a formatted string = %s\n", buffer);
    
    /*
    %S	Second (00-59)
    %M	Minute (00-59)
    %H	Hour (00-23)
    %d	Day (01-31)
    %m	Month (01-12)
    %Y/%y	Year (2009/09)
    %A/%a	Weekday Name (Monday/Mon)
    %B/%b	Month Name (January/Jan)
    %I	12 Hour Format (01-12)
    %p	”AM” or “PM”
    %X	Time (14:55:02)
    %x	Date (08/23/01)
    */
    checkNowIsAlarm();
}

int backToHomeScreen()
{
    timeInit();
    modeChange();

    return 0;
}


int yearSetup()
{
    lcdSecondPrintStr("year setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("now year:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowYear += 1;
            break;
        case 2:
            nowYear -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }
        timeInit();

        lcdSecondPrintNum(getTimeChar("year"), OFF);
        pc.printf("nowYear : %s\n", getTimeChar("year"));
    }
    timeInit();

    return 0;
}

int monthSetup()
{
    lcdSecondPrintStr("month setup", ON);
    lcd_CLS();
    while (true)

    {
        lcdSecondPrintStr("now month:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowMon += 1;
            break;
        case 2:
            nowMon -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }
        timeInit();
        lcdSecondPrintNum(getTimeChar("month"), OFF);
        //lcdSecondPrintNum(getTimeChar("month"), OFF);
        pc.printf("nowMon : %s\n", getTimeChar("month"));
    }
    timeInit();

    return 0;
}
int daySetup()
{
    lcdSecondPrintStr("day setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("now day:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowDay += 1;
            break;
        case 2:
            nowDay -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }
        timeInit();
        lcdSecondPrintNum(getTimeChar("day"), OFF);
        //lcdSecondPrintNum(getTimeChar("day"), OFF);
        pc.printf("nowday : %s\n", getTimeChar("day"));
    }
    timeInit();

    return 0;
}
int hourSetup()
{
    lcdSecondPrintStr("hour setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("now hour:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowHour += 1;
            break;
        case 2:
            nowHour -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }
        timeInit();
        lcdSecondPrintNum(getTimeChar("hour"), OFF);
        //lcdSecondPrintNum(getTimeChar("hour"), OFF);
        pc.printf("nowhour : %s\n", getTimeChar("day"));
    }

    timeInit();

    return 0;
}

int minSetup()
{
    lcdSecondPrintStr("min setup", ON);
    lcd_CLS();

    while (true)
    {
        lcdSecondPrintStr("now minute:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowMin += 1;
            break;
        case 2:
            nowMin -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }

        timeInit();
        lcdSecondPrintNum(getTimeChar("minute"), OFF);
        //lcdSecondPrintNum(getTimeChar("minute"), OFF);
        pc.printf("nowmin : %s\n", getTimeChar("minute"));
    }
    timeInit();

    return 0;
}

int secSetup()
{
    lcdSecondPrintStr("sec setup", ON);
    lcd_CLS();

    while (true)
    {
        lcdSecondPrintStr("now second:", OFF);
        switch (waitPushButton())
        {
        case 1:
            nowSec += 1;
            break;
        case 2:
            nowSec -= 1;
            break;
        case 3:
            timeInit();
            break;
        case 6:
            return 0;
        }
    }
    timeInit();
    lcdSecondPrintNum(getTimeChar("second"), OFF);
    //lcdSecondPrintNum(getTimeChar("second"), OFF);
    pc.printf("nowsec : %s\n", getTimeChar("second"));

    timeInit();

    return 0;
}

int timeSetup()
{
    lcdSecondPrintStr("time setup mode", ON);
    switch (waitPushButton())
    {
    case 1:
        yearSetup();
        break;
    case 2:
        monthSetup();
        break;
    case 3:
        daySetup();
        break;
    case 4:
        hourSetup();
        break;
    case 5:
        minSetup();
        break;
    case 6:
        return 0;
    default:
        break;
    }

    return 0;
}

int modeChange()
{
    lcdSecondPrintStr("select mode", ON);
    printTemperature();
    switch (waitPushButton())
    {
    case 1:
        timeSetup();
        break;
    case 2:
        alarmSetup();
        break;
    case 3:
        alarmSet();
        break;
    case 4:
        alarmSync();
        break;
    case 6:
        return 0;
    default:
        break;
    }

    return 0;
}


int loop(void){
    showTimeToLCD();
    //lcd_cmd(0x18);
    //wait(0.2);
    return 0;
}