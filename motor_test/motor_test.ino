// Arduino Sketch
const int motIn1 = 7; //to driver 6
const int motIn2 = 8; //to driver 5
const int motControl = 6; //to driver 4

const int mot2In1 = 2; //to driver 6
const int mot2In2 = 4; //to driver 5
const int mot2Control = 5; //to driver 4

//int rotSpeed = 0;
//int stepSpeed = 5;
#define LED_PIN 13


void setup(){
  pinMode(motIn1,OUTPUT);
  pinMode(motIn2,OUTPUT);
  pinMode(mot2In1,OUTPUT);
  pinMode(mot2In2,OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  //pinMode(A0, OUTPUT);

  // make the Bluetooth Module reset:
  digitalWrite(A5, LOW);
  delay(100);
  digitalWrite(A5, HIGH);
  delay(500);

  Serial.begin(115200);
  Serial.println("send start!");
  
}

void loop(){
  digitalWrite(motIn1,HIGH);
  digitalWrite(motIn2,LOW);
  digitalWrite(mot2In1,HIGH);
  digitalWrite(mot2In2,LOW);
  analogWrite(motControl,250);
  analogWrite(mot2Control,250);

//  digitalWrite(LED_PIN, HIGH);
//  delay(3000);
//  digitalWrite(LED_PIN, LOW);
//  delay(3000);

   // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    digitalWrite(LED_PIN, HIGH);

    // get incoming byte:
    char inByte = Serial.read();
    Serial.write(inByte); 
    delay(100);
  }
  delay(1);        // delay in between reads for stability

//  int input;
//  input=Serial.read();
//  if(input!=-1){
//  Serial.write(input);
//  Serial.write("\n");
//  }

 // digitalWrite(A0,HIGH);
//  analogWrite(motControl,rotSpeed);
//  delay(500);
//  rotSpeed = rotSpeed + stepSpeed;
//    
//  if (rotSpeed == 80) {
//    rotSpeed = 0;
//    analogWrite(motControl,rotSpeed);
//    delay(1000);
//  }
}
