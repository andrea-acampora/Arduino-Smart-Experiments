#ifndef __CHECKBUTTONTASK__
#define __CHECKBUTTONTASK__

#include "Task.h"
#include "Button.h"

/**
 * This task is used to check if user press a button without using interrupts.
 * It's activated from any Macro task which needs it.
 */
class CheckButtonTask: public Task {
  
public:
  CheckButtonTask(Button* button); 
  void init(int period); 
  void tick();

private:
	
  Button* button;
  enum { ON, OFF } state;
};

#endif
