#include "EnableInterrupt.h"

#include "Led.h"
#include "SleepingTask.h"
#include "Arduino.h"
#include <avr/sleep.h>

SleepingTask::SleepingTask(){
  pir_sensor = new Pir(PIN_PIR);
  led_1 = new Led(PIN_LED_1);
  led_1 -> switchOff();
  }


void SleepingTask::wakeUp(){
  Serial.println("interrupt");
  }

void SleepingTask::init(int period){
  
  Task::init(period);
  this -> setActive(true);
  enableInterrupt(this->pir_sensor->getPin(), wakeUp, RISING);   

}

void SleepingTask::tick(){
  Serial.println("GOING IN POWER DOWN IN 1s ...");
  Serial.flush();
  delay(1000);
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_mode(); 
  Serial.println("wake up");
  sleep_disable();
  }
