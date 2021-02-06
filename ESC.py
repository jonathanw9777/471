import RPi.GPIO as GPIO
import time
 
ledPin = 33
 
def setup():
    global pwm
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.HIGH)
    pwm = GPIO.PWM(ledPin, 1700) # Set Frequency to 1 KHz
    pwm.start(50) # Set the starting Duty Cycle
    print("Starting Duty Cycle at 50")
     
def loop():
    while True:
      pwm.ChangeFrequency(.0018)
         
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
