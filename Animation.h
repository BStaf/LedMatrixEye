#ifndef Animation_h
#define Animation_h

typedef unsigned char byte;

#include "Arduino.h"

class Animation
{
  private:
    int _animationSteps;
    int _currentStep;
    long _speed; //in ms
    byte * _viewMatrix;
    byte * _maskMatrix;
    unsigned long _lastTime;
//    unsigned long millis();
    
    void runUpdateAnimation();
    
  public:
    bool Complete;
    unsigned long CurMS;
    byte * CurrentViewMatrix;
    Animation(byte * viewMatrix, byte * maskMatrix, long speed);
    void Update();
    void Reset();
};

#endif
