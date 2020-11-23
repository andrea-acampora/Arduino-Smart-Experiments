#include "Arduino.h"
#include "ObjectPositionTask.h"

void ObjectPositionTask::init(int period){
    Task::init(period); 
    sonar = new Sonar(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN); 
    this->distanceToTheWall = sonar->getDistance(temperature);  
}

void ObjectPositionTask::tick(){
    this->objectDistance = getObjectDistance();
}

float ObjectPositionTask::getObjectDistance(){
    return sonar->getDistance(temperature);  
}

bool ObjectPositionTask::isObjectDetected(){
    return getObjectDistance() != this->distanceToTheWall; 
}

