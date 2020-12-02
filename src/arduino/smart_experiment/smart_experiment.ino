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
#include "AbortedTask.h"
#include "TerminatedTask.h"
#include "BlinkingTask.h"
#include "Globals.h"
#include "Button.h"
#include "Pir.h"
#include "Pot.h"
#include "ServoMotor.h"
#include "Temp.h"
#include "Light.h"
#include "Led.h"
#include "Sonar.h"
#include "MsgService.h"
#include "TaskManager.h"
#include "CheckButtonTask.h"


Scheduler sched;

TaskManager* taskManager;

Task* blinkingTask;
Task* checkButtonStartTask;
Task* checkButtonStopTask;
Task* readyTask;
Task* inExecutionTask;
Task* abortedTask;
Task* terminatedTask;


Light* led_1;
Light* led_2;
Button* button_start;
Button* button_stop;
Pir* pir;
Pot* pot;
Sonar* sonar;
ServoMotor* servo;
Temp* temp;

void setup() {
  sched.init(40);
  createComponents();
  createTasks();
  initTasks();
  addTasks();
 }
 
void loop() {
  sched.schedule();
}

void createTasks(){
  blinkingTask = new BlinkingTask(led_2);
  checkButtonStartTask = new CheckButtonTask(button_start);
  checkButtonStopTask = new CheckButtonTask(button_stop);
  readyTask = new ReadyTask(led_1,checkButtonStartTask,pir);
  inExecutionTask = new InExecutionTask(led_2, pot, sonar, servo, temp, checkButtonStopTask); 
  abortedTask = new AbortedTask(blinkingTask);
  terminatedTask = new TerminatedTask(blinkingTask);
  taskManager = new TaskManager(readyTask, inExecutionTask, abortedTask, terminatedTask);
}

void createComponents(){
  MsgService.init();
  led_1 = new Led(PIN_LED_1);
  led_2 = new Led(PIN_LED_2);
  button_start = new Button(PIN_BUTTON_START);
  button_stop = new Button(PIN_BUTTON_STOP);
  pir = new Pir(PIN_PIR);
  pot = new Pot(PIN_POT);
  sonar = new Sonar(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN);
  servo = new ServoMotor(PIN_SERVO);
  temp = new Temp(PIN_TEMP);
}

void initTasks(){
  blinkingTask -> init(120);
  checkButtonStartTask -> init(40);
  checkButtonStopTask -> init(40);
  readyTask -> init(120);
  inExecutionTask -> init(40);
  abortedTask -> init(200); 
  terminatedTask -> init(200);
  taskManager -> init(40);
  taskManager -> setActive(true);
}


void addTasks(){
  sched.addTask(taskManager);
  sched.addTask(checkButtonStartTask);
  sched.addTask(checkButtonStopTask);
  sched.addTask(inExecutionTask);
  sched.addTask(readyTask);
  sched.addTask(abortedTask);
  sched.addTask(terminatedTask);
  sched.addTask(blinkingTask);
}
