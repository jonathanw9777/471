from Adafruit_PWM_Servo_Driver import PWM
import time

# Initialize the PWM device using the default address
pwm = PWM(0x40)
frequency = 100

def setPWM(channel, frequency, pwmMicroseconds):
    pulseLength = float(1000000)                   # 1,000,000 us per second
    pulseLength /= frequency                       
    pulseLength /= 4096                     # 12 bits of resolution
    pulse /= pulseLength
    pwmMicroseconds.setPWM(channel, 0, pulse)

pwm.setPWMFreq(frequency)                        # Set frequency to 500 Hz
setServoPulse(15, frequency, 1500)  # Send a 1500 us pulse to channel 15
