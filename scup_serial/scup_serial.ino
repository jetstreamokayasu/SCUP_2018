char input[30];   // 文字列格納用
int i = 0;  // 文字数のカウンタ
int BTReset = 28;

int flag = 0;
char mode = '6';

void setup() {
  digitalWrite(BTReset, LOW);
  delay(100);
  digitalWrite(BTReset, HIGH);
  delay(500);
  Serial.begin(115200);
}
   
void loop() {
  if (Serial.available()) {
      input[i] = Serial.read();
      
      // 文字数が30以上 or 末尾文字
      if (i > 30 || input[i] == '.') {
       // カウンタの初期化
        i = 0;
      }
      else {
        if(input[i] == 's'){
          flag=1;
        }      
        else if(flag && input[i] != '.'){
          // 受信文字列を送信
          mode = input[i];
          Serial.print(mode);
          Serial.print("\n");
          flag=0;      
        }
        i++;
      }
  }
}
