#include <Stepper.h>


AF_Stepper Stepper(200,1);

void setuo()
{
  motor.setSpeed(8);
  Serial.begin(9600);
}

void loop(){
  motor.step(100,FORWARD,SINGLE);
  
}

