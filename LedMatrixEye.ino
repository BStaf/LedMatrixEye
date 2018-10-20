//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************
#include "Animation.h"
#include "AnimationSetup.h"
//Pin connected to ST_CP of 74HC595
int latchPin = 3;
//Pin connected to SH_CP of 74HC595
int clockPin = 2;
////Pin connected to DS of 74HC595
int dataPin = 4;

int state = 0;
/*
byte LedMatrix[8] = {   B00111100, 
                        B01000010,
                        B10000001,
                        B10011001,
                        B10011001,
                        B10000001,
                        B01000010,
                        B00111100 };
*/
Animation *an;
Animation *anWakeUp;
Animation *anLookLR;
Animation *anRoll;
Animation *anBlinkX;
                        
void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i=5; i<=12;i++){
    pinMode(i, OUTPUT);
  }
  anWakeUp = new Animation(OpenEyeMatrix, 0, 150);
  anLookLR = new Animation(LREyeMatrix, 0, 150);
  anRoll = new Animation(RollEyeMatrix, 0 , 80);
  anBlinkX = new Animation(BlinkXMatrix, 0, 200);
  an = anWakeUp;
  an->Update();
}

void loop() {
  if (an->Complete){
    state++;
    switch(state){
      case 1:
        an = anLookLR;
        break;
      case 2:
        an = anRoll;
        break;
      case 3:
        an = anLookLR;
        break;
      case 4:
        an = anBlinkX;
        break;
      case 5:
        an = anBlinkX;
        break;
      case 6:
        an = anBlinkX;
        break;
      case 7:
        an = anBlinkX;
        break;
      default:
        state=0;
        an = anWakeUp;
        break;
    }
    an->Reset();
  }
  draw(an->CurrentViewMatrix);  
  an->Update();
}


void draw(byte* picAr){
  byte commonTrigger = 0;
  for (int i = 0; i < 8; i++) {
    commonTrigger = ~(1 << i);  
    digitalWrite(latchPin, LOW);
    delay(1);
    setCommonPin(i);
    shiftOut(dataPin, clockPin, LSBFIRST, picAr[i]);  
    digitalWrite(latchPin, HIGH);
    delay(1);
  }
}
void setCommonPin(int row){
  for (int i=0;i<8;i++){
    if (i == row)
      digitalWrite(i+5,LOW);
    else
      digitalWrite(i+5,HIGH);
  } 
}

