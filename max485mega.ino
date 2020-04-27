void setup() {
  
  Serial2.begin(9600);//Using Serial1 Port
  Serial.begin(9600);
  pinMode(8, OUTPUT);//DE/RE Controling pin of RS-485
}

void loop() {
  char getdata='m';

  digitalWrite(8,HIGH);//DE/RE=HIGH Transmit Enabled M1
  Serial2.print('9');//Write '9' and Fetch Data From Pro Mini
   
  digitalWrite(8,LOW);//DE/RE=LOW Receive Enabled M1
  delay(1000);

  getdata=Serial2.read();
    Serial.println(getdata);
  if(Serial2.available()){ //If Serial Data is available
    
    while(Serial2.available() )
    { 
    getdata=Serial2.read();
    Serial.print(getdata);
    }
    
    Serial.println("");
    }
}
