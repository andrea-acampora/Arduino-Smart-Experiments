#include "BlinkingTask.h"
#include "Arduino.h"

BlinkingTask::BlinkingTask(Light* led){ 
  this->led = led;
}
  
void BlinkingTask::setActive(bool active){
  Task::setActive(active);
  if (active){
    state = ON;
  } else {
    led->switchOff();
  }
}
  
void BlinkingTask::tick(){
  switch (state){
    case ON: {
      led->switchOn();
      state = OFF;
      break;
    }
    case OFF: {
      led->switchOff();
      state = ON;
      break;
    }
  }
}
