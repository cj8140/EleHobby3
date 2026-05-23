#define LED1 3
#define LED2 5

#define DURATION_BLINK 500 // ①500 = 0.5sec duration
#define PERIOD_TRI 4 // ②4 = 2.05 sec period (512ms * N)
#define PERIOD_SIN 1000 // ③1000 = 1sec period

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  int value1 = (millis() / DURATION_BLINK) % 2;
  digitalWrite(LED1, value1);
  
  int value2 = (millis() / PERIOD_TRI) % 511;
  if (value2 > 255){
    value2 = 510 - value2;
  }
//  int value2 = (int)((sin(TWO_PI * millis() / (float)PERIOD_SIN) + 1.0) * 127.5);
  analogWrite(LED2, value2);
}