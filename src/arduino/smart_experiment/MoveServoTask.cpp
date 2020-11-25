#include "Arduino.h"
#include "MoveServoTask.h"
#include "Globals.h"


void MoveServoTask::init(int period){
    servo = new ServoMotor(SERVO_PIN); 
}

void MoveServoTask::tick(){
    servo->on(); 
    setServo(); 
    servo->off();     
}

void MoveServoTask::setServo(){
    //accede alle variabile velocità per settare l'angolo
    float speed = 30; //a caso
    //mappa per decidere la posizione, l'angolo max è 180 gradi
    int angle = map(speed, 1, MAXVEL, 0, MAXANGLE);
    servo->setPosition(angle); 
}
