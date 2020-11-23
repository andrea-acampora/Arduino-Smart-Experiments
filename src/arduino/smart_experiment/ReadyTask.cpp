#include "Led.h"
#include "ReadyTask.h"
#include "TimerTask.h"
#include "Arduino.h"
#include "Globals.h"

ReadyTask::ReadyTask(Task* calculateFrequency, Task* timer){
  this -> taskList[0] = calculateFrequency;
  this -> taskList[1] = timer;
  led_1 = new Led(PIN_LED_1);
  nTasks = 2;
  }

void ReadyTask::init(int period){
  
  Task::init(period);
  this -> setActive(true);
  led_1 -> switchOn();
  timer = SLEEP_TIME;
  for(int i=0;i<nTasks;i++){
    taskList[i] -> setActive(true);
  }  
}

void ReadyTask::tick(){
  if(state==READY){
    if(timer <= 0){
      state = SLEEPING;
      timer = SLEEP_TIME;
       for(int i=0;i<nTasks;i++){
          taskList[i] -> setActive(false);
        } 
     }
  }
  
}
