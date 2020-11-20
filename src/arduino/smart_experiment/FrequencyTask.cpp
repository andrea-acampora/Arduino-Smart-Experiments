#include "FrequencyTask.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"
#include "Arduino.h"

FrequencyTask::FrequencyTask(){}

void FrequencyTask::init(int period){
  
  Task::init(period);
  calculateFrequency = new CalculateFrequencyTask();
  calculateFrequency->init(0);
  sendToSerial = new SendToSerialTask();
  sendToSerial->init(0);
}

void FrequencyTask::tick(){

  calculateFrequency->tick();
  sendToSerial -> setValue(String(calculateFrequency->getFrequency()));
  sendToSerial->tick();
}
