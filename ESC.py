import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)

GPIO.setup(18,GPIO.OUT)
motor=GPIO.PWM(18,100)
motor.start(0)

# GPIO.setwarnings(False)

try:
    for i in range(100):
        print(i)
        motor.ChangeDutyCycle(i)
        sleep(0.5)
except KeyboardInterrupt:
    print("Motor kapatılıyor... (Ctrl+C ile çıkış yapıldı.)")
finally:
    GPIO.cleanup()
