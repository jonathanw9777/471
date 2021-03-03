#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/*  Brown = Negative, Yellow = Positive
 *  Thruster: Left column (11 9 5)
 *  Right column (10 6 3)
 */
 
/*
   Connections
   ===========
   Connect SCL to SCL pin (analog 5 on Arduino UNO)
   Connect SDA to SDA pin (analog 4 on Arduino UNO)
   Connect VDD to 3-5V DC (depending on your board's logic level)
   Connect GROUND to common ground
*/
Adafruit_BNO055 bno = Adafruit_BNO055(55);
/*Initializes GPIO pins */
byte servoPin11 = 11;
byte servoPin10 = 10;
byte servoPin9 = 9;
byte servoPin6 = 6;
byte servoPin5 = 5;
byte servoPin3 = 3;
/*Initializes state values*/
byte curr_state = NULL;
byte stable = 1;
byte forward = 2;
byte reverse = 3;
byte left = 4;
byte right = 5;

Servo servo1, servo2, servo3, servo4, servo5, servo6;

void setup() {

  /*Connects Thrusters Analog Inputs and Initializes them as neutral */
  servo1.attach(servoPin11);
  servo2.attach(servoPin10);
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

  delay(5000);

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
  /* Initialize sensor event and tol */ 
  sensors_event_t eventInit; 
  tolX1 = eventInit.orientation.x + 35;
  tolX2 = eventInit.orientation.x - 35;
  tolY1 = eventInit.orientation.y + 20;
  tolY2 = eventInit.orientation.y - 20;
  tolZ1 = eventInit.orientation.z + 20;
  tolZ2 = eventInit.orientation.z - 20;
}

void loop(void) {
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

  curr_state = 1;
  switch(curr_state){
   /*Stable*/
   case 1:
        servo1.writeMicroseconds(1600);
        servo2.writeMicroseconds(1600);
        servo3.writeMicroseconds(1600);
        servo4.writeMicroseconds(1600);
        servo5.writeMicroseconds(1600);
        servo6.writeMicroseconds(1600);
//      if (event.orientation.z <= tolZ && event.orientation.z >= tolZ - 20){ 
//      /*Forward State*/
//         curr_state = 2;
//      }
//      else {
//         curr_state = 1;
//      }

      break;
   /*Forward*/
   case 2: 
      servo1.writeMicroseconds(1600);
      servo2.writeMicroseconds(1600);
      servo3.writeMicroseconds(1600);
      servo4.writeMicroseconds(1600);
      servo5.writeMicroseconds(1600);
      servo6.writeMicroseconds(1600);
      if (event.orientation.z <= event.orientation.z + 20 && event.orientation.z >= event.orientation.z - 20){ 
      /*Control Top thrusters*/
         curr_state = 3;
      }
      else {
         curr_state = 1;
      }
      break;
   /*Reverse*/
   case 3:
      servo1.writeMicroseconds(1200);
      servo2.writeMicroseconds(1200);
      servo3.writeMicroseconds(1200);
      servo4.writeMicroseconds(1200);
      servo5.writeMicroseconds(1200);
      servo6.writeMicroseconds(1200);
      if (event.orientation.z <= event.orientation.z + 20 && event.orientation.z >= event.orientation.z - 20){ 
      /*Control Top thrusters*/
         curr_state = 1;
      }
      break;
   /*Turns off with reset button*/ 
   default:
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
      servo3.writeMicroseconds(1500);
      servo4.writeMicroseconds(1500);
      servo5.writeMicroseconds(1500);
      servo6.writeMicroseconds(1500);
      break;
  }
  delay(100);
}
/*    else if (event.orientation.y <= event.orientation.y + 20 && event.orientation.y >= event.orientation.y - 20){ */
    /*Control the front or back thrusters along with top thrusters to balance the Pitch*/
/*  } */
/*    else if (event.orientation.x <= event.orientation.x + 35 && event.orientation.x >= event.orientation.x - 35){ */
    /*Reverse front thruster and forward back thruster depending on Yaw position*/
 
