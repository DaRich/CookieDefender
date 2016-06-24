#include <Servo.h>
#include <AFMotor.h>

Servo servo_1;
Servo servo_2;
Servo servo_3;
AF_Stepper motor(600, 2);

#define SERVO1_PWM 10
#define SERVO2_PWM 9
//#define SERVO2_PWM 8
#define SERVO3_PWM 11

int ledPin = 13;

void setup() {
  
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
  
}

void highControl(int x){

  
  servo_2.write(x);  

  Serial.println("highControl");
  
}

void gun_circle(int x){

  servo_3.write(x);  

  //Serial.println("GUN_CIRCLE");

}


void roll(int x){

    Serial.println("Single coil steps");
    motor.step(x, FORWARD, SINGLE); 
    //motor.step(x, BACKWARD, SINGLE); 

}

void recalHight(){

  int pos = 0;

  pos = servo_1.read(); 
  Serial.println(pos); 
  if  (pos > 0){
    servo_1.write(45);  
    delay(1000);
  } 
  
}


void loop() {
  // put your main code here, to run repeatedly:
  // Suppose there are two servo motors connected.
  // Let them move 180 degrees.
  
  //recal();
  //fire();

  int i = 0;
  int next = 1;

  //while (i != 130){

//    i = i+1;
//    highControl(i); // 0 - 180
//    delay(100);
//    Serial.println(i);
//
//    next = next+1;
//    Serial.println(next);
//
//    if (next == 10){
//      fire();
//      next = 1;
//      Serial.println("FIRE");
//    }


    //if (next == 5){

// for (int i=0; i <= 2500; i++){
//      roll(10);
//      //motor.setSpeed(i);
//      delay(10);
// }

    int pos = 1;

    pos = servo_3.read(); 
    Serial.println(pos); 

    gun_circle(0);
    delay(2000);
    gun_circle(180);
    delay(2000);
    fire();
    delay(2000);
    highControl(0);
    delay(2000);
    highControl(180);
    delay(2000);
    recalFire();
    delay(2000);
    recalHight();

}




