#include "Temp.h"
#include "Arduino.h"

#define VCC ((float)5)

Temp::Temp(int pin){
    this->pin = pin; 
    pinMode(pin, INPUT); 
}

float Temp::getTemperature(){
     return  analogRead(pin)*VCC/1023/0.01;
}
