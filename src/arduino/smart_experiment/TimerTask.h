#ifndef __TIMERTASK__
#define __TIMERTASK__

#include "Task.h"

class TimerTask: public Task {

  int elapsed;
  int period;
  int time_to_expire;

public:

  TimerTask(long int time_to_expire);  
  void init(int period);  
  void tick();
};


#endif
