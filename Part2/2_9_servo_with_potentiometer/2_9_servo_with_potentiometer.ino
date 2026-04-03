#include <Servo.h>
Servo my_servo;

void setup()
{
  my_servo.attach(9);  //핀 연결
  my_servo.write(90); // //가변저항핀모드 인풋 삭제
}

void loop()
{
  int angle_servo = map(analogRead(A1), 0, 1023, 0, 180);
  my_servo.write(angle_servo);

  // v 분리된것을 기본으로하고 한 줄로도 할 수 있다는 코드 설명에서 v
  //my_servo.write(map(analogRead(A1), 0, 1023, 0, 180)); 
  // 
}