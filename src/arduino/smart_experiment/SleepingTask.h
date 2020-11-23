#ifndef __SLEEPINGTASK__
#define __SLEEPINGTASK__

#include "Task.h"
#include "Light.h"
#include "Pir.h"
#include "MsgService.h"

#define PIN_LED_1 13
#define PIN_PIR 4

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
