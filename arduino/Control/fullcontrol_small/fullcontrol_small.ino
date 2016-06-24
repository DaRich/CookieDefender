#include <Servo.h>
#include <AFMotor.h>

Servo servo_1;
Servo servo_2;
Servo servo_3;
AF_Stepper motor(2000, 2);

#define SERVO1_PWM 10
#define SERVO2_PWM 9
//#define SERVO2_PWM 8
#define SERVO3_PWM 11

int top1 = 0; // LED connected to digital pin 13
int middle = 3;   // pushbutton connected to digital pin 7
int bottom = 5;     // variable to store the read value

int ledPin = 13;

  int leftCount = 90;
  int rightCount = 90;
  int topCount = 90;
  int downCount = 90;

  int  left = 1;
  int  right = 2;
  int  top = 3;
  int  down = 4;
  int  shoot = 5;
  

void setup() {

  pinMode(top, INPUT);      // sets the digital pin 7 as input
  pinMode(middle, INPUT);      // sets the digital pin 7 as input
  pinMode(bottom, INPUT);      // sets the digital pin 7 as input
  
  Serial.begin(9600);
  Serial.println("Simple Motor Shield sketch");

  // Use the default "Servo" library of Arduino.
  // Attach the pin number to the servo library.
  // This might also set the servo in the middle position.
  servo_1.attach(SERVO1_PWM);
  servo_2.attach(SERVO2_PWM);
  servo_3.attach(SERVO3_PWM);
  
  motor.setSpeed(10);  // 10 rpm 

  pinMode(ledPin, OUTPUT);
  recalFire();
  recalHight();
  delay(2000);


}

void fire(){

  int angle = 45;  
  servo_1.write(angle);  
  delay(1000);
  servo_1.write(0); 
  
}

void recalFire(){

  int pos = 0;
  pos = servo_1.read(); 
  Serial.println(pos); 
  if  (pos > 0){
    servo_1.write(0);  
    delay(1000);
  } 
  
}

void recalcircle(){

  servo_3.write(90);
  Serial.println("high_recal"); 
  
}

void recalHight(){

  int pos = 0;

  pos = servo_1.read(); 
  Serial.println(pos); 
  if  (pos > 0){
    servo_1.write(90);  
    //delay(1000);
  } 
  
}

void high(int x){

  servo_2.write(x);  
  Serial.println("high");
  
}

void circle(int x){

  servo_3.write(x);  
  //Serial.println("cricle");

}


void reload_back(int x){

    motor.step(1, RELEASE, 0);
    delay(500);
    Serial.println("Single coil steps");
    //motor.step(x, FORWARD, DOUBLE); 
    motor.step(x, BACKWARD, INTERLEAVE);
}

void reload_front(int x){

    motor.step(1, RELEASE, 0);
    delay(500);
    Serial.println("Single coil steps");
    //motor.step(x, BACKWARD, DOUBLE); 
    motor.step(x, BACKWARD, INTERLEAVE);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  // Suppose there are two servo motors connected.
  // Let them move 180 degrees.

    circle(0);
    delay(2000);
    circle(180);
    delay(2000);
    fire();
    delay(2000);
    high(0);
    delay(2000);
    high(180);
    delay(2000);
    recalFire();
    delay(2000);
    fire();
    recalHight();
    delay(2000);
    fire();
    delay(2000);
    recalcircle();
    delay(2000);
    reload_back(1000);
    delay(10);
    reload_front(1000);
    delay(10);
    fire();

}
