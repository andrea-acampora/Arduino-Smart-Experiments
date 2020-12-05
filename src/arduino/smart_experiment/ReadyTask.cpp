#include "ReadyTask.h"
#include "Arduino.h"
#include "Globals.h"
#include "EnableInterrupt.h"
#include "MsgService.h"

/**
 * Task which contains the starting actions before the experiment starts.
 * It's activated from the task manager at the beginning of program's execution.
 * It also manage the sleep mode.
 */
ReadyTask::ReadyTask(Light* led1, Task* checkButtonStartTask,Pir* pir){
  this -> led1 = led1;
  this -> checkButtonStartTask = checkButtonStartTask;
  this -> pir = pir;
 }

void ReadyTask::init(int period){
  Task::init(period);
  state = START;
}

void wakeUp(){}

void ReadyTask::tick(){
  
  switch(state){
    
    case START:
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
        if (this -> isButtonStartPressed()){//function that used the CheckButtonStart task and check if the start button is pressed.
          state = START;
          this -> setActive(false);
        }
        break;
      /*
       * The sleep state of the experiment.
       * The system will be in power save mode until the pir sensor will detect something.
       */ 
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
          state = START;
          disableInterrupt(this -> pir -> getPin());
          sleep_disable();
        }
        break;
  }
}

bool ReadyTask::isButtonStartPressed(){
  return !this->checkButtonStartTask->isActive();
}

bool ReadyTask::isTimeToSleep(){
   return (millis() - this -> start_time) >= SLEEP_TIME;
   }


   
