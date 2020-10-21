#include "AxisPing.h"


AxisPing::AxisPing(int triggerPin, int echoPin, int maxDistance){
 sonar = new NewPing(triggerPin, echoPin, maxDistance);
}

void AxisPing::readPing() {
    int uS = sonar->ping();
    if (uS == 0) over = false;
    else over = true;
    uS = constrain(uS, MIN_DISTANCE * 50, MAX_DISTANCE * 50);
    uS = map(uS, MIN_DISTANCE * 50, MAX_DISTANCE * 50, 0, 1000);
    ultraReading = uS;
}

bool AxisPing::isOver(){
  return over;
}

int AxisPing::ping(){
  return ultraReading;
}