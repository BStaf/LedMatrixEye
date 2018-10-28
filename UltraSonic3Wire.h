//int currentMS;
unsigned long lastUSReadTime=0;// = millis();
long usReadCnt=0;
long usReadAcc=0;
long usLastRead = 999;

long GetRawDistance(int pingPin){
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  // convert the time into a distance
  return pulseIn(pingPin, HIGH);
}

long GetInches(int pingPin){
    return GetRawDistance(pingPin)  / 74 / 2;
}
long GetDistanceDelayed(int pingPin, int msPerRead){
    unsigned long curTime = millis();

    if ((curTime - lastUSReadTime) > msPerRead){
        usLastRead = GetRawDistance(pingPin);
        lastUSReadTime = curTime;
    }
    return usLastRead;
}
long GetDistanceDebounce(int pingPin, int msPerRead){
    unsigned long curTime = millis();
    usReadAcc += GetRawDistance(pingPin);
    usReadCnt++;
    //get average
    if ((curTime - lastUSReadTime) > msPerRead){
        usLastRead = usReadAcc/usReadCnt;
        usReadAcc = usReadCnt = 0;
        lastUSReadTime = curTime;
    }
    return usLastRead;
}
