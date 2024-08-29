#include <MotorDriver.h>

// Change the following state if any of the motors is running in the opposite direction
bool motorAdir = true;
bool motorBdir = true;

#define pwma 2
#define pwmb 4
#define ina1 6
#define ina2 7
#define inb1 5
#define inb2 3

int motor_pins[6] = {pwma, ina1, ina2, pwmb, inb1, inb2};
MotorDriver motor(motor_pins);

void setup() {
  motor.begin();
}

void loop() {
  motor.motor(255, 255, motorAdir, motorBdir);  // Forward direction for both motors at full speed
  delay(1000);
  
  motor.motor(255, 255, !motorAdir, !motorBdir);  // Reverse direction for both motors at full speed
  delay(1000);
}
