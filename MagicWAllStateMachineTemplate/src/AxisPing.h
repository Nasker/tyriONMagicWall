#include <NewPing.h>
#include <Arduino.h>
#include "constants.h"

class AxisPing{
  NewPing* sonar;
  int ultraReading;
  boolean over;

  public:
    AxisPing();
    void readPing();
    bool isOver();
    int ping();
};