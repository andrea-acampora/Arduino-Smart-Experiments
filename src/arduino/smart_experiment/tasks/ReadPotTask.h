#ifndef __READPOTTASK__
#define __READPOTTASK__

#include "Task.h"
#include "Arduino.h"
#include "../componentLib/Pot.h"

class ReadPotTask: public Task {

  Pot* pot;
  
public:

  ReadPotTask();  
  void init(int period);  
  void tick();
  int getValue();
};


#endif
