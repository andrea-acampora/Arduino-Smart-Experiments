#include "Arduino.h"
#include "MsgService.h"
#include "InExecutionTask.h"


InExecutionTask::InExecutionTask(){ }

void InExecutionTask::init(int period){
  Task::init(period);
  state = ENTRY;
}

void InExecutionTask::tick(){
  
  switch(state){
    
    case ENTRY:
       MsgService.sendMsg("STATE=IN_EXECUTION");
       break;
  }
}
