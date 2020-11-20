#include "Arduino.h"
#include "Button.h"

Button::Button(int pin){
    this->pin = pin; 
    pinMode(pin,INPUT_PULLUP);
}

bool Button::isPressed(){
    return digitalRead(pin) == LOW;
}
