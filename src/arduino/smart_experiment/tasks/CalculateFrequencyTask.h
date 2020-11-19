#ifndef __CALCULATEFREQUENCYTASK__
#define __CALCULATEFREQUENCYTASK__

#include "Task.h"

class CalculateFrequencyTask: public Task {

  int frequency;
  int value;

public:

  CalculateFrequencyTask();  
  void init(int period);  
  void tick();
  int getFrequency();
  void setValue();
};


#endif
