#include "ReadPotTask.h"
#include "Arduino.h"

#define POT_PIN A0

ReadPotTask::ReadPotTask(){}

void ReadPotTask::init(int period){
  Task::init(period);
  pot = new Pot(POT_PIN);
}

void FrequencyTask::tick(){}

int getValue(){
  return pot -> getValue();
}


