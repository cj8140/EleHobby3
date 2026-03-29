void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (digitalRead(2) == LOW) { // 핀2 스위치 눌림 (Active LOW)
    digitalWrite(3,HIGH); 
  }
  else {
    digitalWrite(3, LOW);
  }

  if (digitalRead(4) == LOW) { // 핀4 스위치 눌림 (Active LOW)
    digitalWrite(5,HIGH); 
  }
  else {
    digitalWrite(5, LOW);
  }
}