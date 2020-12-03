#ifndef __INEXECUTIONTASK__
#define __INEXECUTIONTASK__

#include "Task.h"
#include "CheckButtonTask.h"
#include "Light.h"
#include "Pot.h"
#include "Sonar.h"
#include "ServoMotor.h"
#include "Button.h"
#include "Temp.h"
#include "Globals.h"
#include "SystemFlag.h"
#include "Arduino.h"
#include "MsgService.h"

#define MAX_TIME 20000

/**
 * Task which represent the main actions of object's tracking during the experiment.
 * It's activated from the task manager when user press the ready button.
 */

class InExecutionTask: public Task {

    Light* led_2;
    Pot* pot;
    Sonar* sonar;
    ServoMotor* servo;
    Temp* temp;
    Button* button_stop;

    Task* checkButtonStopTask;

    enum { ENTRY, TRACKING, OVER} state; 
    int frequency;
    float position;
    float old_position;
    float speed;
    float acceleration;
    unsigned long start_time;
    unsigned long old_t;

    int readFrequency();
    bool isTimeExpired();
    bool isButtonStopPressed();
    void checkTime();
    int arrotonda(float number);
    void calculatePosition();
    void processData();
    void moveServo();
    void sendToSerial();
    
public:

  InExecutionTask(Light* led_2, Pot* pot, Sonar* sonar, ServoMotor* servo, Temp* temp, Task* checkButtonStopTask);  
  void init(int period);  
  void tick();
  
};


#endif
