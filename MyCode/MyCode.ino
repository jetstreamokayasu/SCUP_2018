// 変数の定義
const int motIn1 = 7; //to driver 6
const int motIn2 = 8; //to driver 5
const int motControl = 9; //to driver 4

const int mot2In1 = 2; //to driver 6
const int mot2In2 = 4; //to driver 5
const int mot2Control = 5; //to driver 4

int rotSpeed = 0;
int stepSpeed = 5;
#define LED_PIN 13
 
// 初期化
void setup(){
  pinMode(motIn1,OUTPUT);
  pinMode(motIn2,OUTPUT);
  pinMode(mot2In1,OUTPUT);
  pinMode(mot2In2,OUTPUT);
  pinMode(LED_PIN, OUTPUT);

 // make the Bluetooth Module reset:
  digitalWrite(A5, LOW);
  delay(100);
  digitalWrite(A5, HIGH);
  delay(500);
    // シリアルポートを115200 bps[ビット/秒]で初期化 
  Serial.begin(115200);
}
 
// 繰り返し処理
void loop(){
  int inputchar;
 
  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
 
  if(inputchar != -1 ){
    // 読み込んだデータが -1 以外の場合　以下の処理を行う
 
    switch(inputchar){
      case 'g':
        // 読み込みデータが g の場合
 
        Serial.write("Go!!!\n");
//          digitalWrite(motIn1,HIGH);
//          digitalWrite(motIn2,LOW);
//          digitalWrite(mot2In1,HIGH);
//          digitalWrite(mot2In2,LOW);
//          analogWrite(motControl,100);
//          analogWrite(mot2Control,100);

//          digitalWrite(LED_PIN, HIGH);
//          delay(3000);
//          digitalWrite(LED_PIN, LOW);
//          delay(3000);
        break;
      case 'b':  
        // 読み込みデータが　b の場合
 
        Serial.write("Back!!!\n");
//          digitalWrite(motIn1,HIGH);
//          digitalWrite(motIn2,LOW);
//          digitalWrite(mot2In1,LOW);
//          digitalWrite(mot2In2,HIGH);
//          analogWrite(motControl,100);
//          analogWrite(mot2Control,100);

//          digitalWrite(LED_PIN, HIGH);
//          delay(3000);
//          digitalWrite(LED_PIN, LOW);
//          delay(3000);
        break;
              case 'v':  
        // 読み込みデータが　v の場合
 
        Serial.print("Left!!!\n");
//          digitalWrite(motIn1,HIGH);
//          digitalWrite(motIn2,LOW);
//          digitalWrite(mot2In1,HIGH);
//          digitalWrite(mot2In2,LOW);
//          analogWrite(motControl,100);
//          analogWrite(mot2Control,50);

//          digitalWrite(LED_PIN, HIGH);
//          delay(3000);
//          digitalWrite(LED_PIN, LOW);
//          delay(3000);
        break;
              case 'n':  
        // 読み込みデータが　n の場合
 
        Serial.print("Right!!!\n");
//          digitalWrite(motIn1,HIGH);
//          digitalWrite(motIn2,LOW);
//          digitalWrite(mot2In1,HIGH);
//          digitalWrite(mot2In2,LOW);
//          analogWrite(motControl,50);
//          analogWrite(mot2Control,100);

          digitalWrite(LED_PIN, HIGH);
          delay(3000);
          digitalWrite(LED_PIN, LOW);
          delay(3000);
        break;
              case 'h':  
        // 読み込みデータが　h の場合
 
        Serial.print("Stop!!!\n");
//          digitalWrite(motIn1,HIGH);
//          digitalWrite(motIn2,LOW);
//          digitalWrite(mot2In1,LOW);
//          digitalWrite(mot2In2,LOW);
//          analogWrite(motControl,10);
//          analogWrite(mot2Control,10);
//
//          digitalWrite(LED_PIN, HIGH);
//          delay(3000);
//          digitalWrite(LED_PIN, LOW);
//          delay(3000);
        break;
    }
  } else {
    
    // 読み込むデータが無い場合は何もしない
    
  }
}
