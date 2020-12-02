#ifndef __TERMINATEDTASK__
#define __TERMINATEDTASK__

#include "Task.h"
#include "BlinkingTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "MsgService.h"

class TerminatedTask: public Task {

    Task* blinkingTask;
    enum { ENTRY, WAITING_FOR_RESTART , EXIT} state;
    bool checkUserInput();
       
public:

  TerminatedTask(Task* TerminatedTask);  
  void init(int period);  
  void tick();
  
};


#endif