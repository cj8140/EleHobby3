#include <Servo.h>
Servo my_servo;

void setup()
{
  my_servo.attach(9);  //핀 연결
  my_servo.write(90);

  pinMode(A1, INPUT);
}

void loop()
{
  my_servo.write(map(analogRead(A1), 0, 1023, 45, 135));


  // v 이런식으로 변수로 분리 가능 v
  // int angle_servo = map(analogRead(A1), 0, 1023, 45, 135);
  // my_servo.write(angle_servo);
}