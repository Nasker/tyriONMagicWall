#include <Arduino.h>
#include "functionsHeaders.h"
#include "States.h"

int state = IDLE;
uint32_t ellapsedTime = 0;
int taskTime = 2000;

void setup() {
  Serial.begin(115200);
  ellapsedTime = millis();
  state = IDLE;
}

void loop() {
  stateMachine();
}

void stateMachine(){
  switch(state){
    case IDLE:
      if(ellapsedTime + taskTime < millis()){
        ellapsedTime = millis();
        state = PLAYING;
        Serial.println("Switching to PLAYING STATE");
      }
      break;
    case PLAYING:
      if(ellapsedTime + taskTime < millis()){
        ellapsedTime = millis();
        state = ENDING;
        Serial.println("Switching to ENDING STATE");
      }
      break;
    case ENDING:
      if(ellapsedTime + taskTime < millis()){
        ellapsedTime = millis(); 
        state = IDLE;
        Serial.println("Switching to IDLE STATE");
      }
      break;
  } 
}