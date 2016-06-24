#include <Servo.h>

int moveServo;

Servo myservo;

void setup()
{
 
 myservo.attach(10);
 Serial.begin(9600);
 Serial.println("      Arduino Serial Servo Control");
 Serial.println("Press < or > to move, spacebar to center");
 Serial.println();
 
}

void loop () {
 
 if (Serial.available() > 0) {
   moveServo = Serial.read();
   
   if (moveServo == 44) { myservo.write(71); }
   if (moveServo == 46) { myservo.write(10); }
   if (moveServo == 32) { myservo.write(46); }
 }
}
