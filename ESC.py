import RPi.GPIO as GPIO
import time
 
ledPin = 33
 
def setup():
    global pwm
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.HIGH)
    pwm = GPIO.PWM(ledPin, 1700000000) # Set Frequency to 1 KHz
    pwm.start(90) # Set the starting Duty Cycle
     
def loop():
    while True:
        pwm.ChangeFrequency(1900000000)
         
def destroy():
    pwm.stop()
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()
     
if  __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        destroy()
