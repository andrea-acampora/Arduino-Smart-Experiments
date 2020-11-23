#include "EnableInterrupt.h"

#include "Led.h"
#include "SleepingTask.h"
#include "Arduino.h"
#include <avr/sleep.h>

SleepingTask::SleepingTask(){
  pir_sensor = new Pir(PIN_PIR);
  led_1 = new Led(PIN_LED_1);
  }


void SleepingTask::wakeUp(){
  state = READY;
  
  }

void SleepingTask::init(int period){
  
  Task::init(period);
  this -> setActive(true);
  led_1 -> switchOff();
  enableInterrupt(this->pir_sensor->getPin(), wakeUp, RISING);   

}

void SleepingTask::tick(){
  if (state == SLEEPING){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
    sleep_enable();
    sleep_mode(); 
    sleep_disable();
  }
  }
