#include "Arduino.h"
#include "ProcessDataTask.h"

void ProcessDataTask::init(int period){
    
}

void ProcessDataTask::tick(){
    //aggiornamento variabili fisica
}
        
float ProcessDataTask::getSpeed(){
    return this->speed;
}

float ProcessDataTask::getAcceleration(){
    return this->acceleration; 
}
