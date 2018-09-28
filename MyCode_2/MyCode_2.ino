// 変数の定義

//左車輪
const int motIn1 = 7; //to driver 6
const int motIn2 = 8; //to driver 5
const int motControl = 9; //to driver 4

//右車輪
const int mot2In1 = 2; //to driver 6
const int mot2In2 = 4; //to driver 5
const int mot2Control = 5; //to driver 4

//int rotSpeed = 0;
//int stepSpeed = 5;
#define LED_PIN 13

// 初期化
void setup() {
  //左車輪
  pinMode(motIn1, OUTPUT);
  pinMode(motIn2, OUTPUT);

  //右車輪
  pinMode(mot2In1, OUTPUT);
  pinMode(mot2In2, OUTPUT);
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
void loop() {
  int inputchar;
  int repeat = 62;

  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
   while (Serial.read() != -1 && --repeat > 0);

  if (inputchar != -1 ) {
    // 読み込んだデータが -1 以外の場合　以下の処理を行う

    switch (inputchar) {
      case 'w':
        // 読み込みデータが w の場合
        //前進する
        Serial.print("Forward\n");
        //左車輪
        digitalWrite(motIn1, HIGH);
        digitalWrite(motIn2, LOW);
        analogWrite(motControl, 250);

        //右車輪
        digitalWrite(mot2In1, LOW);
        digitalWrite(mot2In2, HIGH);
        analogWrite(mot2Control, 250);

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        break;
      case 's':
        // 読み込みデータが　s の場合
        //後退する
        Serial.print("Back\n");
        //左車輪
        digitalWrite(motIn1, LOW);
        digitalWrite(motIn2, HIGH);
        analogWrite(motControl, 250);

        //右車輪
        digitalWrite(mot2In1, HIGH);
        digitalWrite(mot2In2, LOW);
        analogWrite(mot2Control, 250);

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        break;
      case 'a':
        // 読み込みデータが　a の場合
        //左折する
        Serial.print("Left\n");
       //左車輪・後進
        digitalWrite(motIn1, LOW);
        digitalWrite(motIn2, HIGH);
        analogWrite(motControl, 200);

        //右車輪・前進
        digitalWrite(mot2In1, LOW);
        digitalWrite(mot2In2, HIGH);
        analogWrite(mot2Control, 200);

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        break;
      case 'd':
        // 読み込みデータがd の場合
        //右折する
        Serial.print("Right\n");
       //左車輪・前進
        digitalWrite(motIn1, HIGH);
        digitalWrite(motIn2, LOW);
        analogWrite(motControl, 250);

        //右車輪・後進
        digitalWrite(mot2In1, HIGH);
        digitalWrite(mot2In2, LOW);
        analogWrite(mot2Control, 250);

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        break;
      case 'l':
        // 読み込みデータが　l の場合
        //停止する
        Serial.print("Stop\n");
        //左車輪・ブレーキ
        digitalWrite(motIn1, HIGH);
        digitalWrite(motIn2, HIGH);
        analogWrite(motControl, 250);

        //右車輪・ブレーキ
        digitalWrite(mot2In1, HIGH);
        digitalWrite(mot2In2, HIGH);
        analogWrite(mot2Control, 250);

        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        break;
    }
  } else {

    // 読み込むデータが無い場合はストップ
        //左車輪・ニュートラル
        digitalWrite(motIn1, LOW);
        digitalWrite(motIn2, LOW);
        analogWrite(motControl, 250);

        //右車輪・ニュートラル
        digitalWrite(mot2In1, LOW);
        digitalWrite(mot2In2, LOW);
        analogWrite(mot2Control, 250);

//        digitalWrite(LED_PIN, HIGH);
        delay(200);
//        digitalWrite(LED_PIN, LOW);
//        delay(100);

  }

}
