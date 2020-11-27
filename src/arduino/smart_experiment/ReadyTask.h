#ifndef __READYTASK__
#define __READYTASK__

#include <avr/sleep.h>
#include "Task.h"
#include "CheckButtonTask.h"
#include "Light.h"
#include "BlinkingTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "Button.h"
#include "Pir.h"

#define SLEEP_TIME 5000

class ReadyTask: public Task {

    Light* led1;
    Pir* pir;
    Task* checkButtonStartTask;
    
    int start_time;
    enum { ENTRY, DETECTING , SLEEPING, EXIT} state; 

    bool isTimeToSleep();
    bool isButtonStartPressed();
       
public:

  ReadyTask(Light* led1, Task* checkButtonStartTask, Pir* pir);  
  void init(int period);  
  void tick();
  
};


#endif
