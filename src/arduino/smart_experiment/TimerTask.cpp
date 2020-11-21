#include "Arduino.h"
#include "TimerTask.h"

TimerTask::TimerTask(long int time_to_expire){
  this -> time_to_expire = time_to_expire;
  }

void TimerTask::init(int period){
  Task::init(period);
  this -> elapsed = 0;
  this -> period = period;
  this -> setActive(true);
}

void TimerTask::tick(){
  this -> elapsed = this -> elapsed + this ->period;
  if(this -> elapsed >= this -> time_to_expire){
    this -> setActive(false);
  }
}
