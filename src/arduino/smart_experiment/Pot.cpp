#include "Arduino.h"
#include "Pot.h"

Pot::Pot(int pin){
    this->pin = pin; 
}

int Pot::getValue(){
    return analogRead(this->pin); 
}
