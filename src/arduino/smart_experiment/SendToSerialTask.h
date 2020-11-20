#ifndef __SENDTOSERIALTASK__
#define __SENDTOSERIALTASK__

#include "Task.h"
#include "Arduino.h"

class SendToSerialTask: public Task {

  String value;


public:

  SendToSerialTask();  
  void setValue(String value);
  void init(int period);  
  void tick();
};


#endif
