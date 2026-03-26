#include <Servo.h>

Servo my_servo;

void setup()
{
  my_servo.attach(11);  //핀 연결
  my_servo.write(45);
}

void loop()
{
  for (int i = 45; i < 135; i++) {
    my_servo.write(i);
    delay(5);  //속도 조절. 숫자 커질수록 느려짐
  }
  for (int i = 134; i > 45; i--) {
    my_servo.write(i);
    delay(5);  //속도 조절. 숫자 커질수록 느려짐
  }
}
