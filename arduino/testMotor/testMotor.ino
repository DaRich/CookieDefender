#include <Servo.h>

Servo motor1;

void setup()
{
  motor1.attach(4);
}

void loop()
{

  motor1.write(120);
  delay(1000);
  motor1.write(180);
  delay(1000);
  
}

