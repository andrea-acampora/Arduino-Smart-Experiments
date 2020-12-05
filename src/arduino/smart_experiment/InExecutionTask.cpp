#include "InExecutionTask.h"
/**
 * Task which represent the main actions of object's tracking during the experiment.
 * It's activated from the task manager when user press the ready button.
 */
 
InExecutionTask::InExecutionTask(Light* led_2, Pot* pot, Sonar* sonar, ServoMotor* servo, Temp* temp, Task* checkButtonStopTask){
  this -> led_2 = led_2;
  this -> pot = pot;
  this -> sonar = sonar;
  this -> servo = servo;
  this -> temp = temp;
  this -> checkButtonStopTask = checkButtonStopTask;
 }

void InExecutionTask::init(int period){
  Task::init(period);
  state = START;
}

void InExecutionTask::tick(){
  
  switch(state){
    
    case START:
      experiment_aborted = false;
      if (this -> sonar -> isObjectDetected(this -> temp -> getTemperature())){ //Checking if sonar detects something at the start of the experiment.
        MsgService.sendMsg("State=IN_EXECUTION");
        this -> checkButtonStopTask -> setActive(true);
        this -> led_2 -> switchOn();
        this -> frequency = this -> readFrequency(); //Reading the frequency from the pot.
        this -> frequency  %2 == 0 ? this -> frequency -= 1 : this -> frequency;
        this -> setPeriod(1000/MAXFREQ * (MAXFREQ - this -> frequency +1)); //Setting the period of the task with multiples of the scheduler period (40);
        this -> servo -> on();
        this -> start_time = millis();
        this -> old_t = millis();
        this -> calculatePosition();
        this -> old_position = position;
        this -> state = TRACKING;
      }else {
        experiment_aborted = true;
        this -> state = OVER;
      }
      break;

    case TRACKING:
      if (!this -> isTimeExpired() && !this->isButtonStopPressed()){//Checking if the experiment is over.
        this -> calculatePosition();
        this -> processData();
        this -> moveServo();
        this -> sendToSerial();
      } else {
         state = OVER;
      }
      break;

    case OVER:
      this -> servo -> off();
      state = START;
      this -> setActive(false);
      break;
  }
}

int InExecutionTask::readFrequency(){
  int value = this -> pot -> getValue();
  return  map(value, 0, 1023 , MINFREQ, MAXFREQ);
}

bool InExecutionTask::isTimeExpired(){
  return millis() - this -> start_time >= MAX_TIME;
}

void InExecutionTask::calculatePosition(){
  this -> position = this -> sonar -> getDistance(this -> temp -> getTemperature());
}

/**
 * The main method of the experiment.
 * It calculates speed and acceleration every tick of the task.
 */
void InExecutionTask::processData(){
  float old_speed = this -> speed;
  unsigned long t = millis();
  float delta_position = abs(this -> old_position - this -> position);
  float delta_t = (t - this -> old_t) / float(1000);
  this -> speed = delta_position / delta_t;
  float delta_speed = abs(old_speed - this -> speed);
  this -> acceleration = delta_speed / delta_t;
  this -> old_t = t;
  this -> old_position = this -> position;

}

/**
 * Method that round the speeed for setting it to the Servo.
 */
int InExecutionTask::arrotonda(float number){
  int resto = (number - int(number))*100;
  return resto > 50 ? ceil(number) : floor(number);
}

/**
 * Move the servo-motor depending on the speed. 
 */
void InExecutionTask::moveServo(){
    if(this -> position < MAX_OBJECT_DISTANCE) {
    int servo_pos = map(arrotonda(this->speed),0,  MAX_VEL, 0 , MAX_ANGLE);
    this -> servo -> setPosition(constrain(servo_pos,0,MAX_ANGLE));
    }
}

void InExecutionTask::sendToSerial(){
  if(this -> position < MAX_OBJECT_DISTANCE) {
    MsgService.sendMsg(String("Pos=") + this -> position);
    MsgService.sendMsg(String("Speed=") + this -> speed);
    MsgService.sendMsg(String("Acc=") + this -> acceleration);
  } else{
    MsgService.sendMsg(String("DATA_ERROR"));
  }
}

bool InExecutionTask::isButtonStopPressed(){
  return !this -> checkButtonStopTask -> isActive();
}
