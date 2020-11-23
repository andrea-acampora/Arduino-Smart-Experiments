#ifndef __PROCESSDATATASK__
#define __PROCESSDATATASK__

#include "Task.h"

class ProcessDataTask : public Task{
    float acceleration;
    float speed; 

    public:
        void init(int period); 
        void tick(); 
        float getSpeed(); 
        float getAcceleration();
}; 

#endif