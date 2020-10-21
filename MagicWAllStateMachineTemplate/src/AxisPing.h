#include <NewPing.h>
#include <Arduino.h>

class AxisPing{
  NewPing* sonar;
  int ultraReading;
  boolean over;

  public:
    AxisPing(int triggerPin, int echoPin, int maxDistance);
    void readPing();
    bool isOver();
    int ping();
};