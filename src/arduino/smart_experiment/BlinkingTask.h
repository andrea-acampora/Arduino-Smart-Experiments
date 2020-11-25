#ifndef __BLINKINGTASK__
#define __BLINKINGTASK__

#include "Task.h"
#include "Light.h"

class BlinkingTask: public Task {
  
public:
  BlinkingTask(Light* led);  
  void setActive(bool active);
  void tick();

private:
	
  Light* led;
  enum { ON, OFF } state;

};

#endif
