#ifndef __TIMERTASK__
#define __TIMERTASK__

#include "Task.h"
#include "Globals.h"

class TimerTask: public Task {

  int period;
  int old_tick;

public:

  TimerTask();  
  void init(int period);  
  void tick();
};


#endif
