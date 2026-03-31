

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() 
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  while(digitalRead(2) == LOW) {
    delay(100);
  }
  while(digitalRead(2) == HIGH) {
    delay(100);
  }

  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  while(digitalRead(2) == LOW) {
    delay(100);
  }
  while(digitalRead(2) == HIGH) {
    delay(100);
  }
}