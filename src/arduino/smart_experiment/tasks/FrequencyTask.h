#ifndef __FREQUENCYTASK__
#define __FREQUENCYTASK__

#include "Task.h"
#include "ReadPotTask.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"

#define POT_PIN A0

class FrequencyTask: public Task {

  ReadPotTask* readPot;
  CalculateFrequencyTask* calculateFrequency;
  SendToSerialTask* sendToSerial;


public:

  FrequencyTask();  
  void init(int period);  
  void tick();

};


#endif
