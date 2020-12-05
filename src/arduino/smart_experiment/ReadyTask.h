#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "CheckButtonTask.h"
#include "Light.h"
#include "BlinkingTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "Button.h"
#include "Pir.h"
#include <avr/sleep.h>

#define SLEEP_TIME 5000

/**
 * Task which contains the starting actions before the experiment starts.
 * It's activated from the task manager at the beginning of program's execution.
 * It also manage the sleep mode.
 */
class ReadyTask: public Task {

    Light* led1;
    Pir* pir;
    Task* checkButtonStartTask;
    
    unsigned long start_time;
    enum { START, DETECTING , SLEEPING } state; 

    bool isTimeToSleep();
    bool isButtonStartPressed();
       
public:

  ReadyTask(Light* led1, Task* checkButtonStartTask, Pir* pir);  
  void init(int period);  
  void tick();
  
};


#endif
