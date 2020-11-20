#ifndef __POT__
#define __POT__

#include "Arduino.h"
class Pot{
    public: 
        Pot(int pin); 
        int getValue(); 
    private: 
        int pin; 
}; 

#endif
