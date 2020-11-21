#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "Light.h"
#include "FrequencyTask.h"

#define SLEEP_TIME 5000
#define PIN_LED_1 13

class ReadyTask: public Task {

  Task* frequencyTask;
  Task* timerTask;
  Light* led_1;

public:

  ReadyTask();  
  void init(int period);  
  void tick();
};


#endif
