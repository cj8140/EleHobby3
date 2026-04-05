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
  digitalWrite(LED1, (millis() / DURATION_BLINK) % 2);                  //DURATION_BLINK 만큼 켜지고 DURATION_BLINK 만큼 꺼지고
  analogWrite(LED2, (int)((sin(TWO_PI * millis() / (float)PERIOD_FADING) + 1.0) * 127.5));
}
