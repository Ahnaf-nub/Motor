#include <Motor.h>

bool motorAdir = False;
bool motorBdir = True;

int motor_pins[6] = {2, 6, 7, 4, 5, 3};
Motor motor(motor_pins);

void setup() {
  motor.begin();
}

void loop() {
  motor.motor(255, 255, motorAdir, motorBdir); // Forward direction for both motors at full speed
  delay(1000);
}
