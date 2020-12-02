#include "CheckButtonTask.h"
#include "Arduino.h"

CheckButtonTask::CheckButtonTask(Button* button){ 
  this->button = button;
}

void CheckButtonTask::init(int period){
  Task::init(period);
  state = ON;
}
  
void CheckButtonTask::tick(){
  switch(state){
    case ON:
     if(this -> button -> isPressed()){
       state = OFF;
     }
     break;

    case OFF:
      this -> setActive(false);
      state = ON;
      break;
  }
}
