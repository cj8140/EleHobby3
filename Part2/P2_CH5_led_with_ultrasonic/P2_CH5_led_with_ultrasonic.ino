void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);

  pinMode(3, OUTPUT);  // LED 1
  pinMode(5, OUTPUT);  // LED 2
}


void loop()
{
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  unsigned long duration = pulseIn(4, HIGH);  //트리거 핀 시간측정

  int distance = 340 * duration / 1000000 * 100 / 2;  // (340m/s) * (1s/1,000,000us) * (1m/100cm) /2
  // 정리된식
  // int distance = 170 * duration / 10000;
  // 위의 식 값 제대로 안나올 경우
  // int distance = (float)(340 * duration) / 1000000 *100 /2;
  Serial.print(distance);

  if (distance < 10) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
  }
  //10미만이 아닌, 20미만 즉 10이상 20미만
  else if (distance < 20) {
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }

  // 대체 코드
  // if (distance < 20) {
  //   digitalWrite(3, HIGH);
  // }
  // else {
  //   digitalWrite(3, LOW);
  // }
  // if (distance < 10) {
  //   digitalWrite(5, HIGH);
  // }
  // else {
  //   digitalWrite(5, LOW);
  // }
}