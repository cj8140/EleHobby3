#include <Servo.h>

#define PIN_TOUCH 2 // Red LED Yellow -- wire
#define PIN_LED_COCKPIT 3 // War-W LED Orange wire
#define PIN_LED_TOP 5 // Red LED Yellow -- wire
#define PIN_LED_LEFT 6 // Yellow LED Yellow wire
#define PIN_LED_FRONT 11 // Blue LED Blue wire

#define PERIOD_SIN 3000 // Ori 1000 code from Police Zaku
#define BRIGHT_LED 80 // Red, Yellow LED

Servo servo_hatch;      //Close 90,  Open 53 <- Ori 91,44
int state=1;   // for switch toggle

void setup() {
  pinMode(PIN_TOUCH, INPUT);

  servo_hatch.attach(9);
  servo_hatch.write(90);

  analogWrite(PIN_LED_TOP, BRIGHT_LED);
  analogWrite(PIN_LED_LEFT, BRIGHT_LED);
}

void loop() {
  int led_value = (int) ((sin(TWO_PI * millis() / (float)PERIOD_SIN) + 1.0) * BRIGHT_LED );
  analogWrite(PIN_LED_FRONT, led_value);

  if (digitalRead(PIN_TOUCH) == HIGH && state==1) {
    for(int i = BRIGHT_LED; i >= 0; i--) {
      analogWrite(PIN_LED_TOP, i);
      analogWrite(PIN_LED_LEFT, i);
      delay(10);
    }

    delay(500);
    analogWrite(PIN_LED_COCKPIT, BRIGHT_LED);

    for(int i = 90; i >= 53; i--) {
      servo_hatch.write(i);
      delay(40);
    }
    state=0;
  }

  if (digitalRead(PIN_TOUCH) == HIGH && state==0) {
      for(int i = 53; i <= 90; i++) {
      servo_hatch.write(i);
      delay(40);
      }

    delay(500);
    analogWrite(PIN_LED_COCKPIT, 0);

    for(int i = 0; i <= BRIGHT_LED; i++) {
      analogWrite(PIN_LED_TOP, i);
      analogWrite(PIN_LED_LEFT, i);
      delay(40);
    }
    state=1;
  }
}
//Elehobby3 Coding P3 Ma.K_V1.8 2026.03.04 By C.J, Kyoji