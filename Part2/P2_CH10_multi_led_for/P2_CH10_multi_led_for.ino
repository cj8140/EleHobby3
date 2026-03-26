#define LED1 2
#define LED2 4

#define CYCLE_BLINK 50
#define DELAY_FADING 10

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 255; i++) {
    digitalWrite(LED1, i / (CYCLE_BLINK / 2) % 2);  //CYCLE_BLINK/2 만큼 켜지고 CYCLE_BLINK/2 만큼 꺼지고

    analogWrite(LED2, i);
    delay(DELAY_FADING);
  }

  for (int i = 255; i >= 0; i--) {
    digitalWrite(LED1, i / (DURATION_BLINK / 2) % 2);

    analogWrite(LED2, i);
    delay(DELAY_FADING);
  }
}
