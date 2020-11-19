#include "Arduino.h"
#include "Pot.h"

Pot::Pot(String pin){
    this.pin = pin; 
}

int Pot::getValue(){
    return analogRead(pin); 
}
