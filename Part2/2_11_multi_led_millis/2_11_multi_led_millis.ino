#define LED1 3
#define LED2 5

#define DURATION_BLINK 500
#define PERIOD_FADING 1000

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  int value1 = (millis() / DURATION_BLINK) % 2;
  int value2 = (int)((sin(TWO_PI * millis() / (float)PERIOD_FADING) + 1.0) * 127.5);

  digitalWrite(LED1, value1);
  analogWrite(LED2, value2);
}
