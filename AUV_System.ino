#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/*
   Connections
   ===========
   Connect SCL to SCL pin (analog 5 on Arduino UNO)
   Connect SDA to SDA pin (analog 4 on Arduino UNO)
   Connect VDD to 3-5V DC (depending on your board's logic level)
   Connect GROUND to common ground
*/
Adafruit_BNO055 bno = Adafruit_BNO055(55);

byte servoPin11 = 11;  /* front left */ 
byte servoPin10 = 10;  /* front right */ 
byte servoPin9 = 9;    /* middle left */ 
byte servoPin6 = 6;    /* middle left */ 
byte servoPin5 = 5;    /* back left */ 
byte servoPin3 = 3;    /* back right */ 

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;



void setup() {

  /*Connects Thrusters Analog Inputs and Initializes them as neutral */
  servo1.attach(servoPin10);
  servo2.attach(servoPin11);
  servo3.attach(servoPin9);
  servo4.attach(servoPin6);
  servo5.attach(servoPin5);
  servo6.attach(servoPin3);

  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);

 
  Serial.begin(9600);
  Serial.println("Orientation Coordinates"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  delay(1000);
    
  bno.setExtCrystalUse(true);

}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");

  /*Based on Z-coordinate, control a certain thruster */
  if (event.orientation.z >= 80) {
      int signal1 = 1700;
      int signal2 = 1200;
      int signal3 = 1700;
      int signal4 = 1200;
      int signal5 = 1700;
      int signal6 = 1200;
      servo1.writeMicroseconds(signal1);
      servo2.writeMicroseconds(signal2);
  }
  else if (event.orientation.z <= -80) {
      int signal1 = 1700;
      int signal2 = 1200;
      int signal3 = 1700;
      int signal4 = 1200;
      int signal5 = 1700;
      int signal6 = 1200;
      servo1.writeMicroseconds(signal1);
      servo2.writeMicroseconds(signal2);
  }
  else {    /*Stable*/
      int signal1 = 1500;
      int signal2 = 1500;
      int signal3 = 1600;
      int signal4 = 1600;
      int signal5 = 1500;
      int signal6 = 1500;
      servo3.writeMicroseconds(signal1);
      servo4.writeMicroseconds(signal2);
      servo3.writeMicroseconds(signal3);
      servo4.writeMicroseconds(signal4);
      servo3.writeMicroseconds(signal5);
      servo4.writeMicroseconds(signal6);
  }
  
  delay(100);
}
/*
 * Stable
 * Forward
 * Reverse
 * Left
 * Right
 * Rotate Left
 * Rotate Right
 * Nose Up
 * Nose Down
 */
 * /
