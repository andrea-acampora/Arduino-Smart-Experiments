#ifndef __CALCULATEFREQUENCYTASK__
#define __CALCULATEFREQUENCYTASK__

#include "Task.h"
#include "Pot.h"
#include "Globals.h"

#define POT_PIN A0
#define MINFREQ 1
#define MAXFREQ 50


class CalculateFrequencyTask: public Task {

  Pot* pot;

public:

  CalculateFrequencyTask();  
  void init(int period);  
  void tick();
};


#endif
