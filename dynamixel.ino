#include<Dynamixel_Serial.h>
#include<DynamixelSerial1.h>

int Temperature,Voltage,Position;

void setup() {
 Serial.begin(9600);
 Dynamixel.begin(57143.2);
 delay(1000);

}

void loop() {
Temperature = Dynamixel.readTemperature(1);
Voltage = Dynamixel.readVoltage(1);
Position = Dynamixel.readVoltage(1);

Dynamixel.move(1,random(200,800));
Serial.print("Temperature:");
Serial.println(Temperaure);
Serial.print("Voltage:");
Serial.println(Voltage);
Serial.print("Position:");
Serial.println(Position);

delay(200);
}
