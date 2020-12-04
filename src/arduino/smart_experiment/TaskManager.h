#ifndef __TASKMANAGER__
#define __TASKMANAGER__

#include "Task.h"
#include "SystemFlag.h"

/**
 * The manager of current macro-task in execution.
 * It continuosly check the state of macro-task in execution and , when it will be disabled, it will start the following one.
 * It's active during all the program execution.
 */
class TaskManager: public Task {
  
public:
  TaskManager(Task* readyTask, Task* inExecutionTask, Task* abortedTask,Task* terminatedTask );
  void init(int period);  
  void tick();

private:
	
  Task* readyTask;
  Task* inExecutionTask;
  Task* abortedTask;
  Task* terminatedTask;

  Task* currentTask;
  
  enum { START , ON } state;

};

#endif
