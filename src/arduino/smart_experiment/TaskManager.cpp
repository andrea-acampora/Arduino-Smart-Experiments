#include "TaskManager.h"
#include "Arduino.h"

TaskManager::TaskManager(Task* readyTask, Task* inExecutionTask, Task* abortedTask,Task* terminatedTask){ 
 this -> readyTask = readyTask;
 this -> inExecutionTask = inExecutionTask;
 this -> abortedTask = abortedTask;
 this -> terminatedTask  = terminatedTask;
}
  
void TaskManager::init(int period){
  Task::init(period);
  state = START;
}
  
void TaskManager::tick(){
  switch (state){
    case START:
      this -> currentTask = this -> readyTask;
      this -> currentTask -> setActive(true);
      state = ON;
      break;

    case ON:
      if(!this -> currentTask -> isActive()){
        if(this -> currentTask == this -> readyTask){
          this -> currentTask = inExecutionTask;
        }
        else if ( this -> currentTask == this -> inExecutionTask ){
          experiment_aborted ? this -> currentTask = this -> abortedTask : this -> currentTask = this -> terminatedTask;
        }
        else if(this -> currentTask == this -> abortedTask || this -> currentTask == this -> terminatedTask){
          this -> currentTask = this -> readyTask;
        }
        this -> currentTask -> setActive(true);
      }
      break;
  }
}
