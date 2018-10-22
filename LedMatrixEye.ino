//**************************************************************//
//  Name    : LedMatrixEye                              
//  Author  : Bill S.                                          
//  Notes   : Drives one LedMtrix based on ultrasonic sensor    
//          : Will show eye animations based on distance                       
//****************************************************************
#include "Animation.h"
#include "AnimationSetup.h"
#include "LedMatrix8x8ShiftRegisters.h"
#include "UltraSonic3Wire.h"
#include "EyeState.h"
//Pin connected to ST_CP of 74HC595
int latchPin = 3;
//Pin connected to SH_CP of 74HC595
int clockPin = 2;
////Pin connected to DS of 74HC595
int dataPin = 4;

int pingPin = 13;

int state;
LedMatrix8x8ShiftRegisters *ledMatrix;
Animation *an;
Animation *anWakeUp;
Animation *anLookLR;
Animation *anRoll;
Animation *anBlinkX;
Animation *anSleep;
Animation *anGoToSleep;
Animation *anWacky;
                        
void setup() {
  ledMatrix = new LedMatrix8x8ShiftRegisters(latchPin, clockPin, dataPin);

  anWakeUp = new Animation(OpenEyeMatrix, 0, 160);
  anLookLR = new Animation(LREyeMatrix, 0, 150);
  anRoll = new Animation(RollEyeMatrix, 0 , 80);
  anBlinkX = new Animation(BlinkXMatrix, 0, 200);
  anSleep = new Animation(SleepMatrix, 0, 100);
  anGoToSleep = new Animation(CloseEyeMatrix, 0, 160);
  anWacky = new Animation(CrazyEyeMatrix,0,80);
  an = anWakeUp;
  an->Update();
  state = 0;
}

void loop() {
  state = getEyeState(pingPin, state, an);

  if (an->Complete)
    an->Reset();

  an = getAnimationForState(state);
  
  ledMatrix->Draw(an->CurrentViewMatrix);  
  an->Update();
  delay(1);
}

Animation * getAnimationForState(int state){
  switch(state){
    case SLEEP:
      return anSleep;
    case GO_TO_SLEEP:
      return anGoToSleep;
    case WAKE_UP: 
      return anWakeUp;
    case LOOK_AROUND:
      return anLookLR;
    case LOOK_WACKY:
      return anWacky;
    case GET_NERVOUS:
      return anRoll;
    case FREAK_OUT:
      return anBlinkX;
  }
  //this shouldn't happen
  return anSleep;
}

