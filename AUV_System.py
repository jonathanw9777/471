# IMU Code
# Goal
# Install driver locally using PyPi
# pip3 install adafruit-circuitpython-bno055

# Install System wide
#sudo pip3 install adafruit-circuitpython-bno055

# Virtual Environment in current project
#mkdir project-name && cd project-name
#python3 -m venv .env
#source .env/bin/activate
#pip3 install adafruit-circuitpython-bno055

import adafruit_bno055

# Takes instantiated and active I2C object
# From busio or the bitbangio library
# Creates an I2C object
from busio import I2C
from board import SDA, SCL
i2c = I2C(SCL, SDA)

# Creates sensor object
sensor = adafruit_bno055.BNO055_I2C(i2c)

# Prints measurements
print(sensor.temperature)
print(sensor.euler)
print(sensor.gravity)

# Algorithm: Power on, Check IMU position, Power the thrusters appropriately,
# Check camera for obstacles, adjust thrsuters if necessary for avoidance
