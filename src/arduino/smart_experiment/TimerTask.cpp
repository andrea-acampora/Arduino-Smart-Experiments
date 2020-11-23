#include "Arduino.h"
#include "TimerTask.h"

TimerTask::TimerTask(){}

void TimerTask::init(int period){
  Task::init(period);
  this -> setActive(false);
  this -> old_tick = 0;
}

void TimerTask::tick(){
  int current = millis();
  int elapsed = current - this -> old_tick;
  timer -= elapsed;
  this -> old_tick = current;
}
