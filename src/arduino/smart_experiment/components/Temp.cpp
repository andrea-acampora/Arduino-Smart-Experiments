#include "Temp.h"
#include "Arduino.h"

#define VCC ((float)5)

Temp::Temp(String pin){
    this.pin = pin; 
    pinMode(pin, INPUT); 
}

float Temp::getTemperature(){
     return  ananalogRead(pin)*VCC/1023/0.01;
}

