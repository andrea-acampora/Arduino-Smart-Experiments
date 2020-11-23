#ifndef __PIR__
#define __PIR__

class Pir{
    public:
        Pir(int pin); 
        bool isDetected();
        int getPin(); 
    private:
        int pin; 
}; 

#endif
