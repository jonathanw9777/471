#include <Servo.h>

byte servoPin11 = 11;
byte servoPin10 = 10;
byte servoPin9 = 9;
byte servoPin6 = 6;
byte servoPin5 = 5;
byte servoPin3 = 3;
Servo servo1, servo2, servo3, servo4, servo5, servo6;

void setup() {
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

  delay(15000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
 
  // State 0: Stable
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  delay(5000);

  //State 1: Forward 
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1700);
  servo6.writeMicroseconds(1700);
  delay(5000);

  // State 2: Reverse
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1300);
  servo6.writeMicroseconds(1300);
  delay(5000);

  // State 3: Left
  servo1.writeMicroseconds(1700);
  servo2.writeMicroseconds(1700);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  delay(5000);

  // State 4: Right
  servo1.writeMicroseconds(1300);
  servo2.writeMicroseconds(1300);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  delay(5000);
  
 // State 5: Roll Left
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1300);
  servo4.writeMicroseconds(1700);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  delay(5000);
  
  // State 6: Roll Right
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1700);
  servo4.writeMicroseconds(1300);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  delay(5000);
  
}
