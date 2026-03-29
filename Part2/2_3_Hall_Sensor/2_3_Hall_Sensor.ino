void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (digitalRead(2) == LOW) { // 자석 감지하면 LOW신호(Active LOW)
    digitalWrite(3,HIGH);
    digitalWrite(5,LOW); 
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
  }
}