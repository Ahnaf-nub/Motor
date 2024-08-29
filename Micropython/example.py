from motor import Motor

# Define motor pins
pwma = 2
pwmb = 4
ina1 = 6
ina2 = 7
inb1 = 5
inb2 = 3
motor_pins = [pwma, ina1, ina2, pwmb, inb1, inb2]

# Change state to change the rotation of motor
motorAdir = True
motorBdir = True
# Initialize MotorDriver instance
motor_driver = Motor(motor_pins)

# Example usage in the main loop
while True:
    motor_driver.motor(512, 512, motorAdir, motorBdir)  # Forward direction for both motors
    time.sleep(1)
    motor_driver.motor(512, 512, not motorAdir, not motorAdir)  # Reverse direction for both motors
    time.sleep(1)
