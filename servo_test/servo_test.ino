// rc_servo_sample1

#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  Serial.begin(9600);   
  myservo.attach( 9 );
}

void loop() {
//  for ( pos = 0; pos < 180; pos += 1 ) {
//    myservo.write( pos );
//    delay( 15 );
//  }
//  for ( pos = 180; pos > 0; pos -= 1 ) {
//    myservo.write( pos );
//    delay( 15 );
//  }

 myservo.write( 90 );
 Serial.println(90);
 delay(2000);
 

 myservo.write( 180 );
 Serial.println(180);
 delay(2000);

 myservo.write( 0 );
 Serial.println(0);
 delay(2000);
 

}
