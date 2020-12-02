#ifndef __ABORTEDTASK__
#define __ABORTEDTASK__

#include "Task.h"
#include "BlinkingTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "MsgService.h"

#define ERROR_TIME 2000

class AbortedTask: public Task {

    Task* blinkingTask;
    unsigned long start_time;
    enum { ENTRY, BLINKING , EXIT} state;

    bool isTimeExpired(); 
       
public:

  AbortedTask(Task* blinkingTask);  
  void init(int period);  
  void tick();
  
};


#endif
