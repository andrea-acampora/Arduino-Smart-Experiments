#ifndef __CHECKBUTTONTASK__
#define __CHECKBUTTONTASK__

#include "Task.h"
#include "Button.h"

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
