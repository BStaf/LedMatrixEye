#include "Arduino.h"

#include "Animation.h"

Animation::Animation(byte * viewMatrix, byte * maskMatrix, long speed)
{
  _animationSteps = viewMatrix[0];
  _viewMatrix = viewMatrix;
  _maskMatrix = maskMatrix;
  _speed = speed;
  _lastTime = 0;
  CurrentViewMatrix = _viewMatrix+1;
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
  Complete = false;
  CurrentViewMatrix = _viewMatrix+1; 
}
void Animation::runUpdateAnimation(){
  if (Complete)
    return;
  if (_currentStep >= _animationSteps)
    Complete = true;
  CurrentViewMatrix = _viewMatrix + (_currentStep * sizeof(byte)*8)+1;
  _currentStep++;
  
}

/*unsigned long Animation::millis(){
	return CurMS;
}*/
