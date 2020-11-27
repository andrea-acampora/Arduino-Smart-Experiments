#ifndef __SONAR__
#define __SONAR__

#include "Globals.h"
#include "Arduino.h"


class Sonar{
  
    public:
        Sonar(int trigPin, int echoPin); 
        float getDistance(float temperature); 
        bool isObjectDetected(float temperature);

    private:
        int trigPin; 
        int echoPin; 
        int maxDistance;
};

#endif
