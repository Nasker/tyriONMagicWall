#include <Arduino.h>
#include "functionsHeaders.h"
#include "States.h"
#include "AxisPing.h"

int state = IDLE;
uint32_t ellapsedTime = 0;
int taskTime = 2000;
AxisPing distanceSens;

void setup() {
  Serial.begin(115200);
  ellapsedTime = millis();
  state = IDLE;
}

void loop() {
  distanceSens.readPing();
  Serial.println(distanceSens.ping());
  stateMachine();
  delay(20);
}

void stateMachine(){
  switch(state){
    case IDLE:
      if(distanceSens.isOver()){
        state = PLAYING;
        Serial.println("\t\tSwitching to PLAYING STATE");
        delay(1000);
      }
      break;
    case PLAYING:
      if(distanceSens.ping() > 100){
        state = ENDING;
        Serial.println("\t\tSwitching to ENDING STATE");
        delay(1000);
      }
      break;
    case ENDING:
      if(!distanceSens.isOver()){
        state = IDLE;
        Serial.println("\t\tSwitching to IDLE STATE");
        delay(1000);
      }
      break;
  } 
}