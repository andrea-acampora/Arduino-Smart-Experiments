#ifndef __INEXECUTIONTASK__
#define __INEXECUTIONTASK__

#include "Task.h"
#include "Arduino.h"

class InExecutionTask: public Task {


    enum { ENTRY, TRACKING, ABORTED, TERMINATED, EXIT} state; 
       
public:

  InExecutionTask();  
  void init(int period);  
  void tick();
  
};


#endif
