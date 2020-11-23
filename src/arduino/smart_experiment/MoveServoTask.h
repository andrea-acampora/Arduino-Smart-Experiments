#ifndef __MOVESERVOTASK__
#define __MOVESERVOTASK__
#include "ServoMotor.h"
#include "Task.h"

#define MAXVEL 80 //a caso
#define MAXANGLE 180
#define SERVO_PIN 3

class MoveServoTask : public Task{
    
    ServoMotor* servo; 
    public:
        void init(int period); 
        void tick(); 
        void setServo(); 
}; 

#endif