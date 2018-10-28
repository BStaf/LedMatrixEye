#define WAKE_UP 2
#define GO_TO_SLEEP 1
#define SLEEP 0
#define LOOK_AROUND 3
#define LOOK_WACKY 4
#define GET_NERVOUS 5
#define FREAK_OUT 6

int inchesToPingMore = 9 * 12 * 72 * 2;
int inchesToWakeUp = 6 * 12 * 74 * 2;
int inchesToNervous = (3.5 * 12) * 74 * 2;
int inchesToWacky = (2.5 * 12) * 74 * 2;
int InchesToFreakOut = 15 * 74 * 2;

int getEyeState(int pingPin, int curState, Animation *animation){
  int pingTime = 1000;
  if (curState == SLEEP)
    pingTime = 2500;
  int curInches = GetDistanceDelayed(pingPin,pingTime);
  //Serial.print(curInches);
  //nobody near handle sleeping
  if (curInches > inchesToWakeUp){
    //Serial.write("sleep\n");
    if (curState == SLEEP)
      return SLEEP;
    else if ((curState == GO_TO_SLEEP)&&(animation->Complete))
      return SLEEP;
    else
      return GO_TO_SLEEP;
  }
  //detected something handle awake states
  else{
    if (curState == SLEEP)
      return WAKE_UP;
    //Serial.write("wake\n");
    if ((curInches < InchesToFreakOut)&&(animation->Complete))
      return FREAK_OUT;
    if ((curInches < inchesToWacky)&&(animation->Complete))
      return LOOK_WACKY;
    if ((curInches < inchesToNervous)&&(animation->Complete))
      return GET_NERVOUS;
    if (animation->Complete)
      return LOOK_AROUND;
  }
  //Serial.write("LastState\n");
  //nothing triggered return current state
  return curState;
}
