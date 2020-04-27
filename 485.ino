#include<SoftwareSerial.h>
SoftwareSerial RS485 (7,6); //rx,tx
#define DIR 13

void setup() {
    
  Serial.begin(9600);
  RS485.begin(4800);
  pinMode(DIR, OUTPUT);//Led Connected
  digitalWrite(DIR,LOW);
 
}

void loop() {

    digitalWrite(DIR,HIGH);
    RS485.println(millis());
     digitalWrite(DIR,LOW);
     delay(1000);
    
}
