#ESC_2.py 
#From https://github.com/inceabdullah/Raspberry-Pi-Multiple-ESC-Calibration-for-Drone/blob/master/raspberry-pi-multiple-esc-calibration-with-pigpio-for-drone.py

# Multi ESC Calibration for Drones
import os    
import time   
os.system ("sudo pigpiod") 
time.sleep(1) 
import pigpio 

ESC = 17  
ESC_2 = 27
#ESC_3 = 27
#ESC_4 = 22

#Count_ESC = [ESC , ESC_2, ESC_3, ESC_4]
Count_ESC = ESC
Count_ESC_2 = ESC_2

pi = pigpio.pi();

#for E in Count_ESC:
#    pi.set_servo_pulsewidth(E, 0) 
pi.set_servo_pulsewidth(ESC, 0) 
max_value = 2000 
min_value = 790

pi.set_servo_pulsewidth(ESC_2, 0) 
max_value = 2000 
min_value = 790  

print("please disconnect battery.. then press kal")
                
def calibrate():   
#    for E in Count_ESC: 
    pi.set_servo_pulsewidth(ESC, 0)
    time.sleep(1)
    pi.set_servo_pulsewidth(ESC, max_value)
    print("Connect battery.. then press Enter to calibrate ESC 1")
    inp = input()
    if inp == '': 
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC, min_value)   
        time.sleep(7)
        time.sleep (5)        
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC, 0)           
        time.sleep(2) 
        print ("Arming ESC 1")
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC, min_value)
        time.sleep(1)
        
        calibrate1()
        
def calibrate1():   
#    for E in Count_ESC: 
    pi.set_servo_pulsewidth(ESC_2, 0)
    time.sleep(1)
    pi.set_servo_pulsewidth(ESC_2, max_value)
    print("Press Enter to calibrate ESC 2")
    inp = input()
    if inp == '': 
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC_2, min_value)   
        time.sleep(7)
        time.sleep (5)        
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC_2, 0)           
        time.sleep(2) 
        print ("Arming ESC 2")
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC_2, min_value)
        time.sleep(1)
        control()
                   
             
def control(): 

    time.sleep(1)
    speed = min_value
    speed1 = min_value
    print ("a : decrease speed & d : increase speed | q : decrease a lot & e : increase a lot\n")
    print ("z : decrease speed & c : increase speed | w : decrease a lot & s : increase a lot\n")
    print ("Press stop to stop both Thrusters")
    while True:
#        for E in Count_ESC:
        pi.set_servo_pulsewidth(ESC, speed)
        pi.set_servo_pulsewidth(ESC_2, speed1)
        inp = input()
        
        if inp == "q":
            speed -= 100    
            print ("ESC 1's speed = %d" % speed)
        elif inp == "e":    
            speed += 100    
            print ("ESC 1's speed = %d" % speed)
        elif inp == "d":
            speed += 10     
            print ("ESC 1's speed = %d" % speed)
        elif inp == "a":
            speed -= 10     
            print ("ESC 1's speed = %d" % speed)
        elif inp == "w":
            speed1 -= 100    
            print ("ESC 2's speed = %d" % speed1)
        elif inp == "s":    
            speed1 += 100    
            print ("ESC 2's speed = %d" % speed1)
        elif inp == "c":
            speed1 += 10     
            print ("ESC 2's speed = %d" % speed1)
        elif inp == "z":
            speed1 -= 10     
            print ("ESC 2's speed = %d" % speed1)
        elif inp == "stop":
            stop()          
            break
        else:
            print ("Press a,q,d or e")
      
def stop(): 
#    for E in Count_ESC:
    pi.set_servo_pulsewidth(ESC, 0)
    pi.stop()

  
inp = input()

if inp == "kal":
    calibrate()
    #calibrate1()


elif inp == "stop":
    stop()
