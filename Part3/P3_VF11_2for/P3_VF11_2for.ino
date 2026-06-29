#define PIN_SW_ROCKET 2 // Rocket Fading Switch
#define PIN_POT A1 // Foot Nozzle Bright control POT 

#define PIN_LED_ROCKET 3 // Rocket LED PWM pin connect to Mosfet Gate with 10k COB LED제어용 모스펫 gate
#define PIN_LED_COCKPIT 5 // Cockpit PWM pin
#define PIN_LED_FOOT 6 // Foot Nozzle PWM pin

void setup() {
  pinMode(PIN_SW_ROCKET, INPUT_PULLUP);

  analogWrite(PIN_LED_COCKPIT, 150);
}

void loop() {
  int brightness = map(analogRead(PIN_POT), 0, 1023, 0, 255); 
  analogWrite(PIN_LED_FOOT, brightness);
  
    if (digitalRead(PIN_SW_ROCKET) == LOW) {
      for(int i = 0; i <= 150; i++) {
        analogWrite(PIN_LED_ROCKET, i);
        delay(10);
      }
      analogWrite(PIN_LED_ROCKET, 255);
      
      delay(brightness*20);
      
      for(int rep = 0; rep < 4; rep++) {
        for(int i = 200; i >= 50; i--) {
          analogWrite(PIN_LED_ROCKET, i);
          delay(3);
        }
        for(int i = 100; i <= 255; i++) {
          analogWrite(PIN_LED_ROCKET, i);
          delay(3);
        }
      }

      for(int i = 255; i >= 0; i--) {
        analogWrite(PIN_LED_ROCKET, i);
        delay(6);
      }
    }
}
//Elehobby3 Coding P3 VF-11B_V2.0 2026.05.07 By C.J. / Kyoji