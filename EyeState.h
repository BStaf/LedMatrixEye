#define WAKE_UP 2
#define GO_TO_SLEEP 1
#define SLEEP 0
#define LOOK_AROUND 3
#define LOOK_WACKY 4
#define GET_NERVOUS 5
#define FREAK_OUT 6

int getEyeState(int pingPin, int curState, Animation *animation){
  int inchesToWakeUp = 30;
  int inchesToNervous = 20;
  int inchesToWacky = 10;
  int InchesToFreakOut = 5;

  int curInches = GetInchesDebounce(pingPin,1000);

  //nobody near handle sleeping
  if (curInches > inchesToWakeUp){
    if (curState == SLEEP)
      return SLEEP;
    else if ((curState == GO_TO_SLEEP)&&(animation->Complete))
      return SLEEP;
    else
      return GO_TO_SLEEP;
  }
  //detected something handle awake states
  else{
    if ((curInches < InchesToFreakOut)&&(animation->Complete))
      return FREAK_OUT;
    if ((curInches < inchesToWacky)&&(animation->Complete))
      return LOOK_WACKY;
    if ((curInches < inchesToNervous)&&(animation->Complete))
      return GET_NERVOUS;
    if (animation->Complete)
      return LOOK_AROUND;
  }
  //nothing triggered return current state
  return curState;
}
