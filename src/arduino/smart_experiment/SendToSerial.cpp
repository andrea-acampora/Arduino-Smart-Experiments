#include "SendToSerialTask.h"
#include "Arduino.h"
#include "MsgService.h"

SendToSerialTask::SendToSerialTask(){}

void SendToSerialTask::init(int period){
  Task::init(period);
  MsgService.init();
}

void SendToSerialTask::tick(){
    MsgService.sendMsg(this->value);
}
