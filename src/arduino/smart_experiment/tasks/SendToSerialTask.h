#ifndef __SENDTOSERIALTASK__
#define __SENDTOSERIALTASK__

#include "Task.h"
#include "ReadPotTask.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"

#define POT_PIN A0

class FrequencyTask: public Task {

  // String pin;
  // Pot* pot;
  // int frequency;
  ReadPotTask* readPot;
  CalculateFrequencyTask* calculateFrequency;
  SendToSerialTask* sendToSerial;


public:

  FrequencyTask();  
  void init(int period);  
  void tick();

};


#endif
