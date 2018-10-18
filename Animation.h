
#ifndef Animation_h
#define Animation_h

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
    
    void runUpdateAnimation();
    
  public:
    bool Complete;
    byte * CurrentViewMatrix;
    Animation(int animationSteps, byte * viewMatrix, byte * maskMatrix, long speed);
    void Update();
    void Reset();
};

#endif