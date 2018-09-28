
const int motIn1 = 7; //to driver 6
const int motIn2 = 8; //to driver 5
const int motControl = 9; //to driver 4

const int mot2In1 = 2; //to driver 6
const int mot2In2 = 4; //to driver 5
const int mot2Control = 5; //to driver 4

int rotSpeed = 0;
int stepSpeed = 5;
#define LED_PIN 13

//サーボモーター
const int deg0msec = 600; // msec.
#include <Servo.h>
Servo servo1;        //Servoオブジェクトを作成
Servo servo2;
int servo1_deg = 170;
int servo2_deg = 0;


// 初期化
void setup(){
  pinMode(motIn1,OUTPUT);
  pinMode(motIn2,OUTPUT);
  pinMode(mot2In1,OUTPUT);
  pinMode(mot2In2,OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(A5,LOW);
  delay(100);
  digitalWrite(A5,HIGH);
  delay(500);
    // シリアルポートを115200 bps[ビット/秒]で初期化
  Serial.begin(115200);



  servo1.attach(10);  //D10ピンをサーボの信号線として設定
  servo2.attach(11);
  Serial.print("setup\n");
}

// 繰り返し処理
void loop(){
  delay(50);
  servo1.write(servo1_deg);
  servo2.write(servo2_deg);

  // シリアルポートより1文字読み込んで残りのほとんどを捨てる
  int inputchar = Serial.read();
  int repeat = 62;
  while (Serial.read() != -1 && --repeat > 0);

  if(inputchar == -1 ) {
    digitalWrite(motIn1,LOW);
    digitalWrite(motIn2,LOW);
    digitalWrite(mot2In1,LOW);
    digitalWrite(mot2In2,LOW);
    return;
  }

  switch(inputchar){
    // 駆動輪の操作********************
    case 'w':
      Serial.print("Go!!!\n");
      digitalWrite(motIn1,HIGH);
      digitalWrite(motIn2,LOW);
      digitalWrite(mot2In1,HIGH);
      digitalWrite(mot2In2,LOW);
      analogWrite(motControl,255);
      analogWrite(mot2Control,255);
      break;
    case 's':
      Serial.print("Back!!!\n");
      digitalWrite(motIn1,LOW);
      digitalWrite(motIn2,HIGH);
      digitalWrite(mot2In1,LOW);
      digitalWrite(mot2In2,HIGH);
      analogWrite(motControl,255);
      analogWrite(mot2Control,255);
      break;
    case 'a':
      Serial.print("Left!!!\n");
      digitalWrite(motIn1,HIGH);
      digitalWrite(motIn2,LOW);
      digitalWrite(mot2In1,LOW);
      digitalWrite(mot2In2,HIGH);
      analogWrite(motControl,0);
      analogWrite(mot2Control,255);
      break;
    case 'd':
      Serial.print("Right!!!\n");
      digitalWrite(motIn1,LOW);
      digitalWrite(motIn2,HIGH);
      digitalWrite(mot2In1,HIGH);
      digitalWrite(mot2In2,LOW);
      analogWrite(motControl,255);
      analogWrite(mot2Control,0);
      break;
    case 'h':
      Serial.print("brake!!!\n");
      digitalWrite(motIn1,HIGH);
      digitalWrite(motIn2,HIGH);
      digitalWrite(mot2In1,HIGH);
      digitalWrite(mot2In2,HIGH);
      break;
    // サーボモーターの角度情報更新********************
    case 'j':
      Serial.print("j!!!\n");
      servo1_deg = 170;
      servo2_deg = 0;
      break;
    case 'k':
      Serial.print("k!!!\n");
      servo1_deg = 70;
      servo2_deg = 100;
      break;
    case 'l':
      Serial.print("l!!!\n");
      servo1_deg = 20;
      servo2_deg = 160;
      break;
  // *********************************************

  }
}
