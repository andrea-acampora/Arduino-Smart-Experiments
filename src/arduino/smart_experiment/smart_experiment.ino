#include "Arduino.h"
#include "Scheduler.h"
#include "Task.h"
#include "FrequencyTask.h"


Scheduler sched;

  void setup() {
   sched.init(100);
   Task* freqTask = new FrequencyTask();
   freqTask -> init(500);
   sched.addTask(freqTask);
}

void loop() {
  sched.schedule();
}
