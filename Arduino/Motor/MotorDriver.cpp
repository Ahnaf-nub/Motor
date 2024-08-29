#include "MotorDriver.h"

MotorDriver::MotorDriver(int mpin_pins[6], bool motor_A_dir, bool motor_B_dir) {
  for (byte i = 0; i < 6; i++) mpin[i] = mpin_pins[i];
  motor_A_direction = motor_A_dir;
  motor_B_direction = motor_B_dir;
}

void MotorDriver::begin() {
  pin_define();
  for (byte i = 0; i < 6; i++) pinMode(mpin[i], OUTPUT);
}

void MotorDriver::pin_define() {
  (motor_A_direction) ? mpin[1] = 5 : mpin[1] = 4;
  (motor_A_direction) ? mpin[2] = 4 : mpin[2] = 5;
  (motor_B_direction) ? mpin[3] = 7 : mpin[3] = 8;
  (motor_B_direction) ? mpin[4] = 8 : mpin[4] = 7;
}

void MotorDriver::motor(int speedA, int speedB, bool directionA, bool directionB) {
  if (directionA) {
    digitalWrite(mpin[1], HIGH);
    digitalWrite(mpin[2], LOW);
  } else {
    digitalWrite(mpin[1], LOW);
    digitalWrite(mpin[2], HIGH);
  }
  if (directionB) {
    digitalWrite(mpin[3], HIGH);
    digitalWrite(mpin[4], LOW);
  } else {
    digitalWrite(mpin[3], LOW);
    digitalWrite(mpin[4], HIGH);
  }
  
  analogWrite(mpin[0], abs(speedA));
  analogWrite(mpin[5], abs(speedB));
}
