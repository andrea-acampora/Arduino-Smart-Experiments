#include "Arduino.h"
#include "Scheduler.h"
#include "Task.h"
#include "ReadyTask.h"
#include "CalculateFrequencyTask.h"
#include "SendToSerialTask.h"
#include "TimerTask.h"
#include "SleepingTask.h"
#include "Globals.h"

#define SLEEP_TIME 5000

Scheduler sched;
Task* calculateFrequency;
Task* timerTask;
Task* sendToSerial;
Task* readyTask;
Task* sleepingTask;

void setup() {
  State state = READY;
  Serial.begin(9600);
  sched.init(100);
  createTasks();
  initTasks();
  addTasks();
 }
 
void loop() {
  sched.schedule();
  Serial.println(state);
}

void createTasks(){

  calculateFrequency = new CalculateFrequencyTask();
  timerTask = new TimerTask();
  readyTask = new ReadyTask(calculateFrequency,timerTask);
  sleepingTask = new SleepingTask();
}

void initTasks(){
  calculateFrequency -> init(300);
  timerTask -> init(200);
  readyTask->init(100);
  sleepingTask -> init(500);
}

void addTasks(){
  sched.addTask(calculateFrequency);
  sched.addTask(timerTask);
  sched.addTask(readyTask);
  sched.addTask(sleepingTask);
}
