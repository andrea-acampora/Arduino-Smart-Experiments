#ifndef __TASKMANAGER__
#define __TASKMANAGER__

#include "Task.h"

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
  
  enum { ENTRY , ON } state;

};

#endif
