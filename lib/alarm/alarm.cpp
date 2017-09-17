#include "alarm.h"

struct tm alarm;
time_t alarmSeconds;
int alarmSec = 0,
    alarmMin = 0,
    alarmHour = 0,
    alarmDay = 1,
    alarmMon = 0,
    alarmYear = 117;

char alarmBuffer[32];

int alarmSync()
{
    char buffer[32];
    alarmSeconds = time(NULL);
    strftime(buffer, 32, "%Y/%m/%d %H:%M:%S %p", localtime(&alarmSeconds));
    lcdSecondPrintStr("alarm updated.", OFF);
    pc.printf("alarm time is %s\n", buffer);
    wait(0.7);
    return 0;
}
int alarmInit()
{
    alarm.tm_sec = 0;
    alarm.tm_min = alarmMin;
    alarm.tm_hour = alarmHour;
    alarm.tm_mday = alarmDay;
    alarm.tm_mon = alarmMon;
    alarm.tm_year = alarmYear;
    /*
    alarmSec = alarm.tm_sec;
    alarmMin = alarm.tm_min;
    alarmHour = alarm.tm_hour;
    alarmDay = alarm.tm_mday;
    alarmMon = alarm.tm_mon;
    alarmYear = alarm.tm_year;
    */
    alarmSeconds = mktime(&alarm);

    return alarmSeconds;
}
int checkNowIsAlarm()
{
    time_t seconds = time(NULL);
    if(seconds < 1483196430){
        return 0;
    }
    if (seconds == alarmSeconds)
    {
        alarmBuzzer();
    }
    else
    {
        printf("until alarm time : %ldsec.\n", alarmSeconds - seconds);
        char buffer[32];
        strftime(buffer, 32, "%Y/%m/%d %H:%M:%S %p", localtime(&alarmSeconds));
        pc.printf("Alarm time is = %s\n", buffer);
    }

    return 0;
}

int alarmSetup()
{
    lcdSecondPrintStr("alarm Setup", ON);
    while (true)
    {
        switch (waitPushButton())
        {
        case 1:
            alarmYearSetup();
            break;
        case 2:
            alarmMonSetup();
            break;
        case 3:
            alarmDaySetup();
            break;
        case 4:
            alarmHourSetup();
            break;
        case 5:
            alarmMinSetup();
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}

int alarmYearSetup()
{
    lcdSecondPrintStr("year setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("alarm year:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmYear += 1;
            break;
        case 2:
            alarmYear -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }
        alarmInit();

        lcdSecondPrintNum(getTimeAlarmChar("year"), OFF);
        pc.printf("alarmYear : %s\n", getTimeAlarmChar("year"));
    }
    alarmInit();

    return 0;
}

char *getTimeAlarmChar(const char *selectTime)
{
    time_t seconds = alarmInit();
    if (!strcmp(selectTime, "year"))
    {
        strftime(alarmBuffer, 32, "%Y", localtime(&seconds));
        printf("alarmbuffer = %s\n", alarmBuffer);
        return alarmBuffer;
    }
    if (!strcmp(selectTime, "month"))
    {
        strftime(alarmBuffer, 32, "%m", localtime(&seconds));
        return alarmBuffer;
    }
    if (!strcmp(selectTime, "day"))
    {
        strftime(alarmBuffer, 32, "%d", localtime(&seconds));
        return alarmBuffer;
    }
    if (!strcmp(selectTime, "hour"))
    {
        strftime(alarmBuffer, 32, "%I", localtime(&seconds));
        return alarmBuffer;
    }
    if (!strcmp(selectTime, "minute"))
    {
        strftime(alarmBuffer, 32, "%M", localtime(&seconds));
        return alarmBuffer;
    }
    if (!strcmp(selectTime, "second"))
    {
        strftime(alarmBuffer, 32, "%S", localtime(&seconds));
        return alarmBuffer;
    }
    return 0;
}

int alarmMonSetup()
{
    lcdSecondPrintStr("month setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("alarm mon:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmMon += 1;
            break;
        case 2:
            alarmMon -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }
        alarmInit();
        lcdSecondPrintNum(getTimeAlarmChar("month"), OFF);
        //lcdSecondPrintNum(getTimeAlarmChar("month"), OFF);
        pc.printf("alarmMon : %s\n", getTimeAlarmChar("month"));
    }
    alarmInit();

    return 0;
}
int alarmDaySetup()
{
    lcdSecondPrintStr("day setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("alarm day:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmDay += 1;
            break;
        case 2:
            alarmDay -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }
        alarmInit();
        lcdSecondPrintNum(getTimeAlarmChar("day"), OFF);
        //lcdSecondPrintNum(getTimeAlarmChar("day"), OFF);
        pc.printf("alarmday : %s\n", getTimeAlarmChar("day"));
    }
    alarmInit();

    return 0;
}
int alarmHourSetup()
{
    lcdSecondPrintStr("hour setup", ON);
    lcd_CLS();
    while (true)
    {
        lcdSecondPrintStr("alarm hour:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmHour += 1;
            break;
        case 2:
            alarmHour -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }
        alarmInit();
        lcdSecondPrintNum(getTimeAlarmChar("hour"), OFF);
        //lcdSecondPrintNum(getTimeAlarmChar("hour"), OFF);
        pc.printf("alarmhour : %s\n", getTimeAlarmChar("day"));
    }

    alarmInit();

    return 0;
}

int alarmMinSetup()
{
    lcdSecondPrintStr("min setup", ON);
    lcd_CLS();

    while (true)
    {
        lcdSecondPrintStr("alarm min:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmMin += 1;
            break;
        case 2:
            alarmMin -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }

        alarmInit();
        lcdSecondPrintNum(getTimeAlarmChar("minute"), OFF);
        //lcdSecondPrintNum(getTimeAlarmChar("minute"), OFF);
        pc.printf("alarmmin : %s\n", getTimeAlarmChar("minute"));
    }
    alarmInit();

    return 0;
}

int alarmSecSetup()
{
    lcdSecondPrintStr("sec setup", ON);
    lcd_CLS();

    while (true)
    {
        lcdSecondPrintStr("alarm sec:", OFF);
        switch (waitPushButton())
        {
        case 1:
            alarmSec += 1;
            break;
        case 2:
            alarmSec -= 1;
            break;
        case 3:
            alarmInit();
            break;
        case 6:
            return 0;
        }
    }
    alarmInit();
    lcdSecondPrintNum(getTimeAlarmChar("second"), OFF);
    //lcdSecondPrintNum(getTimeAlarmChar("second"), OFF);
    pc.printf("alarmsec : %s\n", getTimeAlarmChar("second"));

    alarmInit();

    return 0;
}

int alarmSet()
{
    lcdSecondPrintStr("alarm set", ON);

    return 0;
}

int alarmTimeUpdate()
{
    return 0;
}

int alarmBuzzer()
{

    pc.printf("alarm is on\n");
    buzzer();
    return 0;
}
