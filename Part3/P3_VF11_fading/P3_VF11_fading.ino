//Elehobby3 Coding P3 VF-11B_V1.0 2025.11.07 By C.J.
#define PIN_SW_ROCKET 2 // Rocket Fading Switch 스위치를 누르면 PIN_LED_ROCKET의 밝기가 점점 밝아지다 150에 다다르면 갑자기 255로 밝아짐. 그상태에서 약 5초 유지 후 꺼짐.
#define PIN_POT_FOOT A1 // Foot Nozzle Bright control POT 

#define PIN_LED_ROCKET 3 // Rocket LED PWM pin connect to Mosfet Gate with 10k COB LED제어용 모스펫 gate
#define PIN_LED_COCKPIT 5 // Cockpit PWM pin 전원 켜면 상시 켜짐.
#define PIN_LED_FOOT 6 // Foot Nozzle PWM pin A1의 값에 따라 PIN_LED_FOOT의 밝기가 0~255로 변환 


void setup() {
  pinMode(PIN_SW_ROCKET, INPUT_PULLUP);

  analogWrite(PIN_LED_COCKPIT, 150);
  analogWrite(PIN_LED_ROCKET, 0);
}

void loop() {
  int brightness_foot = map(analogRead(PIN_POT_FOOT), 0, 1023, 0, 255); // foot 밝기 제어
  analogWrite(PIN_LED_FOOT, brightness_foot);
  
  // 버튼 눌리면 밝아지게
  if (digitalRead(PIN_SW_ROCKET) == LOW) {
    for(int i = 0; i <= 150; i++) {
      analogWrite(PIN_LED_ROCKET, i);
      delay(3);
    }
    analogWrite(PIN_LED_ROCKET, 255)
    delay(1000);
    for(int i = 255; i >= 0; i--) {
      analogWrite(PIN_LED_ROCKET, i);
      delay(3);
    }
  }
}