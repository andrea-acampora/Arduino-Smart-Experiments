#ifndef __MOVESERVOTASK__
#define __MOVESERVOTASK__
#include "ServoMotor.h"
#include "Task.h"

class MoveServoTask : public Task{
    
    ServoMotor* servo; 
    public:
        void init(int period); 
        void tick(); 
        void setServo(); 
}; 

#endif
