#include "Arduino.h"
#include "Timer.h"

#include "Animation.h"

Animation::Animation(int animationSteps, byte * viewMatrix, byte * maskMatrix, long speed)
{
  _animationSteps = animationSteps;
  _viewMatrix = viewMatrix;
  _maskMatrix = maskMatrix;
  _speed = speed;

  Reset();
}

void Animation::Update(){
  unsigned long curTime = millis();
  //check if time to update
  if ((curTime-_lastTime) >= _speed){
    runUpdateAnimation();
    _lastTime = curTime;
  }
}
void Animation::Reset(){
  _currentStep = 0;
  _lastTime = 0;
  Complete = false;
}
void Animation::runUpdateAnimation(){
  if (Complete)
    return;
  
  CurrentViewMatrix = _viewMatrix + (_currentStep * sizeof(byte));
  if (++_currentStep > _animationSteps)
    Complete = true;
}
