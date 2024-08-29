from motor import Motor

# Define motor pins
motor_pins = [2, 6, 7, 4, 5, 3]
# Change state to change the rotattion of motor
motorAdir = False
motorBdir = True
# Initialize MotorDriver instance
motor_driver = Motor(motor_pins)

# Example usage in the main loop
while True:
    motor_driver.motor(512, 512, motorAdir, motorBdir)  # Forward direction for both motors
    time.sleep(1)
    motor_driver.motor(512, 512, motorAdir, motorAdir)  # Reverse direction for both motors
    time.sleep(1)
