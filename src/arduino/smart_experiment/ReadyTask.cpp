#include "ReadyTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "EnableInterrupt.h"
#include "MsgService.h"


ReadyTask::ReadyTask(Light* led1, Task* checkButtonStartTask,Pir* pir){
  this -> led1 = led1;
  this -> checkButtonStartTask = checkButtonStartTask;
  this -> pir = pir;
 }

void ReadyTask::init(int period){
  Task::init(period);
  state = ENTRY;
}

void wakeUp(){}

void ReadyTask::tick(){
  
  switch(state){
    
    case ENTRY:
       this -> start_time = millis();
       MsgService.sendMsg("State=READY");
       this -> checkButtonStartTask -> setActive(true);
       this -> led1 -> switchOn();
       state = DETECTING;
       break;

    case DETECTING:
        if(this -> isTimeToSleep()){
          state = SLEEPING;
        }
        if (this -> isButtonStartPressed()){
          state = EXIT;
        }
        break;

     case SLEEPING:
        MsgService.sendMsg("State=SLEEPING");
        this -> led1 -> switchOff();
        enableInterrupt(this -> pir -> getPin(), wakeUp, RISING);
        delay(100);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        Serial.flush();
        sleep_enable();
        sleep_mode();
        if(this-> pir -> isDetected()){
          state = ENTRY;
          disableInterrupt(this -> pir -> getPin());
          sleep_disable();
        }
        break;

      case EXIT:
        state = ENTRY;
        this -> checkButtonStartTask -> setActive(false);
        this -> setActive(false);
        break;
  }
}

bool ReadyTask::isButtonStartPressed(){
  return !this->checkButtonStartTask->isActive();
}

bool ReadyTask::isTimeToSleep(){
   return (millis() - this -> start_time) >= SLEEP_TIME;
   }


   
