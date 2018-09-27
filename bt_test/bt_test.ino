#include <SoftwareSerial.h>

#define tx 1
#define rx 0
#define led 13

//Bluetooth Serial
SoftwareSerial btSerial(rx,tx);

int mode = 0;

void setup() {
  //Initialize LED
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(115200);
  //Initialize Bluetooth Serial baud rate
  btSerial.begin(115200);
  Serial.println("start\n");
}

void loop() {
  char c;
//  char input;
//
//  if(Serial.available()>0){
//    input=Serial.read();
//    Serial.print("input\n");
//  }

  //Store data
  if(btSerial.available()){
    c = btSerial.read();
    Serial.print("input\n");
  }

  //Change mode
  switch(c){
    case '0':
      btSerial.write("LED = disabled\n");
      mode = 0;
      break;
    case '1':
      btSerial.write("LED = enabled\n");
      mode = 1;
      break;
  }

  //Turn on or off LED
  switch(mode){
    case 0:
      digitalWrite(led,LOW);
      break;
    case 1:
      digitalWrite(led,HIGH);
      break;
  }
}
