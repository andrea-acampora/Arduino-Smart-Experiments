#include "SendToSerialTask.h"
#include "Arduino.h"
#include "MsgService.h"

SendToSerialTask::SendToSerialTask(){}

void SendToSerialTask::init(int period){
  Task::init(period);
  MsgService.init();
}

void SendToSerialTask::setValue(String value){
  this->value = value;
}

void SendToSerialTask::tick(){
    MsgService.sendMsg(this->value);
}
