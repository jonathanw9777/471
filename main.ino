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

  delay(12000);

  Serial.begin(9600);
  Serial.println("Orientation Coordinates"); Serial.println("");

  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
  delay(3000);
  bno.setExtCrystalUse(true);
}

/***************************************************************************************************************/

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

  /* Make AUV stable using IMU values*/
  if (/* not stable */) {
    if (/* tilted left */) {
      /* roll right */
    }
    else {
      /* roll left */
    }
  }
  else {
    /* keep rotating left/right */
  }


  /* Bring object straight ahead using camera GPIO input*/
  /*  if(/* in front */) {
    /* forward */
    /*  }
      else {
        /* keep rotating left/right */
    /*  }
    */

    switch (curr_state) {
      /* State 0: Stable */
      case 1:
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;

      /* State 1: Forward */
      case 2:
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1700);
        servo6.writeMicroseconds(1700);
        break;

      /* State 2: Reverse */
      case 3:
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1300);
        servo6.writeMicroseconds(1300);
        break;

      /* State 3: Left */
      case 4:
        servo1.writeMicroseconds(1700);
        servo2.writeMicroseconds(1700);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;

      /* State 4: Right */
      case 5:
        servo1.writeMicroseconds(1300);
        servo2.writeMicroseconds(1300);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;

      /* State 5: Roll Left */
      case 6:
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1300);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;

      /* State 6: Roll Right */
      case 7:
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1300);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;

      default:
        /* State 0: Stable */
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
        servo3.writeMicroseconds(1700);
        servo4.writeMicroseconds(1700);
        servo5.writeMicroseconds(1500);
        servo6.writeMicroseconds(1500);
        break;
    }
    delay(100);
  }

}
