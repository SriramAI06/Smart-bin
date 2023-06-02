#include <Servo.h>


int paper = 0;
int food = 0;
int metal = 0;
int plastic = 0;
int nothing = 0;

Servo servo1;
Servo servo2;
Servo servo3;

const int servoPin1 = 9;
const int servoPin2 = 10;
const int servoPin3 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);

}
void getdata() {
  while (Serial.available()) {
    String c = Serial.readStringUntil('\r');//10000

        paper = c.substring(0, 1).toInt();
        metal = c.substring(1, 2).toInt();
        food = c.substring(2, 3).toInt();
        plastic = c.substring(3, 4).toInt();
        nothing = c.substring(4, 5).toInt();

        c = "";
      
    }
  
}


void food1(){
  servo1.write(90);
  servo3.write(90);
  delay(1500); // Wait for 1 second 
  servo1.write(35);
  servo3.write(150);
  delay(1500); // Wait for 1 second 
  servo1.write(90);
  servo3.write(90);
  delay(1500);
  }

 void paper1(){
  // Rotate the servo motor to 0 degrees
  servo1.write(90);
  servo2.write(90);
  delay(1500); // Wait for 1 second 
  servo1.write(150);
  servo2.write(150);
  delay(1500); // Wait for 1 second 
  servo1.write(90);
  servo2.write(90);
  delay(1500);
  }

  void metal1(){
  // Rotate the servo motor to 0 degrees
  servo1.write(90);
  servo2.write(90);
  delay(1500); // Wait for 1 second 
  servo1.write(150);
  servo2.write(35);
  delay(1500); // Wait for 1 second 
  servo1.write(90);
  servo2.write(90);
  delay(1500);
  }

  void plastic1(){
  servo1.write(90);
  servo3.write(90);
  delay(1500); // Wait for 1 second 
  servo1.write(35);
  servo3.write(35);
  delay(1500); // Wait for 1 second 
  servo1.write(90);
  servo3.write(90);
  delay(1500);
  }

  void nothing1(){

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  }

void loop() {
  // put your main code here, to run repeatedly:
getdata();

if (paper==1){paper1();}

if (food==1){food1();}

if (metal==1){metal1();}

if (plastic==1){plastic1();}

if (nothing==1){nothing1();}
//delay(3000);
}
