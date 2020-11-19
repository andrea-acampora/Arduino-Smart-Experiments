#include "FrequencyTask.h"
#include "ReadPotTask.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"
#include "Arduino.h"

FrequencyTask::FrequencyTask(){}

void FrequencyTask::init(int period){
  Task::init(period);
  readPot = new ReadPotTask();
  readPot -> init(0);
  calculateFrequency = new calculateFrequencyTask();
  calculateFrequency->init(0);
  sendToSerial = new sendToSerialTask();
  sendToSerial->init(0);
}

void FrequencyTask::tick(){
  //readPot->tick(); NON MI SERVE FARLO TICCARE
  calculateFrequency->setValue(readPot->getValue());
  calculateFrequency->tick();
  sendToSerial -> setMessage(calculateFrequency->getFrequency());
  sendToSerial->tick();
}


