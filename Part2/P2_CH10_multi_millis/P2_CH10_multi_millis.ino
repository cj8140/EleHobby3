#define LED1 2
#define LED2 3

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
  analogWrite(LED2, (int)((sin(2.0 * PI * millis() / DURATION_FADING) + 1.0) * 127.5));
}
