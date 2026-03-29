void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (digitalRead(2) == LOW) { // IR감지하면 LOW신호(Active LOW)
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(5, LOW);
  }
}