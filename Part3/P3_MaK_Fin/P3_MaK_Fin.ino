//Elehobby3 Coding P3 F4F_V1.0 2025.10.01 By Kyoji Park
#include <Servo.h>

#define PIN_TOUCH 2 // Red LED Yellow -- wire
#define PIN_LED_COCKPIT 3 // War-W LED Orange wire
#define PIN_LED_BACK 5 // Red LED Yellow -- wire
#define PIN_LED_LEFT 6 // Yellow LED Yellow wire
#define PIN_LED_FRONT 11 // Blue LED Blue wire

#define PERIOD_FRONT_LED 3000 // Ori 1000 code from Police Zaku
#define MAX_BRIGHTNESS_FRONT 140 // Blue LED
#define BRIGHT_SENSOR 40 // Red, Yellow LED

Servo servo_hatch;      //Close 90,  Open 53 <- Ori 91,44
int state=1;   // for switch toggle

void setup() {
  pinMode(PIN_TOUCH, INPUT);

  servo_hatch.attach(9);
  servo_hatch.write(90);

  analogWrite(PIN_LED_FRONT, MAX_BRIGHTNESS_FRONT);
  analogWrite(PIN_LED_LEFT, BRIGHT_SENSOR);
  analogWrite(PIN_LED_BACK, BRIGHT_SENSOR);
}

void loop() {
  int brightness_led_front = (int) ((sin(TWO_PI * millis() / (float)PERIOD_FRONT_LED) + 1.0) * (MAX_BRIGHTNESS_FRONT/2) );
  analogWrite(PIN_LED_FRONT, brightness_led_front);

  if (digitalRead(PIN_TOUCH) == HIGH && state==1) {
    for(int i = BRIGHT_SENSOR; i >= 0; i--) {
      analogWrite(PIN_LED_LEFT, i);
      analogWrite(PIN_LED_BACK, i);
      delay(10);
    }
    delay(500);

    analogWrite(PIN_LED_COCKPIT, 80);

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
    delay(530);

    analogWrite(PIN_LED_COCKPIT, 0);

    for(int i = 0; i <= BRIGHT_SENSOR; i++) {
      analogWrite(PIN_LED_LEFT, i);
      analogWrite(PIN_LED_BACK, i);
      delay(40);
    }
    state=1;
  }
}