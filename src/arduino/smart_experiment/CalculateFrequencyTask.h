#ifndef __CALCULATEFREQUENCYTASK__
#define __CALCULATEFREQUENCYTASK__

#include "Task.h"
#include "Pot.h"
#define POT_PIN A0
#define MINFREQ 1
#define MAXFREQ 50

class CalculateFrequencyTask: public Task {

  int frequency;
  Pot* pot;

public:

  CalculateFrequencyTask();  
  void init(int period);  
  void tick();
  int getFrequency();
};


#endif
