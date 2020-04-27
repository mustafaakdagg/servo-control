int Position = -1;
int Time_Counter = 0;
int TIME_OUT = 10;
int Position_Low_Byte = 0;
int Position_High_Byte = 0;
int Position_Long_Byte = -1;



void setup() {
  Serial.begin(9600);
  Serial1.begin(1000000);
  pinMode(2,OUTPUT);


  digitalWrite(2,HIGH);
  Serial1.write(0xFF);
  Serial1.write(0xFF);
  Serial1.write(0x01);
  Serial1.write(0x04);
  Serial1.write(0x02);
  Serial1.write(0x24);
  Serial1.write(0x02);
  Serial1.write(0xD2);
  digitalWrite(2,LOW);

}

void loop() {
 while(Serila1.available()<7 & Time_Counter<TIME_OUT){
  Time_Counter++;
  delay(1000);
 }

}
