#ifndef __SLEEPINGTASK__
#define __SLEEPINGTASK__

#include "Task.h"
#include "Light.h"
#include "Pir.h"
#include "Globals.h"

class SleepingTask: public Task {

  Light* led_1;
  Pir* pir_sensor;

public:

  SleepingTask();
  void init(int period);  
  static void wakeUp();
  void tick();
  
};


#endif
