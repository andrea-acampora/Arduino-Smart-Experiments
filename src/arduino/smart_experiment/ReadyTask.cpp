#include "ReadyTask.h"
#include "TimerTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "EnableInterrupt.h"
#include "MsgService.h"


ReadyTask::ReadyTask(Light* led1, Button* button1,Pir* pir){
  this -> led1 = led1;
  this -> button1 = button1;
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
       MsgService.sendMsg("STATE=READY");
       this -> led1 -> switchOn();
       state = DETECTING;
       break;

    case DETECTING:
        if( millis() - this -> start_time >= SLEEP_TIME){
          state = SLEEPING;
        }
        if (this -> button1 -> isPressed()){
          state = EXIT;
        }
        break;

     case SLEEPING:
        MsgService.sendMsg("STATE=SLEEPING");
        this -> led1 -> switchOff();
        enableInterrupt(this -> pir -> getPin(), wakeUp, RISING);
        delay(100);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
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
        this -> setActive(false);
        break;
  }
}
