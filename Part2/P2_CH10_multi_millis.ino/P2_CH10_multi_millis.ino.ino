#define LED1 2
#define LED2 4

#define DURATION_BLINK 500
#define DURATION_FADING 1000

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, (millis() / (DURATION_BLINK / 2)) % 2);                  //DURATION_BLINK/2 만큼 켜지고 DURATION_BLINK/2 만큼 꺼지고
  analogWrite(LED2, (sin(millis() / (2 * PI) * DURATION_FADING) + 1) * 127);  //켜졌다 꺼지기까지 DURATION FADING의 주기.
}
