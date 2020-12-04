#include "TerminatedTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "MsgService.h"

/**
 * This task represents the ending state of the experiment.
 * During its execution it will wait for input restart.
 */

TerminatedTask::TerminatedTask(Task* blinkingTask){
  this -> blinkingTask = blinkingTask;
 }

void TerminatedTask::init(int period){
  Task::init(period);
  state = START;
}

void TerminatedTask::tick(){
  
  switch(state){
    
    case START:
       MsgService.sendMsg("State=TERMINATED");
       this -> blinkingTask -> setActive(true);
       state = WAITING_FOR_RESTART;
       break;

    case WAITING_FOR_RESTART:
        if (this -> checkUserInput()){
          state = EXIT;
        }
        break;

      case EXIT:
        state = START;
        this -> blinkingTask -> setActive(false);
        this -> setActive(false);
        break;
  }
}

bool TerminatedTask::checkUserInput(){
  if (MsgService.isMsgAvailable()) {
    Msg* msg = MsgService.receiveMsg();    
    if (msg->getContent() == "OK"){
        delete msg;
        return true;
    }
      return false;
  }
}
