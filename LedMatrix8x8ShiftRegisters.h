#ifndef LedMatrix8x8ShiftRegisters_h
#define LedMatrix8x8ShiftRegisters_h


#include "Arduino.h"

class LedMatrix8x8ShiftRegisters
{
  private:
  //Pin connected to ST_CP of 74HC595
    int _latchPin = 3;
    //Pin connected to SH_CP of 74HC595
    int _clockPin = 2;
    //Pin connected to DS of 74HC595
    int _dataPin = 4;
    
  public:
    LedMatrix8x8ShiftRegisters(int latchPin, int clockPin, int dataPin);
    void Draw(byte* picAr);//array of 8 bytes 
};

#endif
