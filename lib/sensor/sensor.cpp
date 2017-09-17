#include "sensor.h"

LPS25H tempSensor(I2C_SDA, I2C_SCL, 0xBB);

int printTemperature(void){
    tempSensor.get();
    char buffer[16] = {0};
    sprintf(buffer,"P:%4.0fhPa T:%2.1f",tempSensor.pressure(),tempSensor.temperature());
    lcdSecondPrintStr(buffer,OFF);
    printf("Pressure: %f, temperature: %f\n",tempSensor.pressure(), tempSensor.temperature());
    
    return 0;
}
