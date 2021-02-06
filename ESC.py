#import RPi.GPIO as GPIO
#from time import sleep

#GPIO.setmode(GPIO.BCM)

#GPIO.setup(18,GPIO.OUT)
#motor=GPIO.PWM(18,100)
#motor.start(0)

# GPIO.setwarnings(False)

#try:
#    for i in range(100):
#        print(i)
#        motor.ChangeDutyCycle(i)
#        sleep(0.5)
#except KeyboardInterrupt:
#    print("Motor kapatılıyor... (Ctrl+C ile çıkış yapıldı.)")
#finally:
#    GPIO.cleanup()

import RPi.GPIO as GPIO
import time
 
ledPin = 33
 
def setup():
    global pwm
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.LOW)
    pwm = GPIO.PWM(ledPin, 1900) # Set Frequency to 1 KHz
    pwm.start(0) # Set the starting Duty Cycle
     
def loop():
    while True:
        pwm.ChangeDutyCycle(50)
#        for dc in range(0, 101, 1):
#            pwm.ChangeDutyCycle(dc)
#            time.sleep(0.01)
#        time.sleep(1)
#        for dc in range(100, -1, -1):
#            pwm.ChangeDutyCycle(dc)
#            time.sleep(0.01)
#        time.sleep(1)
         
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
