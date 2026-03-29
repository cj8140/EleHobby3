void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);

  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  delay(1000);

  analogWrite(3, 50);
  analogWrite(5, 255);
  delay(1000);

  analogWrite(3, 0);
  digitalWrite(5, 0);
  delay(1000);
}