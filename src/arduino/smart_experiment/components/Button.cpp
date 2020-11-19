#include "Arduino.h"
#include "Button.h"

Button::Button(int pin){
    this.pin = pin; 
}

bool Button::isPressed(){
    return digitalRead(pin) == HIGH;
}