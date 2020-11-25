#include "Arduino.h"
#include "TimerTask.h"

TimerTask::TimerTask(){}

void TimerTask::init(int period){
  Task::init(period);
  this -> setActive(false);
  this -> old_tick = 0;
}

void TimerTask::tick(){

}
