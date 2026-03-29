//Part 2. LED with Potentiometer

void setup()
{
  Serial.begin(9600);  // Serial 시작. 안전한 보드레이트는 9600으로 설정
}

void loop()
{
  int pot_value = analogRead(A1);
  int led_value = map(pot_value, 0, 1023, 0, 255);
  analogWrite(3, led_value);

  Serial.print(pot_value);
  Serial.print(" : ");
  Serial.println(led_value);

  // 변수 안쓸 경우 아래처럼 써야함
  // digitalWrite(3, map(analogRead(A1), 0, 1023, 0, 255));

  // Serial.print(analogRead(A1));
  // Serial.print(" : ");
  // Serial.println(map(analogRead(A1), 0, 1023, 0, 255));
}
