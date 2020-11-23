#include "CalculateFrequencyTask.h"
#include "Arduino.h"
#include "Pot.h"
#include "Globals.h"

CalculateFrequencyTask::CalculateFrequencyTask(){}

void CalculateFrequencyTask::init(int period){
  Task::init(period);
  pot = new Pot(POT_PIN);
}

void CalculateFrequencyTask::tick(){
  int value  = pot -> getValue();
  frequency = map(value,0 , 1023, MINFREQ, MAXFREQ);
}
