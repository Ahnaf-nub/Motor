#include <Motor.h>
// change the following state if any of the motor is running in hte opposite direction
bool motorAdir = true;
bool motorBdir = true;

int motor_pins[6] = {2, 6, 7, 4, 5, 3};
Motor motor(motor_pins);

void setup() {
  motor.begin();
}

void loop() {
  motor.motor(255, 255, motorAdir, motorBdir); // Forward direction for both motors at full speed
  delay(1000);
  motor.motor(255, 255, !motorAdir, !motorBdir); // Forward direction for both motors at full speed
  delay(1000);
}
