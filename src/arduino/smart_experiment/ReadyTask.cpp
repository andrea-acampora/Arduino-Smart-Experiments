#include "Led.h"
#include "ReadyTask.h"
#include "TimerTask.h"
#include "Arduino.h"

ReadyTask::ReadyTask(){}

void ReadyTask::init(int period){
  
  Task::init(period);
  frequencyTask = new FrequencyTask();
  frequencyTask->init(0);
  timerTask = new TimerTask(SLEEP_TIME);
  timerTask -> init(period);
  led_1 = new Led(PIN_LED_1);
  led_1 -> switchOn();
  this -> setActive(true);
}

void ReadyTask::tick(){
  if(timerTask -> isActive()){
      timerTask -> tick();
  }else{
    this -> setActive(false);
  }
  frequencyTask->tick();
}
