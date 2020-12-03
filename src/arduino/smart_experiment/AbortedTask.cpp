#include "AbortedTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "MsgService.h"

/**
 * This task is activated from the task manager when at the start of the Experiment the sonar doesn't detect any object.
 * It will active the BlinkingTask for 2 seconds.
 */
AbortedTask::AbortedTask(Task* blinkingTask){
  this -> blinkingTask = blinkingTask;
 }

void AbortedTask::init(int period){
  Task::init(period);
  state = ENTRY;
}

void AbortedTask::tick(){
  
  switch(state){
    
    case ENTRY:
       MsgService.sendMsg("State=ABORTED");
       this -> start_time = millis();
       this -> blinkingTask -> setActive(true);
       state = BLINKING;
       break;

    case BLINKING:
        if(this -> isTimeExpired()){
          state = EXIT;
        }
        break;

      case EXIT:
        state = ENTRY;
        this -> blinkingTask -> setActive(false);
        this -> setActive(false);
        break;
  }
}

bool AbortedTask::isTimeExpired(){
  return millis() - this -> start_time >= ERROR_TIME;
}
