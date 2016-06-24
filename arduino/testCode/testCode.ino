void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

  while(1){
    Serial.println(digitalRead(12));
    delay(10);
      if(digitalRead(12)){
        digitalWrite(8,HIGH);
        
        
      }
      else{
        digitalWrite(8,LOW);
      }
  }
  // put your main code here, to run repeatedly:

}
