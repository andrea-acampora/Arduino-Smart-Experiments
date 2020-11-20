#include "CalculateFrequencyTask.h"
#include "Arduino.h"
#include "Pot.h"

CalculateFrequencyTask::CalculateFrequencyTask(){}

void CalculateFrequencyTask::init(int period){
  Task::init(period);
  pot = new Pot(POT_PIN);
}

void CalculateFrequencyTask::tick(){
  int value  = pot -> getValue();
  this->frequency = map(value,0 , 1023, MINFREQ, MAXFREQ);
}

int CalculateFrequencyTask::getFrequency(){
  return this->frequency;
}
