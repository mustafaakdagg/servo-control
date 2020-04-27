byte servoID_1 = 0x00;
 
void setup(){
   pinMode(2,OUTPUT);
  Serial.begin(9600);
  Serial1.begin(57143);
  Serial.flush();
}
 
void loop(){
moveServo(servoID_1, 200); // Move to position 200
delay(1000);
moveServo(servoID_1, 500); // Move to position 500
delay(1000);
servoID_1++;
}
 
void moveServo(byte servoID, int Position){
  char Position_H = Position >> 8;  //same as /256 and truncating
  char Position_L = Position % 256;
  byte notchecksum = ~lowByte(servoID + 0x05 + 0x03 + 0x1E + Position_L + Position_H);
  digitalWrite(2,HIGH); // put MAX485 into transmitting mode
  delay(1);
  Serial1.write(0xFF); // Start bytes
  Serial1.write(0xFF);
  Serial1.write(servoID); // Servo ID
  Serial1.write(0x05); // Length of message (2 + 3 parameters)
  Serial1.write(0x03); // Write
  Serial1.write(0x1E); // Parameter 1
  Serial1.write(Position_L); // Parameter 2
  Serial1.write(Position_H); // Parameter 3
  Serial1.write(notchecksum); // notCheckSum
  Serial1.flush(); // for good measure
  digitalWrite(2,LOW); // put MAX485 back into receiving mode
  delay(1);
}
