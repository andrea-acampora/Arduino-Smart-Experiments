#include "Arduino.h"
#include "Scheduler.h"
#include "Task.h"
#include "ReadyTask.h"

#define SLEEP_TIME 5
#define STATE_READY 1
#define STATE_SLEEPING 2
#define STATE_ABORTED 3
#define STATE_IN_EXECUTION 4
#define STATE_TERMINATED 5

Scheduler sched;

Task* currentTask;

int state;
bool task_active;

  void setup() {
   state = STATE_READY;
   currentTask = new ReadyTask();
   currentTask->init(300);
   sched.init(100);
   sched.addTask(currentTask);
}

void loop() {
  
  noInterrupts();
  task_active = currentTask -> isActive();
  int currentState = state;
  interrupts();
  if(!task_active){
    switch(currentState){
      case STATE_READY:
        currentTask = new ReadyTask();//DA CAMBIARE SOLO PER PROVA
        currentTask -> init(200);
        sched.init(50);
    }
    sched.addTask(currentTask);
  }
  sched.schedule();
}
