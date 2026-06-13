#include <Servo.h>

#define PIN_JOY_X A1  //left 0 522
#define PIN_JOY_Y A2  //up 0   519
#define PIN_JOY_SW A3
#define PIN_SW_SELECT 2

Servo servo_turret;  // 180 98 16
Servo servo_barrel;  //HIGH 32  99 104    LOW ; Ori HIGH 36 106 108 LOW

int angle_turret = 90;
int angle_barrel = 99;

void setup() {
  pinMode(PIN_JOY_SW, INPUT_PULLUP);
  pinMode(PIN_SW_SELECT, INPUT_PULLUP);

  servo_turret.write(angle_turret);
  servo_barrel.write(angle_barrel);

  servo_barrel.attach(9);
  servo_turret.attach(10);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIN_SW_SELECT) == LOW) {
    if (analogRead(PIN_JOY_X) > 720) {  //right
      angle_turret -= 1;
      delay(40);
    }
    else if (analogRead(PIN_JOY_X) < 320) {  //left
      angle_turret += 1;
      delay(40);
    }
    angle_turret = constrain(angle_turret, 0, 180);
    servo_turret.write(angle_turret);

    if (analogRead(PIN_JOY_Y) > 720) {  //down
      angle_barrel += 1;
      delay(40);
    }
    else if (analogRead(PIN_JOY_Y) < 320) {  //up
      angle_barrel -= 1;
      delay(40);
    }
    angle_barrel = constrain(angle_barrel, 32, 104);
    servo_barrel.write(angle_barrel);

    if (digitalRead(PIN_JOY_SW) == LOW) {  //천천히 리셋
      for (int i = 0; i < 100; i++) {
        servo_turret.write(map(i, 0, 100, angle_turret, 90));
        servo_barrel.write(map(i, 0, 100, angle_barrel, 99));
        delay(10);
      }
      angle_turret = 90;
      angle_barrel = 99;
    }
  }

  else {
    int turret_target = map(analogRead(PIN_JOY_X), 0, 1023, 180, 0);
    if (angle_turret < turret_target) angle_turret++;
    if (angle_turret > turret_target) angle_turret--;
    servo_turret.write(angle_turret);

    if (analogRead(PIN_JOY_Y) < 520) {
      int barrel_target = map(analogRead(PIN_JOY_Y), 0, 520, 32, 104);
      if (angle_barrel < barrel_target) angle_barrel++;
      if (angle_barrel > barrel_target) angle_barrel--;
      servo_barrel.write(angle_barrel);
    }
    delay(20);
  }

/*
  Serial.print("Turret_X:");
  Serial.print(analogRead(PIN_JOY_X));
  Serial.print("  Turret_Angle: ");
  Serial.print(angle_turret);
  Serial.print("\tBarrel_Y: ");
  Serial.print(analogRead(PIN_JOY_Y));
  Serial.print("  Barrel_Angle: ");
  Serial.println(angle_barrel);
  delay(50);
*/
}

//Elehobby3 Coding P3 K9A1_V1.5 2026.04.03 By C.J

//1 그냥 매핑
// servo_turret.write(map(analogRead(PIN_JOY_X), 0, 1023, 180, 16));
// if(analogRead(PIN_JOY_Y) < 520) {
//   servo_barrel.write(map(analogRead(PIN_JOY_Y), 0, 520, 32, 104));
// }

//2 느린 매핑
// angle_turret = angle_turret*0.9 + map(analogRead(PIN_JOY_X), 0, 1023, 180, 16)*0.1;  //*숫자 두 합 1이 되도록. 앞의 숫자가 클 수록 느려짐
// angle_barrel = angle_barrel*0.9 + map(analogRead(PIN_JOY_Y), 0, 1023, 32, 104)*0.1;
// servo_turret.write(angle_turret);
// servo_barrel.write(angle_barrel);
// delay(100);