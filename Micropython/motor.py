from machine import Pin, PWM

class Motor:
    def __init__(self, mpin, motor_A_direction=0, motor_B_direction=0):
        self.mpin = mpin
        self.motor_A_direction = motor_A_direction
        self.motor_B_direction = motor_B_direction
        self.pin_define()

        # Initialize PWM for speed control
        self.pwm_A = PWM(Pin(self.mpin[0]))
        self.pwm_B = PWM(Pin(self.mpin[5]))

        for pin in self.mpin:
            Pin(pin, Pin.OUT)

    def pin_define(self):
        if self.motor_A_direction:
            self.mpin[1], self.mpin[2] = 5, 4
        else:
            self.mpin[1], self.mpin[2] = 4, 5

        if self.motor_B_direction:
            self.mpin[3], self.mpin[4] = 7, 8
        else:
            self.mpin[3], self.mpin[4] = 8, 7

    def motor(self, speedA, speedB, directionA=True, directionB=True):
        # Set direction for Motor A
        Pin(self.mpin[1], Pin.OUT).value(directionA)
        Pin(self.mpin[2], Pin.OUT).value(not directionA)

        # Set direction for Motor B
        Pin(self.mpin[3], Pin.OUT).value(directionB)
        Pin(self.mpin[4], Pin.OUT).value(not directionB)

        # Set speed (duty cycle)
        self.pwm_A.duty(abs(speedA))
        self.pwm_B.duty(abs(speedB))

