#ifndef __READYTASK__
#define __READYTASK__

#include <avr/sleep.h>
#include "Task.h"
#include "Light.h"
#include "BlinkingTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "Button.h"
#include "Pir.h"

class ReadyTask: public Task {

    Light* led1;
    Button* button1;
    Pir* pir;
    int start_time;
    enum { ENTRY, DETECTING , SLEEPING, EXIT} state; 
       
public:

  ReadyTask(Light* led1, Button* button1, Pir* pir);  
  void init(int period);  
  void tick();
  
};


#endif
