
#include <Dynamixel_Serial.h>       // Library needed to control Dynamixal servo
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4 , 7);  // RX, TX

int Position;
#define SERVO_ID 0x01               // ID of which we will set Dynamixel too
#define SERVO_ControlPin 0x10       // Control pin of buffer chip, NOTE: this does not matter becasue we are not using a half to full contorl buffer.
#define SERVO_SET_Baudrate 57600    // Baud rate speed which the Dynamixel will be set too (57600)
#define LED13 0x0D                  // Pin of Visual indication for runing "heart beat" using onboard LED
#define TX_DEALY 2000               // in uSec
#define CW_LIMIT_ANGLE 0x001        // lowest clockwise angle is 1, as when set to 0 it set servo to wheel mode
#define CCW_LIMIT_ANGLE 0xFFF       // Highest anit-clockwise angle is 0XFFF, as when set to 0 it set servo to wheel mode

void setup(){
mySerial.begin(57600);
delay(1000);                                                           // Give time for Dynamixel to start on power-up

Dynamixel.begin(SERVO_SET_Baudrate, SERVO_ControlPin, TX_DEALY);        // We now need to set Ardiuno to the new Baudrate speed
Dynamixel.setMode(SERVO_ID, SERVO, CW_LIMIT_ANGLE, CCW_LIMIT_ANGLE);    // set mode to SERVO and set angle limits

}


void loop(){
  Dynamixel.servo(SERVO_ID,0x001,0x100);   // Move servo to angle 1(0.088 degree) at speed 100
  delay(3000);
 
Position = Dynamixel.readPosition(SERVO_ID);
mySerial.print(Position);
delay(1000);

  Dynamixel.servo(SERVO_ID,0xFFF,0x3FF);  //  Move servo to max angle at max speed
  delay(3000);

Position = Dynamixel.readPosition(SERVO_ID);
mySerial.print(Position);
delay(1000);
   

   
}
