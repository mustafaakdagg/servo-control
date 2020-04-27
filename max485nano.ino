#include<SoftwareSerial.h>
SoftwareSerial rs485 (7,6); //rx,tx
#define DIR 13

void setup() {
    
  //Serial1.begin(9600);//Uncomment for Arduino Lenardo
  Serial.begin(9600);
  rs485.begin(4800);
  //while(!Serial1);//Uncomment for Arduino Lenardo
  


  pinMode(DIR, OUTPUT);//Led Connected
  digitalWrite(DIR,LOW);
 
}

void loop() {

   if(rs485.available()){
   
   
    Serial.write(rs485.read());
    }
    
}
