#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class MotorDriver {
  public:
    Motor(int mpin[6], bool motor_A_direction = 0, bool motor_B_direction = 0);
    void begin();
    void motor(int speedA, int speedB, bool directionA = true, bool directionB = true);
  private:
    void pin_define();
    int mpin[6];
    bool motor_A_direction;
    bool motor_B_direction;
};

#endif
