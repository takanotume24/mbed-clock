#include "lcd.h"


void lcd_cmd(char x)
{
    char data[2];
    data[0] = 0x00; // CO = 0,RS = 0
    data[1] = x;
    i2c.write(AQM1602XA_addr, data, 2);
}

void lcd_contdata(char x)
{
    char data[2];
    data[0] = 0xC0; //0b11000000 CO = 1, RS = 1
    data[1] = x;
    i2c.write(AQM1602XA_addr, data, 2);
}

void lcd_lastdata(char x)
{
    char data[2];
    data[0] = 0x40; //0b11000000 CO = 0, RS = 1
    data[1] = x;
    i2c.write(AQM1602XA_addr, data, 2);
}

void lcd_printStr(const char *s)
{
    while (*s)
    {
        if (*(s + 1))
        {
            lcd_contdata(*s);
        }
        else
        {
            lcd_lastdata(*s);
        }
        s++;
    }
}

void lcd_setCursor(unsigned char x, unsigned char y)
{
    lcd_cmd(0x80 | (y * 0x40 + x));
}

void lcd_CLS(void)
{
    lcd_cmd(0x01); // Clear Display
}

void lcd_init()
{
    wait(0.04);
    // LCD initialize
    lcd_cmd(0x38);                           // function set
    lcd_cmd(0x39);                           // function set
    lcd_cmd(0x04);                           // EntryModeSet
    lcd_cmd(0x14);                           // interval osc
    lcd_cmd(0x70 | (contrast & 0xF));        // contrast Low
    lcd_cmd(0x5C | ((contrast >> 4) & 0x3)); // contast High/icon/power
    lcd_cmd(0x6C);                           // follower control
    wait(0.2);
    lcd_cmd(0x38); // function set
    lcd_cmd(0x0C); // Display On
    lcd_cmd(0x01); // Clear Display
    wait(0.2);     // need additional wait to Clear Display
}
///////////////////////////////////////////////////////////////////////////

void showTimeToLCD()
{
    time_t seconds = time(NULL); 
    char lcdBuffer[16];
    strftime(lcdBuffer, 16, "%Y%m%d %H%M%S", localtime(&seconds));
    //pc.printf("LCD print = %s\n", lcdBuffer);

    lcd_setCursor(0, 0);
    lcd_printStr(lcdBuffer);
}

void testPrint()
{
    char buffer1[10];
    sprintf(buffer1, "test");

    lcd_setCursor(0, 0);
    lcd_printStr(buffer1);
}

void lcdSecondPrintStr(const char *lcdchar,int clearLCD)
{
    if(clearLCD == ON){
        lcd_CLS();
    }

    pc.printf("%s\n", lcdchar);
    lcd_setCursor(0, 1);
    lcd_printStr(lcdchar);
    lcdchar = 0;
}

void lcdSecondPrintNum(const char *lcdnumber,int clearLCD)
{
    if(clearLCD == ON){
        lcd_CLS();
    }

    lcd_setCursor(11, 1);
    lcd_printStr(lcdnumber);
}

void lcdFirstPrintStr(const char *s)
{
    lcd_setCursor(0, 0);
    while (*s)
    {
        if (*(s + 1))
        {
            lcd_contdata(*s);
        }
        else
        {
            lcd_lastdata(*s);
        }
        s++;
    }
}

void lcdSecondprintStr(const char *s)
{
    lcd_setCursor(1, 0);
    while (*s)
    {
        if (*(s + 1))
        {
            lcd_contdata(*s);
        }
        else
        {
            lcd_lastdata(*s);
        }
        s++;
    }
}