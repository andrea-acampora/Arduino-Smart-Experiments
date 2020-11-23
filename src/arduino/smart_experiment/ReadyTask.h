#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "Light.h"
#include "Arduino.h"
#include "Globals.h"

#define SLEEP_TIME 5000
#define PIN_LED_1 13
#define NMAX 50

class ReadyTask: public Task {

  Task* taskList[NMAX];
  Light* led_1;
  int nTasks;

public:

  ReadyTask(Task* calculateFrequency, Task* timer);  
  void init(int period);  
  void tick();
};


#endif
