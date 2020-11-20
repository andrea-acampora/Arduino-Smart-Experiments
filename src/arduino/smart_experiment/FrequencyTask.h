#ifndef __FREQUENCYTASK__
#define __FREQUENCYTASK__

#include "Task.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"

class FrequencyTask: public Task {

  CalculateFrequencyTask* calculateFrequency;
  SendToSerialTask* sendToSerial;


public:

  FrequencyTask();  
  void init(int period);  
  void tick();

};


#endif
