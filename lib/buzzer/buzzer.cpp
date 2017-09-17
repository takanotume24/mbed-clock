#include "buzzer.h"


void buzzerON(){
    buzzerPin.period(1.0/440);
    buzzerPin.write(0.5);
    wait(5.0); 
}


int buzzer()
{
    pc.printf("buzzer is on\n");
    buzzerPin.period(1.0 / 440);
    while (!checkButton())
    {
        showTimeToLCD();
        buzzerPin.write(0.5f);
    }
    buzzerPin.write(0);
    return 0;
}