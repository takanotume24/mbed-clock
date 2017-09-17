#ifndef LCD
#define LCD

#include "mbed.h"
#include "pin.h"


extern const int AQM1602XA_addr;
extern unsigned char contrast;
extern char lcdBuffer[16];
void lcd_cmd(char);
void lcd_coutdata(char);
void lcd_lastdata(char);
void lcd_printStr(const char *);
void lcd_setCursor(unsigned char, unsigned char);
void lcd_CLS();
void lcd_init();
void showTimeToLCD();

void lcdFirstPrintStr(const char *);
void lcdSecondPrintStr(const char *,int);
void lcdSecondPrintNum(const char *,int);

void testPrint();



#endif