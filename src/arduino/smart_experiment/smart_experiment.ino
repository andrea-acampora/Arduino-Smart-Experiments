/*
 * " Smart-Experiment " - Sistemi Embedded & IoT course of Unibo.
 * 
 * Acampora Andrea
 * Accursi Giacomo 
 */
 
#include "Arduino.h"
#include "Scheduler.h"
#include "Task.h"
#include "ReadyTask.h"
#include "InExecutionTask.h"
#include "BlinkingTask.h"
#include "Globals.h"
#include "Button.h"
#include "Pir.h"
#include "Light.h"
#include "Led.h"
#include "MsgService.h"
#include "TaskManager.h"


Scheduler sched;

TaskManager* taskManager;

Task* blinkingTask;
Task* readyTask;
Task* inExecutionTask;
Task* abortedTask;
Task* terminatedTask;



Light* led_1;
Light* led_2;
Button* button_start;
Button* button_stop;
Pir* pir;

void setup() {
  sched.init(1000/MAXFREQ);
  createComponents();
  createTasks();
  initTasks();
  addTasks();
  Serial.begin(9600);
 }
 
void loop() {
  sched.schedule();
}

void createTasks(){
  blinkingTask = new BlinkingTask(led_2);;
  readyTask = new ReadyTask(led_1,button_start,pir);
  inExecutionTask = new InExecutionTask();// ATTENZIONE
  abortedTask = new ReadyTask(led_1,button_start,pir); // ATTENZIONE
  terminatedTask = new ReadyTask(led_1,button_start,pir); // ATTENZIONE
  taskManager = new TaskManager(readyTask, inExecutionTask, abortedTask, terminatedTask);
}

void createComponents(){
  MsgService.init();
  led_1 = new Led(PIN_LED_1);
  led_2 = new Led(PIN_LED_2);
  button_start = new Button(PIN_BUTTON_START);
  button_stop = new Button(PIN_BUTTON_STOP);
  pir = new Pir(PIN_PIR);
}

void initTasks(){
  blinkingTask -> init(500);
  readyTask -> init(100);
  inExecutionTask -> init(200);
  abortedTask -> init(200);
  terminatedTask -> init(200);
  taskManager -> init(20);
  taskManager -> setActive(true);
}


void addTasks(){
  sched.addTask(taskManager);
  sched.addTask(blinkingTask);
  sched.addTask(readyTask);
  sched.addTask(inExecutionTask);
}
