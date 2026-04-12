//Elehobby3 Coding P3 F4F_V1.4 2025.04.08 By CJ Park, Fin code edited 25.10.20
#define PIN_TRIG 3
#define PIN_ECHO 4
#define PIN_IN1 5
#define PIN_IN2 6
#define PIN_LED_YELLOW1 8
#define PIN_LED_YELLOW2 10
#define PIN_LED_YELLOW3 12

void setup() {
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_LED_YELLOW1, OUTPUT);
  pinMode(PIN_LED_YELLOW2, OUTPUT);
  pinMode(PIN_LED_YELLOW3, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.begin(9600);
  Serial.println("Starting");  
}

void loop() {
  long duration, distance;
  
  digitalWrite(PIN_TRIG, LOW);    // 트리거 핀을 LOW로 설정하여 초기화
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);  // 트리거 핀을 HIGH로 설정하여 초음파 신호 발사
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO, HIGH, 10000);   // Echo 핀에서 신호가 돌아오는 시간 측정

  if(duration == 0) { //Timeout 발생  
    distance = 99;
  }

  else {
    distance = duration * 0.0344 / 2;  // 거리는 시간 * 속도 / 2로 계산 (속도는 공기 중에서 약 343m/s)
  }
  int speed = map(constrain(distance, 10, 30), 10, 30, 255, 0);  //speed 범위 조정

  Serial.print("Dist: ");
  Serial.print(distance);
  Serial.print("\t\tSpeed: ");
  Serial.println(speed);

  digitalWrite(PIN_IN1, 0);  //모터 코드
  analogWrite(PIN_IN2, speed);

  digitalWrite(PIN_LED_YELLOW1, distance <= 30);  // 거리를 3구간으로 나누기
  digitalWrite(PIN_LED_YELLOW2, distance <= 20);
  digitalWrite(PIN_LED_YELLOW3, distance <= 10);
}