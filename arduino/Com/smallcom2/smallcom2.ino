#include <Servo.h>
#include <AFMotor.h>

Servo servo_1;
Servo servo_2;
Servo servo_3;
AF_Stepper motor(2000, 2);

#define SERVO1_PWM 10
#define SERVO2_PWM 9
#define SERVO3_PWM 11

int ledPin = 13;

  int xCount = 180;
  int yCount = 180;

  int  left = 1;
  int  right = 2;
  int  top = 3;
  int  down = 4;
  int  shoot = 5;
  int  recalc = 6;

  int xIndex = 0;
  int yIndex = 0;

  int pos = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Simple Motor Shield sketch");

  servo_1.attach(SERVO1_PWM);
  servo_2.attach(SERVO2_PWM);
  servo_3.attach(SERVO3_PWM);
  
  motor.setSpeed(10);  // 10 rpm 

  pinMode(ledPin, OUTPUT);
  recalFire();
  recalHight();
  delay(2000);

  fire();
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
    servo_1.write(90);  
  } 
  
}

void recalcircle(){

  servo_3.write(0);
  Serial.println("high_recal"); 
  
}

void recalHight(){

  int pos = 0;

  pos = servo_1.read(); 
  Serial.println(pos); 
  if  (pos > 0){
    servo_1.write(0);  
  } 
  
}

void high(int x){

  servo_2.write(x);  
  Serial.println("high");
  
}

void circle(int x){

  servo_3.write(x);
  Serial.println("circle");  

}


void reload_back(int x){

    motor.step(1, RELEASE, 0);
    delay(500);
    Serial.println("Single coil steps"); 
    motor.step(x, BACKWARD, INTERLEAVE);
}

void reload_front(int x){

    motor.step(1, RELEASE, 0);
    delay(500);
    Serial.println("Single coil steps");
    motor.step(x, BACKWARD, INTERLEAVE);
    
}

void loop() {

  while( Serial.available() == 0 );
  
    byte val = Serial.read();
    Serial.println(val, DEC);
  

    if (val == left){

      Serial.println("left");
      xIndex = xIndex+20;
      circle(xIndex);  
            
    }

    if (val == right){
      
      Serial.println("right");
      xIndex = xIndex-20;
      circle(xIndex);  
      
    }

    if (val == top){
      
      Serial.println("top");
      yIndex = yIndex+20;
      high(yIndex); 
    }

    if (val == down){
      
      Serial.println("down");  
      yIndex = yIndex-20;
      high(yIndex); 
    }

    if (val == shoot){
      
      Serial.println("shoot");
      fire(); 
      recalHight();
      recalcircle();
      xIndex = 0;
      yIndex = 0; 
    }
}
