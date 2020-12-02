#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin){
   this->trigPin = trigPin; 
   this->echoPin = echoPin; 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

float Sonar::getDistance(float temperature){
    const float vs = 331.45 + 0.62* temperature;

    /* invio impulso */
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);

    /* ricevi l’eco */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*vs;
    return constrain(d, 0, MAX_OBJECT_DISTANCE);
}

bool Sonar::isObjectDetected(float temperature){
    return  this -> getDistance(temperature) < MAX_OBJECT_DISTANCE;
}
