#ifndef __OBJECTPOSITIONTASK__
#define __OBJECTPOSITIONTASK__

#include "Sonar.h"
#include "Task.h"

#define SONAR_TRIGGER_PIN 7
#define SONAR_ECHO_PIN 8
const float temperature = 20; //da modificare, qui solo per prova

class ObjectPositionTask : public Task{
    float distanceToTheWall;
    float objectDistance; 
    Sonar* sonar;     
    public:
        void init(int period); 
        void tick(); 
        bool isObjectDetected(); 
        float getObjectDistance(); 
        
}; 
#endif 