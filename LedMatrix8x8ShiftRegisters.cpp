#include "Arduino.h"

#include "LedMatrix8x8ShiftRegisters.h"

LedMatrix8x8ShiftRegisters::LedMatrix8x8ShiftRegisters(int latchPin, int clockPin, int dataPin)
{
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin = dataPin;
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_dataPin, OUTPUT);
}

void LedMatrix8x8ShiftRegisters::Draw(byte* picAr){
  byte commonTrigger = 0;
  for (int i = 0; i < 8; i++) {
    commonTrigger = ~(1 << i);  
    digitalWrite(_latchPin, LOW);
    //delay(1);
    shiftOut(_dataPin, _clockPin, MSBFIRST, commonTrigger);  
    shiftOut(_dataPin, _clockPin, LSBFIRST, picAr[i]);
    digitalWrite(_latchPin, HIGH);
  }
}

